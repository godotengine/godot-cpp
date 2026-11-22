/**************************************************************************/
/*  print_string.hpp                                                      */
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

#include <godot_cpp/variant/utility_functions.hpp>

namespace godot {
/**
 * Formats one Variant as text and prints it as a line to standard error.
 *
 * **Used for** reporting a failure while keeping routine output on standard output.
 *
 * - `p_variant` — Value to format and print.
 *
 * ```cpp
 * const int load_status = ERR_FILE_NOT_FOUND;
 * if (load_status != OK) {
 *     print_error("Could not load the atlas. Using the default icon.");
 * }
 * ```
 */
inline void print_error(const Variant &p_variant) {
	UtilityFunctions::printerr(p_variant);
}

/**
 * Formats one Variant as text and prints it as a line to standard output.
 *
 * **Used for** reporting one status message or measurement in the console.
 *
 * - `p_variant` — Value to format and print.
 *
 * ```cpp
 * PackedByteArray decoded_pixels;
 * decoded_pixels.resize(16 * 16 * 4); // One RGBA8 tile.
 * print_line(decoded_pixels.size()); // Report decoded byte count.
 * ```
 */
inline void print_line(const Variant &p_variant) {
	UtilityFunctions::print(p_variant);
}

/**
 * Prints one Variant as text and interprets supported BBCode formatting tags.
 * Formatting on standard output depends on terminal support.
 *
 * **Used for** highlighting the result of an operation in the console.
 *
 * - `p_variant` — Value to format and print, including any BBCode tags.
 *
 * ```cpp
 * const bool imported = true; // Result from the editor importer.
 * if (imported) { print_line_rich("[color=green]Atlas import complete[/color]"); }
 * ```
 */
inline void print_line_rich(const Variant &p_variant) {
	UtilityFunctions::print_rich(p_variant);
}

/**
 * Converts the arguments to text and concatenates them in order into one standard error line.
 *
 * **Used for** reporting a failure with details such as the affected path and error code.
 *
 * - `Args` — Types of the additional values passed to `godot::UtilityFunctions::printerr()`.
 * - `p_variant` — First value to format.
 * - `p_args` — Additional values to append in order.
 *
 * ```cpp
 * const String source_path = "res://tiles/terrain.png";
 * const Error read_status = ERR_FILE_NOT_FOUND;
 * if (read_status != OK) { print_error("Cannot open ", source_path, " (error ", int(read_status), ")"); }
 * ```
 */
template <typename... Args>
void print_error(const Variant &p_variant, Args... p_args) {
	UtilityFunctions::printerr(p_variant, p_args...);
}

/**
 * Converts the arguments to text and concatenates them in order into one standard output line.
 *
 * **Used for** printing a message that combines a label with a computed value.
 *
 * - `Args` — Types of the additional values passed to `godot::UtilityFunctions::print()`.
 * - `p_variant` — First value to format.
 * - `p_args` — Additional values to append in order.
 *
 * ```cpp
 * const Size2i tile_size(16, 16);
 * const Size2i atlas_size(128, 64);
 * print_line("Atlas grid dimensions: ", atlas_size / tile_size);
 * ```
 */
template <typename... Args>
void print_line(const Variant &p_variant, Args... p_args) {
	UtilityFunctions::print(p_variant, p_args...);
}

/**
 * Concatenates the text of the arguments and prints it with supported BBCode formatting.
 * Formatting on standard output depends on terminal support.
 *
 * **Used for** printing a formatted label and its value together.
 *
 * - `Args` — Types of the additional values passed to `godot::UtilityFunctions::print_rich()`.
 * - `p_variant` — First value to format, including any BBCode tags.
 * - `p_args` — Additional values to append in order.
 *
 * ```cpp
 * const int imported_frames = 12; // Count returned by the importer.
 * print_line_rich("[b]Frames imported:[/b] ", imported_frames);
 * ```
 */
template <typename... Args>
void print_line_rich(const Variant &p_variant, Args... p_args) {
	UtilityFunctions::print_rich(p_variant, p_args...);
}

/**
 * Prints the joined argument text only when Godot's verbose standard output is enabled.
 *
 * **Used for** reporting extra diagnostics from an importer or decoder when verbose output is requested.
 *
 * - `Args` — Types of the additional values passed to `godot::UtilityFunctions::print_verbose()`.
 * - `p_variant` — First value to format.
 * - `p_args` — Additional values to append in order.
 *
 * ```cpp
 * const String source_path = "res://tiles/terrain.png";
 * const Size2i decoded_size(128, 64);
 * print_verbose("Decoded ", source_path, " at ", decoded_size, " pixels");
 * ```
 */
template <typename... Args>
void print_verbose(const Variant &p_variant, Args... p_args) {
	UtilityFunctions::print_verbose(p_variant, p_args...);
}

/**
 * Returns the Godot OS singleton's verbose standard output setting.
 *
 * **Used for** deciding whether to gather extra diagnostics before formatting a log message.
 *
 * ```cpp
 * // In an importer, with a PackedByteArray payload returned by the decoder.
 * if (is_print_verbose_enabled()) {
 *     print_line("Decoded payload bytes: ", payload.size());
 * }
 * ```
 */
bool is_print_verbose_enabled();

} // namespace godot
