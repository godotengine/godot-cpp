#include <Path2D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Curve2D.hpp>


namespace godot {


void *Path2D::___get_type_tag()
{
	return (void *) &Path2D::___get_type_tag;
}

void *Path2D::___get_base_type_tag()
{
	return (void *) &Node2D::___get_type_tag;
}

Path2D *Path2D::_new()
{
	return (Path2D *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Path2D")());
}
void Path2D::set_curve(const Ref<Curve2D> curve) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Path2D", "set_curve");
	}
	___godot_icall_void_Object(mb, (const Object *) this, curve.ptr());
}

Ref<Curve2D> Path2D::get_curve() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Path2D", "get_curve");
	}
	return Ref<Curve2D>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void Path2D::_curve_changed() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Path2D", "_curve_changed");
	}
	___godot_icall_void(mb, (const Object *) this);
}

}