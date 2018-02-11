#ifndef GODOT_CPP_INTERPOLATEDCAMERA_HPP
#define GODOT_CPP_INTERPOLATEDCAMERA_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Camera.hpp>
namespace godot {

class Object;

class InterpolatedCamera : public Camera {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "InterpolatedCamera"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static InterpolatedCamera *_new();

	// methods
	void set_target_path(const NodePath target_path);
	NodePath get_target_path() const;
	void set_target(const Object *target);
	void set_speed(const double speed);
	double get_speed() const;
	void set_interpolation_enabled(const bool target_path);
	bool is_interpolation_enabled() const;

};

}

#endif