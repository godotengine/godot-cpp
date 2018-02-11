#include <InputEventMouseMotion.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *InputEventMouseMotion::___get_type_tag()
{
	return (void *) &InputEventMouseMotion::___get_type_tag;
}

void *InputEventMouseMotion::___get_base_type_tag()
{
	return (void *) &InputEventMouse::___get_type_tag;
}

InputEventMouseMotion *InputEventMouseMotion::_new()
{
	return (InputEventMouseMotion *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"InputEventMouseMotion")());
}
void InputEventMouseMotion::set_relative(const Vector2 relative) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventMouseMotion", "set_relative");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, relative);
}

Vector2 InputEventMouseMotion::get_relative() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventMouseMotion", "get_relative");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void InputEventMouseMotion::set_speed(const Vector2 speed) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventMouseMotion", "set_speed");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, speed);
}

Vector2 InputEventMouseMotion::get_speed() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventMouseMotion", "get_speed");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

}