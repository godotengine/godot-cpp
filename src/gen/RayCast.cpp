#include <RayCast.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Object.hpp>


namespace godot {


void *RayCast::___get_type_tag()
{
	return (void *) &RayCast::___get_type_tag;
}

void *RayCast::___get_base_type_tag()
{
	return (void *) &Spatial::___get_type_tag;
}

RayCast *RayCast::_new()
{
	return (RayCast *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"RayCast")());
}
void RayCast::set_enabled(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayCast", "set_enabled");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool RayCast::is_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayCast", "is_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void RayCast::set_cast_to(const Vector3 local_point) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayCast", "set_cast_to");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, local_point);
}

Vector3 RayCast::get_cast_to() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayCast", "get_cast_to");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

bool RayCast::is_colliding() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayCast", "is_colliding");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void RayCast::force_raycast_update() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayCast", "force_raycast_update");
	}
	___godot_icall_void(mb, (const Object *) this);
}

Object *RayCast::get_collider() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayCast", "get_collider");
	}
	return (Object *) ___godot_icall_Object(mb, (const Object *) this);
}

int64_t RayCast::get_collider_shape() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayCast", "get_collider_shape");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

Vector3 RayCast::get_collision_point() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayCast", "get_collision_point");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

Vector3 RayCast::get_collision_normal() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayCast", "get_collision_normal");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

void RayCast::add_exception_rid(const RID rid) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayCast", "add_exception_rid");
	}
	___godot_icall_void_RID(mb, (const Object *) this, rid);
}

void RayCast::add_exception(const Object *node) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayCast", "add_exception");
	}
	___godot_icall_void_Object(mb, (const Object *) this, node);
}

void RayCast::remove_exception_rid(const RID rid) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayCast", "remove_exception_rid");
	}
	___godot_icall_void_RID(mb, (const Object *) this, rid);
}

void RayCast::remove_exception(const Object *node) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayCast", "remove_exception");
	}
	___godot_icall_void_Object(mb, (const Object *) this, node);
}

void RayCast::clear_exceptions() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayCast", "clear_exceptions");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void RayCast::set_collision_mask(const int64_t mask) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayCast", "set_collision_mask");
	}
	___godot_icall_void_int(mb, (const Object *) this, mask);
}

int64_t RayCast::get_collision_mask() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayCast", "get_collision_mask");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void RayCast::set_collision_mask_bit(const int64_t bit, const bool value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayCast", "set_collision_mask_bit");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, bit, value);
}

bool RayCast::get_collision_mask_bit(const int64_t bit) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayCast", "get_collision_mask_bit");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, bit);
}

void RayCast::set_exclude_parent_body(const bool mask) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayCast", "set_exclude_parent_body");
	}
	___godot_icall_void_bool(mb, (const Object *) this, mask);
}

bool RayCast::get_exclude_parent_body() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayCast", "get_exclude_parent_body");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

}