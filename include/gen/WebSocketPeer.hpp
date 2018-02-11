#ifndef GODOT_CPP_WEBSOCKETPEER_HPP
#define GODOT_CPP_WEBSOCKETPEER_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <WebSocketPeer.hpp>

#include <PacketPeer.hpp>
namespace godot {


class WebSocketPeer : public PacketPeer {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "WebSocketPeer"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum WriteMode {
		WRITE_MODE_BINARY = 1,
		WRITE_MODE_TEXT = 0,
	};

	// constants


	static WebSocketPeer *_new();

	// methods
	WebSocketPeer::WriteMode get_write_mode() const;
	void set_write_mode(const int64_t mode);
	bool is_connected_to_host() const;
	bool was_string_packet() const;
	void close();

};

}

#endif