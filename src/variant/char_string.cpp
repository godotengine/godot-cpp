/**************************************************************************/
/*  char_string.cpp                                                       */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#include <godot_cpp/variant/char_string.hpp>

#include <godot_cpp/core/memory.hpp>
#include <godot_cpp/variant/node_path.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/string_name.hpp>

#include <godot_cpp/godot.hpp>

#include <cmath>

namespace godot {

int CharString::length() const {
	return _length;
}

const char *CharString::get_data() const {
	return _data;
}

CharString::CharString(CharString &&p_str) {
	SWAP(_length, p_str._length);
	SWAP(_data, p_str._data);
}

void CharString::operator=(CharString &&p_str) {
	SWAP(_length, p_str._length);
	SWAP(_data, p_str._data);
}

CharString::CharString(const char *str, int length) :
		_data(str), _length(length) {}

CharString::~CharString() {
	if (_data != nullptr) {
		memdelete_arr(_data);
	}
}

int Char16String::length() const {
	return _length;
}

const char16_t *Char16String::get_data() const {
	return _data;
}

Char16String::Char16String(Char16String &&p_str) {
	SWAP(_length, p_str._length);
	SWAP(_data, p_str._data);
}

void Char16String::operator=(Char16String &&p_str) {
	SWAP(_length, p_str._length);
	SWAP(_data, p_str._data);
}

Char16String::Char16String(const char16_t *str, int length) :
		_data(str), _length(length) {}

Char16String::~Char16String() {
	if (_data != nullptr) {
		memdelete_arr(_data);
	}
}

int Char32String::length() const {
	return _length;
}

const char32_t *Char32String::get_data() const {
	return _data;
}

Char32String::Char32String(Char32String &&p_str) {
	SWAP(_length, p_str._length);
	SWAP(_data, p_str._data);
}

void Char32String::operator=(Char32String &&p_str) {
	SWAP(_length, p_str._length);
	SWAP(_data, p_str._data);
}

Char32String::Char32String(const char32_t *str, int length) :
		_data(str), _length(length) {}

Char32String::~Char32String() {
	if (_data != nullptr) {
		memdelete_arr(_data);
	}
}

int CharWideString::length() const {
	return _length;
}

const wchar_t *CharWideString::get_data() const {
	return _data;
}

CharWideString::CharWideString(CharWideString &&p_str) {
	SWAP(_length, p_str._length);
	SWAP(_data, p_str._data);
}

void CharWideString::operator=(CharWideString &&p_str) {
	SWAP(_length, p_str._length);
	SWAP(_data, p_str._data);
}

CharWideString::CharWideString(const wchar_t *str, int length) :
		_data(str), _length(length) {}

CharWideString::~CharWideString() {
	if (_data != nullptr) {
		memdelete_arr(_data);
	}
}

// Custom String functions that are not part of bound API.
// It's easier to have them written in C++ directly than in a Python script that generates them.

String::String(const char *from) {
	internal::gde_interface->string_new_with_latin1_chars(_native_ptr(), from);
}

String::String(const wchar_t *from) {
	internal::gde_interface->string_new_with_wide_chars(_native_ptr(), from);
}

String::String(const char16_t *from) {
	internal::gde_interface->string_new_with_utf16_chars(_native_ptr(), from);
}

String::String(const char32_t *from) {
	internal::gde_interface->string_new_with_utf32_chars(_native_ptr(), from);
}

String String::utf8(const char *from, int len) {
	String ret;
	ret.parse_utf8(from, len);
	return ret;
}

void String::parse_utf8(const char *from, int len) {
	internal::gde_interface->string_new_with_utf8_chars_and_len(_native_ptr(), from, len);
}

String String::utf16(const char16_t *from, int len) {
	String ret;
	ret.parse_utf16(from, len);
	return ret;
}

void String::parse_utf16(const char16_t *from, int len) {
	internal::gde_interface->string_new_with_utf16_chars_and_len(_native_ptr(), from, len);
}

String String::num_real(double p_num, bool p_trailing) {
	if (p_num == (double)(int64_t)p_num) {
		if (p_trailing) {
			return num_int64((int64_t)p_num) + ".0";
		} else {
			return num_int64((int64_t)p_num);
		}
	}
#ifdef REAL_T_IS_DOUBLE
	int decimals = 14;
#else
	int decimals = 6;
#endif
	// We want to align the digits to the above sane default, so we only
	// need to subtract log10 for numbers with a positive power of ten.
	if (p_num > 10) {
		decimals -= (int)floor(log10(p_num));
	}
	return num(p_num, decimals);
}

String itos(int64_t p_val) {
	return String::num_int64(p_val);
}

String uitos(uint64_t p_val) {
	return String::num_uint64(p_val);
}

String rtos(double p_val) {
	return String::num(p_val);
}

String rtoss(double p_val) {
	return String::num_scientific(p_val);
}

CharString String::utf8() const {
	int length = internal::gde_interface->string_to_utf8_chars(_native_ptr(), nullptr, 0);
	int size = length + 1;
	char *cstr = memnew_arr(char, size);
	internal::gde_interface->string_to_utf8_chars(_native_ptr(), cstr, length);

	cstr[length] = '\0';

	return CharString(cstr, length);
}

CharString String::ascii() const {
	int length = internal::gde_interface->string_to_latin1_chars(_native_ptr(), nullptr, 0);
	int size = length + 1;
	char *cstr = memnew_arr(char, size);
	internal::gde_interface->string_to_latin1_chars(_native_ptr(), cstr, length);

	cstr[length] = '\0';

	return CharString(cstr, length);
}

Char16String String::utf16() const {
	int length = internal::gde_interface->string_to_utf16_chars(_native_ptr(), nullptr, 0);
	int size = length + 1;
	char16_t *cstr = memnew_arr(char16_t, size);
	internal::gde_interface->string_to_utf16_chars(_native_ptr(), cstr, length);

	cstr[length] = '\0';

	return Char16String(cstr, length);
}

Char32String String::utf32() const {
	int length = internal::gde_interface->string_to_utf32_chars(_native_ptr(), nullptr, 0);
	int size = length + 1;
	char32_t *cstr = memnew_arr(char32_t, size);
	internal::gde_interface->string_to_utf32_chars(_native_ptr(), cstr, length);

	cstr[length] = '\0';

	return Char32String(cstr, length);
}

CharWideString String::wide_string() const {
	int length = internal::gde_interface->string_to_wide_chars(_native_ptr(), nullptr, 0);
	int size = length + 1;
	wchar_t *cstr = memnew_arr(wchar_t, size);
	internal::gde_interface->string_to_wide_chars(_native_ptr(), cstr, length);

	cstr[length] = '\0';

	return CharWideString(cstr, length);
}

String &String::operator=(const char *p_str) {
	*this = String(p_str);
	return *this;
}

String &String::operator=(const wchar_t *p_str) {
	*this = String(p_str);
	return *this;
}

String &String::operator=(const char16_t *p_str) {
	*this = String(p_str);
	return *this;
}

String &String::operator=(const char32_t *p_str) {
	*this = String(p_str);
	return *this;
}

bool String::operator==(const char *p_str) const {
	return *this == String(p_str);
}

bool String::operator==(const wchar_t *p_str) const {
	return *this == String(p_str);
}

bool String::operator==(const char16_t *p_str) const {
	return *this == String(p_str);
}

bool String::operator==(const char32_t *p_str) const {
	return *this == String(p_str);
}

bool String::operator!=(const char *p_str) const {
	return *this != String(p_str);
}

bool String::operator!=(const wchar_t *p_str) const {
	return *this != String(p_str);
}

bool String::operator!=(const char16_t *p_str) const {
	return *this != String(p_str);
}

bool String::operator!=(const char32_t *p_str) const {
	return *this != String(p_str);
}

String String::operator+(const char *p_str) {
	return *this + String(p_str);
}

String String::operator+(const wchar_t *p_str) {
	return *this + String(p_str);
}

String String::operator+(const char16_t *p_str) {
	return *this + String(p_str);
}

String String::operator+(const char32_t *p_str) {
	return *this + String(p_str);
}

String String::operator+(const char32_t p_char) {
	return *this + String::chr(p_char);
}

String &String::operator+=(const String &p_str) {
	internal::gde_interface->string_operator_plus_eq_string((GDExtensionStringPtr)this, (const GDExtensionStringPtr)&p_str);
	return *this;
}

String &String::operator+=(char32_t p_char) {
	internal::gde_interface->string_operator_plus_eq_char((GDExtensionStringPtr)this, p_char);
	return *this;
}

String &String::operator+=(const char *p_str) {
	internal::gde_interface->string_operator_plus_eq_cstr((GDExtensionStringPtr)this, p_str);
	return *this;
}

String &String::operator+=(const wchar_t *p_str) {
	internal::gde_interface->string_operator_plus_eq_wcstr((GDExtensionStringPtr)this, p_str);
	return *this;
}

String &String::operator+=(const char32_t *p_str) {
	internal::gde_interface->string_operator_plus_eq_c32str((GDExtensionStringPtr)this, p_str);
	return *this;
}

const char32_t &String::operator[](int p_index) const {
	return *internal::gde_interface->string_operator_index_const((GDExtensionStringPtr)this, p_index);
}

char32_t &String::operator[](int p_index) {
	return *internal::gde_interface->string_operator_index((GDExtensionStringPtr)this, p_index);
}

const char32_t *String::ptr() const {
	return internal::gde_interface->string_operator_index_const((GDExtensionStringPtr)this, 0);
}

char32_t *String::ptrw() {
	return internal::gde_interface->string_operator_index((GDExtensionStringPtr)this, 0);
}

bool operator==(const char *p_chr, const String &p_str) {
	return p_str == String(p_chr);
}

bool operator==(const wchar_t *p_chr, const String &p_str) {
	return p_str == String(p_chr);
}

bool operator==(const char16_t *p_chr, const String &p_str) {
	return p_str == String(p_chr);
}

bool operator==(const char32_t *p_chr, const String &p_str) {
	return p_str == String(p_chr);
}

bool operator!=(const char *p_chr, const String &p_str) {
	return !(p_str == p_chr);
}

bool operator!=(const wchar_t *p_chr, const String &p_str) {
	return !(p_str == p_chr);
}

bool operator!=(const char16_t *p_chr, const String &p_str) {
	return !(p_str == p_chr);
}

bool operator!=(const char32_t *p_chr, const String &p_str) {
	return !(p_str == p_chr);
}

String operator+(const char *p_chr, const String &p_str) {
	return String(p_chr) + p_str;
}

String operator+(const wchar_t *p_chr, const String &p_str) {
	return String(p_chr) + p_str;
}

String operator+(const char16_t *p_chr, const String &p_str) {
	return String(p_chr) + p_str;
}

String operator+(const char32_t *p_chr, const String &p_str) {
	return String(p_chr) + p_str;
}

String operator+(char32_t p_char, const String &p_str) {
	return String::chr(p_char) + p_str;
}

StringName::StringName(const char *from) :
		StringName(String(from)) {}

StringName::StringName(const wchar_t *from) :
		StringName(String(from)) {}

StringName::StringName(const char16_t *from) :
		StringName(String(from)) {}

StringName::StringName(const char32_t *from) :
		StringName(String(from)) {}

NodePath::NodePath(const char *from) :
		NodePath(String(from)) {}

NodePath::NodePath(const wchar_t *from) :
		NodePath(String(from)) {}

NodePath::NodePath(const char16_t *from) :
		NodePath(String(from)) {}

NodePath::NodePath(const char32_t *from) :
		NodePath(String(from)) {}

} // namespace godot
