#include <EditorExportPlugin.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *EditorExportPlugin::___get_type_tag()
{
	return (void *) &EditorExportPlugin::___get_type_tag;
}

void *EditorExportPlugin::___get_base_type_tag()
{
	return (void *) &Reference::___get_type_tag;
}

EditorExportPlugin *EditorExportPlugin::_new()
{
	return (EditorExportPlugin *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"EditorExportPlugin")());
}
void EditorExportPlugin::_export_file(const String path, const String type, const PoolStringArray features) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorExportPlugin", "_export_file");
	}
	___godot_icall_void_String_String_PoolStringArray(mb, (const Object *) this, path, type, features);
}

void EditorExportPlugin::_export_begin(const PoolStringArray features, const bool is_debug, const String path, const int64_t flags) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorExportPlugin", "_export_begin");
	}
	___godot_icall_void_PoolStringArray_bool_String_int(mb, (const Object *) this, features, is_debug, path, flags);
}

void EditorExportPlugin::add_shared_object(const String path, const PoolStringArray tags) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorExportPlugin", "add_shared_object");
	}
	___godot_icall_void_String_PoolStringArray(mb, (const Object *) this, path, tags);
}

void EditorExportPlugin::add_file(const String path, const PoolByteArray file, const bool remap) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorExportPlugin", "add_file");
	}
	___godot_icall_void_String_PoolByteArray_bool(mb, (const Object *) this, path, file, remap);
}

void EditorExportPlugin::add_ios_framework(const String path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorExportPlugin", "add_ios_framework");
	}
	___godot_icall_void_String(mb, (const Object *) this, path);
}

void EditorExportPlugin::add_ios_plist_content(const String plist_content) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorExportPlugin", "add_ios_plist_content");
	}
	___godot_icall_void_String(mb, (const Object *) this, plist_content);
}

void EditorExportPlugin::add_ios_linker_flags(const String flags) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorExportPlugin", "add_ios_linker_flags");
	}
	___godot_icall_void_String(mb, (const Object *) this, flags);
}

void EditorExportPlugin::add_ios_bundle_file(const String path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorExportPlugin", "add_ios_bundle_file");
	}
	___godot_icall_void_String(mb, (const Object *) this, path);
}

void EditorExportPlugin::add_ios_cpp_code(const String code) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorExportPlugin", "add_ios_cpp_code");
	}
	___godot_icall_void_String(mb, (const Object *) this, code);
}

void EditorExportPlugin::skip() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorExportPlugin", "skip");
	}
	___godot_icall_void(mb, (const Object *) this);
}

}