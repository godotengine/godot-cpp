#ifndef GODOT_CPP_VISIBILITYENABLER2D_HPP
#define GODOT_CPP_VISIBILITYENABLER2D_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <VisibilityNotifier2D.hpp>
namespace godot {

class Object;

class VisibilityEnabler2D : public VisibilityNotifier2D {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "VisibilityEnabler2D"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum Enabler {
		ENABLER_PAUSE_PARTICLES = 2,
		ENABLER_PARENT_PROCESS = 3,
		ENABLER_FREEZE_BODIES = 1,
		ENABLER_PARENT_PHYSICS_PROCESS = 4,
		ENABLER_PAUSE_ANIMATED_SPRITES = 5,
		ENABLER_MAX = 6,
		ENABLER_PAUSE_ANIMATIONS = 0,
	};

	// constants


	static VisibilityEnabler2D *_new();

	// methods
	void set_enabler(const int64_t enabler, const bool enabled);
	bool is_enabler_enabled(const int64_t enabler) const;
	void _node_removed(const Object *arg0);

};

}

#endif