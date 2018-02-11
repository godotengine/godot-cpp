#include <WebSocketMultiplayerPeer.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <WebSocketPeer.hpp>


namespace godot {


void *WebSocketMultiplayerPeer::___get_type_tag()
{
	return (void *) &WebSocketMultiplayerPeer::___get_type_tag;
}

void *WebSocketMultiplayerPeer::___get_base_type_tag()
{
	return (void *) &NetworkedMultiplayerPeer::___get_type_tag;
}

Ref<WebSocketPeer> WebSocketMultiplayerPeer::get_peer(const int64_t peer_id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("WebSocketMultiplayerPeer", "get_peer");
	}
	return Ref<WebSocketPeer>::__internal_constructor(___godot_icall_Object_int(mb, (const Object *) this, peer_id));
}

}