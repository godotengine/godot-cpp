#ifndef GODOT_CPP_HTTPCLIENT_HPP
#define GODOT_CPP_HTTPCLIENT_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include "HTTPClient.hpp"

#include "Reference.hpp"
namespace godot {

class StreamPeer;

class HTTPClient : public Reference {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "HTTPClient"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum Status {
		STATUS_CONNECTION_ERROR = 8,
		STATUS_RESOLVING = 1,
		STATUS_REQUESTING = 6,
		STATUS_CONNECTED = 5,
		STATUS_CANT_RESOLVE = 2,
		STATUS_SSL_HANDSHAKE_ERROR = 9,
		STATUS_BODY = 7,
		STATUS_DISCONNECTED = 0,
		STATUS_CONNECTING = 3,
		STATUS_CANT_CONNECT = 4,
	};
	enum Method {
		METHOD_MAX = 9,
		METHOD_POST = 2,
		METHOD_TRACE = 6,
		METHOD_OPTIONS = 5,
		METHOD_CONNECT = 7,
		METHOD_HEAD = 1,
		METHOD_GET = 0,
		METHOD_DELETE = 4,
		METHOD_PUT = 3,
		METHOD_PATCH = 8,
	};
	enum ResponseCode {
		RESPONSE_SEE_OTHER = 303,
		RESPONSE_UNAVAILABLE_FOR_LEGAL_REASONS = 451,
		RESPONSE_NOT_IMPLEMENTED = 501,
		RESPONSE_CONFLICT = 409,
		RESPONSE_REQUEST_ENTITY_TOO_LARGE = 413,
		RESPONSE_REQUESTED_RANGE_NOT_SATISFIABLE = 416,
		RESPONSE_SERVICE_UNAVAILABLE = 503,
		RESPONSE_LOCKED = 423,
		RESPONSE_MULTIPLE_CHOICES = 300,
		RESPONSE_UNPROCESSABLE_ENTITY = 422,
		RESPONSE_UNAUTHORIZED = 401,
		RESPONSE_PAYMENT_REQUIRED = 402,
		RESPONSE_LENGTH_REQUIRED = 411,
		RESPONSE_MULTI_STATUS = 207,
		RESPONSE_RESET_CONTENT = 205,
		RESPONSE_MOVED_PERMANENTLY = 301,
		RESPONSE_TEMPORARY_REDIRECT = 307,
		RESPONSE_NOT_ACCEPTABLE = 406,
		RESPONSE_LOOP_DETECTED = 508,
		RESPONSE_PROCESSING = 102,
		RESPONSE_TOO_MANY_REQUESTS = 429,
		RESPONSE_REQUEST_URI_TOO_LONG = 414,
		RESPONSE_IM_A_TEAPOT = 418,
		RESPONSE_BAD_GATEWAY = 502,
		RESPONSE_MISDIRECTED_REQUEST = 421,
		RESPONSE_UNSUPPORTED_MEDIA_TYPE = 415,
		RESPONSE_PERMANENT_REDIRECT = 308,
		RESPONSE_NOT_MODIFIED = 304,
		RESPONSE_NOT_FOUND = 404,
		RESPONSE_GATEWAY_TIMEOUT = 504,
		RESPONSE_METHOD_NOT_ALLOWED = 405,
		RESPONSE_CONTINUE = 100,
		RESPONSE_BAD_REQUEST = 400,
		RESPONSE_OK = 200,
		RESPONSE_SWITCHING_PROTOCOLS = 101,
		RESPONSE_PROXY_AUTHENTICATION_REQUIRED = 407,
		RESPONSE_SWITCH_PROXY = 306,
		RESPONSE_FORBIDDEN = 403,
		RESPONSE_FAILED_DEPENDENCY = 424,
		RESPONSE_NO_CONTENT = 204,
		RESPONSE_UPGRADE_REQUIRED = 426,
		RESPONSE_REQUEST_TIMEOUT = 408,
		RESPONSE_NOT_EXTENDED = 510,
		RESPONSE_IM_USED = 226,
		RESPONSE_PRECONDITION_FAILED = 412,
		RESPONSE_USE_PROXY = 305,
		RESPONSE_HTTP_VERSION_NOT_SUPPORTED = 505,
		RESPONSE_NON_AUTHORITATIVE_INFORMATION = 203,
		RESPONSE_PRECONDITION_REQUIRED = 428,
		RESPONSE_ACCEPTED = 202,
		RESPONSE_EXPECTATION_FAILED = 417,
		RESPONSE_GONE = 410,
		RESPONSE_ALREADY_REPORTED = 208,
		RESPONSE_VARIANT_ALSO_NEGOTIATES = 506,
		RESPONSE_INTERNAL_SERVER_ERROR = 500,
		RESPONSE_CREATED = 201,
		RESPONSE_PARTIAL_CONTENT = 206,
		RESPONSE_FOUND = 302,
		RESPONSE_NETWORK_AUTH_REQUIRED = 511,
		RESPONSE_INSUFFICIENT_STORAGE = 507,
		RESPONSE_REQUEST_HEADER_FIELDS_TOO_LARGE = 431,
	};

	// constants


	static HTTPClient *_new();

	// methods
	Error connect_to_host(const String host, const int64_t port = -1, const bool use_ssl = false, const bool verify_host = true);
	void set_connection(const Ref<StreamPeer> connection);
	Ref<StreamPeer> get_connection() const;
	Error request_raw(const int64_t method, const String url, const PoolStringArray headers, const PoolByteArray body);
	Error request(const int64_t method, const String url, const PoolStringArray headers, const String body = "");
	void close();
	bool has_response() const;
	bool is_response_chunked() const;
	int64_t get_response_code() const;
	PoolStringArray get_response_headers();
	Dictionary get_response_headers_as_dictionary();
	int64_t get_response_body_length() const;
	PoolByteArray read_response_body_chunk();
	void set_read_chunk_size(const int64_t bytes);
	void set_blocking_mode(const bool enabled);
	bool is_blocking_mode_enabled() const;
	HTTPClient::Status get_status() const;
	Error poll();
	String query_string_from_dict(const Dictionary fields);

};

}

#endif