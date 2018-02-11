#include <ArrayMesh.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Material.hpp>


namespace godot {


void *ArrayMesh::___get_type_tag()
{
	return (void *) &ArrayMesh::___get_type_tag;
}

void *ArrayMesh::___get_base_type_tag()
{
	return (void *) &Mesh::___get_type_tag;
}

ArrayMesh *ArrayMesh::_new()
{
	return (ArrayMesh *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"ArrayMesh")());
}
void ArrayMesh::add_blend_shape(const String name) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ArrayMesh", "add_blend_shape");
	}
	___godot_icall_void_String(mb, (const Object *) this, name);
}

int64_t ArrayMesh::get_blend_shape_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ArrayMesh", "get_blend_shape_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

String ArrayMesh::get_blend_shape_name(const int64_t index) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ArrayMesh", "get_blend_shape_name");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, index);
}

void ArrayMesh::clear_blend_shapes() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ArrayMesh", "clear_blend_shapes");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void ArrayMesh::set_blend_shape_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ArrayMesh", "set_blend_shape_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

Mesh::BlendShapeMode ArrayMesh::get_blend_shape_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ArrayMesh", "get_blend_shape_mode");
	}
	return (Mesh::BlendShapeMode) ___godot_icall_int(mb, (const Object *) this);
}

void ArrayMesh::add_surface_from_arrays(const int64_t primitive, const Array arrays, const Array blend_shapes, const int64_t compress_flags) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ArrayMesh", "add_surface_from_arrays");
	}
	___godot_icall_void_int_Array_Array_int(mb, (const Object *) this, primitive, arrays, blend_shapes, compress_flags);
}

int64_t ArrayMesh::get_surface_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ArrayMesh", "get_surface_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void ArrayMesh::surface_remove(const int64_t surf_idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ArrayMesh", "surface_remove");
	}
	___godot_icall_void_int(mb, (const Object *) this, surf_idx);
}

void ArrayMesh::surface_update_region(const int64_t surf_idx, const int64_t offset, const PoolByteArray data) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ArrayMesh", "surface_update_region");
	}
	___godot_icall_void_int_int_PoolByteArray(mb, (const Object *) this, surf_idx, offset, data);
}

int64_t ArrayMesh::surface_get_array_len(const int64_t surf_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ArrayMesh", "surface_get_array_len");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, surf_idx);
}

int64_t ArrayMesh::surface_get_array_index_len(const int64_t surf_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ArrayMesh", "surface_get_array_index_len");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, surf_idx);
}

int64_t ArrayMesh::surface_get_format(const int64_t surf_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ArrayMesh", "surface_get_format");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, surf_idx);
}

Mesh::PrimitiveType ArrayMesh::surface_get_primitive_type(const int64_t surf_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ArrayMesh", "surface_get_primitive_type");
	}
	return (Mesh::PrimitiveType) ___godot_icall_int_int(mb, (const Object *) this, surf_idx);
}

void ArrayMesh::surface_set_material(const int64_t surf_idx, const Ref<Material> material) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ArrayMesh", "surface_set_material");
	}
	___godot_icall_void_int_Object(mb, (const Object *) this, surf_idx, material.ptr());
}

Ref<Material> ArrayMesh::surface_get_material(const int64_t surf_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ArrayMesh", "surface_get_material");
	}
	return Ref<Material>::__internal_constructor(___godot_icall_Object_int(mb, (const Object *) this, surf_idx));
}

void ArrayMesh::surface_set_name(const int64_t surf_idx, const String name) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ArrayMesh", "surface_set_name");
	}
	___godot_icall_void_int_String(mb, (const Object *) this, surf_idx, name);
}

String ArrayMesh::surface_get_name(const int64_t surf_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ArrayMesh", "surface_get_name");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, surf_idx);
}

Array ArrayMesh::surface_get_arrays(const int64_t surf_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ArrayMesh", "surface_get_arrays");
	}
	return ___godot_icall_Array_int(mb, (const Object *) this, surf_idx);
}

Array ArrayMesh::surface_get_blend_shape_arrays(const int64_t surf_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ArrayMesh", "surface_get_blend_shape_arrays");
	}
	return ___godot_icall_Array_int(mb, (const Object *) this, surf_idx);
}

void ArrayMesh::center_geometry() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ArrayMesh", "center_geometry");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void ArrayMesh::regen_normalmaps() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ArrayMesh", "regen_normalmaps");
	}
	___godot_icall_void(mb, (const Object *) this);
}

Error ArrayMesh::lightmap_unwrap(const Transform arg0, const double arg1) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ArrayMesh", "lightmap_unwrap");
	}
	return (Error) ___godot_icall_int_Transform_float(mb, (const Object *) this, arg0, arg1);
}

void ArrayMesh::set_custom_aabb(const AABB aabb) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ArrayMesh", "set_custom_aabb");
	}
	___godot_icall_void_AABB(mb, (const Object *) this, aabb);
}

AABB ArrayMesh::get_custom_aabb() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ArrayMesh", "get_custom_aabb");
	}
	return ___godot_icall_AABB(mb, (const Object *) this);
}

}