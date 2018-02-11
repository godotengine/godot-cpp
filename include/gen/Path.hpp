#ifndef GODOT_CPP_PATH_HPP
#define GODOT_CPP_PATH_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Spatial.hpp>
namespace godot {

class Curve3D;

class Path : public Spatial {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Path"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static Path *_new();

	// methods
	void set_curve(const Ref<Curve3D> curve);
	Ref<Curve3D> get_curve() const;
	void _curve_changed();

};

}

#endif