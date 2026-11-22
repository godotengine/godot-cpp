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

/**
 * Declares the copy-on-write code unit buffer that uses this proxy.
 */
template <typename T>
class CharStringT;

/**
 * Refers to one code unit in a string buffer. Reading loads the unit and assignment requests writable access through copy-on-write storage.
 */
template <typename T>
class [[nodiscard]] CharProxy {
	/**
	 * Allows `godot::String` to construct proxies for its buffer.
	 */
	friend String;
	/**
	 * Allows `godot::CharStringT` to construct proxies for its buffer.
	 */
	friend CharStringT<T>;

	/**
	 * Stores the code unit index in the referenced buffer.
	 */
	const int _index;
	/**
	 * Refers to the buffer owner whose storage is read or detached on write.
	 */
	CowData<T> &_cowdata;
	/**
	 * Zero code unit returned when a read is exactly past the buffer.
	 */
	static constexpr T _null = 0;

	/**
	 * Associates the proxy with an index and its owning buffer.
	 */
	_FORCE_INLINE_ CharProxy(const int &p_index, CowData<T> &p_cowdata) :
			_index(p_index),
			_cowdata(p_cowdata) {}

public:
	/**
	 * Copies the buffer and index association. Both proxies refer to the same position.
	 */
	_FORCE_INLINE_ CharProxy(const CharProxy<T> &p_other) :
			_index(p_other._index),
			_cowdata(p_other._cowdata) {}

	/**
	 * Returns the code unit or zero when the index equals the buffer size.
	 */
	_FORCE_INLINE_ operator T() const {
		if (unlikely(_index == _cowdata.size())) {
			return _null;
		}

		return _cowdata.get(_index);
	}

	/**
	 * Returns the address of the code unit in the current buffer, without detaching shared storage.
	 */
	_FORCE_INLINE_ const T *operator&() const {
		return _cowdata.ptr() + _index;
	}

	/**
	 * Writes the supplied unit at the proxy's index using copy-on-write access.
	 */
	_FORCE_INLINE_ void operator=(const T &p_other) const {
		_cowdata.set(_index, p_other);
	}

	/**
	 * Reads the source proxy and writes its code unit to this proxy's index.
	 */
	_FORCE_INLINE_ void operator=(const CharProxy<T> &p_other) const {
		_cowdata.set(_index, p_other.operator T());
	}
};

/*************************************************************************/
/*  CharStringT                                                          */
/*************************************************************************/

/**
 * Stores a copy-on-write, null-terminated buffer. Lengths and indices refer to code units.
 *
 * - `T` — The code unit type used by the buffer and its terminator.
 */
template <typename T>
class [[nodiscard]] CharStringT {
	/**
	 * Owns the buffer, including the terminator when the buffer is allocated.
	 */
	CowData<T> _cowdata;
	/**
	 * Holds a zero code unit used as the empty buffer fallback.
	 */
	static constexpr T _null = 0;

public:
	/**
	 * Returns the writable buffer after detaching shared storage.
	 */
	_FORCE_INLINE_ T *ptrw() _LIFETIME_BOUND_ { return _cowdata.ptrw(); }
	/**
	 * Returns a read-only pointer to the stored buffer. It can be null for an empty buffer.
	 */
	_FORCE_INLINE_ const T *ptr() const _LIFETIME_BOUND_ { return _cowdata.ptr(); }
	/**
	 * Returns a null-terminated pointer, with a static zero code unit as the empty fallback.
	 */
	_FORCE_INLINE_ const T *get_data() const _LIFETIME_BOUND_ { return size() ? ptr() : &_null; }

	// Returns the number of characters in the buffer, including the terminating NUL character.
	// In most cases, length() should be used instead.
	/**
	 * Returns the number of stored code units, including the null terminator when allocated.
	 */
	_FORCE_INLINE_ int size() const { return _cowdata.size(); }
	// Returns the number of characters in the string (excluding terminating NUL character).
	/**
	 * Returns the number of code units excluding the null terminator.
	 */
	_FORCE_INLINE_ int length() const { return size() ? size() - 1 : 0; }
	/**
	 * Returns whether the content has no code units.
	 */
	_FORCE_INLINE_ bool is_empty() const { return length() == 0; }

	/**
	 * Creates a read-only view of the content without the terminator.
	 */
	_FORCE_INLINE_ operator Span<T>() const _LIFETIME_BOUND_ { return Span(ptr(), length()); }
	/**
	 * Returns a borrowed read-only view of the content without the terminator.
	 */
	_FORCE_INLINE_ Span<T> span() const _LIFETIME_BOUND_ { return Span(ptr(), length()); }

	/// Resizes the string. The given size must include the null terminator.
	/// New characters are not initialized, and should be set by the caller.
	_FORCE_INLINE_ Error resize_uninitialized(int64_t p_size) { return _cowdata.template resize<false>(p_size); }

	/**
	 * Reads the code unit at a valid stored index.
	 */
	_FORCE_INLINE_ T get(int p_index) const { return _cowdata.get(p_index); }
	/**
	 * Replaces the code unit at a valid stored index, detaching shared storage when needed.
	 */
	_FORCE_INLINE_ void set(int p_index, const T &p_elem) { _cowdata.set(p_index, p_elem); }
	/**
	 * Reads the stored unit by reference. An index equal to the buffer size returns the static zero code unit.
	 */
	_FORCE_INLINE_ const T &operator[](int p_index) const {
		if (unlikely(p_index == _cowdata.size())) {
			return _null;
		}
		return _cowdata.get(p_index);
	}
	/**
	 * Returns a proxy for reading or writing the indexed code unit through the string's storage.
	 */
	_FORCE_INLINE_ CharProxy<T> operator[](int p_index) { return CharProxy<T>(p_index, _cowdata); }

	/**
	 * Creates an empty string without allocating a buffer.
	 */
	_FORCE_INLINE_ CharStringT() = default;
	/**
	 * Shares the source buffer until a write requires a copy.
	 */
	_FORCE_INLINE_ CharStringT(const CharStringT &p_str) = default;
	/**
	 * Takes ownership of the source's buffer.
	 */
	_FORCE_INLINE_ CharStringT(CharStringT &&p_str) = default;
	/**
	 * Replaces the current buffer with shared storage from the source.
	 */
	_FORCE_INLINE_ void operator=(const CharStringT &p_str) { _cowdata = p_str._cowdata; }
	/**
	 * Moves the source's buffer into this string.
	 */
	_FORCE_INLINE_ void operator=(CharStringT &&p_str) { _cowdata = std::move(p_str._cowdata); }
	/**
	 * Copies the null-terminated input. A null pointer yields an empty string.
	 */
	_FORCE_INLINE_ CharStringT(const T *p_cstr) { copy_from(p_cstr); }
	/**
	 * Replaces the content with a copy of the null-terminated input. A null pointer clears it.
	 */
	_FORCE_INLINE_ void operator=(const T *p_cstr) { copy_from(p_cstr); }

	/**
	 * Compares the code unit sequences, excluding their terminators.
	 */
	_FORCE_INLINE_ bool operator==(const CharStringT<T> &p_other) const { return span() == p_other.span(); }
	/**
	 * Returns whether the code unit sequences differ.
	 */
	_FORCE_INLINE_ bool operator!=(const CharStringT<T> &p_other) const { return !(*this == p_other); }
	/**
	 * Compares null-terminated content lexicographically by code unit, with empty content ordered first.
	 */
	_FORCE_INLINE_ bool operator<(const CharStringT<T> &p_other) const {
		if (length() == 0) {
			return p_other.length() != 0;
		}
		return str_compare(get_data(), p_other.get_data()) < 0;
	}
	/**
	 * Appends one code unit and writes the terminator after it.
	 */
	_FORCE_INLINE_ CharStringT<T> &operator+=(T p_char) {
		const int lhs_len = length();
		resize_uninitialized(lhs_len + 2);

		T *dst = ptrw();
		dst[lhs_len] = p_char;
		dst[lhs_len + 1] = _null;

		return *this;
	}

	/**
	 * Computes the DJB2 hash of the null-terminated content.
	 */
	uint32_t hash() const { return hash_djb2(get_data()); }

protected:
	/**
	 * Copies the input including its terminator. A null pointer or empty input releases the stored buffer.
	 */
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

/**
 * Marks the string buffer as valid when initialized to all zero bytes.
 */
template <typename T>
struct is_zero_constructible<CharStringT<T>> : std::true_type {};

/**
 * Stores a null-terminated buffer of narrow `char` code units.
 */
using CharString = CharStringT<char>;
/**
 * Stores a null-terminated buffer of `char16_t` code units.
 */
using Char16String = CharStringT<char16_t>;
/**
 * Stores a null-terminated buffer of `char32_t` code units.
 */
using Char32String = CharStringT<char32_t>;
/**
 * Stores a null-terminated buffer of platform-width `wchar_t` code units.
 */
using CharWideString = CharStringT<wchar_t>;

} // namespace godot
