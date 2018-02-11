#include <WebSocketClient.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *WebSocketClient::___get_type_tag()
{
	return (void *) &WebSocketClient::___get_type_tag;
}

void *WebSocketClient::___get_base_type_tag()
{
	return (void *) &WebSocketMultiplayerPeer::___get_type_tag;
}

WebSocketClient *WebSocketClient::_new()
{
	return (WebSocketClient *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"WebSocketClient")());
}
Error WebSocketClient::connect_to_url(const String url, const PoolStringArray protocols, const bool gd_mp_api) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("WebSocketClient", "connect_to_url");
	}
	return (Error) ___godot_icall_int_String_PoolStringArray_bool(mb, (const Object *) this, url, protocols, gd_mp_api);
}

void WebSocketClient::disconnect_from_host() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("WebSocketClient", "disconnect_from_host");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void WebSocketClient::set_verify_ssl_enabled(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("WebSocketClient", "set_verify_ssl_enabled");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool WebSocketClient::is_verify_ssl_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("WebSocketClient", "is_verify_ssl_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

}