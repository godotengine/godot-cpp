#include <TreeItem.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Texture.hpp>
#include <Object.hpp>
#include <TreeItem.hpp>


namespace godot {


void *TreeItem::___get_type_tag()
{
	return (void *) &TreeItem::___get_type_tag;
}

void *TreeItem::___get_base_type_tag()
{
	return (void *) &Object::___get_type_tag;
}

void TreeItem::set_cell_mode(const int64_t column, const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "set_cell_mode");
	}
	___godot_icall_void_int_int(mb, (const Object *) this, column, mode);
}

TreeItem::TreeCellMode TreeItem::get_cell_mode(const int64_t column) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "get_cell_mode");
	}
	return (TreeItem::TreeCellMode) ___godot_icall_int_int(mb, (const Object *) this, column);
}

void TreeItem::set_checked(const int64_t column, const bool checked) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "set_checked");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, column, checked);
}

bool TreeItem::is_checked(const int64_t column) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "is_checked");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, column);
}

void TreeItem::set_text(const int64_t column, const String text) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "set_text");
	}
	___godot_icall_void_int_String(mb, (const Object *) this, column, text);
}

String TreeItem::get_text(const int64_t column) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "get_text");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, column);
}

void TreeItem::set_icon(const int64_t column, const Ref<Texture> texture) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "set_icon");
	}
	___godot_icall_void_int_Object(mb, (const Object *) this, column, texture.ptr());
}

Ref<Texture> TreeItem::get_icon(const int64_t column) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "get_icon");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object_int(mb, (const Object *) this, column));
}

void TreeItem::set_icon_region(const int64_t column, const Rect2 region) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "set_icon_region");
	}
	___godot_icall_void_int_Rect2(mb, (const Object *) this, column, region);
}

Rect2 TreeItem::get_icon_region(const int64_t column) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "get_icon_region");
	}
	return ___godot_icall_Rect2_int(mb, (const Object *) this, column);
}

void TreeItem::set_icon_max_width(const int64_t column, const int64_t width) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "set_icon_max_width");
	}
	___godot_icall_void_int_int(mb, (const Object *) this, column, width);
}

int64_t TreeItem::get_icon_max_width(const int64_t column) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "get_icon_max_width");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, column);
}

void TreeItem::set_range(const int64_t column, const double value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "set_range");
	}
	___godot_icall_void_int_float(mb, (const Object *) this, column, value);
}

double TreeItem::get_range(const int64_t column) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "get_range");
	}
	return ___godot_icall_float_int(mb, (const Object *) this, column);
}

void TreeItem::set_range_config(const int64_t column, const double min, const double max, const double step, const bool expr) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "set_range_config");
	}
	___godot_icall_void_int_float_float_float_bool(mb, (const Object *) this, column, min, max, step, expr);
}

Dictionary TreeItem::get_range_config(const int64_t column) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "get_range_config");
	}
	return ___godot_icall_Dictionary_int(mb, (const Object *) this, column);
}

void TreeItem::set_metadata(const int64_t column, const Variant meta) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "set_metadata");
	}
	___godot_icall_void_int_Variant(mb, (const Object *) this, column, meta);
}

Variant TreeItem::get_metadata(const int64_t column) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "get_metadata");
	}
	return ___godot_icall_Variant_int(mb, (const Object *) this, column);
}

void TreeItem::set_custom_draw(const int64_t column, const Object *object, const String callback) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "set_custom_draw");
	}
	___godot_icall_void_int_Object_String(mb, (const Object *) this, column, object, callback);
}

void TreeItem::set_collapsed(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "set_collapsed");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool TreeItem::is_collapsed() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "is_collapsed");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void TreeItem::set_custom_minimum_height(const int64_t height) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "set_custom_minimum_height");
	}
	___godot_icall_void_int(mb, (const Object *) this, height);
}

int64_t TreeItem::get_custom_minimum_height() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "get_custom_minimum_height");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

TreeItem *TreeItem::get_next() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "get_next");
	}
	return (TreeItem *) ___godot_icall_Object(mb, (const Object *) this);
}

TreeItem *TreeItem::get_prev() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "get_prev");
	}
	return (TreeItem *) ___godot_icall_Object(mb, (const Object *) this);
}

TreeItem *TreeItem::get_parent() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "get_parent");
	}
	return (TreeItem *) ___godot_icall_Object(mb, (const Object *) this);
}

TreeItem *TreeItem::get_children() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "get_children");
	}
	return (TreeItem *) ___godot_icall_Object(mb, (const Object *) this);
}

TreeItem *TreeItem::get_next_visible() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "get_next_visible");
	}
	return (TreeItem *) ___godot_icall_Object(mb, (const Object *) this);
}

TreeItem *TreeItem::get_prev_visible() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "get_prev_visible");
	}
	return (TreeItem *) ___godot_icall_Object(mb, (const Object *) this);
}

void TreeItem::remove_child(const Object *child) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "remove_child");
	}
	___godot_icall_void_Object(mb, (const Object *) this, child);
}

void TreeItem::set_selectable(const int64_t column, const bool selectable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "set_selectable");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, column, selectable);
}

bool TreeItem::is_selectable(const int64_t column) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "is_selectable");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, column);
}

bool TreeItem::is_selected(const int64_t column) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "is_selected");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, column);
}

void TreeItem::select(const int64_t column) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "select");
	}
	___godot_icall_void_int(mb, (const Object *) this, column);
}

void TreeItem::deselect(const int64_t column) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "deselect");
	}
	___godot_icall_void_int(mb, (const Object *) this, column);
}

void TreeItem::set_editable(const int64_t column, const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "set_editable");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, column, enabled);
}

bool TreeItem::is_editable(const int64_t column) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "is_editable");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, column);
}

void TreeItem::set_custom_color(const int64_t column, const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "set_custom_color");
	}
	___godot_icall_void_int_Color(mb, (const Object *) this, column, color);
}

void TreeItem::clear_custom_color(const int64_t column) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "clear_custom_color");
	}
	___godot_icall_void_int(mb, (const Object *) this, column);
}

void TreeItem::set_custom_bg_color(const int64_t column, const Color color, const bool just_outline) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "set_custom_bg_color");
	}
	___godot_icall_void_int_Color_bool(mb, (const Object *) this, column, color, just_outline);
}

void TreeItem::clear_custom_bg_color(const int64_t column) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "clear_custom_bg_color");
	}
	___godot_icall_void_int(mb, (const Object *) this, column);
}

Color TreeItem::get_custom_bg_color(const int64_t column) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "get_custom_bg_color");
	}
	return ___godot_icall_Color_int(mb, (const Object *) this, column);
}

void TreeItem::set_custom_as_button(const int64_t column, const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "set_custom_as_button");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, column, enable);
}

bool TreeItem::is_custom_set_as_button(const int64_t column) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "is_custom_set_as_button");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, column);
}

void TreeItem::add_button(const int64_t column, const Ref<Texture> button, const int64_t button_idx, const bool disabled, const String tooltip) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "add_button");
	}
	___godot_icall_void_int_Object_int_bool_String(mb, (const Object *) this, column, button.ptr(), button_idx, disabled, tooltip);
}

int64_t TreeItem::get_button_count(const int64_t column) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "get_button_count");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, column);
}

Ref<Texture> TreeItem::get_button(const int64_t column, const int64_t button_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "get_button");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object_int_int(mb, (const Object *) this, column, button_idx));
}

void TreeItem::set_button(const int64_t column, const int64_t button_idx, const Ref<Texture> button) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "set_button");
	}
	___godot_icall_void_int_int_Object(mb, (const Object *) this, column, button_idx, button.ptr());
}

void TreeItem::erase_button(const int64_t column, const int64_t button_idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "erase_button");
	}
	___godot_icall_void_int_int(mb, (const Object *) this, column, button_idx);
}

bool TreeItem::is_button_disabled(const int64_t column, const int64_t button_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "is_button_disabled");
	}
	return ___godot_icall_bool_int_int(mb, (const Object *) this, column, button_idx);
}

void TreeItem::set_expand_right(const int64_t column, const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "set_expand_right");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, column, enable);
}

bool TreeItem::get_expand_right(const int64_t column) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "get_expand_right");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, column);
}

void TreeItem::set_tooltip(const int64_t column, const String tooltip) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "set_tooltip");
	}
	___godot_icall_void_int_String(mb, (const Object *) this, column, tooltip);
}

String TreeItem::get_tooltip(const int64_t column) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "get_tooltip");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, column);
}

void TreeItem::set_text_align(const int64_t column, const int64_t text_align) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "set_text_align");
	}
	___godot_icall_void_int_int(mb, (const Object *) this, column, text_align);
}

TreeItem::TextAlign TreeItem::get_text_align(const int64_t column) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "get_text_align");
	}
	return (TreeItem::TextAlign) ___godot_icall_int_int(mb, (const Object *) this, column);
}

void TreeItem::move_to_top() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "move_to_top");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void TreeItem::move_to_bottom() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "move_to_bottom");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void TreeItem::set_disable_folding(const bool disable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "set_disable_folding");
	}
	___godot_icall_void_bool(mb, (const Object *) this, disable);
}

bool TreeItem::is_folding_disabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TreeItem", "is_folding_disabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

}