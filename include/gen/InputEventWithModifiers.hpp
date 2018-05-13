#ifndef GODOT_CPP_INPUTEVENTWITHMODIFIERS_HPP
#define GODOT_CPP_INPUTEVENTWITHMODIFIERS_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "InputEvent.hpp"
namespace godot {


class InputEventWithModifiers : public InputEvent {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "InputEventWithModifiers"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants

	// methods
	void set_alt(const bool enable);
	bool get_alt() const;
	void set_shift(const bool enable);
	bool get_shift() const;
	void set_control(const bool enable);
	bool get_control() const;
	void set_metakey(const bool enable);
	bool get_metakey() const;
	void set_command(const bool enable);
	bool get_command() const;

};

}

#endif