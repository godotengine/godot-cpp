#include <PacketPeer.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *PacketPeer::___get_type_tag()
{
	return (void *) &PacketPeer::___get_type_tag;
}

void *PacketPeer::___get_base_type_tag()
{
	return (void *) &Reference::___get_type_tag;
}

Variant PacketPeer::get_var() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PacketPeer", "get_var");
	}
	return ___godot_icall_Variant(mb, (const Object *) this);
}

Error PacketPeer::put_var(const Variant var) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PacketPeer", "put_var");
	}
	return (Error) ___godot_icall_int_Variant(mb, (const Object *) this, var);
}

PoolByteArray PacketPeer::get_packet() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PacketPeer", "get_packet");
	}
	return ___godot_icall_PoolByteArray(mb, (const Object *) this);
}

Error PacketPeer::put_packet(const PoolByteArray buffer) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PacketPeer", "put_packet");
	}
	return (Error) ___godot_icall_int_PoolByteArray(mb, (const Object *) this, buffer);
}

Error PacketPeer::get_packet_error() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PacketPeer", "get_packet_error");
	}
	return (Error) ___godot_icall_int(mb, (const Object *) this);
}

int64_t PacketPeer::get_available_packet_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PacketPeer", "get_available_packet_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void PacketPeer::set_allow_object_decoding(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PacketPeer", "set_allow_object_decoding");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool PacketPeer::is_object_decoding_allowed() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PacketPeer", "is_object_decoding_allowed");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

}