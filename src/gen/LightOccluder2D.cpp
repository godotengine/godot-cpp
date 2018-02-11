#include <LightOccluder2D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <OccluderPolygon2D.hpp>


namespace godot {


void *LightOccluder2D::___get_type_tag()
{
	return (void *) &LightOccluder2D::___get_type_tag;
}

void *LightOccluder2D::___get_base_type_tag()
{
	return (void *) &Node2D::___get_type_tag;
}

LightOccluder2D *LightOccluder2D::_new()
{
	return (LightOccluder2D *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"LightOccluder2D")());
}
void LightOccluder2D::set_occluder_polygon(const Ref<OccluderPolygon2D> polygon) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LightOccluder2D", "set_occluder_polygon");
	}
	___godot_icall_void_Object(mb, (const Object *) this, polygon.ptr());
}

Ref<OccluderPolygon2D> LightOccluder2D::get_occluder_polygon() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LightOccluder2D", "get_occluder_polygon");
	}
	return Ref<OccluderPolygon2D>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void LightOccluder2D::set_occluder_light_mask(const int64_t mask) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LightOccluder2D", "set_occluder_light_mask");
	}
	___godot_icall_void_int(mb, (const Object *) this, mask);
}

int64_t LightOccluder2D::get_occluder_light_mask() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LightOccluder2D", "get_occluder_light_mask");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void LightOccluder2D::_poly_changed() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LightOccluder2D", "_poly_changed");
	}
	___godot_icall_void(mb, (const Object *) this);
}

}