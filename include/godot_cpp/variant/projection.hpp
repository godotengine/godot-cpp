/**************************************************************************/
/*  projection.hpp                                                        */
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
#include <godot_cpp/variant/vector3.hpp>
#include <godot_cpp/variant/vector4.hpp>

namespace godot {

class Array;
struct AABB;
struct Plane;
struct Rect2;
struct Transform3D;
struct Vector2;

/**
 * A 4×4 matrix for 3D projective transformations.
 */
struct [[nodiscard]] Projection {
	enum Planes {
		PLANE_NEAR,
		PLANE_FAR,
		PLANE_LEFT,
		PLANE_TOP,
		PLANE_RIGHT,
		PLANE_BOTTOM
	};

	Vector4 columns[4] = {
		{ 1, 0, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 0, 1 },
	};

	constexpr const Vector4 &operator[](int p_axis) const {
		DEV_ASSERT((unsigned int)p_axis < 4);
		return columns[p_axis];
	}

	constexpr Vector4 &operator[](int p_axis) {
		DEV_ASSERT((unsigned int)p_axis < 4);
		return columns[p_axis];
	}

	/**
	 * Returns a scalar value that is the signed factor by which areas are scaled by this matrix. If the
	 * sign is negative, the matrix flips the orientation of the area. The determinant can be used to
	 * calculate the invertibility of a matrix or solve linear systems of equations involving the matrix,
	 * among other applications.
	 */
	real_t determinant() const;
	void set_identity();
	void set_zero();
	void set_light_bias();
	void set_depth_correction(bool p_flip_y = true, bool p_reverse_z = true, bool p_remap_z = true);

	void set_light_atlas_rect(const Rect2 &p_rect);
	void set_perspective(real_t p_fovy_degrees, real_t p_aspect, real_t p_z_near, real_t p_z_far, bool p_flip_fov = false);
	void set_perspective(real_t p_fovy_degrees, real_t p_aspect, real_t p_z_near, real_t p_z_far, bool p_flip_fov, int p_eye, real_t p_intraocular_dist, real_t p_convergence_dist);
	void set_for_hmd(int p_eye, real_t p_aspect, real_t p_intraocular_dist, real_t p_display_width, real_t p_display_to_lens, real_t p_oversample, real_t p_z_near, real_t p_z_far);
	void set_orthogonal(real_t p_left, real_t p_right, real_t p_bottom, real_t p_top, real_t p_znear, real_t p_zfar);
	void set_orthogonal(real_t p_size, real_t p_aspect, real_t p_znear, real_t p_zfar, bool p_flip_fov = false);
	void set_frustum(real_t p_left, real_t p_right, real_t p_bottom, real_t p_top, real_t p_near, real_t p_far);
	void set_frustum(real_t p_size, real_t p_aspect, Vector2 p_offset, real_t p_near, real_t p_far, bool p_flip_fov = false);
	void adjust_perspective_znear(real_t p_new_znear);

	/**
	 * Creates a new `godot::Projection` that projects positions from a depth range of `-1` to `1` to one
	 * that ranges from `0` to `1`, and flips the projected positions vertically, according to `flip_y`.
	 */
	static Projection create_depth_correction(bool p_flip_y);
	/**
	 * Creates a new `godot::Projection` that projects positions into the given `godot::Rect2`.
	 */
	static Projection create_light_atlas_rect(const Rect2 &p_rect);
	/**
	 * Creates a new `godot::Projection` that projects positions using a perspective projection with the
	 * given Y-axis field of view (in degrees), X:Y aspect ratio, and clipping planes. `flip_fov` determines
	 * whether the projection's field of view is flipped over its diagonal.
	 */
	static Projection create_perspective(real_t p_fovy_degrees, real_t p_aspect, real_t p_z_near, real_t p_z_far, bool p_flip_fov = false);
	/**
	 * Creates a new `godot::Projection` that projects positions using a perspective projection with the
	 * given Y-axis field of view (in degrees), X:Y aspect ratio, and clipping distances.
	 */
	static Projection create_perspective_hmd(real_t p_fovy_degrees, real_t p_aspect, real_t p_z_near, real_t p_z_far, bool p_flip_fov, int p_eye, real_t p_intraocular_dist, real_t p_convergence_dist);
	/**
	 * Creates a new `godot::Projection` for projecting positions onto a head-mounted display with the given
	 * X:Y aspect ratio, distance between eyes, display width, distance to lens, oversampling factor, and
	 * depth clipping planes. `eye` creates the projection for the left eye when set to 1, or the right eye
	 * when set to 2.
	 */
	static Projection create_for_hmd(int p_eye, real_t p_aspect, real_t p_intraocular_dist, real_t p_display_width, real_t p_display_to_lens, real_t p_oversample, real_t p_z_near, real_t p_z_far);
	/**
	 * Creates a new `godot::Projection` that projects positions using an orthogonal projection with the
	 * given clipping planes.
	 */
	static Projection create_orthogonal(real_t p_left, real_t p_right, real_t p_bottom, real_t p_top, real_t p_znear, real_t p_zfar);
	/**
	 * Creates a new `godot::Projection` that projects positions using an orthogonal projection with the
	 * given size, X:Y aspect ratio, and clipping planes. `flip_fov` determines whether the projection's
	 * field of view is flipped over its diagonal.
	 */
	static Projection create_orthogonal_aspect(real_t p_size, real_t p_aspect, real_t p_znear, real_t p_zfar, bool p_flip_fov = false);
	/**
	 * Creates a new `godot::Projection` that projects positions in a frustum with the given clipping
	 * planes.
	 */
	static Projection create_frustum(real_t p_left, real_t p_right, real_t p_bottom, real_t p_top, real_t p_near, real_t p_far);
	/**
	 * Creates a new `godot::Projection` that projects positions in a frustum with the given size, X:Y
	 * aspect ratio, offset, and clipping planes. `flip_fov` determines whether the projection's field of
	 * view is flipped over its diagonal.
	 */
	static Projection create_frustum_aspect(real_t p_size, real_t p_aspect, Vector2 p_offset, real_t p_near, real_t p_far, bool p_flip_fov = false);
	/**
	 * Creates a new `godot::Projection` that scales a given projection to fit around a given `godot::AABB`
	 * in projection space.
	 */
	static Projection create_fit_aabb(const AABB &p_aabb);
	/**
	 * Returns a `godot::Projection` with the near clipping distance adjusted to be `new_znear`. **Note:**
	 * The original `godot::Projection` must be a perspective projection.
	 */
	Projection perspective_znear_adjusted(real_t p_new_znear) const;
	Plane get_projection_plane(Planes p_plane) const;
	/**
	 * Returns a copy of this `godot::Projection` with the signs of the values of the Y column flipped.
	 */
	Projection flipped_y() const;
	/**
	 * Returns a `godot::Projection` with the X and Y values from the given `godot::Vector2` added to the
	 * first and second values of the final column respectively.
	 */
	Projection jitter_offseted(const Vector2 &p_offset) const;

	/**
	 * Returns the vertical field of view of the projection (in degrees) associated with the given
	 * horizontal field of view (in degrees) and aspect ratio. **Note:** Unlike most methods of
	 * `godot::Projection`, `aspect` is expected to be 1 divided by the X:Y aspect ratio.
	 */
	static real_t get_fovy(real_t p_fovx, real_t p_aspect) {
		return Math::rad_to_deg(Math::atan(p_aspect * Math::tan(Math::deg_to_rad(p_fovx) * 0.5)) * 2.0);
	}

	/**
	 * Returns the distance for this `godot::Projection` beyond which positions are clipped.
	 */
	real_t get_z_far() const;
	/**
	 * Returns the distance for this `godot::Projection` before which positions are clipped.
	 */
	real_t get_z_near() const;
	/**
	 * Returns the X:Y aspect ratio of this `godot::Projection`'s viewport.
	 */
	real_t get_aspect() const;
	/**
	 * Returns the horizontal field of view of the projection (in degrees).
	 */
	real_t get_fov() const;
	/**
	 * Returns `true` if this `godot::Projection` performs an orthogonal projection.
	 */
	bool is_orthogonal() const;

	Vector<Plane> get_projection_planes(const Transform3D &p_transform) const;

	bool get_endpoints(const Transform3D &p_transform, Vector3 *p_8points) const;
	/**
	 * Returns the dimensions of the viewport plane that this `godot::Projection` projects positions onto,
	 * divided by two.
	 */
	Vector2 get_viewport_half_extents() const;
	/**
	 * Returns the dimensions of the far clipping plane of the projection, divided by two.
	 */
	Vector2 get_far_plane_half_extents() const;

	void invert();
	/**
	 * Returns a `godot::Projection` that performs the inverse of this `godot::Projection`'s projective
	 * transformation.
	 */
	Projection inverse() const;

	/**
	 * Returns a `godot::Projection` that applies the combined transformations of this `godot::Projection`
	 * and `right`.
	 */
	constexpr Projection operator*(const Projection &p_matrix) const;

	Plane xform4(const Plane &p_vec4) const;
	_FORCE_INLINE_ Vector3 xform(const Vector3 &p_vec3) const;

	Vector4 xform(const Vector4 &p_vec4) const;
	Vector4 xform_inv(const Vector4 &p_vec4) const;

	explicit operator String() const;

	void scale_translate_to_fit(const AABB &p_aabb);
	void add_jitter_offset(const Vector2 &p_offset);
	void make_scale(const Vector3 &p_scale);
	/**
	 * Returns `for_pixel_width` divided by the viewport's width measured in meters on the near plane, after
	 * this `godot::Projection` is applied.
	 */
	int get_pixels_per_meter(int p_for_pixel_width) const;
	operator Transform3D() const;

	void flip_y();

	bool is_same(const Projection &p_cam) const;

	/**
	 * Tests exact equality of the components.
	 */
	constexpr bool operator==(const Projection &p_cam) const {
		for (uint32_t i = 0; i < 4; i++) {
			for (uint32_t j = 0; j < 4; j++) {
				if (columns[i][j] != p_cam.columns[i][j]) {
					return false;
				}
			}
		}
		return true;
	}

	/**
	 * Tests whether any component differs.
	 */
	constexpr bool operator!=(const Projection &p_cam) const {
		return !(*this == p_cam);
	}

	/**
	 * Returns the factor by which the visible level of detail is scaled by this `godot::Projection`.
	 */
	real_t get_lod_multiplier() const;

	Projection() = default;
	/**
	 * Constructs a Projection from four `godot::Vector4` values (matrix columns).
	 */
	constexpr Projection(const Vector4 &p_x, const Vector4 &p_y, const Vector4 &p_z, const Vector4 &p_w) :
			columns{ p_x, p_y, p_z, p_w } {}
	constexpr Projection(real_t p_xx, real_t p_xy, real_t p_xz, real_t p_xw, real_t p_yx, real_t p_yy, real_t p_yz, real_t p_yw, real_t p_zx, real_t p_zy, real_t p_zz, real_t p_zw, real_t p_wx, real_t p_wy, real_t p_wz, real_t p_ww) :
			columns{
				{ p_xx, p_xy, p_xz, p_xw },
				{ p_yx, p_yy, p_yz, p_yw },
				{ p_zx, p_zy, p_zz, p_zw },
				{ p_wx, p_wy, p_wz, p_ww },
			} {}
	/**
	 * Constructs a Projection as a copy of the given `godot::Transform3D`.
	 */
	Projection(const Transform3D &p_transform);
};

constexpr Projection Projection::operator*(const Projection &p_matrix) const {
	Projection new_matrix;

	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 4; i++) {
			real_t ab = 0;
			for (int k = 0; k < 4; k++) {
				ab += columns[k][i] * p_matrix.columns[j][k];
			}
			new_matrix.columns[j][i] = ab;
		}
	}

	return new_matrix;
}

Vector3 Projection::xform(const Vector3 &p_vec3) const {
	Vector3 ret;
	ret.x = columns[0][0] * p_vec3.x + columns[1][0] * p_vec3.y + columns[2][0] * p_vec3.z + columns[3][0];
	ret.y = columns[0][1] * p_vec3.x + columns[1][1] * p_vec3.y + columns[2][1] * p_vec3.z + columns[3][1];
	ret.z = columns[0][2] * p_vec3.x + columns[1][2] * p_vec3.y + columns[2][2] * p_vec3.z + columns[3][2];
	real_t w = columns[0][3] * p_vec3.x + columns[1][3] * p_vec3.y + columns[2][3] * p_vec3.z + columns[3][3];
	return ret / w;
}

} // namespace godot
