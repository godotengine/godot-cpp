#include <JSONParseResult.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *JSONParseResult::___get_type_tag()
{
	return (void *) &JSONParseResult::___get_type_tag;
}

void *JSONParseResult::___get_base_type_tag()
{
	return (void *) &Reference::___get_type_tag;
}

JSONParseResult *JSONParseResult::_new()
{
	return (JSONParseResult *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"JSONParseResult")());
}
Error JSONParseResult::get_error() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("JSONParseResult", "get_error");
	}
	return (Error) ___godot_icall_int(mb, (const Object *) this);
}

String JSONParseResult::get_error_string() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("JSONParseResult", "get_error_string");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

int64_t JSONParseResult::get_error_line() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("JSONParseResult", "get_error_line");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

Variant JSONParseResult::get_result() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("JSONParseResult", "get_result");
	}
	return ___godot_icall_Variant(mb, (const Object *) this);
}

void JSONParseResult::set_error(const int64_t error) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("JSONParseResult", "set_error");
	}
	___godot_icall_void_int(mb, (const Object *) this, error);
}

void JSONParseResult::set_error_string(const String error_string) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("JSONParseResult", "set_error_string");
	}
	___godot_icall_void_String(mb, (const Object *) this, error_string);
}

void JSONParseResult::set_error_line(const int64_t error_line) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("JSONParseResult", "set_error_line");
	}
	___godot_icall_void_int(mb, (const Object *) this, error_line);
}

void JSONParseResult::set_result(const Variant result) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("JSONParseResult", "set_result");
	}
	___godot_icall_void_Variant(mb, (const Object *) this, result);
}

}