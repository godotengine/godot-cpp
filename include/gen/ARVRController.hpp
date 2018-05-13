#ifndef GODOT_CPP_ARVRCONTROLLER_HPP
#define GODOT_CPP_ARVRCONTROLLER_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include "ARVRPositionalTracker.hpp"

#include "Spatial.hpp"
namespace godot {


class ARVRController : public Spatial {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "ARVRController"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static ARVRController *_new();

	// methods
	void set_controller_id(const int64_t controller_id);
	int64_t get_controller_id() const;
	String get_controller_name() const;
	int64_t get_joystick_id() const;
	int64_t is_button_pressed(const int64_t button) const;
	double get_joystick_axis(const int64_t axis) const;
	bool get_is_active() const;
	ARVRPositionalTracker::TrackerHand get_hand() const;
	double get_rumble() const;
	void set_rumble(const double rumble);

};

}

#endif