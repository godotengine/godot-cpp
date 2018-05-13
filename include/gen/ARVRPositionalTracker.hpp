#ifndef GODOT_CPP_ARVRPOSITIONALTRACKER_HPP
#define GODOT_CPP_ARVRPOSITIONALTRACKER_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include "ARVRServer.hpp"
#include "ARVRPositionalTracker.hpp"

#include "Object.hpp"
namespace godot {


class ARVRPositionalTracker : public Object {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "ARVRPositionalTracker"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum TrackerHand {
		TRACKER_HAND_UNKNOWN = 0,
		TRACKER_LEFT_HAND = 1,
		TRACKER_RIGHT_HAND = 2,
	};

	// constants


	static ARVRPositionalTracker *_new();

	// methods
	ARVRServer::TrackerType get_type() const;
	String get_name() const;
	int64_t get_joy_id() const;
	bool get_tracks_orientation() const;
	Basis get_orientation() const;
	bool get_tracks_position() const;
	Vector3 get_position() const;
	ARVRPositionalTracker::TrackerHand get_hand() const;
	Transform get_transform(const bool adjust_by_reference_frame) const;
	void _set_type(const int64_t type);
	void _set_name(const String name);
	void _set_joy_id(const int64_t joy_id);
	void _set_orientation(const Basis orientation);
	void _set_rw_position(const Vector3 rw_position);
	double get_rumble() const;
	void set_rumble(const double rumble);

};

}

#endif