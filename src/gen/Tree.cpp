#include <Tree.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <InputEvent.hpp>
#include <Object.hpp>
#include <TreeItem.hpp>


namespace godot {


void *Tree::___get_type_tag()
{
	return (void *) &Tree::___get_type_tag;
}

void *Tree::___get_base_type_tag()
{
	return (void *) &Control::___get_type_tag;
}

Tree *Tree::_new()
{
	return (Tree *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Tree")());
}
void Tree::_range_click_timeout() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tree", "_range_click_timeout");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Tree::_gui_input(const Ref<InputEvent> arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tree", "_gui_input");
	}
	___godot_icall_void_Object(mb, (const Object *) this, arg0.ptr());
}

void Tree::_popup_select(const int64_t arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tree", "_popup_select");
	}
	___godot_icall_void_int(mb, (const Object *) this, arg0);
}

void Tree::_text_editor_enter(const String arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tree", "_text_editor_enter");
	}
	___godot_icall_void_String(mb, (const Object *) this, arg0);
}

void Tree::_text_editor_modal_close() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tree", "_text_editor_modal_close");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Tree::_value_editor_changed(const double arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tree", "_value_editor_changed");
	}
	___godot_icall_void_float(mb, (const Object *) this, arg0);
}

void Tree::_scroll_moved(const double arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tree", "_scroll_moved");
	}
	___godot_icall_void_float(mb, (const Object *) this, arg0);
}

void Tree::clear() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tree", "clear");
	}
	___godot_icall_void(mb, (const Object *) this);
}

Object *Tree::create_item(const Object *parent, const int64_t idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tree", "create_item");
	}
	return (Object *) ___godot_icall_Object_Object_int(mb, (const Object *) this, parent, idx);
}

TreeItem *Tree::get_root() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tree", "get_root");
	}
	return (TreeItem *) ___godot_icall_Object(mb, (const Object *) this);
}

void Tree::set_column_min_width(const int64_t column, const int64_t min_width) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tree", "set_column_min_width");
	}
	___godot_icall_void_int_int(mb, (const Object *) this, column, min_width);
}

void Tree::set_column_expand(const int64_t column, const bool expand) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tree", "set_column_expand");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, column, expand);
}

int64_t Tree::get_column_width(const int64_t column) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tree", "get_column_width");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, column);
}

void Tree::set_hide_root(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tree", "set_hide_root");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool Tree::is_root_hidden() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tree", "is_root_hidden");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

TreeItem *Tree::get_next_selected(const Object *from) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tree", "get_next_selected");
	}
	return (TreeItem *) ___godot_icall_Object_Object(mb, (const Object *) this, from);
}

TreeItem *Tree::get_selected() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tree", "get_selected");
	}
	return (TreeItem *) ___godot_icall_Object(mb, (const Object *) this);
}

int64_t Tree::get_selected_column() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tree", "get_selected_column");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t Tree::get_pressed_button() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tree", "get_pressed_button");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void Tree::set_select_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tree", "set_select_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

Tree::SelectMode Tree::get_select_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tree", "get_select_mode");
	}
	return (Tree::SelectMode) ___godot_icall_int(mb, (const Object *) this);
}

void Tree::set_columns(const int64_t amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tree", "set_columns");
	}
	___godot_icall_void_int(mb, (const Object *) this, amount);
}

int64_t Tree::get_columns() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tree", "get_columns");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

TreeItem *Tree::get_edited() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tree", "get_edited");
	}
	return (TreeItem *) ___godot_icall_Object(mb, (const Object *) this);
}

int64_t Tree::get_edited_column() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tree", "get_edited_column");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

Rect2 Tree::get_custom_popup_rect() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tree", "get_custom_popup_rect");
	}
	return ___godot_icall_Rect2(mb, (const Object *) this);
}

Rect2 Tree::get_item_area_rect(const Object *item, const int64_t column) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tree", "get_item_area_rect");
	}
	return ___godot_icall_Rect2_Object_int(mb, (const Object *) this, item, column);
}

TreeItem *Tree::get_item_at_position(const Vector2 position) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tree", "get_item_at_position");
	}
	return (TreeItem *) ___godot_icall_Object_Vector2(mb, (const Object *) this, position);
}

int64_t Tree::get_column_at_position(const Vector2 position) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tree", "get_column_at_position");
	}
	return ___godot_icall_int_Vector2(mb, (const Object *) this, position);
}

int64_t Tree::get_drop_section_at_position(const Vector2 position) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tree", "get_drop_section_at_position");
	}
	return ___godot_icall_int_Vector2(mb, (const Object *) this, position);
}

void Tree::ensure_cursor_is_visible() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tree", "ensure_cursor_is_visible");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Tree::set_column_titles_visible(const bool visible) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tree", "set_column_titles_visible");
	}
	___godot_icall_void_bool(mb, (const Object *) this, visible);
}

bool Tree::are_column_titles_visible() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tree", "are_column_titles_visible");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Tree::set_column_title(const int64_t column, const String title) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tree", "set_column_title");
	}
	___godot_icall_void_int_String(mb, (const Object *) this, column, title);
}

String Tree::get_column_title(const int64_t column) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tree", "get_column_title");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, column);
}

Vector2 Tree::get_scroll() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tree", "get_scroll");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void Tree::set_hide_folding(const bool hide) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tree", "set_hide_folding");
	}
	___godot_icall_void_bool(mb, (const Object *) this, hide);
}

bool Tree::is_folding_hidden() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tree", "is_folding_hidden");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Tree::set_drop_mode_flags(const int64_t flags) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tree", "set_drop_mode_flags");
	}
	___godot_icall_void_int(mb, (const Object *) this, flags);
}

int64_t Tree::get_drop_mode_flags() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tree", "get_drop_mode_flags");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void Tree::set_allow_rmb_select(const bool allow) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tree", "set_allow_rmb_select");
	}
	___godot_icall_void_bool(mb, (const Object *) this, allow);
}

bool Tree::get_allow_rmb_select() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tree", "get_allow_rmb_select");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Tree::set_allow_reselect(const bool allow) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tree", "set_allow_reselect");
	}
	___godot_icall_void_bool(mb, (const Object *) this, allow);
}

bool Tree::get_allow_reselect() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tree", "get_allow_reselect");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

}