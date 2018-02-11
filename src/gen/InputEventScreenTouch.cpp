#include <InputEventScreenTouch.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *InputEventScreenTouch::___get_type_tag()
{
	return (void *) &InputEventScreenTouch::___get_type_tag;
}

void *InputEventScreenTouch::___get_base_type_tag()
{
	return (void *) &InputEvent::___get_type_tag;
}

InputEventScreenTouch *InputEventScreenTouch::_new()
{
	return (InputEventScreenTouch *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"InputEventScreenTouch")());
}
void InputEventScreenTouch::set_index(const int64_t index) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventScreenTouch", "set_index");
	}
	___godot_icall_void_int(mb, (const Object *) this, index);
}

int64_t InputEventScreenTouch::get_index() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventScreenTouch", "get_index");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void InputEventScreenTouch::set_position(const Vector2 position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventScreenTouch", "set_position");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, position);
}

Vector2 InputEventScreenTouch::get_position() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventScreenTouch", "get_position");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void InputEventScreenTouch::set_pressed(const bool pressed) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventScreenTouch", "set_pressed");
	}
	___godot_icall_void_bool(mb, (const Object *) this, pressed);
}

}