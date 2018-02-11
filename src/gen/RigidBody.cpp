#include <RigidBody.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <PhysicsDirectBodyState.hpp>
#include <Object.hpp>


namespace godot {


void *RigidBody::___get_type_tag()
{
	return (void *) &RigidBody::___get_type_tag;
}

void *RigidBody::___get_base_type_tag()
{
	return (void *) &PhysicsBody::___get_type_tag;
}

RigidBody *RigidBody::_new()
{
	return (RigidBody *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"RigidBody")());
}
void RigidBody::_integrate_forces(const PhysicsDirectBodyState *state) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody", "_integrate_forces");
	}
	___godot_icall_void_Object(mb, (const Object *) this, state);
}

void RigidBody::set_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody", "set_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

RigidBody::Mode RigidBody::get_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody", "get_mode");
	}
	return (RigidBody::Mode) ___godot_icall_int(mb, (const Object *) this);
}

void RigidBody::set_mass(const double mass) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody", "set_mass");
	}
	___godot_icall_void_float(mb, (const Object *) this, mass);
}

double RigidBody::get_mass() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody", "get_mass");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void RigidBody::set_weight(const double weight) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody", "set_weight");
	}
	___godot_icall_void_float(mb, (const Object *) this, weight);
}

double RigidBody::get_weight() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody", "get_weight");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void RigidBody::set_friction(const double friction) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody", "set_friction");
	}
	___godot_icall_void_float(mb, (const Object *) this, friction);
}

double RigidBody::get_friction() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody", "get_friction");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void RigidBody::set_bounce(const double bounce) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody", "set_bounce");
	}
	___godot_icall_void_float(mb, (const Object *) this, bounce);
}

double RigidBody::get_bounce() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody", "get_bounce");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void RigidBody::set_linear_velocity(const Vector3 linear_velocity) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody", "set_linear_velocity");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, linear_velocity);
}

Vector3 RigidBody::get_linear_velocity() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody", "get_linear_velocity");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

void RigidBody::set_angular_velocity(const Vector3 angular_velocity) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody", "set_angular_velocity");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, angular_velocity);
}

Vector3 RigidBody::get_angular_velocity() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody", "get_angular_velocity");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

void RigidBody::set_gravity_scale(const double gravity_scale) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody", "set_gravity_scale");
	}
	___godot_icall_void_float(mb, (const Object *) this, gravity_scale);
}

double RigidBody::get_gravity_scale() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody", "get_gravity_scale");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void RigidBody::set_linear_damp(const double linear_damp) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody", "set_linear_damp");
	}
	___godot_icall_void_float(mb, (const Object *) this, linear_damp);
}

double RigidBody::get_linear_damp() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody", "get_linear_damp");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void RigidBody::set_angular_damp(const double angular_damp) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody", "set_angular_damp");
	}
	___godot_icall_void_float(mb, (const Object *) this, angular_damp);
}

double RigidBody::get_angular_damp() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody", "get_angular_damp");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void RigidBody::set_max_contacts_reported(const int64_t amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody", "set_max_contacts_reported");
	}
	___godot_icall_void_int(mb, (const Object *) this, amount);
}

int64_t RigidBody::get_max_contacts_reported() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody", "get_max_contacts_reported");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void RigidBody::set_use_custom_integrator(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody", "set_use_custom_integrator");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool RigidBody::is_using_custom_integrator() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody", "is_using_custom_integrator");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void RigidBody::set_contact_monitor(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody", "set_contact_monitor");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool RigidBody::is_contact_monitor_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody", "is_contact_monitor_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void RigidBody::set_use_continuous_collision_detection(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody", "set_use_continuous_collision_detection");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool RigidBody::is_using_continuous_collision_detection() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody", "is_using_continuous_collision_detection");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void RigidBody::set_axis_velocity(const Vector3 axis_velocity) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody", "set_axis_velocity");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, axis_velocity);
}

void RigidBody::apply_impulse(const Vector3 position, const Vector3 impulse) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody", "apply_impulse");
	}
	___godot_icall_void_Vector3_Vector3(mb, (const Object *) this, position, impulse);
}

void RigidBody::apply_torque_impulse(const Vector3 impulse) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody", "apply_torque_impulse");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, impulse);
}

void RigidBody::set_sleeping(const bool sleeping) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody", "set_sleeping");
	}
	___godot_icall_void_bool(mb, (const Object *) this, sleeping);
}

bool RigidBody::is_sleeping() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody", "is_sleeping");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void RigidBody::set_can_sleep(const bool able_to_sleep) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody", "set_can_sleep");
	}
	___godot_icall_void_bool(mb, (const Object *) this, able_to_sleep);
}

bool RigidBody::is_able_to_sleep() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody", "is_able_to_sleep");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void RigidBody::_direct_state_changed(const Object *arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody", "_direct_state_changed");
	}
	___godot_icall_void_Object(mb, (const Object *) this, arg0);
}

void RigidBody::_body_enter_tree(const int64_t arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody", "_body_enter_tree");
	}
	___godot_icall_void_int(mb, (const Object *) this, arg0);
}

void RigidBody::_body_exit_tree(const int64_t arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody", "_body_exit_tree");
	}
	___godot_icall_void_int(mb, (const Object *) this, arg0);
}

void RigidBody::set_axis_lock(const int64_t axis, const bool lock) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody", "set_axis_lock");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, axis, lock);
}

bool RigidBody::get_axis_lock(const int64_t axis) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody", "get_axis_lock");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, axis);
}

Array RigidBody::get_colliding_bodies() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody", "get_colliding_bodies");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

}