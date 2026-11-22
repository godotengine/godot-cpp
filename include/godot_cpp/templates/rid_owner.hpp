/**************************************************************************/
/*  rid_owner.hpp                                                         */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#pragma once

#include <godot_cpp/core/memory.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/templates/list.hpp>
#include <godot_cpp/templates/spin_lock.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

#include <cstdio>
#include <typeinfo>

namespace godot {

/**
 * Stores resources in fixed-size chunks and identifies each slot with a resource ID. A tag in the ID helps detect IDs for reused slots.
 *
 * - `T` — Value stored in each initialized slot.
 * - `THREAD_SAFE` — Whether to lock the slot tables during the operations that take the allocator lock.
 */
template <typename T, bool THREAD_SAFE = false>
class RID_Alloc {
	/**
	 * Owns the chunks of storage for resource values. Each live value is constructed in its slot.
	 */
	T **chunks = nullptr;
	/**
	 * Stores the free slot indices. The allocation count gives the position of the next free slot in this list.
	 */
	uint32_t **free_list_chunks = nullptr;
	/**
	 * Stores each slot's validation tag and its initialization bit. All bits set marks a free slot.
	 */
	uint32_t **validator_chunks = nullptr;

	/**
	 * Number of slots in each chunk of values and in each matching metadata chunk.
	 */
	uint32_t elements_in_chunk;
	/**
	 * Number of slots available in all allocated chunks, including slots in use.
	 */
	uint32_t max_alloc = 0;
	/**
	 * Number of reserved slots, including slots that still need initialization.
	 */
	uint32_t alloc_count = 0;

	/**
	 * Borrowed string used to identify this owner in leak reports.
	 */
	const char *description = nullptr;

	/**
	 * Guards slot-table changes and lookups when locking is enabled.
	 */
	SpinLock spin_lock;

	/**
	 * Reserves a free slot, adding a chunk if needed. Returns an ID containing the slot index and validation tag. The slot is marked as uninitialized.
	 */
	_FORCE_INLINE_ RID _allocate_rid() {
		if (THREAD_SAFE) {
			spin_lock.lock();
		}

		if (alloc_count == max_alloc) {
			// allocate a new chunk
			uint32_t chunk_count = alloc_count == 0 ? 0 : (max_alloc / elements_in_chunk);

			// grow chunks
			chunks = (T **)memrealloc(chunks, sizeof(T *) * (chunk_count + 1));
			chunks[chunk_count] = (T *)memalloc(sizeof(T) * elements_in_chunk); // but don't initialize

			// grow validators
			validator_chunks = (uint32_t **)memrealloc(validator_chunks, sizeof(uint32_t *) * (chunk_count + 1));
			validator_chunks[chunk_count] = (uint32_t *)memalloc(sizeof(uint32_t) * elements_in_chunk);
			// grow free lists
			free_list_chunks = (uint32_t **)memrealloc(free_list_chunks, sizeof(uint32_t *) * (chunk_count + 1));
			free_list_chunks[chunk_count] = (uint32_t *)memalloc(sizeof(uint32_t) * elements_in_chunk);

			// initialize
			for (uint32_t i = 0; i < elements_in_chunk; i++) {
				// Don't initialize chunk.
				validator_chunks[chunk_count][i] = 0xFFFFFFFF;
				free_list_chunks[chunk_count][i] = alloc_count + i;
			}

			max_alloc += elements_in_chunk;
		}

		uint32_t free_index = free_list_chunks[alloc_count / elements_in_chunk][alloc_count % elements_in_chunk];

		uint32_t free_chunk = free_index / elements_in_chunk;
		uint32_t free_element = free_index % elements_in_chunk;

		uint32_t validator = (uint32_t)(UtilityFunctions::rid_allocate_id() & 0x7FFFFFFF);
		uint64_t id = validator;
		id <<= 32;
		id |= free_index;

		validator_chunks[free_chunk][free_element] = validator;

		validator_chunks[free_chunk][free_element] |= 0x80000000; // mark uninitialized bit

		alloc_count++;

		if (THREAD_SAFE) {
			spin_lock.unlock();
		}

		return UtilityFunctions::rid_from_int64(id);
	}

public:
	/**
	 * Reserves a slot, default-constructs the value in it, and returns its resource ID.
	 */
	RID make_rid() {
		RID rid = _allocate_rid();
		initialize_rid(rid);
		return rid;
	}
	/**
	 * Reserves a slot, copies the supplied value into it, and returns its resource ID.
	 *
	 * - `p_value` — Value to copy into the new slot.
	 */
	RID make_rid(const T &p_value) {
		RID rid = _allocate_rid();
		initialize_rid(rid, p_value);
		return rid;
	}

	// allocate but don't initialize, use initialize_rid afterwards
	/**
	 * Reserves a slot and returns its resource ID. Initialize the slot before reading or freeing it.
	 */
	RID allocate_rid() {
		return _allocate_rid();
	}

	/**
	 * Checks the ID and returns a pointer into the owner's storage, or null if the lookup fails. The lock is released before the pointer is returned.
	 *
	 * - `p_rid` — Resource ID to look up in this owner.
	 * - `p_initialize` — If true, require a reserved slot and clear its uninitialized bit before returning its storage. Otherwise require an initialized slot.
	 */
	_FORCE_INLINE_ T *get_or_null(const RID &p_rid, bool p_initialize = false) {
		if (p_rid == RID()) {
			return nullptr;
		}
		if (THREAD_SAFE) {
			spin_lock.lock();
		}

		uint64_t id = p_rid.get_id();
		uint32_t idx = uint32_t(id & 0xFFFFFFFF);
		if (unlikely(idx >= max_alloc)) {
			if (THREAD_SAFE) {
				spin_lock.unlock();
			}
			return nullptr;
		}

		uint32_t idx_chunk = idx / elements_in_chunk;
		uint32_t idx_element = idx % elements_in_chunk;

		uint32_t validator = uint32_t(id >> 32);

		if (unlikely(p_initialize)) {
			if (unlikely(!(validator_chunks[idx_chunk][idx_element] & 0x80000000))) {
				if (THREAD_SAFE) {
					spin_lock.unlock();
				}
				ERR_FAIL_V_MSG(nullptr, "Initializing already initialized RID");
			}

			if (unlikely((validator_chunks[idx_chunk][idx_element] & 0x7FFFFFFF) != validator)) {
				if (THREAD_SAFE) {
					spin_lock.unlock();
				}
				ERR_FAIL_V_MSG(nullptr, "Attempting to initialize the wrong RID");
				return nullptr;
			}

			validator_chunks[idx_chunk][idx_element] &= 0x7FFFFFFF; // initialized

		} else if (unlikely(validator_chunks[idx_chunk][idx_element] != validator)) {
			if (THREAD_SAFE) {
				spin_lock.unlock();
			}
			if ((validator_chunks[idx_chunk][idx_element] & 0x80000000) && validator_chunks[idx_chunk][idx_element] != 0xFFFFFFFF) {
				ERR_FAIL_V_MSG(nullptr, "Attempting to use an uninitialized RID");
			}
			return nullptr;
		}

		T *ptr = &chunks[idx_chunk][idx_element];

		if (THREAD_SAFE) {
			spin_lock.unlock();
		}

		return ptr;
	}
	/**
	 * Default-constructs a value in a reserved slot. Reports an error if the slot cannot be initialized.
	 *
	 * - `p_rid` — Reserved resource ID from this owner that has not been initialized.
	 */
	void initialize_rid(RID p_rid) {
		T *mem = get_or_null(p_rid, true);
		ERR_FAIL_NULL(mem);
		memnew_placement(mem, T);
	}
	/**
	 * Copy-constructs a value in a reserved slot. Reports an error if the slot cannot be initialized.
	 *
	 * - `p_rid` — Reserved resource ID from this owner that has not been initialized.
	 * - `p_value` — Source value to copy.
	 */
	void initialize_rid(RID p_rid, const T &p_value) {
		T *mem = get_or_null(p_rid, true);
		ERR_FAIL_NULL(mem);
		memnew_placement(mem, T(p_value));
	}

	/**
	 * Checks whether the slot index and validation tag match this owner. A slot can match before initialization.
	 *
	 * - `p_rid` — Resource ID to look up in this owner.
	 */
	_FORCE_INLINE_ bool owns(const RID &p_rid) {
		if (THREAD_SAFE) {
			spin_lock.lock();
		}

		uint64_t id = p_rid.get_id();
		uint32_t idx = uint32_t(id & 0xFFFFFFFF);
		if (unlikely(idx >= max_alloc)) {
			if (THREAD_SAFE) {
				spin_lock.unlock();
			}
			return false;
		}

		uint32_t idx_chunk = idx / elements_in_chunk;
		uint32_t idx_element = idx % elements_in_chunk;

		uint32_t validator = uint32_t(id >> 32);

		bool owned = (validator_chunks[idx_chunk][idx_element] & 0x7FFFFFFF) == validator;

		if (THREAD_SAFE) {
			spin_lock.unlock();
		}

		return owned;
	}

	/**
	 * Destroys the value and returns its slot to the free list. An invalid or uninitialized ID reports an error.
	 *
	 * - `p_rid` — Initialized resource ID from this owner.
	 */
	_FORCE_INLINE_ void free(const RID &p_rid) {
		if (THREAD_SAFE) {
			spin_lock.lock();
		}

		uint64_t id = p_rid.get_id();
		uint32_t idx = uint32_t(id & 0xFFFFFFFF);
		if (unlikely(idx >= max_alloc)) {
			if (THREAD_SAFE) {
				spin_lock.unlock();
			}
			ERR_FAIL();
		}

		uint32_t idx_chunk = idx / elements_in_chunk;
		uint32_t idx_element = idx % elements_in_chunk;

		uint32_t validator = uint32_t(id >> 32);
		if (unlikely(validator_chunks[idx_chunk][idx_element] & 0x80000000)) {
			if (THREAD_SAFE) {
				spin_lock.unlock();
			}
			ERR_FAIL_MSG("Attempted to free an uninitialized or invalid RID");
		} else if (unlikely(validator_chunks[idx_chunk][idx_element] != validator)) {
			if (THREAD_SAFE) {
				spin_lock.unlock();
			}
			ERR_FAIL();
		}

		chunks[idx_chunk][idx_element].~T();
		validator_chunks[idx_chunk][idx_element] = 0xFFFFFFFF; // go invalid

		alloc_count--;
		free_list_chunks[alloc_count / elements_in_chunk][alloc_count % elements_in_chunk] = idx;

		if (THREAD_SAFE) {
			spin_lock.unlock();
		}
	}

	/**
	 * Returns the number of reserved slots, including uninitialized slots.
	 */
	_FORCE_INLINE_ uint32_t get_rid_count() const {
		return alloc_count;
	}

	/**
	 * Appends the occupied slots' IDs in slot order. IDs for reserved slots carry the uninitialized marker.
	 *
	 * - `p_owned` — Destination list. The method appends to its existing entries.
	 */
	void get_owned_list(List<RID> *p_owned) {
		if (THREAD_SAFE) {
			spin_lock.lock();
		}
		for (size_t i = 0; i < max_alloc; i++) {
			uint64_t validator = validator_chunks[i / elements_in_chunk][i % elements_in_chunk];
			if (validator != 0xFFFFFFFF) {
				p_owned->push_back(UtilityFunctions::rid_from_int64((validator << 32) | i));
			}
		}
		if (THREAD_SAFE) {
			spin_lock.unlock();
		}
	}

	// used for fast iteration in the elements or RIDs
	/**
	 * Writes the occupied slots' IDs in slot order. IDs for reserved slots carry the uninitialized marker.
	 *
	 * - `p_rid_buffer` — Writable buffer with space for at least the current RID count. The caller supplies the capacity.
	 */
	void fill_owned_buffer(RID *p_rid_buffer) {
		if (THREAD_SAFE) {
			spin_lock.lock();
		}
		uint32_t idx = 0;
		for (size_t i = 0; i < max_alloc; i++) {
			uint64_t validator = validator_chunks[i / elements_in_chunk][i % elements_in_chunk];
			if (validator != 0xFFFFFFFF) {
				p_rid_buffer[idx] = UtilityFunctions::rid_from_int64((validator << 32) | i);
				idx++;
			}
		}
		if (THREAD_SAFE) {
			spin_lock.unlock();
		}
	}

	/**
	 * Sets the name printed when this owner is destroyed with occupied slots.
	 *
	 * - `p_descrption` — Null-terminated name to use in diagnostics. Keep the string alive through destruction, or pass null to use the default name.
	 */
	void set_description(const char *p_descrption) {
		description = p_descrption;
	}

	/**
	 * Sets the chunk size for the slot allocator. The first reservation allocates storage.
	 *
	 * - `p_target_chunk_byte_size` — Target byte size of a storage chunk. Each chunk holds at least one slot.
	 */
	RID_Alloc(uint32_t p_target_chunk_byte_size = 65536) {
		elements_in_chunk = sizeof(T) > p_target_chunk_byte_size ? 1 : (p_target_chunk_byte_size / sizeof(T));
	}

	/**
	 * Reports remaining allocations, destroys initialized values, and frees all chunks.
	 */
	~RID_Alloc() {
		if (alloc_count) {
			if (description) {
				printf("ERROR: %d  RID allocations of type '%s' were leaked at exit.", alloc_count, description);
			} else {
#ifdef NO_SAFE_CAST
				printf("ERROR: %d RID allocations of type 'unknown' were leaked at exit.", alloc_count);
#else
				printf("ERROR: %d RID allocations of type '%s' were leaked at exit.", alloc_count, typeid(T).name());
#endif
			}

			for (size_t i = 0; i < max_alloc; i++) {
				uint64_t validator = validator_chunks[i / elements_in_chunk][i % elements_in_chunk];
				if (validator & 0x80000000) {
					continue; // uninitialized
				}
				if (validator != 0xFFFFFFFF) {
					chunks[i / elements_in_chunk][i % elements_in_chunk].~T();
				}
			}
		}

		uint32_t chunk_count = max_alloc / elements_in_chunk;
		for (uint32_t i = 0; i < chunk_count; i++) {
			memfree(chunks[i]);
			memfree(validator_chunks[i]);
			memfree(free_list_chunks[i]);
		}

		if (chunks) {
			memfree(chunks);
			memfree(free_list_chunks);
			memfree(validator_chunks);
		}
	}
};

/**
 * Maps resource IDs to pointers. The owner manages the pointer slots while the caller manages the pointed-to objects.
 *
 * - `T` — Type of the pointed-to objects.
 * - `THREAD_SAFE` — Whether to lock the slot tables during the operations that take the allocator lock.
 */
template <typename T, bool THREAD_SAFE = false>
class RID_PtrOwner {
	/**
	 * Owns the slots used to store pointers and their resource IDs.
	 */
	RID_Alloc<T *, THREAD_SAFE> alloc;

public:
	/**
	 * Stores a pointer in a new slot and returns the resource ID for that slot.
	 *
	 * - `p_ptr` — Pointer to store. The owner does not take ownership of the object.
	 */
	_FORCE_INLINE_ RID make_rid(T *p_ptr) {
		return alloc.make_rid(p_ptr);
	}

	/**
	 * Reserves a slot and returns its resource ID. Initialize the slot before reading or freeing it.
	 */
	_FORCE_INLINE_ RID allocate_rid() {
		return alloc.allocate_rid();
	}

	/**
	 * Stores a pointer in a reserved slot so its ID can be used for lookup.
	 *
	 * - `p_rid` — Reserved resource ID from this owner that has not been initialized.
	 * - `p_ptr` — Pointer to store in the slot.
	 */
	_FORCE_INLINE_ void initialize_rid(RID p_rid, T *p_ptr) {
		alloc.initialize_rid(p_rid, p_ptr);
	}

	/**
	 * Returns the stored pointer. A missing slot or a stored null pointer yields null.
	 *
	 * - `p_rid` — Resource ID to look up in this owner.
	 */
	_FORCE_INLINE_ T *get_or_null(const RID &p_rid) {
		T **ptr = alloc.get_or_null(p_rid);
		if (unlikely(!ptr)) {
			return nullptr;
		}
		return *ptr;
	}

	/**
	 * Changes the pointer stored under an initialized ID. The previous pointed-to object is unaffected.
	 *
	 * - `p_rid` — Resource ID to look up in this owner.
	 * - `p_new_ptr` — Replacement pointer, which can be null.
	 */
	_FORCE_INLINE_ void replace(const RID &p_rid, T *p_new_ptr) {
		T **ptr = alloc.get_or_null(p_rid);
		ERR_FAIL_NULL(ptr);
		*ptr = p_new_ptr;
	}

	/**
	 * Checks whether the slot index and validation tag match this owner. A slot can match before initialization.
	 *
	 * - `p_rid` — Resource ID to look up in this owner.
	 */
	_FORCE_INLINE_ bool owns(const RID &p_rid) {
		return alloc.owns(p_rid);
	}

	/**
	 * Frees the ID and recycles its pointer slot. The pointed-to object remains owned by the caller.
	 *
	 * - `p_rid` — Initialized resource ID from this owner.
	 */
	_FORCE_INLINE_ void free(const RID &p_rid) {
		alloc.free(p_rid);
	}

	/**
	 * Returns the number of reserved slots, including uninitialized slots.
	 */
	_FORCE_INLINE_ uint32_t get_rid_count() const {
		return alloc.get_rid_count();
	}

	/**
	 * Appends the occupied slots' IDs in slot order. IDs for reserved slots carry the uninitialized marker.
	 *
	 * - `p_owned` — Destination list. The method appends to its existing entries.
	 */
	_FORCE_INLINE_ void get_owned_list(List<RID> *p_owned) {
		return alloc.get_owned_list(p_owned);
	}

	/**
	 * Writes the occupied slots' IDs in slot order. IDs for reserved slots carry the uninitialized marker.
	 *
	 * - `p_rid_buffer` — Writable buffer with space for at least the current RID count. The caller supplies the capacity.
	 */
	void fill_owned_buffer(RID *p_rid_buffer) {
		alloc.fill_owned_buffer(p_rid_buffer);
	}

	/**
	 * Sets the name printed when this owner is destroyed with occupied slots.
	 *
	 * - `p_descrption` — Null-terminated name to use in diagnostics. Keep the string alive through destruction, or pass null to use the default name.
	 */
	void set_description(const char *p_descrption) {
		alloc.set_description(p_descrption);
	}

	/**
	 * Sets the chunk size for the slot allocator. The first reservation allocates storage.
	 *
	 * - `p_target_chunk_byte_size` — Target byte size of a storage chunk. Each chunk holds at least one slot.
	 */
	RID_PtrOwner(uint32_t p_target_chunk_byte_size = 65536) :
			alloc(p_target_chunk_byte_size) {}
};

/**
 * Owns values in chunked storage and maps resource IDs to their slots.
 *
 * - `T` — Value stored by the owner.
 * - `THREAD_SAFE` — Whether to lock the slot tables during the operations that take the allocator lock.
 */
template <typename T, bool THREAD_SAFE = false>
class RID_Owner {
	/**
	 * Owns the slots, their values, and the resource IDs.
	 */
	RID_Alloc<T, THREAD_SAFE> alloc;

public:
	/**
	 * Reserves a slot, default-constructs the value in it, and returns its resource ID.
	 */
	_FORCE_INLINE_ RID make_rid() {
		return alloc.make_rid();
	}
	/**
	 * Creates a resource ID for a copy of the value.
	 *
	 * - `p_ptr` — Source value to copy into the slot.
	 */
	_FORCE_INLINE_ RID make_rid(const T &p_ptr) {
		return alloc.make_rid(p_ptr);
	}

	/**
	 * Reserves a slot and returns its resource ID. Initialize the slot before reading or freeing it.
	 */
	_FORCE_INLINE_ RID allocate_rid() {
		return alloc.allocate_rid();
	}

	/**
	 * Default-constructs a value in a reserved slot. Reports an error if the slot cannot be initialized.
	 *
	 * - `p_rid` — Reserved resource ID from this owner that has not been initialized.
	 */
	_FORCE_INLINE_ void initialize_rid(RID p_rid) {
		alloc.initialize_rid(p_rid);
	}

	/**
	 * Copy-constructs a value in a reserved slot.
	 *
	 * - `p_rid` — Reserved resource ID from this owner that has not been initialized.
	 * - `p_ptr` — Source value to copy.
	 */
	_FORCE_INLINE_ void initialize_rid(RID p_rid, const T &p_ptr) {
		alloc.initialize_rid(p_rid, p_ptr);
	}

	/**
	 * Returns a pointer to the initialized value, or null if the ID cannot be used. Freeing the ID invalidates the pointer.
	 *
	 * - `p_rid` — Resource ID to look up in this owner.
	 */
	_FORCE_INLINE_ T *get_or_null(const RID &p_rid) {
		return alloc.get_or_null(p_rid);
	}

	/**
	 * Checks whether the slot index and validation tag match this owner. A slot can match before initialization.
	 *
	 * - `p_rid` — Resource ID to look up in this owner.
	 */
	_FORCE_INLINE_ bool owns(const RID &p_rid) {
		return alloc.owns(p_rid);
	}

	/**
	 * Destroys the value and returns its slot to the free list. An invalid or uninitialized ID reports an error.
	 *
	 * - `p_rid` — Initialized resource ID from this owner.
	 */
	_FORCE_INLINE_ void free(const RID &p_rid) {
		alloc.free(p_rid);
	}

	/**
	 * Returns the number of reserved slots, including uninitialized slots.
	 */
	_FORCE_INLINE_ uint32_t get_rid_count() const {
		return alloc.get_rid_count();
	}

	/**
	 * Appends the occupied slots' IDs in slot order. IDs for reserved slots carry the uninitialized marker.
	 *
	 * - `p_owned` — Destination list. The method appends to its existing entries.
	 */
	_FORCE_INLINE_ void get_owned_list(List<RID> *p_owned) {
		return alloc.get_owned_list(p_owned);
	}
	/**
	 * Writes the occupied slots' IDs in slot order. IDs for reserved slots carry the uninitialized marker.
	 *
	 * - `p_rid_buffer` — Writable buffer with space for at least the current RID count. The caller supplies the capacity.
	 */
	void fill_owned_buffer(RID *p_rid_buffer) {
		alloc.fill_owned_buffer(p_rid_buffer);
	}

	/**
	 * Sets the name printed when this owner is destroyed with occupied slots.
	 *
	 * - `p_descrption` — Null-terminated name to use in diagnostics. Keep the string alive through destruction, or pass null to use the default name.
	 */
	void set_description(const char *p_descrption) {
		alloc.set_description(p_descrption);
	}
	/**
	 * Sets the chunk size for the slot allocator. The first reservation allocates storage.
	 *
	 * - `p_target_chunk_byte_size` — Target byte size of a storage chunk. Each chunk holds at least one slot.
	 */
	RID_Owner(uint32_t p_target_chunk_byte_size = 65536) :
			alloc(p_target_chunk_byte_size) {}
};

} // namespace godot
