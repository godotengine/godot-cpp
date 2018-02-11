#ifndef GODOT_CPP_JAVASCRIPT_HPP
#define GODOT_CPP_JAVASCRIPT_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Object.hpp>
namespace godot {


class JavaScript : public Object {
	static JavaScript *_singleton;

	JavaScript();

public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline JavaScript *get_singleton()
	{
		if (!JavaScript::_singleton) {
			JavaScript::_singleton = new JavaScript;
		}
		return JavaScript::_singleton;
	}

	static inline const char *___get_class_name() { return (const char *) "JavaScript"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants

	// methods
	Variant eval(const String code, const bool use_global_execution_context = false);

};

}

#endif