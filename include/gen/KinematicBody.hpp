#ifndef GODOT_CPP_KINEMATICBODY_HPP
#define GODOT_CPP_KINEMATICBODY_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "PhysicsBody.hpp"
namespace godot {

class KinematicCollision;

class KinematicBody : public PhysicsBody {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "KinematicBody"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static KinematicBody *_new();

	// methods
	Ref<KinematicCollision> move_and_collide(const Vector3 rel_vec, const bool infinite_inertia = true);
	Vector3 move_and_slide(const Vector3 linear_velocity, const Vector3 floor_normal = Vector3(0, 0, 0), const bool infinite_inertia = true, const double slope_stop_min_velocity = 0.05, const int64_t max_slides = 4, const double floor_max_angle = 0.785398);
	bool test_move(const Transform from, const Vector3 rel_vec, const bool infinite_inertia);
	bool is_on_floor() const;
	bool is_on_ceiling() const;
	bool is_on_wall() const;
	Vector3 get_floor_velocity() const;
	void set_axis_lock(const int64_t axis, const bool lock);
	bool get_axis_lock(const int64_t axis) const;
	void set_safe_margin(const double pixels);
	double get_safe_margin() const;
	int64_t get_slide_count() const;
	Ref<KinematicCollision> get_slide_collision(const int64_t slide_idx);

};

}

#endif