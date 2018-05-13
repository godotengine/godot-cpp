#ifndef GODOT_CPP_AREA2D_HPP
#define GODOT_CPP_AREA2D_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include "Area2D.hpp"

#include "CollisionObject2D.hpp"
namespace godot {

class Object;

class Area2D : public CollisionObject2D {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Area2D"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum SpaceOverride {
		SPACE_OVERRIDE_COMBINE_REPLACE = 2,
		SPACE_OVERRIDE_COMBINE = 1,
		SPACE_OVERRIDE_REPLACE = 3,
		SPACE_OVERRIDE_DISABLED = 0,
		SPACE_OVERRIDE_REPLACE_COMBINE = 4,
	};

	// constants


	static Area2D *_new();

	// methods
	void _body_enter_tree(const int64_t id);
	void _body_exit_tree(const int64_t id);
	void _area_enter_tree(const int64_t id);
	void _area_exit_tree(const int64_t id);
	void set_space_override_mode(const int64_t space_override_mode);
	Area2D::SpaceOverride get_space_override_mode() const;
	void set_gravity_is_point(const bool enable);
	bool is_gravity_a_point() const;
	void set_gravity_distance_scale(const double distance_scale);
	double get_gravity_distance_scale() const;
	void set_gravity_vector(const Vector2 vector);
	Vector2 get_gravity_vector() const;
	void set_gravity(const double gravity);
	double get_gravity() const;
	void set_linear_damp(const double linear_damp);
	double get_linear_damp() const;
	void set_angular_damp(const double angular_damp);
	double get_angular_damp() const;
	void set_priority(const double priority);
	double get_priority() const;
	void set_collision_mask(const int64_t collision_mask);
	int64_t get_collision_mask() const;
	void set_collision_layer(const int64_t collision_layer);
	int64_t get_collision_layer() const;
	void set_collision_mask_bit(const int64_t bit, const bool value);
	bool get_collision_mask_bit(const int64_t bit) const;
	void set_collision_layer_bit(const int64_t bit, const bool value);
	bool get_collision_layer_bit(const int64_t bit) const;
	void set_monitoring(const bool enable);
	bool is_monitoring() const;
	void set_monitorable(const bool enable);
	bool is_monitorable() const;
	Array get_overlapping_bodies() const;
	Array get_overlapping_areas() const;
	bool overlaps_body(const Object *body) const;
	bool overlaps_area(const Object *area) const;
	void set_audio_bus_name(const String name);
	String get_audio_bus_name() const;
	void set_audio_bus_override(const bool enable);
	bool is_overriding_audio_bus() const;
	void _body_inout(const int64_t arg0, const RID arg1, const int64_t arg2, const int64_t arg3, const int64_t arg4);
	void _area_inout(const int64_t arg0, const RID arg1, const int64_t arg2, const int64_t arg3, const int64_t arg4);

};

}

#endif