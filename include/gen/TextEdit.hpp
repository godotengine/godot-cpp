#ifndef GODOT_CPP_TEXTEDIT_HPP
#define GODOT_CPP_TEXTEDIT_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Control.hpp"
namespace godot {

class InputEvent;
class PopupMenu;

class TextEdit : public Control {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "TextEdit"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum SearchFlags {
		SEARCH_MATCH_CASE = 1,
		SEARCH_BACKWARDS = 4,
		SEARCH_WHOLE_WORDS = 2,
	};
	enum MenuItems {
		MENU_CUT = 0,
		MENU_PASTE = 2,
		MENU_UNDO = 5,
		MENU_CLEAR = 3,
		MENU_SELECT_ALL = 4,
		MENU_MAX = 6,
		MENU_COPY = 1,
	};

	// constants


	static TextEdit *_new();

	// methods
	void _gui_input(const Ref<InputEvent> arg0);
	void _scroll_moved(const double arg0);
	void _cursor_changed_emit();
	void _text_changed_emit();
	void _push_current_op();
	void _click_selection_held();
	void _toggle_draw_caret();
	void _v_scroll_input();
	void set_text(const String text);
	void insert_text_at_cursor(const String text);
	int64_t get_line_count() const;
	String get_text();
	String get_line(const int64_t line) const;
	void cursor_set_column(const int64_t column, const bool adjust_viewport = true);
	void cursor_set_line(const int64_t line, const bool adjust_viewport = true, const bool can_be_hidden = true);
	int64_t cursor_get_column() const;
	int64_t cursor_get_line() const;
	void cursor_set_blink_enabled(const bool enable);
	bool cursor_get_blink_enabled() const;
	void cursor_set_blink_speed(const double blink_speed);
	double cursor_get_blink_speed() const;
	void cursor_set_block_mode(const bool enable);
	bool cursor_is_block_mode() const;
	void set_right_click_moves_caret(const bool enable);
	bool is_right_click_moving_caret() const;
	void set_readonly(const bool enable);
	bool is_readonly() const;
	void set_wrap(const bool enable);
	bool is_wrapping() const;
	void set_context_menu_enabled(const bool enable);
	bool is_context_menu_enabled();
	void cut();
	void copy();
	void paste();
	void select(const int64_t from_line, const int64_t from_column, const int64_t to_line, const int64_t to_column);
	void select_all();
	void deselect();
	bool is_selection_active() const;
	int64_t get_selection_from_line() const;
	int64_t get_selection_from_column() const;
	int64_t get_selection_to_line() const;
	int64_t get_selection_to_column() const;
	String get_selection_text() const;
	String get_word_under_cursor() const;
	PoolIntArray search(const String key, const int64_t flags, const int64_t from_line, const int64_t from_column) const;
	void undo();
	void redo();
	void clear_undo_history();
	void set_show_line_numbers(const bool enable);
	bool is_show_line_numbers_enabled() const;
	void set_hiding_enabled(const int64_t enable);
	int64_t is_hiding_enabled() const;
	void set_line_as_hidden(const int64_t line, const bool enable);
	bool is_line_hidden(const int64_t line) const;
	void fold_all_lines();
	void unhide_all_lines();
	void fold_line(const int64_t line);
	void unfold_line(const int64_t line);
	void toggle_fold_line(const int64_t line);
	bool can_fold(const int64_t line) const;
	bool is_folded(const int64_t line) const;
	void set_highlight_all_occurrences(const bool enable);
	bool is_highlight_all_occurrences_enabled() const;
	void set_override_selected_font_color(const bool override);
	bool is_overriding_selected_font_color() const;
	void set_syntax_coloring(const bool enable);
	bool is_syntax_coloring_enabled() const;
	void set_highlight_current_line(const bool enabled);
	bool is_highlight_current_line_enabled() const;
	void set_smooth_scroll_enable(const bool enable);
	bool is_smooth_scroll_enabled() const;
	void set_v_scroll_speed(const double speed);
	double get_v_scroll_speed() const;
	void add_keyword_color(const String keyword, const Color color);
	bool has_keyword_color(const String keyword) const;
	Color get_keyword_color(const String keyword) const;
	void add_color_region(const String begin_key, const String end_key, const Color color, const bool line_only = false);
	void clear_colors();
	void menu_option(const int64_t option);
	PopupMenu *get_menu() const;

};

}

#endif