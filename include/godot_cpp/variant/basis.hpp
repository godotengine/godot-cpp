/**************************************************************************/
/*  basis.hpp                                                             */
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

#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/variant/quaternion.hpp>
#include <godot_cpp/variant/vector3.hpp>

namespace godot {

/**
 * A 3×3 matrix for representing 3D rotation and scale.
 */
struct [[nodiscard]] Basis {
	/**
	 * When any basis is multiplied by `godot::Basis::FLIP_X`, it negates all components of the `x` axis
	 * (the X column). When `godot::Basis::FLIP_X` is multiplied by any basis, it negates the `x` component
	 * of all axes (the X row).
	 */
	static const Basis FLIP_X;
	/**
	 * When any basis is multiplied by `godot::Basis::FLIP_Y`, it negates all components of the `y` axis
	 * (the Y column). When `godot::Basis::FLIP_Y` is multiplied by any basis, it negates the `y` component
	 * of all axes (the Y row).
	 */
	static const Basis FLIP_Y;
	/**
	 * When any basis is multiplied by `godot::Basis::FLIP_Z`, it negates all components of the `z` axis
	 * (the Z column). When `godot::Basis::FLIP_Z` is multiplied by any basis, it negates the `z` component
	 * of all axes (the Z row).
	 */
	static const Basis FLIP_Z;

	/**
	 * Stores the matrix in row order. Each column is one transformed local axis.
	 */
	Vector3 rows[3] = {
		Vector3(1, 0, 0),
		Vector3(0, 1, 0),
		Vector3(0, 0, 1)
	};

	/**
	 * Returns a read-only reference to a stored matrix row.
	 *
	 * - `p_row` — Zero-based matrix row index, from zero through two.
	 */
	constexpr const Vector3 &operator[](int p_row) const {
		return rows[p_row];
	}
	/**
	 * Returns a writable reference to a stored matrix row.
	 *
	 * - `p_row` — Zero-based matrix row index, from zero through two.
	 */
	constexpr Vector3 &operator[](int p_row) {
		return rows[p_row];
	}

	/**
	 * Replaces the matrix with its inverse. A zero determinant has no inverse.
	 */
	void invert();
	/**
	 * Swaps the rows and columns in place.
	 */
	void transpose();

	/**
	 * Returns the inverse of the matrix without changing this basis.
	 */
	Basis inverse() const;
	/**
	 * Returns the transposed version of this basis. This turns the basis matrix's columns into rows, and
	 * its rows into columns.
	 */
	Basis transposed() const;

	/**
	 * Returns the signed volume scale of the basis. A zero determinant means the basis is singular.
	 */
	_FORCE_INLINE_ real_t determinant() const;

	/**
	 * Applies a rotation in destination coordinates by multiplying on the left.
	 *
	 * - `p_axis` — Unit vector defining the rotation axis.
	 * - `p_angle` — Rotation angle in radians around the axis.
	 */
	void rotate(const Vector3 &p_axis, real_t p_angle);
	/**
	 * Returns a basis rotated in destination coordinates by multiplying on the left.
	 *
	 * - `p_axis` — Unit vector defining the rotation axis.
	 * - `p_angle` — Rotation angle in radians around the axis.
	 */
	Basis rotated(const Vector3 &p_axis, real_t p_angle) const;

	/**
	 * Applies a local rotation by multiplying on the right.
	 *
	 * - `p_axis` — Unit vector defining the rotation axis.
	 * - `p_angle` — Rotation angle in radians around the axis.
	 */
	void rotate_local(const Vector3 &p_axis, real_t p_angle);
	/**
	 * Returns a basis rotated in local coordinates by multiplying on the right.
	 *
	 * - `p_axis` — Unit vector defining the rotation axis.
	 * - `p_angle` — Rotation angle in radians around the axis.
	 */
	Basis rotated_local(const Vector3 &p_axis, real_t p_angle) const;

	/**
	 * Applies an Euler rotation in destination coordinates by multiplying on the left.
	 *
	 * - `p_euler` — Euler angles in radians, stored as X, Y, and Z components.
	 * - `p_order` — Order in which the Euler rotations are applied.
	 */
	void rotate(const Vector3 &p_euler, EulerOrder p_order = EulerOrder::EULER_ORDER_YXZ);
	/**
	 * Returns a basis rotated by Euler angles in destination coordinates.
	 *
	 * - `p_euler` — Euler angles in radians, stored as X, Y, and Z components.
	 * - `p_order` — Order in which the Euler rotations are applied.
	 */
	Basis rotated(const Vector3 &p_euler, EulerOrder p_order = EulerOrder::EULER_ORDER_YXZ) const;

	/**
	 * Applies the quaternion rotation in destination coordinates.
	 *
	 * - `p_quaternion` — Quaternion representing the rotation.
	 */
	void rotate(const Quaternion &p_quaternion);
	/**
	 * Returns a basis rotated by the quaternion in destination coordinates.
	 *
	 * - `p_quaternion` — Quaternion representing the rotation.
	 */
	Basis rotated(const Quaternion &p_quaternion) const;

	/**
	 * Removes scale and reflection from the basis and returns the Euler angles of its rotation.
	 *
	 * - `p_order` — Euler rotation order used to express the result.
	 */
	Vector3 get_euler_normalized(EulerOrder p_order = EulerOrder::EULER_ORDER_YXZ) const;
	/**
	 * Extracts the rotation after removing scale and reflection.
	 *
	 * - `p_axis` — Output for the axis of the extracted rotation.
	 * - `p_angle` — Output for the rotation angle in radians.
	 */
	void get_rotation_axis_angle(Vector3 &p_axis, real_t &p_angle) const;
	/**
	 * Extracts an axis and angle in local coordinates by finding the rotation of the transposed basis and reversing its angle.
	 *
	 * - `p_axis` — Output for the local rotation axis.
	 * - `p_angle` — Output for the local rotation angle in radians.
	 */
	void get_rotation_axis_angle_local(Vector3 &p_axis, real_t &p_angle) const;
	/**
	 * Returns the rotation extracted from the basis as a unit quaternion.
	 */
	Quaternion get_rotation_quaternion() const;

	/**
	 * Rotates the basis from a start direction toward an end direction in destination coordinates. Parallel directions leave the basis unchanged.
	 *
	 * - `p_start_direction` — Unit direction before the rotation.
	 * - `p_end_direction` — Unit direction after the rotation.
	 */
	void rotate_to_align(Vector3 p_start_direction, Vector3 p_end_direction);

	/**
	 * Splits a nonsingular basis with perpendicular axes into its rotation or reflection and nonnegative local scales.
	 *
	 * - `r_rotref` — Output for the orthonormal part, which can include a reflection. Math checks leave it unchanged if the determinant is zero or the input axes fail the orthogonality check.
	 */
	Vector3 rotref_posscale_decomposition(Basis &r_rotref) const;

	/**
	 * Returns the Euler angles of a rotation matrix. Use the normalized extraction when the basis also contains scale.
	 *
	 * - `p_order` — Euler rotation order used to express the result.
	 */
	Vector3 get_euler(EulerOrder p_order = EulerOrder::EULER_ORDER_YXZ) const;
	/**
	 * Replaces the matrix with a rotation from the supplied Euler angles.
	 *
	 * - `p_euler` — Euler angles in radians, stored as X, Y, and Z components.
	 * - `p_order` — Order in which the Euler rotations are applied.
	 */
	void set_euler(const Vector3 &p_euler, EulerOrder p_order = EulerOrder::EULER_ORDER_YXZ);
	/**
	 * Returns a rotation matrix from the supplied Euler angles.
	 *
	 * - `p_euler` — Euler angles in radians, stored as X, Y, and Z components.
	 * - `p_order` — Order in which the Euler rotations are applied.
	 */
	static Basis from_euler(const Vector3 &p_euler, EulerOrder p_order = EulerOrder::EULER_ORDER_YXZ) {
		Basis b;
		b.set_euler(p_euler, p_order);
		return b;
	}

	/**
	 * Converts a rotation matrix to a quaternion. Math checks reject a basis that is not a pure rotation.
	 */
	Quaternion get_quaternion() const;
	/**
	 * Replaces the matrix with the rotation represented by the quaternion.
	 *
	 * - `p_quaternion` — Quaternion representing the rotation.
	 */
	void set_quaternion(const Quaternion &p_quaternion);

	/**
	 * Gets the axis and angle directly from the rotation matrix.
	 *
	 * - `r_axis` — Output for the axis of rotation.
	 * - `r_angle` — Output for the rotation angle in radians.
	 */
	void get_axis_angle(Vector3 &r_axis, real_t &r_angle) const;
	/**
	 * Replaces the matrix with an axis-angle rotation.
	 *
	 * - `p_axis` — Unit vector defining the rotation axis.
	 * - `p_angle` — Rotation angle in radians around the axis.
	 */
	void set_axis_angle(const Vector3 &p_axis, real_t p_angle);

	/**
	 * Scales the rows in place, applying scale in destination coordinates.
	 *
	 * - `p_scale` — Scale factors along the destination X, Y, and Z axes.
	 */
	void scale(const Vector3 &p_scale);
	/**
	 * Returns this basis with each axis's components scaled by the given `scale`'s components. The basis
	 * matrix's rows are multiplied by `scale`'s components. This operation is a global scale (relative to
	 * the parent).
	 *
	 * - `p_scale` — Scale factors along the destination X, Y, and Z axes.
	 */
	Basis scaled(const Vector3 &p_scale) const;

	/**
	 * Scales the columns in place, applying scale in local coordinates.
	 *
	 * - `p_scale` — Scale factors along the local X, Y, and Z axes.
	 */
	void scale_local(const Vector3 &p_scale);
	/**
	 * Returns this basis with each axis scaled by the corresponding component in the given `scale`. The
	 * basis matrix's columns are multiplied by `scale`'s components. This operation is a local scale
	 * (relative to self).
	 *
	 * - `p_scale` — Scale factors along the local X, Y, and Z axes.
	 */
	Basis scaled_local(const Vector3 &p_scale) const;

	/**
	 * Applies the orthogonal scaling calculation to this basis.
	 *
	 * - `p_scale` — Scale factors along the destination X, Y, and Z axes.
	 */
	void scale_orthogonal(const Vector3 &p_scale);
	/**
	 * Returns a scaled basis. The calculation projects the requested change onto the orthonormalized local axes before applying local scale.
	 *
	 * - `p_scale` — Scale factors along the destination X, Y, and Z axes.
	 */
	Basis scaled_orthogonal(const Vector3 &p_scale) const;
	/**
	 * Returns the mean length of the three matrix rows.
	 */
	real_t get_uniform_scale() const;

	/**
	 * Returns the lengths of the three basis columns with a common sign taken from the determinant.
	 */
	Vector3 get_scale() const;
	/**
	 * Returns the lengths of the columns, giving nonnegative local scales.
	 */
	Vector3 get_scale_abs() const;
	/**
	 * Returns the row lengths multiplied by the sign of the determinant.
	 */
	Vector3 get_scale_global() const;

	/**
	 * Replaces the matrix with local scale followed by an axis-angle rotation.
	 *
	 * - `p_axis` — Unit vector defining the rotation axis.
	 * - `p_angle` — Rotation angle in radians around the axis.
	 * - `p_scale` — Scale factors along the local X, Y, and Z axes.
	 */
	void set_axis_angle_scale(const Vector3 &p_axis, real_t p_angle, const Vector3 &p_scale);
	/**
	 * Replaces the matrix with local scale followed by an Euler rotation.
	 *
	 * - `p_euler` — Euler angles in radians, stored as X, Y, and Z components.
	 * - `p_order` — Order in which the Euler rotations are applied.
	 * - `p_scale` — Scale factors along the local X, Y, and Z axes.
	 */
	void set_euler_scale(const Vector3 &p_euler, const Vector3 &p_scale, EulerOrder p_order = EulerOrder::EULER_ORDER_YXZ);
	/**
	 * Replaces the matrix with local scale followed by a quaternion rotation.
	 *
	 * - `p_quaternion` — Quaternion representing the rotation.
	 * - `p_scale` — Scale factors along the local X, Y, and Z axes.
	 */
	void set_quaternion_scale(const Quaternion &p_quaternion, const Vector3 &p_scale);

	// transposed dot products
	/**
	 * Returns the transposed dot product between `with` and the `x` axis (see
	 * `godot::Basis::transposed()`). This is equivalent to `basis.x.dot(vector)`.
	 *
	 * - `p_v` — Vector used in the dot product with the first column.
	 */
	_FORCE_INLINE_ real_t tdotx(const Vector3 &p_v) const {
		return rows[0][0] * p_v[0] + rows[1][0] * p_v[1] + rows[2][0] * p_v[2];
	}
	/**
	 * Returns the transposed dot product between `with` and the `y` axis (see
	 * `godot::Basis::transposed()`). This is equivalent to `basis.y.dot(vector)`.
	 *
	 * - `p_v` — Vector used in the dot product with the second column.
	 */
	_FORCE_INLINE_ real_t tdoty(const Vector3 &p_v) const {
		return rows[0][1] * p_v[0] + rows[1][1] * p_v[1] + rows[2][1] * p_v[2];
	}
	/**
	 * Returns the transposed dot product between `with` and the `z` axis (see
	 * `godot::Basis::transposed()`). This is equivalent to `basis.z.dot(vector)`.
	 *
	 * - `p_v` — Vector used in the dot product with the third column.
	 */
	_FORCE_INLINE_ real_t tdotz(const Vector3 &p_v) const {
		return rows[0][2] * p_v[0] + rows[1][2] * p_v[1] + rows[2][2] * p_v[2];
	}

	/**
	 * Returns `true` if this basis and `b` are approximately equal, by calling `is_equal_approx()` on all
	 * vector components.
	 *
	 * - `p_basis` — Matrix whose entries are compared with this matrix.
	 */
	bool is_equal_approx(const Basis &p_basis) const;
	/**
	 * Tests exact component equality and treats matching NaN components as equal.
	 *
	 * - `p_basis` — Matrix whose entries are compared with this matrix.
	 */
	bool is_same(const Basis &p_basis) const;
	/**
	 * Returns `true` if this basis is finite, by calling `is_finite()` on all vector components.
	 */
	bool is_finite() const;

	/**
	 * Tests exact equality of the components.
	 *
	 * - `p_matrix` — Right-hand matrix in the comparison.
	 */
	constexpr bool operator==(const Basis &p_matrix) const;
	/**
	 * Tests whether any component differs.
	 *
	 * - `p_matrix` — Right-hand matrix in the comparison.
	 */
	constexpr bool operator!=(const Basis &p_matrix) const;

	/**
	 * Multiplies the vector by the matrix, mapping it from local to destination coordinates.
	 *
	 * - `p_vector` — Input vector in local coordinates.
	 */
	_FORCE_INLINE_ Vector3 xform(const Vector3 &p_vector) const;
	/**
	 * Multiplies the vector by the transpose. For an orthonormal basis this is the inverse transform.
	 *
	 * - `p_vector` — Input vector in destination coordinates.
	 */
	_FORCE_INLINE_ Vector3 xform_inv(const Vector3 &p_vector) const;
	/**
	 * Replaces the basis with its product with the right-hand matrix.
	 *
	 * - `p_matrix` — Matrix applied first in the combined transform.
	 */
	_FORCE_INLINE_ void operator*=(const Basis &p_matrix);
	/**
	 * Transforms (multiplies) the `right` basis by this basis. This is the operation performed between
	 * parent and child `godot::Node3D`s.
	 *
	 * - `p_matrix` — Right-hand matrix in the product. Its transform is applied first.
	 */
	_FORCE_INLINE_ Basis operator*(const Basis &p_matrix) const;
	/**
	 * Adds the matching matrix entries in place.
	 *
	 * - `p_matrix` — Matrix supplying the entries to add.
	 */
	constexpr void operator+=(const Basis &p_matrix);
	/**
	 * Adds the matching matrix entries.
	 *
	 * - `p_matrix` — Matrix supplying the entries to add.
	 */
	constexpr Basis operator+(const Basis &p_matrix) const;
	/**
	 * Subtracts the matching matrix entries in place.
	 *
	 * - `p_matrix` — Matrix supplying the entries to subtract.
	 */
	constexpr void operator-=(const Basis &p_matrix);
	/**
	 * Subtracts the matching matrix entries.
	 *
	 * - `p_matrix` — Matrix supplying the entries to subtract.
	 */
	constexpr Basis operator-(const Basis &p_matrix) const;
	/**
	 * Multiplies each matrix entry in place.
	 *
	 * - `p_val` — Factor applied to every entry.
	 */
	constexpr void operator*=(real_t p_val);
	/**
	 * Multiplies all components of the `godot::Basis` by the given `float`. This affects the basis's scale
	 * uniformly, resizing all 3 axes by the `right` value.
	 *
	 * - `p_val` — Factor applied to every entry.
	 */
	constexpr Basis operator*(real_t p_val) const;
	/**
	 * Divides each matrix entry in place.
	 *
	 * - `p_val` — Nonzero divisor applied to every entry.
	 */
	constexpr void operator/=(real_t p_val);
	/**
	 * Divides all components of the `godot::Basis` by the given `float`. This affects the basis's scale
	 * uniformly, resizing all 3 axes by the `right` value.
	 *
	 * - `p_val` — Nonzero divisor applied to every entry.
	 */
	constexpr Basis operator/(real_t p_val) const;

	/**
	 * Tests whether the three basis columns are approximately perpendicular to each other.
	 */
	bool is_orthogonal() const;
	/**
	 * Returns `true` if this basis is orthonormal. An orthonormal basis is both *orthogonal* (the axes are
	 * perpendicular to each other) and *normalized* (the length of every axis is `1.0`). This method can be
	 * especially useful during physics calculations.
	 */
	bool is_orthonormal() const;
	/**
	 * Returns `true` if this basis is conformal. A conformal basis is both *orthogonal* (the axes are
	 * perpendicular to each other) and *uniform* (the axes share the same length). This method can be
	 * especially useful during physics calculations.
	 */
	bool is_conformal() const;
	/**
	 * Tests whether all entries outside the diagonal are approximately zero.
	 */
	bool is_diagonal() const;
	/**
	 * Tests whether the matrix is conformal and its determinant is close to one.
	 */
	bool is_rotation() const;

	/**
	 * Interpolates the matrix entries linearly, row by row.
	 *
	 * - `p_to` — Target basis at weight one.
	 * - `p_weight` — Interpolation factor. Zero selects this basis and one selects the target.
	 */
	Basis lerp(const Basis &p_to, real_t p_weight) const;
	/**
	 * Interpolates the rotations represented by the bases using quaternion spherical interpolation.
	 * Interpolates the row lengths linearly.
	 *
	 * - `p_to` — Target basis at weight one.
	 * - `p_weight` — Interpolation factor. Zero selects this basis and one selects the target.
	 */
	Basis slerp(const Basis &p_to, real_t p_weight) const;
	/**
	 * Applies the basis rotation to spherical harmonic coefficients in place.
	 *
	 * - `p_values` — Writable array of nine coefficients in spherical harmonic order.
	 */
	void rotate_sh(real_t *p_values);

	/**
	 * Formats the three matrix columns with X, Y, and Z labels.
	 */
	explicit operator String() const;

	/* create / set */

	/**
	 * Replaces all matrix entries from values supplied in row order.
	 *
	 * - `p_xx` — Value in row X, column X.
	 * - `p_xy` — Value in row X, column Y.
	 * - `p_xz` — Value in row X, column Z.
	 * - `p_yx` — Value in row Y, column X.
	 * - `p_yy` — Value in row Y, column Y.
	 * - `p_yz` — Value in row Y, column Z.
	 * - `p_zx` — Value in row Z, column X.
	 * - `p_zy` — Value in row Z, column Y.
	 * - `p_zz` — Value in row Z, column Z.
	 */
	_FORCE_INLINE_ void set(real_t p_xx, real_t p_xy, real_t p_xz, real_t p_yx, real_t p_yy, real_t p_yz, real_t p_zx, real_t p_zy, real_t p_zz) {
		rows[0][0] = p_xx;
		rows[0][1] = p_xy;
		rows[0][2] = p_xz;
		rows[1][0] = p_yx;
		rows[1][1] = p_yy;
		rows[1][2] = p_yz;
		rows[2][0] = p_zx;
		rows[2][1] = p_zy;
		rows[2][2] = p_zz;
	}
	/**
	 * Replaces the columns with the three transformed axes.
	 *
	 * - `p_x` — First column, the local X axis.
	 * - `p_y` — Second column, the local Y axis.
	 * - `p_z` — Third column, the local Z axis.
	 */
	_FORCE_INLINE_ void set_columns(const Vector3 &p_x, const Vector3 &p_y, const Vector3 &p_z) {
		set_column(0, p_x);
		set_column(1, p_y);
		set_column(2, p_z);
	}

	/**
	 * Returns a column as a vector in destination coordinates.
	 *
	 * - `p_index` — Zero-based column index, from zero through two.
	 */
	_FORCE_INLINE_ Vector3 get_column(int p_index) const {
		// Get actual basis axis column (we store transposed as rows for performance).
		return Vector3(rows[0][p_index], rows[1][p_index], rows[2][p_index]);
	}

	/**
	 * Replaces a column of the matrix.
	 *
	 * - `p_index` — Zero-based column index, from zero through two.
	 * - `p_value` — New axis vector in destination coordinates.
	 */
	_FORCE_INLINE_ void set_column(int p_index, const Vector3 &p_value) {
		// Set actual basis axis column (we store transposed as rows for performance).
		rows[0][p_index] = p_value.x;
		rows[1][p_index] = p_value.y;
		rows[2][p_index] = p_value.z;
	}

	/**
	 * Returns the three matrix entries on the main diagonal in X, Y, Z order.
	 */
	_FORCE_INLINE_ Vector3 get_main_diagonal() const {
		return Vector3(rows[0][0], rows[1][1], rows[2][2]);
	}

	/**
	 * Sets every matrix entry to zero.
	 */
	_FORCE_INLINE_ void set_zero() {
		rows[0].zero();
		rows[1].zero();
		rows[2].zero();
	}

	/**
	 * Returns the transpose of this basis multiplied by the supplied basis.
	 *
	 * - `p_m` — Right-hand matrix in the product.
	 */
	_FORCE_INLINE_ Basis transpose_xform(const Basis &p_m) const {
		return Basis(
				rows[0].x * p_m[0].x + rows[1].x * p_m[1].x + rows[2].x * p_m[2].x,
				rows[0].x * p_m[0].y + rows[1].x * p_m[1].y + rows[2].x * p_m[2].y,
				rows[0].x * p_m[0].z + rows[1].x * p_m[1].z + rows[2].x * p_m[2].z,
				rows[0].y * p_m[0].x + rows[1].y * p_m[1].x + rows[2].y * p_m[2].x,
				rows[0].y * p_m[0].y + rows[1].y * p_m[1].y + rows[2].y * p_m[2].y,
				rows[0].y * p_m[0].z + rows[1].y * p_m[1].z + rows[2].y * p_m[2].z,
				rows[0].z * p_m[0].x + rows[1].z * p_m[1].x + rows[2].z * p_m[2].x,
				rows[0].z * p_m[0].y + rows[1].z * p_m[1].y + rows[2].z * p_m[2].y,
				rows[0].z * p_m[0].z + rows[1].z * p_m[1].z + rows[2].z * p_m[2].z);
	}
	/**
	 * Creates a basis from its nine matrix entries in row order.
	 *
	 * - `p_xx` — Value in row X, column X.
	 * - `p_xy` — Value in row X, column Y.
	 * - `p_xz` — Value in row X, column Z.
	 * - `p_yx` — Value in row Y, column X.
	 * - `p_yy` — Value in row Y, column Y.
	 * - `p_yz` — Value in row Y, column Z.
	 * - `p_zx` — Value in row Z, column X.
	 * - `p_zy` — Value in row Z, column Y.
	 * - `p_zz` — Value in row Z, column Z.
	 */
	constexpr Basis(real_t p_xx, real_t p_xy, real_t p_xz, real_t p_yx, real_t p_yy, real_t p_yz, real_t p_zx, real_t p_zy, real_t p_zz) :
			rows{
				{ p_xx, p_xy, p_xz },
				{ p_yx, p_yy, p_yz },
				{ p_zx, p_zy, p_zz },
			} {}

	/**
	 * Makes the columns perpendicular and gives them unit length in place using Gram-Schmidt orthonormalization.
	 */
	void orthonormalize();
	/**
	 * Returns a copy with perpendicular, unit-length columns.
	 */
	Basis orthonormalized() const;

	/**
	 * Makes the columns perpendicular and restores the local scale factors.
	 */
	void orthogonalize();
	/**
	 * Returns a copy with perpendicular columns and the original local scale factors.
	 */
	Basis orthogonalized() const;

#ifdef MATH_CHECKS
	/**
	 * Tests approximate equality of entries mirrored across the main diagonal.
	 */
	bool is_symmetric() const;
#endif
	/**
	 * Uses Jacobi rotations to make a symmetric matrix approximately diagonal in place. Returns the accumulated rotation.
	 */
	Basis diagonalize();

	/**
	 * Returns the quaternion conversion of the rotation matrix.
	 */
	operator Quaternion() const { return get_quaternion(); }

	/**
	 * Returns a basis whose forward axis points in the target direction, with orientation set using the up direction.
	 *
	 * - `p_target` — Nonzero direction from the basis origin toward the target.
	 * - `p_up` — Nonzero direction used to choose the basis's up axis.
	 * - `p_use_model_front` — Use local positive Z as forward. Otherwise use local negative Z.
	 */
	static Basis looking_at(const Vector3 &p_target, const Vector3 &p_up = Vector3::UP, bool p_use_model_front = false);

	/**
	 * Creates a rotation matrix from the quaternion.
	 *
	 * - `p_quaternion` — Quaternion representing the rotation.
	 */
	Basis(const Quaternion &p_quaternion) { set_quaternion(p_quaternion); }
	/**
	 * Creates a matrix with local scale followed by the quaternion rotation.
	 *
	 * - `p_quaternion` — Quaternion representing the rotation.
	 * - `p_scale` — Scale factors along the local X, Y, and Z axes.
	 */
	Basis(const Quaternion &p_quaternion, const Vector3 &p_scale) { set_quaternion_scale(p_quaternion, p_scale); }

	/**
	 * Creates a rotation matrix from an axis and angle.
	 *
	 * - `p_axis` — Unit vector defining the rotation axis.
	 * - `p_angle` — Rotation angle in radians around the axis.
	 */
	Basis(const Vector3 &p_axis, real_t p_angle) { set_axis_angle(p_axis, p_angle); }
	/**
	 * Creates a matrix with local scale followed by an axis-angle rotation.
	 *
	 * - `p_axis` — Unit vector defining the rotation axis.
	 * - `p_angle` — Rotation angle in radians around the axis.
	 * - `p_scale` — Scale factors along the local X, Y, and Z axes.
	 */
	Basis(const Vector3 &p_axis, real_t p_angle, const Vector3 &p_scale) { set_axis_angle_scale(p_axis, p_angle, p_scale); }
	/**
	 * Returns a diagonal basis whose three diagonal entries are the supplied axis scales.
	 *
	 * - `p_scale` — Scale factors along the local X, Y, and Z axes.
	 */
	static Basis from_scale(const Vector3 &p_scale);

	/**
	 * Creates a basis with the supplied axis vectors as its columns.
	 *
	 * - `p_x_axis` — First column, the local X axis.
	 * - `p_y_axis` — Second column, the local Y axis.
	 * - `p_z_axis` — Third column, the local Z axis.
	 */
	constexpr Basis(const Vector3 &p_x_axis, const Vector3 &p_y_axis, const Vector3 &p_z_axis) :
			rows{
				{ p_x_axis.x, p_y_axis.x, p_z_axis.x },
				{ p_x_axis.y, p_y_axis.y, p_z_axis.y },
				{ p_x_axis.z, p_y_axis.z, p_z_axis.z },
			} {}

	/**
	 * Creates the identity matrix.
	 */
	Basis() = default;

private:
	// Helper method.
	/**
	 * Sets the diagonal entries and clears every other entry.
	 *
	 * - `p_diag` — The three diagonal entries in X, Y, Z order.
	 */
	void _set_diagonal(const Vector3 &p_diag);
};

inline constexpr Basis Basis::FLIP_X = { { -1, 0, 0 }, { 0, 1, 0 }, { 0, 0, 1 } };
inline constexpr Basis Basis::FLIP_Y = { { 1, 0, 0 }, { 0, -1, 0 }, { 0, 0, 1 } };
inline constexpr Basis Basis::FLIP_Z = { { 1, 0, 0 }, { 0, 1, 0 }, { 0, 0, -1 } };

constexpr bool Basis::operator==(const Basis &p_matrix) const {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (rows[i][j] != p_matrix.rows[i][j]) {
				return false;
			}
		}
	}

	return true;
}

constexpr bool Basis::operator!=(const Basis &p_matrix) const {
	return (!(*this == p_matrix));
}

_FORCE_INLINE_ void Basis::operator*=(const Basis &p_matrix) {
	set(
			p_matrix.tdotx(rows[0]), p_matrix.tdoty(rows[0]), p_matrix.tdotz(rows[0]),
			p_matrix.tdotx(rows[1]), p_matrix.tdoty(rows[1]), p_matrix.tdotz(rows[1]),
			p_matrix.tdotx(rows[2]), p_matrix.tdoty(rows[2]), p_matrix.tdotz(rows[2]));
}

_FORCE_INLINE_ Basis Basis::operator*(const Basis &p_matrix) const {
	return Basis(
			p_matrix.tdotx(rows[0]), p_matrix.tdoty(rows[0]), p_matrix.tdotz(rows[0]),
			p_matrix.tdotx(rows[1]), p_matrix.tdoty(rows[1]), p_matrix.tdotz(rows[1]),
			p_matrix.tdotx(rows[2]), p_matrix.tdoty(rows[2]), p_matrix.tdotz(rows[2]));
}

constexpr void Basis::operator+=(const Basis &p_matrix) {
	rows[0] += p_matrix.rows[0];
	rows[1] += p_matrix.rows[1];
	rows[2] += p_matrix.rows[2];
}

constexpr Basis Basis::operator+(const Basis &p_matrix) const {
	Basis ret(*this);
	ret += p_matrix;
	return ret;
}

constexpr void Basis::operator-=(const Basis &p_matrix) {
	rows[0] -= p_matrix.rows[0];
	rows[1] -= p_matrix.rows[1];
	rows[2] -= p_matrix.rows[2];
}

constexpr Basis Basis::operator-(const Basis &p_matrix) const {
	Basis ret(*this);
	ret -= p_matrix;
	return ret;
}

constexpr void Basis::operator*=(real_t p_val) {
	rows[0] *= p_val;
	rows[1] *= p_val;
	rows[2] *= p_val;
}

constexpr Basis Basis::operator*(real_t p_val) const {
	Basis ret(*this);
	ret *= p_val;
	return ret;
}

constexpr void Basis::operator/=(real_t p_val) {
	rows[0] /= p_val;
	rows[1] /= p_val;
	rows[2] /= p_val;
}

constexpr Basis Basis::operator/(real_t p_val) const {
	Basis ret(*this);
	ret /= p_val;
	return ret;
}

Vector3 Basis::xform(const Vector3 &p_vector) const {
	return Vector3(
			rows[0].dot(p_vector),
			rows[1].dot(p_vector),
			rows[2].dot(p_vector));
}

Vector3 Basis::xform_inv(const Vector3 &p_vector) const {
	return Vector3(
			(rows[0][0] * p_vector.x) + (rows[1][0] * p_vector.y) + (rows[2][0] * p_vector.z),
			(rows[0][1] * p_vector.x) + (rows[1][1] * p_vector.y) + (rows[2][1] * p_vector.z),
			(rows[0][2] * p_vector.x) + (rows[1][2] * p_vector.y) + (rows[2][2] * p_vector.z));
}

real_t Basis::determinant() const {
	return rows[0][0] * (rows[1][1] * rows[2][2] - rows[2][1] * rows[1][2]) -
			rows[1][0] * (rows[0][1] * rows[2][2] - rows[2][1] * rows[0][2]) +
			rows[2][0] * (rows[0][1] * rows[1][2] - rows[1][1] * rows[0][2]);
}

} // namespace godot
