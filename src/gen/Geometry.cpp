#include <Geometry.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *Geometry::___get_type_tag()
{
	return (void *) &Geometry::___get_type_tag;
}

void *Geometry::___get_base_type_tag()
{
	return (void *) &Object::___get_type_tag;
}

Geometry *Geometry::_singleton = NULL;


Geometry::Geometry() {
	_owner = godot::api->godot_global_get_singleton((char *) "Geometry");
}


Array Geometry::build_box_planes(const Vector3 extents) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Geometry", "build_box_planes");
	}
	return ___godot_icall_Array_Vector3(mb, (const Object *) this, extents);
}

Array Geometry::build_cylinder_planes(const double radius, const double height, const int64_t sides, const int64_t axis) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Geometry", "build_cylinder_planes");
	}
	return ___godot_icall_Array_float_float_int_int(mb, (const Object *) this, radius, height, sides, axis);
}

Array Geometry::build_capsule_planes(const double radius, const double height, const int64_t sides, const int64_t lats, const int64_t axis) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Geometry", "build_capsule_planes");
	}
	return ___godot_icall_Array_float_float_int_int_int(mb, (const Object *) this, radius, height, sides, lats, axis);
}

double Geometry::segment_intersects_circle(const Vector2 segment_from, const Vector2 segment_to, const Vector2 circle_position, const double circle_radius) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Geometry", "segment_intersects_circle");
	}
	return ___godot_icall_float_Vector2_Vector2_Vector2_float(mb, (const Object *) this, segment_from, segment_to, circle_position, circle_radius);
}

Variant Geometry::segment_intersects_segment_2d(const Vector2 from_a, const Vector2 to_a, const Vector2 from_b, const Vector2 to_b) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Geometry", "segment_intersects_segment_2d");
	}
	return ___godot_icall_Variant_Vector2_Vector2_Vector2_Vector2(mb, (const Object *) this, from_a, to_a, from_b, to_b);
}

PoolVector2Array Geometry::get_closest_points_between_segments_2d(const Vector2 p1, const Vector2 q1, const Vector2 p2, const Vector2 q2) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Geometry", "get_closest_points_between_segments_2d");
	}
	return ___godot_icall_PoolVector2Array_Vector2_Vector2_Vector2_Vector2(mb, (const Object *) this, p1, q1, p2, q2);
}

PoolVector3Array Geometry::get_closest_points_between_segments(const Vector3 p1, const Vector3 p2, const Vector3 q1, const Vector3 q2) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Geometry", "get_closest_points_between_segments");
	}
	return ___godot_icall_PoolVector3Array_Vector3_Vector3_Vector3_Vector3(mb, (const Object *) this, p1, p2, q1, q2);
}

Vector2 Geometry::get_closest_point_to_segment_2d(const Vector2 point, const Vector2 s1, const Vector2 s2) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Geometry", "get_closest_point_to_segment_2d");
	}
	return ___godot_icall_Vector2_Vector2_Vector2_Vector2(mb, (const Object *) this, point, s1, s2);
}

Vector3 Geometry::get_closest_point_to_segment(const Vector3 point, const Vector3 s1, const Vector3 s2) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Geometry", "get_closest_point_to_segment");
	}
	return ___godot_icall_Vector3_Vector3_Vector3_Vector3(mb, (const Object *) this, point, s1, s2);
}

Vector2 Geometry::get_closest_point_to_segment_uncapped_2d(const Vector2 point, const Vector2 s1, const Vector2 s2) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Geometry", "get_closest_point_to_segment_uncapped_2d");
	}
	return ___godot_icall_Vector2_Vector2_Vector2_Vector2(mb, (const Object *) this, point, s1, s2);
}

Vector3 Geometry::get_closest_point_to_segment_uncapped(const Vector3 point, const Vector3 s1, const Vector3 s2) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Geometry", "get_closest_point_to_segment_uncapped");
	}
	return ___godot_icall_Vector3_Vector3_Vector3_Vector3(mb, (const Object *) this, point, s1, s2);
}

int64_t Geometry::get_uv84_normal_bit(const Vector3 normal) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Geometry", "get_uv84_normal_bit");
	}
	return ___godot_icall_int_Vector3(mb, (const Object *) this, normal);
}

Variant Geometry::ray_intersects_triangle(const Vector3 from, const Vector3 dir, const Vector3 a, const Vector3 b, const Vector3 c) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Geometry", "ray_intersects_triangle");
	}
	return ___godot_icall_Variant_Vector3_Vector3_Vector3_Vector3_Vector3(mb, (const Object *) this, from, dir, a, b, c);
}

Variant Geometry::segment_intersects_triangle(const Vector3 from, const Vector3 to, const Vector3 a, const Vector3 b, const Vector3 c) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Geometry", "segment_intersects_triangle");
	}
	return ___godot_icall_Variant_Vector3_Vector3_Vector3_Vector3_Vector3(mb, (const Object *) this, from, to, a, b, c);
}

PoolVector3Array Geometry::segment_intersects_sphere(const Vector3 from, const Vector3 to, const Vector3 sphere_position, const double sphere_radius) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Geometry", "segment_intersects_sphere");
	}
	return ___godot_icall_PoolVector3Array_Vector3_Vector3_Vector3_float(mb, (const Object *) this, from, to, sphere_position, sphere_radius);
}

PoolVector3Array Geometry::segment_intersects_cylinder(const Vector3 from, const Vector3 to, const double height, const double radius) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Geometry", "segment_intersects_cylinder");
	}
	return ___godot_icall_PoolVector3Array_Vector3_Vector3_float_float(mb, (const Object *) this, from, to, height, radius);
}

PoolVector3Array Geometry::segment_intersects_convex(const Vector3 from, const Vector3 to, const Array planes) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Geometry", "segment_intersects_convex");
	}
	return ___godot_icall_PoolVector3Array_Vector3_Vector3_Array(mb, (const Object *) this, from, to, planes);
}

bool Geometry::point_is_inside_triangle(const Vector2 point, const Vector2 a, const Vector2 b, const Vector2 c) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Geometry", "point_is_inside_triangle");
	}
	return ___godot_icall_bool_Vector2_Vector2_Vector2_Vector2(mb, (const Object *) this, point, a, b, c);
}

PoolIntArray Geometry::triangulate_polygon(const PoolVector2Array polygon) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Geometry", "triangulate_polygon");
	}
	return ___godot_icall_PoolIntArray_PoolVector2Array(mb, (const Object *) this, polygon);
}

PoolVector2Array Geometry::convex_hull_2d(const PoolVector2Array points) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Geometry", "convex_hull_2d");
	}
	return ___godot_icall_PoolVector2Array_PoolVector2Array(mb, (const Object *) this, points);
}

PoolVector3Array Geometry::clip_polygon(const PoolVector3Array points, const Plane plane) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Geometry", "clip_polygon");
	}
	return ___godot_icall_PoolVector3Array_PoolVector3Array_Plane(mb, (const Object *) this, points, plane);
}

Dictionary Geometry::make_atlas(const PoolVector2Array sizes) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Geometry", "make_atlas");
	}
	return ___godot_icall_Dictionary_PoolVector2Array(mb, (const Object *) this, sizes);
}

}