#ifndef GODOT_CPP_LINEEDIT_HPP
#define GODOT_CPP_LINEEDIT_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <LineEdit.hpp>

#include <Control.hpp>
namespace godot {

class InputEvent;
class PopupMenu;

class LineEdit : public Control {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "LineEdit"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum Align {
		ALIGN_FILL = 3,
		ALIGN_LEFT = 0,
		ALIGN_CENTER = 1,
		ALIGN_RIGHT = 2,
	};
	enum MenuItems {
		MENU_CUT = 0,
		MENU_PASTE = 2,
		MENU_REDO = 6,
		MENU_UNDO = 5,
		MENU_CLEAR = 3,
		MENU_SELECT_ALL = 4,
		MENU_MAX = 7,
		MENU_COPY = 1,
	};

	// constants


	static LineEdit *_new();

	// methods
	void _text_changed();
	void _toggle_draw_caret();
	void _editor_settings_changed();
	void set_align(const int64_t align);
	LineEdit::Align get_align() const;
	void _gui_input(const Ref<InputEvent> arg0);
	void clear();
	void select(const int64_t from = 0, const int64_t to = -1);
	void select_all();
	void deselect();
	void set_text(const String text);
	String get_text() const;
	void set_placeholder(const String text);
	String get_placeholder() const;
	void set_placeholder_alpha(const double alpha);
	double get_placeholder_alpha() const;
	void set_cursor_position(const int64_t position);
	int64_t get_cursor_position() const;
	void set_expand_to_text_length(const bool enabled);
	bool get_expand_to_text_length() const;
	void cursor_set_blink_enabled(const bool enabled);
	bool cursor_get_blink_enabled() const;
	void cursor_set_blink_speed(const double blink_speed);
	double cursor_get_blink_speed() const;
	void set_max_length(const int64_t chars);
	int64_t get_max_length() const;
	void append_at_cursor(const String text);
	void set_editable(const bool enabled);
	bool is_editable() const;
	void set_secret(const bool enabled);
	bool is_secret() const;
	void menu_option(const int64_t option);
	PopupMenu *get_menu() const;
	void set_context_menu_enabled(const bool enable);
	bool is_context_menu_enabled();

};

}

#endif