#include <LineEdit.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <InputEvent.hpp>
#include <PopupMenu.hpp>


namespace godot {


void *LineEdit::___get_type_tag()
{
	return (void *) &LineEdit::___get_type_tag;
}

void *LineEdit::___get_base_type_tag()
{
	return (void *) &Control::___get_type_tag;
}

LineEdit *LineEdit::_new()
{
	return (LineEdit *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"LineEdit")());
}
void LineEdit::_text_changed() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LineEdit", "_text_changed");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void LineEdit::_toggle_draw_caret() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LineEdit", "_toggle_draw_caret");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void LineEdit::_editor_settings_changed() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LineEdit", "_editor_settings_changed");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void LineEdit::set_align(const int64_t align) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LineEdit", "set_align");
	}
	___godot_icall_void_int(mb, (const Object *) this, align);
}

LineEdit::Align LineEdit::get_align() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LineEdit", "get_align");
	}
	return (LineEdit::Align) ___godot_icall_int(mb, (const Object *) this);
}

void LineEdit::_gui_input(const Ref<InputEvent> arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LineEdit", "_gui_input");
	}
	___godot_icall_void_Object(mb, (const Object *) this, arg0.ptr());
}

void LineEdit::clear() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LineEdit", "clear");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void LineEdit::select(const int64_t from, const int64_t to) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LineEdit", "select");
	}
	___godot_icall_void_int_int(mb, (const Object *) this, from, to);
}

void LineEdit::select_all() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LineEdit", "select_all");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void LineEdit::deselect() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LineEdit", "deselect");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void LineEdit::set_text(const String text) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LineEdit", "set_text");
	}
	___godot_icall_void_String(mb, (const Object *) this, text);
}

String LineEdit::get_text() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LineEdit", "get_text");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void LineEdit::set_placeholder(const String text) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LineEdit", "set_placeholder");
	}
	___godot_icall_void_String(mb, (const Object *) this, text);
}

String LineEdit::get_placeholder() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LineEdit", "get_placeholder");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void LineEdit::set_placeholder_alpha(const double alpha) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LineEdit", "set_placeholder_alpha");
	}
	___godot_icall_void_float(mb, (const Object *) this, alpha);
}

double LineEdit::get_placeholder_alpha() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LineEdit", "get_placeholder_alpha");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void LineEdit::set_cursor_position(const int64_t position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LineEdit", "set_cursor_position");
	}
	___godot_icall_void_int(mb, (const Object *) this, position);
}

int64_t LineEdit::get_cursor_position() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LineEdit", "get_cursor_position");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void LineEdit::set_expand_to_text_length(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LineEdit", "set_expand_to_text_length");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool LineEdit::get_expand_to_text_length() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LineEdit", "get_expand_to_text_length");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void LineEdit::cursor_set_blink_enabled(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LineEdit", "cursor_set_blink_enabled");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool LineEdit::cursor_get_blink_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LineEdit", "cursor_get_blink_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void LineEdit::cursor_set_blink_speed(const double blink_speed) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LineEdit", "cursor_set_blink_speed");
	}
	___godot_icall_void_float(mb, (const Object *) this, blink_speed);
}

double LineEdit::cursor_get_blink_speed() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LineEdit", "cursor_get_blink_speed");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void LineEdit::set_max_length(const int64_t chars) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LineEdit", "set_max_length");
	}
	___godot_icall_void_int(mb, (const Object *) this, chars);
}

int64_t LineEdit::get_max_length() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LineEdit", "get_max_length");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void LineEdit::append_at_cursor(const String text) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LineEdit", "append_at_cursor");
	}
	___godot_icall_void_String(mb, (const Object *) this, text);
}

void LineEdit::set_editable(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LineEdit", "set_editable");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool LineEdit::is_editable() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LineEdit", "is_editable");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void LineEdit::set_secret(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LineEdit", "set_secret");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool LineEdit::is_secret() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LineEdit", "is_secret");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void LineEdit::menu_option(const int64_t option) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LineEdit", "menu_option");
	}
	___godot_icall_void_int(mb, (const Object *) this, option);
}

PopupMenu *LineEdit::get_menu() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LineEdit", "get_menu");
	}
	return (PopupMenu *) ___godot_icall_Object(mb, (const Object *) this);
}

void LineEdit::set_context_menu_enabled(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LineEdit", "set_context_menu_enabled");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool LineEdit::is_context_menu_enabled() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LineEdit", "is_context_menu_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

}