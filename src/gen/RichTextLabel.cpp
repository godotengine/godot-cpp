#include <RichTextLabel.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <InputEvent.hpp>
#include <Texture.hpp>
#include <Font.hpp>
#include <VScrollBar.hpp>


namespace godot {


void *RichTextLabel::___get_type_tag()
{
	return (void *) &RichTextLabel::___get_type_tag;
}

void *RichTextLabel::___get_base_type_tag()
{
	return (void *) &Control::___get_type_tag;
}

RichTextLabel *RichTextLabel::_new()
{
	return (RichTextLabel *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"RichTextLabel")());
}
void RichTextLabel::_gui_input(const Ref<InputEvent> arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "_gui_input");
	}
	___godot_icall_void_Object(mb, (const Object *) this, arg0.ptr());
}

void RichTextLabel::_scroll_changed(const double arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "_scroll_changed");
	}
	___godot_icall_void_float(mb, (const Object *) this, arg0);
}

String RichTextLabel::get_text() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "get_text");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void RichTextLabel::add_text(const String text) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "add_text");
	}
	___godot_icall_void_String(mb, (const Object *) this, text);
}

void RichTextLabel::set_text(const String text) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "set_text");
	}
	___godot_icall_void_String(mb, (const Object *) this, text);
}

void RichTextLabel::add_image(const Ref<Texture> image) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "add_image");
	}
	___godot_icall_void_Object(mb, (const Object *) this, image.ptr());
}

void RichTextLabel::newline() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "newline");
	}
	___godot_icall_void(mb, (const Object *) this);
}

bool RichTextLabel::remove_line(const int64_t line) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "remove_line");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, line);
}

void RichTextLabel::push_font(const Ref<Font> font) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "push_font");
	}
	___godot_icall_void_Object(mb, (const Object *) this, font.ptr());
}

void RichTextLabel::push_color(const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "push_color");
	}
	___godot_icall_void_Color(mb, (const Object *) this, color);
}

void RichTextLabel::push_align(const int64_t align) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "push_align");
	}
	___godot_icall_void_int(mb, (const Object *) this, align);
}

void RichTextLabel::push_indent(const int64_t level) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "push_indent");
	}
	___godot_icall_void_int(mb, (const Object *) this, level);
}

void RichTextLabel::push_list(const int64_t type) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "push_list");
	}
	___godot_icall_void_int(mb, (const Object *) this, type);
}

void RichTextLabel::push_meta(const Variant data) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "push_meta");
	}
	___godot_icall_void_Variant(mb, (const Object *) this, data);
}

void RichTextLabel::push_underline() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "push_underline");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void RichTextLabel::push_table(const int64_t columns) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "push_table");
	}
	___godot_icall_void_int(mb, (const Object *) this, columns);
}

void RichTextLabel::set_table_column_expand(const int64_t column, const bool expand, const int64_t ratio) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "set_table_column_expand");
	}
	___godot_icall_void_int_bool_int(mb, (const Object *) this, column, expand, ratio);
}

void RichTextLabel::push_cell() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "push_cell");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void RichTextLabel::pop() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "pop");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void RichTextLabel::clear() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "clear");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void RichTextLabel::set_meta_underline(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "set_meta_underline");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool RichTextLabel::is_meta_underlined() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "is_meta_underlined");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void RichTextLabel::set_override_selected_font_color(const bool override) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "set_override_selected_font_color");
	}
	___godot_icall_void_bool(mb, (const Object *) this, override);
}

bool RichTextLabel::is_overriding_selected_font_color() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "is_overriding_selected_font_color");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void RichTextLabel::set_scroll_active(const bool active) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "set_scroll_active");
	}
	___godot_icall_void_bool(mb, (const Object *) this, active);
}

bool RichTextLabel::is_scroll_active() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "is_scroll_active");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void RichTextLabel::set_scroll_follow(const bool follow) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "set_scroll_follow");
	}
	___godot_icall_void_bool(mb, (const Object *) this, follow);
}

bool RichTextLabel::is_scroll_following() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "is_scroll_following");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

VScrollBar *RichTextLabel::get_v_scroll() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "get_v_scroll");
	}
	return (VScrollBar *) ___godot_icall_Object(mb, (const Object *) this);
}

void RichTextLabel::scroll_to_line(const int64_t line) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "scroll_to_line");
	}
	___godot_icall_void_int(mb, (const Object *) this, line);
}

void RichTextLabel::set_tab_size(const int64_t spaces) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "set_tab_size");
	}
	___godot_icall_void_int(mb, (const Object *) this, spaces);
}

int64_t RichTextLabel::get_tab_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "get_tab_size");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void RichTextLabel::set_selection_enabled(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "set_selection_enabled");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool RichTextLabel::is_selection_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "is_selection_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

Error RichTextLabel::parse_bbcode(const String bbcode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "parse_bbcode");
	}
	return (Error) ___godot_icall_int_String(mb, (const Object *) this, bbcode);
}

Error RichTextLabel::append_bbcode(const String bbcode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "append_bbcode");
	}
	return (Error) ___godot_icall_int_String(mb, (const Object *) this, bbcode);
}

void RichTextLabel::set_bbcode(const String text) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "set_bbcode");
	}
	___godot_icall_void_String(mb, (const Object *) this, text);
}

String RichTextLabel::get_bbcode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "get_bbcode");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void RichTextLabel::set_visible_characters(const int64_t amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "set_visible_characters");
	}
	___godot_icall_void_int(mb, (const Object *) this, amount);
}

int64_t RichTextLabel::get_visible_characters() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "get_visible_characters");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void RichTextLabel::set_percent_visible(const double percent_visible) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "set_percent_visible");
	}
	___godot_icall_void_float(mb, (const Object *) this, percent_visible);
}

double RichTextLabel::get_percent_visible() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "get_percent_visible");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

int64_t RichTextLabel::get_total_character_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "get_total_character_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void RichTextLabel::set_use_bbcode(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "set_use_bbcode");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool RichTextLabel::is_using_bbcode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "is_using_bbcode");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

int64_t RichTextLabel::get_line_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "get_line_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t RichTextLabel::get_visible_line_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RichTextLabel", "get_visible_line_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

}