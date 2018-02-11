#include <CollisionPolygon2D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *CollisionPolygon2D::___get_type_tag()
{
	return (void *) &CollisionPolygon2D::___get_type_tag;
}

void *CollisionPolygon2D::___get_base_type_tag()
{
	return (void *) &Node2D::___get_type_tag;
}

CollisionPolygon2D *CollisionPolygon2D::_new()
{
	return (CollisionPolygon2D *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"CollisionPolygon2D")());
}
void CollisionPolygon2D::set_polygon(const PoolVector2Array polygon) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionPolygon2D", "set_polygon");
	}
	___godot_icall_void_PoolVector2Array(mb, (const Object *) this, polygon);
}

PoolVector2Array CollisionPolygon2D::get_polygon() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionPolygon2D", "get_polygon");
	}
	return ___godot_icall_PoolVector2Array(mb, (const Object *) this);
}

void CollisionPolygon2D::set_build_mode(const int64_t build_mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionPolygon2D", "set_build_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, build_mode);
}

CollisionPolygon2D::BuildMode CollisionPolygon2D::get_build_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionPolygon2D", "get_build_mode");
	}
	return (CollisionPolygon2D::BuildMode) ___godot_icall_int(mb, (const Object *) this);
}

void CollisionPolygon2D::set_disabled(const bool disabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionPolygon2D", "set_disabled");
	}
	___godot_icall_void_bool(mb, (const Object *) this, disabled);
}

bool CollisionPolygon2D::is_disabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionPolygon2D", "is_disabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void CollisionPolygon2D::set_one_way_collision(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionPolygon2D", "set_one_way_collision");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool CollisionPolygon2D::is_one_way_collision_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionPolygon2D", "is_one_way_collision_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

}