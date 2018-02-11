#include <InputEventScreenDrag.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *InputEventScreenDrag::___get_type_tag()
{
	return (void *) &InputEventScreenDrag::___get_type_tag;
}

void *InputEventScreenDrag::___get_base_type_tag()
{
	return (void *) &InputEvent::___get_type_tag;
}

InputEventScreenDrag *InputEventScreenDrag::_new()
{
	return (InputEventScreenDrag *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"InputEventScreenDrag")());
}
void InputEventScreenDrag::set_index(const int64_t index) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventScreenDrag", "set_index");
	}
	___godot_icall_void_int(mb, (const Object *) this, index);
}

int64_t InputEventScreenDrag::get_index() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventScreenDrag", "get_index");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void InputEventScreenDrag::set_position(const Vector2 position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventScreenDrag", "set_position");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, position);
}

Vector2 InputEventScreenDrag::get_position() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventScreenDrag", "get_position");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void InputEventScreenDrag::set_relative(const Vector2 relative) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventScreenDrag", "set_relative");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, relative);
}

Vector2 InputEventScreenDrag::get_relative() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventScreenDrag", "get_relative");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void InputEventScreenDrag::set_speed(const Vector2 speed) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventScreenDrag", "set_speed");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, speed);
}

Vector2 InputEventScreenDrag::get_speed() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventScreenDrag", "get_speed");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

}