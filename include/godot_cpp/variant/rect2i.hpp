/**************************************************************************/
/*  rect2i.hpp                                                            */
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

#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/variant/vector2i.hpp>

namespace godot {

class String;
struct Rect2;

/**
 * An axis-aligned rectangle in a 2D space with integer coordinates.
 * The position stores the starting corner, and the size stores the width and height.
 * Overlap and containment tests expect non-negative sizes and compare coordinates in the same space.
 *
 * ```cpp
 * // Crop one 32 ? 16 frame from a loaded sprite sheet (Ref<Image> atlas).
 * Rect2i frame(64, 0, 32, 16);
 * Ref<Image> icon = atlas->get_region(frame);
 * ```
 */
struct [[nodiscard]] Rect2i {
	/**
	 * The starting corner in the rectangle's coordinate space. For a non-negative
	 * size, this is the top-left corner when X increases rightward and Y increases downward.
	 *
	 * ```cpp
	 * // Advance an atlas region by one frame in a row of equally sized frames.
	 * region.position.x += region.size.width;
	 * ```
	 */
	Point2i position;
	/**
	 * The width along X and height along Y, measured from the starting corner.
	 *
	 * ```cpp
	 * // Limit the right edge of an image crop to the image width.
	 * crop.size.width = MIN(crop.size.width, image->get_width() - crop.position.x);
	 * ```
	 */
	Size2i size;

	/**
	 * Returns a const reference to the starting corner stored in this rectangle.
	 *
	 * ```cpp
	 * // Convert a click in image pixels to coordinates relative to the crop.
	 * Point2i pixel_in_crop = click_in_image - crop.get_position();
	 * ```
	 */
	const Point2i &get_position() const { return position; }
	/**
	 * Moves the rectangle by setting its starting corner and keeping its size.
	 *
	 * - `p_position` — New starting corner in this rectangle's coordinate system.
	 *
	 * ```cpp
	 * // Reuse an atlas region for the next frame in the same row.
	 * region.set_position(region.position + Point2i(region.size.width, 0));
	 * Ref<Image> frame = atlas->get_region(region);
	 * ```
	 */
	void set_position(const Point2i &p_position) { position = p_position; }
	/**
	 * Returns a const reference to the width and height stored in this rectangle.
	 *
	 * ```cpp
	 * // Allocate a blank RGBA8 image the size of a nonempty source region.
	 * const Size2i &extent = region.get_size();
	 * Ref<Image> mask = Image::create_empty(extent.width, extent.height, false, Image::FORMAT_RGBA8);
	 * ```
	 */
	const Size2i &get_size() const { return size; }
	/**
	 * Sets the width and height while keeping the starting corner fixed.
	 *
	 * - `p_size` — New width and height measured from the starting corner.
	 *
	 * ```cpp
	 * // Resize a selection with a cursor constrained to its bottom-right quadrant.
	 * selection.set_size(cursor_in_canvas - selection.position);
	 * ```
	 */
	void set_size(const Size2i &p_size) { size = p_size; }

	/**
	 * Returns the width multiplied by the height, in square coordinate units.
	 *
	 * ```cpp
	 * // Allocate a buffer for a nonempty RGBA8 readback region in pixels.
	 * PackedByteArray pixels;
	 * pixels.resize(int64_t(readback_region.get_area()) * 4);
	 * ```
	 */
	int get_area() const { return size.width * size.height; }

	/**
	 * Returns the center in the rectangle's coordinate space. Integer division
	 * rounds the half-size of each odd dimension toward the starting corner.
	 *
	 * ```cpp
	 * // Center a 4 ? 4 pixel handle over a selection in canvas pixels.
	 * Point2i handle_origin = selection.get_center() - Point2i(2, 2);
	 * ```
	 */
	_FORCE_INLINE_ Vector2i get_center() const { return position + (size / 2); }

	/**
	 * Tests whether each rectangle starts strictly before the other ends on both axes.
	 * Touching edges or corners alone return false. A zero-size rectangle strictly inside
	 * the other rectangle can still pass the test.
	 *
	 * - `p_rect` — Other rectangle in the same coordinate system.
	 *
	 * ```cpp
	 * // In a tile cache, dirty_pixels and tile_bounds use the same image coordinates.
	 * if (dirty_pixels.intersects(tile_bounds)) { tile_needs_rebuild = true; }
	 * ```
	 */
	inline bool intersects(const Rect2i &p_rect) const {
#ifdef MATH_CHECKS
		if (unlikely(size.x < 0 || size.y < 0 || p_rect.size.x < 0 || p_rect.size.y < 0)) {
			ERR_PRINT("Rect2i size is negative, this is not supported. Use Rect2i.abs() to get a Rect2i with a positive size.");
		}
#endif
		if (position.x >= (p_rect.position.x + p_rect.size.width)) {
			return false;
		}
		if ((position.x + size.width) <= p_rect.position.x) {
			return false;
		}
		if (position.y >= (p_rect.position.y + p_rect.size.height)) {
			return false;
		}
		if ((position.y + size.height) <= p_rect.position.y) {
			return false;
		}

		return true;
	}

	/**
	 * Tests whether the other rectangle's starting and ending coordinates lie
	 * within this rectangle's bounds on both axes. Equal boundaries count.
	 *
	 * - `p_rect` — Other rectangle in the same coordinate system.
	 *
	 * ```cpp
	 * // Check that a requested frame fits inside the loaded atlas before extracting it.
	 * if (Rect2i(Point2i(), atlas->get_size()).encloses(frame)) {
	 *     frame_image = atlas->get_region(frame);
	 * }
	 * ```
	 */
	inline bool encloses(const Rect2i &p_rect) const {
#ifdef MATH_CHECKS
		if (unlikely(size.x < 0 || size.y < 0 || p_rect.size.x < 0 || p_rect.size.y < 0)) {
			ERR_PRINT("Rect2i size is negative, this is not supported. Use Rect2i.abs() to get a Rect2i with a positive size.");
		}
#endif
		return (p_rect.position.x >= position.x) && (p_rect.position.y >= position.y) &&
				((p_rect.position.x + p_rect.size.x) <= (position.x + size.x)) &&
				((p_rect.position.y + p_rect.size.y) <= (position.y + size.y));
	}

	/**
	 * Returns true when both width and height are strictly positive.
	 *
	 * ```cpp
	 * // Skip a texture update if clipping left no pixels (Rect2i clipped_region).
	 * if (!clipped_region.has_area()) { return; }
	 * Ref<Image> patch = image->get_region(clipped_region);
	 * ```
	 */
	_FORCE_INLINE_ bool has_area() const {
		return size.x > 0 && size.y > 0;
	}

	/**
	 * Returns the common bounds if the rectangles pass the intersection test.
	 * If they only touch at their outer edges or are apart, returns a default rectangle.
	 * An interior zero-size rectangle can produce a result at its position with zero size.
	 *
	 * - `p_rect` — Other rectangle in the same coordinate system.
	 *
	 * ```cpp
	 * // Clip a brush stroke's pixel bounds to the image before extracting the patch.
	 * Rect2i clipped = stroke_bounds.intersection(Rect2i(Point2i(), image->get_size()));
	 * if (clipped.has_area()) { patch = image->get_region(clipped); }
	 * ```
	 */
	inline Rect2i intersection(const Rect2i &p_rect) const {
		Rect2i new_rect = p_rect;

		if (!intersects(new_rect)) {
			return Rect2i();
		}

		new_rect.position = p_rect.position.max(position);

		Point2i p_rect_end = p_rect.position + p_rect.size;
		Point2i end = position + size;

		new_rect.size = p_rect_end.min(end) - new_rect.position;

		return new_rect;
	}

	/**
	 * Returns the smallest axis-aligned rectangle that encloses both rectangles.
	 * A zero-size rectangle still contributes its position to the result.
	 *
	 * - `p_rect` — Other rectangle in the same coordinate system.
	 *
	 * ```cpp
	 * // Invalidate both the old and new marker positions in one repaint.
	 * Rect2i repaint = previous_marker.merge(current_marker);
	 * ```
	 */
	inline Rect2i merge(const Rect2i &p_rect) const {
#ifdef MATH_CHECKS
		if (unlikely(size.x < 0 || size.y < 0 || p_rect.size.x < 0 || p_rect.size.y < 0)) {
			ERR_PRINT("Rect2i size is negative, this is not supported. Use Rect2i.abs() to get a Rect2i with a positive size.");
		}
#endif
		Rect2i new_rect;

		new_rect.position = p_rect.position.min(position);

		new_rect.size = (p_rect.position + p_rect.size).max(position + size);

		new_rect.size = new_rect.size - new_rect.position; // Make relative again.

		return new_rect;
	}
	/**
	 * Tests a point in the rectangle's coordinate space. Each coordinate must
	 * be at least the corresponding start coordinate and strictly below the end coordinate.
	 *
	 * - `p_point` — Point in the same coordinate system. The right and bottom edges are excluded.
	 *
	 * ```cpp
	 * // Test a click against a button rectangle in the same canvas coordinates.
	 * if (button_bounds.has_point(click_in_canvas)) { button->grab_focus(); }
	 * ```
	 */
	bool has_point(const Point2i &p_point) const {
#ifdef MATH_CHECKS
		if (unlikely(size.x < 0 || size.y < 0)) {
			ERR_PRINT("Rect2i size is negative, this is not supported. Use Rect2i.abs() to get a Rect2i with a positive size.");
		}
#endif
		if (p_point.x < position.x) {
			return false;
		}
		if (p_point.y < position.y) {
			return false;
		}

		if (p_point.x >= (position.x + size.x)) {
			return false;
		}
		if (p_point.y >= (position.y + size.y)) {
			return false;
		}

		return true;
	}

	/**
	 * Returns true when both rectangles have exactly the same position and size.
	 *
	 * - `p_rect` — Rectangle whose position and size are compared with this rectangle.
	 *
	 * ```cpp
	 * // Reuse a cached crop of the same unchanged atlas image.
	 * if (requested_region == cached_region) { return cached_frame; }
	 * ```
	 */
	constexpr bool operator==(const Rect2i &p_rect) const { return position == p_rect.position && size == p_rect.size; }
	/**
	 * Returns true when the rectangles differ in position or size.
	 *
	 * - `p_rect` — Rectangle whose position and size are compared with this rectangle.
	 *
	 * ```cpp
	 * // Update a region-enabled Sprite2D when the selected atlas frame changes.
	 * if (next_region != current_region) {
	 *     sprite->set_region_rect(next_region);
	 *     current_region = next_region;
	 * }
	 * ```
	 */
	constexpr bool operator!=(const Rect2i &p_rect) const { return position != p_rect.position || size != p_rect.size; }

	/**
	 * Returns a copy with each edge moved outward by the given number of units.
	 * A negative amount moves each edge inward and can produce a negative size.
	 *
	 * - `p_amount` — Distance to move each edge outward. A negative amount moves the edges inward.
	 *
	 * ```cpp
	 * // Give a small selection handle a 4-pixel hit margin on every edge.
	 * if (handle_bounds.grow(4).has_point(click_in_canvas)) { dragging_handle = true; }
	 * ```
	 */
	Rect2i grow(int p_amount) const {
		Rect2i g = *this;
		g.position.x -= p_amount;
		g.position.y -= p_amount;
		g.size.width += p_amount * 2;
		g.size.height += p_amount * 2;
		return g;
	}

	/**
	 * Returns a copy with the selected edge moved outward by the given number
	 * of units. A negative amount moves that edge inward.
	 *
	 * - `p_side` — Edge to move.
	 * - `p_amount` — Distance to move the edge outward. A negative amount moves it inward.
	 *
	 * ```cpp
	 * // Extend a panel's layout bounds down by the measured footer height.
	 * panel_bounds = panel_bounds.grow_side(SIDE_BOTTOM, footer_height);
	 * ```
	 */
	inline Rect2i grow_side(Side p_side, int p_amount) const {
		Rect2i g = *this;
		g = g.grow_individual((SIDE_LEFT == p_side) ? p_amount : 0,
				(SIDE_TOP == p_side) ? p_amount : 0,
				(SIDE_RIGHT == p_side) ? p_amount : 0,
				(SIDE_BOTTOM == p_side) ? p_amount : 0);
		return g;
	}

	/**
	 * Converts the unsigned side argument to `Side` and forwards it to `grow_side()`.
	 * The Godot engine uses this adapter to expose `grow_side()` to Variant calls.
	 *
	 * - `p_side` — The integer value of a `Side` enumerator.
	 *
	 * - `p_amount` — Distance to move the edge outward. A negative amount moves it inward.
	 *
	 * ```cpp
	 * // In the Godot engine's Variant method table (core/variant/variant_call.cpp).
	 * bind_methodv(Rect2i, grow_side, &Rect2i::grow_side_bind, sarray("side", "amount"), varray());
	 * ```
	 */
	inline Rect2i grow_side_bind(uint32_t p_side, int p_amount) const {
		return grow_side(Side(p_side), p_amount);
	}

	/**
	 * Returns a copy with separate offsets for the left, top, right, and bottom
	 * edges. Positive offsets move their edges outward. Negative offsets move them inward.
	 *
	 * - `p_left` — Distance to move the left edge outward.
	 * - `p_top` — Distance to move the top edge outward.
	 * - `p_right` — Distance to move the right edge outward.
	 * - `p_bottom` — Distance to move the bottom edge outward.
	 *
	 * ```cpp
	 * // Set a label background with 6 px on each side, 3 above, and 5 below.
	 * Rect2i background = text_bounds.grow_individual(6, 3, 6, 5);
	 * ```
	 */
	inline Rect2i grow_individual(int p_left, int p_top, int p_right, int p_bottom) const {
		Rect2i g = *this;
		g.position.x -= p_left;
		g.position.y -= p_top;
		g.size.width += p_left + p_right;
		g.size.height += p_top + p_bottom;

		return g;
	}

	/**
	 * Returns a copy with the edges extended to the point where needed.
	 * The point uses the same coordinate space as the rectangle.
	 * A point on the right or bottom edge remains outside according to `has_point()`.
	 *
	 * - `p_vector` — Point in the rectangle's coordinate system. Its coordinates can become the new edge positions.
	 *
	 * ```cpp
	 * // Preview a larger crop by extending its edges to a dragged guide in image pixels.
	 * Rect2i preview_crop = saved_crop.expand(guide_point);
	 * ```
	 */
	_FORCE_INLINE_ Rect2i expand(const Vector2i &p_vector) const {
		Rect2i r = *this;
		r.expand_to(p_vector);
		return r;
	}

	/**
	 * Extends this rectangle in place to reach a point in the same coordinate space.
	 * An extended right or bottom edge is still excluded by `has_point()`.
	 *
	 * - `p_vector` — Point in the rectangle's coordinate system. Its coordinates can become the new edge positions.
	 *
	 * ```cpp
	 * // Add one changed pixel to a nonempty dirty region in image coordinates.
	 * dirty_region.expand_to(changed_pixel);
	 * dirty_region.expand_to(changed_pixel + Point2i(1, 1)); // Include the pixel's far edges.
	 * ```
	 */
	inline void expand_to(const Point2i &p_vector) {
#ifdef MATH_CHECKS
		if (unlikely(size.x < 0 || size.y < 0)) {
			ERR_PRINT("Rect2i size is negative, this is not supported. Use Rect2i.abs() to get a Rect2i with a positive size.");
		}
#endif
		Point2i begin = position;
		Point2i end = position + size;

		if (p_vector.x < begin.x) {
			begin.x = p_vector.x;
		}
		if (p_vector.y < begin.y) {
			begin.y = p_vector.y;
		}

		if (p_vector.x > end.x) {
			end.x = p_vector.x;
		}
		if (p_vector.y > end.y) {
			end.y = p_vector.y;
		}

		position = begin;
		size = end - begin;
	}

	/**
	 * Returns a rectangle with the same geometric bounds and a non-negative size.
	 * For each negative dimension, the original end coordinate becomes the new start.
	 *
	 * ```cpp
	 * // Normalize a box selection dragged in any direction in canvas pixels.
	 * Rect2i selection = Rect2i(drag_start, drag_end - drag_start).abs();
	 * ```
	 */
	_FORCE_INLINE_ Rect2i abs() const {
		return Rect2i(position + size.mini(0), size.abs());
	}

	/**
	 * Sets the opposite corner by storing the new end minus the starting corner
	 * as the size. An end coordinate below the start produces a negative dimension.
	 *
	 * - `p_end` — New opposite corner in the same coordinate system as the starting corner.
	 *
	 * ```cpp
	 * // Resize a crop by dragging its bottom-right corner within the image.
	 * crop.set_end(cursor_in_image);
	 * ```
	 */
	_FORCE_INLINE_ void set_end(const Vector2i &p_end) {
		size = p_end - position;
	}

	/**
	 * Returns the opposite corner in the rectangle's coordinate space by adding
	 * the size to the starting corner. With positive sizes, this is the upper bound
	 * on both axes, excluded by `has_point()`.
	 *
	 * ```cpp
	 * // Read the bottom-right pixel of a nonempty region inside the image.
	 * Color corner = image->get_pixelv(region.get_end() - Point2i(1, 1));
	 * ```
	 */
	_FORCE_INLINE_ Vector2i get_end() const {
		return position + size;
	}

	/**
	 * Converts the rectangle to a Godot string with `P` for position and `S` for size.
	 * The conversion requires the `String` definition and initialized Godot bindings.
	 *
	 * ```cpp
	 * // In a GDExtension with initialized bindings, log a rejected atlas crop.
	 * print_error("Crop outside atlas bounds: ", static_cast<String>(requested_region));
	 * ```
	 */
	explicit operator String() const;
	/**
	 * Converts each position and size component to the floating-point type of `Rect2`.
	 * The conversion requires the `Rect2` definition.
	 *
	 * ```cpp
	 * // Display an integer atlas frame on a region-enabled Sprite2D.
	 * Rect2 sprite_region = frame;
	 * sprite->set_region_rect(sprite_region);
	 * ```
	 */
	operator Rect2() const;

	/**
	 * Creates a rectangle with both its position and size set to zero.
	 *
	 * ```cpp
	 * Rect2i dirty; // Start a paint pass with no dirty pixels.
	 * for (const Rect2i &stroke : stroke_bounds) {
	 *     dirty = dirty.has_area() ? dirty.merge(stroke) : stroke;
	 * }
	 * ```
	 */
	Rect2i() = default;
	/**
	 * Creates a rectangle from the starting X and Y coordinates, width, and height.
	 *
	 * - `p_x` — X coordinate of the starting corner.
	 * - `p_y` — Y coordinate of the starting corner.
	 * - `p_width` — Width measured from the starting corner.
	 * - `p_height` — Height measured from the starting corner.
	 *
	 * ```cpp
	 * // Extract a fixed icon from a loaded atlas image at pixel (32, 16).
	 * Ref<Image> icon = atlas->get_region(Rect2i(32, 16, 16, 16));
	 * ```
	 */
	constexpr Rect2i(int p_x, int p_y, int p_width, int p_height) :
			position(Point2i(p_x, p_y)),
			size(Size2i(p_width, p_height)) {
	}
	/**
	 * Creates a rectangle by copying the starting point and the width and height
	 * stored in the size vector.
	 *
	 * - `p_pos` — Starting corner in the rectangle's coordinate system.
	 * - `p_size` — Width and height measured from the starting corner.
	 *
	 * ```cpp
	 * // Copy a patch from a loaded image. Both inputs are in image pixels.
	 * Ref<Image> patch = image->get_region(Rect2i(crop_origin, crop_size));
	 * ```
	 */
	constexpr Rect2i(const Point2i &p_pos, const Size2i &p_size) :
			position(p_pos),
			size(p_size) {
	}
};

/**
 * Marks a zero-filled rectangle as valid with zero position and size.
 *
 * ```cpp
 * // Start with an empty dirty region for each tile.
 * LocalVector<Rect2i> dirty_by_tile;
 * dirty_by_tile.resize(tile_count); // Zero-initializes the new rectangles.
 * ```
 */
template <>
struct is_zero_constructible<Rect2i> : std::true_type {};
} // namespace godot
