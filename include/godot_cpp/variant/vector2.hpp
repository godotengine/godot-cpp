/**************************************************************************/
/*  vector2.hpp                                                           */
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

namespace godot {

class String;
struct Vector2i;

/**
 * A 2D vector using floating-point coordinates.
 */
struct [[nodiscard]] Vector2 {
	/**
	 * Left unit vector. Represents the direction of left.
	 */
	static const Vector2 LEFT;
	/**
	 * Right unit vector. Represents the direction of right.
	 */
	static const Vector2 RIGHT;
	/**
	 * Up unit vector. Y is down in 2D, so this vector points -Y.
	 */
	static const Vector2 UP;
	/**
	 * Down unit vector. Y is down in 2D, so this vector points +Y.
	 */
	static const Vector2 DOWN;

	/**
	 * The number of components in the vector.
	 */
	static constexpr int AXIS_COUNT = 2;

	/**
	 * Component indices accepted by `godot::Vector2::operator[]()`.
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
	};

	/**
	 * Shares storage between the X component and its width alias.
	 */
	union {
		/**
		 * The X component of the vector. Shares storage with `width`.
		 */
		real_t x = 0.0f;
		/**
		 * An alias for the X component when the vector represents a size.
		 */
		real_t width;
	};
	/**
	 * Shares storage between the Y component and its height alias.
	 */
	union {
		/**
		 * The Y component of the vector. Shares storage with `height`.
		 */
		real_t y = 0.0f;
		/**
		 * An alias for the Y component when the vector represents a size.
		 */
		real_t height;
	};

	/**
	 * Returns a writable reference to the selected component.
	 *
	 * - `p_axis` — Zero-based component index. Use `godot::Vector2::AXIS_X` or `godot::Vector2::AXIS_Y`.
	 */
	constexpr real_t &operator[](int p_axis) {
		// The pointer math below assumes that the elements are placed back-to-back, like an array.
		// This is always true in practice, but technically not guaranteed; we safety-check it here.
		static_assert(offsetof(Vector2, x) == 0 * sizeof(real_t));
		static_assert(offsetof(Vector2, width) == 0 * sizeof(real_t));
		static_assert(offsetof(Vector2, y) == 1 * sizeof(real_t));
		static_assert(offsetof(Vector2, height) == 1 * sizeof(real_t));
		static_assert(sizeof(Vector2) == 2 * sizeof(real_t));

		DEV_ASSERT((unsigned int)p_axis < 2);
		return (&x)[p_axis];
	}
	/**
	 * Returns a read-only reference to the selected component.
	 *
	 * - `p_axis` — Zero-based component index. Use `godot::Vector2::AXIS_X` or `godot::Vector2::AXIS_Y`.
	 */
	constexpr const real_t &operator[](int p_axis) const {
		DEV_ASSERT((unsigned int)p_axis < 2);
		return (&x)[p_axis];
	}

	/**
	 * Returns the axis of the vector's lowest value. See `AXIS_*` constants. If all components are equal,
	 * this method returns `godot::Vector2::AXIS_Y`.
	 */
	_FORCE_INLINE_ Vector2::Axis min_axis_index() const {
		return x < y ? Vector2::AXIS_X : Vector2::AXIS_Y;
	}

	/**
	 * Returns the axis of the vector's highest value. See `AXIS_*` constants. If all components are equal,
	 * this method returns `godot::Vector2::AXIS_X`.
	 */
	_FORCE_INLINE_ Vector2::Axis max_axis_index() const {
		return x < y ? Vector2::AXIS_Y : Vector2::AXIS_X;
	}

	/**
	 * Scales the vector to unit length in place. A zero or non-finite vector becomes zero.
	 */
	void normalize();
	/**
	 * Returns a copy scaled to unit length. A zero or non-finite input yields zero.
	 */
	Vector2 normalized() const;
	/**
	 * Returns `true` if the vector is normalized, i.e. its length is approximately equal to 1.
	 */
	bool is_normalized() const;

	/**
	 * Returns the length (magnitude) of this vector.
	 */
	real_t length() const;
	/**
	 * Returns the sum of the squares of the two components without taking a square root.
	 */
	real_t length_squared() const;
	/**
	 * Returns the vector scaled when its length exceeds the limit. A zero vector stays zero.
	 *
	 * - `p_len` — Maximum length when nonnegative. A negative value reverses a nonzero vector and sets its length to the magnitude of the value.
	 */
	Vector2 limit_length(real_t p_len = 1.0) const;

	/**
	 * Sets every component to zero.
	 */
	void zero() { x = y = 0; }

	/**
	 * Returns each component's smaller value after comparing it with the matching component of the other vector.
	 *
	 * - `p_vector2` — Vector that supplies the other X and Y values.
	 */
	Vector2 min(const Vector2 &p_vector2) const {
		return Vector2(MIN(x, p_vector2.x), MIN(y, p_vector2.y));
	}

	/**
	 * Returns each component's smaller value after comparing it with the same scalar.
	 *
	 * - `p_scalar` — Value compared with both components.
	 */
	Vector2 minf(real_t p_scalar) const {
		return Vector2(MIN(x, p_scalar), MIN(y, p_scalar));
	}

	/**
	 * Returns each component's larger value after comparing it with the matching component of the other vector.
	 *
	 * - `p_vector2` — Vector that supplies the other X and Y values.
	 */
	Vector2 max(const Vector2 &p_vector2) const {
		return Vector2(MAX(x, p_vector2.x), MAX(y, p_vector2.y));
	}

	/**
	 * Returns each component's larger value after comparing it with the same scalar.
	 *
	 * - `p_scalar` — Value compared with both components.
	 */
	Vector2 maxf(real_t p_scalar) const {
		return Vector2(MAX(x, p_scalar), MAX(y, p_scalar));
	}

	/**
	 * Returns the Euclidean distance between the points represented by the two vectors.
	 *
	 * - `p_vector2` — Other point in the same coordinate system.
	 */
	real_t distance_to(const Vector2 &p_vector2) const;
	/**
	 * Returns the squared Euclidean distance between the points represented by the two vectors without
	 * taking a square root.
	 *
	 * - `p_vector2` — Other point in the same coordinate system.
	 */
	real_t distance_squared_to(const Vector2 &p_vector2) const;
	/**
	 * Returns the signed angle in radians from this vector to the other vector. Positive angles turn
	 * clockwise in Godot's 2D canvas coordinates.
	 *
	 * - `p_vector2` — Other direction in the same coordinate system.
	 */
	real_t angle_to(const Vector2 &p_vector2) const;
	/**
	 * Returns the signed angle in radians from the positive X axis to the direction from this point to the
	 * given point.
	 *
	 * - `p_vector2` — Target point in the same coordinate system.
	 */
	real_t angle_to_point(const Vector2 &p_vector2) const;
	/**
	 * Returns a unit vector from this point to the target. Coincident points give the zero vector.
	 *
	 * - `p_to` — Target point in the same coordinate system.
	 */
	_FORCE_INLINE_ Vector2 direction_to(const Vector2 &p_to) const;

	/**
	 * Returns the sum of the products of matching components.
	 *
	 * - `p_other` — Vector multiplied component by component before summing.
	 */
	real_t dot(const Vector2 &p_other) const;
	/**
	 * Returns the scalar cross product, equal to this X times the other Y minus this Y times the other X.
	 *
	 * - `p_other` — Right-hand vector in the cross product.
	 */
	real_t cross(const Vector2 &p_other) const;
	/**
	 * Wraps both components with the same divisor. Nonzero results have the sign of that divisor.
	 *
	 * - `p_mod` — Nonzero divisor used for both components.
	 */
	Vector2 posmod(real_t p_mod) const;
	/**
	 * Wraps each component with its corresponding divisor. Nonzero results have the sign of their divisors.
	 *
	 * - `p_modv` — Vector of nonzero X and Y divisors.
	 */
	Vector2 posmodv(const Vector2 &p_modv) const;
	/**
	 * Returns the part of this vector parallel to the supplied direction.
	 *
	 * - `p_to` — Nonzero direction of the projection. It does not have to be a unit vector.
	 */
	Vector2 project(const Vector2 &p_to) const;

	/**
	 * Projects a point onto the line for which this vector is the unit normal.
	 *
	 * - `p_d` — Signed distance from the origin along the normal.
	 * - `p_vec` — Point to project, in the same coordinate system as the line.
	 */
	Vector2 plane_project(real_t p_d, const Vector2 &p_vec) const;

	/**
	 * Interpolates each component linearly.
	 *
	 * - `p_to` — Target vector at weight one.
	 * - `p_weight` — Interpolation factor. Zero selects this vector and one selects the target.
	 */
	_FORCE_INLINE_ Vector2 lerp(const Vector2 &p_to, real_t p_weight) const;
	/**
	 * Interpolates the direction along the angular displacement and the length linearly. If either vector is zero, uses linear interpolation.
	 *
	 * - `p_to` — Target vector at weight one.
	 * - `p_weight` — Interpolation factor. Zero selects this vector and one selects the target.
	 */
	_FORCE_INLINE_ Vector2 slerp(const Vector2 &p_to, real_t p_weight) const;
	/**
	 * Returns a cubic interpolation with this vector as the first point.
	 *
	 * - `p_b` — Second interpolation point, reached at weight one.
	 * - `p_pre_a` — Control point before this point.
	 * - `p_post_b` — Control point after the second point.
	 * - `p_weight` — Interpolation factor between this point at zero and the second point at one.
	 */
	_FORCE_INLINE_ Vector2 cubic_interpolate(const Vector2 &p_b, const Vector2 &p_pre_a, const Vector2 &p_post_b, real_t p_weight) const;
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
	_FORCE_INLINE_ Vector2 cubic_interpolate_in_time(const Vector2 &p_b, const Vector2 &p_pre_a, const Vector2 &p_post_b, real_t p_weight, real_t p_b_t, real_t p_pre_a_t, real_t p_post_b_t) const;
	/**
	 * Returns the point on the cubic Bézier curve at the supplied curve parameter.
	 *
	 * - `p_control_1` — Control point next to the start.
	 * - `p_control_2` — Control point next to the end.
	 * - `p_end` — End of the curve. This vector is the start.
	 * - `p_t` — Curve parameter. Zero selects the start and one selects the end.
	 */
	_FORCE_INLINE_ Vector2 bezier_interpolate(const Vector2 &p_control_1, const Vector2 &p_control_2, const Vector2 &p_end, real_t p_t) const;
	/**
	 * Returns the derivative of the cubic Bézier curve with respect to its curve parameter.
	 *
	 * - `p_control_1` — Control point next to the start.
	 * - `p_control_2` — Control point next to the end.
	 * - `p_end` — End of the curve. This vector is the start.
	 * - `p_t` — Curve parameter. Zero selects the start and one selects the end.
	 */
	_FORCE_INLINE_ Vector2 bezier_derivative(const Vector2 &p_control_1, const Vector2 &p_control_2, const Vector2 &p_end, real_t p_t) const;

	/**
	 * Moves toward the target by the given distance. Reaches the target if the distance fits in the step or the points are almost coincident.
	 *
	 * - `p_to` — Target point in the same coordinate system.
	 * - `p_delta` — Step length. A negative value moves away unless the points are almost coincident.
	 */
	Vector2 move_toward(const Vector2 &p_to, real_t p_delta) const;

	/**
	 * Removes the component along the normal to leave a vector parallel to the surface.
	 *
	 * - `p_normal` — Unit normal of the surface.
	 */
	Vector2 slide(const Vector2 &p_normal) const;
	/**
	 * Reflects the vector off the surface with the given unit normal. The normal component changes sign and
	 * the tangential component stays the same.
	 *
	 * - `p_normal` — Unit normal of the surface to bounce off.
	 */
	Vector2 bounce(const Vector2 &p_normal) const;
	/**
	 * Reflects the vector across the axis defined by the given unit vector. The parallel component stays
	 * the same and the perpendicular component changes sign.
	 *
	 * - `p_normal` — Unit vector along the reflection axis.
	 */
	Vector2 reflect(const Vector2 &p_normal) const;

	/**
	 * Tests approximate equality separately for X and Y.
	 *
	 * - `p_v` — Vector whose components are compared with this vector.
	 */
	bool is_equal_approx(const Vector2 &p_v) const;
	/**
	 * Tests exact component equality and treats matching NaN components as equal.
	 *
	 * - `p_v` — Vector whose components are compared with this vector.
	 */
	bool is_same(const Vector2 &p_v) const;
	/**
	 * Tests whether both components are within the zero comparison tolerance.
	 */
	bool is_zero_approx() const;
	/**
	 * Returns `true` if this vector is finite, by calling `is_finite()` on each component.
	 */
	bool is_finite() const;

	/**
	 * Adds each component of the `godot::Vector2` by the components of the given `godot::Vector2`.
	 *
	 * - `p_v` — Vector whose components are added.
	 */
	constexpr Vector2 operator+(const Vector2 &p_v) const;
	/**
	 * Adds the right-hand vector to this vector component by component.
	 *
	 * - `p_v` — Vector whose components are added in place.
	 */
	constexpr void operator+=(const Vector2 &p_v);
	/**
	 * Subtracts each component of the `godot::Vector2` by the components of the given `godot::Vector2`.
	 *
	 * - `p_v` — Vector whose components are subtracted.
	 */
	constexpr Vector2 operator-(const Vector2 &p_v) const;
	/**
	 * Subtracts the right-hand vector from this vector component by component.
	 *
	 * - `p_v` — Vector whose components are subtracted in place.
	 */
	constexpr void operator-=(const Vector2 &p_v);
	/**
	 * Multiplies each component of the `godot::Vector2` by the components of the given `godot::Vector2`.
	 *
	 * - `p_v1` — Vector supplying the factor for each component.
	 */
	constexpr Vector2 operator*(const Vector2 &p_v1) const;

	/**
	 * Multiplies each component of the `godot::Vector2` by the given `float`.
	 *
	 * - `p_rvalue` — Scalar multiplied by both components.
	 */
	constexpr Vector2 operator*(real_t p_rvalue) const;
	/**
	 * Multiplies each component by the given scalar in place.
	 *
	 * - `p_rvalue` — Scalar multiplied by both components in place.
	 */
	constexpr void operator*=(real_t p_rvalue);
	/**
	 * Multiplies each component by the corresponding component of the right-hand vector in place.
	 *
	 * - `p_rvalue` — Vector supplying the factor for each component in place.
	 */
	constexpr void operator*=(const Vector2 &p_rvalue) { *this = *this * p_rvalue; }

	/**
	 * Divides each component of the `godot::Vector2` by the components of the given `godot::Vector2`.
	 *
	 * - `p_v1` — Vector supplying the nonzero divisor for each component.
	 */
	constexpr Vector2 operator/(const Vector2 &p_v1) const;

	/**
	 * Divides each component of the `godot::Vector2` by the given `float`.
	 *
	 * - `p_rvalue` — Nonzero divisor applied to both components.
	 */
	constexpr Vector2 operator/(real_t p_rvalue) const;

	/**
	 * Divides each component by the given scalar in place.
	 *
	 * - `p_rvalue` — Nonzero divisor applied to both components in place.
	 */
	constexpr void operator/=(real_t p_rvalue);
	/**
	 * Divides each component by the corresponding component of the right-hand vector in place.
	 *
	 * - `p_rvalue` — Vector supplying the nonzero divisor for each component in place.
	 */
	constexpr void operator/=(const Vector2 &p_rvalue) { *this = *this / p_rvalue; }

	/**
	 * Returns a vector with each component negated.
	 */
	constexpr Vector2 operator-() const;

	/**
	 * Tests exact equality of the components.
	 *
	 * - `p_vec2` — Right-hand vector in the comparison.
	 */
	constexpr bool operator==(const Vector2 &p_vec2) const;
	/**
	 * Tests whether any component differs.
	 *
	 * - `p_vec2` — Right-hand vector in the comparison.
	 */
	constexpr bool operator!=(const Vector2 &p_vec2) const;

	/**
	 * Compares two `godot::Vector2` vectors by first checking if the X value of the left vector is less
	 * than the X value of the `right` vector.
	 *
	 * - `p_vec2` — Right-hand vector in the comparison.
	 */
	constexpr bool operator<(const Vector2 &p_vec2) const { return x == p_vec2.x ? (y < p_vec2.y) : (x < p_vec2.x); }
	/**
	 * Compares two `godot::Vector2` vectors by first checking if the X value of the left vector is greater
	 * than the X value of the `right` vector.
	 *
	 * - `p_vec2` — Right-hand vector in the comparison.
	 */
	constexpr bool operator>(const Vector2 &p_vec2) const { return x == p_vec2.x ? (y > p_vec2.y) : (x > p_vec2.x); }
	/**
	 * Compares two `godot::Vector2` vectors by first checking if the X value of the left vector is less
	 * than or equal to the X value of the `right` vector.
	 *
	 * - `p_vec2` — Right-hand vector in the comparison.
	 */
	constexpr bool operator<=(const Vector2 &p_vec2) const { return x == p_vec2.x ? (y <= p_vec2.y) : (x < p_vec2.x); }
	/**
	 * Compares two `godot::Vector2` vectors by first checking if the X value of the left vector is greater
	 * than or equal to the X value of the `right` vector.
	 *
	 * - `p_vec2` — Right-hand vector in the comparison.
	 */
	constexpr bool operator>=(const Vector2 &p_vec2) const { return x == p_vec2.x ? (y >= p_vec2.y) : (x > p_vec2.x); }

	/**
	 * Returns the signed angle in radians from the positive X axis to the vector. Positive angles turn
	 * clockwise in Godot's 2D canvas coordinates.
	 */
	real_t angle() const;
	/**
	 * Returns the vector with X equal to the cosine and Y equal to the sine of the angle in radians. Its
	 * length is approximately one.
	 *
	 * - `p_angle` — Angle in radians measured from the positive X axis. Positive angles turn clockwise in 2D canvas coordinates.
	 */
	static Vector2 from_angle(real_t p_angle);

	/**
	 * Returns a new vector with all components in absolute values (i.e. positive).
	 */
	_FORCE_INLINE_ Vector2 abs() const {
		return Vector2(Math::abs(x), Math::abs(y));
	}

	/**
	 * Returns the result of rotating this vector by `angle` (in radians).
	 *
	 * - `p_by` — Rotation angle in radians. Positive angles turn clockwise in 2D canvas coordinates.
	 */
	Vector2 rotated(real_t p_by) const;
	/**
	 * Returns a perpendicular vector rotated 90 degrees counter-clockwise compared to the original, with
	 * the same length.
	 */
	Vector2 orthogonal() const {
		return Vector2(y, -x);
	}

	/**
	 * Returns a new vector with each component set to `1.0` if it's positive, `-1.0` if it's negative, and
	 * `0.0` if it's zero. The result is identical to calling `sign()` on each component.
	 */
	Vector2 sign() const;
	/**
	 * Returns a new vector with all components rounded down (towards negative infinity).
	 */
	Vector2 floor() const;
	/**
	 * Returns a new vector with all components rounded up (towards positive infinity).
	 */
	Vector2 ceil() const;
	/**
	 * Returns a new vector with all components rounded to the nearest integer, with halfway cases rounded
	 * away from zero.
	 */
	Vector2 round() const;
	/**
	 * Returns a new vector with each component snapped to the nearest multiple of the corresponding
	 * component in `step`. This can also be used to round the components to an arbitrary number of
	 * decimals.
	 *
	 * - `p_by` — Grid step for each component. A zero step leaves that component unchanged.
	 */
	Vector2 snapped(const Vector2 &p_by) const;
	/**
	 * Returns a new vector with each component snapped to the nearest multiple of `step`. This can also be
	 * used to round the components to an arbitrary number of decimals.
	 *
	 * - `p_by` — Grid step for both components. Zero leaves the vector unchanged.
	 */
	Vector2 snappedf(real_t p_by) const;
	/**
	 * Returns a new vector with all components clamped between the components of `min` and `max`, by
	 * running `clamp()` on each component.
	 *
	 * - `p_min` — Inclusive lower bounds for X and Y.
	 * - `p_max` — Inclusive upper bounds for X and Y.
	 */
	Vector2 clamp(const Vector2 &p_min, const Vector2 &p_max) const;
	/**
	 * Returns a new vector with all components clamped between `min` and `max`, by running `clamp()` on
	 * each component.
	 *
	 * - `p_min` — Inclusive lower bound for both components.
	 * - `p_max` — Inclusive upper bound for both components.
	 */
	Vector2 clampf(real_t p_min, real_t p_max) const;
	/**
	 * Returns this vector's aspect ratio, which is `x` divided by `y`.
	 */
	real_t aspect() const { return width / height; }

	/**
	 * Formats the X and Y components as a parenthesized, comma-separated string.
	 */
	explicit operator String() const;
	/**
	 * Converts each component to an integer by truncating toward zero.
	 */
	operator Vector2i() const;

	/**
	 * Constructs a default-initialized `godot::Vector2` with all components set to `0`.
	 */
	constexpr Vector2() = default;
	/**
	 * Constructs a new `godot::Vector2` from the given `x` and `y`.
	 *
	 * - `p_x` — X component, or width when used as a size.
	 * - `p_y` — Y component, or height when used as a size.
	 */
	constexpr Vector2(real_t p_x, real_t p_y) :
			x(p_x), y(p_y) {}
};

inline constexpr Vector2 Vector2::LEFT = { -1, 0 };
inline constexpr Vector2 Vector2::RIGHT = { 1, 0 };
inline constexpr Vector2 Vector2::UP = { 0, -1 };
inline constexpr Vector2 Vector2::DOWN = { 0, 1 };

_FORCE_INLINE_ Vector2 Vector2::plane_project(real_t p_d, const Vector2 &p_vec) const {
	return p_vec - *this * (dot(p_vec) - p_d);
}

constexpr Vector2 Vector2::operator+(const Vector2 &p_v) const {
	return Vector2(x + p_v.x, y + p_v.y);
}

constexpr void Vector2::operator+=(const Vector2 &p_v) {
	x += p_v.x;
	y += p_v.y;
}

constexpr Vector2 Vector2::operator-(const Vector2 &p_v) const {
	return Vector2(x - p_v.x, y - p_v.y);
}

constexpr void Vector2::operator-=(const Vector2 &p_v) {
	x -= p_v.x;
	y -= p_v.y;
}

constexpr Vector2 Vector2::operator*(const Vector2 &p_v1) const {
	return Vector2(x * p_v1.x, y * p_v1.y);
}

constexpr Vector2 Vector2::operator*(real_t p_rvalue) const {
	return Vector2(x * p_rvalue, y * p_rvalue);
}

constexpr void Vector2::operator*=(real_t p_rvalue) {
	x *= p_rvalue;
	y *= p_rvalue;
}

constexpr Vector2 Vector2::operator/(const Vector2 &p_v1) const {
	return Vector2(x / p_v1.x, y / p_v1.y);
}

constexpr Vector2 Vector2::operator/(real_t p_rvalue) const {
	return Vector2(x / p_rvalue, y / p_rvalue);
}

constexpr void Vector2::operator/=(real_t p_rvalue) {
	x /= p_rvalue;
	y /= p_rvalue;
}

constexpr Vector2 Vector2::operator-() const {
	return Vector2(-x, -y);
}

constexpr bool Vector2::operator==(const Vector2 &p_vec2) const {
	return x == p_vec2.x && y == p_vec2.y;
}

constexpr bool Vector2::operator!=(const Vector2 &p_vec2) const {
	return x != p_vec2.x || y != p_vec2.y;
}

Vector2 Vector2::lerp(const Vector2 &p_to, real_t p_weight) const {
	Vector2 res = *this;
	res.x = Math::lerp(res.x, p_to.x, p_weight);
	res.y = Math::lerp(res.y, p_to.y, p_weight);
	return res;
}

Vector2 Vector2::slerp(const Vector2 &p_to, real_t p_weight) const {
	real_t start_length_sq = length_squared();
	real_t end_length_sq = p_to.length_squared();
	if (unlikely(start_length_sq == 0.0f || end_length_sq == 0.0f)) {
		// Zero length vectors have no angle, so the best we can do is either lerp or throw an error.
		return lerp(p_to, p_weight);
	}
	real_t start_length = Math::sqrt(start_length_sq);
	real_t result_length = Math::lerp(start_length, Math::sqrt(end_length_sq), p_weight);
	real_t angle = angle_to(p_to);
	return rotated(angle * p_weight) * (result_length / start_length);
}

Vector2 Vector2::cubic_interpolate(const Vector2 &p_b, const Vector2 &p_pre_a, const Vector2 &p_post_b, real_t p_weight) const {
	Vector2 res = *this;
	res.x = Math::cubic_interpolate(res.x, p_b.x, p_pre_a.x, p_post_b.x, p_weight);
	res.y = Math::cubic_interpolate(res.y, p_b.y, p_pre_a.y, p_post_b.y, p_weight);
	return res;
}

Vector2 Vector2::cubic_interpolate_in_time(const Vector2 &p_b, const Vector2 &p_pre_a, const Vector2 &p_post_b, real_t p_weight, real_t p_b_t, real_t p_pre_a_t, real_t p_post_b_t) const {
	Vector2 res = *this;
	res.x = Math::cubic_interpolate_in_time(res.x, p_b.x, p_pre_a.x, p_post_b.x, p_weight, p_b_t, p_pre_a_t, p_post_b_t);
	res.y = Math::cubic_interpolate_in_time(res.y, p_b.y, p_pre_a.y, p_post_b.y, p_weight, p_b_t, p_pre_a_t, p_post_b_t);
	return res;
}

Vector2 Vector2::bezier_interpolate(const Vector2 &p_control_1, const Vector2 &p_control_2, const Vector2 &p_end, real_t p_t) const {
	Vector2 res = *this;
	res.x = Math::bezier_interpolate(res.x, p_control_1.x, p_control_2.x, p_end.x, p_t);
	res.y = Math::bezier_interpolate(res.y, p_control_1.y, p_control_2.y, p_end.y, p_t);
	return res;
}

Vector2 Vector2::bezier_derivative(const Vector2 &p_control_1, const Vector2 &p_control_2, const Vector2 &p_end, real_t p_t) const {
	Vector2 res = *this;
	res.x = Math::bezier_derivative(res.x, p_control_1.x, p_control_2.x, p_end.x, p_t);
	res.y = Math::bezier_derivative(res.y, p_control_1.y, p_control_2.y, p_end.y, p_t);
	return res;
}

Vector2 Vector2::direction_to(const Vector2 &p_to) const {
	Vector2 ret(p_to.x - x, p_to.y - y);
	ret.normalize();
	return ret;
}

// Multiplication operators required to workaround issues with LLVM using implicit conversion
// to Vector2i instead for integers where it should not.

/**
 * Returns the vector with all components multiplied by the left-hand scalar.
 *
 * - `p_scalar` — Left-hand factor applied to both components.
 * - `p_vec` — Vector whose components are multiplied.
 */
constexpr Vector2 operator*(float p_scalar, const Vector2 &p_vec) {
	return p_vec * p_scalar;
}

/**
 * Returns the vector with all components multiplied by the left-hand scalar.
 *
 * - `p_scalar` — Left-hand factor applied to both components.
 * - `p_vec` — Vector whose components are multiplied.
 */
constexpr Vector2 operator*(double p_scalar, const Vector2 &p_vec) {
	return p_vec * p_scalar;
}

/**
 * Returns the vector with all components multiplied by the left-hand scalar.
 *
 * - `p_scalar` — Left-hand factor applied to both components.
 * - `p_vec` — Vector whose components are multiplied.
 */
constexpr Vector2 operator*(int32_t p_scalar, const Vector2 &p_vec) {
	return p_vec * p_scalar;
}

/**
 * Returns the vector with all components multiplied by the left-hand scalar.
 *
 * - `p_scalar` — Left-hand factor applied to both components.
 * - `p_vec` — Vector whose components are multiplied.
 */
constexpr Vector2 operator*(int64_t p_scalar, const Vector2 &p_vec) {
	return p_vec * p_scalar;
}

/**
 * Alias for a 2D vector used as a width and height.
 */
typedef Vector2 Size2;
/**
 * Alias for a 2D vector used as a point.
 */
typedef Vector2 Point2;

/**
 * Marks a zero-filled vector as a valid vector with both components equal to zero.
 */
template <>
struct is_zero_constructible<Vector2> : std::true_type {};
} // namespace godot
