#ifndef GODOT_CPP_BASEBUTTON_HPP
#define GODOT_CPP_BASEBUTTON_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <BaseButton.hpp>
#include <Control.hpp>

#include <Control.hpp>
namespace godot {

class InputEvent;
class ShortCut;
class ButtonGroup;

class BaseButton : public Control {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "BaseButton"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum ActionMode {
		ACTION_MODE_BUTTON_PRESS = 0,
		ACTION_MODE_BUTTON_RELEASE = 1,
	};
	enum DrawMode {
		DRAW_DISABLED = 3,
		DRAW_PRESSED = 1,
		DRAW_NORMAL = 0,
		DRAW_HOVER = 2,
	};

	// constants

	// methods
	void _pressed();
	void _toggled(const bool button_pressed);
	void _gui_input(const Ref<InputEvent> arg0);
	void _unhandled_input(const Ref<InputEvent> arg0);
	void set_pressed(const bool pressed);
	bool is_pressed() const;
	bool is_hovered() const;
	void set_toggle_mode(const bool enabled);
	bool is_toggle_mode() const;
	void set_disabled(const bool disabled);
	bool is_disabled() const;
	void set_action_mode(const int64_t mode);
	BaseButton::ActionMode get_action_mode() const;
	BaseButton::DrawMode get_draw_mode() const;
	void set_enabled_focus_mode(const int64_t mode);
	Control::FocusMode get_enabled_focus_mode() const;
	void set_shortcut(const Ref<ShortCut> shortcut);
	Ref<ShortCut> get_shortcut() const;
	void set_button_group(const Ref<ButtonGroup> button_group);
	Ref<ButtonGroup> get_button_group() const;

};

}

#endif