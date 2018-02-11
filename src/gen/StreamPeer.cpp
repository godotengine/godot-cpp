#include <StreamPeer.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *StreamPeer::___get_type_tag()
{
	return (void *) &StreamPeer::___get_type_tag;
}

void *StreamPeer::___get_base_type_tag()
{
	return (void *) &Reference::___get_type_tag;
}

Error StreamPeer::put_data(const PoolByteArray data) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeer", "put_data");
	}
	return (Error) ___godot_icall_int_PoolByteArray(mb, (const Object *) this, data);
}

Array StreamPeer::put_partial_data(const PoolByteArray data) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeer", "put_partial_data");
	}
	return ___godot_icall_Array_PoolByteArray(mb, (const Object *) this, data);
}

Array StreamPeer::get_data(const int64_t bytes) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeer", "get_data");
	}
	return ___godot_icall_Array_int(mb, (const Object *) this, bytes);
}

Array StreamPeer::get_partial_data(const int64_t bytes) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeer", "get_partial_data");
	}
	return ___godot_icall_Array_int(mb, (const Object *) this, bytes);
}

int64_t StreamPeer::get_available_bytes() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeer", "get_available_bytes");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void StreamPeer::set_big_endian(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeer", "set_big_endian");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool StreamPeer::is_big_endian_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeer", "is_big_endian_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void StreamPeer::put_8(const int64_t value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeer", "put_8");
	}
	___godot_icall_void_int(mb, (const Object *) this, value);
}

void StreamPeer::put_u8(const int64_t value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeer", "put_u8");
	}
	___godot_icall_void_int(mb, (const Object *) this, value);
}

void StreamPeer::put_16(const int64_t value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeer", "put_16");
	}
	___godot_icall_void_int(mb, (const Object *) this, value);
}

void StreamPeer::put_u16(const int64_t value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeer", "put_u16");
	}
	___godot_icall_void_int(mb, (const Object *) this, value);
}

void StreamPeer::put_32(const int64_t value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeer", "put_32");
	}
	___godot_icall_void_int(mb, (const Object *) this, value);
}

void StreamPeer::put_u32(const int64_t value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeer", "put_u32");
	}
	___godot_icall_void_int(mb, (const Object *) this, value);
}

void StreamPeer::put_64(const int64_t value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeer", "put_64");
	}
	___godot_icall_void_int(mb, (const Object *) this, value);
}

void StreamPeer::put_u64(const int64_t value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeer", "put_u64");
	}
	___godot_icall_void_int(mb, (const Object *) this, value);
}

void StreamPeer::put_float(const double value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeer", "put_float");
	}
	___godot_icall_void_float(mb, (const Object *) this, value);
}

void StreamPeer::put_double(const double value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeer", "put_double");
	}
	___godot_icall_void_float(mb, (const Object *) this, value);
}

void StreamPeer::put_utf8_string(const String value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeer", "put_utf8_string");
	}
	___godot_icall_void_String(mb, (const Object *) this, value);
}

void StreamPeer::put_var(const Variant value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeer", "put_var");
	}
	___godot_icall_void_Variant(mb, (const Object *) this, value);
}

int64_t StreamPeer::get_8() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeer", "get_8");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t StreamPeer::get_u8() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeer", "get_u8");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t StreamPeer::get_16() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeer", "get_16");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t StreamPeer::get_u16() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeer", "get_u16");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t StreamPeer::get_32() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeer", "get_32");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t StreamPeer::get_u32() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeer", "get_u32");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t StreamPeer::get_64() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeer", "get_64");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t StreamPeer::get_u64() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeer", "get_u64");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

double StreamPeer::get_float() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeer", "get_float");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

double StreamPeer::get_double() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeer", "get_double");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

String StreamPeer::get_string(const int64_t bytes) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeer", "get_string");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, bytes);
}

String StreamPeer::get_utf8_string(const int64_t bytes) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeer", "get_utf8_string");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, bytes);
}

Variant StreamPeer::get_var() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamPeer", "get_var");
	}
	return ___godot_icall_Variant(mb, (const Object *) this);
}

}