#include <FileDialog.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <InputEvent.hpp>
#include <VBoxContainer.hpp>


namespace godot {


void *FileDialog::___get_type_tag()
{
	return (void *) &FileDialog::___get_type_tag;
}

void *FileDialog::___get_base_type_tag()
{
	return (void *) &ConfirmationDialog::___get_type_tag;
}

FileDialog *FileDialog::_new()
{
	return (FileDialog *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"FileDialog")());
}
void FileDialog::_unhandled_input(const Ref<InputEvent> arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("FileDialog", "_unhandled_input");
	}
	___godot_icall_void_Object(mb, (const Object *) this, arg0.ptr());
}

void FileDialog::_tree_selected() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("FileDialog", "_tree_selected");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void FileDialog::_tree_item_activated() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("FileDialog", "_tree_item_activated");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void FileDialog::_dir_entered(const String arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("FileDialog", "_dir_entered");
	}
	___godot_icall_void_String(mb, (const Object *) this, arg0);
}

void FileDialog::_file_entered(const String arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("FileDialog", "_file_entered");
	}
	___godot_icall_void_String(mb, (const Object *) this, arg0);
}

void FileDialog::_action_pressed() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("FileDialog", "_action_pressed");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void FileDialog::_cancel_pressed() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("FileDialog", "_cancel_pressed");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void FileDialog::_filter_selected(const int64_t arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("FileDialog", "_filter_selected");
	}
	___godot_icall_void_int(mb, (const Object *) this, arg0);
}

void FileDialog::_save_confirm_pressed() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("FileDialog", "_save_confirm_pressed");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void FileDialog::clear_filters() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("FileDialog", "clear_filters");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void FileDialog::add_filter(const String filter) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("FileDialog", "add_filter");
	}
	___godot_icall_void_String(mb, (const Object *) this, filter);
}

void FileDialog::set_filters(const PoolStringArray filters) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("FileDialog", "set_filters");
	}
	___godot_icall_void_PoolStringArray(mb, (const Object *) this, filters);
}

PoolStringArray FileDialog::get_filters() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("FileDialog", "get_filters");
	}
	return ___godot_icall_PoolStringArray(mb, (const Object *) this);
}

String FileDialog::get_current_dir() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("FileDialog", "get_current_dir");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

String FileDialog::get_current_file() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("FileDialog", "get_current_file");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

String FileDialog::get_current_path() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("FileDialog", "get_current_path");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void FileDialog::set_current_dir(const String dir) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("FileDialog", "set_current_dir");
	}
	___godot_icall_void_String(mb, (const Object *) this, dir);
}

void FileDialog::set_current_file(const String file) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("FileDialog", "set_current_file");
	}
	___godot_icall_void_String(mb, (const Object *) this, file);
}

void FileDialog::set_current_path(const String path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("FileDialog", "set_current_path");
	}
	___godot_icall_void_String(mb, (const Object *) this, path);
}

void FileDialog::set_mode_overrides_title(const bool override) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("FileDialog", "set_mode_overrides_title");
	}
	___godot_icall_void_bool(mb, (const Object *) this, override);
}

bool FileDialog::is_mode_overriding_title() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("FileDialog", "is_mode_overriding_title");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void FileDialog::set_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("FileDialog", "set_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

FileDialog::Mode FileDialog::get_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("FileDialog", "get_mode");
	}
	return (FileDialog::Mode) ___godot_icall_int(mb, (const Object *) this);
}

VBoxContainer *FileDialog::get_vbox() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("FileDialog", "get_vbox");
	}
	return (VBoxContainer *) ___godot_icall_Object(mb, (const Object *) this);
}

void FileDialog::set_access(const int64_t access) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("FileDialog", "set_access");
	}
	___godot_icall_void_int(mb, (const Object *) this, access);
}

FileDialog::Access FileDialog::get_access() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("FileDialog", "get_access");
	}
	return (FileDialog::Access) ___godot_icall_int(mb, (const Object *) this);
}

void FileDialog::set_show_hidden_files(const bool show) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("FileDialog", "set_show_hidden_files");
	}
	___godot_icall_void_bool(mb, (const Object *) this, show);
}

bool FileDialog::is_showing_hidden_files() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("FileDialog", "is_showing_hidden_files");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void FileDialog::_select_drive(const int64_t arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("FileDialog", "_select_drive");
	}
	___godot_icall_void_int(mb, (const Object *) this, arg0);
}

void FileDialog::_make_dir() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("FileDialog", "_make_dir");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void FileDialog::_make_dir_confirm() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("FileDialog", "_make_dir_confirm");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void FileDialog::_update_file_list() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("FileDialog", "_update_file_list");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void FileDialog::_update_dir() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("FileDialog", "_update_dir");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void FileDialog::_go_up() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("FileDialog", "_go_up");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void FileDialog::deselect_items() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("FileDialog", "deselect_items");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void FileDialog::invalidate() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("FileDialog", "invalidate");
	}
	___godot_icall_void(mb, (const Object *) this);
}

}