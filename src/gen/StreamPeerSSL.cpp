#include <StreamPeerSSL.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <StreamPeer.hpp>


namespace godot {


void *StreamPeerSSL::___get_type_tag()
{
	return (void *) &StreamPeerSSL::___get_type_tag;
}

void *StreamPeerSSL::___get_base_type_tag()
{
	return (void *) &StreamPeer::___get_type_tag;
}

StreamPeerSSL *StreamPeerSSL::_new()
{
	return (StreamPeerSSL *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"StreamPeerSSL")());
}
void StreamPeerSSL::poll() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeerSSL", "poll");
	}
	___godot_icall_void(mb, (const Object *) this);
}

Error StreamPeerSSL::accept_stream(const Ref<StreamPeer> stream) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeerSSL", "accept_stream");
	}
	return (Error) ___godot_icall_int_Object(mb, (const Object *) this, stream.ptr());
}

Error StreamPeerSSL::connect_to_stream(const Ref<StreamPeer> stream, const bool validate_certs, const String for_hostname) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeerSSL", "connect_to_stream");
	}
	return (Error) ___godot_icall_int_Object_bool_String(mb, (const Object *) this, stream.ptr(), validate_certs, for_hostname);
}

StreamPeerSSL::Status StreamPeerSSL::get_status() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeerSSL", "get_status");
	}
	return (StreamPeerSSL::Status) ___godot_icall_int(mb, (const Object *) this);
}

void StreamPeerSSL::disconnect_from_stream() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeerSSL", "disconnect_from_stream");
	}
	___godot_icall_void(mb, (const Object *) this);
}

}