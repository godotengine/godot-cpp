#include <StreamPeerTCP.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *StreamPeerTCP::___get_type_tag()
{
	return (void *) &StreamPeerTCP::___get_type_tag;
}

void *StreamPeerTCP::___get_base_type_tag()
{
	return (void *) &StreamPeer::___get_type_tag;
}

StreamPeerTCP *StreamPeerTCP::_new()
{
	return (StreamPeerTCP *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"StreamPeerTCP")());
}
Error StreamPeerTCP::connect_to_host(const String host, const int64_t port) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeerTCP", "connect_to_host");
	}
	return (Error) ___godot_icall_int_String_int(mb, (const Object *) this, host, port);
}

bool StreamPeerTCP::is_connected_to_host() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeerTCP", "is_connected_to_host");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

StreamPeerTCP::Status StreamPeerTCP::get_status() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeerTCP", "get_status");
	}
	return (StreamPeerTCP::Status) ___godot_icall_int(mb, (const Object *) this);
}

String StreamPeerTCP::get_connected_host() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeerTCP", "get_connected_host");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

int64_t StreamPeerTCP::get_connected_port() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeerTCP", "get_connected_port");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void StreamPeerTCP::disconnect_from_host() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeerTCP", "disconnect_from_host");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void StreamPeerTCP::set_no_delay(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeerTCP", "set_no_delay");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

}