#include <VisualServer.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Image.hpp>
#include <Object.hpp>


namespace godot {


void *VisualServer::___get_type_tag()
{
	return (void *) &VisualServer::___get_type_tag;
}

void *VisualServer::___get_base_type_tag()
{
	return (void *) &Object::___get_type_tag;
}

VisualServer *VisualServer::_singleton = NULL;


VisualServer::VisualServer() {
	_owner = godot::api->godot_global_get_singleton((char *) "VisualServer");
}


void VisualServer::force_sync() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "force_sync");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void VisualServer::force_draw(const bool swap_buffers) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "force_draw");
	}
	___godot_icall_void_bool(mb, (const Object *) this, swap_buffers);
}

void VisualServer::sync() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "sync");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void VisualServer::draw(const bool swap_buffers) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "draw");
	}
	___godot_icall_void_bool(mb, (const Object *) this, swap_buffers);
}

RID VisualServer::texture_create() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "texture_create");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

RID VisualServer::texture_create_from_image(const Ref<Image> image, const int64_t flags) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "texture_create_from_image");
	}
	return ___godot_icall_RID_Object_int(mb, (const Object *) this, image.ptr(), flags);
}

void VisualServer::texture_allocate(const RID texture, const int64_t width, const int64_t height, const int64_t format, const int64_t flags) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "texture_allocate");
	}
	___godot_icall_void_RID_int_int_int_int(mb, (const Object *) this, texture, width, height, format, flags);
}

void VisualServer::texture_set_data(const RID texture, const Ref<Image> image, const int64_t cube_side) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "texture_set_data");
	}
	___godot_icall_void_RID_Object_int(mb, (const Object *) this, texture, image.ptr(), cube_side);
}

Ref<Image> VisualServer::texture_get_data(const RID texture, const int64_t cube_side) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "texture_get_data");
	}
	return Ref<Image>::__internal_constructor(___godot_icall_Object_RID_int(mb, (const Object *) this, texture, cube_side));
}

void VisualServer::texture_set_flags(const RID texture, const int64_t flags) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "texture_set_flags");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, texture, flags);
}

int64_t VisualServer::texture_get_flags(const RID texture) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "texture_get_flags");
	}
	return ___godot_icall_int_RID(mb, (const Object *) this, texture);
}

Image::Format VisualServer::texture_get_format(const RID texture) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "texture_get_format");
	}
	return (Image::Format) ___godot_icall_int_RID(mb, (const Object *) this, texture);
}

int64_t VisualServer::texture_get_texid(const RID texture) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "texture_get_texid");
	}
	return ___godot_icall_int_RID(mb, (const Object *) this, texture);
}

int64_t VisualServer::texture_get_width(const RID texture) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "texture_get_width");
	}
	return ___godot_icall_int_RID(mb, (const Object *) this, texture);
}

int64_t VisualServer::texture_get_height(const RID texture) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "texture_get_height");
	}
	return ___godot_icall_int_RID(mb, (const Object *) this, texture);
}

void VisualServer::texture_set_size_override(const RID texture, const int64_t width, const int64_t height) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "texture_set_size_override");
	}
	___godot_icall_void_RID_int_int(mb, (const Object *) this, texture, width, height);
}

void VisualServer::texture_set_path(const RID texture, const String path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "texture_set_path");
	}
	___godot_icall_void_RID_String(mb, (const Object *) this, texture, path);
}

String VisualServer::texture_get_path(const RID texture) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "texture_get_path");
	}
	return ___godot_icall_String_RID(mb, (const Object *) this, texture);
}

void VisualServer::texture_set_shrink_all_x2_on_set_data(const bool shrink) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "texture_set_shrink_all_x2_on_set_data");
	}
	___godot_icall_void_bool(mb, (const Object *) this, shrink);
}

Array VisualServer::texture_debug_usage() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "texture_debug_usage");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

void VisualServer::textures_keep_original(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "textures_keep_original");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

RID VisualServer::sky_create() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "sky_create");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

void VisualServer::sky_set_texture(const RID sky, const RID cube_map, const int64_t radiance_size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "sky_set_texture");
	}
	___godot_icall_void_RID_RID_int(mb, (const Object *) this, sky, cube_map, radiance_size);
}

RID VisualServer::shader_create() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "shader_create");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

void VisualServer::shader_set_code(const RID shader, const String code) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "shader_set_code");
	}
	___godot_icall_void_RID_String(mb, (const Object *) this, shader, code);
}

String VisualServer::shader_get_code(const RID shader) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "shader_get_code");
	}
	return ___godot_icall_String_RID(mb, (const Object *) this, shader);
}

Array VisualServer::shader_get_param_list(const RID shader) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "shader_get_param_list");
	}
	return ___godot_icall_Array_RID(mb, (const Object *) this, shader);
}

void VisualServer::shader_set_default_texture_param(const RID shader, const String name, const RID texture) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "shader_set_default_texture_param");
	}
	___godot_icall_void_RID_String_RID(mb, (const Object *) this, shader, name, texture);
}

RID VisualServer::shader_get_default_texture_param(const RID shader, const String name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "shader_get_default_texture_param");
	}
	return ___godot_icall_RID_RID_String(mb, (const Object *) this, shader, name);
}

RID VisualServer::material_create() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "material_create");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

void VisualServer::material_set_shader(const RID shader_material, const RID shader) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "material_set_shader");
	}
	___godot_icall_void_RID_RID(mb, (const Object *) this, shader_material, shader);
}

RID VisualServer::material_get_shader(const RID shader_material) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "material_get_shader");
	}
	return ___godot_icall_RID_RID(mb, (const Object *) this, shader_material);
}

void VisualServer::material_set_param(const RID material, const String parameter, const Variant value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "material_set_param");
	}
	___godot_icall_void_RID_String_Variant(mb, (const Object *) this, material, parameter, value);
}

Variant VisualServer::material_get_param(const RID material, const String parameter) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "material_get_param");
	}
	return ___godot_icall_Variant_RID_String(mb, (const Object *) this, material, parameter);
}

void VisualServer::material_set_render_priority(const RID material, const int64_t priority) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "material_set_render_priority");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, material, priority);
}

void VisualServer::material_set_line_width(const RID material, const double width) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "material_set_line_width");
	}
	___godot_icall_void_RID_float(mb, (const Object *) this, material, width);
}

void VisualServer::material_set_next_pass(const RID material, const RID next_material) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "material_set_next_pass");
	}
	___godot_icall_void_RID_RID(mb, (const Object *) this, material, next_material);
}

RID VisualServer::mesh_create() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "mesh_create");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

void VisualServer::mesh_add_surface_from_arrays(const RID mesh, const int64_t primtive, const Array arrays, const Array blend_shapes, const int64_t compress_format) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "mesh_add_surface_from_arrays");
	}
	___godot_icall_void_RID_int_Array_Array_int(mb, (const Object *) this, mesh, primtive, arrays, blend_shapes, compress_format);
}

void VisualServer::mesh_set_blend_shape_count(const RID mesh, const int64_t amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "mesh_set_blend_shape_count");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, mesh, amount);
}

int64_t VisualServer::mesh_get_blend_shape_count(const RID mesh) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "mesh_get_blend_shape_count");
	}
	return ___godot_icall_int_RID(mb, (const Object *) this, mesh);
}

void VisualServer::mesh_set_blend_shape_mode(const RID mesh, const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "mesh_set_blend_shape_mode");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, mesh, mode);
}

VisualServer::BlendShapeMode VisualServer::mesh_get_blend_shape_mode(const RID mesh) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "mesh_get_blend_shape_mode");
	}
	return (VisualServer::BlendShapeMode) ___godot_icall_int_RID(mb, (const Object *) this, mesh);
}

void VisualServer::mesh_surface_set_material(const RID mesh, const int64_t surface, const RID material) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "mesh_surface_set_material");
	}
	___godot_icall_void_RID_int_RID(mb, (const Object *) this, mesh, surface, material);
}

RID VisualServer::mesh_surface_get_material(const RID mesh, const int64_t surface) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "mesh_surface_get_material");
	}
	return ___godot_icall_RID_RID_int(mb, (const Object *) this, mesh, surface);
}

int64_t VisualServer::mesh_surface_get_array_len(const RID mesh, const int64_t surface) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "mesh_surface_get_array_len");
	}
	return ___godot_icall_int_RID_int(mb, (const Object *) this, mesh, surface);
}

int64_t VisualServer::mesh_surface_get_array_index_len(const RID mesh, const int64_t surface) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "mesh_surface_get_array_index_len");
	}
	return ___godot_icall_int_RID_int(mb, (const Object *) this, mesh, surface);
}

PoolByteArray VisualServer::mesh_surface_get_array(const RID mesh, const int64_t surface) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "mesh_surface_get_array");
	}
	return ___godot_icall_PoolByteArray_RID_int(mb, (const Object *) this, mesh, surface);
}

PoolByteArray VisualServer::mesh_surface_get_index_array(const RID mesh, const int64_t surface) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "mesh_surface_get_index_array");
	}
	return ___godot_icall_PoolByteArray_RID_int(mb, (const Object *) this, mesh, surface);
}

Array VisualServer::mesh_surface_get_arrays(const RID mesh, const int64_t surface) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "mesh_surface_get_arrays");
	}
	return ___godot_icall_Array_RID_int(mb, (const Object *) this, mesh, surface);
}

Array VisualServer::mesh_surface_get_blend_shape_arrays(const RID mesh, const int64_t surface) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "mesh_surface_get_blend_shape_arrays");
	}
	return ___godot_icall_Array_RID_int(mb, (const Object *) this, mesh, surface);
}

int64_t VisualServer::mesh_surface_get_format(const RID mesh, const int64_t surface) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "mesh_surface_get_format");
	}
	return ___godot_icall_int_RID_int(mb, (const Object *) this, mesh, surface);
}

VisualServer::PrimitiveType VisualServer::mesh_surface_get_primitive_type(const RID mesh, const int64_t surface) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "mesh_surface_get_primitive_type");
	}
	return (VisualServer::PrimitiveType) ___godot_icall_int_RID_int(mb, (const Object *) this, mesh, surface);
}

AABB VisualServer::mesh_surface_get_aabb(const RID mesh, const int64_t surface) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "mesh_surface_get_aabb");
	}
	return ___godot_icall_AABB_RID_int(mb, (const Object *) this, mesh, surface);
}

Array VisualServer::mesh_surface_get_skeleton_aabb(const RID mesh, const int64_t surface) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "mesh_surface_get_skeleton_aabb");
	}
	return ___godot_icall_Array_RID_int(mb, (const Object *) this, mesh, surface);
}

void VisualServer::mesh_remove_surface(const RID mesh, const int64_t index) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "mesh_remove_surface");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, mesh, index);
}

int64_t VisualServer::mesh_get_surface_count(const RID mesh) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "mesh_get_surface_count");
	}
	return ___godot_icall_int_RID(mb, (const Object *) this, mesh);
}

void VisualServer::mesh_set_custom_aabb(const RID mesh, const AABB aabb) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "mesh_set_custom_aabb");
	}
	___godot_icall_void_RID_AABB(mb, (const Object *) this, mesh, aabb);
}

AABB VisualServer::mesh_get_custom_aabb(const RID mesh) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "mesh_get_custom_aabb");
	}
	return ___godot_icall_AABB_RID(mb, (const Object *) this, mesh);
}

void VisualServer::mesh_clear(const RID mesh) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "mesh_clear");
	}
	___godot_icall_void_RID(mb, (const Object *) this, mesh);
}

void VisualServer::multimesh_allocate(const RID multimesh, const int64_t instances, const int64_t transform_format, const int64_t color_format) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "multimesh_allocate");
	}
	___godot_icall_void_RID_int_int_int(mb, (const Object *) this, multimesh, instances, transform_format, color_format);
}

int64_t VisualServer::multimesh_get_instance_count(const RID multimesh) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "multimesh_get_instance_count");
	}
	return ___godot_icall_int_RID(mb, (const Object *) this, multimesh);
}

void VisualServer::multimesh_set_mesh(const RID multimesh, const RID mesh) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "multimesh_set_mesh");
	}
	___godot_icall_void_RID_RID(mb, (const Object *) this, multimesh, mesh);
}

void VisualServer::multimesh_instance_set_transform(const RID multimesh, const int64_t index, const Transform transform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "multimesh_instance_set_transform");
	}
	___godot_icall_void_RID_int_Transform(mb, (const Object *) this, multimesh, index, transform);
}

void VisualServer::multimesh_instance_set_transform_2d(const RID multimesh, const int64_t index, const Transform2D transform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "multimesh_instance_set_transform_2d");
	}
	___godot_icall_void_RID_int_Transform2D(mb, (const Object *) this, multimesh, index, transform);
}

void VisualServer::multimesh_instance_set_color(const RID multimesh, const int64_t index, const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "multimesh_instance_set_color");
	}
	___godot_icall_void_RID_int_Color(mb, (const Object *) this, multimesh, index, color);
}

RID VisualServer::multimesh_get_mesh(const RID multimesh) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "multimesh_get_mesh");
	}
	return ___godot_icall_RID_RID(mb, (const Object *) this, multimesh);
}

AABB VisualServer::multimesh_get_aabb(const RID multimesh) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "multimesh_get_aabb");
	}
	return ___godot_icall_AABB_RID(mb, (const Object *) this, multimesh);
}

Transform VisualServer::multimesh_instance_get_transform(const RID multimesh, const int64_t index) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "multimesh_instance_get_transform");
	}
	return ___godot_icall_Transform_RID_int(mb, (const Object *) this, multimesh, index);
}

Transform2D VisualServer::multimesh_instance_get_transform_2d(const RID multimesh, const int64_t index) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "multimesh_instance_get_transform_2d");
	}
	return ___godot_icall_Transform2D_RID_int(mb, (const Object *) this, multimesh, index);
}

Color VisualServer::multimesh_instance_get_color(const RID multimesh, const int64_t index) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "multimesh_instance_get_color");
	}
	return ___godot_icall_Color_RID_int(mb, (const Object *) this, multimesh, index);
}

void VisualServer::multimesh_set_visible_instances(const RID multimesh, const int64_t visible) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "multimesh_set_visible_instances");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, multimesh, visible);
}

int64_t VisualServer::multimesh_get_visible_instances(const RID multimesh) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "multimesh_get_visible_instances");
	}
	return ___godot_icall_int_RID(mb, (const Object *) this, multimesh);
}

RID VisualServer::immediate_create() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "immediate_create");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

void VisualServer::immediate_begin(const RID immediate, const int64_t primitive, const RID texture) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "immediate_begin");
	}
	___godot_icall_void_RID_int_RID(mb, (const Object *) this, immediate, primitive, texture);
}

void VisualServer::immediate_vertex(const RID immediate, const Vector3 vertex) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "immediate_vertex");
	}
	___godot_icall_void_RID_Vector3(mb, (const Object *) this, immediate, vertex);
}

void VisualServer::immediate_vertex_2d(const RID immediate, const Vector2 vertex) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "immediate_vertex_2d");
	}
	___godot_icall_void_RID_Vector2(mb, (const Object *) this, immediate, vertex);
}

void VisualServer::immediate_normal(const RID immediate, const Vector3 normal) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "immediate_normal");
	}
	___godot_icall_void_RID_Vector3(mb, (const Object *) this, immediate, normal);
}

void VisualServer::immediate_tangent(const RID immediate, const Plane tangent) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "immediate_tangent");
	}
	___godot_icall_void_RID_Plane(mb, (const Object *) this, immediate, tangent);
}

void VisualServer::immediate_color(const RID immediate, const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "immediate_color");
	}
	___godot_icall_void_RID_Color(mb, (const Object *) this, immediate, color);
}

void VisualServer::immediate_uv(const RID immediate, const Vector2 tex_uv) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "immediate_uv");
	}
	___godot_icall_void_RID_Vector2(mb, (const Object *) this, immediate, tex_uv);
}

void VisualServer::immediate_uv2(const RID immediate, const Vector2 tex_uv) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "immediate_uv2");
	}
	___godot_icall_void_RID_Vector2(mb, (const Object *) this, immediate, tex_uv);
}

void VisualServer::immediate_end(const RID immediate) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "immediate_end");
	}
	___godot_icall_void_RID(mb, (const Object *) this, immediate);
}

void VisualServer::immediate_clear(const RID immediate) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "immediate_clear");
	}
	___godot_icall_void_RID(mb, (const Object *) this, immediate);
}

void VisualServer::immediate_set_material(const RID immediate, const RID material) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "immediate_set_material");
	}
	___godot_icall_void_RID_RID(mb, (const Object *) this, immediate, material);
}

RID VisualServer::immediate_get_material(const RID immediate) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "immediate_get_material");
	}
	return ___godot_icall_RID_RID(mb, (const Object *) this, immediate);
}

RID VisualServer::skeleton_create() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "skeleton_create");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

void VisualServer::skeleton_allocate(const RID skeleton, const int64_t bones, const bool is_2d_skeleton) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "skeleton_allocate");
	}
	___godot_icall_void_RID_int_bool(mb, (const Object *) this, skeleton, bones, is_2d_skeleton);
}

int64_t VisualServer::skeleton_get_bone_count(const RID skeleton) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "skeleton_get_bone_count");
	}
	return ___godot_icall_int_RID(mb, (const Object *) this, skeleton);
}

void VisualServer::skeleton_bone_set_transform(const RID skeleton, const int64_t bone, const Transform transform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "skeleton_bone_set_transform");
	}
	___godot_icall_void_RID_int_Transform(mb, (const Object *) this, skeleton, bone, transform);
}

Transform VisualServer::skeleton_bone_get_transform(const RID skeleton, const int64_t bone) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "skeleton_bone_get_transform");
	}
	return ___godot_icall_Transform_RID_int(mb, (const Object *) this, skeleton, bone);
}

void VisualServer::skeleton_bone_set_transform_2d(const RID skeleton, const int64_t bone, const Transform2D transform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "skeleton_bone_set_transform_2d");
	}
	___godot_icall_void_RID_int_Transform2D(mb, (const Object *) this, skeleton, bone, transform);
}

Transform2D VisualServer::skeleton_bone_get_transform_2d(const RID skeleton, const int64_t bone) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "skeleton_bone_get_transform_2d");
	}
	return ___godot_icall_Transform2D_RID_int(mb, (const Object *) this, skeleton, bone);
}

RID VisualServer::directional_light_create() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "directional_light_create");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

RID VisualServer::omni_light_create() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "omni_light_create");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

RID VisualServer::spot_light_create() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "spot_light_create");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

void VisualServer::light_set_color(const RID light, const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "light_set_color");
	}
	___godot_icall_void_RID_Color(mb, (const Object *) this, light, color);
}

void VisualServer::light_set_param(const RID light, const int64_t param, const double value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "light_set_param");
	}
	___godot_icall_void_RID_int_float(mb, (const Object *) this, light, param, value);
}

void VisualServer::light_set_shadow(const RID light, const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "light_set_shadow");
	}
	___godot_icall_void_RID_bool(mb, (const Object *) this, light, enabled);
}

void VisualServer::light_set_shadow_color(const RID light, const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "light_set_shadow_color");
	}
	___godot_icall_void_RID_Color(mb, (const Object *) this, light, color);
}

void VisualServer::light_set_projector(const RID light, const RID texture) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "light_set_projector");
	}
	___godot_icall_void_RID_RID(mb, (const Object *) this, light, texture);
}

void VisualServer::light_set_negative(const RID light, const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "light_set_negative");
	}
	___godot_icall_void_RID_bool(mb, (const Object *) this, light, enable);
}

void VisualServer::light_set_cull_mask(const RID light, const int64_t mask) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "light_set_cull_mask");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, light, mask);
}

void VisualServer::light_set_reverse_cull_face_mode(const RID light, const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "light_set_reverse_cull_face_mode");
	}
	___godot_icall_void_RID_bool(mb, (const Object *) this, light, enabled);
}

void VisualServer::light_omni_set_shadow_mode(const RID light, const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "light_omni_set_shadow_mode");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, light, mode);
}

void VisualServer::light_omni_set_shadow_detail(const RID light, const int64_t detail) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "light_omni_set_shadow_detail");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, light, detail);
}

void VisualServer::light_directional_set_shadow_mode(const RID light, const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "light_directional_set_shadow_mode");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, light, mode);
}

void VisualServer::light_directional_set_blend_splits(const RID light, const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "light_directional_set_blend_splits");
	}
	___godot_icall_void_RID_bool(mb, (const Object *) this, light, enable);
}

void VisualServer::light_directional_set_shadow_depth_range_mode(const RID light, const int64_t range_mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "light_directional_set_shadow_depth_range_mode");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, light, range_mode);
}

RID VisualServer::reflection_probe_create() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "reflection_probe_create");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

void VisualServer::reflection_probe_set_update_mode(const RID probe, const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "reflection_probe_set_update_mode");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, probe, mode);
}

void VisualServer::reflection_probe_set_intensity(const RID probe, const double intensity) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "reflection_probe_set_intensity");
	}
	___godot_icall_void_RID_float(mb, (const Object *) this, probe, intensity);
}

void VisualServer::reflection_probe_set_interior_ambient(const RID probe, const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "reflection_probe_set_interior_ambient");
	}
	___godot_icall_void_RID_Color(mb, (const Object *) this, probe, color);
}

void VisualServer::reflection_probe_set_interior_ambient_energy(const RID probe, const double energy) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "reflection_probe_set_interior_ambient_energy");
	}
	___godot_icall_void_RID_float(mb, (const Object *) this, probe, energy);
}

void VisualServer::reflection_probe_set_interior_ambient_probe_contribution(const RID probe, const double contrib) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "reflection_probe_set_interior_ambient_probe_contribution");
	}
	___godot_icall_void_RID_float(mb, (const Object *) this, probe, contrib);
}

void VisualServer::reflection_probe_set_max_distance(const RID probe, const double distance) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "reflection_probe_set_max_distance");
	}
	___godot_icall_void_RID_float(mb, (const Object *) this, probe, distance);
}

void VisualServer::reflection_probe_set_extents(const RID probe, const Vector3 extents) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "reflection_probe_set_extents");
	}
	___godot_icall_void_RID_Vector3(mb, (const Object *) this, probe, extents);
}

void VisualServer::reflection_probe_set_origin_offset(const RID probe, const Vector3 offset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "reflection_probe_set_origin_offset");
	}
	___godot_icall_void_RID_Vector3(mb, (const Object *) this, probe, offset);
}

void VisualServer::reflection_probe_set_as_interior(const RID probe, const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "reflection_probe_set_as_interior");
	}
	___godot_icall_void_RID_bool(mb, (const Object *) this, probe, enable);
}

void VisualServer::reflection_probe_set_enable_box_projection(const RID probe, const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "reflection_probe_set_enable_box_projection");
	}
	___godot_icall_void_RID_bool(mb, (const Object *) this, probe, enable);
}

void VisualServer::reflection_probe_set_enable_shadows(const RID probe, const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "reflection_probe_set_enable_shadows");
	}
	___godot_icall_void_RID_bool(mb, (const Object *) this, probe, enable);
}

void VisualServer::reflection_probe_set_cull_mask(const RID probe, const int64_t layers) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "reflection_probe_set_cull_mask");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, probe, layers);
}

RID VisualServer::gi_probe_create() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "gi_probe_create");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

void VisualServer::gi_probe_set_bounds(const RID probe, const AABB bounds) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "gi_probe_set_bounds");
	}
	___godot_icall_void_RID_AABB(mb, (const Object *) this, probe, bounds);
}

AABB VisualServer::gi_probe_get_bounds(const RID probe) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "gi_probe_get_bounds");
	}
	return ___godot_icall_AABB_RID(mb, (const Object *) this, probe);
}

void VisualServer::gi_probe_set_cell_size(const RID probe, const double range) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "gi_probe_set_cell_size");
	}
	___godot_icall_void_RID_float(mb, (const Object *) this, probe, range);
}

double VisualServer::gi_probe_get_cell_size(const RID probe) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "gi_probe_get_cell_size");
	}
	return ___godot_icall_float_RID(mb, (const Object *) this, probe);
}

void VisualServer::gi_probe_set_to_cell_xform(const RID xform, const Transform arg1) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "gi_probe_set_to_cell_xform");
	}
	___godot_icall_void_RID_Transform(mb, (const Object *) this, xform, arg1);
}

Transform VisualServer::gi_probe_get_to_cell_xform(const RID arg0) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "gi_probe_get_to_cell_xform");
	}
	return ___godot_icall_Transform_RID(mb, (const Object *) this, arg0);
}

void VisualServer::gi_probe_set_dynamic_data(const RID data, const PoolIntArray arg1) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "gi_probe_set_dynamic_data");
	}
	___godot_icall_void_RID_PoolIntArray(mb, (const Object *) this, data, arg1);
}

PoolIntArray VisualServer::gi_probe_get_dynamic_data(const RID arg0) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "gi_probe_get_dynamic_data");
	}
	return ___godot_icall_PoolIntArray_RID(mb, (const Object *) this, arg0);
}

void VisualServer::gi_probe_set_dynamic_range(const RID range, const int64_t arg1) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "gi_probe_set_dynamic_range");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, range, arg1);
}

int64_t VisualServer::gi_probe_get_dynamic_range(const RID arg0) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "gi_probe_get_dynamic_range");
	}
	return ___godot_icall_int_RID(mb, (const Object *) this, arg0);
}

void VisualServer::gi_probe_set_energy(const RID energy, const double arg1) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "gi_probe_set_energy");
	}
	___godot_icall_void_RID_float(mb, (const Object *) this, energy, arg1);
}

double VisualServer::gi_probe_get_energy(const RID arg0) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "gi_probe_get_energy");
	}
	return ___godot_icall_float_RID(mb, (const Object *) this, arg0);
}

void VisualServer::gi_probe_set_bias(const RID bias, const double arg1) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "gi_probe_set_bias");
	}
	___godot_icall_void_RID_float(mb, (const Object *) this, bias, arg1);
}

double VisualServer::gi_probe_get_bias(const RID arg0) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "gi_probe_get_bias");
	}
	return ___godot_icall_float_RID(mb, (const Object *) this, arg0);
}

void VisualServer::gi_probe_set_normal_bias(const RID bias, const double arg1) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "gi_probe_set_normal_bias");
	}
	___godot_icall_void_RID_float(mb, (const Object *) this, bias, arg1);
}

double VisualServer::gi_probe_get_normal_bias(const RID arg0) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "gi_probe_get_normal_bias");
	}
	return ___godot_icall_float_RID(mb, (const Object *) this, arg0);
}

void VisualServer::gi_probe_set_propagation(const RID propagation, const double arg1) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "gi_probe_set_propagation");
	}
	___godot_icall_void_RID_float(mb, (const Object *) this, propagation, arg1);
}

double VisualServer::gi_probe_get_propagation(const RID arg0) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "gi_probe_get_propagation");
	}
	return ___godot_icall_float_RID(mb, (const Object *) this, arg0);
}

void VisualServer::gi_probe_set_interior(const RID enable, const bool arg1) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "gi_probe_set_interior");
	}
	___godot_icall_void_RID_bool(mb, (const Object *) this, enable, arg1);
}

bool VisualServer::gi_probe_is_interior(const RID arg0) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "gi_probe_is_interior");
	}
	return ___godot_icall_bool_RID(mb, (const Object *) this, arg0);
}

void VisualServer::gi_probe_set_compress(const RID enable, const bool arg1) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "gi_probe_set_compress");
	}
	___godot_icall_void_RID_bool(mb, (const Object *) this, enable, arg1);
}

bool VisualServer::gi_probe_is_compressed(const RID arg0) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "gi_probe_is_compressed");
	}
	return ___godot_icall_bool_RID(mb, (const Object *) this, arg0);
}

RID VisualServer::lightmap_capture_create() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "lightmap_capture_create");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

void VisualServer::lightmap_capture_set_bounds(const RID capture, const AABB bounds) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "lightmap_capture_set_bounds");
	}
	___godot_icall_void_RID_AABB(mb, (const Object *) this, capture, bounds);
}

AABB VisualServer::lightmap_capture_get_bounds(const RID capture) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "lightmap_capture_get_bounds");
	}
	return ___godot_icall_AABB_RID(mb, (const Object *) this, capture);
}

void VisualServer::lightmap_capture_set_octree(const RID capture, const PoolByteArray octree) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "lightmap_capture_set_octree");
	}
	___godot_icall_void_RID_PoolByteArray(mb, (const Object *) this, capture, octree);
}

void VisualServer::lightmap_capture_set_octree_cell_transform(const RID capture, const Transform xform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "lightmap_capture_set_octree_cell_transform");
	}
	___godot_icall_void_RID_Transform(mb, (const Object *) this, capture, xform);
}

Transform VisualServer::lightmap_capture_get_octree_cell_transform(const RID capture) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "lightmap_capture_get_octree_cell_transform");
	}
	return ___godot_icall_Transform_RID(mb, (const Object *) this, capture);
}

void VisualServer::lightmap_capture_set_octree_cell_subdiv(const RID capture, const int64_t subdiv) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "lightmap_capture_set_octree_cell_subdiv");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, capture, subdiv);
}

int64_t VisualServer::lightmap_capture_get_octree_cell_subdiv(const RID capture) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "lightmap_capture_get_octree_cell_subdiv");
	}
	return ___godot_icall_int_RID(mb, (const Object *) this, capture);
}

PoolByteArray VisualServer::lightmap_capture_get_octree(const RID capture) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "lightmap_capture_get_octree");
	}
	return ___godot_icall_PoolByteArray_RID(mb, (const Object *) this, capture);
}

void VisualServer::lightmap_capture_set_energy(const RID capture, const double energy) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "lightmap_capture_set_energy");
	}
	___godot_icall_void_RID_float(mb, (const Object *) this, capture, energy);
}

double VisualServer::lightmap_capture_get_energy(const RID capture) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "lightmap_capture_get_energy");
	}
	return ___godot_icall_float_RID(mb, (const Object *) this, capture);
}

RID VisualServer::particles_create() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "particles_create");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

void VisualServer::particles_set_emitting(const RID particles, const bool emitting) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "particles_set_emitting");
	}
	___godot_icall_void_RID_bool(mb, (const Object *) this, particles, emitting);
}

bool VisualServer::particles_get_emitting(const RID particles) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "particles_get_emitting");
	}
	return ___godot_icall_bool_RID(mb, (const Object *) this, particles);
}

void VisualServer::particles_set_amount(const RID particles, const int64_t amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "particles_set_amount");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, particles, amount);
}

void VisualServer::particles_set_lifetime(const RID particles, const double lifetime) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "particles_set_lifetime");
	}
	___godot_icall_void_RID_float(mb, (const Object *) this, particles, lifetime);
}

void VisualServer::particles_set_one_shot(const RID particles, const bool one_shot) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "particles_set_one_shot");
	}
	___godot_icall_void_RID_bool(mb, (const Object *) this, particles, one_shot);
}

void VisualServer::particles_set_pre_process_time(const RID particles, const double time) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "particles_set_pre_process_time");
	}
	___godot_icall_void_RID_float(mb, (const Object *) this, particles, time);
}

void VisualServer::particles_set_explosiveness_ratio(const RID particles, const double ratio) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "particles_set_explosiveness_ratio");
	}
	___godot_icall_void_RID_float(mb, (const Object *) this, particles, ratio);
}

void VisualServer::particles_set_randomness_ratio(const RID particles, const double ratio) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "particles_set_randomness_ratio");
	}
	___godot_icall_void_RID_float(mb, (const Object *) this, particles, ratio);
}

void VisualServer::particles_set_custom_aabb(const RID particles, const AABB aabb) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "particles_set_custom_aabb");
	}
	___godot_icall_void_RID_AABB(mb, (const Object *) this, particles, aabb);
}

void VisualServer::particles_set_speed_scale(const RID particles, const double scale) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "particles_set_speed_scale");
	}
	___godot_icall_void_RID_float(mb, (const Object *) this, particles, scale);
}

void VisualServer::particles_set_use_local_coordinates(const RID particles, const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "particles_set_use_local_coordinates");
	}
	___godot_icall_void_RID_bool(mb, (const Object *) this, particles, enable);
}

void VisualServer::particles_set_process_material(const RID particles, const RID material) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "particles_set_process_material");
	}
	___godot_icall_void_RID_RID(mb, (const Object *) this, particles, material);
}

void VisualServer::particles_set_fixed_fps(const RID particles, const int64_t fps) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "particles_set_fixed_fps");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, particles, fps);
}

void VisualServer::particles_set_fractional_delta(const RID particles, const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "particles_set_fractional_delta");
	}
	___godot_icall_void_RID_bool(mb, (const Object *) this, particles, enable);
}

void VisualServer::particles_restart(const RID particles) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "particles_restart");
	}
	___godot_icall_void_RID(mb, (const Object *) this, particles);
}

void VisualServer::particles_set_draw_order(const RID particles, const int64_t order) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "particles_set_draw_order");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, particles, order);
}

void VisualServer::particles_set_draw_passes(const RID particles, const int64_t count) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "particles_set_draw_passes");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, particles, count);
}

void VisualServer::particles_set_draw_pass_mesh(const RID particles, const int64_t pass, const RID mesh) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "particles_set_draw_pass_mesh");
	}
	___godot_icall_void_RID_int_RID(mb, (const Object *) this, particles, pass, mesh);
}

AABB VisualServer::particles_get_current_aabb(const RID particles) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "particles_get_current_aabb");
	}
	return ___godot_icall_AABB_RID(mb, (const Object *) this, particles);
}

void VisualServer::particles_set_emission_transform(const RID particles, const Transform transform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "particles_set_emission_transform");
	}
	___godot_icall_void_RID_Transform(mb, (const Object *) this, particles, transform);
}

RID VisualServer::camera_create() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "camera_create");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

void VisualServer::camera_set_perspective(const RID camera, const double fovy_degrees, const double z_near, const double z_far) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "camera_set_perspective");
	}
	___godot_icall_void_RID_float_float_float(mb, (const Object *) this, camera, fovy_degrees, z_near, z_far);
}

void VisualServer::camera_set_orthogonal(const RID camera, const double size, const double z_near, const double z_far) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "camera_set_orthogonal");
	}
	___godot_icall_void_RID_float_float_float(mb, (const Object *) this, camera, size, z_near, z_far);
}

void VisualServer::camera_set_transform(const RID camera, const Transform transform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "camera_set_transform");
	}
	___godot_icall_void_RID_Transform(mb, (const Object *) this, camera, transform);
}

void VisualServer::camera_set_cull_mask(const RID camera, const int64_t layers) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "camera_set_cull_mask");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, camera, layers);
}

void VisualServer::camera_set_environment(const RID camera, const RID env) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "camera_set_environment");
	}
	___godot_icall_void_RID_RID(mb, (const Object *) this, camera, env);
}

void VisualServer::camera_set_use_vertical_aspect(const RID camera, const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "camera_set_use_vertical_aspect");
	}
	___godot_icall_void_RID_bool(mb, (const Object *) this, camera, enable);
}

RID VisualServer::viewport_create() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "viewport_create");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

void VisualServer::viewport_set_use_arvr(const RID viewport, const bool use_arvr) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "viewport_set_use_arvr");
	}
	___godot_icall_void_RID_bool(mb, (const Object *) this, viewport, use_arvr);
}

void VisualServer::viewport_set_size(const RID viewport, const int64_t width, const int64_t height) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "viewport_set_size");
	}
	___godot_icall_void_RID_int_int(mb, (const Object *) this, viewport, width, height);
}

void VisualServer::viewport_set_active(const RID viewport, const bool active) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "viewport_set_active");
	}
	___godot_icall_void_RID_bool(mb, (const Object *) this, viewport, active);
}

void VisualServer::viewport_set_parent_viewport(const RID viewport, const RID parent_viewport) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "viewport_set_parent_viewport");
	}
	___godot_icall_void_RID_RID(mb, (const Object *) this, viewport, parent_viewport);
}

void VisualServer::viewport_attach_to_screen(const RID viewport, const Rect2 rect, const int64_t screen) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "viewport_attach_to_screen");
	}
	___godot_icall_void_RID_Rect2_int(mb, (const Object *) this, viewport, rect, screen);
}

void VisualServer::viewport_detach(const RID viewport) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "viewport_detach");
	}
	___godot_icall_void_RID(mb, (const Object *) this, viewport);
}

void VisualServer::viewport_set_update_mode(const RID viewport, const int64_t update_mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "viewport_set_update_mode");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, viewport, update_mode);
}

void VisualServer::viewport_set_vflip(const RID viewport, const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "viewport_set_vflip");
	}
	___godot_icall_void_RID_bool(mb, (const Object *) this, viewport, enabled);
}

void VisualServer::viewport_set_clear_mode(const RID viewport, const int64_t clear_mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "viewport_set_clear_mode");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, viewport, clear_mode);
}

RID VisualServer::viewport_get_texture(const RID viewport) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "viewport_get_texture");
	}
	return ___godot_icall_RID_RID(mb, (const Object *) this, viewport);
}

void VisualServer::viewport_set_hide_scenario(const RID viewport, const bool hidden) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "viewport_set_hide_scenario");
	}
	___godot_icall_void_RID_bool(mb, (const Object *) this, viewport, hidden);
}

void VisualServer::viewport_set_hide_canvas(const RID viewport, const bool hidden) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "viewport_set_hide_canvas");
	}
	___godot_icall_void_RID_bool(mb, (const Object *) this, viewport, hidden);
}

void VisualServer::viewport_set_disable_environment(const RID viewport, const bool disabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "viewport_set_disable_environment");
	}
	___godot_icall_void_RID_bool(mb, (const Object *) this, viewport, disabled);
}

void VisualServer::viewport_set_disable_3d(const RID viewport, const bool disabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "viewport_set_disable_3d");
	}
	___godot_icall_void_RID_bool(mb, (const Object *) this, viewport, disabled);
}

void VisualServer::viewport_attach_camera(const RID viewport, const RID camera) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "viewport_attach_camera");
	}
	___godot_icall_void_RID_RID(mb, (const Object *) this, viewport, camera);
}

void VisualServer::viewport_set_scenario(const RID viewport, const RID scenario) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "viewport_set_scenario");
	}
	___godot_icall_void_RID_RID(mb, (const Object *) this, viewport, scenario);
}

void VisualServer::viewport_attach_canvas(const RID viewport, const RID canvas) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "viewport_attach_canvas");
	}
	___godot_icall_void_RID_RID(mb, (const Object *) this, viewport, canvas);
}

void VisualServer::viewport_remove_canvas(const RID viewport, const RID canvas) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "viewport_remove_canvas");
	}
	___godot_icall_void_RID_RID(mb, (const Object *) this, viewport, canvas);
}

void VisualServer::viewport_set_canvas_transform(const RID viewport, const RID canvas, const Transform2D offset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "viewport_set_canvas_transform");
	}
	___godot_icall_void_RID_RID_Transform2D(mb, (const Object *) this, viewport, canvas, offset);
}

void VisualServer::viewport_set_transparent_background(const RID viewport, const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "viewport_set_transparent_background");
	}
	___godot_icall_void_RID_bool(mb, (const Object *) this, viewport, enabled);
}

void VisualServer::viewport_set_global_canvas_transform(const RID viewport, const Transform2D transform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "viewport_set_global_canvas_transform");
	}
	___godot_icall_void_RID_Transform2D(mb, (const Object *) this, viewport, transform);
}

void VisualServer::viewport_set_canvas_layer(const RID viewport, const RID canvas, const int64_t layer) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "viewport_set_canvas_layer");
	}
	___godot_icall_void_RID_RID_int(mb, (const Object *) this, viewport, canvas, layer);
}

void VisualServer::viewport_set_shadow_atlas_size(const RID viewport, const int64_t size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "viewport_set_shadow_atlas_size");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, viewport, size);
}

void VisualServer::viewport_set_shadow_atlas_quadrant_subdivision(const RID viewport, const int64_t quadrant, const int64_t subdivision) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "viewport_set_shadow_atlas_quadrant_subdivision");
	}
	___godot_icall_void_RID_int_int(mb, (const Object *) this, viewport, quadrant, subdivision);
}

void VisualServer::viewport_set_msaa(const RID viewport, const int64_t msaa) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "viewport_set_msaa");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, viewport, msaa);
}

void VisualServer::viewport_set_hdr(const RID viewport, const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "viewport_set_hdr");
	}
	___godot_icall_void_RID_bool(mb, (const Object *) this, viewport, enabled);
}

void VisualServer::viewport_set_usage(const RID viewport, const int64_t usage) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "viewport_set_usage");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, viewport, usage);
}

int64_t VisualServer::viewport_get_render_info(const RID viewport, const int64_t info) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "viewport_get_render_info");
	}
	return ___godot_icall_int_RID_int(mb, (const Object *) this, viewport, info);
}

void VisualServer::viewport_set_debug_draw(const RID viewport, const int64_t draw) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "viewport_set_debug_draw");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, viewport, draw);
}

RID VisualServer::environment_create() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "environment_create");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

void VisualServer::environment_set_background(const RID env, const int64_t bg) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "environment_set_background");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, env, bg);
}

void VisualServer::environment_set_sky(const RID env, const RID sky) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "environment_set_sky");
	}
	___godot_icall_void_RID_RID(mb, (const Object *) this, env, sky);
}

void VisualServer::environment_set_sky_custom_fov(const RID env, const double scale) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "environment_set_sky_custom_fov");
	}
	___godot_icall_void_RID_float(mb, (const Object *) this, env, scale);
}

void VisualServer::environment_set_bg_color(const RID env, const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "environment_set_bg_color");
	}
	___godot_icall_void_RID_Color(mb, (const Object *) this, env, color);
}

void VisualServer::environment_set_bg_energy(const RID env, const double energy) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "environment_set_bg_energy");
	}
	___godot_icall_void_RID_float(mb, (const Object *) this, env, energy);
}

void VisualServer::environment_set_canvas_max_layer(const RID env, const int64_t max_layer) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "environment_set_canvas_max_layer");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, env, max_layer);
}

void VisualServer::environment_set_ambient_light(const RID env, const Color color, const double energy, const double sky_contibution) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "environment_set_ambient_light");
	}
	___godot_icall_void_RID_Color_float_float(mb, (const Object *) this, env, color, energy, sky_contibution);
}

void VisualServer::environment_set_dof_blur_near(const RID env, const bool enable, const double distance, const double transition, const double far_amount, const int64_t quality) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "environment_set_dof_blur_near");
	}
	___godot_icall_void_RID_bool_float_float_float_int(mb, (const Object *) this, env, enable, distance, transition, far_amount, quality);
}

void VisualServer::environment_set_dof_blur_far(const RID env, const bool enable, const double distance, const double transition, const double far_amount, const int64_t quality) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "environment_set_dof_blur_far");
	}
	___godot_icall_void_RID_bool_float_float_float_int(mb, (const Object *) this, env, enable, distance, transition, far_amount, quality);
}

void VisualServer::environment_set_glow(const RID env, const bool enable, const int64_t level_flags, const double intensity, const double strength, const double bloom_threshold, const int64_t blend_mode, const double hdr_bleed_threshold, const double hdr_bleed_scale, const bool bicubic_upscale) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "environment_set_glow");
	}
	___godot_icall_void_RID_bool_int_float_float_float_int_float_float_bool(mb, (const Object *) this, env, enable, level_flags, intensity, strength, bloom_threshold, blend_mode, hdr_bleed_threshold, hdr_bleed_scale, bicubic_upscale);
}

void VisualServer::environment_set_tonemap(const RID env, const int64_t tone_mapper, const double exposure, const double white, const bool auto_exposure, const double min_luminance, const double max_luminance, const double auto_exp_speed, const double auto_exp_grey) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "environment_set_tonemap");
	}
	___godot_icall_void_RID_int_float_float_bool_float_float_float_float(mb, (const Object *) this, env, tone_mapper, exposure, white, auto_exposure, min_luminance, max_luminance, auto_exp_speed, auto_exp_grey);
}

void VisualServer::environment_set_adjustment(const RID env, const bool enable, const double brightness, const double contrast, const double saturation, const RID ramp) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "environment_set_adjustment");
	}
	___godot_icall_void_RID_bool_float_float_float_RID(mb, (const Object *) this, env, enable, brightness, contrast, saturation, ramp);
}

void VisualServer::environment_set_ssr(const RID env, const bool enable, const int64_t max_steps, const double fade_in, const double fade_out, const double depth_tolerance, const bool roughness) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "environment_set_ssr");
	}
	___godot_icall_void_RID_bool_int_float_float_float_bool(mb, (const Object *) this, env, enable, max_steps, fade_in, fade_out, depth_tolerance, roughness);
}

void VisualServer::environment_set_ssao(const RID env, const bool enable, const double radius, const double intensity, const double radius2, const double intensity2, const double bias, const double light_affect, const Color color, const int64_t quality, const int64_t blur, const double bilateral_sharpness) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "environment_set_ssao");
	}
	___godot_icall_void_RID_bool_float_float_float_float_float_float_Color_int_int_float(mb, (const Object *) this, env, enable, radius, intensity, radius2, intensity2, bias, light_affect, color, quality, blur, bilateral_sharpness);
}

void VisualServer::environment_set_fog(const RID env, const bool enable, const Color color, const Color sun_color, const double sun_amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "environment_set_fog");
	}
	___godot_icall_void_RID_bool_Color_Color_float(mb, (const Object *) this, env, enable, color, sun_color, sun_amount);
}

void VisualServer::environment_set_fog_depth(const RID env, const bool enable, const double depth_begin, const double depth_curve, const bool transmit, const double transmit_curve) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "environment_set_fog_depth");
	}
	___godot_icall_void_RID_bool_float_float_bool_float(mb, (const Object *) this, env, enable, depth_begin, depth_curve, transmit, transmit_curve);
}

void VisualServer::environment_set_fog_height(const RID env, const bool enable, const double min_height, const double max_height, const double height_curve) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "environment_set_fog_height");
	}
	___godot_icall_void_RID_bool_float_float_float(mb, (const Object *) this, env, enable, min_height, max_height, height_curve);
}

RID VisualServer::scenario_create() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "scenario_create");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

void VisualServer::scenario_set_debug(const RID scenario, const int64_t debug_mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "scenario_set_debug");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, scenario, debug_mode);
}

void VisualServer::scenario_set_environment(const RID scenario, const RID environment) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "scenario_set_environment");
	}
	___godot_icall_void_RID_RID(mb, (const Object *) this, scenario, environment);
}

void VisualServer::scenario_set_reflection_atlas_size(const RID scenario, const int64_t p_size, const int64_t subdiv) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "scenario_set_reflection_atlas_size");
	}
	___godot_icall_void_RID_int_int(mb, (const Object *) this, scenario, p_size, subdiv);
}

void VisualServer::scenario_set_fallback_environment(const RID scenario, const RID environment) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "scenario_set_fallback_environment");
	}
	___godot_icall_void_RID_RID(mb, (const Object *) this, scenario, environment);
}

RID VisualServer::instance_create2(const RID base, const RID scenario) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "instance_create2");
	}
	return ___godot_icall_RID_RID_RID(mb, (const Object *) this, base, scenario);
}

RID VisualServer::instance_create() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "instance_create");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

void VisualServer::instance_set_base(const RID instance, const RID base) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "instance_set_base");
	}
	___godot_icall_void_RID_RID(mb, (const Object *) this, instance, base);
}

void VisualServer::instance_set_scenario(const RID instance, const RID scenario) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "instance_set_scenario");
	}
	___godot_icall_void_RID_RID(mb, (const Object *) this, instance, scenario);
}

void VisualServer::instance_set_layer_mask(const RID instance, const int64_t mask) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "instance_set_layer_mask");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, instance, mask);
}

void VisualServer::instance_set_transform(const RID instance, const Transform transform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "instance_set_transform");
	}
	___godot_icall_void_RID_Transform(mb, (const Object *) this, instance, transform);
}

void VisualServer::instance_attach_object_instance_id(const RID instance, const int64_t id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "instance_attach_object_instance_id");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, instance, id);
}

void VisualServer::instance_set_blend_shape_weight(const RID instance, const int64_t shape, const double weight) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "instance_set_blend_shape_weight");
	}
	___godot_icall_void_RID_int_float(mb, (const Object *) this, instance, shape, weight);
}

void VisualServer::instance_set_surface_material(const RID instance, const int64_t surface, const RID material) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "instance_set_surface_material");
	}
	___godot_icall_void_RID_int_RID(mb, (const Object *) this, instance, surface, material);
}

void VisualServer::instance_set_visible(const RID instance, const bool visible) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "instance_set_visible");
	}
	___godot_icall_void_RID_bool(mb, (const Object *) this, instance, visible);
}

void VisualServer::instance_set_use_lightmap(const RID instance, const RID lightmap_instance, const RID lightmap) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "instance_set_use_lightmap");
	}
	___godot_icall_void_RID_RID_RID(mb, (const Object *) this, instance, lightmap_instance, lightmap);
}

void VisualServer::instance_set_custom_aabb(const RID instance, const AABB aabb) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "instance_set_custom_aabb");
	}
	___godot_icall_void_RID_AABB(mb, (const Object *) this, instance, aabb);
}

void VisualServer::instance_attach_skeleton(const RID instance, const RID skeleton) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "instance_attach_skeleton");
	}
	___godot_icall_void_RID_RID(mb, (const Object *) this, instance, skeleton);
}

void VisualServer::instance_set_exterior(const RID instance, const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "instance_set_exterior");
	}
	___godot_icall_void_RID_bool(mb, (const Object *) this, instance, enabled);
}

void VisualServer::instance_set_extra_visibility_margin(const RID instance, const double margin) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "instance_set_extra_visibility_margin");
	}
	___godot_icall_void_RID_float(mb, (const Object *) this, instance, margin);
}

void VisualServer::instance_geometry_set_flag(const RID instance, const int64_t flag, const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "instance_geometry_set_flag");
	}
	___godot_icall_void_RID_int_bool(mb, (const Object *) this, instance, flag, enabled);
}

void VisualServer::instance_geometry_set_cast_shadows_setting(const RID instance, const int64_t shadow_casting_setting) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "instance_geometry_set_cast_shadows_setting");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, instance, shadow_casting_setting);
}

void VisualServer::instance_geometry_set_material_override(const RID instance, const RID material) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "instance_geometry_set_material_override");
	}
	___godot_icall_void_RID_RID(mb, (const Object *) this, instance, material);
}

void VisualServer::instance_geometry_set_draw_range(const RID instance, const double min, const double max, const double min_margin, const double max_margin) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "instance_geometry_set_draw_range");
	}
	___godot_icall_void_RID_float_float_float_float(mb, (const Object *) this, instance, min, max, min_margin, max_margin);
}

void VisualServer::instance_geometry_set_as_instance_lod(const RID instance, const RID as_lod_of_instance) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "instance_geometry_set_as_instance_lod");
	}
	___godot_icall_void_RID_RID(mb, (const Object *) this, instance, as_lod_of_instance);
}

Array VisualServer::instances_cull_aabb(const AABB aabb, const RID scenario) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "instances_cull_aabb");
	}
	return ___godot_icall_Array_AABB_RID(mb, (const Object *) this, aabb, scenario);
}

Array VisualServer::instances_cull_ray(const Vector3 from, const Vector3 to, const RID scenario) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "instances_cull_ray");
	}
	return ___godot_icall_Array_Vector3_Vector3_RID(mb, (const Object *) this, from, to, scenario);
}

Array VisualServer::instances_cull_convex(const Array convex, const RID scenario) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "instances_cull_convex");
	}
	return ___godot_icall_Array_Array_RID(mb, (const Object *) this, convex, scenario);
}

RID VisualServer::canvas_create() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_create");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

void VisualServer::canvas_set_item_mirroring(const RID canvas, const RID item, const Vector2 mirroring) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_set_item_mirroring");
	}
	___godot_icall_void_RID_RID_Vector2(mb, (const Object *) this, canvas, item, mirroring);
}

void VisualServer::canvas_set_modulate(const RID canvas, const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_set_modulate");
	}
	___godot_icall_void_RID_Color(mb, (const Object *) this, canvas, color);
}

RID VisualServer::canvas_item_create() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_item_create");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

void VisualServer::canvas_item_set_parent(const RID item, const RID parent) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_item_set_parent");
	}
	___godot_icall_void_RID_RID(mb, (const Object *) this, item, parent);
}

void VisualServer::canvas_item_set_visible(const RID item, const bool visible) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_item_set_visible");
	}
	___godot_icall_void_RID_bool(mb, (const Object *) this, item, visible);
}

void VisualServer::canvas_item_set_light_mask(const RID item, const int64_t mask) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_item_set_light_mask");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, item, mask);
}

void VisualServer::canvas_item_set_transform(const RID item, const Transform2D transform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_item_set_transform");
	}
	___godot_icall_void_RID_Transform2D(mb, (const Object *) this, item, transform);
}

void VisualServer::canvas_item_set_clip(const RID item, const bool clip) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_item_set_clip");
	}
	___godot_icall_void_RID_bool(mb, (const Object *) this, item, clip);
}

void VisualServer::canvas_item_set_distance_field_mode(const RID item, const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_item_set_distance_field_mode");
	}
	___godot_icall_void_RID_bool(mb, (const Object *) this, item, enabled);
}

void VisualServer::canvas_item_set_custom_rect(const RID item, const bool use_custom_rect, const Rect2 rect) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_item_set_custom_rect");
	}
	___godot_icall_void_RID_bool_Rect2(mb, (const Object *) this, item, use_custom_rect, rect);
}

void VisualServer::canvas_item_set_modulate(const RID item, const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_item_set_modulate");
	}
	___godot_icall_void_RID_Color(mb, (const Object *) this, item, color);
}

void VisualServer::canvas_item_set_self_modulate(const RID item, const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_item_set_self_modulate");
	}
	___godot_icall_void_RID_Color(mb, (const Object *) this, item, color);
}

void VisualServer::canvas_item_set_draw_behind_parent(const RID item, const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_item_set_draw_behind_parent");
	}
	___godot_icall_void_RID_bool(mb, (const Object *) this, item, enabled);
}

void VisualServer::canvas_item_add_line(const RID item, const Vector2 from, const Vector2 to, const Color color, const double width, const bool antialiased) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_item_add_line");
	}
	___godot_icall_void_RID_Vector2_Vector2_Color_float_bool(mb, (const Object *) this, item, from, to, color, width, antialiased);
}

void VisualServer::canvas_item_add_polyline(const RID item, const PoolVector2Array points, const PoolColorArray colors, const double width, const bool antialiased) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_item_add_polyline");
	}
	___godot_icall_void_RID_PoolVector2Array_PoolColorArray_float_bool(mb, (const Object *) this, item, points, colors, width, antialiased);
}

void VisualServer::canvas_item_add_rect(const RID item, const Rect2 rect, const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_item_add_rect");
	}
	___godot_icall_void_RID_Rect2_Color(mb, (const Object *) this, item, rect, color);
}

void VisualServer::canvas_item_add_circle(const RID item, const Vector2 pos, const double radius, const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_item_add_circle");
	}
	___godot_icall_void_RID_Vector2_float_Color(mb, (const Object *) this, item, pos, radius, color);
}

void VisualServer::canvas_item_add_texture_rect(const RID item, const Rect2 rect, const RID texture, const bool tile, const Color modulate, const bool transpose, const RID normal_map) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_item_add_texture_rect");
	}
	___godot_icall_void_RID_Rect2_RID_bool_Color_bool_RID(mb, (const Object *) this, item, rect, texture, tile, modulate, transpose, normal_map);
}

void VisualServer::canvas_item_add_texture_rect_region(const RID item, const Rect2 rect, const RID texture, const Rect2 src_rect, const Color modulate, const bool transpose, const RID normal_map, const bool clip_uv) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_item_add_texture_rect_region");
	}
	___godot_icall_void_RID_Rect2_RID_Rect2_Color_bool_RID_bool(mb, (const Object *) this, item, rect, texture, src_rect, modulate, transpose, normal_map, clip_uv);
}

void VisualServer::canvas_item_add_nine_patch(const RID item, const Rect2 rect, const Rect2 source, const RID texture, const Vector2 topleft, const Vector2 bottomright, const int64_t x_axis_mode, const int64_t y_axis_mode, const bool draw_center, const Color modulate, const RID normal_map) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_item_add_nine_patch");
	}
	___godot_icall_void_RID_Rect2_Rect2_RID_Vector2_Vector2_int_int_bool_Color_RID(mb, (const Object *) this, item, rect, source, texture, topleft, bottomright, x_axis_mode, y_axis_mode, draw_center, modulate, normal_map);
}

void VisualServer::canvas_item_add_primitive(const RID item, const PoolVector2Array points, const PoolColorArray colors, const PoolVector2Array uvs, const RID texture, const double width, const RID normal_map) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_item_add_primitive");
	}
	___godot_icall_void_RID_PoolVector2Array_PoolColorArray_PoolVector2Array_RID_float_RID(mb, (const Object *) this, item, points, colors, uvs, texture, width, normal_map);
}

void VisualServer::canvas_item_add_polygon(const RID item, const PoolVector2Array points, const PoolColorArray colors, const PoolVector2Array uvs, const RID texture, const RID normal_map, const bool antialiased) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_item_add_polygon");
	}
	___godot_icall_void_RID_PoolVector2Array_PoolColorArray_PoolVector2Array_RID_RID_bool(mb, (const Object *) this, item, points, colors, uvs, texture, normal_map, antialiased);
}

void VisualServer::canvas_item_add_triangle_array(const RID item, const PoolIntArray indices, const PoolVector2Array points, const PoolColorArray colors, const PoolVector2Array uvs, const RID texture, const int64_t count, const RID normal_map) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_item_add_triangle_array");
	}
	___godot_icall_void_RID_PoolIntArray_PoolVector2Array_PoolColorArray_PoolVector2Array_RID_int_RID(mb, (const Object *) this, item, indices, points, colors, uvs, texture, count, normal_map);
}

void VisualServer::canvas_item_add_mesh(const RID item, const RID mesh, const RID texture, const RID normal_map) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_item_add_mesh");
	}
	___godot_icall_void_RID_RID_RID_RID(mb, (const Object *) this, item, mesh, texture, normal_map);
}

void VisualServer::canvas_item_add_multimesh(const RID item, const RID mesh, const RID texture, const RID normal_map) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_item_add_multimesh");
	}
	___godot_icall_void_RID_RID_RID_RID(mb, (const Object *) this, item, mesh, texture, normal_map);
}

void VisualServer::canvas_item_add_particles(const RID item, const RID particles, const RID texture, const RID normal_map, const int64_t h_frames, const int64_t v_frames) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_item_add_particles");
	}
	___godot_icall_void_RID_RID_RID_RID_int_int(mb, (const Object *) this, item, particles, texture, normal_map, h_frames, v_frames);
}

void VisualServer::canvas_item_add_set_transform(const RID item, const Transform2D transform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_item_add_set_transform");
	}
	___godot_icall_void_RID_Transform2D(mb, (const Object *) this, item, transform);
}

void VisualServer::canvas_item_add_clip_ignore(const RID item, const bool ignore) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_item_add_clip_ignore");
	}
	___godot_icall_void_RID_bool(mb, (const Object *) this, item, ignore);
}

void VisualServer::canvas_item_set_sort_children_by_y(const RID item, const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_item_set_sort_children_by_y");
	}
	___godot_icall_void_RID_bool(mb, (const Object *) this, item, enabled);
}

void VisualServer::canvas_item_set_z_index(const RID item, const int64_t z_index) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_item_set_z_index");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, item, z_index);
}

void VisualServer::canvas_item_set_z_as_relative_to_parent(const RID item, const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_item_set_z_as_relative_to_parent");
	}
	___godot_icall_void_RID_bool(mb, (const Object *) this, item, enabled);
}

void VisualServer::canvas_item_set_copy_to_backbuffer(const RID item, const bool enabled, const Rect2 rect) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_item_set_copy_to_backbuffer");
	}
	___godot_icall_void_RID_bool_Rect2(mb, (const Object *) this, item, enabled, rect);
}

void VisualServer::canvas_item_clear(const RID item) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_item_clear");
	}
	___godot_icall_void_RID(mb, (const Object *) this, item);
}

void VisualServer::canvas_item_set_draw_index(const RID item, const int64_t index) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_item_set_draw_index");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, item, index);
}

void VisualServer::canvas_item_set_material(const RID item, const RID material) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_item_set_material");
	}
	___godot_icall_void_RID_RID(mb, (const Object *) this, item, material);
}

void VisualServer::canvas_item_set_use_parent_material(const RID item, const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_item_set_use_parent_material");
	}
	___godot_icall_void_RID_bool(mb, (const Object *) this, item, enabled);
}

RID VisualServer::canvas_light_create() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_light_create");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

void VisualServer::canvas_light_attach_to_canvas(const RID light, const RID canvas) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_light_attach_to_canvas");
	}
	___godot_icall_void_RID_RID(mb, (const Object *) this, light, canvas);
}

void VisualServer::canvas_light_set_enabled(const RID light, const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_light_set_enabled");
	}
	___godot_icall_void_RID_bool(mb, (const Object *) this, light, enabled);
}

void VisualServer::canvas_light_set_scale(const RID light, const double scale) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_light_set_scale");
	}
	___godot_icall_void_RID_float(mb, (const Object *) this, light, scale);
}

void VisualServer::canvas_light_set_transform(const RID light, const Transform2D transform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_light_set_transform");
	}
	___godot_icall_void_RID_Transform2D(mb, (const Object *) this, light, transform);
}

void VisualServer::canvas_light_set_texture(const RID light, const RID texture) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_light_set_texture");
	}
	___godot_icall_void_RID_RID(mb, (const Object *) this, light, texture);
}

void VisualServer::canvas_light_set_texture_offset(const RID light, const Vector2 offset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_light_set_texture_offset");
	}
	___godot_icall_void_RID_Vector2(mb, (const Object *) this, light, offset);
}

void VisualServer::canvas_light_set_color(const RID light, const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_light_set_color");
	}
	___godot_icall_void_RID_Color(mb, (const Object *) this, light, color);
}

void VisualServer::canvas_light_set_height(const RID light, const double height) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_light_set_height");
	}
	___godot_icall_void_RID_float(mb, (const Object *) this, light, height);
}

void VisualServer::canvas_light_set_energy(const RID light, const double energy) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_light_set_energy");
	}
	___godot_icall_void_RID_float(mb, (const Object *) this, light, energy);
}

void VisualServer::canvas_light_set_z_range(const RID light, const int64_t min_z, const int64_t max_z) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_light_set_z_range");
	}
	___godot_icall_void_RID_int_int(mb, (const Object *) this, light, min_z, max_z);
}

void VisualServer::canvas_light_set_layer_range(const RID light, const int64_t min_layer, const int64_t max_layer) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_light_set_layer_range");
	}
	___godot_icall_void_RID_int_int(mb, (const Object *) this, light, min_layer, max_layer);
}

void VisualServer::canvas_light_set_item_cull_mask(const RID light, const int64_t mask) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_light_set_item_cull_mask");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, light, mask);
}

void VisualServer::canvas_light_set_item_shadow_cull_mask(const RID light, const int64_t mask) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_light_set_item_shadow_cull_mask");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, light, mask);
}

void VisualServer::canvas_light_set_mode(const RID light, const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_light_set_mode");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, light, mode);
}

void VisualServer::canvas_light_set_shadow_enabled(const RID light, const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_light_set_shadow_enabled");
	}
	___godot_icall_void_RID_bool(mb, (const Object *) this, light, enabled);
}

void VisualServer::canvas_light_set_shadow_buffer_size(const RID light, const int64_t size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_light_set_shadow_buffer_size");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, light, size);
}

void VisualServer::canvas_light_set_shadow_gradient_length(const RID light, const double length) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_light_set_shadow_gradient_length");
	}
	___godot_icall_void_RID_float(mb, (const Object *) this, light, length);
}

void VisualServer::canvas_light_set_shadow_filter(const RID light, const int64_t filter) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_light_set_shadow_filter");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, light, filter);
}

void VisualServer::canvas_light_set_shadow_color(const RID light, const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_light_set_shadow_color");
	}
	___godot_icall_void_RID_Color(mb, (const Object *) this, light, color);
}

void VisualServer::canvas_light_set_shadow_smooth(const RID light, const double smooth) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_light_set_shadow_smooth");
	}
	___godot_icall_void_RID_float(mb, (const Object *) this, light, smooth);
}

RID VisualServer::canvas_light_occluder_create() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_light_occluder_create");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

void VisualServer::canvas_light_occluder_attach_to_canvas(const RID occluder, const RID canvas) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_light_occluder_attach_to_canvas");
	}
	___godot_icall_void_RID_RID(mb, (const Object *) this, occluder, canvas);
}

void VisualServer::canvas_light_occluder_set_enabled(const RID occluder, const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_light_occluder_set_enabled");
	}
	___godot_icall_void_RID_bool(mb, (const Object *) this, occluder, enabled);
}

void VisualServer::canvas_light_occluder_set_polygon(const RID occluder, const RID polygon) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_light_occluder_set_polygon");
	}
	___godot_icall_void_RID_RID(mb, (const Object *) this, occluder, polygon);
}

void VisualServer::canvas_light_occluder_set_transform(const RID occluder, const Transform2D transform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_light_occluder_set_transform");
	}
	___godot_icall_void_RID_Transform2D(mb, (const Object *) this, occluder, transform);
}

void VisualServer::canvas_light_occluder_set_light_mask(const RID occluder, const int64_t mask) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_light_occluder_set_light_mask");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, occluder, mask);
}

RID VisualServer::canvas_occluder_polygon_create() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_occluder_polygon_create");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

void VisualServer::canvas_occluder_polygon_set_shape(const RID occluder_polygon, const PoolVector2Array shape, const bool closed) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_occluder_polygon_set_shape");
	}
	___godot_icall_void_RID_PoolVector2Array_bool(mb, (const Object *) this, occluder_polygon, shape, closed);
}

void VisualServer::canvas_occluder_polygon_set_shape_as_lines(const RID occluder_polygon, const PoolVector2Array shape) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_occluder_polygon_set_shape_as_lines");
	}
	___godot_icall_void_RID_PoolVector2Array(mb, (const Object *) this, occluder_polygon, shape);
}

void VisualServer::canvas_occluder_polygon_set_cull_mode(const RID occluder_polygon, const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "canvas_occluder_polygon_set_cull_mode");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, occluder_polygon, mode);
}

void VisualServer::black_bars_set_margins(const int64_t left, const int64_t top, const int64_t right, const int64_t bottom) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "black_bars_set_margins");
	}
	___godot_icall_void_int_int_int_int(mb, (const Object *) this, left, top, right, bottom);
}

void VisualServer::black_bars_set_images(const RID left, const RID top, const RID right, const RID bottom) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "black_bars_set_images");
	}
	___godot_icall_void_RID_RID_RID_RID(mb, (const Object *) this, left, top, right, bottom);
}

void VisualServer::free_rid(const RID rid) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "free_rid");
	}
	___godot_icall_void_RID(mb, (const Object *) this, rid);
}

void VisualServer::request_frame_drawn_callback(const Object *where, const String method, const Variant userdata) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "request_frame_drawn_callback");
	}
	___godot_icall_void_Object_String_Variant(mb, (const Object *) this, where, method, userdata);
}

bool VisualServer::has_changed() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "has_changed");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void VisualServer::init() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "init");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void VisualServer::finish() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "finish");
	}
	___godot_icall_void(mb, (const Object *) this);
}

int64_t VisualServer::get_render_info(const int64_t info) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "get_render_info");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, info);
}

RID VisualServer::get_test_cube() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "get_test_cube");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

RID VisualServer::get_test_texture() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "get_test_texture");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

RID VisualServer::get_white_texture() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "get_white_texture");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

RID VisualServer::make_sphere_mesh(const int64_t latitudes, const int64_t longitudes, const double radius) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "make_sphere_mesh");
	}
	return ___godot_icall_RID_int_int_float(mb, (const Object *) this, latitudes, longitudes, radius);
}

void VisualServer::set_boot_image(const Ref<Image> image, const Color color, const bool scale) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "set_boot_image");
	}
	___godot_icall_void_Object_Color_bool(mb, (const Object *) this, image.ptr(), color, scale);
}

void VisualServer::set_default_clear_color(const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "set_default_clear_color");
	}
	___godot_icall_void_Color(mb, (const Object *) this, color);
}

bool VisualServer::has_feature(const int64_t feature) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "has_feature");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, feature);
}

bool VisualServer::has_os_feature(const String feature) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "has_os_feature");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, feature);
}

void VisualServer::set_debug_generate_wireframes(const bool generate) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualServer", "set_debug_generate_wireframes");
	}
	___godot_icall_void_bool(mb, (const Object *) this, generate);
}

}