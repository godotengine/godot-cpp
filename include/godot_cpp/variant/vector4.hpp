/**************************************************************************/
/*  vector4.hpp                                                           */
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
struct Vector4i;

/**
 * A 4D vector using floating-point coordinates.
 */
struct [[nodiscard]] Vector4 {
	/**
	 * The number of components in the vector.
	 */
	static constexpr int AXIS_COUNT = 4;

	/**
	 * Component indices accepted by `godot::Vector4::operator[]()`.
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
		/**
		 * Index 3, which selects the W component.
		 */
		AXIS_W,
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
	 * The vector's W component. Also accessible by using the index position `[3]`.
	 */
	real_t w = 0.0f;

	/**
	 * Returns a writable reference to the component at index zero through 3 in X, Y, Z, W order.
	 *
	 * - `p_axis` — Zero-based component index in X, Y, Z, and W order.
	 */
	constexpr real_t &operator[](int p_axis) {
		// The pointer math below assumes that the elements are placed back-to-back, like an array.
		// This is always true in practice, but technically not guaranteed; we safety-check it here.
		static_assert(offsetof(Vector4, x) == 0 * sizeof(real_t));
		static_assert(offsetof(Vector4, y) == 1 * sizeof(real_t));
		static_assert(offsetof(Vector4, z) == 2 * sizeof(real_t));
		static_assert(offsetof(Vector4, w) == 3 * sizeof(real_t));
		static_assert(sizeof(Vector4) == 4 * sizeof(real_t));

		DEV_ASSERT((unsigned int)p_axis < 4);
		return (&x)[p_axis];
	}
	/**
	 * Returns the component at index zero through 3 in X, Y, Z, W order.
	 *
	 * - `p_axis` — Zero-based component index in X, Y, Z, and W order.
	 */
	constexpr const real_t &operator[](int p_axis) const {
		DEV_ASSERT((unsigned int)p_axis < 4);
		return (&x)[p_axis];
	}

	/**
	 * Returns the axis of the vector's lowest value. See `AXIS_*` constants. If all components are equal,
	 * this method returns `godot::Vector4::AXIS_W`.
	 */
	Vector4::Axis min_axis_index() const;
	/**
	 * Returns the axis of the vector's highest value. See `AXIS_*` constants. If all components are equal,
	 * this method returns `godot::Vector4::AXIS_X`.
	 */
	Vector4::Axis max_axis_index() const;

	/**
	 * Returns each component's smaller value after comparing it with the matching component of the other vector.
	 *
	 * - `p_vector4` — Vector that supplies the other X, Y, Z, and W values.
	 */
	Vector4 min(const Vector4 &p_vector4) const {
		return Vector4(MIN(x, p_vector4.x), MIN(y, p_vector4.y), MIN(z, p_vector4.z), MIN(w, p_vector4.w));
	}

	/**
	 * Returns each component's smaller value after comparing it with the same scalar.
	 *
	 * - `p_scalar` — Value compared with every component.
	 */
	Vector4 minf(real_t p_scalar) const {
		return Vector4(MIN(x, p_scalar), MIN(y, p_scalar), MIN(z, p_scalar), MIN(w, p_scalar));
	}

	/**
	 * Returns each component's larger value after comparing it with the matching component of the other vector.
	 *
	 * - `p_vector4` — Vector that supplies the other X, Y, Z, and W values.
	 */
	Vector4 max(const Vector4 &p_vector4) const {
		return Vector4(MAX(x, p_vector4.x), MAX(y, p_vector4.y), MAX(z, p_vector4.z), MAX(w, p_vector4.w));
	}

	/**
	 * Returns each component's larger value after comparing it with the same scalar.
	 *
	 * - `p_scalar` — Value compared with every component.
	 */
	Vector4 maxf(real_t p_scalar) const {
		return Vector4(MAX(x, p_scalar), MAX(y, p_scalar), MAX(z, p_scalar), MAX(w, p_scalar));
	}

	/**
	 * Returns the squared length (squared magnitude) of this vector. This method runs faster than
	 * `godot::Vector4::length()`, so prefer it if you need to compare vectors or need the squared distance
	 * for some formula.
	 */
	_FORCE_INLINE_ real_t length_squared() const;
	/**
	 * Returns `true` if this vector and `to` are approximately equal, by running `is_equal_approx()` on
	 * each component.
	 *
	 * - `p_vec4` — Vector whose components are compared with this vector.
	 */
	bool is_equal_approx(const Vector4 &p_vec4) const;
	/**
	 * Returns `true` if this vector's values are approximately zero, by running `is_zero_approx()` on each
	 * component. This method is faster than using `godot::Vector4::is_equal_approx()` with one value as a
	 * zero vector.
	 */
	bool is_zero_approx() const;
	/**
	 * Tests exact component equality and treats matching NaN components as equal.
	 *
	 * - `p_vec4` — Vector whose components are compared with this vector.
	 */
	bool is_same(const Vector4 &p_vec4) const;
	/**
	 * Returns `true` if this vector is finite, by calling `is_finite()` on each component.
	 */
	bool is_finite() const;
	/**
	 * Returns the length (magnitude) of this vector.
	 */
	real_t length() const;
	/**
	 * Scales the vector to unit length in place. A zero vector stays zero.
	 */
	void normalize();
	/**
	 * Returns the result of scaling the vector to unit length. Equivalent to `v / v.length()`. Returns `(0,
	 * 0, 0, 0)` if `v.length() == 0`.
	 */
	Vector4 normalized() const;
	/**
	 * Returns `true` if the vector is normalized, i.e. its length is approximately equal to 1.
	 */
	bool is_normalized() const;

	/**
	 * Sets every component to zero.
	 */
	void zero() { x = y = z = w = 0; }

	/**
	 * Returns the Euclidean distance between the points represented by the two vectors.
	 *
	 * - `p_to` — Other point in the same coordinate system.
	 */
	real_t distance_to(const Vector4 &p_to) const;
	/**
	 * Returns the squared Euclidean distance between the points represented by the two vectors without
	 * taking a square root.
	 *
	 * - `p_to` — Other point in the same coordinate system.
	 */
	real_t distance_squared_to(const Vector4 &p_to) const;
	/**
	 * Returns the normalized vector pointing from this vector to `to`. This is equivalent to using `(b -
	 * a).normalized()`.
	 *
	 * - `p_to` — Other point in the same coordinate system.
	 */
	Vector4 direction_to(const Vector4 &p_to) const;

	/**
	 * Returns a new vector with all components in absolute values (i.e. positive).
	 */
	Vector4 abs() const;
	/**
	 * Returns a new vector with each component set to `1.0` if it's positive, `-1.0` if it's negative, and
	 * `0.0` if it's zero. The result is identical to calling `sign()` on each component.
	 */
	Vector4 sign() const;
	/**
	 * Returns a new vector with all components rounded down (towards negative infinity).
	 */
	Vector4 floor() const;
	/**
	 * Returns a new vector with all components rounded up (towards positive infinity).
	 */
	Vector4 ceil() const;
	/**
	 * Returns a new vector with all components rounded to the nearest integer, with halfway cases rounded
	 * away from zero.
	 */
	Vector4 round() const;
	/**
	 * Interpolates the components linearly.
	 *
	 * - `p_to` — Target vector at weight one.
	 * - `p_weight` — Interpolation factor. Zero selects this vector and one selects the target.
	 */
	Vector4 lerp(const Vector4 &p_to, real_t p_weight) const;
	/**
	 * Returns a cubic interpolation with this vector as the first point.
	 *
	 * - `p_b` — Second interpolation point, reached at weight one.
	 * - `p_pre_a` — Control point before this point.
	 * - `p_post_b` — Control point after the second point.
	 * - `p_weight` — Interpolation factor between this point at zero and the second point at one.
	 */
	Vector4 cubic_interpolate(const Vector4 &p_b, const Vector4 &p_pre_a, const Vector4 &p_post_b, real_t p_weight) const;
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
	Vector4 cubic_interpolate_in_time(const Vector4 &p_b, const Vector4 &p_pre_a, const Vector4 &p_post_b, real_t p_weight, real_t p_b_t, real_t p_pre_a_t, real_t p_post_b_t) const;

	/**
	 * Wraps all components with the same divisor. Nonzero results have the sign of that divisor.
	 *
	 * - `p_mod` — Nonzero divisor used for every component.
	 */
	Vector4 posmod(real_t p_mod) const;
	/**
	 * Wraps each component with its corresponding divisor. Nonzero results have the sign of their divisors.
	 *
	 * - `p_modv` — Vector of nonzero X, Y, Z, and W divisors.
	 */
	Vector4 posmodv(const Vector4 &p_modv) const;
	/**
	 * Rounds each component to the nearest multiple of the matching step component. A zero step leaves that
	 * component unchanged.
	 *
	 * - `p_step` — Grid spacing for each component. A zero spacing leaves that component unchanged.
	 */
	void snap(const Vector4 &p_step);
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
	Vector4 snapped(const Vector4 &p_step) const;
	/**
	 * Returns a new vector with each component snapped to the nearest multiple of `step`. This can also be
	 * used to round the components to an arbitrary number of decimals.
	 *
	 * - `p_step` — Grid spacing used for every component. Zero leaves the vector unchanged.
	 */
	Vector4 snappedf(real_t p_step) const;
	/**
	 * Returns a new vector with all components clamped between the components of `min` and `max`, by
	 * running `clamp()` on each component.
	 *
	 * - `p_min` — Inclusive lower bounds for X, Y, Z, and W.
	 * - `p_max` — Inclusive upper bounds for X, Y, Z, and W.
	 */
	Vector4 clamp(const Vector4 &p_min, const Vector4 &p_max) const;
	/**
	 * Returns a new vector with all components clamped between `min` and `max`, by running `clamp()` on
	 * each component.
	 *
	 * - `p_min` — Inclusive lower bound used for every component.
	 * - `p_max` — Inclusive upper bound used for every component.
	 */
	Vector4 clampf(real_t p_min, real_t p_max) const;

	/**
	 * Returns the inverse of the vector. This is the same as `Vector4(1.0 / v.x, 1.0 / v.y, 1.0 / v.z, 1.0
	 * / v.w)`.
	 */
	Vector4 inverse() const;
	/**
	 * Returns the dot product of this vector and `with`.
	 *
	 * - `p_vec4` — Vector multiplied component by component before summing.
	 */
	_FORCE_INLINE_ real_t dot(const Vector4 &p_vec4) const;

	/**
	 * Adds the right-hand vector to this vector component by component.
	 *
	 * - `p_vec4` — Vector whose components are added in place.
	 */
	constexpr void operator+=(const Vector4 &p_vec4);
	/**
	 * Subtracts the right-hand vector from this vector component by component.
	 *
	 * - `p_vec4` — Vector whose components are subtracted in place.
	 */
	constexpr void operator-=(const Vector4 &p_vec4);
	/**
	 * Multiplies each component by the corresponding component of the right-hand vector in place.
	 *
	 * - `p_vec4` — Vector that supplies a factor for each component.
	 */
	constexpr void operator*=(const Vector4 &p_vec4);
	/**
	 * Divides each component by the corresponding component of the right-hand vector in place.
	 *
	 * - `p_vec4` — Vector that supplies a nonzero divisor for each component.
	 */
	constexpr void operator/=(const Vector4 &p_vec4);
	/**
	 * Multiplies each component by the given scalar in place.
	 *
	 * - `p_s` — Factor applied to every component.
	 */
	constexpr void operator*=(real_t p_s);
	/**
	 * Divides each component by the given scalar in place.
	 *
	 * - `p_s` — Nonzero divisor applied to every component.
	 */
	constexpr void operator/=(real_t p_s);
	/**
	 * Adds each component of the `godot::Vector4` by the components of the given `godot::Vector4`.
	 *
	 * - `p_vec4` — Vector whose components are added.
	 */
	constexpr Vector4 operator+(const Vector4 &p_vec4) const;
	/**
	 * Subtracts each component of the `godot::Vector4` by the components of the given `godot::Vector4`.
	 *
	 * - `p_vec4` — Vector whose components are subtracted.
	 */
	constexpr Vector4 operator-(const Vector4 &p_vec4) const;
	/**
	 * Multiplies each component of the `godot::Vector4` by the components of the given `godot::Vector4`.
	 *
	 * - `p_vec4` — Vector that supplies a factor for each component.
	 */
	constexpr Vector4 operator*(const Vector4 &p_vec4) const;
	/**
	 * Divides each component of the `godot::Vector4` by the components of the given `godot::Vector4`.
	 *
	 * - `p_vec4` — Vector that supplies a nonzero divisor for each component.
	 */
	constexpr Vector4 operator/(const Vector4 &p_vec4) const;
	/**
	 * Returns a vector with each component negated.
	 */
	constexpr Vector4 operator-() const;
	/**
	 * Multiplies each component of the `godot::Vector4` by the given `float`.
	 *
	 * - `p_s` — Factor applied to every component.
	 */
	constexpr Vector4 operator*(real_t p_s) const;
	/**
	 * Divides each component of the `godot::Vector4` by the given `float`.
	 *
	 * - `p_s` — Nonzero divisor applied to every component.
	 */
	constexpr Vector4 operator/(real_t p_s) const;

	/**
	 * Tests exact equality of the components.
	 *
	 * - `p_vec4` — Right-hand vector in the comparison.
	 */
	constexpr bool operator==(const Vector4 &p_vec4) const;
	/**
	 * Tests whether any component differs.
	 *
	 * - `p_vec4` — Right-hand vector in the comparison.
	 */
	constexpr bool operator!=(const Vector4 &p_vec4) const;
	/**
	 * Compares two `godot::Vector4` vectors by first checking if the X value of the left vector is greater
	 * than the X value of the `right` vector.
	 *
	 * - `p_vec4` — Right-hand vector in the comparison.
	 */
	constexpr bool operator>(const Vector4 &p_vec4) const;
	/**
	 * Compares two `godot::Vector4` vectors by first checking if the X value of the left vector is less
	 * than the X value of the `right` vector.
	 *
	 * - `p_vec4` — Right-hand vector in the comparison.
	 */
	constexpr bool operator<(const Vector4 &p_vec4) const;
	/**
	 * Compares two `godot::Vector4` vectors by first checking if the X value of the left vector is greater
	 * than or equal to the X value of the `right` vector.
	 *
	 * - `p_vec4` — Right-hand vector in the comparison.
	 */
	constexpr bool operator>=(const Vector4 &p_vec4) const;
	/**
	 * Compares two `godot::Vector4` vectors by first checking if the X value of the left vector is less
	 * than or equal to the X value of the `right` vector.
	 *
	 * - `p_vec4` — Right-hand vector in the comparison.
	 */
	constexpr bool operator<=(const Vector4 &p_vec4) const;

	/**
	 * Formats X, Y, Z, and W as a parenthesized, comma-separated string.
	 */
	explicit operator String() const;
	operator Vector4i() const;

	/**
	 * Constructs a default-initialized `godot::Vector4` with all components set to `0`.
	 */
	constexpr Vector4() = default;
	/**
	 * Returns a `godot::Vector4` with the given components.
	 *
	 * - `p_x` — X component.
	 * - `p_y` — Y component.
	 * - `p_z` — Z component.
	 * - `p_w` — W component.
	 */
	constexpr Vector4(real_t p_x, real_t p_y, real_t p_z, real_t p_w) :
			x(p_x), y(p_y), z(p_z), w(p_w) {}
};

real_t Vector4::dot(const Vector4 &p_vec4) const {
	return x * p_vec4.x + y * p_vec4.y + z * p_vec4.z + w * p_vec4.w;
}

real_t Vector4::length_squared() const {
	return dot(*this);
}

constexpr void Vector4::operator+=(const Vector4 &p_vec4) {
	x += p_vec4.x;
	y += p_vec4.y;
	z += p_vec4.z;
	w += p_vec4.w;
}

constexpr void Vector4::operator-=(const Vector4 &p_vec4) {
	x -= p_vec4.x;
	y -= p_vec4.y;
	z -= p_vec4.z;
	w -= p_vec4.w;
}

constexpr void Vector4::operator*=(const Vector4 &p_vec4) {
	x *= p_vec4.x;
	y *= p_vec4.y;
	z *= p_vec4.z;
	w *= p_vec4.w;
}

constexpr void Vector4::operator/=(const Vector4 &p_vec4) {
	x /= p_vec4.x;
	y /= p_vec4.y;
	z /= p_vec4.z;
	w /= p_vec4.w;
}
constexpr void Vector4::operator*=(real_t p_s) {
	x *= p_s;
	y *= p_s;
	z *= p_s;
	w *= p_s;
}

constexpr void Vector4::operator/=(real_t p_s) {
	x /= p_s;
	y /= p_s;
	z /= p_s;
	w /= p_s;
}

constexpr Vector4 Vector4::operator+(const Vector4 &p_vec4) const {
	return Vector4(x + p_vec4.x, y + p_vec4.y, z + p_vec4.z, w + p_vec4.w);
}

constexpr Vector4 Vector4::operator-(const Vector4 &p_vec4) const {
	return Vector4(x - p_vec4.x, y - p_vec4.y, z - p_vec4.z, w - p_vec4.w);
}

constexpr Vector4 Vector4::operator*(const Vector4 &p_vec4) const {
	return Vector4(x * p_vec4.x, y * p_vec4.y, z * p_vec4.z, w * p_vec4.w);
}

constexpr Vector4 Vector4::operator/(const Vector4 &p_vec4) const {
	return Vector4(x / p_vec4.x, y / p_vec4.y, z / p_vec4.z, w / p_vec4.w);
}

constexpr Vector4 Vector4::operator-() const {
	return Vector4(-x, -y, -z, -w);
}

constexpr Vector4 Vector4::operator*(real_t p_s) const {
	return Vector4(x * p_s, y * p_s, z * p_s, w * p_s);
}

constexpr Vector4 Vector4::operator/(real_t p_s) const {
	return Vector4(x / p_s, y / p_s, z / p_s, w / p_s);
}

constexpr bool Vector4::operator==(const Vector4 &p_vec4) const {
	return x == p_vec4.x && y == p_vec4.y && z == p_vec4.z && w == p_vec4.w;
}

constexpr bool Vector4::operator!=(const Vector4 &p_vec4) const {
	return x != p_vec4.x || y != p_vec4.y || z != p_vec4.z || w != p_vec4.w;
}

constexpr bool Vector4::operator<(const Vector4 &p_v) const {
	if (x == p_v.x) {
		if (y == p_v.y) {
			if (z == p_v.z) {
				return w < p_v.w;
			}
			return z < p_v.z;
		}
		return y < p_v.y;
	}
	return x < p_v.x;
}

constexpr bool Vector4::operator>(const Vector4 &p_v) const {
	if (x == p_v.x) {
		if (y == p_v.y) {
			if (z == p_v.z) {
				return w > p_v.w;
			}
			return z > p_v.z;
		}
		return y > p_v.y;
	}
	return x > p_v.x;
}

constexpr bool Vector4::operator<=(const Vector4 &p_v) const {
	if (x == p_v.x) {
		if (y == p_v.y) {
			if (z == p_v.z) {
				return w <= p_v.w;
			}
			return z < p_v.z;
		}
		return y < p_v.y;
	}
	return x < p_v.x;
}

constexpr bool Vector4::operator>=(const Vector4 &p_v) const {
	if (x == p_v.x) {
		if (y == p_v.y) {
			if (z == p_v.z) {
				return w >= p_v.w;
			}
			return z > p_v.z;
		}
		return y > p_v.y;
	}
	return x > p_v.x;
}

/**
 * Returns the vector with all components multiplied by the left-hand scalar.
 *
 * - `p_scalar` — Left-hand factor applied to every component.
 * - `p_vec` — Vector whose components are multiplied.
 */
constexpr Vector4 operator*(float p_scalar, const Vector4 &p_vec) {
	return p_vec * p_scalar;
}

/**
 * Returns the vector with all components multiplied by the left-hand scalar.
 *
 * - `p_scalar` — Left-hand factor applied to every component.
 * - `p_vec` — Vector whose components are multiplied.
 */
constexpr Vector4 operator*(double p_scalar, const Vector4 &p_vec) {
	return p_vec * p_scalar;
}

/**
 * Returns the vector with all components multiplied by the left-hand scalar.
 *
 * - `p_scalar` — Left-hand factor applied to every component.
 * - `p_vec` — Vector whose components are multiplied.
 */
constexpr Vector4 operator*(int32_t p_scalar, const Vector4 &p_vec) {
	return p_vec * p_scalar;
}

/**
 * Returns the vector with all components multiplied by the left-hand scalar.
 *
 * - `p_scalar` — Left-hand factor applied to every component.
 * - `p_vec` — Vector whose components are multiplied.
 */
constexpr Vector4 operator*(int64_t p_scalar, const Vector4 &p_vec) {
	return p_vec * p_scalar;
}

/**
 * Marks a zero-filled vector as a valid vector with all components equal to zero.
 */
template <>
struct is_zero_constructible<Vector4> : std::true_type {};
} // namespace godot
