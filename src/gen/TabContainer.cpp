#include <TabContainer.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <InputEvent.hpp>
#include <Control.hpp>
#include <Texture.hpp>
#include <Object.hpp>
#include <Popup.hpp>


namespace godot {


void *TabContainer::___get_type_tag()
{
	return (void *) &TabContainer::___get_type_tag;
}

void *TabContainer::___get_base_type_tag()
{
	return (void *) &Control::___get_type_tag;
}

TabContainer *TabContainer::_new()
{
	return (TabContainer *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"TabContainer")());
}
void TabContainer::_gui_input(const Ref<InputEvent> arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TabContainer", "_gui_input");
	}
	___godot_icall_void_Object(mb, (const Object *) this, arg0.ptr());
}

int64_t TabContainer::get_tab_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TabContainer", "get_tab_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void TabContainer::set_current_tab(const int64_t tab_idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TabContainer", "set_current_tab");
	}
	___godot_icall_void_int(mb, (const Object *) this, tab_idx);
}

int64_t TabContainer::get_current_tab() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TabContainer", "get_current_tab");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t TabContainer::get_previous_tab() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TabContainer", "get_previous_tab");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

Control *TabContainer::get_current_tab_control() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TabContainer", "get_current_tab_control");
	}
	return (Control *) ___godot_icall_Object(mb, (const Object *) this);
}

Control *TabContainer::get_tab_control(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TabContainer", "get_tab_control");
	}
	return (Control *) ___godot_icall_Object_int(mb, (const Object *) this, idx);
}

void TabContainer::set_tab_align(const int64_t align) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TabContainer", "set_tab_align");
	}
	___godot_icall_void_int(mb, (const Object *) this, align);
}

TabContainer::TabAlign TabContainer::get_tab_align() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TabContainer", "get_tab_align");
	}
	return (TabContainer::TabAlign) ___godot_icall_int(mb, (const Object *) this);
}

void TabContainer::set_tabs_visible(const bool visible) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TabContainer", "set_tabs_visible");
	}
	___godot_icall_void_bool(mb, (const Object *) this, visible);
}

bool TabContainer::are_tabs_visible() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TabContainer", "are_tabs_visible");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void TabContainer::set_tab_title(const int64_t tab_idx, const String title) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TabContainer", "set_tab_title");
	}
	___godot_icall_void_int_String(mb, (const Object *) this, tab_idx, title);
}

String TabContainer::get_tab_title(const int64_t tab_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TabContainer", "get_tab_title");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, tab_idx);
}

void TabContainer::set_tab_icon(const int64_t tab_idx, const Ref<Texture> icon) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TabContainer", "set_tab_icon");
	}
	___godot_icall_void_int_Object(mb, (const Object *) this, tab_idx, icon.ptr());
}

Ref<Texture> TabContainer::get_tab_icon(const int64_t tab_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TabContainer", "get_tab_icon");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object_int(mb, (const Object *) this, tab_idx));
}

void TabContainer::set_tab_disabled(const int64_t tab_idx, const bool disabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TabContainer", "set_tab_disabled");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, tab_idx, disabled);
}

bool TabContainer::get_tab_disabled(const int64_t tab_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TabContainer", "get_tab_disabled");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, tab_idx);
}

void TabContainer::set_popup(const Object *popup) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TabContainer", "set_popup");
	}
	___godot_icall_void_Object(mb, (const Object *) this, popup);
}

Popup *TabContainer::get_popup() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TabContainer", "get_popup");
	}
	return (Popup *) ___godot_icall_Object(mb, (const Object *) this);
}

void TabContainer::_child_renamed_callback() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TabContainer", "_child_renamed_callback");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void TabContainer::_on_theme_changed() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TabContainer", "_on_theme_changed");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void TabContainer::_update_current_tab() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TabContainer", "_update_current_tab");
	}
	___godot_icall_void(mb, (const Object *) this);
}

}