#ifndef GODOT_CPP_STREAMPEERSSL_HPP
#define GODOT_CPP_STREAMPEERSSL_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <StreamPeerSSL.hpp>

#include <StreamPeer.hpp>
namespace godot {

class StreamPeer;

class StreamPeerSSL : public StreamPeer {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "StreamPeerSSL"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum Status {
		STATUS_ERROR_HOSTNAME_MISMATCH = 3,
		STATUS_ERROR_NO_CERTIFICATE = 2,
		STATUS_CONNECTED = 1,
		STATUS_DISCONNECTED = 0,
	};

	// constants


	static StreamPeerSSL *_new();

	// methods
	void poll();
	Error accept_stream(const Ref<StreamPeer> stream);
	Error connect_to_stream(const Ref<StreamPeer> stream, const bool validate_certs = false, const String for_hostname = "");
	StreamPeerSSL::Status get_status() const;
	void disconnect_from_stream();

};

}

#endif