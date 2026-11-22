/**************************************************************************/
/*  char_utils.hpp                                                        */
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

#include "char_range.inc.hpp"

namespace godot {

/**
 * Binary-searches sorted inclusive ranges for the enclosing function's `p_char` and returns the result from that function.
 *
 * **Used for** implementing the Unicode predicates below from sorted ranges.
 *
 * - `m_array` — Array of inclusive ranges, ordered by starting code point. The enclosing function must supply p_char.
 *
 * ```cpp
 * // Inside is_unicode_identifier_start(), before this macro is undefined.
 * BSEARCH_CHAR_RANGE(xid_start);
 * ```
 */
#define BSEARCH_CHAR_RANGE(m_array) \
	int low = 0; \
	int high = sizeof(m_array) / sizeof(m_array[0]) - 1; \
	int middle = (low + high) / 2; \
\
	while (low <= high) { \
		if (p_char < m_array[middle].start) { \
			high = middle - 1; \
		} else if (p_char > m_array[middle].end) { \
			low = middle + 1; \
		} else { \
			return true; \
		} \
\
		middle = (low + high) / 2; \
	} \
\
	return false

/**
 * Tests Unicode XID_Start membership with underscore also allowed.
 *
 * **Used for** validating the first code point of a Unicode identifier.
 *
 * - `p_char` — Code point to test.
 *
 * ```cpp
 * const String identifier = U"_layer";
 * bool valid_start = !identifier.is_empty() && is_unicode_identifier_start(identifier[0]);
 * ```
 */
constexpr bool is_unicode_identifier_start(char32_t p_char) {
	BSEARCH_CHAR_RANGE(xid_start);
}

/**
 * Tests Unicode XID_Continue membership for characters after the start of an identifier.
 *
 * **Used for** validating a later code point of a Unicode identifier, such as a suffix digit.
 *
 * - `p_char` — Code point to test.
 *
 * ```cpp
 * const String identifier = U"Layer7";
 * bool valid_suffix = is_unicode_identifier_continue(identifier[identifier.length() - 1]);
 * ```
 */
constexpr bool is_unicode_identifier_continue(char32_t p_char) {
	BSEARCH_CHAR_RANGE(xid_continue);
}

/**
 * Tests membership in the uppercase Unicode range table.
 *
 * **Used for** checking the case of the first letter in a Unicode label.
 *
 * - `p_char` — Code point to test.
 *
 * ```cpp
 * const String section = U"\u00C9tage";
 * bool already_capitalized = !section.is_empty() && is_unicode_upper_case(section[0]);
 * ```
 */
constexpr bool is_unicode_upper_case(char32_t p_char) {
	BSEARCH_CHAR_RANGE(uppercase_letter);
}

/**
 * Tests membership in the lowercase Unicode range table.
 *
 * **Used for** deciding whether a Unicode label starts with a lowercase letter.
 *
 * - `p_char` — Code point to test.
 *
 * ```cpp
 * const String caption = U"\u00E9chelle";
 * bool capitalize_first = !caption.is_empty() && is_unicode_lower_case(caption[0]);
 * ```
 */
constexpr bool is_unicode_lower_case(char32_t p_char) {
	BSEARCH_CHAR_RANGE(lowercase_letter);
}

/**
 * Tests membership in the Unicode letter range table.
 *
 * **Used for** checking whether a label begins with a letter from a Unicode script.
 *
 * - `p_char` — Code point to test.
 *
 * ```cpp
 * const String label = U"\u754C7";
 * bool starts_with_letter = !label.is_empty() && is_unicode_letter(label[0]);
 * ```
 */
constexpr bool is_unicode_letter(char32_t p_char) {
	BSEARCH_CHAR_RANGE(unicode_letter);
}

#undef BSEARCH_CHAR_RANGE

/**
 * Tests whether the code point is an ASCII uppercase letter from A through Z.
 *
 * **Used for** checking a command key before converting its uppercase letter to lowercase.
 *
 * - `p_char` — Code point to test.
 *
 * ```cpp
 * char32_t key = U'G'; // ASCII key in an input command.
 * if (is_ascii_upper_case(key)) { key += U'a' - U'A'; }
 * ```
 */
constexpr bool is_ascii_upper_case(char32_t p_char) {
	return (p_char >= 'A' && p_char <= 'Z');
}

/**
 * Tests whether the code point is an ASCII lowercase letter from a through z.
 *
 * **Used for** checking a drive letter before converting its lowercase form to uppercase.
 *
 * - `p_char` — Code point to test.
 *
 * ```cpp
 * char32_t drive = U'c'; // Drive letter parsed from a path.
 * if (is_ascii_lower_case(drive)) { drive -= U'a' - U'A'; }
 * ```
 */
constexpr bool is_ascii_lower_case(char32_t p_char) {
	return (p_char >= 'a' && p_char <= 'z');
}

/**
 * Tests whether the code point is one of the ten ASCII decimal digits.
 *
 * **Used for** validating an ASCII digit before subtracting the code point for zero.
 *
 * - `p_char` — Code point to test.
 *
 * ```cpp
 * const String text = "7 steps";
 * int leading_count = is_digit(text[0]) ? int(text[0] - U'0') : 0;
 * ```
 */
constexpr bool is_digit(char32_t p_char) {
	return (p_char >= '0' && p_char <= '9');
}

/**
 * Tests whether the code point is an ASCII decimal digit or a letter from A through F in either case.
 *
 * **Used for** validating digits of a hexadecimal field before converting it to a number.
 *
 * - `p_char` — Code point to test.
 *
 * ```cpp
 * const String code = "3f";
 * if (code.length() != 2 || !is_hex_digit(code[0]) || !is_hex_digit(code[1])) { return; }
 * int channel_value = code.hex_to_int();
 * ```
 */
constexpr bool is_hex_digit(char32_t p_char) {
	return (is_digit(p_char) || (p_char >= 'a' && p_char <= 'f') || (p_char >= 'A' && p_char <= 'F'));
}

/**
 * Tests whether the code point is ASCII zero or one.
 *
 * **Used for** validating each character of a text field containing a binary value.
 *
 * - `p_char` — Code point to test.
 *
 * ```cpp
 * const String bit_mask = "1010";
 * for (int i = 0; i < bit_mask.length(); ++i) {
 *     if (!is_binary_digit(bit_mask[i])) { return; } // Reject invalid mask input.
 * }
 * ```
 */
constexpr bool is_binary_digit(char32_t p_char) {
	return (p_char == '0' || p_char == '1');
}

/**
 * Tests membership in the two ASCII letter ranges.
 *
 * **Used for** validating the letter in a drive prefix.
 *
 * - `p_char` — Code point to test.
 *
 * ```cpp
 * const String path = "C:/atlas.png";
 * bool has_drive_prefix = path.length() >= 2 && is_ascii_alphabet_char(path[0]) && path[1] == U':';
 * ```
 */
constexpr bool is_ascii_alphabet_char(char32_t p_char) {
	return (p_char >= 'a' && p_char <= 'z') || (p_char >= 'A' && p_char <= 'Z');
}

/**
 * Tests whether the code point is an ASCII letter or decimal digit.
 *
 * **Used for** validating a short ID restricted to ASCII letters and digits.
 *
 * - `p_char` — Code point to test.
 *
 * ```cpp
 * const String entered_id = "slot7";
 * for (int i = 0; i < entered_id.length(); ++i) {
 *     if (!is_ascii_alphanumeric_char(entered_id[i])) { return; } // Reject a non-ASCII slot ID.
 * }
 * ```
 */
constexpr bool is_ascii_alphanumeric_char(char32_t p_char) {
	return (p_char >= 'a' && p_char <= 'z') || (p_char >= 'A' && p_char <= 'Z') || (p_char >= '0' && p_char <= '9');
}

/**
 * Tests whether the code point is an ASCII letter, decimal digit, or underscore. Digits pass even when used as the first character.
 *
 * **Used for** scanning the characters of an ASCII identifier token.
 *
 * - `p_char` — Code point to test.
 *
 * ```cpp
 * const String token = "layer_7";
 * int end = 0;
 * while (end < token.length() && is_ascii_identifier_char(token[end])) { ++end; }
 * ```
 */
constexpr bool is_ascii_identifier_char(char32_t p_char) {
	return (p_char >= 'a' && p_char <= 'z') || (p_char >= 'A' && p_char <= 'Z') || (p_char >= '0' && p_char <= '9') || p_char == '_';
}

/**
 * Tests for tab, ASCII space, or ASCII punctuation other than underscore.
 *
 * **Used for** recognizing a delimiter while scanning words or expressions.
 *
 * - `p_char` — Code point to test.
 *
 * ```cpp
 * const String expression = "a+b";
 * bool has_operator_delimiter = is_symbol(expression[1]);
 * ```
 */
constexpr bool is_symbol(char32_t p_char) {
	return p_char != '_' && ((p_char >= '!' && p_char <= '/') || (p_char >= ':' && p_char <= '@') || (p_char >= '[' && p_char <= '`') || (p_char >= '{' && p_char <= '~') || p_char == '\t' || p_char == ' ');
}

/**
 * Tests for C0 or C1 control codes or the ASCII delete code.
 *
 * **Used for** filtering control codes out of a label or input field.
 *
 * - `p_char` — Code point to test.
 *
 * ```cpp
 * const String entered = U"a\u0085b";
 * for (int i = 0; i < entered.length(); ++i) {
 *     if (is_control(entered[i])) { return; } // Reject control codes in the label.
 * }
 * ```
 */
constexpr bool is_control(char32_t p_char) {
	return (p_char <= 0x001f) || (p_char >= 0x007f && p_char <= 0x009f);
}

/**
 * Tests the whitespace set used by Godot, including ASCII space, Unicode spaces such as nonbreaking space, U+200B, and several line breaks.
 *
 * **Used for** locating the first non-whitespace code point in text.
 *
 * - `p_char` — Code point to test.
 *
 * ```cpp
 * const String text = U"\u00A0label";
 * int first = 0;
 * while (first < text.length() && is_whitespace(text[first])) { ++first; }
 * ```
 */
constexpr bool is_whitespace(char32_t p_char) {
	return (p_char == ' ') || (p_char == 0x00a0) || (p_char == 0x1680) || (p_char >= 0x2000 && p_char <= 0x200b) || (p_char == 0x202f) || (p_char == 0x205f) || (p_char == 0x3000) || (p_char == 0x2028) || (p_char == 0x2029) || (p_char >= 0x0009 && p_char <= 0x000d) || (p_char == 0x0085);
}

/**
 * Tests for LF through CR, next line, or the Unicode line or paragraph separator.
 *
 * **Used for** finding where the first line of Unicode text ends.
 *
 * - `p_char` — Code point to test.
 *
 * ```cpp
 * const String text = U"first\u2028second";
 * int first_line_end = 0;
 * while (first_line_end < text.length() && !is_linebreak(text[first_line_end])) { ++first_line_end; }
 * ```
 */
constexpr bool is_linebreak(char32_t p_char) {
	return (p_char >= 0x000a && p_char <= 0x000d) || (p_char == 0x0085) || (p_char == 0x2028) || (p_char == 0x2029);
}

/**
 * Tests Godot's punctuation ranges. They include ASCII space, `U+2000` through
 * `U+206F`, and `U+3000` through `U+303F`. Underscore is excluded.
 *
 * **Used for** checking punctuation at the boundary of a text segment.
 *
 * - `p_char` — Code point to test.
 *
 * ```cpp
 * const String caption = U"next\u3001";
 * bool ends_with_punctuation = !caption.is_empty() && is_punct(caption[caption.length() - 1]);
 * ```
 */
constexpr bool is_punct(char32_t p_char) {
	return (p_char >= ' ' && p_char <= '/') || (p_char >= ':' && p_char <= '@') || (p_char >= '[' && p_char <= '^') || (p_char == '`') || (p_char >= '{' && p_char <= '~') || (p_char >= 0x2000 && p_char <= 0x206f) || (p_char >= 0x3000 && p_char <= 0x303f);
}

/**
 * Tests whether the code point is ASCII underscore.
 *
 * **Used for** finding the underscore boundary between the parts of a token.
 *
 * - `p_char` — Code point to test.
 *
 * ```cpp
 * const String token = "layer_7";
 * int separator = 0;
 * while (separator < token.length() && !is_underscore(token[separator])) { ++separator; }
 * ```
 */
constexpr bool is_underscore(char32_t p_char) {
	return (p_char == '_');
}

} // namespace godot
