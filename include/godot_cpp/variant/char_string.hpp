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

#pragma once

#include <godot_cpp/templates/cowdata.hpp>

#include <cstddef>
#include <cstdint>

namespace godot {

template <typename T>
class CharStringT;

template <typename T>
class [[nodiscard]] CharProxy {
	friend String;
	friend CharStringT<T>;

	const int _index;
	CowData<T> &_cowdata;
	static constexpr T _null = 0;

	_FORCE_INLINE_ CharProxy(const int &p_index, CowData<T> &p_cowdata) :
			_index(p_index),
			_cowdata(p_cowdata) {}

public:
	_FORCE_INLINE_ CharProxy(const CharProxy<T> &p_other) :
			_index(p_other._index),
			_cowdata(p_other._cowdata) {}

	_FORCE_INLINE_ operator T() const {
		if (unlikely(_index == _cowdata.size())) {
			return _null;
		}

		return _cowdata.get(_index);
	}

	_FORCE_INLINE_ const T *operator&() const {
		return _cowdata.ptr() + _index;
	}

	_FORCE_INLINE_ void operator=(const T &p_other) const {
		_cowdata.set(_index, p_other);
	}

	_FORCE_INLINE_ void operator=(const CharProxy<T> &p_other) const {
		_cowdata.set(_index, p_other.operator T());
	}
};

/*************************************************************************/
/*  CharStringT                                                          */
/*************************************************************************/

template <typename T>
class [[nodiscard]] CharStringT {
	CowData<T> _cowdata;
	static constexpr T _null = 0;

public:
	_FORCE_INLINE_ T *ptrw() _LIFETIME_BOUND_ { return _cowdata.ptrw(); }
	_FORCE_INLINE_ const T *ptr() const _LIFETIME_BOUND_ { return _cowdata.ptr(); }
	_FORCE_INLINE_ const T *get_data() const _LIFETIME_BOUND_ { return size() ? ptr() : &_null; }

	// Returns the number of characters in the buffer, including the terminating NUL character.
	// In most cases, length() should be used instead.
	_FORCE_INLINE_ int size() const { return _cowdata.size(); }
	// Returns the number of characters in the string (excluding terminating NUL character).
	_FORCE_INLINE_ int length() const { return size() ? size() - 1 : 0; }
	_FORCE_INLINE_ bool is_empty() const { return length() == 0; }

	_FORCE_INLINE_ operator Span<T>() const _LIFETIME_BOUND_ { return Span(ptr(), length()); }
	_FORCE_INLINE_ Span<T> span() const _LIFETIME_BOUND_ { return Span(ptr(), length()); }

	/// Resizes the string. The given size must include the null terminator.
	/// New characters are not initialized, and should be set by the caller.
	_FORCE_INLINE_ Error resize_uninitialized(int64_t p_size) { return _cowdata.template resize<false>(p_size); }

	_FORCE_INLINE_ T get(int p_index) const { return _cowdata.get(p_index); }
	_FORCE_INLINE_ void set(int p_index, const T &p_elem) { _cowdata.set(p_index, p_elem); }
	_FORCE_INLINE_ const T &operator[](int p_index) const {
		if (unlikely(p_index == _cowdata.size())) {
			return _null;
		}
		return _cowdata.get(p_index);
	}
	_FORCE_INLINE_ CharProxy<T> operator[](int p_index) { return CharProxy<T>(p_index, _cowdata); }

	_FORCE_INLINE_ CharStringT() = default;
	_FORCE_INLINE_ CharStringT(const CharStringT &p_str) = default;
	_FORCE_INLINE_ CharStringT(CharStringT &&p_str) = default;
	_FORCE_INLINE_ void operator=(const CharStringT &p_str) { _cowdata = p_str._cowdata; }
	_FORCE_INLINE_ void operator=(CharStringT &&p_str) { _cowdata = std::move(p_str._cowdata); }
	_FORCE_INLINE_ CharStringT(const T *p_cstr) { copy_from(p_cstr); }
	_FORCE_INLINE_ void operator=(const T *p_cstr) { copy_from(p_cstr); }

	_FORCE_INLINE_ bool operator==(const CharStringT<T> &p_other) const { return span() == p_other.span(); }
	_FORCE_INLINE_ bool operator!=(const CharStringT<T> &p_other) const { return !(*this == p_other); }
	_FORCE_INLINE_ bool operator<(const CharStringT<T> &p_other) const {
		if (length() == 0) {
			return p_other.length() != 0;
		}
		return str_compare(get_data(), p_other.get_data()) < 0;
	}
	_FORCE_INLINE_ CharStringT<T> &operator+=(T p_char) {
		const int lhs_len = length();
		resize_uninitialized(lhs_len + 2);

		T *dst = ptrw();
		dst[lhs_len] = p_char;
		dst[lhs_len + 1] = _null;

		return *this;
	}

	uint32_t hash() const { return hash_djb2(get_data()); }

protected:
	void copy_from(const T *p_cstr) {
		if (!p_cstr) {
			resize_uninitialized(0);
			return;
		}

		size_t len = strlen(p_cstr);
		if (len == 0) {
			resize_uninitialized(0);
			return;
		}

		Error err = resize_uninitialized(++len); // include terminating null char.

		ERR_FAIL_COND_MSG(err != OK, "Failed to copy C-string.");

		memcpy(ptrw(), p_cstr, len * sizeof(T));
	}
};

template <typename T>
struct is_zero_constructible<CharStringT<T>> : std::true_type {};

using CharString = CharStringT<char>;
using Char16String = CharStringT<char16_t>;
using Char32String = CharStringT<char32_t>;
using CharWideString = CharStringT<wchar_t>;

} // namespace godot
