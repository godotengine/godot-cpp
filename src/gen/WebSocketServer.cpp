#include <WebSocketServer.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *WebSocketServer::___get_type_tag()
{
	return (void *) &WebSocketServer::___get_type_tag;
}

void *WebSocketServer::___get_base_type_tag()
{
	return (void *) &WebSocketMultiplayerPeer::___get_type_tag;
}

WebSocketServer *WebSocketServer::_new()
{
	return (WebSocketServer *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"WebSocketServer")());
}
bool WebSocketServer::is_listening() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("WebSocketServer", "is_listening");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

Error WebSocketServer::listen(const int64_t port, const PoolStringArray protocols, const bool gd_mp_api) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("WebSocketServer", "listen");
	}
	return (Error) ___godot_icall_int_int_PoolStringArray_bool(mb, (const Object *) this, port, protocols, gd_mp_api);
}

void WebSocketServer::stop() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("WebSocketServer", "stop");
	}
	___godot_icall_void(mb, (const Object *) this);
}

bool WebSocketServer::has_peer(const int64_t id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("WebSocketServer", "has_peer");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, id);
}

}