#ifndef GODOT_CPP_DIRECTORY_HPP
#define GODOT_CPP_DIRECTORY_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Reference.hpp>
namespace godot {


class Directory : public Reference {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Directory"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static Directory *_new();

	// methods
	Error open(const String path);
	Error list_dir_begin(const bool skip_navigational = false, const bool skip_hidden = false);
	String get_next();
	bool current_is_dir() const;
	void list_dir_end();
	int64_t get_drive_count();
	String get_drive(const int64_t idx);
	int64_t get_current_drive();
	Error change_dir(const String todir);
	String get_current_dir();
	Error make_dir(const String path);
	Error make_dir_recursive(const String path);
	bool file_exists(const String path);
	bool dir_exists(const String path);
	int64_t get_space_left();
	Error copy(const String from, const String to);
	Error rename(const String from, const String to);
	Error remove(const String path);

};

}

#endif