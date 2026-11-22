/**************************************************************************/
/*  span.hpp                                                              */
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
#include <godot_cpp/core/error_macros.hpp>

namespace godot {

/**
 * Tests equality over the given number of elements. Identical fundamental types are compared by byte
 * representation. Other types are compared with element inequality.
 *
 * **Used for** checking whether a decoded file header matches the expected signature.
 *
 * - `LHS` — Element type of the first range.
 * - `RHS` — Element type of the second range.
 * - `p_lhs` — Pointer to the first range.
 * - `p_rhs` — Pointer to the second range.
 * - `p_size` — Element count in both ranges. Zero permits empty ranges without dereferencing the pointers.
 *
 * ```cpp
 * const uint8_t header[] = { 0x47, 0x44 };
 * const uint8_t magic[] = { 0x47, 0x44 };
 * const bool valid_header = godot::are_spans_equal(header, magic, sizeof(magic));
 * ```
 */
template <typename LHS, typename RHS>
bool are_spans_equal(const LHS *p_lhs, const RHS *p_rhs, size_t p_size) {
	if constexpr (std::is_same_v<LHS, RHS> && std::is_fundamental_v<LHS>) {
		// Optimize trivial type comparison.
		// is_trivially_equality_comparable would help, but it doesn't exist.
		// memcmp requires pointer argument to be valid even on size = 0 (C11 §7.24.1(2)).
		// Span allows ptr arguments to be invalid as long as size = 0, so only call when p_size > 0.
		return p_size == 0 || memcmp(p_lhs, p_rhs, p_size * sizeof(LHS)) == 0;
	} else {
		// Normal case: Need to iterate the array manually.
		for (size_t j = 0; j < p_size; j++) {
			if (p_lhs[j] != p_rhs[j]) {
				return false;
			}
		}

		return true;
	}
}

// Equivalent of std::span.
// Represents a view into a contiguous memory space.
// DISCLAIMER: This data type does not own the underlying buffer. DO NOT STORE IT.
//  Additionally, for the lifetime of the Span, do not resize the buffer, and do not insert or remove elements from it.
//  Failure to respect this may lead to crashes or undefined behavior.
/**
 * A read-only view into a contiguous buffer. The buffer owner must keep that storage and range valid
 * while the view is in use.
 *
 * **Used for** accepting array data without copying it or taking ownership.
 *
 * - `T` — Element type of the borrowed range.
 *
 * ```cpp
 * const auto sum_weights = [](godot::Span<float> weights) {
 *     float total = 0;
 *     for (float weight : weights) { total += weight; }
 *     return total;
 * };
 * const float weights[] = { 0.25f, 0.75f };
 * const float total = sum_weights(weights);
 * ```
 */
template <typename T>
class Span {
	/**
	 * Points to the first element in the borrowed range.
	 *
	 * ```cpp
	 * // Inside godot::Span<T>::operator[] after the bounds check.
	 * return _ptr[p_idx];
	 * ```
	 */
	const T *_ptr = nullptr;
	/**
	 * Counts the elements in the borrowed range.
	 *
	 * ```cpp
	 * // Inside godot::Span<T>::is_empty().
	 * return _len == 0;
	 * ```
	 */
	uint64_t _len = 0;

public:
	/**
	 * Identifies character types whose C-array constructor omits a trailing zero code unit.
	 *
	 * **Used for** deciding whether the array constructor treats a final zero as a string terminator.
	 *
	 * ```cpp
	 * static_assert(godot::Span<char>::is_string);
	 * static_assert(!godot::Span<uint16_t>::is_string);
	 * ```
	 */
	static constexpr bool is_string = std::disjunction_v<
			std::is_same<T, char>,
			std::is_same<T, char16_t>,
			std::is_same<T, char32_t>,
			std::is_same<T, wchar_t>>;

	/**
	 * Creates an empty view with a null pointer.
	 *
	 * **Used for** representing an optional range before its backing data is available.
	 *
	 * ```cpp
	 * godot::Span<float> weights;
	 * const float fallback = weights.is_empty() ? 1.0f : weights[0];
	 * ```
	 */
	_FORCE_INLINE_ constexpr Span() = default;

	/**
	 * Borrows the given element range. A nonempty range requires a valid pointer and at least the given
	 * number of elements. In a debug build, a null pointer with a nonzero length reports an error and
	 * becomes an empty view.
	 *
	 * **Used for** viewing part of a larger buffer without copying the selected elements.
	 *
	 * - `p_ptr` — Pointer to the first element. A nonempty range requires a valid pointer.
	 * - `p_len` — Number of accessible elements beginning at `p_ptr`.
	 *
	 * ```cpp
	 * const float samples[] = { 0.0f, 0.5f, 0.75f };
	 * const godot::Span<float> payload(samples + 1, 2);
	 * const float first_sample = payload[0];
	 * ```
	 */
	_FORCE_INLINE_ Span(const T *p_ptr, uint64_t p_len) :
			_ptr(p_ptr), _len(p_len) {
#ifdef DEBUG_ENABLED
		// TODO In c++20, make this check run only in non-consteval, and make this constructor constexpr.
		if (_ptr == nullptr && _len > 0) {
			ERR_PRINT("Internal bug, please report: Span was created from nullptr with size > 0. Recovering by using size = 0.");
			_len = 0;
		}
#endif
	}

	// Allows creating Span directly from C arrays and string literals.
	/**
	 * Borrows a C array. For character arrays, excludes the final element if it is zero.
	 *
	 * **Used for** viewing a string literal as code units without its final null terminator.
	 *
	 * - `N` — Size of the source array, including any terminator.
	 * - `p_array` — Array to borrow. Keep it alive while the view is in use.
	 *
	 * ```cpp
	 * const godot::Span<char> command("quit");
	 * const bool matches = command.size() == 4 && command[0] == 'q';
	 * ```
	 */
	template <size_t N>
	_FORCE_INLINE_ constexpr Span(const T (&p_array)[N]) :
			_ptr(p_array), _len(N) {
		if constexpr (is_string) {
			// Cut off the \0 terminator implicitly added to string literals.
			if (N > 0 && p_array[N - 1] == '\0') {
				_len--;
			}
		}
	}

	/**
	 * Returns the length of the borrowed range in elements.
	 *
	 * **Used for** checking whether the input has enough elements for a fixed-size record.
	 *
	 * ```cpp
	 * const int header[] = { 8, 16 };
	 * const godot::Span<int> dimensions(header);
	 * const bool has_dimensions = dimensions.size() >= 2;
	 * ```
	 */
	_FORCE_INLINE_ constexpr uint64_t size() const { return _len; }
	/**
	 * Returns whether the view has zero elements.
	 *
	 * **Used for** handling missing input before reading the first element.
	 *
	 * ```cpp
	 * const godot::Span<float> weights;
	 * const float first_weight = weights.is_empty() ? 0.0f : weights[0];
	 * ```
	 */
	_FORCE_INLINE_ constexpr bool is_empty() const { return _len == 0; }

	/**
	 * Returns the pointer to the start of the borrowed storage.
	 *
	 * **Used for** passing a borrowed buffer to a function that accepts a pointer and count.
	 *
	 * ```cpp
	 * // With <algorithm> included.
	 * const int values[] = { 1, 4, 2 };
	 * const godot::Span<int> samples(values);
	 * const int peak = *std::max_element(samples.ptr(), samples.ptr() + samples.size());
	 * ```
	 */
	_FORCE_INLINE_ constexpr const T *ptr() const { return _ptr; }

	// NOTE: Span subscripts sanity check the bounds to avoid undefined behavior.
	//       This is slower than direct buffer access and can prevent autovectorization.
	//       If the bounds are known, use ptr() subscript instead.
	/**
	 * Returns the element at the zero-based index. An out-of-range index triggers a crash check.
	 *
	 * **Used for** reading a known field of a fixed-size record.
	 *
	 * - `p_idx` — Zero-based element index. It must be less than the span size.
	 *
	 * ```cpp
	 * const int dimensions[] = { 1920, 1080 };
	 * const godot::Span<int> size(dimensions);
	 * const int pixel_count = size[0] * size[1];
	 * ```
	 */
	_FORCE_INLINE_ constexpr const T &operator[](uint64_t p_idx) const {
		CRASH_COND(p_idx >= _len);
		return _ptr[p_idx];
	}

	/**
	 * Returns the iterator to the start of the borrowed range.
	 *
	 * **Used for** finding an element with a standard iterator-based algorithm.
	 *
	 * ```cpp
	 * // With <algorithm> included.
	 * const int samples[] = { 0, 0, 4 };
	 * const godot::Span<int> values(samples);
	 * const auto start = std::find_if(values.begin(), values.end(), [](int value) { return value != 0; });
	 * const bool has_signal = start != values.end();
	 * ```
	 */
	_FORCE_INLINE_ constexpr const T *begin() const { return _ptr; }
	/**
	 * Returns the iterator past the last element of the borrowed range.
	 *
	 * **Used for** checking whether an iterator-based search reached the end of the range.
	 *
	 * ```cpp
	 * // With <algorithm> included.
	 * const int channels[] = { 1, 2, 4 };
	 * const godot::Span<int> supported(channels);
	 * const bool supports_stereo = std::find(supported.begin(), supported.end(), 2) != supported.end();
	 * ```
	 */
	_FORCE_INLINE_ constexpr const T *end() const { return _ptr + _len; }

	/**
	 * Views the same storage as elements of another type, dropping any trailing partial element. The
	 * caller must ensure the storage is suitable for access through that type.
	 *
	 * **Used for** examining the raw bytes of an object array.
	 *
	 * - `T1` — Type through which to read the same storage. The storage must meet its alignment and access rules.
	 *
	 * ```cpp
	 * const uint32_t colors[] = { 0x11223344, 0x55667788 };
	 * const auto bytes = godot::Span<uint32_t>(colors).reinterpret<unsigned char>();
	 * const unsigned char first_byte = bytes[0]; // In the machine's byte order.
	 * ```
	 */
	template <typename T1>
	_FORCE_INLINE_ constexpr Span<T1> reinterpret() const {
		return Span<T1>(reinterpret_cast<const T1 *>(_ptr), _len * sizeof(T) / sizeof(T1));
	}

	// Algorithms.
	/**
	 * Searches forward from the given index and returns the first matching index, or `-1` if absent.
	 *
	 * **Used for** locating the delimiter that ends a field in a buffer.
	 *
	 * - `p_val` — Element to match.
	 * - `p_from` — First index to search. An index at or beyond the end returns `-1`.
	 *
	 * ```cpp
	 * const godot::Span<char> record("width=1920");
	 * const int64_t separator = record.find('=');
	 * const bool has_value = separator >= 0 && uint64_t(separator + 1) < record.size();
	 * ```
	 */
	constexpr int64_t find(const T &p_val, uint64_t p_from = 0) const;
	/**
	 * Finds the first matching sequence at or after the given index, or returns `-1`. The searched
	 * sequence must fit within the view.
	 *
	 * **Used for** locating a marker in a buffer before parsing the following field.
	 *
	 * - `T1` — Element type of the search sequence.
	 * - `p_span` — Sequence to match. Its length must be at most the length of this span.
	 * - `p_from` — First candidate start index.
	 *
	 * ```cpp
	 * const godot::Span<char> record("section:data");
	 * const godot::Span<char> marker(":data");
	 * const int64_t marker_start = record.find_sequence(marker);
	 * ```
	 */
	template <typename T1 = T>
	constexpr int64_t find_sequence(const Span<T1> &p_span, uint64_t p_from = 0) const;
	/**
	 * Searches backward from the supplied in-range index and returns the first matching index encountered,
	 * or `-1`.
	 *
	 * **Used for** locating the previous delimiter before a known field.
	 *
	 * - `p_val` — Element to match.
	 * - `p_from` — First index to search backward. It must be less than the size of the span.
	 *
	 * ```cpp
	 * const godot::Span<char> address("root/room/light");
	 * const int64_t parent_slash = address.rfind('/', 8);
	 * ```
	 */
	constexpr int64_t rfind(const T &p_val, uint64_t p_from) const;
	/**
	 * Searches backward from the last element and returns the last matching index, or `-1`. The view must
	 * be nonempty.
	 *
	 * **Used for** locating the final delimiter in a nonempty path.
	 *
	 * - `p_val` — Element to match starting at the last index.
	 *
	 * ```cpp
	 * const godot::Span<char> path("room/light.png");
	 * const int64_t extension = path.rfind('.');
	 * const bool has_extension = extension >= 0;
	 * ```
	 */
	_FORCE_INLINE_ constexpr int64_t rfind(const T &p_val) const { return rfind(p_val, size() - 1); }
	/**
	 * Searches backward from the supplied starting index for a matching sequence. Returns `-1` if absent.
	 * The starting position must leave enough elements for the sequence.
	 *
	 * **Used for** locating the previous occurrence of a multi-character delimiter.
	 *
	 * - `T1` — Element type of the search sequence.
	 * - `p_span` — Sequence to match.
	 * - `p_from` — First candidate start index. The sequence must fit at that index.
	 *
	 * ```cpp
	 * const godot::Span<char> path("Scene::Room::Lamp");
	 * const godot::Span<char> separator("::");
	 * const int64_t owner_end = path.rfind_sequence(separator, 10);
	 * ```
	 */
	template <typename T1 = T>
	constexpr int64_t rfind_sequence(const Span<T1> &p_span, uint64_t p_from) const;
	/**
	 * Searches backward from the last position where the sequence fits. Returns its starting index or `-1`
	 * if absent. The sequence must fit within the view.
	 *
	 * **Used for** finding the final separator in a qualified name.
	 *
	 * - `T1` — Element type of the search sequence.
	 * - `p_span` — Sequence to match. Its length must be at most the length of this span.
	 *
	 * ```cpp
	 * const godot::Span<char> name("Scene::Room::Lamp");
	 * const godot::Span<char> separator("::");
	 * const int64_t leaf_start = name.rfind_sequence(separator) + 2;
	 * ```
	 */
	template <typename T1 = T>
	_FORCE_INLINE_ constexpr int64_t rfind_sequence(const Span<T1> &p_span) const { return rfind_sequence(p_span, size() - p_span.size()); }
	/**
	 * Counts all elements equal to the supplied value.
	 *
	 * **Used for** counting separators before splitting a buffer into fields.
	 *
	 * - `p_val` — Element to match at each index.
	 *
	 * ```cpp
	 * const godot::Span<char> record("4,8,16");
	 * const uint64_t fields = record.count(',') + 1;
	 * ```
	 */
	constexpr uint64_t count(const T &p_val) const;
	/**
	 * Returns an insertion index in a span sorted by the supplied comparison. The index can equal the span
	 * size.
	 *
	 * **Used for** finding where to insert a key in an already sorted range.
	 *
	 * - `Comparator` — Comparison type that defines the order of the span.
	 * - `p_value` — Value whose insertion index is searched.
	 * - `p_before` — Pass true to insert before equivalent values, or false to insert after them.
	 * - `p_compare` — Comparison used to sort the range.
	 *
	 * ```cpp
	 * const int levels[] = { 2, 4, 4, 8 };
	 * const godot::Span<int> sorted(levels);
	 * const uint64_t first_four = sorted.bisect(4, true);
	 * ```
	 */
	template <typename Comparator = Comparator<T>>
	constexpr uint64_t bisect(const T &p_value, bool p_before, Comparator p_compare = Comparator()) const;

	/**
	 * Returns the greatest element according to the element type's greater-than operator. The span must be
	 * nonempty.
	 *
	 * **Used for** finding the peak of a nonempty set of samples.
	 *
	 * ```cpp
	 * const float waveform[] = { 0.05f, 0.75f, 0.25f };
	 * const float peak = godot::Span<float>(waveform).max();
	 * ```
	 */
	constexpr T max() const;
};

template <typename T>
constexpr int64_t Span<T>::find(const T &p_val, uint64_t p_from) const {
	for (uint64_t i = p_from; i < size(); i++) {
		if (ptr()[i] == p_val) {
			return i;
		}
	}
	return -1;
}

template <typename T>
template <typename T1>
constexpr int64_t Span<T>::find_sequence(const Span<T1> &p_span, uint64_t p_from) const {
	for (uint64_t i = p_from; i <= size() - p_span.size(); i++) {
		if (are_spans_equal(ptr() + i, p_span.ptr(), p_span.size())) {
			return i;
		}
	}

	return -1;
}

template <typename T>
constexpr int64_t Span<T>::rfind(const T &p_val, uint64_t p_from) const {
	DEV_ASSERT(p_from < size());
	for (int64_t i = p_from; i >= 0; i--) {
		if (ptr()[i] == p_val) {
			return i;
		}
	}
	return -1;
}

template <typename T>
template <typename T1>
constexpr int64_t Span<T>::rfind_sequence(const Span<T1> &p_span, uint64_t p_from) const {
	DEV_ASSERT(p_from + p_span.size() <= size());
	for (int64_t i = p_from; i >= 0; i--) {
		if (are_spans_equal(ptr() + i, p_span.ptr(), p_span.size())) {
			return i;
		}
	}

	return -1;
}

template <typename T>
constexpr uint64_t Span<T>::count(const T &p_val) const {
	uint64_t amount = 0;
	for (uint64_t i = 0; i < size(); i++) {
		if (ptr()[i] == p_val) {
			amount++;
		}
	}
	return amount;
}

template <typename T>
template <typename Comparator>
constexpr uint64_t Span<T>::bisect(const T &p_value, bool p_before, Comparator p_compare) const {
	uint64_t lo = 0;
	uint64_t hi = size();
	if (p_before) {
		while (lo < hi) {
			const uint64_t mid = (lo + hi) / 2;
			if (p_compare(ptr()[mid], p_value)) {
				lo = mid + 1;
			} else {
				hi = mid;
			}
		}
	} else {
		while (lo < hi) {
			const uint64_t mid = (lo + hi) / 2;
			if (p_compare(p_value, ptr()[mid])) {
				hi = mid;
			} else {
				lo = mid + 1;
			}
		}
	}
	return lo;
}

template <typename T>
constexpr T Span<T>::max() const {
	DEV_ASSERT(size() > 0);
	T max_val = _ptr[0];
	for (size_t i = 1; i < _len; ++i) {
		if (_ptr[i] > max_val) {
			max_val = _ptr[i];
		}
	}
	return max_val;
}

/**
 * Returns whether the spans have equal lengths and matching content under `godot::are_spans_equal`.
 *
 * **Used for** checking whether a decoded signature exactly matches the expected byte span.
 *
 * - `LHS` — Element type of the first span.
 * - `RHS` — Element type of the second span.
 * - `p_lhs` — First span to compare.
 * - `p_rhs` — Second span to compare.
 *
 * ```cpp
 * const godot::Span<char> tag("GD");
 * const bool matches = tag == godot::Span<char>("GD");
 * ```
 */
template <typename LHS, typename RHS>
bool operator==(const Span<LHS> &p_lhs, const Span<RHS> &p_rhs) {
	return p_lhs.size() == p_rhs.size() && are_spans_equal(p_lhs.ptr(), p_rhs.ptr(), p_lhs.size());
}

/**
 * Returns whether the spans differ in length or content under `godot::are_spans_equal`.
 *
 * **Used for** detecting changes in a saved token before updating a cache.
 *
 * - `LHS` — Element type of the first span.
 * - `RHS` — Element type of the second span.
 * - `p_lhs` — First span to compare.
 * - `p_rhs` — Second span to compare.
 *
 * ```cpp
 * const godot::Span<char> previous("room");
 * const godot::Span<char> current("hall");
 * const bool update_cache = previous != current;
 * ```
 */
template <typename LHS, typename RHS>
_FORCE_INLINE_ bool operator!=(const Span<LHS> &p_lhs, const Span<RHS> &p_rhs) {
	return !(p_lhs == p_rhs);
}

// Zero-constructing Span initializes _ptr and _len to 0 (and thus empty).
/**
 * Marks a zero-initialized span as a valid empty view.
 *
 * **Used for** letting array storage clear newly created span elements into empty views.
 *
 * - `T` — Element type of each span in storage.
 *
 * ```cpp
 * // A byte-clearing allocator can test the trait before choosing its initialization path.
 * using Slot = godot::Span<int>;
 * constexpr bool can_clear_slots = godot::is_zero_constructible_v<Slot>;
 * ```
 */
template <typename T>
struct is_zero_constructible<Span<T>> : std::true_type {};

} // namespace godot
