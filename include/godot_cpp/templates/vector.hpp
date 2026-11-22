/**************************************************************************/
/*  vector.hpp                                                            */
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
#include <godot_cpp/templates/cowdata.hpp>
#include <godot_cpp/templates/sort_array.hpp>
#include <godot_cpp/templates/span.hpp>

#include <initializer_list>

namespace godot {

template <typename T>
class Vector;

/**
 * Provides indexed writable access to its containing vector, detaching shared storage before a write.
 */
template <typename T>
class VectorWriteProxy {
public:
	/**
	 * Returns a writable reference at the index after checking bounds and detaching shared storage.
	 */
	_FORCE_INLINE_ T &operator[](typename CowData<T>::Size p_index) {
		CRASH_BAD_INDEX(p_index, ((Vector<T> *)(this))->_cowdata.size());

		return ((Vector<T> *)(this))->_cowdata.ptrw()[p_index];
	}
};

/**
 * A contiguous sequence with reference-counted storage. Copies share the buffer until an operation requires writable storage.
 */
template <typename T>
class Vector {
	/**
	 * Lets the write proxy access the vector's copy-on-write buffer.
	 */
	friend class VectorWriteProxy<T>;

public:
	/**
	 * Accesses elements by index for modification through `godot::VectorWriteProxy`.
	 */
	VectorWriteProxy<T> write;
	/**
	 * Signed element count and index type, also used for negative offsets and search failure.
	 */
	typedef typename CowData<T>::Size Size;
	/**
	 * Unsigned storage capacity type, measured in elements.
	 */
	typedef typename CowData<T>::USize USize;

private:
	/**
	 * Owns the shared element buffer and its size and capacity.
	 */
	CowData<T> _cowdata;

public:
	// Must take a copy instead of a reference (see GH-31736).
	/**
	 * Appends an element by moving a local copy into storage. Returns false on success or true when insertion reports an error.
	 */
	_FORCE_INLINE_ bool push_back(T p_elem) { return _cowdata.push_back(std::move(p_elem)); }
	/**
	 * Appends an element through the same operation as `godot::Vector::push_back`, with false indicating success.
	 */
	_FORCE_INLINE_ bool append(T p_elem) { return _cowdata.push_back(std::move(p_elem)); } //alias
	/**
	 * Replaces every existing element with a copy of the supplied value.
	 */
	void fill(T p_elem);

	/**
	 * Erases the element at the index and shifts following elements left.
	 */
	void remove_at(Size p_index) { _cowdata.remove_at(p_index); }
	/**
	 * Erases the first element equal to the supplied value and returns whether a match was found.
	 */
	_FORCE_INLINE_ bool erase(const T &p_val) {
		Size idx = find(p_val);
		if (idx >= 0) {
			remove_at(idx);
			return true;
		}
		return false;
	}

	/**
	 * Reverses the order of elements in place.
	 */
	void reverse();

	/**
	 * Returns a writable buffer pointer after detaching shared storage.
	 */
	_FORCE_INLINE_ T *ptrw() _LIFETIME_BOUND_ { return _cowdata.ptrw(); }
	/**
	 * Returns the read-only buffer pointer, which can be null for an empty vector.
	 */
	_FORCE_INLINE_ const T *ptr() const _LIFETIME_BOUND_ { return _cowdata.ptr(); }
	/**
	 * Returns the number of live elements.
	 */
	_FORCE_INLINE_ Size size() const { return _cowdata.size(); }
	/**
	 * Returns the allocated capacity in elements.
	 */
	_FORCE_INLINE_ USize capacity() const { return _cowdata.capacity(); }

	/**
	 * Borrows a read-only view of the current element range.
	 */
	_FORCE_INLINE_ operator Span<T>() const _LIFETIME_BOUND_ { return _cowdata.span(); }
	/**
	 * Returns a read-only view valid while the current buffer and element range remain valid.
	 */
	_FORCE_INLINE_ Span<T> span() const _LIFETIME_BOUND_ { return _cowdata.span(); }

	/**
	 * Releases this vector's reference to the buffer and leaves it empty.
	 */
	_FORCE_INLINE_ void clear() { _cowdata.clear(); }
	/**
	 * Returns whether the vector has zero elements.
	 */
	_FORCE_INLINE_ bool is_empty() const { return _cowdata.is_empty(); }

	/**
	 * Returns a copy of the element at a valid index.
	 */
	_FORCE_INLINE_ T get(Size p_index) _LIFETIME_BOUND_ { return _cowdata.get(p_index); }
	/**
	 * Returns a read-only reference to the element at a valid index.
	 */
	_FORCE_INLINE_ const T &get(Size p_index) const _LIFETIME_BOUND_ { return _cowdata.get(p_index); }
	/**
	 * Replaces the indexed element, detaching shared storage when necessary.
	 */
	_FORCE_INLINE_ void set(Size p_index, const T &p_elem) { _cowdata.set(p_index, p_elem); }

	/// Resize the vector.
	/// Elements are initialized (or not) depending on what the default C++ behavior for this type is.
	_FORCE_INLINE_ Error resize(Size p_size) {
		return _cowdata.template resize<!std::is_trivially_constructible_v<T>>(p_size);
	}

	/// Resize and set new values to 0 / false / nullptr.
	/// This is only available for zero constructible types.
	_FORCE_INLINE_ Error resize_initialized(Size p_size) {
		return _cowdata.template resize<true>(p_size);
	}

	/// Resize and keep memory uninitialized.
	/// This means that any newly added elements have an unknown value, and are expected to be set after the `resize_uninitialized` call.
	/// This is only available for trivially destructible types (otherwise, trivial resize might be UB).
	_FORCE_INLINE_ Error resize_uninitialized(Size p_size) {
		// resize() statically asserts that T is compatible, no need to do it ourselves.
		return _cowdata.template resize<false>(p_size);
	}

	/// Reserves capacity for at least p_size total elements.
	/// You can use `reserve` before repeated insertions to improve performance.
	/// The capacity grows in 1.5x increments when possible, and uses `p_size`
	/// exactly otherwise.
	Error reserve(Size p_size) {
		ERR_FAIL_COND_V(p_size < 0, ERR_INVALID_PARAMETER);
		return _cowdata.reserve(p_size);
	}

	/// Reserves capacity for exactly p_size total elements.
	/// This can be useful to reduce RAM use of large vectors, but wastes CPU
	/// time if more than p_size elements are added after the `reserve_exact` call.
	/// Prefer using `reserve`, unless the vector (or copies of it) will never
	/// grow again after p_size elements are inserted.
	Error reserve_exact(Size p_size) {
		ERR_FAIL_COND_V(p_size < 0, ERR_INVALID_PARAMETER);
		return _cowdata.reserve_exact(p_size);
	}

	/**
	 * Returns a read-only reference at the given index. An invalid index triggers a crash check.
	 */
	_FORCE_INLINE_ const T &operator[](Size p_index) const _LIFETIME_BOUND_ { return _cowdata.get(p_index); }
	// Must take a copy instead of a reference (see GH-31736).
	/**
	 * Inserts before the given index or appends at the current size. Returns an error for invalid positions or recoverable allocation failures.
	 */
	Error insert(Size p_pos, T p_val) { return _cowdata.insert(p_pos, std::move(p_val)); }
	/**
	 * Searches forward from the starting index. Negative starts are relative to the end. Returns the first matching index or `-1`.
	 */
	Size find(const T &p_val, Size p_from = 0) const {
		if (p_from < 0) {
			p_from = size() + p_from;
		}
		if (p_from < 0 || p_from >= size()) {
			return -1;
		}
		return span().find(p_val, p_from);
	}
	/**
	 * Searches backward from the starting index. Negative starts are relative to the end. Returns the first index encountered or `-1`.
	 */
	Size rfind(const T &p_val, Size p_from = -1) const {
		if (p_from < 0) {
			p_from = size() + p_from;
		}
		if (p_from < 0 || p_from >= size()) {
			return -1;
		}
		return span().rfind(p_val, p_from);
	}
	/**
	 * Returns the number of elements equal to the given value.
	 */
	Size count(const T &p_val) const { return span().count(p_val); }

	// Must take a copy instead of a reference (see GH-31736).
	/**
	 * Copies the elements of the supplied vector onto the end in their existing order.
	 */
	void append_array(Vector<T> p_other);

	/**
	 * Returns whether any element is equal to the supplied value.
	 */
	_FORCE_INLINE_ bool has(const T &p_val) const { return find(p_val) != -1; }

	/**
	 * Sorts the elements in place with the default comparator.
	 */
	void sort() {
		sort_custom<Comparator<T>>();
	}

	/**
	 * Detaches shared storage and sorts in place. The arguments construct the comparator used by the sorter.
	 */
	template <typename Comparator, bool Validate = SORT_ARRAY_VALIDATE_ENABLED, typename... Args>
	void sort_custom(Args &&...args) {
		Size len = _cowdata.size();
		if (len == 0) {
			return;
		}

		T *data = ptrw();
		SortArray<T, Comparator, Validate> sorter{ args... };
		sorter.sort(data, len);
	}

	/**
	 * Returns an insertion index in the sorted vector. `p_before` selects the position before or after equivalent elements.
	 */
	Size bsearch(const T &p_value, bool p_before) const {
		return bsearch_custom<Comparator<T>>(p_value, p_before);
	}

	/**
	 * Finds the insertion index in a vector sorted according to the supplied comparator type. Arguments initialize the comparator.
	 */
	template <typename Comparator, typename Value, typename... Args>
	Size bsearch_custom(const Value &p_value, bool p_before, Args &&...args) const {
		return span().bisect(p_value, p_before, Comparator{ args... });
	}

	/**
	 * Returns a copy that shares the current storage until a write detaches it.
	 */
	Vector<T> duplicate() const {
		return *this;
	}

	/**
	 * Inserts after existing equivalent values in a vector sorted in ascending order.
	 */
	void ordered_insert(const T &p_val) {
		Size i;
		for (i = 0; i < _cowdata.size(); i++) {
			if (p_val < operator[](i)) {
				break;
			}
		}
		insert(i, p_val);
	}

	/**
	 * Shares the source's buffer and releases the previous buffer reference.
	 */
	void operator=(const Vector &p_from) { _cowdata = p_from._cowdata; }
	/**
	 * Moves the source's storage into this vector when the buffers differ.
	 */
	void operator=(Vector &&p_from) { _cowdata = std::move(p_from._cowdata); }

	/**
	 * Copies the elements' in-memory byte representations into a byte array.
	 */
	Vector<uint8_t> to_byte_array() const {
		Vector<uint8_t> ret;
		if (is_empty()) {
			return ret;
		}
		size_t alloc_size = size() * sizeof(T);
		ret.resize(alloc_size);
		if (alloc_size) {
			memcpy(ret.ptrw(), ptr(), alloc_size);
		}
		return ret;
	}

	/**
	 * Copies the half-open range from the start index through the element before the end index. Negative indices count from the end. Both bounds are clamped to the vector.
	 */
	Vector<T> slice(Size p_begin, Size p_end = CowData<T>::MAX_INT) const {
		Vector<T> result;

		const Size s = size();

		Size begin = CLAMP(p_begin, -s, s);
		if (begin < 0) {
			begin += s;
		}
		Size end = CLAMP(p_end, -s, s);
		if (end < 0) {
			end += s;
		}

		ERR_FAIL_COND_V(begin > end, result);

		Size result_size = end - begin;
		result.resize(result_size);

		const T *const r = ptr();
		T *const w = result.ptrw();
		for (Size i = 0; i < result_size; ++i) {
			w[i] = r[begin + i];
		}

		return result;
	}

	/**
	 * Returns whether the vectors have equal size and matching contents under `godot::are_spans_equal`.
	 */
	bool operator==(const Vector<T> &p_arr) const { return span() == p_arr.span(); }
	/**
	 * Returns whether the vectors differ in size or contents under `godot::are_spans_equal`.
	 */
	bool operator!=(const Vector<T> &p_arr) const { return span() != p_arr.span(); }

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
	 * Returns a writable start iterator after detaching shared storage.
	 */
	_FORCE_INLINE_ Iterator begin() _LIFETIME_BOUND_ {
		return Iterator(ptrw());
	}
	/**
	 * Returns a writable iterator just past the last element after detaching shared storage.
	 */
	_FORCE_INLINE_ Iterator end() _LIFETIME_BOUND_ {
		return Iterator(ptrw() + size());
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
	 * Creates an empty vector without an element allocation.
	 */
	_FORCE_INLINE_ Vector() {}
	/**
	 * Copies the initializer list into a new element buffer.
	 */
	_FORCE_INLINE_ Vector(std::initializer_list<T> p_init) :
			_cowdata(p_init) {}
	/**
	 * Copies the elements of the supplied view into owned storage.
	 */
	_FORCE_INLINE_ explicit Vector(Span<T> p_span) :
			_cowdata(p_span) {}
	/**
	 * Shares the source's buffer until an operation needs writable storage.
	 */
	_FORCE_INLINE_ Vector(const Vector &p_from) = default;
	/**
	 * Takes the source's buffer and leaves the source empty.
	 */
	_FORCE_INLINE_ Vector(Vector &&p_from) = default;
};

template <typename T>
void Vector<T>::reverse() {
	T *p = ptrw();
	for (Size i = 0; i < size() / 2; i++) {
		SWAP(p[i], p[size() - i - 1]);
	}
}

template <typename T>
void Vector<T>::append_array(Vector<T> p_other) {
	const Size ds = p_other.size();
	if (ds == 0) {
		return;
	}
	const Size bs = size();
	resize(bs + ds);
	T *p = ptrw();
	for (Size i = 0; i < ds; ++i) {
		p[bs + i] = p_other[i];
	}
}

template <typename T>
void Vector<T>::fill(T p_elem) {
	T *p = ptrw();
	for (Size i = 0; i < size(); i++) {
		p[i] = p_elem;
	}
}

// Zero-constructing Vector initializes CowData.ptr() to nullptr and thus empty.
/**
 * Marks an all-zero vector as a valid empty vector.
 */
template <typename T>
struct is_zero_constructible<Vector<T>> : std::true_type {};

} // namespace godot
