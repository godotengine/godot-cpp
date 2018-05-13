#ifndef GODOT_CPP_GDNATIVELIBRARY_HPP
#define GODOT_CPP_GDNATIVELIBRARY_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Resource.hpp"
namespace godot {

class ConfigFile;

class GDNativeLibrary : public Resource {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "GDNativeLibrary"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static GDNativeLibrary *_new();

	// methods
	Ref<ConfigFile> get_config_file();
	void set_config_file(const Ref<ConfigFile> config_file);
	String get_current_library_path() const;
	PoolStringArray get_current_dependencies() const;
	bool should_load_once() const;
	bool is_singleton() const;
	String get_symbol_prefix() const;
	bool is_reloadable() const;
	void set_load_once(const bool load_once);
	void set_singleton(const bool singleton);
	void set_symbol_prefix(const String symbol_prefix);
	void set_reloadable(const bool reloadable);

};

}

#endif