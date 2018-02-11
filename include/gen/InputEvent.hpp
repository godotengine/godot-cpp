#ifndef GODOT_CPP_INPUTEVENT_HPP
#define GODOT_CPP_INPUTEVENT_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Resource.hpp>
namespace godot {

class InputEvent;

class InputEvent : public Resource {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "InputEvent"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants

	// methods
	void set_device(const int64_t device);
	int64_t get_device() const;
	bool is_pressed() const;
	bool is_action(const String action) const;
	bool is_action_pressed(const String action) const;
	bool is_action_released(const String action) const;
	bool is_echo() const;
	String as_text() const;
	bool action_match(const Ref<InputEvent> event) const;
	bool shortcut_match(const Ref<InputEvent> event) const;
	bool is_action_type() const;
	Ref<InputEvent> xformed_by(const Transform2D xform, const Vector2 local_ofs = Vector2(0, 0)) const;

};

}

#endif