#ifndef GODOT_CPP_POPUPMENU_HPP
#define GODOT_CPP_POPUPMENU_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Popup.hpp>
namespace godot {

class InputEvent;
class Texture;
class ShortCut;

class PopupMenu : public Popup {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "PopupMenu"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static PopupMenu *_new();

	// methods
	void _gui_input(const Ref<InputEvent> arg0);
	void add_icon_item(const Ref<Texture> texture, const String label, const int64_t id = -1, const int64_t accel = 0);
	void add_item(const String label, const int64_t id = -1, const int64_t accel = 0);
	void add_icon_check_item(const Ref<Texture> texture, const String label, const int64_t id = -1, const int64_t accel = 0);
	void add_check_item(const String label, const int64_t id = -1, const int64_t accel = 0);
	void add_submenu_item(const String label, const String submenu, const int64_t id = -1);
	void add_icon_shortcut(const Ref<Texture> texture, const Ref<ShortCut> shortcut, const int64_t id = -1, const bool global = false);
	void add_shortcut(const Ref<ShortCut> shortcut, const int64_t id = -1, const bool global = false);
	void add_icon_check_shortcut(const Ref<Texture> texture, const Ref<ShortCut> shortcut, const int64_t id = -1, const bool global = false);
	void add_check_shortcut(const Ref<ShortCut> shortcut, const int64_t id = -1, const bool global = false);
	void set_item_text(const int64_t idx, const String text);
	void set_item_icon(const int64_t idx, const Ref<Texture> icon);
	void set_item_checked(const int64_t idx, const bool checked);
	void set_item_id(const int64_t idx, const int64_t id);
	void set_item_accelerator(const int64_t idx, const int64_t accel);
	void set_item_metadata(const int64_t idx, const Variant metadata);
	void set_item_disabled(const int64_t idx, const bool disabled);
	void set_item_submenu(const int64_t idx, const String submenu);
	void set_item_as_separator(const int64_t idx, const bool enable);
	void set_item_as_checkable(const int64_t idx, const bool enable);
	void set_item_tooltip(const int64_t idx, const String tooltip);
	void set_item_shortcut(const int64_t idx, const Ref<ShortCut> shortcut, const bool global = false);
	void set_item_multistate(const int64_t idx, const int64_t state);
	void toggle_item_checked(const int64_t idx);
	void toggle_item_multistate(const int64_t idx);
	String get_item_text(const int64_t idx) const;
	Ref<Texture> get_item_icon(const int64_t idx) const;
	bool is_item_checked(const int64_t idx) const;
	int64_t get_item_id(const int64_t idx) const;
	int64_t get_item_index(const int64_t id) const;
	int64_t get_item_accelerator(const int64_t idx) const;
	Variant get_item_metadata(const int64_t idx) const;
	bool is_item_disabled(const int64_t idx) const;
	String get_item_submenu(const int64_t idx) const;
	bool is_item_separator(const int64_t idx) const;
	bool is_item_checkable(const int64_t idx) const;
	String get_item_tooltip(const int64_t idx) const;
	Ref<ShortCut> get_item_shortcut(const int64_t idx) const;
	int64_t get_item_count() const;
	void remove_item(const int64_t idx);
	void add_separator();
	void clear();
	void _set_items(const Array arg0);
	Array _get_items() const;
	void set_hide_on_item_selection(const bool enable);
	bool is_hide_on_item_selection() const;
	void set_hide_on_checkable_item_selection(const bool enable);
	bool is_hide_on_checkable_item_selection() const;
	void set_hide_on_state_item_selection(const bool enable);
	bool is_hide_on_state_item_selection() const;
	void _submenu_timeout();

};

}

#endif