#ifndef GODOT_CPP_RICHTEXTLABEL_HPP
#define GODOT_CPP_RICHTEXTLABEL_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Control.hpp"
namespace godot {

class InputEvent;
class Texture;
class Font;
class VScrollBar;

class RichTextLabel : public Control {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "RichTextLabel"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum Align {
		ALIGN_FILL = 3,
		ALIGN_LEFT = 0,
		ALIGN_CENTER = 1,
		ALIGN_RIGHT = 2,
	};
	enum ListType {
		LIST_LETTERS = 1,
		LIST_DOTS = 2,
		LIST_NUMBERS = 0,
	};
	enum ItemType {
		ITEM_NEWLINE = 3,
		ITEM_LIST = 9,
		ITEM_TEXT = 1,
		ITEM_FRAME = 0,
		ITEM_COLOR = 5,
		ITEM_ALIGN = 7,
		ITEM_INDENT = 8,
		ITEM_TABLE = 10,
		ITEM_FONT = 4,
		ITEM_UNDERLINE = 6,
		ITEM_META = 11,
		ITEM_IMAGE = 2,
	};

	// constants


	static RichTextLabel *_new();

	// methods
	void _gui_input(const Ref<InputEvent> arg0);
	void _scroll_changed(const double arg0);
	String get_text();
	void add_text(const String text);
	void set_text(const String text);
	void add_image(const Ref<Texture> image);
	void newline();
	bool remove_line(const int64_t line);
	void push_font(const Ref<Font> font);
	void push_color(const Color color);
	void push_align(const int64_t align);
	void push_indent(const int64_t level);
	void push_list(const int64_t type);
	void push_meta(const Variant data);
	void push_underline();
	void push_table(const int64_t columns);
	void set_table_column_expand(const int64_t column, const bool expand, const int64_t ratio);
	void push_cell();
	void pop();
	void clear();
	void set_meta_underline(const bool enable);
	bool is_meta_underlined() const;
	void set_override_selected_font_color(const bool override);
	bool is_overriding_selected_font_color() const;
	void set_scroll_active(const bool active);
	bool is_scroll_active() const;
	void set_scroll_follow(const bool follow);
	bool is_scroll_following() const;
	VScrollBar *get_v_scroll();
	void scroll_to_line(const int64_t line);
	void set_tab_size(const int64_t spaces);
	int64_t get_tab_size() const;
	void set_selection_enabled(const bool enabled);
	bool is_selection_enabled() const;
	Error parse_bbcode(const String bbcode);
	Error append_bbcode(const String bbcode);
	void set_bbcode(const String text);
	String get_bbcode() const;
	void set_visible_characters(const int64_t amount);
	int64_t get_visible_characters() const;
	void set_percent_visible(const double percent_visible);
	double get_percent_visible() const;
	int64_t get_total_character_count() const;
	void set_use_bbcode(const bool enable);
	bool is_using_bbcode() const;
	int64_t get_line_count() const;
	int64_t get_visible_line_count() const;
	int64_t get_content_height();

};

}

#endif