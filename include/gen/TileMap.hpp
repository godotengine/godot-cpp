#ifndef GODOT_CPP_TILEMAP_HPP
#define GODOT_CPP_TILEMAP_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include "TileMap.hpp"

#include "Node2D.hpp"
namespace godot {

class TileSet;

class TileMap : public Node2D {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "TileMap"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum Mode {
		MODE_ISOMETRIC = 1,
		MODE_SQUARE = 0,
		MODE_CUSTOM = 2,
	};
	enum TileOrigin {
		TILE_ORIGIN_BOTTOM_LEFT = 2,
		TILE_ORIGIN_CENTER = 1,
		TILE_ORIGIN_TOP_LEFT = 0,
	};
	enum HalfOffset {
		HALF_OFFSET_Y = 1,
		HALF_OFFSET_X = 0,
		HALF_OFFSET_DISABLED = 2,
	};

	// constants
	const static int INVALID_CELL = -1;


	static TileMap *_new();

	// methods
	void set_tileset(const Ref<TileSet> tileset);
	Ref<TileSet> get_tileset() const;
	void set_mode(const int64_t mode);
	TileMap::Mode get_mode() const;
	void set_half_offset(const int64_t half_offset);
	TileMap::HalfOffset get_half_offset() const;
	void set_custom_transform(const Transform2D custom_transform);
	Transform2D get_custom_transform() const;
	void set_cell_size(const Vector2 size);
	Vector2 get_cell_size() const;
	void _set_old_cell_size(const int64_t size);
	int64_t _get_old_cell_size() const;
	void set_quadrant_size(const int64_t size);
	int64_t get_quadrant_size() const;
	void set_tile_origin(const int64_t origin);
	TileMap::TileOrigin get_tile_origin() const;
	void set_clip_uv(const bool enable);
	bool get_clip_uv() const;
	void set_y_sort_mode(const bool enable);
	bool is_y_sort_mode_enabled() const;
	void set_collision_use_kinematic(const bool use_kinematic);
	bool get_collision_use_kinematic() const;
	void set_collision_layer(const int64_t layer);
	int64_t get_collision_layer() const;
	void set_collision_mask(const int64_t mask);
	int64_t get_collision_mask() const;
	void set_collision_layer_bit(const int64_t bit, const bool value);
	bool get_collision_layer_bit(const int64_t bit) const;
	void set_collision_mask_bit(const int64_t bit, const bool value);
	bool get_collision_mask_bit(const int64_t bit) const;
	void set_collision_friction(const double value);
	double get_collision_friction() const;
	void set_collision_bounce(const double value);
	double get_collision_bounce() const;
	void set_occluder_light_mask(const int64_t mask);
	int64_t get_occluder_light_mask() const;
	void set_cell(const int64_t x, const int64_t y, const int64_t tile, const bool flip_x = false, const bool flip_y = false, const bool transpose = false, const Vector2 autotile_coord = Vector2(0, 0));
	void set_cellv(const Vector2 position, const int64_t tile, const bool flip_x = false, const bool flip_y = false, const bool transpose = false);
	int64_t get_cell(const int64_t x, const int64_t y) const;
	int64_t get_cellv(const Vector2 position) const;
	bool is_cell_x_flipped(const int64_t x, const int64_t y) const;
	bool is_cell_y_flipped(const int64_t x, const int64_t y) const;
	bool is_cell_transposed(const int64_t x, const int64_t y) const;
	void fix_invalid_tiles();
	void clear();
	Array get_used_cells() const;
	Array get_used_cells_by_id(const int64_t id) const;
	Rect2 get_used_rect();
	Vector2 map_to_world(const Vector2 map_position, const bool ignore_half_ofs = false) const;
	Vector2 world_to_map(const Vector2 world_position) const;
	void _clear_quadrants();
	void _recreate_quadrants();
	void _update_dirty_quadrants();
	void update_bitmask_area(const Vector2 position);
	void update_bitmask_region(const Vector2 start = Vector2(0, 0), const Vector2 end = Vector2(0, 0));
	void _set_tile_data(const PoolIntArray arg0);
	PoolIntArray _get_tile_data() const;

};

}

#endif