#ifndef QUAT_H
#define QUAT_H

#include <cmath>

#include "Vector3.h"

namespace godot {

#define CMP_EPSILON 0.00001

typedef float real_t;

class Quat{
public:

	real_t x,y,z,w;

	real_t length_squared() const;
	real_t length() const;
	void normalize();
	Quat normalized() const;
	Quat inverse() const;
	real_t dot(const Quat& q) const;
	void set_euler(const Vector3& p_euler);
	Vector3 get_euler() const;
	Quat slerp(const Quat& q, const real_t& t) const;
	Quat slerpni(const Quat& q, const real_t& t) const;
	Quat cubic_slerp(const Quat& q, const Quat& prep, const Quat& postq,const real_t& t) const;

	void get_axis_and_angle(Vector3& r_axis, real_t &r_angle) const {
		r_angle = 2 * ::acos(w);
		r_axis.x = x / ::sqrt(1-w*w);
		r_axis.y = y / ::sqrt(1-w*w);
		r_axis.z = z / ::sqrt(1-w*w);
	}

	void operator*=(const Quat& q);
	Quat operator*(const Quat& q) const;



	Quat operator*(const Vector3& v) const
	{
		return Quat( w * v.x + y * v.z - z * v.y,
			w * v.y + z * v.x - x * v.z,
			w * v.z + x * v.y - y * v.x,
			-x * v.x - y * v.y - z * v.z);
	}

	Vector3 xform(const Vector3& v) const {

		Quat q = *this * v;
		q *= this->inverse();
		return Vector3(q.x,q.y,q.z);
	}

	void operator+=(const Quat& q);
	void operator-=(const Quat& q);
	void operator*=(const real_t& s);
	void operator/=(const real_t& s);
	Quat operator+(const Quat& q2) const;
	Quat operator-(const Quat& q2) const;
	Quat operator-() const;
	Quat operator*(const real_t& s) const;
	Quat operator/(const real_t& s) const;


	bool operator==(const Quat& p_quat) const;
	bool operator!=(const Quat& p_quat) const;

	operator String() const;

	inline void set( real_t p_x, real_t p_y, real_t p_z, real_t p_w) {
		x=p_x; y=p_y; z=p_z; w=p_w;
	}
	inline Quat(real_t p_x, real_t p_y, real_t p_z, real_t p_w) {
		x=p_x; y=p_y; z=p_z; w=p_w;
	}
	Quat(const Vector3& axis, const real_t& angle);

	Quat(const Vector3& v0, const Vector3& v1) // shortest arc
	{
		Vector3 c = v0.cross(v1);
		real_t  d = v0.dot(v1);

		if (d < -1.0 + CMP_EPSILON) {
			x=0;
			y=1;
			z=0;
			w=0;
		} else {

			real_t  s = ::sqrt((1.0 + d) * 2.0);
			real_t rs = 1.0 / s;

			x=c.x*rs;
			y=c.y*rs;
			z=c.z*rs;
			w=s * 0.5;
		}
	}

	inline Quat() {x=y=z=0; w=1; }


};


real_t Quat::dot(const Quat& q) const {
	return x * q.x+y * q.y+z * q.z+w * q.w;
}

real_t Quat::length_squared() const {
	return dot(*this);
}

void Quat::operator+=(const Quat& q) {
	x += q.x; y += q.y; z += q.z; w += q.w;
}

void Quat::operator-=(const Quat& q) {
	x -= q.x; y -= q.y; z -= q.z; w -= q.w;
}

void Quat::operator*=(const real_t& s) {
	x *= s; y *= s; z *= s; w *= s;
}


void Quat::operator/=(const real_t& s) {

	*this *= 1.0 / s;
}

Quat Quat::operator+(const Quat& q2) const {
	const Quat& q1 = *this;
	return Quat( q1.x+q2.x, q1.y+q2.y, q1.z+q2.z, q1.w+q2.w );
}

Quat Quat::operator-(const Quat& q2) const {
	const Quat& q1 = *this;
	return Quat( q1.x-q2.x, q1.y-q2.y, q1.z-q2.z, q1.w-q2.w);
}

Quat Quat::operator-() const {
	const Quat& q2 = *this;
	return Quat( -q2.x, -q2.y,  -q2.z,  -q2.w);
}

Quat Quat::operator*(const real_t& s) const {
	return Quat(x * s, y * s, z * s, w * s);
}

Quat Quat::operator/(const real_t& s) const {
	return *this * (1.0 / s);
}


bool Quat::operator==(const Quat& p_quat) const {
	return x==p_quat.x && y==p_quat.y && z==p_quat.z && w==p_quat.w;
}

bool Quat::operator!=(const Quat& p_quat) const {
	return x!=p_quat.x || y!=p_quat.y || z!=p_quat.z || w!=p_quat.w;
}


}

#endif // QUAT_H
