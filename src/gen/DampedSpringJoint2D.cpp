#include <DampedSpringJoint2D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *DampedSpringJoint2D::___get_type_tag()
{
	return (void *) &DampedSpringJoint2D::___get_type_tag;
}

void *DampedSpringJoint2D::___get_base_type_tag()
{
	return (void *) &Joint2D::___get_type_tag;
}

DampedSpringJoint2D *DampedSpringJoint2D::_new()
{
	return (DampedSpringJoint2D *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"DampedSpringJoint2D")());
}
void DampedSpringJoint2D::set_length(const double length) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("DampedSpringJoint2D", "set_length");
	}
	___godot_icall_void_float(mb, (const Object *) this, length);
}

double DampedSpringJoint2D::get_length() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("DampedSpringJoint2D", "get_length");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void DampedSpringJoint2D::set_rest_length(const double rest_length) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("DampedSpringJoint2D", "set_rest_length");
	}
	___godot_icall_void_float(mb, (const Object *) this, rest_length);
}

double DampedSpringJoint2D::get_rest_length() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("DampedSpringJoint2D", "get_rest_length");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void DampedSpringJoint2D::set_stiffness(const double stiffness) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("DampedSpringJoint2D", "set_stiffness");
	}
	___godot_icall_void_float(mb, (const Object *) this, stiffness);
}

double DampedSpringJoint2D::get_stiffness() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("DampedSpringJoint2D", "get_stiffness");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void DampedSpringJoint2D::set_damping(const double damping) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("DampedSpringJoint2D", "set_damping");
	}
	___godot_icall_void_float(mb, (const Object *) this, damping);
}

double DampedSpringJoint2D::get_damping() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("DampedSpringJoint2D", "get_damping");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

}