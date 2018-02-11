#include <InputEventAction.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *InputEventAction::___get_type_tag()
{
	return (void *) &InputEventAction::___get_type_tag;
}

void *InputEventAction::___get_base_type_tag()
{
	return (void *) &InputEvent::___get_type_tag;
}

InputEventAction *InputEventAction::_new()
{
	return (InputEventAction *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"InputEventAction")());
}
void InputEventAction::set_action(const String action) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventAction", "set_action");
	}
	___godot_icall_void_String(mb, (const Object *) this, action);
}

String InputEventAction::get_action() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventAction", "get_action");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void InputEventAction::set_pressed(const bool pressed) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventAction", "set_pressed");
	}
	___godot_icall_void_bool(mb, (const Object *) this, pressed);
}

}