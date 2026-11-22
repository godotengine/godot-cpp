/**************************************************************************/
/*  color.hpp                                                             */
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

namespace godot {

class String;

/**
 * A color represented in RGBA format.
 */
struct [[nodiscard]] Color {
	/**
	 * The color's red component, typically on the range of 0 to 1.
	 */
	float r = 0.0f;
	/**
	 * The color's green component, typically on the range of 0 to 1.
	 */
	float g = 0.0f;
	/**
	 * The color's blue component, typically on the range of 0 to 1.
	 */
	float b = 0.0f;
	/**
	 * The color's alpha component, typically on the range of 0 to 1.
	 */
	float a = 1.0f;

	/**
	 * Returns the color converted to a 32-bit integer in RGBA format (each component is 8 bits). RGBA is
	 * Godot's default format. This method is the inverse of `godot::Color::hex()`.
	 */
	uint32_t to_rgba32() const;
	/**
	 * Returns the color converted to a 32-bit integer in ARGB format (each component is 8 bits). ARGB is
	 * more compatible with DirectX.
	 */
	uint32_t to_argb32() const;
	/**
	 * Returns the color converted to a 32-bit integer in ABGR format (each component is 8 bits). ABGR is
	 * the reversed version of the default RGBA format.
	 */
	uint32_t to_abgr32() const;
	/**
	 * Returns the color converted to a 64-bit integer in RGBA format (each component is 16 bits). RGBA is
	 * Godot's default format. This method is the inverse of `godot::Color::hex64()`.
	 */
	uint64_t to_rgba64() const;
	/**
	 * Returns the color converted to a 64-bit integer in ARGB format (each component is 16 bits). ARGB is
	 * more compatible with DirectX.
	 */
	uint64_t to_argb64() const;
	/**
	 * Returns the color converted to a 64-bit integer in ABGR format (each component is 16 bits). ABGR is
	 * the reversed version of the default RGBA format.
	 */
	uint64_t to_abgr64() const;
	/**
	 * Formats the color as RGB or RGBA hexadecimal digits without a leading hash sign.
	 *
	 * - `p_alpha` — Whether to include alpha after the RGB digits.
	 */
	String to_html(bool p_alpha = true) const;
	/**
	 * Returns the HSV hue as a fraction of a full turn. An achromatic color has hue zero.
	 */
	float get_h() const;
	/**
	 * Returns the HSV saturation as the RGB range divided by the largest channel. Returns zero when the largest channel is zero.
	 */
	float get_s() const;
	/**
	 * Returns the largest RGB channel as the HSV value.
	 */
	float get_v() const;
	/**
	 * Sets the RGB channels from hue, saturation, and value, and sets the alpha channel.
	 *
	 * - `p_h` — Hue as a fraction of a full turn. Zero and one are red.
	 * - `p_s` — Saturation. Zero produces a gray value.
	 * - `p_v` — Value of the brightest RGB component.
	 * - `p_alpha` — Opacity. Zero is transparent and one is opaque.
	 */
	void set_hsv(float p_h, float p_s, float p_v, float p_alpha = 1.0f);

	/**
	 * Returns a writable reference to the selected color channel.
	 *
	 * - `p_idx` — Zero-based index in red, green, blue, alpha order. Use a value from zero through three.
	 */
	constexpr float &operator[](int p_idx) {
		// The pointer math below assumes that the elements are placed back-to-back, like an array.
		// This is always true in practice, but technically not guaranteed; we safety-check it here.
		static_assert(offsetof(Color, r) == 0 * sizeof(float));
		static_assert(offsetof(Color, g) == 1 * sizeof(float));
		static_assert(offsetof(Color, b) == 2 * sizeof(float));
		static_assert(offsetof(Color, a) == 3 * sizeof(float));
		static_assert(sizeof(Color) == 4 * sizeof(float));

		DEV_ASSERT((unsigned int)p_idx < 4);
		return (&r)[p_idx];
	}
	/**
	 * Returns a read-only reference to the selected color channel.
	 *
	 * - `p_idx` — Zero-based index in red, green, blue, alpha order. Use a value from zero through three.
	 */
	constexpr const float &operator[](int p_idx) const {
		DEV_ASSERT((unsigned int)p_idx < 4);
		return (&r)[p_idx];
	}

	/**
	 * Returns the address of the first of four contiguous float channels in RGBA order.
	 */
	constexpr const float *as_float4_buffer() const { return &r; }

	/**
	 * Tests exact equality of the components.
	 *
	 * - `p_color` — Other color whose channels are compared with this color.
	 */
	constexpr bool operator==(const Color &p_color) const {
		return (r == p_color.r && g == p_color.g && b == p_color.b && a == p_color.a);
	}
	/**
	 * Tests whether any component differs.
	 *
	 * - `p_color` — Other color whose channels are compared with this color.
	 */
	constexpr bool operator!=(const Color &p_color) const {
		return (r != p_color.r || g != p_color.g || b != p_color.b || a != p_color.a);
	}

	/**
	 * Adds each RGBA channel using the supplied color.
	 *
	 * - `p_color` — Color whose corresponding channels are added.
	 */
	constexpr Color operator+(const Color &p_color) const;
	/**
	 * Adds each RGBA channel in place using the supplied color.
	 *
	 * - `p_color` — Color whose corresponding channels are added.
	 */
	constexpr void operator+=(const Color &p_color);

	/**
	 * Subtracts all four channels from one, including alpha.
	 */
	constexpr Color operator-() const;
	/**
	 * Subtracts each RGBA channel using the supplied color.
	 *
	 * - `p_color` — Color whose corresponding channels are subtracted.
	 */
	constexpr Color operator-(const Color &p_color) const;
	/**
	 * Subtracts each RGBA channel in place using the supplied color.
	 *
	 * - `p_color` — Color whose corresponding channels are subtracted.
	 */
	constexpr void operator-=(const Color &p_color);

	/**
	 * Multiplies each RGBA channel using the supplied color.
	 *
	 * - `p_color` — Color that supplies each channel's factor.
	 */
	constexpr Color operator*(const Color &p_color) const;
	/**
	 * Multiplies each RGBA channel using the supplied scalar.
	 *
	 * - `p_scalar` — Factor applied to all four channels.
	 */
	constexpr Color operator*(float p_scalar) const;
	/**
	 * Multiplies each RGBA channel in place using the supplied color.
	 *
	 * - `p_color` — Color that supplies each channel's factor.
	 */
	constexpr void operator*=(const Color &p_color);
	/**
	 * Multiplies each RGBA channel in place using the supplied scalar.
	 *
	 * - `p_scalar` — Factor applied to all four channels.
	 */
	constexpr void operator*=(float p_scalar);

	/**
	 * Divides each RGBA channel by its corresponding divisor.
	 *
	 * - `p_color` — Color that supplies each channel's divisor.
	 */
	constexpr Color operator/(const Color &p_color) const;
	/**
	 * Divides each RGBA channel by its corresponding divisor.
	 *
	 * - `p_scalar` — Divisor used for all four channels.
	 */
	constexpr Color operator/(float p_scalar) const;
	/**
	 * Divides each RGBA channel by its corresponding divisor in place.
	 *
	 * - `p_color` — Color that supplies each channel's divisor.
	 */
	constexpr void operator/=(const Color &p_color);
	/**
	 * Divides each RGBA channel by its corresponding divisor in place.
	 *
	 * - `p_scalar` — Divisor used for all four channels.
	 */
	constexpr void operator/=(float p_scalar);

	/**
	 * Returns `true` if this color and `to` are approximately equal, by running `is_equal_approx()` on each
	 * component.
	 *
	 * - `p_color` — Other color whose channels are compared with this color.
	 */
	bool is_equal_approx(const Color &p_color) const;
	/**
	 * Tests exact channel equality and treats matching NaN channels as equal.
	 *
	 * - `p_color` — Other color whose channels are compared with this color.
	 */
	bool is_same(const Color &p_color) const;

	/**
	 * Restricts each channel to the supplied bounds.
	 *
	 * - `p_min` — Inclusive lower bound for each RGBA channel.
	 * - `p_max` — Inclusive upper bound for each RGBA channel.
	 */
	Color clamp(const Color &p_min = Color(0, 0, 0, 0), const Color &p_max = Color(1, 1, 1, 1)) const;
	/**
	 * Replaces each RGB channel with one minus its value. Leaves alpha unchanged.
	 */
	void invert();
	/**
	 * Returns the color with its `r`, `g`, and `b` components inverted (`(1 - r, 1 - g, 1 - b, a)`).
	 */
	Color inverted() const;

	/**
	 * Returns weighted luminance from RGB. Values outside the usual channel range can yield luminance outside zero to one.
	 */
	_FORCE_INLINE_ float get_luminance() const {
		return 0.2126f * r + 0.7152f * g + 0.0722f * b;
	}

	/**
	 * Interpolates all four channels linearly.
	 *
	 * - `p_to` — Color reached at weight one.
	 * - `p_weight` — Interpolation factor. Zero uses this color and one uses the target.
	 */
	_FORCE_INLINE_ Color lerp(const Color &p_to, float p_weight) const {
		Color res = *this;
		res.r = Math::lerp(res.r, p_to.r, p_weight);
		res.g = Math::lerp(res.g, p_to.g, p_weight);
		res.b = Math::lerp(res.b, p_to.b, p_weight);
		res.a = Math::lerp(res.a, p_to.a, p_weight);
		return res;
	}

	/**
	 * Moves the RGB channels toward zero. Leaves alpha unchanged.
	 *
	 * - `p_amount` — Fraction of the distance toward black. Zero leaves RGB unchanged and one makes RGB zero.
	 */
	_FORCE_INLINE_ Color darkened(float p_amount) const {
		Color res = *this;
		res.r = res.r * (1.0f - p_amount);
		res.g = res.g * (1.0f - p_amount);
		res.b = res.b * (1.0f - p_amount);
		return res;
	}

	/**
	 * Moves the RGB channels toward one. Leaves alpha unchanged.
	 *
	 * - `p_amount` — Fraction of the distance toward white. Zero leaves RGB unchanged and one makes RGB one.
	 */
	_FORCE_INLINE_ Color lightened(float p_amount) const {
		Color res = *this;
		res.r = res.r + (1.0f - res.r) * p_amount;
		res.g = res.g + (1.0f - res.g) * p_amount;
		res.b = res.b + (1.0f - res.b) * p_amount;
		return res;
	}

	/**
	 * Packs RGB into three 9-bit fields with a shared 5-bit exponent. Does not include alpha.
	 */
	_FORCE_INLINE_ uint32_t to_rgbe9995() const {
		// https://github.com/microsoft/DirectX-Graphics-Samples/blob/v10.0.19041.0/MiniEngine/Core/Color.cpp
		static const float kMaxVal = float(0x1FF << 7);
		static const float kMinVal = float(1.f / (1 << 16));

		// Clamp RGB to [0, 1.FF*2^16]
		const float _r = CLAMP(r, 0.0f, kMaxVal);
		const float _g = CLAMP(g, 0.0f, kMaxVal);
		const float _b = CLAMP(b, 0.0f, kMaxVal);

		// Compute the maximum channel, no less than 1.0*2^-15
		const float MaxChannel = MAX(MAX(_r, _g), MAX(_b, kMinVal));

		// Take the exponent of the maximum channel (rounding up the 9th bit) and
		// add 15 to it.  When added to the channels, it causes the implicit '1.0'
		// bit and the first 8 mantissa bits to be shifted down to the low 9 bits
		// of the mantissa, rounding the truncated bits.
		union {
			float f;
			uint32_t i;
		} R, G, B, E;

		E.f = MaxChannel;
		E.i += 0x07804000; // Add 15 to the exponent and 0x4000 to the mantissa
		E.i &= 0x7F800000; // Zero the mantissa

		// This shifts the 9-bit values we need into the lowest bits, rounding as
		// needed. Note that if the channel has a smaller exponent than the max
		// channel, it will shift even more.  This is intentional.
		R.f = _r + E.f;
		G.f = _g + E.f;
		B.f = _b + E.f;

		// Convert the Bias to the correct exponent in the upper 5 bits.
		E.i <<= 4;
		E.i += 0x10000000;

		// Combine the fields. RGB floats have unwanted data in the upper 9
		// bits. Only red needs to mask them off because green and blue shift
		// it out to the left.
		return E.i | (B.i << 18U) | (G.i << 9U) | (R.i & 511U);
	}

	/**
	 * Composites the supplied color over this color using alpha, returning the new RGB and alpha.
	 *
	 * - `p_over` — Foreground color, including the alpha used to blend it over this color.
	 */
	_FORCE_INLINE_ Color blend(const Color &p_over) const {
		Color res;
		float sa = 1.0f - p_over.a;
		res.a = a * sa + p_over.a;
		if (res.a == 0) {
			return Color(0, 0, 0, 0);
		} else {
			res.r = (r * a * sa + p_over.r * p_over.a) / res.a;
			res.g = (g * a * sa + p_over.g * p_over.a) / res.a;
			res.b = (b * a * sa + p_over.b * p_over.a) / res.a;
		}
		return res;
	}

	/**
	 * Converts the RGB channels from sRGB to linear RGB. Copies alpha unchanged.
	 */
	_FORCE_INLINE_ Color srgb_to_linear() const {
		return Color(
				r < 0.04045f ? r * (1.0f / 12.92f) : Math::pow(float((r + 0.055) * (1.0 / (1.0 + 0.055))), 2.4f),
				g < 0.04045f ? g * (1.0f / 12.92f) : Math::pow(float((g + 0.055) * (1.0 / (1.0 + 0.055))), 2.4f),
				b < 0.04045f ? b * (1.0f / 12.92f) : Math::pow(float((b + 0.055) * (1.0 / (1.0 + 0.055))), 2.4f),
				a);
	}
	/**
	 * Converts the RGB channels from linear RGB to sRGB. Copies alpha unchanged.
	 */
	_FORCE_INLINE_ Color linear_to_srgb() const {
		return Color(
				r < 0.0031308f ? 12.92f * r : (1.0 + 0.055) * Math::pow(r, 1.0f / 2.4f) - 0.055,
				g < 0.0031308f ? 12.92f * g : (1.0 + 0.055) * Math::pow(g, 1.0f / 2.4f) - 0.055,
				b < 0.0031308f ? 12.92f * b : (1.0 + 0.055) * Math::pow(b, 1.0f / 2.4f) - 0.055, a);
	}

	/**
	 * Reads four 8-bit channels from an RGBA integer and scales each to zero through one.
	 *
	 * - `p_hex` — Packed RGBA value with red in the highest byte and alpha in the lowest byte.
	 */
	static Color hex(uint32_t p_hex);
	/**
	 * Reads four 16-bit channels from an RGBA integer and scales each to zero through one.
	 *
	 * - `p_hex` — Packed RGBA value with red in the highest 16 bits and alpha in the lowest 16 bits.
	 */
	static Color hex64(uint64_t p_hex);
	/**
	 * Parses an HTML hexadecimal color. Missing alpha gives an opaque color. An empty or invalid string gives opaque black.
	 *
	 * - `p_rgba` — Three or six RGB digits, or four or eight RGBA digits. A leading hash sign is optional.
	 */
	static Color html(const String &p_rgba);
	/**
	 * Checks whether the string is a supported RGB or RGBA hexadecimal color.
	 *
	 * - `p_color` — String to check, with an optional leading hash sign.
	 */
	static bool html_is_valid(const String &p_color);
	/**
	 * Returns the named color. An unknown name reports an error and returns opaque black.
	 *
	 * - `p_name` — Named color to look up, ignoring case, spaces, hyphens, underscores, apostrophes, and periods.
	 */
	static Color named(const String &p_name);
	/**
	 * Returns the named color or the supplied fallback when the name is unknown.
	 *
	 * - `p_name` — Named color to look up, ignoring case, spaces, hyphens, underscores, apostrophes, and periods.
	 * - `p_default` — Color returned if the input does not identify a supported color.
	 */
	static Color named(const String &p_name, const Color &p_default);
	/**
	 * Returns the named color's table index, or minus one when the name is unknown.
	 *
	 * - `p_name` — Named color to look up, ignoring case, spaces, hyphens, underscores, apostrophes, and periods.
	 */
	static int find_named_color(const String &p_name);
	/**
	 * Returns the number of entries in the named color table.
	 */
	static int get_named_color_count();
	/**
	 * Returns the name at the table index. An invalid index reports an error and returns an empty string.
	 *
	 * - `p_idx` — Zero-based index less than the named color count.
	 */
	static String get_named_color_name(int p_idx);
	/**
	 * Returns the color at the table index. An invalid index reports an error and returns opaque black.
	 *
	 * - `p_idx` — Zero-based index less than the named color count.
	 */
	static Color get_named_color(int p_idx);
	/**
	 * Parses a hexadecimal color or looks up a named color. Returns the supplied fallback if neither applies.
	 *
	 * - `p_string` — Hexadecimal color string or named color.
	 * - `p_default` — Color returned if the input does not identify a supported color.
	 */
	static Color from_string(const String &p_string, const Color &p_default);
	/**
	 * Returns the RGB color for the supplied HSV values, with the supplied alpha.
	 *
	 * - `p_h` — Hue as a fraction of a full turn. Zero and one are red.
	 * - `p_s` — Saturation. Zero produces a gray value.
	 * - `p_v` — Value of the brightest RGB component.
	 * - `p_alpha` — Opacity. Zero is transparent and one is opaque.
	 */
	static Color from_hsv(float p_h, float p_s, float p_v, float p_alpha = 1.0f);
	/**
	 * Decodes a `godot::Color` from an RGBE9995 format integer. See `godot::Image::FORMAT_RGBE9995`.
	 *
	 * - `p_rgbe` — Packed RGB value with a 5-bit shared exponent above the three 9-bit channel fields.
	 */
	static Color from_rgbe9995(uint32_t p_rgbe);
	/**
	 * Converts the supplied integer channels to floats by dividing each by 255. Does not clamp the input.
	 *
	 * - `p_r8` — Red multiplied by one over 255.
	 * - `p_g8` — Green multiplied by one over 255.
	 * - `p_b8` — Blue multiplied by one over 255.
	 * - `p_a8` — Alpha multiplied by one over 255.
	 */
	static Color from_rgba8(int64_t p_r8, int64_t p_g8, int64_t p_b8, int64_t p_a8 = 255);

	/**
	 * Compares red first, then green, blue, and alpha to break ties.
	 *
	 * - `p_color` — Right-hand color in the comparison.
	 */
	constexpr bool operator<(const Color &p_color) const; // Used in set keys.
	/**
	 * Formats the four RGBA channels as a parenthesized, comma-separated string.
	 */
	explicit operator String() const;

	// For the binder.
	/**
	 * Sets red from an 8-bit channel value.
	 *
	 * - `p_r8` — Input clamped to zero through 255, then divided by 255.
	 */
	_FORCE_INLINE_ void set_r8(int32_t p_r8) { r = (CLAMP(p_r8, 0, 255) / 255.0f); }
	/**
	 * Returns red converted to the nearest 8-bit value and clamped to zero through 255.
	 */
	_FORCE_INLINE_ int32_t get_r8() const { return int32_t(CLAMP(Math::round(r * 255.0f), 0.0f, 255.0f)); }
	/**
	 * Sets green from an 8-bit channel value.
	 *
	 * - `p_g8` — Input clamped to zero through 255, then divided by 255.
	 */
	_FORCE_INLINE_ void set_g8(int32_t p_g8) { g = (CLAMP(p_g8, 0, 255) / 255.0f); }
	/**
	 * Returns green converted to the nearest 8-bit value and clamped to zero through 255.
	 */
	_FORCE_INLINE_ int32_t get_g8() const { return int32_t(CLAMP(Math::round(g * 255.0f), 0.0f, 255.0f)); }
	/**
	 * Sets blue from an 8-bit channel value.
	 *
	 * - `p_b8` — Input clamped to zero through 255, then divided by 255.
	 */
	_FORCE_INLINE_ void set_b8(int32_t p_b8) { b = (CLAMP(p_b8, 0, 255) / 255.0f); }
	/**
	 * Returns blue converted to the nearest 8-bit value and clamped to zero through 255.
	 */
	_FORCE_INLINE_ int32_t get_b8() const { return int32_t(CLAMP(Math::round(b * 255.0f), 0.0f, 255.0f)); }
	/**
	 * Sets alpha from an 8-bit channel value.
	 *
	 * - `p_a8` — Input clamped to zero through 255, then divided by 255.
	 */
	_FORCE_INLINE_ void set_a8(int32_t p_a8) { a = (CLAMP(p_a8, 0, 255) / 255.0f); }
	/**
	 * Returns alpha converted to the nearest 8-bit value and clamped to zero through 255.
	 */
	_FORCE_INLINE_ int32_t get_a8() const { return int32_t(CLAMP(Math::round(a * 255.0f), 0.0f, 255.0f)); }

	/**
	 * Changes the HSV hue while keeping saturation, value, and alpha.
	 *
	 * - `p_h` — Hue as a fraction of a full turn. Zero and one are red.
	 */
	_FORCE_INLINE_ void set_h(float p_h) { set_hsv(p_h, get_s(), get_v(), a); }
	/**
	 * Changes the HSV saturation while keeping hue, value, and alpha.
	 *
	 * - `p_s` — Saturation. Zero produces a gray value.
	 */
	_FORCE_INLINE_ void set_s(float p_s) { set_hsv(get_h(), p_s, get_v(), a); }
	/**
	 * Changes the HSV value while keeping hue, saturation, and alpha.
	 *
	 * - `p_v` — Value of the brightest RGB component.
	 */
	_FORCE_INLINE_ void set_v(float p_v) { set_hsv(get_h(), get_s(), p_v, a); }

	/**
	 * Creates opaque black, with RGB zero and alpha one.
	 */
	constexpr Color() = default;

	/**
	 * RGBA construct parameters.
	 * Alpha is not optional as otherwise we can't bind the RGB version for scripting.
	 *
	 * - `p_r` — Red channel value.
	 * - `p_g` — Green channel value.
	 * - `p_b` — Blue channel value.
	 * - `p_a` — Opacity. Zero is transparent and one is opaque.
	 */
	constexpr Color(float p_r, float p_g, float p_b, float p_a) :
			r(p_r), g(p_g), b(p_b), a(p_a) {}

	/**
	 * RGB construct parameters.
	 *
	 * - `p_r` — Red channel value.
	 * - `p_g` — Green channel value.
	 * - `p_b` — Blue channel value.
	 */
	constexpr Color(float p_r, float p_g, float p_b) :
			r(p_r), g(p_g), b(p_b), a(1) {}

	/**
	 * Construct a Color from another Color, but with the specified alpha value.
	 *
	 * - `p_c` — Color that supplies the RGB channels.
	 * - `p_a` — Opacity. Zero is transparent and one is opaque.
	 */
	constexpr Color(const Color &p_c, float p_a) :
			r(p_c.r), g(p_c.g), b(p_c.b), a(p_a) {}

	/**
	 * Constructs a `godot::Color` either from an HTML color code or from a standardized color name. The
	 * supported color names are the same as the constants.
	 *
	 * - `p_code` — RGB or RGBA hexadecimal code, or a supported color name.
	 */
	Color(const String &p_code) {
		if (html_is_valid(p_code)) {
			*this = html(p_code);
		} else {
			*this = named(p_code);
		}
	}

	/**
	 * Constructs a `godot::Color` either from an HTML color code or from a standardized color name, with
	 * `alpha` on the range of 0.0 to 1.0. The supported color names are the same as the constants.
	 *
	 * - `p_code` — RGB or RGBA hexadecimal code, or a supported color name.
	 * - `p_a` — Alpha value to use instead of the one in the parsed color.
	 */
	Color(const String &p_code, float p_a) {
		*this = Color(p_code);
		a = p_a;
	}
};

constexpr Color Color::operator+(const Color &p_color) const {
	return Color(
			r + p_color.r,
			g + p_color.g,
			b + p_color.b,
			a + p_color.a);
}

constexpr void Color::operator+=(const Color &p_color) {
	r = r + p_color.r;
	g = g + p_color.g;
	b = b + p_color.b;
	a = a + p_color.a;
}

constexpr Color Color::operator-(const Color &p_color) const {
	return Color(
			r - p_color.r,
			g - p_color.g,
			b - p_color.b,
			a - p_color.a);
}

constexpr void Color::operator-=(const Color &p_color) {
	r = r - p_color.r;
	g = g - p_color.g;
	b = b - p_color.b;
	a = a - p_color.a;
}

constexpr Color Color::operator*(const Color &p_color) const {
	return Color(
			r * p_color.r,
			g * p_color.g,
			b * p_color.b,
			a * p_color.a);
}

constexpr Color Color::operator*(float p_scalar) const {
	return Color(
			r * p_scalar,
			g * p_scalar,
			b * p_scalar,
			a * p_scalar);
}

constexpr void Color::operator*=(const Color &p_color) {
	r = r * p_color.r;
	g = g * p_color.g;
	b = b * p_color.b;
	a = a * p_color.a;
}

constexpr void Color::operator*=(float p_scalar) {
	r = r * p_scalar;
	g = g * p_scalar;
	b = b * p_scalar;
	a = a * p_scalar;
}

constexpr Color Color::operator/(const Color &p_color) const {
	return Color(
			r / p_color.r,
			g / p_color.g,
			b / p_color.b,
			a / p_color.a);
}

constexpr Color Color::operator/(float p_scalar) const {
	return Color(
			r / p_scalar,
			g / p_scalar,
			b / p_scalar,
			a / p_scalar);
}

constexpr void Color::operator/=(const Color &p_color) {
	r = r / p_color.r;
	g = g / p_color.g;
	b = b / p_color.b;
	a = a / p_color.a;
}

constexpr void Color::operator/=(float p_scalar) {
	r = r / p_scalar;
	g = g / p_scalar;
	b = b / p_scalar;
	a = a / p_scalar;
}

constexpr Color Color::operator-() const {
	return Color(
			1.0f - r,
			1.0f - g,
			1.0f - b,
			1.0f - a);
}

constexpr bool Color::operator<(const Color &p_color) const {
	if (r == p_color.r) {
		if (g == p_color.g) {
			if (b == p_color.b) {
				return (a < p_color.a);
			} else {
				return (b < p_color.b);
			}
		} else {
			return g < p_color.g;
		}
	} else {
		return r < p_color.r;
	}
}

/**
 * Multiplies each RGBA channel by the left-hand scalar.
 *
 * - `p_scalar` — Factor applied to all four channels.
 * - `p_color` — Color whose channels are multiplied.
 */
constexpr Color operator*(float p_scalar, const Color &p_color) {
	return p_color * p_scalar;
}

} // namespace godot
