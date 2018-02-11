#include <AStar.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *AStar::___get_type_tag()
{
	return (void *) &AStar::___get_type_tag;
}

void *AStar::___get_base_type_tag()
{
	return (void *) &Reference::___get_type_tag;
}

AStar *AStar::_new()
{
	return (AStar *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"AStar")());
}
double AStar::_estimate_cost(const int64_t from_id, const int64_t to_id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AStar", "_estimate_cost");
	}
	return ___godot_icall_float_int_int(mb, (const Object *) this, from_id, to_id);
}

double AStar::_compute_cost(const int64_t from_id, const int64_t to_id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AStar", "_compute_cost");
	}
	return ___godot_icall_float_int_int(mb, (const Object *) this, from_id, to_id);
}

int64_t AStar::get_available_point_id() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AStar", "get_available_point_id");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void AStar::add_point(const int64_t id, const Vector3 position, const double weight_scale) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AStar", "add_point");
	}
	___godot_icall_void_int_Vector3_float(mb, (const Object *) this, id, position, weight_scale);
}

Vector3 AStar::get_point_position(const int64_t id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AStar", "get_point_position");
	}
	return ___godot_icall_Vector3_int(mb, (const Object *) this, id);
}

void AStar::set_point_position(const int64_t id, const Vector3 position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AStar", "set_point_position");
	}
	___godot_icall_void_int_Vector3(mb, (const Object *) this, id, position);
}

double AStar::get_point_weight_scale(const int64_t id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AStar", "get_point_weight_scale");
	}
	return ___godot_icall_float_int(mb, (const Object *) this, id);
}

void AStar::set_point_weight_scale(const int64_t id, const double weight_scale) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AStar", "set_point_weight_scale");
	}
	___godot_icall_void_int_float(mb, (const Object *) this, id, weight_scale);
}

void AStar::remove_point(const int64_t id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AStar", "remove_point");
	}
	___godot_icall_void_int(mb, (const Object *) this, id);
}

bool AStar::has_point(const int64_t id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AStar", "has_point");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, id);
}

Array AStar::get_points() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AStar", "get_points");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

PoolIntArray AStar::get_point_connections(const int64_t id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AStar", "get_point_connections");
	}
	return ___godot_icall_PoolIntArray_int(mb, (const Object *) this, id);
}

void AStar::connect_points(const int64_t id, const int64_t to_id, const bool bidirectional) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AStar", "connect_points");
	}
	___godot_icall_void_int_int_bool(mb, (const Object *) this, id, to_id, bidirectional);
}

void AStar::disconnect_points(const int64_t id, const int64_t to_id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AStar", "disconnect_points");
	}
	___godot_icall_void_int_int(mb, (const Object *) this, id, to_id);
}

bool AStar::are_points_connected(const int64_t id, const int64_t to_id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AStar", "are_points_connected");
	}
	return ___godot_icall_bool_int_int(mb, (const Object *) this, id, to_id);
}

void AStar::clear() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AStar", "clear");
	}
	___godot_icall_void(mb, (const Object *) this);
}

int64_t AStar::get_closest_point(const Vector3 to_position) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AStar", "get_closest_point");
	}
	return ___godot_icall_int_Vector3(mb, (const Object *) this, to_position);
}

Vector3 AStar::get_closest_position_in_segment(const Vector3 to_position) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AStar", "get_closest_position_in_segment");
	}
	return ___godot_icall_Vector3_Vector3(mb, (const Object *) this, to_position);
}

PoolVector3Array AStar::get_point_path(const int64_t from_id, const int64_t to_id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AStar", "get_point_path");
	}
	return ___godot_icall_PoolVector3Array_int_int(mb, (const Object *) this, from_id, to_id);
}

PoolIntArray AStar::get_id_path(const int64_t from_id, const int64_t to_id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AStar", "get_id_path");
	}
	return ___godot_icall_PoolIntArray_int_int(mb, (const Object *) this, from_id, to_id);
}

}