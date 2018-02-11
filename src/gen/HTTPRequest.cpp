#include <HTTPRequest.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *HTTPRequest::___get_type_tag()
{
	return (void *) &HTTPRequest::___get_type_tag;
}

void *HTTPRequest::___get_base_type_tag()
{
	return (void *) &Node::___get_type_tag;
}

HTTPRequest *HTTPRequest::_new()
{
	return (HTTPRequest *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"HTTPRequest")());
}
Error HTTPRequest::request(const String url, const PoolStringArray custom_headers, const bool ssl_validate_domain, const int64_t method, const String request_data) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("HTTPRequest", "request");
	}
	return (Error) ___godot_icall_int_String_PoolStringArray_bool_int_String(mb, (const Object *) this, url, custom_headers, ssl_validate_domain, method, request_data);
}

void HTTPRequest::cancel_request() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("HTTPRequest", "cancel_request");
	}
	___godot_icall_void(mb, (const Object *) this);
}

HTTPClient::Status HTTPRequest::get_http_client_status() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("HTTPRequest", "get_http_client_status");
	}
	return (HTTPClient::Status) ___godot_icall_int(mb, (const Object *) this);
}

void HTTPRequest::set_use_threads(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("HTTPRequest", "set_use_threads");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool HTTPRequest::is_using_threads() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("HTTPRequest", "is_using_threads");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void HTTPRequest::set_body_size_limit(const int64_t bytes) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("HTTPRequest", "set_body_size_limit");
	}
	___godot_icall_void_int(mb, (const Object *) this, bytes);
}

int64_t HTTPRequest::get_body_size_limit() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("HTTPRequest", "get_body_size_limit");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void HTTPRequest::set_max_redirects(const int64_t amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("HTTPRequest", "set_max_redirects");
	}
	___godot_icall_void_int(mb, (const Object *) this, amount);
}

int64_t HTTPRequest::get_max_redirects() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("HTTPRequest", "get_max_redirects");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void HTTPRequest::set_download_file(const String path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("HTTPRequest", "set_download_file");
	}
	___godot_icall_void_String(mb, (const Object *) this, path);
}

String HTTPRequest::get_download_file() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("HTTPRequest", "get_download_file");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

int64_t HTTPRequest::get_downloaded_bytes() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("HTTPRequest", "get_downloaded_bytes");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t HTTPRequest::get_body_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("HTTPRequest", "get_body_size");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void HTTPRequest::_redirect_request(const String arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("HTTPRequest", "_redirect_request");
	}
	___godot_icall_void_String(mb, (const Object *) this, arg0);
}

void HTTPRequest::_request_done(const int64_t arg0, const int64_t arg1, const PoolStringArray arg2, const PoolByteArray arg3) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("HTTPRequest", "_request_done");
	}
	___godot_icall_void_int_int_PoolStringArray_PoolByteArray(mb, (const Object *) this, arg0, arg1, arg2, arg3);
}

}