#ifndef GODOT_CPP_GRIDMAP_HPP
#define GODOT_CPP_GRIDMAP_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Spatial.hpp>
namespace godot {

class MeshLibrary;
class Resource;

class GridMap : public Spatial {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "GridMap"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants
	const static int INVALID_CELL_ITEM = -1;


	static GridMap *_new();

	// methods
	void set_collision_layer(const int64_t layer);
	int64_t get_collision_layer() const;
	void set_collision_mask(const int64_t mask);
	int64_t get_collision_mask() const;
	void set_collision_mask_bit(const int64_t bit, const bool value);
	bool get_collision_mask_bit(const int64_t bit) const;
	void set_collision_layer_bit(const int64_t bit, const bool value);
	bool get_collision_layer_bit(const int64_t bit) const;
	void set_theme(const Ref<MeshLibrary> theme);
	Ref<MeshLibrary> get_theme() const;
	void set_cell_size(const Vector3 size);
	Vector3 get_cell_size() const;
	void set_cell_scale(const double scale);
	double get_cell_scale() const;
	void set_octant_size(const int64_t size);
	int64_t get_octant_size() const;
	void set_cell_item(const int64_t x, const int64_t y, const int64_t z, const int64_t item, const int64_t orientation = 0);
	int64_t get_cell_item(const int64_t x, const int64_t y, const int64_t z) const;
	int64_t get_cell_item_orientation(const int64_t x, const int64_t y, const int64_t z) const;
	Vector3 world_to_map(const Vector3 pos) const;
	Vector3 map_to_world(const int64_t x, const int64_t y, const int64_t z) const;
	void _update_octants_callback();
	void resource_changed(const Ref<Resource> resource);
	void set_center_x(const bool enable);
	bool get_center_x() const;
	void set_center_y(const bool enable);
	bool get_center_y() const;
	void set_center_z(const bool enable);
	bool get_center_z() const;
	void set_clip(const bool enabled, const bool clipabove = true, const int64_t floor = 0, const int64_t axis = 0);
	void clear();
	Array get_used_cells() const;
	Array get_meshes();
	Array get_bake_meshes();
	RID get_bake_mesh_instance(const int64_t idx);
	void clear_baked_meshes();
	void make_baked_meshes(const bool gen_lightmap_uv = false, const double lightmap_uv_texel_size = 0.1);

};

}

#endif