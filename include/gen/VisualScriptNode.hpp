#ifndef GODOT_CPP_VISUALSCRIPTNODE_HPP
#define GODOT_CPP_VISUALSCRIPTNODE_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Resource.hpp"
namespace godot {

class VisualScript;

class VisualScriptNode : public Resource {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "VisualScriptNode"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants

	// methods
	Ref<VisualScript> get_visual_script() const;
	void set_default_input_value(const int64_t port_idx, const Variant value);
	Variant get_default_input_value(const int64_t port_idx) const;
	void ports_changed_notify();
	void _set_default_input_values(const Array values);
	Array _get_default_input_values() const;

};

}

#endif