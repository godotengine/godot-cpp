#ifndef GODOT_CPP_FILEDIALOG_HPP
#define GODOT_CPP_FILEDIALOG_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <FileDialog.hpp>

#include <ConfirmationDialog.hpp>
namespace godot {

class InputEvent;
class VBoxContainer;

class FileDialog : public ConfirmationDialog {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "FileDialog"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum Mode {
		MODE_SAVE_FILE = 4,
		MODE_OPEN_FILE = 0,
		MODE_OPEN_FILES = 1,
		MODE_OPEN_ANY = 3,
		MODE_OPEN_DIR = 2,
	};
	enum Access {
		ACCESS_RESOURCES = 0,
		ACCESS_FILESYSTEM = 2,
		ACCESS_USERDATA = 1,
	};

	// constants


	static FileDialog *_new();

	// methods
	void _unhandled_input(const Ref<InputEvent> arg0);
	void _tree_selected();
	void _tree_item_activated();
	void _dir_entered(const String arg0);
	void _file_entered(const String arg0);
	void _action_pressed();
	void _cancel_pressed();
	void _filter_selected(const int64_t arg0);
	void _save_confirm_pressed();
	void clear_filters();
	void add_filter(const String filter);
	void set_filters(const PoolStringArray filters);
	PoolStringArray get_filters() const;
	String get_current_dir() const;
	String get_current_file() const;
	String get_current_path() const;
	void set_current_dir(const String dir);
	void set_current_file(const String file);
	void set_current_path(const String path);
	void set_mode_overrides_title(const bool override);
	bool is_mode_overriding_title() const;
	void set_mode(const int64_t mode);
	FileDialog::Mode get_mode() const;
	VBoxContainer *get_vbox();
	void set_access(const int64_t access);
	FileDialog::Access get_access() const;
	void set_show_hidden_files(const bool show);
	bool is_showing_hidden_files() const;
	void _select_drive(const int64_t arg0);
	void _make_dir();
	void _make_dir_confirm();
	void _update_file_list();
	void _update_dir();
	void _go_up();
	void deselect_items();
	void invalidate();

};

}

#endif