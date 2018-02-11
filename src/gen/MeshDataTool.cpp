#include <MeshDataTool.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <ArrayMesh.hpp>
#include <Material.hpp>


namespace godot {


void *MeshDataTool::___get_type_tag()
{
	return (void *) &MeshDataTool::___get_type_tag;
}

void *MeshDataTool::___get_base_type_tag()
{
	return (void *) &Reference::___get_type_tag;
}

MeshDataTool *MeshDataTool::_new()
{
	return (MeshDataTool *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"MeshDataTool")());
}
void MeshDataTool::clear() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshDataTool", "clear");
	}
	___godot_icall_void(mb, (const Object *) this);
}

Error MeshDataTool::create_from_surface(const Ref<ArrayMesh> mesh, const int64_t surface) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshDataTool", "create_from_surface");
	}
	return (Error) ___godot_icall_int_Object_int(mb, (const Object *) this, mesh.ptr(), surface);
}

Error MeshDataTool::commit_to_surface(const Ref<ArrayMesh> mesh) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshDataTool", "commit_to_surface");
	}
	return (Error) ___godot_icall_int_Object(mb, (const Object *) this, mesh.ptr());
}

int64_t MeshDataTool::get_format() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshDataTool", "get_format");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t MeshDataTool::get_vertex_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshDataTool", "get_vertex_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t MeshDataTool::get_edge_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshDataTool", "get_edge_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t MeshDataTool::get_face_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshDataTool", "get_face_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void MeshDataTool::set_vertex(const int64_t idx, const Vector3 vertex) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshDataTool", "set_vertex");
	}
	___godot_icall_void_int_Vector3(mb, (const Object *) this, idx, vertex);
}

Vector3 MeshDataTool::get_vertex(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshDataTool", "get_vertex");
	}
	return ___godot_icall_Vector3_int(mb, (const Object *) this, idx);
}

void MeshDataTool::set_vertex_normal(const int64_t idx, const Vector3 normal) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshDataTool", "set_vertex_normal");
	}
	___godot_icall_void_int_Vector3(mb, (const Object *) this, idx, normal);
}

Vector3 MeshDataTool::get_vertex_normal(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshDataTool", "get_vertex_normal");
	}
	return ___godot_icall_Vector3_int(mb, (const Object *) this, idx);
}

void MeshDataTool::set_vertex_tangent(const int64_t idx, const Plane tangent) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshDataTool", "set_vertex_tangent");
	}
	___godot_icall_void_int_Plane(mb, (const Object *) this, idx, tangent);
}

Plane MeshDataTool::get_vertex_tangent(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshDataTool", "get_vertex_tangent");
	}
	return ___godot_icall_Plane_int(mb, (const Object *) this, idx);
}

void MeshDataTool::set_vertex_uv(const int64_t idx, const Vector2 uv) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshDataTool", "set_vertex_uv");
	}
	___godot_icall_void_int_Vector2(mb, (const Object *) this, idx, uv);
}

Vector2 MeshDataTool::get_vertex_uv(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshDataTool", "get_vertex_uv");
	}
	return ___godot_icall_Vector2_int(mb, (const Object *) this, idx);
}

void MeshDataTool::set_vertex_uv2(const int64_t idx, const Vector2 uv2) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshDataTool", "set_vertex_uv2");
	}
	___godot_icall_void_int_Vector2(mb, (const Object *) this, idx, uv2);
}

Vector2 MeshDataTool::get_vertex_uv2(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshDataTool", "get_vertex_uv2");
	}
	return ___godot_icall_Vector2_int(mb, (const Object *) this, idx);
}

void MeshDataTool::set_vertex_color(const int64_t idx, const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshDataTool", "set_vertex_color");
	}
	___godot_icall_void_int_Color(mb, (const Object *) this, idx, color);
}

Color MeshDataTool::get_vertex_color(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshDataTool", "get_vertex_color");
	}
	return ___godot_icall_Color_int(mb, (const Object *) this, idx);
}

void MeshDataTool::set_vertex_bones(const int64_t idx, const PoolIntArray bones) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshDataTool", "set_vertex_bones");
	}
	___godot_icall_void_int_PoolIntArray(mb, (const Object *) this, idx, bones);
}

PoolIntArray MeshDataTool::get_vertex_bones(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshDataTool", "get_vertex_bones");
	}
	return ___godot_icall_PoolIntArray_int(mb, (const Object *) this, idx);
}

void MeshDataTool::set_vertex_weights(const int64_t idx, const PoolRealArray weights) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshDataTool", "set_vertex_weights");
	}
	___godot_icall_void_int_PoolRealArray(mb, (const Object *) this, idx, weights);
}

PoolRealArray MeshDataTool::get_vertex_weights(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshDataTool", "get_vertex_weights");
	}
	return ___godot_icall_PoolRealArray_int(mb, (const Object *) this, idx);
}

void MeshDataTool::set_vertex_meta(const int64_t idx, const Variant meta) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshDataTool", "set_vertex_meta");
	}
	___godot_icall_void_int_Variant(mb, (const Object *) this, idx, meta);
}

Variant MeshDataTool::get_vertex_meta(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshDataTool", "get_vertex_meta");
	}
	return ___godot_icall_Variant_int(mb, (const Object *) this, idx);
}

PoolIntArray MeshDataTool::get_vertex_edges(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshDataTool", "get_vertex_edges");
	}
	return ___godot_icall_PoolIntArray_int(mb, (const Object *) this, idx);
}

PoolIntArray MeshDataTool::get_vertex_faces(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshDataTool", "get_vertex_faces");
	}
	return ___godot_icall_PoolIntArray_int(mb, (const Object *) this, idx);
}

int64_t MeshDataTool::get_edge_vertex(const int64_t idx, const int64_t vertex) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshDataTool", "get_edge_vertex");
	}
	return ___godot_icall_int_int_int(mb, (const Object *) this, idx, vertex);
}

PoolIntArray MeshDataTool::get_edge_faces(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshDataTool", "get_edge_faces");
	}
	return ___godot_icall_PoolIntArray_int(mb, (const Object *) this, idx);
}

void MeshDataTool::set_edge_meta(const int64_t idx, const Variant meta) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshDataTool", "set_edge_meta");
	}
	___godot_icall_void_int_Variant(mb, (const Object *) this, idx, meta);
}

Variant MeshDataTool::get_edge_meta(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshDataTool", "get_edge_meta");
	}
	return ___godot_icall_Variant_int(mb, (const Object *) this, idx);
}

int64_t MeshDataTool::get_face_vertex(const int64_t idx, const int64_t vertex) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshDataTool", "get_face_vertex");
	}
	return ___godot_icall_int_int_int(mb, (const Object *) this, idx, vertex);
}

int64_t MeshDataTool::get_face_edge(const int64_t idx, const int64_t edge) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshDataTool", "get_face_edge");
	}
	return ___godot_icall_int_int_int(mb, (const Object *) this, idx, edge);
}

void MeshDataTool::set_face_meta(const int64_t idx, const Variant meta) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshDataTool", "set_face_meta");
	}
	___godot_icall_void_int_Variant(mb, (const Object *) this, idx, meta);
}

Variant MeshDataTool::get_face_meta(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshDataTool", "get_face_meta");
	}
	return ___godot_icall_Variant_int(mb, (const Object *) this, idx);
}

Vector3 MeshDataTool::get_face_normal(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshDataTool", "get_face_normal");
	}
	return ___godot_icall_Vector3_int(mb, (const Object *) this, idx);
}

void MeshDataTool::set_material(const Ref<Material> material) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshDataTool", "set_material");
	}
	___godot_icall_void_Object(mb, (const Object *) this, material.ptr());
}

Ref<Material> MeshDataTool::get_material() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshDataTool", "get_material");
	}
	return Ref<Material>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

}