#include <GridMap.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <MeshLibrary.hpp>
#include <Resource.hpp>


namespace godot {


void *GridMap::___get_type_tag()
{
	return (void *) &GridMap::___get_type_tag;
}

void *GridMap::___get_base_type_tag()
{
	return (void *) &Spatial::___get_type_tag;
}

GridMap *GridMap::_new()
{
	return (GridMap *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"GridMap")());
}
void GridMap::set_collision_layer(const int64_t layer) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GridMap", "set_collision_layer");
	}
	___godot_icall_void_int(mb, (const Object *) this, layer);
}

int64_t GridMap::get_collision_layer() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GridMap", "get_collision_layer");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void GridMap::set_collision_mask(const int64_t mask) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GridMap", "set_collision_mask");
	}
	___godot_icall_void_int(mb, (const Object *) this, mask);
}

int64_t GridMap::get_collision_mask() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GridMap", "get_collision_mask");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void GridMap::set_collision_mask_bit(const int64_t bit, const bool value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GridMap", "set_collision_mask_bit");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, bit, value);
}

bool GridMap::get_collision_mask_bit(const int64_t bit) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GridMap", "get_collision_mask_bit");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, bit);
}

void GridMap::set_collision_layer_bit(const int64_t bit, const bool value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GridMap", "set_collision_layer_bit");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, bit, value);
}

bool GridMap::get_collision_layer_bit(const int64_t bit) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GridMap", "get_collision_layer_bit");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, bit);
}

void GridMap::set_theme(const Ref<MeshLibrary> theme) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GridMap", "set_theme");
	}
	___godot_icall_void_Object(mb, (const Object *) this, theme.ptr());
}

Ref<MeshLibrary> GridMap::get_theme() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GridMap", "get_theme");
	}
	return Ref<MeshLibrary>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void GridMap::set_cell_size(const Vector3 size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GridMap", "set_cell_size");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, size);
}

Vector3 GridMap::get_cell_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GridMap", "get_cell_size");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

void GridMap::set_cell_scale(const double scale) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GridMap", "set_cell_scale");
	}
	___godot_icall_void_float(mb, (const Object *) this, scale);
}

double GridMap::get_cell_scale() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GridMap", "get_cell_scale");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void GridMap::set_octant_size(const int64_t size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GridMap", "set_octant_size");
	}
	___godot_icall_void_int(mb, (const Object *) this, size);
}

int64_t GridMap::get_octant_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GridMap", "get_octant_size");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void GridMap::set_cell_item(const int64_t x, const int64_t y, const int64_t z, const int64_t item, const int64_t orientation) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GridMap", "set_cell_item");
	}
	___godot_icall_void_int_int_int_int_int(mb, (const Object *) this, x, y, z, item, orientation);
}

int64_t GridMap::get_cell_item(const int64_t x, const int64_t y, const int64_t z) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GridMap", "get_cell_item");
	}
	return ___godot_icall_int_int_int_int(mb, (const Object *) this, x, y, z);
}

int64_t GridMap::get_cell_item_orientation(const int64_t x, const int64_t y, const int64_t z) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GridMap", "get_cell_item_orientation");
	}
	return ___godot_icall_int_int_int_int(mb, (const Object *) this, x, y, z);
}

Vector3 GridMap::world_to_map(const Vector3 pos) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GridMap", "world_to_map");
	}
	return ___godot_icall_Vector3_Vector3(mb, (const Object *) this, pos);
}

Vector3 GridMap::map_to_world(const int64_t x, const int64_t y, const int64_t z) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GridMap", "map_to_world");
	}
	return ___godot_icall_Vector3_int_int_int(mb, (const Object *) this, x, y, z);
}

void GridMap::_update_octants_callback() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GridMap", "_update_octants_callback");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void GridMap::resource_changed(const Ref<Resource> resource) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GridMap", "resource_changed");
	}
	___godot_icall_void_Object(mb, (const Object *) this, resource.ptr());
}

void GridMap::set_center_x(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GridMap", "set_center_x");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool GridMap::get_center_x() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GridMap", "get_center_x");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void GridMap::set_center_y(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GridMap", "set_center_y");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool GridMap::get_center_y() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GridMap", "get_center_y");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void GridMap::set_center_z(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GridMap", "set_center_z");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool GridMap::get_center_z() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GridMap", "get_center_z");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void GridMap::set_clip(const bool enabled, const bool clipabove, const int64_t floor, const int64_t axis) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GridMap", "set_clip");
	}
	___godot_icall_void_bool_bool_int_int(mb, (const Object *) this, enabled, clipabove, floor, axis);
}

void GridMap::clear() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GridMap", "clear");
	}
	___godot_icall_void(mb, (const Object *) this);
}

Array GridMap::get_used_cells() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GridMap", "get_used_cells");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

Array GridMap::get_meshes() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GridMap", "get_meshes");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

Array GridMap::get_bake_meshes() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GridMap", "get_bake_meshes");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

RID GridMap::get_bake_mesh_instance(const int64_t idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GridMap", "get_bake_mesh_instance");
	}
	return ___godot_icall_RID_int(mb, (const Object *) this, idx);
}

void GridMap::clear_baked_meshes() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GridMap", "clear_baked_meshes");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void GridMap::make_baked_meshes(const bool gen_lightmap_uv, const double lightmap_uv_texel_size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GridMap", "make_baked_meshes");
	}
	___godot_icall_void_bool_float(mb, (const Object *) this, gen_lightmap_uv, lightmap_uv_texel_size);
}

}