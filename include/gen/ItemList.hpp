#ifndef GODOT_CPP_ITEMLIST_HPP
#define GODOT_CPP_ITEMLIST_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include "ItemList.hpp"

#include "Control.hpp"
namespace godot {

class Texture;
class VScrollBar;
class InputEvent;

class ItemList : public Control {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "ItemList"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum SelectMode {
		SELECT_MULTI = 1,
		SELECT_SINGLE = 0,
	};
	enum IconMode {
		ICON_MODE_TOP = 0,
		ICON_MODE_LEFT = 1,
	};

	// constants


	static ItemList *_new();

	// methods
	void add_item(const String text, const Ref<Texture> icon = nullptr, const bool selectable = true);
	void add_icon_item(const Ref<Texture> icon, const bool selectable = true);
	void set_item_text(const int64_t idx, const String text);
	String get_item_text(const int64_t idx) const;
	void set_item_icon(const int64_t idx, const Ref<Texture> icon);
	Ref<Texture> get_item_icon(const int64_t idx) const;
	void set_item_icon_region(const int64_t idx, const Rect2 rect);
	Rect2 get_item_icon_region(const int64_t idx) const;
	void set_item_icon_modulate(const int64_t idx, const Color modulate);
	Color get_item_icon_modulate(const int64_t idx) const;
	void set_item_selectable(const int64_t idx, const bool selectable);
	bool is_item_selectable(const int64_t idx) const;
	void set_item_disabled(const int64_t idx, const bool disabled);
	bool is_item_disabled(const int64_t idx) const;
	void set_item_metadata(const int64_t idx, const Variant metadata);
	Variant get_item_metadata(const int64_t idx) const;
	void set_item_custom_bg_color(const int64_t idx, const Color custom_bg_color);
	Color get_item_custom_bg_color(const int64_t idx) const;
	void set_item_tooltip_enabled(const int64_t idx, const bool enable);
	bool is_item_tooltip_enabled(const int64_t idx) const;
	void set_item_tooltip(const int64_t idx, const String tooltip);
	String get_item_tooltip(const int64_t idx) const;
	void select(const int64_t idx, const bool single = true);
	void unselect(const int64_t idx);
	void unselect_all();
	bool is_selected(const int64_t idx) const;
	PoolIntArray get_selected_items();
	void move_item(const int64_t from_idx, const int64_t to_idx);
	int64_t get_item_count() const;
	void remove_item(const int64_t idx);
	void clear();
	void sort_items_by_text();
	void set_fixed_column_width(const int64_t width);
	int64_t get_fixed_column_width() const;
	void set_same_column_width(const bool enable);
	bool is_same_column_width() const;
	void set_max_text_lines(const int64_t lines);
	int64_t get_max_text_lines() const;
	void set_max_columns(const int64_t amount);
	int64_t get_max_columns() const;
	void set_select_mode(const int64_t mode);
	ItemList::SelectMode get_select_mode() const;
	void set_icon_mode(const int64_t mode);
	ItemList::IconMode get_icon_mode() const;
	void set_fixed_icon_size(const Vector2 size);
	Vector2 get_fixed_icon_size() const;
	void set_icon_scale(const double scale);
	double get_icon_scale() const;
	void set_allow_rmb_select(const bool allow);
	bool get_allow_rmb_select() const;
	void set_allow_reselect(const bool allow);
	bool get_allow_reselect() const;
	void set_auto_height(const bool enable);
	bool has_auto_height() const;
	bool is_anything_selected();
	int64_t get_item_at_position(const Vector2 position, const bool exact = false) const;
	void ensure_current_is_visible();
	VScrollBar *get_v_scroll();
	void _scroll_changed(const double arg0);
	void _gui_input(const Ref<InputEvent> arg0);
	void _set_items(const Array arg0);
	Array _get_items() const;

};

}

#endif