#include <InputEventKey.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *InputEventKey::___get_type_tag()
{
	return (void *) &InputEventKey::___get_type_tag;
}

void *InputEventKey::___get_base_type_tag()
{
	return (void *) &InputEventWithModifiers::___get_type_tag;
}

InputEventKey *InputEventKey::_new()
{
	return (InputEventKey *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"InputEventKey")());
}
void InputEventKey::set_pressed(const bool pressed) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventKey", "set_pressed");
	}
	___godot_icall_void_bool(mb, (const Object *) this, pressed);
}

void InputEventKey::set_scancode(const int64_t scancode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventKey", "set_scancode");
	}
	___godot_icall_void_int(mb, (const Object *) this, scancode);
}

int64_t InputEventKey::get_scancode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventKey", "get_scancode");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void InputEventKey::set_unicode(const int64_t unicode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventKey", "set_unicode");
	}
	___godot_icall_void_int(mb, (const Object *) this, unicode);
}

int64_t InputEventKey::get_unicode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventKey", "get_unicode");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void InputEventKey::set_echo(const bool echo) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventKey", "set_echo");
	}
	___godot_icall_void_bool(mb, (const Object *) this, echo);
}

int64_t InputEventKey::get_scancode_with_modifiers() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventKey", "get_scancode_with_modifiers");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

}