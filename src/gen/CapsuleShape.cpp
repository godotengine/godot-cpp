#include <CapsuleShape.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *CapsuleShape::___get_type_tag()
{
	return (void *) &CapsuleShape::___get_type_tag;
}

void *CapsuleShape::___get_base_type_tag()
{
	return (void *) &Shape::___get_type_tag;
}

CapsuleShape *CapsuleShape::_new()
{
	return (CapsuleShape *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"CapsuleShape")());
}
void CapsuleShape::set_radius(const double radius) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CapsuleShape", "set_radius");
	}
	___godot_icall_void_float(mb, (const Object *) this, radius);
}

double CapsuleShape::get_radius() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CapsuleShape", "get_radius");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void CapsuleShape::set_height(const double height) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CapsuleShape", "set_height");
	}
	___godot_icall_void_float(mb, (const Object *) this, height);
}

double CapsuleShape::get_height() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CapsuleShape", "get_height");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

}