#include <ConfigFile.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *ConfigFile::___get_type_tag()
{
	return (void *) &ConfigFile::___get_type_tag;
}

void *ConfigFile::___get_base_type_tag()
{
	return (void *) &Reference::___get_type_tag;
}

ConfigFile *ConfigFile::_new()
{
	return (ConfigFile *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"ConfigFile")());
}
void ConfigFile::set_value(const String section, const String key, const Variant value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ConfigFile", "set_value");
	}
	___godot_icall_void_String_String_Variant(mb, (const Object *) this, section, key, value);
}

Variant ConfigFile::get_value(const String section, const String key, const Variant _default) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ConfigFile", "get_value");
	}
	return ___godot_icall_Variant_String_String_Variant(mb, (const Object *) this, section, key, _default);
}

bool ConfigFile::has_section(const String section) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ConfigFile", "has_section");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, section);
}

bool ConfigFile::has_section_key(const String section, const String key) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ConfigFile", "has_section_key");
	}
	return ___godot_icall_bool_String_String(mb, (const Object *) this, section, key);
}

PoolStringArray ConfigFile::get_sections() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ConfigFile", "get_sections");
	}
	return ___godot_icall_PoolStringArray(mb, (const Object *) this);
}

PoolStringArray ConfigFile::get_section_keys(const String section) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ConfigFile", "get_section_keys");
	}
	return ___godot_icall_PoolStringArray_String(mb, (const Object *) this, section);
}

void ConfigFile::erase_section(const String section) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ConfigFile", "erase_section");
	}
	___godot_icall_void_String(mb, (const Object *) this, section);
}

Error ConfigFile::load(const String path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ConfigFile", "load");
	}
	return (Error) ___godot_icall_int_String(mb, (const Object *) this, path);
}

Error ConfigFile::save(const String path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ConfigFile", "save");
	}
	return (Error) ___godot_icall_int_String(mb, (const Object *) this, path);
}

}