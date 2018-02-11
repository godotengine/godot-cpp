#ifndef GODOT_CPP_EDITORFILESYSTEM_HPP
#define GODOT_CPP_EDITORFILESYSTEM_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Node.hpp>
namespace godot {

class EditorFileSystemDirectory;

class EditorFileSystem : public Node {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "EditorFileSystem"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants

	// methods
	EditorFileSystemDirectory *get_filesystem();
	bool is_scanning() const;
	double get_scanning_progress() const;
	void scan();
	void scan_sources();
	void update_file(const String path);
	EditorFileSystemDirectory *get_filesystem_path(const String path);
	String get_file_type(const String path) const;

};

}

#endif