#include <GDNativeLibrary.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <ConfigFile.hpp>


namespace godot {


void *GDNativeLibrary::___get_type_tag()
{
	return (void *) &GDNativeLibrary::___get_type_tag;
}

void *GDNativeLibrary::___get_base_type_tag()
{
	return (void *) &Resource::___get_type_tag;
}

GDNativeLibrary *GDNativeLibrary::_new()
{
	return (GDNativeLibrary *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"GDNativeLibrary")());
}
Ref<ConfigFile> GDNativeLibrary::get_config_file() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GDNativeLibrary", "get_config_file");
	}
	return Ref<ConfigFile>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void GDNativeLibrary::set_config_file(const Ref<ConfigFile> config_file) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GDNativeLibrary", "set_config_file");
	}
	___godot_icall_void_Object(mb, (const Object *) this, config_file.ptr());
}

String GDNativeLibrary::get_current_library_path() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GDNativeLibrary", "get_current_library_path");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

PoolStringArray GDNativeLibrary::get_current_dependencies() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GDNativeLibrary", "get_current_dependencies");
	}
	return ___godot_icall_PoolStringArray(mb, (const Object *) this);
}

bool GDNativeLibrary::should_load_once() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GDNativeLibrary", "should_load_once");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

bool GDNativeLibrary::is_singleton() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GDNativeLibrary", "is_singleton");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

String GDNativeLibrary::get_symbol_prefix() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GDNativeLibrary", "get_symbol_prefix");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

bool GDNativeLibrary::is_reloadable() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GDNativeLibrary", "is_reloadable");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void GDNativeLibrary::set_load_once(const bool load_once) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GDNativeLibrary", "set_load_once");
	}
	___godot_icall_void_bool(mb, (const Object *) this, load_once);
}

void GDNativeLibrary::set_singleton(const bool singleton) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GDNativeLibrary", "set_singleton");
	}
	___godot_icall_void_bool(mb, (const Object *) this, singleton);
}

void GDNativeLibrary::set_symbol_prefix(const String symbol_prefix) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GDNativeLibrary", "set_symbol_prefix");
	}
	___godot_icall_void_String(mb, (const Object *) this, symbol_prefix);
}

void GDNativeLibrary::set_reloadable(const bool reloadable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GDNativeLibrary", "set_reloadable");
	}
	___godot_icall_void_bool(mb, (const Object *) this, reloadable);
}

}