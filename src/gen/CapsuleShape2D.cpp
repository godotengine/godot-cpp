#include <CapsuleShape2D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *CapsuleShape2D::___get_type_tag()
{
	return (void *) &CapsuleShape2D::___get_type_tag;
}

void *CapsuleShape2D::___get_base_type_tag()
{
	return (void *) &Shape2D::___get_type_tag;
}

CapsuleShape2D *CapsuleShape2D::_new()
{
	return (CapsuleShape2D *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"CapsuleShape2D")());
}
void CapsuleShape2D::set_radius(const double radius) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CapsuleShape2D", "set_radius");
	}
	___godot_icall_void_float(mb, (const Object *) this, radius);
}

double CapsuleShape2D::get_radius() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CapsuleShape2D", "get_radius");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void CapsuleShape2D::set_height(const double height) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CapsuleShape2D", "set_height");
	}
	___godot_icall_void_float(mb, (const Object *) this, height);
}

double CapsuleShape2D::get_height() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CapsuleShape2D", "get_height");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

}