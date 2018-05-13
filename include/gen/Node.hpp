#ifndef GODOT_CPP_NODE_HPP
#define GODOT_CPP_NODE_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include "Node.hpp"

#include "Object.hpp"
namespace godot {

class InputEvent;
class InputEventKey;
class Object;
class Node;
class SceneTree;
class Viewport;
class MultiplayerAPI;

class Node : public Object {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Node"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum PauseMode {
		PAUSE_MODE_STOP = 1,
		PAUSE_MODE_INHERIT = 0,
		PAUSE_MODE_PROCESS = 2,
	};
	enum DuplicateFlags {
		DUPLICATE_SIGNALS = 1,
		DUPLICATE_SCRIPTS = 4,
		DUPLICATE_USE_INSTANCING = 8,
		DUPLICATE_GROUPS = 2,
	};
	enum RPCMode {
		RPC_MODE_DISABLED = 0,
		RPC_MODE_SLAVE = 4,
		RPC_MODE_SYNC = 2,
		RPC_MODE_REMOTE = 1,
		RPC_MODE_MASTER = 3,
	};

	// constants
	const static int NOTIFICATION_INTERNAL_PROCESS = 25;
	const static int NOTIFICATION_PHYSICS_PROCESS = 16;
	const static int NOTIFICATION_DRAG_END = 22;
	const static int NOTIFICATION_ENTER_TREE = 10;
	const static int NOTIFICATION_PARENTED = 18;
	const static int NOTIFICATION_MOVED_IN_PARENT = 12;
	const static int NOTIFICATION_READY = 13;
	const static int NOTIFICATION_UNPAUSED = 15;
	const static int NOTIFICATION_PROCESS = 17;
	const static int NOTIFICATION_PAUSED = 14;
	const static int NOTIFICATION_INTERNAL_PHYSICS_PROCESS = 26;
	const static int NOTIFICATION_UNPARENTED = 19;
	const static int NOTIFICATION_DRAG_BEGIN = 21;
	const static int NOTIFICATION_EXIT_TREE = 11;
	const static int NOTIFICATION_PATH_CHANGED = 23;
	const static int NOTIFICATION_TRANSLATION_CHANGED = 24;
	const static int NOTIFICATION_INSTANCED = 20;


	static Node *_new();

	// methods
	void _process(const double delta);
	void _physics_process(const double delta);
	void _enter_tree();
	void _exit_tree();
	void _ready();
	void _input(const Ref<InputEvent> event);
	void _unhandled_input(const Ref<InputEvent> event);
	void _unhandled_key_input(const Ref<InputEventKey> event);
	void add_child_below_node(const Object *node, const Object *child_node, const bool legible_unique_name = false);
	void set_name(const String name);
	String get_name() const;
	void add_child(const Object *node, const bool legible_unique_name = false);
	void remove_child(const Object *node);
	int64_t get_child_count() const;
	Array get_children() const;
	Node *get_child(const int64_t idx) const;
	bool has_node(const NodePath path) const;
	Node *get_node(const NodePath path) const;
	Node *get_parent() const;
	Node *find_node(const String mask, const bool recursive = true, const bool owned = true) const;
	bool has_node_and_resource(const NodePath path) const;
	Array get_node_and_resource(const NodePath path);
	bool is_inside_tree() const;
	bool is_a_parent_of(const Object *node) const;
	bool is_greater_than(const Object *node) const;
	NodePath get_path() const;
	NodePath get_path_to(const Object *node) const;
	void add_to_group(const String group, const bool persistent = false);
	void remove_from_group(const String group);
	bool is_in_group(const String group) const;
	void move_child(const Object *child_node, const int64_t to_position);
	Array get_groups() const;
	void raise();
	void set_owner(const Object *owner);
	Node *get_owner() const;
	void remove_and_skip();
	int64_t get_index() const;
	void print_tree();
	void print_tree_pretty();
	void set_filename(const String filename);
	String get_filename() const;
	void propagate_notification(const int64_t what);
	void propagate_call(const String method, const Array args = Array(), const bool parent_first = false);
	void set_physics_process(const bool enable);
	double get_physics_process_delta_time() const;
	bool is_physics_processing() const;
	double get_process_delta_time() const;
	void set_process(const bool enable);
	bool is_processing() const;
	void set_process_input(const bool enable);
	bool is_processing_input() const;
	void set_process_unhandled_input(const bool enable);
	bool is_processing_unhandled_input() const;
	void set_process_unhandled_key_input(const bool enable);
	bool is_processing_unhandled_key_input() const;
	void set_pause_mode(const int64_t mode);
	Node::PauseMode get_pause_mode() const;
	bool can_process() const;
	void print_stray_nodes();
	int64_t get_position_in_parent() const;
	void set_display_folded(const bool fold);
	bool is_displayed_folded() const;
	void set_process_internal(const bool enable);
	bool is_processing_internal() const;
	void set_physics_process_internal(const bool enable);
	bool is_physics_processing_internal() const;
	SceneTree *get_tree() const;
	Node *duplicate(const int64_t flags = 15) const;
	void replace_by(const Object *node, const bool keep_data = false);
	void set_scene_instance_load_placeholder(const bool load_placeholder);
	bool get_scene_instance_load_placeholder() const;
	Viewport *get_viewport() const;
	void queue_free();
	void request_ready();
	void set_network_master(const int64_t id, const bool recursive = true);
	int64_t get_network_master() const;
	bool is_network_master() const;
	Ref<MultiplayerAPI> get_multiplayer() const;
	Ref<MultiplayerAPI> get_custom_multiplayer() const;
	void set_custom_multiplayer(const Ref<MultiplayerAPI> api);
	void rpc_config(const String method, const int64_t mode);
	void rset_config(const String property, const int64_t mode);
	void _set_import_path(const NodePath import_path);
	NodePath _get_import_path() const;
	Variant rpc(const String method, const Array& __var_args = Array());
	Variant rpc_unreliable(const String method, const Array& __var_args = Array());
	Variant rpc_id(const int64_t peer_id, const String method, const Array& __var_args = Array());
	Variant rpc_unreliable_id(const int64_t peer_id, const String method, const Array& __var_args = Array());
	void rset(const String property, const Variant value);
	void rset_id(const int64_t peer_id, const String property, const Variant value);
	void rset_unreliable(const String property, const Variant value);
	void rset_unreliable_id(const int64_t peer_id, const String property, const Variant value);
	template <class... Args> Variant rpc(const String method, Args... args){
		return rpc(method, Array::make(args...));
	}
	template <class... Args> Variant rpc_unreliable(const String method, Args... args){
		return rpc_unreliable(method, Array::make(args...));
	}
	template <class... Args> Variant rpc_id(const int64_t peer_id, const String method, Args... args){
		return rpc_id(peer_id,method, Array::make(args...));
	}
	template <class... Args> Variant rpc_unreliable_id(const int64_t peer_id, const String method, Args... args){
		return rpc_unreliable_id(peer_id,method, Array::make(args...));
	}

};

}

#endif