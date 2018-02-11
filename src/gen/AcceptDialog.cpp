#include <AcceptDialog.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Button.hpp>
#include <Label.hpp>
#include <Object.hpp>


namespace godot {


void *AcceptDialog::___get_type_tag()
{
	return (void *) &AcceptDialog::___get_type_tag;
}

void *AcceptDialog::___get_base_type_tag()
{
	return (void *) &WindowDialog::___get_type_tag;
}

AcceptDialog *AcceptDialog::_new()
{
	return (AcceptDialog *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"AcceptDialog")());
}
void AcceptDialog::_ok() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AcceptDialog", "_ok");
	}
	___godot_icall_void(mb, (const Object *) this);
}

Button *AcceptDialog::get_ok() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AcceptDialog", "get_ok");
	}
	return (Button *) ___godot_icall_Object(mb, (const Object *) this);
}

Label *AcceptDialog::get_label() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AcceptDialog", "get_label");
	}
	return (Label *) ___godot_icall_Object(mb, (const Object *) this);
}

void AcceptDialog::set_hide_on_ok(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AcceptDialog", "set_hide_on_ok");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool AcceptDialog::get_hide_on_ok() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AcceptDialog", "get_hide_on_ok");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

Button *AcceptDialog::add_button(const String text, const bool right, const String action) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AcceptDialog", "add_button");
	}
	return (Button *) ___godot_icall_Object_String_bool_String(mb, (const Object *) this, text, right, action);
}

Button *AcceptDialog::add_cancel(const String name) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AcceptDialog", "add_cancel");
	}
	return (Button *) ___godot_icall_Object_String(mb, (const Object *) this, name);
}

void AcceptDialog::_builtin_text_entered(const String arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AcceptDialog", "_builtin_text_entered");
	}
	___godot_icall_void_String(mb, (const Object *) this, arg0);
}

void AcceptDialog::register_text_enter(const Object *line_edit) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AcceptDialog", "register_text_enter");
	}
	___godot_icall_void_Object(mb, (const Object *) this, line_edit);
}

void AcceptDialog::_custom_action(const String arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AcceptDialog", "_custom_action");
	}
	___godot_icall_void_String(mb, (const Object *) this, arg0);
}

void AcceptDialog::set_text(const String text) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AcceptDialog", "set_text");
	}
	___godot_icall_void_String(mb, (const Object *) this, text);
}

String AcceptDialog::get_text() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AcceptDialog", "get_text");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

}