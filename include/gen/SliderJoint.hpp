#ifndef GODOT_CPP_SLIDERJOINT_HPP
#define GODOT_CPP_SLIDERJOINT_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Joint.hpp"
namespace godot {


class SliderJoint : public Joint {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "SliderJoint"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum Param {
		PARAM_ANGULAR_LIMIT_DAMPING = 15,
		PARAM_LINEAR_MOTION_SOFTNESS = 5,
		PARAM_ANGULAR_ORTHOGONAL_RESTITUTION = 20,
		PARAM_ANGULAR_MOTION_SOFTNESS = 16,
		PARAM_LINEAR_LIMIT_LOWER = 1,
		PARAM_ANGULAR_LIMIT_SOFTNESS = 13,
		PARAM_LINEAR_ORTHOGONAL_RESTITUTION = 9,
		PARAM_ANGULAR_MOTION_DAMPING = 18,
		PARAM_LINEAR_LIMIT_UPPER = 0,
		PARAM_ANGULAR_ORTHOGONAL_SOFTNESS = 19,
		PARAM_ANGULAR_LIMIT_RESTITUTION = 14,
		PARAM_LINEAR_ORTHOGONAL_DAMPING = 10,
		PARAM_LINEAR_LIMIT_DAMPING = 4,
		PARAM_ANGULAR_ORTHOGONAL_DAMPING = 21,
		PARAM_LINEAR_LIMIT_RESTITUTION = 3,
		PARAM_ANGULAR_LIMIT_UPPER = 11,
		PARAM_LINEAR_ORTHOGONAL_SOFTNESS = 8,
		PARAM_LINEAR_MOTION_DAMPING = 7,
		PARAM_MAX = 22,
		PARAM_ANGULAR_MOTION_RESTITUTION = 17,
		PARAM_LINEAR_LIMIT_SOFTNESS = 2,
		PARAM_ANGULAR_LIMIT_LOWER = 12,
		PARAM_LINEAR_MOTION_RESTITUTION = 6,
	};

	// constants


	static SliderJoint *_new();

	// methods
	void set_param(const int64_t param, const double value);
	double get_param(const int64_t param) const;
	void _set_upper_limit_angular(const double upper_limit_angular);
	double _get_upper_limit_angular() const;
	void _set_lower_limit_angular(const double lower_limit_angular);
	double _get_lower_limit_angular() const;

};

}

#endif