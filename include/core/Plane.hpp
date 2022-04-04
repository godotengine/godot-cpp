/*************************************************************************/
/*  Plane.hpp                                                            */
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

#ifndef PLANE_H
#define PLANE_H

#include "Vector3.hpp"

#include <cmath>

namespace godot {

enum ClockDirection {

	CLOCKWISE,
	COUNTERCLOCKWISE
};

class Plane {
public:
	Vector3 normal;
	real_t d;

	void set_normal(const Vector3 &p_normal);

	inline Vector3 get_normal() const { return normal; } ///Point is coplanar, CMP_EPSILON for precision

	void normalize();

	Plane normalized() const;

	/* Plane-Point operations */

	inline Vector3 center() const { return normal * d; }
	Vector3 get_any_point() const;
	Vector3 get_any_perpendicular_normal() const;

	bool is_point_over(const Vector3 &p_point) const; ///< Point is over plane
	real_t distance_to(const Vector3 &p_point) const;
	bool has_point(const Vector3 &p_point, real_t _epsilon = CMP_EPSILON) const;

	/* intersections */

	bool intersect_3(const Plane &p_plane1, const Plane &p_plane2, Vector3 *r_result = 0) const;
	bool intersects_ray(Vector3 p_from, Vector3 p_dir, Vector3 *p_intersection) const;
	bool intersects_segment(Vector3 p_begin, Vector3 p_end, Vector3 *p_intersection) const;

	Vector3 project(const Vector3 &p_point) const;

	/* misc */

	inline Plane operator-() const { return Plane(-normal, -d); }
	bool is_almost_like(const Plane &p_plane) const;

	bool operator==(const Plane &p_plane) const;
	bool operator!=(const Plane &p_plane) const;
	operator String() const;

	inline Plane() { d = 0; }
	inline Plane(real_t p_a, real_t p_b, real_t p_c, real_t p_d) :
			normal(p_a, p_b, p_c),
			d(p_d) {}

	Plane(const Vector3 &p_normal, real_t p_d);
	Plane(const Vector3 &p_point, const Vector3 &p_normal);
	Plane(const Vector3 &p_point1, const Vector3 &p_point2, const Vector3 &p_point3, ClockDirection p_dir = CLOCKWISE);
};

} // namespace godot

#endif // PLANE_H
