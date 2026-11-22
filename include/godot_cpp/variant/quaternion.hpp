/**************************************************************************/
/*  quaternion.hpp                                                        */
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
#include <godot_cpp/core/math.hpp>
#include <godot_cpp/variant/vector3.hpp>

namespace godot {

/**
 * A unit quaternion used for representing 3D rotations.
 */
struct [[nodiscard]] Quaternion {
	/**
	 * The quaternion component along the imaginary i axis.
	 */
	real_t x = 0.0f;
	/**
	 * The quaternion component along the imaginary j axis.
	 */
	real_t y = 0.0f;
	/**
	 * The quaternion component along the imaginary k axis.
	 */
	real_t z = 0.0f;
	/**
	 * The real component of the quaternion.
	 */
	real_t w = 1.0f;

	constexpr real_t &operator[](int p_idx) {
		// The pointer math below assumes that the elements are placed back-to-back, like an array.
		// This is always true in practice, but technically not guaranteed; we safety-check it here.
		static_assert(offsetof(Quaternion, x) == 0 * sizeof(real_t));
		static_assert(offsetof(Quaternion, y) == 1 * sizeof(real_t));
		static_assert(offsetof(Quaternion, z) == 2 * sizeof(real_t));
		static_assert(offsetof(Quaternion, w) == 3 * sizeof(real_t));
		static_assert(sizeof(Quaternion) == 4 * sizeof(real_t));

		DEV_ASSERT((unsigned int)p_idx < 4);
		return (&x)[p_idx];
	}
	constexpr const real_t &operator[](int p_idx) const {
		DEV_ASSERT((unsigned int)p_idx < 4);
		return (&x)[p_idx];
	}

	/**
	 * Returns the sum of squares of the four components without taking a square root.
	 */
	_FORCE_INLINE_ real_t length_squared() const;
	/**
	 * Returns `true` if this quaternion and `to` are approximately equal, by calling `is_equal_approx()` on
	 * each component.
	 */
	bool is_equal_approx(const Quaternion &p_quaternion) const;
	bool is_same(const Quaternion &p_quaternion) const;
	/**
	 * Returns `true` if this quaternion is finite, by calling `is_finite()` on each component.
	 */
	bool is_finite() const;
	/**
	 * Returns this quaternion's length, also called magnitude.
	 */
	real_t length() const;
	void normalize();
	/**
	 * Returns a copy of this quaternion, normalized so that its length is `1.0`. See also
	 * `godot::Quaternion::is_normalized()`.
	 */
	Quaternion normalized() const;
	/**
	 * Returns `true` if this quaternion is normalized.
	 */
	bool is_normalized() const;
	/**
	 * Returns the inverse version of this quaternion, inverting the sign of every component except `w`.
	 */
	Quaternion inverse() const;
	/**
	 * Returns the logarithm of this quaternion. Multiplies this quaternion's rotation axis by its rotation
	 * angle, and stores the result in the returned quaternion's vector part (`x`, `y`, and `z`). The
	 * returned quaternion's real part (`w`) is always `0.0`.
	 */
	Quaternion log() const;
	/**
	 * Returns the exponential of this quaternion. The rotation axis of the result is the normalized
	 * rotation axis of this quaternion, the angle of the result is the length of the vector part of this
	 * quaternion.
	 */
	Quaternion exp() const;
	/**
	 * Returns the dot product between this quaternion and `with`. This is equivalent to `(quat.x * with.x)
	 * + (quat.y * with.y) + (quat.z * with.z) + (quat.w * with.w)`.
	 */
	_FORCE_INLINE_ real_t dot(const Quaternion &p_q) const;
	/**
	 * Returns the angle between this quaternion and `to`. This is the magnitude of the angle you would need
	 * to rotate by to get from one to the other. **Note:** The magnitude of the floating-point error for
	 * this method is abnormally high, so methods such as `is_zero_approx` will not work reliably.
	 */
	real_t angle_to(const Quaternion &p_to) const;

	Vector3 get_euler(EulerOrder p_order = EulerOrder::EULER_ORDER_YXZ) const;
	/**
	 * Creates a rotation quaternion from X, Y, and Z angles in radians using intrinsic YXZ order.
	 */
	static Quaternion from_euler(const Vector3 &p_euler);

	/**
	 * Performs a spherical-linear interpolation with the `to` quaternion, given a `weight` and returns the
	 * result. Both this quaternion and `to` must be normalized.
	 */
	Quaternion slerp(const Quaternion &p_to, real_t p_weight) const;
	/**
	 * Performs a spherical-linear interpolation with the `to` quaternion, given a `weight` and returns the
	 * result. Unlike `godot::Quaternion::slerp()`, this method does not check if the rotation path is
	 * smaller than 90 degrees. Both this quaternion and `to` must be normalized.
	 */
	Quaternion slerpni(const Quaternion &p_to, real_t p_weight) const;
	/**
	 * Performs a spherical cubic interpolation between quaternions `pre_a`, this vector, `b`, and `post_b`,
	 * by the given amount `weight`.
	 */
	Quaternion spherical_cubic_interpolate(const Quaternion &p_b, const Quaternion &p_pre_a, const Quaternion &p_post_b, real_t p_weight) const;
	/**
	 * Performs a spherical cubic interpolation between quaternions `pre_a`, this vector, `b`, and `post_b`,
	 * by the given amount `weight`. It can perform smoother interpolation than
	 * `godot::Quaternion::spherical_cubic_interpolate()` by the time values.
	 */
	Quaternion spherical_cubic_interpolate_in_time(const Quaternion &p_b, const Quaternion &p_pre_a, const Quaternion &p_post_b, real_t p_weight, real_t p_b_t, real_t p_pre_a_t, real_t p_post_b_t) const;

	/**
	 * Returns the rotation axis of the rotation represented by this quaternion.
	 */
	Vector3 get_axis() const;
	/**
	 * Returns the angle of the rotation represented by this quaternion. **Note:** The quaternion must be
	 * normalized.
	 */
	real_t get_angle() const;

	_FORCE_INLINE_ void get_axis_angle(Vector3 &r_axis, real_t &r_angle) const {
		r_angle = 2 * Math::acos(w);
		real_t r = ((real_t)1) / Math::sqrt(1 - w * w);
		r_axis.x = x * r;
		r_axis.y = y * r;
		r_axis.z = z * r;
	}

	constexpr void operator*=(const Quaternion &p_q);
	/**
	 * Composes (multiplies) two quaternions. This rotates the `right` quaternion (the child) by this
	 * quaternion (the parent).
	 */
	constexpr Quaternion operator*(const Quaternion &p_q) const;

	_FORCE_INLINE_ Vector3 xform(const Vector3 &p_v) const {
#ifdef MATH_CHECKS
		ERR_FAIL_COND_V_MSG(!is_normalized(), p_v, "The quaternion " + operator String() + " must be normalized.");
#endif
		Vector3 u(x, y, z);
		Vector3 uv = u.cross(p_v);
		return p_v + ((uv * w) + u.cross(uv)) * ((real_t)2);
	}

	_FORCE_INLINE_ Vector3 xform_inv(const Vector3 &p_v) const {
		return inverse().xform(p_v);
	}

	constexpr void operator+=(const Quaternion &p_q);
	constexpr void operator-=(const Quaternion &p_q);
	constexpr void operator*=(real_t p_s);
	constexpr void operator/=(real_t p_s);
	/**
	 * Adds each component of the left `godot::Quaternion` to the right `godot::Quaternion`. This operation
	 * is not meaningful on its own, but it can be used as a part of a larger expression, such as
	 * approximating an intermediate rotation between two nearby rotations.
	 */
	constexpr Quaternion operator+(const Quaternion &p_q2) const;
	/**
	 * Subtracts each component of the left `godot::Quaternion` by the right `godot::Quaternion`. This
	 * operation is not meaningful on its own, but it can be used as a part of a larger expression.
	 */
	constexpr Quaternion operator-(const Quaternion &p_q2) const;
	constexpr Quaternion operator-() const;
	/**
	 * Multiplies each component of the `godot::Quaternion` by the right `float` value. This operation is
	 * not meaningful on its own, but it can be used as a part of a larger expression.
	 */
	constexpr Quaternion operator*(real_t p_s) const;
	/**
	 * Divides each component of the `godot::Quaternion` by the right `float` value. This operation is not
	 * meaningful on its own, but it can be used as a part of a larger expression.
	 */
	constexpr Quaternion operator/(real_t p_s) const;

	/**
	 * Tests exact equality of the components.
	 */
	constexpr bool operator==(const Quaternion &p_quaternion) const;
	/**
	 * Tests whether any component differs.
	 */
	constexpr bool operator!=(const Quaternion &p_quaternion) const;

	explicit operator String() const;

	constexpr Quaternion() = default;

	/**
	 * Constructs a `godot::Quaternion` defined by the given values. **Note:** Only normalized quaternions
	 * represent rotation; if these values are not normalized, the new `godot::Quaternion` will not be a
	 * valid rotation.
	 */
	constexpr Quaternion(real_t p_x, real_t p_y, real_t p_z, real_t p_w) :
			x(p_x), y(p_y), z(p_z), w(p_w) {}

	/**
	 * Constructs a `godot::Quaternion` representing rotation around the `axis` by the given `angle`, in
	 * radians. The axis must be a normalized vector.
	 */
	Quaternion(const Vector3 &p_axis, real_t p_angle);

	/**
	 * Constructs a `godot::Quaternion` representing the shortest arc between `arc_from` and `arc_to`. These
	 * can be imagined as two points intersecting a sphere's surface, with a radius of `1.0`.
	 */
	Quaternion(const Vector3 &p_v0, const Vector3 &p_v1) { // Shortest arc.
#ifdef MATH_CHECKS
		ERR_FAIL_COND_MSG(p_v0.is_zero_approx() || p_v1.is_zero_approx(), "The vectors must not be zero.");
#endif
#ifdef REAL_T_IS_DOUBLE
		constexpr real_t ALMOST_ONE = 0.999999999999999;
#else
		constexpr real_t ALMOST_ONE = 0.99999975f;
#endif
		Vector3 n0 = p_v0.normalized();
		Vector3 n1 = p_v1.normalized();
		real_t d = n0.dot(n1);
		if (Math::abs(d) > ALMOST_ONE) {
			if (d >= 0) {
				return; // Vectors are same.
			}
			Vector3 axis = n0.get_any_perpendicular();
			x = axis.x;
			y = axis.y;
			z = axis.z;
			w = 0;
		} else {
			Vector3 c = n0.cross(n1);
			real_t s = Math::sqrt((1.0f + d) * 2.0f);
			real_t rs = 1.0f / s;

			x = c.x * rs;
			y = c.y * rs;
			z = c.z * rs;
			w = s * 0.5f;
		}
		normalize();
	}
};

real_t Quaternion::dot(const Quaternion &p_q) const {
	return x * p_q.x + y * p_q.y + z * p_q.z + w * p_q.w;
}

real_t Quaternion::length_squared() const {
	return dot(*this);
}

constexpr void Quaternion::operator+=(const Quaternion &p_q) {
	x += p_q.x;
	y += p_q.y;
	z += p_q.z;
	w += p_q.w;
}

constexpr void Quaternion::operator-=(const Quaternion &p_q) {
	x -= p_q.x;
	y -= p_q.y;
	z -= p_q.z;
	w -= p_q.w;
}

constexpr void Quaternion::operator*=(real_t p_s) {
	x *= p_s;
	y *= p_s;
	z *= p_s;
	w *= p_s;
}

constexpr void Quaternion::operator/=(real_t p_s) {
	*this *= (1 / p_s);
}

constexpr Quaternion Quaternion::operator+(const Quaternion &p_q2) const {
	const Quaternion &q1 = *this;
	return Quaternion(q1.x + p_q2.x, q1.y + p_q2.y, q1.z + p_q2.z, q1.w + p_q2.w);
}

constexpr Quaternion Quaternion::operator-(const Quaternion &p_q2) const {
	const Quaternion &q1 = *this;
	return Quaternion(q1.x - p_q2.x, q1.y - p_q2.y, q1.z - p_q2.z, q1.w - p_q2.w);
}

constexpr Quaternion Quaternion::operator-() const {
	const Quaternion &q2 = *this;
	return Quaternion(-q2.x, -q2.y, -q2.z, -q2.w);
}

constexpr Quaternion Quaternion::operator*(real_t p_s) const {
	return Quaternion(x * p_s, y * p_s, z * p_s, w * p_s);
}

constexpr Quaternion Quaternion::operator/(real_t p_s) const {
	return *this * (1 / p_s);
}

constexpr bool Quaternion::operator==(const Quaternion &p_quaternion) const {
	return x == p_quaternion.x && y == p_quaternion.y && z == p_quaternion.z && w == p_quaternion.w;
}

constexpr bool Quaternion::operator!=(const Quaternion &p_quaternion) const {
	return x != p_quaternion.x || y != p_quaternion.y || z != p_quaternion.z || w != p_quaternion.w;
}

constexpr void Quaternion::operator*=(const Quaternion &p_q) {
	real_t xx = w * p_q.x + x * p_q.w + y * p_q.z - z * p_q.y;
	real_t yy = w * p_q.y + y * p_q.w + z * p_q.x - x * p_q.z;
	real_t zz = w * p_q.z + z * p_q.w + x * p_q.y - y * p_q.x;
	w = w * p_q.w - x * p_q.x - y * p_q.y - z * p_q.z;
	x = xx;
	y = yy;
	z = zz;
}

constexpr Quaternion Quaternion::operator*(const Quaternion &p_q) const {
	Quaternion r = *this;
	r *= p_q;
	return r;
}

constexpr Quaternion operator*(real_t p_real, const Quaternion &p_quaternion) {
	return p_quaternion * p_real;
}

} // namespace godot
