#ifndef GODOT_CPP_FUNCREF_HPP
#define GODOT_CPP_FUNCREF_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Reference.hpp>
namespace godot {

class Object;

class FuncRef : public Reference {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "FuncRef"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static FuncRef *_new();

	// methods
	Variant call_func(const Array& __var_args = Array());
	void set_instance(const Object *instance);
	void set_function(const String name);
	template <class... Args> Variant call_func(Args... args){
		return call_func(Array::make(args...));
	}

};

}

#endif