/**************************************************************************/
/*  math.compat.inc                                                  */
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


#ifndef DISABLE_DEPRECATED

namespace godot {

#undef ABS

// Generic ABS function, for math uses please use Math::abs.
/**
 * Returns the absolute value through comparison with zero and unary negation. Kept for source compatibility when deprecated APIs are enabled.
 *
 * **Used for** compiling older extension code that obtains a magnitude through the generic ABS function.
 *
 * - `T` — Type supporting comparison with zero and unary negation.
 * - `m_v` — Value whose magnitude is returned if representable as this type.
 */
template <typename T>
[[deprecated("Use Math::abs instead")]]
constexpr T ABS(T m_v) {
	return m_v < 0 ? -m_v : m_v;
}

}

// To maintain compatibility an alias is defined outside the namespace.
// Consider it deprecated.
/**
 * Exposes `godot::real_t` in the global namespace for source compatibility with older extension code.
 *
 * **Used for** compiling older extension code that uses the scalar type without a namespace qualification.
 */
using real_t = ::godot::real_t;

#endif
