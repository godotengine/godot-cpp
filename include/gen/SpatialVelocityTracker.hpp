#ifndef GODOT_CPP_SPATIALVELOCITYTRACKER_HPP
#define GODOT_CPP_SPATIALVELOCITYTRACKER_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Reference.hpp"
namespace godot {


class SpatialVelocityTracker : public Reference {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "SpatialVelocityTracker"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static SpatialVelocityTracker *_new();

	// methods
	void set_track_physics_step(const bool enable);
	bool is_tracking_physics_step() const;
	void update_position(const Vector3 position);
	Vector3 get_tracked_linear_velocity() const;
	void reset(const Vector3 position);

};

}

#endif