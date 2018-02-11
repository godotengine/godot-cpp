#ifndef GODOT_CPP_PACKETPEER_HPP
#define GODOT_CPP_PACKETPEER_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Reference.hpp>
namespace godot {


class PacketPeer : public Reference {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "PacketPeer"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants

	// methods
	Variant get_var();
	Error put_var(const Variant var);
	PoolByteArray get_packet();
	Error put_packet(const PoolByteArray buffer);
	Error get_packet_error() const;
	int64_t get_available_packet_count() const;
	void set_allow_object_decoding(const bool enable);
	bool is_object_decoding_allowed() const;

};

}

#endif