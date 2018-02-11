#include <PackedScene.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Object.hpp>
#include <Node.hpp>
#include <SceneState.hpp>


namespace godot {


void *PackedScene::___get_type_tag()
{
	return (void *) &PackedScene::___get_type_tag;
}

void *PackedScene::___get_base_type_tag()
{
	return (void *) &Resource::___get_type_tag;
}

PackedScene *PackedScene::_new()
{
	return (PackedScene *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"PackedScene")());
}
Error PackedScene::pack(const Object *path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PackedScene", "pack");
	}
	return (Error) ___godot_icall_int_Object(mb, (const Object *) this, path);
}

Node *PackedScene::instance(const int64_t edit_state) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PackedScene", "instance");
	}
	return (Node *) ___godot_icall_Object_int(mb, (const Object *) this, edit_state);
}

bool PackedScene::can_instance() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PackedScene", "can_instance");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void PackedScene::_set_bundled_scene(const Dictionary arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PackedScene", "_set_bundled_scene");
	}
	___godot_icall_void_Dictionary(mb, (const Object *) this, arg0);
}

Dictionary PackedScene::_get_bundled_scene() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PackedScene", "_get_bundled_scene");
	}
	return ___godot_icall_Dictionary(mb, (const Object *) this);
}

Ref<SceneState> PackedScene::get_state() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PackedScene", "get_state");
	}
	return Ref<SceneState>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

}