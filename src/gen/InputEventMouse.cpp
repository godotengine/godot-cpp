#include <InputEventMouse.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *InputEventMouse::___get_type_tag()
{
	return (void *) &InputEventMouse::___get_type_tag;
}

void *InputEventMouse::___get_base_type_tag()
{
	return (void *) &InputEventWithModifiers::___get_type_tag;
}

void InputEventMouse::set_button_mask(const int64_t button_mask) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventMouse", "set_button_mask");
	}
	___godot_icall_void_int(mb, (const Object *) this, button_mask);
}

int64_t InputEventMouse::get_button_mask() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventMouse", "get_button_mask");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void InputEventMouse::set_position(const Vector2 position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventMouse", "set_position");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, position);
}

Vector2 InputEventMouse::get_position() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventMouse", "get_position");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void InputEventMouse::set_global_position(const Vector2 global_position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventMouse", "set_global_position");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, global_position);
}

Vector2 InputEventMouse::get_global_position() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventMouse", "get_global_position");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

}