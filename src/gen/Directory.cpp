#include <Directory.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *Directory::___get_type_tag()
{
	return (void *) &Directory::___get_type_tag;
}

void *Directory::___get_base_type_tag()
{
	return (void *) &Reference::___get_type_tag;
}

Directory *Directory::_new()
{
	return (Directory *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"_Directory")());
}
Error Directory::open(const String path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Directory", "open");
	}
	return (Error) ___godot_icall_int_String(mb, (const Object *) this, path);
}

Error Directory::list_dir_begin(const bool skip_navigational, const bool skip_hidden) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Directory", "list_dir_begin");
	}
	return (Error) ___godot_icall_int_bool_bool(mb, (const Object *) this, skip_navigational, skip_hidden);
}

String Directory::get_next() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Directory", "get_next");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

bool Directory::current_is_dir() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Directory", "current_is_dir");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Directory::list_dir_end() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Directory", "list_dir_end");
	}
	___godot_icall_void(mb, (const Object *) this);
}

int64_t Directory::get_drive_count() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Directory", "get_drive_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

String Directory::get_drive(const int64_t idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Directory", "get_drive");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, idx);
}

int64_t Directory::get_current_drive() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Directory", "get_current_drive");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

Error Directory::change_dir(const String todir) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Directory", "change_dir");
	}
	return (Error) ___godot_icall_int_String(mb, (const Object *) this, todir);
}

String Directory::get_current_dir() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Directory", "get_current_dir");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

Error Directory::make_dir(const String path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Directory", "make_dir");
	}
	return (Error) ___godot_icall_int_String(mb, (const Object *) this, path);
}

Error Directory::make_dir_recursive(const String path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Directory", "make_dir_recursive");
	}
	return (Error) ___godot_icall_int_String(mb, (const Object *) this, path);
}

bool Directory::file_exists(const String path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Directory", "file_exists");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, path);
}

bool Directory::dir_exists(const String path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Directory", "dir_exists");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, path);
}

int64_t Directory::get_space_left() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Directory", "get_space_left");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

Error Directory::copy(const String from, const String to) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Directory", "copy");
	}
	return (Error) ___godot_icall_int_String_String(mb, (const Object *) this, from, to);
}

Error Directory::rename(const String from, const String to) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Directory", "rename");
	}
	return (Error) ___godot_icall_int_String_String(mb, (const Object *) this, from, to);
}

Error Directory::remove(const String path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Directory", "remove");
	}
	return (Error) ___godot_icall_int_String(mb, (const Object *) this, path);
}

}