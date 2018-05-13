#ifndef GODOT_CPP_GROOVEJOINT2D_HPP
#define GODOT_CPP_GROOVEJOINT2D_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Joint2D.hpp"
namespace godot {


class GrooveJoint2D : public Joint2D {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "GrooveJoint2D"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static GrooveJoint2D *_new();

	// methods
	void set_length(const double length);
	double get_length() const;
	void set_initial_offset(const double offset);
	double get_initial_offset() const;

};

}

#endif