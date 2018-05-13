#ifndef GODOT_CPP_WORLD2D_HPP
#define GODOT_CPP_WORLD2D_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Resource.hpp"
namespace godot {

class Physics2DDirectSpaceState;

class World2D : public Resource {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "World2D"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static World2D *_new();

	// methods
	RID get_canvas();
	RID get_space();
	Physics2DDirectSpaceState *get_direct_space_state();

};

}

#endif