#include <ItemList.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Texture.hpp>
#include <VScrollBar.hpp>
#include <InputEvent.hpp>


namespace godot {


void *ItemList::___get_type_tag()
{
	return (void *) &ItemList::___get_type_tag;
}

void *ItemList::___get_base_type_tag()
{
	return (void *) &Control::___get_type_tag;
}

ItemList *ItemList::_new()
{
	return (ItemList *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"ItemList")());
}
void ItemList::add_item(const String text, const Ref<Texture> icon, const bool selectable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "add_item");
	}
	___godot_icall_void_String_Object_bool(mb, (const Object *) this, text, icon.ptr(), selectable);
}

void ItemList::add_icon_item(const Ref<Texture> icon, const bool selectable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "add_icon_item");
	}
	___godot_icall_void_Object_bool(mb, (const Object *) this, icon.ptr(), selectable);
}

void ItemList::set_item_text(const int64_t idx, const String text) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "set_item_text");
	}
	___godot_icall_void_int_String(mb, (const Object *) this, idx, text);
}

String ItemList::get_item_text(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "get_item_text");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, idx);
}

void ItemList::set_item_icon(const int64_t idx, const Ref<Texture> icon) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "set_item_icon");
	}
	___godot_icall_void_int_Object(mb, (const Object *) this, idx, icon.ptr());
}

Ref<Texture> ItemList::get_item_icon(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "get_item_icon");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object_int(mb, (const Object *) this, idx));
}

void ItemList::set_item_icon_region(const int64_t idx, const Rect2 rect) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "set_item_icon_region");
	}
	___godot_icall_void_int_Rect2(mb, (const Object *) this, idx, rect);
}

Rect2 ItemList::get_item_icon_region(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "get_item_icon_region");
	}
	return ___godot_icall_Rect2_int(mb, (const Object *) this, idx);
}

void ItemList::set_item_selectable(const int64_t idx, const bool selectable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "set_item_selectable");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, idx, selectable);
}

bool ItemList::is_item_selectable(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "is_item_selectable");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, idx);
}

void ItemList::set_item_disabled(const int64_t idx, const bool disabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "set_item_disabled");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, idx, disabled);
}

bool ItemList::is_item_disabled(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "is_item_disabled");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, idx);
}

void ItemList::set_item_metadata(const int64_t idx, const Variant metadata) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "set_item_metadata");
	}
	___godot_icall_void_int_Variant(mb, (const Object *) this, idx, metadata);
}

Variant ItemList::get_item_metadata(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "get_item_metadata");
	}
	return ___godot_icall_Variant_int(mb, (const Object *) this, idx);
}

void ItemList::set_item_custom_bg_color(const int64_t idx, const Color custom_bg_color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "set_item_custom_bg_color");
	}
	___godot_icall_void_int_Color(mb, (const Object *) this, idx, custom_bg_color);
}

Color ItemList::get_item_custom_bg_color(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "get_item_custom_bg_color");
	}
	return ___godot_icall_Color_int(mb, (const Object *) this, idx);
}

void ItemList::set_item_tooltip_enabled(const int64_t idx, const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "set_item_tooltip_enabled");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, idx, enable);
}

bool ItemList::is_item_tooltip_enabled(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "is_item_tooltip_enabled");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, idx);
}

void ItemList::set_item_tooltip(const int64_t idx, const String tooltip) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "set_item_tooltip");
	}
	___godot_icall_void_int_String(mb, (const Object *) this, idx, tooltip);
}

String ItemList::get_item_tooltip(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "get_item_tooltip");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, idx);
}

void ItemList::select(const int64_t idx, const bool single) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "select");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, idx, single);
}

void ItemList::unselect(const int64_t idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "unselect");
	}
	___godot_icall_void_int(mb, (const Object *) this, idx);
}

void ItemList::unselect_all() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "unselect_all");
	}
	___godot_icall_void(mb, (const Object *) this);
}

bool ItemList::is_selected(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "is_selected");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, idx);
}

PoolIntArray ItemList::get_selected_items() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "get_selected_items");
	}
	return ___godot_icall_PoolIntArray(mb, (const Object *) this);
}

void ItemList::move_item(const int64_t p_from_idx, const int64_t p_to_idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "move_item");
	}
	___godot_icall_void_int_int(mb, (const Object *) this, p_from_idx, p_to_idx);
}

int64_t ItemList::get_item_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "get_item_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void ItemList::remove_item(const int64_t idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "remove_item");
	}
	___godot_icall_void_int(mb, (const Object *) this, idx);
}

void ItemList::clear() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "clear");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void ItemList::sort_items_by_text() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "sort_items_by_text");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void ItemList::set_fixed_column_width(const int64_t width) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "set_fixed_column_width");
	}
	___godot_icall_void_int(mb, (const Object *) this, width);
}

int64_t ItemList::get_fixed_column_width() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "get_fixed_column_width");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void ItemList::set_same_column_width(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "set_same_column_width");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool ItemList::is_same_column_width() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "is_same_column_width");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void ItemList::set_max_text_lines(const int64_t lines) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "set_max_text_lines");
	}
	___godot_icall_void_int(mb, (const Object *) this, lines);
}

int64_t ItemList::get_max_text_lines() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "get_max_text_lines");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void ItemList::set_max_columns(const int64_t amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "set_max_columns");
	}
	___godot_icall_void_int(mb, (const Object *) this, amount);
}

int64_t ItemList::get_max_columns() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "get_max_columns");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void ItemList::set_select_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "set_select_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

ItemList::SelectMode ItemList::get_select_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "get_select_mode");
	}
	return (ItemList::SelectMode) ___godot_icall_int(mb, (const Object *) this);
}

void ItemList::set_icon_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "set_icon_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

ItemList::IconMode ItemList::get_icon_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "get_icon_mode");
	}
	return (ItemList::IconMode) ___godot_icall_int(mb, (const Object *) this);
}

void ItemList::set_fixed_icon_size(const Vector2 size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "set_fixed_icon_size");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, size);
}

Vector2 ItemList::get_fixed_icon_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "get_fixed_icon_size");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void ItemList::set_icon_scale(const double scale) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "set_icon_scale");
	}
	___godot_icall_void_float(mb, (const Object *) this, scale);
}

double ItemList::get_icon_scale() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "get_icon_scale");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void ItemList::set_allow_rmb_select(const bool allow) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "set_allow_rmb_select");
	}
	___godot_icall_void_bool(mb, (const Object *) this, allow);
}

bool ItemList::get_allow_rmb_select() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "get_allow_rmb_select");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void ItemList::set_allow_reselect(const bool allow) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "set_allow_reselect");
	}
	___godot_icall_void_bool(mb, (const Object *) this, allow);
}

bool ItemList::get_allow_reselect() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "get_allow_reselect");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void ItemList::set_auto_height(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "set_auto_height");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool ItemList::has_auto_height() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "has_auto_height");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

bool ItemList::is_anything_selected() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "is_anything_selected");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

int64_t ItemList::get_item_at_position(const Vector2 position, const bool exact) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "get_item_at_position");
	}
	return ___godot_icall_int_Vector2_bool(mb, (const Object *) this, position, exact);
}

void ItemList::ensure_current_is_visible() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "ensure_current_is_visible");
	}
	___godot_icall_void(mb, (const Object *) this);
}

VScrollBar *ItemList::get_v_scroll() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "get_v_scroll");
	}
	return (VScrollBar *) ___godot_icall_Object(mb, (const Object *) this);
}

void ItemList::_scroll_changed(const double arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "_scroll_changed");
	}
	___godot_icall_void_float(mb, (const Object *) this, arg0);
}

void ItemList::_gui_input(const Ref<InputEvent> arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "_gui_input");
	}
	___godot_icall_void_Object(mb, (const Object *) this, arg0.ptr());
}

void ItemList::_set_items(const Array arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "_set_items");
	}
	___godot_icall_void_Array(mb, (const Object *) this, arg0);
}

Array ItemList::_get_items() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ItemList", "_get_items");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

}