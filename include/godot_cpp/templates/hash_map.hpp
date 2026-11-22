/**************************************************************************/
/*  hash_map.hpp                                                          */
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

#include <godot_cpp/core/error_macros.hpp>
#include <godot_cpp/core/memory.hpp>
#include <godot_cpp/templates/hashfuncs.hpp>
#include <godot_cpp/templates/pair.hpp>
#include <godot_cpp/templates/sort_list.hpp>

#include <initializer_list>

namespace godot {


/**
 * A node in the map's iteration list. Rebuilding the hash table preserves the node's address.
 */
template <typename TKey, typename TValue>
struct HashMapElement {
	/**
	 * Points to the next entry in iteration order, or is null at the tail.
	 */
	HashMapElement *next = nullptr;
	/**
	 * Points to the previous entry in iteration order, or is null at the head.
	 */
	HashMapElement *prev = nullptr;
	/**
	 * Stores the key and value for this entry.
	 */
	KeyValue<TKey, TValue> data;
	/**
	 * Creates an unlinked node with a default-constructed key and value.
	 */
	HashMapElement() {}
	/**
	 * Creates an unlinked node with copies of the given key and value.
	 */
	HashMapElement(const TKey &p_key, const TValue &p_value) :
			data(p_key, p_value) {}
};

/**
 * Maps keys to values through Robin Hood hashing. Individually allocated entries form a doubly linked list that controls iteration order. Rehashing preserves entry addresses.
 *
 * - `Hasher` — Computes the key hash. Equal keys must produce equal hashes.
 * - `Comparator` — Tests keys for equality.
 * - `Allocator` — Creates and destroys linked-list nodes.
 */
template <typename TKey, typename TValue,
		typename Hasher = HashMapHasherDefault,
		typename Comparator = HashMapComparatorDefault<TKey>,
		typename Allocator = DefaultTypedAllocator<HashMapElement<TKey, TValue>>>
class HashMap : private Allocator {
public:
	/**
	 * Index of the default minimum bucket count in `godot::hash_table_size_primes`.
	 */
	static constexpr uint32_t MIN_CAPACITY_INDEX = 2; // Use a prime.
	/**
	 * Maximum fraction of occupied buckets before insertion grows the table.
	 */
	static constexpr float MAX_OCCUPANCY = 0.75;
	/**
	 * Hash reserved for unoccupied buckets.
	 */
	static constexpr uint32_t EMPTY_HASH = 0;
	/**
	 * The key-value pair type stored in each node.
	 */
	using KV = KeyValue<TKey, TValue>; // Type alias for easier access to KeyValue.

private:
	/**
	 * Stores entry pointers indexed by hash bucket. Only occupied buckets have a valid pointer.
	 */
	HashMapElement<TKey, TValue> **_elements = nullptr;
	/**
	 * Stores the remapped hash for each bucket, with zero marking an empty bucket.
	 */
	uint32_t *_hashes = nullptr;
	/**
	 * Points to the first node in iteration order.
	 */
	HashMapElement<TKey, TValue> *_head_element = nullptr;
	/**
	 * Points to the last node in iteration order.
	 */
	HashMapElement<TKey, TValue> *_tail_element = nullptr;

	/**
	 * Selects the bucket count and its reciprocal from the hash-table size tables.
	 */
	uint32_t _capacity_idx = 0;
	/**
	 * Counts the entries in the map.
	 */
	uint32_t _size = 0;

	/**
	 * Computes a key hash and replaces zero with one to preserve the empty-bucket marker.
	 */
	_FORCE_INLINE_ static uint32_t _hash(const TKey &p_key) {
		uint32_t hash = Hasher::hash(p_key);

		if (unlikely(hash == EMPTY_HASH)) {
			hash = EMPTY_HASH + 1;
		}

		return hash;
	}

	/**
	 * Advances a bucket index, wrapping to zero at the end.
	 */
	_FORCE_INLINE_ static constexpr void _increment_mod(uint32_t &r_idx, const uint32_t p_capacity) {
		r_idx++;
		// `if` is faster than both fastmod and mod.
		if (unlikely(r_idx == p_capacity)) {
			r_idx = 0;
		}
	}

	/**
	 * Computes the forward distance from a hash's starting bucket to its current bucket, with wraparound.
	 */
	static _FORCE_INLINE_ uint32_t _get_probe_length(const uint32_t p_idx, const uint32_t p_hash, const uint32_t p_capacity, const uint64_t p_capacity_inv) {
		const uint32_t original_idx = fastmod(p_hash, p_capacity_inv, p_capacity);
		const uint32_t distance_idx = p_idx - original_idx + p_capacity;
		// At most p_capacity over 0, so we can use an if (faster than fastmod).
		return distance_idx >= p_capacity ? distance_idx - p_capacity : distance_idx;
	}

	/**
	 * Looks up a key in a nonempty map and writes its bucket index on success.
	 */
	bool _lookup_idx(const TKey &p_key, uint32_t &r_idx) const {
		return _elements != nullptr && _size > 0 && _lookup_idx_unchecked(p_key, _hash(p_key), r_idx);
	}

	/// Note: Assumes that _elements != nullptr
	bool _lookup_idx_unchecked(const TKey &p_key, uint32_t p_hash, uint32_t &r_idx) const {
		const uint32_t capacity = hash_table_size_primes[_capacity_idx];
		const uint64_t capacity_inv = hash_table_size_primes_inv[_capacity_idx];
		uint32_t idx = fastmod(p_hash, capacity_inv, capacity);
		uint32_t distance = 0;

		while (true) {
			if (_hashes[idx] == EMPTY_HASH) {
				return false;
			}

			if (distance > _get_probe_length(idx, _hashes[idx], capacity, capacity_inv)) {
				return false;
			}

			if (_hashes[idx] == p_hash && Comparator::compare(_elements[idx]->data.key, p_key)) {
				r_idx = idx;
				return true;
			}

			_increment_mod(idx, capacity);
			distance++;
		}
	}

	/**
	 * Places an existing node and hash, displacing entries with shorter probe distances, and increments the entry count.
	 */
	void _insert_element(uint32_t p_hash, HashMapElement<TKey, TValue> *p_value) {
		const uint32_t capacity = hash_table_size_primes[_capacity_idx];
		const uint64_t capacity_inv = hash_table_size_primes_inv[_capacity_idx];
		uint32_t hash = p_hash;
		HashMapElement<TKey, TValue> *value = p_value;
		uint32_t distance = 0;
		uint32_t idx = fastmod(hash, capacity_inv, capacity);

		while (true) {
			if (_hashes[idx] == EMPTY_HASH) {
				_elements[idx] = value;
				_hashes[idx] = hash;

				_size++;

				return;
			}

			// Not an empty slot, let's check the probing length of the existing one.
			uint32_t existing_probe_len = _get_probe_length(idx, _hashes[idx], capacity, capacity_inv);
			if (existing_probe_len < distance) {
				SWAP(hash, _hashes[idx]);
				SWAP(value, _elements[idx]);
				distance = existing_probe_len;
			}

			_increment_mod(idx, capacity);
			distance++;
		}
	}

	/**
	 * Rebuilds the bucket arrays using stored hashes and existing nodes.
	 */
	void _resize_and_rehash(uint32_t p_new_capacity_idx) {
		uint32_t old_capacity = hash_table_size_primes[_capacity_idx];

		// Capacity can't be 0.
		_capacity_idx = MAX((uint32_t)MIN_CAPACITY_INDEX, p_new_capacity_idx);

		uint32_t capacity = hash_table_size_primes[_capacity_idx];

		HashMapElement<TKey, TValue> **old_elements = _elements;
		uint32_t *old_hashes = _hashes;

		_size = 0;
		static_assert(EMPTY_HASH == 0, "Assuming EMPTY_HASH = 0 for alloc_static_zeroed call");

		_hashes = reinterpret_cast<uint32_t *>(Memory::alloc_static_zeroed(sizeof(uint32_t) * capacity));
		_elements = reinterpret_cast<HashMapElement<TKey, TValue> **>(Memory::alloc_static(sizeof(HashMapElement<TKey, TValue> *) * capacity));

		if (old_capacity == 0) {
			// Nothing to do.
			return;
		}

		for (uint32_t i = 0; i < old_capacity; i++) {
			if (old_hashes[i] == EMPTY_HASH) {
				continue;
			}

			_insert_element(old_hashes[i], old_elements[i]);
		}

		Memory::free_static(old_elements);
		Memory::free_static(old_hashes);
	}

	/**
	 * Allocates and links a new node, then indexes it by hash. The caller must establish that the key is absent.
	 */
	_FORCE_INLINE_ HashMapElement<TKey, TValue> *_insert(const TKey &p_key, const TValue &p_value, uint32_t p_hash, bool p_front_insert = false) {
		uint32_t capacity = hash_table_size_primes[_capacity_idx];
		if (unlikely(_elements == nullptr)) {
			// Allocate on demand to save memory.

			static_assert(EMPTY_HASH == 0, "Assuming EMPTY_HASH = 0 for alloc_static_zeroed call");
			_hashes = reinterpret_cast<uint32_t *>(Memory::alloc_static_zeroed(sizeof(uint32_t) * capacity));
			_elements = reinterpret_cast<HashMapElement<TKey, TValue> **>(Memory::alloc_static(sizeof(HashMapElement<TKey, TValue> *) * capacity));
		}

		if (_size + 1 > MAX_OCCUPANCY * capacity) {
			ERR_FAIL_COND_V_MSG(_capacity_idx + 1 == HASH_TABLE_SIZE_MAX, nullptr, "Hash table maximum capacity reached, aborting insertion.");
			_resize_and_rehash(_capacity_idx + 1);
		}

		HashMapElement<TKey, TValue> *elem = Allocator::new_allocation(HashMapElement<TKey, TValue>(p_key, p_value));

		if (_tail_element == nullptr) {
			_head_element = elem;
			_tail_element = elem;
		} else if (p_front_insert) {
			_head_element->prev = elem;
			elem->next = _head_element;
			_head_element = elem;
		} else {
			_tail_element->next = elem;
			elem->prev = _tail_element;
			_tail_element = elem;
		}

		_insert_element(p_hash, elem);
		return elem;
	}

	/**
	 * Destroys entries from tail to head through the allocator. The caller resets the bucket and list state.
	 */
	void _clear_data() {
		HashMapElement<TKey, TValue> *current = _tail_element;
		while (current != nullptr) {
			HashMapElement<TKey, TValue> *prev = current->prev;
			Allocator::delete_allocation(current);
			current = prev;
		}
	}

public:
	/**
	 * Returns the selected bucket count, even before allocation.
	 */
	_FORCE_INLINE_ uint32_t get_capacity() const { return hash_table_size_primes[_capacity_idx]; }
	/**
	 * Returns the number of key-value pairs.
	 */
	_FORCE_INLINE_ uint32_t size() const { return _size; }

	/* Standard Godot Container API */

	/**
	 * Returns whether the map contains zero entries.
	 */
	bool is_empty() const {
		return _size == 0;
	}

	/**
	 * Destroys all entries and clears the buckets while keeping the bucket allocation.
	 */
	void clear() {
		if (_elements == nullptr || _size == 0) {
			return;
		}

		_clear_data();
		memset(_hashes, EMPTY_HASH, get_capacity() * sizeof(uint32_t));

		_tail_element = nullptr;
		_head_element = nullptr;
		_size = 0;
	}

	/**
	 * Reorders iteration by ascending key using `godot::KeyValueSort`.
	 */
	void sort() {
		sort_custom<KeyValueSort<TKey, TValue>>();
	}

	/**
	 * Reorders the linked list with the comparator `C` without moving the entries.
	 */
	template <typename C>
	void sort_custom() {
		if (size() < 2) {
			return;
		}

		using E = HashMapElement<TKey, TValue>;
		SortList<E, KeyValue<TKey, TValue>, &E::data, &E::prev, &E::next, C> sorter;
		sorter.sort(_head_element, _tail_element);
	}

	/**
	 * Returns a writable reference to an existing value. An absent key triggers a crash check.
	 */
	TValue &get(const TKey &p_key) _LIFETIME_BOUND_ {
		uint32_t idx = 0;
		bool exists = _lookup_idx(p_key, idx);
		CRASH_COND_MSG(!exists, "HashMap key not found.");
		return _elements[idx]->data.value;
	}

	/**
	 * Returns a read-only reference to an existing value. An absent key triggers a crash check.
	 */
	const TValue &get(const TKey &p_key) const _LIFETIME_BOUND_ {
		uint32_t idx = 0;
		bool exists = _lookup_idx(p_key, idx);
		CRASH_COND_MSG(!exists, "HashMap key not found.");
		return _elements[idx]->data.value;
	}

	/**
	 * Returns a read-only pointer to the value, or null if the key is absent.
	 */
	const TValue *getptr(const TKey &p_key) const _LIFETIME_BOUND_ {
		uint32_t idx = 0;
		bool exists = _lookup_idx(p_key, idx);

		if (exists) {
			return &_elements[idx]->data.value;
		}
		return nullptr;
	}

	/**
	 * Returns a writable pointer to the value, or null if the key is absent.
	 */
	TValue *getptr(const TKey &p_key) _LIFETIME_BOUND_ {
		uint32_t idx = 0;
		bool exists = _lookup_idx(p_key, idx);

		if (exists) {
			return &_elements[idx]->data.value;
		}
		return nullptr;
	}

	/**
	 * Returns whether the map contains the key.
	 */
	_FORCE_INLINE_ bool has(const TKey &p_key) const {
		uint32_t _idx = 0;
		return _lookup_idx(p_key, _idx);
	}

	/**
	 * Removes the entry and returns whether the key existed. Iterators to the removed node become invalid.
	 */
	bool erase(const TKey &p_key) {
		uint32_t idx = 0;
		bool exists = _lookup_idx(p_key, idx);

		if (!exists) {
			return false;
		}

		const uint32_t capacity = hash_table_size_primes[_capacity_idx];
		const uint64_t capacity_inv = hash_table_size_primes_inv[_capacity_idx];
		uint32_t next_idx = fastmod((idx + 1), capacity_inv, capacity);
		while (_hashes[next_idx] != EMPTY_HASH && _get_probe_length(next_idx, _hashes[next_idx], capacity, capacity_inv) != 0) {
			SWAP(_hashes[next_idx], _hashes[idx]);
			SWAP(_elements[next_idx], _elements[idx]);
			idx = next_idx;
			_increment_mod(next_idx, capacity);
		}

		_hashes[idx] = EMPTY_HASH;

		if (_head_element == _elements[idx]) {
			_head_element = _elements[idx]->next;
		}

		if (_tail_element == _elements[idx]) {
			_tail_element = _elements[idx]->prev;
		}

		if (_elements[idx]->prev) {
			_elements[idx]->prev->next = _elements[idx]->next;
		}

		if (_elements[idx]->next) {
			_elements[idx]->next->prev = _elements[idx]->prev;
		}

		Allocator::delete_allocation(_elements[idx]);

		_size--;
		return true;
	}

	// Replace the key of an entry in-place, without invalidating iterators or changing the entries position during iteration.
	// p_old_key must exist in the map and p_new_key must not, unless it is equal to p_old_key.
	/**
	 * Changes the key in place and updates the table. A different replacement key must be absent. The entry keeps its position in iteration order.
	 */
	bool replace_key(const TKey &p_old_key, const TKey &p_new_key) {
		ERR_FAIL_COND_V(_elements == nullptr || _size == 0, false);
		if (p_old_key == p_new_key) {
			return true;
		}
		const uint32_t new_hash = _hash(p_new_key);
		uint32_t idx = 0;
		ERR_FAIL_COND_V(_lookup_idx_unchecked(p_new_key, new_hash, idx), false);
		ERR_FAIL_COND_V(!_lookup_idx(p_old_key, idx), false);
		HashMapElement<TKey, TValue> *element = _elements[idx];

		// Delete the old entries in _hashes and _elements.
		const uint32_t capacity = hash_table_size_primes[_capacity_idx];
		const uint64_t capacity_inv = hash_table_size_primes_inv[_capacity_idx];
		uint32_t next_idx = fastmod((idx + 1), capacity_inv, capacity);
		while (_hashes[next_idx] != EMPTY_HASH && _get_probe_length(next_idx, _hashes[next_idx], capacity, capacity_inv) != 0) {
			SWAP(_hashes[next_idx], _hashes[idx]);
			SWAP(_elements[next_idx], _elements[idx]);
			idx = next_idx;
			_increment_mod(next_idx, capacity);
		}

		_hashes[idx] = EMPTY_HASH;

		// _insert_element will increment this again.
		_size--;

		// Update the HashMapElement with the new key and reinsert it.
		const_cast<TKey &>(element->data.key) = p_new_key;
		_insert_element(new_hash, element);

		return true;
	}

	// Reserves space for a number of elements, useful to avoid many resizes and rehashes.
	// If adding a known (possibly large) number of elements at once, must be larger than old capacity.
	/**
	 * Selects at least the requested bucket count, rounded up to a supported size. Allocation stays deferred until first insertion if the table has never been allocated.
	 */
	void reserve(uint32_t p_new_capacity) {
		uint32_t new_idx = _capacity_idx;

		while (hash_table_size_primes[new_idx] < p_new_capacity) {
			ERR_FAIL_COND_MSG(new_idx + 1 == (uint32_t)HASH_TABLE_SIZE_MAX, nullptr);
			new_idx++;
		}

		if (new_idx == _capacity_idx) {
			if (p_new_capacity < _size) {
				WARN_VERBOSE("reserve() called with a capacity smaller than the current size. This is likely a mistake.");
			}
			return;
		}

		if (_elements == nullptr) {
			_capacity_idx = new_idx;
			return; // Unallocated yet.
		}
		_resize_and_rehash(new_idx);
	}

	/** Iterator API **/

	/**
	 * Traverses the map's linked entries with read-only access to values.
	 */
	struct ConstIterator {
		/**
		 * Returns a read-only reference to the current entry. The iterator must be on an entry.
		 */
		_FORCE_INLINE_ const KeyValue<TKey, TValue> &operator*() const {
			return E->data;
		}
		/**
		 * Returns a read-only pointer to the current entry.
		 */
		_FORCE_INLINE_ const KeyValue<TKey, TValue> *operator->() const { return &E->data; }
		/**
		 * Advances to the next entry. Advancing past the last entry reaches the end.
		 */
		_FORCE_INLINE_ ConstIterator &operator++() {
			if (E) {
				E = E->next;
			}
			return *this;
		}
		/**
		 * Moves to the previous node. A null node pointer stays null.
		 */
		_FORCE_INLINE_ ConstIterator &operator--() {
			if (E) {
				E = E->prev;
			}
			return *this;
		}

		/**
		 * Tests whether the iterators point to the same node.
		 */
		_FORCE_INLINE_ bool operator==(const ConstIterator &b) const { return E == b.E; }
		/**
		 * Tests whether the iterators point to different nodes.
		 */
		_FORCE_INLINE_ bool operator!=(const ConstIterator &b) const { return E != b.E; }

		/**
		 * Returns whether the iterator is at an entry rather than the end.
		 */
		_FORCE_INLINE_ explicit operator bool() const {
			return E != nullptr;
		}

		/**
		 * Starts at the supplied node. A null pointer marks the end.
		 */
		_FORCE_INLINE_ ConstIterator(const HashMapElement<TKey, TValue> *p_E) { E = p_E; }
		/**
		 * Creates an iterator with no current entry.
		 */
		_FORCE_INLINE_ ConstIterator() {}
		/**
		 * Copies the source iterator's position.
		 */
		_FORCE_INLINE_ ConstIterator(const ConstIterator &p_it) { E = p_it.E; }
		/**
		 * Sets the iterator to the source iterator's position.
		 */
		_FORCE_INLINE_ void operator=(const ConstIterator &p_it) {
			E = p_it.E;
		}

	private:
		/**
		 * Points to the current node, or is null at the end.
		 */
		const HashMapElement<TKey, TValue> *E = nullptr;
	};

	/**
	 * Traverses the map's linked entries with writable access to values.
	 */
	struct Iterator {
		/**
		 * Returns a reference to the current entry. The iterator must be on an entry.
		 */
		_FORCE_INLINE_ KeyValue<TKey, TValue> &operator*() const {
			return E->data;
		}
		/**
		 * Returns a pointer to the current entry.
		 */
		_FORCE_INLINE_ KeyValue<TKey, TValue> *operator->() const { return &E->data; }
		/**
		 * Advances to the next entry. Advancing past the last entry reaches the end.
		 */
		_FORCE_INLINE_ Iterator &operator++() {
			if (E) {
				E = E->next;
			}
			return *this;
		}
		/**
		 * Moves to the previous node. A null node pointer stays null.
		 */
		_FORCE_INLINE_ Iterator &operator--() {
			if (E) {
				E = E->prev;
			}
			return *this;
		}

		/**
		 * Tests whether the iterators point to the same node.
		 */
		_FORCE_INLINE_ bool operator==(const Iterator &b) const { return E == b.E; }
		/**
		 * Tests whether the iterators point to different nodes.
		 */
		_FORCE_INLINE_ bool operator!=(const Iterator &b) const { return E != b.E; }

		/**
		 * Returns whether the iterator is at an entry rather than the end.
		 */
		_FORCE_INLINE_ explicit operator bool() const {
			return E != nullptr;
		}

		/**
		 * Starts at the supplied node. A null pointer marks the end.
		 */
		_FORCE_INLINE_ Iterator(HashMapElement<TKey, TValue> *p_E) { E = p_E; }
		/**
		 * Creates an iterator with no current entry.
		 */
		_FORCE_INLINE_ Iterator() {}
		/**
		 * Copies the source iterator's position.
		 */
		_FORCE_INLINE_ Iterator(const Iterator &p_it) { E = p_it.E; }
		/**
		 * Sets the iterator to the source iterator's position.
		 */
		_FORCE_INLINE_ void operator=(const Iterator &p_it) {
			E = p_it.E;
		}

		/**
		 * Creates a read-only iterator at the same node.
		 */
		operator ConstIterator() const {
			return ConstIterator(E);
		}

	private:
		/**
		 * Points to the current node, or is null at the end.
		 */
		HashMapElement<TKey, TValue> *E = nullptr;
	};

	/**
	 * Returns a writable iterator to the first entry, or the end sentinel for an empty map.
	 */
	_FORCE_INLINE_ Iterator begin() _LIFETIME_BOUND_ {
		return Iterator(_head_element);
	}
	/**
	 * Returns the writable end sentinel, which holds a null node pointer.
	 */
	_FORCE_INLINE_ Iterator end() _LIFETIME_BOUND_ {
		return Iterator(nullptr);
	}
	/**
	 * Returns a writable iterator to the last entry, or the end sentinel for an empty map.
	 */
	_FORCE_INLINE_ Iterator last() _LIFETIME_BOUND_ {
		return Iterator(_tail_element);
	}

	/**
	 * Returns a writable iterator to the key's entry, or the end sentinel if absent.
	 */
	_FORCE_INLINE_ Iterator find(const TKey &p_key) _LIFETIME_BOUND_ {
		uint32_t idx = 0;
		bool exists = _lookup_idx(p_key, idx);
		if (!exists) {
			return end();
		}
		return Iterator(_elements[idx]);
	}

	/**
	 * Erases the key referred to by the iterator. An end iterator has no effect.
	 */
	_FORCE_INLINE_ void remove(const Iterator &p_iter) {
		if (p_iter) {
			erase(p_iter->key);
		}
	}

	/**
	 * Returns a read-only iterator to the first entry, or the end sentinel for an empty map.
	 */
	_FORCE_INLINE_ ConstIterator begin() const _LIFETIME_BOUND_ {
		return ConstIterator(_head_element);
	}
	/**
	 * Returns the read-only end sentinel, which holds a null node pointer.
	 */
	_FORCE_INLINE_ ConstIterator end() const _LIFETIME_BOUND_ {
		return ConstIterator(nullptr);
	}
	/**
	 * Returns a read-only iterator to the last entry, or the end sentinel for an empty map.
	 */
	_FORCE_INLINE_ ConstIterator last() const _LIFETIME_BOUND_ {
		return ConstIterator(_tail_element);
	}

	/**
	 * Returns a read-only iterator to the key's entry, or the end sentinel if absent.
	 */
	_FORCE_INLINE_ ConstIterator find(const TKey &p_key) const _LIFETIME_BOUND_ {
		uint32_t idx = 0;
		bool exists = _lookup_idx(p_key, idx);
		if (!exists) {
			return end();
		}
		return ConstIterator(_elements[idx]);
	}

	/* Indexing */

	/**
	 * Returns a read-only reference to an existing value. An absent key triggers a crash check.
	 */
	const TValue &operator[](const TKey &p_key) const _LIFETIME_BOUND_ {
		uint32_t idx = 0;
		bool exists = _lookup_idx(p_key, idx);
		CRASH_COND(!exists);
		return _elements[idx]->data.value;
	}

	/**
	 * Returns a writable reference to the value. Inserts a value-initialized entry at the tail if the key is absent.
	 */
	TValue &operator[](const TKey &p_key) _LIFETIME_BOUND_ {
		const uint32_t hash = _hash(p_key);
		uint32_t idx = 0;
		bool exists = _elements && _size > 0 && _lookup_idx_unchecked(p_key, hash, idx);
		if (!exists) {
			return _insert(p_key, TValue(), hash)->data.value;
		} else {
			return _elements[idx]->data.value;
		}
	}

	/* Insert */

	/**
	 * Returns an iterator to the inserted or updated entry. For a new key, `p_front_insert` selects the head of the iteration list instead of the tail.
	 */
	Iterator insert(const TKey &p_key, const TValue &p_value, bool p_front_insert = false) {
		const uint32_t hash = _hash(p_key);
		uint32_t idx = 0;
		bool exists = _elements && _size > 0 && _lookup_idx_unchecked(p_key, hash, idx);
		if (!exists) {
			return Iterator(_insert(p_key, p_value, hash, p_front_insert));
		} else {
			_elements[idx]->data.value = p_value;
			return Iterator(_elements[idx]);
		}
	}

	/* Constructors */

	/**
	 * Copies the source entries into newly allocated nodes in their iteration order.
	 */
	explicit HashMap(const HashMap &p_other) {
		reserve(hash_table_size_primes[p_other._capacity_idx]);

		if (p_other._size == 0) {
			return;
		}

		for (const KeyValue<TKey, TValue> &E : p_other) {
			insert(E.key, E.value);
		}
	}

	/**
	 * Takes the source's bucket arrays and nodes and leaves the source empty.
	 */
	HashMap(HashMap &&p_other) {
		_elements = p_other._elements;
		_hashes = p_other._hashes;
		_head_element = p_other._head_element;
		_tail_element = p_other._tail_element;
		_capacity_idx = p_other._capacity_idx;
		_size = p_other._size;

		p_other._elements = nullptr;
		p_other._hashes = nullptr;
		p_other._head_element = nullptr;
		p_other._tail_element = nullptr;
		p_other._capacity_idx = MIN_CAPACITY_INDEX;
		p_other._size = 0;
	}

	/**
	 * Replaces the entries with copies from the source in iteration order. May retain a larger bucket allocation.
	 */
	void operator=(const HashMap &p_other) {
		if (this == &p_other) {
			return; // Ignore self assignment.
		}
		if (_size != 0) {
			clear();
		}

		reserve(hash_table_size_primes[p_other._capacity_idx]);

		if (p_other._elements == nullptr) {
			return; // Nothing to copy.
		}

		for (const KeyValue<TKey, TValue> &E : p_other) {
			insert(E.key, E.value);
		}
	}

	/**
	 * Destroys the old entries, takes the source's allocations, and leaves the source empty.
	 */
	HashMap &operator=(HashMap &&p_other) {
		if (this == &p_other) {
			return *this;
		}

		if (_size != 0) {
			clear();
		}
		if (_elements != nullptr) {
			Memory::free_static(_elements);
			Memory::free_static(_hashes);
		}

		_elements = p_other._elements;
		_hashes = p_other._hashes;
		_head_element = p_other._head_element;
		_tail_element = p_other._tail_element;
		_capacity_idx = p_other._capacity_idx;
		_size = p_other._size;

		p_other._elements = nullptr;
		p_other._hashes = nullptr;
		p_other._head_element = nullptr;
		p_other._tail_element = nullptr;
		p_other._capacity_idx = MIN_CAPACITY_INDEX;
		p_other._size = 0;

		return *this;
	}

	/**
	 * Selects a starting bucket count and defers allocation.
	 */
	HashMap(uint32_t p_initial_capacity) {
		// Capacity can't be 0.
		_capacity_idx = 0;
		reserve(p_initial_capacity);
	}
	/**
	 * Creates an empty map with the default bucket count and no allocation.
	 */
	HashMap() {
		_capacity_idx = MIN_CAPACITY_INDEX;
	}

	/**
	 * Inserts the listed pairs in order. A repeated key keeps its first position and receives the last value.
	 */
	HashMap(std::initializer_list<KeyValue<TKey, TValue>> p_init) {
		reserve(p_init.size());
		for (const KeyValue<TKey, TValue> &E : p_init) {
			insert(E.key, E.value);
		}
	}

	/**
	 * Returns the stored hash at the debug bucket index, or zero for an empty map or an out-of-range index.
	 */
	uint32_t debug_get_hash(uint32_t p_idx) {
		if (_size == 0) {
			return 0;
		}
		ERR_FAIL_INDEX_V(p_idx, get_capacity(), 0);
		return _hashes[p_idx];
	}
	/**
	 * Returns an iterator for inspecting a debug bucket. The caller must verify that a bucket in a nonempty table is occupied.
	 */
	Iterator debug_get_element(uint32_t p_idx) {
		if (_size == 0) {
			return Iterator();
		}
		ERR_FAIL_INDEX_V(p_idx, get_capacity(), Iterator());
		return Iterator(_elements[p_idx]);
	}

	/**
	 * Destroys the entries through the allocator and frees the bucket arrays.
	 */
	~HashMap() {
		_clear_data();

		if (_elements != nullptr) {
			Memory::free_static(_elements);
			Memory::free_static(_hashes);
		}
	}
};

} // namespace godot
