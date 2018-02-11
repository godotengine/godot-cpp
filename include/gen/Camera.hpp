#ifndef GODOT_CPP_CAMERA_HPP
#define GODOT_CPP_CAMERA_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <Camera.hpp>

#include <Spatial.hpp>
namespace godot {

class Environment;

class Camera : public Spatial {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Camera"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum KeepAspect {
		KEEP_WIDTH = 0,
		KEEP_HEIGHT = 1,
	};
	enum Projection {
		PROJECTION_PERSPECTIVE = 0,
		PROJECTION_ORTHOGONAL = 1,
	};
	enum DopplerTracking {
		DOPPLER_TRACKING_IDLE_STEP = 1,
		DOPPLER_TRACKING_PHYSICS_STEP = 2,
		DOPPLER_TRACKING_DISABLED = 0,
	};

	// constants


	static Camera *_new();

	// methods
	Vector3 project_ray_normal(const Vector2 screen_point) const;
	Vector3 project_local_ray_normal(const Vector2 screen_point) const;
	Vector3 project_ray_origin(const Vector2 screen_point) const;
	Vector2 unproject_position(const Vector3 world_point) const;
	bool is_position_behind(const Vector3 world_point) const;
	Vector3 project_position(const Vector2 screen_point) const;
	void set_perspective(const double fov, const double z_near, const double z_far);
	void set_orthogonal(const double size, const double z_near, const double z_far);
	void make_current();
	void clear_current(const bool enable_next = true);
	void set_current(const bool arg0);
	bool is_current() const;
	Transform get_camera_transform() const;
	double get_fov() const;
	double get_size() const;
	double get_zfar() const;
	double get_znear() const;
	void set_fov(const double arg0);
	void set_size(const double arg0);
	void set_zfar(const double arg0);
	void set_znear(const double arg0);
	Camera::Projection get_projection() const;
	void set_projection(const int64_t arg0);
	void set_h_offset(const double ofs);
	double get_h_offset() const;
	void set_v_offset(const double ofs);
	double get_v_offset() const;
	void set_cull_mask(const int64_t mask);
	int64_t get_cull_mask() const;
	void set_environment(const Ref<Environment> env);
	Ref<Environment> get_environment() const;
	void set_keep_aspect_mode(const int64_t mode);
	Camera::KeepAspect get_keep_aspect_mode() const;
	void set_doppler_tracking(const int64_t mode);
	Camera::DopplerTracking get_doppler_tracking() const;

};

}

#endif