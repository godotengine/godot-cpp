#ifndef VECTOR3_H
#define VECTOR3_H

#include "Defs.hpp"

#include "String.hpp"

namespace godot {

class Basis;

struct Vector3 {

	enum Axis {
		AXIS_X,
		AXIS_Y,
		AXIS_Z,
	};

	union {
		struct {
			real_t x;
			real_t y;
			real_t z;
		};

		real_t coord[3];
	};

	Vector3(real_t x, real_t y, real_t z);

	Vector3();

	const real_t &operator[](int p_axis) const;

	real_t &operator[](int p_axis);

	Vector3 &operator+=(const Vector3 &p_v);

	Vector3 operator+(const Vector3 &p_v) const;

	Vector3 &operator-=(const Vector3 &p_v);

	Vector3 operator-(const Vector3 &p_v) const;

	Vector3 &operator*=(const Vector3 &p_v);

	Vector3 operator*(const Vector3 &p_v) const;

	Vector3 &operator/=(const Vector3 &p_v);

	Vector3 operator/(const Vector3 &p_v) const;

	Vector3 &operator*=(real_t p_scalar);

	Vector3 operator*(real_t p_scalar) const;

	Vector3 &operator/=(real_t p_scalar);

	Vector3 operator/(real_t p_scalar) const;

	Vector3 operator-() const;

	bool operator==(const Vector3 &p_v) const;

	bool operator!=(const Vector3 &p_v) const;

	bool operator<(const Vector3 &p_v) const;

	bool operator<=(const Vector3 &p_v) const;

	Vector3 abs() const;

	Vector3 ceil() const;

	Vector3 cross(const Vector3 &b) const;

	Vector3 linear_interpolate(const Vector3 &p_b, real_t p_t) const;

	Vector3 cubic_interpolate(const Vector3 &b, const Vector3 &pre_a, const Vector3 &post_b, const real_t t) const;

	Vector3 bounce(const Vector3 &p_normal) const;

	real_t length() const;

	real_t length_squared() const;

	real_t distance_squared_to(const Vector3 &b) const;

	real_t distance_to(const Vector3 &b) const;

	real_t dot(const Vector3 &b) const;

	real_t angle_to(const Vector3 &b) const;

	Vector3 floor() const;

	Vector3 inverse() const;

	bool is_normalized() const;

	Basis outer(const Vector3 &b) const;

	int max_axis() const;

	int min_axis() const;

	void normalize();

	Vector3 normalized() const;

	Vector3 reflect(const Vector3 &by) const;

	Vector3 rotated(const Vector3 &axis, const real_t phi) const;

	void rotate(const Vector3 &p_axis, real_t p_phi);

	Vector3 slide(const Vector3 &by) const;

	void snap(real_t p_val);

	Vector3 snapped(const float by);

	operator String() const;
};

inline Vector3 operator*(real_t p_scalar, const Vector3 &p_vec) {
	return p_vec * p_scalar;
}

inline Vector3 vec3_cross(const Vector3 &p_a, const Vector3 &p_b) {

	return p_a.cross(p_b);
}

} // namespace godot

#endif // VECTOR3_H
