#ifndef GODOT_CPP_JOINT2D_HPP
#define GODOT_CPP_JOINT2D_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Node2D.hpp"
namespace godot {


class Joint2D : public Node2D {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Joint2D"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants

	// methods
	void set_node_a(const NodePath node);
	NodePath get_node_a() const;
	void set_node_b(const NodePath node);
	NodePath get_node_b() const;
	void set_bias(const double bias);
	double get_bias() const;
	void set_exclude_nodes_from_collision(const bool enable);
	bool get_exclude_nodes_from_collision() const;

};

}

#endif