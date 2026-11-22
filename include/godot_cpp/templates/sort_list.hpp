/**************************************************************************/
/*  sort_list.hpp                                                         */
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

#include <godot_cpp/core/defs.hpp>

namespace godot {

/**
 * Sorts a doubly linked range by relinking its elements. Elements that compare equivalent keep their relative order.
 *
 * - `Element` — The node type containing the value and links.
 * - `T` — The value type used by the comparator.
 * - `value` — Pointer to the element's sortable member.
 * - `prev` — Pointer to the element's backward link.
 * - `next` — Pointer to the element's forward link.
 * - `Comparator` — Callable that returns true if the first value should precede the second.
 *
 * ```cpp
 * // In List::sort_custom(), order the existing nodes by their stored values.
 * SortList<Element, T, &Element::value, &Element::prev_ptr, &Element::next_ptr, C> sorter;
 * sorter.sort(_data->first, _data->last);
 * ```
 */
template <typename Element, typename T, T Element::*value, Element *Element::*prev, Element *Element::*next, typename Comparator = Comparator<T>>
class SortList {
public:
	/**
	 * The ordering object used for every comparison in the linked range.
	 *
	 * ```cpp
	 * // In SortList::_is_sorted(), when comparing two adjacent elements.
	 * if (compare(r_sorted_until->*next->*value, r_sorted_until->*value)) { return false; }
	 * ```
	 */
	Comparator compare;

	/**
	 * Sorts the inclusive range between the head and tail and updates both pointers. Links immediately outside the range reconnect to its new ends.
	 *
	 * ```cpp
	 * // In List::sort_custom(), after the short-list check.
	 * SortList<Element, T, &Element::value, &Element::prev_ptr, &Element::next_ptr, C> sorter;
	 * sorter.sort(_data->first, _data->last);
	 * ```
	 */
	void sort(Element *&r_head, Element *&r_tail) {
		Element *sorted_until;
		if (_is_sorted(r_head, r_tail, sorted_until)) {
			return;
		}

		// In case we're sorting only part of a larger list.
		Element *head_prev = r_head->*prev;
		r_head->*prev = nullptr;
		Element *tail_next = r_tail->*next;
		r_tail->*next = nullptr;

		// Sort unsorted section and merge.
		Element *head2 = sorted_until->*next;
		_split(sorted_until, head2);
		_merge_sort(head2, r_tail);
		_merge(r_head, sorted_until, head2, r_tail, r_head, r_tail);

		// Reconnect to larger list if needed.
		if (head_prev) {
			_connect(head_prev, r_head);
		}
		if (tail_next) {
			_connect(r_tail, tail_next);
		}
	}

private:
	/**
	 * Scans adjacent items and returns true if none is out of order.
	 *
	 * - `r_sorted_until` — Receives the last element of the ordered prefix.
	 *
	 * ```cpp
	 * // In SortList::sort().
	 * Element *sorted_until;
	 * if (_is_sorted(r_head, r_tail, sorted_until)) { return; }
	 * ```
	 */
	bool _is_sorted(Element *p_head, Element *p_tail, Element *&r_sorted_until) {
		r_sorted_until = p_head;
		while (r_sorted_until != p_tail) {
			if (compare(r_sorted_until->*next->*value, r_sorted_until->*value)) {
				return false;
			}

			r_sorted_until = r_sorted_until->*next;
		}

		return true;
	}

	/**
	 * Splits a detached range, sorts both halves recursively, and merges them into the new head and tail.
	 *
	 * ```cpp
	 * // In SortList::sort(), after splitting off the unordered suffix.
	 * _merge_sort(head2, r_tail);
	 * ```
	 */
	void _merge_sort(Element *&r_head, Element *&r_tail) {
		if (r_head == r_tail) {
			return;
		}

		Element *tail1 = _get_mid(r_head);
		Element *head2 = tail1->*next;
		_split(tail1, head2);

		_merge_sort(r_head, tail1);
		_merge_sort(head2, r_tail);
		_merge(r_head, tail1, head2, r_tail, r_head, r_tail);
	}

	/**
	 * Relinks two sorted, detached ranges into one sorted range. On ties, takes elements from the first range before the second.
	 *
	 * ```cpp
	 * // In SortList::_merge_sort(), after sorting each half.
	 * _merge(r_head, tail1, head2, r_tail, r_head, r_tail);
	 * ```
	 */
	void _merge(
			Element *p_head1, Element *p_tail1,
			Element *p_head2, Element *p_tail2,
			Element *&r_head, Element *&r_tail) {
		if (compare(p_head2->*value, p_head1->*value)) {
			r_head = p_head2;
			p_head2 = p_head2->*next;
		} else {
			r_head = p_head1;
			p_head1 = p_head1->*next;
		}

		Element *curr = r_head;
		while (p_head1 && p_head2) {
			if (compare(p_head2->*value, p_head1->*value)) {
				_connect(curr, p_head2);
				p_head2 = p_head2->*next;
			} else {
				_connect(curr, p_head1);
				p_head1 = p_head1->*next;
			}
			curr = curr->*next;
		}

		if (p_head1) {
			_connect(curr, p_head1);
			r_tail = p_tail1;
		} else {
			_connect(curr, p_head2);
			r_tail = p_tail2;
		}
	}

	/**
	 * Uses the forward links to find the middle element of a detached range. For an even count, returns the last element of the first half.
	 *
	 * ```cpp
	 * // In SortList::_merge_sort().
	 * Element *tail1 = _get_mid(r_head);
	 * ```
	 */
	Element *_get_mid(Element *p_head) {
		Element *end = p_head;
		Element *mid = p_head;
		while (end->*next && end->*next->*next) {
			end = end->*next->*next;
			mid = mid->*next;
		}

		return mid;
	}

	/**
	 * Makes the right element follow the left element by setting both links between them.
	 *
	 * ```cpp
	 * // In SortList::sort(), when reconnecting the external predecessor.
	 * if (head_prev) { _connect(head_prev, r_head); }
	 * ```
	 */
	_FORCE_INLINE_ void _connect(Element *p_a, Element *p_b) {
		p_a->*next = p_b;
		p_b->*prev = p_a;
	}

	/**
	 * Breaks both links between the last element of the first range and the first element of the second range.
	 *
	 * ```cpp
	 * // In SortList::_merge_sort(), after identifying the adjacent elements.
	 * _split(tail1, head2);
	 * ```
	 */
	_FORCE_INLINE_ void _split(Element *p_a, Element *p_b) {
		p_a->*next = nullptr;
		p_b->*prev = nullptr;
	}
};

} // namespace godot
