#include <InputEvent.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <InputEvent.hpp>


namespace godot {


void *InputEvent::___get_type_tag()
{
	return (void *) &InputEvent::___get_type_tag;
}

void *InputEvent::___get_base_type_tag()
{
	return (void *) &Resource::___get_type_tag;
}

void InputEvent::set_device(const int64_t device) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEvent", "set_device");
	}
	___godot_icall_void_int(mb, (const Object *) this, device);
}

int64_t InputEvent::get_device() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEvent", "get_device");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

bool InputEvent::is_pressed() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEvent", "is_pressed");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

bool InputEvent::is_action(const String action) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEvent", "is_action");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, action);
}

bool InputEvent::is_action_pressed(const String action) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEvent", "is_action_pressed");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, action);
}

bool InputEvent::is_action_released(const String action) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEvent", "is_action_released");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, action);
}

bool InputEvent::is_echo() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEvent", "is_echo");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

String InputEvent::as_text() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEvent", "as_text");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

bool InputEvent::action_match(const Ref<InputEvent> event) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEvent", "action_match");
	}
	return ___godot_icall_bool_Object(mb, (const Object *) this, event.ptr());
}

bool InputEvent::shortcut_match(const Ref<InputEvent> event) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEvent", "shortcut_match");
	}
	return ___godot_icall_bool_Object(mb, (const Object *) this, event.ptr());
}

bool InputEvent::is_action_type() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEvent", "is_action_type");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

Ref<InputEvent> InputEvent::xformed_by(const Transform2D xform, const Vector2 local_ofs) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEvent", "xformed_by");
	}
	return Ref<InputEvent>::__internal_constructor(___godot_icall_Object_Transform2D_Vector2(mb, (const Object *) this, xform, local_ofs));
}

}