#include <NetworkedMultiplayerENet.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *NetworkedMultiplayerENet::___get_type_tag()
{
	return (void *) &NetworkedMultiplayerENet::___get_type_tag;
}

void *NetworkedMultiplayerENet::___get_base_type_tag()
{
	return (void *) &NetworkedMultiplayerPeer::___get_type_tag;
}

NetworkedMultiplayerENet *NetworkedMultiplayerENet::_new()
{
	return (NetworkedMultiplayerENet *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"NetworkedMultiplayerENet")());
}
Error NetworkedMultiplayerENet::create_server(const int64_t port, const int64_t max_clients, const int64_t in_bandwidth, const int64_t out_bandwidth) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NetworkedMultiplayerENet", "create_server");
	}
	return (Error) ___godot_icall_int_int_int_int_int(mb, (const Object *) this, port, max_clients, in_bandwidth, out_bandwidth);
}

Error NetworkedMultiplayerENet::create_client(const String ip, const int64_t port, const int64_t in_bandwidth, const int64_t out_bandwidth) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NetworkedMultiplayerENet", "create_client");
	}
	return (Error) ___godot_icall_int_String_int_int_int(mb, (const Object *) this, ip, port, in_bandwidth, out_bandwidth);
}

void NetworkedMultiplayerENet::close_connection() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NetworkedMultiplayerENet", "close_connection");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void NetworkedMultiplayerENet::set_compression_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NetworkedMultiplayerENet", "set_compression_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

NetworkedMultiplayerENet::CompressionMode NetworkedMultiplayerENet::get_compression_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NetworkedMultiplayerENet", "get_compression_mode");
	}
	return (NetworkedMultiplayerENet::CompressionMode) ___godot_icall_int(mb, (const Object *) this);
}

void NetworkedMultiplayerENet::set_bind_ip(const String ip) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NetworkedMultiplayerENet", "set_bind_ip");
	}
	___godot_icall_void_String(mb, (const Object *) this, ip);
}

}