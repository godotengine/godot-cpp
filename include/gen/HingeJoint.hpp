#ifndef GODOT_CPP_HINGEJOINT_HPP
#define GODOT_CPP_HINGEJOINT_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Joint.hpp>
namespace godot {


class HingeJoint : public Joint {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "HingeJoint"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum Param {
		PARAM_LIMIT_UPPER = 1,
		PARAM_MOTOR_MAX_IMPULSE = 7,
		PARAM_MAX = 8,
		PARAM_LIMIT_LOWER = 2,
		PARAM_LIMIT_RELAXATION = 5,
		PARAM_LIMIT_SOFTNESS = 4,
		PARAM_MOTOR_TARGET_VELOCITY = 6,
		PARAM_LIMIT_BIAS = 3,
		PARAM_BIAS = 0,
	};
	enum Flag {
		FLAG_USE_LIMIT = 0,
		FLAG_MAX = 2,
		FLAG_ENABLE_MOTOR = 1,
	};

	// constants


	static HingeJoint *_new();

	// methods
	void set_param(const int64_t param, const double value);
	double get_param(const int64_t param) const;
	void set_flag(const int64_t flag, const bool enabled);
	bool get_flag(const int64_t flag) const;
	void _set_upper_limit(const double upper_limit);
	double _get_upper_limit() const;
	void _set_lower_limit(const double lower_limit);
	double _get_lower_limit() const;

};

}

#endif