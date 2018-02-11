#ifndef GODOT_CPP_VISUALSCRIPTYIELD_HPP
#define GODOT_CPP_VISUALSCRIPTYIELD_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <VisualScriptYield.hpp>

#include <VisualScriptNode.hpp>
namespace godot {


class VisualScriptYield : public VisualScriptNode {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "VisualScriptYield"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum YieldMode {
		YIELD_PHYSICS_FRAME = 2,
		YIELD_FRAME = 1,
		YIELD_WAIT = 3,
	};

	// constants


	static VisualScriptYield *_new();

	// methods
	void set_yield_mode(const int64_t mode);
	VisualScriptYield::YieldMode get_yield_mode();
	void set_wait_time(const double sec);
	double get_wait_time();

};

}

#endif