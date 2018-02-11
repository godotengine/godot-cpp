#include <PopupMenu.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <InputEvent.hpp>
#include <Texture.hpp>
#include <ShortCut.hpp>


namespace godot {


void *PopupMenu::___get_type_tag()
{
	return (void *) &PopupMenu::___get_type_tag;
}

void *PopupMenu::___get_base_type_tag()
{
	return (void *) &Popup::___get_type_tag;
}

PopupMenu *PopupMenu::_new()
{
	return (PopupMenu *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"PopupMenu")());
}
void PopupMenu::_gui_input(const Ref<InputEvent> arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "_gui_input");
	}
	___godot_icall_void_Object(mb, (const Object *) this, arg0.ptr());
}

void PopupMenu::add_icon_item(const Ref<Texture> texture, const String label, const int64_t id, const int64_t accel) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "add_icon_item");
	}
	___godot_icall_void_Object_String_int_int(mb, (const Object *) this, texture.ptr(), label, id, accel);
}

void PopupMenu::add_item(const String label, const int64_t id, const int64_t accel) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "add_item");
	}
	___godot_icall_void_String_int_int(mb, (const Object *) this, label, id, accel);
}

void PopupMenu::add_icon_check_item(const Ref<Texture> texture, const String label, const int64_t id, const int64_t accel) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "add_icon_check_item");
	}
	___godot_icall_void_Object_String_int_int(mb, (const Object *) this, texture.ptr(), label, id, accel);
}

void PopupMenu::add_check_item(const String label, const int64_t id, const int64_t accel) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "add_check_item");
	}
	___godot_icall_void_String_int_int(mb, (const Object *) this, label, id, accel);
}

void PopupMenu::add_submenu_item(const String label, const String submenu, const int64_t id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "add_submenu_item");
	}
	___godot_icall_void_String_String_int(mb, (const Object *) this, label, submenu, id);
}

void PopupMenu::add_icon_shortcut(const Ref<Texture> texture, const Ref<ShortCut> shortcut, const int64_t id, const bool global) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "add_icon_shortcut");
	}
	___godot_icall_void_Object_Object_int_bool(mb, (const Object *) this, texture.ptr(), shortcut.ptr(), id, global);
}

void PopupMenu::add_shortcut(const Ref<ShortCut> shortcut, const int64_t id, const bool global) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "add_shortcut");
	}
	___godot_icall_void_Object_int_bool(mb, (const Object *) this, shortcut.ptr(), id, global);
}

void PopupMenu::add_icon_check_shortcut(const Ref<Texture> texture, const Ref<ShortCut> shortcut, const int64_t id, const bool global) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "add_icon_check_shortcut");
	}
	___godot_icall_void_Object_Object_int_bool(mb, (const Object *) this, texture.ptr(), shortcut.ptr(), id, global);
}

void PopupMenu::add_check_shortcut(const Ref<ShortCut> shortcut, const int64_t id, const bool global) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "add_check_shortcut");
	}
	___godot_icall_void_Object_int_bool(mb, (const Object *) this, shortcut.ptr(), id, global);
}

void PopupMenu::set_item_text(const int64_t idx, const String text) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "set_item_text");
	}
	___godot_icall_void_int_String(mb, (const Object *) this, idx, text);
}

void PopupMenu::set_item_icon(const int64_t idx, const Ref<Texture> icon) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "set_item_icon");
	}
	___godot_icall_void_int_Object(mb, (const Object *) this, idx, icon.ptr());
}

void PopupMenu::set_item_checked(const int64_t idx, const bool checked) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "set_item_checked");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, idx, checked);
}

void PopupMenu::set_item_id(const int64_t idx, const int64_t id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "set_item_id");
	}
	___godot_icall_void_int_int(mb, (const Object *) this, idx, id);
}

void PopupMenu::set_item_accelerator(const int64_t idx, const int64_t accel) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "set_item_accelerator");
	}
	___godot_icall_void_int_int(mb, (const Object *) this, idx, accel);
}

void PopupMenu::set_item_metadata(const int64_t idx, const Variant metadata) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "set_item_metadata");
	}
	___godot_icall_void_int_Variant(mb, (const Object *) this, idx, metadata);
}

void PopupMenu::set_item_disabled(const int64_t idx, const bool disabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "set_item_disabled");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, idx, disabled);
}

void PopupMenu::set_item_submenu(const int64_t idx, const String submenu) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "set_item_submenu");
	}
	___godot_icall_void_int_String(mb, (const Object *) this, idx, submenu);
}

void PopupMenu::set_item_as_separator(const int64_t idx, const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "set_item_as_separator");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, idx, enable);
}

void PopupMenu::set_item_as_checkable(const int64_t idx, const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "set_item_as_checkable");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, idx, enable);
}

void PopupMenu::set_item_tooltip(const int64_t idx, const String tooltip) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "set_item_tooltip");
	}
	___godot_icall_void_int_String(mb, (const Object *) this, idx, tooltip);
}

void PopupMenu::set_item_shortcut(const int64_t idx, const Ref<ShortCut> shortcut, const bool global) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "set_item_shortcut");
	}
	___godot_icall_void_int_Object_bool(mb, (const Object *) this, idx, shortcut.ptr(), global);
}

void PopupMenu::set_item_multistate(const int64_t idx, const int64_t state) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "set_item_multistate");
	}
	___godot_icall_void_int_int(mb, (const Object *) this, idx, state);
}

void PopupMenu::toggle_item_checked(const int64_t idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "toggle_item_checked");
	}
	___godot_icall_void_int(mb, (const Object *) this, idx);
}

void PopupMenu::toggle_item_multistate(const int64_t idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "toggle_item_multistate");
	}
	___godot_icall_void_int(mb, (const Object *) this, idx);
}

String PopupMenu::get_item_text(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "get_item_text");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, idx);
}

Ref<Texture> PopupMenu::get_item_icon(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "get_item_icon");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object_int(mb, (const Object *) this, idx));
}

bool PopupMenu::is_item_checked(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "is_item_checked");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, idx);
}

int64_t PopupMenu::get_item_id(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "get_item_id");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, idx);
}

int64_t PopupMenu::get_item_index(const int64_t id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "get_item_index");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, id);
}

int64_t PopupMenu::get_item_accelerator(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "get_item_accelerator");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, idx);
}

Variant PopupMenu::get_item_metadata(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "get_item_metadata");
	}
	return ___godot_icall_Variant_int(mb, (const Object *) this, idx);
}

bool PopupMenu::is_item_disabled(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "is_item_disabled");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, idx);
}

String PopupMenu::get_item_submenu(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "get_item_submenu");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, idx);
}

bool PopupMenu::is_item_separator(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "is_item_separator");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, idx);
}

bool PopupMenu::is_item_checkable(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "is_item_checkable");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, idx);
}

String PopupMenu::get_item_tooltip(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "get_item_tooltip");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, idx);
}

Ref<ShortCut> PopupMenu::get_item_shortcut(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "get_item_shortcut");
	}
	return Ref<ShortCut>::__internal_constructor(___godot_icall_Object_int(mb, (const Object *) this, idx));
}

int64_t PopupMenu::get_item_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "get_item_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void PopupMenu::remove_item(const int64_t idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "remove_item");
	}
	___godot_icall_void_int(mb, (const Object *) this, idx);
}

void PopupMenu::add_separator() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "add_separator");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void PopupMenu::clear() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "clear");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void PopupMenu::_set_items(const Array arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "_set_items");
	}
	___godot_icall_void_Array(mb, (const Object *) this, arg0);
}

Array PopupMenu::_get_items() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "_get_items");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

void PopupMenu::set_hide_on_item_selection(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "set_hide_on_item_selection");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool PopupMenu::is_hide_on_item_selection() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "is_hide_on_item_selection");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void PopupMenu::set_hide_on_checkable_item_selection(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "set_hide_on_checkable_item_selection");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool PopupMenu::is_hide_on_checkable_item_selection() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "is_hide_on_checkable_item_selection");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void PopupMenu::set_hide_on_state_item_selection(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "set_hide_on_state_item_selection");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool PopupMenu::is_hide_on_state_item_selection() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "is_hide_on_state_item_selection");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void PopupMenu::_submenu_timeout() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PopupMenu", "_submenu_timeout");
	}
	___godot_icall_void(mb, (const Object *) this);
}

}