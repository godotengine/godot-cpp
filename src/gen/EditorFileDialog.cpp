#include <EditorFileDialog.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <InputEvent.hpp>
#include <VBoxContainer.hpp>
#include <Texture.hpp>


namespace godot {


void *EditorFileDialog::___get_type_tag()
{
	return (void *) &EditorFileDialog::___get_type_tag;
}

void *EditorFileDialog::___get_base_type_tag()
{
	return (void *) &ConfirmationDialog::___get_type_tag;
}

EditorFileDialog *EditorFileDialog::_new()
{
	return (EditorFileDialog *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"EditorFileDialog")());
}
void EditorFileDialog::_unhandled_input(const Ref<InputEvent> arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "_unhandled_input");
	}
	___godot_icall_void_Object(mb, (const Object *) this, arg0.ptr());
}

void EditorFileDialog::_item_selected(const int64_t arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "_item_selected");
	}
	___godot_icall_void_int(mb, (const Object *) this, arg0);
}

void EditorFileDialog::_multi_selected(const int64_t arg0, const bool arg1) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "_multi_selected");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, arg0, arg1);
}

void EditorFileDialog::_items_clear_selection() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "_items_clear_selection");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void EditorFileDialog::_item_list_item_rmb_selected(const int64_t arg0, const Vector2 arg1) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "_item_list_item_rmb_selected");
	}
	___godot_icall_void_int_Vector2(mb, (const Object *) this, arg0, arg1);
}

void EditorFileDialog::_item_list_rmb_clicked(const Vector2 arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "_item_list_rmb_clicked");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, arg0);
}

void EditorFileDialog::_item_menu_id_pressed(const int64_t arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "_item_menu_id_pressed");
	}
	___godot_icall_void_int(mb, (const Object *) this, arg0);
}

void EditorFileDialog::_item_db_selected(const int64_t arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "_item_db_selected");
	}
	___godot_icall_void_int(mb, (const Object *) this, arg0);
}

void EditorFileDialog::_dir_entered(const String arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "_dir_entered");
	}
	___godot_icall_void_String(mb, (const Object *) this, arg0);
}

void EditorFileDialog::_file_entered(const String arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "_file_entered");
	}
	___godot_icall_void_String(mb, (const Object *) this, arg0);
}

void EditorFileDialog::_action_pressed() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "_action_pressed");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void EditorFileDialog::_cancel_pressed() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "_cancel_pressed");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void EditorFileDialog::_filter_selected(const int64_t arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "_filter_selected");
	}
	___godot_icall_void_int(mb, (const Object *) this, arg0);
}

void EditorFileDialog::_save_confirm_pressed() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "_save_confirm_pressed");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void EditorFileDialog::clear_filters() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "clear_filters");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void EditorFileDialog::add_filter(const String filter) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "add_filter");
	}
	___godot_icall_void_String(mb, (const Object *) this, filter);
}

String EditorFileDialog::get_current_dir() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "get_current_dir");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

String EditorFileDialog::get_current_file() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "get_current_file");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

String EditorFileDialog::get_current_path() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "get_current_path");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void EditorFileDialog::set_current_dir(const String dir) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "set_current_dir");
	}
	___godot_icall_void_String(mb, (const Object *) this, dir);
}

void EditorFileDialog::set_current_file(const String file) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "set_current_file");
	}
	___godot_icall_void_String(mb, (const Object *) this, file);
}

void EditorFileDialog::set_current_path(const String path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "set_current_path");
	}
	___godot_icall_void_String(mb, (const Object *) this, path);
}

void EditorFileDialog::set_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "set_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

EditorFileDialog::Mode EditorFileDialog::get_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "get_mode");
	}
	return (EditorFileDialog::Mode) ___godot_icall_int(mb, (const Object *) this);
}

VBoxContainer *EditorFileDialog::get_vbox() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "get_vbox");
	}
	return (VBoxContainer *) ___godot_icall_Object(mb, (const Object *) this);
}

void EditorFileDialog::set_access(const int64_t access) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "set_access");
	}
	___godot_icall_void_int(mb, (const Object *) this, access);
}

EditorFileDialog::Access EditorFileDialog::get_access() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "get_access");
	}
	return (EditorFileDialog::Access) ___godot_icall_int(mb, (const Object *) this);
}

void EditorFileDialog::set_show_hidden_files(const bool show) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "set_show_hidden_files");
	}
	___godot_icall_void_bool(mb, (const Object *) this, show);
}

bool EditorFileDialog::is_showing_hidden_files() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "is_showing_hidden_files");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void EditorFileDialog::_select_drive(const int64_t arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "_select_drive");
	}
	___godot_icall_void_int(mb, (const Object *) this, arg0);
}

void EditorFileDialog::_make_dir() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "_make_dir");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void EditorFileDialog::_make_dir_confirm() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "_make_dir_confirm");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void EditorFileDialog::_update_file_list() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "_update_file_list");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void EditorFileDialog::_update_dir() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "_update_dir");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void EditorFileDialog::_thumbnail_done(const String arg0, const Ref<Texture> arg1, const Variant arg2) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "_thumbnail_done");
	}
	___godot_icall_void_String_Object_Variant(mb, (const Object *) this, arg0, arg1.ptr(), arg2);
}

void EditorFileDialog::set_display_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "set_display_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

EditorFileDialog::DisplayMode EditorFileDialog::get_display_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "get_display_mode");
	}
	return (EditorFileDialog::DisplayMode) ___godot_icall_int(mb, (const Object *) this);
}

void EditorFileDialog::_thumbnail_result(const String arg0, const Ref<Texture> arg1, const Variant arg2) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "_thumbnail_result");
	}
	___godot_icall_void_String_Object_Variant(mb, (const Object *) this, arg0, arg1.ptr(), arg2);
}

void EditorFileDialog::set_disable_overwrite_warning(const bool disable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "set_disable_overwrite_warning");
	}
	___godot_icall_void_bool(mb, (const Object *) this, disable);
}

bool EditorFileDialog::is_overwrite_warning_disabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "is_overwrite_warning_disabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void EditorFileDialog::_recent_selected(const int64_t arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "_recent_selected");
	}
	___godot_icall_void_int(mb, (const Object *) this, arg0);
}

void EditorFileDialog::_go_back() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "_go_back");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void EditorFileDialog::_go_forward() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "_go_forward");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void EditorFileDialog::_go_up() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "_go_up");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void EditorFileDialog::_favorite_toggled(const bool arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "_favorite_toggled");
	}
	___godot_icall_void_bool(mb, (const Object *) this, arg0);
}

void EditorFileDialog::_favorite_selected(const int64_t arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "_favorite_selected");
	}
	___godot_icall_void_int(mb, (const Object *) this, arg0);
}

void EditorFileDialog::_favorite_move_up() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "_favorite_move_up");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void EditorFileDialog::_favorite_move_down() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "_favorite_move_down");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void EditorFileDialog::invalidate() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EditorFileDialog", "invalidate");
	}
	___godot_icall_void(mb, (const Object *) this);
}

}