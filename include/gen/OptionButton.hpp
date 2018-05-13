#ifndef GODOT_CPP_OPTIONBUTTON_HPP
#define GODOT_CPP_OPTIONBUTTON_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Button.hpp"
namespace godot {

class Texture;
class PopupMenu;

class OptionButton : public Button {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "OptionButton"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static OptionButton *_new();

	// methods
	void _selected(const int64_t arg0);
	void _focused(const int64_t arg0);
	void add_item(const String label, const int64_t id = -1);
	void add_icon_item(const Ref<Texture> texture, const String label, const int64_t id = -1);
	void set_item_text(const int64_t idx, const String text);
	void set_item_icon(const int64_t idx, const Ref<Texture> texture);
	void set_item_disabled(const int64_t idx, const bool disabled);
	void set_item_id(const int64_t idx, const int64_t id);
	void set_item_metadata(const int64_t idx, const Variant metadata);
	String get_item_text(const int64_t idx) const;
	Ref<Texture> get_item_icon(const int64_t idx) const;
	int64_t get_item_id(const int64_t idx) const;
	Variant get_item_metadata(const int64_t idx) const;
	bool is_item_disabled(const int64_t idx) const;
	int64_t get_item_count() const;
	void add_separator();
	void clear();
	void select(const int64_t idx);
	int64_t get_selected() const;
	int64_t get_selected_id() const;
	Variant get_selected_metadata() const;
	void remove_item(const int64_t idx);
	void _select_int(const int64_t arg0);
	PopupMenu *get_popup() const;
	void _set_items(const Array arg0);
	Array _get_items() const;

};

}

#endif