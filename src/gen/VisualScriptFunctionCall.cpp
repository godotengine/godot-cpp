#include <VisualScriptFunctionCall.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *VisualScriptFunctionCall::___get_type_tag()
{
	return (void *) &VisualScriptFunctionCall::___get_type_tag;
}

void *VisualScriptFunctionCall::___get_base_type_tag()
{
	return (void *) &VisualScriptNode::___get_type_tag;
}

VisualScriptFunctionCall *VisualScriptFunctionCall::_new()
{
	return (VisualScriptFunctionCall *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"VisualScriptFunctionCall")());
}
void VisualScriptFunctionCall::set_base_type(const String base_type) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptFunctionCall", "set_base_type");
	}
	___godot_icall_void_String(mb, (const Object *) this, base_type);
}

String VisualScriptFunctionCall::get_base_type() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptFunctionCall", "get_base_type");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void VisualScriptFunctionCall::set_base_script(const String base_script) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptFunctionCall", "set_base_script");
	}
	___godot_icall_void_String(mb, (const Object *) this, base_script);
}

String VisualScriptFunctionCall::get_base_script() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptFunctionCall", "get_base_script");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void VisualScriptFunctionCall::set_basic_type(const int64_t basic_type) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptFunctionCall", "set_basic_type");
	}
	___godot_icall_void_int(mb, (const Object *) this, basic_type);
}

Variant::Type VisualScriptFunctionCall::get_basic_type() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptFunctionCall", "get_basic_type");
	}
	return (Variant::Type) ___godot_icall_int(mb, (const Object *) this);
}

void VisualScriptFunctionCall::set_singleton(const String singleton) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptFunctionCall", "set_singleton");
	}
	___godot_icall_void_String(mb, (const Object *) this, singleton);
}

String VisualScriptFunctionCall::get_singleton() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptFunctionCall", "get_singleton");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void VisualScriptFunctionCall::set_function(const String function) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptFunctionCall", "set_function");
	}
	___godot_icall_void_String(mb, (const Object *) this, function);
}

String VisualScriptFunctionCall::get_function() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptFunctionCall", "get_function");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void VisualScriptFunctionCall::set_call_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptFunctionCall", "set_call_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

VisualScriptFunctionCall::CallMode VisualScriptFunctionCall::get_call_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptFunctionCall", "get_call_mode");
	}
	return (VisualScriptFunctionCall::CallMode) ___godot_icall_int(mb, (const Object *) this);
}

void VisualScriptFunctionCall::set_base_path(const NodePath base_path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptFunctionCall", "set_base_path");
	}
	___godot_icall_void_NodePath(mb, (const Object *) this, base_path);
}

NodePath VisualScriptFunctionCall::get_base_path() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptFunctionCall", "get_base_path");
	}
	return ___godot_icall_NodePath(mb, (const Object *) this);
}

void VisualScriptFunctionCall::set_use_default_args(const int64_t amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptFunctionCall", "set_use_default_args");
	}
	___godot_icall_void_int(mb, (const Object *) this, amount);
}

int64_t VisualScriptFunctionCall::get_use_default_args() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptFunctionCall", "get_use_default_args");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void VisualScriptFunctionCall::_set_argument_cache(const Dictionary argument_cache) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptFunctionCall", "_set_argument_cache");
	}
	___godot_icall_void_Dictionary(mb, (const Object *) this, argument_cache);
}

Dictionary VisualScriptFunctionCall::_get_argument_cache() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptFunctionCall", "_get_argument_cache");
	}
	return ___godot_icall_Dictionary(mb, (const Object *) this);
}

void VisualScriptFunctionCall::set_rpc_call_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptFunctionCall", "set_rpc_call_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

VisualScriptFunctionCall::RPCCallMode VisualScriptFunctionCall::get_rpc_call_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptFunctionCall", "get_rpc_call_mode");
	}
	return (VisualScriptFunctionCall::RPCCallMode) ___godot_icall_int(mb, (const Object *) this);
}

void VisualScriptFunctionCall::set_validate(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptFunctionCall", "set_validate");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool VisualScriptFunctionCall::get_validate() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptFunctionCall", "get_validate");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

}