#ifndef GODOT_CPP_INPUTEVENTACTION_HPP
#define GODOT_CPP_INPUTEVENTACTION_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <InputEvent.hpp>
namespace godot {


class InputEventAction : public InputEvent {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "InputEventAction"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static InputEventAction *_new();

	// methods
	void set_action(const String action);
	String get_action() const;
	void set_pressed(const bool pressed);

};

}

#endif