#include <BoxShape.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *BoxShape::___get_type_tag()
{
	return (void *) &BoxShape::___get_type_tag;
}

void *BoxShape::___get_base_type_tag()
{
	return (void *) &Shape::___get_type_tag;
}

BoxShape *BoxShape::_new()
{
	return (BoxShape *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"BoxShape")());
}
void BoxShape::set_extents(const Vector3 extents) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BoxShape", "set_extents");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, extents);
}

Vector3 BoxShape::get_extents() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BoxShape", "get_extents");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

}