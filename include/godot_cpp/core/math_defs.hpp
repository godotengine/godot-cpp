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
/**
 * The square root of two.
 *
 * ```cpp
 * const double tile_side_px = 16;
 * double diagonal_step_px = tile_side_px * Math::SQRT2;
 * ```
 */
inline constexpr double SQRT2 = 1.4142135623730950488016887242;
/**
 * The square root of three.
 *
 * ```cpp
 * const double hex_side_px = 24;
 * double pointy_hex_width_px = hex_side_px * Math::SQRT3;
 * ```
 */
inline constexpr double SQRT3 = 1.7320508075688772935274463415059;
/**
 * The square root of one half.
 *
 * ```cpp
 * const real_t speed = 120;
 * Vector2 diagonal_velocity = Vector2(Math::SQRT12, -Math::SQRT12) * speed;
 * ```
 */
inline constexpr double SQRT12 = 0.7071067811865475244008443621048490;
/**
 * The square root of one third.
 *
 * ```cpp
 * const real_t diagonal = Math::SQRT13;
 * Vector3 isometric_view_direction(diagonal, -diagonal, diagonal);
 * ```
 */
inline constexpr double SQRT13 = 0.57735026918962576450914878050196;
/**
 * The natural logarithm of two.
 *
 * ```cpp
 * const double half_life_seconds = 0.25, frame_seconds = 0.016;
 * double opacity = Math::exp(-frame_seconds * Math::LN2 / half_life_seconds);
 * ```
 */
inline constexpr double LN2 = 0.6931471805599453094172321215;
/**
 * The angle in radians of one full turn.
 *
 * ```cpp
 * const int blade_index = 2, blade_count = 6;
 * real_t blade_angle = Math::TAU * blade_index / blade_count;
 * ```
 */
inline constexpr double TAU = 6.2831853071795864769252867666;
/**
 * The ratio of a circle's circumference to its diameter. It also gives the angle in radians of half a turn.
 *
 * ```cpp
 * const double degrees = 135;
 * real_t wheel_rotation = degrees * Math::PI / 180.0;
 * ```
 */
inline constexpr double PI = 3.1415926535897932384626433833;
/**
 * The base of the natural logarithm.
 *
 * ```cpp
 * const double duration = 2.0, growth_rate = 0.4;
 * double emission_multiplier = Math::pow(Math::E, growth_rate * duration);
 * ```
 */
inline constexpr double E = 2.7182818284590452353602874714;
/**
 * The positive infinity value of type `double`.
 *
 * ```cpp
 * const double sample_distances[] = { 12.0, 7.0, 18.0 };
 * double nearest = Math::INF;
 * for (double distance : sample_distances) { if (distance < nearest) { nearest = distance; } }
 * ```
 */
inline constexpr double INF = std::numeric_limits<double>::infinity();
/**
 * A quiet NaN value of type `double`.
 *
 * ```cpp
 * const bool probe_hit = false;
 * double measured_depth = probe_hit ? 3.5 : Math::NaN; // A miss gives no depth.
 * ```
 */
inline constexpr double NaN = std::numeric_limits<double>::quiet_NaN();
} // namespace Math

/**
 * The base tolerance for approximate comparisons, including the minimum absolute tolerance in `Math::is_equal_approx()`.
 *
 * ```cpp
 * const real_t fade_delta = 0.000004;
 * bool stop_updating_opacity = Math::abs(fade_delta) < CMP_EPSILON;
 * ```
 */
inline constexpr double CMP_EPSILON = 0.00001;
/**
 * The square of `CMP_EPSILON`, for comparisons against squared magnitudes.
 *
 * ```cpp
 * Vector2 old_anchor(0, 0), new_anchor(0.000004, 0);
 * bool rebuild_mesh = old_anchor.distance_squared_to(new_anchor) >= CMP_EPSILON2;
 * ```
 */
inline constexpr double CMP_EPSILON2 = CMP_EPSILON * CMP_EPSILON;

/**
 * An absolute tolerance of 0.000001 for normalization checks.
 *
 * ```cpp
 * Vector3 imported_normal(0, 0.9995, 0);
 * if (Math::abs(imported_normal.length() - 1) > CMP_NORMALIZE_TOLERANCE) { imported_normal.normalize(); }
 * ```
 */
inline constexpr double CMP_NORMALIZE_TOLERANCE = 0.000001;
/**
 * A distance tolerance of 0.00001 for testing whether a point lies in a plane.
 *
 * ```cpp
 * Plane floor(Vector3(0, 1, 0), 0);
 * Vector3 seam_vertex(2, 0.000002, 4);
 * bool belongs_to_floor = Math::abs(floor.distance_to(seam_vertex)) <= CMP_POINT_IN_PLANE_EPSILON;
 * ```
 */
inline constexpr double CMP_POINT_IN_PLANE_EPSILON = 0.00001;

#ifdef DEBUG_ENABLED
/**
 * Enables diagnostic branches in math operations for debug builds.
 *
 * ```cpp
 * // In a function validating a rectangle passed by the caller.
 * #ifdef MATH_CHECKS
 * ERR_FAIL_COND_MSG(bounds.size.x < 0, "Negative width for a texture update region.");
 * #endif
 * ```
 */
#define MATH_CHECKS
#endif

//this epsilon is for values related to a unit size (scalar or vector len)
#ifdef PRECISE_MATH_CHECKS
/**
 * The tighter tolerance for unit-size comparisons when `PRECISE_MATH_CHECKS` is defined.
 *
 * ```cpp
 * Vector3 decoded_direction(0.999998, 0, 0);
 * bool keep = Math::is_equal_approx(decoded_direction.length_squared(), real_t(1), real_t(UNIT_EPSILON));
 * ```
 */
inline constexpr double UNIT_EPSILON = 0.00001;
#else
//tolerate some more floating point error normally
/**
 * The default tolerance for unit-size comparisons, including squared length tests for normalized vectors.
 *
 * ```cpp
 * Vector3 decoded_direction(0.9998, 0, 0);
 * if (!Math::is_equal_approx(decoded_direction.length_squared(), real_t(1), real_t(UNIT_EPSILON))) {
 *     decoded_direction.normalize();
 * }
 * ```
 */
inline constexpr double UNIT_EPSILON = 0.001;
#endif

/**
 * Converts a duration from microseconds to seconds using floating-point division.
 *
 * ```cpp
 * const uint64_t begin_us = 1050000, end_us = 1300000; // Timer readings.
 * double duration_seconds = USEC_TO_SEC(end_us - begin_us);
 * ```
 */
#define USEC_TO_SEC(m_usec) ((m_usec) / 1000000.0)

#ifdef REAL_T_IS_DOUBLE
/**
 * The double-precision scalar type used by vector components and other Godot math types when `REAL_T_IS_DOUBLE` is defined.
 *
 * ```cpp
 * const real_t yaw = real_t(Math::PI / 4);
 * Vector3 view_axis(Math::cos(yaw), 0, Math::sin(yaw));
 * ```
 */
typedef double real_t;
#else
/**
 * The single-precision scalar type used by vector components and other Godot math types in the default build.
 *
 * ```cpp
 * const real_t half_width = 2.5;
 * Vector3 local_edge(half_width, 0, 0);
 * ```
 */
typedef float real_t;
#endif
} // namespace godot
