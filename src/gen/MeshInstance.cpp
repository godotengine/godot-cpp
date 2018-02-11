#include <MeshInstance.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Mesh.hpp>
#include <Material.hpp>


namespace godot {


void *MeshInstance::___get_type_tag()
{
	return (void *) &MeshInstance::___get_type_tag;
}

void *MeshInstance::___get_base_type_tag()
{
	return (void *) &GeometryInstance::___get_type_tag;
}

MeshInstance *MeshInstance::_new()
{
	return (MeshInstance *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"MeshInstance")());
}
void MeshInstance::set_mesh(const Ref<Mesh> mesh) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshInstance", "set_mesh");
	}
	___godot_icall_void_Object(mb, (const Object *) this, mesh.ptr());
}

Ref<Mesh> MeshInstance::get_mesh() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshInstance", "get_mesh");
	}
	return Ref<Mesh>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void MeshInstance::set_skeleton_path(const NodePath skeleton_path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshInstance", "set_skeleton_path");
	}
	___godot_icall_void_NodePath(mb, (const Object *) this, skeleton_path);
}

NodePath MeshInstance::get_skeleton_path() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshInstance", "get_skeleton_path");
	}
	return ___godot_icall_NodePath(mb, (const Object *) this);
}

void MeshInstance::set_surface_material(const int64_t surface, const Ref<Material> material) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshInstance", "set_surface_material");
	}
	___godot_icall_void_int_Object(mb, (const Object *) this, surface, material.ptr());
}

Ref<Material> MeshInstance::get_surface_material(const int64_t surface) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshInstance", "get_surface_material");
	}
	return Ref<Material>::__internal_constructor(___godot_icall_Object_int(mb, (const Object *) this, surface));
}

void MeshInstance::create_trimesh_collision() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshInstance", "create_trimesh_collision");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void MeshInstance::create_convex_collision() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshInstance", "create_convex_collision");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void MeshInstance::_mesh_changed() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshInstance", "_mesh_changed");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void MeshInstance::create_debug_tangents() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshInstance", "create_debug_tangents");
	}
	___godot_icall_void(mb, (const Object *) this);
}

}