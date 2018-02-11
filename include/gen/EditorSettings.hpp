#ifndef GODOT_CPP_EDITORSETTINGS_HPP
#define GODOT_CPP_EDITORSETTINGS_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Resource.hpp>
namespace godot {


class EditorSettings : public Resource {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "EditorSettings"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants

	// methods
	bool has_setting(const String name) const;
	void set_setting(const String name, const Variant value);
	Variant get_setting(const String name) const;
	void erase(const String property);
	void set_initial_value(const String name, const Variant value, const bool update_current);
	bool property_can_revert(const String name);
	Variant property_get_revert(const String name);
	void add_property_info(const Dictionary info);
	String get_settings_dir() const;
	String get_project_settings_dir() const;
	void set_favorite_dirs(const PoolStringArray dirs);
	PoolStringArray get_favorite_dirs() const;
	void set_recent_dirs(const PoolStringArray dirs);
	PoolStringArray get_recent_dirs() const;

};

}

#endif