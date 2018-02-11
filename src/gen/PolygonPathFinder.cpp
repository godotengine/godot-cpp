#include <PolygonPathFinder.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *PolygonPathFinder::___get_type_tag()
{
	return (void *) &PolygonPathFinder::___get_type_tag;
}

void *PolygonPathFinder::___get_base_type_tag()
{
	return (void *) &Resource::___get_type_tag;
}

PolygonPathFinder *PolygonPathFinder::_new()
{
	return (PolygonPathFinder *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"PolygonPathFinder")());
}
void PolygonPathFinder::setup(const PoolVector2Array points, const PoolIntArray connections) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PolygonPathFinder", "setup");
	}
	___godot_icall_void_PoolVector2Array_PoolIntArray(mb, (const Object *) this, points, connections);
}

PoolVector2Array PolygonPathFinder::find_path(const Vector2 from, const Vector2 to) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PolygonPathFinder", "find_path");
	}
	return ___godot_icall_PoolVector2Array_Vector2_Vector2(mb, (const Object *) this, from, to);
}

PoolVector2Array PolygonPathFinder::get_intersections(const Vector2 from, const Vector2 to) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PolygonPathFinder", "get_intersections");
	}
	return ___godot_icall_PoolVector2Array_Vector2_Vector2(mb, (const Object *) this, from, to);
}

Vector2 PolygonPathFinder::get_closest_point(const Vector2 point) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PolygonPathFinder", "get_closest_point");
	}
	return ___godot_icall_Vector2_Vector2(mb, (const Object *) this, point);
}

bool PolygonPathFinder::is_point_inside(const Vector2 point) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PolygonPathFinder", "is_point_inside");
	}
	return ___godot_icall_bool_Vector2(mb, (const Object *) this, point);
}

void PolygonPathFinder::set_point_penalty(const int64_t idx, const double penalty) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PolygonPathFinder", "set_point_penalty");
	}
	___godot_icall_void_int_float(mb, (const Object *) this, idx, penalty);
}

double PolygonPathFinder::get_point_penalty(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PolygonPathFinder", "get_point_penalty");
	}
	return ___godot_icall_float_int(mb, (const Object *) this, idx);
}

Rect2 PolygonPathFinder::get_bounds() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PolygonPathFinder", "get_bounds");
	}
	return ___godot_icall_Rect2(mb, (const Object *) this);
}

void PolygonPathFinder::_set_data(const Dictionary arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PolygonPathFinder", "_set_data");
	}
	___godot_icall_void_Dictionary(mb, (const Object *) this, arg0);
}

Dictionary PolygonPathFinder::_get_data() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PolygonPathFinder", "_get_data");
	}
	return ___godot_icall_Dictionary(mb, (const Object *) this);
}

}