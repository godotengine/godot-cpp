#ifndef GODOT_CPP_INPUTEVENTSCREENDRAG_HPP
#define GODOT_CPP_INPUTEVENTSCREENDRAG_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <InputEvent.hpp>
namespace godot {


class InputEventScreenDrag : public InputEvent {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "InputEventScreenDrag"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static InputEventScreenDrag *_new();

	// methods
	void set_index(const int64_t index);
	int64_t get_index() const;
	void set_position(const Vector2 position);
	Vector2 get_position() const;
	void set_relative(const Vector2 relative);
	Vector2 get_relative() const;
	void set_speed(const Vector2 speed);
	Vector2 get_speed() const;

};

}

#endif