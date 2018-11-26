#ifndef VECTOR2_H
#define VECTOR2_H

#include <gdnative/vector2.h>

#include "Defs.hpp"

namespace godot {

class String;

struct Vector2 {

	union {
		real_t x;
		real_t width;
	};
	union {
		real_t y;
		real_t height;
	};

	inline real_t &operator[](int p_idx) {
		return p_idx ? y : x;
	}
	inline const real_t &operator[](int p_idx) const {
		return p_idx ? y : x;
	}

	Vector2 operator+(const Vector2 &p_v) const;

	void operator+=(const Vector2 &p_v);

	Vector2 operator-(const Vector2 &p_v) const;

	void operator-=(const Vector2 &p_v);

	Vector2 operator*(const Vector2 &p_v1) const;

	Vector2 operator*(const real_t &rvalue) const;

	void operator*=(const real_t &rvalue);

	inline void operator*=(const Vector2 &rvalue) { *this = *this * rvalue; }

	Vector2 operator/(const Vector2 &p_v1) const;

	Vector2 operator/(const real_t &rvalue) const;

	void operator/=(const real_t &rvalue);

	Vector2 operator-() const;

	bool operator==(const Vector2 &p_vec2) const;

	bool operator!=(const Vector2 &p_vec2) const;

	inline bool operator<(const Vector2 &p_vec2) const { return (x == p_vec2.x) ? (y < p_vec2.y) : (x < p_vec2.x); }
	inline bool operator<=(const Vector2 &p_vec2) const { return (x == p_vec2.x) ? (y <= p_vec2.y) : (x <= p_vec2.x); }

	void normalize();

	Vector2 normalized() const;

	real_t length() const;
	real_t length_squared() const;

	real_t distance_to(const Vector2 &p_vector2) const;
	real_t distance_squared_to(const Vector2 &p_vector2) const;

	real_t angle_to(const Vector2 &p_vector2) const;
	real_t angle_to_point(const Vector2 &p_vector2) const;

	real_t dot(const Vector2 &p_other) const;

	real_t cross(const Vector2 &p_other) const;
	Vector2 cross(real_t p_other) const;

	Vector2 project(const Vector2 &p_vec) const;

	Vector2 plane_project(real_t p_d, const Vector2 &p_vec) const;

	Vector2 clamped(real_t p_len) const;

	static Vector2 linear_interpolate(const Vector2 &p_a, const Vector2 &p_b, real_t p_t);

	Vector2 linear_interpolate(const Vector2 &p_b, real_t p_t) const;
	Vector2 cubic_interpolate(const Vector2 &p_b, const Vector2 &p_pre_a, const Vector2 &p_post_b, real_t p_t) const;

	Vector2 slide(const Vector2 &p_vec) const;

	Vector2 reflect(const Vector2 &p_vec) const;

	real_t angle() const;

	void set_rotation(real_t p_radians);

	Vector2 abs() const;
	Vector2 rotated(real_t p_by) const;

	Vector2 tangent() const;

	Vector2 floor() const;

	Vector2 snapped(const Vector2 &p_by) const;
	inline real_t aspect() const { return width / height; }

	operator String() const;

	inline Vector2(real_t p_x, real_t p_y) {
		x = p_x;
		y = p_y;
	}
	inline Vector2() {
		x = 0;
		y = 0;
	}
};

inline Vector2 operator*(real_t p_scalar, const Vector2 &p_vec) {
	return p_vec * p_scalar;
}

} // namespace godot

#endif // VECTOR2_H
