#ifndef GODOT_CPP_EDITOREXPORTPLUGIN_HPP
#define GODOT_CPP_EDITOREXPORTPLUGIN_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Reference.hpp>
namespace godot {


class EditorExportPlugin : public Reference {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "EditorExportPlugin"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static EditorExportPlugin *_new();

	// methods
	void _export_file(const String path, const String type, const PoolStringArray features);
	void _export_begin(const PoolStringArray features, const bool is_debug, const String path, const int64_t flags);
	void add_shared_object(const String path, const PoolStringArray tags);
	void add_file(const String path, const PoolByteArray file, const bool remap);
	void add_ios_framework(const String path);
	void add_ios_plist_content(const String plist_content);
	void add_ios_linker_flags(const String flags);
	void add_ios_bundle_file(const String path);
	void add_ios_cpp_code(const String code);
	void skip();

};

}

#endif