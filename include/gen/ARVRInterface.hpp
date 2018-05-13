#ifndef GODOT_CPP_ARVRINTERFACE_HPP
#define GODOT_CPP_ARVRINTERFACE_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include "ARVRInterface.hpp"

#include "Reference.hpp"
namespace godot {


class ARVRInterface : public Reference {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "ARVRInterface"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum Tracking_status {
		ARVR_NOT_TRACKING = 4,
		ARVR_NORMAL_TRACKING = 0,
		ARVR_EXCESSIVE_MOTION = 1,
		ARVR_UNKNOWN_TRACKING = 3,
		ARVR_INSUFFICIENT_FEATURES = 2,
	};
	enum Eyes {
		EYE_LEFT = 1,
		EYE_MONO = 0,
		EYE_RIGHT = 2,
	};
	enum Capabilities {
		ARVR_EXTERNAL = 8,
		ARVR_STEREO = 2,
		ARVR_MONO = 1,
		ARVR_AR = 4,
		ARVR_NONE = 0,
	};

	// constants

	// methods
	String get_name() const;
	int64_t get_capabilities() const;
	bool is_primary();
	void set_is_primary(const bool enable);
	bool is_initialized();
	void set_is_initialized(const bool initialized);
	bool initialize();
	void uninitialize();
	ARVRInterface::Tracking_status get_tracking_status() const;
	Vector2 get_render_targetsize();
	bool is_stereo();
	bool get_anchor_detection_is_enabled() const;
	void set_anchor_detection_is_enabled(const bool enable);

};

}

#endif