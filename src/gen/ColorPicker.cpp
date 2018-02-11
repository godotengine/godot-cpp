#include <ColorPicker.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Object.hpp>
#include <InputEvent.hpp>


namespace godot {


void *ColorPicker::___get_type_tag()
{
	return (void *) &ColorPicker::___get_type_tag;
}

void *ColorPicker::___get_base_type_tag()
{
	return (void *) &BoxContainer::___get_type_tag;
}

ColorPicker *ColorPicker::_new()
{
	return (ColorPicker *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"ColorPicker")());
}
void ColorPicker::set_pick_color(const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ColorPicker", "set_pick_color");
	}
	___godot_icall_void_Color(mb, (const Object *) this, color);
}

Color ColorPicker::get_pick_color() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ColorPicker", "get_pick_color");
	}
	return ___godot_icall_Color(mb, (const Object *) this);
}

void ColorPicker::set_raw_mode(const bool mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ColorPicker", "set_raw_mode");
	}
	___godot_icall_void_bool(mb, (const Object *) this, mode);
}

bool ColorPicker::is_raw_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ColorPicker", "is_raw_mode");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void ColorPicker::set_edit_alpha(const bool show) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ColorPicker", "set_edit_alpha");
	}
	___godot_icall_void_bool(mb, (const Object *) this, show);
}

bool ColorPicker::is_editing_alpha() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ColorPicker", "is_editing_alpha");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void ColorPicker::add_preset(const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ColorPicker", "add_preset");
	}
	___godot_icall_void_Color(mb, (const Object *) this, color);
}

void ColorPicker::_value_changed(const double arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ColorPicker", "_value_changed");
	}
	___godot_icall_void_float(mb, (const Object *) this, arg0);
}

void ColorPicker::_html_entered(const String arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ColorPicker", "_html_entered");
	}
	___godot_icall_void_String(mb, (const Object *) this, arg0);
}

void ColorPicker::_text_type_toggled() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ColorPicker", "_text_type_toggled");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void ColorPicker::_add_preset_pressed() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ColorPicker", "_add_preset_pressed");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void ColorPicker::_screen_pick_pressed() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ColorPicker", "_screen_pick_pressed");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void ColorPicker::_sample_draw() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ColorPicker", "_sample_draw");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void ColorPicker::_update_presets() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ColorPicker", "_update_presets");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void ColorPicker::_hsv_draw(const int64_t arg0, const Object *arg1) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ColorPicker", "_hsv_draw");
	}
	___godot_icall_void_int_Object(mb, (const Object *) this, arg0, arg1);
}

void ColorPicker::_uv_input(const Ref<InputEvent> arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ColorPicker", "_uv_input");
	}
	___godot_icall_void_Object(mb, (const Object *) this, arg0.ptr());
}

void ColorPicker::_w_input(const Ref<InputEvent> arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ColorPicker", "_w_input");
	}
	___godot_icall_void_Object(mb, (const Object *) this, arg0.ptr());
}

void ColorPicker::_preset_input(const Ref<InputEvent> arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ColorPicker", "_preset_input");
	}
	___godot_icall_void_Object(mb, (const Object *) this, arg0.ptr());
}

void ColorPicker::_screen_input(const Ref<InputEvent> arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ColorPicker", "_screen_input");
	}
	___godot_icall_void_Object(mb, (const Object *) this, arg0.ptr());
}

void ColorPicker::_focus_enter() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ColorPicker", "_focus_enter");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void ColorPicker::_focus_exit() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ColorPicker", "_focus_exit");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void ColorPicker::_html_focus_exit() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ColorPicker", "_html_focus_exit");
	}
	___godot_icall_void(mb, (const Object *) this);
}

}