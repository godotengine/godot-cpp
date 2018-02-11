#include <Script.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Object.hpp>
#include <Script.hpp>


namespace godot {


void *Script::___get_type_tag()
{
	return (void *) &Script::___get_type_tag;
}

void *Script::___get_base_type_tag()
{
	return (void *) &Resource::___get_type_tag;
}

bool Script::can_instance() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Script", "can_instance");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

bool Script::instance_has(const Object *base_object) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Script", "instance_has");
	}
	return ___godot_icall_bool_Object(mb, (const Object *) this, base_object);
}

bool Script::has_source_code() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Script", "has_source_code");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

String Script::get_source_code() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Script", "get_source_code");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void Script::set_source_code(const String source) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Script", "set_source_code");
	}
	___godot_icall_void_String(mb, (const Object *) this, source);
}

Error Script::reload(const bool keep_state) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Script", "reload");
	}
	return (Error) ___godot_icall_int_bool(mb, (const Object *) this, keep_state);
}

Ref<Script> Script::get_base_script() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Script", "get_base_script");
	}
	return Ref<Script>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

String Script::get_instance_base_type() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Script", "get_instance_base_type");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

bool Script::has_script_signal(const String signal_name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Script", "has_script_signal");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, signal_name);
}

bool Script::is_tool() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Script", "is_tool");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

}