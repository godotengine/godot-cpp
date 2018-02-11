#include <Physics2DDirectBodyState.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Object.hpp>
#include <Physics2DDirectSpaceState.hpp>


namespace godot {


void *Physics2DDirectBodyState::___get_type_tag()
{
	return (void *) &Physics2DDirectBodyState::___get_type_tag;
}

void *Physics2DDirectBodyState::___get_base_type_tag()
{
	return (void *) &Object::___get_type_tag;
}

Vector2 Physics2DDirectBodyState::get_total_gravity() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DDirectBodyState", "get_total_gravity");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

double Physics2DDirectBodyState::get_total_linear_damp() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DDirectBodyState", "get_total_linear_damp");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

double Physics2DDirectBodyState::get_total_angular_damp() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DDirectBodyState", "get_total_angular_damp");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

double Physics2DDirectBodyState::get_inverse_mass() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DDirectBodyState", "get_inverse_mass");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

double Physics2DDirectBodyState::get_inverse_inertia() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DDirectBodyState", "get_inverse_inertia");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Physics2DDirectBodyState::set_linear_velocity(const Vector2 velocity) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DDirectBodyState", "set_linear_velocity");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, velocity);
}

Vector2 Physics2DDirectBodyState::get_linear_velocity() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DDirectBodyState", "get_linear_velocity");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void Physics2DDirectBodyState::set_angular_velocity(const double velocity) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DDirectBodyState", "set_angular_velocity");
	}
	___godot_icall_void_float(mb, (const Object *) this, velocity);
}

double Physics2DDirectBodyState::get_angular_velocity() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DDirectBodyState", "get_angular_velocity");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Physics2DDirectBodyState::set_transform(const Transform2D transform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DDirectBodyState", "set_transform");
	}
	___godot_icall_void_Transform2D(mb, (const Object *) this, transform);
}

Transform2D Physics2DDirectBodyState::get_transform() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DDirectBodyState", "get_transform");
	}
	return ___godot_icall_Transform2D(mb, (const Object *) this);
}

void Physics2DDirectBodyState::set_sleep_state(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DDirectBodyState", "set_sleep_state");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool Physics2DDirectBodyState::is_sleeping() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DDirectBodyState", "is_sleeping");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

int64_t Physics2DDirectBodyState::get_contact_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DDirectBodyState", "get_contact_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

Vector2 Physics2DDirectBodyState::get_contact_local_position(const int64_t contact_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DDirectBodyState", "get_contact_local_position");
	}
	return ___godot_icall_Vector2_int(mb, (const Object *) this, contact_idx);
}

Vector2 Physics2DDirectBodyState::get_contact_local_normal(const int64_t contact_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DDirectBodyState", "get_contact_local_normal");
	}
	return ___godot_icall_Vector2_int(mb, (const Object *) this, contact_idx);
}

int64_t Physics2DDirectBodyState::get_contact_local_shape(const int64_t contact_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DDirectBodyState", "get_contact_local_shape");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, contact_idx);
}

RID Physics2DDirectBodyState::get_contact_collider(const int64_t contact_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DDirectBodyState", "get_contact_collider");
	}
	return ___godot_icall_RID_int(mb, (const Object *) this, contact_idx);
}

Vector2 Physics2DDirectBodyState::get_contact_collider_position(const int64_t contact_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DDirectBodyState", "get_contact_collider_position");
	}
	return ___godot_icall_Vector2_int(mb, (const Object *) this, contact_idx);
}

int64_t Physics2DDirectBodyState::get_contact_collider_id(const int64_t contact_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DDirectBodyState", "get_contact_collider_id");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, contact_idx);
}

Object *Physics2DDirectBodyState::get_contact_collider_object(const int64_t contact_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DDirectBodyState", "get_contact_collider_object");
	}
	return (Object *) ___godot_icall_Object_int(mb, (const Object *) this, contact_idx);
}

int64_t Physics2DDirectBodyState::get_contact_collider_shape(const int64_t contact_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DDirectBodyState", "get_contact_collider_shape");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, contact_idx);
}

Variant Physics2DDirectBodyState::get_contact_collider_shape_metadata(const int64_t contact_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DDirectBodyState", "get_contact_collider_shape_metadata");
	}
	return ___godot_icall_Variant_int(mb, (const Object *) this, contact_idx);
}

Vector2 Physics2DDirectBodyState::get_contact_collider_velocity_at_position(const int64_t contact_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DDirectBodyState", "get_contact_collider_velocity_at_position");
	}
	return ___godot_icall_Vector2_int(mb, (const Object *) this, contact_idx);
}

double Physics2DDirectBodyState::get_step() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DDirectBodyState", "get_step");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Physics2DDirectBodyState::integrate_forces() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DDirectBodyState", "integrate_forces");
	}
	___godot_icall_void(mb, (const Object *) this);
}

Physics2DDirectSpaceState *Physics2DDirectBodyState::get_space_state() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DDirectBodyState", "get_space_state");
	}
	return (Physics2DDirectSpaceState *) ___godot_icall_Object(mb, (const Object *) this);
}

}