#include <File.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *File::___get_type_tag()
{
	return (void *) &File::___get_type_tag;
}

void *File::___get_base_type_tag()
{
	return (void *) &Reference::___get_type_tag;
}

File *File::_new()
{
	return (File *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"_File")());
}
Error File::open_encrypted(const String path, const int64_t mode_flags, const PoolByteArray key) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "open_encrypted");
	}
	return (Error) ___godot_icall_int_String_int_PoolByteArray(mb, (const Object *) this, path, mode_flags, key);
}

Error File::open_encrypted_with_pass(const String path, const int64_t mode_flags, const String pass) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "open_encrypted_with_pass");
	}
	return (Error) ___godot_icall_int_String_int_String(mb, (const Object *) this, path, mode_flags, pass);
}

Error File::open_compressed(const String path, const int64_t mode_flags, const int64_t compression_mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "open_compressed");
	}
	return (Error) ___godot_icall_int_String_int_int(mb, (const Object *) this, path, mode_flags, compression_mode);
}

Error File::open(const String path, const int64_t flags) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "open");
	}
	return (Error) ___godot_icall_int_String_int(mb, (const Object *) this, path, flags);
}

void File::close() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "close");
	}
	___godot_icall_void(mb, (const Object *) this);
}

String File::get_path() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "get_path");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

String File::get_path_absolute() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "get_path_absolute");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

bool File::is_open() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "is_open");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void File::seek(const int64_t position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "seek");
	}
	___godot_icall_void_int(mb, (const Object *) this, position);
}

void File::seek_end(const int64_t position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "seek_end");
	}
	___godot_icall_void_int(mb, (const Object *) this, position);
}

int64_t File::get_position() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "get_position");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t File::get_len() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "get_len");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

bool File::eof_reached() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "eof_reached");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

int64_t File::get_8() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "get_8");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t File::get_16() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "get_16");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t File::get_32() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "get_32");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t File::get_64() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "get_64");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

double File::get_float() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "get_float");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

double File::get_double() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "get_double");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

double File::get_real() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "get_real");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

PoolByteArray File::get_buffer(const int64_t len) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "get_buffer");
	}
	return ___godot_icall_PoolByteArray_int(mb, (const Object *) this, len);
}

String File::get_line() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "get_line");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

String File::get_as_text() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "get_as_text");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

String File::get_md5(const String path) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "get_md5");
	}
	return ___godot_icall_String_String(mb, (const Object *) this, path);
}

String File::get_sha256(const String path) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "get_sha256");
	}
	return ___godot_icall_String_String(mb, (const Object *) this, path);
}

bool File::get_endian_swap() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "get_endian_swap");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void File::set_endian_swap(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "set_endian_swap");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

Error File::get_error() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "get_error");
	}
	return (Error) ___godot_icall_int(mb, (const Object *) this);
}

Variant File::get_var() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "get_var");
	}
	return ___godot_icall_Variant(mb, (const Object *) this);
}

PoolStringArray File::get_csv_line(const String delim) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "get_csv_line");
	}
	return ___godot_icall_PoolStringArray_String(mb, (const Object *) this, delim);
}

void File::store_8(const int64_t value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "store_8");
	}
	___godot_icall_void_int(mb, (const Object *) this, value);
}

void File::store_16(const int64_t value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "store_16");
	}
	___godot_icall_void_int(mb, (const Object *) this, value);
}

void File::store_32(const int64_t value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "store_32");
	}
	___godot_icall_void_int(mb, (const Object *) this, value);
}

void File::store_64(const int64_t value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "store_64");
	}
	___godot_icall_void_int(mb, (const Object *) this, value);
}

void File::store_float(const double value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "store_float");
	}
	___godot_icall_void_float(mb, (const Object *) this, value);
}

void File::store_double(const double value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "store_double");
	}
	___godot_icall_void_float(mb, (const Object *) this, value);
}

void File::store_real(const double value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "store_real");
	}
	___godot_icall_void_float(mb, (const Object *) this, value);
}

void File::store_buffer(const PoolByteArray buffer) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "store_buffer");
	}
	___godot_icall_void_PoolByteArray(mb, (const Object *) this, buffer);
}

void File::store_line(const String line) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "store_line");
	}
	___godot_icall_void_String(mb, (const Object *) this, line);
}

void File::store_string(const String string) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "store_string");
	}
	___godot_icall_void_String(mb, (const Object *) this, string);
}

void File::store_var(const Variant value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "store_var");
	}
	___godot_icall_void_Variant(mb, (const Object *) this, value);
}

void File::store_pascal_string(const String string) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "store_pascal_string");
	}
	___godot_icall_void_String(mb, (const Object *) this, string);
}

String File::get_pascal_string() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "get_pascal_string");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

bool File::file_exists(const String path) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "file_exists");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, path);
}

int64_t File::get_modified_time(const String file) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_File", "get_modified_time");
	}
	return ___godot_icall_int_String(mb, (const Object *) this, file);
}

}