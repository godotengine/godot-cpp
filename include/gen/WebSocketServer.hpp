#ifndef GODOT_CPP_WEBSOCKETSERVER_HPP
#define GODOT_CPP_WEBSOCKETSERVER_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "WebSocketMultiplayerPeer.hpp"
namespace godot {


class WebSocketServer : public WebSocketMultiplayerPeer {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "WebSocketServer"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static WebSocketServer *_new();

	// methods
	bool is_listening() const;
	Error listen(const int64_t port, const PoolStringArray protocols = PoolStringArray(), const bool gd_mp_api = false);
	void stop();
	bool has_peer(const int64_t id) const;
	String get_peer_address(const int64_t id) const;
	int64_t get_peer_port(const int64_t id) const;
	void disconnect_peer(const int64_t id);

};

}

#endif