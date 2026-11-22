/**************************************************************************/
/*  rect2.hpp                                                             */
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
#include <godot_cpp/variant/vector2.hpp>

namespace godot {

class String;
struct Rect2i;
struct Transform2D;

/**
 * A 2D axis-aligned bounding box using floating-point coordinates.
 */
struct [[nodiscard]] Rect2 {
	/**
	 * The origin point. This is usually the top-left corner of the rectangle.
	 */
	Point2 position;
	/**
	 * The signed width and height of the rectangle from its starting corner. Most intersection and
	 * containment tests expect nonnegative extents.
	 */
	Size2 size;

	/**
	 * Returns a read-only reference to the corner from which the rectangle extends by its size. In canvas
	 * coordinates with positive size, this is the top-left corner.
	 */
	const Vector2 &get_position() const { return position; }
	/**
	 * Moves the rectangle to the given starting corner and preserves its size.
	 *
	 * - `p_pos` — New starting corner in this rectangle's coordinate system.
	 */
	void set_position(const Vector2 &p_pos) { position = p_pos; }
	/**
	 * Returns a read-only reference to the rectangle's width and height.
	 */
	const Vector2 &get_size() const { return size; }
	/**
	 * Changes the rectangle's width and height while keeping its starting corner fixed.
	 *
	 * - `p_size` — New width and height measured from the starting corner.
	 */
	void set_size(const Vector2 &p_size) { size = p_size; }

	/**
	 * Returns the rectangle's area. This is equivalent to `size.x * size.y`. See also
	 * `godot::Rect2::has_area()`.
	 */
	real_t get_area() const { return size.width * size.height; }

	/**
	 * Returns the center point of the rectangle. This is the same as `position + (size / 2.0)`.
	 */
	_FORCE_INLINE_ Vector2 get_center() const { return position + (size * 0.5f); }

	/**
	 * Returns `true` if this rectangle overlaps with the `b` rectangle. The edges of both rectangles are
	 * excluded, unless `include_borders` is `true`.
	 *
	 * - `p_rect` — Other rectangle in the same coordinate system.
	 * - `p_include_borders` — Whether rectangles that only share an edge or corner count as intersecting.
	 */
	inline bool intersects(const Rect2 &p_rect, bool p_include_borders = false) const {
#ifdef MATH_CHECKS
		if (unlikely(size.x < 0 || size.y < 0 || p_rect.size.x < 0 || p_rect.size.y < 0)) {
			ERR_PRINT("Rect2 size is negative, this is not supported. Use Rect2.abs() to get a Rect2 with a positive size.");
		}
#endif
		if (p_include_borders) {
			if (position.x > (p_rect.position.x + p_rect.size.width)) {
				return false;
			}
			if ((position.x + size.width) < p_rect.position.x) {
				return false;
			}
			if (position.y > (p_rect.position.y + p_rect.size.height)) {
				return false;
			}
			if ((position.y + size.height) < p_rect.position.y) {
				return false;
			}
		} else {
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
		}

		return true;
	}

	inline real_t distance_to(const Vector2 &p_point) const {
#ifdef MATH_CHECKS
		if (unlikely(size.x < 0 || size.y < 0)) {
			ERR_PRINT("Rect2 size is negative, this is not supported. Use Rect2.abs() to get a Rect2 with a positive size.");
		}
#endif
		real_t dist = 0.0;
		bool inside = true;

		if (p_point.x < position.x) {
			real_t d = position.x - p_point.x;
			dist = d;
			inside = false;
		}
		if (p_point.y < position.y) {
			real_t d = position.y - p_point.y;
			dist = inside ? d : MIN(dist, d);
			inside = false;
		}
		if (p_point.x >= (position.x + size.x)) {
			real_t d = p_point.x - (position.x + size.x);
			dist = inside ? d : MIN(dist, d);
			inside = false;
		}
		if (p_point.y >= (position.y + size.y)) {
			real_t d = p_point.y - (position.y + size.y);
			dist = inside ? d : MIN(dist, d);
			inside = false;
		}

		if (inside) {
			return 0;
		} else {
			return dist;
		}
	}

	/**
	 * Tests this rectangle against the quadrilateral formed by transforming the other rectangle's four
	 * corners into this coordinate system.
	 *
	 * - `p_xform` — Transform that maps the other rectangle into this rectangle's coordinate system.
	 * - `p_rect` — Rectangle in the input coordinate system of the transform.
	 */
	bool intersects_transformed(const Transform2D &p_xform, const Rect2 &p_rect) const;

	/**
	 * Tests a finite segment against the rectangle. On a hit, writes the contact point and normal through
	 * the corresponding output pointers if supplied.
	 *
	 * - `p_from` — Start of the segment in the rectangle's coordinate system.
	 * - `p_to` — End of the segment in the rectangle's coordinate system.
	 * - `r_pos` — Optional output for the first hit point in the rectangle's coordinate system. It is unchanged on failure.
	 * - `r_normal` — Optional output for the entry edge normal, or zero if there is no entry edge. It is unchanged on failure.
	 */
	bool intersects_segment(const Point2 &p_from, const Point2 &p_to, Point2 *r_pos = nullptr, Point2 *r_normal = nullptr) const;

	/**
	 * Returns `true` if this rectangle *completely* encloses the `b` rectangle.
	 *
	 * - `p_rect` — Other rectangle in the same coordinate system.
	 */
	inline bool encloses(const Rect2 &p_rect) const {
#ifdef MATH_CHECKS
		if (unlikely(size.x < 0 || size.y < 0 || p_rect.size.x < 0 || p_rect.size.y < 0)) {
			ERR_PRINT("Rect2 size is negative, this is not supported. Use Rect2.abs() to get a Rect2 with a positive size.");
		}
#endif
		return (p_rect.position.x >= position.x) && (p_rect.position.y >= position.y) &&
				((p_rect.position.x + p_rect.size.x) <= (position.x + size.x)) &&
				((p_rect.position.y + p_rect.size.y) <= (position.y + size.y));
	}

	/**
	 * Returns `true` if this rectangle has positive width and height.
	 */
	_FORCE_INLINE_ bool has_area() const {
		return size.x > 0.0f && size.y > 0.0f;
	}

	/**
	 * Returns the axis-aligned bounds of the overlap with the transformed rectangle in this coordinate
	 * system. Returns an empty rectangle if there is no overlap.
	 *
	 * - `p_xform` — Transform that maps the other rectangle into this rectangle's coordinate system.
	 * - `p_rect` — Rectangle in the input coordinate system of the transform.
	 */
	Rect2 intersection_transformed(const Transform2D &p_xform, const Rect2 &p_rect) const;

	// Returns the intersection between two Rect2s or an empty Rect2 if there is no intersection.
	/**
	 * Returns the rectangle shared by both rectangles, or an empty rectangle when they do not intersect.
	 *
	 * - `p_rect` — Other rectangle in the same coordinate system.
	 */
	inline Rect2 intersection(const Rect2 &p_rect) const {
		Rect2 new_rect = p_rect;

		if (!intersects(new_rect)) {
			return Rect2();
		}

		new_rect.position = p_rect.position.max(position);

		Point2 p_rect_end = p_rect.position + p_rect.size;
		Point2 end = position + size;

		new_rect.size = p_rect_end.min(end) - new_rect.position;

		return new_rect;
	}

	/**
	 * Returns a `godot::Rect2` that encloses both this rectangle and `b` around the edges. See also
	 * `godot::Rect2::encloses()`.
	 *
	 * - `p_rect` — Other rectangle in the same coordinate system.
	 */
	inline Rect2 merge(const Rect2 &p_rect) const { ///< return a merged rect
#ifdef MATH_CHECKS
		if (unlikely(size.x < 0 || size.y < 0 || p_rect.size.x < 0 || p_rect.size.y < 0)) {
			ERR_PRINT("Rect2 size is negative, this is not supported. Use Rect2.abs() to get a Rect2 with a positive size.");
		}
#endif
		Rect2 new_rect;

		new_rect.position = p_rect.position.min(position);

		new_rect.size = (p_rect.position + p_rect.size).max(position + size);

		new_rect.size = new_rect.size - new_rect.position; // Make relative again.

		return new_rect;
	}

	/**
	 * Tests whether a point lies in the rectangle. For positive sizes, includes the left and top edges and
	 * excludes the right and bottom edges.
	 *
	 * - `p_point` — Point in the same coordinate system. The right and bottom edges are excluded.
	 */
	inline bool has_point(const Point2 &p_point) const {
#ifdef MATH_CHECKS
		if (unlikely(size.x < 0 || size.y < 0)) {
			ERR_PRINT("Rect2 size is negative, this is not supported. Use Rect2.abs() to get a Rect2 with a positive size.");
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
	 * Returns `true` if this rectangle and `rect` are approximately equal, by calling
	 * `godot::Vector2::is_equal_approx()` on the `position` and the `size`.
	 *
	 * - `p_rect` — Rectangle whose position and size are compared with this rectangle.
	 */
	bool is_equal_approx(const Rect2 &p_rect) const;
	/**
	 * Tests exact equality of position and size, treating corresponding NaN components as equal.
	 *
	 * - `p_rect` — Rectangle whose position and size are compared with this rectangle.
	 */
	bool is_same(const Rect2 &p_rect) const;
	/**
	 * Returns `true` if this rectangle's values are finite, by calling `godot::Vector2::is_finite()` on the
	 * `position` and the `size`.
	 */
	bool is_finite() const;

	/**
	 * Tests exact equality of the components.
	 *
	 * - `p_rect` — Rectangle whose position and size are compared with this rectangle.
	 */
	constexpr bool operator==(const Rect2 &p_rect) const { return position == p_rect.position && size == p_rect.size; }
	/**
	 * Tests whether any component differs.
	 *
	 * - `p_rect` — Rectangle whose position and size are compared with this rectangle.
	 */
	constexpr bool operator!=(const Rect2 &p_rect) const { return position != p_rect.position || size != p_rect.size; }

	/**
	 * Returns a copy of this rectangle extended on all sides by the given `amount`. A negative `amount`
	 * shrinks the rectangle instead.
	 *
	 * - `p_amount` — Distance to move each edge outward. A negative amount moves the edges inward.
	 */
	inline Rect2 grow(real_t p_amount) const {
		Rect2 g = *this;
		g.grow_by(p_amount);
		return g;
	}

	/**
	 * Moves each edge outward by the given distance in place. A negative distance moves each edge inward.
	 *
	 * - `p_amount` — Distance to move each edge outward. A negative amount moves the edges inward.
	 */
	inline void grow_by(real_t p_amount) {
		position.x -= p_amount;
		position.y -= p_amount;
		size.width += p_amount * 2;
		size.height += p_amount * 2;
	}

	/**
	 * Returns a copy with only the selected edge moved outward by the given distance. A negative distance
	 * moves it inward.
	 *
	 * - `p_side` — Edge to move.
	 * - `p_amount` — Distance to move the edge outward. A negative amount moves it inward.
	 */
	inline Rect2 grow_side(Side p_side, real_t p_amount) const {
		Rect2 g = *this;
		g = g.grow_individual((SIDE_LEFT == p_side) ? p_amount : 0,
				(SIDE_TOP == p_side) ? p_amount : 0,
				(SIDE_RIGHT == p_side) ? p_amount : 0,
				(SIDE_BOTTOM == p_side) ? p_amount : 0);
		return g;
	}

	/**
	 * Returns a copy with only the edge identified by the numeric `godot::Side` value moved outward by the
	 * given distance.
	 *
	 * - `p_side` — Integer value of a `godot::Side` enumerator.
	 * - `p_amount` — Distance to move the edge outward. A negative amount moves it inward.
	 */
	inline Rect2 grow_side_bind(uint32_t p_side, real_t p_amount) const {
		return grow_side(Side(p_side), p_amount);
	}

	/**
	 * Returns a copy of this rectangle with its `left`, `top`, `right`, and `bottom` sides extended by the
	 * given amounts. Negative values shrink the sides, instead.
	 *
	 * - `p_left` — Distance to move the left edge outward.
	 * - `p_top` — Distance to move the top edge outward.
	 * - `p_right` — Distance to move the right edge outward.
	 * - `p_bottom` — Distance to move the bottom edge outward.
	 */
	inline Rect2 grow_individual(real_t p_left, real_t p_top, real_t p_right, real_t p_bottom) const {
		Rect2 g = *this;
		g.position.x -= p_left;
		g.position.y -= p_top;
		g.size.width += p_left + p_right;
		g.size.height += p_top + p_bottom;

		return g;
	}

	/**
	 * Returns a copy of this rectangle expanded to align the edges with the given `to` point, if necessary.
	 *
	 * - `p_vector` — Point in the rectangle's coordinate system. Its coordinates can become the new edge positions.
	 */
	_FORCE_INLINE_ Rect2 expand(const Vector2 &p_vector) const {
		Rect2 r = *this;
		r.expand_to(p_vector);
		return r;
	}

	/**
	 * Expands the rectangle in place just enough to enclose the given point.
	 *
	 * - `p_vector` — Point in the rectangle's coordinate system. Its coordinates can become the new edge positions.
	 */
	inline void expand_to(const Vector2 &p_vector) { // In place function for speed.
#ifdef MATH_CHECKS
		if (unlikely(size.x < 0 || size.y < 0)) {
			ERR_PRINT("Rect2 size is negative, this is not supported. Use Rect2.abs() to get a Rect2 with a positive size.");
		}
#endif
		Vector2 begin = position;
		Vector2 end = position + size;

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
	 * Returns the same bounds with nonnegative width and height. Moves the starting corner when the
	 * corresponding extent was negative.
	 */
	_FORCE_INLINE_ Rect2 abs() const {
		return Rect2(position + size.minf(0), size.abs());
	}

	/**
	 * Returns a rectangle with each position and size component rounded to the nearest integer.
	 */
	_FORCE_INLINE_ Rect2 round() const {
		return Rect2(position.round(), size.round());
	}

	/**
	 * Returns the vertex's position of this rect that's the farthest in the given direction. This point is
	 * commonly known as the support point in collision detection algorithms.
	 *
	 * - `p_direction` — Direction in the rectangle's coordinate system. A zero component selects the starting edge for that axis.
	 */
	Vector2 get_support(const Vector2 &p_direction) const {
		Vector2 support = position;
		if (p_direction.x > 0.0f) {
			support.x += size.x;
		}
		if (p_direction.y > 0.0f) {
			support.y += size.y;
		}
		return support;
	}

	/**
	 * Tests whether the rectangle overlaps the filled area or boundary of the polygon described by the
	 * ordered vertices.
	 *
	 * - `p_points` — Readable array of vertices in boundary order and in the rectangle's coordinate system.
	 * - `p_point_count` — Number of vertices in the supplied array.
	 */
	_FORCE_INLINE_ bool intersects_filled_polygon(const Vector2 *p_points, int p_point_count) const {
		Vector2 center = get_center();
		int side_plus = 0;
		int side_minus = 0;
		Vector2 end = position + size;

		int i_f = p_point_count - 1;
		for (int i = 0; i < p_point_count; i++) {
			const Vector2 &a = p_points[i_f];
			const Vector2 &b = p_points[i];
			i_f = i;

			Vector2 r = (b - a);
			const real_t l = r.length();
			if (l == 0.0f) {
				continue;
			}

			// Check inside.
			Vector2 tg = r.orthogonal();
			const real_t s = tg.dot(center) - tg.dot(a);
			if (s < 0.0f) {
				side_plus++;
			} else {
				side_minus++;
			}

			// Check ray box.
			r /= l;
			Vector2 ir(1.0f / r.x, 1.0f / r.y);

			// lb is the corner of AABB with minimal coordinates - left bottom, rt is maximal corner
			// r.org is origin of ray
			Vector2 t13 = (position - a) * ir;
			Vector2 t24 = (end - a) * ir;

			const real_t tmin = MAX(MIN(t13.x, t24.x), MIN(t13.y, t24.y));
			const real_t tmax = MIN(MAX(t13.x, t24.x), MAX(t13.y, t24.y));

			// if tmax < 0, ray (line) is intersecting AABB, but the whole AABB is behind us
			if (tmax < 0 || tmin > tmax || tmin >= l) {
				continue;
			}

			return true;
		}

		if (side_plus * side_minus == 0) {
			return true; // All inside.
		} else {
			return false;
		}
	}

	/**
	 * Sets the opposite corner by updating the size. Preserves the starting corner.
	 *
	 * - `p_end` — New opposite corner in the same coordinate system as the starting corner.
	 */
	_FORCE_INLINE_ void set_end(const Vector2 &p_end) {
		size = p_end - position;
	}

	/**
	 * Returns the opposite corner, computed as position plus size.
	 */
	_FORCE_INLINE_ Vector2 get_end() const {
		return position + size;
	}

	/**
	 * Formats the starting corner and size in the string form used by Godot.
	 */
	explicit operator String() const;
	/**
	 * Converts the position and size components to integers by truncating toward zero.
	 */
	operator Rect2i() const;

	/**
	 * Returns the axis-aligned rectangle enclosing the supplied points. Returns an empty rectangle if there
	 * are no points.
	 *
	 * - `p_points` — Readable, non-null array of points in one coordinate system.
	 * - `p_point_count` — Positive number of points to read. A nonpositive count reports an error and returns an empty rectangle.
	 */
	static Rect2 from_points(const Vector2 *p_points, int p_point_count) {
		Rect2 result;
		ERR_FAIL_NULL_V_MSG(p_points, result, "The pointer of points passed in is invalid.");
		ERR_FAIL_COND_V_MSG(p_point_count <= 0, result, "The number of points passed in is invalid.");
		result.position = p_points[0];
		Vector2 end = result.position;
		for (int i = 1; i < p_point_count; i++) {
			const Vector2 &p = p_points[i];

			if (p.x < result.position.x) {
				result.position.x = p.x;
			} else if (p.x > end.x) {
				end.x = p.x;
			}
			if (p.y < result.position.y) {
				result.position.y = p.y;
			} else if (p.y > end.y) {
				end.y = p.y;
			}
		}
		result.size = end - result.position;
		return result;
	}

	/**
	 * Constructs a `godot::Rect2` with its `position` and `size` set to `godot::Vector2::ZERO`.
	 */
	Rect2() = default;
	/**
	 * Constructs a `godot::Rect2` by setting its `position` to (`x`, `y`), and its `size` to (`width`,
	 * `height`).
	 *
	 * - `p_x` — X coordinate of the starting corner.
	 * - `p_y` — Y coordinate of the starting corner.
	 * - `p_width` — Width measured from the starting corner.
	 * - `p_height` — Height measured from the starting corner.
	 */
	constexpr Rect2(real_t p_x, real_t p_y, real_t p_width, real_t p_height) :
			position(Point2(p_x, p_y)),
			size(Size2(p_width, p_height)) {
	}
	/**
	 * Constructs a `godot::Rect2` by `position` and `size`.
	 *
	 * - `p_pos` — Starting corner in the rectangle's coordinate system.
	 * - `p_size` — Width and height measured from the starting corner.
	 */
	constexpr Rect2(const Point2 &p_pos, const Size2 &p_size) :
			position(p_pos),
			size(p_size) {
	}
};

/**
 * Marks a zero-filled rectangle as valid with zero position and size.
 */
template <>
struct is_zero_constructible<Rect2> : std::true_type {};
} // namespace godot
