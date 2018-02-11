#include <Joint.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *Joint::___get_type_tag()
{
	return (void *) &Joint::___get_type_tag;
}

void *Joint::___get_base_type_tag()
{
	return (void *) &Spatial::___get_type_tag;
}

void Joint::set_node_a(const NodePath node) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Joint", "set_node_a");
	}
	___godot_icall_void_NodePath(mb, (const Object *) this, node);
}

NodePath Joint::get_node_a() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Joint", "get_node_a");
	}
	return ___godot_icall_NodePath(mb, (const Object *) this);
}

void Joint::set_node_b(const NodePath node) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Joint", "set_node_b");
	}
	___godot_icall_void_NodePath(mb, (const Object *) this, node);
}

NodePath Joint::get_node_b() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Joint", "get_node_b");
	}
	return ___godot_icall_NodePath(mb, (const Object *) this);
}

void Joint::set_solver_priority(const int64_t priority) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Joint", "set_solver_priority");
	}
	___godot_icall_void_int(mb, (const Object *) this, priority);
}

int64_t Joint::get_solver_priority() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Joint", "get_solver_priority");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void Joint::set_exclude_nodes_from_collision(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Joint", "set_exclude_nodes_from_collision");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool Joint::get_exclude_nodes_from_collision() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Joint", "get_exclude_nodes_from_collision");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

}