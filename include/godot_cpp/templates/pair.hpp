/**************************************************************************/
/*  pair.hpp                                                              */
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
 * Stores two values that can have different types. Ordering compares the first members and uses the second members to break ties.
 *
 * ```cpp
 * // Keep the row and column of the selected frame together.
 * Pair<int, int> frame(atlas_row, atlas_column);
 * Rect2i region(frame.second * tile_width, frame.first * tile_height, tile_width, tile_height);
 * ```
 */
template <typename F, typename S>
struct Pair {
	/**
	 * Holds the first value, which also takes priority in ordering comparisons.
	 *
	 * ```cpp
	 * // frame is a Pair<int, int> holding an atlas row and column.
	 * int source_y = frame.first * tile_height;
	 * ```
	 */
	F first{};
	/**
	 * Holds the second value, which breaks ties in ordering comparisons.
	 *
	 * ```cpp
	 * // frame is a Pair<int, int> holding an atlas row and column.
	 * int source_x = frame.second * tile_width;
	 * ```
	 */
	S second{};

	/**
	 * Uses empty brace initialization for both values. Scalar members are initialized to zero.
	 *
	 * ```cpp
	 * Pair<int, int> cell; // Start scanning an atlas at row 0, column 0.
	 * ++cell.second; // Advance to the next column.
	 * ```
	 */
	constexpr Pair() = default;
	/**
	 * Copies the supplied values into the first and second members in that order.
	 *
	 * ```cpp
	 * // Keep both dimensions returned by the image decoder.
	 * Pair<int, int> dimensions(decoded_width, decoded_height);
	 * bool needs_downsample = dimensions.first > max_texture_width;
	 * ```
	 */
	constexpr Pair(const F &p_first, const S &p_second) :
			first(p_first), second(p_second) {}

	/**
	 * Returns true if both first and second are equal.
	 *
	 * ```cpp
	 * // Compare (texture page, frame index) entries from the draw list.
	 * bool reuse_command = current == cached;
	 * ```
	 */
	constexpr bool operator==(const Pair &p_other) const { return first == p_other.first && second == p_other.second; }
	/**
	 * Returns true if either first or second differs.
	 *
	 * ```cpp
	 * // Compare (texture page, frame index) entries from the draw list.
	 * bool rebuild_command = current != cached;
	 * ```
	 */
	constexpr bool operator!=(const Pair &p_other) const { return first != p_other.first || second != p_other.second; }
	/**
	 * Returns true if the first is smaller or equal with a smaller second.
	 *
	 * ```cpp
	 * // Compare (texture page, frame index) entries from the draw list.
	 * const auto &first_to_draw = current < candidate ? current : candidate;
	 * ```
	 */
	constexpr bool operator<(const Pair &p_other) const { return first == p_other.first ? (second < p_other.second) : (first < p_other.first); }
	/**
	 * Returns true if the first is smaller or equal with a second at most as large.
	 *
	 * ```cpp
	 * // Compare (texture page, frame index) entries from the draw list.
	 * bool within_scan_range = current <= last;
	 * ```
	 */
	constexpr bool operator<=(const Pair &p_other) const { return first == p_other.first ? (second <= p_other.second) : (first < p_other.first); }
	/**
	 * Returns true if the first is larger or equal with a larger second.
	 *
	 * ```cpp
	 * // Compare (texture page, frame index) entries from the draw list.
	 * const auto &first_in_reverse = current > candidate ? current : candidate;
	 * ```
	 */
	constexpr bool operator>(const Pair &p_other) const { return first == p_other.first ? (second > p_other.second) : (first > p_other.first); }
	/**
	 * Returns true if the first is larger or equal with a second at least as large.
	 *
	 * ```cpp
	 * // Compare (texture page, frame index) entries from the draw list.
	 * bool within_reverse_scan = current >= first;
	 * ```
	 */
	constexpr bool operator>=(const Pair &p_other) const { return first == p_other.first ? (second >= p_other.second) : (first > p_other.first); }
};

/**
 * A comparator that orders pairs by the first member and then the second.
 *
 * ```cpp
 * // Sort existing frame entries by texture page, then by frame index.
 * std::sort(frames.begin(), frames.end(), PairSort<int, int>());
 * ```
 */
template <typename F, typename S>
struct PairSort {
	/**
	 * Delegates to `Pair::operator<()` so pairs with equal first members are ordered by their second members.
	 *
	 * ```cpp
	 * // Merge two sorted lists of (texture page, frame index) pairs.
	 * const auto &next_frame = PairSort<int, int>()(left_frame, right_frame) ? left_frame : right_frame;
	 * ```
	 */
	constexpr bool operator()(const Pair<F, S> &p_lhs, const Pair<F, S> &p_rhs) const {
		return p_lhs < p_rhs;
	}
};

/**
 * Allows array placement to clear a pair's storage to zero when both member types are zero-constructible.
 *
 * ```cpp
 * // In the atlas importer, new row/column counters begin at zero.
 * LocalVector<Pair<int, int>> counters;
 * counters.resize(page_count);
 * ```
 */
template <typename F, typename S>
struct is_zero_constructible<Pair<F, S>> : std::conjunction<is_zero_constructible<F>, is_zero_constructible<S>> {};

/**
 * Holds a key that cannot be changed and a value that can be changed. Map entries use this layout to keep key lookup stable when a value is edited.
 *
 * ```cpp
 * // Store a tile ID and its collision-layer mask, then enable layer 2.
 * KeyValue<int, uint32_t> entry(tile_id, collision_mask);
 * entry.value |= uint32_t(1) << 1;
 * ```
 */
template <typename K, typename V>
struct KeyValue {
	/**
	 * Holds the read-only key of this entry.
	 *
	 * ```cpp
	 * // Copy the cache entry's ID into a diagnostics record.
	 * int preview_id = entry.key;
	 * ```
	 */
	const K key{};
	/**
	 * Holds the value associated with this entry's key.
	 *
	 * ```cpp
	 * // Change the layer mask without replacing the entry's tile ID.
	 * entry.value |= uint32_t(1) << 1;
	 * ```
	 */
	V value{};

	/**
	 * Disallows copy assignment so assignment cannot replace the stored key.
	 *
	 * ```cpp
	 * // Whole-entry copy assignment is deleted. Copy the preview state into a stable entry.
	 * destination.value = source.value;
	 * ```
	 */
	KeyValue &operator=(const KeyValue &p_kv) = delete;
	/**
	 * Disallows move assignment so assignment cannot replace the stored key.
	 *
	 * ```cpp
	 * // Whole-entry move assignment is deleted. Move the label into a stable entry.
	 * destination.value = std::move(source.value);
	 * ```
	 */
	KeyValue &operator=(KeyValue &&p_kv) = delete;

	/**
	 * Constructs an entry by copying the source key and value.
	 *
	 * ```cpp
	 * // Capture the old (tile ID, collision mask) before editing it.
	 * KeyValue<int, uint32_t> before(entry);
	 * entry.value = updated_mask;
	 * ```
	 */
	constexpr KeyValue(const KeyValue &p_kv) = default;
	/**
	 * Constructs an entry from an rvalue. The source key is const and the value can be moved if its type supports moving.
	 *
	 * ```cpp
	 * // Transfer a temporary preview label into an entry whose ID stays fixed.
	 * KeyValue<int, String> preview(std::move(pending_label));
	 * ```
	 */
	constexpr KeyValue(KeyValue &&p_kv) = default;
	/**
	 * Constructs an entry by copying the supplied key and value.
	 *
	 * ```cpp
	 * // Associate a preview ID with the title loaded from its metadata.
	 * KeyValue<int, String> entry(preview_id, title);
	 * ```
	 */
	constexpr KeyValue(const K &p_key, const V &p_value) :
			key(p_key), value(p_value) {}
	/**
	 * Constructs an entry from a pair. The first member supplies the key, and the second supplies the value.
	 *
	 * ```cpp
	 * // An importer supplied (tile ID, layer mask) as a Pair<int, uint32_t>.
	 * KeyValue<int, uint32_t> entry(imported_tile);
	 * ```
	 */
	constexpr KeyValue(const Pair<K, V> &p_pair) :
			key(p_pair.first), value(p_pair.second) {}

	/**
	 * Returns true if both key and value are equal.
	 *
	 * ```cpp
	 * // Compare (tile ID, collision mask) entries from the draw list.
	 * bool reuse_command = current == cached;
	 * ```
	 */
	constexpr bool operator==(const KeyValue &p_other) const { return key == p_other.key && value == p_other.value; }
	/**
	 * Returns true if either key or value differs.
	 *
	 * ```cpp
	 * // Compare (tile ID, collision mask) entries from the draw list.
	 * bool rebuild_command = current != cached;
	 * ```
	 */
	constexpr bool operator!=(const KeyValue &p_other) const { return key != p_other.key || value != p_other.value; }
	/**
	 * Returns true if the key is smaller or equal with a smaller value.
	 *
	 * ```cpp
	 * // Compare (tile ID, collision mask) entries from the draw list.
	 * const auto &first_to_draw = current < candidate ? current : candidate;
	 * ```
	 */
	constexpr bool operator<(const KeyValue &p_other) const { return key == p_other.key ? (value < p_other.value) : (key < p_other.key); }
	/**
	 * Returns true if the key is smaller or equal with a value at most as large.
	 *
	 * ```cpp
	 * // Compare (tile ID, collision mask) entries from the draw list.
	 * bool within_scan_range = current <= last;
	 * ```
	 */
	constexpr bool operator<=(const KeyValue &p_other) const { return key == p_other.key ? (value <= p_other.value) : (key < p_other.key); }
	/**
	 * Returns true if the key is larger or equal with a larger value.
	 *
	 * ```cpp
	 * // Compare (tile ID, collision mask) entries from the draw list.
	 * const auto &first_in_reverse = current > candidate ? current : candidate;
	 * ```
	 */
	constexpr bool operator>(const KeyValue &p_other) const { return key == p_other.key ? (value > p_other.value) : (key > p_other.key); }
	/**
	 * Returns true if the key is larger or equal with a value at least as large.
	 *
	 * ```cpp
	 * // Compare (tile ID, collision mask) entries from the draw list.
	 * bool within_reverse_scan = current >= first;
	 * ```
	 */
	constexpr bool operator>=(const KeyValue &p_other) const { return key == p_other.key ? (value >= p_other.value) : (key > p_other.key); }
};

/**
 * A comparator that orders entries by key alone. Entries with the same key compare equivalent even when their values differ.
 *
 * ```cpp
 * // Binary-search sorted entries by tile ID with a probe whose mask is ignored.
 * auto pos = std::lower_bound(first, last, KeyValue<int, uint32_t>(tile_id, 0), KeyValueSort<int, uint32_t>());
 * ```
 */
template <typename K, typename V>
struct KeyValueSort {
	/**
	 * Returns true if the left entry's key is smaller than the right entry's key.
	 *
	 * ```cpp
	 * // In a merge of two tile registries, select the next entry by ID alone.
	 * const auto &next = KeyValueSort<int, uint32_t>()(left_entry, right_entry) ? left_entry : right_entry;
	 * ```
	 */
	constexpr bool operator()(const KeyValue<K, V> &p_lhs, const KeyValue<K, V> &p_rhs) const {
		return p_lhs.key < p_rhs.key;
	}
};

/**
 * Marks an entry as zero-constructible when both its key and value types are zero-constructible.
 *
 * ```cpp
 * // Verify that array placement can clear newly allocated tile ID and mask slots to zero.
 * static_assert(is_zero_constructible_v<KeyValue<int, uint32_t>>);
 * ```
 */
template <typename K, typename V>
struct is_zero_constructible<KeyValue<K, V>> : std::conjunction<is_zero_constructible<K>, is_zero_constructible<V>> {};

} // namespace godot
