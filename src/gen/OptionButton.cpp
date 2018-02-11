#include <OptionButton.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Texture.hpp>
#include <PopupMenu.hpp>


namespace godot {


void *OptionButton::___get_type_tag()
{
	return (void *) &OptionButton::___get_type_tag;
}

void *OptionButton::___get_base_type_tag()
{
	return (void *) &Button::___get_type_tag;
}

OptionButton *OptionButton::_new()
{
	return (OptionButton *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"OptionButton")());
}
void OptionButton::_selected(const int64_t arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("OptionButton", "_selected");
	}
	___godot_icall_void_int(mb, (const Object *) this, arg0);
}

void OptionButton::_focused(const int64_t arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("OptionButton", "_focused");
	}
	___godot_icall_void_int(mb, (const Object *) this, arg0);
}

void OptionButton::add_item(const String label, const int64_t id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("OptionButton", "add_item");
	}
	___godot_icall_void_String_int(mb, (const Object *) this, label, id);
}

void OptionButton::add_icon_item(const Ref<Texture> texture, const String label, const int64_t id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("OptionButton", "add_icon_item");
	}
	___godot_icall_void_Object_String_int(mb, (const Object *) this, texture.ptr(), label, id);
}

void OptionButton::set_item_text(const int64_t idx, const String text) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("OptionButton", "set_item_text");
	}
	___godot_icall_void_int_String(mb, (const Object *) this, idx, text);
}

void OptionButton::set_item_icon(const int64_t idx, const Ref<Texture> texture) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("OptionButton", "set_item_icon");
	}
	___godot_icall_void_int_Object(mb, (const Object *) this, idx, texture.ptr());
}

void OptionButton::set_item_disabled(const int64_t idx, const bool disabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("OptionButton", "set_item_disabled");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, idx, disabled);
}

void OptionButton::set_item_id(const int64_t idx, const int64_t id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("OptionButton", "set_item_id");
	}
	___godot_icall_void_int_int(mb, (const Object *) this, idx, id);
}

void OptionButton::set_item_metadata(const int64_t idx, const Variant metadata) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("OptionButton", "set_item_metadata");
	}
	___godot_icall_void_int_Variant(mb, (const Object *) this, idx, metadata);
}

String OptionButton::get_item_text(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("OptionButton", "get_item_text");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, idx);
}

Ref<Texture> OptionButton::get_item_icon(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("OptionButton", "get_item_icon");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object_int(mb, (const Object *) this, idx));
}

int64_t OptionButton::get_item_id(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("OptionButton", "get_item_id");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, idx);
}

Variant OptionButton::get_item_metadata(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("OptionButton", "get_item_metadata");
	}
	return ___godot_icall_Variant_int(mb, (const Object *) this, idx);
}

bool OptionButton::is_item_disabled(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("OptionButton", "is_item_disabled");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, idx);
}

int64_t OptionButton::get_item_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("OptionButton", "get_item_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void OptionButton::add_separator() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("OptionButton", "add_separator");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void OptionButton::clear() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("OptionButton", "clear");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void OptionButton::select(const int64_t idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("OptionButton", "select");
	}
	___godot_icall_void_int(mb, (const Object *) this, idx);
}

int64_t OptionButton::get_selected() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("OptionButton", "get_selected");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t OptionButton::get_selected_id() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("OptionButton", "get_selected_id");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

Variant OptionButton::get_selected_metadata() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("OptionButton", "get_selected_metadata");
	}
	return ___godot_icall_Variant(mb, (const Object *) this);
}

void OptionButton::remove_item(const int64_t idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("OptionButton", "remove_item");
	}
	___godot_icall_void_int(mb, (const Object *) this, idx);
}

void OptionButton::_select_int(const int64_t arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("OptionButton", "_select_int");
	}
	___godot_icall_void_int(mb, (const Object *) this, arg0);
}

PopupMenu *OptionButton::get_popup() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("OptionButton", "get_popup");
	}
	return (PopupMenu *) ___godot_icall_Object(mb, (const Object *) this);
}

void OptionButton::_set_items(const Array arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("OptionButton", "_set_items");
	}
	___godot_icall_void_Array(mb, (const Object *) this, arg0);
}

Array OptionButton::_get_items() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("OptionButton", "_get_items");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

}