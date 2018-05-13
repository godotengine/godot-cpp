#ifndef GODOT_CPP_SHORTCUT_HPP
#define GODOT_CPP_SHORTCUT_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Resource.hpp"
namespace godot {

class InputEvent;

class ShortCut : public Resource {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "ShortCut"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static ShortCut *_new();

	// methods
	void set_shortcut(const Ref<InputEvent> event);
	Ref<InputEvent> get_shortcut() const;
	bool is_valid() const;
	bool is_shortcut(const Ref<InputEvent> event) const;
	String get_as_text() const;

};

}

#endif