#include <PacketPeerStream.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <StreamPeer.hpp>


namespace godot {


void *PacketPeerStream::___get_type_tag()
{
	return (void *) &PacketPeerStream::___get_type_tag;
}

void *PacketPeerStream::___get_base_type_tag()
{
	return (void *) &PacketPeer::___get_type_tag;
}

PacketPeerStream *PacketPeerStream::_new()
{
	return (PacketPeerStream *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"PacketPeerStream")());
}
void PacketPeerStream::set_stream_peer(const Ref<StreamPeer> peer) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PacketPeerStream", "set_stream_peer");
	}
	___godot_icall_void_Object(mb, (const Object *) this, peer.ptr());
}

Ref<StreamPeer> PacketPeerStream::get_stream_peer() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PacketPeerStream", "get_stream_peer");
	}
	return Ref<StreamPeer>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void PacketPeerStream::set_input_buffer_max_size(const int64_t max_size_bytes) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PacketPeerStream", "set_input_buffer_max_size");
	}
	___godot_icall_void_int(mb, (const Object *) this, max_size_bytes);
}

void PacketPeerStream::set_output_buffer_max_size(const int64_t max_size_bytes) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PacketPeerStream", "set_output_buffer_max_size");
	}
	___godot_icall_void_int(mb, (const Object *) this, max_size_bytes);
}

int64_t PacketPeerStream::get_input_buffer_max_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PacketPeerStream", "get_input_buffer_max_size");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t PacketPeerStream::get_output_buffer_max_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PacketPeerStream", "get_output_buffer_max_size");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

}