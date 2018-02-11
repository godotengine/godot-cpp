#ifndef GODOT_CPP_PACKETPEERUDP_HPP
#define GODOT_CPP_PACKETPEERUDP_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <PacketPeer.hpp>
namespace godot {


class PacketPeerUDP : public PacketPeer {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "PacketPeerUDP"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static PacketPeerUDP *_new();

	// methods
	Error listen(const int64_t port, const String bind_address = "*", const int64_t recv_buf_size = 65536);
	void close();
	Error wait();
	bool is_listening() const;
	String get_packet_ip() const;
	int64_t get_packet_port() const;
	Error set_dest_address(const String host, const int64_t port);

};

}

#endif