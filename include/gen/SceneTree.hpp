#ifndef GODOT_CPP_SCENETREE_HPP
#define GODOT_CPP_SCENETREE_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <MainLoop.hpp>
namespace godot {

class Viewport;
class Object;
class Node;
class SceneTreeTimer;
class PackedScene;
class NetworkedMultiplayerPeer;

class SceneTree : public MainLoop {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "SceneTree"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum StretchAspect {
		STRETCH_ASPECT_KEEP_HEIGHT = 3,
		STRETCH_ASPECT_KEEP_WIDTH = 2,
		STRETCH_ASPECT_EXPAND = 4,
		STRETCH_ASPECT_KEEP = 1,
		STRETCH_ASPECT_IGNORE = 0,
	};
	enum GroupCallFlags {
		GROUP_CALL_REVERSE = 1,
		GROUP_CALL_REALTIME = 2,
		GROUP_CALL_DEFAULT = 0,
		GROUP_CALL_UNIQUE = 4,
	};
	enum StretchMode {
		STRETCH_MODE_2D = 1,
		STRETCH_MODE_VIEWPORT = 2,
		STRETCH_MODE_DISABLED = 0,
	};

	// constants


	static SceneTree *_new();

	// methods
	Viewport *get_root() const;
	bool has_group(const String name) const;
	void set_auto_accept_quit(const bool enabled);
	void set_quit_on_go_back(const bool enabled);
	void set_debug_collisions_hint(const bool enable);
	bool is_debugging_collisions_hint() const;
	void set_debug_navigation_hint(const bool enable);
	bool is_debugging_navigation_hint() const;
	void set_edited_scene_root(const Object *scene);
	Node *get_edited_scene_root() const;
	void set_pause(const bool enable);
	bool is_paused() const;
	void set_input_as_handled();
	bool is_input_handled();
	Ref<SceneTreeTimer> create_timer(const double time_sec, const bool pause_mode_process = true);
	int64_t get_node_count() const;
	int64_t get_frame() const;
	void quit();
	void set_screen_stretch(const int64_t mode, const int64_t aspect, const Vector2 minsize, const double shrink = 1);
	void queue_delete(const Object *obj);
	Variant call_group_flags(const int64_t flags, const String group, const String method, const Array& __var_args = Array());
	void notify_group_flags(const int64_t call_flags, const String group, const int64_t notification);
	void set_group_flags(const int64_t call_flags, const String group, const String property, const Variant value);
	Variant call_group(const String group, const String method, const Array& __var_args = Array());
	void notify_group(const String group, const int64_t notification);
	void set_group(const String group, const String property, const Variant value);
	Array get_nodes_in_group(const String group);
	void set_current_scene(const Object *child_node);
	Node *get_current_scene() const;
	Error change_scene(const String path);
	Error change_scene_to(const Ref<PackedScene> packed_scene);
	Error reload_current_scene();
	void _change_scene(const Object *arg0);
	void set_network_peer(const Ref<NetworkedMultiplayerPeer> peer);
	Ref<NetworkedMultiplayerPeer> get_network_peer() const;
	bool is_network_server() const;
	bool has_network_peer() const;
	PoolIntArray get_network_connected_peers() const;
	int64_t get_network_unique_id() const;
	int64_t get_rpc_sender_id() const;
	void set_refuse_new_network_connections(const bool refuse);
	bool is_refusing_new_network_connections() const;
	void _network_peer_connected(const int64_t arg0);
	void _network_peer_disconnected(const int64_t arg0);
	void _connected_to_server();
	void _connection_failed();
	void _server_disconnected();
	void set_use_font_oversampling(const bool enable);
	bool is_using_font_oversampling() const;
	template <class... Args> Variant call_group_flags(const int64_t flags, const String group, const String method, Args... args){
		return call_group_flags(flags,group,method, Array::make(args...));
	}
	template <class... Args> Variant call_group(const String group, const String method, Args... args){
		return call_group(group,method, Array::make(args...));
	}

};

}

#endif