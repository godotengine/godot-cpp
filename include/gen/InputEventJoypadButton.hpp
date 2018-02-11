#ifndef GODOT_CPP_INPUTEVENTJOYPADBUTTON_HPP
#define GODOT_CPP_INPUTEVENTJOYPADBUTTON_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <InputEvent.hpp>
namespace godot {


class InputEventJoypadButton : public InputEvent {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "InputEventJoypadButton"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static InputEventJoypadButton *_new();

	// methods
	void set_button_index(const int64_t button_index);
	int64_t get_button_index() const;
	void set_pressure(const double pressure);
	double get_pressure() const;
	void set_pressed(const bool pressed);

};

}

#endif