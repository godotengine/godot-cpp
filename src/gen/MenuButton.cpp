#include <MenuButton.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <PopupMenu.hpp>
#include <InputEvent.hpp>


namespace godot {


void *MenuButton::___get_type_tag()
{
	return (void *) &MenuButton::___get_type_tag;
}

void *MenuButton::___get_base_type_tag()
{
	return (void *) &Button::___get_type_tag;
}

MenuButton *MenuButton::_new()
{
	return (MenuButton *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"MenuButton")());
}
PopupMenu *MenuButton::get_popup() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MenuButton", "get_popup");
	}
	return (PopupMenu *) ___godot_icall_Object(mb, (const Object *) this);
}

void MenuButton::_unhandled_key_input(const Ref<InputEvent> arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MenuButton", "_unhandled_key_input");
	}
	___godot_icall_void_Object(mb, (const Object *) this, arg0.ptr());
}

void MenuButton::_set_items(const Array arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MenuButton", "_set_items");
	}
	___godot_icall_void_Array(mb, (const Object *) this, arg0);
}

Array MenuButton::_get_items() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MenuButton", "_get_items");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

void MenuButton::set_disable_shortcuts(const bool disabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MenuButton", "set_disable_shortcuts");
	}
	___godot_icall_void_bool(mb, (const Object *) this, disabled);
}

}