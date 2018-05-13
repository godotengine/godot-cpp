#ifndef GODOT_CPP_TREEITEM_HPP
#define GODOT_CPP_TREEITEM_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include "TreeItem.hpp"

#include "Object.hpp"
namespace godot {

class Texture;
class Object;
class TreeItem;

class TreeItem : public Object {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "TreeItem"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum TreeCellMode {
		CELL_MODE_ICON = 4,
		CELL_MODE_STRING = 0,
		CELL_MODE_RANGE = 2,
		CELL_MODE_CHECK = 1,
		CELL_MODE_CUSTOM = 5,
		CELL_MODE_RANGE_EXPRESSION = 3,
	};
	enum TextAlign {
		ALIGN_LEFT = 0,
		ALIGN_CENTER = 1,
		ALIGN_RIGHT = 2,
	};

	// constants

	// methods
	void set_cell_mode(const int64_t column, const int64_t mode);
	TreeItem::TreeCellMode get_cell_mode(const int64_t column) const;
	void set_checked(const int64_t column, const bool checked);
	bool is_checked(const int64_t column) const;
	void set_text(const int64_t column, const String text);
	String get_text(const int64_t column) const;
	void set_icon(const int64_t column, const Ref<Texture> texture);
	Ref<Texture> get_icon(const int64_t column) const;
	void set_icon_region(const int64_t column, const Rect2 region);
	Rect2 get_icon_region(const int64_t column) const;
	void set_icon_max_width(const int64_t column, const int64_t width);
	int64_t get_icon_max_width(const int64_t column) const;
	void set_range(const int64_t column, const double value);
	double get_range(const int64_t column) const;
	void set_range_config(const int64_t column, const double min, const double max, const double step, const bool expr = false);
	Dictionary get_range_config(const int64_t column);
	void set_metadata(const int64_t column, const Variant meta);
	Variant get_metadata(const int64_t column) const;
	void set_custom_draw(const int64_t column, const Object *object, const String callback);
	void set_collapsed(const bool enable);
	bool is_collapsed();
	void set_custom_minimum_height(const int64_t height);
	int64_t get_custom_minimum_height() const;
	TreeItem *get_next();
	TreeItem *get_prev();
	TreeItem *get_parent();
	TreeItem *get_children();
	TreeItem *get_next_visible();
	TreeItem *get_prev_visible();
	void remove_child(const Object *child);
	void set_selectable(const int64_t column, const bool selectable);
	bool is_selectable(const int64_t column) const;
	bool is_selected(const int64_t column);
	void select(const int64_t column);
	void deselect(const int64_t column);
	void set_editable(const int64_t column, const bool enabled);
	bool is_editable(const int64_t column);
	void set_custom_color(const int64_t column, const Color color);
	void clear_custom_color(const int64_t column);
	void set_custom_bg_color(const int64_t column, const Color color, const bool just_outline = false);
	void clear_custom_bg_color(const int64_t column);
	Color get_custom_bg_color(const int64_t column) const;
	void set_custom_as_button(const int64_t column, const bool enable);
	bool is_custom_set_as_button(const int64_t column) const;
	void add_button(const int64_t column, const Ref<Texture> button, const int64_t button_idx = -1, const bool disabled = false, const String tooltip = "");
	int64_t get_button_count(const int64_t column) const;
	Ref<Texture> get_button(const int64_t column, const int64_t button_idx) const;
	void set_button(const int64_t column, const int64_t button_idx, const Ref<Texture> button);
	void erase_button(const int64_t column, const int64_t button_idx);
	bool is_button_disabled(const int64_t column, const int64_t button_idx) const;
	void set_expand_right(const int64_t column, const bool enable);
	bool get_expand_right(const int64_t column) const;
	void set_tooltip(const int64_t column, const String tooltip);
	String get_tooltip(const int64_t column) const;
	void set_text_align(const int64_t column, const int64_t text_align);
	TreeItem::TextAlign get_text_align(const int64_t column) const;
	void move_to_top();
	void move_to_bottom();
	void set_disable_folding(const bool disable);
	bool is_folding_disabled() const;

};

}

#endif