#ifndef GODOT_CPP_NETWORKEDMULTIPLAYERPEER_HPP
#define GODOT_CPP_NETWORKEDMULTIPLAYERPEER_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include "NetworkedMultiplayerPeer.hpp"

#include "PacketPeer.hpp"
namespace godot {


class NetworkedMultiplayerPeer : public PacketPeer {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "NetworkedMultiplayerPeer"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum ConnectionStatus {
		CONNECTION_CONNECTING = 1,
		CONNECTION_DISCONNECTED = 0,
		CONNECTION_CONNECTED = 2,
	};
	enum TransferMode {
		TRANSFER_MODE_UNRELIABLE_ORDERED = 1,
		TRANSFER_MODE_UNRELIABLE = 0,
		TRANSFER_MODE_RELIABLE = 2,
	};

	// constants
	const static int TARGET_PEER_BROADCAST = 0;
	const static int TARGET_PEER_SERVER = 1;

	// methods
	void set_transfer_mode(const int64_t mode);
	NetworkedMultiplayerPeer::TransferMode get_transfer_mode() const;
	void set_target_peer(const int64_t id);
	int64_t get_packet_peer() const;
	void poll();
	NetworkedMultiplayerPeer::ConnectionStatus get_connection_status() const;
	int64_t get_unique_id() const;
	void set_refuse_new_connections(const bool enable);
	bool is_refusing_new_connections() const;

};

}

#endif