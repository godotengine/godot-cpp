#include <StreamPeerBuffer.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <StreamPeerBuffer.hpp>


namespace godot {


void *StreamPeerBuffer::___get_type_tag()
{
	return (void *) &StreamPeerBuffer::___get_type_tag;
}

void *StreamPeerBuffer::___get_base_type_tag()
{
	return (void *) &StreamPeer::___get_type_tag;
}

StreamPeerBuffer *StreamPeerBuffer::_new()
{
	return (StreamPeerBuffer *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"StreamPeerBuffer")());
}
void StreamPeerBuffer::seek(const int64_t position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeerBuffer", "seek");
	}
	___godot_icall_void_int(mb, (const Object *) this, position);
}

int64_t StreamPeerBuffer::get_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeerBuffer", "get_size");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t StreamPeerBuffer::get_position() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeerBuffer", "get_position");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void StreamPeerBuffer::resize(const int64_t size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeerBuffer", "resize");
	}
	___godot_icall_void_int(mb, (const Object *) this, size);
}

void StreamPeerBuffer::set_data_array(const PoolByteArray data) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeerBuffer", "set_data_array");
	}
	___godot_icall_void_PoolByteArray(mb, (const Object *) this, data);
}

PoolByteArray StreamPeerBuffer::get_data_array() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeerBuffer", "get_data_array");
	}
	return ___godot_icall_PoolByteArray(mb, (const Object *) this);
}

void StreamPeerBuffer::clear() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeerBuffer", "clear");
	}
	___godot_icall_void(mb, (const Object *) this);
}

Ref<StreamPeerBuffer> StreamPeerBuffer::duplicate() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeerBuffer", "duplicate");
	}
	return Ref<StreamPeerBuffer>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

}