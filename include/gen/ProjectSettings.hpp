#ifndef GODOT_CPP_PROJECTSETTINGS_HPP
#define GODOT_CPP_PROJECTSETTINGS_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Object.hpp>
namespace godot {


class ProjectSettings : public Object {
	static ProjectSettings *_singleton;

	ProjectSettings();

public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline ProjectSettings *get_singleton()
	{
		if (!ProjectSettings::_singleton) {
			ProjectSettings::_singleton = new ProjectSettings;
		}
		return ProjectSettings::_singleton;
	}

	static inline const char *___get_class_name() { return (const char *) "ProjectSettings"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants

	// methods
	bool has_setting(const String name) const;
	void set_setting(const String name, const Variant value);
	Variant get_setting(const String name) const;
	void set_order(const String name, const int64_t position);
	int64_t get_order(const String name) const;
	void set_initial_value(const String name, const Variant value);
	void add_property_info(const Dictionary hint);
	void clear(const String name);
	String localize_path(const String path) const;
	String globalize_path(const String path) const;
	Error save();
	bool load_resource_pack(const String pack);
	bool property_can_revert(const String name);
	Variant property_get_revert(const String name);
	Error save_custom(const String file);

};

}

#endif