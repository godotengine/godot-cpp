/**************************************************************************/
/*  vector3.hpp                                                           */
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
#include <godot_cpp/core/math.hpp>
#include <godot_cpp/variant/string.hpp>

namespace godot {

struct Basis;
struct Vector2;
struct Vector3i;

/**
 * A 3D vector using floating-point coordinates.
 */
struct [[nodiscard]] Vector3 {
	/**
	 * Left unit vector. Represents the local direction of left, and the global direction of west.
	 */
	static const Vector3 LEFT;
	/**
	 * Right unit vector. Represents the local direction of right, and the global direction of east.
	 */
	static const Vector3 RIGHT;
	/**
	 * Up unit vector.
	 */
	static const Vector3 UP;
	/**
	 * Down unit vector.
	 */
	static const Vector3 DOWN;
	/**
	 * Forward unit vector. Represents the local direction of forward, and the global direction of north.
	 * Keep in mind that the forward direction for lights, cameras, etc is different from 3D assets like
	 * characters, which face towards the camera by convention. Use `godot::Vector3::MODEL_FRONT` and
	 * similar constants when working in 3D asset space.
	 */
	static const Vector3 FORWARD;
	/**
	 * Back unit vector. Represents the local direction of back, and the global direction of south.
	 */
	static const Vector3 BACK;
	/**
	 * Unit vector pointing towards the left side of imported 3D assets.
	 */
	static const Vector3 MODEL_LEFT;
	/**
	 * Unit vector pointing towards the right side of imported 3D assets.
	 */
	static const Vector3 MODEL_RIGHT;
	/**
	 * Unit vector pointing towards the top side (up) of imported 3D assets.
	 */
	static const Vector3 MODEL_TOP;
	/**
	 * Unit vector pointing towards the bottom side (down) of imported 3D assets.
	 */
	static const Vector3 MODEL_BOTTOM;
	/**
	 * Unit vector pointing towards the front side (facing forward) of imported 3D assets.
	 */
	static const Vector3 MODEL_FRONT;
	/**
	 * Unit vector pointing towards the rear side (back) of imported 3D assets.
	 */
	static const Vector3 MODEL_REAR;

	/**
	 * The number of components in the vector.
	 */
	static constexpr int AXIS_COUNT = 3;

	/**
	 * Component indices accepted by `godot::Vector3::operator[]()`.
	 */
	enum Axis {
		/**
		 * Index 0, which selects the X component.
		 */
		AXIS_X,
		/**
		 * Index 1, which selects the Y component.
		 */
		AXIS_Y,
		/**
		 * Index 2, which selects the Z component.
		 */
		AXIS_Z,
	};

	/**
	 * The vector's X component. Also accessible by using the index position `[0]`.
	 */
	real_t x = 0.0f;
	/**
	 * The vector's Y component. Also accessible by using the index position `[1]`.
	 */
	real_t y = 0.0f;
	/**
	 * The vector's Z component. Also accessible by using the index position `[2]`.
	 */
	real_t z = 0.0f;

	/**
	 * Returns a writable reference to the component at index zero through 2 in X, Y, Z order.
	 *
	 * - `p_axis` — Zero-based component index in X, Y, Z order.
	 */
	constexpr real_t &operator[](int p_axis) {
		// The pointer math below assumes that the elements are placed back-to-back, like an array.
		// This is always true in practice, but technically not guaranteed; we safety-check it here.
		static_assert(offsetof(Vector3, x) == 0 * sizeof(real_t));
		static_assert(offsetof(Vector3, y) == 1 * sizeof(real_t));
		static_assert(offsetof(Vector3, z) == 2 * sizeof(real_t));
		static_assert(sizeof(Vector3) == 3 * sizeof(real_t));

		DEV_ASSERT((unsigned int)p_axis < 3);
		return (&x)[p_axis];
	}
	/**
	 * Returns the component at index zero through 2 in X, Y, Z order.
	 *
	 * - `p_axis` — Zero-based component index in X, Y, Z order.
	 */
	constexpr const real_t &operator[](int p_axis) const {
		DEV_ASSERT((unsigned int)p_axis < 3);
		return (&x)[p_axis];
	}

	/**
	 * Returns the axis of the vector's lowest value. See `AXIS_*` constants. If all components are equal,
	 * this method returns `godot::Vector3::AXIS_Z`.
	 */
	_FORCE_INLINE_ Vector3::Axis min_axis_index() const {
		return x < y ? (x < z ? Vector3::AXIS_X : Vector3::AXIS_Z) : (y < z ? Vector3::AXIS_Y : Vector3::AXIS_Z);
	}

	/**
	 * Returns the axis of the vector's highest value. See `AXIS_*` constants. If all components are equal,
	 * this method returns `godot::Vector3::AXIS_X`.
	 */
	_FORCE_INLINE_ Vector3::Axis max_axis_index() const {
		return x < y ? (y < z ? Vector3::AXIS_Z : Vector3::AXIS_Y) : (x < z ? Vector3::AXIS_Z : Vector3::AXIS_X);
	}

	/**
	 * Returns each component's smaller value after comparing it with the matching component of the other vector.
	 *
	 * - `p_vector3` — Vector that supplies the other X, Y, and Z values.
	 */
	Vector3 min(const Vector3 &p_vector3) const {
		return Vector3(MIN(x, p_vector3.x), MIN(y, p_vector3.y), MIN(z, p_vector3.z));
	}

	/**
	 * Returns each component's smaller value after comparing it with the same scalar.
	 *
	 * - `p_scalar` — Value compared with all three components.
	 */
	Vector3 minf(real_t p_scalar) const {
		return Vector3(MIN(x, p_scalar), MIN(y, p_scalar), MIN(z, p_scalar));
	}

	/**
	 * Returns each component's larger value after comparing it with the matching component of the other vector.
	 *
	 * - `p_vector3` — Vector that supplies the other X, Y, and Z values.
	 */
	Vector3 max(const Vector3 &p_vector3) const {
		return Vector3(MAX(x, p_vector3.x), MAX(y, p_vector3.y), MAX(z, p_vector3.z));
	}

	/**
	 * Returns each component's larger value after comparing it with the same scalar.
	 *
	 * - `p_scalar` — Value compared with all three components.
	 */
	Vector3 maxf(real_t p_scalar) const {
		return Vector3(MAX(x, p_scalar), MAX(y, p_scalar), MAX(z, p_scalar));
	}

	/**
	 * Returns a new vector with all components clamped between the components of `min` and `max`, by
	 * running `clamp()` on each component.
	 *
	 * - `p_min` — Inclusive lower bounds for X, Y, and Z.
	 * - `p_max` — Inclusive upper bounds for X, Y, and Z.
	 */
	Vector3 clamp(const Vector3 &p_min, const Vector3 &p_max) const {
		return Vector3(
				CLAMP(x, p_min.x, p_max.x),
				CLAMP(y, p_min.y, p_max.y),
				CLAMP(z, p_min.z, p_max.z));
	}

	/**
	 * Returns a new vector with all components clamped between `min` and `max`, by running `clamp()` on
	 * each component.
	 *
	 * - `p_min` — Inclusive lower bound for every component.
	 * - `p_max` — Inclusive upper bound for every component.
	 */
	Vector3 clampf(real_t p_min, real_t p_max) const {
		return Vector3(
				CLAMP(x, p_min, p_max),
				CLAMP(y, p_min, p_max),
				CLAMP(z, p_min, p_max));
	}

	/**
	 * Returns the length (magnitude) of this vector.
	 */
	_FORCE_INLINE_ real_t length() const;
	/**
	 * Returns the squared length (squared magnitude) of this vector. This method runs faster than
	 * `godot::Vector3::length()`, so prefer it if you need to compare vectors or need the squared distance
	 * for some formula.
	 */
	_FORCE_INLINE_ real_t length_squared() const;

	/**
	 * Scales the vector to unit length in place. A zero vector stays zero.
	 */
	_FORCE_INLINE_ void normalize();
	/**
	 * Returns the result of scaling the vector to unit length. Equivalent to `v / v.length()`. Returns `(0,
	 * 0, 0)` if `v.length() == 0`.
	 */
	_FORCE_INLINE_ Vector3 normalized() const;
	/**
	 * Returns `true` if the vector is normalized, i.e. its length is approximately equal to 1.
	 */
	_FORCE_INLINE_ bool is_normalized() const;
	/**
	 * Returns the inverse of the vector. This is the same as `Vector3(1.0 / v.x, 1.0 / v.y, 1.0 / v.z)`.
	 */
	_FORCE_INLINE_ Vector3 inverse() const;
	/**
	 * Returns the vector scaled when its length exceeds the limit. A zero vector stays zero.
	 *
	 * - `p_len` — Maximum length when nonnegative. A negative value reverses a nonzero vector and sets its length to the magnitude of the value.
	 */
	Vector3 limit_length(real_t p_len = 1.0) const;

	/**
	 * Sets every component to zero.
	 */
	_FORCE_INLINE_ void zero();

	/**
	 * Rounds each component to the nearest multiple of the matching step component. A zero step leaves that
	 * component unchanged.
	 *
	 * - `p_step` — Grid spacing for each component. A zero spacing leaves that component unchanged.
	 */
	void snap(const Vector3 &p_step);
	/**
	 * Rounds each component to the nearest multiple of the given step. A zero step leaves the vector
	 * unchanged.
	 *
	 * - `p_step` — Grid spacing used for every component. Zero leaves the vector unchanged.
	 */
	void snapf(real_t p_step);
	/**
	 * Returns a new vector with each component snapped to the nearest multiple of the corresponding
	 * component in `step`. This can also be used to round the components to an arbitrary number of
	 * decimals.
	 *
	 * - `p_step` — Grid spacing for each component. A zero spacing leaves that component unchanged.
	 */
	Vector3 snapped(const Vector3 &p_step) const;
	/**
	 * Returns a new vector with each component snapped to the nearest multiple of `step`. This can also be
	 * used to round the components to an arbitrary number of decimals.
	 *
	 * - `p_step` — Grid spacing used for every component. Zero leaves the vector unchanged.
	 */
	Vector3 snappedf(real_t p_step) const;

	/**
	 * Rotates the vector in place about the normalized axis by the given angle in radians.
	 *
	 * - `p_axis` — Unit vector defining the axis of rotation.
	 * - `p_angle` — Rotation angle in radians, using the right-hand rule around the axis.
	 */
	void rotate(const Vector3 &p_axis, real_t p_angle);
	/**
	 * Returns the result of rotating this vector around a given axis by `angle` (in radians). The axis must
	 * be a normalized vector.
	 *
	 * - `p_axis` — Unit vector defining the axis of rotation.
	 * - `p_angle` — Rotation angle in radians, using the right-hand rule around the axis.
	 */
	Vector3 rotated(const Vector3 &p_axis, real_t p_angle) const;

	/* Static Methods between 2 vector3s */

	/**
	 * Interpolates the components linearly.
	 *
	 * - `p_to` — Target vector at weight one.
	 * - `p_weight` — Interpolation factor. Zero selects this vector and one selects the target.
	 */
	_FORCE_INLINE_ Vector3 lerp(const Vector3 &p_to, real_t p_weight) const;
	/**
	 * Interpolates the direction by rotating toward the target and interpolates the length linearly. Collinear vectors and zero vectors use linear interpolation.
	 *
	 * - `p_to` — Target vector at weight one.
	 * - `p_weight` — Interpolation factor. Zero selects this vector and one selects the target.
	 */
	_FORCE_INLINE_ Vector3 slerp(const Vector3 &p_to, real_t p_weight) const;
	/**
	 * Returns a cubic interpolation with this vector as the first point.
	 *
	 * - `p_b` — Second interpolation point, reached at weight one.
	 * - `p_pre_a` — Control point before this point.
	 * - `p_post_b` — Control point after the second point.
	 * - `p_weight` — Interpolation factor between this point at zero and the second point at one.
	 */
	_FORCE_INLINE_ Vector3 cubic_interpolate(const Vector3 &p_b, const Vector3 &p_pre_a, const Vector3 &p_post_b, real_t p_weight) const;
	/**
	 * Returns a cubic interpolation using the time of each point. This point is at time zero.
	 *
	 * - `p_b` — Second interpolation point, reached at weight one.
	 * - `p_pre_a` — Control point before this point.
	 * - `p_post_b` — Control point after the second point.
	 * - `p_weight` — Interpolation factor between this point at zero and the second point at one.
	 * - `p_b_t` — Time of the second point relative to this point.
	 * - `p_pre_a_t` — Time of the preceding control point relative to this point.
	 * - `p_post_b_t` — Time of the following control point relative to this point.
	 */
	_FORCE_INLINE_ Vector3 cubic_interpolate_in_time(const Vector3 &p_b, const Vector3 &p_pre_a, const Vector3 &p_post_b, real_t p_weight, real_t p_b_t, real_t p_pre_a_t, real_t p_post_b_t) const;
	/**
	 * Returns the point on the cubic Bézier curve at the supplied curve parameter.
	 *
	 * - `p_control_1` — Control point next to the start.
	 * - `p_control_2` — Control point next to the end.
	 * - `p_end` — End of the curve. This vector is the start.
	 * - `p_t` — Curve parameter. Zero selects the start and one selects the end.
	 */
	_FORCE_INLINE_ Vector3 bezier_interpolate(const Vector3 &p_control_1, const Vector3 &p_control_2, const Vector3 &p_end, real_t p_t) const;
	/**
	 * Returns the derivative of the cubic Bézier curve with respect to its curve parameter.
	 *
	 * - `p_control_1` — Control point next to the start.
	 * - `p_control_2` — Control point next to the end.
	 * - `p_end` — End of the curve. This vector is the start.
	 * - `p_t` — Curve parameter. Zero selects the start and one selects the end.
	 */
	_FORCE_INLINE_ Vector3 bezier_derivative(const Vector3 &p_control_1, const Vector3 &p_control_2, const Vector3 &p_end, real_t p_t) const;

	/**
	 * Moves toward the target by the given distance. Reaches the target if the distance fits in the step or the points are almost coincident.
	 *
	 * - `p_to` — Target point in the same coordinate system.
	 * - `p_delta` — Step length. A negative value moves away unless the points are almost coincident.
	 */
	Vector3 move_toward(const Vector3 &p_to, real_t p_delta) const;

	/**
	 * Returns the octahedral-encoded (oct32) form of this `godot::Vector3` as a `godot::Vector2`. Since a
	 * `godot::Vector2` occupies 1/3 less memory compared to `godot::Vector3`, this form of compression can
	 * be used to pass greater amounts of `godot::Vector3::normalized()` `godot::Vector3`s without
	 * increasing storage or memory requirements.
	 */
	Vector2 octahedron_encode() const;
	/**
	 * Returns the `godot::Vector3` from an octahedral-compressed form created using
	 * `godot::Vector3::octahedron_encode()` (stored as a `godot::Vector2`).
	 *
	 * - `p_oct` — Two coordinates from octahedral encoding, each from zero through one.
	 */
	static Vector3 octahedron_decode(const Vector2 &p_oct);
	/**
	 * Packs the tangent direction and its handedness sign into a two-component octahedral encoding. The
	 * sign selects which half of the encoded Y range holds the direction.
	 *
	 * - `p_sign` — Tangent sign. Zero and positive values encode a positive sign.
	 */
	Vector2 octahedron_tangent_encode(float p_sign) const;
	/**
	 * Decodes a tangent direction and writes its handedness as either positive or negative one through the
	 * required `r_sign` pointer.
	 *
	 * - `p_oct` — Two coordinates from octahedral tangent encoding.
	 * - `r_sign` — Writable non-null pointer. Receives either one or minus one.
	 */
	static Vector3 octahedron_tangent_decode(const Vector2 &p_oct, float *r_sign);

	/**
	 * Returns the cross product of this vector and `with`.
	 *
	 * - `p_with` — Right-hand vector of the cross product, in the same coordinate system.
	 */
	_FORCE_INLINE_ Vector3 cross(const Vector3 &p_with) const;
	/**
	 * Returns the sum of the products of matching components.
	 *
	 * - `p_with` — Vector multiplied component by component before summing.
	 */
	_FORCE_INLINE_ real_t dot(const Vector3 &p_with) const;
	/**
	 * Returns a matrix whose rows are the supplied vector scaled by this vector's X, Y, and Z components.
	 *
	 * - `p_with` — Vector that supplies the components of each row before scaling.
	 */
	Basis outer(const Vector3 &p_with) const;
	/**
	 * Returns a unit vector perpendicular to this vector. Reports an error and returns zero if this vector
	 * is approximately zero.
	 */
	_FORCE_INLINE_ Vector3 get_any_perpendicular() const;

	/**
	 * Returns a new vector with all components in absolute values (i.e. positive).
	 */
	_FORCE_INLINE_ Vector3 abs() const;
	/**
	 * Returns a new vector with all components rounded down (towards negative infinity).
	 */
	_FORCE_INLINE_ Vector3 floor() const;
	/**
	 * Returns a new vector with each component set to `1.0` if it's positive, `-1.0` if it's negative, and
	 * `0.0` if it's zero. The result is identical to calling `sign()` on each component.
	 */
	_FORCE_INLINE_ Vector3 sign() const;
	/**
	 * Returns a new vector with all components rounded up (towards positive infinity).
	 */
	_FORCE_INLINE_ Vector3 ceil() const;
	/**
	 * Returns a new vector with all components rounded to the nearest integer, with halfway cases rounded
	 * away from zero.
	 */
	_FORCE_INLINE_ Vector3 round() const;

	/**
	 * Returns the Euclidean distance between the points represented by the two vectors.
	 *
	 * - `p_to` — Other point in the same coordinate system.
	 */
	_FORCE_INLINE_ real_t distance_to(const Vector3 &p_to) const;
	/**
	 * Returns the squared Euclidean distance between the points represented by the two vectors without
	 * taking a square root.
	 *
	 * - `p_to` — Other point in the same coordinate system.
	 */
	_FORCE_INLINE_ real_t distance_squared_to(const Vector3 &p_to) const;

	/**
	 * Wraps all components with the same divisor. Nonzero results have the sign of that divisor.
	 *
	 * - `p_mod` — Nonzero divisor used for every component.
	 */
	_FORCE_INLINE_ Vector3 posmod(real_t p_mod) const;
	/**
	 * Wraps each component with its corresponding divisor. Nonzero results have the sign of their divisors.
	 *
	 * - `p_modv` — Vector of nonzero X, Y, and Z divisors.
	 */
	_FORCE_INLINE_ Vector3 posmodv(const Vector3 &p_modv) const;
	/**
	 * Returns the part of this vector parallel to the supplied direction.
	 *
	 * - `p_to` — Nonzero direction of projection. It does not have to be a unit vector.
	 */
	_FORCE_INLINE_ Vector3 project(const Vector3 &p_to) const;

	/**
	 * Returns the unsigned minimum angle to the given vector, in radians.
	 *
	 * - `p_to` — Other direction in the same coordinate system.
	 */
	_FORCE_INLINE_ real_t angle_to(const Vector3 &p_to) const;
	/**
	 * Returns the signed angle to the given vector, in radians. The sign of the angle is positive in a
	 * counter-clockwise direction and negative in a clockwise direction when viewed from the side specified
	 * by the `axis`.
	 *
	 * - `p_to` — Other direction in the same coordinate system.
	 * - `p_axis` — Direction used to choose the sign. The angle is negative if the cross product points away from this axis.
	 */
	_FORCE_INLINE_ real_t signed_angle_to(const Vector3 &p_to, const Vector3 &p_axis) const;
	/**
	 * Returns the normalized vector pointing from this vector to `to`. This is equivalent to using `(b -
	 * a).normalized()`.
	 *
	 * - `p_to` — Target point in the same coordinate system.
	 */
	_FORCE_INLINE_ Vector3 direction_to(const Vector3 &p_to) const;

	/**
	 * Removes the component along the normal to leave a vector parallel to the surface.
	 *
	 * - `p_normal` — Unit normal of the surface.
	 */
	_FORCE_INLINE_ Vector3 slide(const Vector3 &p_normal) const;
	/**
	 * Reflects the vector off the surface with the given unit normal. The normal component changes sign and
	 * the tangential component stays the same.
	 *
	 * - `p_normal` — Unit normal of the surface to bounce off.
	 */
	_FORCE_INLINE_ Vector3 bounce(const Vector3 &p_normal) const;
	/**
	 * Reflects the vector across the axis defined by the given unit vector. The parallel component stays
	 * the same and the perpendicular component changes sign.
	 *
	 * - `p_normal` — Unit vector along the reflection axis.
	 */
	_FORCE_INLINE_ Vector3 reflect(const Vector3 &p_normal) const;

	/**
	 * Returns `true` if this vector and `to` are approximately equal, by running `is_equal_approx()` on
	 * each component.
	 *
	 * - `p_v` — Vector whose components are compared with this vector.
	 */
	bool is_equal_approx(const Vector3 &p_v) const;
	/**
	 * Tests exact component equality and treats matching NaN components as equal.
	 *
	 * - `p_v` — Vector whose components are compared with this vector.
	 */
	bool is_same(const Vector3 &p_v) const;
	/**
	 * Returns `true` if this vector's values are approximately zero, by running `is_zero_approx()` on each
	 * component. This method is faster than using `godot::Vector3::is_equal_approx()` with one value as a
	 * zero vector.
	 */
	bool is_zero_approx() const;
	/**
	 * Returns `true` if this vector is finite, by calling `is_finite()` on each component.
	 */
	bool is_finite() const;

	/* Operators */

	/**
	 * Adds the right-hand vector to this vector component by component.
	 *
	 * - `p_v` — Vector whose components are added in place.
	 */
	constexpr Vector3 &operator+=(const Vector3 &p_v);
	/**
	 * Adds each component of the `godot::Vector3` by the components of the given `godot::Vector3`.
	 *
	 * - `p_v` — Vector whose components are added.
	 */
	constexpr Vector3 operator+(const Vector3 &p_v) const;
	/**
	 * Subtracts the right-hand vector from this vector component by component.
	 *
	 * - `p_v` — Vector whose components are subtracted in place.
	 */
	constexpr Vector3 &operator-=(const Vector3 &p_v);
	/**
	 * Subtracts each component of the `godot::Vector3` by the components of the given `godot::Vector3`.
	 *
	 * - `p_v` — Vector whose components are subtracted.
	 */
	constexpr Vector3 operator-(const Vector3 &p_v) const;
	/**
	 * Multiplies each component by the corresponding component of the right-hand vector in place.
	 *
	 * - `p_v` — Vector supplying the factor for each component in place.
	 */
	constexpr Vector3 &operator*=(const Vector3 &p_v);
	/**
	 * Multiplies each component of the `godot::Vector3` by the components of the given `godot::Vector3`.
	 *
	 * - `p_v` — Vector supplying the factor for each component.
	 */
	constexpr Vector3 operator*(const Vector3 &p_v) const;
	/**
	 * Divides each component by the corresponding component of the right-hand vector in place.
	 *
	 * - `p_v` — Vector supplying the nonzero divisor for each component in place.
	 */
	constexpr Vector3 &operator/=(const Vector3 &p_v);
	/**
	 * Divides each component of the `godot::Vector3` by the components of the given `godot::Vector3`.
	 *
	 * - `p_v` — Vector supplying the nonzero divisor for each component.
	 */
	constexpr Vector3 operator/(const Vector3 &p_v) const;

	/**
	 * Multiplies each component by the given scalar in place.
	 *
	 * - `p_scalar` — Scalar multiplied by every component in place.
	 */
	constexpr Vector3 &operator*=(real_t p_scalar);
	/**
	 * Multiplies each component of the `godot::Vector3` by the given `float`.
	 *
	 * - `p_scalar` — Scalar multiplied by every component.
	 */
	constexpr Vector3 operator*(real_t p_scalar) const;
	/**
	 * Divides each component by the given scalar in place.
	 *
	 * - `p_scalar` — Nonzero divisor applied to every component in place.
	 */
	constexpr Vector3 &operator/=(real_t p_scalar);
	/**
	 * Divides each component of the `godot::Vector3` by the given `float`.
	 *
	 * - `p_scalar` — Nonzero divisor applied to every component.
	 */
	constexpr Vector3 operator/(real_t p_scalar) const;

	/**
	 * Returns a vector with each component negated.
	 */
	constexpr Vector3 operator-() const;

	/**
	 * Tests exact equality of the components.
	 *
	 * - `p_v` — Right-hand vector in the comparison.
	 */
	constexpr bool operator==(const Vector3 &p_v) const;
	/**
	 * Tests whether any component differs.
	 *
	 * - `p_v` — Right-hand vector in the comparison.
	 */
	constexpr bool operator!=(const Vector3 &p_v) const;
	/**
	 * Compares two `godot::Vector3` vectors by first checking if the X value of the left vector is less
	 * than the X value of the `right` vector.
	 *
	 * - `p_v` — Right-hand vector in the comparison.
	 */
	constexpr bool operator<(const Vector3 &p_v) const;
	/**
	 * Compares two `godot::Vector3` vectors by first checking if the X value of the left vector is less
	 * than or equal to the X value of the `right` vector.
	 *
	 * - `p_v` — Right-hand vector in the comparison.
	 */
	constexpr bool operator<=(const Vector3 &p_v) const;
	/**
	 * Compares two `godot::Vector3` vectors by first checking if the X value of the left vector is greater
	 * than the X value of the `right` vector.
	 *
	 * - `p_v` — Right-hand vector in the comparison.
	 */
	constexpr bool operator>(const Vector3 &p_v) const;
	/**
	 * Compares two `godot::Vector3` vectors by first checking if the X value of the left vector is greater
	 * than or equal to the X value of the `right` vector.
	 *
	 * - `p_v` — Right-hand vector in the comparison.
	 */
	constexpr bool operator>=(const Vector3 &p_v) const;

	/**
	 * Formats X, Y, and Z as a parenthesized, comma-separated string.
	 */
	explicit operator String() const;
	/**
	 * Converts each component to an integer by truncating toward zero.
	 */
	operator Vector3i() const;

	/**
	 * Constructs a default-initialized `godot::Vector3` with all components set to `0`.
	 */
	constexpr Vector3() :
			x(0), y(0), z(0) {}
	/**
	 * Returns a `godot::Vector3` with the given components.
	 *
	 * - `p_x` — X component.
	 * - `p_y` — Y component.
	 * - `p_z` — Z component.
	 */
	constexpr Vector3(real_t p_x, real_t p_y, real_t p_z) :
			x(p_x), y(p_y), z(p_z) {}
};

inline constexpr Vector3 Vector3::LEFT = { -1, 0, 0 };
inline constexpr Vector3 Vector3::RIGHT = { 1, 0, 0 };
inline constexpr Vector3 Vector3::UP = { 0, 1, 0 };
inline constexpr Vector3 Vector3::DOWN = { 0, -1, 0 };
inline constexpr Vector3 Vector3::FORWARD = { 0, 0, -1 };
inline constexpr Vector3 Vector3::BACK = { 0, 0, 1 };
inline constexpr Vector3 Vector3::MODEL_LEFT = { 1, 0, 0 };
inline constexpr Vector3 Vector3::MODEL_RIGHT = { -1, 0, 0 };
inline constexpr Vector3 Vector3::MODEL_TOP = { 0, 1, 0 };
inline constexpr Vector3 Vector3::MODEL_BOTTOM = { 0, -1, 0 };
inline constexpr Vector3 Vector3::MODEL_FRONT = { 0, 0, 1 };
inline constexpr Vector3 Vector3::MODEL_REAR = { 0, 0, -1 };

Vector3 Vector3::cross(const Vector3 &p_with) const {
	Vector3 ret(
			(y * p_with.z) - (z * p_with.y),
			(z * p_with.x) - (x * p_with.z),
			(x * p_with.y) - (y * p_with.x));

	return ret;
}

real_t Vector3::dot(const Vector3 &p_with) const {
	return x * p_with.x + y * p_with.y + z * p_with.z;
}

Vector3 Vector3::abs() const {
	return Vector3(Math::abs(x), Math::abs(y), Math::abs(z));
}

Vector3 Vector3::sign() const {
	return Vector3(SIGN(x), SIGN(y), SIGN(z));
}

Vector3 Vector3::floor() const {
	return Vector3(Math::floor(x), Math::floor(y), Math::floor(z));
}

Vector3 Vector3::ceil() const {
	return Vector3(Math::ceil(x), Math::ceil(y), Math::ceil(z));
}

Vector3 Vector3::round() const {
	return Vector3(Math::round(x), Math::round(y), Math::round(z));
}

Vector3 Vector3::lerp(const Vector3 &p_to, real_t p_weight) const {
	Vector3 res = *this;
	res.x = Math::lerp(res.x, p_to.x, p_weight);
	res.y = Math::lerp(res.y, p_to.y, p_weight);
	res.z = Math::lerp(res.z, p_to.z, p_weight);
	return res;
}

Vector3 Vector3::slerp(const Vector3 &p_to, real_t p_weight) const {
	// This method seems more complicated than it really is, since we write out
	// the internals of some methods for efficiency (mainly, checking length).
	real_t start_length_sq = length_squared();
	real_t end_length_sq = p_to.length_squared();
	if (unlikely(start_length_sq == 0.0f || end_length_sq == 0.0f)) {
		// Zero length vectors have no angle, so the best we can do is either lerp or throw an error.
		return lerp(p_to, p_weight);
	}
	Vector3 axis = cross(p_to);
	real_t axis_length_sq = axis.length_squared();
	if (unlikely(axis_length_sq == 0.0f)) {
		// Colinear vectors have no rotation axis or angle between them, so the best we can do is lerp.
		return lerp(p_to, p_weight);
	}
	axis /= Math::sqrt(axis_length_sq);
	real_t start_length = Math::sqrt(start_length_sq);
	real_t result_length = Math::lerp(start_length, Math::sqrt(end_length_sq), p_weight);
	real_t angle = angle_to(p_to);
	return rotated(axis, angle * p_weight) * (result_length / start_length);
}

Vector3 Vector3::cubic_interpolate(const Vector3 &p_b, const Vector3 &p_pre_a, const Vector3 &p_post_b, real_t p_weight) const {
	Vector3 res = *this;
	res.x = Math::cubic_interpolate(res.x, p_b.x, p_pre_a.x, p_post_b.x, p_weight);
	res.y = Math::cubic_interpolate(res.y, p_b.y, p_pre_a.y, p_post_b.y, p_weight);
	res.z = Math::cubic_interpolate(res.z, p_b.z, p_pre_a.z, p_post_b.z, p_weight);
	return res;
}

Vector3 Vector3::cubic_interpolate_in_time(const Vector3 &p_b, const Vector3 &p_pre_a, const Vector3 &p_post_b, real_t p_weight, real_t p_b_t, real_t p_pre_a_t, real_t p_post_b_t) const {
	Vector3 res = *this;
	res.x = Math::cubic_interpolate_in_time(res.x, p_b.x, p_pre_a.x, p_post_b.x, p_weight, p_b_t, p_pre_a_t, p_post_b_t);
	res.y = Math::cubic_interpolate_in_time(res.y, p_b.y, p_pre_a.y, p_post_b.y, p_weight, p_b_t, p_pre_a_t, p_post_b_t);
	res.z = Math::cubic_interpolate_in_time(res.z, p_b.z, p_pre_a.z, p_post_b.z, p_weight, p_b_t, p_pre_a_t, p_post_b_t);
	return res;
}

Vector3 Vector3::bezier_interpolate(const Vector3 &p_control_1, const Vector3 &p_control_2, const Vector3 &p_end, real_t p_t) const {
	Vector3 res = *this;
	res.x = Math::bezier_interpolate(res.x, p_control_1.x, p_control_2.x, p_end.x, p_t);
	res.y = Math::bezier_interpolate(res.y, p_control_1.y, p_control_2.y, p_end.y, p_t);
	res.z = Math::bezier_interpolate(res.z, p_control_1.z, p_control_2.z, p_end.z, p_t);
	return res;
}

Vector3 Vector3::bezier_derivative(const Vector3 &p_control_1, const Vector3 &p_control_2, const Vector3 &p_end, real_t p_t) const {
	Vector3 res = *this;
	res.x = Math::bezier_derivative(res.x, p_control_1.x, p_control_2.x, p_end.x, p_t);
	res.y = Math::bezier_derivative(res.y, p_control_1.y, p_control_2.y, p_end.y, p_t);
	res.z = Math::bezier_derivative(res.z, p_control_1.z, p_control_2.z, p_end.z, p_t);
	return res;
}

real_t Vector3::distance_to(const Vector3 &p_to) const {
	return (p_to - *this).length();
}

real_t Vector3::distance_squared_to(const Vector3 &p_to) const {
	return (p_to - *this).length_squared();
}

Vector3 Vector3::posmod(real_t p_mod) const {
	return Vector3(Math::fposmod(x, p_mod), Math::fposmod(y, p_mod), Math::fposmod(z, p_mod));
}

Vector3 Vector3::posmodv(const Vector3 &p_modv) const {
	return Vector3(Math::fposmod(x, p_modv.x), Math::fposmod(y, p_modv.y), Math::fposmod(z, p_modv.z));
}

Vector3 Vector3::project(const Vector3 &p_to) const {
	return p_to * (dot(p_to) / p_to.length_squared());
}

real_t Vector3::angle_to(const Vector3 &p_to) const {
	return Math::atan2(cross(p_to).length(), dot(p_to));
}

real_t Vector3::signed_angle_to(const Vector3 &p_to, const Vector3 &p_axis) const {
	Vector3 cross_to = cross(p_to);
	real_t unsigned_angle = Math::atan2(cross_to.length(), dot(p_to));
	real_t sign = cross_to.dot(p_axis);
	return (sign < 0) ? -unsigned_angle : unsigned_angle;
}

Vector3 Vector3::direction_to(const Vector3 &p_to) const {
	Vector3 ret(p_to.x - x, p_to.y - y, p_to.z - z);
	ret.normalize();
	return ret;
}

Vector3 Vector3::get_any_perpendicular() const {
	// Return the any perpendicular vector by cross product with the Vector3.RIGHT or Vector3.UP,
	// whichever has the greater angle to the current vector with the sign of each element positive.
	// The only essence is "to avoid being parallel to the current vector", and there is no mathematical basis for using Vector3.RIGHT and Vector3.UP,
	// since it could be a different vector depending on the prior branching code Math::abs(x) <= Math::abs(y) && Math::abs(x) <= Math::abs(z).
	// However, it would be reasonable to use any of the axes of the basis, as it is simpler to calculate.
	ERR_FAIL_COND_V_MSG(is_zero_approx(), Vector3(0, 0, 0), "The Vector3 must not be zero.");
	return cross((Math::abs(x) <= Math::abs(y) && Math::abs(x) <= Math::abs(z)) ? Vector3::RIGHT : Vector3::UP).normalized();
}

/* Operators */

constexpr Vector3 &Vector3::operator+=(const Vector3 &p_v) {
	x += p_v.x;
	y += p_v.y;
	z += p_v.z;
	return *this;
}

constexpr Vector3 Vector3::operator+(const Vector3 &p_v) const {
	return Vector3(x + p_v.x, y + p_v.y, z + p_v.z);
}

constexpr Vector3 &Vector3::operator-=(const Vector3 &p_v) {
	x -= p_v.x;
	y -= p_v.y;
	z -= p_v.z;
	return *this;
}

constexpr Vector3 Vector3::operator-(const Vector3 &p_v) const {
	return Vector3(x - p_v.x, y - p_v.y, z - p_v.z);
}

constexpr Vector3 &Vector3::operator*=(const Vector3 &p_v) {
	x *= p_v.x;
	y *= p_v.y;
	z *= p_v.z;
	return *this;
}

constexpr Vector3 Vector3::operator*(const Vector3 &p_v) const {
	return Vector3(x * p_v.x, y * p_v.y, z * p_v.z);
}

constexpr Vector3 &Vector3::operator/=(const Vector3 &p_v) {
	x /= p_v.x;
	y /= p_v.y;
	z /= p_v.z;
	return *this;
}

constexpr Vector3 Vector3::operator/(const Vector3 &p_v) const {
	return Vector3(x / p_v.x, y / p_v.y, z / p_v.z);
}

constexpr Vector3 &Vector3::operator*=(real_t p_scalar) {
	x *= p_scalar;
	y *= p_scalar;
	z *= p_scalar;
	return *this;
}

// Multiplication operators required to workaround issues with LLVM using implicit conversion
// to Vector3i instead for integers where it should not.

/**
 * Returns the vector with all components multiplied by the left-hand scalar.
 *
 * - `p_scalar` — Left-hand factor applied to every component.
 * - `p_vec` — Vector whose components are multiplied.
 */
constexpr Vector3 operator*(float p_scalar, const Vector3 &p_vec) {
	return p_vec * p_scalar;
}

/**
 * Returns the vector with all components multiplied by the left-hand scalar.
 *
 * - `p_scalar` — Left-hand factor applied to every component.
 * - `p_vec` — Vector whose components are multiplied.
 */
constexpr Vector3 operator*(double p_scalar, const Vector3 &p_vec) {
	return p_vec * p_scalar;
}

/**
 * Returns the vector with all components multiplied by the left-hand scalar.
 *
 * - `p_scalar` — Left-hand factor applied to every component.
 * - `p_vec` — Vector whose components are multiplied.
 */
constexpr Vector3 operator*(int32_t p_scalar, const Vector3 &p_vec) {
	return p_vec * p_scalar;
}

/**
 * Returns the vector with all components multiplied by the left-hand scalar.
 *
 * - `p_scalar` — Left-hand factor applied to every component.
 * - `p_vec` — Vector whose components are multiplied.
 */
constexpr Vector3 operator*(int64_t p_scalar, const Vector3 &p_vec) {
	return p_vec * p_scalar;
}

constexpr Vector3 Vector3::operator*(real_t p_scalar) const {
	return Vector3(x * p_scalar, y * p_scalar, z * p_scalar);
}

constexpr Vector3 &Vector3::operator/=(real_t p_scalar) {
	x /= p_scalar;
	y /= p_scalar;
	z /= p_scalar;
	return *this;
}

constexpr Vector3 Vector3::operator/(real_t p_scalar) const {
	return Vector3(x / p_scalar, y / p_scalar, z / p_scalar);
}

constexpr Vector3 Vector3::operator-() const {
	return Vector3(-x, -y, -z);
}

constexpr bool Vector3::operator==(const Vector3 &p_v) const {
	return x == p_v.x && y == p_v.y && z == p_v.z;
}

constexpr bool Vector3::operator!=(const Vector3 &p_v) const {
	return x != p_v.x || y != p_v.y || z != p_v.z;
}

constexpr bool Vector3::operator<(const Vector3 &p_v) const {
	if (x == p_v.x) {
		if (y == p_v.y) {
			return z < p_v.z;
		}
		return y < p_v.y;
	}
	return x < p_v.x;
}

constexpr bool Vector3::operator>(const Vector3 &p_v) const {
	if (x == p_v.x) {
		if (y == p_v.y) {
			return z > p_v.z;
		}
		return y > p_v.y;
	}
	return x > p_v.x;
}

constexpr bool Vector3::operator<=(const Vector3 &p_v) const {
	if (x == p_v.x) {
		if (y == p_v.y) {
			return z <= p_v.z;
		}
		return y < p_v.y;
	}
	return x < p_v.x;
}

constexpr bool Vector3::operator>=(const Vector3 &p_v) const {
	if (x == p_v.x) {
		if (y == p_v.y) {
			return z >= p_v.z;
		}
		return y > p_v.y;
	}
	return x > p_v.x;
}

/**
 * Returns the cross product of the two vectors. The result is perpendicular to both input vectors.
 *
 * - `p_a` — Left-hand vector of the cross product.
 * - `p_b` — Right-hand vector of the cross product.
 */
_FORCE_INLINE_ Vector3 vec3_cross(const Vector3 &p_a, const Vector3 &p_b) {
	return p_a.cross(p_b);
}

/**
 * Returns the sum of the products of the two vectors' corresponding components.
 *
 * - `p_a` — First vector in the dot product.
 * - `p_b` — Second vector in the dot product.
 */
_FORCE_INLINE_ real_t vec3_dot(const Vector3 &p_a, const Vector3 &p_b) {
	return p_a.dot(p_b);
}

real_t Vector3::length() const {
	real_t x2 = x * x;
	real_t y2 = y * y;
	real_t z2 = z * z;

	return Math::sqrt(x2 + y2 + z2);
}

real_t Vector3::length_squared() const {
	real_t x2 = x * x;
	real_t y2 = y * y;
	real_t z2 = z * z;

	return x2 + y2 + z2;
}

void Vector3::normalize() {
	if (!is_finite()) {
#ifdef MATH_CHECKS
		WARN_PRINT("Vector3 cannot be normalized, the elements must be finite. Making (0, 0, 0) as a fallback.");
#endif // MATH_CHECKS
		zero();
		return;
	}

	real_t l = length_squared();
	if (l == 0) {
		zero();
	} else {
		l = Math::sqrt(l);
		x /= l;
		y /= l;
		z /= l;
	}
}

Vector3 Vector3::normalized() const {
	Vector3 v = *this;
	v.normalize();
	return v;
}

bool Vector3::is_normalized() const {
	// use length_squared() instead of length() to avoid sqrt(), makes it more stringent.
	return Math::is_equal_approx(length_squared(), 1, (real_t)UNIT_EPSILON);
}

Vector3 Vector3::inverse() const {
	return Vector3(1.0f / x, 1.0f / y, 1.0f / z);
}

void Vector3::zero() {
	x = y = z = 0;
}

// slide returns the component of the vector along the given plane, specified by its normal vector.
Vector3 Vector3::slide(const Vector3 &p_normal) const {
#ifdef MATH_CHECKS
	ERR_FAIL_COND_V_MSG(!p_normal.is_normalized(), Vector3(), "The normal Vector3 " + p_normal.operator String() + " must be normalized.");
#endif
	return *this - p_normal * dot(p_normal);
}

Vector3 Vector3::bounce(const Vector3 &p_normal) const {
	return -reflect(p_normal);
}

Vector3 Vector3::reflect(const Vector3 &p_normal) const {
#ifdef MATH_CHECKS
	ERR_FAIL_COND_V_MSG(!p_normal.is_normalized(), Vector3(), "The normal Vector3 " + p_normal.operator String() + " must be normalized.");
#endif
	return 2.0f * p_normal * dot(p_normal) - *this;
}

/**
 * Marks a zero-filled vector as a valid vector with all components equal to zero.
 */
template <>
struct is_zero_constructible<Vector3> : std::true_type {};

} // namespace godot
