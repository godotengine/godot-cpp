/*************************************************************************/
/*  quaternion.hpp                                                       */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2022 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2022 Godot Engine contributors (cf. AUTHORS.md).   */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#ifndef GODOT_QUAT_HPP
#define GODOT_QUAT_HPP

#include <godot_cpp/core/math.hpp>
#include <godot_cpp/variant/vector3.hpp>

namespace godot {

class Quaternion {
	_FORCE_INLINE_ GDNativeTypePtr _native_ptr() const { return (void *)this; }

	friend class Variant;

public:
	union {
		struct {
			real_t x;
			real_t y;
			real_t z;
			real_t w;
		};
		real_t components[4] = { 0, 0, 0, 1.0 };
	};

	inline real_t &operator[](int idx) {
		return components[idx];
	}
	inline const real_t &operator[](int idx) const {
		return components[idx];
	}
	inline real_t length_squared() const;
	bool is_equal_approx(const Quaternion &p_quat) const;
	real_t length() const;
	void normalize();
	Quaternion normalized() const;
	bool is_normalized() const;
	Quaternion inverse() const;
	inline real_t dot(const Quaternion &p_q) const;

	Vector3 get_euler_xyz() const;
	Vector3 get_euler_yxz() const;
	Vector3 get_euler() const { return get_euler_yxz(); };

	Quaternion slerp(const Quaternion &p_to, const real_t &p_weight) const;
	Quaternion slerpni(const Quaternion &p_to, const real_t &p_weight) const;
	Quaternion cubic_slerp(const Quaternion &p_b, const Quaternion &p_pre_a, const Quaternion &p_post_b, const real_t &p_weight) const;

	inline void get_axis_angle(Vector3 &r_axis, real_t &r_angle) const {
		r_angle = 2 * Math::acos(w);
		real_t r = ((real_t)1) / Math::sqrt(1 - w * w);
		r_axis.x = x * r;
		r_axis.y = y * r;
		r_axis.z = z * r;
	}

	void operator*=(const Quaternion &p_q);
	Quaternion operator*(const Quaternion &p_q) const;

	Quaternion operator*(const Vector3 &v) const {
		return Quaternion(w * v.x + y * v.z - z * v.y,
				w * v.y + z * v.x - x * v.z,
				w * v.z + x * v.y - y * v.x,
				-x * v.x - y * v.y - z * v.z);
	}

	inline Vector3 xform(const Vector3 &v) const {
#ifdef MATH_CHECKS
		ERR_FAIL_COND_V(!is_normalized(), v);
#endif
		Vector3 u(x, y, z);
		Vector3 uv = u.cross(v);
		return v + ((uv * w) + u.cross(uv)) * ((real_t)2);
	}

	inline Vector3 xform_inv(const Vector3 &v) const {
		return inverse().xform(v);
	}

	inline void operator+=(const Quaternion &p_q);
	inline void operator-=(const Quaternion &p_q);
	inline void operator*=(const real_t &s);
	inline void operator/=(const real_t &s);
	inline Quaternion operator+(const Quaternion &q2) const;
	inline Quaternion operator-(const Quaternion &q2) const;
	inline Quaternion operator-() const;
	inline Quaternion operator*(const real_t &s) const;
	inline Quaternion operator/(const real_t &s) const;

	inline bool operator==(const Quaternion &p_quat) const;
	inline bool operator!=(const Quaternion &p_quat) const;

	operator String() const;

	inline Quaternion() {}

	inline Quaternion(real_t p_x, real_t p_y, real_t p_z, real_t p_w) :
			x(p_x),
			y(p_y),
			z(p_z),
			w(p_w) {
	}

	Quaternion(const Vector3 &p_axis, real_t p_angle);

	Quaternion(const Vector3 &p_euler);

	Quaternion(const Quaternion &p_q) :
			x(p_q.x),
			y(p_q.y),
			z(p_q.z),
			w(p_q.w) {
	}

	Quaternion &operator=(const Quaternion &p_q) {
		x = p_q.x;
		y = p_q.y;
		z = p_q.z;
		w = p_q.w;
		return *this;
	}

	Quaternion(const Vector3 &v0, const Vector3 &v1) // shortest arc
	{
		Vector3 c = v0.cross(v1);
		real_t d = v0.dot(v1);

		if (d < (real_t)-1.0 + CMP_EPSILON) {
			x = (real_t)0.0;
			y = (real_t)1.0;
			z = (real_t)0.0;
			w = (real_t)0.0;
		} else {
			real_t s = Math::sqrt(((real_t)1.0 + d) * (real_t)2.0);
			real_t rs = (real_t)1.0 / s;

			x = c.x * rs;
			y = c.y * rs;
			z = c.z * rs;
			w = s * (real_t)0.5;
		}
	}
};

real_t Quaternion::dot(const Quaternion &p_q) const {
	return x * p_q.x + y * p_q.y + z * p_q.z + w * p_q.w;
}

real_t Quaternion::length_squared() const {
	return dot(*this);
}

void Quaternion::operator+=(const Quaternion &p_q) {
	x += p_q.x;
	y += p_q.y;
	z += p_q.z;
	w += p_q.w;
}

void Quaternion::operator-=(const Quaternion &p_q) {
	x -= p_q.x;
	y -= p_q.y;
	z -= p_q.z;
	w -= p_q.w;
}

void Quaternion::operator*=(const real_t &s) {
	x *= s;
	y *= s;
	z *= s;
	w *= s;
}

void Quaternion::operator/=(const real_t &s) {
	*this *= (real_t)1.0 / s;
}

Quaternion Quaternion::operator+(const Quaternion &q2) const {
	const Quaternion &q1 = *this;
	return Quaternion(q1.x + q2.x, q1.y + q2.y, q1.z + q2.z, q1.w + q2.w);
}

Quaternion Quaternion::operator-(const Quaternion &q2) const {
	const Quaternion &q1 = *this;
	return Quaternion(q1.x - q2.x, q1.y - q2.y, q1.z - q2.z, q1.w - q2.w);
}

Quaternion Quaternion::operator-() const {
	const Quaternion &q2 = *this;
	return Quaternion(-q2.x, -q2.y, -q2.z, -q2.w);
}

Quaternion Quaternion::operator*(const real_t &s) const {
	return Quaternion(x * s, y * s, z * s, w * s);
}

Quaternion Quaternion::operator/(const real_t &s) const {
	return *this * ((real_t)1.0 / s);
}

bool Quaternion::operator==(const Quaternion &p_quat) const {
	return x == p_quat.x && y == p_quat.y && z == p_quat.z && w == p_quat.w;
}

bool Quaternion::operator!=(const Quaternion &p_quat) const {
	return x != p_quat.x || y != p_quat.y || z != p_quat.z || w != p_quat.w;
}

inline Quaternion operator*(const real_t &p_real, const Quaternion &p_quat) {
	return p_quat * p_real;
}

} // namespace godot

#endif // GODOT_QUAT_HPP
