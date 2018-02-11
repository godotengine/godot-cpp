#ifndef GODOT_CPP_EDITORFILEDIALOG_HPP
#define GODOT_CPP_EDITORFILEDIALOG_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <EditorFileDialog.hpp>

#include <ConfirmationDialog.hpp>
namespace godot {

class InputEvent;
class VBoxContainer;
class Texture;

class EditorFileDialog : public ConfirmationDialog {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "EditorFileDialog"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum DisplayMode {
		DISPLAY_THUMBNAILS = 0,
		DISPLAY_LIST = 1,
	};
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


	static EditorFileDialog *_new();

	// methods
	void _unhandled_input(const Ref<InputEvent> arg0);
	void _item_selected(const int64_t arg0);
	void _multi_selected(const int64_t arg0, const bool arg1);
	void _items_clear_selection();
	void _item_list_item_rmb_selected(const int64_t arg0, const Vector2 arg1);
	void _item_list_rmb_clicked(const Vector2 arg0);
	void _item_menu_id_pressed(const int64_t arg0);
	void _item_db_selected(const int64_t arg0);
	void _dir_entered(const String arg0);
	void _file_entered(const String arg0);
	void _action_pressed();
	void _cancel_pressed();
	void _filter_selected(const int64_t arg0);
	void _save_confirm_pressed();
	void clear_filters();
	void add_filter(const String filter);
	String get_current_dir() const;
	String get_current_file() const;
	String get_current_path() const;
	void set_current_dir(const String dir);
	void set_current_file(const String file);
	void set_current_path(const String path);
	void set_mode(const int64_t mode);
	EditorFileDialog::Mode get_mode() const;
	VBoxContainer *get_vbox();
	void set_access(const int64_t access);
	EditorFileDialog::Access get_access() const;
	void set_show_hidden_files(const bool show);
	bool is_showing_hidden_files() const;
	void _select_drive(const int64_t arg0);
	void _make_dir();
	void _make_dir_confirm();
	void _update_file_list();
	void _update_dir();
	void _thumbnail_done(const String arg0, const Ref<Texture> arg1, const Variant arg2);
	void set_display_mode(const int64_t mode);
	EditorFileDialog::DisplayMode get_display_mode() const;
	void _thumbnail_result(const String arg0, const Ref<Texture> arg1, const Variant arg2);
	void set_disable_overwrite_warning(const bool disable);
	bool is_overwrite_warning_disabled() const;
	void _recent_selected(const int64_t arg0);
	void _go_back();
	void _go_forward();
	void _go_up();
	void _favorite_toggled(const bool arg0);
	void _favorite_selected(const int64_t arg0);
	void _favorite_move_up();
	void _favorite_move_down();
	void invalidate();

};

}

#endif