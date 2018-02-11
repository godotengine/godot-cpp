#include <Camera2D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Object.hpp>
#include <Node.hpp>


namespace godot {


void *Camera2D::___get_type_tag()
{
	return (void *) &Camera2D::___get_type_tag;
}

void *Camera2D::___get_base_type_tag()
{
	return (void *) &Node2D::___get_type_tag;
}

Camera2D *Camera2D::_new()
{
	return (Camera2D *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Camera2D")());
}
void Camera2D::set_offset(const Vector2 offset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "set_offset");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, offset);
}

Vector2 Camera2D::get_offset() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "get_offset");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void Camera2D::set_anchor_mode(const int64_t anchor_mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "set_anchor_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, anchor_mode);
}

Camera2D::AnchorMode Camera2D::get_anchor_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "get_anchor_mode");
	}
	return (Camera2D::AnchorMode) ___godot_icall_int(mb, (const Object *) this);
}

void Camera2D::set_rotating(const bool rotating) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "set_rotating");
	}
	___godot_icall_void_bool(mb, (const Object *) this, rotating);
}

bool Camera2D::is_rotating() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "is_rotating");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Camera2D::make_current() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "make_current");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Camera2D::clear_current() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "clear_current");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Camera2D::_make_current(const Object *arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "_make_current");
	}
	___godot_icall_void_Object(mb, (const Object *) this, arg0);
}

void Camera2D::_update_scroll() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "_update_scroll");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Camera2D::_set_current(const bool current) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "_set_current");
	}
	___godot_icall_void_bool(mb, (const Object *) this, current);
}

bool Camera2D::is_current() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "is_current");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Camera2D::set_limit(const int64_t margin, const int64_t limit) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "set_limit");
	}
	___godot_icall_void_int_int(mb, (const Object *) this, margin, limit);
}

int64_t Camera2D::get_limit(const int64_t margin) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "get_limit");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, margin);
}

void Camera2D::set_limit_smoothing_enabled(const bool limit_smoothing_enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "set_limit_smoothing_enabled");
	}
	___godot_icall_void_bool(mb, (const Object *) this, limit_smoothing_enabled);
}

bool Camera2D::is_limit_smoothing_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "is_limit_smoothing_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Camera2D::set_v_drag_enabled(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "set_v_drag_enabled");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool Camera2D::is_v_drag_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "is_v_drag_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Camera2D::set_h_drag_enabled(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "set_h_drag_enabled");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool Camera2D::is_h_drag_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "is_h_drag_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Camera2D::set_v_offset(const double ofs) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "set_v_offset");
	}
	___godot_icall_void_float(mb, (const Object *) this, ofs);
}

double Camera2D::get_v_offset() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "get_v_offset");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Camera2D::set_h_offset(const double ofs) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "set_h_offset");
	}
	___godot_icall_void_float(mb, (const Object *) this, ofs);
}

double Camera2D::get_h_offset() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "get_h_offset");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Camera2D::set_drag_margin(const int64_t margin, const double drag_margin) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "set_drag_margin");
	}
	___godot_icall_void_int_float(mb, (const Object *) this, margin, drag_margin);
}

double Camera2D::get_drag_margin(const int64_t margin) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "get_drag_margin");
	}
	return ___godot_icall_float_int(mb, (const Object *) this, margin);
}

Vector2 Camera2D::get_camera_position() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "get_camera_position");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

Vector2 Camera2D::get_camera_screen_center() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "get_camera_screen_center");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void Camera2D::set_zoom(const Vector2 zoom) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "set_zoom");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, zoom);
}

Vector2 Camera2D::get_zoom() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "get_zoom");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void Camera2D::set_custom_viewport(const Object *viewport) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "set_custom_viewport");
	}
	___godot_icall_void_Object(mb, (const Object *) this, viewport);
}

Node *Camera2D::get_custom_viewport() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "get_custom_viewport");
	}
	return (Node *) ___godot_icall_Object(mb, (const Object *) this);
}

void Camera2D::set_follow_smoothing(const double follow_smoothing) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "set_follow_smoothing");
	}
	___godot_icall_void_float(mb, (const Object *) this, follow_smoothing);
}

double Camera2D::get_follow_smoothing() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "get_follow_smoothing");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Camera2D::set_enable_follow_smoothing(const bool follow_smoothing) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "set_enable_follow_smoothing");
	}
	___godot_icall_void_bool(mb, (const Object *) this, follow_smoothing);
}

bool Camera2D::is_follow_smoothing_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "is_follow_smoothing_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Camera2D::force_update_scroll() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "force_update_scroll");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Camera2D::reset_smoothing() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "reset_smoothing");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Camera2D::align() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "align");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Camera2D::_set_old_smoothing(const double follow_smoothing) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "_set_old_smoothing");
	}
	___godot_icall_void_float(mb, (const Object *) this, follow_smoothing);
}

void Camera2D::set_screen_drawing_enabled(const bool screen_drawing_enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "set_screen_drawing_enabled");
	}
	___godot_icall_void_bool(mb, (const Object *) this, screen_drawing_enabled);
}

bool Camera2D::is_screen_drawing_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "is_screen_drawing_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Camera2D::set_limit_drawing_enabled(const bool limit_drawing_enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "set_limit_drawing_enabled");
	}
	___godot_icall_void_bool(mb, (const Object *) this, limit_drawing_enabled);
}

bool Camera2D::is_limit_drawing_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "is_limit_drawing_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Camera2D::set_margin_drawing_enabled(const bool margin_drawing_enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "set_margin_drawing_enabled");
	}
	___godot_icall_void_bool(mb, (const Object *) this, margin_drawing_enabled);
}

bool Camera2D::is_margin_drawing_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera2D", "is_margin_drawing_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

}