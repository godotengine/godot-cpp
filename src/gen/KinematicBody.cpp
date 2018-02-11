#include <KinematicBody.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <KinematicCollision.hpp>


namespace godot {


void *KinematicBody::___get_type_tag()
{
	return (void *) &KinematicBody::___get_type_tag;
}

void *KinematicBody::___get_base_type_tag()
{
	return (void *) &PhysicsBody::___get_type_tag;
}

KinematicBody *KinematicBody::_new()
{
	return (KinematicBody *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"KinematicBody")());
}
Ref<KinematicCollision> KinematicBody::move_and_collide(const Vector3 rel_vec, const bool infinite_inertia) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("KinematicBody", "move_and_collide");
	}
	return Ref<KinematicCollision>::__internal_constructor(___godot_icall_Object_Vector3_bool(mb, (const Object *) this, rel_vec, infinite_inertia));
}

Vector3 KinematicBody::move_and_slide(const Vector3 linear_velocity, const Vector3 floor_normal, const bool infinite_inertia, const double slope_stop_min_velocity, const int64_t max_slides, const double floor_max_angle) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("KinematicBody", "move_and_slide");
	}
	return ___godot_icall_Vector3_Vector3_Vector3_bool_float_int_float(mb, (const Object *) this, linear_velocity, floor_normal, infinite_inertia, slope_stop_min_velocity, max_slides, floor_max_angle);
}

bool KinematicBody::test_move(const Transform from, const Vector3 rel_vec, const bool infinite_inertia) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("KinematicBody", "test_move");
	}
	return ___godot_icall_bool_Transform_Vector3_bool(mb, (const Object *) this, from, rel_vec, infinite_inertia);
}

bool KinematicBody::is_on_floor() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("KinematicBody", "is_on_floor");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

bool KinematicBody::is_on_ceiling() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("KinematicBody", "is_on_ceiling");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

bool KinematicBody::is_on_wall() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("KinematicBody", "is_on_wall");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

Vector3 KinematicBody::get_floor_velocity() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("KinematicBody", "get_floor_velocity");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

void KinematicBody::set_axis_lock(const int64_t axis, const bool lock) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("KinematicBody", "set_axis_lock");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, axis, lock);
}

bool KinematicBody::get_axis_lock(const int64_t axis) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("KinematicBody", "get_axis_lock");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, axis);
}

void KinematicBody::set_safe_margin(const double pixels) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("KinematicBody", "set_safe_margin");
	}
	___godot_icall_void_float(mb, (const Object *) this, pixels);
}

double KinematicBody::get_safe_margin() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("KinematicBody", "get_safe_margin");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

int64_t KinematicBody::get_slide_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("KinematicBody", "get_slide_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

Ref<KinematicCollision> KinematicBody::get_slide_collision(const int64_t slide_idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("KinematicBody", "get_slide_collision");
	}
	return Ref<KinematicCollision>::__internal_constructor(___godot_icall_Object_int(mb, (const Object *) this, slide_idx));
}

}