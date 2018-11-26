#ifndef BASIS_H
#define BASIS_H

#include "Defs.hpp"

#include "Vector3.hpp"

namespace godot {

class Quat;

class Basis {
public:
	union {
		Vector3 elements[3];
		Vector3 x, y, z;
	};

	Basis(const Quat &p_quat); // euler
	Basis(const Vector3 &p_euler); // euler
	Basis(const Vector3 &p_axis, real_t p_phi);

	Basis(const Vector3 &row0, const Vector3 &row1, const Vector3 &row2);

	Basis(real_t xx, real_t xy, real_t xz, real_t yx, real_t yy, real_t yz, real_t zx, real_t zy, real_t zz);

	Basis();

	const Vector3 &operator[](int axis) const;
	Vector3 &operator[](int axis);

	void invert();

	bool isequal_approx(const Basis &a, const Basis &b) const;

	bool is_orthogonal() const;

	bool is_rotation() const;

	void transpose();

	Basis inverse() const;

	Basis transposed() const;

	real_t determinant() const;

	Vector3 get_axis(int p_axis) const;

	void set_axis(int p_axis, const Vector3 &p_value);

	void rotate(const Vector3 &p_axis, real_t p_phi);

	Basis rotated(const Vector3 &p_axis, real_t p_phi) const;

	void scale(const Vector3 &p_scale);

	Basis scaled(const Vector3 &p_scale) const;

	Vector3 get_scale() const;

	Vector3 get_euler_xyz() const;
	void set_euler_xyz(const Vector3 &p_euler);
	Vector3 get_euler_yxz() const;
	void set_euler_yxz(const Vector3 &p_euler);

	inline Vector3 get_euler() const { return get_euler_yxz(); }
	inline void set_euler(const Vector3 &p_euler) { set_euler_yxz(p_euler); }

	// transposed dot products
	real_t tdotx(const Vector3 &v) const;
	real_t tdoty(const Vector3 &v) const;
	real_t tdotz(const Vector3 &v) const;

	bool operator==(const Basis &p_matrix) const;

	bool operator!=(const Basis &p_matrix) const;

	Vector3 xform(const Vector3 &p_vector) const;

	Vector3 xform_inv(const Vector3 &p_vector) const;
	void operator*=(const Basis &p_matrix);

	Basis operator*(const Basis &p_matrix) const;

	void operator+=(const Basis &p_matrix);

	Basis operator+(const Basis &p_matrix) const;

	void operator-=(const Basis &p_matrix);

	Basis operator-(const Basis &p_matrix) const;

	void operator*=(real_t p_val);

	Basis operator*(real_t p_val) const;

	int get_orthogonal_index() const; // down below

	void set_orthogonal_index(int p_index); // down below

	operator String() const;

	void get_axis_and_angle(Vector3 &r_axis, real_t &r_angle) const;

	/* create / set */

	void set(real_t xx, real_t xy, real_t xz, real_t yx, real_t yy, real_t yz, real_t zx, real_t zy, real_t zz);

	Vector3 get_column(int i) const;

	Vector3 get_row(int i) const;
	Vector3 get_main_diagonal() const;

	void set_row(int i, const Vector3 &p_row);

	Basis transpose_xform(const Basis &m) const;

	void orthonormalize();

	Basis orthonormalized() const;

	bool is_symmetric() const;

	Basis diagonalize();

	operator Quat() const;
};

} // namespace godot

#endif // BASIS_H
