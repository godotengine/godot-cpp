/**************************************************************************/
/*  math_defs.hpp                                                         */
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

#include <limits>
namespace godot {

namespace Math {
inline constexpr double SQRT2 = 1.4142135623730950488016887242;
inline constexpr double SQRT3 = 1.7320508075688772935274463415059;
inline constexpr double SQRT12 = 0.7071067811865475244008443621048490;
inline constexpr double SQRT13 = 0.57735026918962576450914878050196;
inline constexpr double LN2 = 0.6931471805599453094172321215;
inline constexpr double TAU = 6.2831853071795864769252867666;
inline constexpr double PI = 3.1415926535897932384626433833;
inline constexpr double E = 2.7182818284590452353602874714;
inline constexpr double INF = std::numeric_limits<double>::infinity();
inline constexpr double NaN = std::numeric_limits<double>::quiet_NaN();
} // namespace Math

inline constexpr double CMP_EPSILON = 0.00001;
inline constexpr double CMP_EPSILON2 = CMP_EPSILON * CMP_EPSILON;

inline constexpr double CMP_NORMALIZE_TOLERANCE = 0.000001;
inline constexpr double CMP_POINT_IN_PLANE_EPSILON = 0.00001;

#ifdef DEBUG_ENABLED
#define MATH_CHECKS
#endif

//this epsilon is for values related to a unit size (scalar or vector len)
#ifdef PRECISE_MATH_CHECKS
inline constexpr double UNIT_EPSILON = 0.00001;
#else
//tolerate some more floating point error normally
inline constexpr double UNIT_EPSILON = 0.001;
#endif

#define USEC_TO_SEC(m_usec) ((m_usec) / 1000000.0)

/**
 * The "Real" type is an abstract type used for real numbers, such as 1.5,
 * in contrast to integer numbers. Precision can be controlled with the
 * presence or absence of the REAL_T_IS_DOUBLE define.
 */
#ifdef REAL_T_IS_DOUBLE
typedef double real_t;
#else
typedef float real_t;
#endif
} // namespace godot
