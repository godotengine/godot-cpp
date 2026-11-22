/**************************************************************************/
/*  vector4i.hpp                                                          */
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

#include <godot_cpp/core/error_macros.hpp>
#include <godot_cpp/core/math.hpp>

namespace godot {

class String;
struct Vector4;

/**
 * A 4D vector using integer coordinates.
 */
struct [[nodiscard]] Vector4i {
	/**
	 * The number of components in the vector.
	 */
	static constexpr int AXIS_COUNT = 4;

	/**
	 * Component indices accepted by `godot::Vector4i::operator[]()`.
	 */
	enum Axis {
		/**
		 * Index 0, which selects the X component.
		 */
		AXIS_X,
		/**
		 * Index 1, which selects the Y component.
		 */
		AXIS_Y,
		/**
		 * Index 2, which selects the Z component.
		 */
		AXIS_Z,
		/**
		 * Index 3, which selects the W component.
		 */
		AXIS_W,
	};

	/**
	 * The vector's X component. Also accessible by using the index position `[0]`.
	 */
	int32_t x = 0;
	/**
	 * The vector's Y component. Also accessible by using the index position `[1]`.
	 */
	int32_t y = 0;
	/**
	 * The vector's Z component. Also accessible by using the index position `[2]`.
	 */
	int32_t z = 0;
	/**
	 * The vector's W component. Also accessible by using the index position `[3]`.
	 */
	int32_t w = 0;

	/**
	 * Returns a writable reference to the component at index zero through 3 in X, Y, Z, W order.
	 *
	 * - `p_axis` — Zero-based component index in X, Y, Z, and W order.
	 */
	constexpr int32_t &operator[](int p_axis) {
		// The pointer math below assumes that the elements are placed back-to-back, like an array.
		// This is always true in practice, but technically not guaranteed; we safety-check it here.
		static_assert(offsetof(Vector4i, x) == 0 * sizeof(int32_t));
		static_assert(offsetof(Vector4i, y) == 1 * sizeof(int32_t));
		static_assert(offsetof(Vector4i, z) == 2 * sizeof(int32_t));
		static_assert(offsetof(Vector4i, w) == 3 * sizeof(int32_t));
		static_assert(sizeof(Vector4i) == 4 * sizeof(int32_t));

		DEV_ASSERT((unsigned int)p_axis < 4);
		return (&x)[p_axis];
	}
	/**
	 * Returns the component at index zero through 3 in X, Y, Z, W order.
	 *
	 * - `p_axis` — Zero-based component index in X, Y, Z, and W order.
	 */
	constexpr const int32_t &operator[](int p_axis) const {
		DEV_ASSERT((unsigned int)p_axis < 4);
		return (&x)[p_axis];
	}

	/**
	 * Returns the axis of the vector's lowest value. See `AXIS_*` constants. If all components are equal,
	 * this method returns `godot::Vector4i::AXIS_W`.
	 */
	Vector4i::Axis min_axis_index() const;
	/**
	 * Returns the axis of the vector's highest value. See `AXIS_*` constants. If all components are equal,
	 * this method returns `godot::Vector4i::AXIS_X`.
	 */
	Vector4i::Axis max_axis_index() const;

	/**
	 * Returns each component's smaller value after comparing it with the matching component of the other vector.
	 *
	 * - `p_vector4i` — Vector that supplies the other X, Y, Z, and W values.
	 */
	Vector4i min(const Vector4i &p_vector4i) const {
		return Vector4i(MIN(x, p_vector4i.x), MIN(y, p_vector4i.y), MIN(z, p_vector4i.z), MIN(w, p_vector4i.w));
	}

	/**
	 * Returns each component's smaller value after comparing it with the same scalar.
	 *
	 * - `p_scalar` — Value compared with every component.
	 */
	Vector4i mini(int32_t p_scalar) const {
		return Vector4i(MIN(x, p_scalar), MIN(y, p_scalar), MIN(z, p_scalar), MIN(w, p_scalar));
	}

	/**
	 * Returns each component's larger value after comparing it with the matching component of the other vector.
	 *
	 * - `p_vector4i` — Vector that supplies the other X, Y, Z, and W values.
	 */
	Vector4i max(const Vector4i &p_vector4i) const {
		return Vector4i(MAX(x, p_vector4i.x), MAX(y, p_vector4i.y), MAX(z, p_vector4i.z), MAX(w, p_vector4i.w));
	}

	/**
	 * Returns each component's larger value after comparing it with the same scalar.
	 *
	 * - `p_scalar` — Value compared with every component.
	 */
	Vector4i maxi(int32_t p_scalar) const {
		return Vector4i(MAX(x, p_scalar), MAX(y, p_scalar), MAX(z, p_scalar), MAX(w, p_scalar));
	}

	/**
	 * Returns the squared length (squared magnitude) of this vector. This method runs faster than
	 * `godot::Vector4i::length()`, so prefer it if you need to compare vectors or need the squared distance
	 * for some formula.
	 */
	_FORCE_INLINE_ int64_t length_squared() const;
	/**
	 * Returns the length (magnitude) of this vector.
	 */
	_FORCE_INLINE_ double length() const;

	/**
	 * Sets every component to zero.
	 */
	_FORCE_INLINE_ void zero();

	/**
	 * Returns the Euclidean distance between the points represented by the two vectors.
	 *
	 * - `p_to` — Other point in the same coordinate system.
	 */
	_FORCE_INLINE_ double distance_to(const Vector4i &p_to) const;
	/**
	 * Returns the squared Euclidean distance between the points represented by the two vectors without
	 * taking a square root.
	 *
	 * - `p_to` — Other point in the same coordinate system.
	 */
	_FORCE_INLINE_ int64_t distance_squared_to(const Vector4i &p_to) const;

	/**
	 * Returns a new vector with all components in absolute values (i.e. positive).
	 */
	_FORCE_INLINE_ Vector4i abs() const;
	/**
	 * Returns a new vector with each component set to `1` if it's positive, `-1` if it's negative, and `0`
	 * if it's zero. The result is identical to calling `sign()` on each component.
	 */
	_FORCE_INLINE_ Vector4i sign() const;
	/**
	 * Returns a new vector with all components clamped between the components of `min` and `max`, by
	 * running `clamp()` on each component.
	 *
	 * - `p_min` — Inclusive lower bounds for X, Y, Z, and W.
	 * - `p_max` — Inclusive upper bounds for X, Y, Z, and W.
	 */
	Vector4i clamp(const Vector4i &p_min, const Vector4i &p_max) const;
	/**
	 * Returns a new vector with all components clamped between `min` and `max`, by running `clamp()` on
	 * each component.
	 *
	 * - `p_min` — Inclusive lower bound used for every component.
	 * - `p_max` — Inclusive upper bound used for every component.
	 */
	Vector4i clampi(int32_t p_min, int32_t p_max) const;
	/**
	 * Returns a new vector with each component snapped to the closest multiple of the corresponding
	 * component in `step`.
	 *
	 * - `p_step` — Grid spacing for each component. A zero spacing leaves that component unchanged.
	 */
	Vector4i snapped(const Vector4i &p_step) const;
	/**
	 * Returns a new vector with each component snapped to the closest multiple of `step`.
	 *
	 * - `p_step` — Grid spacing used for every component. Zero leaves the vector unchanged.
	 */
	Vector4i snappedi(int32_t p_step) const;

	/* Operators */

	/**
	 * Adds the right-hand vector to this vector component by component.
	 *
	 * - `p_v` — Vector whose components are added in place.
	 */
	constexpr Vector4i &operator+=(const Vector4i &p_v);
	/**
	 * Adds each component of the `godot::Vector4i` by the components of the given `godot::Vector4i`.
	 *
	 * - `p_v` — Vector whose components are added.
	 */
	constexpr Vector4i operator+(const Vector4i &p_v) const;
	/**
	 * Subtracts the right-hand vector from this vector component by component.
	 *
	 * - `p_v` — Vector whose components are subtracted in place.
	 */
	constexpr Vector4i &operator-=(const Vector4i &p_v);
	/**
	 * Subtracts each component of the `godot::Vector4i` by the components of the given `godot::Vector4i`.
	 *
	 * - `p_v` — Vector whose components are subtracted.
	 */
	constexpr Vector4i operator-(const Vector4i &p_v) const;
	/**
	 * Multiplies each component by the corresponding component of the right-hand vector in place.
	 *
	 * - `p_v` — Vector that supplies a factor for each component.
	 */
	constexpr Vector4i &operator*=(const Vector4i &p_v);
	/**
	 * Multiplies each component of the `godot::Vector4i` by the components of the given `godot::Vector4i`.
	 *
	 * - `p_v` — Vector that supplies a factor for each component.
	 */
	constexpr Vector4i operator*(const Vector4i &p_v) const;
	/**
	 * Divides each component by the corresponding component of the right-hand vector in place.
	 *
	 * - `p_v` — Vector that supplies a nonzero divisor for each component.
	 */
	constexpr Vector4i &operator/=(const Vector4i &p_v);
	/**
	 * Divides each component of the `godot::Vector4i` by the components of the given `godot::Vector4i`.
	 *
	 * - `p_v` — Vector that supplies a nonzero divisor for each component.
	 */
	constexpr Vector4i operator/(const Vector4i &p_v) const;
	/**
	 * Replaces each component with its signed C++ remainder after division by the corresponding right-hand
	 * component.
	 *
	 * - `p_v` — Vector that supplies a nonzero divisor for each component.
	 */
	constexpr Vector4i &operator%=(const Vector4i &p_v);
	/**
	 * Gets the remainder of each component of the `godot::Vector4i` with the components of the given
	 * `godot::Vector4i`. This operation uses truncated division, which is often not desired as it does not
	 * work well with negative numbers. Consider using `posmod()` instead if you want to handle negative
	 * numbers.
	 *
	 * - `p_v` — Vector that supplies a nonzero divisor for each component.
	 */
	constexpr Vector4i operator%(const Vector4i &p_v) const;

	/**
	 * Multiplies each component by the given scalar in place.
	 *
	 * - `p_scalar` — Factor applied to every component.
	 */
	constexpr Vector4i &operator*=(int32_t p_scalar);
	/**
	 * Multiplies each component of the `godot::Vector4i` by the given `int`.
	 *
	 * - `p_scalar` — Factor applied to every component.
	 */
	constexpr Vector4i operator*(int32_t p_scalar) const;
	/**
	 * Divides each component by the given scalar in place.
	 *
	 * - `p_scalar` — Nonzero divisor applied to every component.
	 */
	constexpr Vector4i &operator/=(int32_t p_scalar);
	/**
	 * Divides each component of the `godot::Vector4i` by the given `int`.
	 *
	 * - `p_scalar` — Nonzero divisor applied to every component.
	 */
	constexpr Vector4i operator/(int32_t p_scalar) const;
	/**
	 * Replaces each component with its signed C++ remainder after division by the scalar.
	 *
	 * - `p_scalar` — Nonzero divisor applied to every component.
	 */
	constexpr Vector4i &operator%=(int32_t p_scalar);
	/**
	 * Gets the remainder of each component of the `godot::Vector4i` with the given `int`. This operation
	 * uses truncated division, which is often not desired as it does not work well with negative numbers.
	 * Consider using `posmod()` instead if you want to handle negative numbers.
	 *
	 * - `p_scalar` — Nonzero divisor applied to every component.
	 */
	constexpr Vector4i operator%(int32_t p_scalar) const;

	/**
	 * Returns a vector with each component negated.
	 */
	constexpr Vector4i operator-() const;

	/**
	 * Tests exact equality of the components.
	 *
	 * - `p_v` — Right-hand vector in the comparison.
	 */
	constexpr bool operator==(const Vector4i &p_v) const;
	/**
	 * Tests whether any component differs.
	 *
	 * - `p_v` — Right-hand vector in the comparison.
	 */
	constexpr bool operator!=(const Vector4i &p_v) const;
	/**
	 * Compares two `godot::Vector4i` vectors by first checking if the X value of the left vector is less
	 * than the X value of the `right` vector. If the X values are exactly equal, then it repeats this check
	 * with the Y values of the two vectors, Z values of the two vectors, and then with the W values. This
	 * operator is useful for sorting vectors.
	 *
	 * - `p_v` — Right-hand vector in the comparison.
	 */
	constexpr bool operator<(const Vector4i &p_v) const;
	/**
	 * Compares two `godot::Vector4i` vectors by first checking if the X value of the left vector is less
	 * than or equal to the X value of the `right` vector. If the X values are exactly equal, then it
	 * repeats this check with the Y values of the two vectors, Z values of the two vectors, and then with
	 * the W values. This operator is useful for sorting vectors.
	 *
	 * - `p_v` — Right-hand vector in the comparison.
	 */
	constexpr bool operator<=(const Vector4i &p_v) const;
	/**
	 * Compares two `godot::Vector4i` vectors by first checking if the X value of the left vector is greater
	 * than the X value of the `right` vector. If the X values are exactly equal, then it repeats this check
	 * with the Y values of the two vectors, Z values of the two vectors, and then with the W values. This
	 * operator is useful for sorting vectors.
	 *
	 * - `p_v` — Right-hand vector in the comparison.
	 */
	constexpr bool operator>(const Vector4i &p_v) const;
	/**
	 * Compares two `godot::Vector4i` vectors by first checking if the X value of the left vector is greater
	 * than or equal to the X value of the `right` vector. If the X values are exactly equal, then it
	 * repeats this check with the Y values of the two vectors, Z values of the two vectors, and then with
	 * the W values. This operator is useful for sorting vectors.
	 *
	 * - `p_v` — Right-hand vector in the comparison.
	 */
	constexpr bool operator>=(const Vector4i &p_v) const;

	/**
	 * Formats X, Y, Z, and W as a parenthesized, comma-separated string.
	 */
	explicit operator String() const;
	/**
	 * Copies the four integer components into a floating-point vector.
	 */
	operator Vector4() const;

	/**
	 * Constructs a default-initialized `godot::Vector4i` with all components set to `0`.
	 */
	constexpr Vector4i() = default;
	/**
	 * Returns a `godot::Vector4i` with the given components.
	 *
	 * - `p_x` — X component.
	 * - `p_y` — Y component.
	 * - `p_z` — Z component.
	 * - `p_w` — W component.
	 */
	constexpr Vector4i(int32_t p_x, int32_t p_y, int32_t p_z, int32_t p_w) :
			x(p_x), y(p_y), z(p_z), w(p_w) {}
};

int64_t Vector4i::length_squared() const {
	return x * (int64_t)x + y * (int64_t)y + z * (int64_t)z + w * (int64_t)w;
}

double Vector4i::length() const {
	return Math::sqrt((double)length_squared());
}

double Vector4i::distance_to(const Vector4i &p_to) const {
	return (p_to - *this).length();
}

int64_t Vector4i::distance_squared_to(const Vector4i &p_to) const {
	return (p_to - *this).length_squared();
}

Vector4i Vector4i::abs() const {
	return Vector4i(Math::abs(x), Math::abs(y), Math::abs(z), Math::abs(w));
}

Vector4i Vector4i::sign() const {
	return Vector4i(SIGN(x), SIGN(y), SIGN(z), SIGN(w));
}

/* Operators */

constexpr Vector4i &Vector4i::operator+=(const Vector4i &p_v) {
	x += p_v.x;
	y += p_v.y;
	z += p_v.z;
	w += p_v.w;
	return *this;
}

constexpr Vector4i Vector4i::operator+(const Vector4i &p_v) const {
	return Vector4i(x + p_v.x, y + p_v.y, z + p_v.z, w + p_v.w);
}

constexpr Vector4i &Vector4i::operator-=(const Vector4i &p_v) {
	x -= p_v.x;
	y -= p_v.y;
	z -= p_v.z;
	w -= p_v.w;
	return *this;
}

constexpr Vector4i Vector4i::operator-(const Vector4i &p_v) const {
	return Vector4i(x - p_v.x, y - p_v.y, z - p_v.z, w - p_v.w);
}

constexpr Vector4i &Vector4i::operator*=(const Vector4i &p_v) {
	x *= p_v.x;
	y *= p_v.y;
	z *= p_v.z;
	w *= p_v.w;
	return *this;
}

constexpr Vector4i Vector4i::operator*(const Vector4i &p_v) const {
	return Vector4i(x * p_v.x, y * p_v.y, z * p_v.z, w * p_v.w);
}

constexpr Vector4i &Vector4i::operator/=(const Vector4i &p_v) {
	x = Math::division_no_overflow(x, p_v.x);
	y = Math::division_no_overflow(y, p_v.y);
	z = Math::division_no_overflow(z, p_v.z);
	w = Math::division_no_overflow(w, p_v.w);
	return *this;
}

constexpr Vector4i Vector4i::operator/(const Vector4i &p_v) const {
	return Vector4i(Math::division_no_overflow(x, p_v.x), Math::division_no_overflow(y, p_v.y), Math::division_no_overflow(z, p_v.z), Math::division_no_overflow(w, p_v.w));
}

constexpr Vector4i &Vector4i::operator%=(const Vector4i &p_v) {
	x = Math::modulo_no_overflow(x, p_v.x);
	y = Math::modulo_no_overflow(y, p_v.y);
	z = Math::modulo_no_overflow(z, p_v.z);
	w = Math::modulo_no_overflow(w, p_v.w);
	return *this;
}

constexpr Vector4i Vector4i::operator%(const Vector4i &p_v) const {
	return Vector4i(Math::modulo_no_overflow(x, p_v.x), Math::modulo_no_overflow(y, p_v.y), Math::modulo_no_overflow(z, p_v.z), Math::modulo_no_overflow(w, p_v.w));
}

constexpr Vector4i &Vector4i::operator*=(int32_t p_scalar) {
	x *= p_scalar;
	y *= p_scalar;
	z *= p_scalar;
	w *= p_scalar;
	return *this;
}

constexpr Vector4i Vector4i::operator*(int32_t p_scalar) const {
	return Vector4i(x * p_scalar, y * p_scalar, z * p_scalar, w * p_scalar);
}

// Multiplication operators required to workaround issues with LLVM using implicit conversion.

/**
 * Multiplies each component by the left-hand integer factor.
 *
 * - `p_scalar` — Left-hand factor applied to every component.
 * - `p_vector` — Vector whose components are multiplied.
 */
constexpr Vector4i operator*(int32_t p_scalar, const Vector4i &p_vector) {
	return p_vector * p_scalar;
}

/**
 * Converts the factor to a 32-bit integer before multiplying each component.
 *
 * - `p_scalar` — Left-hand factor converted to a 32-bit integer before multiplication.
 * - `p_vector` — Vector whose components are multiplied.
 */
constexpr Vector4i operator*(int64_t p_scalar, const Vector4i &p_vector) {
	return p_vector * p_scalar;
}

/**
 * Converts the floating-point factor to a 32-bit integer by truncating toward zero, then multiplies each component.
 *
 * - `p_scalar` — Left-hand factor converted to a 32-bit integer before multiplication.
 * - `p_vector` — Vector whose components are multiplied.
 */
constexpr Vector4i operator*(float p_scalar, const Vector4i &p_vector) {
	return p_vector * p_scalar;
}

/**
 * Converts the floating-point factor to a 32-bit integer by truncating toward zero, then multiplies each component.
 *
 * - `p_scalar` — Left-hand factor converted to a 32-bit integer before multiplication.
 * - `p_vector` — Vector whose components are multiplied.
 */
constexpr Vector4i operator*(double p_scalar, const Vector4i &p_vector) {
	return p_vector * p_scalar;
}

constexpr Vector4i &Vector4i::operator/=(int32_t p_scalar) {
	x = Math::division_no_overflow(x, p_scalar);
	y = Math::division_no_overflow(y, p_scalar);
	z = Math::division_no_overflow(z, p_scalar);
	w = Math::division_no_overflow(w, p_scalar);
	return *this;
}

constexpr Vector4i Vector4i::operator/(int32_t p_scalar) const {
	return Vector4i(Math::division_no_overflow(x, p_scalar), Math::division_no_overflow(y, p_scalar), Math::division_no_overflow(z, p_scalar), Math::division_no_overflow(w, p_scalar));
}

constexpr Vector4i &Vector4i::operator%=(int32_t p_scalar) {
	x = Math::modulo_no_overflow(x, p_scalar);
	y = Math::modulo_no_overflow(y, p_scalar);
	z = Math::modulo_no_overflow(z, p_scalar);
	w = Math::modulo_no_overflow(w, p_scalar);
	return *this;
}

constexpr Vector4i Vector4i::operator%(int32_t p_scalar) const {
	return Vector4i(Math::modulo_no_overflow(x, p_scalar), Math::modulo_no_overflow(y, p_scalar), Math::modulo_no_overflow(z, p_scalar), Math::modulo_no_overflow(w, p_scalar));
}

constexpr Vector4i Vector4i::operator-() const {
	return Vector4i(-x, -y, -z, -w);
}

constexpr bool Vector4i::operator==(const Vector4i &p_v) const {
	return (x == p_v.x && y == p_v.y && z == p_v.z && w == p_v.w);
}

constexpr bool Vector4i::operator!=(const Vector4i &p_v) const {
	return (x != p_v.x || y != p_v.y || z != p_v.z || w != p_v.w);
}

constexpr bool Vector4i::operator<(const Vector4i &p_v) const {
	if (x == p_v.x) {
		if (y == p_v.y) {
			if (z == p_v.z) {
				return w < p_v.w;
			} else {
				return z < p_v.z;
			}
		} else {
			return y < p_v.y;
		}
	} else {
		return x < p_v.x;
	}
}

constexpr bool Vector4i::operator>(const Vector4i &p_v) const {
	if (x == p_v.x) {
		if (y == p_v.y) {
			if (z == p_v.z) {
				return w > p_v.w;
			} else {
				return z > p_v.z;
			}
		} else {
			return y > p_v.y;
		}
	} else {
		return x > p_v.x;
	}
}

constexpr bool Vector4i::operator<=(const Vector4i &p_v) const {
	if (x == p_v.x) {
		if (y == p_v.y) {
			if (z == p_v.z) {
				return w <= p_v.w;
			} else {
				return z < p_v.z;
			}
		} else {
			return y < p_v.y;
		}
	} else {
		return x < p_v.x;
	}
}

constexpr bool Vector4i::operator>=(const Vector4i &p_v) const {
	if (x == p_v.x) {
		if (y == p_v.y) {
			if (z == p_v.z) {
				return w >= p_v.w;
			} else {
				return z > p_v.z;
			}
		} else {
			return y > p_v.y;
		}
	} else {
		return x > p_v.x;
	}
}

void Vector4i::zero() {
	x = y = z = w = 0;
}

/**
 * Marks a zero-filled vector as a valid vector with all components equal to zero.
 */
template <>
struct is_zero_constructible<Vector4i> : std::true_type {};
} // namespace godot
