#include <EditorImportPlugin.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *EditorImportPlugin::___get_type_tag()
{
	return (void *) &EditorImportPlugin::___get_type_tag;
}

void *EditorImportPlugin::___get_base_type_tag()
{
	return (void *) &Reference::___get_type_tag;
}

EditorImportPlugin *EditorImportPlugin::_new()
{
	return (EditorImportPlugin *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"EditorImportPlugin")());
}
String EditorImportPlugin::get_importer_name() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorImportPlugin", "get_importer_name");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

String EditorImportPlugin::get_visible_name() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorImportPlugin", "get_visible_name");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

int64_t EditorImportPlugin::get_preset_count() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorImportPlugin", "get_preset_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

String EditorImportPlugin::get_preset_name(const int64_t preset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorImportPlugin", "get_preset_name");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, preset);
}

Array EditorImportPlugin::get_recognized_extensions() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorImportPlugin", "get_recognized_extensions");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

Array EditorImportPlugin::get_import_options(const int64_t preset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorImportPlugin", "get_import_options");
	}
	return ___godot_icall_Array_int(mb, (const Object *) this, preset);
}

String EditorImportPlugin::get_save_extension() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorImportPlugin", "get_save_extension");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

String EditorImportPlugin::get_resource_type() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorImportPlugin", "get_resource_type");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

double EditorImportPlugin::get_priority() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorImportPlugin", "get_priority");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

int64_t EditorImportPlugin::get_import_order() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorImportPlugin", "get_import_order");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

bool EditorImportPlugin::get_option_visibility(const String option, const Dictionary options) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorImportPlugin", "get_option_visibility");
	}
	return ___godot_icall_bool_String_Dictionary(mb, (const Object *) this, option, options);
}

int64_t EditorImportPlugin::import(const String source_file, const String save_path, const Dictionary options, const Array r_platform_variants, const Array r_gen_files) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorImportPlugin", "import");
	}
	return ___godot_icall_int_String_String_Dictionary_Array_Array(mb, (const Object *) this, source_file, save_path, options, r_platform_variants, r_gen_files);
}

}