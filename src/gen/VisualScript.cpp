#include <VisualScript.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <VisualScriptNode.hpp>


namespace godot {


void *VisualScript::___get_type_tag()
{
	return (void *) &VisualScript::___get_type_tag;
}

void *VisualScript::___get_base_type_tag()
{
	return (void *) &Script::___get_type_tag;
}

VisualScript *VisualScript::_new()
{
	return (VisualScript *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"VisualScript")());
}
void VisualScript::_node_ports_changed(const int64_t arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "_node_ports_changed");
	}
	___godot_icall_void_int(mb, (const Object *) this, arg0);
}

void VisualScript::add_function(const String name) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "add_function");
	}
	___godot_icall_void_String(mb, (const Object *) this, name);
}

bool VisualScript::has_function(const String name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "has_function");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, name);
}

void VisualScript::remove_function(const String name) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "remove_function");
	}
	___godot_icall_void_String(mb, (const Object *) this, name);
}

void VisualScript::rename_function(const String name, const String new_name) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "rename_function");
	}
	___godot_icall_void_String_String(mb, (const Object *) this, name, new_name);
}

void VisualScript::set_function_scroll(const String name, const Vector2 ofs) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "set_function_scroll");
	}
	___godot_icall_void_String_Vector2(mb, (const Object *) this, name, ofs);
}

Vector2 VisualScript::get_function_scroll(const String name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "get_function_scroll");
	}
	return ___godot_icall_Vector2_String(mb, (const Object *) this, name);
}

void VisualScript::add_node(const String func, const int64_t id, const Ref<VisualScriptNode> node, const Vector2 position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "add_node");
	}
	___godot_icall_void_String_int_Object_Vector2(mb, (const Object *) this, func, id, node.ptr(), position);
}

void VisualScript::remove_node(const String func, const int64_t id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "remove_node");
	}
	___godot_icall_void_String_int(mb, (const Object *) this, func, id);
}

int64_t VisualScript::get_function_node_id(const String name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "get_function_node_id");
	}
	return ___godot_icall_int_String(mb, (const Object *) this, name);
}

Ref<VisualScriptNode> VisualScript::get_node(const String func, const int64_t id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "get_node");
	}
	return Ref<VisualScriptNode>::__internal_constructor(___godot_icall_Object_String_int(mb, (const Object *) this, func, id));
}

bool VisualScript::has_node(const String func, const int64_t id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "has_node");
	}
	return ___godot_icall_bool_String_int(mb, (const Object *) this, func, id);
}

void VisualScript::set_node_position(const String func, const int64_t id, const Vector2 position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "set_node_position");
	}
	___godot_icall_void_String_int_Vector2(mb, (const Object *) this, func, id, position);
}

Vector2 VisualScript::get_node_position(const String func, const int64_t id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "get_node_position");
	}
	return ___godot_icall_Vector2_String_int(mb, (const Object *) this, func, id);
}

void VisualScript::sequence_connect(const String func, const int64_t from_node, const int64_t from_output, const int64_t to_node) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "sequence_connect");
	}
	___godot_icall_void_String_int_int_int(mb, (const Object *) this, func, from_node, from_output, to_node);
}

void VisualScript::sequence_disconnect(const String func, const int64_t from_node, const int64_t from_output, const int64_t to_node) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "sequence_disconnect");
	}
	___godot_icall_void_String_int_int_int(mb, (const Object *) this, func, from_node, from_output, to_node);
}

bool VisualScript::has_sequence_connection(const String func, const int64_t from_node, const int64_t from_output, const int64_t to_node) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "has_sequence_connection");
	}
	return ___godot_icall_bool_String_int_int_int(mb, (const Object *) this, func, from_node, from_output, to_node);
}

void VisualScript::data_connect(const String func, const int64_t from_node, const int64_t from_port, const int64_t to_node, const int64_t to_port) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "data_connect");
	}
	___godot_icall_void_String_int_int_int_int(mb, (const Object *) this, func, from_node, from_port, to_node, to_port);
}

void VisualScript::data_disconnect(const String func, const int64_t from_node, const int64_t from_port, const int64_t to_node, const int64_t to_port) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "data_disconnect");
	}
	___godot_icall_void_String_int_int_int_int(mb, (const Object *) this, func, from_node, from_port, to_node, to_port);
}

bool VisualScript::has_data_connection(const String func, const int64_t from_node, const int64_t from_port, const int64_t to_node, const int64_t to_port) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "has_data_connection");
	}
	return ___godot_icall_bool_String_int_int_int_int(mb, (const Object *) this, func, from_node, from_port, to_node, to_port);
}

void VisualScript::add_variable(const String name, const Variant default_value, const bool _export) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "add_variable");
	}
	___godot_icall_void_String_Variant_bool(mb, (const Object *) this, name, default_value, _export);
}

bool VisualScript::has_variable(const String name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "has_variable");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, name);
}

void VisualScript::remove_variable(const String name) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "remove_variable");
	}
	___godot_icall_void_String(mb, (const Object *) this, name);
}

void VisualScript::set_variable_default_value(const String name, const Variant value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "set_variable_default_value");
	}
	___godot_icall_void_String_Variant(mb, (const Object *) this, name, value);
}

Variant VisualScript::get_variable_default_value(const String name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "get_variable_default_value");
	}
	return ___godot_icall_Variant_String(mb, (const Object *) this, name);
}

void VisualScript::set_variable_info(const String name, const Dictionary value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "set_variable_info");
	}
	___godot_icall_void_String_Dictionary(mb, (const Object *) this, name, value);
}

Dictionary VisualScript::get_variable_info(const String name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "get_variable_info");
	}
	return ___godot_icall_Dictionary_String(mb, (const Object *) this, name);
}

void VisualScript::set_variable_export(const String name, const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "set_variable_export");
	}
	___godot_icall_void_String_bool(mb, (const Object *) this, name, enable);
}

bool VisualScript::get_variable_export(const String name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "get_variable_export");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, name);
}

void VisualScript::rename_variable(const String name, const String new_name) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "rename_variable");
	}
	___godot_icall_void_String_String(mb, (const Object *) this, name, new_name);
}

void VisualScript::add_custom_signal(const String name) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "add_custom_signal");
	}
	___godot_icall_void_String(mb, (const Object *) this, name);
}

bool VisualScript::has_custom_signal(const String name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "has_custom_signal");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, name);
}

void VisualScript::custom_signal_add_argument(const String name, const int64_t type, const String argname, const int64_t index) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "custom_signal_add_argument");
	}
	___godot_icall_void_String_int_String_int(mb, (const Object *) this, name, type, argname, index);
}

void VisualScript::custom_signal_set_argument_type(const String name, const int64_t argidx, const int64_t type) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "custom_signal_set_argument_type");
	}
	___godot_icall_void_String_int_int(mb, (const Object *) this, name, argidx, type);
}

Variant::Type VisualScript::custom_signal_get_argument_type(const String name, const int64_t argidx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "custom_signal_get_argument_type");
	}
	return (Variant::Type) ___godot_icall_int_String_int(mb, (const Object *) this, name, argidx);
}

void VisualScript::custom_signal_set_argument_name(const String name, const int64_t argidx, const String argname) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "custom_signal_set_argument_name");
	}
	___godot_icall_void_String_int_String(mb, (const Object *) this, name, argidx, argname);
}

String VisualScript::custom_signal_get_argument_name(const String name, const int64_t argidx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "custom_signal_get_argument_name");
	}
	return ___godot_icall_String_String_int(mb, (const Object *) this, name, argidx);
}

void VisualScript::custom_signal_remove_argument(const String name, const int64_t argidx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "custom_signal_remove_argument");
	}
	___godot_icall_void_String_int(mb, (const Object *) this, name, argidx);
}

int64_t VisualScript::custom_signal_get_argument_count(const String name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "custom_signal_get_argument_count");
	}
	return ___godot_icall_int_String(mb, (const Object *) this, name);
}

void VisualScript::custom_signal_swap_argument(const String name, const int64_t argidx, const int64_t withidx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "custom_signal_swap_argument");
	}
	___godot_icall_void_String_int_int(mb, (const Object *) this, name, argidx, withidx);
}

void VisualScript::remove_custom_signal(const String name) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "remove_custom_signal");
	}
	___godot_icall_void_String(mb, (const Object *) this, name);
}

void VisualScript::rename_custom_signal(const String name, const String new_name) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "rename_custom_signal");
	}
	___godot_icall_void_String_String(mb, (const Object *) this, name, new_name);
}

void VisualScript::set_instance_base_type(const String type) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "set_instance_base_type");
	}
	___godot_icall_void_String(mb, (const Object *) this, type);
}

void VisualScript::_set_data(const Dictionary data) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "_set_data");
	}
	___godot_icall_void_Dictionary(mb, (const Object *) this, data);
}

Dictionary VisualScript::_get_data() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScript", "_get_data");
	}
	return ___godot_icall_Dictionary(mb, (const Object *) this);
}

}