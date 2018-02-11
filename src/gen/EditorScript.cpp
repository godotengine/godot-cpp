#include <EditorScript.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Object.hpp>
#include <Node.hpp>
#include <EditorInterface.hpp>


namespace godot {


void *EditorScript::___get_type_tag()
{
	return (void *) &EditorScript::___get_type_tag;
}

void *EditorScript::___get_base_type_tag()
{
	return (void *) &Reference::___get_type_tag;
}

EditorScript *EditorScript::_new()
{
	return (EditorScript *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"EditorScript")());
}
void EditorScript::_run() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorScript", "_run");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void EditorScript::add_root_node(const Object *node) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorScript", "add_root_node");
	}
	___godot_icall_void_Object(mb, (const Object *) this, node);
}

Node *EditorScript::get_scene() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorScript", "get_scene");
	}
	return (Node *) ___godot_icall_Object(mb, (const Object *) this);
}

EditorInterface *EditorScript::get_editor_interface() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorScript", "get_editor_interface");
	}
	return (EditorInterface *) ___godot_icall_Object(mb, (const Object *) this);
}

}