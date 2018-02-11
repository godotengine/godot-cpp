#include <EditorSceneImporter.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Node.hpp>
#include <Animation.hpp>


namespace godot {


void *EditorSceneImporter::___get_type_tag()
{
	return (void *) &EditorSceneImporter::___get_type_tag;
}

void *EditorSceneImporter::___get_base_type_tag()
{
	return (void *) &Reference::___get_type_tag;
}

EditorSceneImporter *EditorSceneImporter::_new()
{
	return (EditorSceneImporter *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"EditorSceneImporter")());
}
int64_t EditorSceneImporter::_get_import_flags() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorSceneImporter", "_get_import_flags");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

Array EditorSceneImporter::_get_extensions() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorSceneImporter", "_get_extensions");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

Node *EditorSceneImporter::_import_scene(const String path, const int64_t flags, const int64_t bake_fps) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorSceneImporter", "_import_scene");
	}
	return (Node *) ___godot_icall_Object_String_int_int(mb, (const Object *) this, path, flags, bake_fps);
}

Ref<Animation> EditorSceneImporter::_import_animation(const String path, const int64_t flags, const int64_t bake_fps) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorSceneImporter", "_import_animation");
	}
	return Ref<Animation>::__internal_constructor(___godot_icall_Object_String_int_int(mb, (const Object *) this, path, flags, bake_fps));
}

Node *EditorSceneImporter::import_scene_from_other_importer(const String path, const int64_t flags, const int64_t bake_fps) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorSceneImporter", "import_scene_from_other_importer");
	}
	return (Node *) ___godot_icall_Object_String_int_int(mb, (const Object *) this, path, flags, bake_fps);
}

Ref<Animation> EditorSceneImporter::import_animation_from_other_importer(const String path, const int64_t flags, const int64_t bake_fps) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorSceneImporter", "import_animation_from_other_importer");
	}
	return Ref<Animation>::__internal_constructor(___godot_icall_Object_String_int_int(mb, (const Object *) this, path, flags, bake_fps));
}

}