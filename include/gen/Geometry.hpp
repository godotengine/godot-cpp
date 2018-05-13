#ifndef GODOT_CPP_GEOMETRY_HPP
#define GODOT_CPP_GEOMETRY_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Object.hpp"
namespace godot {


class Geometry : public Object {
	static Geometry *_singleton;

	Geometry();

public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline Geometry *get_singleton()
	{
		if (!Geometry::_singleton) {
			Geometry::_singleton = new Geometry;
		}
		return Geometry::_singleton;
	}

	static inline const char *___get_class_name() { return (const char *) "Geometry"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants

	// methods
	Array build_box_planes(const Vector3 extents);
	Array build_cylinder_planes(const double radius, const double height, const int64_t sides, const int64_t axis = 2);
	Array build_capsule_planes(const double radius, const double height, const int64_t sides, const int64_t lats, const int64_t axis = 2);
	double segment_intersects_circle(const Vector2 segment_from, const Vector2 segment_to, const Vector2 circle_position, const double circle_radius);
	Variant segment_intersects_segment_2d(const Vector2 from_a, const Vector2 to_a, const Vector2 from_b, const Vector2 to_b);
	Variant line_intersects_line_2d(const Vector2 from_a, const Vector2 dir_a, const Vector2 from_b, const Vector2 dir_b);
	PoolVector2Array get_closest_points_between_segments_2d(const Vector2 p1, const Vector2 q1, const Vector2 p2, const Vector2 q2);
	PoolVector3Array get_closest_points_between_segments(const Vector3 p1, const Vector3 p2, const Vector3 q1, const Vector3 q2);
	Vector2 get_closest_point_to_segment_2d(const Vector2 point, const Vector2 s1, const Vector2 s2);
	Vector3 get_closest_point_to_segment(const Vector3 point, const Vector3 s1, const Vector3 s2);
	Vector2 get_closest_point_to_segment_uncapped_2d(const Vector2 point, const Vector2 s1, const Vector2 s2);
	Vector3 get_closest_point_to_segment_uncapped(const Vector3 point, const Vector3 s1, const Vector3 s2);
	int64_t get_uv84_normal_bit(const Vector3 normal);
	Variant ray_intersects_triangle(const Vector3 from, const Vector3 dir, const Vector3 a, const Vector3 b, const Vector3 c);
	Variant segment_intersects_triangle(const Vector3 from, const Vector3 to, const Vector3 a, const Vector3 b, const Vector3 c);
	PoolVector3Array segment_intersects_sphere(const Vector3 from, const Vector3 to, const Vector3 sphere_position, const double sphere_radius);
	PoolVector3Array segment_intersects_cylinder(const Vector3 from, const Vector3 to, const double height, const double radius);
	PoolVector3Array segment_intersects_convex(const Vector3 from, const Vector3 to, const Array planes);
	bool point_is_inside_triangle(const Vector2 point, const Vector2 a, const Vector2 b, const Vector2 c) const;
	PoolIntArray triangulate_polygon(const PoolVector2Array polygon);
	PoolVector2Array convex_hull_2d(const PoolVector2Array points);
	PoolVector3Array clip_polygon(const PoolVector3Array points, const Plane plane);
	Dictionary make_atlas(const PoolVector2Array sizes);

};

}

#endif