#ifndef GODOT_CPP_ASTAR_HPP
#define GODOT_CPP_ASTAR_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Reference.hpp>
namespace godot {


class AStar : public Reference {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "AStar"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static AStar *_new();

	// methods
	double _estimate_cost(const int64_t from_id, const int64_t to_id);
	double _compute_cost(const int64_t from_id, const int64_t to_id);
	int64_t get_available_point_id() const;
	void add_point(const int64_t id, const Vector3 position, const double weight_scale = 1);
	Vector3 get_point_position(const int64_t id) const;
	void set_point_position(const int64_t id, const Vector3 position);
	double get_point_weight_scale(const int64_t id) const;
	void set_point_weight_scale(const int64_t id, const double weight_scale);
	void remove_point(const int64_t id);
	bool has_point(const int64_t id) const;
	Array get_points();
	PoolIntArray get_point_connections(const int64_t id);
	void connect_points(const int64_t id, const int64_t to_id, const bool bidirectional = true);
	void disconnect_points(const int64_t id, const int64_t to_id);
	bool are_points_connected(const int64_t id, const int64_t to_id) const;
	void clear();
	int64_t get_closest_point(const Vector3 to_position) const;
	Vector3 get_closest_position_in_segment(const Vector3 to_position) const;
	PoolVector3Array get_point_path(const int64_t from_id, const int64_t to_id);
	PoolIntArray get_id_path(const int64_t from_id, const int64_t to_id);

};

}

#endif