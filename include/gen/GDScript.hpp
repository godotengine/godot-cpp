#ifndef GODOT_CPP_GDSCRIPT_HPP
#define GODOT_CPP_GDSCRIPT_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Script.hpp>
namespace godot {

class Object;

class GDScript : public Script {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "GDScript"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static GDScript *_new();

	// methods
	Object *new_(const Array& __var_args = Array());
	PoolByteArray get_as_byte_code() const;
	template <class... Args> Object *new_(Args... args){
		return new_(Array::make(args...));
	}

};

}

#endif