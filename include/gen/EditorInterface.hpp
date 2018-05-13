#ifndef GODOT_CPP_EDITORINTERFACE_HPP
#define GODOT_CPP_EDITORINTERFACE_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Node.hpp"
namespace godot {

class Object;
class EditorSelection;
class EditorSettings;
class ScriptEditor;
class Control;
class Resource;
class Node;
class EditorResourcePreview;
class EditorFileSystem;

class EditorInterface : public Node {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "EditorInterface"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants

	// methods
	void inspect_object(const Object *object, const String for_property = "");
	EditorSelection *get_selection();
	Ref<EditorSettings> get_editor_settings();
	ScriptEditor *get_script_editor();
	Control *get_base_control();
	void edit_resource(const Ref<Resource> resource);
	void open_scene_from_path(const String scene_filepath);
	void reload_scene_from_path(const String scene_filepath);
	Array get_open_scenes() const;
	Node *get_edited_scene_root();
	EditorResourcePreview *get_resource_previewer();
	EditorFileSystem *get_resource_filesystem();
	Control *get_editor_viewport();
	Array make_mesh_previews(const Array meshes, const int64_t preview_size);
	void select_file(const String p_file);
	String get_selected_path() const;
	void set_plugin_enabled(const String plugin, const bool enabled);
	bool is_plugin_enabled(const String plugin) const;
	Error save_scene();
	void save_scene_as(const String path, const bool with_preview = true);

};

}

#endif