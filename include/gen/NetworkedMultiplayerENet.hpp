#ifndef GODOT_CPP_NETWORKEDMULTIPLAYERENET_HPP
#define GODOT_CPP_NETWORKEDMULTIPLAYERENET_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include "NetworkedMultiplayerENet.hpp"

#include "NetworkedMultiplayerPeer.hpp"
namespace godot {


class NetworkedMultiplayerENet : public NetworkedMultiplayerPeer {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "NetworkedMultiplayerENet"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum CompressionMode {
		COMPRESS_NONE = 0,
		COMPRESS_FASTLZ = 2,
		COMPRESS_RANGE_CODER = 1,
		COMPRESS_ZLIB = 3,
		COMPRESS_ZSTD = 4,
	};

	// constants


	static NetworkedMultiplayerENet *_new();

	// methods
	Error create_server(const int64_t port, const int64_t max_clients = 32, const int64_t in_bandwidth = 0, const int64_t out_bandwidth = 0);
	Error create_client(const String address, const int64_t port, const int64_t in_bandwidth = 0, const int64_t out_bandwidth = 0, const int64_t client_port = 0);
	void close_connection(const int64_t wait_usec = 100);
	void disconnect_peer(const int64_t id, const bool now = false);
	void set_compression_mode(const int64_t mode);
	NetworkedMultiplayerENet::CompressionMode get_compression_mode() const;
	void set_bind_ip(const String ip);
	String get_peer_address(const int64_t id) const;
	int64_t get_peer_port(const int64_t id) const;
	int64_t get_packet_channel() const;
	int64_t get_last_packet_channel() const;
	void set_transfer_channel(const int64_t channel);
	int64_t get_transfer_channel() const;
	void set_channel_count(const int64_t channels);
	int64_t get_channel_count() const;
	void set_always_ordered(const bool ordered);
	bool is_always_ordered() const;

};

}

#endif