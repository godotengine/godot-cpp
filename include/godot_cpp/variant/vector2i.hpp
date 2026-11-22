/**************************************************************************/
/*  vector2i.hpp                                                          */
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
struct Vector2;

/**
 * A pair of signed 32-bit components for integer positions, offsets, and extents in two dimensions. The caller supplies the coordinate space.
 *
 * ```cpp
 * Point2i cursor_px(53, 34);
 * const Size2i tile_px(16, 16);
 * Point2i hovered_cell = cursor_px / tile_px;
 * ```
 */
struct [[nodiscard]] Vector2i {
	/**
	 * A unit step along negative X.
	 *
	 * ```cpp
	 * Point2i player_cell(5, 4);
	 * Point2i candidate = player_cell + Vector2i::LEFT;
	 * bool inside_map = Rect2i(0, 0, 12, 8).has_point(candidate);
	 * ```
	 */
	static const Vector2i LEFT;
	/**
	 * A unit step along positive X.
	 *
	 * ```cpp
	 * Point2i player_cell(5, 4);
	 * Point2i candidate = player_cell + Vector2i::RIGHT;
	 * bool inside_map = Rect2i(0, 0, 12, 8).has_point(candidate);
	 * ```
	 */
	static const Vector2i RIGHT;
	/**
	 * A unit step along negative Y.
	 *
	 * ```cpp
	 * Point2i player_cell(5, 4);
	 * Point2i candidate = player_cell + Vector2i::UP;
	 * bool inside_map = Rect2i(0, 0, 12, 8).has_point(candidate);
	 * ```
	 */
	static const Vector2i UP;
	/**
	 * A unit step along positive Y.
	 *
	 * ```cpp
	 * Point2i player_cell(5, 4);
	 * Point2i candidate = player_cell + Vector2i::DOWN;
	 * bool inside_map = Rect2i(0, 0, 12, 8).has_point(candidate);
	 * ```
	 */
	static const Vector2i DOWN;

	/**
	 * The number of components addressable by the indexed operators.
	 *
	 * ```cpp
	 * Vector2i cell(3, 8), map_size(12, 8);
	 * bool in_bounds = true;
	 * for (int axis = 0; axis < Vector2i::AXIS_COUNT; ++axis) {
	 *     in_bounds &= cell[axis] >= 0 && cell[axis] < map_size[axis];
	 * }
	 * ```
	 */
	static constexpr int AXIS_COUNT = 2;

	/**
	 * Selects one of the two components for indexed access. Axis query methods return these indices.
	 *
	 * ```cpp
	 * Size2i minimap(128, 64);
	 * Vector2i::Axis long_axis = minimap.max_axis_index();
	 * int pixels_to_scan = minimap[long_axis];
	 * ```
	 */
	enum Axis {
		/**
		 * Selects the first component, which also holds the width when used as a size.
		 *
		 * ```cpp
		 * Point2i cell(3, 2);
		 * const int cells_per_row = 12;
		 * int offset = cell.y * cells_per_row + cell[Vector2i::AXIS_X];
		 * ```
		 */
		AXIS_X,
		/**
		 * Selects the second component, which also holds the height when used as a size.
		 *
		 * ```cpp
		 * Point2i cell(3, 2);
		 * const int tile_height = 16;
		 * int top_pixel = cell[Vector2i::AXIS_Y] * tile_height;
		 * ```
		 */
		AXIS_Y,
	};

	/**
	 * Shares storage between the X component and its width alias.
	 *
	 * ```cpp
	 * Size2i image(320, 180);
	 * int row_bytes = image.width * 4; // RGBA8.
	 * ```
	 */
	union {
		/**
		 * The signed component along the first axis.
		 *
		 * ```cpp
		 * Point2i player_cell(2, 3);
		 * const int input_dx = -1;
		 * player_cell.x += input_dx;
		 * ```
		 */
		int32_t x = 0;
		/**
		 * An alias for the first component when the vector describes a width and height.
		 *
		 * ```cpp
		 * Size2i image(320, 180);
		 * const int bytes_per_pixel = 4;
		 * int row_bytes = image.width * bytes_per_pixel;
		 * ```
		 */
		int32_t width;
	};
	/**
	 * Shares storage between the Y component and its height alias.
	 *
	 * ```cpp
	 * Size2i image(320, 180);
	 * int row_count = image.height; // Rows in the upload.
	 * ```
	 */
	union {
		/**
		 * The signed component along the second axis.
		 *
		 * ```cpp
		 * Point2i cell(3, 2);
		 * const int cells_per_row = 12;
		 * int flat_index = cell.y * cells_per_row + cell.x;
		 * ```
		 */
		int32_t y = 0;
		/**
		 * An alias for the second component when the vector describes a width and height.
		 *
		 * ```cpp
		 * Size2i image(320, 180);
		 * const int row_bytes = 320 * 4;
		 * int buffer_bytes = row_bytes * image.height;
		 * ```
		 */
		int32_t height;
	};

	/**
	 * Returns a writable reference to the selected component.
	 *
	 * - `p_axis` — `AXIS_X` or `AXIS_Y`.
	 *
	 * ```cpp
	 * Point2i cell(4, 3);
	 * Vector2i::Axis drag_axis = Vector2i::AXIS_Y;
	 * const int drag_cells = 2;
	 * cell[drag_axis] += drag_cells;
	 * ```
	 */
	constexpr int32_t &operator[](int p_axis) {
		// The pointer math below assumes that the elements are placed back-to-back, like an array.
		// This is always true in practice, but technically not guaranteed; we safety-check it here.
		static_assert(offsetof(Vector2i, x) == 0 * sizeof(int32_t));
		static_assert(offsetof(Vector2i, width) == 0 * sizeof(int32_t));
		static_assert(offsetof(Vector2i, y) == 1 * sizeof(int32_t));
		static_assert(offsetof(Vector2i, height) == 1 * sizeof(int32_t));
		static_assert(sizeof(Vector2i) == 2 * sizeof(int32_t));

		DEV_ASSERT((unsigned int)p_axis < 2);
		return (&x)[p_axis];
	}
	/**
	 * Returns a const reference to the selected component.
	 *
	 * - `p_axis` — `AXIS_X` or `AXIS_Y`.
	 *
	 * ```cpp
	 * const Size2i region(12, 8);
	 * Vector2i::Axis slicing_axis = Vector2i::AXIS_X;
	 * int columns_to_process = region[slicing_axis];
	 * ```
	 */
	constexpr const int32_t &operator[](int p_axis) const {
		DEV_ASSERT((unsigned int)p_axis < 2);
		return (&x)[p_axis];
	}

	/**
	 * Returns the index of the component with the lower signed value. Ties select Y.
	 *
	 * ```cpp
	 * Size2i free_space(12, 7);
	 * int square_tile_limit = free_space[free_space.min_axis_index()];
	 * ```
	 */
	_FORCE_INLINE_ Vector2i::Axis min_axis_index() const {
		return x < y ? Vector2i::AXIS_X : Vector2i::AXIS_Y;
	}

	/**
	 * Returns the index of the component with the higher signed value. Ties select X.
	 *
	 * ```cpp
	 * Vector2i drag_cells(5, 2); // Positive drag from a selection handle.
	 * Vector2i::Axis lock_axis = drag_cells.max_axis_index();
	 * drag_cells[lock_axis == Vector2i::AXIS_X ? Vector2i::AXIS_Y : Vector2i::AXIS_X] = 0;
	 * ```
	 */
	_FORCE_INLINE_ Vector2i::Axis max_axis_index() const {
		return x < y ? Vector2i::AXIS_Y : Vector2i::AXIS_X;
	}

	/**
	 * Returns the lower signed value from each pair of corresponding components.
	 *
	 * - `p_vector2i` — Vector that supplies the other X and Y values.
	 *
	 * ```cpp
	 * Point2i drag_start(7, 2), drag_end(3, 8);
	 * Point2i selection_origin = drag_start.min(drag_end);
	 * ```
	 */
	Vector2i min(const Vector2i &p_vector2i) const {
		return Vector2i(MIN(x, p_vector2i.x), MIN(y, p_vector2i.y));
	}

	/**
	 * Caps each component at the same upper limit.
	 *
	 * - `p_scalar` — Value compared with every component.
	 *
	 * ```cpp
	 * Size2i requested_grid(120, 40);
	 * const int max_axis_cells = 64;
	 * Size2i capped_grid = requested_grid.mini(max_axis_cells);
	 * ```
	 */
	Vector2i mini(int32_t p_scalar) const {
		return Vector2i(MIN(x, p_scalar), MIN(y, p_scalar));
	}

	/**
	 * Returns the higher signed value from each pair of corresponding components.
	 *
	 * - `p_vector2i` — Vector that supplies the other X and Y values.
	 *
	 * ```cpp
	 * Point2i drag_start(7, 2), drag_end(3, 8);
	 * Point2i far_corner = drag_start.max(drag_end);
	 * ```
	 */
	Vector2i max(const Vector2i &p_vector2i) const {
		return Vector2i(MAX(x, p_vector2i.x), MAX(y, p_vector2i.y));
	}

	/**
	 * Raises each component to the same lower limit when it falls below that limit.
	 *
	 * - `p_scalar` — Value compared with every component.
	 *
	 * ```cpp
	 * Size2i layout_size(0, 32);
	 * Size2i texture_size = layout_size.maxi(1); // Both dimensions must be positive.
	 * ```
	 */
	Vector2i maxi(int32_t p_scalar) const {
		return Vector2i(MAX(x, p_scalar), MAX(y, p_scalar));
	}

	/**
	 * Returns the Euclidean distance between the points in their shared coordinate space.
	 *
	 * - `p_to` — Other point in the same coordinate system.
	 *
	 * ```cpp
	 * Point2i guard_cell(2, 3), target_cell(5, 7);
	 * const double sight_range_in_cells = 6;
	 * bool in_range = guard_cell.distance_to(target_cell) <= sight_range_in_cells;
	 * ```
	 */
	double distance_to(const Vector2i &p_to) const {
		return (p_to - *this).length();
	}

	/**
	 * Returns the squared Euclidean distance between the points in square coordinate units.
	 *
	 * - `p_to` — Other point in the same coordinate system.
	 *
	 * ```cpp
	 * Point2i cursor_cell(2, 3), handle_cell(5, 7);
	 * const int pick_radius = 6;
	 * bool pick = cursor_cell.distance_squared_to(handle_cell) <= pick_radius * pick_radius;
	 * ```
	 */
	int64_t distance_squared_to(const Vector2i &p_to) const {
		return (p_to - *this).length_squared();
	}

	/**
	 * Returns the component-wise sum of two vectors.
	 *
	 * - `p_v` — Vector whose components are added.
	 *
	 * ```cpp
	 * Point2i pivot(3, 5);
	 * Vector2i local_cell(2, -1);
	 * Point2i map_cell = pivot + local_cell;
	 * ```
	 */
	constexpr Vector2i operator+(const Vector2i &p_v) const;
	/**
	 * Adds the other vector's components to this vector in place.
	 *
	 * - `p_v` — Vector whose components are added in place.
	 *
	 * ```cpp
	 * Point2i canvas_position(8, 9);
	 * Vector2i drag_delta_pixels(3, -2);
	 * canvas_position += drag_delta_pixels;
	 * ```
	 */
	constexpr void operator+=(const Vector2i &p_v);
	/**
	 * Subtracts the right vector's components from the left vector and returns the difference.
	 *
	 * - `p_v` — Vector whose components are subtracted.
	 *
	 * ```cpp
	 * Point2i sprite_pixel(18, 11), atlas_origin(16, 8);
	 * Point2i sprite_local_pixel = sprite_pixel - atlas_origin;
	 * ```
	 */
	constexpr Vector2i operator-(const Vector2i &p_v) const;
	/**
	 * Subtracts the other vector's components from this vector in place.
	 *
	 * - `p_v` — Vector whose components are subtracted in place.
	 *
	 * ```cpp
	 * Point2i cursor_on_canvas(18, 11);
	 * const Vector2i viewport_offset(16, 8);
	 * cursor_on_canvas -= viewport_offset; // Now in viewport pixels.
	 * ```
	 */
	constexpr void operator-=(const Vector2i &p_v);
	/**
	 * Multiplies corresponding components of the two vectors.
	 *
	 * - `p_v1` — Vector that supplies a factor for each component.
	 *
	 * ```cpp
	 * Point2i sprite_cell(3, 2);
	 * Size2i tile_pixels(16, 24);
	 * Point2i source_origin = sprite_cell * tile_pixels;
	 * ```
	 */
	constexpr Vector2i operator*(const Vector2i &p_v1) const;

	/**
	 * Multiplies both components by the same integer and returns the result.
	 *
	 * - `p_rvalue` — Factor applied to every component.
	 *
	 * ```cpp
	 * Vector2i step(1, -1);
	 * const int repeat_count = 4;
	 * Point2i destination = Point2i(4, 6) + step * repeat_count;
	 * ```
	 */
	constexpr Vector2i operator*(int32_t p_rvalue) const;
	/**
	 * Multiplies both components by the integer in place.
	 *
	 * - `p_rvalue` — Factor applied to every component.
	 *
	 * ```cpp
	 * Size2i icon(12, 16);
	 * const int integer_scale = 3;
	 * icon *= integer_scale; // Scaled preview size.
	 * ```
	 */
	constexpr void operator*=(int32_t p_rvalue);

	/**
	 * Divides each component by the corresponding nonzero component. Quotients truncate toward zero.
	 *
	 * - `p_v1` — Vector that supplies a nonzero divisor for each component.
	 *
	 * ```cpp
	 * Point2i canvas_pixel(55, 31);
	 * Size2i tile_pixels(16, 8);
	 * Point2i tile_index = canvas_pixel / tile_pixels;
	 * ```
	 */
	constexpr Vector2i operator/(const Vector2i &p_v1) const;
	/**
	 * Divides both components by the same nonzero integer and returns the truncated quotients.
	 *
	 * - `p_rvalue` — Nonzero divisor applied to every component.
	 *
	 * ```cpp
	 * Size2i viewport(640, 360);
	 * const int downsample = 2;
	 * Size2i buffer_size = viewport / downsample;
	 * ```
	 */
	constexpr Vector2i operator/(int32_t p_rvalue) const;
	/**
	 * Replaces both components with their truncated quotients by the same nonzero integer.
	 *
	 * - `p_rvalue` — Nonzero divisor applied to every component.
	 *
	 * ```cpp
	 * Size2i mip_level(64, 32);
	 * const int next_mip_scale = 2;
	 * mip_level /= next_mip_scale;
	 * ```
	 */
	constexpr void operator/=(int32_t p_rvalue);

	/**
	 * Returns the signed remainder of each component divided by the corresponding nonzero component.
	 *
	 * - `p_v1` — Vector that supplies a nonzero divisor for each component.
	 *
	 * ```cpp
	 * Point2i texture_pixel(54, 29);
	 * Size2i tile_pixels(16, 8);
	 * Point2i pixel_within_tile = texture_pixel % tile_pixels;
	 * ```
	 */
	constexpr Vector2i operator%(const Vector2i &p_v1) const;
	/**
	 * Returns both signed remainders using the same nonzero divisor.
	 *
	 * - `p_rvalue` — Nonzero divisor applied to every component.
	 *
	 * ```cpp
	 * Point2i absolute_cell(39, 22);
	 * const int chunk_side = 16;
	 * Point2i cell_within_chunk = absolute_cell % chunk_side;
	 * ```
	 */
	constexpr Vector2i operator%(int32_t p_rvalue) const;
	/**
	 * Replaces both components with their signed remainders using the same nonzero divisor.
	 *
	 * - `p_rvalue` — Nonzero divisor applied to every component.
	 *
	 * ```cpp
	 * Point2i local_cell(16, 3); // One step past the right edge.
	 * const int board_side = 16;
	 * local_cell %= board_side; // Wrap X back to the first column.
	 * ```
	 */
	constexpr void operator%=(int32_t p_rvalue);

	/**
	 * Returns the vector pointing in the opposite direction by negating each component.
	 *
	 * ```cpp
	 * Vector2i last_drag_delta(3, -2);
	 * Vector2i undo_delta = -last_drag_delta;
	 * ```
	 */
	constexpr Vector2i operator-() const;
	/**
	 * Orders vectors by increasing X, then by increasing Y when X is equal.
	 *
	 * - `p_vec2` — Right-hand vector in the comparison.
	 *
	 * ```cpp
	 * Point2i a(2, 3), b(2, 4);
	 * Point2i first_in_column_order = a < b ? a : b;
	 * ```
	 */
	constexpr bool operator<(const Vector2i &p_vec2) const { return (x == p_vec2.x) ? (y < p_vec2.y) : (x < p_vec2.x); }
	/**
	 * Orders vectors by decreasing X, then by decreasing Y when X is equal.
	 *
	 * - `p_vec2` — Right-hand vector in the comparison.
	 *
	 * ```cpp
	 * Point2i a(3, 0), b(2, 9);
	 * Point2i last_in_column_order = a > b ? a : b;
	 * ```
	 */
	constexpr bool operator>(const Vector2i &p_vec2) const { return (x == p_vec2.x) ? (y > p_vec2.y) : (x > p_vec2.x); }

	/**
	 * Tests whether this vector is lexicographically less than or equal to the other, comparing X before Y.
	 *
	 * - `p_vec2` — Right-hand vector in the comparison.
	 *
	 * ```cpp
	 * Point2i first_dirty(2, 3), last_dirty(2, 4);
	 * bool scan_interval_is_ordered = first_dirty <= last_dirty; // X then Y.
	 * ```
	 */
	constexpr bool operator<=(const Vector2i &p_vec2) const { return x == p_vec2.x ? (y <= p_vec2.y) : (x < p_vec2.x); }
	/**
	 * Tests whether this vector is lexicographically greater than or equal to the other, comparing X before Y.
	 *
	 * - `p_vec2` — Right-hand vector in the comparison.
	 *
	 * ```cpp
	 * Point2i scan_cell(2, 4), final_cell(2, 3);
	 * bool finished_column_order_scan = scan_cell >= final_cell;
	 * ```
	 */
	constexpr bool operator>=(const Vector2i &p_vec2) const { return x == p_vec2.x ? (y >= p_vec2.y) : (x > p_vec2.x); }

	/**
	 * Tests exact equality of the two X and Y components.
	 *
	 * - `p_vec2` — Right-hand vector in the comparison.
	 *
	 * ```cpp
	 * Point2i player_cell(2, 3), exit_cell(2, 3);
	 * bool reached_exit = player_cell == exit_cell;
	 * ```
	 */
	constexpr bool operator==(const Vector2i &p_vec2) const;
	/**
	 * Tests whether either component differs.
	 *
	 * - `p_vec2` — Right-hand vector in the comparison.
	 *
	 * ```cpp
	 * Point2i last_hovered(2, 3), current_hovered(2, 4);
	 * bool update_highlight = current_hovered != last_hovered;
	 * ```
	 */
	constexpr bool operator!=(const Vector2i &p_vec2) const;

	/**
	 * Returns the sum of the squared components using 64-bit products.
	 *
	 * ```cpp
	 * Vector2i drag_delta(3, 4); // Pixels relative to the press position.
	 * const int threshold = 4;
	 * bool start_drag = drag_delta.length_squared() >= threshold * threshold;
	 * ```
	 */
	int64_t length_squared() const;
	/**
	 * Returns the Euclidean magnitude as a floating-point value.
	 *
	 * ```cpp
	 * Vector2i ruler_delta(3, 4); // Displacement in image pixels.
	 * const double millimeters_per_pixel = 0.25;
	 * double measured_mm = ruler_delta.length() * millimeters_per_pixel;
	 * ```
	 */
	double length() const;

	/**
	 * Divides the width by the height in floating-point arithmetic to give the aspect ratio.
	 *
	 * ```cpp
	 * Size2i source(1920, 1080);
	 * const int preview_height = 180;
	 * int preview_width = int(preview_height * source.aspect());
	 * ```
	 */
	real_t aspect() const { return width / (real_t)height; }
	/**
	 * Replaces each component with -1, 0, or 1 according to its sign.
	 *
	 * ```cpp
	 * Point2i npc(7, 2), target(3, 2);
	 * Vector2i one_cell_step = (target - npc).sign();
	 * npc += one_cell_step;
	 * ```
	 */
	Vector2i sign() const { return Vector2i(SIGN(x), SIGN(y)); }
	/**
	 * Returns the component-wise absolute values.
	 *
	 * ```cpp
	 * Point2i drag_start(12, 3), drag_end(8, 10);
	 * Size2i drag_dimensions = (drag_end - drag_start).abs();
	 * ```
	 */
	Vector2i abs() const { return Vector2i(Math::abs(x), Math::abs(y)); }
	/**
	 * Clamps each component to the inclusive interval between that axis's minimum and maximum.
	 *
	 * - `p_min` — Inclusive lower bounds for X and Y.
	 * - `p_max` — Inclusive upper bounds for X and Y.
	 *
	 * ```cpp
	 * Point2i cursor_cell(-2, 9);
	 * const Size2i map_size(4, 6);
	 * Point2i nearest_valid_cell = cursor_cell.clamp(Point2i(), map_size - Size2i(1, 1));
	 * ```
	 */
	Vector2i clamp(const Vector2i &p_min, const Vector2i &p_max) const;
	/**
	 * Clamps both components using the same inclusive lower and upper limits.
	 *
	 * - `p_min` — Inclusive lower bound used for every component.
	 * - `p_max` — Inclusive upper bound used for every component.
	 *
	 * ```cpp
	 * Vector2i scroll_cells(-2, 9);
	 * const int max_scroll_cells = 5;
	 * Vector2i visible_offset = scroll_cells.clampi(0, max_scroll_cells);
	 * ```
	 */
	Vector2i clampi(int32_t p_min, int32_t p_max) const;
	/**
	 * Rounds each component to a multiple of its own step. A zero step preserves the corresponding component.
	 *
	 * - `p_step` — Grid spacing for each component. A zero spacing leaves that component unchanged.
	 *
	 * ```cpp
	 * Point2i dragged_anchor(7, 13); // Canvas pixels.
	 * const Size2i grid_spacing(4, 5);
	 * Point2i snapped_anchor = dragged_anchor.snapped(grid_spacing);
	 * ```
	 */
	Vector2i snapped(const Vector2i &p_step) const;
	/**
	 * Rounds both components to multiples of the same step. A zero step preserves both components.
	 *
	 * - `p_step` — Grid spacing used for every component. Zero leaves the vector unchanged.
	 *
	 * ```cpp
	 * Point2i cursor_on_canvas(7, 13);
	 * const int grid_spacing_px = 4;
	 * Point2i brush_anchor = cursor_on_canvas.snappedi(grid_spacing_px);
	 * ```
	 */
	Vector2i snappedi(int32_t p_step) const;

	/**
	 * Formats the two components as a parenthesized, comma-separated pair. Requires initialized Godot bindings.
	 *
	 * ```cpp
	 * Point2i rejected_cell(24, 3);
	 * print_error("Brush outside the map at ", static_cast<String>(rejected_cell));
	 * ```
	 */
	explicit operator String() const;
	/**
	 * Converts the two integer components to `real_t`. Large integers can lose precision in a single-precision build.
	 *
	 * ```cpp
	 * Point2i cell_on_canvas(2, 3);
	 * Vector2 preview_position = cell_on_canvas;
	 * preview_position += Vector2(0.5, 0.5); // Center of this pixel.
	 * ```
	 */
	operator Vector2() const;

	/**
	 * Creates a vector with both components zero.
	 *
	 * ```cpp
	 * Vector2i pan_offset; // Start with no pixel displacement.
	 * const Vector2i mouse_delta(2, 3);
	 * pan_offset += mouse_delta;
	 * ```
	 */
	constexpr Vector2i() = default;
	/**
	 * Stores the given signed integer in each component.
	 *
	 * - `p_x` — X component.
	 * - `p_y` — Y component.
	 *
	 * ```cpp
	 * constexpr int columns = 32, rows = 18;
	 * constexpr Vector2i map_size(columns, rows);
	 * static_assert(map_size.x * map_size.y == 576);
	 * ```
	 */
	constexpr Vector2i(int32_t p_x, int32_t p_y) :
			x(p_x), y(p_y) {}
};

inline constexpr Vector2i Vector2i::LEFT = { -1, 0 };
inline constexpr Vector2i Vector2i::RIGHT = { 1, 0 };
inline constexpr Vector2i Vector2i::UP = { 0, -1 };
inline constexpr Vector2i Vector2i::DOWN = { 0, 1 };

constexpr Vector2i Vector2i::operator+(const Vector2i &p_v) const {
	return Vector2i(x + p_v.x, y + p_v.y);
}

constexpr void Vector2i::operator+=(const Vector2i &p_v) {
	x += p_v.x;
	y += p_v.y;
}

constexpr Vector2i Vector2i::operator-(const Vector2i &p_v) const {
	return Vector2i(x - p_v.x, y - p_v.y);
}

constexpr void Vector2i::operator-=(const Vector2i &p_v) {
	x -= p_v.x;
	y -= p_v.y;
}

constexpr Vector2i Vector2i::operator*(const Vector2i &p_v1) const {
	return Vector2i(x * p_v1.x, y * p_v1.y);
}

constexpr Vector2i Vector2i::operator*(int32_t p_rvalue) const {
	return Vector2i(x * p_rvalue, y * p_rvalue);
}

constexpr void Vector2i::operator*=(int32_t p_rvalue) {
	x *= p_rvalue;
	y *= p_rvalue;
}

constexpr Vector2i Vector2i::operator/(const Vector2i &p_v1) const {
	return Vector2i(Math::division_no_overflow(x, p_v1.x), Math::division_no_overflow(y, p_v1.y));
}

constexpr Vector2i Vector2i::operator/(int32_t p_rvalue) const {
	return Vector2i(Math::division_no_overflow(x, p_rvalue), Math::division_no_overflow(y, p_rvalue));
}

constexpr void Vector2i::operator/=(int32_t p_rvalue) {
	x = Math::division_no_overflow(x, p_rvalue);
	y = Math::division_no_overflow(y, p_rvalue);
}

constexpr Vector2i Vector2i::operator%(const Vector2i &p_v1) const {
	return Vector2i(Math::modulo_no_overflow(x, p_v1.x), Math::modulo_no_overflow(y, p_v1.y));
}

constexpr Vector2i Vector2i::operator%(int32_t p_rvalue) const {
	return Vector2i(Math::modulo_no_overflow(x, p_rvalue), Math::modulo_no_overflow(y, p_rvalue));
}

constexpr void Vector2i::operator%=(int32_t p_rvalue) {
	x = Math::modulo_no_overflow(x, p_rvalue);
	y = Math::modulo_no_overflow(y, p_rvalue);
}

constexpr Vector2i Vector2i::operator-() const {
	return Vector2i(-x, -y);
}

constexpr bool Vector2i::operator==(const Vector2i &p_vec2) const {
	return x == p_vec2.x && y == p_vec2.y;
}

constexpr bool Vector2i::operator!=(const Vector2i &p_vec2) const {
	return x != p_vec2.x || y != p_vec2.y;
}

// Multiplication operators required to workaround issues with LLVM using implicit conversion.

/**
 * Multiplies both vector components by the integer supplied on the left.
 *
 * - `p_scalar` — Left-hand factor applied to every component.
 * - `p_vector` — Vector whose components are multiplied.
 *
 * ```cpp
 * const int32_t scale = 3;
 * const Size2i base_icon(2, 4);
 * Size2i integer_preview = scale * base_icon;
 * ```
 */
constexpr Vector2i operator*(int32_t p_scalar, const Vector2i &p_vector) {
	return p_vector * p_scalar;
}

/**
 * Converts the left 64-bit integer to the 32-bit integer used by the vector's multiplication operator.
 *
 * - `p_scalar` — Left-hand factor converted to a 32-bit integer before multiplication.
 * - `p_vector` — Vector whose components are multiplied.
 *
 * ```cpp
 * const int64_t scale = 3; // Imported integer scale.
 * const Size2i base_icon(2, 4);
 * Size2i integer_preview = scale * base_icon;
 * ```
 */
constexpr Vector2i operator*(int64_t p_scalar, const Vector2i &p_vector) {
	return p_vector * p_scalar;
}

/**
 * Converts the left floating-point factor to the 32-bit integer used by the vector's multiplication operator. Fractional parts truncate toward zero.
 *
 * - `p_scalar` — Left-hand factor converted to a 32-bit integer before multiplication.
 * - `p_vector` — Vector whose components are multiplied.
 *
 * ```cpp
 * const float scale = 3.5f;
 * const Size2i base_icon(2, 4);
 * Size2i integer_preview = scale * base_icon; // Factor truncates to 3.
 * ```
 */
constexpr Vector2i operator*(float p_scalar, const Vector2i &p_vector) {
	return p_vector * p_scalar;
}

/**
 * Converts the left floating-point factor to the 32-bit integer used by the vector's multiplication operator. Fractional parts truncate toward zero.
 *
 * - `p_scalar` — Left-hand factor converted to a 32-bit integer before multiplication.
 * - `p_vector` — Vector whose components are multiplied.
 *
 * ```cpp
 * const double scale = 3.5;
 * const Size2i base_icon(2, 4);
 * Size2i integer_preview = scale * base_icon; // Factor truncates to 3.
 * ```
 */
constexpr Vector2i operator*(double p_scalar, const Vector2i &p_vector) {
	return p_vector * p_scalar;
}

/**
 * Names a vector used to store an integer width and height.
 *
 * ```cpp
 * const Size2i viewport_size(320, 180);
 * Size2i render_target_size = viewport_size / 2; // Half-resolution preview.
 * ```
 */
typedef Vector2i Size2i;
/**
 * Names a vector used as an integer position in a 2D coordinate space.
 *
 * ```cpp
 * const Point2i sprite_cell(2, 3);
 * const Size2i tile_pixels(16, 16);
 * Point2i atlas_offset = sprite_cell * tile_pixels;
 * ```
 */
typedef Vector2i Point2i;

/**
 * Allows array placement to zero-initialize storage for vectors. Both components then have their default value.
 *
 * ```cpp
 * static_assert(is_zero_constructible_v<Vector2i>);
 * ```
 */
template <>
struct is_zero_constructible<Vector2i> : std::true_type {};
} // namespace godot
