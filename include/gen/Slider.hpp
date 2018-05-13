#ifndef GODOT_CPP_SLIDER_HPP
#define GODOT_CPP_SLIDER_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Range.hpp"
namespace godot {

class InputEvent;

class Slider : public Range {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Slider"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants

	// methods
	void _gui_input(const Ref<InputEvent> arg0);
	void set_ticks(const int64_t count);
	int64_t get_ticks() const;
	bool get_ticks_on_borders() const;
	void set_ticks_on_borders(const bool ticks_on_border);
	void set_editable(const bool editable);
	bool is_editable() const;

};

}

#endif