#include <SurfaceTool.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Material.hpp>
#include <Mesh.hpp>
#include <ArrayMesh.hpp>


namespace godot {


void *SurfaceTool::___get_type_tag()
{
	return (void *) &SurfaceTool::___get_type_tag;
}

void *SurfaceTool::___get_base_type_tag()
{
	return (void *) &Reference::___get_type_tag;
}

SurfaceTool *SurfaceTool::_new()
{
	return (SurfaceTool *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"SurfaceTool")());
}
void SurfaceTool::begin(const int64_t primitive) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SurfaceTool", "begin");
	}
	___godot_icall_void_int(mb, (const Object *) this, primitive);
}

void SurfaceTool::add_vertex(const Vector3 vertex) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SurfaceTool", "add_vertex");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, vertex);
}

void SurfaceTool::add_color(const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SurfaceTool", "add_color");
	}
	___godot_icall_void_Color(mb, (const Object *) this, color);
}

void SurfaceTool::add_normal(const Vector3 normal) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SurfaceTool", "add_normal");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, normal);
}

void SurfaceTool::add_tangent(const Plane tangent) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SurfaceTool", "add_tangent");
	}
	___godot_icall_void_Plane(mb, (const Object *) this, tangent);
}

void SurfaceTool::add_uv(const Vector2 uv) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SurfaceTool", "add_uv");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, uv);
}

void SurfaceTool::add_uv2(const Vector2 uv2) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SurfaceTool", "add_uv2");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, uv2);
}

void SurfaceTool::add_bones(const PoolIntArray bones) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SurfaceTool", "add_bones");
	}
	___godot_icall_void_PoolIntArray(mb, (const Object *) this, bones);
}

void SurfaceTool::add_weights(const PoolRealArray weights) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SurfaceTool", "add_weights");
	}
	___godot_icall_void_PoolRealArray(mb, (const Object *) this, weights);
}

void SurfaceTool::add_smooth_group(const bool smooth) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SurfaceTool", "add_smooth_group");
	}
	___godot_icall_void_bool(mb, (const Object *) this, smooth);
}

void SurfaceTool::add_triangle_fan(const PoolVector3Array vertexes, const PoolVector2Array uvs, const PoolColorArray colors, const PoolVector2Array uv2s, const PoolVector3Array normals, const Array tangents) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SurfaceTool", "add_triangle_fan");
	}
	___godot_icall_void_PoolVector3Array_PoolVector2Array_PoolColorArray_PoolVector2Array_PoolVector3Array_Array(mb, (const Object *) this, vertexes, uvs, colors, uv2s, normals, tangents);
}

void SurfaceTool::add_index(const int64_t index) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SurfaceTool", "add_index");
	}
	___godot_icall_void_int(mb, (const Object *) this, index);
}

void SurfaceTool::index() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SurfaceTool", "index");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void SurfaceTool::deindex() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SurfaceTool", "deindex");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void SurfaceTool::generate_normals() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SurfaceTool", "generate_normals");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void SurfaceTool::generate_tangents() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SurfaceTool", "generate_tangents");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void SurfaceTool::add_to_format(const int64_t flags) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SurfaceTool", "add_to_format");
	}
	___godot_icall_void_int(mb, (const Object *) this, flags);
}

void SurfaceTool::set_material(const Ref<Material> material) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SurfaceTool", "set_material");
	}
	___godot_icall_void_Object(mb, (const Object *) this, material.ptr());
}

void SurfaceTool::clear() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SurfaceTool", "clear");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void SurfaceTool::create_from(const Ref<Mesh> existing, const int64_t surface) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SurfaceTool", "create_from");
	}
	___godot_icall_void_Object_int(mb, (const Object *) this, existing.ptr(), surface);
}

void SurfaceTool::append_from(const Ref<Mesh> existing, const int64_t surface, const Transform transform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SurfaceTool", "append_from");
	}
	___godot_icall_void_Object_int_Transform(mb, (const Object *) this, existing.ptr(), surface, transform);
}

Ref<ArrayMesh> SurfaceTool::commit(const Ref<ArrayMesh> existing, const int64_t flags) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SurfaceTool", "commit");
	}
	return Ref<ArrayMesh>::__internal_constructor(___godot_icall_Object_Object_int(mb, (const Object *) this, existing.ptr(), flags));
}

}