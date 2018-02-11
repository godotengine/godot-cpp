#include <VisualScriptPropertyGet.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *VisualScriptPropertyGet::___get_type_tag()
{
	return (void *) &VisualScriptPropertyGet::___get_type_tag;
}

void *VisualScriptPropertyGet::___get_base_type_tag()
{
	return (void *) &VisualScriptNode::___get_type_tag;
}

VisualScriptPropertyGet *VisualScriptPropertyGet::_new()
{
	return (VisualScriptPropertyGet *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"VisualScriptPropertyGet")());
}
void VisualScriptPropertyGet::set_base_type(const String base_type) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptPropertyGet", "set_base_type");
	}
	___godot_icall_void_String(mb, (const Object *) this, base_type);
}

String VisualScriptPropertyGet::get_base_type() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptPropertyGet", "get_base_type");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void VisualScriptPropertyGet::set_base_script(const String base_script) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptPropertyGet", "set_base_script");
	}
	___godot_icall_void_String(mb, (const Object *) this, base_script);
}

String VisualScriptPropertyGet::get_base_script() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptPropertyGet", "get_base_script");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void VisualScriptPropertyGet::set_basic_type(const int64_t basic_type) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptPropertyGet", "set_basic_type");
	}
	___godot_icall_void_int(mb, (const Object *) this, basic_type);
}

Variant::Type VisualScriptPropertyGet::get_basic_type() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptPropertyGet", "get_basic_type");
	}
	return (Variant::Type) ___godot_icall_int(mb, (const Object *) this);
}

void VisualScriptPropertyGet::_set_type_cache(const int64_t type_cache) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptPropertyGet", "_set_type_cache");
	}
	___godot_icall_void_int(mb, (const Object *) this, type_cache);
}

Variant::Type VisualScriptPropertyGet::_get_type_cache() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptPropertyGet", "_get_type_cache");
	}
	return (Variant::Type) ___godot_icall_int(mb, (const Object *) this);
}

void VisualScriptPropertyGet::set_property(const String property) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptPropertyGet", "set_property");
	}
	___godot_icall_void_String(mb, (const Object *) this, property);
}

String VisualScriptPropertyGet::get_property() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptPropertyGet", "get_property");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void VisualScriptPropertyGet::set_call_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptPropertyGet", "set_call_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

VisualScriptPropertyGet::CallMode VisualScriptPropertyGet::get_call_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptPropertyGet", "get_call_mode");
	}
	return (VisualScriptPropertyGet::CallMode) ___godot_icall_int(mb, (const Object *) this);
}

void VisualScriptPropertyGet::set_base_path(const NodePath base_path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptPropertyGet", "set_base_path");
	}
	___godot_icall_void_NodePath(mb, (const Object *) this, base_path);
}

NodePath VisualScriptPropertyGet::get_base_path() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptPropertyGet", "get_base_path");
	}
	return ___godot_icall_NodePath(mb, (const Object *) this);
}

void VisualScriptPropertyGet::set_index(const String index) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptPropertyGet", "set_index");
	}
	___godot_icall_void_String(mb, (const Object *) this, index);
}

String VisualScriptPropertyGet::get_index() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptPropertyGet", "get_index");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

}