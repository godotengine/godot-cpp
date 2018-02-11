#include <RegExMatch.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *RegExMatch::___get_type_tag()
{
	return (void *) &RegExMatch::___get_type_tag;
}

void *RegExMatch::___get_base_type_tag()
{
	return (void *) &Reference::___get_type_tag;
}

RegExMatch *RegExMatch::_new()
{
	return (RegExMatch *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"RegExMatch")());
}
String RegExMatch::get_subject() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RegExMatch", "get_subject");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

int64_t RegExMatch::get_group_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RegExMatch", "get_group_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

Dictionary RegExMatch::get_names() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RegExMatch", "get_names");
	}
	return ___godot_icall_Dictionary(mb, (const Object *) this);
}

Array RegExMatch::get_strings() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RegExMatch", "get_strings");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

String RegExMatch::get_string(const Variant name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RegExMatch", "get_string");
	}
	return ___godot_icall_String_Variant(mb, (const Object *) this, name);
}

int64_t RegExMatch::get_start(const Variant name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RegExMatch", "get_start");
	}
	return ___godot_icall_int_Variant(mb, (const Object *) this, name);
}

int64_t RegExMatch::get_end(const Variant name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RegExMatch", "get_end");
	}
	return ___godot_icall_int_Variant(mb, (const Object *) this, name);
}

}