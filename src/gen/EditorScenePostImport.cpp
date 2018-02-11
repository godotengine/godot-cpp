#include <EditorScenePostImport.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Object.hpp>


namespace godot {


void *EditorScenePostImport::___get_type_tag()
{
	return (void *) &EditorScenePostImport::___get_type_tag;
}

void *EditorScenePostImport::___get_base_type_tag()
{
	return (void *) &Reference::___get_type_tag;
}

EditorScenePostImport *EditorScenePostImport::_new()
{
	return (EditorScenePostImport *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"EditorScenePostImport")());
}
void EditorScenePostImport::post_import(const Object *scene) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorScenePostImport", "post_import");
	}
	___godot_icall_void_Object(mb, (const Object *) this, scene);
}

}