#ifndef GODOT_CPP_INPUTEVENTKEY_HPP
#define GODOT_CPP_INPUTEVENTKEY_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <InputEventWithModifiers.hpp>
namespace godot {


class InputEventKey : public InputEventWithModifiers {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "InputEventKey"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static InputEventKey *_new();

	// methods
	void set_pressed(const bool pressed);
	void set_scancode(const int64_t scancode);
	int64_t get_scancode() const;
	void set_unicode(const int64_t unicode);
	int64_t get_unicode() const;
	void set_echo(const bool echo);
	int64_t get_scancode_with_modifiers() const;

};

}

#endif