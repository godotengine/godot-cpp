#include <EditorFileSystemDirectory.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <EditorFileSystemDirectory.hpp>


namespace godot {


void *EditorFileSystemDirectory::___get_type_tag()
{
	return (void *) &EditorFileSystemDirectory::___get_type_tag;
}

void *EditorFileSystemDirectory::___get_base_type_tag()
{
	return (void *) &Object::___get_type_tag;
}

EditorFileSystemDirectory *EditorFileSystemDirectory::_new()
{
	return (EditorFileSystemDirectory *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"EditorFileSystemDirectory")());
}
int64_t EditorFileSystemDirectory::get_subdir_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileSystemDirectory", "get_subdir_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

EditorFileSystemDirectory *EditorFileSystemDirectory::get_subdir(const int64_t idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileSystemDirectory", "get_subdir");
	}
	return (EditorFileSystemDirectory *) ___godot_icall_Object_int(mb, (const Object *) this, idx);
}

int64_t EditorFileSystemDirectory::get_file_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileSystemDirectory", "get_file_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

String EditorFileSystemDirectory::get_file(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileSystemDirectory", "get_file");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, idx);
}

String EditorFileSystemDirectory::get_file_path(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileSystemDirectory", "get_file_path");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, idx);
}

String EditorFileSystemDirectory::get_file_type(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileSystemDirectory", "get_file_type");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, idx);
}

bool EditorFileSystemDirectory::get_file_import_is_valid(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileSystemDirectory", "get_file_import_is_valid");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, idx);
}

String EditorFileSystemDirectory::get_name() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileSystemDirectory", "get_name");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

String EditorFileSystemDirectory::get_path() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileSystemDirectory", "get_path");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

EditorFileSystemDirectory *EditorFileSystemDirectory::get_parent() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileSystemDirectory", "get_parent");
	}
	return (EditorFileSystemDirectory *) ___godot_icall_Object(mb, (const Object *) this);
}

int64_t EditorFileSystemDirectory::find_file_index(const String name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileSystemDirectory", "find_file_index");
	}
	return ___godot_icall_int_String(mb, (const Object *) this, name);
}

int64_t EditorFileSystemDirectory::find_dir_index(const String name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileSystemDirectory", "find_dir_index");
	}
	return ___godot_icall_int_String(mb, (const Object *) this, name);
}

}