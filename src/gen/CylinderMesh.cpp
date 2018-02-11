#include <CylinderMesh.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *CylinderMesh::___get_type_tag()
{
	return (void *) &CylinderMesh::___get_type_tag;
}

void *CylinderMesh::___get_base_type_tag()
{
	return (void *) &PrimitiveMesh::___get_type_tag;
}

CylinderMesh *CylinderMesh::_new()
{
	return (CylinderMesh *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"CylinderMesh")());
}
void CylinderMesh::set_top_radius(const double radius) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CylinderMesh", "set_top_radius");
	}
	___godot_icall_void_float(mb, (const Object *) this, radius);
}

double CylinderMesh::get_top_radius() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CylinderMesh", "get_top_radius");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void CylinderMesh::set_bottom_radius(const double radius) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CylinderMesh", "set_bottom_radius");
	}
	___godot_icall_void_float(mb, (const Object *) this, radius);
}

double CylinderMesh::get_bottom_radius() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CylinderMesh", "get_bottom_radius");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void CylinderMesh::set_height(const double height) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CylinderMesh", "set_height");
	}
	___godot_icall_void_float(mb, (const Object *) this, height);
}

double CylinderMesh::get_height() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CylinderMesh", "get_height");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void CylinderMesh::set_radial_segments(const int64_t segments) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CylinderMesh", "set_radial_segments");
	}
	___godot_icall_void_int(mb, (const Object *) this, segments);
}

int64_t CylinderMesh::get_radial_segments() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CylinderMesh", "get_radial_segments");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void CylinderMesh::set_rings(const int64_t rings) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CylinderMesh", "set_rings");
	}
	___godot_icall_void_int(mb, (const Object *) this, rings);
}

int64_t CylinderMesh::get_rings() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CylinderMesh", "get_rings");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

}