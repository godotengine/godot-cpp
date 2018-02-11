#include <TCP_Server.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <StreamPeerTCP.hpp>


namespace godot {


void *TCP_Server::___get_type_tag()
{
	return (void *) &TCP_Server::___get_type_tag;
}

void *TCP_Server::___get_base_type_tag()
{
	return (void *) &Reference::___get_type_tag;
}

TCP_Server *TCP_Server::_new()
{
	return (TCP_Server *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"TCP_Server")());
}
Error TCP_Server::listen(const int64_t port, const String bind_address) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TCP_Server", "listen");
	}
	return (Error) ___godot_icall_int_int_String(mb, (const Object *) this, port, bind_address);
}

bool TCP_Server::is_connection_available() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TCP_Server", "is_connection_available");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

Ref<StreamPeerTCP> TCP_Server::take_connection() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TCP_Server", "take_connection");
	}
	return Ref<StreamPeerTCP>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void TCP_Server::stop() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TCP_Server", "stop");
	}
	___godot_icall_void(mb, (const Object *) this);
}

}