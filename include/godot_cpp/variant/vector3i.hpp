/**************************************************************************/
/*  vector3i.hpp                                                          */
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
struct Vector3;

/**
 * A 3D vector using integer coordinates.
 */
struct [[nodiscard]] Vector3i {
	/**
	 * Left unit vector. Represents the local direction of left, and the global direction of west.
	 */
	static const Vector3i LEFT;
	/**
	 * Right unit vector. Represents the local direction of right, and the global direction of east.
	 */
	static const Vector3i RIGHT;
	/**
	 * Up unit vector.
	 */
	static const Vector3i UP;
	/**
	 * Down unit vector.
	 */
	static const Vector3i DOWN;
	/**
	 * Forward unit vector. Represents the local direction of forward, and the global direction of north.
	 */
	static const Vector3i FORWARD;
	/**
	 * Back unit vector. Represents the local direction of back, and the global direction of south.
	 */
	static const Vector3i BACK;

	/**
	 * The number of components in the vector.
	 */
	static constexpr int AXIS_COUNT = 3;

	/**
	 * Component indices accepted by `godot::Vector3i::operator[]()`.
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
	 * Returns a writable reference to the component at index zero through 2 in X, Y, Z order.
	 *
	 * - `p_axis` — Zero-based component index in X, Y, and Z order.
	 */
	constexpr int32_t &operator[](int p_axis) {
		// The pointer math below assumes that the elements are placed back-to-back, like an array.
		// This is always true in practice, but technically not guaranteed; we safety-check it here.
		static_assert(offsetof(Vector3i, x) == 0 * sizeof(int32_t));
		static_assert(offsetof(Vector3i, y) == 1 * sizeof(int32_t));
		static_assert(offsetof(Vector3i, z) == 2 * sizeof(int32_t));
		static_assert(sizeof(Vector3i) == 3 * sizeof(int32_t));

		DEV_ASSERT((unsigned int)p_axis < 3);
		return (&x)[p_axis];
	}
	/**
	 * Returns the component at index zero through 2 in X, Y, Z order.
	 *
	 * - `p_axis` — Zero-based component index in X, Y, and Z order.
	 */
	constexpr const int32_t &operator[](int p_axis) const {
		DEV_ASSERT((unsigned int)p_axis < 3);
		return (&x)[p_axis];
	}

	/**
	 * Returns the axis of the vector's lowest value. See `AXIS_*` constants. If all components are equal,
	 * this method returns `godot::Vector3i::AXIS_Z`.
	 */
	Vector3i::Axis min_axis_index() const;
	/**
	 * Returns the axis of the vector's highest value. See `AXIS_*` constants. If all components are equal,
	 * this method returns `godot::Vector3i::AXIS_X`.
	 */
	Vector3i::Axis max_axis_index() const;

	/**
	 * Returns each component's smaller value after comparing it with the matching component of the other vector.
	 *
	 * - `p_vector3i` — Vector that supplies the other X, Y, and Z values.
	 */
	Vector3i min(const Vector3i &p_vector3i) const {
		return Vector3i(MIN(x, p_vector3i.x), MIN(y, p_vector3i.y), MIN(z, p_vector3i.z));
	}

	/**
	 * Returns each component's smaller value after comparing it with the same scalar.
	 *
	 * - `p_scalar` — Value compared with every component.
	 */
	Vector3i mini(int32_t p_scalar) const {
		return Vector3i(MIN(x, p_scalar), MIN(y, p_scalar), MIN(z, p_scalar));
	}

	/**
	 * Returns each component's larger value after comparing it with the matching component of the other vector.
	 *
	 * - `p_vector3i` — Vector that supplies the other X, Y, and Z values.
	 */
	Vector3i max(const Vector3i &p_vector3i) const {
		return Vector3i(MAX(x, p_vector3i.x), MAX(y, p_vector3i.y), MAX(z, p_vector3i.z));
	}

	/**
	 * Returns each component's larger value after comparing it with the same scalar.
	 *
	 * - `p_scalar` — Value compared with every component.
	 */
	Vector3i maxi(int32_t p_scalar) const {
		return Vector3i(MAX(x, p_scalar), MAX(y, p_scalar), MAX(z, p_scalar));
	}

	/**
	 * Returns the squared length (squared magnitude) of this vector. This method runs faster than
	 * `godot::Vector3i::length()`, so prefer it if you need to compare vectors or need the squared distance
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
	 * Returns a new vector with all components in absolute values (i.e. positive).
	 */
	_FORCE_INLINE_ Vector3i abs() const;
	/**
	 * Returns a new vector with each component set to `1` if it's positive, `-1` if it's negative, and `0`
	 * if it's zero. The result is identical to calling `sign()` on each component.
	 */
	_FORCE_INLINE_ Vector3i sign() const;
	/**
	 * Returns a new vector with all components clamped between the components of `min` and `max`, by
	 * running `clamp()` on each component.
	 *
	 * - `p_min` — Inclusive lower bounds for X, Y, and Z.
	 * - `p_max` — Inclusive upper bounds for X, Y, and Z.
	 */
	Vector3i clamp(const Vector3i &p_min, const Vector3i &p_max) const;
	/**
	 * Returns a new vector with all components clamped between `min` and `max`, by running `clamp()` on
	 * each component.
	 *
	 * - `p_min` — Inclusive lower bound used for every component.
	 * - `p_max` — Inclusive upper bound used for every component.
	 */
	Vector3i clampi(int32_t p_min, int32_t p_max) const;
	/**
	 * Returns a new vector with each component snapped to the closest multiple of the corresponding
	 * component in `step`.
	 *
	 * - `p_step` — Grid spacing for each component. A zero spacing leaves that component unchanged.
	 */
	Vector3i snapped(const Vector3i &p_step) const;
	/**
	 * Returns a new vector with each component snapped to the closest multiple of `step`.
	 *
	 * - `p_step` — Grid spacing used for every component. Zero leaves the vector unchanged.
	 */
	Vector3i snappedi(int32_t p_step) const;

	/**
	 * Returns the Euclidean distance between the points represented by the two vectors.
	 *
	 * - `p_to` — Other point in the same coordinate system.
	 */
	_FORCE_INLINE_ double distance_to(const Vector3i &p_to) const;
	/**
	 * Returns the squared Euclidean distance between the points represented by the two vectors without
	 * taking a square root.
	 *
	 * - `p_to` — Other point in the same coordinate system.
	 */
	_FORCE_INLINE_ int64_t distance_squared_to(const Vector3i &p_to) const;

	/* Operators */

	/**
	 * Adds the right-hand vector to this vector component by component.
	 *
	 * - `p_v` — Vector whose components are added in place.
	 */
	constexpr Vector3i &operator+=(const Vector3i &p_v);
	/**
	 * Adds each component of the `godot::Vector3i` by the components of the given `godot::Vector3i`.
	 *
	 * - `p_v` — Vector whose components are added.
	 */
	constexpr Vector3i operator+(const Vector3i &p_v) const;
	/**
	 * Subtracts the right-hand vector from this vector component by component.
	 *
	 * - `p_v` — Vector whose components are subtracted in place.
	 */
	constexpr Vector3i &operator-=(const Vector3i &p_v);
	/**
	 * Subtracts each component of the `godot::Vector3i` by the components of the given `godot::Vector3i`.
	 *
	 * - `p_v` — Vector whose components are subtracted.
	 */
	constexpr Vector3i operator-(const Vector3i &p_v) const;
	/**
	 * Multiplies each component by the corresponding component of the right-hand vector in place.
	 *
	 * - `p_v` — Vector that supplies a factor for each component.
	 */
	constexpr Vector3i &operator*=(const Vector3i &p_v);
	/**
	 * Multiplies each component of the `godot::Vector3i` by the components of the given `godot::Vector3i`.
	 *
	 * - `p_v` — Vector that supplies a factor for each component.
	 */
	constexpr Vector3i operator*(const Vector3i &p_v) const;
	/**
	 * Divides each component by the corresponding component of the right-hand vector in place.
	 *
	 * - `p_v` — Vector that supplies a nonzero divisor for each component.
	 */
	constexpr Vector3i &operator/=(const Vector3i &p_v);
	/**
	 * Divides each component of the `godot::Vector3i` by the components of the given `godot::Vector3i`.
	 *
	 * - `p_v` — Vector that supplies a nonzero divisor for each component.
	 */
	constexpr Vector3i operator/(const Vector3i &p_v) const;
	/**
	 * Replaces each component with its signed C++ remainder after division by the corresponding right-hand
	 * component.
	 *
	 * - `p_v` — Vector that supplies a nonzero divisor for each component.
	 */
	constexpr Vector3i &operator%=(const Vector3i &p_v);
	/**
	 * Gets the remainder of each component of the `godot::Vector3i` with the components of the given
	 * `godot::Vector3i`. This operation uses truncated division, which is often not desired as it does not
	 * work well with negative numbers. Consider using `posmod()` instead if you want to handle negative
	 * numbers.
	 *
	 * - `p_v` — Vector that supplies a nonzero divisor for each component.
	 */
	constexpr Vector3i operator%(const Vector3i &p_v) const;

	/**
	 * Multiplies each component by the given scalar in place.
	 *
	 * - `p_scalar` — Factor applied to every component.
	 */
	constexpr Vector3i &operator*=(int32_t p_scalar);
	/**
	 * Multiplies each component of the `godot::Vector3i` by the given `int`.
	 *
	 * - `p_scalar` — Factor applied to every component.
	 */
	constexpr Vector3i operator*(int32_t p_scalar) const;
	/**
	 * Divides each component by the given scalar in place.
	 *
	 * - `p_scalar` — Nonzero divisor applied to every component.
	 */
	constexpr Vector3i &operator/=(int32_t p_scalar);
	/**
	 * Divides each component of the `godot::Vector3i` by the given `int`.
	 *
	 * - `p_scalar` — Nonzero divisor applied to every component.
	 */
	constexpr Vector3i operator/(int32_t p_scalar) const;
	/**
	 * Replaces each component with its signed C++ remainder after division by the scalar.
	 *
	 * - `p_scalar` — Nonzero divisor applied to every component.
	 */
	constexpr Vector3i &operator%=(int32_t p_scalar);
	/**
	 * Gets the remainder of each component of the `godot::Vector3i` with the given `int`. This operation
	 * uses truncated division, which is often not desired as it does not work well with negative numbers.
	 * Consider using `posmod()` instead if you want to handle negative numbers.
	 *
	 * - `p_scalar` — Nonzero divisor applied to every component.
	 */
	constexpr Vector3i operator%(int32_t p_scalar) const;

	/**
	 * Returns a vector with each component negated.
	 */
	constexpr Vector3i operator-() const;

	/**
	 * Tests exact equality of the components.
	 *
	 * - `p_v` — Right-hand vector in the comparison.
	 */
	constexpr bool operator==(const Vector3i &p_v) const;
	/**
	 * Tests whether any component differs.
	 *
	 * - `p_v` — Right-hand vector in the comparison.
	 */
	constexpr bool operator!=(const Vector3i &p_v) const;
	/**
	 * Compares two `godot::Vector3i` vectors by first checking if the X value of the left vector is less
	 * than the X value of the `right` vector. If the X values are exactly equal, then it repeats this check
	 * with the Y values of the two vectors, and then with the Z values. This operator is useful for sorting
	 * vectors.
	 *
	 * - `p_v` — Right-hand vector in the comparison.
	 */
	constexpr bool operator<(const Vector3i &p_v) const;
	/**
	 * Compares two `godot::Vector3i` vectors by first checking if the X value of the left vector is less
	 * than or equal to the X value of the `right` vector. If the X values are exactly equal, then it
	 * repeats this check with the Y values of the two vectors, and then with the Z values. This operator is
	 * useful for sorting vectors.
	 *
	 * - `p_v` — Right-hand vector in the comparison.
	 */
	constexpr bool operator<=(const Vector3i &p_v) const;
	/**
	 * Compares two `godot::Vector3i` vectors by first checking if the X value of the left vector is greater
	 * than the X value of the `right` vector. If the X values are exactly equal, then it repeats this check
	 * with the Y values of the two vectors, and then with the Z values. This operator is useful for sorting
	 * vectors.
	 *
	 * - `p_v` — Right-hand vector in the comparison.
	 */
	constexpr bool operator>(const Vector3i &p_v) const;
	/**
	 * Compares two `godot::Vector3i` vectors by first checking if the X value of the left vector is greater
	 * than or equal to the X value of the `right` vector. If the X values are exactly equal, then it
	 * repeats this check with the Y values of the two vectors, and then with the Z values. This operator is
	 * useful for sorting vectors.
	 *
	 * - `p_v` — Right-hand vector in the comparison.
	 */
	constexpr bool operator>=(const Vector3i &p_v) const;

	/**
	 * Formats X, Y, and Z as a parenthesized, comma-separated string.
	 */
	explicit operator String() const;
	operator Vector3() const;

	/**
	 * Constructs a default-initialized `godot::Vector3i` with all components set to `0`.
	 */
	constexpr Vector3i() = default;
	/**
	 * Returns a `godot::Vector3i` with the given components.
	 *
	 * - `p_x` — X component.
	 * - `p_y` — Y component.
	 * - `p_z` — Z component.
	 */
	constexpr Vector3i(int32_t p_x, int32_t p_y, int32_t p_z) :
			x(p_x), y(p_y), z(p_z) {}
};

inline constexpr Vector3i Vector3i::LEFT = { -1, 0, 0 };
inline constexpr Vector3i Vector3i::RIGHT = { 1, 0, 0 };
inline constexpr Vector3i Vector3i::UP = { 0, 1, 0 };
inline constexpr Vector3i Vector3i::DOWN = { 0, -1, 0 };
inline constexpr Vector3i Vector3i::FORWARD = { 0, 0, -1 };
inline constexpr Vector3i Vector3i::BACK = { 0, 0, 1 };

int64_t Vector3i::length_squared() const {
	return x * (int64_t)x + y * (int64_t)y + z * (int64_t)z;
}

double Vector3i::length() const {
	return Math::sqrt((double)length_squared());
}

Vector3i Vector3i::abs() const {
	return Vector3i(Math::abs(x), Math::abs(y), Math::abs(z));
}

Vector3i Vector3i::sign() const {
	return Vector3i(SIGN(x), SIGN(y), SIGN(z));
}

double Vector3i::distance_to(const Vector3i &p_to) const {
	return (p_to - *this).length();
}

int64_t Vector3i::distance_squared_to(const Vector3i &p_to) const {
	return (p_to - *this).length_squared();
}

/* Operators */

constexpr Vector3i &Vector3i::operator+=(const Vector3i &p_v) {
	x += p_v.x;
	y += p_v.y;
	z += p_v.z;
	return *this;
}

constexpr Vector3i Vector3i::operator+(const Vector3i &p_v) const {
	return Vector3i(x + p_v.x, y + p_v.y, z + p_v.z);
}

constexpr Vector3i &Vector3i::operator-=(const Vector3i &p_v) {
	x -= p_v.x;
	y -= p_v.y;
	z -= p_v.z;
	return *this;
}

constexpr Vector3i Vector3i::operator-(const Vector3i &p_v) const {
	return Vector3i(x - p_v.x, y - p_v.y, z - p_v.z);
}

constexpr Vector3i &Vector3i::operator*=(const Vector3i &p_v) {
	x *= p_v.x;
	y *= p_v.y;
	z *= p_v.z;
	return *this;
}

constexpr Vector3i Vector3i::operator*(const Vector3i &p_v) const {
	return Vector3i(x * p_v.x, y * p_v.y, z * p_v.z);
}

constexpr Vector3i &Vector3i::operator/=(const Vector3i &p_v) {
	x = Math::division_no_overflow(x, p_v.x);
	y = Math::division_no_overflow(y, p_v.y);
	z = Math::division_no_overflow(z, p_v.z);
	return *this;
}

constexpr Vector3i Vector3i::operator/(const Vector3i &p_v) const {
	return Vector3i(Math::division_no_overflow(x, p_v.x), Math::division_no_overflow(y, p_v.y), Math::division_no_overflow(z, p_v.z));
}

constexpr Vector3i &Vector3i::operator%=(const Vector3i &p_v) {
	x = Math::modulo_no_overflow(x, p_v.x);
	y = Math::modulo_no_overflow(y, p_v.y);
	z = Math::modulo_no_overflow(z, p_v.z);
	return *this;
}

constexpr Vector3i Vector3i::operator%(const Vector3i &p_v) const {
	return Vector3i(Math::modulo_no_overflow(x, p_v.x), Math::modulo_no_overflow(y, p_v.y), Math::modulo_no_overflow(z, p_v.z));
}

constexpr Vector3i &Vector3i::operator*=(int32_t p_scalar) {
	x *= p_scalar;
	y *= p_scalar;
	z *= p_scalar;
	return *this;
}

constexpr Vector3i Vector3i::operator*(int32_t p_scalar) const {
	return Vector3i(x * p_scalar, y * p_scalar, z * p_scalar);
}

// Multiplication operators required to workaround issues with LLVM using implicit conversion.

/**
 * Multiplies each component by the left-hand integer factor.
 *
 * - `p_scalar` — Left-hand factor applied to every component.
 * - `p_vector` — Vector whose components are multiplied.
 */
constexpr Vector3i operator*(int32_t p_scalar, const Vector3i &p_vector) {
	return p_vector * p_scalar;
}

/**
 * Converts the factor to a 32-bit integer before multiplying each component.
 *
 * - `p_scalar` — Left-hand factor converted to a 32-bit integer before multiplication.
 * - `p_vector` — Vector whose components are multiplied.
 */
constexpr Vector3i operator*(int64_t p_scalar, const Vector3i &p_vector) {
	return p_vector * p_scalar;
}

/**
 * Converts the floating-point factor to a 32-bit integer by truncating toward zero, then multiplies each component.
 *
 * - `p_scalar` — Left-hand factor converted to a 32-bit integer before multiplication.
 * - `p_vector` — Vector whose components are multiplied.
 */
constexpr Vector3i operator*(float p_scalar, const Vector3i &p_vector) {
	return p_vector * p_scalar;
}

/**
 * Converts the floating-point factor to a 32-bit integer by truncating toward zero, then multiplies each component.
 *
 * - `p_scalar` — Left-hand factor converted to a 32-bit integer before multiplication.
 * - `p_vector` — Vector whose components are multiplied.
 */
constexpr Vector3i operator*(double p_scalar, const Vector3i &p_vector) {
	return p_vector * p_scalar;
}

constexpr Vector3i &Vector3i::operator/=(int32_t p_scalar) {
	x = Math::division_no_overflow(x, p_scalar);
	y = Math::division_no_overflow(y, p_scalar);
	z = Math::division_no_overflow(z, p_scalar);
	return *this;
}

constexpr Vector3i Vector3i::operator/(int32_t p_scalar) const {
	return Vector3i(Math::division_no_overflow(x, p_scalar), Math::division_no_overflow(y, p_scalar), Math::division_no_overflow(z, p_scalar));
}

constexpr Vector3i &Vector3i::operator%=(int32_t p_scalar) {
	x = Math::modulo_no_overflow(x, p_scalar);
	y = Math::modulo_no_overflow(y, p_scalar);
	z = Math::modulo_no_overflow(z, p_scalar);
	return *this;
}

constexpr Vector3i Vector3i::operator%(int32_t p_scalar) const {
	return Vector3i(Math::modulo_no_overflow(x, p_scalar), Math::modulo_no_overflow(y, p_scalar), Math::modulo_no_overflow(z, p_scalar));
}

constexpr Vector3i Vector3i::operator-() const {
	return Vector3i(-x, -y, -z);
}

constexpr bool Vector3i::operator==(const Vector3i &p_v) const {
	return (x == p_v.x && y == p_v.y && z == p_v.z);
}

constexpr bool Vector3i::operator!=(const Vector3i &p_v) const {
	return (x != p_v.x || y != p_v.y || z != p_v.z);
}

constexpr bool Vector3i::operator<(const Vector3i &p_v) const {
	if (x == p_v.x) {
		if (y == p_v.y) {
			return z < p_v.z;
		} else {
			return y < p_v.y;
		}
	} else {
		return x < p_v.x;
	}
}

constexpr bool Vector3i::operator>(const Vector3i &p_v) const {
	if (x == p_v.x) {
		if (y == p_v.y) {
			return z > p_v.z;
		} else {
			return y > p_v.y;
		}
	} else {
		return x > p_v.x;
	}
}

constexpr bool Vector3i::operator<=(const Vector3i &p_v) const {
	if (x == p_v.x) {
		if (y == p_v.y) {
			return z <= p_v.z;
		} else {
			return y < p_v.y;
		}
	} else {
		return x < p_v.x;
	}
}

constexpr bool Vector3i::operator>=(const Vector3i &p_v) const {
	if (x == p_v.x) {
		if (y == p_v.y) {
			return z >= p_v.z;
		} else {
			return y > p_v.y;
		}
	} else {
		return x > p_v.x;
	}
}

void Vector3i::zero() {
	x = y = z = 0;
}

/**
 * Marks a zero-filled vector as a valid vector with all components equal to zero.
 */
template <>
struct is_zero_constructible<Vector3i> : std::true_type {};
} // namespace godot
