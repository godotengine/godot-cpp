#include <RigidBody2D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Physics2DDirectBodyState.hpp>
#include <Physics2DTestMotionResult.hpp>
#include <Object.hpp>


namespace godot {


void *RigidBody2D::___get_type_tag()
{
	return (void *) &RigidBody2D::___get_type_tag;
}

void *RigidBody2D::___get_base_type_tag()
{
	return (void *) &PhysicsBody2D::___get_type_tag;
}

RigidBody2D *RigidBody2D::_new()
{
	return (RigidBody2D *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"RigidBody2D")());
}
void RigidBody2D::_integrate_forces(const Physics2DDirectBodyState *state) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "_integrate_forces");
	}
	___godot_icall_void_Object(mb, (const Object *) this, state);
}

void RigidBody2D::set_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "set_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

RigidBody2D::Mode RigidBody2D::get_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "get_mode");
	}
	return (RigidBody2D::Mode) ___godot_icall_int(mb, (const Object *) this);
}

void RigidBody2D::set_mass(const double mass) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "set_mass");
	}
	___godot_icall_void_float(mb, (const Object *) this, mass);
}

double RigidBody2D::get_mass() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "get_mass");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

double RigidBody2D::get_inertia() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "get_inertia");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void RigidBody2D::set_inertia(const double inertia) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "set_inertia");
	}
	___godot_icall_void_float(mb, (const Object *) this, inertia);
}

void RigidBody2D::set_weight(const double weight) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "set_weight");
	}
	___godot_icall_void_float(mb, (const Object *) this, weight);
}

double RigidBody2D::get_weight() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "get_weight");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void RigidBody2D::set_friction(const double friction) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "set_friction");
	}
	___godot_icall_void_float(mb, (const Object *) this, friction);
}

double RigidBody2D::get_friction() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "get_friction");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void RigidBody2D::set_bounce(const double bounce) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "set_bounce");
	}
	___godot_icall_void_float(mb, (const Object *) this, bounce);
}

double RigidBody2D::get_bounce() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "get_bounce");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void RigidBody2D::set_gravity_scale(const double gravity_scale) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "set_gravity_scale");
	}
	___godot_icall_void_float(mb, (const Object *) this, gravity_scale);
}

double RigidBody2D::get_gravity_scale() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "get_gravity_scale");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void RigidBody2D::set_linear_damp(const double linear_damp) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "set_linear_damp");
	}
	___godot_icall_void_float(mb, (const Object *) this, linear_damp);
}

double RigidBody2D::get_linear_damp() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "get_linear_damp");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void RigidBody2D::set_angular_damp(const double angular_damp) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "set_angular_damp");
	}
	___godot_icall_void_float(mb, (const Object *) this, angular_damp);
}

double RigidBody2D::get_angular_damp() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "get_angular_damp");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void RigidBody2D::set_linear_velocity(const Vector2 linear_velocity) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "set_linear_velocity");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, linear_velocity);
}

Vector2 RigidBody2D::get_linear_velocity() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "get_linear_velocity");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void RigidBody2D::set_angular_velocity(const double angular_velocity) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "set_angular_velocity");
	}
	___godot_icall_void_float(mb, (const Object *) this, angular_velocity);
}

double RigidBody2D::get_angular_velocity() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "get_angular_velocity");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void RigidBody2D::set_max_contacts_reported(const int64_t amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "set_max_contacts_reported");
	}
	___godot_icall_void_int(mb, (const Object *) this, amount);
}

int64_t RigidBody2D::get_max_contacts_reported() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "get_max_contacts_reported");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void RigidBody2D::set_use_custom_integrator(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "set_use_custom_integrator");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool RigidBody2D::is_using_custom_integrator() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "is_using_custom_integrator");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void RigidBody2D::set_contact_monitor(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "set_contact_monitor");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool RigidBody2D::is_contact_monitor_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "is_contact_monitor_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void RigidBody2D::set_continuous_collision_detection_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "set_continuous_collision_detection_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

RigidBody2D::CCDMode RigidBody2D::get_continuous_collision_detection_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "get_continuous_collision_detection_mode");
	}
	return (RigidBody2D::CCDMode) ___godot_icall_int(mb, (const Object *) this);
}

void RigidBody2D::set_axis_velocity(const Vector2 axis_velocity) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "set_axis_velocity");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, axis_velocity);
}

void RigidBody2D::apply_impulse(const Vector2 offset, const Vector2 impulse) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "apply_impulse");
	}
	___godot_icall_void_Vector2_Vector2(mb, (const Object *) this, offset, impulse);
}

void RigidBody2D::set_applied_force(const Vector2 force) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "set_applied_force");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, force);
}

Vector2 RigidBody2D::get_applied_force() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "get_applied_force");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void RigidBody2D::set_applied_torque(const double torque) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "set_applied_torque");
	}
	___godot_icall_void_float(mb, (const Object *) this, torque);
}

double RigidBody2D::get_applied_torque() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "get_applied_torque");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void RigidBody2D::add_force(const Vector2 offset, const Vector2 force) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "add_force");
	}
	___godot_icall_void_Vector2_Vector2(mb, (const Object *) this, offset, force);
}

void RigidBody2D::set_sleeping(const bool sleeping) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "set_sleeping");
	}
	___godot_icall_void_bool(mb, (const Object *) this, sleeping);
}

bool RigidBody2D::is_sleeping() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "is_sleeping");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void RigidBody2D::set_can_sleep(const bool able_to_sleep) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "set_can_sleep");
	}
	___godot_icall_void_bool(mb, (const Object *) this, able_to_sleep);
}

bool RigidBody2D::is_able_to_sleep() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "is_able_to_sleep");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

bool RigidBody2D::test_motion(const Vector2 motion, const bool infinite_inertia, const double margin, const Ref<Physics2DTestMotionResult> result) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "test_motion");
	}
	return ___godot_icall_bool_Vector2_bool_float_Object(mb, (const Object *) this, motion, infinite_inertia, margin, result.ptr());
}

void RigidBody2D::_direct_state_changed(const Object *arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "_direct_state_changed");
	}
	___godot_icall_void_Object(mb, (const Object *) this, arg0);
}

void RigidBody2D::_body_enter_tree(const int64_t arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "_body_enter_tree");
	}
	___godot_icall_void_int(mb, (const Object *) this, arg0);
}

void RigidBody2D::_body_exit_tree(const int64_t arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "_body_exit_tree");
	}
	___godot_icall_void_int(mb, (const Object *) this, arg0);
}

Array RigidBody2D::get_colliding_bodies() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RigidBody2D", "get_colliding_bodies");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

}