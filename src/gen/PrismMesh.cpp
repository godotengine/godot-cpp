#include <PrismMesh.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *PrismMesh::___get_type_tag()
{
	return (void *) &PrismMesh::___get_type_tag;
}

void *PrismMesh::___get_base_type_tag()
{
	return (void *) &PrimitiveMesh::___get_type_tag;
}

PrismMesh *PrismMesh::_new()
{
	return (PrismMesh *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"PrismMesh")());
}
void PrismMesh::set_left_to_right(const double left_to_right) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PrismMesh", "set_left_to_right");
	}
	___godot_icall_void_float(mb, (const Object *) this, left_to_right);
}

double PrismMesh::get_left_to_right() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PrismMesh", "get_left_to_right");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void PrismMesh::set_size(const Vector3 size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PrismMesh", "set_size");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, size);
}

Vector3 PrismMesh::get_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PrismMesh", "get_size");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

void PrismMesh::set_subdivide_width(const int64_t segments) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PrismMesh", "set_subdivide_width");
	}
	___godot_icall_void_int(mb, (const Object *) this, segments);
}

int64_t PrismMesh::get_subdivide_width() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PrismMesh", "get_subdivide_width");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void PrismMesh::set_subdivide_height(const int64_t segments) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PrismMesh", "set_subdivide_height");
	}
	___godot_icall_void_int(mb, (const Object *) this, segments);
}

int64_t PrismMesh::get_subdivide_height() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PrismMesh", "get_subdivide_height");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void PrismMesh::set_subdivide_depth(const int64_t segments) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PrismMesh", "set_subdivide_depth");
	}
	___godot_icall_void_int(mb, (const Object *) this, segments);
}

int64_t PrismMesh::get_subdivide_depth() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PrismMesh", "get_subdivide_depth");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

}