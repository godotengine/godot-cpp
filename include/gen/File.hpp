#ifndef GODOT_CPP_FILE_HPP
#define GODOT_CPP_FILE_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Reference.hpp>
namespace godot {


class File : public Reference {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "File"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum CompressionMode {
		COMPRESSION_GZIP = 3,
		COMPRESSION_ZSTD = 2,
		COMPRESSION_DEFLATE = 1,
		COMPRESSION_FASTLZ = 0,
	};
	enum ModeFlags {
		READ = 1,
		WRITE = 2,
		READ_WRITE = 3,
		WRITE_READ = 7,
	};

	// constants


	static File *_new();

	// methods
	Error open_encrypted(const String path, const int64_t mode_flags, const PoolByteArray key);
	Error open_encrypted_with_pass(const String path, const int64_t mode_flags, const String pass);
	Error open_compressed(const String path, const int64_t mode_flags, const int64_t compression_mode = 0);
	Error open(const String path, const int64_t flags);
	void close();
	String get_path() const;
	String get_path_absolute() const;
	bool is_open() const;
	void seek(const int64_t position);
	void seek_end(const int64_t position = 0);
	int64_t get_position() const;
	int64_t get_len() const;
	bool eof_reached() const;
	int64_t get_8() const;
	int64_t get_16() const;
	int64_t get_32() const;
	int64_t get_64() const;
	double get_float() const;
	double get_double() const;
	double get_real() const;
	PoolByteArray get_buffer(const int64_t len) const;
	String get_line() const;
	String get_as_text() const;
	String get_md5(const String path) const;
	String get_sha256(const String path) const;
	bool get_endian_swap();
	void set_endian_swap(const bool enable);
	Error get_error() const;
	Variant get_var() const;
	PoolStringArray get_csv_line(const String delim = ",") const;
	void store_8(const int64_t value);
	void store_16(const int64_t value);
	void store_32(const int64_t value);
	void store_64(const int64_t value);
	void store_float(const double value);
	void store_double(const double value);
	void store_real(const double value);
	void store_buffer(const PoolByteArray buffer);
	void store_line(const String line);
	void store_string(const String string);
	void store_var(const Variant value);
	void store_pascal_string(const String string);
	String get_pascal_string();
	bool file_exists(const String path) const;
	int64_t get_modified_time(const String file) const;

};

}

#endif