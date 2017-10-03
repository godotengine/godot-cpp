#ifndef STRING_H
#define STRING_H

#include <gdnative/string.h>

namespace godot {

class NodePath;
class Variant;
class PoolByteArray;
class PoolRealArray;
class PoolStringArray;

class String {
	godot_string _godot_string;

public:
	String();
	String(const char *contents);
	String(const wchar_t *contents);
	String(const wchar_t c);
	String(const String &other);

	~String();

	wchar_t &operator[](const int idx);
	wchar_t operator[](const int idx) const;

	void operator=(const String &s);
	bool operator==(const String &s);
	bool operator!=(const String &s);
	String operator+(const String &s);
	void operator+=(const String &s);
	void operator+=(const wchar_t c);
	bool operator<(const String &s);
	bool operator<=(const String &s);
	bool operator>(const String &s);
	bool operator>=(const String &s);

	operator NodePath() const;

	int length() const;
	const char *c_string() const;

	int64_t find(String p_what) const;
	int64_t find_from(String p_what, int64_t p_from) const;
	bool begins_with(String &s) const;
	bool begins_with_char_array(const char *p_char_array) const;
	PoolStringArray bigrams() const;
	String c_escape() const;
	String c_unescape() const;
	String capitalize() const;
	bool empty() const;
	bool ends_with(String &text) const;
	void erase(int position, int chars);
	int find(String what, int from = 0) const;
	int find_last(String what) const;
	int findn(String what, int from = 0) const;
	String format(Variant values, String placeholder) const;
	String get_base_dir() const;
	String get_basename() const;
	String get_extension() const;
	String get_file() const;
	int hash() const;
	int hex_to_int() const;
	String insert(int position, String what) const;
	bool is_abs_path() const;
	bool is_rel_path() const;
	bool is_subsequence_of(String text) const;
	bool is_subsequence_ofi(String text) const;
	bool is_valid_float() const;
	bool is_valid_html_color() const;
	bool is_valid_identifier() const;
	bool is_valid_integer() const;
	bool is_valid_ip_address() const;
	String json_escape() const;
	String left(int position) const;
	bool match(String expr) const;
	bool matchn(String expr) const;
	PoolByteArray md5_buffer() const;
	String md5_text() const;
	int ord_at(int at) const;
	String pad_decimals(int digits) const;
	String pad_zeros(int digits) const;
	String percent_decode() const;
	String percent_encode() const;
	String plus_file(String file) const;
	String replace(String what, String forwhat) const;
	String replacen(String what, String forwhat) const;
	int rfind(String what, int from = -1) const;
	int rfindn(String what, int from = -1) const;
	String right(int position) const;
	PoolByteArray sha256_buffer() const;
	String sha256_text() const;
	float similarity(String text) const;
	PoolStringArray split(String divisor, bool allow_empty = true) const;
	PoolRealArray split_floats(String divisor, bool allow_empty = true) const;
	String strip_edges(bool left = true, bool right = true) const;
	String substr(int from, int len) const;
	float to_float() const;
	int64_t to_int() const;
	String to_lower() const;
	String to_upper() const;
	String xml_escape() const;
	String xml_unescape() const;
};

String operator+(const char *a, const String &b);
}

#endif // STRING_H
