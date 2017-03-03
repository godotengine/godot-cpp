#ifndef VECTOR3_H
#define VECTOR3_H

typedef float real_t;

#include "String.h"

#include <cmath>

typedef float real_t; // @Todo move this to a global Godot.h

namespace godot {


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

	Vector3(real_t x, real_t y, real_t z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vector3()
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}

	Vector3(const Vector3& b)
	{
		this->x = b.x;
		this->y = b.y;
		this->z = b.z;
	}

	const real_t& operator[](int p_axis) const
	{
		return coord[p_axis];
	}

	real_t& operator[](int p_axis)
	{
		return coord[p_axis];
	}

	Vector3& operator+=(const Vector3& p_v)
	{
		x += p_v.x;
		y += p_v.y;
		z += p_v.z;
		return *this;
	}

	Vector3 operator+(const Vector3& p_v) const
	{
		Vector3 v = *this;
		v += p_v;
		return v;
	}

	Vector3& operator-=(const Vector3& p_v)
	{
		x -= p_v.x;
		y -= p_v.y;
		z -= p_v.z;
		return *this;
	}

	Vector3 operator-(const Vector3& p_v) const
	{
		Vector3 v = *this;
		v -= p_v;
		return v;
	}

	Vector3& operator*=(const Vector3& p_v)
	{
		x *= p_v.x;
		y *= p_v.y;
		z *= p_v.z;
		return *this;
	}

	Vector3 operator*(const Vector3& p_v) const
	{
		Vector3 v = *this;
		v *= p_v;
		return v;
	}

	Vector3& operator/=(const Vector3& p_v)
	{
		x /= p_v.x;
		y /= p_v.y;
		z /= p_v.z;
		return *this;
	}

	Vector3 operator/(const Vector3& p_v) const
	{
		Vector3 v = *this;
		v /= p_v;
		return v;
	}


	Vector3& operator*=(real_t p_scalar)
	{
		*this *= Vector3(p_scalar, p_scalar, p_scalar);
		return *this;
	}

	Vector3 operator*(real_t p_scalar) const
	{
		Vector3 v = *this;
		v *= p_scalar;
		return v;
	}

	Vector3& operator/=(real_t p_scalar)
	{
		*this /= Vector3(p_scalar, p_scalar, p_scalar);
		return *this;
	}

	Vector3 operator/(real_t p_scalar) const
	{
		Vector3 v = *this;
		v /= p_scalar;
		return v;
	}

	Vector3 operator-() const
	{
		return Vector3(-x, -y, -z);
	}

	bool operator==(const Vector3& p_v) const
	{
		return (x==p_v.x && y==p_v.y && z==p_v.z);
	}

	bool operator!=(const Vector3& p_v) const
	{
		return (x!=p_v.x || y!=p_v.y || z!=p_v.z);
	}

	bool operator<(const Vector3& p_v) const
	{
		if (x==p_v.x) {
			if (y==p_v.y)
				return z<p_v.z;
			else
				return y<p_v.y;
		} else {
			return x<p_v.x;
		}
	}

	bool operator<=(const Vector3& p_v) const
	{
		if (x==p_v.x) {
			if (y==p_v.y)
				return z<=p_v.z;
			else
				return y<p_v.y;
		} else {
			return x<p_v.x;
		}
	}

	Vector3 abs() const
	{
		return Vector3(::fabs(x), ::fabs(y), ::fabs(z));
	}

	Vector3 ceil() const
	{
		return Vector3(::ceil(x), ::ceil(y), ::ceil(z));
	}

	Vector3 cross(const Vector3& b) const
	{
		Vector3 ret (
			(y * b.z) - (z * b.y),
			(z * b.x) - (x * b.z),
			(x * b.y) - (y * b.x)
		);

		return ret;
	}

	Vector3 linear_interpolate(const Vector3& p_b,real_t p_t) const
	{
		return Vector3(
			x+(p_t * (p_b.x-x)),
			y+(p_t * (p_b.y-y)),
			z+(p_t * (p_b.z-z))
		);
	}

	Vector3 cubic_interpolate(const Vector3& b, const Vector3& pre_a, const Vector3& post_b, const real_t t) const
	{
		Vector3 p0=pre_a;
		Vector3 p1=*this;
		Vector3 p2=b;
		Vector3 p3=post_b;

		real_t t2 = t * t;
		real_t t3 = t2 * t;

		Vector3 out;
		out = ( ( p1 * 2.0) +
		( -p0 + p2 ) * t +
		( p0 * 2.0 - p1 * 5.0 + p2 * 4 - p3 ) * t2 +
		( -p0 + p1 * 3.0 - p2 * 3.0 + p3 ) * t3 ) * 0.5;
		return out;
	}

	real_t length() const
	{
		real_t x2=x*x;
		real_t y2=y*y;
		real_t z2=z*z;

		return ::sqrt(x2+y2+z2);
	}

	real_t length_squared() const
	{
		real_t x2=x*x;
		real_t y2=y*y;
		real_t z2=z*z;

		return x2+y2+z2;
	}

	real_t distance_squared_to(const Vector3& b) const
	{
		return (b-*this).length();
	}

	real_t distance_to(const Vector3& b) const
	{
		return (b-*this).length_squared();
	}

	real_t dot(const Vector3& b) const
	{
		return x*b.x + y*b.y + z*b.z;
	}

	Vector3 floor() const
	{
		return Vector3(::floor(x), ::floor(y), ::floor(z));
	}

	Vector3 inverse() const
	{
		return Vector3( 1.0/x, 1.0/y, 1.0/z );
	}




	int max_axis() const
	{
		return x < y ? (y < z ? 2 : 1) : (x < z ? 2 : 0);
	}

	int min_axis() const
	{
		return x < y ? (x < z ? 0 : 2) : (y < z ? 1 : 2);
	}

	void normalize()
	{
		real_t l=length();
		if (l==0) {
			x=y=z=0;
		} else {
			x/=l;
			y/=l;
			z/=l;
		}
	}

	Vector3 normalized() const
	{
		Vector3 v = *this;
		v.normalize();
		return v;
	}

	Vector3 reflect(const Vector3& by) const
	{
		return by - *this * this->dot(by) * 2.0;
	}

	Vector3 rotated(const Vector3& axis, const real_t phi) const
	{
		Vector3 v = *this;
		v.rotate(axis, phi);
		return v;
	}

	void rotate(const Vector3& p_axis,real_t p_phi)
	{
		// this is ugly, but I don't want to deal with C++ header inclusion order issues

		// this is what is happening here

		// *this=Basis(p_axis,p_phi).xform(*this);

		Vector3 elements[3];

		Vector3 axis_sq(p_axis.x*p_axis.x,p_axis.y*p_axis.y,p_axis.z*p_axis.z);

		real_t cosine= ::cos(p_phi);
		real_t sine= ::sin(p_phi);

		elements[0][0] = axis_sq.x + cosine * ( 1.0 - axis_sq.x );
		elements[0][1] = p_axis.x * p_axis.y *  ( 1.0 - cosine ) - p_axis.z * sine;
		elements[0][2] = p_axis.z * p_axis.x * ( 1.0 - cosine ) + p_axis.y * sine;

		elements[1][0] = p_axis.x * p_axis.y * ( 1.0 - cosine ) + p_axis.z * sine;
		elements[1][1] = axis_sq.y + cosine  * ( 1.0 - axis_sq.y );
		elements[1][2] = p_axis.y * p_axis.z * ( 1.0 - cosine ) - p_axis.x * sine;

		elements[2][0] = p_axis.z * p_axis.x * ( 1.0 - cosine ) - p_axis.y * sine;
		elements[2][1] = p_axis.y * p_axis.z * ( 1.0 - cosine ) + p_axis.x * sine;
		elements[2][2] = axis_sq.z + cosine  * ( 1.0 - axis_sq.z );

		*this = Vector3(
			elements[0].dot(*this),
			elements[1].dot(*this),
			elements[2].dot(*this)
		);

	}

	Vector3 slide(const Vector3& by) const
	{
		return by - *this * this->dot(by);
	}

// this is ugly as well, but hey, I'm a simple man
#define _ugly_stepify(val, step) (step != 0 ? ::floor(val / step + 0.5) * step : val)

	void snap(real_t p_val)
	{
		x = _ugly_stepify(x,p_val);
		y = _ugly_stepify(y,p_val);
		z = _ugly_stepify(z,p_val);
	}

#undef _ugly_stepify

	Vector3 snapped(const float by)
	{
		Vector3 v = *this;
		v.snap(by);
		return v;
	}
};

Vector3 operator*(real_t p_scalar, const Vector3& p_vec)
{
	return p_vec * p_scalar;
}

}

#endif // VECTOR3_H
