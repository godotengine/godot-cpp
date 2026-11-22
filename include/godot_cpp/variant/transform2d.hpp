/**************************************************************************/
/*  transform2d.hpp                                                       */
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

#include <godot_cpp/templates/vector.hpp>
#include <godot_cpp/variant/packed_vector2_array.hpp>
#include <godot_cpp/variant/rect2.hpp>
#include <godot_cpp/variant/vector2.hpp>

namespace godot {

class String;

/**
 * An affine transform that maps 2D points from local coordinates to a destination coordinate system.
 * Its first two columns define the transformed axes and its third column holds the translation.
 */
struct [[nodiscard]] Transform2D {
	// WARNING: The basis of Transform2D is stored differently from Basis.
	// In terms of columns array, the basis matrix looks like "on paper":
	// M = (columns[0][0] columns[1][0])
	//     (columns[0][1] columns[1][1])
	// This is such that the columns, which can be interpreted as basis vectors
	// of the coordinate system "painted" on the object, can be accessed as columns[i].
	// NOTE: This is the opposite of the indices in mathematical texts,
	// meaning: $M_{12}$ in a math book corresponds to columns[1][0] here.
	// This requires additional care when working with explicit indices.
	// See https://en.wikipedia.org/wiki/Row-_and_column-major_order for further reading.

	// WARNING: Be aware that unlike 3D code, 2D code uses a left-handed coordinate system:
	// Y-axis points down, and angle is measure from +X to +Y in a clockwise-fashion.

	/**
	 * A transform that negates the X coordinate and preserves the other coordinates and the origin.
	 */
	static const Transform2D FLIP_X;
	/**
	 * A transform that negates the Y coordinate and preserves the other coordinates and the origin.
	 */
	static const Transform2D FLIP_Y;

	/**
	 * The destination coordinates of the local X axis, Y axis, and origin, in that order.
	 */
	Vector2 columns[3] = {
		{ 1, 0 },
		{ 0, 1 },
		{ 0, 0 },
	};

	/**
	 * Returns the X coordinate of the vector multiplied by the basis, before translation.
	 */
	_FORCE_INLINE_ real_t tdotx(const Vector2 &p_v) const { return columns[0][0] * p_v.x + columns[1][0] * p_v.y; }
	/**
	 * Returns the Y coordinate of the vector multiplied by the basis, before translation.
	 */
	_FORCE_INLINE_ real_t tdoty(const Vector2 &p_v) const { return columns[0][1] * p_v.x + columns[1][1] * p_v.y; }

	/**
	 * Returns a read-only reference to column 0, 1, or 2. The columns hold the transformed X axis, Y axis,
	 * and origin, respectively.
	 */
	constexpr const Vector2 &operator[](int p_idx) const { return columns[p_idx]; }
	/**
	 * Returns a writable reference to column 0, 1, or 2. Writing a column changes the transformed X axis, Y
	 * axis, or origin, respectively.
	 */
	constexpr Vector2 &operator[](int p_idx) { return columns[p_idx]; }

	/**
	 * Replaces the transform with its inverse using the transpose of the basis. The original basis must be
	 * orthonormal.
	 */
	void invert();
	/**
	 * Returns the inverse transform using the transpose of the basis. The original basis must be
	 * orthonormal.
	 */
	Transform2D inverse() const;

	/**
	 * Replaces the transform with its affine inverse. The basis must have a nonzero determinant and may
	 * include scale or skew.
	 */
	void affine_invert();
	/**
	 * Returns the affine inverse that maps destination points back to local coordinates. The basis must
	 * have a nonzero determinant and may include scale or skew.
	 */
	Transform2D affine_inverse() const;

	/**
	 * Rebuilds the basis with the given angle in radians and the current scale. Clears skew and preserves
	 * the origin.
	 */
	void set_rotation(real_t p_rot);
	/**
	 * Returns the angle in radians from the positive X axis to the first basis column. Positive angles turn
	 * clockwise in Godot's 2D canvas coordinates.
	 */
	real_t get_rotation() const;
	/**
	 * Returns the signed deviation in radians from perpendicular basis axes. Accounts for a reflection when
	 * measuring the Y axis.
	 */
	real_t get_skew() const;
	/**
	 * Turns the second basis column to set its angular deviation from perpendicular in radians. Preserves
	 * the first column, the second column's length, and the origin.
	 */
	void set_skew(real_t p_angle);
	/**
	 * Replaces the basis with the given rotation in radians and axis scales. Clears skew and preserves the
	 * origin.
	 */
	_FORCE_INLINE_ void set_rotation_and_scale(real_t p_rot, const Size2 &p_scale);
	/**
	 * Replaces the basis with the given axis scales, rotation in radians, and skew in radians. Preserves
	 * the origin.
	 */
	_FORCE_INLINE_ void set_rotation_scale_and_skew(real_t p_rot, const Size2 &p_scale, real_t p_skew);
	/**
	 * Rotates both basis and origin around the destination origin by the given angle in radians.
	 */
	void rotate(real_t p_angle);

	/**
	 * Scales the basis rows and origin along the destination axes.
	 */
	void scale(const Size2 &p_scale);
	/**
	 * Scales the basis along destination X and Y while preserving the origin.
	 */
	void scale_basis(const Size2 &p_scale);
	/**
	 * Moves the origin by a local offset converted through this transform's basis.
	 */
	void translate_local(real_t p_tx, real_t p_ty);
	/**
	 * Moves the origin by a local offset converted through this transform's basis.
	 */
	void translate_local(const Vector2 &p_translation);

	/**
	 * Returns the signed area scale of the basis. A negative result indicates a reflection and zero
	 * indicates a singular basis.
	 */
	real_t determinant() const;

	/**
	 * Returns the lengths of the basis columns. Negates the Y component when the determinant is negative.
	 */
	Size2 get_scale() const;
	/**
	 * Normalizes each basis column and multiplies it by its corresponding scale component. Preserves the
	 * origin.
	 */
	void set_scale(const Size2 &p_scale);

	/**
	 * Returns a read-only reference to the position of the local origin in destination coordinates.
	 */
	_FORCE_INLINE_ const Vector2 &get_origin() const { return columns[2]; }
	/**
	 * Moves the local origin to the given position in destination coordinates. Preserves the basis.
	 */
	_FORCE_INLINE_ void set_origin(const Vector2 &p_origin) { columns[2] = p_origin; }

	/**
	 * Returns a copy with its basis and origin scaled along the destination axes.
	 */
	Transform2D scaled(const Size2 &p_scale) const;
	/**
	 * Returns a copy with its basis columns scaled along the local axes. Preserves the origin.
	 */
	Transform2D scaled_local(const Size2 &p_scale) const;
	/**
	 * Returns a copy whose origin is moved by the supplied destination-space offset. Preserves the basis.
	 */
	Transform2D translated(const Vector2 &p_offset) const;
	/**
	 * Returns a copy whose origin is moved by the supplied local offset converted through the basis.
	 */
	Transform2D translated_local(const Vector2 &p_offset) const;
	/**
	 * Returns a copy rotated about the destination origin. Rotates the basis and origin by the given angle
	 * in radians.
	 */
	Transform2D rotated(real_t p_angle) const;
	/**
	 * Returns a copy with its basis rotated in local coordinates. The angle is in radians, and the origin
	 * stays fixed.
	 */
	Transform2D rotated_local(real_t p_angle) const;

	/**
	 * Returns a copy with its origin set to zero. Preserves the basis.
	 */
	Transform2D untranslated() const;

	/**
	 * Replaces the basis with perpendicular unit axes by applying Gram–Schmidt orthonormalization.
	 * Preserves the origin.
	 */
	void orthonormalize();
	/**
	 * Returns a copy with perpendicular unit basis axes and the original origin.
	 */
	Transform2D orthonormalized() const;
	/**
	 * Tests whether the basis columns are approximately perpendicular and have equal length. Reflections
	 * can satisfy this test.
	 */
	bool is_conformal() const;
	/**
	 * Tests the components of the basis and origin for approximate equality.
	 */
	bool is_equal_approx(const Transform2D &p_transform) const;
	/**
	 * Tests component-wise equality, treating a pair of NaN components as equal.
	 */
	bool is_same(const Transform2D &p_transform) const;
	/**
	 * Tests whether every component of the basis and origin is finite.
	 */
	bool is_finite() const;

	/**
	 * Returns a transform at the same origin with unit scale and zero skew, oriented so that its X axis
	 * points toward the target in destination coordinates.
	 */
	Transform2D looking_at(const Vector2 &p_target) const;

	/**
	 * Tests exact equality of all basis and origin components.
	 */
	constexpr bool operator==(const Transform2D &p_transform) const;
	/**
	 * Tests whether any basis or origin component differs.
	 */
	constexpr bool operator!=(const Transform2D &p_transform) const;

	/**
	 * Composes this transform with the right-hand transform. The right-hand transform acts on a point
	 * first.
	 */
	void operator*=(const Transform2D &p_transform);
	/**
	 * Returns the composition of this transform and the right-hand transform. The right-hand transform acts
	 * on a point first.
	 */
	Transform2D operator*(const Transform2D &p_transform) const;
	/**
	 * Multiplies each basis and origin component by the scalar in place.
	 */
	constexpr void operator*=(real_t p_val);
	/**
	 * Returns a copy with each basis and origin component multiplied by the scalar.
	 */
	constexpr Transform2D operator*(real_t p_val) const;
	/**
	 * Divides each basis and origin component by the scalar in place.
	 */
	constexpr void operator/=(real_t p_val);
	/**
	 * Returns a copy with each basis and origin component divided by the scalar.
	 */
	constexpr Transform2D operator/(real_t p_val) const;

	/**
	 * Interpolates the origin and signed scale component-wise, and interpolates rotation and skew along the
	 * shorter angular paths. A weight of zero starts at this transform and one reaches the target
	 * decomposition.
	 */
	Transform2D interpolate_with(const Transform2D &p_transform, real_t p_c) const;

	/**
	 * Multiplies a local vector by the basis without applying the origin.
	 */
	_FORCE_INLINE_ Vector2 basis_xform(const Vector2 &p_vec) const;
	/**
	 * Multiplies a destination vector by the transpose of the basis without applying the origin. This
	 * reverses the basis transform when the basis is orthonormal.
	 */
	_FORCE_INLINE_ Vector2 basis_xform_inv(const Vector2 &p_vec) const;
	/**
	 * Maps a point from local to destination coordinates using the basis and origin.
	 */
	_FORCE_INLINE_ Vector2 xform(const Vector2 &p_vec) const;
	/**
	 * Subtracts the origin and multiplies the result by the transposed basis. This maps a destination point
	 * to local coordinates when the basis is orthonormal.
	 */
	_FORCE_INLINE_ Vector2 xform_inv(const Vector2 &p_vec) const;
	/**
	 * Returns the smallest axis-aligned box containing the transformed input corners in destination
	 * coordinates.
	 */
	_FORCE_INLINE_ Rect2 xform(const Rect2 &p_rect) const;
	/**
	 * Applies the transpose-based inverse to the box corners and returns their axis-aligned bounds. The
	 * basis must be orthonormal for this to be the inverse transform.
	 */
	_FORCE_INLINE_ Rect2 xform_inv(const Rect2 &p_rect) const;
	/**
	 * Returns a new packed array with each point mapped from local to destination coordinates.
	 */
	_FORCE_INLINE_ PackedVector2Array xform(const PackedVector2Array &p_array) const;
	/**
	 * Returns a new packed array with the transpose-based inverse applied to each point. The basis must be
	 * orthonormal for the result to be in local coordinates.
	 */
	_FORCE_INLINE_ PackedVector2Array xform_inv(const PackedVector2Array &p_array) const;

	/**
	 * Formats the basis columns and origin as a `godot::String`.
	 */
	explicit operator String() const;

	/**
	 * Creates a transform from the X column, Y column, and origin. Each consecutive pair supplies the X and
	 * Y coordinates of one column.
	 */
	constexpr Transform2D(real_t p_xx, real_t p_xy, real_t p_yx, real_t p_yy, real_t p_ox, real_t p_oy) :
			columns{
				{ p_xx, p_xy },
				{ p_yx, p_yy },
				{ p_ox, p_oy },
			} {}

	/**
	 * Creates a transform from the destination-space images of the local X axis, Y axis, and origin.
	 */
	constexpr Transform2D(const Vector2 &p_x, const Vector2 &p_y, const Vector2 &p_origin) :
			columns{ p_x, p_y, p_origin } {}

	/**
	 * Creates a transform with the given rotation in radians, unit scale, and the given destination-space
	 * origin.
	 */
	Transform2D(real_t p_rot, const Vector2 &p_pos);

	/**
	 * Creates a transform from rotation and skew in radians, axis scales, and a destination-space origin.
	 */
	Transform2D(real_t p_rot, const Size2 &p_scale, real_t p_skew, const Vector2 &p_pos);

	/**
	 * Creates an identity transform with unit axes and a zero origin.
	 */
	Transform2D() = default;
};

inline constexpr Transform2D Transform2D::FLIP_X = { { -1, 0 }, { 0, 1 }, { 0, 0 } };
inline constexpr Transform2D Transform2D::FLIP_Y = { { 1, 0 }, { 0, -1 }, { 0, 0 } };

constexpr bool Transform2D::operator==(const Transform2D &p_transform) const {
	for (int i = 0; i < 3; i++) {
		if (columns[i] != p_transform.columns[i]) {
			return false;
		}
	}

	return true;
}

constexpr bool Transform2D::operator!=(const Transform2D &p_transform) const {
	for (int i = 0; i < 3; i++) {
		if (columns[i] != p_transform.columns[i]) {
			return true;
		}
	}

	return false;
}

constexpr void Transform2D::operator*=(real_t p_val) {
	columns[0] *= p_val;
	columns[1] *= p_val;
	columns[2] *= p_val;
}

constexpr Transform2D Transform2D::operator*(real_t p_val) const {
	Transform2D ret(*this);
	ret *= p_val;
	return ret;
}

constexpr void Transform2D::operator/=(real_t p_val) {
	columns[0] /= p_val;
	columns[1] /= p_val;
	columns[2] /= p_val;
}

constexpr Transform2D Transform2D::operator/(real_t p_val) const {
	Transform2D ret(*this);
	ret /= p_val;
	return ret;
}

Vector2 Transform2D::basis_xform(const Vector2 &p_vec) const {
	return Vector2(
			tdotx(p_vec),
			tdoty(p_vec));
}

Vector2 Transform2D::basis_xform_inv(const Vector2 &p_vec) const {
	return Vector2(
			columns[0].dot(p_vec),
			columns[1].dot(p_vec));
}

Vector2 Transform2D::xform(const Vector2 &p_vec) const {
	return Vector2(
				   tdotx(p_vec),
				   tdoty(p_vec)) +
			columns[2];
}

Vector2 Transform2D::xform_inv(const Vector2 &p_vec) const {
	Vector2 v = p_vec - columns[2];

	return Vector2(
			columns[0].dot(v),
			columns[1].dot(v));
}

Rect2 Transform2D::xform(const Rect2 &p_rect) const {
	Vector2 x = columns[0] * p_rect.size.x;
	Vector2 y = columns[1] * p_rect.size.y;
	Vector2 pos = xform(p_rect.position);

	Rect2 new_rect;
	new_rect.position = pos;
	new_rect.expand_to(pos + x);
	new_rect.expand_to(pos + y);
	new_rect.expand_to(pos + x + y);
	return new_rect;
}

void Transform2D::set_rotation_and_scale(real_t p_rot, const Size2 &p_scale) {
	columns[0][0] = Math::cos(p_rot) * p_scale.x;
	columns[1][1] = Math::cos(p_rot) * p_scale.y;
	columns[1][0] = -Math::sin(p_rot) * p_scale.y;
	columns[0][1] = Math::sin(p_rot) * p_scale.x;
}

void Transform2D::set_rotation_scale_and_skew(real_t p_rot, const Size2 &p_scale, real_t p_skew) {
	columns[0][0] = Math::cos(p_rot) * p_scale.x;
	columns[1][1] = Math::cos(p_rot + p_skew) * p_scale.y;
	columns[1][0] = -Math::sin(p_rot + p_skew) * p_scale.y;
	columns[0][1] = Math::sin(p_rot) * p_scale.x;
}

Rect2 Transform2D::xform_inv(const Rect2 &p_rect) const {
	Vector2 ends[4] = {
		xform_inv(p_rect.position),
		xform_inv(Vector2(p_rect.position.x, p_rect.position.y + p_rect.size.y)),
		xform_inv(Vector2(p_rect.position.x + p_rect.size.x, p_rect.position.y + p_rect.size.y)),
		xform_inv(Vector2(p_rect.position.x + p_rect.size.x, p_rect.position.y))
	};

	Rect2 new_rect;
	new_rect.position = ends[0];
	new_rect.expand_to(ends[1]);
	new_rect.expand_to(ends[2]);
	new_rect.expand_to(ends[3]);

	return new_rect;
}

PackedVector2Array Transform2D::xform(const PackedVector2Array &p_array) const {
	PackedVector2Array array;
	array.resize(p_array.size());

	const Vector2 *r = p_array.ptr();
	Vector2 *w = array.ptrw();

	for (int i = 0; i < p_array.size(); ++i) {
		w[i] = xform(r[i]);
	}
	return array;
}

PackedVector2Array Transform2D::xform_inv(const PackedVector2Array &p_array) const {
	PackedVector2Array array;
	array.resize(p_array.size());

	const Vector2 *r = p_array.ptr();
	Vector2 *w = array.ptrw();

	for (int i = 0; i < p_array.size(); ++i) {
		w[i] = xform_inv(r[i]);
	}
	return array;
}

} // namespace godot
