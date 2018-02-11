#include <InputMap.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <InputEvent.hpp>


namespace godot {


void *InputMap::___get_type_tag()
{
	return (void *) &InputMap::___get_type_tag;
}

void *InputMap::___get_base_type_tag()
{
	return (void *) &Object::___get_type_tag;
}

InputMap *InputMap::_singleton = NULL;


InputMap::InputMap() {
	_owner = godot::api->godot_global_get_singleton((char *) "InputMap");
}


bool InputMap::has_action(const String action) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputMap", "has_action");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, action);
}

Array InputMap::get_actions() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputMap", "get_actions");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

void InputMap::add_action(const String action) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputMap", "add_action");
	}
	___godot_icall_void_String(mb, (const Object *) this, action);
}

void InputMap::erase_action(const String action) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputMap", "erase_action");
	}
	___godot_icall_void_String(mb, (const Object *) this, action);
}

void InputMap::action_add_event(const String action, const Ref<InputEvent> event) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputMap", "action_add_event");
	}
	___godot_icall_void_String_Object(mb, (const Object *) this, action, event.ptr());
}

bool InputMap::action_has_event(const String action, const Ref<InputEvent> event) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputMap", "action_has_event");
	}
	return ___godot_icall_bool_String_Object(mb, (const Object *) this, action, event.ptr());
}

void InputMap::action_erase_event(const String action, const Ref<InputEvent> event) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputMap", "action_erase_event");
	}
	___godot_icall_void_String_Object(mb, (const Object *) this, action, event.ptr());
}

Array InputMap::get_action_list(const String action) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputMap", "get_action_list");
	}
	return ___godot_icall_Array_String(mb, (const Object *) this, action);
}

bool InputMap::event_is_action(const Ref<InputEvent> event, const String action) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputMap", "event_is_action");
	}
	return ___godot_icall_bool_Object_String(mb, (const Object *) this, event.ptr(), action);
}

void InputMap::load_from_globals() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputMap", "load_from_globals");
	}
	___godot_icall_void(mb, (const Object *) this);
}

}