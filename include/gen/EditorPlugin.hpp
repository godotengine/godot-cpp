#ifndef GODOT_CPP_EDITORPLUGIN_HPP
#define GODOT_CPP_EDITORPLUGIN_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Node.hpp"
namespace godot {

class InputEvent;
class Control;
class Camera;
class EditorSpatialGizmo;
class Spatial;
class Object;
class ConfigFile;
class ToolButton;
class Script;
class Texture;
class UndoRedo;
class EditorImportPlugin;
class EditorSceneImporter;
class EditorExportPlugin;
class EditorInterface;

class EditorPlugin : public Node {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "EditorPlugin"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum DockSlot {
		DOCK_SLOT_MAX = 8,
		DOCK_SLOT_LEFT_BL = 1,
		DOCK_SLOT_RIGHT_BR = 7,
		DOCK_SLOT_RIGHT_UR = 6,
		DOCK_SLOT_LEFT_UR = 2,
		DOCK_SLOT_LEFT_UL = 0,
		DOCK_SLOT_RIGHT_UL = 4,
		DOCK_SLOT_RIGHT_BL = 5,
		DOCK_SLOT_LEFT_BR = 3,
	};
	enum CustomControlContainer {
		CONTAINER_TOOLBAR = 0,
		CONTAINER_SPATIAL_EDITOR_BOTTOM = 3,
		CONTAINER_CANVAS_EDITOR_SIDE = 5,
		CONTAINER_SPATIAL_EDITOR_SIDE = 2,
		CONTAINER_SPATIAL_EDITOR_MENU = 1,
		CONTAINER_CANVAS_EDITOR_BOTTOM = 6,
		CONTAINER_PROPERTY_EDITOR_BOTTOM = 7,
		CONTAINER_CANVAS_EDITOR_MENU = 4,
	};

	// constants


	static EditorPlugin *_new();

	// methods
	bool forward_canvas_gui_input(const Ref<InputEvent> event);
	void forward_draw_over_viewport(const Control *overlay);
	void forward_force_draw_over_viewport(const Control *overlay);
	bool forward_spatial_gui_input(const Camera *camera, const Ref<InputEvent> event);
	Ref<EditorSpatialGizmo> create_spatial_gizmo(const Spatial *for_spatial);
	String get_plugin_name();
	Object *get_plugin_icon();
	bool has_main_screen();
	void make_visible(const bool visible);
	void edit(const Object *object);
	bool handles(const Object *object);
	Dictionary get_state();
	void set_state(const Dictionary state);
	void clear();
	void save_external_data();
	void apply_changes();
	PoolStringArray get_breakpoints();
	void set_window_layout(const Ref<ConfigFile> layout);
	void get_window_layout(const Ref<ConfigFile> layout);
	void add_control_to_container(const int64_t container, const Object *control);
	ToolButton *add_control_to_bottom_panel(const Object *control, const String title);
	void add_control_to_dock(const int64_t slot, const Object *control);
	void remove_control_from_docks(const Object *control);
	void remove_control_from_bottom_panel(const Object *control);
	void remove_control_from_container(const int64_t container, const Object *control);
	void add_tool_menu_item(const String name, const Object *handler, const String callback, const Variant ud = Variant());
	void add_tool_submenu_item(const String name, const Object *submenu);
	void remove_tool_menu_item(const String name);
	void add_custom_type(const String type, const String base, const Ref<Script> script, const Ref<Texture> icon);
	void remove_custom_type(const String type);
	void add_autoload_singleton(const String name, const String path);
	void remove_autoload_singleton(const String name);
	int64_t update_overlays() const;
	void make_bottom_panel_item_visible(const Object *item);
	void hide_bottom_panel();
	UndoRedo *get_undo_redo();
	void queue_save_layout() const;
	void add_import_plugin(const Ref<EditorImportPlugin> importer);
	void remove_import_plugin(const Ref<EditorImportPlugin> importer);
	void add_scene_import_plugin(const Ref<EditorSceneImporter> scene_importer);
	void remove_scene_import_plugin(const Ref<EditorSceneImporter> scene_importer);
	void add_export_plugin(const Ref<EditorExportPlugin> exporter);
	void remove_export_plugin(const Ref<EditorExportPlugin> exporter);
	void set_input_event_forwarding_always_enabled();
	void set_force_draw_over_forwarding_enabled();
	EditorInterface *get_editor_interface();

};

}

#endif