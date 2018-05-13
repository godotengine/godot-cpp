#ifndef GODOT_CPP_VISIBILITYENABLER_HPP
#define GODOT_CPP_VISIBILITYENABLER_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "VisibilityNotifier.hpp"
namespace godot {

class Object;

class VisibilityEnabler : public VisibilityNotifier {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "VisibilityEnabler"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum Enabler {
		ENABLER_FREEZE_BODIES = 1,
		ENABLER_PAUSE_ANIMATIONS = 0,
		ENABLER_MAX = 2,
	};

	// constants


	static VisibilityEnabler *_new();

	// methods
	void set_enabler(const int64_t enabler, const bool enabled);
	bool is_enabler_enabled(const int64_t enabler) const;
	void _node_removed(const Object *arg0);

};

}

#endif