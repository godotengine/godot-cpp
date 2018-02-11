#ifndef GODOT_CPP_VISUALSCRIPTMATHCONSTANT_HPP
#define GODOT_CPP_VISUALSCRIPTMATHCONSTANT_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <VisualScriptMathConstant.hpp>

#include <VisualScriptNode.hpp>
namespace godot {


class VisualScriptMathConstant : public VisualScriptNode {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "VisualScriptMathConstant"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum MathConstant {
		MATH_CONSTANT_HALF_PI = 2,
		MATH_CONSTANT_MAX = 8,
		MATH_CONSTANT_ONE = 0,
		MATH_CONSTANT_NAN = 7,
		MATH_CONSTANT_SQRT2 = 5,
		MATH_CONSTANT_E = 4,
		MATH_CONSTANT_INF = 6,
		MATH_CONSTANT_PI = 1,
		MATH_CONSTANT_TAU = 3,
	};

	// constants


	static VisualScriptMathConstant *_new();

	// methods
	void set_math_constant(const int64_t which);
	VisualScriptMathConstant::MathConstant get_math_constant();

};

}

#endif