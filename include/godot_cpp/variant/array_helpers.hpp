/**************************************************************************/
/*  array_helpers.hpp                                                     */
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

namespace godot {
namespace helpers {
/**
 * Appends one element to the container passed by value and returns the result.
 *
 * **Used for** extending a packed array with one item before storing the updated array.
 *
 * - `T` — Container type with an `append()` method that accepts `ValueT`.
 * - `ValueT` — Type of the element passed to `append()`.
 * - `appendable` — Container that receives the element.
 * - `value` — Element to append at the end.
 *
 * ```cpp
 * PackedInt32Array layer_ids;
 * layer_ids.append(2); // Existing foreground layer.
 * const int overlay_id = 7;
 * layer_ids = helpers::append_all(layer_ids, overlay_id);
 * ```
 */
template <typename T, typename ValueT>
T append_all(T appendable, ValueT value) {
	appendable.append(value);
	return appendable;
}

/**
 * Appends each supplied element in order and returns the container by value.
 *
 * **Used for** building a Godot array from a list of arguments while keeping their order.
 *
 * - `T` — Container type whose `append()` method accepts each supplied element.
 * - `ValueT` — Type of the first element.
 * - `Args` — Types of the remaining elements, in order.
 * - `appendable` — Container that receives the elements.
 * - `value` — First element to append.
 * - `args` — Remaining elements to append after `value`.
 *
 * ```cpp
 * const int base_layer = 4, trim_layer = 7, overlay_layer = 9;
 * PackedInt32Array draw_order = helpers::append_all(PackedInt32Array(), base_layer, trim_layer, overlay_layer);
 * ```
 */
template <typename T, typename ValueT, typename... Args>
T append_all(T appendable, ValueT value, Args... args) {
	appendable.append(value);
	return append_all(appendable, args...);
}

/**
 * Returns the supplied container by value without adding an element.
 *
 * **Used for** keeping the starting array when a variadic builder receives an empty argument pack.
 *
 * - `T` — Type of the container to return.
 * - `appendable` — Container to return.
 *
 * ```cpp
 * // In a variadic builder, args contains zero or more renderer layer IDs.
 * // When the pack is empty, this overload keeps the base layer without adding anything.
 * return helpers::append_all(base_layers, args...);
 * ```
 */
template <typename T>
T append_all(T appendable) {
	return appendable;
}
} // namespace helpers
} // namespace godot
