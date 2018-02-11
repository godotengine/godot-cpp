#ifndef GODOT_CPP_PATHFOLLOW_HPP
#define GODOT_CPP_PATHFOLLOW_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <PathFollow.hpp>

#include <Spatial.hpp>
namespace godot {


class PathFollow : public Spatial {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "PathFollow"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum RotationMode {
		ROTATION_Y = 1,
		ROTATION_NONE = 0,
		ROTATION_XY = 2,
		ROTATION_XYZ = 3,
	};

	// constants


	static PathFollow *_new();

	// methods
	void set_offset(const double offset);
	double get_offset() const;
	void set_h_offset(const double h_offset);
	double get_h_offset() const;
	void set_v_offset(const double v_offset);
	double get_v_offset() const;
	void set_unit_offset(const double unit_offset);
	double get_unit_offset() const;
	void set_rotation_mode(const int64_t rotation_mode);
	PathFollow::RotationMode get_rotation_mode() const;
	void set_cubic_interpolation(const bool enable);
	bool get_cubic_interpolation() const;
	void set_loop(const bool loop);
	bool has_loop() const;

};

}

#endif