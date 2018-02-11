#include <Control.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <InputEvent.hpp>
#include <Object.hpp>
#include <Control.hpp>
#include <Theme.hpp>
#include <Texture.hpp>
#include <Shader.hpp>
#include <StyleBox.hpp>
#include <Font.hpp>


namespace godot {


void *Control::___get_type_tag()
{
	return (void *) &Control::___get_type_tag;
}

void *Control::___get_base_type_tag()
{
	return (void *) &CanvasItem::___get_type_tag;
}

Control *Control::_new()
{
	return (Control *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Control")());
}
void Control::_gui_input(const Ref<InputEvent> event) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "_gui_input");
	}
	___godot_icall_void_Object(mb, (const Object *) this, event.ptr());
}

Vector2 Control::_get_minimum_size() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "_get_minimum_size");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

Object *Control::get_drag_data(const Vector2 position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "get_drag_data");
	}
	return (Object *) ___godot_icall_Object_Vector2(mb, (const Object *) this, position);
}

bool Control::can_drop_data(const Vector2 position, const Variant data) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "can_drop_data");
	}
	return ___godot_icall_bool_Vector2_Variant(mb, (const Object *) this, position, data);
}

void Control::drop_data(const Vector2 position, const Variant data) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "drop_data");
	}
	___godot_icall_void_Vector2_Variant(mb, (const Object *) this, position, data);
}

bool Control::has_point(const Vector2 point) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "has_point");
	}
	return ___godot_icall_bool_Vector2(mb, (const Object *) this, point);
}

void Control::_size_changed() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "_size_changed");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Control::_update_minimum_size() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "_update_minimum_size");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Control::accept_event() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "accept_event");
	}
	___godot_icall_void(mb, (const Object *) this);
}

Vector2 Control::get_minimum_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "get_minimum_size");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

Vector2 Control::get_combined_minimum_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "get_combined_minimum_size");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void Control::set_anchors_preset(const int64_t preset, const bool keep_margin) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "set_anchors_preset");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, preset, keep_margin);
}

void Control::set_margins_preset(const int64_t preset, const int64_t resize_mode, const int64_t margin) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "set_margins_preset");
	}
	___godot_icall_void_int_int_int(mb, (const Object *) this, preset, resize_mode, margin);
}

void Control::set_anchors_and_margins_preset(const int64_t preset, const int64_t resize_mode, const int64_t margin) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "set_anchors_and_margins_preset");
	}
	___godot_icall_void_int_int_int(mb, (const Object *) this, preset, resize_mode, margin);
}

void Control::set_anchor(const int64_t margin, const double anchor, const bool keep_margin, const bool push_opposite_anchor) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "set_anchor");
	}
	___godot_icall_void_int_float_bool_bool(mb, (const Object *) this, margin, anchor, keep_margin, push_opposite_anchor);
}

void Control::_set_anchor(const int64_t margin, const double anchor) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "_set_anchor");
	}
	___godot_icall_void_int_float(mb, (const Object *) this, margin, anchor);
}

double Control::get_anchor(const int64_t margin) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "get_anchor");
	}
	return ___godot_icall_float_int(mb, (const Object *) this, margin);
}

void Control::set_margin(const int64_t margin, const double offset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "set_margin");
	}
	___godot_icall_void_int_float(mb, (const Object *) this, margin, offset);
}

void Control::set_anchor_and_margin(const int64_t margin, const double anchor, const double offset, const bool push_opposite_anchor) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "set_anchor_and_margin");
	}
	___godot_icall_void_int_float_float_bool(mb, (const Object *) this, margin, anchor, offset, push_opposite_anchor);
}

void Control::set_begin(const Vector2 position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "set_begin");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, position);
}

void Control::set_end(const Vector2 position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "set_end");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, position);
}

void Control::set_position(const Vector2 position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "set_position");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, position);
}

void Control::set_size(const Vector2 size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "set_size");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, size);
}

void Control::set_custom_minimum_size(const Vector2 size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "set_custom_minimum_size");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, size);
}

void Control::set_global_position(const Vector2 position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "set_global_position");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, position);
}

void Control::set_rotation(const double radians) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "set_rotation");
	}
	___godot_icall_void_float(mb, (const Object *) this, radians);
}

void Control::set_rotation_degrees(const double degrees) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "set_rotation_degrees");
	}
	___godot_icall_void_float(mb, (const Object *) this, degrees);
}

void Control::set_scale(const Vector2 scale) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "set_scale");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, scale);
}

void Control::set_pivot_offset(const Vector2 pivot_offset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "set_pivot_offset");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, pivot_offset);
}

double Control::get_margin(const int64_t margin) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "get_margin");
	}
	return ___godot_icall_float_int(mb, (const Object *) this, margin);
}

Vector2 Control::get_begin() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "get_begin");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

Vector2 Control::get_end() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "get_end");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

Vector2 Control::get_position() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "get_position");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

Vector2 Control::get_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "get_size");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

double Control::get_rotation() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "get_rotation");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

double Control::get_rotation_degrees() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "get_rotation_degrees");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

Vector2 Control::get_scale() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "get_scale");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

Vector2 Control::get_pivot_offset() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "get_pivot_offset");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

Vector2 Control::get_custom_minimum_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "get_custom_minimum_size");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

Vector2 Control::get_parent_area_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "get_parent_area_size");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

Vector2 Control::get_global_position() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "get_global_position");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

Rect2 Control::get_rect() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "get_rect");
	}
	return ___godot_icall_Rect2(mb, (const Object *) this);
}

Rect2 Control::get_global_rect() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "get_global_rect");
	}
	return ___godot_icall_Rect2(mb, (const Object *) this);
}

void Control::show_modal(const bool exclusive) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "show_modal");
	}
	___godot_icall_void_bool(mb, (const Object *) this, exclusive);
}

void Control::set_focus_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "set_focus_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

Control::FocusMode Control::get_focus_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "get_focus_mode");
	}
	return (Control::FocusMode) ___godot_icall_int(mb, (const Object *) this);
}

bool Control::has_focus() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "has_focus");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Control::grab_focus() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "grab_focus");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Control::release_focus() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "release_focus");
	}
	___godot_icall_void(mb, (const Object *) this);
}

Control *Control::get_focus_owner() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "get_focus_owner");
	}
	return (Control *) ___godot_icall_Object(mb, (const Object *) this);
}

void Control::set_h_size_flags(const int64_t flags) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "set_h_size_flags");
	}
	___godot_icall_void_int(mb, (const Object *) this, flags);
}

int64_t Control::get_h_size_flags() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "get_h_size_flags");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void Control::set_stretch_ratio(const double ratio) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "set_stretch_ratio");
	}
	___godot_icall_void_float(mb, (const Object *) this, ratio);
}

double Control::get_stretch_ratio() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "get_stretch_ratio");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Control::set_v_size_flags(const int64_t flags) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "set_v_size_flags");
	}
	___godot_icall_void_int(mb, (const Object *) this, flags);
}

int64_t Control::get_v_size_flags() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "get_v_size_flags");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void Control::set_theme(const Ref<Theme> theme) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "set_theme");
	}
	___godot_icall_void_Object(mb, (const Object *) this, theme.ptr());
}

Ref<Theme> Control::get_theme() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "get_theme");
	}
	return Ref<Theme>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void Control::add_icon_override(const String name, const Ref<Texture> texture) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "add_icon_override");
	}
	___godot_icall_void_String_Object(mb, (const Object *) this, name, texture.ptr());
}

void Control::add_shader_override(const String name, const Ref<Shader> shader) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "add_shader_override");
	}
	___godot_icall_void_String_Object(mb, (const Object *) this, name, shader.ptr());
}

void Control::add_stylebox_override(const String name, const Ref<StyleBox> stylebox) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "add_stylebox_override");
	}
	___godot_icall_void_String_Object(mb, (const Object *) this, name, stylebox.ptr());
}

void Control::add_font_override(const String name, const Ref<Font> font) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "add_font_override");
	}
	___godot_icall_void_String_Object(mb, (const Object *) this, name, font.ptr());
}

void Control::add_color_override(const String name, const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "add_color_override");
	}
	___godot_icall_void_String_Color(mb, (const Object *) this, name, color);
}

void Control::add_constant_override(const String name, const int64_t constant) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "add_constant_override");
	}
	___godot_icall_void_String_int(mb, (const Object *) this, name, constant);
}

Ref<Texture> Control::get_icon(const String name, const String type) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "get_icon");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object_String_String(mb, (const Object *) this, name, type));
}

Ref<StyleBox> Control::get_stylebox(const String name, const String type) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "get_stylebox");
	}
	return Ref<StyleBox>::__internal_constructor(___godot_icall_Object_String_String(mb, (const Object *) this, name, type));
}

Ref<Font> Control::get_font(const String name, const String type) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "get_font");
	}
	return Ref<Font>::__internal_constructor(___godot_icall_Object_String_String(mb, (const Object *) this, name, type));
}

Color Control::get_color(const String name, const String type) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "get_color");
	}
	return ___godot_icall_Color_String_String(mb, (const Object *) this, name, type);
}

int64_t Control::get_constant(const String name, const String type) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "get_constant");
	}
	return ___godot_icall_int_String_String(mb, (const Object *) this, name, type);
}

bool Control::has_icon_override(const String name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "has_icon_override");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, name);
}

bool Control::has_shader_override(const String name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "has_shader_override");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, name);
}

bool Control::has_stylebox_override(const String name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "has_stylebox_override");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, name);
}

bool Control::has_font_override(const String name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "has_font_override");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, name);
}

bool Control::has_color_override(const String name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "has_color_override");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, name);
}

bool Control::has_constant_override(const String name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "has_constant_override");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, name);
}

bool Control::has_icon(const String name, const String type) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "has_icon");
	}
	return ___godot_icall_bool_String_String(mb, (const Object *) this, name, type);
}

bool Control::has_stylebox(const String name, const String type) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "has_stylebox");
	}
	return ___godot_icall_bool_String_String(mb, (const Object *) this, name, type);
}

bool Control::has_font(const String name, const String type) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "has_font");
	}
	return ___godot_icall_bool_String_String(mb, (const Object *) this, name, type);
}

bool Control::has_color(const String name, const String type) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "has_color");
	}
	return ___godot_icall_bool_String_String(mb, (const Object *) this, name, type);
}

bool Control::has_constant(const String name, const String type) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "has_constant");
	}
	return ___godot_icall_bool_String_String(mb, (const Object *) this, name, type);
}

Control *Control::get_parent_control() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "get_parent_control");
	}
	return (Control *) ___godot_icall_Object(mb, (const Object *) this);
}

void Control::set_h_grow_direction(const int64_t direction) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "set_h_grow_direction");
	}
	___godot_icall_void_int(mb, (const Object *) this, direction);
}

Control::GrowDirection Control::get_h_grow_direction() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "get_h_grow_direction");
	}
	return (Control::GrowDirection) ___godot_icall_int(mb, (const Object *) this);
}

void Control::set_v_grow_direction(const int64_t direction) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "set_v_grow_direction");
	}
	___godot_icall_void_int(mb, (const Object *) this, direction);
}

Control::GrowDirection Control::get_v_grow_direction() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "get_v_grow_direction");
	}
	return (Control::GrowDirection) ___godot_icall_int(mb, (const Object *) this);
}

void Control::set_tooltip(const String tooltip) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "set_tooltip");
	}
	___godot_icall_void_String(mb, (const Object *) this, tooltip);
}

String Control::get_tooltip(const Vector2 at_position) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "get_tooltip");
	}
	return ___godot_icall_String_Vector2(mb, (const Object *) this, at_position);
}

String Control::_get_tooltip() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "_get_tooltip");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void Control::set_default_cursor_shape(const int64_t shape) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "set_default_cursor_shape");
	}
	___godot_icall_void_int(mb, (const Object *) this, shape);
}

Control::CursorShape Control::get_default_cursor_shape() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "get_default_cursor_shape");
	}
	return (Control::CursorShape) ___godot_icall_int(mb, (const Object *) this);
}

Control::CursorShape Control::get_cursor_shape(const Vector2 position) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "get_cursor_shape");
	}
	return (Control::CursorShape) ___godot_icall_int_Vector2(mb, (const Object *) this, position);
}

void Control::set_focus_neighbour(const int64_t margin, const NodePath neighbour) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "set_focus_neighbour");
	}
	___godot_icall_void_int_NodePath(mb, (const Object *) this, margin, neighbour);
}

NodePath Control::get_focus_neighbour(const int64_t margin) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "get_focus_neighbour");
	}
	return ___godot_icall_NodePath_int(mb, (const Object *) this, margin);
}

void Control::set_focus_next(const NodePath next) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "set_focus_next");
	}
	___godot_icall_void_NodePath(mb, (const Object *) this, next);
}

NodePath Control::get_focus_next() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "get_focus_next");
	}
	return ___godot_icall_NodePath(mb, (const Object *) this);
}

void Control::set_focus_previous(const NodePath previous) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "set_focus_previous");
	}
	___godot_icall_void_NodePath(mb, (const Object *) this, previous);
}

NodePath Control::get_focus_previous() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "get_focus_previous");
	}
	return ___godot_icall_NodePath(mb, (const Object *) this);
}

void Control::force_drag(const Variant data, const Object *preview) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "force_drag");
	}
	___godot_icall_void_Variant_Object(mb, (const Object *) this, data, preview);
}

void Control::set_mouse_filter(const int64_t filter) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "set_mouse_filter");
	}
	___godot_icall_void_int(mb, (const Object *) this, filter);
}

Control::MouseFilter Control::get_mouse_filter() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "get_mouse_filter");
	}
	return (Control::MouseFilter) ___godot_icall_int(mb, (const Object *) this);
}

void Control::set_clip_contents(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "set_clip_contents");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool Control::is_clipping_contents() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "is_clipping_contents");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Control::grab_click_focus() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "grab_click_focus");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Control::set_drag_forwarding(const Object *target) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "set_drag_forwarding");
	}
	___godot_icall_void_Object(mb, (const Object *) this, target);
}

void Control::set_drag_preview(const Object *control) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "set_drag_preview");
	}
	___godot_icall_void_Object(mb, (const Object *) this, control);
}

void Control::warp_mouse(const Vector2 to_position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "warp_mouse");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, to_position);
}

void Control::minimum_size_changed() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "minimum_size_changed");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Control::_theme_changed() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "_theme_changed");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Control::_font_changed() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Control", "_font_changed");
	}
	___godot_icall_void(mb, (const Object *) this);
}

}