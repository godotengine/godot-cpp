#include <Camera.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Environment.hpp>


namespace godot {


void *Camera::___get_type_tag()
{
	return (void *) &Camera::___get_type_tag;
}

void *Camera::___get_base_type_tag()
{
	return (void *) &Spatial::___get_type_tag;
}

Camera *Camera::_new()
{
	return (Camera *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Camera")());
}
Vector3 Camera::project_ray_normal(const Vector2 screen_point) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera", "project_ray_normal");
	}
	return ___godot_icall_Vector3_Vector2(mb, (const Object *) this, screen_point);
}

Vector3 Camera::project_local_ray_normal(const Vector2 screen_point) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera", "project_local_ray_normal");
	}
	return ___godot_icall_Vector3_Vector2(mb, (const Object *) this, screen_point);
}

Vector3 Camera::project_ray_origin(const Vector2 screen_point) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera", "project_ray_origin");
	}
	return ___godot_icall_Vector3_Vector2(mb, (const Object *) this, screen_point);
}

Vector2 Camera::unproject_position(const Vector3 world_point) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera", "unproject_position");
	}
	return ___godot_icall_Vector2_Vector3(mb, (const Object *) this, world_point);
}

bool Camera::is_position_behind(const Vector3 world_point) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera", "is_position_behind");
	}
	return ___godot_icall_bool_Vector3(mb, (const Object *) this, world_point);
}

Vector3 Camera::project_position(const Vector2 screen_point) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera", "project_position");
	}
	return ___godot_icall_Vector3_Vector2(mb, (const Object *) this, screen_point);
}

void Camera::set_perspective(const double fov, const double z_near, const double z_far) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera", "set_perspective");
	}
	___godot_icall_void_float_float_float(mb, (const Object *) this, fov, z_near, z_far);
}

void Camera::set_orthogonal(const double size, const double z_near, const double z_far) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera", "set_orthogonal");
	}
	___godot_icall_void_float_float_float(mb, (const Object *) this, size, z_near, z_far);
}

void Camera::make_current() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera", "make_current");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Camera::clear_current(const bool enable_next) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera", "clear_current");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable_next);
}

void Camera::set_current(const bool arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera", "set_current");
	}
	___godot_icall_void_bool(mb, (const Object *) this, arg0);
}

bool Camera::is_current() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera", "is_current");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

Transform Camera::get_camera_transform() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera", "get_camera_transform");
	}
	return ___godot_icall_Transform(mb, (const Object *) this);
}

double Camera::get_fov() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera", "get_fov");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

double Camera::get_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera", "get_size");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

double Camera::get_zfar() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera", "get_zfar");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

double Camera::get_znear() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera", "get_znear");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Camera::set_fov(const double arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera", "set_fov");
	}
	___godot_icall_void_float(mb, (const Object *) this, arg0);
}

void Camera::set_size(const double arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera", "set_size");
	}
	___godot_icall_void_float(mb, (const Object *) this, arg0);
}

void Camera::set_zfar(const double arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera", "set_zfar");
	}
	___godot_icall_void_float(mb, (const Object *) this, arg0);
}

void Camera::set_znear(const double arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera", "set_znear");
	}
	___godot_icall_void_float(mb, (const Object *) this, arg0);
}

Camera::Projection Camera::get_projection() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera", "get_projection");
	}
	return (Camera::Projection) ___godot_icall_int(mb, (const Object *) this);
}

void Camera::set_projection(const int64_t arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera", "set_projection");
	}
	___godot_icall_void_int(mb, (const Object *) this, arg0);
}

void Camera::set_h_offset(const double ofs) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera", "set_h_offset");
	}
	___godot_icall_void_float(mb, (const Object *) this, ofs);
}

double Camera::get_h_offset() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera", "get_h_offset");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Camera::set_v_offset(const double ofs) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera", "set_v_offset");
	}
	___godot_icall_void_float(mb, (const Object *) this, ofs);
}

double Camera::get_v_offset() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera", "get_v_offset");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Camera::set_cull_mask(const int64_t mask) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera", "set_cull_mask");
	}
	___godot_icall_void_int(mb, (const Object *) this, mask);
}

int64_t Camera::get_cull_mask() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera", "get_cull_mask");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void Camera::set_environment(const Ref<Environment> env) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera", "set_environment");
	}
	___godot_icall_void_Object(mb, (const Object *) this, env.ptr());
}

Ref<Environment> Camera::get_environment() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera", "get_environment");
	}
	return Ref<Environment>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void Camera::set_keep_aspect_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera", "set_keep_aspect_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

Camera::KeepAspect Camera::get_keep_aspect_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera", "get_keep_aspect_mode");
	}
	return (Camera::KeepAspect) ___godot_icall_int(mb, (const Object *) this);
}

void Camera::set_doppler_tracking(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera", "set_doppler_tracking");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

Camera::DopplerTracking Camera::get_doppler_tracking() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Camera", "get_doppler_tracking");
	}
	return (Camera::DopplerTracking) ___godot_icall_int(mb, (const Object *) this);
}

}