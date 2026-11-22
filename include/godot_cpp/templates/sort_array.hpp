/**************************************************************************/
/*  sort_array.hpp                                                        */
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

namespace godot {

/**
 * Reports an invalid comparator condition and breaks the enclosing scan when the condition holds.
 */
#define ERR_BAD_COMPARE(cond) \
	if (unlikely(cond)) { \
		ERR_PRINT("bad comparison function; sorting will be broken"); \
		break; \
	}

#ifdef DEBUG_ENABLED
/**
 * Enables comparator boundary checks by default in debug builds.
 */
#define SORT_ARRAY_VALIDATE_ENABLED true
#else
/**
 * Omits comparator boundary checks by default in other builds.
 */
#define SORT_ARRAY_VALIDATE_ENABLED false
#endif

/**
 * Sorts or partitions a contiguous array in place. Bounds are zero-based, with the final index excluded.
 *
 * - `Comparator` — Strict ordering predicate for the elements.
 * - `Validate` — Enables checks for comparator behavior that would make a scan cross its bounds.
 */
template <typename T, typename Comparator = Comparator<T>, bool Validate = SORT_ARRAY_VALIDATE_ENABLED>
class SortArray {
	/**
	 * Groups the cutoff used to select the insertion-sort path.
	 */
	enum {
		/// Largest partition that introsort leaves for the final insertion pass.
		INTROSORT_THRESHOLD = 16
	};

public:
	/**
	 * Determines the ordering used by heap, partition, and insertion operations.
	 */
	Comparator compare;

	/**
	 * Returns the index of the middle-ranked value among the three supplied positions.
	 */
	inline int64_t median_of_3_index(const T *p_ptr, int64_t p_a_index, int64_t p_b_index, int64_t p_c_index) const {
		const T &a = p_ptr[p_a_index];
		const T &b = p_ptr[p_b_index];
		const T &c = p_ptr[p_c_index];
		if (compare(a, b)) {
			if (compare(b, c)) {
				return p_b_index;
			} else if (compare(a, c)) {
				return p_c_index;
			} else {
				return p_a_index;
			}
		} else if (compare(a, c)) {
			return p_a_index;
		} else if (compare(b, c)) {
			return p_c_index;
		} else {
			return p_b_index;
		}
	}

	/**
	 * Returns the floor of the base-two logarithm of a positive integer.
	 */
	inline int64_t bitlog(int64_t p_n) const {
		int64_t k;
		for (k = 0; p_n != 1; p_n >>= 1) {
			++k;
		}
		return k;
	}

	/* Heap / Heapsort functions */

	/**
	 * Fills a heap hole by shifting parents down until the value can be placed. Hole and top indices are relative to the heap start.
	 */
	inline void push_heap(int64_t p_first, int64_t p_hole_idx, int64_t p_top_index, T p_value, T *p_array) const {
		int64_t parent = (p_hole_idx - 1) / 2;
		while (p_hole_idx > p_top_index && compare(p_array[p_first + parent], p_value)) {
			p_array[p_first + p_hole_idx] = p_array[p_first + parent];
			p_hole_idx = parent;
			parent = (p_hole_idx - 1) / 2;
		}
		p_array[p_first + p_hole_idx] = p_value;
	}

	/**
	 * Moves the heap root to the result index and fills the root hole with the supplied replacement value.
	 */
	inline void pop_heap(int64_t p_first, int64_t p_last, int64_t p_result, T p_value, T *p_array) const {
		p_array[p_result] = p_array[p_first];
		adjust_heap(p_first, 0, p_last - p_first, p_value, p_array);
	}
	/**
	 * Moves the heap root to the last element position and restores the heap over the remaining prefix.
	 */
	inline void pop_heap(int64_t p_first, int64_t p_last, T *p_array) const {
		pop_heap(p_first, p_last - 1, p_last - 1, p_array[p_last - 1], p_array);
	}

	/**
	 * Restores the heap below a relative hole index by moving larger children up and placing the replacement value.
	 */
	inline void adjust_heap(int64_t p_first, int64_t p_hole_idx, int64_t p_len, T p_value, T *p_array) const {
		int64_t top_index = p_hole_idx;
		int64_t second_child = 2 * p_hole_idx + 2;

		while (second_child < p_len) {
			if (compare(p_array[p_first + second_child], p_array[p_first + (second_child - 1)])) {
				second_child--;
			}

			p_array[p_first + p_hole_idx] = p_array[p_first + second_child];
			p_hole_idx = second_child;
			second_child = 2 * (second_child + 1);
		}

		if (second_child == p_len) {
			p_array[p_first + p_hole_idx] = p_array[p_first + (second_child - 1)];
			p_hole_idx = second_child - 1;
		}
		push_heap(p_first, p_hole_idx, top_index, p_value, p_array);
	}

	/**
	 * Sorts the range in place by repeatedly moving its heap root to the end of the remaining heap.
	 */
	inline void sort_heap(int64_t p_first, int64_t p_last, T *p_array) const {
		while (p_last - p_first > 1) {
			pop_heap(p_first, p_last--, p_array);
		}
	}

	/**
	 * Rearranges the range into a heap using the configured ordering.
	 */
	inline void make_heap(int64_t p_first, int64_t p_last, T *p_array) const {
		if (p_last - p_first < 2) {
			return;
		}
		int64_t len = p_last - p_first;
		int64_t parent = (len - 2) / 2;

		while (true) {
			adjust_heap(p_first, parent, len, p_array[p_first + parent], p_array);
			if (parent == 0) {
				return;
			}
			parent--;
		}
	}

	/**
	 * Moves the smallest elements into the prefix ending before `p_middle` and sorts that prefix.
	 */
	inline void partial_sort(int64_t p_first, int64_t p_last, int64_t p_middle, T *p_array) const {
		make_heap(p_first, p_middle, p_array);
		for (int64_t i = p_middle; i < p_last; i++) {
			if (compare(p_array[i], p_array[p_first])) {
				pop_heap(p_first, p_middle, i, p_array[i], p_array);
			}
		}
		sort_heap(p_first, p_middle, p_array);
	}

	/**
	 * Builds a heap in the prefix ending before `p_middle` and keeps the smallest elements in that heap.
	 */
	inline void partial_select(int64_t p_first, int64_t p_last, int64_t p_middle, T *p_array) const {
		make_heap(p_first, p_middle, p_array);
		for (int64_t i = p_middle; i < p_last; i++) {
			if (compare(p_array[i], p_array[p_first])) {
				pop_heap(p_first, p_middle, i, p_array[i], p_array);
			}
		}
	}

	/**
	 * Partitions the range around the value at the pivot index and returns the split index.
	 */
	inline int64_t partitioner(int64_t p_first, int64_t p_last, int64_t p_pivot, T *p_array) const {
		const int64_t unmodified_first = p_first;
		const int64_t unmodified_last = p_last;
		const T *pivot_element_location = &p_array[p_pivot];

		while (true) {
			while (p_first != p_pivot && compare(p_array[p_first], *pivot_element_location)) {
				if constexpr (Validate) {
					ERR_BAD_COMPARE(p_first == unmodified_last - 1);
				}
				p_first++;
			}
			p_last--;
			while (p_last != p_pivot && compare(*pivot_element_location, p_array[p_last])) {
				if constexpr (Validate) {
					ERR_BAD_COMPARE(p_last == unmodified_first);
				}
				p_last--;
			}

			if (p_first >= p_last) {
				return p_first;
			}

			if (pivot_element_location == &p_array[p_first]) {
				pivot_element_location = &p_array[p_last];
			} else if (pivot_element_location == &p_array[p_last]) {
				pivot_element_location = &p_array[p_first];
			}
			SWAP(p_array[p_first], p_array[p_last]);
			p_first++;
		}
	}

	/**
	 * Partitions the range until its sections reach the cutoff. Uses heap sort if the depth budget is exhausted.
	 */
	inline void introsort(int64_t p_first, int64_t p_last, T *p_array, int64_t p_max_depth) const {
		while (p_last - p_first > INTROSORT_THRESHOLD) {
			if (p_max_depth == 0) {
				partial_sort(p_first, p_last, p_last, p_array);
				return;
			}

			p_max_depth--;

			int64_t cut = partitioner(
					p_first,
					p_last,
					median_of_3_index(p_array, p_first, p_first + (p_last - p_first) / 2, p_last - 1),
					p_array);

			introsort(cut, p_last, p_array, p_max_depth);
			p_last = cut;
		}
	}

	/**
	 * Narrows the range containing the target rank and finishes small ranges with insertion sort. Uses a heap-based fallback when the depth budget runs out.
	 */
	inline void introselect(int64_t p_first, int64_t p_nth, int64_t p_last, T *p_array, int64_t p_max_depth) const {
		while (p_last - p_first > 3) {
			if (p_max_depth == 0) {
				partial_select(p_first, p_nth + 1, p_last, p_array);
				SWAP(p_first, p_nth);
				return;
			}

			p_max_depth--;

			int64_t cut = partitioner(
					p_first,
					p_last,
					median_of_3_index(p_array, p_first, p_first + (p_last - p_first) / 2, p_last - 1),
					p_array);

			if (cut <= p_nth) {
				p_first = cut;
			} else {
				p_last = cut;
			}
		}

		insertion_sort(p_first, p_last, p_array);
	}

	/**
	 * Shifts larger values right to insert the supplied value. The earlier range must contain an element that stops the backward scan.
	 */
	inline void unguarded_linear_insert(int64_t p_last, T p_value, T *p_array) const {
		int64_t next = p_last - 1;
		while (compare(p_value, p_array[next])) {
			if constexpr (Validate) {
				ERR_BAD_COMPARE(next == 0);
			}
			p_array[p_last] = p_array[next];
			p_last = next;
			next--;
		}
		p_array[p_last] = p_value;
	}

	/**
	 * Inserts the element at `p_last` into the sorted prefix beginning at `p_first`.
	 */
	inline void linear_insert(int64_t p_first, int64_t p_last, T *p_array) const {
		T val = p_array[p_last];
		if (compare(val, p_array[p_first])) {
			for (int64_t i = p_last; i > p_first; i--) {
				p_array[i] = p_array[i - 1];
			}

			p_array[p_first] = val;
		} else {
			unguarded_linear_insert(p_last, val, p_array);
		}
	}

	/**
	 * Sorts the half-open range by inserting each element into its sorted prefix.
	 */
	inline void insertion_sort(int64_t p_first, int64_t p_last, T *p_array) const {
		if (p_first == p_last) {
			return;
		}
		for (int64_t i = p_first + 1; i != p_last; i++) {
			linear_insert(p_first, i, p_array);
		}
	}

	/**
	 * Insertion-sorts a range whose preceding elements can stop the unbounded backward scans.
	 */
	inline void unguarded_insertion_sort(int64_t p_first, int64_t p_last, T *p_array) const {
		for (int64_t i = p_first; i != p_last; i++) {
			unguarded_linear_insert(i, p_array[i], p_array);
		}
	}

	/**
	 * Completes sorting with insertion sort after the partitioning pass, using the first sorted block to bound later insertions.
	 */
	inline void final_insertion_sort(int64_t p_first, int64_t p_last, T *p_array) const {
		if (p_last - p_first > INTROSORT_THRESHOLD) {
			insertion_sort(p_first, p_first + INTROSORT_THRESHOLD, p_array);
			unguarded_insertion_sort(p_first + INTROSORT_THRESHOLD, p_last, p_array);
		} else {
			insertion_sort(p_first, p_last, p_array);
		}
	}

	/**
	 * Sorts the specified half-open range in place.
	 */
	inline void sort_range(int64_t p_first, int64_t p_last, T *p_array) const {
		if (p_first != p_last) {
			introsort(p_first, p_last, p_array, bitlog(p_last - p_first) * 2);
			final_insertion_sort(p_first, p_last, p_array);
		}
	}

	/**
	 * Sorts the first `p_len` elements in place.
	 */
	inline void sort(T *p_array, int64_t p_len) const {
		sort_range(0, p_len, p_array);
	}

	/**
	 * Partitions the range to place the value with the given sorted rank at `p_nth`. The regions on either side need not be sorted.
	 */
	inline void nth_element(int64_t p_first, int64_t p_last, int64_t p_nth, T *p_array) const {
		if (p_first == p_last || p_nth == p_last) {
			return;
		}
		introselect(p_first, p_nth, p_last, p_array, bitlog(p_last - p_first) * 2);
	}
};

} // namespace godot
