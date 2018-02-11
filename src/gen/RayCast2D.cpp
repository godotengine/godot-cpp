#include <RayCast2D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Object.hpp>


namespace godot {


void *RayCast2D::___get_type_tag()
{
	return (void *) &RayCast2D::___get_type_tag;
}

void *RayCast2D::___get_base_type_tag()
{
	return (void *) &Node2D::___get_type_tag;
}

RayCast2D *RayCast2D::_new()
{
	return (RayCast2D *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"RayCast2D")());
}
void RayCast2D::set_enabled(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayCast2D", "set_enabled");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool RayCast2D::is_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayCast2D", "is_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void RayCast2D::set_cast_to(const Vector2 local_point) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayCast2D", "set_cast_to");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, local_point);
}

Vector2 RayCast2D::get_cast_to() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayCast2D", "get_cast_to");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

bool RayCast2D::is_colliding() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayCast2D", "is_colliding");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void RayCast2D::force_raycast_update() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayCast2D", "force_raycast_update");
	}
	___godot_icall_void(mb, (const Object *) this);
}

Object *RayCast2D::get_collider() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayCast2D", "get_collider");
	}
	return (Object *) ___godot_icall_Object(mb, (const Object *) this);
}

int64_t RayCast2D::get_collider_shape() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayCast2D", "get_collider_shape");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

Vector2 RayCast2D::get_collision_point() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayCast2D", "get_collision_point");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

Vector2 RayCast2D::get_collision_normal() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayCast2D", "get_collision_normal");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void RayCast2D::add_exception_rid(const RID rid) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayCast2D", "add_exception_rid");
	}
	___godot_icall_void_RID(mb, (const Object *) this, rid);
}

void RayCast2D::add_exception(const Object *node) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayCast2D", "add_exception");
	}
	___godot_icall_void_Object(mb, (const Object *) this, node);
}

void RayCast2D::remove_exception_rid(const RID rid) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayCast2D", "remove_exception_rid");
	}
	___godot_icall_void_RID(mb, (const Object *) this, rid);
}

void RayCast2D::remove_exception(const Object *node) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayCast2D", "remove_exception");
	}
	___godot_icall_void_Object(mb, (const Object *) this, node);
}

void RayCast2D::clear_exceptions() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayCast2D", "clear_exceptions");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void RayCast2D::set_collision_mask(const int64_t mask) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayCast2D", "set_collision_mask");
	}
	___godot_icall_void_int(mb, (const Object *) this, mask);
}

int64_t RayCast2D::get_collision_mask() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayCast2D", "get_collision_mask");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void RayCast2D::set_collision_mask_bit(const int64_t bit, const bool value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayCast2D", "set_collision_mask_bit");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, bit, value);
}

bool RayCast2D::get_collision_mask_bit(const int64_t bit) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayCast2D", "get_collision_mask_bit");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, bit);
}

void RayCast2D::set_exclude_parent_body(const bool mask) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayCast2D", "set_exclude_parent_body");
	}
	___godot_icall_void_bool(mb, (const Object *) this, mask);
}

bool RayCast2D::get_exclude_parent_body() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayCast2D", "get_exclude_parent_body");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

}