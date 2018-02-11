#include <PlaneMesh.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *PlaneMesh::___get_type_tag()
{
	return (void *) &PlaneMesh::___get_type_tag;
}

void *PlaneMesh::___get_base_type_tag()
{
	return (void *) &PrimitiveMesh::___get_type_tag;
}

PlaneMesh *PlaneMesh::_new()
{
	return (PlaneMesh *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"PlaneMesh")());
}
void PlaneMesh::set_size(const Vector2 size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PlaneMesh", "set_size");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, size);
}

Vector2 PlaneMesh::get_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PlaneMesh", "get_size");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void PlaneMesh::set_subdivide_width(const int64_t subdivide) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PlaneMesh", "set_subdivide_width");
	}
	___godot_icall_void_int(mb, (const Object *) this, subdivide);
}

int64_t PlaneMesh::get_subdivide_width() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PlaneMesh", "get_subdivide_width");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void PlaneMesh::set_subdivide_depth(const int64_t subdivide) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PlaneMesh", "set_subdivide_depth");
	}
	___godot_icall_void_int(mb, (const Object *) this, subdivide);
}

int64_t PlaneMesh::get_subdivide_depth() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PlaneMesh", "get_subdivide_depth");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

}