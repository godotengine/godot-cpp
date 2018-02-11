#include <SpinBox.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <InputEvent.hpp>
#include <LineEdit.hpp>


namespace godot {


void *SpinBox::___get_type_tag()
{
	return (void *) &SpinBox::___get_type_tag;
}

void *SpinBox::___get_base_type_tag()
{
	return (void *) &Range::___get_type_tag;
}

SpinBox *SpinBox::_new()
{
	return (SpinBox *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"SpinBox")());
}
void SpinBox::_gui_input(const Ref<InputEvent> arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpinBox", "_gui_input");
	}
	___godot_icall_void_Object(mb, (const Object *) this, arg0.ptr());
}

void SpinBox::_text_entered(const String arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpinBox", "_text_entered");
	}
	___godot_icall_void_String(mb, (const Object *) this, arg0);
}

void SpinBox::set_suffix(const String suffix) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpinBox", "set_suffix");
	}
	___godot_icall_void_String(mb, (const Object *) this, suffix);
}

String SpinBox::get_suffix() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpinBox", "get_suffix");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void SpinBox::set_prefix(const String prefix) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpinBox", "set_prefix");
	}
	___godot_icall_void_String(mb, (const Object *) this, prefix);
}

String SpinBox::get_prefix() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpinBox", "get_prefix");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void SpinBox::set_editable(const bool editable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpinBox", "set_editable");
	}
	___godot_icall_void_bool(mb, (const Object *) this, editable);
}

bool SpinBox::is_editable() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpinBox", "is_editable");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void SpinBox::_line_edit_focus_exit() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpinBox", "_line_edit_focus_exit");
	}
	___godot_icall_void(mb, (const Object *) this);
}

LineEdit *SpinBox::get_line_edit() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpinBox", "get_line_edit");
	}
	return (LineEdit *) ___godot_icall_Object(mb, (const Object *) this);
}

void SpinBox::_line_edit_input(const Ref<InputEvent> arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpinBox", "_line_edit_input");
	}
	___godot_icall_void_Object(mb, (const Object *) this, arg0.ptr());
}

void SpinBox::_range_click_timeout() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpinBox", "_range_click_timeout");
	}
	___godot_icall_void(mb, (const Object *) this);
}

}