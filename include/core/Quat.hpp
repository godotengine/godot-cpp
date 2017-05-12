#ifndef QUAT_H
#define QUAT_H

#if defined(_WIN32)
#  ifdef _GD_CPP_CORE_API_IMPL
#    define GD_CPP_CORE_API __declspec(dllexport)
#  else
#    define GD_CPP_CORE_API __declspec(dllimport)
#  endif
#else
#  define GD_CPP_CORE_API
#endif

#include <cmath>

#include "Vector3.hpp"

// #include "Basis.h"

namespace godot {

class GD_CPP_CORE_API Quat{
public:

	real_t x,y,z,w;

	real_t length_squared() const;
	real_t length() const;

	void normalize();

	Quat normalized() const;

	Quat inverse() const;

	void set_euler(const Vector3& p_euler);

	real_t dot(const Quat& q) const;

	Vector3 get_euler() const;

	Quat slerp(const Quat& q, const real_t& t) const;

	Quat slerpni(const Quat& q, const real_t& t) const;

	Quat cubic_slerp(const Quat& q, const Quat& prep, const Quat& postq,const real_t& t) const;

	void get_axis_and_angle(Vector3& r_axis, real_t &r_angle) const;

	void operator*=(const Quat& q);
	Quat operator*(const Quat& q) const;



	Quat operator*(const Vector3& v) const;

	Vector3 xform(const Vector3& v) const;


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

	Quat(const Vector3& v0, const Vector3& v1) ;

	inline Quat() {x=y=z=0; w=1; }

};


}

#endif // QUAT_H
