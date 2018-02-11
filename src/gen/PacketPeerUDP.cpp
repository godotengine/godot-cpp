#include <PacketPeerUDP.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *PacketPeerUDP::___get_type_tag()
{
	return (void *) &PacketPeerUDP::___get_type_tag;
}

void *PacketPeerUDP::___get_base_type_tag()
{
	return (void *) &PacketPeer::___get_type_tag;
}

PacketPeerUDP *PacketPeerUDP::_new()
{
	return (PacketPeerUDP *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"PacketPeerUDP")());
}
Error PacketPeerUDP::listen(const int64_t port, const String bind_address, const int64_t recv_buf_size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PacketPeerUDP", "listen");
	}
	return (Error) ___godot_icall_int_int_String_int(mb, (const Object *) this, port, bind_address, recv_buf_size);
}

void PacketPeerUDP::close() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PacketPeerUDP", "close");
	}
	___godot_icall_void(mb, (const Object *) this);
}

Error PacketPeerUDP::wait() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PacketPeerUDP", "wait");
	}
	return (Error) ___godot_icall_int(mb, (const Object *) this);
}

bool PacketPeerUDP::is_listening() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PacketPeerUDP", "is_listening");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

String PacketPeerUDP::get_packet_ip() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PacketPeerUDP", "get_packet_ip");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

int64_t PacketPeerUDP::get_packet_port() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PacketPeerUDP", "get_packet_port");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

Error PacketPeerUDP::set_dest_address(const String host, const int64_t port) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PacketPeerUDP", "set_dest_address");
	}
	return (Error) ___godot_icall_int_String_int(mb, (const Object *) this, host, port);
}

}