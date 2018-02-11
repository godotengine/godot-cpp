#include <KinematicBody2D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <KinematicCollision2D.hpp>


namespace godot {


void *KinematicBody2D::___get_type_tag()
{
	return (void *) &KinematicBody2D::___get_type_tag;
}

void *KinematicBody2D::___get_base_type_tag()
{
	return (void *) &PhysicsBody2D::___get_type_tag;
}

KinematicBody2D *KinematicBody2D::_new()
{
	return (KinematicBody2D *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"KinematicBody2D")());
}
Ref<KinematicCollision2D> KinematicBody2D::move_and_collide(const Vector2 rel_vec, const bool infinite_inertia) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("KinematicBody2D", "move_and_collide");
	}
	return Ref<KinematicCollision2D>::__internal_constructor(___godot_icall_Object_Vector2_bool(mb, (const Object *) this, rel_vec, infinite_inertia));
}

Vector2 KinematicBody2D::move_and_slide(const Vector2 linear_velocity, const Vector2 floor_normal, const bool infinite_inertia, const double slope_stop_min_velocity, const int64_t max_bounces, const double floor_max_angle) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("KinematicBody2D", "move_and_slide");
	}
	return ___godot_icall_Vector2_Vector2_Vector2_bool_float_int_float(mb, (const Object *) this, linear_velocity, floor_normal, infinite_inertia, slope_stop_min_velocity, max_bounces, floor_max_angle);
}

bool KinematicBody2D::test_move(const Transform2D from, const Vector2 rel_vec, const bool infinite_inertia) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("KinematicBody2D", "test_move");
	}
	return ___godot_icall_bool_Transform2D_Vector2_bool(mb, (const Object *) this, from, rel_vec, infinite_inertia);
}

bool KinematicBody2D::is_on_floor() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("KinematicBody2D", "is_on_floor");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

bool KinematicBody2D::is_on_ceiling() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("KinematicBody2D", "is_on_ceiling");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

bool KinematicBody2D::is_on_wall() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("KinematicBody2D", "is_on_wall");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

Vector2 KinematicBody2D::get_floor_velocity() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("KinematicBody2D", "get_floor_velocity");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void KinematicBody2D::set_safe_margin(const double pixels) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("KinematicBody2D", "set_safe_margin");
	}
	___godot_icall_void_float(mb, (const Object *) this, pixels);
}

double KinematicBody2D::get_safe_margin() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("KinematicBody2D", "get_safe_margin");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

int64_t KinematicBody2D::get_slide_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("KinematicBody2D", "get_slide_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

Ref<KinematicCollision2D> KinematicBody2D::get_slide_collision(const int64_t slide_idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("KinematicBody2D", "get_slide_collision");
	}
	return Ref<KinematicCollision2D>::__internal_constructor(___godot_icall_Object_int(mb, (const Object *) this, slide_idx));
}

}