#ifndef GODOT_CPP_SHAPE2D_HPP
#define GODOT_CPP_SHAPE2D_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Resource.hpp"
namespace godot {

class Shape2D;

class Shape2D : public Resource {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Shape2D"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants

	// methods
	void set_custom_solver_bias(const double bias);
	double get_custom_solver_bias() const;
	bool collide(const Transform2D local_xform, const Ref<Shape2D> with_shape, const Transform2D shape_xform);
	bool collide_with_motion(const Transform2D local_xform, const Vector2 local_motion, const Ref<Shape2D> with_shape, const Transform2D shape_xform, const Vector2 shape_motion);
	Variant collide_and_get_contacts(const Transform2D local_xform, const Ref<Shape2D> with_shape, const Transform2D shape_xform);
	Variant collide_with_motion_and_get_contacts(const Transform2D local_xform, const Vector2 local_motion, const Ref<Shape2D> with_shape, const Transform2D shape_xform, const Vector2 shape_motion);

};

}

#endif