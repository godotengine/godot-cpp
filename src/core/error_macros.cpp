/*************************************************************************/
/*  error_macros.cpp                                                     */
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

#include <godot_cpp/core/error_macros.hpp>

#include <godot_cpp/godot.hpp>

#include <string>

namespace godot {

void _err_print_error(const char *p_function, const char *p_file, int p_line, const char *p_error, const char *p_message, bool p_is_warning) {
	if (p_is_warning) {
		internal::gdn_interface->print_warning(p_message, p_function, p_file, p_line);
	} else {
		internal::gdn_interface->print_error(p_message, p_function, p_file, p_line);
	}
}

void _err_print_error(const char *p_function, const char *p_file, int p_line, const String &p_error, const char *p_message, bool p_is_warning) {
	if (p_is_warning) {
		internal::gdn_interface->print_warning(p_message, p_function, p_file, p_line);
	} else {
		internal::gdn_interface->print_error(p_message, p_function, p_file, p_line);
	}
}

void _err_print_error(const char *p_function, const char *p_file, int p_line, const char *p_error, const String &p_message, bool p_is_warning) {
	if (p_is_warning) {
		internal::gdn_interface->print_warning(p_message.utf8().get_data(), p_function, p_file, p_line);
	} else {
		internal::gdn_interface->print_error(p_message.utf8().get_data(), p_function, p_file, p_line);
	}
}

void _err_print_error(const char *p_function, const char *p_file, int p_line, const String &p_error, const String &p_message, bool p_is_warning) {
	if (p_is_warning) {
		internal::gdn_interface->print_warning(p_message.utf8().get_data(), p_function, p_file, p_line);
	} else {
		internal::gdn_interface->print_error(p_message.utf8().get_data(), p_function, p_file, p_line);
	}
}

void _err_print_error(const char *p_function, const char *p_file, int p_line, const char *p_error, bool p_is_warning) {
	_err_print_error(p_function, p_file, p_line, "", p_error, p_is_warning);
}

void _err_print_error(const char *p_function, const char *p_file, int p_line, const String &p_error, bool p_is_warning) {
	_err_print_error(p_function, p_file, p_line, "", p_error, p_is_warning);
}

void _err_print_index_error(const char *p_function, const char *p_file, int p_line, int64_t p_index, int64_t p_size, const char *p_index_str, const char *p_size_str, const char *p_message, bool fatal) {
	std::string fstr(fatal ? "FATAL: " : "");
	std::string err(fstr + "Index " + p_index_str + " = " + std::to_string(p_index) + " is out of bounds (" + p_size_str + " = " + std::to_string(p_size) + ").");
	_err_print_error(p_function, p_file, p_line, err.c_str(), p_message);
}

void _err_print_index_error(const char *p_function, const char *p_file, int p_line, int64_t p_index, int64_t p_size, const char *p_index_str, const char *p_size_str, const String &p_message, bool fatal) {
	std::string fstr(fatal ? "FATAL: " : "");
	std::string err(fstr + "Index " + p_index_str + " = " + std::to_string(p_index) + " is out of bounds (" + p_size_str + " = " + std::to_string(p_size) + ").");
	_err_print_error(p_function, p_file, p_line, err.c_str(), p_message);
}

} // namespace godot
