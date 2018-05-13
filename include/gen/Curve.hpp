#ifndef GODOT_CPP_CURVE_HPP
#define GODOT_CPP_CURVE_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include "Curve.hpp"

#include "Resource.hpp"
namespace godot {


class Curve : public Resource {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Curve"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum TangentMode {
		TANGENT_MODE_COUNT = 2,
		TANGENT_FREE = 0,
		TANGENT_LINEAR = 1,
	};

	// constants


	static Curve *_new();

	// methods
	int64_t add_point(const Vector2 position, const double left_tangent = 0, const double right_tangent = 0, const int64_t left_mode = 0, const int64_t right_mode = 0);
	void remove_point(const int64_t index);
	void clear_points();
	Vector2 get_point_position(const int64_t index) const;
	void set_point_value(const int64_t index, const double y);
	int64_t set_point_offset(const int64_t index, const double offset);
	double interpolate(const double offset) const;
	double interpolate_baked(const double offset);
	double get_point_left_tangent(const int64_t index) const;
	double get_point_right_tangent(const int64_t index) const;
	Curve::TangentMode get_point_left_mode(const int64_t index) const;
	Curve::TangentMode get_point_right_mode(const int64_t index) const;
	void set_point_left_tangent(const int64_t index, const double tangent);
	void set_point_right_tangent(const int64_t index, const double tangent);
	void set_point_left_mode(const int64_t index, const int64_t mode);
	void set_point_right_mode(const int64_t index, const int64_t mode);
	double get_min_value() const;
	void set_min_value(const double min);
	double get_max_value() const;
	void set_max_value(const double max);
	void clean_dupes();
	void bake();
	int64_t get_bake_resolution() const;
	void set_bake_resolution(const int64_t resolution);
	Array _get_data() const;
	void _set_data(const Array data);

};

}

#endif