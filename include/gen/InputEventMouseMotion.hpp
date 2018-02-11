#ifndef GODOT_CPP_INPUTEVENTMOUSEMOTION_HPP
#define GODOT_CPP_INPUTEVENTMOUSEMOTION_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <InputEventMouse.hpp>
namespace godot {


class InputEventMouseMotion : public InputEventMouse {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "InputEventMouseMotion"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static InputEventMouseMotion *_new();

	// methods
	void set_relative(const Vector2 relative);
	Vector2 get_relative() const;
	void set_speed(const Vector2 speed);
	Vector2 get_speed() const;

};

}

#endif