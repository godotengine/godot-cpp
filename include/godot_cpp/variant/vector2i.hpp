/*************************************************************************/
/*  vector2i.hpp                                                         */
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

#ifndef GODOT_VECTOR2I_HPP
#define GODOT_VECTOR2I_HPP

#include <godot_cpp/core/math.hpp>

namespace godot {

class String;
class Vector2;

class Vector2i {
	_FORCE_INLINE_ GDNativeTypePtr _native_ptr() const { return (void *)this; }

	friend class Variant;

public:
	enum Axis {
		AXIS_X,
		AXIS_Y,
	};

	union {
		int32_t x = 0;
		int32_t width;
	};
	union {
		int32_t y = 0;
		int32_t height;
	};

	inline int32_t &operator[](int p_idx) {
		return p_idx ? y : x;
	}
	inline const int32_t &operator[](int p_idx) const {
		return p_idx ? y : x;
	}

	Vector2i operator+(const Vector2i &p_v) const;
	void operator+=(const Vector2i &p_v);
	Vector2i operator-(const Vector2i &p_v) const;
	void operator-=(const Vector2i &p_v);
	Vector2i operator*(const Vector2i &p_v1) const;

	Vector2i operator*(const int32_t &rvalue) const;
	void operator*=(const int32_t &rvalue);

	Vector2i operator/(const Vector2i &p_v1) const;
	Vector2i operator/(const int32_t &rvalue) const;
	void operator/=(const int32_t &rvalue);

	Vector2i operator%(const Vector2i &p_v1) const;
	Vector2i operator%(const int32_t &rvalue) const;
	void operator%=(const int32_t &rvalue);

	Vector2i operator-() const;
	bool operator<(const Vector2i &p_vec2) const { return (x == p_vec2.x) ? (y < p_vec2.y) : (x < p_vec2.x); }
	bool operator>(const Vector2i &p_vec2) const { return (x == p_vec2.x) ? (y > p_vec2.y) : (x > p_vec2.x); }

	bool operator<=(const Vector2i &p_vec2) const { return x == p_vec2.x ? (y <= p_vec2.y) : (x < p_vec2.x); }
	bool operator>=(const Vector2i &p_vec2) const { return x == p_vec2.x ? (y >= p_vec2.y) : (x > p_vec2.x); }

	bool operator==(const Vector2i &p_vec2) const;
	bool operator!=(const Vector2i &p_vec2) const;

	real_t aspect() const { return width / (real_t)height; }
	Vector2i sign() const { return Vector2i(Math::sign(x), Math::sign(y)); }
	Vector2i abs() const { return Vector2i(Math::abs(x), Math::abs(y)); }

	operator String() const;
	operator Vector2() const;

	inline Vector2i() {}
	inline Vector2i(int32_t p_x, int32_t p_y) {
		x = p_x;
		y = p_y;
	}
};

inline Vector2i operator*(const int32_t &p_scalar, const Vector2i &p_vector) {
	return p_vector * p_scalar;
}

inline Vector2i operator*(const int64_t &p_scalar, const Vector2i &p_vector) {
	return p_vector * (int32_t)p_scalar;
}

inline Vector2i operator*(const float &p_scalar, const Vector2i &p_vector) {
	float x = (float)p_vector.x * p_scalar;
	float y = (float)p_vector.y * p_scalar;
	return Vector2i((int32_t)round(x), (int32_t)round(y));
}

inline Vector2i operator*(const double &p_scalar, const Vector2i &p_vector) {
	double x = (double)p_vector.x * p_scalar;
	double y = (double)p_vector.y * p_scalar;
	return Vector2i((int32_t)round(x), (int32_t)round(y));
}

typedef Vector2i Size2i;
typedef Vector2i Point2i;

} // namespace godot

#endif // GODOT_VECTOR2I_HPP
