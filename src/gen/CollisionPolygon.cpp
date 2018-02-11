#include <CollisionPolygon.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *CollisionPolygon::___get_type_tag()
{
	return (void *) &CollisionPolygon::___get_type_tag;
}

void *CollisionPolygon::___get_base_type_tag()
{
	return (void *) &Spatial::___get_type_tag;
}

CollisionPolygon *CollisionPolygon::_new()
{
	return (CollisionPolygon *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"CollisionPolygon")());
}
void CollisionPolygon::set_depth(const double depth) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionPolygon", "set_depth");
	}
	___godot_icall_void_float(mb, (const Object *) this, depth);
}

double CollisionPolygon::get_depth() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionPolygon", "get_depth");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void CollisionPolygon::set_polygon(const PoolVector2Array polygon) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionPolygon", "set_polygon");
	}
	___godot_icall_void_PoolVector2Array(mb, (const Object *) this, polygon);
}

PoolVector2Array CollisionPolygon::get_polygon() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionPolygon", "get_polygon");
	}
	return ___godot_icall_PoolVector2Array(mb, (const Object *) this);
}

void CollisionPolygon::set_disabled(const bool disabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionPolygon", "set_disabled");
	}
	___godot_icall_void_bool(mb, (const Object *) this, disabled);
}

bool CollisionPolygon::is_disabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionPolygon", "is_disabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

}