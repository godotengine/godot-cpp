/**************************************************************************/
/*  math.hpp                                                              */
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

#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/core/error_macros.hpp>
#include <godot_cpp/core/math_defs.hpp>

#include <gdextension_interface.h>

#include <cmath>

namespace godot {

/**
 * Provides scalar math operations used by the Godot C++ bindings.
 */
namespace Math {

// These four functions do not exist in upstream Godot.
// We keep them to not break compatibility

/**
 * Restricts a value to an inclusive interval.
 *
 * - `T` — Value type used for the bounds and result.
 * - `x` — Value to restrict.
 * - `minv` — Inclusive lower bound.
 * - `maxv` — Inclusive upper bound.
 */
template <typename T>
constexpr T clamp(T x, T minv, T maxv) {
	return static_cast<T>(CLAMP(x, minv, maxv));
}

/**
 * Returns the smaller of two values. Equal values select the second operand.
 *
 * - `T` — Type supporting the comparison and result.
 * - `a` — First candidate value.
 * - `b` — Second candidate value.
 */
template <typename T>
constexpr T min(T a, T b) {
	return static_cast<T>(MIN(a, b));
}

/**
 * Returns the larger of two values. Equal values select the second operand.
 *
 * - `T` — Type supporting the comparison and result.
 * - `a` — First candidate value.
 * - `b` — Second candidate value.
 */
template <typename T>
constexpr T max(T a, T b) {
	return static_cast<T>(MAX(a, b));
}

/**
 * Returns one for a positive value, minus one for a negative value, or zero otherwise.
 *
 * - `T` — Type used to compare with zero and represent the result.
 * - `x` — Value whose sign is tested.
 */
template <typename T>
constexpr T sign(T x) {
	return static_cast<T>(SIGN(x));
}

// Functions reproduced as in Godot's source code `math_funcs.h`.
// Some are overloads to automatically support changing real_t into either double or float in the way Godot does.

/**
 * Returns the sine of the angle.
 *
 * **Used for** finding the vertical component of a unit vector from its angle.
 *
 * - `p_x` — Angle in radians.
 */
_ALWAYS_INLINE_ double sin(double p_x) {
	return std::sin(p_x);
}
/**
 * Returns the sine of the angle.
 *
 * **Used for** finding the vertical component of a unit vector from its angle.
 *
 * - `p_x` — Angle in radians.
 */
_ALWAYS_INLINE_ float sin(float p_x) {
	return std::sin(p_x);
}

/**
 * Returns the cosine of the angle.
 *
 * **Used for** finding the horizontal component of a unit vector from its angle.
 *
 * - `p_x` — Angle in radians.
 */
_ALWAYS_INLINE_ double cos(double p_x) {
	return std::cos(p_x);
}
/**
 * Returns the cosine of the angle.
 *
 * **Used for** finding the horizontal component of a unit vector from its angle.
 *
 * - `p_x` — Angle in radians.
 */
_ALWAYS_INLINE_ float cos(float p_x) {
	return std::cos(p_x);
}

/**
 * Returns the tangent of the angle. The tangent is undefined at odd multiples of π/2.
 *
 * **Used for** converting a slope angle to a rise per unit of horizontal distance.
 *
 * - `p_x` — Angle in radians.
 */
_ALWAYS_INLINE_ double tan(double p_x) {
	return std::tan(p_x);
}
/**
 * Returns the tangent of the angle. The tangent is undefined at odd multiples of π/2.
 *
 * **Used for** converting a slope angle to a rise per unit of horizontal distance.
 *
 * - `p_x` — Angle in radians.
 */
_ALWAYS_INLINE_ float tan(float p_x) {
	return std::tan(p_x);
}

/**
 * Returns the hyperbolic sine.
 *
 * **Used for** computing the slope of a hanging curve modeled as a catenary.
 *
 * - `p_x` — Argument of the hyperbolic sine.
 */
_ALWAYS_INLINE_ double sinh(double p_x) {
	return std::sinh(p_x);
}
/**
 * Returns the hyperbolic sine.
 *
 * **Used for** computing the slope of a hanging curve modeled as a catenary.
 *
 * - `p_x` — Argument of the hyperbolic sine.
 */
_ALWAYS_INLINE_ float sinh(float p_x) {
	return std::sinh(p_x);
}

/**
 * Returns the sine of the argument divided by the argument, with a limit of one at zero.
 *
 * - `p_x` — Angle in radians.
 */
_ALWAYS_INLINE_ double sinc(double p_x) {
	return p_x == 0 ? 1 : sin(p_x) / p_x;
}
/**
 * Returns the sine of the argument divided by the argument, with a limit of one at zero.
 *
 * - `p_x` — Angle in radians.
 */
_ALWAYS_INLINE_ float sinc(float p_x) {
	return p_x == 0 ? 1 : sin(p_x) / p_x;
}

/**
 * Returns the normalized sinc function. It multiplies the input by pi before evaluating the sinc.
 *
 * - `p_x` — Input to the normalized sinc function, before scaling by pi.
 */
_ALWAYS_INLINE_ double sincn(double p_x) {
	return sinc(PI * p_x);
}
/**
 * Returns the normalized sinc function. It multiplies the input by pi before evaluating the sinc.
 *
 * - `p_x` — Input to the normalized sinc function, before scaling by pi.
 */
_ALWAYS_INLINE_ float sincn(float p_x) {
	return sinc((float)PI * p_x);
}

/**
 * Returns the hyperbolic cosine.
 *
 * **Used for** computing the height of a point on a catenary.
 *
 * - `p_x` — Argument of the hyperbolic cosine.
 */
_ALWAYS_INLINE_ double cosh(double p_x) {
	return std::cosh(p_x);
}
/**
 * Returns the hyperbolic cosine.
 *
 * **Used for** computing the height of a point on a catenary.
 *
 * - `p_x` — Argument of the hyperbolic cosine.
 */
_ALWAYS_INLINE_ float cosh(float p_x) {
	return std::cosh(p_x);
}

/**
 * Returns the hyperbolic tangent.
 *
 * **Used for** smoothly limiting a signal's output to the interval between −1 and 1.
 *
 * - `p_x` — Argument of the hyperbolic tangent.
 */
_ALWAYS_INLINE_ double tanh(double p_x) {
	return std::tanh(p_x);
}
/**
 * Returns the hyperbolic tangent.
 *
 * **Used for** smoothly limiting a signal's output to the interval between −1 and 1.
 *
 * - `p_x` — Argument of the hyperbolic tangent.
 */
_ALWAYS_INLINE_ float tanh(float p_x) {
	return std::tanh(p_x);
}

// Always does clamping so always safe to use.
/**
 * Returns the inverse sine in radians after restricting the argument to the interval from minus one to one.
 *
 * **Used for** recovering an angle from a normalized vertical component.
 *
 * - `p_x` — Sine value to invert.
 */
_ALWAYS_INLINE_ double asin(double p_x) {
	return p_x < -1 ? (-PI / 2) : (p_x > 1 ? (PI / 2) : std::asin(p_x));
}
/**
 * Returns the inverse sine in radians after restricting the argument to the interval from minus one to one.
 *
 * **Used for** recovering an angle from a normalized vertical component.
 *
 * - `p_x` — Sine value to invert.
 */
_ALWAYS_INLINE_ float asin(float p_x) {
	return p_x < -1 ? (-(float)PI / 2) : (p_x > 1 ? ((float)PI / 2) : std::asin(p_x));
}

// Always does clamping so always safe to use.
/**
 * Returns the inverse cosine in radians after restricting the argument to the interval from minus one to one.
 *
 * **Used for** finding the angle between two normalized vectors from their dot product.
 *
 * - `p_x` — Cosine value to invert.
 */
_ALWAYS_INLINE_ double acos(double p_x) {
	return p_x < -1 ? PI : (p_x > 1 ? 0 : std::acos(p_x));
}
/**
 * Returns the inverse cosine in radians after restricting the argument to the interval from minus one to one.
 *
 * **Used for** finding the angle between two normalized vectors from their dot product.
 *
 * - `p_x` — Cosine value to invert.
 */
_ALWAYS_INLINE_ float acos(float p_x) {
	return p_x < -1 ? (float)PI : (p_x > 1 ? 0 : std::acos(p_x));
}

/**
 * Returns the inverse tangent in radians.
 *
 * **Used for** converting a signed slope to an angle of inclination.
 *
 * - `p_x` — Tangent value to invert.
 */
_ALWAYS_INLINE_ double atan(double p_x) {
	return std::atan(p_x);
}
/**
 * Returns the inverse tangent in radians.
 *
 * **Used for** converting a signed slope to an angle of inclination.
 *
 * - `p_x` — Tangent value to invert.
 */
_ALWAYS_INLINE_ float atan(float p_x) {
	return std::atan(p_x);
}

/**
 * Returns the signed angle from the positive X axis to the direction given by the two components, in radians.
 *
 * **Used for** orienting an object toward a 2D displacement that may point into any quadrant.
 *
 * - `p_y` — Y component of the direction.
 * - `p_x` — X component of the direction.
 */
_ALWAYS_INLINE_ double atan2(double p_y, double p_x) {
	return std::atan2(p_y, p_x);
}
/**
 * Returns the signed angle from the positive X axis to the direction given by the two components, in radians.
 *
 * **Used for** orienting an object toward a 2D displacement that may point into any quadrant.
 *
 * - `p_y` — Y component of the direction.
 * - `p_x` — X component of the direction.
 */
_ALWAYS_INLINE_ float atan2(float p_y, float p_x) {
	return std::atan2(p_y, p_x);
}

/**
 * Returns the inverse hyperbolic sine.
 *
 * **Used for** solving for the position on a catenary from its slope.
 *
 * - `p_x` — Hyperbolic sine value to invert.
 */
_ALWAYS_INLINE_ double asinh(double p_x) {
	return std::asinh(p_x);
}
/**
 * Returns the inverse hyperbolic sine.
 *
 * **Used for** solving for the position on a catenary from its slope.
 *
 * - `p_x` — Hyperbolic sine value to invert.
 */
_ALWAYS_INLINE_ float asinh(float p_x) {
	return std::asinh(p_x);
}

// Always does clamping so always safe to use.
/**
 * Returns the inverse hyperbolic cosine, or zero when the argument is smaller than one.
 *
 * **Used for** solving for a distance from the lowest point of a catenary using its normalized height.
 *
 * - `p_x` — Hyperbolic cosine value to invert.
 */
_ALWAYS_INLINE_ double acosh(double p_x) {
	return p_x < 1 ? 0 : std::acosh(p_x);
}
/**
 * Returns the inverse hyperbolic cosine, or zero when the argument is smaller than one.
 *
 * **Used for** solving for a distance from the lowest point of a catenary using its normalized height.
 *
 * - `p_x` — Hyperbolic cosine value to invert.
 */
_ALWAYS_INLINE_ float acosh(float p_x) {
	return p_x < 1 ? 0 : std::acosh(p_x);
}

// Always does clamping so always safe to use.
/**
 * Returns the inverse hyperbolic tangent. Values at or beyond either endpoint return infinity with the corresponding sign.
 *
 * **Used for** recovering an unbounded signal from a value previously limited with `godot::Math::tanh()`.
 *
 * - `p_x` — Hyperbolic tangent value to invert, with a finite result in the open interval from minus one to one.
 */
_ALWAYS_INLINE_ double atanh(double p_x) {
	return p_x <= -1 ? -INF : (p_x >= 1 ? INF : std::atanh(p_x));
}
/**
 * Returns the inverse hyperbolic tangent. Values at or beyond either endpoint return infinity with the corresponding sign.
 *
 * **Used for** recovering an unbounded signal from a value previously limited with `godot::Math::tanh()`.
 *
 * - `p_x` — Hyperbolic tangent value to invert, with a finite result in the open interval from minus one to one.
 */
_ALWAYS_INLINE_ float atanh(float p_x) {
	return p_x <= -1 ? (float)-INF : (p_x >= 1 ? (float)INF : std::atanh(p_x));
}

/**
 * Returns the square root of the argument.
 *
 * **Used for** recovering a length from its squared magnitude.
 *
 * - `p_x` — Radicand. A negative value has no real square root.
 */
_ALWAYS_INLINE_ double sqrt(double p_x) {
	return std::sqrt(p_x);
}
/**
 * Returns the square root of the argument.
 *
 * **Used for** recovering a length from its squared magnitude.
 *
 * - `p_x` — Radicand. A negative value has no real square root.
 */
_ALWAYS_INLINE_ float sqrt(float p_x) {
	return std::sqrt(p_x);
}

/**
 * Returns the floating-point remainder after truncating the quotient toward zero. A nonzero remainder has the sign of the dividend.
 *
 * **Used for** finding the fraction of a repeating interval that remains while preserving the dividend's direction.
 *
 * - `p_x` — Dividend.
 * - `p_y` — Divisor. A finite remainder requires a nonzero divisor.
 */
_ALWAYS_INLINE_ double fmod(double p_x, double p_y) {
	return std::fmod(p_x, p_y);
}
/**
 * Returns the floating-point remainder after truncating the quotient toward zero. A nonzero remainder has the sign of the dividend.
 *
 * **Used for** finding the fraction of a repeating interval that remains while preserving the dividend's direction.
 *
 * - `p_x` — Dividend.
 * - `p_y` — Divisor. A finite remainder requires a nonzero divisor.
 */
_ALWAYS_INLINE_ float fmod(float p_x, float p_y) {
	return std::fmod(p_x, p_y);
}

/**
 * Splits the value into integer and fractional parts, both with the input's sign. Returns the fractional part.
 *
 * - `p_x` — Value to split.
 * - `r_y` — Writable storage for the integer part.
 */
_ALWAYS_INLINE_ double modf(double p_x, double *r_y) {
	return std::modf(p_x, r_y);
}
/**
 * Splits the value into integer and fractional parts, both with the input's sign. Returns the fractional part.
 *
 * - `p_x` — Value to split.
 * - `r_y` — Writable storage for the integer part.
 */
_ALWAYS_INLINE_ float modf(float p_x, float *r_y) {
	return std::modf(p_x, r_y);
}

/**
 * Rounds down to the greatest integer-valued number at or below the input.
 *
 * **Used for** choosing the grid cell at or below a position.
 *
 * - `p_x` — Number to round toward negative infinity.
 */
_ALWAYS_INLINE_ double floor(double p_x) {
	return std::floor(p_x);
}
/**
 * Rounds down to the greatest integer-valued number at or below the input.
 *
 * **Used for** choosing the grid cell at or below a position.
 *
 * - `p_x` — Number to round toward negative infinity.
 */
_ALWAYS_INLINE_ float floor(float p_x) {
	return std::floor(p_x);
}

/**
 * Rounds up to the smallest integer-valued number at or above the input.
 *
 * **Used for** counting enough whole cells to cover an extent.
 *
 * - `p_x` — Number to round toward positive infinity.
 */
_ALWAYS_INLINE_ double ceil(double p_x) {
	return std::ceil(p_x);
}
/**
 * Rounds up to the smallest integer-valued number at or above the input.
 *
 * **Used for** counting enough whole cells to cover an extent.
 *
 * - `p_x` — Number to round toward positive infinity.
 */
_ALWAYS_INLINE_ float ceil(float p_x) {
	return std::ceil(p_x);
}

/**
 * Raises the base to the supplied exponent.
 *
 * **Used for** computing multiplicative growth over a specified number of steps.
 *
 * - `p_x` — Base of the power.
 * - `p_y` — Exponent. A negative real base requires an integer-valued exponent for a real result.
 */
_ALWAYS_INLINE_ double pow(double p_x, double p_y) {
	return std::pow(p_x, p_y);
}
/**
 * Raises the base to the supplied exponent.
 *
 * **Used for** computing multiplicative growth over a specified number of steps.
 *
 * - `p_x` — Base of the power.
 * - `p_y` — Exponent. A negative real base requires an integer-valued exponent for a real result.
 */
_ALWAYS_INLINE_ float pow(float p_x, float p_y) {
	return std::pow(p_x, p_y);
}

/**
 * Returns the natural logarithm. Zero returns negative infinity and negative inputs return NaN.
 *
 * **Used for** recovering an exponent or converting a multiplicative ratio to a logarithmic scale.
 *
 * - `p_x` — Positive input for a finite logarithm.
 */
_ALWAYS_INLINE_ double log(double p_x) {
	return std::log(p_x);
}
/**
 * Returns the natural logarithm. Zero returns negative infinity and negative inputs return NaN.
 *
 * **Used for** recovering an exponent or converting a multiplicative ratio to a logarithmic scale.
 *
 * - `p_x` — Positive input for a finite logarithm.
 */
_ALWAYS_INLINE_ float log(float p_x) {
	return std::log(p_x);
}

/**
 * Returns the natural logarithm of one plus the argument.
 *
 * - `p_x` — Value added to one before taking the logarithm. A finite result requires a value greater than minus one.
 */
_ALWAYS_INLINE_ double log1p(double p_x) {
	return std::log1p(p_x);
}
/**
 * Returns the natural logarithm of one plus the argument.
 *
 * - `p_x` — Value added to one before taking the logarithm. A finite result requires a value greater than minus one.
 */
_ALWAYS_INLINE_ float log1p(float p_x) {
	return std::log1p(p_x);
}

/**
 * Returns the base-two logarithm.
 *
 * - `p_x` — Positive input for a finite logarithm.
 */
_ALWAYS_INLINE_ double log2(double p_x) {
	return std::log2(p_x);
}
/**
 * Returns the base-two logarithm.
 *
 * - `p_x` — Positive input for a finite logarithm.
 */
_ALWAYS_INLINE_ float log2(float p_x) {
	return std::log2(p_x);
}

/**
 * Raises Euler's number to the supplied power.
 *
 * **Used for** computing a continuous growth or decay factor from an exponent.
 *
 * - `p_x` — Exponent of the natural exponential.
 */
_ALWAYS_INLINE_ double exp(double p_x) {
	return std::exp(p_x);
}
/**
 * Raises Euler's number to the supplied power.
 *
 * **Used for** computing a continuous growth or decay factor from an exponent.
 *
 * - `p_x` — Exponent of the natural exponential.
 */
_ALWAYS_INLINE_ float exp(float p_x) {
	return std::exp(p_x);
}

/**
 * Returns the magnitude and converts signed zero to positive zero.
 *
 * **Used for** measuring the magnitude of a signed difference.
 *
 * - `p_value` — Floating-point input.
 */
constexpr double abs(double p_value) {
	return p_value == 0 ? 0.0 : (p_value < 0 ? -p_value : p_value);
}
/**
 * Returns the magnitude and converts signed zero to positive zero.
 *
 * **Used for** measuring the magnitude of a signed difference.
 *
 * - `p_value` — Floating-point input.
 */
constexpr float abs(float p_value) {
	return p_value == 0 ? 0.0 : (p_value < 0 ? -p_value : p_value);
}
/**
 * Returns the magnitude of the integer when it is representable in the result type.
 *
 * - `p_value` — Signed input. The magnitude of the most negative value cannot be represented in this type.
 */
constexpr int8_t abs(int8_t p_value) {
	return p_value > 0 ? p_value : -p_value;
}
/**
 * Returns the magnitude of the integer when it is representable in the result type.
 *
 * - `p_value` — Signed input. The magnitude of the most negative value cannot be represented in this type.
 */
constexpr int16_t abs(int16_t p_value) {
	return p_value > 0 ? p_value : -p_value;
}
/**
 * Returns the magnitude of the integer when it is representable in the result type.
 *
 * - `p_value` — Signed input. The magnitude of the most negative value cannot be represented in this type.
 */
constexpr int32_t abs(int32_t p_value) {
	return p_value > 0 ? p_value : -p_value;
}
/**
 * Returns the magnitude of the integer when it is representable in the result type.
 *
 * - `p_value` — Signed input. The magnitude of the most negative value cannot be represented in this type.
 */
constexpr int64_t abs(int64_t p_value) {
	return p_value > 0 ? p_value : -p_value;
}

/**
 * Checks whether the value is a floating-point NaN.
 *
 * **Used for** detecting an undefined floating-point result before using it in further calculations.
 *
 * - `p_val` — Value to test for NaN.
 */
constexpr bool is_nan(double p_val) {
	return p_val != p_val;
}
/**
 * Checks whether the value is a floating-point NaN.
 *
 * **Used for** detecting an undefined floating-point result before using it in further calculations.
 *
 * - `p_val` — Value to test for NaN.
 */
constexpr bool is_nan(float p_val) {
	return p_val != p_val;
}

/**
 * Checks whether the value is positive or negative infinity.
 *
 * **Used for** detecting an unbounded floating-point result or an overflow represented as infinity.
 *
 * - `p_val` — Value to test for infinity.
 */
constexpr bool is_inf(double p_val) {
	return abs(p_val) == INF;
}
/**
 * Checks whether the value is positive or negative infinity.
 *
 * **Used for** detecting an unbounded floating-point result or an overflow represented as infinity.
 *
 * - `p_val` — Value to test for infinity.
 */
constexpr bool is_inf(float p_val) {
	return abs(p_val) == (float)INF;
}

// These methods assume (p_num + p_den) doesn't overflow.
/**
 * Computes the ceiling of the integer quotient for operands of the same sign or a zero numerator with a positive divisor. Intermediate sums must fit.
 *
 * - `p_num` — Integer numerator.
 * - `p_den` — Nonzero denominator. Use matching operand signs for a nonzero numerator.
 */
constexpr int32_t division_round_up(int32_t p_num, int32_t p_den) {
	int32_t offset = (p_num < 0 && p_den < 0) ? 1 : -1;
	return (p_num + p_den + offset) / p_den;
}
/**
 * Computes the ceiling of the unsigned quotient. The sum of the operands must fit.
 *
 * - `p_num` — Unsigned numerator.
 * - `p_den` — Nonzero unsigned denominator.
 */
constexpr uint32_t division_round_up(uint32_t p_num, uint32_t p_den) {
	return (p_num + p_den - 1) / p_den;
}
/**
 * Computes the ceiling of the integer quotient for operands of the same sign or a zero numerator with a positive divisor. Intermediate sums must fit.
 *
 * - `p_num` — Integer numerator.
 * - `p_den` — Nonzero denominator. Use matching operand signs for a nonzero numerator.
 */
constexpr int64_t division_round_up(int64_t p_num, int64_t p_den) {
	int32_t offset = (p_num < 0 && p_den < 0) ? 1 : -1;
	return (p_num + p_den + offset) / p_den;
}
/**
 * Computes the ceiling of the unsigned quotient. The sum of the operands must fit.
 *
 * - `p_num` — Unsigned numerator.
 * - `p_den` — Nonzero unsigned denominator.
 */
constexpr uint64_t division_round_up(uint64_t p_num, uint64_t p_den) {
	return (p_num + p_den - 1) / p_den;
}
GODOT_MSVC_WARNING_PUSH_AND_IGNORE(4146) // Unary minus operator applied to unsigned type, result still unsigned
/**
 * Divides with truncation toward zero. Uses unsigned negation for a divisor of minus one to handle the most negative numerator.
 *
 * - `p_num` — Signed dividend.
 * - `p_den` — Nonzero divisor.
 */
constexpr int32_t division_no_overflow(int32_t p_num, int32_t p_den) {
	if (unlikely(p_den == -1)) {
		return int32_t(-uint32_t(p_num));
	}
	return p_num / p_den;
}
/**
 * Divides with truncation toward zero. Uses unsigned negation for a divisor of minus one to handle the most negative numerator.
 *
 * - `p_num` — Signed dividend.
 * - `p_den` — Nonzero divisor.
 */
constexpr int64_t division_no_overflow(int64_t p_num, int64_t p_den) {
	if (unlikely(p_den == -1)) {
		return int64_t(-uint64_t(p_num));
	}
	return p_num / p_den;
}
GODOT_MSVC_WARNING_POP
/**
 * Returns the signed remainder. A divisor of minus one always returns zero, including for the most negative dividend.
 *
 * - `p_num` — Signed dividend.
 * - `p_den` — Nonzero divisor.
 */
constexpr int32_t modulo_no_overflow(int32_t p_num, int32_t p_den) {
	if (unlikely(p_den == -1)) {
		return 0;
	}
	return p_num % p_den;
}
/**
 * Returns the signed remainder. A divisor of minus one always returns zero, including for the most negative dividend.
 *
 * - `p_num` — Signed dividend.
 * - `p_den` — Nonzero divisor.
 */
constexpr int64_t modulo_no_overflow(int64_t p_num, int64_t p_den) {
	if (unlikely(p_den == -1)) {
		return 0;
	}
	return p_num % p_den;
}
/**
 * Checks whether the value is neither infinite nor NaN.
 *
 * **Used for** rejecting invalid movement or calculation results before storing them.
 *
 * - `p_val` — Value to test for finiteness.
 */
constexpr bool is_finite(double p_val) {
	return !is_nan(p_val) && !is_inf(p_val);
}
/**
 * Checks whether the value is neither infinite nor NaN.
 *
 * **Used for** rejecting invalid movement or calculation results before storing them.
 *
 * - `p_val` — Value to test for finiteness.
 */
constexpr bool is_finite(float p_val) {
	return !is_nan(p_val) && !is_inf(p_val);
}

/**
 * Computes a floating-point remainder with the sign of the divisor when the result is nonzero.
 *
 * **Used for** wrapping a value into a periodic interval, including values below the start.
 *
 * - `p_x` — Dividend to wrap.
 * - `p_y` — Nonzero divisor that sets the period and the sign of the remainder.
 */
_ALWAYS_INLINE_ double fposmod(double p_x, double p_y) {
	double value = fmod(p_x, p_y);
	if (((value < 0) && (p_y > 0)) || ((value > 0) && (p_y < 0))) {
		value += p_y;
	}
	value += 0.0;
	return value;
}
/**
 * Computes a floating-point remainder with the sign of the divisor when the result is nonzero.
 *
 * **Used for** wrapping a value into a periodic interval, including values below the start.
 *
 * - `p_x` — Dividend to wrap.
 * - `p_y` — Nonzero divisor that sets the period and the sign of the remainder.
 */
_ALWAYS_INLINE_ float fposmod(float p_x, float p_y) {
	float value = fmod(p_x, p_y);
	if (((value < 0) && (p_y > 0)) || ((value > 0) && (p_y < 0))) {
		value += p_y;
	}
	value += 0.0f;
	return value;
}

/**
 * Computes the nonnegative floating-point remainder for a positive divisor.
 *
 * - `p_x` — Dividend to wrap.
 * - `p_y` — Positive divisor that sets the period.
 */
_ALWAYS_INLINE_ double fposmodp(double p_x, double p_y) {
	double value = fmod(p_x, p_y);
	if (value < 0) {
		value += p_y;
	}
	value += 0.0;
	return value;
}
/**
 * Computes the nonnegative floating-point remainder for a positive divisor.
 *
 * - `p_x` — Dividend to wrap.
 * - `p_y` — Positive divisor that sets the period.
 */
_ALWAYS_INLINE_ float fposmodp(float p_x, float p_y) {
	float value = fmod(p_x, p_y);
	if (value < 0) {
		value += p_y;
	}
	value += 0.0f;
	return value;
}

/**
 * Computes a signed integer remainder with the sign of the divisor when nonzero. Logs an error and returns zero for a zero divisor.
 *
 * **Used for** wrapping a value into a periodic interval, including values below the start.
 *
 * - `p_x` — Integer dividend.
 * - `p_y` — Integer divisor. The quotient must be representable for the remainder operation.
 */
_ALWAYS_INLINE_ int64_t posmod(int64_t p_x, int64_t p_y) {
	ERR_FAIL_COND_V_MSG(p_y == 0, 0, "Division by zero in posmod is undefined. Returning 0 as fallback.");
	int64_t value = p_x % p_y;
	if (((value < 0) && (p_y > 0)) || ((value > 0) && (p_y < 0))) {
		value += p_y;
	}
	return value;
}

/**
 * Converts an angle from degrees to radians.
 *
 * **Used for** passing an angle entered in an editor field to a Godot rotation API.
 *
 * - `p_y` — Angle in degrees.
 */
constexpr double deg_to_rad(double p_y) {
	return p_y * (PI / 180.0);
}
/**
 * Converts an angle from degrees to radians.
 *
 * **Used for** passing an angle entered in an editor field to a Godot rotation API.
 *
 * - `p_y` — Angle in degrees.
 */
constexpr float deg_to_rad(float p_y) {
	return p_y * ((float)PI / 180.0f);
}

/**
 * Converts an angle from radians to degrees.
 *
 * **Used for** displaying a Godot rotation angle in an editor or debugging tool.
 *
 * - `p_y` — Angle in radians.
 */
constexpr double rad_to_deg(double p_y) {
	return p_y * (180.0 / PI);
}
/**
 * Converts an angle from radians to degrees.
 *
 * **Used for** displaying a Godot rotation angle in an editor or debugging tool.
 *
 * - `p_y` — Angle in radians.
 */
constexpr float rad_to_deg(float p_y) {
	return p_y * (180.0f / (float)PI);
}

/**
 * Interpolates linearly between two values. Weights outside zero to one extrapolate.
 *
 * **Used for** blending two scalar measurements or animation values at a chosen progress fraction.
 *
 * - `p_from` — Start value at weight zero.
 * - `p_to` — End value at weight one.
 * - `p_weight` — Interpolation factor. Zero selects the start and one selects the end.
 */
constexpr double lerp(double p_from, double p_to, double p_weight) {
	return p_from + (p_to - p_from) * p_weight;
}
/**
 * Interpolates linearly between two values. Weights outside zero to one extrapolate.
 *
 * **Used for** blending two scalar measurements or animation values at a chosen progress fraction.
 *
 * - `p_from` — Start value at weight zero.
 * - `p_to` — End value at weight one.
 * - `p_weight` — Interpolation factor. Zero selects the start and one selects the end.
 */
constexpr float lerp(float p_from, float p_to, float p_weight) {
	return p_from + (p_to - p_from) * p_weight;
}

/**
 * Evaluates a cubic interpolant between two samples with two adjacent control samples.
 *
 * **Used for** smoothing a scalar animation curve between sampled values.
 *
 * - `p_from` — Start value at weight zero.
 * - `p_to` — End value at weight one.
 * - `p_pre` — Control sample before the start.
 * - `p_post` — Control sample after the end.
 * - `p_weight` — Interpolation factor. Zero selects the start and one selects the end.
 */
constexpr double cubic_interpolate(double p_from, double p_to, double p_pre, double p_post, double p_weight) {
	return 0.5 *
			((p_from * 2.0) +
					(-p_pre + p_to) * p_weight +
					(2.0 * p_pre - 5.0 * p_from + 4.0 * p_to - p_post) * (p_weight * p_weight) +
					(-p_pre + 3.0 * p_from - 3.0 * p_to + p_post) * (p_weight * p_weight * p_weight));
}
/**
 * Evaluates a cubic interpolant between two samples with two adjacent control samples.
 *
 * **Used for** smoothing a scalar animation curve between sampled values.
 *
 * - `p_from` — Start value at weight zero.
 * - `p_to` — End value at weight one.
 * - `p_pre` — Control sample before the start.
 * - `p_post` — Control sample after the end.
 * - `p_weight` — Interpolation factor. Zero selects the start and one selects the end.
 */
constexpr float cubic_interpolate(float p_from, float p_to, float p_pre, float p_post, float p_weight) {
	return 0.5f *
			((p_from * 2.0f) +
					(-p_pre + p_to) * p_weight +
					(2.0f * p_pre - 5.0f * p_from + 4.0f * p_to - p_post) * (p_weight * p_weight) +
					(-p_pre + 3.0f * p_from - 3.0f * p_to + p_post) * (p_weight * p_weight * p_weight));
}

/**
 * Unwraps neighboring angles around each segment before evaluating a cubic interpolant.
 *
 * **Used for** smoothing angular motion between sampled rotations.
 *
 * - `p_from` — Start angle in radians.
 * - `p_to` — Target angle in radians.
 * - `p_pre` — Control angle before the start, in radians.
 * - `p_post` — Control angle after the end, in radians.
 * - `p_weight` — Interpolation factor. Zero selects the start and one selects the end.
 */
_ALWAYS_INLINE_ double cubic_interpolate_angle(double p_from, double p_to, double p_pre, double p_post, double p_weight) {
	double from_rot = fmod(p_from, TAU);

	double pre_diff = fmod(p_pre - from_rot, TAU);
	double pre_rot = from_rot + fmod(2.0 * pre_diff, TAU) - pre_diff;

	double to_diff = fmod(p_to - from_rot, TAU);
	double to_rot = from_rot + fmod(2.0 * to_diff, TAU) - to_diff;

	double post_diff = fmod(p_post - to_rot, TAU);
	double post_rot = to_rot + fmod(2.0 * post_diff, TAU) - post_diff;

	return cubic_interpolate(from_rot, to_rot, pre_rot, post_rot, p_weight);
}

/**
 * Unwraps neighboring angles around each segment before evaluating a cubic interpolant.
 *
 * **Used for** smoothing angular motion between sampled rotations.
 *
 * - `p_from` — Start angle in radians.
 * - `p_to` — Target angle in radians.
 * - `p_pre` — Control angle before the start, in radians.
 * - `p_post` — Control angle after the end, in radians.
 * - `p_weight` — Interpolation factor. Zero selects the start and one selects the end.
 */
_ALWAYS_INLINE_ float cubic_interpolate_angle(float p_from, float p_to, float p_pre, float p_post, float p_weight) {
	float from_rot = fmod(p_from, (float)TAU);

	float pre_diff = fmod(p_pre - from_rot, (float)TAU);
	float pre_rot = from_rot + fmod(2.0f * pre_diff, (float)TAU) - pre_diff;

	float to_diff = fmod(p_to - from_rot, (float)TAU);
	float to_rot = from_rot + fmod(2.0f * to_diff, (float)TAU) - to_diff;

	float post_diff = fmod(p_post - to_rot, (float)TAU);
	float post_rot = to_rot + fmod(2.0f * post_diff, (float)TAU) - post_diff;

	return cubic_interpolate(from_rot, to_rot, pre_rot, post_rot, p_weight);
}

/**
 * Evaluates a cubic interpolant using timestamps that can be unevenly spaced.
 *
 * **Used for** smoothing a scalar animation curve between sampled values.
 *
 * - `p_from` — Start value at weight zero.
 * - `p_to` — End value at weight one.
 * - `p_pre` — Control sample before the start.
 * - `p_post` — Control sample after the end.
 * - `p_weight` — Interpolation factor. Zero selects the start and one selects the end.
 * - `p_to_t` — Time of the end sample relative to the start at time zero.
 * - `p_pre_t` — Time of the preceding sample relative to the start.
 * - `p_post_t` — Time of the following sample relative to the start.
 */
constexpr double cubic_interpolate_in_time(double p_from, double p_to, double p_pre, double p_post, double p_weight,
		double p_to_t, double p_pre_t, double p_post_t) {
	/* Barry-Goldman method */
	double t = lerp(0.0, p_to_t, p_weight);
	double a1 = lerp(p_pre, p_from, p_pre_t == 0 ? 0.0 : (t - p_pre_t) / -p_pre_t);
	double a2 = lerp(p_from, p_to, p_to_t == 0 ? 0.5 : t / p_to_t);
	double a3 = lerp(p_to, p_post, p_post_t - p_to_t == 0 ? 1.0 : (t - p_to_t) / (p_post_t - p_to_t));
	double b1 = lerp(a1, a2, p_to_t - p_pre_t == 0 ? 0.0 : (t - p_pre_t) / (p_to_t - p_pre_t));
	double b2 = lerp(a2, a3, p_post_t == 0 ? 1.0 : t / p_post_t);
	return lerp(b1, b2, p_to_t == 0 ? 0.5 : t / p_to_t);
}
/**
 * Evaluates a cubic interpolant using timestamps that can be unevenly spaced.
 *
 * **Used for** smoothing a scalar animation curve between sampled values.
 *
 * - `p_from` — Start value at weight zero.
 * - `p_to` — End value at weight one.
 * - `p_pre` — Control sample before the start.
 * - `p_post` — Control sample after the end.
 * - `p_weight` — Interpolation factor. Zero selects the start and one selects the end.
 * - `p_to_t` — Time of the end sample relative to the start at time zero.
 * - `p_pre_t` — Time of the preceding sample relative to the start.
 * - `p_post_t` — Time of the following sample relative to the start.
 */
constexpr float cubic_interpolate_in_time(float p_from, float p_to, float p_pre, float p_post, float p_weight,
		float p_to_t, float p_pre_t, float p_post_t) {
	/* Barry-Goldman method */
	float t = lerp(0.0f, p_to_t, p_weight);
	float a1 = lerp(p_pre, p_from, p_pre_t == 0 ? 0.0f : (t - p_pre_t) / -p_pre_t);
	float a2 = lerp(p_from, p_to, p_to_t == 0 ? 0.5f : t / p_to_t);
	float a3 = lerp(p_to, p_post, p_post_t - p_to_t == 0 ? 1.0f : (t - p_to_t) / (p_post_t - p_to_t));
	float b1 = lerp(a1, a2, p_to_t - p_pre_t == 0 ? 0.0f : (t - p_pre_t) / (p_to_t - p_pre_t));
	float b2 = lerp(a2, a3, p_post_t == 0 ? 1.0f : t / p_post_t);
	return lerp(b1, b2, p_to_t == 0 ? 0.5f : t / p_to_t);
}

/**
 * Unwraps adjacent angles and evaluates a cubic interpolant using the samples' relative timestamps.
 *
 * **Used for** smoothing angular motion between sampled rotations.
 *
 * - `p_from` — Start angle in radians.
 * - `p_to` — Target angle in radians.
 * - `p_pre` — Control angle before the start, in radians.
 * - `p_post` — Control angle after the end, in radians.
 * - `p_weight` — Interpolation factor. Zero selects the start and one selects the end.
 * - `p_to_t` — Time of the end sample relative to the start at time zero.
 * - `p_pre_t` — Time of the preceding sample relative to the start.
 * - `p_post_t` — Time of the following sample relative to the start.
 */
_ALWAYS_INLINE_ double cubic_interpolate_angle_in_time(double p_from, double p_to, double p_pre, double p_post, double p_weight,
		double p_to_t, double p_pre_t, double p_post_t) {
	double from_rot = fmod(p_from, TAU);

	double pre_diff = fmod(p_pre - from_rot, TAU);
	double pre_rot = from_rot + fmod(2.0 * pre_diff, TAU) - pre_diff;

	double to_diff = fmod(p_to - from_rot, TAU);
	double to_rot = from_rot + fmod(2.0 * to_diff, TAU) - to_diff;

	double post_diff = fmod(p_post - to_rot, TAU);
	double post_rot = to_rot + fmod(2.0 * post_diff, TAU) - post_diff;

	return cubic_interpolate_in_time(from_rot, to_rot, pre_rot, post_rot, p_weight, p_to_t, p_pre_t, p_post_t);
}
/**
 * Unwraps adjacent angles and evaluates a cubic interpolant using the samples' relative timestamps.
 *
 * **Used for** smoothing angular motion between sampled rotations.
 *
 * - `p_from` — Start angle in radians.
 * - `p_to` — Target angle in radians.
 * - `p_pre` — Control angle before the start, in radians.
 * - `p_post` — Control angle after the end, in radians.
 * - `p_weight` — Interpolation factor. Zero selects the start and one selects the end.
 * - `p_to_t` — Time of the end sample relative to the start at time zero.
 * - `p_pre_t` — Time of the preceding sample relative to the start.
 * - `p_post_t` — Time of the following sample relative to the start.
 */
_ALWAYS_INLINE_ float cubic_interpolate_angle_in_time(float p_from, float p_to, float p_pre, float p_post, float p_weight,
		float p_to_t, float p_pre_t, float p_post_t) {
	float from_rot = fmod(p_from, (float)TAU);

	float pre_diff = fmod(p_pre - from_rot, (float)TAU);
	float pre_rot = from_rot + fmod(2.0f * pre_diff, (float)TAU) - pre_diff;

	float to_diff = fmod(p_to - from_rot, (float)TAU);
	float to_rot = from_rot + fmod(2.0f * to_diff, (float)TAU) - to_diff;

	float post_diff = fmod(p_post - to_rot, (float)TAU);
	float post_rot = to_rot + fmod(2.0f * post_diff, (float)TAU) - post_diff;

	return cubic_interpolate_in_time(from_rot, to_rot, pre_rot, post_rot, p_weight, p_to_t, p_pre_t, p_post_t);
}

/**
 * Evaluates the cubic Bézier curve at the supplied parameter.
 *
 * **Used for** sampling an animation or drawing curve defined by two endpoints and two controls.
 *
 * - `p_start` — First endpoint of the cubic curve.
 * - `p_control_1` — Control point adjacent to the first endpoint.
 * - `p_control_2` — Control point adjacent to the last endpoint.
 * - `p_end` — Last endpoint of the cubic curve.
 * - `p_t` — Curve parameter. Zero selects the start and one selects the end.
 */
constexpr double bezier_interpolate(double p_start, double p_control_1, double p_control_2, double p_end, double p_t) {
	/* Formula from Wikipedia article on Bezier curves. */
	double omt = (1.0 - p_t);
	double omt2 = omt * omt;
	double omt3 = omt2 * omt;
	double t2 = p_t * p_t;
	double t3 = t2 * p_t;

	return p_start * omt3 + p_control_1 * omt2 * p_t * 3.0 + p_control_2 * omt * t2 * 3.0 + p_end * t3;
}
/**
 * Evaluates the cubic Bézier curve at the supplied parameter.
 *
 * **Used for** sampling an animation or drawing curve defined by two endpoints and two controls.
 *
 * - `p_start` — First endpoint of the cubic curve.
 * - `p_control_1` — Control point adjacent to the first endpoint.
 * - `p_control_2` — Control point adjacent to the last endpoint.
 * - `p_end` — Last endpoint of the cubic curve.
 * - `p_t` — Curve parameter. Zero selects the start and one selects the end.
 */
constexpr float bezier_interpolate(float p_start, float p_control_1, float p_control_2, float p_end, float p_t) {
	/* Formula from Wikipedia article on Bezier curves. */
	float omt = (1.0f - p_t);
	float omt2 = omt * omt;
	float omt3 = omt2 * omt;
	float t2 = p_t * p_t;
	float t3 = t2 * p_t;

	return p_start * omt3 + p_control_1 * omt2 * p_t * 3.0f + p_control_2 * omt * t2 * 3.0f + p_end * t3;
}

/**
 * Returns the derivative of the cubic Bézier curve with respect to its parameter.
 *
 * **Used for** finding the slope of a Bézier segment, or the tangent when applied to each component.
 *
 * - `p_start` — First endpoint of the cubic curve.
 * - `p_control_1` — Control point adjacent to the first endpoint.
 * - `p_control_2` — Control point adjacent to the last endpoint.
 * - `p_end` — Last endpoint of the cubic curve.
 * - `p_t` — Curve parameter. Zero selects the start and one selects the end.
 */
constexpr double bezier_derivative(double p_start, double p_control_1, double p_control_2, double p_end, double p_t) {
	/* Formula from Wikipedia article on Bezier curves. */
	double omt = (1.0 - p_t);
	double omt2 = omt * omt;
	double t2 = p_t * p_t;

	double d = (p_control_1 - p_start) * 3.0 * omt2 + (p_control_2 - p_control_1) * 6.0 * omt * p_t + (p_end - p_control_2) * 3.0 * t2;
	return d;
}
/**
 * Returns the derivative of the cubic Bézier curve with respect to its parameter.
 *
 * **Used for** finding the slope of a Bézier segment, or the tangent when applied to each component.
 *
 * - `p_start` — First endpoint of the cubic curve.
 * - `p_control_1` — Control point adjacent to the first endpoint.
 * - `p_control_2` — Control point adjacent to the last endpoint.
 * - `p_end` — Last endpoint of the cubic curve.
 * - `p_t` — Curve parameter. Zero selects the start and one selects the end.
 */
constexpr float bezier_derivative(float p_start, float p_control_1, float p_control_2, float p_end, float p_t) {
	/* Formula from Wikipedia article on Bezier curves. */
	float omt = (1.0f - p_t);
	float omt2 = omt * omt;
	float t2 = p_t * p_t;

	float d = (p_control_1 - p_start) * 3.0f * omt2 + (p_control_2 - p_control_1) * 6.0f * omt * p_t + (p_end - p_control_2) * 3.0f * t2;
	return d;
}

/**
 * Returns the signed shortest angular difference between the two angles, in radians.
 *
 * **Used for** deciding which direction to rotate toward a target heading.
 *
 * - `p_from` — Start angle in radians.
 * - `p_to` — Target angle in radians.
 */
_ALWAYS_INLINE_ double angle_difference(double p_from, double p_to) {
	double difference = fmod(p_to - p_from, TAU);
	return fmod(2.0 * difference, TAU) - difference;
}
/**
 * Returns the signed shortest angular difference between the two angles, in radians.
 *
 * **Used for** deciding which direction to rotate toward a target heading.
 *
 * - `p_from` — Start angle in radians.
 * - `p_to` — Target angle in radians.
 */
_ALWAYS_INLINE_ float angle_difference(float p_from, float p_to) {
	float difference = fmod(p_to - p_from, (float)TAU);
	return fmod(2.0f * difference, (float)TAU) - difference;
}

/**
 * Interpolates in radians along the shortest angular displacement from the start to the target.
 *
 * **Used for** blending headings across the wrap at a full turn.
 *
 * - `p_from` — Start angle in radians.
 * - `p_to` — Target angle in radians.
 * - `p_weight` — Interpolation factor. Zero selects the start and one selects the end.
 */
_ALWAYS_INLINE_ double lerp_angle(double p_from, double p_to, double p_weight) {
	return p_from + angle_difference(p_from, p_to) * p_weight;
}
/**
 * Interpolates in radians along the shortest angular displacement from the start to the target.
 *
 * **Used for** blending headings across the wrap at a full turn.
 *
 * - `p_from` — Start angle in radians.
 * - `p_to` — Target angle in radians.
 * - `p_weight` — Interpolation factor. Zero selects the start and one selects the end.
 */
_ALWAYS_INLINE_ float lerp_angle(float p_from, float p_to, float p_weight) {
	return p_from + angle_difference(p_from, p_to) * p_weight;
}

/**
 * Returns the interpolation factor of a value between the endpoints. A value outside the interval produces a factor outside zero to one.
 *
 * **Used for** normalizing a measured value to a fraction within a known range.
 *
 * - `p_from` — Endpoint corresponding to factor zero.
 * - `p_to` — Distinct endpoint corresponding to factor one.
 * - `p_value` — Value to express as an interpolation factor.
 */
constexpr double inverse_lerp(double p_from, double p_to, double p_value) {
	return (p_value - p_from) / (p_to - p_from);
}
/**
 * Returns the interpolation factor of a value between the endpoints. A value outside the interval produces a factor outside zero to one.
 *
 * **Used for** normalizing a measured value to a fraction within a known range.
 *
 * - `p_from` — Endpoint corresponding to factor zero.
 * - `p_to` — Distinct endpoint corresponding to factor one.
 * - `p_value` — Value to express as an interpolation factor.
 */
constexpr float inverse_lerp(float p_from, float p_to, float p_value) {
	return (p_value - p_from) / (p_to - p_from);
}

/**
 * Maps a value from one interval to another using its linear position. A value outside the source interval extrapolates.
 *
 * **Used for** converting a measurement into another scale, such as mapping slider travel to a gain range.
 *
 * - `p_value` — Value in source units.
 * - `p_istart` — Start of the source interval.
 * - `p_istop` — End of the source interval. Must differ from the start for a finite factor.
 * - `p_ostart` — Destination value corresponding to the source start.
 * - `p_ostop` — Destination value corresponding to the source end.
 */
constexpr double remap(double p_value, double p_istart, double p_istop, double p_ostart, double p_ostop) {
	return lerp(p_ostart, p_ostop, inverse_lerp(p_istart, p_istop, p_value));
}
/**
 * Maps a value from one interval to another using its linear position. A value outside the source interval extrapolates.
 *
 * **Used for** converting a measurement into another scale, such as mapping slider travel to a gain range.
 *
 * - `p_value` — Value in source units.
 * - `p_istart` — Start of the source interval.
 * - `p_istop` — End of the source interval. Must differ from the start for a finite factor.
 * - `p_ostart` — Destination value corresponding to the source start.
 * - `p_ostop` — Destination value corresponding to the source end.
 */
constexpr float remap(float p_value, float p_istart, float p_istop, float p_ostart, float p_ostop) {
	return lerp(p_ostart, p_ostop, inverse_lerp(p_istart, p_istop, p_value));
}

/**
 * Tests exact equality first, then tests whether the absolute difference is strictly below the supplied tolerance.
 *
 * - `p_left` — First value.
 * - `p_right` — Second value.
 * - `p_tolerance` — Exclusive limit on the magnitude of the difference.
 */
constexpr bool is_equal_approx(double p_left, double p_right, double p_tolerance) {
	// Check for exact equality first, required to handle "infinity" values.
	if (p_left == p_right) {
		return true;
	}
	// Then check for approximate equality.
	return abs(p_left - p_right) < p_tolerance;
}
/**
 * Tests exact equality first, then tests whether the absolute difference is strictly below the supplied tolerance.
 *
 * - `p_left` — First value.
 * - `p_right` — Second value.
 * - `p_tolerance` — Exclusive limit on the magnitude of the difference.
 */
constexpr bool is_equal_approx(float p_left, float p_right, float p_tolerance) {
	// Check for exact equality first, required to handle "infinity" values.
	if (p_left == p_right) {
		return true;
	}
	// Then check for approximate equality.
	return abs(p_left - p_right) < p_tolerance;
}

/**
 * Tests exact equality first, then compares the difference with epsilon scaled by the magnitude of the first value. The tolerance is at least epsilon.
 *
 * - `p_left` — First value, which determines the tolerance scale.
 * - `p_right` — Value compared to the first.
 */
constexpr bool is_equal_approx(double p_left, double p_right) {
	// Check for exact equality first, required to handle "infinity" values.
	if (p_left == p_right) {
		return true;
	}
	// Then check for approximate equality.
	double tolerance = CMP_EPSILON * abs(p_left);
	if (tolerance < CMP_EPSILON) {
		tolerance = CMP_EPSILON;
	}
	return abs(p_left - p_right) < tolerance;
}
/**
 * Tests exact equality first, then compares the difference with epsilon scaled by the magnitude of the first value. The tolerance is at least epsilon.
 *
 * - `p_left` — First value, which determines the tolerance scale.
 * - `p_right` — Value compared to the first.
 */
constexpr bool is_equal_approx(float p_left, float p_right) {
	// Check for exact equality first, required to handle "infinity" values.
	if (p_left == p_right) {
		return true;
	}
	// Then check for approximate equality.
	float tolerance = (float)CMP_EPSILON * abs(p_left);
	if (tolerance < (float)CMP_EPSILON) {
		tolerance = (float)CMP_EPSILON;
	}
	return abs(p_left - p_right) < tolerance;
}

/**
 * Tests whether the absolute value is strictly smaller than the comparison epsilon.
 *
 * - `p_value` — Value to test for approximate zero.
 */
constexpr bool is_zero_approx(double p_value) {
	return abs(p_value) < CMP_EPSILON;
}
/**
 * Tests whether the absolute value is strictly smaller than the comparison epsilon.
 *
 * - `p_value` — Value to test for approximate zero.
 */
constexpr bool is_zero_approx(float p_value) {
	return abs(p_value) < (float)CMP_EPSILON;
}

/**
 * Compares two numbers for equality and also considers any two NaNs equal.
 *
 * - `p_left` — First comparison operand.
 * - `p_right` — Second comparison operand.
 */
constexpr bool is_same(double p_left, double p_right) {
	return (p_left == p_right) || (is_nan(p_left) && is_nan(p_right));
}
/**
 * Compares two numbers for equality and also considers any two NaNs equal.
 *
 * - `p_left` — First comparison operand.
 * - `p_right` — Second comparison operand.
 */
constexpr bool is_same(float p_left, float p_right) {
	return (p_left == p_right) || (is_nan(p_left) && is_nan(p_right));
}

/**
 * Returns a cubic easing factor clamped between zero and one. Approximately equal endpoints produce a step.
 *
 * **Used for** blending near a threshold with a gradual transition instead of a sudden change.
 *
 * - `p_from` — Endpoint associated with factor zero.
 * - `p_to` — Endpoint associated with factor one.
 * - `p_s` — Value to map to an eased factor.
 */
constexpr double smoothstep(double p_from, double p_to, double p_s) {
	if (is_equal_approx(p_from, p_to)) {
		if (likely(p_from <= p_to)) {
			return p_s <= p_from ? 0.0 : 1.0;
		} else {
			return p_s <= p_to ? 1.0 : 0.0;
		}
	}
	double s = clamp((p_s - p_from) / (p_to - p_from), 0.0, 1.0);
	return s * s * (3.0 - 2.0 * s);
}
/**
 * Returns a cubic easing factor clamped between zero and one. Approximately equal endpoints produce a step.
 *
 * **Used for** blending near a threshold with a gradual transition instead of a sudden change.
 *
 * - `p_from` — Endpoint associated with factor zero.
 * - `p_to` — Endpoint associated with factor one.
 * - `p_s` — Value to map to an eased factor.
 */
constexpr float smoothstep(float p_from, float p_to, float p_s) {
	if (is_equal_approx(p_from, p_to)) {
		if (likely(p_from <= p_to)) {
			return p_s <= p_from ? 0.0f : 1.0f;
		} else {
			return p_s <= p_to ? 1.0f : 0.0f;
		}
	}
	float s = clamp((p_s - p_from) / (p_to - p_from), 0.0f, 1.0f);
	return s * s * (3.0f - 2.0f * s);
}

/**
 * Steps toward the target without overshooting for a nonnegative step. A negative step moves away from the target.
 *
 * **Used for** advancing a scalar toward a target at a fixed rate per update.
 *
 * - `p_from` — Current value.
 * - `p_to` — Target value.
 * - `p_delta` — Signed step size in the same units as the values.
 */
constexpr double move_toward(double p_from, double p_to, double p_delta) {
	return abs(p_to - p_from) <= p_delta ? p_to : p_from + sign(p_to - p_from) * p_delta;
}
/**
 * Steps toward the target without overshooting for a nonnegative step. A negative step moves away from the target.
 *
 * **Used for** advancing a scalar toward a target at a fixed rate per update.
 *
 * - `p_from` — Current value.
 * - `p_to` — Target value.
 * - `p_delta` — Signed step size in the same units as the values.
 */
constexpr float move_toward(float p_from, float p_to, float p_delta) {
	return abs(p_to - p_from) <= p_delta ? p_to : p_from + sign(p_to - p_from) * p_delta;
}

/**
 * Rotates along the shortest path by up to the step. A negative step rotates away until the angular separation reaches pi.
 *
 * **Used for** turning toward a heading at a rate limited per update.
 *
 * - `p_from` — Start angle in radians.
 * - `p_to` — Target angle in radians.
 * - `p_delta` — Signed angular step in radians.
 */
_ALWAYS_INLINE_ double rotate_toward(double p_from, double p_to, double p_delta) {
	double difference = angle_difference(p_from, p_to);
	double abs_difference = abs(difference);
	// When `p_delta < 0` move no further than to PI radians away from `p_to` (as PI is the max possible angle distance).
	return p_from + CLAMP(p_delta, abs_difference - PI, abs_difference) * (difference >= 0.0 ? 1.0 : -1.0);
}
/**
 * Rotates along the shortest path by up to the step. A negative step rotates away until the angular separation reaches pi.
 *
 * **Used for** turning toward a heading at a rate limited per update.
 *
 * - `p_from` — Start angle in radians.
 * - `p_to` — Target angle in radians.
 * - `p_delta` — Signed angular step in radians.
 */
_ALWAYS_INLINE_ float rotate_toward(float p_from, float p_to, float p_delta) {
	float difference = angle_difference(p_from, p_to);
	float abs_difference = abs(difference);
	// When `p_delta < 0` move no further than to PI radians away from `p_to` (as PI is the max possible angle distance).
	return p_from + CLAMP(p_delta, abs_difference - (float)PI, abs_difference) * (difference >= 0.0f ? 1.0f : -1.0f);
}

/**
 * Converts a linear amplitude ratio to decibels using twenty times its base-ten logarithm.
 *
 * **Used for** setting decibel-based audio volume from a linear gain control.
 *
 * - `p_linear` — Amplitude ratio. Zero gives negative infinity.
 */
_ALWAYS_INLINE_ double linear_to_db(double p_linear) {
	return log(p_linear) * 8.6858896380650365530225783783321;
}
/**
 * Converts a linear amplitude ratio to decibels using twenty times its base-ten logarithm.
 *
 * **Used for** setting decibel-based audio volume from a linear gain control.
 *
 * - `p_linear` — Amplitude ratio. Zero gives negative infinity.
 */
_ALWAYS_INLINE_ float linear_to_db(float p_linear) {
	return log(p_linear) * (float)8.6858896380650365530225783783321;
}

/**
 * Converts a decibel value to a linear amplitude ratio.
 *
 * **Used for** applying an audio volume setting as a gain multiplier.
 *
 * - `p_db` — Gain in decibels.
 */
_ALWAYS_INLINE_ double db_to_linear(double p_db) {
	return exp(p_db * 0.11512925464970228420089957273422);
}
/**
 * Converts a decibel value to a linear amplitude ratio.
 *
 * **Used for** applying an audio volume setting as a gain multiplier.
 *
 * - `p_db` — Gain in decibels.
 */
_ALWAYS_INLINE_ float db_to_linear(float p_db) {
	return exp(p_db * (float)0.11512925464970228420089957273422);
}

/**
 * Rounds to the nearest integer-valued number, with ties away from zero.
 *
 * **Used for** aligning a coordinate to the closest integer position.
 *
 * - `p_val` — Value to round.
 */
_ALWAYS_INLINE_ double round(double p_val) {
	return std::round(p_val);
}
/**
 * Rounds to the nearest integer-valued number, with ties away from zero.
 *
 * **Used for** aligning a coordinate to the closest integer position.
 *
 * - `p_val` — Value to round.
 */
_ALWAYS_INLINE_ float round(float p_val) {
	return std::round(p_val);
}

/**
 * Wraps a floating-point value into a range with an excluded upper bound. Maps a near-zero range or a result near the upper bound to the lower bound.
 *
 * **Used for** cycling an index or a periodic value through a fixed interval.
 *
 * - `p_value` — Value to wrap.
 * - `p_min` — Inclusive lower bound.
 * - `p_max` — Exclusive upper bound for an increasing range.
 */
_ALWAYS_INLINE_ double wrapf(double p_value, double p_min, double p_max) {
	double range = p_max - p_min;
	if (is_zero_approx(range)) {
		return p_min;
	}
	double result = p_value - (range * floor((p_value - p_min) / range));
	if (is_equal_approx(result, p_max)) {
		return p_min;
	}
	return result;
}
/**
 * Wraps a floating-point value into a range with an excluded upper bound. Maps a near-zero range or a result near the upper bound to the lower bound.
 *
 * **Used for** cycling an index or a periodic value through a fixed interval.
 *
 * - `p_value` — Value to wrap.
 * - `p_min` — Inclusive lower bound.
 * - `p_max` — Exclusive upper bound for an increasing range.
 */
_ALWAYS_INLINE_ float wrapf(float p_value, float p_min, float p_max) {
	float range = p_max - p_min;
	if (is_zero_approx(range)) {
		return p_min;
	}
	float result = p_value - (range * floor((p_value - p_min) / range));
	if (is_equal_approx(result, p_max)) {
		return p_min;
	}
	return result;
}

/**
 * Wraps an integer into a range with an excluded upper bound. Equal bounds produce the lower bound.
 *
 * **Used for** cycling an index or a periodic value through a fixed interval.
 *
 * - `p_value` — Integer to wrap.
 * - `p_min` — Inclusive lower bound.
 * - `p_max` — Exclusive upper bound for an increasing range.
 */
constexpr int64_t wrapi(int64_t p_value, int64_t p_min, int64_t p_max) {
	int64_t range = p_max - p_min;
	return range == 0 ? p_min : p_min + ((((p_value - p_min) % range) + range) % range);
}

/**
 * Returns the fraction above the floor of the value. The result is nonnegative for finite values.
 *
 * - `p_value` — Value whose fractional part is requested.
 */
_ALWAYS_INLINE_ double fract(double p_value) {
	return p_value - floor(p_value);
}
/**
 * Returns the fraction above the floor of the value. The result is nonnegative for finite values.
 *
 * - `p_value` — Value whose fractional part is requested.
 */
_ALWAYS_INLINE_ float fract(float p_value) {
	return p_value - floor(p_value);
}

/**
 * Returns the value on a triangular wave. For positive length, it rises from zero to the length and back over twice the length.
 *
 * **Used for** animating a position or blending weight that repeatedly reverses direction at its endpoints.
 *
 * - `p_value` — Position in the repeated wave.
 * - `p_length` — Distance from the valley to the peak. A zero length returns zero.
 */
_ALWAYS_INLINE_ double pingpong(double p_value, double p_length) {
	return (p_length != 0.0) ? abs(fract((p_value - p_length) / (p_length * 2.0)) * p_length * 2.0 - p_length) : 0.0;
}
/**
 * Returns the value on a triangular wave. For positive length, it rises from zero to the length and back over twice the length.
 *
 * **Used for** animating a position or blending weight that repeatedly reverses direction at its endpoints.
 *
 * - `p_value` — Position in the repeated wave.
 * - `p_length` — Distance from the valley to the peak. A zero length returns zero.
 */
_ALWAYS_INLINE_ float pingpong(float p_value, float p_length) {
	return (p_length != 0.0f) ? abs(fract((p_value - p_length) / (p_length * 2.0f)) * p_length * 2.0f - p_length) : 0.0f;
}

/**
 * Rounds to a multiple of the step. With a positive step, halfway values round toward positive infinity.
 *
 * - `p_value` — Value to snap.
 * - `p_step` — Grid spacing. Zero passes the value through.
 */
_ALWAYS_INLINE_ double snapped(double p_value, double p_step) {
	if (p_step != 0) {
		p_value = Math::floor(p_value / p_step + 0.5) * p_step;
	}
	return p_value;
}

// This function should be as fast as possible and rounding mode should not matter.
/**
 * Rounds using the active floating-point rounding mode and converts the result to an integer.
 *
 * - `p_value` — Value whose rounded result must be representable as an int.
 */
_ALWAYS_INLINE_ int fast_ftoi(float p_value) {
	return std::rint(p_value);
}

/**
 * Expands a binary16 bit pattern to the equivalent binary32 bit pattern, including special values.
 *
 * - `p_half` — 16-bit encoding of the half-precision value.
 */
constexpr uint32_t halfbits_to_floatbits(uint16_t p_half) {
	uint16_t h_exp = (p_half & 0x7c00u);
	uint32_t f_sgn = ((uint32_t)p_half & 0x8000u) << 16;
	switch (h_exp) {
		case 0x0000u: { /* 0 or subnormal */
			uint16_t h_sig = (p_half & 0x03ffu);
			/* Signed zero */
			if (h_sig == 0) {
				return f_sgn;
			}
			/* Subnormal */
			h_sig <<= 1;
			while ((h_sig & 0x0400u) == 0) {
				h_sig <<= 1;
				h_exp++;
			}
			uint32_t f_exp = ((uint32_t)(127 - 15 - h_exp)) << 23;
			uint32_t f_sig = ((uint32_t)(h_sig & 0x03ffu)) << 13;
			return f_sgn + f_exp + f_sig;
		} break;
		case 0x7c00u: /* inf or NaN */
			/* All-ones exponent and a copy of the significand */
			return f_sgn + 0x7f800000u + (((uint32_t)(p_half & 0x03ffu)) << 13);
		default: /* normalized */
			/* Just need to adjust the exponent and shift */
			return f_sgn + (((uint32_t)(p_half & 0x7fffu) + 0x1c000u) << 13);
	}
}

/**
 * Loads and converts a binary16 bit pattern to a float.
 *
 * - `p_half` — Pointer to a readable 16-bit half-precision encoding.
 */
_ALWAYS_INLINE_ float halfptr_to_float(const uint16_t *p_half) {
	union {
		uint32_t u32;
		float f32;
	} u;

	u.u32 = halfbits_to_floatbits(*p_half);
	return u.f32;
}

/**
 * Converts a binary16 bit pattern to its float value.
 *
 * - `p_half` — 16-bit encoding supplied by value.
 */
_ALWAYS_INLINE_ float half_to_float(const uint16_t p_half) {
	return halfptr_to_float(&p_half);
}

/**
 * Encodes a float as binary16, truncating excess mantissa bits. Values below the normal binary16 range become zero. Overflow becomes infinity.
 *
 * - `p_value` — Single-precision input to encode.
 */
_ALWAYS_INLINE_ uint16_t make_half_float(float p_value) {
	union {
		float fv;
		uint32_t ui;
	} ci;
	ci.fv = p_value;

	uint32_t x = ci.ui;
	uint32_t sign = (unsigned short)(x >> 31);
	uint32_t mantissa;
	uint32_t exponent;
	uint16_t hf;

	// get mantissa
	mantissa = x & ((1 << 23) - 1);
	// get exponent bits
	exponent = x & (0xFF << 23);
	if (exponent >= 0x47800000) {
		// check if the original single precision float number is a NaN
		if (mantissa && (exponent == (0xFF << 23))) {
			// we have a single precision NaN
			mantissa = (1 << 23) - 1;
		} else {
			// 16-bit half-float representation stores number as Inf
			mantissa = 0;
		}
		hf = (((uint16_t)sign) << 15) | (uint16_t)((0x1F << 10)) |
				(uint16_t)(mantissa >> 13);
	}
	// check if exponent is <= -15
	else if (exponent <= 0x38000000) {
		/*
		// store a denorm half-float value or zero
		exponent = (0x38000000 - exponent) >> 23;
		mantissa >>= (14 + exponent);

		hf = (((uint16_t)sign) << 15) | (uint16_t)(mantissa);
		*/
		hf = 0; //denormals do not work for 3D, convert to zero
	} else {
		hf = (((uint16_t)sign) << 15) |
				(uint16_t)((exponent - 0x38000000) >> 13) |
				(uint16_t)(mantissa >> 13);
	}

	return hf;
}

/**
 * Rounds the target to the offset grid.
 *
 * - `p_offset` — Grid origin.
 * - `p_step` — Grid spacing. Zero passes the target through.
 * - `p_target` — Value to snap.
 */
_ALWAYS_INLINE_ float snap_scalar(float p_offset, float p_step, float p_target) {
	return p_step != 0 ? snapped(p_target - p_offset, p_step) + p_offset : p_target;
}

/**
 * Tests two candidate positions on a grid with separation and returns the closer one. A tie selects the second candidate.
 *
 * - `p_offset` — Offset of the repeating grid.
 * - `p_step` — Base spacing. Zero passes the target through.
 * - `p_target` — Value compared with the two candidate positions.
 * - `p_separation` — Additional spacing between repetitions and part of the second candidate's offset.
 */
_ALWAYS_INLINE_ float snap_scalar_separation(float p_offset, float p_step, float p_target, float p_separation) {
	if (p_step != 0) {
		float a = snapped(p_target - p_offset, p_step + p_separation) + p_offset;
		float b = a;
		if (p_target >= 0) {
			b -= p_separation;
		} else {
			b += p_step;
		}
		return (abs(p_target - a) < abs(p_target - b)) ? a : b;
	}
	return p_target;
}

} // namespace Math
} // namespace godot

#include "math.compat.inc"
