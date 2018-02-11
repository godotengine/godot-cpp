#ifndef GODOT_CPP_CONFIGFILE_HPP
#define GODOT_CPP_CONFIGFILE_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Reference.hpp>
namespace godot {


class ConfigFile : public Reference {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "ConfigFile"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static ConfigFile *_new();

	// methods
	void set_value(const String section, const String key, const Variant value);
	Variant get_value(const String section, const String key, const Variant _default = Variant()) const;
	bool has_section(const String section) const;
	bool has_section_key(const String section, const String key) const;
	PoolStringArray get_sections() const;
	PoolStringArray get_section_keys(const String section) const;
	void erase_section(const String section);
	Error load(const String path);
	Error save(const String path);

};

}

#endif