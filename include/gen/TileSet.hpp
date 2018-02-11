#ifndef GODOT_CPP_TILESET_HPP
#define GODOT_CPP_TILESET_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <TileSet.hpp>

#include <Resource.hpp>
namespace godot {

class Object;
class Texture;
class ShaderMaterial;
class Shape2D;
class NavigationPolygon;
class OccluderPolygon2D;

class TileSet : public Resource {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "TileSet"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum AutotileBindings {
		BIND_TOPRIGHT = 4,
		BIND_TOPLEFT = 1,
		BIND_RIGHT = 32,
		BIND_TOP = 2,
		BIND_LEFT = 8,
		BIND_BOTTOM = 128,
		BIND_BOTTOMRIGHT = 256,
		BIND_BOTTOMLEFT = 64,
	};
	enum BitmaskMode {
		BITMASK_3X3 = 1,
		BITMASK_2X2 = 0,
	};

	// constants


	static TileSet *_new();

	// methods
	bool _is_tile_bound(const int64_t drawn_id, const int64_t neighbor_id);
	Vector2 _forward_subtile_selection(const int64_t autotile_id, const int64_t bitmask, const Object *tilemap, const Vector2 tile_location);
	void create_tile(const int64_t id);
	void autotile_set_bitmask_mode(const int64_t id, const int64_t mode);
	TileSet::BitmaskMode autotile_get_bitmask_mode(const int64_t id) const;
	void tile_set_name(const int64_t id, const String name);
	String tile_get_name(const int64_t id) const;
	void tile_set_texture(const int64_t id, const Ref<Texture> texture);
	Ref<Texture> tile_get_texture(const int64_t id) const;
	void tile_set_normal_map(const int64_t id, const Ref<Texture> normal_map);
	Ref<Texture> tile_get_normal_map(const int64_t id) const;
	void tile_set_material(const int64_t id, const Ref<ShaderMaterial> material);
	Ref<ShaderMaterial> tile_get_material(const int64_t id) const;
	void tile_set_texture_offset(const int64_t id, const Vector2 texture_offset);
	Vector2 tile_get_texture_offset(const int64_t id) const;
	void tile_set_region(const int64_t id, const Rect2 region);
	Rect2 tile_get_region(const int64_t id) const;
	void tile_set_shape(const int64_t id, const int64_t shape_id, const Ref<Shape2D> shape);
	Ref<Shape2D> tile_get_shape(const int64_t id, const int64_t shape_id) const;
	void tile_set_shape_transform(const int64_t id, const int64_t shape_id, const Transform2D shape_transform);
	Transform2D tile_get_shape_transform(const int64_t id, const int64_t shape_id) const;
	void tile_set_shape_one_way(const int64_t id, const int64_t shape_id, const bool one_way);
	bool tile_get_shape_one_way(const int64_t id, const int64_t shape_id) const;
	void tile_add_shape(const int64_t id, const Ref<Shape2D> shape, const Transform2D shape_transform, const bool one_way = false, const Vector2 autotile_coord = Vector2(0, 0));
	int64_t tile_get_shape_count(const int64_t id) const;
	void tile_set_shapes(const int64_t id, const Array shapes);
	Array tile_get_shapes(const int64_t id) const;
	void tile_set_navigation_polygon(const int64_t id, const Ref<NavigationPolygon> navigation_polygon);
	Ref<NavigationPolygon> tile_get_navigation_polygon(const int64_t id) const;
	void tile_set_navigation_polygon_offset(const int64_t id, const Vector2 navigation_polygon_offset);
	Vector2 tile_get_navigation_polygon_offset(const int64_t id) const;
	void tile_set_light_occluder(const int64_t id, const Ref<OccluderPolygon2D> light_occluder);
	Ref<OccluderPolygon2D> tile_get_light_occluder(const int64_t id) const;
	void tile_set_occluder_offset(const int64_t id, const Vector2 occluder_offset);
	Vector2 tile_get_occluder_offset(const int64_t id) const;
	void remove_tile(const int64_t id);
	void clear();
	int64_t get_last_unused_tile_id() const;
	int64_t find_tile_by_name(const String name) const;
	Array get_tiles_ids() const;

};

}

#endif