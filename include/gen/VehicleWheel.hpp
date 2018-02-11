#ifndef GODOT_CPP_VEHICLEWHEEL_HPP
#define GODOT_CPP_VEHICLEWHEEL_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Spatial.hpp>
namespace godot {


class VehicleWheel : public Spatial {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "VehicleWheel"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static VehicleWheel *_new();

	// methods
	void set_radius(const double length);
	double get_radius() const;
	void set_suspension_rest_length(const double length);
	double get_suspension_rest_length() const;
	void set_suspension_travel(const double length);
	double get_suspension_travel() const;
	void set_suspension_stiffness(const double length);
	double get_suspension_stiffness() const;
	void set_suspension_max_force(const double length);
	double get_suspension_max_force() const;
	void set_damping_compression(const double length);
	double get_damping_compression() const;
	void set_damping_relaxation(const double length);
	double get_damping_relaxation() const;
	void set_use_as_traction(const bool enable);
	bool is_used_as_traction() const;
	void set_use_as_steering(const bool enable);
	bool is_used_as_steering() const;
	void set_friction_slip(const double length);
	double get_friction_slip() const;
	bool is_in_contact() const;
	void set_roll_influence(const double roll_influence);
	double get_roll_influence() const;
	double get_skidinfo() const;

};

}

#endif