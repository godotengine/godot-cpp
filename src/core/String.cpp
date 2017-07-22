#include "String.hpp"

#include "NodePath.hpp"

#include <godot/godot_string.h>

#include <string.h>

namespace godot {

godot::String::String()
{
	godot_string_new(&_godot_string);
}

String::String(const char *contents)
{
	godot_string_new_data(&_godot_string, contents, strlen(contents));
}

String::String(const wchar_t *contents)
{
	// @Todo
	// godot_string_new_data(&_godot_string, contents, strlen(contents));
	godot_string_new(&_godot_string);
}

String::String(const wchar_t c)
{
	// @Todo
	godot_string_new(&_godot_string);
}

String::String(const String& other)
{
	godot_string_new_copy(&_godot_string, &other._godot_string);
}

String::~String()
{
	godot_string_destroy(&_godot_string);
}


String String::substr(int p_from,int p_chars) const
{
	return String(); // @Todo
}


wchar_t &String::operator [](const int idx)
{
	return *godot_string_operator_index(&_godot_string, idx);
}

wchar_t String::operator [](const int idx) const
{
	return *godot_string_operator_index((godot_string *) &_godot_string, idx);
}

int String::length() const
{
	int len = 0;
	godot_string_get_data(&_godot_string, nullptr, &len);
	return len;
}

void String::operator =(const String &s)
{
	godot_string_destroy(&_godot_string);
	godot_string_new_copy(&_godot_string, &s._godot_string);
}

bool String::operator ==(const String &s)
{
	return godot_string_operator_equal(&_godot_string, &s._godot_string);
}

bool String::operator !=(const String &s)
{
	return !(*this == s);
}

String String::operator +(const String &s)
{
	String new_string = *this;
	new_string._godot_string = godot_string_operator_plus(&new_string._godot_string, &s._godot_string);

	return new_string;
}

void String::operator +=(const String &s)
{
	_godot_string = godot_string_operator_plus(&_godot_string, &s._godot_string);
}

void String::operator +=(const wchar_t c)
{
	// @Todo
}

bool String::operator <(const String &s)
{
	return godot_string_operator_less(&_godot_string, &s._godot_string);
}

bool String::operator <=(const String &s)
{
	return godot_string_operator_less(&_godot_string, &s._godot_string) || (*this == s);
}

bool String::operator >(const String &s)
{
	return !(*this <= s);
}

bool String::operator >=(const String &s)
{
	return !(*this < s);
}

String::operator NodePath() const
{
	return NodePath(*this);
}

const char *String::c_string() const
{
	return godot_string_c_str(&_godot_string);
}


String operator +(const char *a, const String& b)
{
	return String(a) + b;
}



}
