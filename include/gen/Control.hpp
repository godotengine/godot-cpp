#ifndef GODOT_CPP_CONTROL_HPP
#define GODOT_CPP_CONTROL_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <Control.hpp>

#include <CanvasItem.hpp>
namespace godot {

class InputEvent;
class Object;
class Control;
class Theme;
class Texture;
class Shader;
class StyleBox;
class Font;

class Control : public CanvasItem {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Control"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum Anchor {
		ANCHOR_BEGIN = 0,
		ANCHOR_END = 1,
	};
	enum FocusMode {
		FOCUS_NONE = 0,
		FOCUS_ALL = 2,
		FOCUS_CLICK = 1,
	};
	enum LayoutPresetMode {
		PRESET_MODE_MINSIZE = 0,
		PRESET_MODE_KEEP_WIDTH = 1,
		PRESET_MODE_KEEP_SIZE = 3,
		PRESET_MODE_KEEP_HEIGHT = 2,
	};
	enum MouseFilter {
		MOUSE_FILTER_STOP = 0,
		MOUSE_FILTER_IGNORE = 2,
		MOUSE_FILTER_PASS = 1,
	};
	enum CursorShape {
		CURSOR_ARROW = 0,
		CURSOR_WAIT = 4,
		CURSOR_FORBIDDEN = 8,
		CURSOR_CROSS = 3,
		CURSOR_DRAG = 6,
		CURSOR_FDIAGSIZE = 12,
		CURSOR_HSIZE = 10,
		CURSOR_MOVE = 13,
		CURSOR_IBEAM = 1,
		CURSOR_HSPLIT = 15,
		CURSOR_BUSY = 5,
		CURSOR_HELP = 16,
		CURSOR_POINTING_HAND = 2,
		CURSOR_VSIZE = 9,
		CURSOR_CAN_DROP = 7,
		CURSOR_VSPLIT = 14,
		CURSOR_BDIAGSIZE = 11,
	};
	enum GrowDirection {
		GROW_DIRECTION_END = 1,
		GROW_DIRECTION_BEGIN = 0,
	};
	enum SizeFlags {
		SIZE_EXPAND = 2,
		SIZE_SHRINK_END = 8,
		SIZE_FILL = 1,
		SIZE_SHRINK_CENTER = 4,
		SIZE_EXPAND_FILL = 3,
	};
	enum LayoutPreset {
		PRESET_TOP_LEFT = 0,
		PRESET_CENTER_RIGHT = 6,
		PRESET_BOTTOM_LEFT = 2,
		PRESET_CENTER_TOP = 5,
		PRESET_CENTER_LEFT = 4,
		PRESET_WIDE = 15,
		PRESET_HCENTER_WIDE = 14,
		PRESET_VCENTER_WIDE = 13,
		PRESET_CENTER = 8,
		PRESET_CENTER_BOTTOM = 7,
		PRESET_TOP_RIGHT = 1,
		PRESET_TOP_WIDE = 10,
		PRESET_RIGHT_WIDE = 11,
		PRESET_BOTTOM_RIGHT = 3,
		PRESET_LEFT_WIDE = 9,
		PRESET_BOTTOM_WIDE = 12,
	};

	// constants
	const static int NOTIFICATION_MOUSE_EXIT = 42;
	const static int NOTIFICATION_THEME_CHANGED = 45;
	const static int NOTIFICATION_MOUSE_ENTER = 41;
	const static int NOTIFICATION_FOCUS_ENTER = 43;
	const static int NOTIFICATION_FOCUS_EXIT = 44;
	const static int NOTIFICATION_MODAL_CLOSE = 46;
	const static int NOTIFICATION_RESIZED = 40;


	static Control *_new();

	// methods
	void _gui_input(const Ref<InputEvent> event);
	Vector2 _get_minimum_size();
	Object *get_drag_data(const Vector2 position);
	bool can_drop_data(const Vector2 position, const Variant data);
	void drop_data(const Vector2 position, const Variant data);
	bool has_point(const Vector2 point);
	void _size_changed();
	void _update_minimum_size();
	void accept_event();
	Vector2 get_minimum_size() const;
	Vector2 get_combined_minimum_size() const;
	void set_anchors_preset(const int64_t preset, const bool keep_margin = false);
	void set_margins_preset(const int64_t preset, const int64_t resize_mode = 0, const int64_t margin = 0);
	void set_anchors_and_margins_preset(const int64_t preset, const int64_t resize_mode = 0, const int64_t margin = 0);
	void set_anchor(const int64_t margin, const double anchor, const bool keep_margin = false, const bool push_opposite_anchor = true);
	void _set_anchor(const int64_t margin, const double anchor);
	double get_anchor(const int64_t margin) const;
	void set_margin(const int64_t margin, const double offset);
	void set_anchor_and_margin(const int64_t margin, const double anchor, const double offset, const bool push_opposite_anchor = false);
	void set_begin(const Vector2 position);
	void set_end(const Vector2 position);
	void set_position(const Vector2 position);
	void set_size(const Vector2 size);
	void set_custom_minimum_size(const Vector2 size);
	void set_global_position(const Vector2 position);
	void set_rotation(const double radians);
	void set_rotation_degrees(const double degrees);
	void set_scale(const Vector2 scale);
	void set_pivot_offset(const Vector2 pivot_offset);
	double get_margin(const int64_t margin) const;
	Vector2 get_begin() const;
	Vector2 get_end() const;
	Vector2 get_position() const;
	Vector2 get_size() const;
	double get_rotation() const;
	double get_rotation_degrees() const;
	Vector2 get_scale() const;
	Vector2 get_pivot_offset() const;
	Vector2 get_custom_minimum_size() const;
	Vector2 get_parent_area_size() const;
	Vector2 get_global_position() const;
	Rect2 get_rect() const;
	Rect2 get_global_rect() const;
	void show_modal(const bool exclusive = false);
	void set_focus_mode(const int64_t mode);
	Control::FocusMode get_focus_mode() const;
	bool has_focus() const;
	void grab_focus();
	void release_focus();
	Control *get_focus_owner() const;
	void set_h_size_flags(const int64_t flags);
	int64_t get_h_size_flags() const;
	void set_stretch_ratio(const double ratio);
	double get_stretch_ratio() const;
	void set_v_size_flags(const int64_t flags);
	int64_t get_v_size_flags() const;
	void set_theme(const Ref<Theme> theme);
	Ref<Theme> get_theme() const;
	void add_icon_override(const String name, const Ref<Texture> texture);
	void add_shader_override(const String name, const Ref<Shader> shader);
	void add_stylebox_override(const String name, const Ref<StyleBox> stylebox);
	void add_font_override(const String name, const Ref<Font> font);
	void add_color_override(const String name, const Color color);
	void add_constant_override(const String name, const int64_t constant);
	Ref<Texture> get_icon(const String name, const String type = "") const;
	Ref<StyleBox> get_stylebox(const String name, const String type = "") const;
	Ref<Font> get_font(const String name, const String type = "") const;
	Color get_color(const String name, const String type = "") const;
	int64_t get_constant(const String name, const String type = "") const;
	bool has_icon_override(const String name) const;
	bool has_shader_override(const String name) const;
	bool has_stylebox_override(const String name) const;
	bool has_font_override(const String name) const;
	bool has_color_override(const String name) const;
	bool has_constant_override(const String name) const;
	bool has_icon(const String name, const String type = "") const;
	bool has_stylebox(const String name, const String type = "") const;
	bool has_font(const String name, const String type = "") const;
	bool has_color(const String name, const String type = "") const;
	bool has_constant(const String name, const String type = "") const;
	Control *get_parent_control() const;
	void set_h_grow_direction(const int64_t direction);
	Control::GrowDirection get_h_grow_direction() const;
	void set_v_grow_direction(const int64_t direction);
	Control::GrowDirection get_v_grow_direction() const;
	void set_tooltip(const String tooltip);
	String get_tooltip(const Vector2 at_position = Vector2(0, 0)) const;
	String _get_tooltip() const;
	void set_default_cursor_shape(const int64_t shape);
	Control::CursorShape get_default_cursor_shape() const;
	Control::CursorShape get_cursor_shape(const Vector2 position = Vector2(0, 0)) const;
	void set_focus_neighbour(const int64_t margin, const NodePath neighbour);
	NodePath get_focus_neighbour(const int64_t margin) const;
	void set_focus_next(const NodePath next);
	NodePath get_focus_next() const;
	void set_focus_previous(const NodePath previous);
	NodePath get_focus_previous() const;
	void force_drag(const Variant data, const Object *preview);
	void set_mouse_filter(const int64_t filter);
	Control::MouseFilter get_mouse_filter() const;
	void set_clip_contents(const bool enable);
	bool is_clipping_contents();
	void grab_click_focus();
	void set_drag_forwarding(const Object *target);
	void set_drag_preview(const Object *control);
	void warp_mouse(const Vector2 to_position);
	void minimum_size_changed();
	void _theme_changed();
	void _font_changed();

};

}

#endif