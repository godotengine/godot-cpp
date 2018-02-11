#include <Node.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <InputEvent.hpp>
#include <InputEventKey.hpp>
#include <Object.hpp>
#include <Node.hpp>
#include <SceneTree.hpp>
#include <Viewport.hpp>


namespace godot {


void *Node::___get_type_tag()
{
	return (void *) &Node::___get_type_tag;
}

void *Node::___get_base_type_tag()
{
	return (void *) &Object::___get_type_tag;
}

Node *Node::_new()
{
	return (Node *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Node")());
}
void Node::_process(const double delta) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "_process");
	}
	___godot_icall_void_float(mb, (const Object *) this, delta);
}

void Node::_physics_process(const double delta) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "_physics_process");
	}
	___godot_icall_void_float(mb, (const Object *) this, delta);
}

void Node::_enter_tree() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "_enter_tree");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Node::_exit_tree() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "_exit_tree");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Node::_ready() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "_ready");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Node::_input(const Ref<InputEvent> event) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "_input");
	}
	___godot_icall_void_Object(mb, (const Object *) this, event.ptr());
}

void Node::_unhandled_input(const Ref<InputEvent> event) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "_unhandled_input");
	}
	___godot_icall_void_Object(mb, (const Object *) this, event.ptr());
}

void Node::_unhandled_key_input(const Ref<InputEventKey> event) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "_unhandled_key_input");
	}
	___godot_icall_void_Object(mb, (const Object *) this, event.ptr());
}

void Node::add_child_below_node(const Object *node, const Object *child_node, const bool legible_unique_name) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "add_child_below_node");
	}
	___godot_icall_void_Object_Object_bool(mb, (const Object *) this, node, child_node, legible_unique_name);
}

void Node::set_name(const String name) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "set_name");
	}
	___godot_icall_void_String(mb, (const Object *) this, name);
}

String Node::get_name() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "get_name");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void Node::add_child(const Object *node, const bool legible_unique_name) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "add_child");
	}
	___godot_icall_void_Object_bool(mb, (const Object *) this, node, legible_unique_name);
}

void Node::remove_child(const Object *node) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "remove_child");
	}
	___godot_icall_void_Object(mb, (const Object *) this, node);
}

int64_t Node::get_child_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "get_child_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

Array Node::get_children() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "get_children");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

Node *Node::get_child(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "get_child");
	}
	return (Node *) ___godot_icall_Object_int(mb, (const Object *) this, idx);
}

bool Node::has_node(const NodePath path) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "has_node");
	}
	return ___godot_icall_bool_NodePath(mb, (const Object *) this, path);
}

Node *Node::get_node(const NodePath path) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "get_node");
	}
	return (Node *) ___godot_icall_Object_NodePath(mb, (const Object *) this, path);
}

Node *Node::get_parent() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "get_parent");
	}
	return (Node *) ___godot_icall_Object(mb, (const Object *) this);
}

Node *Node::find_node(const String mask, const bool recursive, const bool owned) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "find_node");
	}
	return (Node *) ___godot_icall_Object_String_bool_bool(mb, (const Object *) this, mask, recursive, owned);
}

bool Node::has_node_and_resource(const NodePath path) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "has_node_and_resource");
	}
	return ___godot_icall_bool_NodePath(mb, (const Object *) this, path);
}

Array Node::get_node_and_resource(const NodePath path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "get_node_and_resource");
	}
	return ___godot_icall_Array_NodePath(mb, (const Object *) this, path);
}

bool Node::is_inside_tree() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "is_inside_tree");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

bool Node::is_a_parent_of(const Object *node) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "is_a_parent_of");
	}
	return ___godot_icall_bool_Object(mb, (const Object *) this, node);
}

bool Node::is_greater_than(const Object *node) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "is_greater_than");
	}
	return ___godot_icall_bool_Object(mb, (const Object *) this, node);
}

NodePath Node::get_path() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "get_path");
	}
	return ___godot_icall_NodePath(mb, (const Object *) this);
}

NodePath Node::get_path_to(const Object *node) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "get_path_to");
	}
	return ___godot_icall_NodePath_Object(mb, (const Object *) this, node);
}

void Node::add_to_group(const String group, const bool persistent) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "add_to_group");
	}
	___godot_icall_void_String_bool(mb, (const Object *) this, group, persistent);
}

void Node::remove_from_group(const String group) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "remove_from_group");
	}
	___godot_icall_void_String(mb, (const Object *) this, group);
}

bool Node::is_in_group(const String group) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "is_in_group");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, group);
}

void Node::move_child(const Object *child_node, const int64_t to_position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "move_child");
	}
	___godot_icall_void_Object_int(mb, (const Object *) this, child_node, to_position);
}

Array Node::get_groups() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "get_groups");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

void Node::raise() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "raise");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Node::set_owner(const Object *owner) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "set_owner");
	}
	___godot_icall_void_Object(mb, (const Object *) this, owner);
}

Node *Node::get_owner() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "get_owner");
	}
	return (Node *) ___godot_icall_Object(mb, (const Object *) this);
}

void Node::remove_and_skip() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "remove_and_skip");
	}
	___godot_icall_void(mb, (const Object *) this);
}

int64_t Node::get_index() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "get_index");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void Node::print_tree() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "print_tree");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Node::set_filename(const String filename) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "set_filename");
	}
	___godot_icall_void_String(mb, (const Object *) this, filename);
}

String Node::get_filename() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "get_filename");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void Node::propagate_notification(const int64_t what) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "propagate_notification");
	}
	___godot_icall_void_int(mb, (const Object *) this, what);
}

void Node::propagate_call(const String method, const Array args, const bool parent_first) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "propagate_call");
	}
	___godot_icall_void_String_Array_bool(mb, (const Object *) this, method, args, parent_first);
}

void Node::set_physics_process(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "set_physics_process");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

double Node::get_physics_process_delta_time() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "get_physics_process_delta_time");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

bool Node::is_physics_processing() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "is_physics_processing");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

double Node::get_process_delta_time() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "get_process_delta_time");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Node::set_process(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "set_process");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool Node::is_processing() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "is_processing");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Node::set_process_input(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "set_process_input");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool Node::is_processing_input() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "is_processing_input");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Node::set_process_unhandled_input(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "set_process_unhandled_input");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool Node::is_processing_unhandled_input() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "is_processing_unhandled_input");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Node::set_process_unhandled_key_input(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "set_process_unhandled_key_input");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool Node::is_processing_unhandled_key_input() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "is_processing_unhandled_key_input");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Node::set_pause_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "set_pause_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

Node::PauseMode Node::get_pause_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "get_pause_mode");
	}
	return (Node::PauseMode) ___godot_icall_int(mb, (const Object *) this);
}

bool Node::can_process() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "can_process");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Node::print_stray_nodes() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "print_stray_nodes");
	}
	___godot_icall_void(mb, (const Object *) this);
}

int64_t Node::get_position_in_parent() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "get_position_in_parent");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void Node::set_display_folded(const bool fold) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "set_display_folded");
	}
	___godot_icall_void_bool(mb, (const Object *) this, fold);
}

bool Node::is_displayed_folded() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "is_displayed_folded");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Node::set_process_internal(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "set_process_internal");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool Node::is_processing_internal() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "is_processing_internal");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Node::set_physics_process_internal(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "set_physics_process_internal");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool Node::is_physics_processing_internal() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "is_physics_processing_internal");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

SceneTree *Node::get_tree() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "get_tree");
	}
	return (SceneTree *) ___godot_icall_Object(mb, (const Object *) this);
}

Node *Node::duplicate(const int64_t flags) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "duplicate");
	}
	return (Node *) ___godot_icall_Object_int(mb, (const Object *) this, flags);
}

void Node::replace_by(const Object *node, const bool keep_data) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "replace_by");
	}
	___godot_icall_void_Object_bool(mb, (const Object *) this, node, keep_data);
}

void Node::set_scene_instance_load_placeholder(const bool load_placeholder) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "set_scene_instance_load_placeholder");
	}
	___godot_icall_void_bool(mb, (const Object *) this, load_placeholder);
}

bool Node::get_scene_instance_load_placeholder() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "get_scene_instance_load_placeholder");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

Viewport *Node::get_viewport() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "get_viewport");
	}
	return (Viewport *) ___godot_icall_Object(mb, (const Object *) this);
}

void Node::queue_free() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "queue_free");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Node::request_ready() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "request_ready");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Node::set_network_master(const int64_t id, const bool recursive) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "set_network_master");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, id, recursive);
}

int64_t Node::get_network_master() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "get_network_master");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

bool Node::is_network_master() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "is_network_master");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Node::rpc_config(const String method, const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "rpc_config");
	}
	___godot_icall_void_String_int(mb, (const Object *) this, method, mode);
}

void Node::rset_config(const String property, const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "rset_config");
	}
	___godot_icall_void_String_int(mb, (const Object *) this, property, mode);
}

void Node::_set_import_path(const NodePath import_path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "_set_import_path");
	}
	___godot_icall_void_NodePath(mb, (const Object *) this, import_path);
}

NodePath Node::_get_import_path() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "_get_import_path");
	}
	return ___godot_icall_NodePath(mb, (const Object *) this);
}

Variant Node::rpc(const String method, const Array& __var_args) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "rpc");
	}
	Variant __given_args[1];
	godot::api->godot_variant_new_nil((godot_variant *) &__given_args[0]);

	__given_args[0] = method;

	godot_variant **__args = (godot_variant **) alloca(sizeof(godot_variant *) * (__var_args.size() + 1));

	__args[0] = (godot_variant *) &__given_args[0];

	for (int i = 0; i < __var_args.size(); i++) {
		__args[i + 1] = (godot_variant *) &((Array &) __var_args)[i];
	}

	Variant __result;
	*(godot_variant *) &__result = godot::api->godot_method_bind_call(mb, ((const Object *) this)->_owner, (const godot_variant **) __args, (__var_args.size() + 1), nullptr);

	godot::api->godot_variant_destroy((godot_variant *) &__given_args[0]);

	return __result;
}

Variant Node::rpc_unreliable(const String method, const Array& __var_args) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "rpc_unreliable");
	}
	Variant __given_args[1];
	godot::api->godot_variant_new_nil((godot_variant *) &__given_args[0]);

	__given_args[0] = method;

	godot_variant **__args = (godot_variant **) alloca(sizeof(godot_variant *) * (__var_args.size() + 1));

	__args[0] = (godot_variant *) &__given_args[0];

	for (int i = 0; i < __var_args.size(); i++) {
		__args[i + 1] = (godot_variant *) &((Array &) __var_args)[i];
	}

	Variant __result;
	*(godot_variant *) &__result = godot::api->godot_method_bind_call(mb, ((const Object *) this)->_owner, (const godot_variant **) __args, (__var_args.size() + 1), nullptr);

	godot::api->godot_variant_destroy((godot_variant *) &__given_args[0]);

	return __result;
}

Variant Node::rpc_id(const int64_t peer_id, const String method, const Array& __var_args) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "rpc_id");
	}
	Variant __given_args[2];
	godot::api->godot_variant_new_nil((godot_variant *) &__given_args[0]);
	godot::api->godot_variant_new_nil((godot_variant *) &__given_args[1]);

	__given_args[0] = peer_id;
	__given_args[1] = method;

	godot_variant **__args = (godot_variant **) alloca(sizeof(godot_variant *) * (__var_args.size() + 2));

	__args[0] = (godot_variant *) &__given_args[0];
	__args[1] = (godot_variant *) &__given_args[1];

	for (int i = 0; i < __var_args.size(); i++) {
		__args[i + 2] = (godot_variant *) &((Array &) __var_args)[i];
	}

	Variant __result;
	*(godot_variant *) &__result = godot::api->godot_method_bind_call(mb, ((const Object *) this)->_owner, (const godot_variant **) __args, (__var_args.size() + 2), nullptr);

	godot::api->godot_variant_destroy((godot_variant *) &__given_args[0]);
	godot::api->godot_variant_destroy((godot_variant *) &__given_args[1]);

	return __result;
}

Variant Node::rpc_unreliable_id(const int64_t peer_id, const String method, const Array& __var_args) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "rpc_unreliable_id");
	}
	Variant __given_args[2];
	godot::api->godot_variant_new_nil((godot_variant *) &__given_args[0]);
	godot::api->godot_variant_new_nil((godot_variant *) &__given_args[1]);

	__given_args[0] = peer_id;
	__given_args[1] = method;

	godot_variant **__args = (godot_variant **) alloca(sizeof(godot_variant *) * (__var_args.size() + 2));

	__args[0] = (godot_variant *) &__given_args[0];
	__args[1] = (godot_variant *) &__given_args[1];

	for (int i = 0; i < __var_args.size(); i++) {
		__args[i + 2] = (godot_variant *) &((Array &) __var_args)[i];
	}

	Variant __result;
	*(godot_variant *) &__result = godot::api->godot_method_bind_call(mb, ((const Object *) this)->_owner, (const godot_variant **) __args, (__var_args.size() + 2), nullptr);

	godot::api->godot_variant_destroy((godot_variant *) &__given_args[0]);
	godot::api->godot_variant_destroy((godot_variant *) &__given_args[1]);

	return __result;
}

void Node::rset(const String property, const Variant value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "rset");
	}
	___godot_icall_void_String_Variant(mb, (const Object *) this, property, value);
}

void Node::rset_id(const int64_t peer_id, const String property, const Variant value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "rset_id");
	}
	___godot_icall_void_int_String_Variant(mb, (const Object *) this, peer_id, property, value);
}

void Node::rset_unreliable(const String property, const Variant value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "rset_unreliable");
	}
	___godot_icall_void_String_Variant(mb, (const Object *) this, property, value);
}

void Node::rset_unreliable_id(const int64_t peer_id, const String property, const Variant value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node", "rset_unreliable_id");
	}
	___godot_icall_void_int_String_Variant(mb, (const Object *) this, peer_id, property, value);
}

}