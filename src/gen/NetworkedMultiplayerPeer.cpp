#include <NetworkedMultiplayerPeer.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *NetworkedMultiplayerPeer::___get_type_tag()
{
	return (void *) &NetworkedMultiplayerPeer::___get_type_tag;
}

void *NetworkedMultiplayerPeer::___get_base_type_tag()
{
	return (void *) &PacketPeer::___get_type_tag;
}

void NetworkedMultiplayerPeer::set_transfer_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NetworkedMultiplayerPeer", "set_transfer_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

NetworkedMultiplayerPeer::TransferMode NetworkedMultiplayerPeer::get_transfer_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NetworkedMultiplayerPeer", "get_transfer_mode");
	}
	return (NetworkedMultiplayerPeer::TransferMode) ___godot_icall_int(mb, (const Object *) this);
}

void NetworkedMultiplayerPeer::set_target_peer(const int64_t id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NetworkedMultiplayerPeer", "set_target_peer");
	}
	___godot_icall_void_int(mb, (const Object *) this, id);
}

int64_t NetworkedMultiplayerPeer::get_packet_peer() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NetworkedMultiplayerPeer", "get_packet_peer");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void NetworkedMultiplayerPeer::poll() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NetworkedMultiplayerPeer", "poll");
	}
	___godot_icall_void(mb, (const Object *) this);
}

NetworkedMultiplayerPeer::ConnectionStatus NetworkedMultiplayerPeer::get_connection_status() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NetworkedMultiplayerPeer", "get_connection_status");
	}
	return (NetworkedMultiplayerPeer::ConnectionStatus) ___godot_icall_int(mb, (const Object *) this);
}

int64_t NetworkedMultiplayerPeer::get_unique_id() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NetworkedMultiplayerPeer", "get_unique_id");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void NetworkedMultiplayerPeer::set_refuse_new_connections(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NetworkedMultiplayerPeer", "set_refuse_new_connections");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool NetworkedMultiplayerPeer::is_refusing_new_connections() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NetworkedMultiplayerPeer", "is_refusing_new_connections");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

}