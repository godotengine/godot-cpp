#ifndef GODOT_CPP_EDITORFILESYSTEMDIRECTORY_HPP
#define GODOT_CPP_EDITORFILESYSTEMDIRECTORY_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Object.hpp"
namespace godot {

class EditorFileSystemDirectory;

class EditorFileSystemDirectory : public Object {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "EditorFileSystemDirectory"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static EditorFileSystemDirectory *_new();

	// methods
	int64_t get_subdir_count() const;
	EditorFileSystemDirectory *get_subdir(const int64_t idx);
	int64_t get_file_count() const;
	String get_file(const int64_t idx) const;
	String get_file_path(const int64_t idx) const;
	String get_file_type(const int64_t idx) const;
	bool get_file_import_is_valid(const int64_t idx) const;
	String get_name();
	String get_path() const;
	EditorFileSystemDirectory *get_parent();
	int64_t find_file_index(const String name) const;
	int64_t find_dir_index(const String name) const;

};

}

#endif