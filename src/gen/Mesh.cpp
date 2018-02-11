#include <Mesh.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Shape.hpp>
#include <Mesh.hpp>
#include <TriangleMesh.hpp>


namespace godot {


void *Mesh::___get_type_tag()
{
	return (void *) &Mesh::___get_type_tag;
}

void *Mesh::___get_base_type_tag()
{
	return (void *) &Resource::___get_type_tag;
}

void Mesh::set_lightmap_size_hint(const Vector2 size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Mesh", "set_lightmap_size_hint");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, size);
}

Vector2 Mesh::get_lightmap_size_hint() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Mesh", "get_lightmap_size_hint");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

Ref<Shape> Mesh::create_trimesh_shape() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Mesh", "create_trimesh_shape");
	}
	return Ref<Shape>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

Ref<Shape> Mesh::create_convex_shape() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Mesh", "create_convex_shape");
	}
	return Ref<Shape>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

Ref<Mesh> Mesh::create_outline(const double margin) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Mesh", "create_outline");
	}
	return Ref<Mesh>::__internal_constructor(___godot_icall_Object_float(mb, (const Object *) this, margin));
}

PoolVector3Array Mesh::get_faces() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Mesh", "get_faces");
	}
	return ___godot_icall_PoolVector3Array(mb, (const Object *) this);
}

Ref<TriangleMesh> Mesh::generate_triangle_mesh() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Mesh", "generate_triangle_mesh");
	}
	return Ref<TriangleMesh>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

}