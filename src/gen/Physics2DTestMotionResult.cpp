#include <Physics2DTestMotionResult.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Object.hpp>


namespace godot {


void *Physics2DTestMotionResult::___get_type_tag()
{
	return (void *) &Physics2DTestMotionResult::___get_type_tag;
}

void *Physics2DTestMotionResult::___get_base_type_tag()
{
	return (void *) &Reference::___get_type_tag;
}

Physics2DTestMotionResult *Physics2DTestMotionResult::_new()
{
	return (Physics2DTestMotionResult *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Physics2DTestMotionResult")());
}
Vector2 Physics2DTestMotionResult::get_motion() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DTestMotionResult", "get_motion");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

Vector2 Physics2DTestMotionResult::get_motion_remainder() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DTestMotionResult", "get_motion_remainder");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

Vector2 Physics2DTestMotionResult::get_collision_point() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DTestMotionResult", "get_collision_point");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

Vector2 Physics2DTestMotionResult::get_collision_normal() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DTestMotionResult", "get_collision_normal");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

Vector2 Physics2DTestMotionResult::get_collider_velocity() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DTestMotionResult", "get_collider_velocity");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

int64_t Physics2DTestMotionResult::get_collider_id() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DTestMotionResult", "get_collider_id");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

RID Physics2DTestMotionResult::get_collider_rid() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DTestMotionResult", "get_collider_rid");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

Object *Physics2DTestMotionResult::get_collider() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DTestMotionResult", "get_collider");
	}
	return (Object *) ___godot_icall_Object(mb, (const Object *) this);
}

int64_t Physics2DTestMotionResult::get_collider_shape() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DTestMotionResult", "get_collider_shape");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

}