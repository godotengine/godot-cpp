#include <AnimationTreePlayer.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Animation.hpp>


namespace godot {


void *AnimationTreePlayer::___get_type_tag()
{
	return (void *) &AnimationTreePlayer::___get_type_tag;
}

void *AnimationTreePlayer::___get_base_type_tag()
{
	return (void *) &Node::___get_type_tag;
}

AnimationTreePlayer *AnimationTreePlayer::_new()
{
	return (AnimationTreePlayer *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"AnimationTreePlayer")());
}
void AnimationTreePlayer::add_node(const int64_t type, const String id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "add_node");
	}
	___godot_icall_void_int_String(mb, (const Object *) this, type, id);
}

bool AnimationTreePlayer::node_exists(const String node) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "node_exists");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, node);
}

Error AnimationTreePlayer::node_rename(const String node, const String new_name) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "node_rename");
	}
	return (Error) ___godot_icall_int_String_String(mb, (const Object *) this, node, new_name);
}

AnimationTreePlayer::NodeType AnimationTreePlayer::node_get_type(const String id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "node_get_type");
	}
	return (AnimationTreePlayer::NodeType) ___godot_icall_int_String(mb, (const Object *) this, id);
}

int64_t AnimationTreePlayer::node_get_input_count(const String id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "node_get_input_count");
	}
	return ___godot_icall_int_String(mb, (const Object *) this, id);
}

String AnimationTreePlayer::node_get_input_source(const String id, const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "node_get_input_source");
	}
	return ___godot_icall_String_String_int(mb, (const Object *) this, id, idx);
}

void AnimationTreePlayer::animation_node_set_animation(const String id, const Ref<Animation> animation) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "animation_node_set_animation");
	}
	___godot_icall_void_String_Object(mb, (const Object *) this, id, animation.ptr());
}

Ref<Animation> AnimationTreePlayer::animation_node_get_animation(const String id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "animation_node_get_animation");
	}
	return Ref<Animation>::__internal_constructor(___godot_icall_Object_String(mb, (const Object *) this, id));
}

void AnimationTreePlayer::animation_node_set_master_animation(const String id, const String source) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "animation_node_set_master_animation");
	}
	___godot_icall_void_String_String(mb, (const Object *) this, id, source);
}

String AnimationTreePlayer::animation_node_get_master_animation(const String id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "animation_node_get_master_animation");
	}
	return ___godot_icall_String_String(mb, (const Object *) this, id);
}

void AnimationTreePlayer::animation_node_set_filter_path(const String id, const NodePath path, const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "animation_node_set_filter_path");
	}
	___godot_icall_void_String_NodePath_bool(mb, (const Object *) this, id, path, enable);
}

void AnimationTreePlayer::oneshot_node_set_fadein_time(const String id, const double time_sec) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "oneshot_node_set_fadein_time");
	}
	___godot_icall_void_String_float(mb, (const Object *) this, id, time_sec);
}

double AnimationTreePlayer::oneshot_node_get_fadein_time(const String id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "oneshot_node_get_fadein_time");
	}
	return ___godot_icall_float_String(mb, (const Object *) this, id);
}

void AnimationTreePlayer::oneshot_node_set_fadeout_time(const String id, const double time_sec) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "oneshot_node_set_fadeout_time");
	}
	___godot_icall_void_String_float(mb, (const Object *) this, id, time_sec);
}

double AnimationTreePlayer::oneshot_node_get_fadeout_time(const String id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "oneshot_node_get_fadeout_time");
	}
	return ___godot_icall_float_String(mb, (const Object *) this, id);
}

void AnimationTreePlayer::oneshot_node_set_autorestart(const String id, const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "oneshot_node_set_autorestart");
	}
	___godot_icall_void_String_bool(mb, (const Object *) this, id, enable);
}

void AnimationTreePlayer::oneshot_node_set_autorestart_delay(const String id, const double delay_sec) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "oneshot_node_set_autorestart_delay");
	}
	___godot_icall_void_String_float(mb, (const Object *) this, id, delay_sec);
}

void AnimationTreePlayer::oneshot_node_set_autorestart_random_delay(const String id, const double rand_sec) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "oneshot_node_set_autorestart_random_delay");
	}
	___godot_icall_void_String_float(mb, (const Object *) this, id, rand_sec);
}

bool AnimationTreePlayer::oneshot_node_has_autorestart(const String id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "oneshot_node_has_autorestart");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, id);
}

double AnimationTreePlayer::oneshot_node_get_autorestart_delay(const String id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "oneshot_node_get_autorestart_delay");
	}
	return ___godot_icall_float_String(mb, (const Object *) this, id);
}

double AnimationTreePlayer::oneshot_node_get_autorestart_random_delay(const String id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "oneshot_node_get_autorestart_random_delay");
	}
	return ___godot_icall_float_String(mb, (const Object *) this, id);
}

void AnimationTreePlayer::oneshot_node_start(const String id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "oneshot_node_start");
	}
	___godot_icall_void_String(mb, (const Object *) this, id);
}

void AnimationTreePlayer::oneshot_node_stop(const String id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "oneshot_node_stop");
	}
	___godot_icall_void_String(mb, (const Object *) this, id);
}

bool AnimationTreePlayer::oneshot_node_is_active(const String id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "oneshot_node_is_active");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, id);
}

void AnimationTreePlayer::oneshot_node_set_filter_path(const String id, const NodePath path, const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "oneshot_node_set_filter_path");
	}
	___godot_icall_void_String_NodePath_bool(mb, (const Object *) this, id, path, enable);
}

void AnimationTreePlayer::mix_node_set_amount(const String id, const double ratio) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "mix_node_set_amount");
	}
	___godot_icall_void_String_float(mb, (const Object *) this, id, ratio);
}

double AnimationTreePlayer::mix_node_get_amount(const String id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "mix_node_get_amount");
	}
	return ___godot_icall_float_String(mb, (const Object *) this, id);
}

void AnimationTreePlayer::blend2_node_set_amount(const String id, const double blend) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "blend2_node_set_amount");
	}
	___godot_icall_void_String_float(mb, (const Object *) this, id, blend);
}

double AnimationTreePlayer::blend2_node_get_amount(const String id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "blend2_node_get_amount");
	}
	return ___godot_icall_float_String(mb, (const Object *) this, id);
}

void AnimationTreePlayer::blend2_node_set_filter_path(const String id, const NodePath path, const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "blend2_node_set_filter_path");
	}
	___godot_icall_void_String_NodePath_bool(mb, (const Object *) this, id, path, enable);
}

void AnimationTreePlayer::blend3_node_set_amount(const String id, const double blend) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "blend3_node_set_amount");
	}
	___godot_icall_void_String_float(mb, (const Object *) this, id, blend);
}

double AnimationTreePlayer::blend3_node_get_amount(const String id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "blend3_node_get_amount");
	}
	return ___godot_icall_float_String(mb, (const Object *) this, id);
}

void AnimationTreePlayer::blend4_node_set_amount(const String id, const Vector2 blend) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "blend4_node_set_amount");
	}
	___godot_icall_void_String_Vector2(mb, (const Object *) this, id, blend);
}

Vector2 AnimationTreePlayer::blend4_node_get_amount(const String id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "blend4_node_get_amount");
	}
	return ___godot_icall_Vector2_String(mb, (const Object *) this, id);
}

void AnimationTreePlayer::timescale_node_set_scale(const String id, const double scale) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "timescale_node_set_scale");
	}
	___godot_icall_void_String_float(mb, (const Object *) this, id, scale);
}

double AnimationTreePlayer::timescale_node_get_scale(const String id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "timescale_node_get_scale");
	}
	return ___godot_icall_float_String(mb, (const Object *) this, id);
}

void AnimationTreePlayer::timeseek_node_seek(const String id, const double seconds) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "timeseek_node_seek");
	}
	___godot_icall_void_String_float(mb, (const Object *) this, id, seconds);
}

void AnimationTreePlayer::transition_node_set_input_count(const String id, const int64_t count) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "transition_node_set_input_count");
	}
	___godot_icall_void_String_int(mb, (const Object *) this, id, count);
}

int64_t AnimationTreePlayer::transition_node_get_input_count(const String id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "transition_node_get_input_count");
	}
	return ___godot_icall_int_String(mb, (const Object *) this, id);
}

void AnimationTreePlayer::transition_node_delete_input(const String id, const int64_t input_idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "transition_node_delete_input");
	}
	___godot_icall_void_String_int(mb, (const Object *) this, id, input_idx);
}

void AnimationTreePlayer::transition_node_set_input_auto_advance(const String id, const int64_t input_idx, const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "transition_node_set_input_auto_advance");
	}
	___godot_icall_void_String_int_bool(mb, (const Object *) this, id, input_idx, enable);
}

bool AnimationTreePlayer::transition_node_has_input_auto_advance(const String id, const int64_t input_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "transition_node_has_input_auto_advance");
	}
	return ___godot_icall_bool_String_int(mb, (const Object *) this, id, input_idx);
}

void AnimationTreePlayer::transition_node_set_xfade_time(const String id, const double time_sec) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "transition_node_set_xfade_time");
	}
	___godot_icall_void_String_float(mb, (const Object *) this, id, time_sec);
}

double AnimationTreePlayer::transition_node_get_xfade_time(const String id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "transition_node_get_xfade_time");
	}
	return ___godot_icall_float_String(mb, (const Object *) this, id);
}

void AnimationTreePlayer::transition_node_set_current(const String id, const int64_t input_idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "transition_node_set_current");
	}
	___godot_icall_void_String_int(mb, (const Object *) this, id, input_idx);
}

int64_t AnimationTreePlayer::transition_node_get_current(const String id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "transition_node_get_current");
	}
	return ___godot_icall_int_String(mb, (const Object *) this, id);
}

void AnimationTreePlayer::node_set_position(const String id, const Vector2 screen_position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "node_set_position");
	}
	___godot_icall_void_String_Vector2(mb, (const Object *) this, id, screen_position);
}

Vector2 AnimationTreePlayer::node_get_position(const String id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "node_get_position");
	}
	return ___godot_icall_Vector2_String(mb, (const Object *) this, id);
}

void AnimationTreePlayer::remove_node(const String id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "remove_node");
	}
	___godot_icall_void_String(mb, (const Object *) this, id);
}

Error AnimationTreePlayer::connect_nodes(const String id, const String dst_id, const int64_t dst_input_idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "connect_nodes");
	}
	return (Error) ___godot_icall_int_String_String_int(mb, (const Object *) this, id, dst_id, dst_input_idx);
}

bool AnimationTreePlayer::are_nodes_connected(const String id, const String dst_id, const int64_t dst_input_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "are_nodes_connected");
	}
	return ___godot_icall_bool_String_String_int(mb, (const Object *) this, id, dst_id, dst_input_idx);
}

void AnimationTreePlayer::disconnect_nodes(const String id, const int64_t dst_input_idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "disconnect_nodes");
	}
	___godot_icall_void_String_int(mb, (const Object *) this, id, dst_input_idx);
}

void AnimationTreePlayer::set_active(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "set_active");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool AnimationTreePlayer::is_active() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "is_active");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void AnimationTreePlayer::set_base_path(const NodePath path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "set_base_path");
	}
	___godot_icall_void_NodePath(mb, (const Object *) this, path);
}

NodePath AnimationTreePlayer::get_base_path() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "get_base_path");
	}
	return ___godot_icall_NodePath(mb, (const Object *) this);
}

void AnimationTreePlayer::set_master_player(const NodePath nodepath) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "set_master_player");
	}
	___godot_icall_void_NodePath(mb, (const Object *) this, nodepath);
}

NodePath AnimationTreePlayer::get_master_player() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "get_master_player");
	}
	return ___godot_icall_NodePath(mb, (const Object *) this);
}

PoolStringArray AnimationTreePlayer::get_node_list() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "get_node_list");
	}
	return ___godot_icall_PoolStringArray(mb, (const Object *) this);
}

void AnimationTreePlayer::set_animation_process_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "set_animation_process_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

AnimationTreePlayer::AnimationProcessMode AnimationTreePlayer::get_animation_process_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "get_animation_process_mode");
	}
	return (AnimationTreePlayer::AnimationProcessMode) ___godot_icall_int(mb, (const Object *) this);
}

void AnimationTreePlayer::advance(const double delta) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "advance");
	}
	___godot_icall_void_float(mb, (const Object *) this, delta);
}

void AnimationTreePlayer::reset() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "reset");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void AnimationTreePlayer::recompute_caches() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationTreePlayer", "recompute_caches");
	}
	___godot_icall_void(mb, (const Object *) this);
}

}