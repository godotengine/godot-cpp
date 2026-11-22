/**************************************************************************/
/*  vset.hpp                                                              */
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

#include <godot_cpp/templates/vector.hpp>

namespace godot {
/**
 * A set backed by a sorted, copy-on-write vector. Insertion uses ordering to find duplicates. The initializer list is copied as supplied.
 *
 * **Used for** collecting distinct IDs in order, such as the tiles that need to be redrawn.
 *
 * - `T` — The stored element type. Its less-than comparison determines order and equivalence.
 *
 * ```cpp
 * // Collect sorted tile IDs for redraw, once per edited tile.
 * VSet<int> dirty_tiles;
 * for (int tile_id : edited_tiles) { dirty_tiles.insert(tile_id); }
 * ```
 */
template <typename T>
class _WARN_UNUSED_ VSet {
	/**
	 * Holds the sorted elements. Copies of the set share this vector's storage until a write detaches it.
	 *
	 * ```cpp
	 * // In VSet::insert(), after finding the insertion index.
	 * _data.insert(pos, p_val);
	 * ```
	 */
	Vector<T> _data;

protected:
	/**
	 * Finds the first position where the value can be inserted in sorted order. Writes whether that position
	 * contains an equivalent element to `r_exact`. An empty set gives index 0 and writes false.
	 *
	 * **Used for** choosing whether to keep an existing element or insert a new element at the returned index.
	 *
	 * - `p_val` — Value whose position is found using the element ordering.
	 * - `r_exact` — Output set to true for an equivalent element and false otherwise.
	 *
	 * ```cpp
	 * // In VSet::insert().
	 * bool exact;
	 * int pos = _find(p_val, exact);
	 * ```
	 */
	_FORCE_INLINE_ int _find(const T &p_val, bool &r_exact) const {
		r_exact = false;
		if (_data.is_empty()) {
			return 0;
		}

		int64_t pos = _data.span().bisect(p_val, true);

		if (pos < _data.size() && !(p_val < _data[pos]) && !(_data[pos] < p_val)) {
			r_exact = true;
		}
		return pos;
	}

	/**
	 * Finds the index of an ordering-equivalent value, or returns -1 when it is absent.
	 *
	 * **Used for** implementing lookups and removals that require an element to exist in the set.
	 *
	 * - `p_val` — Value to compare with the sorted elements.
	 *
	 * ```cpp
	 * // In VSet::has().
	 * return _find_exact(p_val) != -1;
	 * ```
	 */
	_FORCE_INLINE_ int _find_exact(const T &p_val) const {
		if (_data.is_empty()) {
			return -1;
		}

		int64_t pos = _data.span().bisect(p_val, true);

		if (pos < _data.size() && !(p_val < _data[pos]) && !(_data[pos] < p_val)) {
			return pos;
		}
		return -1;
	}

public:
	/**
	 * Inserts a value at its sorted position. An equivalent element already in the set is kept.
	 *
	 * **Used for** adding an ID to a work queue that should list each ID once.
	 *
	 * - `p_val` — Value to insert when no equivalent element is present.
	 *
	 * ```cpp
	 * // Mark this tile for redraw. Repeated edits still produce one queued ID.
	 * dirty_tiles.insert(edited_tile_id);
	 * ```
	 */
	void insert(const T &p_val) {
		bool exact;
		int pos = _find(p_val, exact);
		if (exact) {
			return;
		}
		_data.insert(pos, p_val);
	}

	/**
	 * Tests whether the set contains a value equivalent under its ordering comparison.
	 *
	 * **Used for** checking whether an item is still pending before acting on it.
	 *
	 * - `p_val` — Value to look for.
	 *
	 * ```cpp
	 * // A completed tile job may have been canceled before its result arrived.
	 * if (!pending_tiles.has(completed_tile_id)) { return; }
	 * ```
	 */
	bool has(const T &p_val) const {
		return _find_exact(p_val) != -1;
	}

	/**
	 * Removes the equivalent element when present. Elements after it move one index toward the front.
	 *
	 * **Used for** removing a completed or canceled item from a sorted collection of pending IDs.
	 *
	 * - `p_val` — Value whose equivalent element is removed if present.
	 *
	 * ```cpp
	 * // Remove this tile from the pending set after its redraw completes.
	 * pending_tiles.erase(completed_tile_id);
	 * ```
	 */
	void erase(const T &p_val) {
		int pos = _find_exact(p_val);
		if (pos < 0) {
			return;
		}
		_data.remove_at(pos);
	}

	/**
	 * Returns the zero-based index of the equivalent element or -1 if it is absent.
	 *
	 * **Used for** locating the row for a known ID in a sorted list backed by the set.
	 *
	 * - `p_val` — Value to look for.
	 *
	 * ```cpp
	 * // Move an ItemList selection to the row holding the given layer ID.
	 * int row = available_layers.find(selected_layer_id);
	 * if (row >= 0) { inspector_list->select(row); }
	 * ```
	 */
	int find(const T &p_val) const {
		return _find_exact(p_val);
	}

	/**
	 * Tests whether the set has zero elements.
	 *
	 * **Used for** deciding whether a queue of distinct work items needs to be processed.
	 *
	 * ```cpp
	 * // Skip scheduling a redraw when no tile is dirty.
	 * if (dirty_tiles.is_empty()) { return; }
	 * ```
	 */
	_FORCE_INLINE_ bool is_empty() const { return _data.is_empty(); }

	/**
	 * Returns the number of elements in the set.
	 *
	 * **Used for** setting a progress total or bounding a loop over the sorted entries.
	 *
	 * ```cpp
	 * // Set the total work for a redraw progress bar.
	 * progress->set_max(dirty_tiles.size());
	 * ```
	 */
	_FORCE_INLINE_ int size() const { return _data.size(); }

	/**
	 * Returns a mutable reference at the given zero-based index and detaches shared storage when necessary. A replacement must preserve sorted order and uniqueness for lookup to work.
	 *
	 * **Used for** replacing an element in place when the new value still fits between its neighbors.
	 *
	 * - `p_index` — Index from zero through one less than `godot::VSet::size()`.
	 *
	 * ```cpp
	 * // Replace the first ID in [3, 7, 9] with 4, preserving order and uniqueness.
	 * dirty_tiles[0] = 4;
	 * ```
	 */
	inline T &operator[](int p_index) {
		return _data.write[p_index];
	}

	/**
	 * Returns a const reference at the given zero-based index.
	 *
	 * **Used for** reading elements in sorted order, such as choosing the lowest pending ID.
	 *
	 * - `p_index` — Index from zero through one less than `godot::VSet::size()`.
	 *
	 * ```cpp
	 * // In a const view of the dirty set, choose the smallest tile ID first.
	 * if (!dirty_tiles.is_empty()) { schedule_tile(dirty_tiles[0]); }
	 * ```
	 */
	inline const T &operator[](int p_index) const {
		return _data[p_index];
	}

	/**
	 * Creates a set with no elements.
	 *
	 * **Used for** preparing a sorted collection before the first item is known.
	 *
	 * ```cpp
	 * VSet<int> dirty_tiles; // Start a paint pass with no queued tiles.
	 * dirty_tiles.insert(first_edited_tile);
	 * ```
	 */
	_FORCE_INLINE_ VSet() {}
	/**
	 * Copies the initializer list in the order supplied.
	 *
	 * **Used for** creating a set from a preset list of distinct values already in sorted order.
	 *
	 * - `p_init` — An already sorted list of distinct elements when the set will be used for insertion or lookup.
	 *
	 * ```cpp
	 * // Terrain layer IDs available in a preset, listed in ascending order.
	 * VSet<int> terrain_layers{ 3, 7, 9 };
	 * bool supported = terrain_layers.has(selected_layer_id);
	 * ```
	 */
	_FORCE_INLINE_ VSet(std::initializer_list<T> p_init) :
			_data(p_init) {}
};

} // namespace godot
