/**************************************************************************/
/*  local_vector.hpp                                                      */
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
#include <godot_cpp/core/math_funcs_binary.hpp>
#include <godot_cpp/core/memory.hpp>
#include <godot_cpp/templates/sort_array.hpp>
#include <godot_cpp/templates/span.hpp>
#include <godot_cpp/templates/vector.hpp>

#include <initializer_list>
#include <type_traits>

namespace godot {

// If tight, it grows strictly as much as needed.
// Otherwise, it grows exponentially (the default and what you want in most cases).
/**
 * Owns a contiguous growable array without shared storage.
 *
 * - `U` — Unsigned index, count, and capacity type.
 * - `force_trivial` — Reserved for source compatibility and must be false.
 * - `tight` — Grows capacity to the requested size instead of using geometric growth.
 */
template <typename T, typename U = uint32_t, bool force_trivial = false, bool tight = false>
class LocalVector {
	static_assert(!force_trivial, "force_trivial is no longer supported. Use resize_uninitialized instead.");

private:
	/**
	 * Counts the live elements.
	 */
	U count = 0;
	/**
	 * Counts the allocated element slots.
	 */
	U capacity = 0;
	/**
	 * Owns the allocation containing the live elements.
	 */
	T *data = nullptr;

	/**
	 * Changes the live range, destroying removed elements when required. `p_init` controls construction of newly added elements.
	 */
	template <bool p_init>
	void _resize(U p_size) {
		if (p_size < count) {
			if constexpr (!std::is_trivially_destructible_v<T>) {
				for (U i = p_size; i < count; i++) {
					data[i].~T();
				}
			}
			count = p_size;
		} else if (p_size > count) {
			reserve(p_size);
			if constexpr (p_init) {
				memnew_arr_placement(data + count, p_size - count);
			} else {
				static_assert(std::is_trivially_destructible_v<T>, "T must be trivially destructible to resize uninitialized");
			}
			count = p_size;
		}
	}

public:
	/**
	 * Returns the writable start of the owned buffer.
	 */
	_FORCE_INLINE_ T *ptr() _LIFETIME_BOUND_ { return data; }
	/**
	 * Returns the read-only start of the owned buffer.
	 */
	_FORCE_INLINE_ const T *ptr() const _LIFETIME_BOUND_ { return data; }
	/**
	 * Returns the live element count.
	 */
	_FORCE_INLINE_ U size() const { return count; }

	/**
	 * Returns a borrowed read-only view of the current element range.
	 */
	_FORCE_INLINE_ Span<T> span() const _LIFETIME_BOUND_ { return Span(data, count); }
	/**
	 * Converts to a borrowed read-only view of the current element range.
	 */
	_FORCE_INLINE_ operator Span<T>() const _LIFETIME_BOUND_ { return span(); }

	// Must take a copy instead of a reference (see GH-31736).
	/**
	 * Appends an element by moving a local copy into storage, growing the buffer if needed.
	 */
	_FORCE_INLINE_ void push_back(T p_elem) {
		if (unlikely(count == capacity)) {
			reserve(count + 1);
		}

		memnew_placement(&data[count++], T(std::move(p_elem)));
	}

	/**
	 * Erases the indexed element and shifts following elements to preserve their order.
	 */
	void remove_at(U p_index) {
		ERR_FAIL_UNSIGNED_INDEX(p_index, count);
		count--;
		for (U i = p_index; i < count; i++) {
			data[i] = std::move(data[i + 1]);
		}
		data[count].~T();
	}

	/// Removes the item copying the last value into the position of the one to
	/// remove. It's generally faster than `remove_at`.
	void remove_at_unordered(U p_index) {
		ERR_FAIL_INDEX(p_index, count);
		count--;
		if (count > p_index) {
			data[p_index] = std::move(data[count]);
		}
		data[count].~T();
	}

	/**
	 * Erases the first equal value and returns whether it found a match. Preserves the order of the remaining elements.
	 */
	_FORCE_INLINE_ bool erase(const T &p_val) {
		int64_t idx = find(p_val);
		if (idx >= 0) {
			remove_at(idx);
			return true;
		}
		return false;
	}

	/**
	 * Erases the first equal value and returns whether it found a match. Moves the last element into the gap if needed.
	 */
	bool erase_unordered(const T &p_val) {
		int64_t idx = find(p_val);
		if (idx >= 0) {
			remove_at_unordered(idx);
			return true;
		}
		return false;
	}

	/**
	 * Erases all equal values without preserving order and returns the number removed.
	 */
	U erase_multiple_unordered(const T &p_val) {
		U from = 0;
		U occurrences = 0;
		while (true) {
			int64_t idx = find(p_val, from);

			if (idx == -1) {
				break;
			}
			remove_at_unordered(idx);
			from = idx;
			occurrences++;
		}
		return occurrences;
	}

	/**
	 * Reverses the order of the stored elements in place.
	 */
	void reverse() {
		for (U i = 0; i < count / 2; i++) {
			SWAP(data[i], data[count - i - 1]);
		}
	}
#ifndef DISABLE_DEPRECATED
	/**
	 * Reverses the elements in place. This spelling is kept for source compatibility.
	 */
	[[deprecated("Use reverse() instead")]] void invert() { reverse(); }
#endif

	/**
	 * Destroys the elements while retaining the allocation for reuse.
	 */
	_FORCE_INLINE_ void clear() { resize(0); }
	/**
	 * Destroys the elements and releases the allocated buffer.
	 */
	_FORCE_INLINE_ void reset() {
		clear();
		if (data) {
			memfree(data);
			data = nullptr;
			capacity = 0;
		}
	}
	/**
	 * Returns whether there are no live elements.
	 */
	_FORCE_INLINE_ bool is_empty() const { return count == 0; }
	/**
	 * Returns the allocated capacity in elements.
	 */
	_FORCE_INLINE_ U get_capacity() const { return capacity; }
	/**
	 * Grows the allocation to hold at least the requested number of elements. Growth can invalidate pointers and iterators.
	 */
	void reserve(U p_size) {
		if (p_size > capacity) {
			if (tight) {
				capacity = p_size;
			} else {
				// Try 1.5x the current capacity.
				// This ratio was chosen because it is close to the ideal growth rate of the golden ratio.
				// See https://archive.ph/Z2R8w for details.
				capacity = MAX((U)2, capacity + ((1 + capacity) >> 1));
				// If 1.5x growth isn't enough, just use the needed size exactly.
				if (p_size > capacity) {
					capacity = p_size;
				}
			}
			data = (T *)memrealloc(data, capacity * sizeof(T));
			CRASH_COND_MSG(!data, "Out of memory");
		} else if (p_size < count) {
			WARN_VERBOSE("reserve() called with a capacity smaller than the current size. This is likely a mistake.");
		}
	}

	/// Resize the vector.
	/// Elements are initialized (or not) depending on what the default C++ behavior for T is.
	/// Note: If force_trivial is set, this will behave like resize_uninitialized instead.
	void resize(U p_size) {
		// Don't init when trivially constructible.
		_resize<!std::is_trivially_constructible_v<T>>(p_size);
	}

	/// Resize and set new values to 0 / false / nullptr.
	_FORCE_INLINE_ void resize_initialized(U p_size) { _resize<true>(p_size); }

	/// Resize and keep memory uninitialized.
	/// This means that any newly added elements have an unknown value, and are expected to be set after the `resize_uninitialized` call.
	/// This is only available for trivially destructible types (otherwise, trivial resize might be UB).
	_FORCE_INLINE_ void resize_uninitialized(U p_size) { _resize<false>(p_size); }

	/**
	 * Returns a read-only reference at the index. An invalid index triggers a crash check.
	 */
	_FORCE_INLINE_ const T &operator[](U p_index) const _LIFETIME_BOUND_ {
		CRASH_BAD_UNSIGNED_INDEX(p_index, count);
		return data[p_index];
	}
	/**
	 * Returns a writable reference at the index. An invalid index triggers a crash check.
	 */
	_FORCE_INLINE_ T &operator[](U p_index) _LIFETIME_BOUND_ {
		CRASH_BAD_UNSIGNED_INDEX(p_index, count);
		return data[p_index];
	}

	/**
	 * Traverses contiguous elements with writable access. A storage reallocation invalidates the iterator.
	 */
	struct Iterator {
		/**
		 * Returns a writable reference to the current element.
		 */
		_FORCE_INLINE_ T &operator*() const {
			return *elem_ptr;
		}
		/**
		 * Returns the address of the current element.
		 */
		_FORCE_INLINE_ T *operator->() const { return elem_ptr; }
		/**
		 * Advances to the next element position.
		 */
		_FORCE_INLINE_ Iterator &operator++() {
			elem_ptr++;
			return *this;
		}
		/**
		 * Moves to the preceding element position.
		 */
		_FORCE_INLINE_ Iterator &operator--() {
			elem_ptr--;
			return *this;
		}

		/**
		 * Returns whether both iterators point to the same position.
		 */
		_FORCE_INLINE_ bool operator==(const Iterator &b) const { return elem_ptr == b.elem_ptr; }
		/**
		 * Returns whether the iterators point to different positions.
		 */
		_FORCE_INLINE_ bool operator!=(const Iterator &b) const { return elem_ptr != b.elem_ptr; }

		/**
		 * Starts the iterator at the supplied element pointer.
		 */
		Iterator(T *p_ptr) { elem_ptr = p_ptr; }
		/**
		 * Creates an iterator with a null element pointer.
		 */
		Iterator() {}
		/**
		 * Copies the source iterator's element pointer.
		 */
		Iterator(const Iterator &p_it) { elem_ptr = p_it.elem_ptr; }

	private:
		/**
		 * Points to the current element or the position past the last element.
		 */
		T *elem_ptr = nullptr;
	};

	/**
	 * Traverses contiguous elements with read-only access. A storage reallocation invalidates the iterator.
	 */
	struct ConstIterator {
		/**
		 * Returns a read-only reference to the current element.
		 */
		_FORCE_INLINE_ const T &operator*() const {
			return *elem_ptr;
		}
		/**
		 * Returns the address of the current element.
		 */
		_FORCE_INLINE_ const T *operator->() const { return elem_ptr; }
		/**
		 * Advances to the next element position.
		 */
		_FORCE_INLINE_ ConstIterator &operator++() {
			elem_ptr++;
			return *this;
		}
		/**
		 * Moves to the preceding element position.
		 */
		_FORCE_INLINE_ ConstIterator &operator--() {
			elem_ptr--;
			return *this;
		}

		/**
		 * Returns whether both iterators point to the same position.
		 */
		_FORCE_INLINE_ bool operator==(const ConstIterator &b) const { return elem_ptr == b.elem_ptr; }
		/**
		 * Returns whether the iterators point to different positions.
		 */
		_FORCE_INLINE_ bool operator!=(const ConstIterator &b) const { return elem_ptr != b.elem_ptr; }

		/**
		 * Starts the iterator at the supplied element pointer.
		 */
		ConstIterator(const T *p_ptr) { elem_ptr = p_ptr; }
		/**
		 * Creates an iterator with a null element pointer.
		 */
		ConstIterator() {}
		/**
		 * Copies the source iterator's element pointer.
		 */
		ConstIterator(const ConstIterator &p_it) { elem_ptr = p_it.elem_ptr; }

	private:
		/**
		 * Points to the current element or the position past the last element.
		 */
		const T *elem_ptr = nullptr;
	};

	/**
	 * Returns a writable iterator to the start of the buffer.
	 */
	_FORCE_INLINE_ Iterator begin() _LIFETIME_BOUND_ {
		return Iterator(data);
	}
	/**
	 * Returns a writable iterator just past the last element.
	 */
	_FORCE_INLINE_ Iterator end() _LIFETIME_BOUND_ {
		return Iterator(data + size());
	}

	/**
	 * Returns a read-only iterator to the start of the buffer.
	 */
	_FORCE_INLINE_ ConstIterator begin() const _LIFETIME_BOUND_ {
		return ConstIterator(ptr());
	}
	/**
	 * Returns a read-only iterator just past the last element.
	 */
	_FORCE_INLINE_ ConstIterator end() const _LIFETIME_BOUND_ {
		return ConstIterator(ptr() + size());
	}

	/**
	 * Inserts before the indexed element and shifts later elements right. The current size is a valid append position.
	 */
	void insert(U p_pos, T p_val) {
		ERR_FAIL_UNSIGNED_INDEX(p_pos, count + 1);
		if (p_pos == count) {
			push_back(std::move(p_val));
		} else {
			resize(count + 1);
			for (U i = count - 1; i > p_pos; i--) {
				data[i] = std::move(data[i - 1]);
			}
			data[p_pos] = std::move(p_val);
		}
	}

	/**
	 * Searches forward from the given start, with negative starts measured from the end. Returns the first matching index or `-1`.
	 */
	int64_t find(const T &p_val, int64_t p_from = 0) const {
		if (p_from < 0) {
			p_from = size() + p_from;
		}
		if (p_from < 0 || p_from >= size()) {
			return -1;
		}
		return span().find(p_val, p_from);
	}

	/**
	 * Reports whether an element compares equal to the supplied value.
	 */
	bool has(const T &p_val) const {
		return find(p_val) != -1;
	}

	/**
	 * Sorts the elements in place using the supplied comparator type.
	 */
	template <typename C>
	void sort_custom() {
		U len = count;
		if (len == 0) {
			return;
		}

		SortArray<T, C> sorter;
		sorter.sort(data, len);
	}

	/**
	 * Sorts the elements in place with the default comparator.
	 */
	void sort() {
		sort_custom<Comparator<T>>();
	}

	/**
	 * Inserts after any equivalent values in an ascending sequence.
	 */
	void ordered_insert(T p_val) {
		U i;
		for (i = 0; i < count; i++) {
			if (p_val < data[i]) {
				break;
			}
		}
		insert(i, p_val);
	}

	/**
	 * Copies the elements' in-memory byte representations to a vector of bytes.
	 */
	Vector<uint8_t> to_byte_array() const { //useful to pass stuff to gpu or variant
		Vector<uint8_t> ret;
		ret.resize(count * sizeof(T));
		uint8_t *w = ret.ptrw();
		if (w) {
			memcpy(w, data, sizeof(T) * count);
		}
		return ret;
	}

	/**
	 * Creates an empty array without allocating storage.
	 */
	_FORCE_INLINE_ LocalVector() {}
	/**
	 * Copies the listed elements in order into owned storage.
	 */
	_FORCE_INLINE_ LocalVector(std::initializer_list<T> p_init) {
		reserve(p_init.size());
		for (const T &element : p_init) {
			push_back(element);
		}
	}
	/**
	 * Copies the source's elements into independent storage.
	 */
	_FORCE_INLINE_ explicit LocalVector(const LocalVector &p_from) {
		resize(p_from.size());
		for (U i = 0; i < p_from.count; i++) {
			data[i] = p_from.data[i];
		}
	}
	/**
	 * Takes the source allocation and leaves the source empty.
	 */
	_FORCE_INLINE_ LocalVector(LocalVector &&p_from) {
		data = p_from.data;
		count = p_from.count;
		capacity = p_from.capacity;

		p_from.data = nullptr;
		p_from.count = 0;
		p_from.capacity = 0;
	}

	/**
	 * Replaces the current elements with copies of the source elements.
	 */
	inline void operator=(const LocalVector &p_from) {
		resize(p_from.size());
		for (U i = 0; i < p_from.count; i++) {
			data[i] = p_from.data[i];
		}
	}
	/**
	 * Copies the elements from a `godot::Vector` into independently owned storage.
	 */
	inline void operator=(const Vector<T> &p_from) {
		resize(p_from.size());
		for (U i = 0; i < count; i++) {
			data[i] = p_from[i];
		}
	}
	/**
	 * Releases the old storage and takes the source's allocation, leaving the source empty.
	 */
	inline void operator=(LocalVector &&p_from) {
		if (unlikely(this == &p_from)) {
			return;
		}
		reset();

		data = p_from.data;
		count = p_from.count;
		capacity = p_from.capacity;

		p_from.data = nullptr;
		p_from.count = 0;
		p_from.capacity = 0;
	}
	/**
	 * Assigns the source vector's elements into local storage. The vector's const subscript leaves the source buffer owned by the source.
	 */
	inline void operator=(Vector<T> &&p_from) {
		resize(p_from.size());
		for (U i = 0; i < count; i++) {
			data[i] = std::move(p_from[i]);
		}
	}

	/**
	 * Destroys any remaining elements and frees the allocation.
	 */
	_FORCE_INLINE_ ~LocalVector() {
		if (data) {
			reset();
		}
	}
};

/**
 * A local vector that grows its allocation to the requested capacity.
 */
template <typename T, typename U = uint32_t>
using TightLocalVector = LocalVector<T, U, false, true>;

// Zero-constructing LocalVector initializes count, capacity and data to 0 and thus empty.
/**
 * Marks an all-zero local vector as a valid empty vector.
 */
template <typename T, typename U, bool force_trivial, bool tight>
struct is_zero_constructible<LocalVector<T, U, force_trivial, tight>> : std::true_type {};

} // namespace godot
