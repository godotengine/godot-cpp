#ifndef GODOT_CPP_EDITORSCENEIMPORTER_HPP
#define GODOT_CPP_EDITORSCENEIMPORTER_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Reference.hpp>
namespace godot {

class Node;
class Animation;

class EditorSceneImporter : public Reference {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "EditorSceneImporter"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants
	const static int IMPORT_GENERATE_TANGENT_ARRAYS = 256;
	const static int IMPORT_ANIMATION_FORCE_ALL_TRACKS_IN_ALL_CLIPS = 16;
	const static int IMPORT_ANIMATION_OPTIMIZE = 8;
	const static int IMPORT_ANIMATION_KEEP_VALUE_TRACKS = 32;
	const static int IMPORT_MATERIALS_IN_INSTANCES = 1024;
	const static int IMPORT_FAIL_ON_MISSING_DEPENDENCIES = 512;
	const static int IMPORT_USE_COMPRESSION = 2048;
	const static int IMPORT_ANIMATION = 2;
	const static int IMPORT_SCENE = 1;
	const static int IMPORT_ANIMATION_DETECT_LOOP = 4;


	static EditorSceneImporter *_new();

	// methods
	int64_t _get_import_flags();
	Array _get_extensions();
	Node *_import_scene(const String path, const int64_t flags, const int64_t bake_fps);
	Ref<Animation> _import_animation(const String path, const int64_t flags, const int64_t bake_fps);
	Node *import_scene_from_other_importer(const String path, const int64_t flags, const int64_t bake_fps);
	Ref<Animation> import_animation_from_other_importer(const String path, const int64_t flags, const int64_t bake_fps);

};

}

#endif