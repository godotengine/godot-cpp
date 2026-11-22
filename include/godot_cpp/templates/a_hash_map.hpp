/**************************************************************************/
/*  a_hash_map.hpp                                                        */
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

#include <godot_cpp/core/math_funcs_binary.hpp>
#include <godot_cpp/templates/hash_map.hpp>

#include <initializer_list>

namespace godot {

class String;
class StringName;
class Variant;

/**
 * An array-based implementation of a hash map. It is very efficient in terms of performance and
 * memory usage. Works like a dynamic array, adding elements to the end of the array, and
 * allows you to access array elements by their index by using `get_by_index` method.
 * Example:
 * ```cpp
 *  AHashMap<int, Object *> map;
 *
 *  int get_object_id_by_number(int p_number) {
 *		int id = map.get_index(p_number);
 *		return id;
 *  }
 *
 *  Object *get_object_by_id(int p_id) {
 *		map.get_by_index(p_id).value;
 *  }
 * ```
 * Still, don`t erase the elements because ID can break.
 *
 * When an element erase, its place is taken by the element from the end.
 *
 *        <-------------
 *      |               |
 *  6 8 X 9 32 -1 5 -10 7 X X X
 *  6 8 7 9 32 -1 5 -10 X X X X
 *
 *
 * Use RBMap if you need to iterate over sorted elements.
 *
 * Use HashMap if:
 *   - You need to keep an iterator or const pointer to Key and you intend to add/remove elements in the meantime.
 *   - You need to preserve the insertion order when using erase.
 *
 * It is recommended to use `HashMap` if `KeyValue` size is very large.
 */
template <typename TKey, typename TValue,
		typename Hasher = HashMapHasherDefault,
		typename Comparator = HashMapComparatorDefault<TKey>>
class AHashMap {
public:
	// Must be a power of two.
	/**
	 * Default number of hash buckets for a new or reset map.
	 */
	static constexpr uint32_t INITIAL_CAPACITY = 16;
	/**
	 * Hash reserved for a vacant metadata bucket.
	 */
	static constexpr uint32_t EMPTY_HASH = 0;
	static_assert(EMPTY_HASH == 0, "EMPTY_HASH must always be 0 for the memcpy() optimization.");

private:
	/**
	 * Identifies a packed entry from an occupied hash bucket.
	 */
	struct Metadata {
		/**
		 * Stores the remapped hash. Zero marks a vacant bucket.
		 */
		uint32_t hash;
		/**
		 * Index of the key-value pair in the packed entry array.
		 */
		uint32_t element_idx;
	};

	static_assert(sizeof(Metadata) == 8);

	/**
	 * Alias for the key-value pair stored in the packed array.
	 */
	typedef KeyValue<TKey, TValue> MapKeyValue;
	/**
	 * Owns the contiguous array of live key-value pairs.
	 */
	MapKeyValue *_elements = nullptr;
	/**
	 * Owns the open-addressed hash bucket array.
	 */
	Metadata *_metadata = nullptr;

	// Due to optimization, this is `capacity - 1`. Use + 1 to get normal capacity.
	/**
	 * Stores the power-of-two bucket count minus one, used to wrap bucket indices.
	 */
	uint32_t _capacity_mask = 0;
	/**
	 * Counts the live pairs at the start of the entry array.
	 */
	uint32_t _size = 0;

	/**
	 * Computes a key hash and maps zero to one to preserve the empty-bucket marker.
	 */
	uint32_t _hash(const TKey &p_key) const {
		uint32_t hash = Hasher::hash(p_key);

		if (unlikely(hash == EMPTY_HASH)) {
			hash = EMPTY_HASH + 1;
		}

		return hash;
	}

	/**
	 * Returns one less than the entry limit for a bucket mask of the form `2^n - 1`.
	 */
	static _FORCE_INLINE_ uint32_t _get_resize_count(uint32_t p_capacity_mask) {
		return p_capacity_mask ^ (p_capacity_mask + 1) >> 2; // = get_capacity() * 0.75 - 1; Works only if p_capacity_mask = 2^n - 1.
	}

	/**
	 * Computes the forward distance between the starting bucket and the current bucket. The capacity argument is the bucket mask.
	 */
	static _FORCE_INLINE_ uint32_t _get_probe_length(uint32_t p_meta_idx, uint32_t p_hash, uint32_t p_capacity) {
		const uint32_t original_idx = p_hash & p_capacity;
		return (p_meta_idx - original_idx + p_capacity + 1) & p_capacity;
	}

	/**
	 * Searches for the key and writes its entry and metadata indices on success.
	 */
	bool _lookup_idx(const TKey &p_key, uint32_t &r_element_idx, uint32_t &r_meta_idx) const {
		if (unlikely(_elements == nullptr)) {
			return false; // Failed lookups, no _elements.
		}
		return _lookup_idx_with_hash(p_key, r_element_idx, r_meta_idx, _hash(p_key));
	}

	/**
	 * Looks up a key with a precomputed nonzero hash. On success writes both array indices.
	 */
	bool _lookup_idx_with_hash(const TKey &p_key, uint32_t &r_element_idx, uint32_t &r_meta_idx, uint32_t p_hash) const {
		if (unlikely(_elements == nullptr)) {
			return false; // Failed lookups, no _elements.
		}

		uint32_t meta_idx = p_hash & _capacity_mask;
		Metadata metadata = _metadata[meta_idx];
		if (metadata.hash == p_hash && Comparator::compare(_elements[metadata.element_idx].key, p_key)) {
			r_element_idx = metadata.element_idx;
			r_meta_idx = meta_idx;
			return true;
		}

		if (metadata.hash == EMPTY_HASH) {
			return false;
		}

		// A collision occurred.
		meta_idx = (meta_idx + 1) & _capacity_mask;
		uint32_t distance = 1;
		while (true) {
			metadata = _metadata[meta_idx];
			if (metadata.hash == p_hash && Comparator::compare(_elements[metadata.element_idx].key, p_key)) {
				r_element_idx = metadata.element_idx;
				r_meta_idx = meta_idx;
				return true;
			}

			if (metadata.hash == EMPTY_HASH) {
				return false;
			}

			if (distance > _get_probe_length(meta_idx, metadata.hash, _capacity_mask)) {
				return false;
			}

			meta_idx = (meta_idx + 1) & _capacity_mask;
			distance++;
		}
	}

	/**
	 * Inserts the hash and packed index with Robin Hood probing. Returns the final vacant bucket filled, which may hold displaced metadata.
	 */
	uint32_t _insert_metadata(uint32_t p_hash, uint32_t p_element_idx) {
		uint32_t meta_idx = p_hash & _capacity_mask;

		if (_metadata[meta_idx].hash == EMPTY_HASH) {
			_metadata[meta_idx] = Metadata{ p_hash, p_element_idx };
			return meta_idx;
		}

		uint32_t distance = 1;
		meta_idx = (meta_idx + 1) & _capacity_mask;
		Metadata metadata;
		metadata.hash = p_hash;
		metadata.element_idx = p_element_idx;

		while (true) {
			if (_metadata[meta_idx].hash == EMPTY_HASH) {
#ifdef DEV_ENABLED
				if (unlikely(distance > 12)) {
					WARN_PRINT("Excessive collision count, is the right hash function being used?");
				}
#endif
				_metadata[meta_idx] = metadata;
				return meta_idx;
			}

			// Not an empty slot, let's check the probing length of the existing one.
			uint32_t existing_probe_len = _get_probe_length(meta_idx, _metadata[meta_idx].hash, _capacity_mask);
			if (existing_probe_len < distance) {
				SWAP(metadata, _metadata[meta_idx]);
				distance = existing_probe_len;
			}

			meta_idx = (meta_idx + 1) & _capacity_mask;
			distance++;
		}
	}

	/**
	 * Resizes the packed array and rebuilds the hash buckets without changing live entry indices.
	 */
	void _resize_and_rehash(uint32_t p_new_capacity) {
		uint32_t real_old_capacity = _capacity_mask + 1;
		// Capacity can't be 0 and must be 2^n - 1.
		_capacity_mask = MAX(4u, p_new_capacity);
		uint32_t real_capacity = Math::next_power_of_2(_capacity_mask);
		_capacity_mask = real_capacity - 1;

		Metadata *old_map_data = _metadata;

		_metadata = reinterpret_cast<Metadata *>(Memory::alloc_static_zeroed(sizeof(Metadata) * real_capacity));
		_elements = reinterpret_cast<MapKeyValue *>(Memory::realloc_static(_elements, sizeof(MapKeyValue) * (_get_resize_count(_capacity_mask) + 1)));

		if (_size != 0) {
			for (uint32_t i = 0; i < real_old_capacity; i++) {
				Metadata metadata = old_map_data[i];
				if (metadata.hash != EMPTY_HASH) {
					_insert_metadata(metadata.hash, metadata.element_idx);
				}
			}
		}

		Memory::free_static(old_map_data);
	}

	/**
	 * Appends a key-value pair, expanding the arrays if needed, and returns the packed entry index.
	 */
	int32_t _insert_element(const TKey &p_key, const TValue &p_value, uint32_t p_hash) {
		if (unlikely(_elements == nullptr)) {
			// Allocate on demand to save memory.

			uint32_t real_capacity = _capacity_mask + 1;
			_metadata = reinterpret_cast<Metadata *>(Memory::alloc_static_zeroed(sizeof(Metadata) * real_capacity));
			_elements = reinterpret_cast<MapKeyValue *>(Memory::alloc_static(sizeof(MapKeyValue) * (_get_resize_count(_capacity_mask) + 1)));
		}

		if (unlikely(_size > _get_resize_count(_capacity_mask))) {
			_resize_and_rehash(_capacity_mask * 2);
		}

		memnew_placement(&_elements[_size], MapKeyValue(p_key, p_value));

		_insert_metadata(p_hash, _size);
		_size++;
		return _size - 1;
	}

	/**
	 * Copies another map's packed entries and bucket metadata into unallocated storage.
	 */
	void _init_from(const AHashMap &p_other) {
		_capacity_mask = p_other._capacity_mask;
		uint32_t real_capacity = _capacity_mask + 1;
		_size = p_other._size;

		if (p_other._size == 0) {
			return;
		}

		_metadata = reinterpret_cast<Metadata *>(Memory::alloc_static(sizeof(Metadata) * real_capacity));
		_elements = reinterpret_cast<MapKeyValue *>(Memory::alloc_static(sizeof(MapKeyValue) * (_get_resize_count(_capacity_mask) + 1)));

		if constexpr (std::is_trivially_copyable_v<TKey> && std::is_trivially_copyable_v<TValue>) {
			void *destination = _elements;
			const void *source = p_other._elements;
			memcpy(destination, source, sizeof(MapKeyValue) * _size);
		} else {
			for (uint32_t i = 0; i < _size; i++) {
				memnew_placement(&_elements[i], MapKeyValue(p_other._elements[i]));
			}
		}

		memcpy(_metadata, p_other._metadata, sizeof(Metadata) * real_capacity);
	}

public:
	/* Standard Godot Container API */

	/**
	 * Returns the selected number of hash buckets, even before allocation.
	 */
	_FORCE_INLINE_ uint32_t get_capacity() const { return _capacity_mask + 1; }
	/**
	 * Returns the number of live key-value pairs.
	 */
	_FORCE_INLINE_ uint32_t size() const { return _size; }

	/**
	 * Returns whether there are no live entries.
	 */
	_FORCE_INLINE_ bool is_empty() const {
		return _size == 0;
	}

	/**
	 * Destroys all entries and clears the metadata while keeping the allocated arrays.
	 */
	void clear() {
		if (_elements == nullptr || _size == 0) {
			return;
		}

		memset(_metadata, EMPTY_HASH, (_capacity_mask + 1) * sizeof(Metadata));
		if constexpr (!(std::is_trivially_destructible_v<TKey> && std::is_trivially_destructible_v<TValue>)) {
			for (uint32_t i = 0; i < _size; i++) {
				_elements[i].key.~TKey();
				_elements[i].value.~TValue();
			}
		}

		_size = 0;
	}

	/**
	 * Returns a writable reference to the value for an existing key. An absent key triggers a crash check.
	 */
	TValue &get(const TKey &p_key) _LIFETIME_BOUND_ {
		uint32_t element_idx = 0;
		uint32_t meta_idx = 0;
		bool exists = _lookup_idx(p_key, element_idx, meta_idx);
		CRASH_COND_MSG(!exists, "AHashMap key not found.");
		return _elements[element_idx].value;
	}

	/**
	 * Returns a read-only reference to the value for an existing key. An absent key triggers a crash check.
	 */
	const TValue &get(const TKey &p_key) const _LIFETIME_BOUND_ {
		uint32_t element_idx = 0;
		uint32_t meta_idx = 0;
		bool exists = _lookup_idx(p_key, element_idx, meta_idx);
		CRASH_COND_MSG(!exists, "AHashMap key not found.");
		return _elements[element_idx].value;
	}

	/**
	 * Returns a read-only pointer to the stored value, or null if the key is absent.
	 */
	const TValue *getptr(const TKey &p_key) const _LIFETIME_BOUND_ {
		uint32_t element_idx = 0;
		uint32_t meta_idx = 0;
		bool exists = _lookup_idx(p_key, element_idx, meta_idx);

		if (exists) {
			return &_elements[element_idx].value;
		}
		return nullptr;
	}

	/**
	 * Returns a writable pointer to the stored value, or null if the key is absent.
	 */
	TValue *getptr(const TKey &p_key) _LIFETIME_BOUND_ {
		uint32_t element_idx = 0;
		uint32_t meta_idx = 0;
		bool exists = _lookup_idx(p_key, element_idx, meta_idx);

		if (exists) {
			return &_elements[element_idx].value;
		}
		return nullptr;
	}

	/**
	 * Returns whether the map contains the key.
	 */
	bool has(const TKey &p_key) const {
		uint32_t _idx = 0;
		uint32_t meta_idx = 0;
		return _lookup_idx(p_key, _idx, meta_idx);
	}

	/**
	 * Removes the entry and returns whether the key existed. Moves the last entry into the gap when necessary, changing that entry's index.
	 */
	bool erase(const TKey &p_key) {
		uint32_t meta_idx = 0;
		uint32_t element_idx = 0;
		bool exists = _lookup_idx(p_key, element_idx, meta_idx);

		if (!exists) {
			return false;
		}

		uint32_t next_meta_idx = (meta_idx + 1) & _capacity_mask;
		while (_metadata[next_meta_idx].hash != EMPTY_HASH && _get_probe_length(next_meta_idx, _metadata[next_meta_idx].hash, _capacity_mask) != 0) {
			SWAP(_metadata[next_meta_idx], _metadata[meta_idx]);

			meta_idx = next_meta_idx;
			next_meta_idx = (next_meta_idx + 1) & _capacity_mask;
		}

		_metadata[meta_idx].hash = EMPTY_HASH;
		_elements[element_idx].key.~TKey();
		_elements[element_idx].value.~TValue();
		_size--;

		if (element_idx < _size) {
			memcpy((void *)&_elements[element_idx], (const void *)&_elements[_size], sizeof(MapKeyValue));
			uint32_t moved_element_idx = 0;
			uint32_t moved_meta_idx = 0;
			_lookup_idx(_elements[_size].key, moved_element_idx, moved_meta_idx);
			_metadata[moved_meta_idx].element_idx = element_idx;
		}

		return true;
	}

	// Replace the key of an entry in-place, without invalidating iterators or changing the entries position during iteration.
	// p_old_key must exist in the map and p_new_key must not, unless it is equal to p_old_key.
	/**
	 * Replaces the key in place and updates the hash metadata. The value and packed index stay associated with the entry. A different replacement key must be absent.
	 */
	bool replace_key(const TKey &p_old_key, const TKey &p_new_key) {
		if (p_old_key == p_new_key) {
			return true;
		}
		uint32_t meta_idx = 0;
		uint32_t element_idx = 0;
		ERR_FAIL_COND_V(_lookup_idx(p_new_key, element_idx, meta_idx), false);
		ERR_FAIL_COND_V(!_lookup_idx(p_old_key, element_idx, meta_idx), false);
		MapKeyValue &element = _elements[element_idx];
		const_cast<TKey &>(element.key) = p_new_key;

		uint32_t next_meta_idx = (meta_idx + 1) & _capacity_mask;
		while (_metadata[next_meta_idx].hash != EMPTY_HASH && _get_probe_length(next_meta_idx, _metadata[next_meta_idx].hash, _capacity_mask) != 0) {
			SWAP(_metadata[next_meta_idx], _metadata[meta_idx]);

			meta_idx = next_meta_idx;
			next_meta_idx = (next_meta_idx + 1) & _capacity_mask;
		}

		_metadata[meta_idx].hash = EMPTY_HASH;

		uint32_t hash = _hash(p_new_key);
		_insert_metadata(hash, element_idx);

		return true;
	}

	// Reserves space for a number of elements, useful to avoid many resizes and rehashes.
	// If adding a known (possibly large) number of elements at once, must be larger than old capacity.
	/**
	 * Selects a power-of-two bucket count of at least four before allocation. With allocated storage, only grows the arrays when the request exceeds the current bucket count.
	 */
	void reserve(uint32_t p_new_capacity) {
		if (_elements == nullptr) {
			_capacity_mask = MAX(4u, p_new_capacity);
			_capacity_mask = Math::next_power_of_2(_capacity_mask) - 1;
			return; // Unallocated yet.
		}
		if (p_new_capacity <= get_capacity()) {
			if (p_new_capacity < size()) {
				WARN_VERBOSE("reserve() called with a capacity smaller than the current size. This is likely a mistake.");
			}
			return;
		}
		_resize_and_rehash(p_new_capacity);
	}

	/** Iterator API **/

	/**
	 * Traverses the map's packed entries with read-only access to values.
	 */
	struct ConstIterator {
		/**
		 * Returns a read-only reference to the current entry. The iterator must be on an entry.
		 */
		_FORCE_INLINE_ const MapKeyValue &operator*() const {
			return *pair;
		}
		/**
		 * Returns a read-only pointer to the current entry.
		 */
		_FORCE_INLINE_ const MapKeyValue *operator->() const {
			return pair;
		}
		/**
		 * Advances to the next entry. Advancing past the last entry reaches the end.
		 */
		_FORCE_INLINE_ ConstIterator &operator++() {
			pair++;
			return *this;
		}

		/**
		 * Moves to the previous entry. The stored bounds identify the start of the range.
		 */
		_FORCE_INLINE_ ConstIterator &operator--() {
			pair--;
			if (pair < begin) {
				pair = end;
			}
			return *this;
		}

		/**
		 * Tests whether the iterators point to the same entry.
		 */
		_FORCE_INLINE_ bool operator==(const ConstIterator &b) const { return pair == b.pair; }
		/**
		 * Tests whether the iterators point to different entries.
		 */
		_FORCE_INLINE_ bool operator!=(const ConstIterator &b) const { return pair != b.pair; }

		/**
		 * Returns whether the iterator is at an entry rather than the end.
		 */
		_FORCE_INLINE_ explicit operator bool() const {
			return pair != end;
		}

		/**
		 * Starts at the supplied position and records the bounds of the entry array.
		 */
		_FORCE_INLINE_ ConstIterator(MapKeyValue *p_key, MapKeyValue *p_begin, MapKeyValue *p_end) {
			pair = p_key;
			begin = p_begin;
			end = p_end;
		}
		/**
		 * Creates an iterator with no current entry.
		 */
		_FORCE_INLINE_ ConstIterator() {}
		/**
		 * Copies the source iterator's position.
		 */
		_FORCE_INLINE_ ConstIterator(const ConstIterator &p_it) {
			pair = p_it.pair;
			begin = p_it.begin;
			end = p_it.end;
		}
		/**
		 * Sets the iterator to the source iterator's position.
		 */
		_FORCE_INLINE_ void operator=(const ConstIterator &p_it) {
			pair = p_it.pair;
			begin = p_it.begin;
			end = p_it.end;
		}

	private:
		/**
		 * Points to the current entry or to the position past the last entry.
		 */
		MapKeyValue *pair = nullptr;
		/**
		 * Points to the first entry of the captured range.
		 */
		MapKeyValue *begin = nullptr;
		/**
		 * Points past the last entry of the captured range.
		 */
		MapKeyValue *end = nullptr;
	};

	/**
	 * Traverses the map's packed entries with writable access to values.
	 */
	struct Iterator {
		/**
		 * Returns a reference to the current entry. The iterator must be on an entry.
		 */
		_FORCE_INLINE_ MapKeyValue &operator*() const {
			return *pair;
		}
		/**
		 * Returns a pointer to the current entry.
		 */
		_FORCE_INLINE_ MapKeyValue *operator->() const {
			return pair;
		}
		/**
		 * Advances to the next entry. Advancing past the last entry reaches the end.
		 */
		_FORCE_INLINE_ Iterator &operator++() {
			pair++;
			return *this;
		}
		/**
		 * Moves to the previous entry. The stored bounds identify the start of the range.
		 */
		_FORCE_INLINE_ Iterator &operator--() {
			pair--;
			if (pair < begin) {
				pair = end;
			}
			return *this;
		}

		/**
		 * Tests whether the iterators point to the same entry.
		 */
		_FORCE_INLINE_ bool operator==(const Iterator &b) const { return pair == b.pair; }
		/**
		 * Tests whether the iterators point to different entries.
		 */
		_FORCE_INLINE_ bool operator!=(const Iterator &b) const { return pair != b.pair; }

		/**
		 * Returns whether the iterator is at an entry rather than the end.
		 */
		_FORCE_INLINE_ explicit operator bool() const {
			return pair != end;
		}

		/**
		 * Starts at the supplied position and records the bounds of the entry array.
		 */
		_FORCE_INLINE_ Iterator(MapKeyValue *p_key, MapKeyValue *p_begin, MapKeyValue *p_end) {
			pair = p_key;
			begin = p_begin;
			end = p_end;
		}
		/**
		 * Creates an iterator with no current entry.
		 */
		_FORCE_INLINE_ Iterator() {}
		/**
		 * Copies the source iterator's position.
		 */
		_FORCE_INLINE_ Iterator(const Iterator &p_it) {
			pair = p_it.pair;
			begin = p_it.begin;
			end = p_it.end;
		}
		/**
		 * Sets the iterator to the source iterator's position.
		 */
		_FORCE_INLINE_ void operator=(const Iterator &p_it) {
			pair = p_it.pair;
			begin = p_it.begin;
			end = p_it.end;
		}

		/**
		 * Creates a read-only iterator with the same position and bounds.
		 */
		operator ConstIterator() const {
			return ConstIterator(pair, begin, end);
		}

	private:
		/**
		 * Points to the current entry or to the position past the last entry.
		 */
		MapKeyValue *pair = nullptr;
		/**
		 * Points to the first entry of the captured range.
		 */
		MapKeyValue *begin = nullptr;
		/**
		 * Points past the last entry of the captured range.
		 */
		MapKeyValue *end = nullptr;
	};

	/**
	 * Returns a writable iterator to the first packed entry. For an empty map, this is the end position.
	 */
	_FORCE_INLINE_ Iterator begin() _LIFETIME_BOUND_ {
		return Iterator(_elements, _elements, _elements + _size);
	}
	/**
	 * Returns a writable iterator past the last packed entry.
	 */
	_FORCE_INLINE_ Iterator end() _LIFETIME_BOUND_ {
		return Iterator(_elements + _size, _elements, _elements + _size);
	}
	/**
	 * Returns a writable iterator to the last packed entry, or an empty iterator for an empty map.
	 */
	_FORCE_INLINE_ Iterator last() _LIFETIME_BOUND_ {
		if (unlikely(_size == 0)) {
			return Iterator(nullptr, nullptr, nullptr);
		}
		return Iterator(_elements + _size - 1, _elements, _elements + _size);
	}

	/**
	 * Returns a writable iterator to the entry for the key, or the end iterator if absent.
	 */
	Iterator find(const TKey &p_key) _LIFETIME_BOUND_ {
		uint32_t meta_idx = 0;
		uint32_t element_idx = 0;
		bool exists = _lookup_idx(p_key, element_idx, meta_idx);
		if (!exists) {
			return end();
		}
		return Iterator(_elements + element_idx, _elements, _elements + _size);
	}

	/**
	 * Erases the key at the iterator's position if the iterator refers to an entry.
	 */
	void remove(const Iterator &p_iter) {
		if (p_iter) {
			erase(p_iter->key);
		}
	}

	/**
	 * Returns a read-only iterator to the first packed entry. For an empty map, this is the end position.
	 */
	_FORCE_INLINE_ ConstIterator begin() const _LIFETIME_BOUND_ {
		return ConstIterator(_elements, _elements, _elements + _size);
	}
	/**
	 * Returns a read-only iterator past the last packed entry.
	 */
	_FORCE_INLINE_ ConstIterator end() const _LIFETIME_BOUND_ {
		return ConstIterator(_elements + _size, _elements, _elements + _size);
	}
	/**
	 * Returns a read-only iterator to the last packed entry, or an empty iterator for an empty map.
	 */
	_FORCE_INLINE_ ConstIterator last() const _LIFETIME_BOUND_ {
		if (unlikely(_size == 0)) {
			return ConstIterator(nullptr, nullptr, nullptr);
		}
		return ConstIterator(_elements + _size - 1, _elements, _elements + _size);
	}

	/**
	 * Returns a read-only iterator to the entry for the key, or the end iterator if absent.
	 */
	ConstIterator find(const TKey &p_key) const _LIFETIME_BOUND_ {
		uint32_t element_idx = 0;
		uint32_t meta_idx = 0;
		bool exists = _lookup_idx(p_key, element_idx, meta_idx);
		if (!exists) {
			return end();
		}
		return ConstIterator(_elements + element_idx, _elements, _elements + _size);
	}

	/* Indexing */

	/**
	 * Returns a read-only reference to the value for an existing key. An absent key triggers a crash check.
	 */
	const TValue &operator[](const TKey &p_key) const _LIFETIME_BOUND_ {
		uint32_t element_idx = 0;
		uint32_t meta_idx = 0;
		bool exists = _lookup_idx(p_key, element_idx, meta_idx);
		CRASH_COND(!exists);
		return _elements[element_idx].value;
	}

	/**
	 * Returns a writable reference to the value. Appends a value-initialized entry if the key is absent.
	 */
	TValue &operator[](const TKey &p_key) _LIFETIME_BOUND_ {
		uint32_t element_idx = 0;
		uint32_t meta_idx = 0;
		uint32_t hash = _hash(p_key);
		bool exists = _lookup_idx_with_hash(p_key, element_idx, meta_idx, hash);

		if (exists) {
			return _elements[element_idx].value;
		} else {
			element_idx = _insert_element(p_key, TValue(), hash);
			return _elements[element_idx].value;
		}
	}

	/* Insert */

	/**
	 * Appends a new entry or updates the value of an existing entry. Returns an iterator to that entry.
	 */
	Iterator insert(const TKey &p_key, const TValue &p_value) _LIFETIME_BOUND_ {
		uint32_t element_idx = 0;
		uint32_t meta_idx = 0;
		uint32_t hash = _hash(p_key);
		bool exists = _lookup_idx_with_hash(p_key, element_idx, meta_idx, hash);

		if (!exists) {
			element_idx = _insert_element(p_key, p_value, hash);
		} else {
			_elements[element_idx].value = p_value;
		}
		return Iterator(_elements + element_idx, _elements, _elements + _size);
	}

	// Inserts an element without checking if it already exists.
	/**
	 * Appends a pair for a key known to be absent and returns its iterator. Development builds assert that the key is absent.
	 */
	Iterator insert_new(const TKey &p_key, const TValue &p_value) _LIFETIME_BOUND_ {
		DEV_ASSERT(!has(p_key));
		uint32_t hash = _hash(p_key);
		uint32_t element_idx = _insert_element(p_key, p_value, hash);
		return Iterator(_elements + element_idx, _elements, _elements + _size);
	}

	/* Array methods. */

	// Unsafe. Changing keys and going outside the bounds of an array can lead to undefined behavior.
	/**
	 * Returns the base of the packed entry array. Access is valid only within the live range and while the array remains allocated at that address.
	 */
	KeyValue<TKey, TValue> *get_elements_ptr() _LIFETIME_BOUND_ {
		return _elements;
	}

	// Returns the element index. If not found, returns -1.
	/**
	 * Returns the packed index for the key, or `-1` if the key is absent.
	 */
	int get_index(const TKey &p_key) {
		uint32_t element_idx = 0;
		uint32_t meta_idx = 0;
		bool exists = _lookup_idx(p_key, element_idx, meta_idx);
		if (!exists) {
			return -1;
		}
		return element_idx;
	}

	/**
	 * Returns the pair at a packed index. An out-of-range index triggers a crash check.
	 */
	KeyValue<TKey, TValue> &get_by_index(uint32_t p_index) _LIFETIME_BOUND_ {
		CRASH_BAD_UNSIGNED_INDEX(p_index, _size);
		return _elements[p_index];
	}

	/**
	 * Erases the entry at the packed index and returns false if the index is out of range.
	 */
	bool erase_by_index(uint32_t p_index) {
		if (p_index >= size()) {
			return false;
		}
		return erase(_elements[p_index].key);
	}

	/* Constructors */

	/**
	 * Takes ownership of the source's arrays and leaves the source empty.
	 */
	AHashMap(AHashMap &&p_other) {
		_elements = p_other._elements;
		_metadata = p_other._metadata;
		_capacity_mask = p_other._capacity_mask;
		_size = p_other._size;

		p_other._elements = nullptr;
		p_other._metadata = nullptr;
		p_other._capacity_mask = 0;
		p_other._size = 0;
	}

	/**
	 * Copies the source's entries and table into independent storage.
	 */
	explicit AHashMap(const AHashMap &p_other) {
		_init_from(p_other);
	}

	/**
	 * Releases the old storage and replaces it with a copy of the source, unless assigned to itself.
	 */
	void operator=(const AHashMap &p_other) {
		if (this == &p_other) {
			return; // Ignore self assignment.
		}

		reset();

		_init_from(p_other);
	}

	/**
	 * Selects the initial bucket count by rounding up to a power of two with a minimum of four. Allocation is deferred.
	 */
	AHashMap(uint32_t p_initial_capacity) {
		// Capacity can't be 0 and must be 2^n - 1.
		_capacity_mask = MAX(4u, p_initial_capacity);
		_capacity_mask = Math::next_power_of_2(_capacity_mask) - 1;
	}
	/**
	 * Creates an empty map with the default bucket count and deferred allocation.
	 */
	AHashMap() :
			_capacity_mask(INITIAL_CAPACITY - 1) {
	}

	/**
	 * Inserts the pairs in list order. For a repeated key, the last value replaces the previous value.
	 */
	AHashMap(std::initializer_list<KeyValue<TKey, TValue>> p_init) {
		reserve(p_init.size());
		for (const KeyValue<TKey, TValue> &E : p_init) {
			insert(E.key, E.value);
		}
	}

	/**
	 * Destroys the entries, releases both arrays, and restores the default bucket count.
	 */
	void reset() {
		if (_elements != nullptr) {
			if constexpr (!(std::is_trivially_destructible_v<TKey> && std::is_trivially_destructible_v<TValue>)) {
				for (uint32_t i = 0; i < _size; i++) {
					_elements[i].key.~TKey();
					_elements[i].value.~TValue();
				}
			}
			Memory::free_static(_elements);
			Memory::free_static(_metadata);
			_elements = nullptr;
		}
		_capacity_mask = INITIAL_CAPACITY - 1;
		_size = 0;
	}

	/**
	 * Destroys the entries and frees the map's arrays.
	 */
	~AHashMap() {
		reset();
	}
};

} //namespace godot
