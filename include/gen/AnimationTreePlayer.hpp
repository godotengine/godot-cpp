#ifndef GODOT_CPP_ANIMATIONTREEPLAYER_HPP
#define GODOT_CPP_ANIMATIONTREEPLAYER_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <AnimationTreePlayer.hpp>

#include <Node.hpp>
namespace godot {

class Animation;

class AnimationTreePlayer : public Node {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "AnimationTreePlayer"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum AnimationProcessMode {
		ANIMATION_PROCESS_IDLE = 1,
		ANIMATION_PROCESS_PHYSICS = 0,
	};
	enum NodeType {
		NODE_ANIMATION = 1,
		NODE_OUTPUT = 0,
		NODE_ONESHOT = 2,
		NODE_MIX = 3,
		NODE_TIMESCALE = 7,
		NODE_TRANSITION = 9,
		NODE_BLEND4 = 6,
		NODE_BLEND3 = 5,
		NODE_BLEND2 = 4,
		NODE_TIMESEEK = 8,
	};

	// constants


	static AnimationTreePlayer *_new();

	// methods
	void add_node(const int64_t type, const String id);
	bool node_exists(const String node) const;
	Error node_rename(const String node, const String new_name);
	AnimationTreePlayer::NodeType node_get_type(const String id) const;
	int64_t node_get_input_count(const String id) const;
	String node_get_input_source(const String id, const int64_t idx) const;
	void animation_node_set_animation(const String id, const Ref<Animation> animation);
	Ref<Animation> animation_node_get_animation(const String id) const;
	void animation_node_set_master_animation(const String id, const String source);
	String animation_node_get_master_animation(const String id) const;
	void animation_node_set_filter_path(const String id, const NodePath path, const bool enable);
	void oneshot_node_set_fadein_time(const String id, const double time_sec);
	double oneshot_node_get_fadein_time(const String id) const;
	void oneshot_node_set_fadeout_time(const String id, const double time_sec);
	double oneshot_node_get_fadeout_time(const String id) const;
	void oneshot_node_set_autorestart(const String id, const bool enable);
	void oneshot_node_set_autorestart_delay(const String id, const double delay_sec);
	void oneshot_node_set_autorestart_random_delay(const String id, const double rand_sec);
	bool oneshot_node_has_autorestart(const String id) const;
	double oneshot_node_get_autorestart_delay(const String id) const;
	double oneshot_node_get_autorestart_random_delay(const String id) const;
	void oneshot_node_start(const String id);
	void oneshot_node_stop(const String id);
	bool oneshot_node_is_active(const String id) const;
	void oneshot_node_set_filter_path(const String id, const NodePath path, const bool enable);
	void mix_node_set_amount(const String id, const double ratio);
	double mix_node_get_amount(const String id) const;
	void blend2_node_set_amount(const String id, const double blend);
	double blend2_node_get_amount(const String id) const;
	void blend2_node_set_filter_path(const String id, const NodePath path, const bool enable);
	void blend3_node_set_amount(const String id, const double blend);
	double blend3_node_get_amount(const String id) const;
	void blend4_node_set_amount(const String id, const Vector2 blend);
	Vector2 blend4_node_get_amount(const String id) const;
	void timescale_node_set_scale(const String id, const double scale);
	double timescale_node_get_scale(const String id) const;
	void timeseek_node_seek(const String id, const double seconds);
	void transition_node_set_input_count(const String id, const int64_t count);
	int64_t transition_node_get_input_count(const String id) const;
	void transition_node_delete_input(const String id, const int64_t input_idx);
	void transition_node_set_input_auto_advance(const String id, const int64_t input_idx, const bool enable);
	bool transition_node_has_input_auto_advance(const String id, const int64_t input_idx) const;
	void transition_node_set_xfade_time(const String id, const double time_sec);
	double transition_node_get_xfade_time(const String id) const;
	void transition_node_set_current(const String id, const int64_t input_idx);
	int64_t transition_node_get_current(const String id) const;
	void node_set_position(const String id, const Vector2 screen_position);
	Vector2 node_get_position(const String id) const;
	void remove_node(const String id);
	Error connect_nodes(const String id, const String dst_id, const int64_t dst_input_idx);
	bool are_nodes_connected(const String id, const String dst_id, const int64_t dst_input_idx) const;
	void disconnect_nodes(const String id, const int64_t dst_input_idx);
	void set_active(const bool enabled);
	bool is_active() const;
	void set_base_path(const NodePath path);
	NodePath get_base_path() const;
	void set_master_player(const NodePath nodepath);
	NodePath get_master_player() const;
	PoolStringArray get_node_list();
	void set_animation_process_mode(const int64_t mode);
	AnimationTreePlayer::AnimationProcessMode get_animation_process_mode() const;
	void advance(const double delta);
	void reset();
	void recompute_caches();

};

}

#endif