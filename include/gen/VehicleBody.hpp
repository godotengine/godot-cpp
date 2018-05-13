#ifndef GODOT_CPP_VEHICLEBODY_HPP
#define GODOT_CPP_VEHICLEBODY_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "RigidBody.hpp"
namespace godot {


class VehicleBody : public RigidBody {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "VehicleBody"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static VehicleBody *_new();

	// methods
	void set_engine_force(const double engine_force);
	double get_engine_force() const;
	void set_brake(const double brake);
	double get_brake() const;
	void set_steering(const double steering);
	double get_steering() const;

};

}

#endif