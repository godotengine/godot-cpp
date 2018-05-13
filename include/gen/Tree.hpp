#ifndef GODOT_CPP_TREE_HPP
#define GODOT_CPP_TREE_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include "Tree.hpp"

#include "Control.hpp"
namespace godot {

class InputEvent;
class Object;
class TreeItem;

class Tree : public Control {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Tree"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum SelectMode {
		SELECT_MULTI = 2,
		SELECT_ROW = 1,
		SELECT_SINGLE = 0,
	};
	enum DropModeFlags {
		DROP_MODE_DISABLED = 0,
		DROP_MODE_INBETWEEN = 2,
		DROP_MODE_ON_ITEM = 1,
	};

	// constants


	static Tree *_new();

	// methods
	void _range_click_timeout();
	void _gui_input(const Ref<InputEvent> arg0);
	void _popup_select(const int64_t arg0);
	void _text_editor_enter(const String arg0);
	void _text_editor_modal_close();
	void _value_editor_changed(const double arg0);
	void _scroll_moved(const double arg0);
	void clear();
	Object *create_item(const Object *parent = nullptr, const int64_t idx = -1);
	TreeItem *get_root();
	void set_column_min_width(const int64_t column, const int64_t min_width);
	void set_column_expand(const int64_t column, const bool expand);
	int64_t get_column_width(const int64_t column) const;
	void set_hide_root(const bool enable);
	bool is_root_hidden() const;
	TreeItem *get_next_selected(const Object *from);
	TreeItem *get_selected() const;
	int64_t get_selected_column() const;
	int64_t get_pressed_button() const;
	void set_select_mode(const int64_t mode);
	Tree::SelectMode get_select_mode() const;
	void set_columns(const int64_t amount);
	int64_t get_columns() const;
	TreeItem *get_edited() const;
	int64_t get_edited_column() const;
	Rect2 get_custom_popup_rect() const;
	Rect2 get_item_area_rect(const Object *item, const int64_t column = -1) const;
	TreeItem *get_item_at_position(const Vector2 position) const;
	int64_t get_column_at_position(const Vector2 position) const;
	int64_t get_drop_section_at_position(const Vector2 position) const;
	void ensure_cursor_is_visible();
	void set_column_titles_visible(const bool visible);
	bool are_column_titles_visible() const;
	void set_column_title(const int64_t column, const String title);
	String get_column_title(const int64_t column) const;
	Vector2 get_scroll() const;
	void set_hide_folding(const bool hide);
	bool is_folding_hidden() const;
	void set_drop_mode_flags(const int64_t flags);
	int64_t get_drop_mode_flags() const;
	void set_allow_rmb_select(const bool allow);
	bool get_allow_rmb_select() const;
	void set_allow_reselect(const bool allow);
	bool get_allow_reselect() const;

};

}

#endif