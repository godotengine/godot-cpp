#include <RegEx.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <RegExMatch.hpp>


namespace godot {


void *RegEx::___get_type_tag()
{
	return (void *) &RegEx::___get_type_tag;
}

void *RegEx::___get_base_type_tag()
{
	return (void *) &Reference::___get_type_tag;
}

RegEx *RegEx::_new()
{
	return (RegEx *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"RegEx")());
}
void RegEx::clear() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RegEx", "clear");
	}
	___godot_icall_void(mb, (const Object *) this);
}

Error RegEx::compile(const String pattern) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RegEx", "compile");
	}
	return (Error) ___godot_icall_int_String(mb, (const Object *) this, pattern);
}

Ref<RegExMatch> RegEx::search(const String subject, const int64_t offset, const int64_t end) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RegEx", "search");
	}
	return Ref<RegExMatch>::__internal_constructor(___godot_icall_Object_String_int_int(mb, (const Object *) this, subject, offset, end));
}

Array RegEx::search_all(const String subject, const int64_t offset, const int64_t end) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RegEx", "search_all");
	}
	return ___godot_icall_Array_String_int_int(mb, (const Object *) this, subject, offset, end);
}

String RegEx::sub(const String subject, const String replacement, const bool all, const int64_t offset, const int64_t end) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RegEx", "sub");
	}
	return ___godot_icall_String_String_String_bool_int_int(mb, (const Object *) this, subject, replacement, all, offset, end);
}

bool RegEx::is_valid() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RegEx", "is_valid");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

String RegEx::get_pattern() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RegEx", "get_pattern");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

int64_t RegEx::get_group_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RegEx", "get_group_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

Array RegEx::get_names() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RegEx", "get_names");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

}