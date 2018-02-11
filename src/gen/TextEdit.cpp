#include <TextEdit.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <InputEvent.hpp>
#include <PopupMenu.hpp>


namespace godot {


void *TextEdit::___get_type_tag()
{
	return (void *) &TextEdit::___get_type_tag;
}

void *TextEdit::___get_base_type_tag()
{
	return (void *) &Control::___get_type_tag;
}

TextEdit *TextEdit::_new()
{
	return (TextEdit *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"TextEdit")());
}
void TextEdit::_gui_input(const Ref<InputEvent> arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "_gui_input");
	}
	___godot_icall_void_Object(mb, (const Object *) this, arg0.ptr());
}

void TextEdit::_scroll_moved(const double arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "_scroll_moved");
	}
	___godot_icall_void_float(mb, (const Object *) this, arg0);
}

void TextEdit::_cursor_changed_emit() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "_cursor_changed_emit");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void TextEdit::_text_changed_emit() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "_text_changed_emit");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void TextEdit::_push_current_op() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "_push_current_op");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void TextEdit::_click_selection_held() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "_click_selection_held");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void TextEdit::_toggle_draw_caret() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "_toggle_draw_caret");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void TextEdit::_v_scroll_input() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "_v_scroll_input");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void TextEdit::set_text(const String text) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "set_text");
	}
	___godot_icall_void_String(mb, (const Object *) this, text);
}

void TextEdit::insert_text_at_cursor(const String text) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "insert_text_at_cursor");
	}
	___godot_icall_void_String(mb, (const Object *) this, text);
}

int64_t TextEdit::get_line_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "get_line_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

String TextEdit::get_text() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "get_text");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

String TextEdit::get_line(const int64_t line) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "get_line");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, line);
}

void TextEdit::cursor_set_column(const int64_t column, const bool adjust_viewport) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "cursor_set_column");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, column, adjust_viewport);
}

void TextEdit::cursor_set_line(const int64_t line, const bool adjust_viewport, const bool can_be_hidden) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "cursor_set_line");
	}
	___godot_icall_void_int_bool_bool(mb, (const Object *) this, line, adjust_viewport, can_be_hidden);
}

int64_t TextEdit::cursor_get_column() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "cursor_get_column");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t TextEdit::cursor_get_line() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "cursor_get_line");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void TextEdit::cursor_set_blink_enabled(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "cursor_set_blink_enabled");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool TextEdit::cursor_get_blink_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "cursor_get_blink_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void TextEdit::cursor_set_blink_speed(const double blink_speed) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "cursor_set_blink_speed");
	}
	___godot_icall_void_float(mb, (const Object *) this, blink_speed);
}

double TextEdit::cursor_get_blink_speed() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "cursor_get_blink_speed");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void TextEdit::cursor_set_block_mode(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "cursor_set_block_mode");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool TextEdit::cursor_is_block_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "cursor_is_block_mode");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void TextEdit::set_right_click_moves_caret(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "set_right_click_moves_caret");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool TextEdit::is_right_click_moving_caret() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "is_right_click_moving_caret");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void TextEdit::set_readonly(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "set_readonly");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool TextEdit::is_readonly() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "is_readonly");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void TextEdit::set_wrap(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "set_wrap");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool TextEdit::is_wrapping() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "is_wrapping");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void TextEdit::set_context_menu_enabled(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "set_context_menu_enabled");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool TextEdit::is_context_menu_enabled() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "is_context_menu_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void TextEdit::cut() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "cut");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void TextEdit::copy() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "copy");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void TextEdit::paste() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "paste");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void TextEdit::select(const int64_t from_line, const int64_t from_column, const int64_t to_line, const int64_t to_column) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "select");
	}
	___godot_icall_void_int_int_int_int(mb, (const Object *) this, from_line, from_column, to_line, to_column);
}

void TextEdit::select_all() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "select_all");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void TextEdit::deselect() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "deselect");
	}
	___godot_icall_void(mb, (const Object *) this);
}

bool TextEdit::is_selection_active() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "is_selection_active");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

int64_t TextEdit::get_selection_from_line() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "get_selection_from_line");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t TextEdit::get_selection_from_column() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "get_selection_from_column");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t TextEdit::get_selection_to_line() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "get_selection_to_line");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t TextEdit::get_selection_to_column() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "get_selection_to_column");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

String TextEdit::get_selection_text() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "get_selection_text");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

String TextEdit::get_word_under_cursor() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "get_word_under_cursor");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

PoolIntArray TextEdit::search(const String key, const int64_t flags, const int64_t from_line, const int64_t from_column) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "search");
	}
	return ___godot_icall_PoolIntArray_String_int_int_int(mb, (const Object *) this, key, flags, from_line, from_column);
}

void TextEdit::undo() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "undo");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void TextEdit::redo() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "redo");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void TextEdit::clear_undo_history() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "clear_undo_history");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void TextEdit::set_show_line_numbers(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "set_show_line_numbers");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool TextEdit::is_show_line_numbers_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "is_show_line_numbers_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void TextEdit::set_hiding_enabled(const int64_t enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "set_hiding_enabled");
	}
	___godot_icall_void_int(mb, (const Object *) this, enable);
}

int64_t TextEdit::is_hiding_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "is_hiding_enabled");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void TextEdit::set_line_as_hidden(const int64_t line, const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "set_line_as_hidden");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, line, enable);
}

bool TextEdit::is_line_hidden(const int64_t line) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "is_line_hidden");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, line);
}

void TextEdit::fold_all_lines() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "fold_all_lines");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void TextEdit::unhide_all_lines() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "unhide_all_lines");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void TextEdit::fold_line(const int64_t line) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "fold_line");
	}
	___godot_icall_void_int(mb, (const Object *) this, line);
}

void TextEdit::unfold_line(const int64_t line) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "unfold_line");
	}
	___godot_icall_void_int(mb, (const Object *) this, line);
}

void TextEdit::toggle_fold_line(const int64_t line) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "toggle_fold_line");
	}
	___godot_icall_void_int(mb, (const Object *) this, line);
}

bool TextEdit::can_fold(const int64_t line) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "can_fold");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, line);
}

bool TextEdit::is_folded(const int64_t line) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "is_folded");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, line);
}

void TextEdit::set_highlight_all_occurrences(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "set_highlight_all_occurrences");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool TextEdit::is_highlight_all_occurrences_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "is_highlight_all_occurrences_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void TextEdit::set_override_selected_font_color(const bool override) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "set_override_selected_font_color");
	}
	___godot_icall_void_bool(mb, (const Object *) this, override);
}

bool TextEdit::is_overriding_selected_font_color() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "is_overriding_selected_font_color");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void TextEdit::set_syntax_coloring(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "set_syntax_coloring");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool TextEdit::is_syntax_coloring_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "is_syntax_coloring_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void TextEdit::set_highlight_current_line(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "set_highlight_current_line");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool TextEdit::is_highlight_current_line_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "is_highlight_current_line_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void TextEdit::set_smooth_scroll_enable(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "set_smooth_scroll_enable");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool TextEdit::is_smooth_scroll_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "is_smooth_scroll_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void TextEdit::set_v_scroll_speed(const double speed) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "set_v_scroll_speed");
	}
	___godot_icall_void_float(mb, (const Object *) this, speed);
}

double TextEdit::get_v_scroll_speed() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "get_v_scroll_speed");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void TextEdit::add_keyword_color(const String keyword, const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "add_keyword_color");
	}
	___godot_icall_void_String_Color(mb, (const Object *) this, keyword, color);
}

bool TextEdit::has_keyword_color(const String keyword) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "has_keyword_color");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, keyword);
}

Color TextEdit::get_keyword_color(const String keyword) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "get_keyword_color");
	}
	return ___godot_icall_Color_String(mb, (const Object *) this, keyword);
}

void TextEdit::add_color_region(const String begin_key, const String end_key, const Color color, const bool line_only) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "add_color_region");
	}
	___godot_icall_void_String_String_Color_bool(mb, (const Object *) this, begin_key, end_key, color, line_only);
}

void TextEdit::clear_colors() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "clear_colors");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void TextEdit::menu_option(const int64_t option) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "menu_option");
	}
	___godot_icall_void_int(mb, (const Object *) this, option);
}

PopupMenu *TextEdit::get_menu() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextEdit", "get_menu");
	}
	return (PopupMenu *) ___godot_icall_Object(mb, (const Object *) this);
}

}