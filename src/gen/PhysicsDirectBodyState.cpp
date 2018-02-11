#include <PhysicsDirectBodyState.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Object.hpp>
#include <PhysicsDirectSpaceState.hpp>


namespace godot {


void *PhysicsDirectBodyState::___get_type_tag()
{
	return (void *) &PhysicsDirectBodyState::___get_type_tag;
}

void *PhysicsDirectBodyState::___get_base_type_tag()
{
	return (void *) &Object::___get_type_tag;
}

Vector3 PhysicsDirectBodyState::get_total_gravity() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsDirectBodyState", "get_total_gravity");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

double PhysicsDirectBodyState::get_total_linear_damp() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsDirectBodyState", "get_total_linear_damp");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

double PhysicsDirectBodyState::get_total_angular_damp() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsDirectBodyState", "get_total_angular_damp");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

Vector3 PhysicsDirectBodyState::get_center_of_mass() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsDirectBodyState", "get_center_of_mass");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

Basis PhysicsDirectBodyState::get_principal_inertia_axes() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsDirectBodyState", "get_principal_inertia_axes");
	}
	return ___godot_icall_Basis(mb, (const Object *) this);
}

double PhysicsDirectBodyState::get_inverse_mass() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsDirectBodyState", "get_inverse_mass");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

Vector3 PhysicsDirectBodyState::get_inverse_inertia() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsDirectBodyState", "get_inverse_inertia");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

void PhysicsDirectBodyState::set_linear_velocity(const Vector3 velocity) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsDirectBodyState", "set_linear_velocity");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, velocity);
}

Vector3 PhysicsDirectBodyState::get_linear_velocity() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsDirectBodyState", "get_linear_velocity");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

void PhysicsDirectBodyState::set_angular_velocity(const Vector3 velocity) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsDirectBodyState", "set_angular_velocity");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, velocity);
}

Vector3 PhysicsDirectBodyState::get_angular_velocity() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsDirectBodyState", "get_angular_velocity");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

void PhysicsDirectBodyState::set_transform(const Transform transform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsDirectBodyState", "set_transform");
	}
	___godot_icall_void_Transform(mb, (const Object *) this, transform);
}

Transform PhysicsDirectBodyState::get_transform() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsDirectBodyState", "get_transform");
	}
	return ___godot_icall_Transform(mb, (const Object *) this);
}

void PhysicsDirectBodyState::add_central_force(const Vector3 force) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsDirectBodyState", "add_central_force");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, force);
}

void PhysicsDirectBodyState::add_force(const Vector3 force, const Vector3 position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsDirectBodyState", "add_force");
	}
	___godot_icall_void_Vector3_Vector3(mb, (const Object *) this, force, position);
}

void PhysicsDirectBodyState::add_torque(const Vector3 torque) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsDirectBodyState", "add_torque");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, torque);
}

void PhysicsDirectBodyState::apply_impulse(const Vector3 position, const Vector3 j) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsDirectBodyState", "apply_impulse");
	}
	___godot_icall_void_Vector3_Vector3(mb, (const Object *) this, position, j);
}

void PhysicsDirectBodyState::apply_torque_impulse(const Vector3 j) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsDirectBodyState", "apply_torque_impulse");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, j);
}

void PhysicsDirectBodyState::set_sleep_state(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsDirectBodyState", "set_sleep_state");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool PhysicsDirectBodyState::is_sleeping() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsDirectBodyState", "is_sleeping");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

int64_t PhysicsDirectBodyState::get_contact_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsDirectBodyState", "get_contact_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

Vector3 PhysicsDirectBodyState::get_contact_local_position(const int64_t contact_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsDirectBodyState", "get_contact_local_position");
	}
	return ___godot_icall_Vector3_int(mb, (const Object *) this, contact_idx);
}

Vector3 PhysicsDirectBodyState::get_contact_local_normal(const int64_t contact_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsDirectBodyState", "get_contact_local_normal");
	}
	return ___godot_icall_Vector3_int(mb, (const Object *) this, contact_idx);
}

int64_t PhysicsDirectBodyState::get_contact_local_shape(const int64_t contact_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsDirectBodyState", "get_contact_local_shape");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, contact_idx);
}

RID PhysicsDirectBodyState::get_contact_collider(const int64_t contact_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsDirectBodyState", "get_contact_collider");
	}
	return ___godot_icall_RID_int(mb, (const Object *) this, contact_idx);
}

Vector3 PhysicsDirectBodyState::get_contact_collider_position(const int64_t contact_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsDirectBodyState", "get_contact_collider_position");
	}
	return ___godot_icall_Vector3_int(mb, (const Object *) this, contact_idx);
}

int64_t PhysicsDirectBodyState::get_contact_collider_id(const int64_t contact_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsDirectBodyState", "get_contact_collider_id");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, contact_idx);
}

Object *PhysicsDirectBodyState::get_contact_collider_object(const int64_t contact_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsDirectBodyState", "get_contact_collider_object");
	}
	return (Object *) ___godot_icall_Object_int(mb, (const Object *) this, contact_idx);
}

int64_t PhysicsDirectBodyState::get_contact_collider_shape(const int64_t contact_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsDirectBodyState", "get_contact_collider_shape");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, contact_idx);
}

Vector3 PhysicsDirectBodyState::get_contact_collider_velocity_at_position(const int64_t contact_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsDirectBodyState", "get_contact_collider_velocity_at_position");
	}
	return ___godot_icall_Vector3_int(mb, (const Object *) this, contact_idx);
}

double PhysicsDirectBodyState::get_step() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsDirectBodyState", "get_step");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void PhysicsDirectBodyState::integrate_forces() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsDirectBodyState", "integrate_forces");
	}
	___godot_icall_void(mb, (const Object *) this);
}

PhysicsDirectSpaceState *PhysicsDirectBodyState::get_space_state() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsDirectBodyState", "get_space_state");
	}
	return (PhysicsDirectSpaceState *) ___godot_icall_Object(mb, (const Object *) this);
}

}