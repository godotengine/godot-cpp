#include <InputEventJoypadMotion.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *InputEventJoypadMotion::___get_type_tag()
{
	return (void *) &InputEventJoypadMotion::___get_type_tag;
}

void *InputEventJoypadMotion::___get_base_type_tag()
{
	return (void *) &InputEvent::___get_type_tag;
}

InputEventJoypadMotion *InputEventJoypadMotion::_new()
{
	return (InputEventJoypadMotion *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"InputEventJoypadMotion")());
}
void InputEventJoypadMotion::set_axis(const int64_t axis) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventJoypadMotion", "set_axis");
	}
	___godot_icall_void_int(mb, (const Object *) this, axis);
}

int64_t InputEventJoypadMotion::get_axis() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventJoypadMotion", "get_axis");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void InputEventJoypadMotion::set_axis_value(const double axis_value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventJoypadMotion", "set_axis_value");
	}
	___godot_icall_void_float(mb, (const Object *) this, axis_value);
}

double InputEventJoypadMotion::get_axis_value() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventJoypadMotion", "get_axis_value");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

}