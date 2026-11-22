/**************************************************************************/
/*  aabb.hpp                                                              */
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

#include <godot_cpp/variant/plane.hpp>
#include <godot_cpp/variant/vector3.hpp>


namespace godot {

class Variant;

/**
 * A 3D axis-aligned bounding box.
 *
 * **Used for** storing mesh or collision bounds for quick overlap checks before testing detailed geometry.
 */
struct [[nodiscard]] AABB {
	/**
	 * The origin point. This is usually the corner on the bottom-left and forward of the bounding box.
	 *
	 * **Used for** moving bounds to another point while keeping their extents.
	 */
	Vector3 position;
	/**
	 * The signed box extent along X, Y, and Z from its starting corner. Most intersection and containment
	 * tests expect nonnegative extents.
	 *
	 * **Used for** reading or editing the box extents when resizing a region.
	 */
	Vector3 size;

	/**
	 * Returns the bounding box's volume. This is equivalent to `size.x * size.y * size.z`. See also
	 * `godot::AABB::has_volume()`.
	 *
	 * **Used for** comparing the space occupied by two boxes.
	 */
	real_t get_volume() const;
	/**
	 * Returns `true` if this bounding box's width, height, and depth are all positive. See also
	 * `godot::AABB::get_volume()`.
	 *
	 * **Used for** rejecting flat or empty bounds before a volume calculation.
	 */
	_FORCE_INLINE_ bool has_volume() const {
		return size.x > 0.0f && size.y > 0.0f && size.z > 0.0f;
	}

	/**
	 * Returns `true` if this bounding box has a surface or a length, that is, at least one component of
	 * `size` is greater than `0`. Otherwise, returns `false`.
	 *
	 * **Used for** keeping flat or line-shaped bounds that still extend along an axis.
	 */
	_FORCE_INLINE_ bool has_surface() const {
		return size.x > 0.0f || size.y > 0.0f || size.z > 0.0f;
	}

	/**
	 * Returns a read-only reference to the corner from which the box extends by its size.
	 *
	 * **Used for** reading the first corner when placing or drawing box bounds.
	 */
	const Vector3 &get_position() const { return position; }
	/**
	 * Moves the box to the given starting corner and preserves its size.
	 *
	 * **Used for** repositioning box bounds without changing their size.
	 *
	 * - `p_pos` — New starting corner, in the box's coordinate space.
	 */
	void set_position(const Vector3 &p_pos) { position = p_pos; }
	/**
	 * Returns a read-only reference to the box's width, height, and depth.
	 *
	 * **Used for** reading the extents when sizing a debug box display.
	 */
	const Vector3 &get_size() const { return size; }
	/**
	 * Changes the box's width, height, and depth while keeping its starting corner fixed.
	 *
	 * **Used for** resizing a box whose starting corner must remain fixed.
	 *
	 * - `p_size` — New signed extents along the X, Y, and Z axes.
	 */
	void set_size(const Vector3 &p_size) { size = p_size; }

	/**
	 * Tests exact equality of the components.
	 *
	 * **Used for** checking whether the current bounds exactly match a cached copy.
	 *
	 * - `p_rval` — Box whose starting corner and size are compared with this box.
	 */
	constexpr bool operator==(const AABB &p_rval) const {
		return position == p_rval.position && size == p_rval.size;
	}
	/**
	 * Tests whether any component differs.
	 *
	 * **Used for** invalidating a cache when stored bounds change.
	 *
	 * - `p_rval` — Box whose starting corner and size are checked for differences.
	 */
	constexpr bool operator!=(const AABB &p_rval) const {
		return position != p_rval.position || size != p_rval.size;
	}

	/**
	 * Tests whether the starting corners and sizes match within the tolerance of `godot::Vector3::is_equal_approx()`.
	 *
	 * **Used for** deciding whether a small change in computed bounds needs to update a cache.
	 *
	 * - `p_aabb` — Box whose starting corner and size are compared with approximate equality.
	 */
	bool is_equal_approx(const AABB &p_aabb) const;
	/**
	 * Tests exact equality of position and size, treating corresponding NaN components as equal.
	 *
	 * **Used for** comparing imported bounds snapshots that can contain matching NaN components.
	 *
	 * - `p_aabb` — Box whose starting corner and size are compared, including matching NaN components.
	 */
	bool is_same(const AABB &p_aabb) const;
	/**
	 * Returns `true` if this bounding box's values are finite, by calling `godot::Vector3::is_finite()` on
	 * the `position` and the `size`.
	 *
	 * **Used for** rejecting bounds with invalid floating-point coordinates before a spatial query.
	 */
	bool is_finite() const;
	/**
	 * Tests whether the box ranges overlap on all three axes. Contact at a shared boundary alone fails the test.
	 *
	 * **Used for** finding potential overlaps before a detailed collision test that ignores boundary-only contact.
	 *
	 * - `p_aabb` — Other box, in the same coordinate space as this box.
	 */
	_FORCE_INLINE_ bool intersects(const AABB &p_aabb) const;
	/**
	 * Tests whether the box ranges overlap or touch on all three axes.
	 *
	 * **Used for** keeping boxes that touch a query boundary in the candidate set.
	 *
	 * - `p_aabb` — Other box, in the same coordinate space as this box.
	 */
	_FORCE_INLINE_ bool intersects_inclusive(const AABB &p_aabb) const;
	/**
	 * Tests whether the other box fits entirely inside this box. Shared boundaries count as contained.
	 *
	 * **Used for** checking whether a child object's bounds fit entirely in a parent region.
	 *
	 * - `p_aabb` — Other box, in the same coordinate space as this box.
	 */
	_FORCE_INLINE_ bool encloses(const AABB &p_aabb) const;

	/**
	 * Returns the smallest axis-aligned box that contains both boxes.
	 *
	 * **Used for** computing parent bounds from two child regions without updating either region.
	 *
	 * - `p_with` — Other box, in the same coordinate space as this box.
	 */
	AABB merge(const AABB &p_with) const;
	/**
	 * Expands this box in place to the smallest axis-aligned box that contains both boxes.
	 *
	 * **Used for** accumulating the bounds of multiple children in one stored box.
	 *
	 * - `p_aabb` — Other box, in the same coordinate space as this box.
	 */
	void merge_with(const AABB &p_aabb);
	/**
	 * Returns the shared part of the boxes. Touching boxes can produce a box with zero extent on one or more axes. Disjoint boxes return a default `godot::AABB`.
	 *
	 * **Used for** restricting a region to the part shared by two bounds.
	 *
	 * - `p_aabb` — Other box, in the same coordinate space as this box.
	 */
	AABB intersection(const AABB &p_aabb) const;
	/**
	 * Tests whether the line through the ray origin overlaps the box within the given open parameter range. The ray parameter scales the direction vector.
	 *
	 * **Used for** rejecting boxes outside the ray parameter range of a bounded query.
	 *
	 * - `p_from` — Ray origin, in the box's coordinate space.
	 * - `p_dir` — Ray direction, in the box's coordinate space.
	 * - `p_t0` — Lower bound for the ray parameter. An exit at this bound fails the test.
	 * - `p_t1` — Upper bound for the ray parameter. An entry at this bound fails the test.
	 */
	_FORCE_INLINE_ bool smits_intersect_ray(const Vector3 &p_from, const Vector3 &p_dir, real_t p_t0, real_t p_t1) const;

	/**
	 * Tests whether the segment intersects the box, including contact at either endpoint.
	 *
	 * **Used for** finding where a finite movement path first reaches a box.
	 *
	 * - `p_from` — First segment endpoint, in the box's coordinate space.
	 * - `p_to` — Last segment endpoint, in the box's coordinate space.
	 * - `r_intersection_point` — Optional output for the first point in the box. Receives the starting point if the segment starts inside. A miss leaves it unchanged.
	 * - `r_normal` — Optional output for the outward entry normal. Receives zero when the segment starts inside or at the entry face. A miss leaves it unchanged.
	 */
	bool intersects_segment(const Vector3 &p_from, const Vector3 &p_to, Vector3 *r_intersection_point = nullptr, Vector3 *r_normal = nullptr) const;
	/**
	 * Tests whether a ray starting at the given point and extending in the given direction reaches the box.
	 *
	 * **Used for** rejecting boxes outside a picking ray when hit coordinates are unnecessary.
	 *
	 * - `p_from` — Ray origin, in the box's coordinate space.
	 * - `p_dir` — Ray direction, in the box's coordinate space.
	 */
	bool intersects_ray(const Vector3 &p_from, const Vector3 &p_dir) const {
		bool inside;
		return find_intersects_ray(p_from, p_dir, inside);
	}
	/**
	 * Tests whether the forward ray reaches the box. When the ray starts inside, the hit data describes the entry behind the origin.
	 *
	 * **Used for** finding the entry face for picking and distinguishing rays that start inside the box.
	 *
	 * - `p_from` — Ray origin, in the box's coordinate space.
	 * - `p_dir` — Ray direction, in the box's coordinate space.
	 * - `r_inside` — Receives `true` if the ray's computed entry is behind its origin. Receives `false` on a miss.
	 * - `r_intersection_point` — Optional output for the entry point, including the entry behind the origin when the ray starts inside. A miss leaves it unchanged.
	 * - `r_normal` — Optional output for the outward normal of the entry face. A miss leaves it unchanged.
	 */
	bool find_intersects_ray(const Vector3 &p_from, const Vector3 &p_dir, bool &r_inside, Vector3 *r_intersection_point = nullptr, Vector3 *r_normal = nullptr) const;

	/**
	 * Tests for separation along the convex shape's face normals and the box axes. Returns `true` if these tests find no separation.
	 *
	 * **Used for** rejecting boxes outside a convex view or query volume before more detailed tests.
	 *
	 * - `p_planes` — Array of face planes with outward normals, in the box's coordinate space.
	 * - `p_plane_count` — Number of face planes in the array.
	 * - `p_points` — Array of convex shape vertices, in the box's coordinate space.
	 * - `p_point_count` — Number of vertices in the array.
	 */
	_FORCE_INLINE_ bool intersects_convex_shape(const Plane *p_planes, int p_plane_count, const Vector3 *p_points, int p_point_count) const;
	/**
	 * Tests whether the box lies inside every plane of a convex shape. The face planes must point outward.
	 *
	 * **Used for** checking whether a culling volume contains a box completely.
	 *
	 * - `p_planes` — Array of face planes with outward normals, in the box's coordinate space.
	 * - `p_plane_count` — Number of face planes in the array.
	 */
	_FORCE_INLINE_ bool inside_convex_shape(const Plane *p_planes, int p_plane_count) const;
	/**
	 * Returns `true` when at least one corner is on the positive side of the plane and at least one is on the plane or on its negative side.
	 *
	 * **Used for** finding boxes that may need to be split by a clipping plane.
	 *
	 * - `p_plane` — Plane to test against the box corners, in the box's coordinate space.
	 */
	bool intersects_plane(const Plane &p_plane) const;

	/**
	 * Tests whether the point lies in the box. Includes points on all six faces.
	 *
	 * **Used for** checking whether a sampled position lies inside a spatial cell.
	 *
	 * - `p_point` — Point to test, in the box's coordinate space.
	 */
	_FORCE_INLINE_ bool has_point(const Vector3 &p_point) const;
	/**
	 * Returns the vertex's position of this bounding box that's the farthest in the given direction. This
	 * point is commonly known as the support point in collision detection algorithms.
	 *
	 * **Used for** finding the box corner farthest along a collision test axis.
	 *
	 * - `p_direction` — Direction in the box's coordinate space. A zero component selects the starting coordinate on that axis.
	 */
	_FORCE_INLINE_ Vector3 get_support(const Vector3 &p_direction) const;

	/**
	 * Returns the longest normalized axis of this bounding box's `size`, as a `godot::Vector3`
	 * (`godot::Vector3::RIGHT`, `godot::Vector3::UP`, or `godot::Vector3::BACK`).
	 *
	 * **Used for** choosing the direction along which to split a bounding region.
	 */
	Vector3 get_longest_axis() const;
	/**
	 * Returns the index to the longest axis of this bounding box's `size` (see `godot::Vector3::AXIS_X`,
	 * `godot::Vector3::AXIS_Y`, and `godot::Vector3::AXIS_Z`). For an example, see
	 * `godot::AABB::get_longest_axis()`.
	 *
	 * **Used for** selecting the vector component along which to split a bounding region.
	 */
	int get_longest_axis_index() const;
	/**
	 * Returns the longest dimension of this bounding box's `size`. For an example, see
	 * `godot::AABB::get_longest_axis()`.
	 *
	 * **Used for** checking whether the largest extent exceeds a size limit.
	 */
	_FORCE_INLINE_ real_t get_longest_axis_size() const;

	/**
	 * Returns the shortest normalized axis of this bounding box's `size`, as a `godot::Vector3`
	 * (`godot::Vector3::RIGHT`, `godot::Vector3::UP`, or `godot::Vector3::BACK`).
	 *
	 * **Used for** choosing the direction across the thinnest part of a bounding region.
	 */
	Vector3 get_shortest_axis() const;
	/**
	 * Returns the index to the shortest axis of this bounding box's `size` (see `godot::Vector3::AXIS_X`,
	 * `godot::Vector3::AXIS_Y`, and `godot::Vector3::AXIS_Z`). For an example, see
	 * `godot::AABB::get_shortest_axis()`.
	 *
	 * **Used for** selecting the vector component for a thickness check.
	 */
	int get_shortest_axis_index() const;
	/**
	 * Returns the shortest dimension of this bounding box's `size`. For an example, see
	 * `godot::AABB::get_shortest_axis()`.
	 *
	 * **Used for** comparing the box's smallest extent with a minimum thickness.
	 */
	_FORCE_INLINE_ real_t get_shortest_axis_size() const;

	/**
	 * Returns a copy with each face moved outward by the given distance. A negative distance moves the faces inward.
	 *
	 * **Used for** checking nearby objects within a margin of the current bounds.
	 *
	 * - `p_by` — Distance to move each face, in the box's coordinate units. A negative distance moves it inward.
	 */
	AABB grow(real_t p_by) const;
	/**
	 * Moves each face outward by the given distance. A negative distance moves each face inward.
	 *
	 * **Used for** adding padding to a culling volume whose stored bounds need to change.
	 *
	 * - `p_amount` — Distance to move each face, in the box's coordinate units. A negative distance moves it inward.
	 */
	_FORCE_INLINE_ void grow_by(real_t p_amount);

	/**
	 * Writes the two endpoints of one of the box's twelve edges in the box's coordinate system.
	 *
	 * **Used for** drawing the line segments of a wireframe bounding box.
	 *
	 * - `p_edge` — Edge index from `0` to `11`.
	 * - `r_from` — Receives the first endpoint. An invalid index leaves it unchanged.
	 * - `r_to` — Receives the second endpoint. An invalid index leaves it unchanged.
	 */
	void get_edge(int p_edge, Vector3 &r_from, Vector3 &r_to) const;
	/**
	 * Returns a box vertex in the box's coordinate space.
	 *
	 * **Used for** transforming individual box corners into another coordinate space before rebuilding bounds.
	 *
	 * - `p_point` — Vertex index from `0` to `7`. Index `0` selects `position` and `7` selects the opposite corner. An invalid index returns a zero vector.
	 */
	_FORCE_INLINE_ Vector3 get_endpoint(int p_point) const;

	/**
	 * Returns the smallest axis-aligned box that contains this box and the given point.
	 *
	 * **Used for** testing how much a bounding box would grow if it included a new point.
	 *
	 * - `p_vector` — Point to include, in the box's coordinate space.
	 */
	AABB expand(const Vector3 &p_vector) const;
	/**
	 * Writes the range of signed plane equation values over the box. With a unit normal these are signed distances.
	 *
	 * **Used for** determining whether the box projects entirely to one side of a clipping plane.
	 *
	 * - `p_plane` — Plane in the box's coordinate space. Use a unit normal to get signed distances in coordinate units.
	 * - `r_min` — Receives the smallest signed plane equation value over the box corners.
	 * - `r_max` — Receives the largest signed plane equation value over the box corners.
	 */
	_FORCE_INLINE_ void project_range_in_plane(const Plane &p_plane, real_t &r_min, real_t &r_max) const;
	/**
	 * Expands the box bounds in place just enough to include the point.
	 *
	 * **Used for** updating bounds incrementally as a mesh importer reads each vertex.
	 *
	 * - `p_vector` — Point to include, in the box's coordinate space.
	 */
	_FORCE_INLINE_ void expand_to(const Vector3 &p_vector);

	/**
	 * Returns the same bounds with nonnegative extents. Moves the starting corner along each axis with a negative extent.
	 *
	 * **Used for** preparing bounds built from reversed corners for intersection tests.
	 */
	_FORCE_INLINE_ AABB abs() const {
		return AABB(position + size.minf(0), size.abs());
	}

	/**
	 * Returns the first point of the segment inside the box as a `godot::Variant`, or `godot::Variant::NIL` if the segment misses.
	 *
	 * **Used for** passing a segment hit through a Variant API that uses `godot::Variant::NIL` for a miss.
	 *
	 * - `p_from` — First segment endpoint, in the box's coordinate space.
	 * - `p_to` — Last segment endpoint, in the box's coordinate space.
	 */
	Variant intersects_segment_bind(const Vector3 &p_from, const Vector3 &p_to) const;
	/**
	 * Returns the ray intersection point as a `godot::Variant`, or a nil variant if the ray misses the box.
	 * Returns the ray start when it lies inside the box.
	 *
	 * **Used for** passing a ray hit through a Variant API that uses `godot::Variant::NIL` for a miss.
	 *
	 * - `p_from` — Ray origin, in the box's coordinate space.
	 * - `p_dir` — Ray direction, in the box's coordinate space.
	 */
	Variant intersects_ray_bind(const Vector3 &p_from, const Vector3 &p_dir) const;

	/**
	 * Moves the starting corner down to grid boundaries and the opposite corner up to the next grid boundaries. An opposite coordinate already on a boundary moves up by one cell.
	 *
	 * **Used for** updating stored bounds to cover whole cells of a spatial grid.
	 *
	 * - `p_unit` — Positive grid cell size on all three axes, in the box's coordinate units.
	 */
	_FORCE_INLINE_ void quantize(real_t p_unit);
	/**
	 * Returns a copy whose bounds follow the grid. An opposite coordinate already on a grid boundary moves up by one cell.
	 *
	 * **Used for** computing grid-aligned coverage while keeping the original bounds for exact tests.
	 *
	 * - `p_unit` — Positive grid cell size on all three axes, in the box's coordinate units.
	 */
	_FORCE_INLINE_ AABB quantized(real_t p_unit) const;

	/**
	 * Sets the opposite corner by updating the size. Preserves the starting corner.
	 *
	 * **Used for** resizing bounds from a dragged opposite corner while keeping the first corner fixed.
	 *
	 * - `p_end` — New opposite corner, in the box's coordinate space.
	 */
	_FORCE_INLINE_ void set_end(const Vector3 &p_end) {
		size = p_end - position;
	}

	/**
	 * Returns the opposite corner, computed as position plus size.
	 *
	 * **Used for** reading the opposite corner when exporting the box as two corners.
	 */
	_FORCE_INLINE_ Vector3 get_end() const {
		return position + size;
	}

	/**
	 * Returns the center point of the bounding box. This is the same as `position + (size / 2.0)`.
	 *
	 * **Used for** placing a debug marker at the midpoint of a bounding region.
	 */
	_FORCE_INLINE_ Vector3 get_center() const {
		return position + (size * 0.5f);
	}

	/**
	 * Formats the starting corner and size as a `godot::String`.
	 *
	 * **Used for** including box coordinates and extents in a diagnostic message.
	 */
	explicit operator String() const;

	/**
	 * Constructs an `godot::AABB` with its `position` and `size` set to `godot::Vector3::ZERO`.
	 *
	 * **Used for** using an empty box as the initial state before filling in bounds.
	 */
	AABB() = default;
	/**
	 * Creates a box from the starting corner and signed extents. The constructor stores both vectors as supplied.
	 *
	 * **Used for** creating bounds from a corner and size computed by a mesh or collision tool.
	 *
	 * - `p_pos` — Starting corner, in the box's coordinate space.
	 * - `p_size` — Signed extents along the X, Y, and Z axes.
	 */
	constexpr AABB(const Vector3 &p_pos, const Vector3 &p_size) :
			position(p_pos),
			size(p_size) {
	}
};

inline bool AABB::intersects(const AABB &p_aabb) const {
#ifdef MATH_CHECKS
	if (unlikely(size.x < 0 || size.y < 0 || size.z < 0 || p_aabb.size.x < 0 || p_aabb.size.y < 0 || p_aabb.size.z < 0)) {
		ERR_PRINT("AABB size is negative, this is not supported. Use AABB.abs() to get an AABB with a positive size.");
	}
#endif
	if (position.x >= (p_aabb.position.x + p_aabb.size.x)) {
		return false;
	}
	if ((position.x + size.x) <= p_aabb.position.x) {
		return false;
	}
	if (position.y >= (p_aabb.position.y + p_aabb.size.y)) {
		return false;
	}
	if ((position.y + size.y) <= p_aabb.position.y) {
		return false;
	}
	if (position.z >= (p_aabb.position.z + p_aabb.size.z)) {
		return false;
	}
	if ((position.z + size.z) <= p_aabb.position.z) {
		return false;
	}

	return true;
}

inline bool AABB::intersects_inclusive(const AABB &p_aabb) const {
#ifdef MATH_CHECKS
	if (unlikely(size.x < 0 || size.y < 0 || size.z < 0 || p_aabb.size.x < 0 || p_aabb.size.y < 0 || p_aabb.size.z < 0)) {
		ERR_PRINT("AABB size is negative, this is not supported. Use AABB.abs() to get an AABB with a positive size.");
	}
#endif
	if (position.x > (p_aabb.position.x + p_aabb.size.x)) {
		return false;
	}
	if ((position.x + size.x) < p_aabb.position.x) {
		return false;
	}
	if (position.y > (p_aabb.position.y + p_aabb.size.y)) {
		return false;
	}
	if ((position.y + size.y) < p_aabb.position.y) {
		return false;
	}
	if (position.z > (p_aabb.position.z + p_aabb.size.z)) {
		return false;
	}
	if ((position.z + size.z) < p_aabb.position.z) {
		return false;
	}

	return true;
}

inline bool AABB::encloses(const AABB &p_aabb) const {
#ifdef MATH_CHECKS
	if (unlikely(size.x < 0 || size.y < 0 || size.z < 0 || p_aabb.size.x < 0 || p_aabb.size.y < 0 || p_aabb.size.z < 0)) {
		ERR_PRINT("AABB size is negative, this is not supported. Use AABB.abs() to get an AABB with a positive size.");
	}
#endif
	Vector3 src_min = position;
	Vector3 src_max = position + size;
	Vector3 dst_min = p_aabb.position;
	Vector3 dst_max = p_aabb.position + p_aabb.size;

	return (
			(src_min.x <= dst_min.x) &&
			(src_max.x >= dst_max.x) &&
			(src_min.y <= dst_min.y) &&
			(src_max.y >= dst_max.y) &&
			(src_min.z <= dst_min.z) &&
			(src_max.z >= dst_max.z));
}

Vector3 AABB::get_support(const Vector3 &p_direction) const {
	Vector3 support = position;
	if (p_direction.x > 0.0f) {
		support.x += size.x;
	}
	if (p_direction.y > 0.0f) {
		support.y += size.y;
	}
	if (p_direction.z > 0.0f) {
		support.z += size.z;
	}
	return support;
}

Vector3 AABB::get_endpoint(int p_point) const {
	switch (p_point) {
		case 0:
			return Vector3(position.x, position.y, position.z);
		case 1:
			return Vector3(position.x, position.y, position.z + size.z);
		case 2:
			return Vector3(position.x, position.y + size.y, position.z);
		case 3:
			return Vector3(position.x, position.y + size.y, position.z + size.z);
		case 4:
			return Vector3(position.x + size.x, position.y, position.z);
		case 5:
			return Vector3(position.x + size.x, position.y, position.z + size.z);
		case 6:
			return Vector3(position.x + size.x, position.y + size.y, position.z);
		case 7:
			return Vector3(position.x + size.x, position.y + size.y, position.z + size.z);
	}

	ERR_FAIL_V(Vector3());
}

bool AABB::intersects_convex_shape(const Plane *p_planes, int p_plane_count, const Vector3 *p_points, int p_point_count) const {
	Vector3 half_extents = size * 0.5f;
	Vector3 ofs = position + half_extents;

	for (int i = 0; i < p_plane_count; i++) {
		const Plane &p = p_planes[i];
		Vector3 point(
				(p.normal.x > 0) ? -half_extents.x : half_extents.x,
				(p.normal.y > 0) ? -half_extents.y : half_extents.y,
				(p.normal.z > 0) ? -half_extents.z : half_extents.z);
		point += ofs;
		if (p.is_point_over(point)) {
			return false;
		}
	}

	// Make sure all points in the shape aren't fully separated from the AABB on
	// each axis.
	int bad_point_counts_positive[3] = { 0 };
	int bad_point_counts_negative[3] = { 0 };

	for (int k = 0; k < 3; k++) {
		for (int i = 0; i < p_point_count; i++) {
			if (p_points[i][k] > ofs[k] + half_extents[k]) {
				bad_point_counts_positive[k]++;
			}
			if (p_points[i][k] < ofs[k] - half_extents[k]) {
				bad_point_counts_negative[k]++;
			}
		}

		if (bad_point_counts_negative[k] == p_point_count) {
			return false;
		}
		if (bad_point_counts_positive[k] == p_point_count) {
			return false;
		}
	}

	return true;
}

bool AABB::inside_convex_shape(const Plane *p_planes, int p_plane_count) const {
	Vector3 half_extents = size * 0.5f;
	Vector3 ofs = position + half_extents;

	for (int i = 0; i < p_plane_count; i++) {
		const Plane &p = p_planes[i];
		Vector3 point(
				(p.normal.x < 0) ? -half_extents.x : half_extents.x,
				(p.normal.y < 0) ? -half_extents.y : half_extents.y,
				(p.normal.z < 0) ? -half_extents.z : half_extents.z);
		point += ofs;
		if (p.is_point_over(point)) {
			return false;
		}
	}

	return true;
}

bool AABB::has_point(const Vector3 &p_point) const {
#ifdef MATH_CHECKS
	if (unlikely(size.x < 0 || size.y < 0 || size.z < 0)) {
		ERR_PRINT("AABB size is negative, this is not supported. Use AABB.abs() to get an AABB with a positive size.");
	}
#endif
	if (p_point.x < position.x) {
		return false;
	}
	if (p_point.y < position.y) {
		return false;
	}
	if (p_point.z < position.z) {
		return false;
	}
	if (p_point.x > position.x + size.x) {
		return false;
	}
	if (p_point.y > position.y + size.y) {
		return false;
	}
	if (p_point.z > position.z + size.z) {
		return false;
	}

	return true;
}

inline void AABB::expand_to(const Vector3 &p_vector) {
#ifdef MATH_CHECKS
	if (unlikely(size.x < 0 || size.y < 0 || size.z < 0)) {
		ERR_PRINT("AABB size is negative, this is not supported. Use AABB.abs() to get an AABB with a positive size.");
	}
#endif
	Vector3 begin = position;
	Vector3 end = position + size;

	if (p_vector.x < begin.x) {
		begin.x = p_vector.x;
	}
	if (p_vector.y < begin.y) {
		begin.y = p_vector.y;
	}
	if (p_vector.z < begin.z) {
		begin.z = p_vector.z;
	}

	if (p_vector.x > end.x) {
		end.x = p_vector.x;
	}
	if (p_vector.y > end.y) {
		end.y = p_vector.y;
	}
	if (p_vector.z > end.z) {
		end.z = p_vector.z;
	}

	position = begin;
	size = end - begin;
}

void AABB::project_range_in_plane(const Plane &p_plane, real_t &r_min, real_t &r_max) const {
	Vector3 half_extents(size.x * 0.5f, size.y * 0.5f, size.z * 0.5f);
	Vector3 center(position.x + half_extents.x, position.y + half_extents.y, position.z + half_extents.z);

	real_t length = p_plane.normal.abs().dot(half_extents);
	real_t distance = p_plane.distance_to(center);
	r_min = distance - length;
	r_max = distance + length;
}

inline real_t AABB::get_longest_axis_size() const {
	real_t max_size = size.x;

	if (size.y > max_size) {
		max_size = size.y;
	}

	if (size.z > max_size) {
		max_size = size.z;
	}

	return max_size;
}

inline real_t AABB::get_shortest_axis_size() const {
	real_t max_size = size.x;

	if (size.y < max_size) {
		max_size = size.y;
	}

	if (size.z < max_size) {
		max_size = size.z;
	}

	return max_size;
}

bool AABB::smits_intersect_ray(const Vector3 &p_from, const Vector3 &p_dir, real_t p_t0, real_t p_t1) const {
#ifdef MATH_CHECKS
	if (unlikely(size.x < 0 || size.y < 0 || size.z < 0)) {
		ERR_PRINT("AABB size is negative, this is not supported. Use AABB.abs() to get an AABB with a positive size.");
	}
#endif
	real_t divx = 1.0f / p_dir.x;
	real_t divy = 1.0f / p_dir.y;
	real_t divz = 1.0f / p_dir.z;

	Vector3 upbound = position + size;
	real_t tmin, tmax, tymin, tymax, tzmin, tzmax;
	if (p_dir.x >= 0) {
		tmin = (position.x - p_from.x) * divx;
		tmax = (upbound.x - p_from.x) * divx;
	} else {
		tmin = (upbound.x - p_from.x) * divx;
		tmax = (position.x - p_from.x) * divx;
	}
	if (p_dir.y >= 0) {
		tymin = (position.y - p_from.y) * divy;
		tymax = (upbound.y - p_from.y) * divy;
	} else {
		tymin = (upbound.y - p_from.y) * divy;
		tymax = (position.y - p_from.y) * divy;
	}
	if ((tmin > tymax) || (tymin > tmax)) {
		return false;
	}
	if (tymin > tmin) {
		tmin = tymin;
	}
	if (tymax < tmax) {
		tmax = tymax;
	}
	if (p_dir.z >= 0) {
		tzmin = (position.z - p_from.z) * divz;
		tzmax = (upbound.z - p_from.z) * divz;
	} else {
		tzmin = (upbound.z - p_from.z) * divz;
		tzmax = (position.z - p_from.z) * divz;
	}
	if ((tmin > tzmax) || (tzmin > tmax)) {
		return false;
	}
	if (tzmin > tmin) {
		tmin = tzmin;
	}
	if (tzmax < tmax) {
		tmax = tzmax;
	}
	return ((tmin < p_t1) && (tmax > p_t0));
}

void AABB::grow_by(real_t p_amount) {
	position.x -= p_amount;
	position.y -= p_amount;
	position.z -= p_amount;
	size.x += 2.0f * p_amount;
	size.y += 2.0f * p_amount;
	size.z += 2.0f * p_amount;
}

void AABB::quantize(real_t p_unit) {
	size += position;

	position.x -= Math::fposmodp(position.x, p_unit);
	position.y -= Math::fposmodp(position.y, p_unit);
	position.z -= Math::fposmodp(position.z, p_unit);

	size.x -= Math::fposmodp(size.x, p_unit);
	size.y -= Math::fposmodp(size.y, p_unit);
	size.z -= Math::fposmodp(size.z, p_unit);

	size.x += p_unit;
	size.y += p_unit;
	size.z += p_unit;

	size -= position;
}

AABB AABB::quantized(real_t p_unit) const {
	AABB ret = *this;
	ret.quantize(p_unit);
	return ret;
}

/**
 * Marks zero-filled storage as a valid default AABB.
 *
 * **Used for** sizing arrays whose new AABB elements can start as empty boxes.
 */
template <>
struct is_zero_constructible<AABB> : std::true_type {};
} // namespace godot
