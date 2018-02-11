#include <CapsuleMesh.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *CapsuleMesh::___get_type_tag()
{
	return (void *) &CapsuleMesh::___get_type_tag;
}

void *CapsuleMesh::___get_base_type_tag()
{
	return (void *) &PrimitiveMesh::___get_type_tag;
}

CapsuleMesh *CapsuleMesh::_new()
{
	return (CapsuleMesh *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"CapsuleMesh")());
}
void CapsuleMesh::set_radius(const double radius) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CapsuleMesh", "set_radius");
	}
	___godot_icall_void_float(mb, (const Object *) this, radius);
}

double CapsuleMesh::get_radius() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CapsuleMesh", "get_radius");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void CapsuleMesh::set_mid_height(const double mid_height) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CapsuleMesh", "set_mid_height");
	}
	___godot_icall_void_float(mb, (const Object *) this, mid_height);
}

double CapsuleMesh::get_mid_height() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CapsuleMesh", "get_mid_height");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void CapsuleMesh::set_radial_segments(const int64_t segments) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CapsuleMesh", "set_radial_segments");
	}
	___godot_icall_void_int(mb, (const Object *) this, segments);
}

int64_t CapsuleMesh::get_radial_segments() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CapsuleMesh", "get_radial_segments");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void CapsuleMesh::set_rings(const int64_t rings) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CapsuleMesh", "set_rings");
	}
	___godot_icall_void_int(mb, (const Object *) this, rings);
}

int64_t CapsuleMesh::get_rings() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CapsuleMesh", "get_rings");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

}