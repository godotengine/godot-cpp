#ifndef GODOT_CPP_COLORPICKERBUTTON_HPP
#define GODOT_CPP_COLORPICKERBUTTON_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Button.hpp"
namespace godot {

class ColorPicker;
class PopupPanel;

class ColorPickerButton : public Button {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "ColorPickerButton"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static ColorPickerButton *_new();

	// methods
	void set_pick_color(const Color color);
	Color get_pick_color() const;
	ColorPicker *get_picker() const;
	PopupPanel *get_popup() const;
	void set_edit_alpha(const bool show);
	bool is_editing_alpha() const;
	void _color_changed(const Color arg0);
	void _modal_closed();

};

}

#endif