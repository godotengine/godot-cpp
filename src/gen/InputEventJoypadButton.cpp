#include <InputEventJoypadButton.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *InputEventJoypadButton::___get_type_tag()
{
	return (void *) &InputEventJoypadButton::___get_type_tag;
}

void *InputEventJoypadButton::___get_base_type_tag()
{
	return (void *) &InputEvent::___get_type_tag;
}

InputEventJoypadButton *InputEventJoypadButton::_new()
{
	return (InputEventJoypadButton *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"InputEventJoypadButton")());
}
void InputEventJoypadButton::set_button_index(const int64_t button_index) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventJoypadButton", "set_button_index");
	}
	___godot_icall_void_int(mb, (const Object *) this, button_index);
}

int64_t InputEventJoypadButton::get_button_index() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventJoypadButton", "get_button_index");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void InputEventJoypadButton::set_pressure(const double pressure) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventJoypadButton", "set_pressure");
	}
	___godot_icall_void_float(mb, (const Object *) this, pressure);
}

double InputEventJoypadButton::get_pressure() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventJoypadButton", "get_pressure");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void InputEventJoypadButton::set_pressed(const bool pressed) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventJoypadButton", "set_pressed");
	}
	___godot_icall_void_bool(mb, (const Object *) this, pressed);
}

}