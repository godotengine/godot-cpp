#include <EditorSelection.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Object.hpp>


namespace godot {


void *EditorSelection::___get_type_tag()
{
	return (void *) &EditorSelection::___get_type_tag;
}

void *EditorSelection::___get_base_type_tag()
{
	return (void *) &Object::___get_type_tag;
}

EditorSelection *EditorSelection::_new()
{
	return (EditorSelection *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"EditorSelection")());
}
void EditorSelection::_node_removed(const Object *arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorSelection", "_node_removed");
	}
	___godot_icall_void_Object(mb, (const Object *) this, arg0);
}

void EditorSelection::clear() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorSelection", "clear");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void EditorSelection::add_node(const Object *node) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorSelection", "add_node");
	}
	___godot_icall_void_Object(mb, (const Object *) this, node);
}

void EditorSelection::remove_node(const Object *node) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorSelection", "remove_node");
	}
	___godot_icall_void_Object(mb, (const Object *) this, node);
}

Array EditorSelection::get_selected_nodes() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorSelection", "get_selected_nodes");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

Array EditorSelection::get_transformable_selected_nodes() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorSelection", "get_transformable_selected_nodes");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

void EditorSelection::_emit_change() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorSelection", "_emit_change");
	}
	___godot_icall_void(mb, (const Object *) this);
}

}