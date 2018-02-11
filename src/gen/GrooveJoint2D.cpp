#include <GrooveJoint2D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *GrooveJoint2D::___get_type_tag()
{
	return (void *) &GrooveJoint2D::___get_type_tag;
}

void *GrooveJoint2D::___get_base_type_tag()
{
	return (void *) &Joint2D::___get_type_tag;
}

GrooveJoint2D *GrooveJoint2D::_new()
{
	return (GrooveJoint2D *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"GrooveJoint2D")());
}
void GrooveJoint2D::set_length(const double length) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GrooveJoint2D", "set_length");
	}
	___godot_icall_void_float(mb, (const Object *) this, length);
}

double GrooveJoint2D::get_length() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GrooveJoint2D", "get_length");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void GrooveJoint2D::set_initial_offset(const double offset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GrooveJoint2D", "set_initial_offset");
	}
	___godot_icall_void_float(mb, (const Object *) this, offset);
}

double GrooveJoint2D::get_initial_offset() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GrooveJoint2D", "get_initial_offset");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

}