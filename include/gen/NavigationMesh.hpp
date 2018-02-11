#ifndef GODOT_CPP_NAVIGATIONMESH_HPP
#define GODOT_CPP_NAVIGATIONMESH_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Resource.hpp>
namespace godot {

class Mesh;

class NavigationMesh : public Resource {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "NavigationMesh"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants
	const static int SAMPLE_PARTITION_WATERSHED = 0;
	const static int SAMPLE_PARTITION_MONOTONE = 1;
	const static int SAMPLE_PARTITION_LAYERS = 2;


	static NavigationMesh *_new();

	// methods
	void set_sample_partition_type(const int64_t sample_partition_type);
	int64_t get_sample_partition_type() const;
	void set_cell_size(const double cell_size);
	double get_cell_size() const;
	void set_cell_height(const double cell_height);
	double get_cell_height() const;
	void set_agent_height(const double agent_height);
	double get_agent_height() const;
	void set_agent_radius(const double agent_radius);
	double get_agent_radius();
	void set_agent_max_climb(const double agent_max_climb);
	double get_agent_max_climb() const;
	void set_agent_max_slope(const double agent_max_slope);
	double get_agent_max_slope() const;
	void set_region_min_size(const double region_min_size);
	double get_region_min_size() const;
	void set_region_merge_size(const double region_merge_size);
	double get_region_merge_size() const;
	void set_edge_max_length(const double edge_max_length);
	double get_edge_max_length() const;
	void set_edge_max_error(const double edge_max_error);
	double get_edge_max_error() const;
	void set_verts_per_poly(const double verts_per_poly);
	double get_verts_per_poly() const;
	void set_detail_sample_distance(const double detail_sample_dist);
	double get_detail_sample_distance() const;
	void set_detail_sample_max_error(const double detail_sample_max_error);
	double get_detail_sample_max_error() const;
	void set_filter_low_hanging_obstacles(const bool filter_low_hanging_obstacles);
	bool get_filter_low_hanging_obstacles() const;
	void set_filter_ledge_spans(const bool filter_ledge_spans);
	bool get_filter_ledge_spans() const;
	void set_filter_walkable_low_height_spans(const bool filter_walkable_low_height_spans);
	bool get_filter_walkable_low_height_spans() const;
	void set_vertices(const PoolVector3Array vertices);
	PoolVector3Array get_vertices() const;
	void add_polygon(const PoolIntArray polygon);
	int64_t get_polygon_count() const;
	PoolIntArray get_polygon(const int64_t idx);
	void clear_polygons();
	void create_from_mesh(const Ref<Mesh> mesh);
	void _set_polygons(const Array polygons);
	Array _get_polygons() const;

};

}

#endif