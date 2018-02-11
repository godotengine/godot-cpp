#include <Path.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Curve3D.hpp>


namespace godot {


void *Path::___get_type_tag()
{
	return (void *) &Path::___get_type_tag;
}

void *Path::___get_base_type_tag()
{
	return (void *) &Spatial::___get_type_tag;
}

Path *Path::_new()
{
	return (Path *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Path")());
}
void Path::set_curve(const Ref<Curve3D> curve) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Path", "set_curve");
	}
	___godot_icall_void_Object(mb, (const Object *) this, curve.ptr());
}

Ref<Curve3D> Path::get_curve() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Path", "get_curve");
	}
	return Ref<Curve3D>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void Path::_curve_changed() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Path", "_curve_changed");
	}
	___godot_icall_void(mb, (const Object *) this);
}

}