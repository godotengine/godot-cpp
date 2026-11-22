/**************************************************************************/
/*  math_funcs_binary.hpp                                                 */
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

namespace Math {

/* Functions to handle powers of 2 and shifting. */

/**
 * Tests whether a positive integer has exactly one set bit. Zero returns false.
 *
 * ```cpp
 * const uint32_t ring_capacity = 64;
 * uint32_t head = 63;
 * if (Math::is_power_of_2(ring_capacity)) { head = (head + 1) & (ring_capacity - 1); }
 * ```
 */
template <typename T>
constexpr bool is_power_of_2(const T x) {
	return x && ((x & (x - 1)) == 0);
}

/**
 * Returns the smallest power of two at least as large as the input. Zero returns zero. An unrepresentable next power wraps to zero.
 *
 * ```cpp
 * const uint64_t requested_bytes = 5000;
 * uint64_t buffer_capacity = Math::next_power_of_2(requested_bytes);
 * ```
 */
constexpr uint64_t next_power_of_2(uint64_t p_number) {
	if (p_number == 0) {
		return 0;
	}

	--p_number;
	p_number |= p_number >> 1;
	p_number |= p_number >> 2;
	p_number |= p_number >> 4;
	p_number |= p_number >> 8;
	p_number |= p_number >> 16;
	p_number |= p_number >> 32;

	return ++p_number;
}

/**
 * Returns the smallest power of two at least as large as the input. Zero returns zero. An unrepresentable next power wraps to zero.
 *
 * ```cpp
 * const uint32_t required_slots = 13;
 * uint32_t ring_capacity = Math::next_power_of_2(required_slots);
 * ```
 */
constexpr uint32_t next_power_of_2(uint32_t p_number) {
	if (p_number == 0) {
		return 0;
	}

	--p_number;
	p_number |= p_number >> 1;
	p_number |= p_number >> 2;
	p_number |= p_number >> 4;
	p_number |= p_number >> 8;
	p_number |= p_number >> 16;

	return ++p_number;
}

/**
 * Returns the largest power of two at most as large as the input, or zero for zero.
 *
 * ```cpp
 * const uint64_t budget_bytes = 5000;
 * uint64_t block_bytes = Math::previous_power_of_2(budget_bytes);
 * ```
 */
constexpr uint64_t previous_power_of_2(uint64_t p_number) {
	p_number |= p_number >> 1;
	p_number |= p_number >> 2;
	p_number |= p_number >> 4;
	p_number |= p_number >> 8;
	p_number |= p_number >> 16;
	p_number |= p_number >> 32;
	return p_number - (p_number >> 1);
}

/**
 * Returns the largest power of two at most as large as the input, or zero for zero.
 *
 * ```cpp
 * const uint32_t max_texture_width = 1500;
 * uint32_t supported_width = Math::previous_power_of_2(max_texture_width);
 * ```
 */
constexpr uint32_t previous_power_of_2(uint32_t p_number) {
	p_number |= p_number >> 1;
	p_number |= p_number >> 2;
	p_number |= p_number >> 4;
	p_number |= p_number >> 8;
	p_number |= p_number >> 16;
	return p_number - (p_number >> 1);
}

/**
 * Returns the nearest power of two, choosing the larger on ties. Zero returns zero. If the closest power exceeds the type's range, the result wraps to zero.
 *
 * ```cpp
 * const uint64_t target_cache_bytes = 6000;
 * uint64_t block_bytes = Math::closest_power_of_2(target_cache_bytes);
 * ```
 */
constexpr uint64_t closest_power_of_2(uint64_t p_number) {
	uint64_t nx = next_power_of_2(p_number);
	uint64_t px = previous_power_of_2(p_number);
	return (nx - p_number) > (p_number - px) ? px : nx;
}

/**
 * Returns the nearest power of two, choosing the larger on ties. Zero returns zero. If the closest power exceeds the type's range, the result wraps to zero.
 *
 * ```cpp
 * const uint32_t target_texture_width = 70;
 * uint32_t resize_width = Math::closest_power_of_2(target_texture_width);
 * ```
 */
constexpr uint32_t closest_power_of_2(uint32_t p_number) {
	uint32_t nx = next_power_of_2(p_number);
	uint32_t px = previous_power_of_2(p_number);
	return (nx - p_number) > (p_number - px) ? px : nx;
}

/**
 * Returns the position of the only set bit, starting at bit zero. Returns -1 for zero and for values with multiple set bits.
 *
 * ```cpp
 * const uint64_t tile_size = 16, pixel_x = 80;
 * const int32_t shift = Math::get_shift_from_power_of_2(tile_size);
 * if (shift < 0) { return; }
 * uint64_t tile_x = pixel_x >> shift;
 * ```
 */
constexpr int32_t get_shift_from_power_of_2(uint64_t p_bits) {
	for (uint64_t i = 0; i < (uint64_t)64; i++) {
		if (p_bits == (uint64_t)((uint64_t)1 << i)) {
			return i;
		}
	}

	return -1;
}

/**
 * Returns the position of the only set bit, starting at bit zero. Returns -1 for zero and for values with multiple set bits.
 *
 * ```cpp
 * const uint32_t block_size = 64, index = 127;
 * const int32_t shift = Math::get_shift_from_power_of_2(block_size);
 * if (shift < 0) { return; }
 * uint32_t block_index = index >> shift;
 * ```
 */
constexpr int32_t get_shift_from_power_of_2(uint32_t p_bits) {
	for (uint32_t i = 0; i < (uint32_t)32; i++) {
		if (p_bits == (uint32_t)((uint32_t)1 << i)) {
			return i;
		}
	}

	return -1;
}

/**
 * Rounds a positive integer up to the next power of two, keeping exact powers unchanged.
 *
 * - `T` — An integer type with a byte size that is a power of two.
 * - `p_number` — A positive value whose rounded result fits in `T`.
 *
 * ```cpp
 * const uint16_t used_entries = 129; // Side-table entries required by the importer.
 * uint16_t table_capacity = Math::nearest_power_of_2_templated(used_entries);
 * ```
 */
template <typename T>
constexpr T nearest_power_of_2_templated(T p_number) {
	--p_number;

	// The number of operations on x is the base two logarithm
	// of the number of bits in the type. Add three to account
	// for sizeof(T) being in bytes.
	constexpr size_t shift_steps = get_shift_from_power_of_2((uint64_t)sizeof(T)) + 3;

	// If the compiler is smart, it unrolls this loop.
	// If it's dumb, this is a bit slow.
	for (size_t i = 0; i < shift_steps; i++) {
		p_number |= p_number >> (1 << i);
	}

	return ++p_number;
}

/**
 * Returns one more than the highest set bit index among the low 63 bits. Returns zero when those bits are clear.
 *
 * ```cpp
 * const uint64_t highest_valid_offset = 511;
 * unsigned packed_bits = unsigned(Math::nearest_shift(highest_valid_offset)); // 9
 * ```
 */
constexpr uint64_t nearest_shift(uint64_t p_number) {
	uint64_t i = 63;
	do {
		i--;
		if (p_number & ((uint64_t)1 << i)) {
			return i + (uint64_t)1;
		}
	} while (i != 0);

	return 0;
}

/**
 * Returns one more than the highest set bit index among the low 31 bits. Returns zero when those bits are clear.
 *
 * ```cpp
 * const uint32_t last_frame_index = 11;
 * uint32_t frame_index_bits = Math::nearest_shift(last_frame_index); // 4
 * ```
 */
constexpr uint32_t nearest_shift(uint32_t p_number) {
	uint32_t i = 31;
	do {
		i--;
		if (p_number & ((uint32_t)1 << i)) {
			return i + (uint32_t)1;
		}
	} while (i != 0);

	return 0;
}

/**
 * Returns the floor of the base-two logarithm for integers from two upward. Zero and one return themselves.
 *
 * ```cpp
 * const uint32_t texture_width = 256, texture_height = 128;
 * const uint32_t largest = texture_width > texture_height ? texture_width : texture_height;
 * uint32_t mip_levels = largest <= 1 ? 1 : 1 + Math::floor_log2(largest);
 * ```
 */
template <typename T>
constexpr T floor_log2(T x) {
	return x < 2 ? x : 1 + floor_log2(x >> 1);
}

// Get the number of bits needed to represent the number.
// IE, if you pass in 8, you will get 4.
/**
 * Returns `floor_log2(x)`. For inputs of two or more, this is the zero-based index of the highest set bit.
 *
 * ```cpp
 * const uint32_t last_frame_index = 11; // 12 frames, indexed from zero.
 * uint32_t index_bits = last_frame_index < 2 ? last_frame_index : Math::get_num_bits(last_frame_index) + 1;
 * ```
 */
template <typename T>
constexpr T get_num_bits(T x) {
	return floor_log2(x);
}

} //namespace Math

} //namespace godot
