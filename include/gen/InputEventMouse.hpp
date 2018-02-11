#ifndef GODOT_CPP_INPUTEVENTMOUSE_HPP
#define GODOT_CPP_INPUTEVENTMOUSE_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <InputEventWithModifiers.hpp>
namespace godot {


class InputEventMouse : public InputEventWithModifiers {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "InputEventMouse"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants

	// methods
	void set_button_mask(const int64_t button_mask);
	int64_t get_button_mask() const;
	void set_position(const Vector2 position);
	Vector2 get_position() const;
	void set_global_position(const Vector2 global_position);
	Vector2 get_global_position() const;

};

}

#endif