#include <TileMap.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <TileSet.hpp>


namespace godot {


void *TileMap::___get_type_tag()
{
	return (void *) &TileMap::___get_type_tag;
}

void *TileMap::___get_base_type_tag()
{
	return (void *) &Node2D::___get_type_tag;
}

TileMap *TileMap::_new()
{
	return (TileMap *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"TileMap")());
}
void TileMap::set_tileset(const Ref<TileSet> tileset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "set_tileset");
	}
	___godot_icall_void_Object(mb, (const Object *) this, tileset.ptr());
}

Ref<TileSet> TileMap::get_tileset() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "get_tileset");
	}
	return Ref<TileSet>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void TileMap::set_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "set_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

TileMap::Mode TileMap::get_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "get_mode");
	}
	return (TileMap::Mode) ___godot_icall_int(mb, (const Object *) this);
}

void TileMap::set_half_offset(const int64_t half_offset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "set_half_offset");
	}
	___godot_icall_void_int(mb, (const Object *) this, half_offset);
}

TileMap::HalfOffset TileMap::get_half_offset() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "get_half_offset");
	}
	return (TileMap::HalfOffset) ___godot_icall_int(mb, (const Object *) this);
}

void TileMap::set_custom_transform(const Transform2D custom_transform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "set_custom_transform");
	}
	___godot_icall_void_Transform2D(mb, (const Object *) this, custom_transform);
}

Transform2D TileMap::get_custom_transform() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "get_custom_transform");
	}
	return ___godot_icall_Transform2D(mb, (const Object *) this);
}

void TileMap::set_cell_size(const Vector2 size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "set_cell_size");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, size);
}

Vector2 TileMap::get_cell_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "get_cell_size");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void TileMap::_set_old_cell_size(const int64_t size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "_set_old_cell_size");
	}
	___godot_icall_void_int(mb, (const Object *) this, size);
}

int64_t TileMap::_get_old_cell_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "_get_old_cell_size");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void TileMap::set_quadrant_size(const int64_t size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "set_quadrant_size");
	}
	___godot_icall_void_int(mb, (const Object *) this, size);
}

int64_t TileMap::get_quadrant_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "get_quadrant_size");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void TileMap::set_tile_origin(const int64_t origin) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "set_tile_origin");
	}
	___godot_icall_void_int(mb, (const Object *) this, origin);
}

TileMap::TileOrigin TileMap::get_tile_origin() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "get_tile_origin");
	}
	return (TileMap::TileOrigin) ___godot_icall_int(mb, (const Object *) this);
}

void TileMap::set_clip_uv(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "set_clip_uv");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool TileMap::get_clip_uv() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "get_clip_uv");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void TileMap::set_y_sort_mode(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "set_y_sort_mode");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool TileMap::is_y_sort_mode_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "is_y_sort_mode_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void TileMap::set_collision_use_kinematic(const bool use_kinematic) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "set_collision_use_kinematic");
	}
	___godot_icall_void_bool(mb, (const Object *) this, use_kinematic);
}

bool TileMap::get_collision_use_kinematic() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "get_collision_use_kinematic");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void TileMap::set_collision_layer(const int64_t layer) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "set_collision_layer");
	}
	___godot_icall_void_int(mb, (const Object *) this, layer);
}

int64_t TileMap::get_collision_layer() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "get_collision_layer");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void TileMap::set_collision_mask(const int64_t mask) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "set_collision_mask");
	}
	___godot_icall_void_int(mb, (const Object *) this, mask);
}

int64_t TileMap::get_collision_mask() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "get_collision_mask");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void TileMap::set_collision_layer_bit(const int64_t bit, const bool value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "set_collision_layer_bit");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, bit, value);
}

bool TileMap::get_collision_layer_bit(const int64_t bit) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "get_collision_layer_bit");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, bit);
}

void TileMap::set_collision_mask_bit(const int64_t bit, const bool value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "set_collision_mask_bit");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, bit, value);
}

bool TileMap::get_collision_mask_bit(const int64_t bit) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "get_collision_mask_bit");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, bit);
}

void TileMap::set_collision_friction(const double value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "set_collision_friction");
	}
	___godot_icall_void_float(mb, (const Object *) this, value);
}

double TileMap::get_collision_friction() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "get_collision_friction");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void TileMap::set_collision_bounce(const double value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "set_collision_bounce");
	}
	___godot_icall_void_float(mb, (const Object *) this, value);
}

double TileMap::get_collision_bounce() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "get_collision_bounce");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void TileMap::set_occluder_light_mask(const int64_t mask) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "set_occluder_light_mask");
	}
	___godot_icall_void_int(mb, (const Object *) this, mask);
}

int64_t TileMap::get_occluder_light_mask() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "get_occluder_light_mask");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void TileMap::set_cell(const int64_t x, const int64_t y, const int64_t tile, const bool flip_x, const bool flip_y, const bool transpose, const Vector2 autotile_coord) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "set_cell");
	}
	___godot_icall_void_int_int_int_bool_bool_bool_Vector2(mb, (const Object *) this, x, y, tile, flip_x, flip_y, transpose, autotile_coord);
}

void TileMap::set_cellv(const Vector2 position, const int64_t tile, const bool flip_x, const bool flip_y, const bool transpose) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "set_cellv");
	}
	___godot_icall_void_Vector2_int_bool_bool_bool(mb, (const Object *) this, position, tile, flip_x, flip_y, transpose);
}

int64_t TileMap::get_cell(const int64_t x, const int64_t y) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "get_cell");
	}
	return ___godot_icall_int_int_int(mb, (const Object *) this, x, y);
}

int64_t TileMap::get_cellv(const Vector2 position) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "get_cellv");
	}
	return ___godot_icall_int_Vector2(mb, (const Object *) this, position);
}

bool TileMap::is_cell_x_flipped(const int64_t x, const int64_t y) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "is_cell_x_flipped");
	}
	return ___godot_icall_bool_int_int(mb, (const Object *) this, x, y);
}

bool TileMap::is_cell_y_flipped(const int64_t x, const int64_t y) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "is_cell_y_flipped");
	}
	return ___godot_icall_bool_int_int(mb, (const Object *) this, x, y);
}

bool TileMap::is_cell_transposed(const int64_t x, const int64_t y) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "is_cell_transposed");
	}
	return ___godot_icall_bool_int_int(mb, (const Object *) this, x, y);
}

void TileMap::fix_invalid_tiles() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "fix_invalid_tiles");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void TileMap::clear() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "clear");
	}
	___godot_icall_void(mb, (const Object *) this);
}

Array TileMap::get_used_cells() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "get_used_cells");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

Array TileMap::get_used_cells_by_id(const int64_t id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "get_used_cells_by_id");
	}
	return ___godot_icall_Array_int(mb, (const Object *) this, id);
}

Rect2 TileMap::get_used_rect() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "get_used_rect");
	}
	return ___godot_icall_Rect2(mb, (const Object *) this);
}

Vector2 TileMap::map_to_world(const Vector2 map_position, const bool ignore_half_ofs) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "map_to_world");
	}
	return ___godot_icall_Vector2_Vector2_bool(mb, (const Object *) this, map_position, ignore_half_ofs);
}

Vector2 TileMap::world_to_map(const Vector2 world_position) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "world_to_map");
	}
	return ___godot_icall_Vector2_Vector2(mb, (const Object *) this, world_position);
}

void TileMap::_clear_quadrants() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "_clear_quadrants");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void TileMap::_recreate_quadrants() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "_recreate_quadrants");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void TileMap::_update_dirty_quadrants() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "_update_dirty_quadrants");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void TileMap::update_bitmask_area(const Vector2 position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "update_bitmask_area");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, position);
}

void TileMap::update_bitmask_region(const Vector2 start, const Vector2 end) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "update_bitmask_region");
	}
	___godot_icall_void_Vector2_Vector2(mb, (const Object *) this, start, end);
}

void TileMap::_set_tile_data(const PoolIntArray arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "_set_tile_data");
	}
	___godot_icall_void_PoolIntArray(mb, (const Object *) this, arg0);
}

PoolIntArray TileMap::_get_tile_data() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileMap", "_get_tile_data");
	}
	return ___godot_icall_PoolIntArray(mb, (const Object *) this);
}

}