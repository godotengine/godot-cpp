#ifndef GODOT_CPP_TABCONTAINER_HPP
#define GODOT_CPP_TABCONTAINER_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include "TabContainer.hpp"

#include "Control.hpp"
namespace godot {

class InputEvent;
class Control;
class Texture;
class Object;
class Popup;

class TabContainer : public Control {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "TabContainer"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum TabAlign {
		ALIGN_LEFT = 0,
		ALIGN_CENTER = 1,
		ALIGN_RIGHT = 2,
	};

	// constants


	static TabContainer *_new();

	// methods
	void _gui_input(const Ref<InputEvent> arg0);
	int64_t get_tab_count() const;
	void set_current_tab(const int64_t tab_idx);
	int64_t get_current_tab() const;
	int64_t get_previous_tab() const;
	Control *get_current_tab_control() const;
	Control *get_tab_control(const int64_t idx) const;
	void set_tab_align(const int64_t align);
	TabContainer::TabAlign get_tab_align() const;
	void set_tabs_visible(const bool visible);
	bool are_tabs_visible() const;
	void set_tab_title(const int64_t tab_idx, const String title);
	String get_tab_title(const int64_t tab_idx) const;
	void set_tab_icon(const int64_t tab_idx, const Ref<Texture> icon);
	Ref<Texture> get_tab_icon(const int64_t tab_idx) const;
	void set_tab_disabled(const int64_t tab_idx, const bool disabled);
	bool get_tab_disabled(const int64_t tab_idx) const;
	void set_popup(const Object *popup);
	Popup *get_popup() const;
	void set_drag_to_rearrange_enabled(const bool enabled);
	bool get_drag_to_rearrange_enabled() const;
	void set_tabs_rearrange_group(const int64_t group_id);
	int64_t get_tabs_rearrange_group() const;
	void _child_renamed_callback();
	void _on_theme_changed();
	void _update_current_tab();

};

}

#endif