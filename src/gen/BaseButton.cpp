#include <BaseButton.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <InputEvent.hpp>
#include <ShortCut.hpp>
#include <ButtonGroup.hpp>


namespace godot {


void *BaseButton::___get_type_tag()
{
	return (void *) &BaseButton::___get_type_tag;
}

void *BaseButton::___get_base_type_tag()
{
	return (void *) &Control::___get_type_tag;
}

void BaseButton::_pressed() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BaseButton", "_pressed");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void BaseButton::_toggled(const bool button_pressed) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BaseButton", "_toggled");
	}
	___godot_icall_void_bool(mb, (const Object *) this, button_pressed);
}

void BaseButton::_gui_input(const Ref<InputEvent> arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BaseButton", "_gui_input");
	}
	___godot_icall_void_Object(mb, (const Object *) this, arg0.ptr());
}

void BaseButton::_unhandled_input(const Ref<InputEvent> arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BaseButton", "_unhandled_input");
	}
	___godot_icall_void_Object(mb, (const Object *) this, arg0.ptr());
}

void BaseButton::set_pressed(const bool pressed) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BaseButton", "set_pressed");
	}
	___godot_icall_void_bool(mb, (const Object *) this, pressed);
}

bool BaseButton::is_pressed() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BaseButton", "is_pressed");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

bool BaseButton::is_hovered() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BaseButton", "is_hovered");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void BaseButton::set_toggle_mode(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BaseButton", "set_toggle_mode");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool BaseButton::is_toggle_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BaseButton", "is_toggle_mode");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void BaseButton::set_disabled(const bool disabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BaseButton", "set_disabled");
	}
	___godot_icall_void_bool(mb, (const Object *) this, disabled);
}

bool BaseButton::is_disabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BaseButton", "is_disabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void BaseButton::set_action_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BaseButton", "set_action_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

BaseButton::ActionMode BaseButton::get_action_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BaseButton", "get_action_mode");
	}
	return (BaseButton::ActionMode) ___godot_icall_int(mb, (const Object *) this);
}

BaseButton::DrawMode BaseButton::get_draw_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BaseButton", "get_draw_mode");
	}
	return (BaseButton::DrawMode) ___godot_icall_int(mb, (const Object *) this);
}

void BaseButton::set_enabled_focus_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BaseButton", "set_enabled_focus_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

Control::FocusMode BaseButton::get_enabled_focus_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BaseButton", "get_enabled_focus_mode");
	}
	return (Control::FocusMode) ___godot_icall_int(mb, (const Object *) this);
}

void BaseButton::set_shortcut(const Ref<ShortCut> shortcut) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BaseButton", "set_shortcut");
	}
	___godot_icall_void_Object(mb, (const Object *) this, shortcut.ptr());
}

Ref<ShortCut> BaseButton::get_shortcut() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BaseButton", "get_shortcut");
	}
	return Ref<ShortCut>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void BaseButton::set_button_group(const Ref<ButtonGroup> button_group) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BaseButton", "set_button_group");
	}
	___godot_icall_void_Object(mb, (const Object *) this, button_group.ptr());
}

Ref<ButtonGroup> BaseButton::get_button_group() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BaseButton", "get_button_group");
	}
	return Ref<ButtonGroup>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

}