/**************************************************************************/
/*  list.hpp                                                              */
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
#include <godot_cpp/templates/sort_list.hpp>

#include <initializer_list>

/**
 * Ordered storage implemented as a doubly linked list.
 *
 * Elements are pointer stable.
 *
 * Core container guidance:
 * https://docs.godotengine.org/en/latest/engine_details/architecture/core_types.html#containers
 */

namespace godot {

/**
 * A doubly linked list that keeps element addresses stable until the elements are erased.
 *
 * - `T` — Value stored in each element.
 * - `A` — Allocator used for elements and the list data.
 */
template <typename T, typename A = DefaultAllocator>
class _WARN_UNUSED_ List {
	/**
	 * Declares the record that owns the first and last links and stores the size.
	 */
	struct _Data;

public:
	/**
	 * Stores one list value, the links to its neighbors, and the owning list data.
	 */
	class Element {
	private:
		/**
		 * Allows the list to update this element's ownership and links.
		 */
		friend class List<T, A>;

		/**
		 * Stores the value that this element contributes to the list.
		 */
		T value;
		/**
		 * Points to the next element, or is null at the end of the list.
		 */
		Element *next_ptr = nullptr;
		/**
		 * Points to the previous element, or is null at the start of the list.
		 */
		Element *prev_ptr = nullptr;
		/**
		 * Points to the list data that currently owns this element.
		 */
		_Data *data = nullptr;

	public:
		/**
		 * Returns a read-only pointer to the next element, or null at the end.
		 */
		_FORCE_INLINE_ const Element *next() const {
			return next_ptr;
		}
		/**
		 * Returns a writable pointer to the next element, or null at the end.
		 */
		_FORCE_INLINE_ Element *next() {
			return next_ptr;
		}

		/**
		 * Returns a read-only pointer to the previous element, or null at the start.
		 */
		_FORCE_INLINE_ const Element *prev() const {
			return prev_ptr;
		}
		/**
		 * Returns a writable pointer to the previous element, or null at the start.
		 */
		_FORCE_INLINE_ Element *prev() {
			return prev_ptr;
		}

		/**
		 * Returns a read-only reference to the value stored by this element.
		 */
		_FORCE_INLINE_ const T &operator*() const {
			return value;
		}
		/**
		 * Returns a read-only pointer to the value stored by this element.
		 */
		_FORCE_INLINE_ const T *operator->() const {
			return &value;
		}
		/**
		 * Returns a writable reference to the value stored by this element.
		 */
		_FORCE_INLINE_ T &operator*() {
			return value;
		}
		/**
		 * Returns a writable pointer to the value stored by this element.
		 */
		_FORCE_INLINE_ T *operator->() {
			return &value;
		}

		/**
		 * Returns a writable reference to the stored value.
		 */
		_FORCE_INLINE_ T &get() {
			return value;
		}
		/**
		 * Returns a read-only reference to the stored value.
		 */
		_FORCE_INLINE_ const T &get() const {
			return value;
		}
		/**
		 * Copies a new value into the existing element.
		 *
		 * - `p_value` — Replacement value.
		 */
		_FORCE_INLINE_ void set(const T &p_value) {
			value = (T &)p_value;
		}

		/**
		 * Erases this element from its owning list data and destroys it.
		 */
		void erase() {
			data->erase(this);
		}

		/**
		 * Moves this element to the end of another list without copying it or changing its address.
		 *
		 * - `p_dst_list` — Destination list to receive this live element.
		 */
		void transfer_to_back(List<T, A> *p_dst_list);
	};

	/**
	 * The type of the value stored in each element.
	 */
	typedef T ValueType;

	/**
	 * Visits list elements in link order with read-only access to their values.
	 */
	struct ConstIterator {
		/**
		 * Returns a read-only reference to the current value. The iterator must refer to an element.
		 */
		_FORCE_INLINE_ const T &operator*() const {
			return E->get();
		}
		/**
		 * Returns a read-only pointer to the current value.
		 */
		_FORCE_INLINE_ const T *operator->() const { return &E->get(); }
		/**
		 * Moves to the next list element. After the last element the iterator reaches the end.
		 */
		_FORCE_INLINE_ ConstIterator &operator++() {
			E = E->next();
			return *this;
		}
		/**
		 * Moves to the previous list element. Before the first element the iterator holds a null pointer.
		 */
		_FORCE_INLINE_ ConstIterator &operator--() {
			E = E->prev();
			return *this;
		}

		/**
		 * Tests whether the iterators refer to the same element.
		 *
		 * - `p_other` — Iterator whose element is compared with this iterator's element.
		 */
		_FORCE_INLINE_ bool operator==(const ConstIterator &p_other) const { return E == p_other.E; }
		/**
		 * Tests whether the iterators refer to different elements.
		 *
		 * - `p_other` — Iterator whose element is compared with this iterator's element.
		 */
		_FORCE_INLINE_ bool operator!=(const ConstIterator &p_other) const { return E != p_other.E; }

		/**
		 * Starts the iterator at the supplied element.
		 *
		 * - `p_element` — Current element. Null makes an end iterator.
		 */
		_FORCE_INLINE_ ConstIterator(const Element *p_element) { E = p_element; }
		/**
		 * Creates an iterator without a current element.
		 */
		_FORCE_INLINE_ ConstIterator() {}
		/**
		 * Copies the source iterator's position.
		 *
		 * - `p_it` — Iterator whose current element is copied.
		 */
		_FORCE_INLINE_ ConstIterator(const ConstIterator &p_it) { E = p_it.E; }

	private:
		/**
		 * Points to the current element, or is null at the end.
		 */
		const Element *E = nullptr;
	};

	/**
	 * Visits list elements in link order with writable access to their values.
	 */
	struct Iterator {
		/**
		 * Returns a writable reference to the current value. The iterator must refer to an element.
		 */
		_FORCE_INLINE_ T &operator*() const {
			return E->get();
		}
		/**
		 * Returns a writable pointer to the current value.
		 */
		_FORCE_INLINE_ T *operator->() const { return &E->get(); }
		/**
		 * Moves to the next list element. After the last element the iterator reaches the end.
		 */
		_FORCE_INLINE_ Iterator &operator++() {
			E = E->next();
			return *this;
		}
		/**
		 * Moves to the previous list element. Before the first element the iterator holds a null pointer.
		 */
		_FORCE_INLINE_ Iterator &operator--() {
			E = E->prev();
			return *this;
		}

		/**
		 * Tests whether the iterators refer to the same element.
		 *
		 * - `p_other` — Iterator whose element is compared with this iterator's element.
		 */
		_FORCE_INLINE_ bool operator==(const Iterator &p_other) const { return E == p_other.E; }
		/**
		 * Tests whether the iterators refer to different elements.
		 *
		 * - `p_other` — Iterator whose element is compared with this iterator's element.
		 */
		_FORCE_INLINE_ bool operator!=(const Iterator &p_other) const { return E != p_other.E; }

		/**
		 * Starts the iterator at the supplied element.
		 *
		 * - `p_element` — Current element. Null makes an end iterator.
		 */
		Iterator(Element *p_element) { E = p_element; }
		/**
		 * Creates an iterator without a current element.
		 */
		Iterator() {}
		/**
		 * Copies the source iterator's position.
		 *
		 * - `p_it` — Iterator whose current element is copied.
		 */
		Iterator(const Iterator &p_it) { E = p_it.E; }

		/**
		 * Creates a read-only iterator at the same list position.
		 */
		operator ConstIterator() const {
			return ConstIterator(E);
		}

	private:
		/**
		 * Points to the current element, or is null at the end.
		 */
		Element *E = nullptr;
	};

	/**
	 * Returns a writable iterator to the first element, or the end if the list is empty.
	 */
	_FORCE_INLINE_ Iterator begin() {
		return Iterator(front());
	}
	/**
	 * Returns the writable end iterator with no current element.
	 */
	_FORCE_INLINE_ Iterator end() {
		return Iterator(nullptr);
	}

#if 0
	//to use when replacing find()
	/**
	 * In this disabled branch, wraps the lookup result in a writable iterator.
	 *
	 * - `p_key` — Value used for lookup.
	 */
	_FORCE_INLINE_ Iterator find(const K &p_key) {
		return Iterator(find(p_key));
	}
#endif
	/**
	 * Returns a read-only iterator to the first element, or the end if the list is empty.
	 */
	_FORCE_INLINE_ ConstIterator begin() const {
		return ConstIterator(front());
	}
	/**
	 * Returns the read-only end iterator with no current element.
	 */
	_FORCE_INLINE_ ConstIterator end() const {
		return ConstIterator(nullptr);
	}
#if 0
	//to use when replacing find()
	/**
	 * In this disabled branch, wraps the lookup result in a read-only iterator.
	 *
	 * - `p_key` — Value used for lookup.
	 */
	_FORCE_INLINE_ ConstIterator find(const K &p_key) const {
		return ConstIterator(find(p_key));
	}
#endif
private:
	/**
	 * Holds the endpoint links and size for one list.
	 */
	struct _Data {
		/**
		 * Points to the first element, or is null when the list is empty.
		 */
		Element *first = nullptr;
		/**
		 * Points to the last element, or is null when the list is empty.
		 */
		Element *last = nullptr;
		/**
		 * Counts the elements currently linked to this list data.
		 */
		int size_cache = 0;

		/**
		 * Unlinks and destroys the element and reduces the count. Reports an error and returns false for a null pointer or an element owned by another list.
		 *
		 * - `p_element` — Live element that belongs to this list.
		 */
		bool erase(Element *p_element) {
			ERR_FAIL_NULL_V(p_element, false);
			ERR_FAIL_COND_V(p_element->data != this, false);

			if (first == p_element) {
				first = p_element->next_ptr;
			}

			if (last == p_element) {
				last = p_element->prev_ptr;
			}

			if (p_element->prev_ptr) {
				p_element->prev_ptr->next_ptr = p_element->next_ptr;
			}

			if (p_element->next_ptr) {
				p_element->next_ptr->prev_ptr = p_element->prev_ptr;
			}

			memdelete_allocator<Element, A>(p_element);
			size_cache--;

			return true;
		}
	};

	/**
	 * Points to the list data, which is allocated when an element needs it.
	 */
	_Data *_data = nullptr;

public:
	/**
	 * Returns a read-only pointer to the first element, or null if empty.
	 */
	_FORCE_INLINE_ const Element *front() const _LIFETIME_BOUND_ {
		return _data ? _data->first : nullptr;
	}

	/**
	 * Returns a writable pointer to the first element, or null if empty.
	 */
	_FORCE_INLINE_ Element *front() _LIFETIME_BOUND_ {
		return _data ? _data->first : nullptr;
	}

	/**
	 * Returns a read-only pointer to the last element, or null if empty.
	 */
	_FORCE_INLINE_ const Element *back() const _LIFETIME_BOUND_ {
		return _data ? _data->last : nullptr;
	}

	/**
	 * Returns a writable pointer to the last element, or null if empty.
	 */
	_FORCE_INLINE_ Element *back() _LIFETIME_BOUND_ {
		return _data ? _data->last : nullptr;
	}

	/**
	 * Adds an element to the end and returns its address.
	 *
	 * - `p_value` — Value copied into the new element.
	 */
	Element *push_back(const T &p_value) _LIFETIME_BOUND_ {
		if (!_data) {
			_data = memnew_allocator(_Data, A);
			_data->first = nullptr;
			_data->last = nullptr;
			_data->size_cache = 0;
		}

		Element *n = memnew_allocator(Element, A);
		n->value = (T &)p_value;

		n->prev_ptr = _data->last;
		n->next_ptr = nullptr;
		n->data = _data;

		if (_data->last) {
			_data->last->next_ptr = n;
		}

		_data->last = n;

		if (!_data->first) {
			_data->first = n;
		}

		_data->size_cache++;

		return n;
	}

	/**
	 * Erases the last element if the list has one.
	 */
	void pop_back() {
		if (_data && _data->last) {
			erase(_data->last);
		}
	}

	/**
	 * Adds an element to the start and returns its address.
	 *
	 * - `p_value` — Value copied into the new element.
	 */
	Element *push_front(const T &p_value) _LIFETIME_BOUND_ {
		if (!_data) {
			_data = memnew_allocator(_Data, A);
			_data->first = nullptr;
			_data->last = nullptr;
			_data->size_cache = 0;
		}

		Element *n = memnew_allocator(Element, A);
		n->value = (T &)p_value;
		n->prev_ptr = nullptr;
		n->next_ptr = _data->first;
		n->data = _data;

		if (_data->first) {
			_data->first->prev_ptr = n;
		}

		_data->first = n;

		if (!_data->last) {
			_data->last = n;
		}

		_data->size_cache++;

		return n;
	}

	/**
	 * Erases the first element if the list has one.
	 */
	void pop_front() {
		if (_data && _data->first) {
			erase(_data->first);
		}
	}

	/**
	 * Adds a new element after the given element and returns its address. A null position appends the value.
	 *
	 * - `p_element` — Element in this list after which to insert, or null to append.
	 * - `p_value` — Value to copy into the new element.
	 */
	Element *insert_after(Element *p_element, const T &p_value) _LIFETIME_BOUND_ {
		CRASH_COND(p_element && (!_data || p_element->data != _data));

		if (!p_element) {
			return push_back(p_value);
		}

		Element *n = memnew_allocator(Element, A);
		n->value = (T &)p_value;
		n->prev_ptr = p_element;
		n->next_ptr = p_element->next_ptr;
		n->data = _data;

		if (!p_element->next_ptr) {
			_data->last = n;
		} else {
			p_element->next_ptr->prev_ptr = n;
		}

		p_element->next_ptr = n;

		_data->size_cache++;

		return n;
	}

	/**
	 * Adds a new element before the given element and returns its address. A null position appends the value.
	 *
	 * - `p_element` — Element in this list before which to insert, or null to append.
	 * - `p_value` — Value to copy into the new element.
	 */
	Element *insert_before(Element *p_element, const T &p_value) _LIFETIME_BOUND_ {
		CRASH_COND(p_element && (!_data || p_element->data != _data));

		if (!p_element) {
			return push_back(p_value);
		}

		Element *n = memnew_allocator(Element, A);
		n->value = (T &)p_value;
		n->prev_ptr = p_element->prev_ptr;
		n->next_ptr = p_element;
		n->data = _data;

		if (!p_element->prev_ptr) {
			_data->first = n;
		} else {
			p_element->prev_ptr->next_ptr = n;
		}

		p_element->prev_ptr = n;

		_data->size_cache++;

		return n;
	}

	/**
	 * Returns a read-only pointer to the first element with a matching value, or null.
	 *
	 * - `T_v` — Type that can be compared with the stored value using equality.
	 * - `p_val` — Value to find, starting at the front of the list.
	 */
	template <typename T_v>
	const Element *find(const T_v &p_val) const _LIFETIME_BOUND_ {
		const Element *it = front();
		while (it) {
			if (it->value == p_val) {
				return it;
			}
			it = it->next();
		}

		return nullptr;
	}

	/**
	 * Returns a writable pointer to the first element with a matching value, or null.
	 *
	 * - `T_v` — Type that can be compared with a stored value using equality.
	 * - `p_val` — Value to find, starting at the front of the list.
	 */
	template <typename T_v>
	Element *find(const T_v &p_val) _LIFETIME_BOUND_ {
		Element *it = front();
		while (it) {
			if (it->value == p_val) {
				return it;
			}
			it = it->next();
		}

		return nullptr;
	}

	/**
	 * Erases the given element and returns whether it was removed. Removing the last element releases the list data.
	 *
	 * - `p_element` — Element owned by this list. Null has no effect.
	 */
	bool erase(Element *p_element) {
		if (_data && p_element) {
			bool ret = _data->erase(p_element);

			if (_data->size_cache == 0) {
				memdelete_allocator<_Data, A>(_data);
				_data = nullptr;
			}

			return ret;
		}

		return false;
	}

	/**
	 * Erases the first element with a matching value and returns whether it was removed.
	 *
	 * - `p_value` — Value to compare with stored elements, starting at the front.
	 */
	bool erase(const T &p_value) {
		Element *I = find(p_value);
		return erase(I);
	}

	/**
	 * Returns whether the list has no linked elements.
	 */
	_FORCE_INLINE_ bool is_empty() const {
		return (!_data || !_data->size_cache);
	}

	/**
	 * Erases all linked elements starting at the front.
	 */
	void clear() {
		while (front()) {
			erase(front());
		}
	}

	/**
	 * Returns the number of linked elements.
	 */
	_FORCE_INLINE_ int size() const {
		return _data ? _data->size_cache : 0;
	}

	/**
	 * Exchanges the positions of two elements without moving their stored values.
	 *
	 * - `p_left` — First element in this list.
	 * - `p_right` — Second element in this list.
	 */
	void swap(Element *p_left, Element *p_right) {
		ERR_FAIL_COND(!p_left || !p_right);
		ERR_FAIL_COND(p_left->data != _data);
		ERR_FAIL_COND(p_right->data != _data);

		if (p_left == p_right) {
			return;
		}
		Element *A_prev = p_left->prev_ptr;
		Element *A_next = p_left->next_ptr;
		Element *B_prev = p_right->prev_ptr;
		Element *B_next = p_right->next_ptr;

		if (A_prev) {
			A_prev->next_ptr = p_right;
		} else {
			_data->first = p_right;
		}
		if (B_prev) {
			B_prev->next_ptr = p_left;
		} else {
			_data->first = p_left;
		}
		if (A_next) {
			A_next->prev_ptr = p_right;
		} else {
			_data->last = p_right;
		}
		if (B_next) {
			B_next->prev_ptr = p_left;
		} else {
			_data->last = p_left;
		}
		p_left->prev_ptr = A_next == p_right ? p_right : B_prev;
		p_left->next_ptr = B_next == p_left ? p_right : B_next;
		p_right->prev_ptr = B_next == p_left ? p_left : A_prev;
		p_right->next_ptr = A_next == p_right ? p_left : A_next;
	}
	/**
	 * Erases the current elements and then copies the source values in order. Copying a list into itself clears it.
	 *
	 * - `p_list` — Source of the values copied after clearing the destination.
	 */
	void operator=(const List &p_list) {
		clear();
		const Element *it = p_list.front();
		while (it) {
			push_back(it->get());
			it = it->next();
		}
	}
	/**
	 * Destroys the old elements, takes the source list data, and leaves the source empty. Self-assignment has no effect.
	 *
	 * - `p_list` — Source list.
	 */
	void operator=(List &&p_list) {
		if (unlikely(this == &p_list)) {
			return;
		}

		clear();
		_data = p_list._data;
		p_list._data = nullptr;
	}

	// Random access to elements, use with care,
	// do not use for iteration.
	/**
	 * Returns a writable reference to the value at the index by walking the links from the first element.
	 *
	 * - `p_index` — Zero-based position. An out-of-range index stops execution.
	 */
	T &get(int p_index) _LIFETIME_BOUND_ {
		CRASH_BAD_INDEX(p_index, size());

		Element *I = front();
		int c = 0;
		while (c < p_index) {
			I = I->next();
			c++;
		}

		return I->get();
	}

	// Random access to elements, use with care,
	// do not use for iteration.
	/**
	 * Returns a read-only reference to the value at the index by walking the links from the first element.
	 *
	 * - `p_index` — Zero-based position. An out-of-range index stops execution.
	 */
	const T &get(int p_index) const _LIFETIME_BOUND_ {
		CRASH_BAD_INDEX(p_index, size());

		const Element *I = front();
		int c = 0;
		while (c < p_index) {
			I = I->next();
			c++;
		}

		return I->get();
	}

	/**
	 * Moves the given element to the last position without changing its value or address.
	 *
	 * - `p_element` — Live element that belongs to this list.
	 */
	void move_to_back(Element *p_element) {
		ERR_FAIL_COND(p_element->data != _data);
		if (!p_element->next_ptr) {
			return;
		}

		if (_data->first == p_element) {
			_data->first = p_element->next_ptr;
		}

		if (_data->last == p_element) {
			_data->last = p_element->prev_ptr;
		}

		if (p_element->prev_ptr) {
			p_element->prev_ptr->next_ptr = p_element->next_ptr;
		}

		p_element->next_ptr->prev_ptr = p_element->prev_ptr;

		_data->last->next_ptr = p_element;
		p_element->prev_ptr = _data->last;
		p_element->next_ptr = nullptr;
		_data->last = p_element;
	}

	/**
	 * Reverses value order by swapping values between existing elements. The element links stay in place.
	 */
	void reverse() {
		int s = size() / 2;
		Element *F = front();
		Element *B = back();
		for (int i = 0; i < s; i++) {
			SWAP(F->value, B->value);
			F = F->next();
			B = B->prev();
		}
	}

	/**
	 * Moves the given element to the first position without changing its value or address.
	 *
	 * - `p_element` — Live element that belongs to this list.
	 */
	void move_to_front(Element *p_element) {
		ERR_FAIL_COND(p_element->data != _data);
		if (!p_element->prev_ptr) {
			return;
		}

		if (_data->first == p_element) {
			_data->first = p_element->next_ptr;
		}

		if (_data->last == p_element) {
			_data->last = p_element->prev_ptr;
		}

		p_element->prev_ptr->next_ptr = p_element->next_ptr;

		if (p_element->next_ptr) {
			p_element->next_ptr->prev_ptr = p_element->prev_ptr;
		}

		_data->first->prev_ptr = p_element;
		p_element->next_ptr = _data->first;
		p_element->prev_ptr = nullptr;
		_data->first = p_element;
	}

	/**
	 * Moves an existing element immediately before another element by changing their links.
	 *
	 * - `p_value` — Element from this list to move.
	 * - `p_where` — Different element from this list to insert before.
	 */
	void move_before(Element *p_value, Element *p_where) {
		if (p_value->prev_ptr) {
			p_value->prev_ptr->next_ptr = p_value->next_ptr;
		} else {
			_data->first = p_value->next_ptr;
		}
		if (p_value->next_ptr) {
			p_value->next_ptr->prev_ptr = p_value->prev_ptr;
		} else {
			_data->last = p_value->prev_ptr;
		}

		p_value->next_ptr = p_where;
		if (!p_where) {
			p_value->prev_ptr = _data->last;
			_data->last = p_value;
			return;
		}

		p_value->prev_ptr = p_where->prev_ptr;

		if (p_where->prev_ptr) {
			p_where->prev_ptr->next_ptr = p_value;
		} else {
			_data->first = p_value;
		}

		p_where->prev_ptr = p_value;
	}

	/**
	 * Sorts the list using the default comparator by changing the links between elements.
	 */
	void sort() {
		sort_custom<Comparator<T>>();
	}

	/**
	 * Sorts the list by changing the links between elements. The elements keep their addresses.
	 *
	 * - `C` — Strict ordering predicate called with two stored values.
	 */
	template <typename C>
	void sort_custom() {
		if (size() < 2) {
			return;
		}

		SortList<Element, T, &Element::value, &Element::prev_ptr, &Element::next_ptr, C> sorter;
		sorter.sort(_data->first, _data->last);
	}

	/**
	 * Returns the address of the data record used as the backing identity, or null when no record exists.
	 */
	const void *id() const {
		return (void *)_data;
	}

	/**
	 * Creates an independent list by copying the source values in order.
	 *
	 * - `p_list` — Source list.
	 */
	explicit List(const List &p_list) {
		const Element *it = p_list.front();
		while (it) {
			push_back(it->get());
			it = it->next();
		}
	}
	/**
	 * Takes the source list data and leaves the source empty.
	 *
	 * - `p_list` — Source list.
	 */
	List(List &&p_list) {
		_data = p_list._data;
		p_list._data = nullptr;
	}

	/**
	 * Creates an empty list without allocating a data record.
	 */
	List() {}

	/**
	 * Copies the listed values into new elements in initializer order.
	 *
	 * - `p_init` — Values to append to the list in order.
	 */
	List(std::initializer_list<T> p_init) {
		for (const T &E : p_init) {
			push_back(E);
		}
	}

	/**
	 * Erases all elements and releases the list data.
	 */
	~List() {
		clear();
		if (_data) {
			ERR_FAIL_COND(_data->size_cache);
			memdelete_allocator<_Data, A>(_data);
		}
	}
};

template <typename T, typename A>
void List<T, A>::Element::transfer_to_back(List<T, A> *p_dst_list) {
	// Detach from current.

	if (data->first == this) {
		data->first = data->first->next_ptr;
	}
	if (data->last == this) {
		data->last = data->last->prev_ptr;
	}
	if (prev_ptr) {
		prev_ptr->next_ptr = next_ptr;
	}
	if (next_ptr) {
		next_ptr->prev_ptr = prev_ptr;
	}
	data->size_cache--;

	// Attach to the back of the new one.

	if (!p_dst_list->_data) {
		p_dst_list->_data = memnew_allocator(_Data, A);
		p_dst_list->_data->first = this;
		p_dst_list->_data->last = nullptr;
		p_dst_list->_data->size_cache = 0;
		prev_ptr = nullptr;
	} else {
		p_dst_list->_data->last->next_ptr = this;
		prev_ptr = p_dst_list->_data->last;
	}
	p_dst_list->_data->last = this;
	next_ptr = nullptr;

	data = p_dst_list->_data;
	p_dst_list->_data->size_cache++;
}

} // namespace godot
