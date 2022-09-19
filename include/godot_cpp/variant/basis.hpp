/*************************************************************************/
/*  basis.hpp                                                            */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2022 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2022 Godot Engine contributors (cf. AUTHORS.md).   */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#ifndef GODOT_BASIS_HPP
#define GODOT_BASIS_HPP

#include <godot_cpp/core/math.hpp>
#include <godot_cpp/variant/quaternion.hpp>
#include <godot_cpp/variant/vector3.hpp>

namespace godot {

class Basis {
	_FORCE_INLINE_ GDNativeTypePtr _native_ptr() const { return (void *)this; }

	friend class Variant;

public:
	Vector3 rows[3] = {
		Vector3(1, 0, 0),
		Vector3(0, 1, 0),
		Vector3(0, 0, 1)
	};

	inline const Vector3 &operator[](int axis) const {
		return rows[axis];
	}
	inline Vector3 &operator[](int axis) {
		return rows[axis];
	}

	void invert();
	void transpose();

	Basis inverse() const;
	Basis transposed() const;

	inline real_t determinant() const;

	void from_z(const Vector3 &p_z);

	inline Vector3 get_axis(int p_axis) const {
		// get actual basis axis (rows is transposed for performance)
		return Vector3(rows[0][p_axis], rows[1][p_axis], rows[2][p_axis]);
	}
	inline void set_axis(int p_axis, const Vector3 &p_value) {
		// get actual basis axis (rows is transposed for performance)
		rows[0][p_axis] = p_value.x;
		rows[1][p_axis] = p_value.y;
		rows[2][p_axis] = p_value.z;
	}

	void rotate(const Vector3 &p_axis, real_t p_phi);
	Basis rotated(const Vector3 &p_axis, real_t p_phi) const;

	void rotate_local(const Vector3 &p_axis, real_t p_phi);
	Basis rotated_local(const Vector3 &p_axis, real_t p_phi) const;

	void rotate(const Vector3 &p_euler);
	Basis rotated(const Vector3 &p_euler) const;

	void rotate(const Quaternion &p_quat);
	Basis rotated(const Quaternion &p_quat) const;

	Vector3 get_rotation_euler() const;
	void get_rotation_axis_angle(Vector3 &p_axis, real_t &p_angle) const;
	void get_rotation_axis_angle_local(Vector3 &p_axis, real_t &p_angle) const;
	Quaternion get_rotation_quaternion() const;
	Vector3 get_rotation() const { return get_rotation_euler(); };

	Vector3 rotref_posscale_decomposition(Basis &rotref) const;

	Vector3 get_euler_xyz() const;
	void set_euler_xyz(const Vector3 &p_euler);

	Vector3 get_euler_xzy() const;
	void set_euler_xzy(const Vector3 &p_euler);

	Vector3 get_euler_yzx() const;
	void set_euler_yzx(const Vector3 &p_euler);

	Vector3 get_euler_yxz() const;
	void set_euler_yxz(const Vector3 &p_euler);

	Vector3 get_euler_zxy() const;
	void set_euler_zxy(const Vector3 &p_euler);

	Vector3 get_euler_zyx() const;
	void set_euler_zyx(const Vector3 &p_euler);

	Quaternion get_quaternion() const;
	void set_quaternion(const Quaternion &p_quat);

	Vector3 get_euler() const { return get_euler_yxz(); }
	void set_euler(const Vector3 &p_euler) { set_euler_yxz(p_euler); }

	void get_axis_angle(Vector3 &r_axis, real_t &r_angle) const;
	void set_axis_angle(const Vector3 &p_axis, real_t p_phi);

	void scale(const Vector3 &p_scale);
	Basis scaled(const Vector3 &p_scale) const;

	void scale_local(const Vector3 &p_scale);
	Basis scaled_local(const Vector3 &p_scale) const;

	void make_scale_uniform();
	float get_uniform_scale() const;

	Vector3 get_scale() const;
	Vector3 get_scale_abs() const;
	Vector3 get_scale_local() const;

	void set_axis_angle_scale(const Vector3 &p_axis, real_t p_phi, const Vector3 &p_scale);
	void set_euler_scale(const Vector3 &p_euler, const Vector3 &p_scale);
	void set_quaternion_scale(const Quaternion &p_quat, const Vector3 &p_scale);

	// transposed dot products
	inline real_t tdotx(const Vector3 &v) const {
		return rows[0][0] * v[0] + rows[1][0] * v[1] + rows[2][0] * v[2];
	}
	inline real_t tdoty(const Vector3 &v) const {
		return rows[0][1] * v[0] + rows[1][1] * v[1] + rows[2][1] * v[2];
	}
	inline real_t tdotz(const Vector3 &v) const {
		return rows[0][2] * v[0] + rows[1][2] * v[1] + rows[2][2] * v[2];
	}

	bool is_equal_approx(const Basis &p_basis) const;

	bool operator==(const Basis &p_matrix) const;
	bool operator!=(const Basis &p_matrix) const;

	inline Vector3 xform(const Vector3 &p_vector) const;
	inline Vector3 xform_inv(const Vector3 &p_vector) const;
	inline void operator*=(const Basis &p_matrix);
	inline Basis operator*(const Basis &p_matrix) const;
	inline void operator+=(const Basis &p_matrix);
	inline Basis operator+(const Basis &p_matrix) const;
	inline void operator-=(const Basis &p_matrix);
	inline Basis operator-(const Basis &p_matrix) const;
	inline void operator*=(real_t p_val);
	inline Basis operator*(real_t p_val) const;

	int get_orthogonal_index() const;
	void set_orthogonal_index(int p_index);

	void set_diagonal(const Vector3 &p_diag);

	bool is_orthogonal() const;
	bool is_diagonal() const;
	bool is_rotation() const;

	Basis slerp(const Basis &p_to, const real_t &p_weight) const;
	void rotate_sh(real_t *p_values);

	operator String() const;

	/* create / set */

	inline void set(real_t xx, real_t xy, real_t xz, real_t yx, real_t yy, real_t yz, real_t zx, real_t zy, real_t zz) {
		rows[0][0] = xx;
		rows[0][1] = xy;
		rows[0][2] = xz;
		rows[1][0] = yx;
		rows[1][1] = yy;
		rows[1][2] = yz;
		rows[2][0] = zx;
		rows[2][1] = zy;
		rows[2][2] = zz;
	}
	inline void set(const Vector3 &p_x, const Vector3 &p_y, const Vector3 &p_z) {
		set_axis(0, p_x);
		set_axis(1, p_y);
		set_axis(2, p_z);
	}
	inline Vector3 get_column(int i) const {
		return Vector3(rows[0][i], rows[1][i], rows[2][i]);
	}

	inline Vector3 get_row(int i) const {
		return Vector3(rows[i][0], rows[i][1], rows[i][2]);
	}
	inline Vector3 get_main_diagonal() const {
		return Vector3(rows[0][0], rows[1][1], rows[2][2]);
	}

	inline void set_row(int i, const Vector3 &p_row) {
		rows[i][0] = p_row.x;
		rows[i][1] = p_row.y;
		rows[i][2] = p_row.z;
	}

	inline void set_zero() {
		rows[0].zero();
		rows[1].zero();
		rows[2].zero();
	}

	inline Basis transpose_xform(const Basis &m) const {
		return Basis(
				rows[0].x * m[0].x + rows[1].x * m[1].x + rows[2].x * m[2].x,
				rows[0].x * m[0].y + rows[1].x * m[1].y + rows[2].x * m[2].y,
				rows[0].x * m[0].z + rows[1].x * m[1].z + rows[2].x * m[2].z,
				rows[0].y * m[0].x + rows[1].y * m[1].x + rows[2].y * m[2].x,
				rows[0].y * m[0].y + rows[1].y * m[1].y + rows[2].y * m[2].y,
				rows[0].y * m[0].z + rows[1].y * m[1].z + rows[2].y * m[2].z,
				rows[0].z * m[0].x + rows[1].z * m[1].x + rows[2].z * m[2].x,
				rows[0].z * m[0].y + rows[1].z * m[1].y + rows[2].z * m[2].y,
				rows[0].z * m[0].z + rows[1].z * m[1].z + rows[2].z * m[2].z);
	}
	Basis(real_t xx, real_t xy, real_t xz, real_t yx, real_t yy, real_t yz, real_t zx, real_t zy, real_t zz) {
		set(xx, xy, xz, yx, yy, yz, zx, zy, zz);
	}

	void orthonormalize();
	Basis orthonormalized() const;

#ifdef MATH_CHECKS
	bool is_symmetric() const;
#endif
	Basis diagonalize();

	operator Quaternion() const { return get_quaternion(); }

	Basis(const Quaternion &p_quat) { set_quaternion(p_quat); };
	Basis(const Quaternion &p_quat, const Vector3 &p_scale) { set_quaternion_scale(p_quat, p_scale); }

	Basis(const Vector3 &p_euler) { set_euler(p_euler); }
	Basis(const Vector3 &p_euler, const Vector3 &p_scale) { set_euler_scale(p_euler, p_scale); }

	Basis(const Vector3 &p_axis, real_t p_phi) { set_axis_angle(p_axis, p_phi); }
	Basis(const Vector3 &p_axis, real_t p_phi, const Vector3 &p_scale) { set_axis_angle_scale(p_axis, p_phi, p_scale); }

	inline Basis(const Vector3 &p_x, const Vector3 &p_y, const Vector3 &p_z) {
		set_axis(0, p_x);
		set_axis(1, p_y);
		set_axis(2, p_z);
	}

	inline Basis() {}
};

inline void Basis::operator*=(const Basis &p_matrix) {
	set(
			p_matrix.tdotx(rows[0]), p_matrix.tdoty(rows[0]), p_matrix.tdotz(rows[0]),
			p_matrix.tdotx(rows[1]), p_matrix.tdoty(rows[1]), p_matrix.tdotz(rows[1]),
			p_matrix.tdotx(rows[2]), p_matrix.tdoty(rows[2]), p_matrix.tdotz(rows[2]));
}

inline Basis Basis::operator*(const Basis &p_matrix) const {
	return Basis(
			p_matrix.tdotx(rows[0]), p_matrix.tdoty(rows[0]), p_matrix.tdotz(rows[0]),
			p_matrix.tdotx(rows[1]), p_matrix.tdoty(rows[1]), p_matrix.tdotz(rows[1]),
			p_matrix.tdotx(rows[2]), p_matrix.tdoty(rows[2]), p_matrix.tdotz(rows[2]));
}

inline void Basis::operator+=(const Basis &p_matrix) {
	rows[0] += p_matrix.rows[0];
	rows[1] += p_matrix.rows[1];
	rows[2] += p_matrix.rows[2];
}

inline Basis Basis::operator+(const Basis &p_matrix) const {
	Basis ret(*this);
	ret += p_matrix;
	return ret;
}

inline void Basis::operator-=(const Basis &p_matrix) {
	rows[0] -= p_matrix.rows[0];
	rows[1] -= p_matrix.rows[1];
	rows[2] -= p_matrix.rows[2];
}

inline Basis Basis::operator-(const Basis &p_matrix) const {
	Basis ret(*this);
	ret -= p_matrix;
	return ret;
}

inline void Basis::operator*=(real_t p_val) {
	rows[0] *= p_val;
	rows[1] *= p_val;
	rows[2] *= p_val;
}

inline Basis Basis::operator*(real_t p_val) const {
	Basis ret(*this);
	ret *= p_val;
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

#endif // GODOT_BASIS_HPP
