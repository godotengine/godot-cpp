#ifndef GODOT_CPP_PINJOINT_HPP
#define GODOT_CPP_PINJOINT_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Joint.hpp>
namespace godot {


class PinJoint : public Joint {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "PinJoint"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum Param {
		PARAM_DAMPING = 1,
		PARAM_IMPULSE_CLAMP = 2,
		PARAM_BIAS = 0,
	};

	// constants


	static PinJoint *_new();

	// methods
	void set_param(const int64_t param, const double value);
	double get_param(const int64_t param) const;

};

}

#endif