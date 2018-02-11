#include <WebSocketPeer.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *WebSocketPeer::___get_type_tag()
{
	return (void *) &WebSocketPeer::___get_type_tag;
}

void *WebSocketPeer::___get_base_type_tag()
{
	return (void *) &PacketPeer::___get_type_tag;
}

WebSocketPeer *WebSocketPeer::_new()
{
	return (WebSocketPeer *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"WebSocketPeer")());
}
WebSocketPeer::WriteMode WebSocketPeer::get_write_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("WebSocketPeer", "get_write_mode");
	}
	return (WebSocketPeer::WriteMode) ___godot_icall_int(mb, (const Object *) this);
}

void WebSocketPeer::set_write_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("WebSocketPeer", "set_write_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

bool WebSocketPeer::is_connected_to_host() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("WebSocketPeer", "is_connected_to_host");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

bool WebSocketPeer::was_string_packet() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("WebSocketPeer", "was_string_packet");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void WebSocketPeer::close() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("WebSocketPeer", "close");
	}
	___godot_icall_void(mb, (const Object *) this);
}

}