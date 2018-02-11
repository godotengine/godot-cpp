#ifndef GODOT_CPP_JOINT_HPP
#define GODOT_CPP_JOINT_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Spatial.hpp>
namespace godot {


class Joint : public Spatial {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Joint"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants

	// methods
	void set_node_a(const NodePath node);
	NodePath get_node_a() const;
	void set_node_b(const NodePath node);
	NodePath get_node_b() const;
	void set_solver_priority(const int64_t priority);
	int64_t get_solver_priority() const;
	void set_exclude_nodes_from_collision(const bool enable);
	bool get_exclude_nodes_from_collision() const;

};

}

#endif