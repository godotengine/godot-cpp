#include <SceneTree.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Viewport.hpp>
#include <Object.hpp>
#include <Node.hpp>
#include <SceneTreeTimer.hpp>
#include <PackedScene.hpp>
#include <NetworkedMultiplayerPeer.hpp>


namespace godot {


void *SceneTree::___get_type_tag()
{
	return (void *) &SceneTree::___get_type_tag;
}

void *SceneTree::___get_base_type_tag()
{
	return (void *) &MainLoop::___get_type_tag;
}

SceneTree *SceneTree::_new()
{
	return (SceneTree *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"SceneTree")());
}
Viewport *SceneTree::get_root() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "get_root");
	}
	return (Viewport *) ___godot_icall_Object(mb, (const Object *) this);
}

bool SceneTree::has_group(const String name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "has_group");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, name);
}

void SceneTree::set_auto_accept_quit(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "set_auto_accept_quit");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

void SceneTree::set_quit_on_go_back(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "set_quit_on_go_back");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

void SceneTree::set_debug_collisions_hint(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "set_debug_collisions_hint");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool SceneTree::is_debugging_collisions_hint() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "is_debugging_collisions_hint");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void SceneTree::set_debug_navigation_hint(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "set_debug_navigation_hint");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool SceneTree::is_debugging_navigation_hint() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "is_debugging_navigation_hint");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void SceneTree::set_edited_scene_root(const Object *scene) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "set_edited_scene_root");
	}
	___godot_icall_void_Object(mb, (const Object *) this, scene);
}

Node *SceneTree::get_edited_scene_root() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "get_edited_scene_root");
	}
	return (Node *) ___godot_icall_Object(mb, (const Object *) this);
}

void SceneTree::set_pause(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "set_pause");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool SceneTree::is_paused() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "is_paused");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void SceneTree::set_input_as_handled() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "set_input_as_handled");
	}
	___godot_icall_void(mb, (const Object *) this);
}

bool SceneTree::is_input_handled() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "is_input_handled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

Ref<SceneTreeTimer> SceneTree::create_timer(const double time_sec, const bool pause_mode_process) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "create_timer");
	}
	return Ref<SceneTreeTimer>::__internal_constructor(___godot_icall_Object_float_bool(mb, (const Object *) this, time_sec, pause_mode_process));
}

int64_t SceneTree::get_node_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "get_node_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t SceneTree::get_frame() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "get_frame");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void SceneTree::quit() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "quit");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void SceneTree::set_screen_stretch(const int64_t mode, const int64_t aspect, const Vector2 minsize, const double shrink) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "set_screen_stretch");
	}
	___godot_icall_void_int_int_Vector2_float(mb, (const Object *) this, mode, aspect, minsize, shrink);
}

void SceneTree::queue_delete(const Object *obj) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "queue_delete");
	}
	___godot_icall_void_Object(mb, (const Object *) this, obj);
}

Variant SceneTree::call_group_flags(const int64_t flags, const String group, const String method, const Array& __var_args) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "call_group_flags");
	}
	Variant __given_args[3];
	godot::api->godot_variant_new_nil((godot_variant *) &__given_args[0]);
	godot::api->godot_variant_new_nil((godot_variant *) &__given_args[1]);
	godot::api->godot_variant_new_nil((godot_variant *) &__given_args[2]);

	__given_args[0] = flags;
	__given_args[1] = group;
	__given_args[2] = method;

	godot_variant **__args = (godot_variant **) alloca(sizeof(godot_variant *) * (__var_args.size() + 3));

	__args[0] = (godot_variant *) &__given_args[0];
	__args[1] = (godot_variant *) &__given_args[1];
	__args[2] = (godot_variant *) &__given_args[2];

	for (int i = 0; i < __var_args.size(); i++) {
		__args[i + 3] = (godot_variant *) &((Array &) __var_args)[i];
	}

	Variant __result;
	*(godot_variant *) &__result = godot::api->godot_method_bind_call(mb, ((const Object *) this)->_owner, (const godot_variant **) __args, (__var_args.size() + 3), nullptr);

	godot::api->godot_variant_destroy((godot_variant *) &__given_args[0]);
	godot::api->godot_variant_destroy((godot_variant *) &__given_args[1]);
	godot::api->godot_variant_destroy((godot_variant *) &__given_args[2]);

	return __result;
}

void SceneTree::notify_group_flags(const int64_t call_flags, const String group, const int64_t notification) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "notify_group_flags");
	}
	___godot_icall_void_int_String_int(mb, (const Object *) this, call_flags, group, notification);
}

void SceneTree::set_group_flags(const int64_t call_flags, const String group, const String property, const Variant value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "set_group_flags");
	}
	___godot_icall_void_int_String_String_Variant(mb, (const Object *) this, call_flags, group, property, value);
}

Variant SceneTree::call_group(const String group, const String method, const Array& __var_args) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "call_group");
	}
	Variant __given_args[2];
	godot::api->godot_variant_new_nil((godot_variant *) &__given_args[0]);
	godot::api->godot_variant_new_nil((godot_variant *) &__given_args[1]);

	__given_args[0] = group;
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

void SceneTree::notify_group(const String group, const int64_t notification) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "notify_group");
	}
	___godot_icall_void_String_int(mb, (const Object *) this, group, notification);
}

void SceneTree::set_group(const String group, const String property, const Variant value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "set_group");
	}
	___godot_icall_void_String_String_Variant(mb, (const Object *) this, group, property, value);
}

Array SceneTree::get_nodes_in_group(const String group) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "get_nodes_in_group");
	}
	return ___godot_icall_Array_String(mb, (const Object *) this, group);
}

void SceneTree::set_current_scene(const Object *child_node) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "set_current_scene");
	}
	___godot_icall_void_Object(mb, (const Object *) this, child_node);
}

Node *SceneTree::get_current_scene() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "get_current_scene");
	}
	return (Node *) ___godot_icall_Object(mb, (const Object *) this);
}

Error SceneTree::change_scene(const String path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "change_scene");
	}
	return (Error) ___godot_icall_int_String(mb, (const Object *) this, path);
}

Error SceneTree::change_scene_to(const Ref<PackedScene> packed_scene) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "change_scene_to");
	}
	return (Error) ___godot_icall_int_Object(mb, (const Object *) this, packed_scene.ptr());
}

Error SceneTree::reload_current_scene() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "reload_current_scene");
	}
	return (Error) ___godot_icall_int(mb, (const Object *) this);
}

void SceneTree::_change_scene(const Object *arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "_change_scene");
	}
	___godot_icall_void_Object(mb, (const Object *) this, arg0);
}

void SceneTree::set_network_peer(const Ref<NetworkedMultiplayerPeer> peer) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "set_network_peer");
	}
	___godot_icall_void_Object(mb, (const Object *) this, peer.ptr());
}

Ref<NetworkedMultiplayerPeer> SceneTree::get_network_peer() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "get_network_peer");
	}
	return Ref<NetworkedMultiplayerPeer>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

bool SceneTree::is_network_server() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "is_network_server");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

bool SceneTree::has_network_peer() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "has_network_peer");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

PoolIntArray SceneTree::get_network_connected_peers() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "get_network_connected_peers");
	}
	return ___godot_icall_PoolIntArray(mb, (const Object *) this);
}

int64_t SceneTree::get_network_unique_id() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "get_network_unique_id");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t SceneTree::get_rpc_sender_id() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "get_rpc_sender_id");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void SceneTree::set_refuse_new_network_connections(const bool refuse) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "set_refuse_new_network_connections");
	}
	___godot_icall_void_bool(mb, (const Object *) this, refuse);
}

bool SceneTree::is_refusing_new_network_connections() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "is_refusing_new_network_connections");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void SceneTree::_network_peer_connected(const int64_t arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "_network_peer_connected");
	}
	___godot_icall_void_int(mb, (const Object *) this, arg0);
}

void SceneTree::_network_peer_disconnected(const int64_t arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "_network_peer_disconnected");
	}
	___godot_icall_void_int(mb, (const Object *) this, arg0);
}

void SceneTree::_connected_to_server() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "_connected_to_server");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void SceneTree::_connection_failed() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "_connection_failed");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void SceneTree::_server_disconnected() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "_server_disconnected");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void SceneTree::set_use_font_oversampling(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "set_use_font_oversampling");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool SceneTree::is_using_font_oversampling() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneTree", "is_using_font_oversampling");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

}