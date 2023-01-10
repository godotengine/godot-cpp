/**************************************************************************/
/*  char_string.hpp                                                       */
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

#ifndef GODOT_CHAR_STRING_HPP
#define GODOT_CHAR_STRING_HPP

#include <cstddef>
#include <cstdint>

namespace godot {

class CharString {
	friend class String;

	const char *_data = nullptr;
	int _length = 0;

	CharString(const char *str, int length);

public:
	int length() const;
	const char *get_data() const;

	CharString(CharString &&p_str);
	void operator=(CharString &&p_str);
	CharString() {}
	~CharString();
};

class Char16String {
	friend class String;

	const char16_t *_data = nullptr;
	int _length = 0;

	Char16String(const char16_t *str, int length);

public:
	int length() const;
	const char16_t *get_data() const;

	Char16String(Char16String &&p_str);
	void operator=(Char16String &&p_str);
	Char16String() {}
	~Char16String();
};

class Char32String {
	friend class String;

	const char32_t *_data = nullptr;
	int _length = 0;

	Char32String(const char32_t *str, int length);

public:
	int length() const;
	const char32_t *get_data() const;

	Char32String(Char32String &&p_str);
	void operator=(Char32String &&p_str);
	Char32String() {}
	~Char32String();
};

class CharWideString {
	friend class String;

	const wchar_t *_data = nullptr;
	int _length = 0;

	CharWideString(const wchar_t *str, int length);

public:
	int length() const;
	const wchar_t *get_data() const;

	CharWideString(CharWideString &&p_str);
	void operator=(CharWideString &&p_str);
	CharWideString() {}
	~CharWideString();
};

} // namespace godot

#endif // GODOT_CHAR_STRING_HPP
