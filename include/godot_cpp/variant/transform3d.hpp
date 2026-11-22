/**************************************************************************/
/*  transform3d.hpp                                                       */
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

#include <godot_cpp/core/math.hpp>
#include <godot_cpp/templates/vector.hpp>
#include <godot_cpp/variant/aabb.hpp>
#include <godot_cpp/variant/basis.hpp>
#include <godot_cpp/variant/packed_vector3_array.hpp>
#include <godot_cpp/variant/plane.hpp>

namespace godot {

/**
 * An affine transform that maps 3D points from local coordinates to a destination coordinate system.
 * Its basis describes the transformed axes, and its origin describes translation.
 */
struct [[nodiscard]] Transform3D {
	/**
	 * A transform that negates the X coordinate and preserves the other coordinates and the origin.
	 */
	static const Transform3D FLIP_X;
	/**
	 * A transform that negates the Y coordinate and preserves the other coordinates and the origin.
	 */
	static const Transform3D FLIP_Y;
	/**
	 * A transform that negates the Z coordinate and preserves the other coordinates and the origin.
	 */
	static const Transform3D FLIP_Z;

	/**
	 * The linear part of the transform. Its columns are the images of the local X, Y, and Z axes in
	 * destination coordinates.
	 */
	Basis basis;
	/**
	 * The position of the local origin in destination coordinates.
	 */
	Vector3 origin;

	/**
	 * Replaces the transform with its inverse using the transpose of the basis. The original basis must be
	 * orthonormal.
	 */
	void invert();
	/**
	 * Returns the inverse transform using the transpose of the basis. The original basis must be
	 * orthonormal.
	 */
	Transform3D inverse() const;

	/**
	 * Replaces the transform with its affine inverse. The basis must have a nonzero determinant and may
	 * include scale or skew.
	 */
	void affine_invert();
	/**
	 * Returns the affine inverse that maps destination points back to local coordinates. The basis must
	 * have a nonzero determinant and may include scale or skew.
	 */
	Transform3D affine_inverse() const;

	/**
	 * Returns a copy rotated about the destination origin. Rotates the basis and origin by the given angle
	 * in radians around the normalized axis.
	 */
	Transform3D rotated(const Vector3 &p_axis, real_t p_angle) const;
	/**
	 * Returns a copy with its basis rotated in local coordinates around the given normalized local axis.
	 * The angle is in radians, and the origin stays fixed.
	 */
	Transform3D rotated_local(const Vector3 &p_axis, real_t p_angle) const;

	/**
	 * Rotates the basis and origin around the given normalized axis through the destination origin. The
	 * angle is in radians.
	 */
	void rotate(const Vector3 &p_axis, real_t p_angle);
	/**
	 * Rotates the basis around the given normalized axis in destination coordinates. The angle is in
	 * radians and the origin stays fixed.
	 */
	void rotate_basis(const Vector3 &p_axis, real_t p_angle);

	/**
	 * Moves the origin to the eye position and replaces the basis with an orthonormal basis facing the
	 * target. The negative Z axis faces the target by default. Pass true in `p_use_model_front` to use
	 * positive Z. The view direction and up vector must be nonzero and nonparallel.
	 */
	void set_look_at(const Vector3 &p_eye, const Vector3 &p_target, const Vector3 &p_up = Vector3::UP, bool p_use_model_front = false);
	/**
	 * Returns a transform at the same origin with an orthonormal basis facing the target in destination
	 * coordinates. The negative Z axis faces the target by default. Pass true in `p_use_model_front` to use
	 * positive Z. The view direction and up vector must be nonzero and nonparallel.
	 */
	Transform3D looking_at(const Vector3 &p_target, const Vector3 &p_up = Vector3::UP, bool p_use_model_front = false) const;

	/**
	 * Scales the basis rows and origin along the destination axes.
	 */
	void scale(const Vector3 &p_scale);
	/**
	 * Returns a copy with its basis and origin scaled along the destination axes.
	 */
	Transform3D scaled(const Vector3 &p_scale) const;
	/**
	 * Returns a copy with its basis columns scaled along the local axes. Preserves the origin.
	 */
	Transform3D scaled_local(const Vector3 &p_scale) const;
	/**
	 * Scales the basis along the destination axes while preserving the origin.
	 */
	void scale_basis(const Vector3 &p_scale);
	/**
	 * Moves the origin by a local offset converted through this transform's basis.
	 */
	void translate_local(real_t p_tx, real_t p_ty, real_t p_tz);
	/**
	 * Moves the origin by a local offset converted through this transform's basis.
	 */
	void translate_local(const Vector3 &p_translation);
	/**
	 * Returns a copy whose origin is moved by the supplied destination-space offset. Preserves the basis.
	 */
	Transform3D translated(const Vector3 &p_translation) const;
	/**
	 * Returns a copy whose origin is moved by the supplied local offset converted through the basis.
	 */
	Transform3D translated_local(const Vector3 &p_translation) const;

	/**
	 * Returns a read-only reference to the linear part of the transform.
	 */
	const Basis &get_basis() const { return basis; }
	/**
	 * Replaces the linear part of the transform and preserves the origin.
	 */
	void set_basis(const Basis &p_basis) { basis = p_basis; }

	/**
	 * Returns a read-only reference to the position of the local origin in destination coordinates.
	 */
	const Vector3 &get_origin() const { return origin; }
	/**
	 * Moves the local origin to the given position in destination coordinates. Preserves the basis.
	 */
	void set_origin(const Vector3 &p_origin) { origin = p_origin; }

	/**
	 * Replaces the basis with perpendicular unit axes by applying Gram–Schmidt orthonormalization.
	 * Preserves the origin.
	 */
	void orthonormalize();
	/**
	 * Returns a copy with perpendicular unit basis axes and the original origin.
	 */
	Transform3D orthonormalized() const;
	/**
	 * Makes the basis axes perpendicular while restoring the scale extracted from the original basis.
	 * Preserves the origin.
	 */
	void orthogonalize();
	/**
	 * Returns a copy with perpendicular basis axes and the scale extracted from the original basis.
	 * Preserves the origin.
	 */
	Transform3D orthogonalized() const;
	/**
	 * Tests the components of the basis and origin for approximate equality.
	 */
	bool is_equal_approx(const Transform3D &p_transform) const;
	/**
	 * Tests component-wise equality, treating a pair of NaN components as equal.
	 */
	bool is_same(const Transform3D &p_transform) const;
	/**
	 * Tests whether every component of the basis and origin is finite.
	 */
	bool is_finite() const;

	/**
	 * Tests exact equality of all basis and origin components.
	 */
	constexpr bool operator==(const Transform3D &p_transform) const;
	/**
	 * Tests whether any basis or origin component differs.
	 */
	constexpr bool operator!=(const Transform3D &p_transform) const;

	/**
	 * Maps a point from local to destination coordinates using the basis and origin.
	 */
	_FORCE_INLINE_ Vector3 xform(const Vector3 &p_vector) const;
	/**
	 * Returns the smallest axis-aligned box containing the transformed input corners in destination
	 * coordinates.
	 */
	_FORCE_INLINE_ AABB xform(const AABB &p_aabb) const;
	/**
	 * Returns a new packed array with each point mapped from local to destination coordinates.
	 */
	_FORCE_INLINE_ PackedVector3Array xform(const PackedVector3Array &p_array) const;

	// NOTE: These are UNSAFE with non-uniform scaling, and will produce incorrect results.
	// They use the transpose.
	// For safe inverse transforms, xform by the affine_inverse.
	/**
	 * Subtracts the origin and multiplies the result by the transposed basis. This maps a destination point
	 * to local coordinates when the basis is orthonormal.
	 */
	_FORCE_INLINE_ Vector3 xform_inv(const Vector3 &p_vector) const;
	/**
	 * Applies the transpose-based inverse to the box corners and returns their axis-aligned bounds. The
	 * basis must be orthonormal for this to be the inverse transform.
	 */
	_FORCE_INLINE_ AABB xform_inv(const AABB &p_aabb) const;
	/**
	 * Returns a new packed array with the transpose-based inverse applied to each point. The basis must be
	 * orthonormal for the result to be in local coordinates.
	 */
	_FORCE_INLINE_ PackedVector3Array xform_inv(const PackedVector3Array &p_array) const;

	// Safe with non-uniform scaling (uses affine_inverse).
	/**
	 * Maps a plane to destination coordinates using the inverse transpose of the basis for its normal. The
	 * input plane must have a unit normal and the basis must be invertible.
	 */
	_FORCE_INLINE_ Plane xform(const Plane &p_plane) const;
	/**
	 * Maps a plane from destination to local coordinates using the affine inverse. The input plane must
	 * have a unit normal and the basis must be invertible.
	 */
	_FORCE_INLINE_ Plane xform_inv(const Plane &p_plane) const;

	// These fast versions use precomputed affine inverse, and should be used in bottleneck areas where
	// multiple planes are to be transformed.
	/**
	 * Maps a plane to destination coordinates using the supplied inverse transpose of the forward basis to
	 * transform its normal. The input plane must have a unit normal.
	 */
	_FORCE_INLINE_ Plane xform_fast(const Plane &p_plane, const Basis &p_basis_inverse_transpose) const;
	/**
	 * Maps a plane back to local coordinates using the supplied affine inverse for its position and the
	 * transpose of the forward basis for its normal. The input plane must have a unit normal.
	 */
	static _FORCE_INLINE_ Plane xform_inv_fast(const Plane &p_plane, const Transform3D &p_inverse, const Basis &p_basis_transpose);

	/**
	 * Composes this transform with the right-hand transform. The right-hand transform acts on a point
	 * first.
	 */
	void operator*=(const Transform3D &p_transform);
	/**
	 * Returns the composition of this transform and the right-hand transform. The right-hand transform acts
	 * on a point first.
	 */
	Transform3D operator*(const Transform3D &p_transform) const;
	/**
	 * Multiplies each basis and origin component by the scalar in place.
	 */
	constexpr void operator*=(real_t p_val);
	/**
	 * Returns a copy with each basis and origin component multiplied by the scalar.
	 */
	constexpr Transform3D operator*(real_t p_val) const;
	/**
	 * Divides each basis and origin component by the scalar in place.
	 */
	constexpr void operator/=(real_t p_val);
	/**
	 * Returns a copy with each basis and origin component divided by the scalar.
	 */
	constexpr Transform3D operator/(real_t p_val) const;

	/**
	 * Interpolates the extracted rotations spherically and the scales and origins component-wise. The
	 * result is rebuilt from those components.
	 */
	Transform3D interpolate_with(const Transform3D &p_transform, real_t p_c) const;

	/**
	 * Returns a transform whose basis is this basis transposed times the input basis. Its origin is the
	 * difference between the two origins multiplied by this basis.
	 */
	_FORCE_INLINE_ Transform3D inverse_xform(const Transform3D &p_transform) const {
		Vector3 v = p_transform.origin - origin;
		return Transform3D(basis.transpose_xform(p_transform.basis),
				basis.xform(v));
	}

	/**
	 * Replaces the basis and origin. The first nine scalars supply the three basis rows in order. The last
	 * three scalars supply the destination-space origin.
	 */
	void set(real_t p_xx, real_t p_xy, real_t p_xz, real_t p_yx, real_t p_yy, real_t p_yz, real_t p_zx, real_t p_zy, real_t p_zz, real_t p_tx, real_t p_ty, real_t p_tz) {
		basis.set(p_xx, p_xy, p_xz, p_yx, p_yy, p_yz, p_zx, p_zy, p_zz);
		origin.x = p_tx;
		origin.y = p_ty;
		origin.z = p_tz;
	}

	/**
	 * Formats the basis columns and origin as a `godot::String`.
	 */
	explicit operator String() const;

	/**
	 * Creates an identity transform with unit axes and a zero origin.
	 */
	Transform3D() = default;
	/**
	 * Creates a transform from a linear basis and a destination-space origin.
	 */
	constexpr Transform3D(const Basis &p_basis, const Vector3 &p_origin = Vector3()) :
			basis(p_basis),
			origin(p_origin) {}
	/**
	 * Creates a transform from the destination-space images of the local X, Y, and Z axes and the local
	 * origin.
	 */
	constexpr Transform3D(const Vector3 &p_x, const Vector3 &p_y, const Vector3 &p_z, const Vector3 &p_origin) :
			basis(p_x, p_y, p_z),
			origin(p_origin) {}
	/**
	 * Creates a transform from nine basis entries in row order followed by three destination-space origin
	 * coordinates.
	 */
	constexpr Transform3D(real_t p_xx, real_t p_xy, real_t p_xz, real_t p_yx, real_t p_yy, real_t p_yz, real_t p_zx, real_t p_zy, real_t p_zz, real_t p_ox, real_t p_oy, real_t p_oz) :
			basis(p_xx, p_xy, p_xz, p_yx, p_yy, p_yz, p_zx, p_zy, p_zz),
			origin(p_ox, p_oy, p_oz) {}
};

inline constexpr Transform3D Transform3D::FLIP_X = { Basis::FLIP_X };
inline constexpr Transform3D Transform3D::FLIP_Y = { Basis::FLIP_Y };
inline constexpr Transform3D Transform3D::FLIP_Z = { Basis::FLIP_Z };

constexpr bool Transform3D::operator==(const Transform3D &p_transform) const {
	return (basis == p_transform.basis && origin == p_transform.origin);
}

constexpr bool Transform3D::operator!=(const Transform3D &p_transform) const {
	return (basis != p_transform.basis || origin != p_transform.origin);
}

constexpr void Transform3D::operator*=(real_t p_val) {
	origin *= p_val;
	basis *= p_val;
}

constexpr Transform3D Transform3D::operator*(real_t p_val) const {
	Transform3D ret(*this);
	ret *= p_val;
	return ret;
}

constexpr void Transform3D::operator/=(real_t p_val) {
	basis /= p_val;
	origin /= p_val;
}

constexpr Transform3D Transform3D::operator/(real_t p_val) const {
	Transform3D ret(*this);
	ret /= p_val;
	return ret;
}

_FORCE_INLINE_ Vector3 Transform3D::xform(const Vector3 &p_vector) const {
	return Vector3(
			basis[0].dot(p_vector) + origin.x,
			basis[1].dot(p_vector) + origin.y,
			basis[2].dot(p_vector) + origin.z);
}

_FORCE_INLINE_ Vector3 Transform3D::xform_inv(const Vector3 &p_vector) const {
	Vector3 v = p_vector - origin;

	return Vector3(
			(basis.rows[0][0] * v.x) + (basis.rows[1][0] * v.y) + (basis.rows[2][0] * v.z),
			(basis.rows[0][1] * v.x) + (basis.rows[1][1] * v.y) + (basis.rows[2][1] * v.z),
			(basis.rows[0][2] * v.x) + (basis.rows[1][2] * v.y) + (basis.rows[2][2] * v.z));
}

// Neither the plane regular xform or xform_inv are particularly efficient,
// as they do a basis inverse. For xforming a large number
// of planes it is better to pre-calculate the inverse transpose basis once
// and reuse it for each plane, by using the 'fast' version of the functions.
_FORCE_INLINE_ Plane Transform3D::xform(const Plane &p_plane) const {
	Basis b = basis.inverse();
	b.transpose();
	return xform_fast(p_plane, b);
}

_FORCE_INLINE_ Plane Transform3D::xform_inv(const Plane &p_plane) const {
	Transform3D inv = affine_inverse();
	Basis basis_transpose = basis.transposed();
	return xform_inv_fast(p_plane, inv, basis_transpose);
}

_FORCE_INLINE_ AABB Transform3D::xform(const AABB &p_aabb) const {
	/* https://dev.theomader.com/transform-bounding-boxes/ */
	Vector3 min = p_aabb.position;
	Vector3 max = p_aabb.position + p_aabb.size;
	Vector3 tmin, tmax;
	for (int i = 0; i < 3; i++) {
		tmin[i] = tmax[i] = origin[i];
		for (int j = 0; j < 3; j++) {
			real_t e = basis[i][j] * min[j];
			real_t f = basis[i][j] * max[j];
			if (e < f) {
				tmin[i] += e;
				tmax[i] += f;
			} else {
				tmin[i] += f;
				tmax[i] += e;
			}
		}
	}
	AABB r_aabb;
	r_aabb.position = tmin;
	r_aabb.size = tmax - tmin;
	return r_aabb;
}

_FORCE_INLINE_ AABB Transform3D::xform_inv(const AABB &p_aabb) const {
	/* define vertices */
	Vector3 vertices[8] = {
		Vector3(p_aabb.position.x + p_aabb.size.x, p_aabb.position.y + p_aabb.size.y, p_aabb.position.z + p_aabb.size.z),
		Vector3(p_aabb.position.x + p_aabb.size.x, p_aabb.position.y + p_aabb.size.y, p_aabb.position.z),
		Vector3(p_aabb.position.x + p_aabb.size.x, p_aabb.position.y, p_aabb.position.z + p_aabb.size.z),
		Vector3(p_aabb.position.x + p_aabb.size.x, p_aabb.position.y, p_aabb.position.z),
		Vector3(p_aabb.position.x, p_aabb.position.y + p_aabb.size.y, p_aabb.position.z + p_aabb.size.z),
		Vector3(p_aabb.position.x, p_aabb.position.y + p_aabb.size.y, p_aabb.position.z),
		Vector3(p_aabb.position.x, p_aabb.position.y, p_aabb.position.z + p_aabb.size.z),
		Vector3(p_aabb.position.x, p_aabb.position.y, p_aabb.position.z)
	};

	AABB ret;

	ret.position = xform_inv(vertices[0]);

	for (int i = 1; i < 8; i++) {
		ret.expand_to(xform_inv(vertices[i]));
	}

	return ret;
}

PackedVector3Array Transform3D::xform(const PackedVector3Array &p_array) const {
	PackedVector3Array array;
	array.resize(p_array.size());

	const Vector3 *r = p_array.ptr();
	Vector3 *w = array.ptrw();

	for (int i = 0; i < p_array.size(); ++i) {
		w[i] = xform(r[i]);
	}
	return array;
}

PackedVector3Array Transform3D::xform_inv(const PackedVector3Array &p_array) const {
	PackedVector3Array array;
	array.resize(p_array.size());

	const Vector3 *r = p_array.ptr();
	Vector3 *w = array.ptrw();

	for (int i = 0; i < p_array.size(); ++i) {
		w[i] = xform_inv(r[i]);
	}
	return array;
}

_FORCE_INLINE_ Plane Transform3D::xform_fast(const Plane &p_plane, const Basis &p_basis_inverse_transpose) const {
	// Transform a single point on the plane.
	Vector3 point = p_plane.normal * p_plane.d;
	point = xform(point);

	// Use inverse transpose for correct normals with non-uniform scaling.
	Vector3 normal = p_basis_inverse_transpose.xform(p_plane.normal);
	normal.normalize();

	real_t d = normal.dot(point);
	return Plane(normal, d);
}

_FORCE_INLINE_ Plane Transform3D::xform_inv_fast(const Plane &p_plane, const Transform3D &p_inverse, const Basis &p_basis_transpose) {
	// Transform a single point on the plane.
	Vector3 point = p_plane.normal * p_plane.d;
	point = p_inverse.xform(point);

	// Note that instead of precalculating the transpose, an alternative
	// would be to use the transpose for the basis transform.
	// However that would be less SIMD friendly (requiring a swizzle).
	// So the cost is one extra precalced value in the calling code.
	// This is probably worth it, as this could be used in bottleneck areas. And
	// where it is not a bottleneck, the non-fast method is fine.

	// Use transpose for correct normals with non-uniform scaling.
	Vector3 normal = p_basis_transpose.xform(p_plane.normal);
	normal.normalize();

	real_t d = normal.dot(point);
	return Plane(normal, d);
}

} // namespace godot
