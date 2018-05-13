#ifndef GODOT_CPP_HTTPREQUEST_HPP
#define GODOT_CPP_HTTPREQUEST_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include "HTTPClient.hpp"

#include "Node.hpp"
namespace godot {


class HTTPRequest : public Node {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "HTTPRequest"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum Result {
		RESULT_DOWNLOAD_FILE_WRITE_ERROR = 10,
		RESULT_DOWNLOAD_FILE_CANT_OPEN = 9,
		RESULT_REQUEST_FAILED = 8,
		RESULT_CANT_CONNECT = 2,
		RESULT_CANT_RESOLVE = 3,
		RESULT_CONNECTION_ERROR = 4,
		RESULT_SUCCESS = 0,
		RESULT_NO_RESPONSE = 6,
		RESULT_SSL_HANDSHAKE_ERROR = 5,
		RESULT_BODY_SIZE_LIMIT_EXCEEDED = 7,
		RESULT_REDIRECT_LIMIT_REACHED = 11,
		RESULT_CHUNKED_BODY_SIZE_MISMATCH = 1,
	};

	// constants


	static HTTPRequest *_new();

	// methods
	Error request(const String url, const PoolStringArray custom_headers = PoolStringArray(), const bool ssl_validate_domain = true, const int64_t method = 0, const String request_data = "");
	void cancel_request();
	HTTPClient::Status get_http_client_status() const;
	void set_use_threads(const bool enable);
	bool is_using_threads() const;
	void set_body_size_limit(const int64_t bytes);
	int64_t get_body_size_limit() const;
	void set_max_redirects(const int64_t amount);
	int64_t get_max_redirects() const;
	void set_download_file(const String path);
	String get_download_file() const;
	int64_t get_downloaded_bytes() const;
	int64_t get_body_size() const;
	void _redirect_request(const String arg0);
	void _request_done(const int64_t arg0, const int64_t arg1, const PoolStringArray arg2, const PoolByteArray arg3);

};

}

#endif