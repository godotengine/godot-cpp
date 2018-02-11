#include <ScriptEditor.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Object.hpp>
#include <Resource.hpp>
#include <Reference.hpp>
#include <Script.hpp>
#include <InputEvent.hpp>


namespace godot {


void *ScriptEditor::___get_type_tag()
{
	return (void *) &ScriptEditor::___get_type_tag;
}

void *ScriptEditor::___get_base_type_tag()
{
	return (void *) &PanelContainer::___get_type_tag;
}

void ScriptEditor::_file_dialog_action(const String arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "_file_dialog_action");
	}
	___godot_icall_void_String(mb, (const Object *) this, arg0);
}

void ScriptEditor::_tab_changed(const int64_t arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "_tab_changed");
	}
	___godot_icall_void_int(mb, (const Object *) this, arg0);
}

void ScriptEditor::_menu_option(const int64_t arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "_menu_option");
	}
	___godot_icall_void_int(mb, (const Object *) this, arg0);
}

void ScriptEditor::_close_current_tab() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "_close_current_tab");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void ScriptEditor::_close_discard_current_tab(const String arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "_close_discard_current_tab");
	}
	___godot_icall_void_String(mb, (const Object *) this, arg0);
}

void ScriptEditor::_close_docs_tab() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "_close_docs_tab");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void ScriptEditor::_close_all_tabs() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "_close_all_tabs");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void ScriptEditor::_close_other_tabs() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "_close_other_tabs");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void ScriptEditor::_open_recent_script(const int64_t arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "_open_recent_script");
	}
	___godot_icall_void_int(mb, (const Object *) this, arg0);
}

void ScriptEditor::_editor_play() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "_editor_play");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void ScriptEditor::_editor_pause() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "_editor_pause");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void ScriptEditor::_editor_stop() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "_editor_stop");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void ScriptEditor::_add_callback(const Object *arg0, const String arg1, const PoolStringArray arg2) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "_add_callback");
	}
	___godot_icall_void_Object_String_PoolStringArray(mb, (const Object *) this, arg0, arg1, arg2);
}

void ScriptEditor::_reload_scripts() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "_reload_scripts");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void ScriptEditor::_resave_scripts(const String arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "_resave_scripts");
	}
	___godot_icall_void_String(mb, (const Object *) this, arg0);
}

void ScriptEditor::_res_saved_callback(const Ref<Resource> arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "_res_saved_callback");
	}
	___godot_icall_void_Object(mb, (const Object *) this, arg0.ptr());
}

void ScriptEditor::_goto_script_line(const Reference *arg0, const int64_t arg1) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "_goto_script_line");
	}
	___godot_icall_void_Object_int(mb, (const Object *) this, arg0, arg1);
}

void ScriptEditor::_goto_script_line2(const int64_t arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "_goto_script_line2");
	}
	___godot_icall_void_int(mb, (const Object *) this, arg0);
}

void ScriptEditor::_help_search(const String arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "_help_search");
	}
	___godot_icall_void_String(mb, (const Object *) this, arg0);
}

void ScriptEditor::_help_index(const String arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "_help_index");
	}
	___godot_icall_void_String(mb, (const Object *) this, arg0);
}

void ScriptEditor::_save_history() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "_save_history");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void ScriptEditor::_copy_script_path() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "_copy_script_path");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void ScriptEditor::_breaked(const bool arg0, const bool arg1) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "_breaked");
	}
	___godot_icall_void_bool_bool(mb, (const Object *) this, arg0, arg1);
}

void ScriptEditor::_show_debugger(const bool arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "_show_debugger");
	}
	___godot_icall_void_bool(mb, (const Object *) this, arg0);
}

String ScriptEditor::_get_debug_tooltip(const String arg0, const Object *arg1) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "_get_debug_tooltip");
	}
	return ___godot_icall_String_String_Object(mb, (const Object *) this, arg0, arg1);
}

void ScriptEditor::_autosave_scripts() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "_autosave_scripts");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void ScriptEditor::_editor_settings_changed() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "_editor_settings_changed");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void ScriptEditor::_update_script_names() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "_update_script_names");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void ScriptEditor::_tree_changed() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "_tree_changed");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void ScriptEditor::_members_overview_selected(const int64_t arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "_members_overview_selected");
	}
	___godot_icall_void_int(mb, (const Object *) this, arg0);
}

void ScriptEditor::_help_overview_selected(const int64_t arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "_help_overview_selected");
	}
	___godot_icall_void_int(mb, (const Object *) this, arg0);
}

void ScriptEditor::_script_selected(const int64_t arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "_script_selected");
	}
	___godot_icall_void_int(mb, (const Object *) this, arg0);
}

void ScriptEditor::_script_created(const Ref<Script> arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "_script_created");
	}
	___godot_icall_void_Object(mb, (const Object *) this, arg0.ptr());
}

void ScriptEditor::_script_split_dragged(const double arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "_script_split_dragged");
	}
	___godot_icall_void_float(mb, (const Object *) this, arg0);
}

void ScriptEditor::_help_class_open(const String arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "_help_class_open");
	}
	___godot_icall_void_String(mb, (const Object *) this, arg0);
}

void ScriptEditor::_help_class_goto(const String arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "_help_class_goto");
	}
	___godot_icall_void_String(mb, (const Object *) this, arg0);
}

void ScriptEditor::_request_help(const String arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "_request_help");
	}
	___godot_icall_void_String(mb, (const Object *) this, arg0);
}

void ScriptEditor::_history_forward() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "_history_forward");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void ScriptEditor::_history_back() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "_history_back");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void ScriptEditor::_live_auto_reload_running_scripts() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "_live_auto_reload_running_scripts");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void ScriptEditor::_unhandled_input(const Ref<InputEvent> arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "_unhandled_input");
	}
	___godot_icall_void_Object(mb, (const Object *) this, arg0.ptr());
}

void ScriptEditor::_script_list_gui_input(const Ref<InputEvent> arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "_script_list_gui_input");
	}
	___godot_icall_void_Object(mb, (const Object *) this, arg0.ptr());
}

void ScriptEditor::_script_changed() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "_script_changed");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void ScriptEditor::_update_recent_scripts() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "_update_recent_scripts");
	}
	___godot_icall_void(mb, (const Object *) this);
}

Variant ScriptEditor::get_drag_data_fw(const Vector2 point, const Object *from) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "get_drag_data_fw");
	}
	return ___godot_icall_Variant_Vector2_Object(mb, (const Object *) this, point, from);
}

bool ScriptEditor::can_drop_data_fw(const Vector2 point, const Variant data, const Object *from) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "can_drop_data_fw");
	}
	return ___godot_icall_bool_Vector2_Variant_Object(mb, (const Object *) this, point, data, from);
}

void ScriptEditor::drop_data_fw(const Vector2 point, const Variant data, const Object *from) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "drop_data_fw");
	}
	___godot_icall_void_Vector2_Variant_Object(mb, (const Object *) this, point, data, from);
}

Ref<Script> ScriptEditor::get_current_script() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "get_current_script");
	}
	return Ref<Script>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

Array ScriptEditor::get_open_scripts() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "get_open_scripts");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

void ScriptEditor::open_script_create_dialog(const String base_name, const String base_path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScriptEditor", "open_script_create_dialog");
	}
	___godot_icall_void_String_String(mb, (const Object *) this, base_name, base_path);
}

}