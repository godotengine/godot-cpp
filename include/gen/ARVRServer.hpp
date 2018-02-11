#ifndef GODOT_CPP_ARVRSERVER_HPP
#define GODOT_CPP_ARVRSERVER_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Object.hpp>
namespace godot {

class ARVRInterface;
class ARVRPositionalTracker;

class ARVRServer : public Object {
	static ARVRServer *_singleton;

	ARVRServer();

public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline ARVRServer *get_singleton()
	{
		if (!ARVRServer::_singleton) {
			ARVRServer::_singleton = new ARVRServer;
		}
		return ARVRServer::_singleton;
	}

	static inline const char *___get_class_name() { return (const char *) "ARVRServer"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum RotationMode {
		RESET_BUT_KEEP_TILT = 1,
		DONT_RESET_ROTATION = 2,
		RESET_FULL_ROTATION = 0,
	};
	enum TrackerType {
		TRACKER_BASESTATION = 2,
		TRACKER_CONTROLLER = 1,
		TRACKER_ANY = 255,
		TRACKER_ANY_KNOWN = 127,
		TRACKER_ANCHOR = 4,
		TRACKER_UNKNOWN = 128,
	};

	// constants

	// methods
	double get_world_scale() const;
	void set_world_scale(const double arg0);
	Transform get_reference_frame() const;
	void center_on_hmd(const int64_t rotation_mode, const bool keep_height);
	Transform get_hmd_transform();
	int64_t get_interface_count() const;
	Ref<ARVRInterface> get_interface(const int64_t idx) const;
	Array get_interfaces() const;
	Ref<ARVRInterface> find_interface(const String name) const;
	int64_t get_tracker_count() const;
	ARVRPositionalTracker *get_tracker(const int64_t idx) const;
	Ref<ARVRInterface> get_primary_interface() const;
	void set_primary_interface(const Ref<ARVRInterface> interface);
	int64_t get_last_process_usec();
	int64_t get_last_commit_usec();
	int64_t get_last_frame_usec();

};

}

#endif