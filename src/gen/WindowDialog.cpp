#include <WindowDialog.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <InputEvent.hpp>
#include <TextureButton.hpp>


namespace godot {


void *WindowDialog::___get_type_tag()
{
	return (void *) &WindowDialog::___get_type_tag;
}

void *WindowDialog::___get_base_type_tag()
{
	return (void *) &Popup::___get_type_tag;
}

WindowDialog *WindowDialog::_new()
{
	return (WindowDialog *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"WindowDialog")());
}
void WindowDialog::_gui_input(const Ref<InputEvent> arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("WindowDialog", "_gui_input");
	}
	___godot_icall_void_Object(mb, (const Object *) this, arg0.ptr());
}

void WindowDialog::set_title(const String title) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("WindowDialog", "set_title");
	}
	___godot_icall_void_String(mb, (const Object *) this, title);
}

String WindowDialog::get_title() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("WindowDialog", "get_title");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void WindowDialog::set_resizable(const bool resizable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("WindowDialog", "set_resizable");
	}
	___godot_icall_void_bool(mb, (const Object *) this, resizable);
}

bool WindowDialog::get_resizable() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("WindowDialog", "get_resizable");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void WindowDialog::_closed() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("WindowDialog", "_closed");
	}
	___godot_icall_void(mb, (const Object *) this);
}

TextureButton *WindowDialog::get_close_button() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("WindowDialog", "get_close_button");
	}
	return (TextureButton *) ___godot_icall_Object(mb, (const Object *) this);
}

}