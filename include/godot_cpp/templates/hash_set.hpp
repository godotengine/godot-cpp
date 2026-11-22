/**************************************************************************/
/*  hash_set.hpp                                                          */
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

namespace godot {

/**
 * Set container using robin hood hashing.
 *
 * Elements are not pointer stable.
 * The element order is arbitrary.
 *
 * Core container guidance:
 * https://docs.godotengine.org/en/latest/engine_details/architecture/core_types.html#containers
 */
template <typename TKey,
		typename Hasher = HashMapHasherDefault,
		typename Comparator = HashMapComparatorDefault<TKey>>
class _WARN_UNUSED_ HashSet {
public:
	/**
	 * Index of the default minimum bucket count in `godot::hash_table_size_primes`.
	 */
	static constexpr uint32_t MIN_CAPACITY_INDEX = 2; // Use a prime.
	/**
	 * Maximum occupied fraction of the table before a new insertion grows it.
	 */
	static constexpr float MAX_OCCUPANCY = 0.75;
	/**
	 * Hash reserved for an empty bucket.
	 */
	static constexpr uint32_t EMPTY_HASH = 0;

private:
	/**
	 * Owns the contiguous array of stored keys.
	 */
	TKey *_keys = nullptr;
	/**
	 * Maps occupied hash bucket indices to packed key indices.
	 */
	uint32_t *_hash_idx_to_key_idx = nullptr;
	/**
	 * Maps packed key indices to their occupied hash buckets.
	 */
	uint32_t *_key_idx_to_hash_idx = nullptr;
	/**
	 * Stores the remapped hash for each bucket. Zero marks a vacant bucket.
	 */
	uint32_t *_hashes = nullptr;

	/**
	 * Selects the bucket count and reciprocal from the supported table sizes.
	 */
	uint32_t _capacity_idx = 0;
	/**
	 * Counts the live keys at the start of the packed array.
	 */
	uint32_t _size = 0;

	/**
	 * Hashes a key and remaps zero to one to preserve the empty-bucket marker.
	 */
	_FORCE_INLINE_ uint32_t _hash(const TKey &p_key) const {
		uint32_t hash = Hasher::hash(p_key);

		if (unlikely(hash == EMPTY_HASH)) {
			hash = EMPTY_HASH + 1;
		}

		return hash;
	}

	/**
	 * Advances the bucket index and wraps to zero when it reaches the bucket count.
	 */
	_FORCE_INLINE_ static constexpr void _increment_mod(uint32_t &r_idx, const uint32_t p_capacity) {
		r_idx++;
		// `if` is faster than both fastmod and mod.
		if (unlikely(r_idx == p_capacity)) {
			r_idx = 0;
		}
	}

	/**
	 * Computes the forward distance from a key's starting bucket to its current bucket, with wraparound.
	 */
	static _FORCE_INLINE_ uint32_t _get_probe_length(const uint32_t p_hash_idx, const uint32_t p_hash, const uint32_t p_capacity, const uint64_t p_capacity_inv) {
		const uint32_t original_idx = fastmod(p_hash, p_capacity_inv, p_capacity);
		const uint32_t distance_idx = p_hash_idx - original_idx + p_capacity;
		// At most p_capacity over 0, so we can use an if (faster than fastmod).
		return distance_idx >= p_capacity ? distance_idx - p_capacity : distance_idx;
	}

	/**
	 * Looks up a key and writes its packed array index when found.
	 */
	bool _lookup_key_idx(const TKey &p_key, uint32_t &r_key_idx) const {
		if (_keys == nullptr || _size == 0) {
			return false; // Failed lookups, no elements
		}

		const uint32_t capacity = hash_table_size_primes[_capacity_idx];
		const uint64_t capacity_inv = hash_table_size_primes_inv[_capacity_idx];
		uint32_t hash = _hash(p_key);
		uint32_t hash_idx = fastmod(hash, capacity_inv, capacity);
		uint32_t distance = 0;

		while (true) {
			if (_hashes[hash_idx] == EMPTY_HASH) {
				return false;
			}

			if (_hashes[hash_idx] == hash && Comparator::compare(_keys[_hash_idx_to_key_idx[hash_idx]], p_key)) {
				r_key_idx = _hash_idx_to_key_idx[hash_idx];
				return true;
			}

			if (distance > _get_probe_length(hash_idx, _hashes[hash_idx], capacity, capacity_inv)) {
				return false;
			}

			_increment_mod(hash_idx, capacity);
			distance++;
		}
	}

	/**
	 * Inserts a hash and packed key index, updating both index maps as Robin Hood probing displaces entries. Returns the last bucket filled.
	 */
	uint32_t _insert_with_hash(uint32_t p_hash, uint32_t p_key_idx) {
		const uint32_t capacity = hash_table_size_primes[_capacity_idx];
		const uint64_t capacity_inv = hash_table_size_primes_inv[_capacity_idx];
		uint32_t hash = p_hash;
		uint32_t key_idx = p_key_idx;
		uint32_t distance = 0;
		uint32_t hash_idx = fastmod(hash, capacity_inv, capacity);

		while (true) {
			if (_hashes[hash_idx] == EMPTY_HASH) {
				_hashes[hash_idx] = hash;
				_key_idx_to_hash_idx[key_idx] = hash_idx;
				_hash_idx_to_key_idx[hash_idx] = key_idx;
				return hash_idx;
			}

			// Not an empty slot, let's check the probing length of the existing one.
			uint32_t existing_probe_len = _get_probe_length(hash_idx, _hashes[hash_idx], capacity, capacity_inv);
			if (existing_probe_len < distance) {
				_key_idx_to_hash_idx[key_idx] = hash_idx;
				SWAP(hash, _hashes[hash_idx]);
				SWAP(key_idx, _hash_idx_to_key_idx[hash_idx]);
				distance = existing_probe_len;
			}

			_increment_mod(hash_idx, capacity);
			distance++;
		}
	}

	/**
	 * Resizes the arrays and rebuilds the bucket indices from existing hashes.
	 */
	void _resize_and_rehash(uint32_t p_new_capacity_idx) {
		// Capacity can't be 0.
		_capacity_idx = MAX((uint32_t)MIN_CAPACITY_INDEX, p_new_capacity_idx);

		uint32_t capacity = hash_table_size_primes[_capacity_idx];

		uint32_t *old_hashes = _hashes;
		uint32_t *old_key_to_hash = _key_idx_to_hash_idx;

		static_assert(EMPTY_HASH == 0, "Assuming EMPTY_HASH = 0 for alloc_static_zeroed call");
		_hashes = reinterpret_cast<uint32_t *>(Memory::alloc_static_zeroed(sizeof(uint32_t) * capacity));
		_keys = reinterpret_cast<TKey *>(Memory::realloc_static(_keys, sizeof(TKey) * capacity));
		_key_idx_to_hash_idx = reinterpret_cast<uint32_t *>(Memory::alloc_static(sizeof(uint32_t) * capacity));
		_hash_idx_to_key_idx = reinterpret_cast<uint32_t *>(Memory::realloc_static(_hash_idx_to_key_idx, sizeof(uint32_t) * capacity));

		for (uint32_t i = 0; i < _size; i++) {
			uint32_t h = old_hashes[old_key_to_hash[i]];
			_insert_with_hash(h, i);
		}

		Memory::free_static(old_hashes);
		Memory::free_static(old_key_to_hash);
	}

	// Returns key index.
	/**
	 * Returns the existing or newly appended key's packed index. Returns `-1` when the table cannot grow further.
	 */
	_FORCE_INLINE_ int32_t _insert(const TKey &p_key) {
		uint32_t capacity = hash_table_size_primes[_capacity_idx];
		if (unlikely(_keys == nullptr)) {
			// Allocate on demand to save memory.

			static_assert(EMPTY_HASH == 0, "Assuming EMPTY_HASH = 0 for alloc_static_zeroed call");
			_hashes = reinterpret_cast<uint32_t *>(Memory::alloc_static_zeroed(sizeof(uint32_t) * capacity));
			_keys = reinterpret_cast<TKey *>(Memory::alloc_static(sizeof(TKey) * capacity));
			_key_idx_to_hash_idx = reinterpret_cast<uint32_t *>(Memory::alloc_static(sizeof(uint32_t) * capacity));
			_hash_idx_to_key_idx = reinterpret_cast<uint32_t *>(Memory::alloc_static(sizeof(uint32_t) * capacity));
		}

		uint32_t key_idx = 0;
		bool exists = _lookup_key_idx(p_key, key_idx);

		if (exists) {
			return key_idx;
		} else {
			if (_size + 1 > MAX_OCCUPANCY * capacity) {
				ERR_FAIL_COND_V_MSG(_capacity_idx + 1 == HASH_TABLE_SIZE_MAX, -1, "Hash table maximum capacity reached, aborting insertion.");
				_resize_and_rehash(_capacity_idx + 1);
			}

			uint32_t hash = _hash(p_key);
			memnew_placement(&_keys[_size], TKey(p_key));
			_insert_with_hash(hash, _size);
			_size++;
			return _size - 1;
		}
	}

	/**
	 * Copies another set's keys and bucket mappings into unallocated storage.
	 */
	void _init_from(const HashSet &p_other) {
		_capacity_idx = p_other._capacity_idx;
		_size = p_other._size;

		if (p_other._size == 0) {
			return;
		}

		uint32_t capacity = hash_table_size_primes[_capacity_idx];

		_hashes = reinterpret_cast<uint32_t *>(Memory::alloc_static(sizeof(uint32_t) * capacity));
		_keys = reinterpret_cast<TKey *>(Memory::alloc_static(sizeof(TKey) * capacity));
		_key_idx_to_hash_idx = reinterpret_cast<uint32_t *>(Memory::alloc_static(sizeof(uint32_t) * capacity));
		_hash_idx_to_key_idx = reinterpret_cast<uint32_t *>(Memory::alloc_static(sizeof(uint32_t) * capacity));

		for (uint32_t i = 0; i < _size; i++) {
			memnew_placement(&_keys[i], TKey(p_other._keys[i]));
			_key_idx_to_hash_idx[i] = p_other._key_idx_to_hash_idx[i];
		}

		for (uint32_t i = 0; i < capacity; i++) {
			_hashes[i] = p_other._hashes[i];
			_hash_idx_to_key_idx[i] = p_other._hash_idx_to_key_idx[i];
		}
	}

public:
	/**
	 * Returns the selected bucket count, even before storage allocation.
	 */
	_FORCE_INLINE_ uint32_t get_capacity() const { return hash_table_size_primes[_capacity_idx]; }
	/**
	 * Returns the number of unique keys.
	 */
	_FORCE_INLINE_ uint32_t size() const { return _size; }

	/* Standard Godot Container API */

	/**
	 * Returns whether the set contains no keys.
	 */
	bool is_empty() const {
		return _size == 0;
	}

	/**
	 * Destroys all keys and marks the table empty while retaining the allocation.
	 */
	void clear() {
		if (_keys == nullptr || _size == 0) {
			return;
		}

		uint32_t capacity = hash_table_size_primes[_capacity_idx];
		memset(_hashes, EMPTY_HASH, sizeof(EMPTY_HASH) * capacity);

		if constexpr (!std::is_trivially_destructible_v<TKey>) {
			for (uint32_t i = 0; i < _size; i++) {
				_keys[i].~TKey();
			}
		}

		_size = 0;
	}

	/**
	 * Returns whether the set contains the key.
	 */
	_FORCE_INLINE_ bool has(const TKey &p_key) const {
		uint32_t _idx = 0;
		return _lookup_key_idx(p_key, _idx);
	}

	/**
	 * Removes the key and returns whether it existed. If needed, moves the last key into the gap to keep storage packed.
	 */
	bool erase(const TKey &p_key) {
		uint32_t key_idx = 0;
		bool exists = _lookup_key_idx(p_key, key_idx);

		if (!exists) {
			return false;
		}

		uint32_t hash_idx = _key_idx_to_hash_idx[key_idx];

		const uint32_t capacity = hash_table_size_primes[_capacity_idx];
		const uint64_t capacity_inv = hash_table_size_primes_inv[_capacity_idx];
		uint32_t next_hash_idx = fastmod(hash_idx + 1, capacity_inv, capacity);
		while (_hashes[next_hash_idx] != EMPTY_HASH && _get_probe_length(next_hash_idx, _hashes[next_hash_idx], capacity, capacity_inv) != 0) {
			uint32_t cur_key_idx = _hash_idx_to_key_idx[hash_idx];
			uint32_t next_key_idx = _hash_idx_to_key_idx[next_hash_idx];
			SWAP(_key_idx_to_hash_idx[cur_key_idx], _key_idx_to_hash_idx[next_key_idx]);
			SWAP(_hashes[next_hash_idx], _hashes[hash_idx]);
			SWAP(_hash_idx_to_key_idx[next_hash_idx], _hash_idx_to_key_idx[hash_idx]);

			hash_idx = next_hash_idx;
			_increment_mod(next_hash_idx, capacity);
		}

		_hashes[hash_idx] = EMPTY_HASH;
		_keys[key_idx].~TKey();
		_size--;
		if (key_idx < _size) {
			// Not the last key, move the last one here to keep keys contiguous.
			memnew_placement(&_keys[key_idx], TKey(_keys[_size]));
			_keys[_size].~TKey();
			_key_idx_to_hash_idx[key_idx] = _key_idx_to_hash_idx[_size];
			_hash_idx_to_key_idx[_key_idx_to_hash_idx[_size]] = key_idx;
		}

		return true;
	}

	// Reserves space for a number of elements, useful to avoid many resizes and rehashes.
	// If adding a known (possibly large) number of elements at once, must be larger than old capacity.
	/**
	 * Grows the selected bucket count to a supported size that meets the request. Defers allocation when the keys have no storage yet.
	 */
	void reserve(uint32_t p_new_capacity) {
		uint32_t new_capacity_idx = _capacity_idx;

		while (hash_table_size_primes[new_capacity_idx] < p_new_capacity) {
			ERR_FAIL_COND_MSG(new_capacity_idx + 1 == (uint32_t)HASH_TABLE_SIZE_MAX, nullptr);
			new_capacity_idx++;
		}

		if (new_capacity_idx == _capacity_idx) {
			if (p_new_capacity < _size) {
				WARN_VERBOSE("reserve() called with a capacity smaller than the current size. This is likely a mistake.");
			}
			return;
		}

		if (_keys == nullptr) {
			_capacity_idx = new_capacity_idx;
			return; // Unallocated yet.
		}
		_resize_and_rehash(new_capacity_idx);
	}

	/** Iterator API **/

	/**
	 * Traverses the packed array with read-only access to keys. Growth can invalidate the iterator and erasing can move the last key.
	 */
	struct Iterator {
		/**
		 * Returns a reference to the current key. The iterator must be on a key.
		 */
		_FORCE_INLINE_ const TKey &operator*() const {
			return _keys[_key_idx];
		}
		/**
		 * Returns a pointer to the current key. The iterator must be on a key.
		 */
		_FORCE_INLINE_ const TKey *operator->() const {
			return &_keys[_key_idx];
		}
		/**
		 * Advances to the next packed key and resets to the end sentinel after the last key.
		 */
		_FORCE_INLINE_ Iterator &operator++() {
			_key_idx++;
			if (_key_idx >= (int32_t)_num_keys) {
				_key_idx = -1;
				_keys = nullptr;
				_num_keys = 0;
			}
			return *this;
		}
		/**
		 * Moves to the previous packed key and resets to the end sentinel before the first key.
		 */
		_FORCE_INLINE_ Iterator &operator--() {
			_key_idx--;
			if (_key_idx < 0) {
				_key_idx = -1;
				_keys = nullptr;
				_num_keys = 0;
			}
			return *this;
		}

		/**
		 * Tests whether the iterators refer to the same key array and index.
		 */
		_FORCE_INLINE_ bool operator==(const Iterator &p_other) const { return _keys == p_other._keys && _key_idx == p_other._key_idx; }
		/**
		 * Tests whether the iterators differ in key array or index.
		 */
		_FORCE_INLINE_ bool operator!=(const Iterator &p_other) const { return _keys != p_other._keys || _key_idx != p_other._key_idx; }

		/**
		 * Returns whether the iterator holds a key array pointer.
		 */
		_FORCE_INLINE_ explicit operator bool() const {
			return _keys != nullptr;
		}

		/**
		 * Records the key array, the number of keys, and the initial index.
		 */
		_FORCE_INLINE_ Iterator(const TKey *p_keys, uint32_t p_num_keys, int32_t p_key_idx = -1) {
			_keys = p_keys;
			_num_keys = p_num_keys;
			_key_idx = p_key_idx;
		}
		/**
		 * Creates an end iterator with no key array.
		 */
		_FORCE_INLINE_ Iterator() {}
		/**
		 * Copies the source iterator's array, range size, and index.
		 */
		_FORCE_INLINE_ Iterator(const Iterator &p_it) {
			_keys = p_it._keys;
			_num_keys = p_it._num_keys;
			_key_idx = p_it._key_idx;
		}
		/**
		 * Replaces this iterator's array, range size, and index with the source's.
		 */
		_FORCE_INLINE_ void operator=(const Iterator &p_it) {
			_keys = p_it._keys;
			_num_keys = p_it._num_keys;
			_key_idx = p_it._key_idx;
		}

	private:
		/**
		 * Points to the packed keys for the iteration range, or is null for the end sentinel.
		 */
		const TKey *_keys = nullptr;
		/**
		 * Stores the number of keys captured for iteration.
		 */
		uint32_t _num_keys = 0;
		/**
		 * Stores the current packed key index. The end sentinel uses `-1`.
		 */
		int32_t _key_idx = -1;
	};

	/**
	 * Returns an iterator to the first packed key, or the end sentinel for an empty set.
	 */
	_FORCE_INLINE_ Iterator begin() const _LIFETIME_BOUND_ {
		return _size ? Iterator(_keys, _size, 0) : Iterator();
	}
	/**
	 * Returns the end sentinel with no key array.
	 */
	_FORCE_INLINE_ Iterator end() const _LIFETIME_BOUND_ {
		return Iterator();
	}
	/**
	 * Returns an iterator to the last key, or the end sentinel for an empty set.
	 */
	_FORCE_INLINE_ Iterator last() const _LIFETIME_BOUND_ {
		if (_size == 0) {
			return Iterator();
		}
		return Iterator(_keys, _size, _size - 1);
	}

	/**
	 * Returns an iterator to the key, or the end sentinel if it is absent.
	 */
	_FORCE_INLINE_ Iterator find(const TKey &p_key) const _LIFETIME_BOUND_ {
		uint32_t key_idx = 0;
		bool exists = _lookup_key_idx(p_key, key_idx);
		if (!exists) {
			return end();
		}
		return Iterator(_keys, _size, key_idx);
	}

	/**
	 * Erases the key at the iterator's position. The end sentinel has no effect.
	 */
	_FORCE_INLINE_ void remove(const Iterator &p_iter) {
		if (p_iter) {
			erase(*p_iter);
		}
	}

	/* Insert */

	/**
	 * Inserts the key if absent and returns an iterator to the corresponding packed position.
	 */
	Iterator insert(const TKey &p_key) _LIFETIME_BOUND_ {
		uint32_t key_idx = _insert(p_key);
		return Iterator(_keys, _size, key_idx);
	}

	/* Constructors */

	/**
	 * Creates an independent copy of the keys and bucket mappings.
	 */
	explicit HashSet(const HashSet &p_other) {
		_init_from(p_other);
	}

	/**
	 * Takes ownership of the source arrays and leaves the source empty.
	 */
	HashSet(HashSet &&p_other) {
		_keys = p_other._keys;
		_hash_idx_to_key_idx = p_other._hash_idx_to_key_idx;
		_key_idx_to_hash_idx = p_other._key_idx_to_hash_idx;
		_hashes = p_other._hashes;

		_capacity_idx = p_other._capacity_idx;
		_size = p_other._size;

		p_other._keys = nullptr;
		p_other._hash_idx_to_key_idx = nullptr;
		p_other._hashes = nullptr;
		p_other._key_idx_to_hash_idx = nullptr;

		p_other._capacity_idx = 0;
		p_other._size = 0;
	}

	/**
	 * Destroys the old keys and storage and copies the source set, unless assigned to itself.
	 */
	void operator=(const HashSet &p_other) {
		if (this == &p_other) {
			return; // Ignore self assignment.
		}

		clear();

		if (_keys != nullptr) {
			Memory::free_static(_keys);
			Memory::free_static(_key_idx_to_hash_idx);
			Memory::free_static(_hash_idx_to_key_idx);
			Memory::free_static(_hashes);
			_keys = nullptr;
			_hashes = nullptr;
			_hash_idx_to_key_idx = nullptr;
			_key_idx_to_hash_idx = nullptr;
		}

		_init_from(p_other);
	}

	/**
	 * Exchanges the key arrays, bucket tables, and counts with the source set.
	 */
	void operator=(HashSet &&p_other) {
		if (this == &p_other) {
			return; // Ignore self assignment.
		}

		SWAP(_keys, p_other._keys);
		SWAP(_hash_idx_to_key_idx, p_other._hash_idx_to_key_idx);
		SWAP(_key_idx_to_hash_idx, p_other._key_idx_to_hash_idx);
		SWAP(_hashes, p_other._hashes);

		SWAP(_capacity_idx, p_other._capacity_idx);
		SWAP(_size, p_other._size);
	}

	/**
	 * Returns whether both sets contain the same keys, regardless of iteration order.
	 */
	bool operator==(const HashSet &p_other) const {
		if (_size != p_other._size) {
			return false;
		}
		for (uint32_t i = 0; i < _size; i++) {
			if (!p_other.has(_keys[i])) {
				return false;
			}
		}
		return true;
	}
	/**
	 * Returns whether the sets differ in membership.
	 */
	bool operator!=(const HashSet &p_other) const {
		return !(*this == p_other);
	}

	/**
	 * Selects the initial bucket count for an empty set and defers allocation.
	 */
	HashSet(uint32_t p_initial_capacity) {
		// Capacity can't be 0.
		_capacity_idx = 0;
		reserve(p_initial_capacity);
	}
	/**
	 * Creates an empty set with the default bucket count and no allocated arrays.
	 */
	HashSet() {
		_capacity_idx = MIN_CAPACITY_INDEX;
	}
	/**
	 * Inserts all listed keys, keeping one entry per unique key.
	 */
	HashSet(std::initializer_list<TKey> p_init) {
		reserve(p_init.size());
		for (const TKey &E : p_init) {
			insert(E);
		}
	}

	/**
	 * Destroys the keys, frees the arrays, and restores the default bucket count.
	 */
	void reset() {
		clear();

		if (_keys != nullptr) {
			Memory::free_static(_keys);
			Memory::free_static(_key_idx_to_hash_idx);
			Memory::free_static(_hash_idx_to_key_idx);
			Memory::free_static(_hashes);
			_keys = nullptr;
			_hashes = nullptr;
			_hash_idx_to_key_idx = nullptr;
			_key_idx_to_hash_idx = nullptr;
		}
		_capacity_idx = MIN_CAPACITY_INDEX;
	}

	/**
	 * Destroys any live keys and frees the set's arrays.
	 */
	~HashSet() {
		clear();

		if (_keys != nullptr) {
			Memory::free_static(_keys);
			Memory::free_static(_key_idx_to_hash_idx);
			Memory::free_static(_hash_idx_to_key_idx);
			Memory::free_static(_hashes);
		}
	}
};

} // namespace godot
