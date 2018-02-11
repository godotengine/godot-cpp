#include <EditorInterface.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Object.hpp>
#include <EditorSelection.hpp>
#include <EditorSettings.hpp>
#include <ScriptEditor.hpp>
#include <Control.hpp>
#include <Resource.hpp>
#include <Node.hpp>
#include <EditorResourcePreview.hpp>
#include <EditorFileSystem.hpp>


namespace godot {


void *EditorInterface::___get_type_tag()
{
	return (void *) &EditorInterface::___get_type_tag;
}

void *EditorInterface::___get_base_type_tag()
{
	return (void *) &Node::___get_type_tag;
}

void EditorInterface::inspect_object(const Object *object, const String for_property) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorInterface", "inspect_object");
	}
	___godot_icall_void_Object_String(mb, (const Object *) this, object, for_property);
}

EditorSelection *EditorInterface::get_selection() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorInterface", "get_selection");
	}
	return (EditorSelection *) ___godot_icall_Object(mb, (const Object *) this);
}

Ref<EditorSettings> EditorInterface::get_editor_settings() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorInterface", "get_editor_settings");
	}
	return Ref<EditorSettings>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

ScriptEditor *EditorInterface::get_script_editor() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorInterface", "get_script_editor");
	}
	return (ScriptEditor *) ___godot_icall_Object(mb, (const Object *) this);
}

Control *EditorInterface::get_base_control() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorInterface", "get_base_control");
	}
	return (Control *) ___godot_icall_Object(mb, (const Object *) this);
}

void EditorInterface::edit_resource(const Ref<Resource> resource) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorInterface", "edit_resource");
	}
	___godot_icall_void_Object(mb, (const Object *) this, resource.ptr());
}

void EditorInterface::open_scene_from_path(const String scene_filepath) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorInterface", "open_scene_from_path");
	}
	___godot_icall_void_String(mb, (const Object *) this, scene_filepath);
}

void EditorInterface::reload_scene_from_path(const String scene_filepath) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorInterface", "reload_scene_from_path");
	}
	___godot_icall_void_String(mb, (const Object *) this, scene_filepath);
}

Array EditorInterface::get_open_scenes() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorInterface", "get_open_scenes");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

Node *EditorInterface::get_edited_scene_root() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorInterface", "get_edited_scene_root");
	}
	return (Node *) ___godot_icall_Object(mb, (const Object *) this);
}

EditorResourcePreview *EditorInterface::get_resource_previewer() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorInterface", "get_resource_previewer");
	}
	return (EditorResourcePreview *) ___godot_icall_Object(mb, (const Object *) this);
}

EditorFileSystem *EditorInterface::get_resource_filesystem() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorInterface", "get_resource_filesystem");
	}
	return (EditorFileSystem *) ___godot_icall_Object(mb, (const Object *) this);
}

Control *EditorInterface::get_editor_viewport() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorInterface", "get_editor_viewport");
	}
	return (Control *) ___godot_icall_Object(mb, (const Object *) this);
}

Array EditorInterface::make_mesh_previews(const Array meshes, const int64_t preview_size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorInterface", "make_mesh_previews");
	}
	return ___godot_icall_Array_Array_int(mb, (const Object *) this, meshes, preview_size);
}

void EditorInterface::select_file(const String p_file) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorInterface", "select_file");
	}
	___godot_icall_void_String(mb, (const Object *) this, p_file);
}

String EditorInterface::get_selected_path() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorInterface", "get_selected_path");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void EditorInterface::set_plugin_enabled(const String plugin, const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorInterface", "set_plugin_enabled");
	}
	___godot_icall_void_String_bool(mb, (const Object *) this, plugin, enabled);
}

bool EditorInterface::is_plugin_enabled(const String plugin) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorInterface", "is_plugin_enabled");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, plugin);
}

Error EditorInterface::save_scene() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorInterface", "save_scene");
	}
	return (Error) ___godot_icall_int(mb, (const Object *) this);
}

void EditorInterface::save_scene_as(const String path, const bool with_preview) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorInterface", "save_scene_as");
	}
	___godot_icall_void_String_bool(mb, (const Object *) this, path, with_preview);
}

}