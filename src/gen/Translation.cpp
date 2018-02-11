#include <Translation.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *Translation::___get_type_tag()
{
	return (void *) &Translation::___get_type_tag;
}

void *Translation::___get_base_type_tag()
{
	return (void *) &Resource::___get_type_tag;
}

Translation *Translation::_new()
{
	return (Translation *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Translation")());
}
void Translation::set_locale(const String locale) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Translation", "set_locale");
	}
	___godot_icall_void_String(mb, (const Object *) this, locale);
}

String Translation::get_locale() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Translation", "get_locale");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void Translation::add_message(const String src_message, const String xlated_message) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Translation", "add_message");
	}
	___godot_icall_void_String_String(mb, (const Object *) this, src_message, xlated_message);
}

String Translation::get_message(const String src_message) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Translation", "get_message");
	}
	return ___godot_icall_String_String(mb, (const Object *) this, src_message);
}

void Translation::erase_message(const String src_message) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Translation", "erase_message");
	}
	___godot_icall_void_String(mb, (const Object *) this, src_message);
}

PoolStringArray Translation::get_message_list() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Translation", "get_message_list");
	}
	return ___godot_icall_PoolStringArray(mb, (const Object *) this);
}

int64_t Translation::get_message_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Translation", "get_message_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void Translation::_set_messages(const PoolStringArray arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Translation", "_set_messages");
	}
	___godot_icall_void_PoolStringArray(mb, (const Object *) this, arg0);
}

PoolStringArray Translation::_get_messages() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Translation", "_get_messages");
	}
	return ___godot_icall_PoolStringArray(mb, (const Object *) this);
}

}