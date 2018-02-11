#include <CubeMesh.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *CubeMesh::___get_type_tag()
{
	return (void *) &CubeMesh::___get_type_tag;
}

void *CubeMesh::___get_base_type_tag()
{
	return (void *) &PrimitiveMesh::___get_type_tag;
}

CubeMesh *CubeMesh::_new()
{
	return (CubeMesh *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"CubeMesh")());
}
void CubeMesh::set_size(const Vector3 size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CubeMesh", "set_size");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, size);
}

Vector3 CubeMesh::get_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CubeMesh", "get_size");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

void CubeMesh::set_subdivide_width(const int64_t subdivide) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CubeMesh", "set_subdivide_width");
	}
	___godot_icall_void_int(mb, (const Object *) this, subdivide);
}

int64_t CubeMesh::get_subdivide_width() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CubeMesh", "get_subdivide_width");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void CubeMesh::set_subdivide_height(const int64_t divisions) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CubeMesh", "set_subdivide_height");
	}
	___godot_icall_void_int(mb, (const Object *) this, divisions);
}

int64_t CubeMesh::get_subdivide_height() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CubeMesh", "get_subdivide_height");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void CubeMesh::set_subdivide_depth(const int64_t divisions) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CubeMesh", "set_subdivide_depth");
	}
	___godot_icall_void_int(mb, (const Object *) this, divisions);
}

int64_t CubeMesh::get_subdivide_depth() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CubeMesh", "get_subdivide_depth");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

}