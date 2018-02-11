#include <PrimitiveMesh.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Material.hpp>


namespace godot {


void *PrimitiveMesh::___get_type_tag()
{
	return (void *) &PrimitiveMesh::___get_type_tag;
}

void *PrimitiveMesh::___get_base_type_tag()
{
	return (void *) &Mesh::___get_type_tag;
}

void PrimitiveMesh::_update() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PrimitiveMesh", "_update");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void PrimitiveMesh::set_material(const Ref<Material> material) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PrimitiveMesh", "set_material");
	}
	___godot_icall_void_Object(mb, (const Object *) this, material.ptr());
}

Ref<Material> PrimitiveMesh::get_material() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PrimitiveMesh", "get_material");
	}
	return Ref<Material>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

Array PrimitiveMesh::get_mesh_arrays() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PrimitiveMesh", "get_mesh_arrays");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

}