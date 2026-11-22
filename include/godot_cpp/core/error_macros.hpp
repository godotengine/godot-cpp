/**************************************************************************/
/*  error_macros.hpp                                                      */
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

#include <godot_cpp/core/defs.hpp>

#include <atomic>

namespace godot {

class String;

/**
 * Reports an error or warning through Godot with the source location.
 *
 * - `p_function` — Function name included in the diagnostic.
 * - `p_file` — Source file name included in the diagnostic.
 * - `p_line` — Source line number included in the diagnostic.
 * - `p_error` — Primary diagnostic text.
 * - `p_editor_notify` — Whether to also notify the editor.
 * - `p_is_warning` — Whether to print the diagnostic as a warning. False prints an error.
 */
void _err_print_error(const char *p_function, const char *p_file, int p_line, const char *p_error, bool p_editor_notify = false, bool p_is_warning = false);
/**
 * Reports an error or warning through Godot with the source location.
 *
 * - `p_function` — Function name included in the diagnostic.
 * - `p_file` — Source file name included in the diagnostic.
 * - `p_line` — Source line number included in the diagnostic.
 * - `p_error` — Primary diagnostic text.
 * - `p_editor_notify` — Whether to also notify the editor.
 * - `p_is_warning` — Whether to print the diagnostic as a warning. False prints an error.
 */
void _err_print_error(const char *p_function, const char *p_file, int p_line, const String &p_error, bool p_editor_notify = false, bool p_is_warning = false);
/**
 * Reports an error or warning through Godot with the source location and a separate detail message.
 *
 * - `p_function` — Function name included in the diagnostic.
 * - `p_file` — Source file name included in the diagnostic.
 * - `p_line` — Source line number included in the diagnostic.
 * - `p_error` — Primary diagnostic text.
 * - `p_message` — Additional detail printed with the diagnostic.
 * - `p_editor_notify` — Whether to also notify the editor.
 * - `p_is_warning` — Whether to print the diagnostic as a warning. False prints an error.
 */
void _err_print_error(const char *p_function, const char *p_file, int p_line, const char *p_error, const char *p_message, bool p_editor_notify = false, bool p_is_warning = false);
/**
 * Reports an error or warning through Godot with the source location and a separate detail message.
 *
 * - `p_function` — Function name included in the diagnostic.
 * - `p_file` — Source file name included in the diagnostic.
 * - `p_line` — Source line number included in the diagnostic.
 * - `p_error` — Primary diagnostic text.
 * - `p_message` — Additional detail printed with the diagnostic.
 * - `p_editor_notify` — Whether to also notify the editor.
 * - `p_is_warning` — Whether to print the diagnostic as a warning. False prints an error.
 */
void _err_print_error(const char *p_function, const char *p_file, int p_line, const String &p_error, const char *p_message, bool p_editor_notify = false, bool p_is_warning = false);
/**
 * Reports an error or warning through Godot with the source location and a separate detail message.
 *
 * - `p_function` — Function name included in the diagnostic.
 * - `p_file` — Source file name included in the diagnostic.
 * - `p_line` — Source line number included in the diagnostic.
 * - `p_error` — Primary diagnostic text.
 * - `p_message` — Additional detail printed with the diagnostic.
 * - `p_editor_notify` — Whether to also notify the editor.
 * - `p_is_warning` — Whether to print the diagnostic as a warning. False prints an error.
 */
void _err_print_error(const char *p_function, const char *p_file, int p_line, const char *p_error, const String &p_message, bool p_editor_notify = false, bool p_is_warning = false);
/**
 * Reports an error or warning through Godot with the source location and a separate detail message.
 *
 * - `p_function` — Function name included in the diagnostic.
 * - `p_file` — Source file name included in the diagnostic.
 * - `p_line` — Source line number included in the diagnostic.
 * - `p_error` — Primary diagnostic text.
 * - `p_message` — Additional detail printed with the diagnostic.
 * - `p_editor_notify` — Whether to also notify the editor.
 * - `p_is_warning` — Whether to print the diagnostic as a warning. False prints an error.
 */
void _err_print_error(const char *p_function, const char *p_file, int p_line, const String &p_error, const String &p_message, bool p_editor_notify = false, bool p_is_warning = false);
/**
 * Formats and reports an out-of-bounds index. The fatal flag marks the message.
 *
 * - `p_function` — Function name included in the diagnostic.
 * - `p_file` — Source file name included in the diagnostic.
 * - `p_line` — Source line number included in the diagnostic.
 * - `p_index` — Index value that failed the bounds check.
 * - `p_size` — Exclusive upper bound of the valid range.
 * - `p_index_str` — Source text of the index expression.
 * - `p_size_str` — Source text of the upper-bound expression.
 * - `p_message` — Additional detail printed with the error.
 * - `p_editor_notify` — Whether to also notify the editor.
 * - `p_fatal` — Whether to prefix the report with FATAL. This function does not trigger the trap.
 */
void _err_print_index_error(const char *p_function, const char *p_file, int p_line, int64_t p_index, int64_t p_size, const char *p_index_str, const char *p_size_str, const char *p_message = "", bool p_editor_notify = false, bool p_fatal = false);
/**
 * Formats and reports an out-of-bounds index. The fatal flag marks the message.
 *
 * - `p_function` — Function name included in the diagnostic.
 * - `p_file` — Source file name included in the diagnostic.
 * - `p_line` — Source line number included in the diagnostic.
 * - `p_index` — Index value that failed the bounds check.
 * - `p_size` — Exclusive upper bound of the valid range.
 * - `p_index_str` — Source text of the index expression.
 * - `p_size_str` — Source text of the upper-bound expression.
 * - `p_message` — Additional detail printed with the error.
 * - `p_editor_notify` — Whether to also notify the editor.
 * - `p_fatal` — Whether to prefix the report with FATAL. This function does not trigger the trap.
 */
void _err_print_index_error(const char *p_function, const char *p_file, int p_line, int64_t p_index, int64_t p_size, const char *p_index_str, const char *p_size_str, const String &p_message, bool p_editor_notify = false, bool p_fatal = false);
/**
 * Flushes standard output so diagnostics can be written before a trap.
 */
void _err_flush_stdout();

// Normally present in print_string.hpp, added here because our include situation is
// different from upstream godot and some files might otherwise not compile.
/**
 * Returns whether Godot's verbose output is enabled.
 */
bool is_print_verbose_enabled();

} // namespace godot

#ifdef __GNUC__
/**
 * Expands to the current function name used in diagnostics.
 */
#define FUNCTION_STR __FUNCTION__
#else
/**
 * Expands to the current function name used in diagnostics.
 */
#define FUNCTION_STR __FUNCTION__
#endif

#ifdef _MSC_VER
/**
 * Triggers a debugger break through the MSVC intrinsic.
 */
#define GENERATE_TRAP() __debugbreak()
#else
/**
 * Triggers a compiler trap on targets using the builtin.
 */
#define GENERATE_TRAP() __builtin_trap()
#endif

/**
 * Error macros.
 * WARNING: These macros work in the opposite way to assert().
 *
 * Unlike exceptions and asserts, these macros try to maintain consistency and stability.
 * In most cases, bugs and/or invalid data are not fatal. They should never allow a perfectly
 * running application to fail or crash.
 * Always try to return processable data, so the engine can keep running well.
 * Use the _MSG versions to print a meaningful message to help with debugging.
 *
 * The `((void)0)` no-op statement is used as a trick to force us to put a semicolon after
 * those macros, making them look like proper statements.
 * The if wrappers are used to ensure that the macro replacement does not trigger unexpected
 * issues when expanded e.g. after an `if (cond) ERR_FAIL();` without braces.
 */

// Index out of bounds error macros.
// These macros should be used instead of `ERR_FAIL_COND` for bounds checking.

// Integer index out of bounds error macros.

/**
 * Logs an error and returns from the current function when the index is negative or at or above the size.
 *
 * - `m_index` — Index expression. It can be evaluated again to report an error.
 * - `m_size` — Exclusive upper bound of the valid index range. It can be evaluated again to report an error.
 */
#define ERR_FAIL_INDEX(m_index, m_size) \
	if (unlikely((m_index) < 0 || (m_index) >= (m_size))) { \
		::godot::_err_print_index_error(FUNCTION_STR, __FILE__, __LINE__, m_index, m_size, _STR(m_index), _STR(m_size)); \
		return; \
	} else \
		((void)0)

/**
 * Logs an error and returns from the current function when the index is negative or at or above the size.
 *
 * - `m_index` — Index expression. It can be evaluated again to report an error.
 * - `m_size` — Exclusive upper bound of the valid index range. It can be evaluated again to report an error.
 * - `m_msg` — Additional diagnostic detail printed on failure.
 */
#define ERR_FAIL_INDEX_MSG(m_index, m_size, m_msg) \
	if (unlikely((m_index) < 0 || (m_index) >= (m_size))) { \
		::godot::_err_print_index_error(FUNCTION_STR, __FILE__, __LINE__, m_index, m_size, _STR(m_index), _STR(m_size), m_msg); \
		return; \
	} else \
		((void)0)

/**
 * Logs an error and returns from the current function when the index is negative or at or above the size. Also notifies the editor.
 *
 * - `m_index` — Index expression. It can be evaluated again to report an error.
 * - `m_size` — Exclusive upper bound of the valid index range. It can be evaluated again to report an error.
 * - `m_msg` — Additional diagnostic detail printed on failure.
 */
#define ERR_FAIL_INDEX_EDMSG(m_index, m_size, m_msg) \
	if (unlikely((m_index) < 0 || (m_index) >= (m_size))) { \
		::godot::_err_print_index_error(FUNCTION_STR, __FILE__, __LINE__, m_index, m_size, _STR(m_index), _STR(m_size), m_msg, true); \
		return; \
	} else \
		((void)0)

/**
 * Logs an error and returns from the current function when the index is negative or at or above the size.
 *
 * - `m_index` — Index expression. It can be evaluated again to report an error.
 * - `m_size` — Exclusive upper bound of the valid index range. It can be evaluated again to report an error.
 * - `m_retval` — Value returned by the enclosing function on failure.
 */
#define ERR_FAIL_INDEX_V(m_index, m_size, m_retval) \
	if (unlikely((m_index) < 0 || (m_index) >= (m_size))) { \
		::godot::_err_print_index_error(FUNCTION_STR, __FILE__, __LINE__, m_index, m_size, _STR(m_index), _STR(m_size)); \
		return m_retval; \
	} else \
		((void)0)

/**
 * Logs an error and returns from the current function when the index is negative or at or above the size.
 *
 * - `m_index` — Index expression. It can be evaluated again to report an error.
 * - `m_size` — Exclusive upper bound of the valid index range. It can be evaluated again to report an error.
 * - `m_retval` — Value returned by the enclosing function on failure.
 * - `m_msg` — Additional diagnostic detail printed on failure.
 */
#define ERR_FAIL_INDEX_V_MSG(m_index, m_size, m_retval, m_msg) \
	if (unlikely((m_index) < 0 || (m_index) >= (m_size))) { \
		::godot::_err_print_index_error(FUNCTION_STR, __FILE__, __LINE__, m_index, m_size, _STR(m_index), _STR(m_size), m_msg); \
		return m_retval; \
	} else \
		((void)0)

/**
 * Logs an error and returns from the current function when the index is negative or at or above the size. Also notifies the editor.
 *
 * - `m_index` — Index expression. It can be evaluated again to report an error.
 * - `m_size` — Exclusive upper bound of the valid index range. It can be evaluated again to report an error.
 * - `m_retval` — Value returned by the enclosing function on failure.
 * - `m_msg` — Additional diagnostic detail printed on failure.
 */
#define ERR_FAIL_INDEX_V_EDMSG(m_index, m_size, m_retval, m_msg) \
	if (unlikely((m_index) < 0 || (m_index) >= (m_size))) { \
		::godot::_err_print_index_error(FUNCTION_STR, __FILE__, __LINE__, m_index, m_size, _STR(m_index), _STR(m_size), m_msg, true); \
		return m_retval; \
	} else \
		((void)0)

/**
 * Logs a fatal error, flushes standard output, and triggers a trap when the index is negative or at or above the size.
 *
 * - `m_index` — Index expression. It can be evaluated again to report an error.
 * - `m_size` — Exclusive upper bound of the valid index range. It can be evaluated again to report an error.
 */
#define CRASH_BAD_INDEX(m_index, m_size) \
	if (unlikely((m_index) < 0 || (m_index) >= (m_size))) { \
		::godot::_err_print_index_error(FUNCTION_STR, __FILE__, __LINE__, m_index, m_size, _STR(m_index), _STR(m_size), "", false, true); \
		::godot::_err_flush_stdout(); \
		GENERATE_TRAP(); \
	} else \
		((void)0)

/**
 * Logs a fatal error, flushes standard output, and triggers a trap when the index is negative or at or above the size.
 *
 * - `m_index` — Index expression. It can be evaluated again to report an error.
 * - `m_size` — Exclusive upper bound of the valid index range. It can be evaluated again to report an error.
 * - `m_msg` — Additional diagnostic detail printed on failure.
 */
#define CRASH_BAD_INDEX_MSG(m_index, m_size, m_msg) \
	if (unlikely((m_index) < 0 || (m_index) >= (m_size))) { \
		::godot::_err_print_index_error(FUNCTION_STR, __FILE__, __LINE__, m_index, m_size, _STR(m_index), _STR(m_size), m_msg, false, true); \
		::godot::_err_flush_stdout(); \
		GENERATE_TRAP(); \
	} else \
		((void)0)

// Unsigned integer index out of bounds error macros.

/**
 * Logs an error and returns from the current function when the unsigned index is at or above the size.
 *
 * - `m_index` — Index expression. It can be evaluated again to report an error.
 * - `m_size` — Exclusive upper bound of the valid index range. It can be evaluated again to report an error.
 */
#define ERR_FAIL_UNSIGNED_INDEX(m_index, m_size) \
	if (unlikely((m_index) >= (m_size))) { \
		::godot::_err_print_index_error(FUNCTION_STR, __FILE__, __LINE__, m_index, m_size, _STR(m_index), _STR(m_size)); \
		return; \
	} else \
		((void)0)

/**
 * Logs an error and returns from the current function when the unsigned index is at or above the size.
 *
 * - `m_index` — Index expression. It can be evaluated again to report an error.
 * - `m_size` — Exclusive upper bound of the valid index range. It can be evaluated again to report an error.
 * - `m_msg` — Additional diagnostic detail printed on failure.
 */
#define ERR_FAIL_UNSIGNED_INDEX_MSG(m_index, m_size, m_msg) \
	if (unlikely((m_index) >= (m_size))) { \
		::godot::_err_print_index_error(FUNCTION_STR, __FILE__, __LINE__, m_index, m_size, _STR(m_index), _STR(m_size), m_msg); \
		return; \
	} else \
		((void)0)

/**
 * Logs an error and returns from the current function when the unsigned index is at or above the size. Also notifies the editor.
 *
 * - `m_index` — Index expression. It can be evaluated again to report an error.
 * - `m_size` — Exclusive upper bound of the valid index range. It can be evaluated again to report an error.
 * - `m_msg` — Additional diagnostic detail printed on failure.
 */
#define ERR_FAIL_UNSIGNED_INDEX_EDMSG(m_index, m_size, m_msg) \
	if (unlikely((m_index) >= (m_size))) { \
		::godot::_err_print_index_error(FUNCTION_STR, __FILE__, __LINE__, m_index, m_size, _STR(m_index), _STR(m_size), m_msg, true); \
		return; \
	} else \
		((void)0)

/**
 * Logs an error and returns from the current function when the unsigned index is at or above the size.
 *
 * - `m_index` — Index expression. It can be evaluated again to report an error.
 * - `m_size` — Exclusive upper bound of the valid index range. It can be evaluated again to report an error.
 * - `m_retval` — Value returned by the enclosing function on failure.
 */
#define ERR_FAIL_UNSIGNED_INDEX_V(m_index, m_size, m_retval) \
	if (unlikely((m_index) >= (m_size))) { \
		::godot::_err_print_index_error(FUNCTION_STR, __FILE__, __LINE__, m_index, m_size, _STR(m_index), _STR(m_size)); \
		return m_retval; \
	} else \
		((void)0)

/**
 * Logs an error and returns from the current function when the unsigned index is at or above the size.
 *
 * - `m_index` — Index expression. It can be evaluated again to report an error.
 * - `m_size` — Exclusive upper bound of the valid index range. It can be evaluated again to report an error.
 * - `m_retval` — Value returned by the enclosing function on failure.
 * - `m_msg` — Additional diagnostic detail printed on failure.
 */
#define ERR_FAIL_UNSIGNED_INDEX_V_MSG(m_index, m_size, m_retval, m_msg) \
	if (unlikely((m_index) >= (m_size))) { \
		::godot::_err_print_index_error(FUNCTION_STR, __FILE__, __LINE__, m_index, m_size, _STR(m_index), _STR(m_size), m_msg); \
		return m_retval; \
	} else \
		((void)0)

/**
 * Logs an error and returns from the current function when the unsigned index is at or above the size. Also notifies the editor.
 *
 * - `m_index` — Index expression. It can be evaluated again to report an error.
 * - `m_size` — Exclusive upper bound of the valid index range. It can be evaluated again to report an error.
 * - `m_retval` — Value returned by the enclosing function on failure.
 * - `m_msg` — Additional diagnostic detail printed on failure.
 */
#define ERR_FAIL_UNSIGNED_INDEX_V_EDMSG(m_index, m_size, m_retval, m_msg) \
	if (unlikely((m_index) >= (m_size))) { \
		::godot::_err_print_index_error(FUNCTION_STR, __FILE__, __LINE__, m_index, m_size, _STR(m_index), _STR(m_size), m_msg, true); \
		return m_retval; \
	} else \
		((void)0)

/**
 * Logs a fatal error, flushes standard output, and triggers a trap when the unsigned index is at or above the size.
 *
 * - `m_index` — Index expression. It can be evaluated again to report an error.
 * - `m_size` — Exclusive upper bound of the valid index range. It can be evaluated again to report an error.
 */
#define CRASH_BAD_UNSIGNED_INDEX(m_index, m_size) \
	if (unlikely((m_index) >= (m_size))) { \
		::godot::_err_print_index_error(FUNCTION_STR, __FILE__, __LINE__, m_index, m_size, _STR(m_index), _STR(m_size), "", false, true); \
		::godot::_err_flush_stdout(); \
		GENERATE_TRAP(); \
	} else \
		((void)0)

/**
 * Logs a fatal error, flushes standard output, and triggers a trap when the unsigned index is at or above the size.
 *
 * - `m_index` — Index expression. It can be evaluated again to report an error.
 * - `m_size` — Exclusive upper bound of the valid index range. It can be evaluated again to report an error.
 * - `m_msg` — Additional diagnostic detail printed on failure.
 */
#define CRASH_BAD_UNSIGNED_INDEX_MSG(m_index, m_size, m_msg) \
	if (unlikely((m_index) >= (m_size))) { \
		::godot::_err_print_index_error(FUNCTION_STR, __FILE__, __LINE__, m_index, m_size, _STR(m_index), _STR(m_size), m_msg, false, true); \
		::godot::_err_flush_stdout(); \
		GENERATE_TRAP(); \
	} else \
		((void)0)

// Null reference error macros.

/**
 * Logs an error and returns from the current function when the pointer is null.
 *
 * - `m_param` — Pointer expression to check.
 */
#define ERR_FAIL_NULL(m_param) \
	if (unlikely(m_param == nullptr)) { \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Parameter \"" _STR(m_param) "\" is null."); \
		return; \
	} else \
		((void)0)

/**
 * Logs an error and returns from the current function when the pointer is null.
 *
 * - `m_param` — Pointer expression to check.
 * - `m_msg` — Additional diagnostic detail printed on failure.
 */
#define ERR_FAIL_NULL_MSG(m_param, m_msg) \
	if (unlikely(m_param == nullptr)) { \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Parameter \"" _STR(m_param) "\" is null.", m_msg); \
		return; \
	} else \
		((void)0)

/**
 * Logs an error and returns from the current function when the pointer is null. Also notifies the editor.
 *
 * - `m_param` — Pointer expression to check.
 * - `m_msg` — Additional diagnostic detail printed on failure.
 */
#define ERR_FAIL_NULL_EDMSG(m_param, m_msg) \
	if (unlikely(m_param == nullptr)) { \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Parameter \"" _STR(m_param) "\" is null.", m_msg, true); \
		return; \
	} else \
		((void)0)

/**
 * Logs an error and returns from the current function when the pointer is null.
 *
 * - `m_param` — Pointer expression to check.
 * - `m_retval` — Value returned by the enclosing function on failure.
 */
#define ERR_FAIL_NULL_V(m_param, m_retval) \
	if (unlikely(m_param == nullptr)) { \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Parameter \"" _STR(m_param) "\" is null."); \
		return m_retval; \
	} else \
		((void)0)

/**
 * Logs an error and returns from the current function when the pointer is null.
 *
 * - `m_param` — Pointer expression to check.
 * - `m_retval` — Value returned by the enclosing function on failure.
 * - `m_msg` — Additional diagnostic detail printed on failure.
 */
#define ERR_FAIL_NULL_V_MSG(m_param, m_retval, m_msg) \
	if (unlikely(m_param == nullptr)) { \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Parameter \"" _STR(m_param) "\" is null.", m_msg); \
		return m_retval; \
	} else \
		((void)0)

/**
 * Logs an error and returns from the current function when the pointer is null. Also notifies the editor.
 *
 * - `m_param` — Pointer expression to check.
 * - `m_retval` — Value returned by the enclosing function on failure.
 * - `m_msg` — Additional diagnostic detail printed on failure.
 */
#define ERR_FAIL_NULL_V_EDMSG(m_param, m_retval, m_msg) \
	if (unlikely(m_param == nullptr)) { \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Parameter \"" _STR(m_param) "\" is null.", m_msg, true); \
		return m_retval; \
	} else \
		((void)0)

/**
 * Logs an error and returns from the current function when the condition is true.
 *
 * - `m_cond` — Condition tested by the macro.
 */
#define ERR_FAIL_COND(m_cond) \
	if (unlikely(m_cond)) { \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Condition \"" _STR(m_cond) "\" is true."); \
		return; \
	} else \
		((void)0)

/**
 * Logs an error and returns from the current function when the condition is true.
 *
 * - `m_cond` — Condition tested by the macro.
 * - `m_msg` — Additional diagnostic detail printed on failure.
 */
#define ERR_FAIL_COND_MSG(m_cond, m_msg) \
	if (unlikely(m_cond)) { \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Condition \"" _STR(m_cond) "\" is true.", m_msg); \
		return; \
	} else \
		((void)0)

/**
 * Logs an error and returns from the current function when the condition is true. Also notifies the editor.
 *
 * - `m_cond` — Condition tested by the macro.
 * - `m_msg` — Additional diagnostic detail printed on failure.
 */
#define ERR_FAIL_COND_EDMSG(m_cond, m_msg) \
	if (unlikely(m_cond)) { \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Condition \"" _STR(m_cond) "\" is true.", m_msg, true); \
		return; \
	} else \
		((void)0)

/**
 * Logs an error and returns from the current function when the condition is true.
 *
 * - `m_cond` — Condition tested by the macro.
 * - `m_retval` — Value returned by the enclosing function on failure.
 */
#define ERR_FAIL_COND_V(m_cond, m_retval) \
	if (unlikely(m_cond)) { \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Condition \"" _STR(m_cond) "\" is true. Returning: " _STR(m_retval)); \
		return m_retval; \
	} else \
		((void)0)

/**
 * Logs an error and returns from the current function when the condition is true.
 *
 * - `m_cond` — Condition tested by the macro.
 * - `m_retval` — Value returned by the enclosing function on failure.
 * - `m_msg` — Additional diagnostic detail printed on failure.
 */
#define ERR_FAIL_COND_V_MSG(m_cond, m_retval, m_msg) \
	if (unlikely(m_cond)) { \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Condition \"" _STR(m_cond) "\" is true. Returning: " _STR(m_retval), m_msg); \
		return m_retval; \
	} else \
		((void)0)

/**
 * Logs an error and returns from the current function when the condition is true. Also notifies the editor.
 *
 * - `m_cond` — Condition tested by the macro.
 * - `m_retval` — Value returned by the enclosing function on failure.
 * - `m_msg` — Additional diagnostic detail printed on failure.
 */
#define ERR_FAIL_COND_V_EDMSG(m_cond, m_retval, m_msg) \
	if (unlikely(m_cond)) { \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Condition \"" _STR(m_cond) "\" is true. Returning: " _STR(m_retval), m_msg, true); \
		return m_retval; \
	} else \
		((void)0)

/**
 * Logs an error and skips the rest of the current loop iteration when the condition is true.
 *
 * - `m_cond` — Condition tested by the macro.
 */
#define ERR_CONTINUE(m_cond) \
	if (unlikely(m_cond)) { \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Condition \"" _STR(m_cond) "\" is true. Continuing."); \
		continue; \
	} else \
		((void)0)

/**
 * Logs an error and skips the rest of the current loop iteration when the condition is true.
 *
 * - `m_cond` — Condition tested by the macro.
 * - `m_msg` — Additional diagnostic detail printed on failure.
 */
#define ERR_CONTINUE_MSG(m_cond, m_msg) \
	if (unlikely(m_cond)) { \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Condition \"" _STR(m_cond) "\" is true. Continuing.", m_msg); \
		continue; \
	} else \
		((void)0)

/**
 * Logs an error and skips the rest of the current loop iteration when the condition is true. Also notifies the editor.
 *
 * - `m_cond` — Condition tested by the macro.
 * - `m_msg` — Additional diagnostic detail printed on failure.
 */
#define ERR_CONTINUE_EDMSG(m_cond, m_msg) \
	if (unlikely(m_cond)) { \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Condition \"" _STR(m_cond) "\" is true. Continuing.", m_msg, true); \
		continue; \
	} else \
		((void)0)

/**
 * Logs an error and leaves the current loop when the condition is true.
 *
 * - `m_cond` — Condition tested by the macro.
 */
#define ERR_BREAK(m_cond) \
	if (unlikely(m_cond)) { \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Condition \"" _STR(m_cond) "\" is true. Breaking."); \
		break; \
	} else \
		((void)0)

/**
 * Logs an error and leaves the current loop when the condition is true.
 *
 * - `m_cond` — Condition tested by the macro.
 * - `m_msg` — Additional diagnostic detail printed on failure.
 */
#define ERR_BREAK_MSG(m_cond, m_msg) \
	if (unlikely(m_cond)) { \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Condition \"" _STR(m_cond) "\" is true. Breaking.", m_msg); \
		break; \
	} else \
		((void)0)

/**
 * Logs an error and leaves the current loop when the condition is true. Also notifies the editor.
 *
 * - `m_cond` — Condition tested by the macro.
 * - `m_msg` — Additional diagnostic detail printed on failure.
 */
#define ERR_BREAK_EDMSG(m_cond, m_msg) \
	if (unlikely(m_cond)) { \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Condition \"" _STR(m_cond) "\" is true. Breaking.", m_msg, true); \
		break; \
	} else \
		((void)0)

/**
 * Logs a fatal error, flushes standard output, and triggers a trap when the condition is true.
 *
 * - `m_cond` — Condition tested by the macro.
 */
#define CRASH_COND(m_cond) \
	if (unlikely(m_cond)) { \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "FATAL: Condition \"" _STR(m_cond) "\" is true."); \
		::godot::_err_flush_stdout(); \
		GENERATE_TRAP(); \
	} else \
		((void)0)

/**
 * Logs a fatal error, flushes standard output, and triggers a trap when the condition is true.
 *
 * - `m_cond` — Condition tested by the macro.
 * - `m_msg` — Additional diagnostic detail printed on failure.
 */
#define CRASH_COND_MSG(m_cond, m_msg) \
	if (unlikely(m_cond)) { \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "FATAL: Condition \"" _STR(m_cond) "\" is true.", m_msg); \
		::godot::_err_flush_stdout(); \
		GENERATE_TRAP(); \
	} else \
		((void)0)

// Generic error macros.

/**
 * Logs an error and returns from the current function.
 */
#define ERR_FAIL() \
	if (true) { \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Method/function failed."); \
		return; \
	} else \
		((void)0)

/**
 * Logs an error and returns from the current function.
 *
 * - `m_msg` — Additional diagnostic detail printed on failure.
 */
#define ERR_FAIL_MSG(m_msg) \
	if (true) { \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Method/function failed.", m_msg); \
		return; \
	} else \
		((void)0)

/**
 * Logs an error and returns from the current function. Also notifies the editor.
 *
 * - `m_msg` — Additional diagnostic detail printed on failure.
 */
#define ERR_FAIL_EDMSG(m_msg) \
	if (true) { \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Method/function failed.", m_msg, true); \
		return; \
	} else \
		((void)0)

/**
 * Logs an error and returns from the current function.
 *
 * - `m_retval` — Value returned by the enclosing function on failure.
 */
#define ERR_FAIL_V(m_retval) \
	if (true) { \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Method/function failed. Returning: " _STR(m_retval)); \
		return m_retval; \
	} else \
		((void)0)

/**
 * Logs an error and returns from the current function.
 *
 * - `m_retval` — Value returned by the enclosing function on failure.
 * - `m_msg` — Additional diagnostic detail printed on failure.
 */
#define ERR_FAIL_V_MSG(m_retval, m_msg) \
	if (true) { \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Method/function failed. Returning: " _STR(m_retval), m_msg); \
		return m_retval; \
	} else \
		((void)0)

/**
 * Logs an error and returns from the current function. Also notifies the editor.
 *
 * - `m_retval` — Value returned by the enclosing function on failure.
 * - `m_msg` — Additional diagnostic detail printed on failure.
 */
#define ERR_FAIL_V_EDMSG(m_retval, m_msg) \
	if (true) { \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Method/function failed. Returning: " _STR(m_retval), m_msg, true); \
		return m_retval; \
	} else \
		((void)0)

/**
 * Logs an error and continues execution.
 *
 * - `m_msg` — Diagnostic message printed when the macro logs.
 */
#define ERR_PRINT(m_msg) \
	::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, m_msg)

/**
 * Logs an error and continues execution. Also notifies the editor.
 *
 * - `m_msg` — Diagnostic message printed when the macro logs.
 */
#define ERR_PRINT_ED(m_msg) \
	::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, m_msg, true)

/**
 * Logs an error the first time execution reaches this expansion.
 *
 * - `m_msg` — Diagnostic message printed when the macro logs.
 */
#define ERR_PRINT_ONCE(m_msg) \
	if (true) { \
		static bool first_print = true; \
		if (first_print) { \
			::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, m_msg); \
			first_print = false; \
		} \
	} else \
		((void)0)

/**
 * Logs an error the first time execution reaches this expansion. Also notifies the editor.
 *
 * - `m_msg` — Diagnostic message printed when the macro logs.
 */
#define ERR_PRINT_ONCE_ED(m_msg) \
	if (true) { \
		static bool first_print = true; \
		if (first_print) { \
			::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, m_msg, true); \
			first_print = false; \
		} \
	} else \
		((void)0)

// Print warning message macros.

/**
 * Logs a warning and continues execution.
 *
 * - `m_msg` — Diagnostic message printed when the macro logs.
 */
#define WARN_PRINT(m_msg) \
	::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, m_msg, false, true)

/**
 * Logs a warning and continues execution. Also notifies the editor.
 *
 * - `m_msg` — Diagnostic message printed when the macro logs.
 */
#define WARN_PRINT_ED(m_msg) \
	::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, m_msg, true, true)

/**
 * Logs a warning the first time execution reaches this expansion.
 *
 * - `m_msg` — Diagnostic message printed when the macro logs.
 */
#define WARN_PRINT_ONCE(m_msg) \
	if (true) { \
		static bool first_print = true; \
		if (first_print) { \
			::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, m_msg, false, true); \
			first_print = false; \
		} \
	} else \
		((void)0)

/**
 * Logs a warning the first time execution reaches this expansion. Also notifies the editor.
 *
 * - `m_msg` — Diagnostic message printed when the macro logs.
 */
#define WARN_PRINT_ONCE_ED(m_msg) \
	if (true) { \
		static bool first_print = true; \
		if (first_print) { \
			::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, m_msg, true, true); \
			first_print = false; \
		} \
	} else \
		((void)0)

/**
 * Logs a warning when verbose output is enabled.
 *
 * - `m_msg` — Diagnostic message printed when the macro logs.
 */
#define WARN_VERBOSE(m_msg) \
	{ \
		if (is_print_verbose_enabled()) { \
			WARN_PRINT(m_msg); \
		} \
	}

// Print deprecated warning message macros.

/**
 * Warns that the current function is deprecated and records that the warning has been shown for this expansion. Also notifies the editor.
 */
#define WARN_DEPRECATED \
	if (true) { \
		static std::atomic<bool> warning_shown; \
		if (!warning_shown.load()) { \
			::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "This method has been deprecated and will be removed in the future.", false, true); \
			warning_shown.store(true); \
		} \
	} else \
		((void)0)

/**
 * Warns that the current function is deprecated and records that the warning has been shown for this expansion.
 *
 * - `m_msg` — Diagnostic message printed when the macro logs.
 */
#define WARN_DEPRECATED_MSG(m_msg) \
	if (true) { \
		static std::atomic<bool> warning_shown; \
		if (!warning_shown.load()) { \
			::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "This method has been deprecated and will be removed in the future.", m_msg, false, true); \
			warning_shown.store(true); \
		} \
	} else \
		((void)0)

/**
 * Logs a fatal error, flushes standard output, and triggers a trap.
 */
#define CRASH_NOW() \
	if (true) { \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "FATAL: Method/function failed."); \
		::godot::_err_flush_stdout(); \
		GENERATE_TRAP(); \
	} else \
		((void)0)

/**
 * Logs a fatal error, flushes standard output, and triggers a trap.
 *
 * - `m_msg` — Additional diagnostic detail printed on failure.
 */
#define CRASH_NOW_MSG(m_msg) \
	if (true) { \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "FATAL: Method/function failed.", m_msg); \
		::godot::_err_flush_stdout(); \
		GENERATE_TRAP(); \
	} else \
		((void)0)

/**
 * This should be a 'free' assert for program flow and should not be needed in any releases,
 *  only used in dev builds.
 */
#ifdef DEBUG_ENABLED
/**
 * Logs an error, flushes standard output, and triggers a trap if the condition is false.
 *
 * - `m_cond` — Condition that must be true to continue execution.
 */
#define DEV_ASSERT(m_cond) \
	if (unlikely(!(m_cond))) { \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "FATAL: DEV_ASSERT failed  \"" _STR(m_cond) "\" is false."); \
		::godot::_err_flush_stdout(); \
		GENERATE_TRAP(); \
	} else \
		((void)0)
#else
/**
 * Expands to no check when debug support is disabled.
 *
 * - `m_cond` — Condition expression. It is not evaluated in this build.
 */
#define DEV_ASSERT(m_cond)
#endif

/**
 * Gives an error message when a method bind is invalid (likely the hash changed).
 * Avoids crashing the application in this case. It's not free, so it's debug only.
 */
#ifdef DEBUG_ENABLED
/**
 * Reports a missing method binding and returns from the current function before the call. The message is printed once per expansion.
 *
 * - `m_mb` — Resolved method binding pointer. A null pointer causes an early return.
 * - `m_ret` — Value returned when the method binding is missing.
 */
#define CHECK_METHOD_BIND_RET(m_mb, m_ret) \
	if (unlikely(!m_mb)) { \
		ERR_PRINT_ONCE("Method bind was not found. Likely the engine method changed to an incompatible version."); \
		return m_ret; \
	} else \
		((void)0)

/**
 * Reports a missing method binding and returns from the current function before the call. The message is printed once per expansion.
 *
 * - `m_mb` — Resolved method binding pointer. A null pointer causes an early return.
 */
#define CHECK_METHOD_BIND(m_mb) \
	if (unlikely(!m_mb)) { \
		ERR_PRINT_ONCE("Method bind was not found. Likely the engine method changed to an incompatible version."); \
		return; \
	} else \
		((void)0)
#else
/**
 * Expands to no method binding check when debug support is disabled.
 *
 * - `m_mb` — Method binding expression. It is not evaluated in this build.
 * - `m_ret` — Fallback expression. It is not evaluated in this build.
 */
#define CHECK_METHOD_BIND_RET(m_mb, m_ret)
/**
 * Expands to no method binding check when debug support is disabled.
 *
 * - `m_mb` — Method binding expression. It is not evaluated in this build.
 */
#define CHECK_METHOD_BIND(m_mb)
#endif
