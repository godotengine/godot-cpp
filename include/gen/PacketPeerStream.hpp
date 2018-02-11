#ifndef GODOT_CPP_PACKETPEERSTREAM_HPP
#define GODOT_CPP_PACKETPEERSTREAM_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <PacketPeer.hpp>
namespace godot {

class StreamPeer;

class PacketPeerStream : public PacketPeer {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "PacketPeerStream"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static PacketPeerStream *_new();

	// methods
	void set_stream_peer(const Ref<StreamPeer> peer);
	Ref<StreamPeer> get_stream_peer() const;
	void set_input_buffer_max_size(const int64_t max_size_bytes);
	void set_output_buffer_max_size(const int64_t max_size_bytes);
	int64_t get_input_buffer_max_size() const;
	int64_t get_output_buffer_max_size() const;

};

}

#endif