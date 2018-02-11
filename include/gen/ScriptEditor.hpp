#ifndef GODOT_CPP_SCRIPTEDITOR_HPP
#define GODOT_CPP_SCRIPTEDITOR_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <PanelContainer.hpp>
namespace godot {

class Object;
class Resource;
class Reference;
class Script;
class InputEvent;

class ScriptEditor : public PanelContainer {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "ScriptEditor"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants

	// methods
	void _file_dialog_action(const String arg0);
	void _tab_changed(const int64_t arg0);
	void _menu_option(const int64_t arg0);
	void _close_current_tab();
	void _close_discard_current_tab(const String arg0);
	void _close_docs_tab();
	void _close_all_tabs();
	void _close_other_tabs();
	void _open_recent_script(const int64_t arg0);
	void _editor_play();
	void _editor_pause();
	void _editor_stop();
	void _add_callback(const Object *arg0, const String arg1, const PoolStringArray arg2);
	void _reload_scripts();
	void _resave_scripts(const String arg0);
	void _res_saved_callback(const Ref<Resource> arg0);
	void _goto_script_line(const Reference *arg0, const int64_t arg1);
	void _goto_script_line2(const int64_t arg0);
	void _help_search(const String arg0);
	void _help_index(const String arg0);
	void _save_history();
	void _copy_script_path();
	void _breaked(const bool arg0, const bool arg1);
	void _show_debugger(const bool arg0);
	String _get_debug_tooltip(const String arg0, const Object *arg1);
	void _autosave_scripts();
	void _editor_settings_changed();
	void _update_script_names();
	void _tree_changed();
	void _members_overview_selected(const int64_t arg0);
	void _help_overview_selected(const int64_t arg0);
	void _script_selected(const int64_t arg0);
	void _script_created(const Ref<Script> arg0);
	void _script_split_dragged(const double arg0);
	void _help_class_open(const String arg0);
	void _help_class_goto(const String arg0);
	void _request_help(const String arg0);
	void _history_forward();
	void _history_back();
	void _live_auto_reload_running_scripts();
	void _unhandled_input(const Ref<InputEvent> arg0);
	void _script_list_gui_input(const Ref<InputEvent> arg0);
	void _script_changed();
	void _update_recent_scripts();
	Variant get_drag_data_fw(const Vector2 point, const Object *from);
	bool can_drop_data_fw(const Vector2 point, const Variant data, const Object *from) const;
	void drop_data_fw(const Vector2 point, const Variant data, const Object *from);
	Ref<Script> get_current_script();
	Array get_open_scripts() const;
	void open_script_create_dialog(const String base_name, const String base_path);

};

}

#endif