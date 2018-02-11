#include <PinJoint2D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *PinJoint2D::___get_type_tag()
{
	return (void *) &PinJoint2D::___get_type_tag;
}

void *PinJoint2D::___get_base_type_tag()
{
	return (void *) &Joint2D::___get_type_tag;
}

PinJoint2D *PinJoint2D::_new()
{
	return (PinJoint2D *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"PinJoint2D")());
}
void PinJoint2D::set_softness(const double softness) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PinJoint2D", "set_softness");
	}
	___godot_icall_void_float(mb, (const Object *) this, softness);
}

double PinJoint2D::get_softness() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PinJoint2D", "get_softness");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

}