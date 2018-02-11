#include <HTTPClient.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <StreamPeer.hpp>


namespace godot {


void *HTTPClient::___get_type_tag()
{
	return (void *) &HTTPClient::___get_type_tag;
}

void *HTTPClient::___get_base_type_tag()
{
	return (void *) &Reference::___get_type_tag;
}

HTTPClient *HTTPClient::_new()
{
	return (HTTPClient *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"HTTPClient")());
}
Error HTTPClient::connect_to_host(const String host, const int64_t port, const bool use_ssl, const bool verify_host) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("HTTPClient", "connect_to_host");
	}
	return (Error) ___godot_icall_int_String_int_bool_bool(mb, (const Object *) this, host, port, use_ssl, verify_host);
}

void HTTPClient::set_connection(const Ref<StreamPeer> connection) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("HTTPClient", "set_connection");
	}
	___godot_icall_void_Object(mb, (const Object *) this, connection.ptr());
}

Ref<StreamPeer> HTTPClient::get_connection() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("HTTPClient", "get_connection");
	}
	return Ref<StreamPeer>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

Error HTTPClient::request_raw(const int64_t method, const String url, const PoolStringArray headers, const PoolByteArray body) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("HTTPClient", "request_raw");
	}
	return (Error) ___godot_icall_int_int_String_PoolStringArray_PoolByteArray(mb, (const Object *) this, method, url, headers, body);
}

Error HTTPClient::request(const int64_t method, const String url, const PoolStringArray headers, const String body) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("HTTPClient", "request");
	}
	return (Error) ___godot_icall_int_int_String_PoolStringArray_String(mb, (const Object *) this, method, url, headers, body);
}

void HTTPClient::close() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("HTTPClient", "close");
	}
	___godot_icall_void(mb, (const Object *) this);
}

bool HTTPClient::has_response() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("HTTPClient", "has_response");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

bool HTTPClient::is_response_chunked() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("HTTPClient", "is_response_chunked");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

int64_t HTTPClient::get_response_code() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("HTTPClient", "get_response_code");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

PoolStringArray HTTPClient::get_response_headers() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("HTTPClient", "get_response_headers");
	}
	return ___godot_icall_PoolStringArray(mb, (const Object *) this);
}

Dictionary HTTPClient::get_response_headers_as_dictionary() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("HTTPClient", "get_response_headers_as_dictionary");
	}
	return ___godot_icall_Dictionary(mb, (const Object *) this);
}

int64_t HTTPClient::get_response_body_length() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("HTTPClient", "get_response_body_length");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

PoolByteArray HTTPClient::read_response_body_chunk() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("HTTPClient", "read_response_body_chunk");
	}
	return ___godot_icall_PoolByteArray(mb, (const Object *) this);
}

void HTTPClient::set_read_chunk_size(const int64_t bytes) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("HTTPClient", "set_read_chunk_size");
	}
	___godot_icall_void_int(mb, (const Object *) this, bytes);
}

void HTTPClient::set_blocking_mode(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("HTTPClient", "set_blocking_mode");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool HTTPClient::is_blocking_mode_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("HTTPClient", "is_blocking_mode_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

HTTPClient::Status HTTPClient::get_status() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("HTTPClient", "get_status");
	}
	return (HTTPClient::Status) ___godot_icall_int(mb, (const Object *) this);
}

Error HTTPClient::poll() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("HTTPClient", "poll");
	}
	return (Error) ___godot_icall_int(mb, (const Object *) this);
}

String HTTPClient::query_string_from_dict(const Dictionary fields) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("HTTPClient", "query_string_from_dict");
	}
	return ___godot_icall_String_Dictionary(mb, (const Object *) this, fields);
}

}