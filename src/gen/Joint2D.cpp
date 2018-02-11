#include <Joint2D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *Joint2D::___get_type_tag()
{
	return (void *) &Joint2D::___get_type_tag;
}

void *Joint2D::___get_base_type_tag()
{
	return (void *) &Node2D::___get_type_tag;
}

void Joint2D::set_node_a(const NodePath node) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Joint2D", "set_node_a");
	}
	___godot_icall_void_NodePath(mb, (const Object *) this, node);
}

NodePath Joint2D::get_node_a() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Joint2D", "get_node_a");
	}
	return ___godot_icall_NodePath(mb, (const Object *) this);
}

void Joint2D::set_node_b(const NodePath node) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Joint2D", "set_node_b");
	}
	___godot_icall_void_NodePath(mb, (const Object *) this, node);
}

NodePath Joint2D::get_node_b() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Joint2D", "get_node_b");
	}
	return ___godot_icall_NodePath(mb, (const Object *) this);
}

void Joint2D::set_bias(const double bias) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Joint2D", "set_bias");
	}
	___godot_icall_void_float(mb, (const Object *) this, bias);
}

double Joint2D::get_bias() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Joint2D", "get_bias");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Joint2D::set_exclude_nodes_from_collision(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Joint2D", "set_exclude_nodes_from_collision");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool Joint2D::get_exclude_nodes_from_collision() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Joint2D", "get_exclude_nodes_from_collision");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

}