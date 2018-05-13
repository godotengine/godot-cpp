#ifndef GODOT_CPP_COLORPICKER_HPP
#define GODOT_CPP_COLORPICKER_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "BoxContainer.hpp"
namespace godot {

class Object;
class InputEvent;

class ColorPicker : public BoxContainer {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "ColorPicker"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static ColorPicker *_new();

	// methods
	void set_pick_color(const Color color);
	Color get_pick_color() const;
	void set_raw_mode(const bool mode);
	bool is_raw_mode() const;
	void set_edit_alpha(const bool show);
	bool is_editing_alpha() const;
	void add_preset(const Color color);
	void _value_changed(const double arg0);
	void _html_entered(const String arg0);
	void _text_type_toggled();
	void _add_preset_pressed();
	void _screen_pick_pressed();
	void _sample_draw();
	void _update_presets();
	void _hsv_draw(const int64_t arg0, const Object *arg1);
	void _uv_input(const Ref<InputEvent> arg0);
	void _w_input(const Ref<InputEvent> arg0);
	void _preset_input(const Ref<InputEvent> arg0);
	void _screen_input(const Ref<InputEvent> arg0);
	void _focus_enter();
	void _focus_exit();
	void _html_focus_exit();

};

}

#endif