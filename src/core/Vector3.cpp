#include "Vector3.hpp"

#include "String.hpp"

#include <stdlib.h>

#include <cmath>

#include "Basis.hpp"

namespace godot {

Vector3::Vector3(real_t x, real_t y, real_t z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::Vector3() {
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

const real_t &Vector3::operator[](int p_axis) const {
	return coord[p_axis];
}

real_t &Vector3::operator[](int p_axis) {
	return coord[p_axis];
}

Vector3 &Vector3::operator+=(const Vector3 &p_v) {
	x += p_v.x;
	y += p_v.y;
	z += p_v.z;
	return *this;
}

Vector3 Vector3::operator+(const Vector3 &p_v) const {
	Vector3 v = *this;
	v += p_v;
	return v;
}

Vector3 &Vector3::operator-=(const Vector3 &p_v) {
	x -= p_v.x;
	y -= p_v.y;
	z -= p_v.z;
	return *this;
}

Vector3 Vector3::operator-(const Vector3 &p_v) const {
	Vector3 v = *this;
	v -= p_v;
	return v;
}

Vector3 &Vector3::operator*=(const Vector3 &p_v) {
	x *= p_v.x;
	y *= p_v.y;
	z *= p_v.z;
	return *this;
}

Vector3 Vector3::operator*(const Vector3 &p_v) const {
	Vector3 v = *this;
	v *= p_v;
	return v;
}

Vector3 &Vector3::operator/=(const Vector3 &p_v) {
	x /= p_v.x;
	y /= p_v.y;
	z /= p_v.z;
	return *this;
}

Vector3 Vector3::operator/(const Vector3 &p_v) const {
	Vector3 v = *this;
	v /= p_v;
	return v;
}

Vector3 &Vector3::operator*=(real_t p_scalar) {
	*this *= Vector3(p_scalar, p_scalar, p_scalar);
	return *this;
}

Vector3 Vector3::operator*(real_t p_scalar) const {
	Vector3 v = *this;
	v *= p_scalar;
	return v;
}

Vector3 &Vector3::operator/=(real_t p_scalar) {
	*this /= Vector3(p_scalar, p_scalar, p_scalar);
	return *this;
}

Vector3 Vector3::operator/(real_t p_scalar) const {
	Vector3 v = *this;
	v /= p_scalar;
	return v;
}

Vector3 Vector3::operator-() const {
	return Vector3(-x, -y, -z);
}

bool Vector3::operator==(const Vector3 &p_v) const {
	return (x == p_v.x && y == p_v.y && z == p_v.z);
}

bool Vector3::operator!=(const Vector3 &p_v) const {
	return (x != p_v.x || y != p_v.y || z != p_v.z);
}

bool Vector3::operator<(const Vector3 &p_v) const {
	if (x == p_v.x) {
		if (y == p_v.y)
			return z < p_v.z;
		else
			return y < p_v.y;
	} else {
		return x < p_v.x;
	}
}

bool Vector3::operator<=(const Vector3 &p_v) const {
	if (x == p_v.x) {
		if (y == p_v.y)
			return z <= p_v.z;
		else
			return y < p_v.y;
	} else {
		return x < p_v.x;
	}
}

Vector3 Vector3::abs() const {
	return Vector3(::fabs(x), ::fabs(y), ::fabs(z));
}

Vector3 Vector3::ceil() const {
	return Vector3(::ceil(x), ::ceil(y), ::ceil(z));
}

Vector3 Vector3::cross(const Vector3 &b) const {
	Vector3 ret(
			(y * b.z) - (z * b.y),
			(z * b.x) - (x * b.z),
			(x * b.y) - (y * b.x));

	return ret;
}

Vector3 Vector3::linear_interpolate(const Vector3 &p_b, real_t p_t) const {
	return Vector3(
			x + (p_t * (p_b.x - x)),
			y + (p_t * (p_b.y - y)),
			z + (p_t * (p_b.z - z)));
}

Vector3 Vector3::cubic_interpolate(const Vector3 &b, const Vector3 &pre_a, const Vector3 &post_b, const real_t t) const {
	Vector3 p0 = pre_a;
	Vector3 p1 = *this;
	Vector3 p2 = b;
	Vector3 p3 = post_b;

	real_t t2 = t * t;
	real_t t3 = t2 * t;

	Vector3 out;
	out = ((p1 * 2.0) +
				  (-p0 + p2) * t +
				  (p0 * 2.0 - p1 * 5.0 + p2 * 4 - p3) * t2 +
				  (-p0 + p1 * 3.0 - p2 * 3.0 + p3) * t3) *
		  0.5;
	return out;
}

Vector3 Vector3::bounce(const Vector3 &p_normal) const {
	return -reflect(p_normal);
}

real_t Vector3::length() const {
	real_t x2 = x * x;
	real_t y2 = y * y;
	real_t z2 = z * z;

	return ::sqrt(x2 + y2 + z2);
}

real_t Vector3::length_squared() const {
	real_t x2 = x * x;
	real_t y2 = y * y;
	real_t z2 = z * z;

	return x2 + y2 + z2;
}

real_t Vector3::distance_squared_to(const Vector3 &b) const {
	return (b - *this).length_squared();
}

real_t Vector3::distance_to(const Vector3 &b) const {
	return (b - *this).length();
}

real_t Vector3::dot(const Vector3 &b) const {
	return x * b.x + y * b.y + z * b.z;
}

real_t Vector3::angle_to(const Vector3 &b) const {
	return std::atan2(cross(b).length(), dot(b));
}

Vector3 Vector3::floor() const {
	return Vector3(::floor(x), ::floor(y), ::floor(z));
}

Vector3 Vector3::inverse() const {
	return Vector3(1.0 / x, 1.0 / y, 1.0 / z);
}

bool Vector3::is_normalized() const {
	return std::abs(length_squared() - 1.0) < 0.00001;
}

Basis Vector3::outer(const Vector3 &b) const {
	Vector3 row0(x * b.x, x * b.y, x * b.z);
	Vector3 row1(y * b.x, y * b.y, y * b.z);
	Vector3 row2(z * b.x, z * b.y, z * b.z);
	return Basis(row0, row1, row2);
}

int Vector3::max_axis() const {
	return x < y ? (y < z ? 2 : 1) : (x < z ? 2 : 0);
}

int Vector3::min_axis() const {
	return x < y ? (x < z ? 0 : 2) : (y < z ? 1 : 2);
}

void Vector3::normalize() {
	real_t l = length();
	if (l == 0) {
		x = y = z = 0;
	} else {
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

Vector3 Vector3::reflect(const Vector3 &by) const {
	return by - *this * this->dot(by) * 2.0;
}

Vector3 Vector3::rotated(const Vector3 &axis, const real_t phi) const {
	Vector3 v = *this;
	v.rotate(axis, phi);
	return v;
}

void Vector3::rotate(const Vector3 &p_axis, real_t p_phi) {
	*this = Basis(p_axis, p_phi).xform(*this);
}

Vector3 Vector3::slide(const Vector3 &by) const {
	return by - *this * this->dot(by);
}

// this is ugly as well, but hey, I'm a simple man
#define _ugly_stepify(val, step) (step != 0 ? ::floor(val / step + 0.5) * step : val)

void Vector3::snap(real_t p_val) {
	x = _ugly_stepify(x, p_val);
	y = _ugly_stepify(y, p_val);
	z = _ugly_stepify(z, p_val);
}

#undef _ugly_stepify

Vector3 Vector3::snapped(const float by) {
	Vector3 v = *this;
	v.snap(by);
	return v;
}

Vector3::operator String() const {
	return String::num(x) + ", " + String::num(y) + ", " + String::num(z);
}

} // namespace godot
