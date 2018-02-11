#include <NavigationMesh.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Mesh.hpp>


namespace godot {


void *NavigationMesh::___get_type_tag()
{
	return (void *) &NavigationMesh::___get_type_tag;
}

void *NavigationMesh::___get_base_type_tag()
{
	return (void *) &Resource::___get_type_tag;
}

NavigationMesh *NavigationMesh::_new()
{
	return (NavigationMesh *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"NavigationMesh")());
}
void NavigationMesh::set_sample_partition_type(const int64_t sample_partition_type) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMesh", "set_sample_partition_type");
	}
	___godot_icall_void_int(mb, (const Object *) this, sample_partition_type);
}

int64_t NavigationMesh::get_sample_partition_type() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMesh", "get_sample_partition_type");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void NavigationMesh::set_cell_size(const double cell_size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMesh", "set_cell_size");
	}
	___godot_icall_void_float(mb, (const Object *) this, cell_size);
}

double NavigationMesh::get_cell_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMesh", "get_cell_size");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void NavigationMesh::set_cell_height(const double cell_height) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMesh", "set_cell_height");
	}
	___godot_icall_void_float(mb, (const Object *) this, cell_height);
}

double NavigationMesh::get_cell_height() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMesh", "get_cell_height");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void NavigationMesh::set_agent_height(const double agent_height) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMesh", "set_agent_height");
	}
	___godot_icall_void_float(mb, (const Object *) this, agent_height);
}

double NavigationMesh::get_agent_height() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMesh", "get_agent_height");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void NavigationMesh::set_agent_radius(const double agent_radius) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMesh", "set_agent_radius");
	}
	___godot_icall_void_float(mb, (const Object *) this, agent_radius);
}

double NavigationMesh::get_agent_radius() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMesh", "get_agent_radius");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void NavigationMesh::set_agent_max_climb(const double agent_max_climb) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMesh", "set_agent_max_climb");
	}
	___godot_icall_void_float(mb, (const Object *) this, agent_max_climb);
}

double NavigationMesh::get_agent_max_climb() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMesh", "get_agent_max_climb");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void NavigationMesh::set_agent_max_slope(const double agent_max_slope) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMesh", "set_agent_max_slope");
	}
	___godot_icall_void_float(mb, (const Object *) this, agent_max_slope);
}

double NavigationMesh::get_agent_max_slope() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMesh", "get_agent_max_slope");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void NavigationMesh::set_region_min_size(const double region_min_size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMesh", "set_region_min_size");
	}
	___godot_icall_void_float(mb, (const Object *) this, region_min_size);
}

double NavigationMesh::get_region_min_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMesh", "get_region_min_size");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void NavigationMesh::set_region_merge_size(const double region_merge_size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMesh", "set_region_merge_size");
	}
	___godot_icall_void_float(mb, (const Object *) this, region_merge_size);
}

double NavigationMesh::get_region_merge_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMesh", "get_region_merge_size");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void NavigationMesh::set_edge_max_length(const double edge_max_length) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMesh", "set_edge_max_length");
	}
	___godot_icall_void_float(mb, (const Object *) this, edge_max_length);
}

double NavigationMesh::get_edge_max_length() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMesh", "get_edge_max_length");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void NavigationMesh::set_edge_max_error(const double edge_max_error) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMesh", "set_edge_max_error");
	}
	___godot_icall_void_float(mb, (const Object *) this, edge_max_error);
}

double NavigationMesh::get_edge_max_error() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMesh", "get_edge_max_error");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void NavigationMesh::set_verts_per_poly(const double verts_per_poly) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMesh", "set_verts_per_poly");
	}
	___godot_icall_void_float(mb, (const Object *) this, verts_per_poly);
}

double NavigationMesh::get_verts_per_poly() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMesh", "get_verts_per_poly");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void NavigationMesh::set_detail_sample_distance(const double detail_sample_dist) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMesh", "set_detail_sample_distance");
	}
	___godot_icall_void_float(mb, (const Object *) this, detail_sample_dist);
}

double NavigationMesh::get_detail_sample_distance() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMesh", "get_detail_sample_distance");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void NavigationMesh::set_detail_sample_max_error(const double detail_sample_max_error) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMesh", "set_detail_sample_max_error");
	}
	___godot_icall_void_float(mb, (const Object *) this, detail_sample_max_error);
}

double NavigationMesh::get_detail_sample_max_error() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMesh", "get_detail_sample_max_error");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void NavigationMesh::set_filter_low_hanging_obstacles(const bool filter_low_hanging_obstacles) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMesh", "set_filter_low_hanging_obstacles");
	}
	___godot_icall_void_bool(mb, (const Object *) this, filter_low_hanging_obstacles);
}

bool NavigationMesh::get_filter_low_hanging_obstacles() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMesh", "get_filter_low_hanging_obstacles");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void NavigationMesh::set_filter_ledge_spans(const bool filter_ledge_spans) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMesh", "set_filter_ledge_spans");
	}
	___godot_icall_void_bool(mb, (const Object *) this, filter_ledge_spans);
}

bool NavigationMesh::get_filter_ledge_spans() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMesh", "get_filter_ledge_spans");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void NavigationMesh::set_filter_walkable_low_height_spans(const bool filter_walkable_low_height_spans) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMesh", "set_filter_walkable_low_height_spans");
	}
	___godot_icall_void_bool(mb, (const Object *) this, filter_walkable_low_height_spans);
}

bool NavigationMesh::get_filter_walkable_low_height_spans() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMesh", "get_filter_walkable_low_height_spans");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void NavigationMesh::set_vertices(const PoolVector3Array vertices) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMesh", "set_vertices");
	}
	___godot_icall_void_PoolVector3Array(mb, (const Object *) this, vertices);
}

PoolVector3Array NavigationMesh::get_vertices() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMesh", "get_vertices");
	}
	return ___godot_icall_PoolVector3Array(mb, (const Object *) this);
}

void NavigationMesh::add_polygon(const PoolIntArray polygon) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMesh", "add_polygon");
	}
	___godot_icall_void_PoolIntArray(mb, (const Object *) this, polygon);
}

int64_t NavigationMesh::get_polygon_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMesh", "get_polygon_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

PoolIntArray NavigationMesh::get_polygon(const int64_t idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMesh", "get_polygon");
	}
	return ___godot_icall_PoolIntArray_int(mb, (const Object *) this, idx);
}

void NavigationMesh::clear_polygons() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMesh", "clear_polygons");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void NavigationMesh::create_from_mesh(const Ref<Mesh> mesh) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMesh", "create_from_mesh");
	}
	___godot_icall_void_Object(mb, (const Object *) this, mesh.ptr());
}

void NavigationMesh::_set_polygons(const Array polygons) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMesh", "_set_polygons");
	}
	___godot_icall_void_Array(mb, (const Object *) this, polygons);
}

Array NavigationMesh::_get_polygons() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMesh", "_get_polygons");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

}