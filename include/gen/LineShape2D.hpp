#ifndef GODOT_CPP_LINESHAPE2D_HPP
#define GODOT_CPP_LINESHAPE2D_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Shape2D.hpp>
namespace godot {


class LineShape2D : public Shape2D {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "LineShape2D"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static LineShape2D *_new();

	// methods
	void set_normal(const Vector2 normal);
	Vector2 get_normal() const;
	void set_d(const double d);
	double get_d() const;

};

}

#endif