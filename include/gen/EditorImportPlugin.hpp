#ifndef GODOT_CPP_EDITORIMPORTPLUGIN_HPP
#define GODOT_CPP_EDITORIMPORTPLUGIN_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Reference.hpp"
namespace godot {


class EditorImportPlugin : public Reference {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "EditorImportPlugin"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static EditorImportPlugin *_new();

	// methods
	String get_importer_name();
	String get_visible_name();
	int64_t get_preset_count();
	String get_preset_name(const int64_t preset);
	Array get_recognized_extensions();
	Array get_import_options(const int64_t preset);
	String get_save_extension();
	String get_resource_type();
	double get_priority();
	int64_t get_import_order();
	bool get_option_visibility(const String option, const Dictionary options);
	int64_t import(const String source_file, const String save_path, const Dictionary options, const Array r_platform_variants, const Array r_gen_files);

};

}

#endif