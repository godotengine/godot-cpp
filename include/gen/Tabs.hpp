#ifndef GODOT_CPP_TABS_HPP
#define GODOT_CPP_TABS_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include "Tabs.hpp"

#include "Control.hpp"
namespace godot {

class InputEvent;
class Texture;

class Tabs : public Control {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Tabs"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum CloseButtonDisplayPolicy {
		CLOSE_BUTTON_MAX = 3,
		CLOSE_BUTTON_SHOW_ACTIVE_ONLY = 1,
		CLOSE_BUTTON_SHOW_ALWAYS = 2,
		CLOSE_BUTTON_SHOW_NEVER = 0,
	};
	enum TabAlign {
		ALIGN_MAX = 3,
		ALIGN_LEFT = 0,
		ALIGN_CENTER = 1,
		ALIGN_RIGHT = 2,
	};

	// constants


	static Tabs *_new();

	// methods
	void _gui_input(const Ref<InputEvent> arg0);
	int64_t get_tab_count() const;
	void set_current_tab(const int64_t tab_idx);
	int64_t get_current_tab() const;
	void set_tab_title(const int64_t tab_idx, const String title);
	String get_tab_title(const int64_t tab_idx) const;
	void set_tab_icon(const int64_t tab_idx, const Ref<Texture> icon);
	Ref<Texture> get_tab_icon(const int64_t tab_idx) const;
	void set_tab_disabled(const int64_t tab_idx, const bool disabled);
	bool get_tab_disabled(const int64_t tab_idx) const;
	void remove_tab(const int64_t tab_idx);
	void add_tab(const String title = "", const Ref<Texture> icon = nullptr);
	void set_tab_align(const int64_t align);
	Tabs::TabAlign get_tab_align() const;
	int64_t get_tab_offset() const;
	bool get_offset_buttons_visible() const;
	void ensure_tab_visible(const int64_t idx);
	Rect2 get_tab_rect(const int64_t tab_idx) const;
	void move_tab(const int64_t from, const int64_t to);
	void set_tab_close_display_policy(const int64_t policy);
	Tabs::CloseButtonDisplayPolicy get_tab_close_display_policy() const;
	void set_scrolling_enabled(const bool enabled);
	bool get_scrolling_enabled() const;
	void set_drag_to_rearrange_enabled(const bool enabled);
	bool get_drag_to_rearrange_enabled() const;
	void set_tabs_rearrange_group(const int64_t group_id);
	int64_t get_tabs_rearrange_group() const;

};

}

#endif