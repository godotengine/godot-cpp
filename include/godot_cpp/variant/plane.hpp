/**************************************************************************/
/*  plane.hpp                                                             */
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
#include <godot_cpp/variant/vector3.hpp>

namespace godot {

class Variant;

/**
 * A plane in 3D described by `normal.dot(point) = d`. The normal also defines the positive side. Distance and projection methods use a unit normal for geometric results.
 *
 * **Used for** representing a clipping plane or construction surface for point and ray tests.
 *
 * ```cpp
 * Plane floor(Vector3(0, 1, 0), 2); // Platform surface in world coordinates.
 * Vector3 player_feet(4, 2.3, 3);
 * real_t ground_clearance = floor.distance_to(player_feet);
 * ```
 */
struct [[nodiscard]] Plane {
	/**
	 * The coordinate plane at X = 0 with a normal along positive X.
	 *
	 * **Used for** constraining movement to the YZ plane through the origin.
	 *
	 * ```cpp
	 * Vector3 drag_delta(4, 2, -3); // World-space drag.
	 * Vector3 locked_to_yz = Plane::PLANE_YZ.project(drag_delta); // Discard X motion.
	 * ```
	 */
	static const Plane PLANE_YZ;
	/**
	 * The coordinate plane at Y = 0 with a normal along positive Y.
	 *
	 * **Used for** finding a horizontal heading by removing its vertical component.
	 *
	 * ```cpp
	 * Vector3 camera_forward(0.5, -0.5, -0.5);
	 * Vector3 ground_heading = Plane::PLANE_XZ.project(camera_forward).normalized();
	 * ```
	 */
	static const Plane PLANE_XZ;
	/**
	 * The coordinate plane at Z = 0 with a normal along positive Z.
	 *
	 * **Used for** testing which side of the XY plane a point lies on.
	 *
	 * ```cpp
	 * Vector3 mesh_vertex(10, 20, -3);
	 * bool behind_canvas = Plane::PLANE_XY.distance_to(mesh_vertex) < 0;
	 * ```
	 */
	static const Plane PLANE_XY;

	/**
	 * The vector perpendicular to the plane, which points toward its positive side. Its magnitude scales the plane equation.
	 *
	 * **Used for** offsetting a point away from a plane along its normal.
	 *
	 * ```cpp
	 * Plane ground(Vector3(0, 1, 0), 2);
	 * Vector3 probe_start = ground.get_center() + ground.normal * real_t(0.1);
	 * ```
	 */
	Vector3 normal;
	/**
	 * The constant on the right side of the plane equation. For a unit normal it is the signed offset from the origin along that normal.
	 *
	 * **Used for** moving a plane along its unit normal while keeping its orientation.
	 *
	 * ```cpp
	 * Plane waterline = Plane::PLANE_XZ;
	 * const real_t lake_elevation = 2;
	 * waterline.d = lake_elevation; // Horizontal water surface at Y = 2.
	 * ```
	 */
	real_t d = 0;

	/**
	 * Replaces the normal and keeps the equation constant `d`. This can change both the plane's orientation and its distance from the origin.
	 *
	 * **Used for** reorienting a plane through the origin while keeping its equation constant.
	 *
	 * - `p_normal` — New vector perpendicular to the plane. The setter stores it as supplied and keeps `d`.
	 *
	 * ```cpp
	 * Plane grid = Plane::PLANE_XZ; // Ground grid passes through the world origin.
	 * const Vector3 front_view_normal(0, 0, 1);
	 * grid.set_normal(front_view_normal); // Switch to the front-view grid.
	 * ```
	 */
	void set_normal(const Vector3 &p_normal);
	/**
	 * Returns a copy of the stored normal, in the same coordinate space as the plane.
	 *
	 * **Used for** finding a direction in which to offset geometry away from the plane.
	 *
	 * ```cpp
	 * Plane wall(Vector3(0, 0, 1), 2);
	 * Vector3 decal_center(4, 1, 2);
	 * Vector3 decal_position = decal_center + wall.get_normal() * real_t(0.001);
	 * ```
	 */
	_FORCE_INLINE_ Vector3 get_normal() const { return normal; }

	/**
	 * Sets all normal components and the equation constant to zero, producing a degenerate plane.
	 *
	 * **Used for** resetting a stored plane when a clipping constraint is cleared.
	 *
	 * ```cpp
	 * Plane active_clip = Plane::PLANE_YZ; // Previously active clipping plane.
	 * active_clip.zero();
	 * bool clip_enabled = active_clip.normal != Vector3();
	 * ```
	 */
	void zero() {
		normal.zero();
		d = 0;
	}

	/**
	 * Divides the normal and `d` by the normal's length so they describe the same plane with a unit normal. A zero-length normal clears the plane.
	 *
	 * **Used for** preparing stored coefficients for signed distance tests in coordinate units.
	 *
	 * ```cpp
	 * Plane clip(0, 2, 0, 4); // Raw clipping coefficients received from a tool.
	 * clip.normalize();
	 * real_t clearance = clip.distance_to(Vector3(0, 3, 0)); // 1 world unit.
	 * ```
	 */
	void normalize();
	/**
	 * Returns a normalized copy. A zero-length normal yields a plane with all coefficients zero.
	 *
	 * **Used for** getting a unit-normal plane for projections while keeping the original coefficients.
	 *
	 * ```cpp
	 * const Plane imported(0, 2, 0, 4);
	 * Plane collision_plane = imported.normalized();
	 * Vector3 foot = collision_plane.project(Vector3(3, 5, 1));
	 * ```
	 */
	Plane normalized() const;

	/* Plane-Point operations */

	/**
	 * Returns `normal * d`. With a unit normal this is the point on the plane nearest the coordinate origin.
	 *
	 * **Used for** finding where to anchor a plane grid nearest the origin.
	 *
	 * ```cpp
	 * Plane work_surface(Vector3(0, 1, 0), 2);
	 * Vector3 grid_origin = work_surface.get_center(); // Anchor the grid nearest the world origin.
	 * ```
	 */
	_FORCE_INLINE_ Vector3 get_center() const { return normal * d; }
	/**
	 * Returns a unit vector perpendicular to the plane's unit normal, by projecting a coordinate axis into the plane and normalizing the result.
	 *
	 * **Used for** building one of the tangent axes for a plane grid.
	 *
	 * ```cpp
	 * Plane work_surface(Vector3(0, 1, 0), 2);
	 * Vector3 tangent = work_surface.get_any_perpendicular_normal();
	 * Vector3 bitangent = work_surface.normal.cross(tangent); // Second axis for a plane grid.
	 * ```
	 */
	Vector3 get_any_perpendicular_normal() const;

	/**
	 * Tests whether the point is strictly on the positive side of the plane in the same coordinate space.
	 *
	 * **Used for** checking whether a point belongs to the positive half-space of a clipping plane.
	 *
	 * - `p_point` — Point to test, in the plane's coordinate space.
	 *
	 * ```cpp
	 * Plane waterline(Vector3(0, 1, 0), 2);
	 * Vector3 player_head(3, 1.8, 4);
	 * bool head_submerged = !waterline.is_point_over(player_head);
	 * ```
	 */
	_FORCE_INLINE_ bool is_point_over(const Vector3 &p_point) const;
	/**
	 * Returns `normal.dot(p_point) - d`. For a unit normal this is the signed perpendicular distance in coordinate units.
	 *
	 * **Used for** checking clearance from a surface when the plane normal has unit length.
	 *
	 * - `p_point` — Point from which to measure, in the plane's coordinate space.
	 *
	 * ```cpp
	 * Plane barrier(Vector3(1, 0, 0), 4);
	 * Vector3 sphere_center(4.3, 1, 0);
	 * const real_t sphere_radius = 0.5;
	 * bool touches = Math::abs(barrier.distance_to(sphere_center)) <= sphere_radius;
	 * ```
	 */
	_FORCE_INLINE_ real_t distance_to(const Vector3 &p_point) const;
	/**
	 * Tests whether the absolute plane equation residual at the point is within the tolerance.
	 *
	 * **Used for** checking whether an imported vertex lies on the plane within a chosen tolerance.
	 *
	 * - `p_tolerance` — Maximum absolute residual. With a unit normal, it is a distance in coordinate units.
	 *
	 * - `p_point` — Point to test, in the plane's coordinate space.
	 *
	 * ```cpp
	 * Plane floor(Vector3(0, 1, 0), 2);
	 * Vector3 candidate_vertex(1, 2.005, 4);
	 * const real_t weld_tolerance = 0.01;
	 * bool belongs_to_floor = floor.has_point(candidate_vertex, weld_tolerance);
	 * ```
	 */
	_FORCE_INLINE_ bool has_point(const Vector3 &p_point, real_t p_tolerance = CMP_EPSILON) const;

	/* intersections */

	/**
	 * Returns `true` when this plane and the two given planes meet at one point. Returns `false` when the scalar triple product of the three normals is approximately zero.
	 *
	 * **Used for** finding a corner where three clipping planes meet.
	 *
	 * - `p_plane1` — Second plane in the test, in the same coordinate space as this plane.
	 * - `p_plane2` — Third plane in the test, in the same coordinate space as this plane.
	 * - `r_result` — Optional output for the shared point. A failed test leaves it unchanged.
	 *
	 * ```cpp
	 * Plane right(Vector3(1, 0, 0), 4), top(Vector3(0, 1, 0), 2), back(Vector3(0, 0, 1), 6);
	 * Vector3 box_corner;
	 * if (!right.intersect_3(top, back, &box_corner)) { return; } // Skip a degenerate brush.
	 * ```
	 */
	bool intersect_3(const Plane &p_plane1, const Plane &p_plane2, Vector3 *r_result = nullptr) const;
	/**
	 * Tests whether the ray hits the plane. A parallel ray fails the test. The test allows a small tolerance at the origin.
	 *
	 * **Used for** placing an editor preview where a viewport ray hits the construction plane.
	 *
	 * - `p_from` — Ray origin, in the plane's coordinate space.
	 * - `p_dir` — Ray direction, in the plane's coordinate space.
	 * - `p_intersection` — Writable pointer that receives the hit point in the plane's coordinate space. A failed test leaves it unchanged.
	 *
	 * ```cpp
	 * // In a 3D editor tool, the viewport camera supplies ray_origin and ray_direction.
	 * // Both are world-space Vector3 values. preview points to the Node3D being placed.
	 * Plane construction_surface(Vector3(0, 1, 0), 0);
	 * Vector3 placement;
	 * if (construction_surface.intersects_ray(ray_origin, ray_direction, &placement)) {
	 *     preview->set_global_position(placement);
	 * }
	 * ```
	 */
	bool intersects_ray(const Vector3 &p_from, const Vector3 &p_dir, Vector3 *p_intersection) const;
	/**
	 * Tests whether the segment hits the plane. A parallel segment fails the test. The test allows a small tolerance at both endpoints.
	 *
	 * **Used for** finding where an object's movement crosses a plane between two recorded positions.
	 *
	 * - `p_begin` — First segment endpoint, in the plane's coordinate space.
	 * - `p_end` — Last segment endpoint, in the plane's coordinate space.
	 * - `p_intersection` — Writable pointer that receives the hit point in the plane's coordinate space. A failed test leaves it unchanged.
	 *
	 * ```cpp
	 * Plane waterline(Vector3(0, 1, 0), 2);
	 * Vector3 previous_position(1, 2.4, 3), current_position(1.3, 1.9, 3);
	 * Vector3 splash_position;
	 * bool spawn_splash = waterline.intersects_segment(previous_position, current_position, &splash_position);
	 * ```
	 */
	bool intersects_segment(const Vector3 &p_begin, const Vector3 &p_end, Vector3 *p_intersection) const;

	/**
	 * Returns the point where the three planes meet as a `godot::Variant`. Returns `godot::Variant::NIL` when the planes have no unique intersection within the test tolerance.
	 *
	 * **Used for** passing a three-plane corner to a Variant caller that represents a failed test with `godot::Variant::NIL`.
	 *
	 * - `p_plane1` — Second plane in the test, in the same coordinate space as this plane.
	 * - `p_plane2` — Third plane in the test, in the same coordinate space as this plane.
	 *
	 * ```cpp
	 * Plane left(Vector3(1, 0, 0), 0), right(Vector3(1, 0, 0), 4), floor(Vector3(0, 1, 0), 0);
	 * Variant corner = left.intersect_3_bind(right, floor);
	 * if (corner.get_type() == Variant::NIL) { return; } // Parallel walls yield no corner.
	 * ```
	 */
	Variant intersect_3_bind(const Plane &p_plane1, const Plane &p_plane2) const;
	/**
	 * Returns the ray hit point as a `godot::Variant`. Returns `godot::Variant::NIL` if the ray fails the plane intersection test.
	 *
	 * **Used for** passing a ray hit to a Variant caller that represents a miss with `godot::Variant::NIL`.
	 *
	 * - `p_from` — Ray origin, in the plane's coordinate space.
	 * - `p_dir` — Ray direction, in the plane's coordinate space.
	 *
	 * ```cpp
	 * Plane floor(Vector3(0, 1, 0), 0);
	 * Vector3 probe_at(2, 3, 4);
	 * Variant hit = floor.intersects_ray_bind(probe_at, Vector3(0, -1, 0));
	 * if (hit.get_type() == Variant::NIL) { return; } // No target for the ground probe.
	 * ```
	 */
	Variant intersects_ray_bind(const Vector3 &p_from, const Vector3 &p_dir) const;
	/**
	 * Returns the segment hit point as a `godot::Variant`. Returns `godot::Variant::NIL` if the segment fails the plane intersection test.
	 *
	 * **Used for** passing a segment hit to a Variant caller that represents a miss with `godot::Variant::NIL`.
	 *
	 * - `p_begin` — First segment endpoint, in the plane's coordinate space.
	 * - `p_end` — Last segment endpoint, in the plane's coordinate space.
	 *
	 * ```cpp
	 * Plane gate(Vector3(1, 0, 0), 4);
	 * Vector3 previous(3, 1, 2), current(5, 1, 2);
	 * Variant hit = gate.intersects_segment_bind(previous, current);
	 * bool crossed_gate = hit.get_type() == Variant::VECTOR3;
	 * ```
	 */
	Variant intersects_segment_bind(const Vector3 &p_begin, const Vector3 &p_end) const;

	/**
	 * Returns the perpendicular projection of the point onto the plane when the normal has unit length. The input and result use the plane's coordinate space.
	 *
	 * **Used for** placing a point on a construction surface along the surface normal.
	 *
	 * - `p_point` — Point to project, in the plane's coordinate space.
	 *
	 * ```cpp
	 * Plane platform(Vector3(0, 1, 0), 2);
	 * Vector3 world_cursor(2, 2.1, 4);
	 * Vector3 tile_preview_position = platform.project(world_cursor);
	 * ```
	 */
	_FORCE_INLINE_ Vector3 project(const Vector3 &p_point) const {
		return p_point - normal * distance_to(p_point);
	}

	/* misc */

	/**
	 * Negates `normal` and `d` together. This retains the same plane and reverses its positive side.
	 *
	 * **Used for** switching which side of a clipping plane is kept.
	 *
	 * ```cpp
	 * Plane clip(Vector3(1, 0, 0), 3);
	 * Plane opposite = -clip;
	 * bool keep_on_left = opposite.is_point_over(Vector3(2, 1, 0));
	 * ```
	 */
	constexpr Plane operator-() const { return Plane(-normal, -d); }
	/**
	 * Compares the stored normal components and `d` with approximate equality. Sign-reversed coefficients are compared as supplied.
	 *
	 * **Used for** checking whether small rounding changes require rebuilding clipping data.
	 *
	 * - `p_plane` — Plane whose normal and `d` are compared with this plane's coefficients.
	 *
	 * ```cpp
	 * Plane cached(Vector3(0, 1, 0), 2);
	 * Plane rebuilt(Vector3(0, 1, 0), 2.000001); // Small rounding change after import.
	 * bool reuse_clipping_state = cached.is_equal_approx(rebuilt);
	 * ```
	 */
	bool is_equal_approx(const Plane &p_plane) const;
	/**
	 * Compares the normal components and `d` exactly. Matching NaN coefficients compare equal.
	 *
	 * **Used for** comparing stored coefficients that can include matching NaN values.
	 *
	 * - `p_plane` — Plane whose coefficients are compared with this plane's coefficients, including matching NaN values.
	 *
	 * ```cpp
	 * Plane missing(0, 1, 0, real_t(Math::NaN));
	 * Plane reported(0, 1, 0, real_t(Math::NaN));
	 * bool same_snapshot = missing.is_same(reported); // Matching invalid coefficients.
	 * ```
	 */
	bool is_same(const Plane &p_plane) const;
	/**
	 * Tests approximate coefficient equality in either orientation. The other plane can match directly or with both its normal and `d` negated.
	 *
	 * **Used for** matching two faces that can have opposite winding.
	 *
	 * - `p_plane` — Plane whose coefficients are compared in both orientations.
	 *
	 * ```cpp
	 * Plane mesh_face(Vector3(0, 1, 0), 2);
	 * Plane other_face(Vector3(0, -1, 0), -2); // Opposite winding.
	 * bool same_surface = mesh_face.is_equal_approx_any_side(other_face);
	 * ```
	 */
	bool is_equal_approx_any_side(const Plane &p_plane) const;
	/**
	 * Tests that all three normal components and the equation constant are finite.
	 *
	 * **Used for** rejecting invalid plane coefficients before constructing collision geometry.
	 *
	 * ```cpp
	 * Plane imported(0, 1, 0, real_t(Math::INF)); // Coefficients from an import.
	 * if (!imported.is_finite()) { return; } // Discard before constructing collision geometry.
	 * ```
	 */
	bool is_finite() const;

	/**
	 * Tests exact equality of the stored normal components and `d`.
	 *
	 * **Used for** checking whether a cached clipping equation can be used again without a change.
	 *
	 * - `p_plane` — Plane whose stored normal and `d` are compared with this plane's values.
	 *
	 * ```cpp
	 * Plane active(Vector3(0, 1, 0), 2);
	 * Plane requested(Vector3(0, 1, 0), 2);
	 * bool reuse_clip_equation = active == requested;
	 * ```
	 */
	constexpr bool operator==(const Plane &p_plane) const;
	/**
	 * Tests whether the normal or the equation constant differs under ordinary floating-point comparison.
	 *
	 * **Used for** checking whether a changed plane equation requires rebuilding a clipping mask.
	 *
	 * - `p_plane` — Plane whose stored normal and `d` are checked for differences.
	 *
	 * ```cpp
	 * Plane previous_waterline(Vector3(0, 1, 0), 2);
	 * Plane raised_waterline(Vector3(0, 1, 0), 3);
	 * bool rebuild_water_mask = previous_waterline != raised_waterline;
	 * ```
	 */
	constexpr bool operator!=(const Plane &p_plane) const;
	/**
	 * Formats the normal under `N` and the equation constant under `D` using the Godot string API.
	 *
	 * **Used for** logging plane coefficients while debugging imported geometry.
	 *
	 * ```cpp
	 * Plane imported_clip(0, 2, 0, 4);
	 * print_verbose("Imported clipping plane: ", static_cast<String>(imported_clip));
	 * ```
	 */
	explicit operator String() const;

	/**
	 * Creates a degenerate plane with a zero normal and equation constant.
	 *
	 * **Used for** representing an unset plane before a tool has picked a surface.
	 *
	 * ```cpp
	 * Plane picked_surface; // No surface picked yet.
	 * bool has_surface = picked_surface.normal != Vector3();
	 * ```
	 */
	Plane() = default;
	/**
	 * Creates a plane from its four equation coefficients. It stores the normal components as supplied.
	 *
	 * **Used for** loading plane coefficients from a tool that supplies an equation directly.
	 *
	 * - `p_a` — X component of the normal.
	 * - `p_b` — Y component of the normal.
	 * - `p_c` — Z component of the normal.
	 * - `p_d` — Right-hand side of the plane equation.
	 *
	 * ```cpp
	 * constexpr real_t ceiling_height = 3;
	 * constexpr Plane ceiling(0, -1, 0, -ceiling_height);
	 * bool too_high = ceiling.distance_to(Vector3(1, 4, 1)) < 0;
	 * ```
	 */
	constexpr Plane(real_t p_a, real_t p_b, real_t p_c, real_t p_d) :
			normal(p_a, p_b, p_c),
			d(p_d) {}

	/**
	 * Stores the supplied normal and equation constant. A zero constant places a valid plane through the origin.
	 *
	 * **Used for** creating a clipping plane from an axis normal and an offset.
	 *
	 * - `p_normal` — Normal that sets the positive side. The constructor stores it as supplied.
	 * - `p_d` — Right-hand side of the plane equation. The default puts the plane through the origin if the normal is nonzero.
	 *
	 * ```cpp
	 * constexpr Vector3 up(0, 1, 0);
	 * constexpr real_t platform_elevation = 2;
	 * constexpr Plane platform(up, platform_elevation);
	 * ```
	 */
	constexpr Plane(const Vector3 &p_normal, real_t p_d = 0.0);
	/**
	 * Stores the supplied normal and computes `d` so the given point lies on the plane.
	 *
	 * **Used for** creating a plane through a known surface point, such as an anchor on a shelf.
	 *
	 * - `p_normal` — Normal that sets the positive side. The constructor stores it as supplied.
	 * - `p_point` — Point on the plane, in the same coordinate space as the normal.
	 *
	 * ```cpp
	 * Vector3 shelf_normal(0, 1, 0), shelf_anchor(4, 2, 3);
	 * Plane shelf(shelf_normal, shelf_anchor);
	 * Vector3 target = shelf.project(Vector3(5, 3, 3));
	 * ```
	 */
	_FORCE_INLINE_ Plane(const Vector3 &p_normal, const Vector3 &p_point);
	/**
	 * Creates a plane through three points. The winding order sets the direction of the unit normal. Collinear points produce a zero normal.
	 *
	 * **Used for** building a plane from a triangle's winding.
	 *
	 * - `p_point1` — First point in the winding order, in the plane's coordinate space.
	 * - `p_point2` — Second point in the winding order, in the same coordinate space.
	 * - `p_point3` — Third point in the winding order, in the same coordinate space.
	 * - `p_dir` — Order of the three points when viewed from the positive side.
	 *
	 * ```cpp
	 * Vector3 a(0, 0, 0), b(1, 0, 0), c(0, 0, 1); // Face vertices in mesh space.
	 * Plane face(a, b, c, CLOCKWISE);
	 * Vector3 face_normal = face.get_normal();
	 * ```
	 */
	_FORCE_INLINE_ Plane(const Vector3 &p_point1, const Vector3 &p_point2, const Vector3 &p_point3, ClockDirection p_dir = CLOCKWISE);
};

inline constexpr Plane Plane::PLANE_YZ = { 1, 0, 0, 0 };
inline constexpr Plane Plane::PLANE_XZ = { 0, 1, 0, 0 };
inline constexpr Plane Plane::PLANE_XY = { 0, 0, 1, 0 };

bool Plane::is_point_over(const Vector3 &p_point) const {
	return (normal.dot(p_point) > d);
}

real_t Plane::distance_to(const Vector3 &p_point) const {
	return (normal.dot(p_point) - d);
}

bool Plane::has_point(const Vector3 &p_point, real_t p_tolerance) const {
	real_t dist = normal.dot(p_point) - d;
	dist = Math::abs(dist);
	return (dist <= p_tolerance);
}

constexpr Plane::Plane(const Vector3 &p_normal, real_t p_d) :
		normal(p_normal),
		d(p_d) {
}

Plane::Plane(const Vector3 &p_normal, const Vector3 &p_point) :
		normal(p_normal),
		d(p_normal.dot(p_point)) {
}

Plane::Plane(const Vector3 &p_point1, const Vector3 &p_point2, const Vector3 &p_point3, ClockDirection p_dir) {
	if (p_dir == CLOCKWISE) {
		normal = (p_point1 - p_point3).cross(p_point1 - p_point2);
	} else {
		normal = (p_point1 - p_point2).cross(p_point1 - p_point3);
	}

	normal.normalize();
	d = normal.dot(p_point1);
}

constexpr bool Plane::operator==(const Plane &p_plane) const {
	return normal == p_plane.normal && d == p_plane.d;
}

constexpr bool Plane::operator!=(const Plane &p_plane) const {
	return normal != p_plane.normal || d != p_plane.d;
}

/**
 * Allows the binding's array placement code to zero-initialize plane storage. Zero coefficients match the default plane.
 *
 * **Used for** letting array storage initialize default planes by clearing their bytes.
 *
 * ```cpp
 * static_assert(is_zero_constructible_v<Plane>);
 * ```
 */
template <>
struct is_zero_constructible<Plane> : std::true_type {};

} // namespace godot
