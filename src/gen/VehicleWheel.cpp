#include <VehicleWheel.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *VehicleWheel::___get_type_tag()
{
	return (void *) &VehicleWheel::___get_type_tag;
}

void *VehicleWheel::___get_base_type_tag()
{
	return (void *) &Spatial::___get_type_tag;
}

VehicleWheel *VehicleWheel::_new()
{
	return (VehicleWheel *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"VehicleWheel")());
}
void VehicleWheel::set_radius(const double length) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VehicleWheel", "set_radius");
	}
	___godot_icall_void_float(mb, (const Object *) this, length);
}

double VehicleWheel::get_radius() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VehicleWheel", "get_radius");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void VehicleWheel::set_suspension_rest_length(const double length) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VehicleWheel", "set_suspension_rest_length");
	}
	___godot_icall_void_float(mb, (const Object *) this, length);
}

double VehicleWheel::get_suspension_rest_length() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VehicleWheel", "get_suspension_rest_length");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void VehicleWheel::set_suspension_travel(const double length) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VehicleWheel", "set_suspension_travel");
	}
	___godot_icall_void_float(mb, (const Object *) this, length);
}

double VehicleWheel::get_suspension_travel() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VehicleWheel", "get_suspension_travel");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void VehicleWheel::set_suspension_stiffness(const double length) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VehicleWheel", "set_suspension_stiffness");
	}
	___godot_icall_void_float(mb, (const Object *) this, length);
}

double VehicleWheel::get_suspension_stiffness() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VehicleWheel", "get_suspension_stiffness");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void VehicleWheel::set_suspension_max_force(const double length) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VehicleWheel", "set_suspension_max_force");
	}
	___godot_icall_void_float(mb, (const Object *) this, length);
}

double VehicleWheel::get_suspension_max_force() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VehicleWheel", "get_suspension_max_force");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void VehicleWheel::set_damping_compression(const double length) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VehicleWheel", "set_damping_compression");
	}
	___godot_icall_void_float(mb, (const Object *) this, length);
}

double VehicleWheel::get_damping_compression() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VehicleWheel", "get_damping_compression");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void VehicleWheel::set_damping_relaxation(const double length) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VehicleWheel", "set_damping_relaxation");
	}
	___godot_icall_void_float(mb, (const Object *) this, length);
}

double VehicleWheel::get_damping_relaxation() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VehicleWheel", "get_damping_relaxation");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void VehicleWheel::set_use_as_traction(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VehicleWheel", "set_use_as_traction");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool VehicleWheel::is_used_as_traction() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VehicleWheel", "is_used_as_traction");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void VehicleWheel::set_use_as_steering(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VehicleWheel", "set_use_as_steering");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool VehicleWheel::is_used_as_steering() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VehicleWheel", "is_used_as_steering");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void VehicleWheel::set_friction_slip(const double length) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VehicleWheel", "set_friction_slip");
	}
	___godot_icall_void_float(mb, (const Object *) this, length);
}

double VehicleWheel::get_friction_slip() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VehicleWheel", "get_friction_slip");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

bool VehicleWheel::is_in_contact() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VehicleWheel", "is_in_contact");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void VehicleWheel::set_roll_influence(const double roll_influence) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VehicleWheel", "set_roll_influence");
	}
	___godot_icall_void_float(mb, (const Object *) this, roll_influence);
}

double VehicleWheel::get_roll_influence() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VehicleWheel", "get_roll_influence");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

double VehicleWheel::get_skidinfo() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VehicleWheel", "get_skidinfo");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

}