#include <EditorPlugin.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <InputEvent.hpp>
#include <Control.hpp>
#include <Camera.hpp>
#include <EditorSpatialGizmo.hpp>
#include <Spatial.hpp>
#include <Object.hpp>
#include <ConfigFile.hpp>
#include <ToolButton.hpp>
#include <Script.hpp>
#include <Texture.hpp>
#include <UndoRedo.hpp>
#include <EditorImportPlugin.hpp>
#include <EditorSceneImporter.hpp>
#include <EditorExportPlugin.hpp>
#include <EditorInterface.hpp>


namespace godot {


void *EditorPlugin::___get_type_tag()
{
	return (void *) &EditorPlugin::___get_type_tag;
}

void *EditorPlugin::___get_base_type_tag()
{
	return (void *) &Node::___get_type_tag;
}

EditorPlugin *EditorPlugin::_new()
{
	return (EditorPlugin *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"EditorPlugin")());
}
bool EditorPlugin::forward_canvas_gui_input(const Ref<InputEvent> event) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "forward_canvas_gui_input");
	}
	return ___godot_icall_bool_Object(mb, (const Object *) this, event.ptr());
}

void EditorPlugin::forward_draw_over_viewport(const Control *overlay) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "forward_draw_over_viewport");
	}
	___godot_icall_void_Object(mb, (const Object *) this, overlay);
}

void EditorPlugin::forward_force_draw_over_viewport(const Control *overlay) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "forward_force_draw_over_viewport");
	}
	___godot_icall_void_Object(mb, (const Object *) this, overlay);
}

bool EditorPlugin::forward_spatial_gui_input(const Camera *camera, const Ref<InputEvent> event) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "forward_spatial_gui_input");
	}
	return ___godot_icall_bool_Object_Object(mb, (const Object *) this, camera, event.ptr());
}

Ref<EditorSpatialGizmo> EditorPlugin::create_spatial_gizmo(const Spatial *for_spatial) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "create_spatial_gizmo");
	}
	return Ref<EditorSpatialGizmo>::__internal_constructor(___godot_icall_Object_Object(mb, (const Object *) this, for_spatial));
}

String EditorPlugin::get_plugin_name() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "get_plugin_name");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

Object *EditorPlugin::get_plugin_icon() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "get_plugin_icon");
	}
	return (Object *) ___godot_icall_Object(mb, (const Object *) this);
}

bool EditorPlugin::has_main_screen() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "has_main_screen");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void EditorPlugin::make_visible(const bool visible) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "make_visible");
	}
	___godot_icall_void_bool(mb, (const Object *) this, visible);
}

void EditorPlugin::edit(const Object *object) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "edit");
	}
	___godot_icall_void_Object(mb, (const Object *) this, object);
}

bool EditorPlugin::handles(const Object *object) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "handles");
	}
	return ___godot_icall_bool_Object(mb, (const Object *) this, object);
}

Dictionary EditorPlugin::get_state() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "get_state");
	}
	return ___godot_icall_Dictionary(mb, (const Object *) this);
}

void EditorPlugin::set_state(const Dictionary state) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "set_state");
	}
	___godot_icall_void_Dictionary(mb, (const Object *) this, state);
}

void EditorPlugin::clear() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "clear");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void EditorPlugin::save_external_data() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "save_external_data");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void EditorPlugin::apply_changes() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "apply_changes");
	}
	___godot_icall_void(mb, (const Object *) this);
}

PoolStringArray EditorPlugin::get_breakpoints() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "get_breakpoints");
	}
	return ___godot_icall_PoolStringArray(mb, (const Object *) this);
}

void EditorPlugin::set_window_layout(const Ref<ConfigFile> layout) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "set_window_layout");
	}
	___godot_icall_void_Object(mb, (const Object *) this, layout.ptr());
}

void EditorPlugin::get_window_layout(const Ref<ConfigFile> layout) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "get_window_layout");
	}
	___godot_icall_void_Object(mb, (const Object *) this, layout.ptr());
}

void EditorPlugin::add_control_to_container(const int64_t container, const Object *control) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "add_control_to_container");
	}
	___godot_icall_void_int_Object(mb, (const Object *) this, container, control);
}

ToolButton *EditorPlugin::add_control_to_bottom_panel(const Object *control, const String title) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "add_control_to_bottom_panel");
	}
	return (ToolButton *) ___godot_icall_Object_Object_String(mb, (const Object *) this, control, title);
}

void EditorPlugin::add_control_to_dock(const int64_t slot, const Object *control) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "add_control_to_dock");
	}
	___godot_icall_void_int_Object(mb, (const Object *) this, slot, control);
}

void EditorPlugin::remove_control_from_docks(const Object *control) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "remove_control_from_docks");
	}
	___godot_icall_void_Object(mb, (const Object *) this, control);
}

void EditorPlugin::remove_control_from_bottom_panel(const Object *control) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "remove_control_from_bottom_panel");
	}
	___godot_icall_void_Object(mb, (const Object *) this, control);
}

void EditorPlugin::remove_control_from_container(const int64_t container, const Object *control) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "remove_control_from_container");
	}
	___godot_icall_void_int_Object(mb, (const Object *) this, container, control);
}

void EditorPlugin::add_tool_menu_item(const String name, const Object *handler, const String callback, const Variant ud) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "add_tool_menu_item");
	}
	___godot_icall_void_String_Object_String_Variant(mb, (const Object *) this, name, handler, callback, ud);
}

void EditorPlugin::add_tool_submenu_item(const String name, const Object *submenu) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "add_tool_submenu_item");
	}
	___godot_icall_void_String_Object(mb, (const Object *) this, name, submenu);
}

void EditorPlugin::remove_tool_menu_item(const String name) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "remove_tool_menu_item");
	}
	___godot_icall_void_String(mb, (const Object *) this, name);
}

void EditorPlugin::add_custom_type(const String type, const String base, const Ref<Script> script, const Ref<Texture> icon) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "add_custom_type");
	}
	___godot_icall_void_String_String_Object_Object(mb, (const Object *) this, type, base, script.ptr(), icon.ptr());
}

void EditorPlugin::remove_custom_type(const String type) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "remove_custom_type");
	}
	___godot_icall_void_String(mb, (const Object *) this, type);
}

void EditorPlugin::add_autoload_singleton(const String name, const String path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "add_autoload_singleton");
	}
	___godot_icall_void_String_String(mb, (const Object *) this, name, path);
}

void EditorPlugin::remove_autoload_singleton(const String name) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "remove_autoload_singleton");
	}
	___godot_icall_void_String(mb, (const Object *) this, name);
}

int64_t EditorPlugin::update_overlays() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "update_overlays");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void EditorPlugin::make_bottom_panel_item_visible(const Object *item) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "make_bottom_panel_item_visible");
	}
	___godot_icall_void_Object(mb, (const Object *) this, item);
}

void EditorPlugin::hide_bottom_panel() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "hide_bottom_panel");
	}
	___godot_icall_void(mb, (const Object *) this);
}

UndoRedo *EditorPlugin::get_undo_redo() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "get_undo_redo");
	}
	return (UndoRedo *) ___godot_icall_Object(mb, (const Object *) this);
}

void EditorPlugin::queue_save_layout() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "queue_save_layout");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void EditorPlugin::add_import_plugin(const Ref<EditorImportPlugin> importer) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "add_import_plugin");
	}
	___godot_icall_void_Object(mb, (const Object *) this, importer.ptr());
}

void EditorPlugin::remove_import_plugin(const Ref<EditorImportPlugin> importer) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "remove_import_plugin");
	}
	___godot_icall_void_Object(mb, (const Object *) this, importer.ptr());
}

void EditorPlugin::add_scene_import_plugin(const Ref<EditorSceneImporter> scene_importer) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "add_scene_import_plugin");
	}
	___godot_icall_void_Object(mb, (const Object *) this, scene_importer.ptr());
}

void EditorPlugin::remove_scene_import_plugin(const Ref<EditorSceneImporter> scene_importer) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "remove_scene_import_plugin");
	}
	___godot_icall_void_Object(mb, (const Object *) this, scene_importer.ptr());
}

void EditorPlugin::add_export_plugin(const Ref<EditorExportPlugin> exporter) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "add_export_plugin");
	}
	___godot_icall_void_Object(mb, (const Object *) this, exporter.ptr());
}

void EditorPlugin::remove_export_plugin(const Ref<EditorExportPlugin> exporter) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "remove_export_plugin");
	}
	___godot_icall_void_Object(mb, (const Object *) this, exporter.ptr());
}

void EditorPlugin::set_input_event_forwarding_always_enabled() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "set_input_event_forwarding_always_enabled");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void EditorPlugin::set_force_draw_over_forwarding_enabled() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "set_force_draw_over_forwarding_enabled");
	}
	___godot_icall_void(mb, (const Object *) this);
}

EditorInterface *EditorPlugin::get_editor_interface() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorPlugin", "get_editor_interface");
	}
	return (EditorInterface *) ___godot_icall_Object(mb, (const Object *) this);
}

}