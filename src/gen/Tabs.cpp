#include <Tabs.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <InputEvent.hpp>
#include <Texture.hpp>


namespace godot {


void *Tabs::___get_type_tag()
{
	return (void *) &Tabs::___get_type_tag;
}

void *Tabs::___get_base_type_tag()
{
	return (void *) &Control::___get_type_tag;
}

Tabs *Tabs::_new()
{
	return (Tabs *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Tabs")());
}
void Tabs::_gui_input(const Ref<InputEvent> arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tabs", "_gui_input");
	}
	___godot_icall_void_Object(mb, (const Object *) this, arg0.ptr());
}

int64_t Tabs::get_tab_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tabs", "get_tab_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void Tabs::set_current_tab(const int64_t tab_idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tabs", "set_current_tab");
	}
	___godot_icall_void_int(mb, (const Object *) this, tab_idx);
}

int64_t Tabs::get_current_tab() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tabs", "get_current_tab");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void Tabs::set_tab_title(const int64_t tab_idx, const String title) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tabs", "set_tab_title");
	}
	___godot_icall_void_int_String(mb, (const Object *) this, tab_idx, title);
}

String Tabs::get_tab_title(const int64_t tab_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tabs", "get_tab_title");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, tab_idx);
}

void Tabs::set_tab_icon(const int64_t tab_idx, const Ref<Texture> icon) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tabs", "set_tab_icon");
	}
	___godot_icall_void_int_Object(mb, (const Object *) this, tab_idx, icon.ptr());
}

Ref<Texture> Tabs::get_tab_icon(const int64_t tab_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tabs", "get_tab_icon");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object_int(mb, (const Object *) this, tab_idx));
}

void Tabs::set_tab_disabled(const int64_t tab_idx, const bool disabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tabs", "set_tab_disabled");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, tab_idx, disabled);
}

bool Tabs::get_tab_disabled(const int64_t tab_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tabs", "get_tab_disabled");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, tab_idx);
}

void Tabs::remove_tab(const int64_t tab_idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tabs", "remove_tab");
	}
	___godot_icall_void_int(mb, (const Object *) this, tab_idx);
}

void Tabs::add_tab(const String title, const Ref<Texture> icon) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tabs", "add_tab");
	}
	___godot_icall_void_String_Object(mb, (const Object *) this, title, icon.ptr());
}

void Tabs::set_tab_align(const int64_t align) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tabs", "set_tab_align");
	}
	___godot_icall_void_int(mb, (const Object *) this, align);
}

Tabs::TabAlign Tabs::get_tab_align() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tabs", "get_tab_align");
	}
	return (Tabs::TabAlign) ___godot_icall_int(mb, (const Object *) this);
}

int64_t Tabs::get_tab_offset() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tabs", "get_tab_offset");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

bool Tabs::get_offset_buttons_visible() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tabs", "get_offset_buttons_visible");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Tabs::ensure_tab_visible(const int64_t idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tabs", "ensure_tab_visible");
	}
	___godot_icall_void_int(mb, (const Object *) this, idx);
}

Rect2 Tabs::get_tab_rect(const int64_t tab_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tabs", "get_tab_rect");
	}
	return ___godot_icall_Rect2_int(mb, (const Object *) this, tab_idx);
}

void Tabs::move_tab(const int64_t from, const int64_t to) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tabs", "move_tab");
	}
	___godot_icall_void_int_int(mb, (const Object *) this, from, to);
}

void Tabs::set_tab_close_display_policy(const int64_t policy) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tabs", "set_tab_close_display_policy");
	}
	___godot_icall_void_int(mb, (const Object *) this, policy);
}

Tabs::CloseButtonDisplayPolicy Tabs::get_tab_close_display_policy() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tabs", "get_tab_close_display_policy");
	}
	return (Tabs::CloseButtonDisplayPolicy) ___godot_icall_int(mb, (const Object *) this);
}

void Tabs::set_scrolling_enabled(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tabs", "set_scrolling_enabled");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool Tabs::get_scrolling_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tabs", "get_scrolling_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

}