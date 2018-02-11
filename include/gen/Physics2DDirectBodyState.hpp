#ifndef GODOT_CPP_PHYSICS2DDIRECTBODYSTATE_HPP
#define GODOT_CPP_PHYSICS2DDIRECTBODYSTATE_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Object.hpp>
namespace godot {

class Object;
class Physics2DDirectSpaceState;

class Physics2DDirectBodyState : public Object {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Physics2DDirectBodyState"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants

	// methods
	Vector2 get_total_gravity() const;
	double get_total_linear_damp() const;
	double get_total_angular_damp() const;
	double get_inverse_mass() const;
	double get_inverse_inertia() const;
	void set_linear_velocity(const Vector2 velocity);
	Vector2 get_linear_velocity() const;
	void set_angular_velocity(const double velocity);
	double get_angular_velocity() const;
	void set_transform(const Transform2D transform);
	Transform2D get_transform() const;
	void set_sleep_state(const bool enabled);
	bool is_sleeping() const;
	int64_t get_contact_count() const;
	Vector2 get_contact_local_position(const int64_t contact_idx) const;
	Vector2 get_contact_local_normal(const int64_t contact_idx) const;
	int64_t get_contact_local_shape(const int64_t contact_idx) const;
	RID get_contact_collider(const int64_t contact_idx) const;
	Vector2 get_contact_collider_position(const int64_t contact_idx) const;
	int64_t get_contact_collider_id(const int64_t contact_idx) const;
	Object *get_contact_collider_object(const int64_t contact_idx) const;
	int64_t get_contact_collider_shape(const int64_t contact_idx) const;
	Variant get_contact_collider_shape_metadata(const int64_t contact_idx) const;
	Vector2 get_contact_collider_velocity_at_position(const int64_t contact_idx) const;
	double get_step() const;
	void integrate_forces();
	Physics2DDirectSpaceState *get_space_state();

};

}

#endif