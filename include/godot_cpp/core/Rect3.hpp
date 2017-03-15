#ifndef RECT3_H
#define RECT3_H

#if defined(_WIN32)
#  ifdef _GD_CPP_CORE_API_IMPL
#    define GD_CPP_CORE_API __declspec(dllexport)
#  else
#    define GD_CPP_CORE_API __declspec(dllimport)
#  endif
#else
#  define GD_CPP_CORE_API
#endif

#include "Vector3.hpp"

#include "Plane.hpp"

#include <cstdlib>

namespace godot {

class GD_CPP_CORE_API Rect3 {
public:
	Vector3 pos;
	Vector3 size;

	real_t get_area() const; /// get area
	inline bool has_no_area() const {

		return (size.x<=CMP_EPSILON || size.y<=CMP_EPSILON  || size.z<=CMP_EPSILON);
	}

	inline bool has_no_surface() const {

		return (size.x<=CMP_EPSILON && size.y<=CMP_EPSILON  && size.z<=CMP_EPSILON);
	}

	inline const Vector3& get_pos() const { return pos; }
	inline void set_pos(const Vector3& p_pos) { pos=p_pos; }
	inline const Vector3& get_size() const { return size; }
	inline void set_size(const Vector3& p_size) { size=p_size; }


	bool operator==(const Rect3& p_rval) const;
	bool operator!=(const Rect3& p_rval) const;

	bool intersects(const Rect3& p_aabb) const; /// Both AABBs overlap
	bool intersects_inclusive(const Rect3& p_aabb) const; /// Both AABBs (or their faces) overlap
	bool encloses(const Rect3 & p_aabb) const; /// p_aabb is completely inside this

	Rect3 merge(const Rect3& p_with) const;
	void merge_with(const Rect3& p_aabb); ///merge with another AABB
	Rect3 intersection(const Rect3& p_aabb) const; ///get box where two intersect, empty if no intersection occurs
	bool intersects_segment(const Vector3& p_from, const Vector3& p_to,Vector3* r_clip=NULL,Vector3* r_normal=NULL) const;
	bool intersects_ray(const Vector3& p_from, const Vector3& p_dir,Vector3* r_clip=NULL,Vector3* r_normal=NULL) const;
	bool smits_intersect_ray(const Vector3 &from,const Vector3& p_dir, real_t t0, real_t t1) const;

	bool intersects_convex_shape(const Plane *p_plane, int p_plane_count) const;
	bool intersects_plane(const Plane &p_plane) const;

	bool has_point(const Vector3& p_point) const;
	Vector3 get_support(const Vector3& p_normal) const;


	Vector3 get_longest_axis() const;
	int get_longest_axis_index() const;
	real_t get_longest_axis_size() const;

	Vector3 get_shortest_axis() const;
	int get_shortest_axis_index() const;
	real_t get_shortest_axis_size() const;

	Rect3 grow(real_t p_by) const;
	void grow_by(real_t p_amount);

	void get_edge(int p_edge,Vector3& r_from,Vector3& r_to) const;
	Vector3 get_endpoint(int p_point) const;

	Rect3 expand(const Vector3& p_vector) const;
	void project_range_in_plane(const Plane& p_plane,real_t &r_min,real_t& r_max) const;
	void expand_to(const Vector3& p_vector); /** expand to contain a point if necesary */

	operator String() const;

	inline Rect3() {}
	inline Rect3(const Vector3 &p_pos,const Vector3& p_size) { pos=p_pos; size=p_size; }


};

}

#endif // RECT3_H
