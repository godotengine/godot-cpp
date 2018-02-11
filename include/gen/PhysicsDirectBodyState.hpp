#ifndef GODOT_CPP_PHYSICSDIRECTBODYSTATE_HPP
#define GODOT_CPP_PHYSICSDIRECTBODYSTATE_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Object.hpp>
namespace godot {

class Object;
class PhysicsDirectSpaceState;

class PhysicsDirectBodyState : public Object {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "PhysicsDirectBodyState"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants

	// methods
	Vector3 get_total_gravity() const;
	double get_total_linear_damp() const;
	double get_total_angular_damp() const;
	Vector3 get_center_of_mass() const;
	Basis get_principal_inertia_axes() const;
	double get_inverse_mass() const;
	Vector3 get_inverse_inertia() const;
	void set_linear_velocity(const Vector3 velocity);
	Vector3 get_linear_velocity() const;
	void set_angular_velocity(const Vector3 velocity);
	Vector3 get_angular_velocity() const;
	void set_transform(const Transform transform);
	Transform get_transform() const;
	void add_central_force(const Vector3 force);
	void add_force(const Vector3 force, const Vector3 position);
	void add_torque(const Vector3 torque);
	void apply_impulse(const Vector3 position, const Vector3 j);
	void apply_torque_impulse(const Vector3 j);
	void set_sleep_state(const bool enabled);
	bool is_sleeping() const;
	int64_t get_contact_count() const;
	Vector3 get_contact_local_position(const int64_t contact_idx) const;
	Vector3 get_contact_local_normal(const int64_t contact_idx) const;
	int64_t get_contact_local_shape(const int64_t contact_idx) const;
	RID get_contact_collider(const int64_t contact_idx) const;
	Vector3 get_contact_collider_position(const int64_t contact_idx) const;
	int64_t get_contact_collider_id(const int64_t contact_idx) const;
	Object *get_contact_collider_object(const int64_t contact_idx) const;
	int64_t get_contact_collider_shape(const int64_t contact_idx) const;
	Vector3 get_contact_collider_velocity_at_position(const int64_t contact_idx) const;
	double get_step() const;
	void integrate_forces();
	PhysicsDirectSpaceState *get_space_state();

};

}

#endif