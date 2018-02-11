#include <XMLParser.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *XMLParser::___get_type_tag()
{
	return (void *) &XMLParser::___get_type_tag;
}

void *XMLParser::___get_base_type_tag()
{
	return (void *) &Reference::___get_type_tag;
}

XMLParser *XMLParser::_new()
{
	return (XMLParser *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"XMLParser")());
}
Error XMLParser::read() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("XMLParser", "read");
	}
	return (Error) ___godot_icall_int(mb, (const Object *) this);
}

XMLParser::NodeType XMLParser::get_node_type() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("XMLParser", "get_node_type");
	}
	return (XMLParser::NodeType) ___godot_icall_int(mb, (const Object *) this);
}

String XMLParser::get_node_name() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("XMLParser", "get_node_name");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

String XMLParser::get_node_data() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("XMLParser", "get_node_data");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

int64_t XMLParser::get_node_offset() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("XMLParser", "get_node_offset");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t XMLParser::get_attribute_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("XMLParser", "get_attribute_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

String XMLParser::get_attribute_name(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("XMLParser", "get_attribute_name");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, idx);
}

String XMLParser::get_attribute_value(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("XMLParser", "get_attribute_value");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, idx);
}

bool XMLParser::has_attribute(const String name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("XMLParser", "has_attribute");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, name);
}

String XMLParser::get_named_attribute_value(const String name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("XMLParser", "get_named_attribute_value");
	}
	return ___godot_icall_String_String(mb, (const Object *) this, name);
}

String XMLParser::get_named_attribute_value_safe(const String name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("XMLParser", "get_named_attribute_value_safe");
	}
	return ___godot_icall_String_String(mb, (const Object *) this, name);
}

bool XMLParser::is_empty() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("XMLParser", "is_empty");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

int64_t XMLParser::get_current_line() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("XMLParser", "get_current_line");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void XMLParser::skip_section() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("XMLParser", "skip_section");
	}
	___godot_icall_void(mb, (const Object *) this);
}

Error XMLParser::seek(const int64_t position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("XMLParser", "seek");
	}
	return (Error) ___godot_icall_int_int(mb, (const Object *) this, position);
}

Error XMLParser::open(const String file) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("XMLParser", "open");
	}
	return (Error) ___godot_icall_int_String(mb, (const Object *) this, file);
}

Error XMLParser::open_buffer(const PoolByteArray buffer) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("XMLParser", "open_buffer");
	}
	return (Error) ___godot_icall_int_PoolByteArray(mb, (const Object *) this, buffer);
}

}