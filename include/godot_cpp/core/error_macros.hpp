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

#ifndef GODOT_ERROR_MACROS_HPP
#define GODOT_ERROR_MACROS_HPP

#ifdef GODOT_MODULE
#include "core/error/error_macros.h"
#else

#include <godot_cpp/core/defs.hpp>

#include <atomic>

namespace godot {

class String;

void _err_print_error(const char *p_function, const char *p_file, int p_line, const char *p_error, bool p_editor_notify = false, bool p_is_warning = false);
void _err_print_error(const char *p_function, const char *p_file, int p_line, const String &p_error, bool p_editor_notify = false, bool p_is_warning = false);
void _err_print_error(const char *p_function, const char *p_file, int p_line, const char *p_error, const char *p_message, bool p_editor_notify = false, bool p_is_warning = false);
void _err_print_error(const char *p_function, const char *p_file, int p_line, const String &p_error, const char *p_message, bool p_editor_notify = false, bool p_is_warning = false);
void _err_print_error(const char *p_function, const char *p_file, int p_line, const char *p_error, const String &p_message, bool p_editor_notify = false, bool p_is_warning = false);
void _err_print_error(const char *p_function, const char *p_file, int p_line, const String &p_error, const String &p_message, bool p_editor_notify = false, bool p_is_warning = false);
void _err_print_index_error(const char *p_function, const char *p_file, int p_line, int64_t p_index, int64_t p_size, const char *p_index_str, const char *p_size_str, const char *p_message = "", bool p_editor_notify = false, bool p_fatal = false);
void _err_print_index_error(const char *p_function, const char *p_file, int p_line, int64_t p_index, int64_t p_size, const char *p_index_str, const char *p_size_str, const String &p_message, bool p_editor_notify = false, bool p_fatal = false);
void _err_flush_stdout();

} // namespace godot

#ifdef __GNUC__
#define FUNCTION_STR __FUNCTION__
#else
#define FUNCTION_STR __FUNCTION__
#endif

#ifdef _MSC_VER
/**
 * Don't use GENERATE_TRAP() directly, should only be used be the macros below.
 */
#define GENERATE_TRAP() __debugbreak()
#else
/**
 * Don't use GENERATE_TRAP() directly, should only be used be the macros below.
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
 * Try using `ERR_FAIL_INDEX_MSG`.
 * Only use this macro if there is no sensible error message.
 *
 * Ensures an integer index `m_index` is less than `m_size` and greater than or equal to 0.
 * If not, the current function returns.
 */
#define ERR_FAIL_INDEX(m_index, m_size)                                                                                  \
	if (unlikely((m_index) < 0 || (m_index) >= (m_size))) {                                                              \
		::godot::_err_print_index_error(FUNCTION_STR, __FILE__, __LINE__, m_index, m_size, _STR(m_index), _STR(m_size)); \
		return;                                                                                                          \
	} else                                                                                                               \
		((void)0)

/**
 * Ensures an integer index `m_index` is less than `m_size` and greater than or equal to 0.
 * If not, prints `m_msg` and the current function returns.
 */
#define ERR_FAIL_INDEX_MSG(m_index, m_size, m_msg)                                                                              \
	if (unlikely((m_index) < 0 || (m_index) >= (m_size))) {                                                                     \
		::godot::_err_print_index_error(FUNCTION_STR, __FILE__, __LINE__, m_index, m_size, _STR(m_index), _STR(m_size), m_msg); \
		return;                                                                                                                 \
	} else                                                                                                                      \
		((void)0)

/**
 * Same as `ERR_FAIL_INDEX_MSG` but also notifies the editor.
 */
#define ERR_FAIL_INDEX_EDMSG(m_index, m_size, m_msg)                                                                                  \
	if (unlikely((m_index) < 0 || (m_index) >= (m_size))) {                                                                           \
		::godot::_err_print_index_error(FUNCTION_STR, __FILE__, __LINE__, m_index, m_size, _STR(m_index), _STR(m_size), m_msg, true); \
		return;                                                                                                                       \
	} else                                                                                                                            \
		((void)0)

/**
 * Try using `ERR_FAIL_INDEX_V_MSG`.
 * Only use this macro if there is no sensible error message.
 *
 * Ensures an integer index `m_index` is less than `m_size` and greater than or equal to 0.
 * If not, the current function returns `m_retval`.
 */
#define ERR_FAIL_INDEX_V(m_index, m_size, m_retval)                                                                      \
	if (unlikely((m_index) < 0 || (m_index) >= (m_size))) {                                                              \
		::godot::_err_print_index_error(FUNCTION_STR, __FILE__, __LINE__, m_index, m_size, _STR(m_index), _STR(m_size)); \
		return m_retval;                                                                                                 \
	} else                                                                                                               \
		((void)0)

/**
 * Ensures an integer index `m_index` is less than `m_size` and greater than or equal to 0.
 * If not, prints `m_msg` and the current function returns `m_retval`.
 */
#define ERR_FAIL_INDEX_V_MSG(m_index, m_size, m_retval, m_msg)                                                                  \
	if (unlikely((m_index) < 0 || (m_index) >= (m_size))) {                                                                     \
		::godot::_err_print_index_error(FUNCTION_STR, __FILE__, __LINE__, m_index, m_size, _STR(m_index), _STR(m_size), m_msg); \
		return m_retval;                                                                                                        \
	} else                                                                                                                      \
		((void)0)

/**
 * Same as `ERR_FAIL_INDEX_V_MSG` but also notifies the editor.
 */
#define ERR_FAIL_INDEX_V_EDMSG(m_index, m_size, m_retval, m_msg)                                                                      \
	if (unlikely((m_index) < 0 || (m_index) >= (m_size))) {                                                                           \
		::godot::_err_print_index_error(FUNCTION_STR, __FILE__, __LINE__, m_index, m_size, _STR(m_index), _STR(m_size), m_msg, true); \
		return m_retval;                                                                                                              \
	} else                                                                                                                            \
		((void)0)

/**
 * Try using `ERR_FAIL_INDEX_MSG` or `ERR_FAIL_INDEX_V_MSG`.
 * Only use this macro if there is no sensible fallback i.e. the error is unrecoverable, and
 * there is no sensible error message.
 *
 * Ensures an integer index `m_index` is less than `m_size` and greater than or equal to 0.
 * If not, the application crashes.
 */
#define CRASH_BAD_INDEX(m_index, m_size)                                                                                                  \
	if (unlikely((m_index) < 0 || (m_index) >= (m_size))) {                                                                               \
		::godot::_err_print_index_error(FUNCTION_STR, __FILE__, __LINE__, m_index, m_size, _STR(m_index), _STR(m_size), "", false, true); \
		::godot::_err_flush_stdout();                                                                                                     \
		GENERATE_TRAP();                                                                                                                  \
	} else                                                                                                                                \
		((void)0)

/**
 * Try using `ERR_FAIL_INDEX_MSG` or `ERR_FAIL_INDEX_V_MSG`.
 * Only use this macro if there is no sensible fallback i.e. the error is unrecoverable.
 *
 * Ensures an integer index `m_index` is less than `m_size` and greater than or equal to 0.
 * If not, prints `m_msg` and the application crashes.
 */
#define CRASH_BAD_INDEX_MSG(m_index, m_size, m_msg)                                                                                          \
	if (unlikely((m_index) < 0 || (m_index) >= (m_size))) {                                                                                  \
		::godot::_err_print_index_error(FUNCTION_STR, __FILE__, __LINE__, m_index, m_size, _STR(m_index), _STR(m_size), m_msg, false, true); \
		::godot::_err_flush_stdout();                                                                                                        \
		GENERATE_TRAP();                                                                                                                     \
	} else                                                                                                                                   \
		((void)0)

// Unsigned integer index out of bounds error macros.

/**
 * Try using `ERR_FAIL_UNSIGNED_INDEX_MSG`.
 * Only use this macro if there is no sensible error message.
 *
 * Ensures an unsigned integer index `m_index` is less than `m_size`.
 * If not, the current function returns.
 */
#define ERR_FAIL_UNSIGNED_INDEX(m_index, m_size)                                                                         \
	if (unlikely((m_index) >= (m_size))) {                                                                               \
		::godot::_err_print_index_error(FUNCTION_STR, __FILE__, __LINE__, m_index, m_size, _STR(m_index), _STR(m_size)); \
		return;                                                                                                          \
	} else                                                                                                               \
		((void)0)

/**
 * Ensures an unsigned integer index `m_index` is less than `m_size`.
 * If not, prints `m_msg` and the current function returns.
 */
#define ERR_FAIL_UNSIGNED_INDEX_MSG(m_index, m_size, m_msg)                                                                     \
	if (unlikely((m_index) >= (m_size))) {                                                                                      \
		::godot::_err_print_index_error(FUNCTION_STR, __FILE__, __LINE__, m_index, m_size, _STR(m_index), _STR(m_size), m_msg); \
		return;                                                                                                                 \
	} else                                                                                                                      \
		((void)0)

/**
 * Same as `ERR_FAIL_UNSIGNED_INDEX_MSG` but also notifies the editor.
 */
#define ERR_FAIL_UNSIGNED_INDEX_EDMSG(m_index, m_size, m_msg)                                                                         \
	if (unlikely((m_index) >= (m_size))) {                                                                                            \
		::godot::_err_print_index_error(FUNCTION_STR, __FILE__, __LINE__, m_index, m_size, _STR(m_index), _STR(m_size), m_msg, true); \
		return;                                                                                                                       \
	} else                                                                                                                            \
		((void)0)

/**
 * Try using `ERR_FAIL_UNSIGNED_INDEX_V_MSG`.
 * Only use this macro if there is no sensible error message.
 *
 * Ensures an unsigned integer index `m_index` is less than `m_size`.
 * If not, the current function returns `m_retval`.
 */
#define ERR_FAIL_UNSIGNED_INDEX_V(m_index, m_size, m_retval)                                                             \
	if (unlikely((m_index) >= (m_size))) {                                                                               \
		::godot::_err_print_index_error(FUNCTION_STR, __FILE__, __LINE__, m_index, m_size, _STR(m_index), _STR(m_size)); \
		return m_retval;                                                                                                 \
	} else                                                                                                               \
		((void)0)

/**
 * Ensures an unsigned integer index `m_index` is less than `m_size`.
 * If not, prints `m_msg` and the current function returns `m_retval`.
 */
#define ERR_FAIL_UNSIGNED_INDEX_V_MSG(m_index, m_size, m_retval, m_msg)                                                         \
	if (unlikely((m_index) >= (m_size))) {                                                                                      \
		::godot::_err_print_index_error(FUNCTION_STR, __FILE__, __LINE__, m_index, m_size, _STR(m_index), _STR(m_size), m_msg); \
		return m_retval;                                                                                                        \
	} else                                                                                                                      \
		((void)0)

/**
 * Same as `ERR_FAIL_UNSIGNED_INDEX_V_EDMSG` but also notifies the editor.
 */
#define ERR_FAIL_UNSIGNED_INDEX_V_EDMSG(m_index, m_size, m_retval, m_msg)                                                             \
	if (unlikely((m_index) >= (m_size))) {                                                                                            \
		::godot::_err_print_index_error(FUNCTION_STR, __FILE__, __LINE__, m_index, m_size, _STR(m_index), _STR(m_size), m_msg, true); \
		return m_retval;                                                                                                              \
	} else                                                                                                                            \
		((void)0)

/**
 * Try using `ERR_FAIL_UNSIGNED_INDEX_MSG` or `ERR_FAIL_UNSIGNED_INDEX_V_MSG`.
 * Only use this macro if there is no sensible fallback i.e. the error is unrecoverable, and
 * there is no sensible error message.
 *
 * Ensures an unsigned integer index `m_index` is less than `m_size`.
 * If not, the application crashes.
 */
#define CRASH_BAD_UNSIGNED_INDEX(m_index, m_size)                                                                                         \
	if (unlikely((m_index) >= (m_size))) {                                                                                                \
		::godot::_err_print_index_error(FUNCTION_STR, __FILE__, __LINE__, m_index, m_size, _STR(m_index), _STR(m_size), "", false, true); \
		::godot::_err_flush_stdout();                                                                                                     \
		GENERATE_TRAP();                                                                                                                  \
	} else                                                                                                                                \
		((void)0)

/**
 * Try using `ERR_FAIL_UNSIGNED_INDEX_MSG` or `ERR_FAIL_UNSIGNED_INDEX_V_MSG`.
 * Only use this macro if there is no sensible fallback i.e. the error is unrecoverable.
 *
 * Ensures an unsigned integer index `m_index` is less than `m_size`.
 * If not, prints `m_msg` and the application crashes.
 */
#define CRASH_BAD_UNSIGNED_INDEX_MSG(m_index, m_size, m_msg)                                                                                 \
	if (unlikely((m_index) >= (m_size))) {                                                                                                   \
		::godot::_err_print_index_error(FUNCTION_STR, __FILE__, __LINE__, m_index, m_size, _STR(m_index), _STR(m_size), m_msg, false, true); \
		::godot::_err_flush_stdout();                                                                                                        \
		GENERATE_TRAP();                                                                                                                     \
	} else                                                                                                                                   \
		((void)0)

// Null reference error macros.

/**
 * Try using `ERR_FAIL_NULL_MSG`.
 * Only use this macro if there is no sensible error message.
 *
 * Ensures a pointer `m_param` is not null.
 * If it is null, the current function returns.
 */
#define ERR_FAIL_NULL(m_param)                                                                                   \
	if (unlikely(m_param == nullptr)) {                                                                          \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Parameter \"" _STR(m_param) "\" is null."); \
		return;                                                                                                  \
	} else                                                                                                       \
		((void)0)

/**
 * Ensures a pointer `m_param` is not null.
 * If it is null, prints `m_msg` and the current function returns.
 */
#define ERR_FAIL_NULL_MSG(m_param, m_msg)                                                                               \
	if (unlikely(m_param == nullptr)) {                                                                                 \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Parameter \"" _STR(m_param) "\" is null.", m_msg); \
		return;                                                                                                         \
	} else                                                                                                              \
		((void)0)

/**
 * Same as `ERR_FAIL_NULL_MSG` but also notifies the editor.
 */
#define ERR_FAIL_NULL_EDMSG(m_param, m_msg)                                                                                   \
	if (unlikely(m_param == nullptr)) {                                                                                       \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Parameter \"" _STR(m_param) "\" is null.", m_msg, true); \
		return;                                                                                                               \
	} else                                                                                                                    \
		((void)0)

/**
 * Try using `ERR_FAIL_NULL_V_MSG`.
 * Only use this macro if there is no sensible error message.
 *
 * Ensures a pointer `m_param` is not null.
 * If it is null, the current function returns `m_retval`.
 */
#define ERR_FAIL_NULL_V(m_param, m_retval)                                                                       \
	if (unlikely(m_param == nullptr)) {                                                                          \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Parameter \"" _STR(m_param) "\" is null."); \
		return m_retval;                                                                                         \
	} else                                                                                                       \
		((void)0)

/**
 * Ensures a pointer `m_param` is not null.
 * If it is null, prints `m_msg` and the current function returns `m_retval`.
 */
#define ERR_FAIL_NULL_V_MSG(m_param, m_retval, m_msg)                                                                   \
	if (unlikely(m_param == nullptr)) {                                                                                 \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Parameter \"" _STR(m_param) "\" is null.", m_msg); \
		return m_retval;                                                                                                \
	} else                                                                                                              \
		((void)0)

/**
 * Same as `ERR_FAIL_NULL_V_MSG` but also notifies the editor.
 */
#define ERR_FAIL_NULL_V_EDMSG(m_param, m_retval, m_msg)                                                                       \
	if (unlikely(m_param == nullptr)) {                                                                                       \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Parameter \"" _STR(m_param) "\" is null.", m_msg, true); \
		return m_retval;                                                                                                      \
	} else                                                                                                                    \
		((void)0)

/**
 * Try using `ERR_FAIL_COND_MSG`.
 * Only use this macro if there is no sensible error message.
 * If checking for null use ERR_FAIL_NULL_MSG instead.
 * If checking index bounds use ERR_FAIL_INDEX_MSG instead.
 *
 * Ensures `m_cond` is false.
 * If `m_cond` is true, the current function returns.
 */
#define ERR_FAIL_COND(m_cond)                                                                                   \
	if (unlikely(m_cond)) {                                                                                     \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Condition \"" _STR(m_cond) "\" is true."); \
		return;                                                                                                 \
	} else                                                                                                      \
		((void)0)

/**
 * Ensures `m_cond` is false.
 * If `m_cond` is true, prints `m_msg` and the current function returns.
 *
 * If checking for null use ERR_FAIL_NULL_MSG instead.
 * If checking index bounds use ERR_FAIL_INDEX_MSG instead.
 */
#define ERR_FAIL_COND_MSG(m_cond, m_msg)                                                                               \
	if (unlikely(m_cond)) {                                                                                            \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Condition \"" _STR(m_cond) "\" is true.", m_msg); \
		return;                                                                                                        \
	} else                                                                                                             \
		((void)0)

/**
 * Same as `ERR_FAIL_COND_MSG` but also notifies the editor.
 */
#define ERR_FAIL_COND_EDMSG(m_cond, m_msg)                                                                                   \
	if (unlikely(m_cond)) {                                                                                                  \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Condition \"" _STR(m_cond) "\" is true.", m_msg, true); \
		return;                                                                                                              \
	} else                                                                                                                   \
		((void)0)

/**
 * Try using `ERR_FAIL_COND_V_MSG`.
 * Only use this macro if there is no sensible error message.
 * If checking for null use ERR_FAIL_NULL_V_MSG instead.
 * If checking index bounds use ERR_FAIL_INDEX_V_MSG instead.
 *
 * Ensures `m_cond` is false.
 * If `m_cond` is true, the current function returns `m_retval`.
 */
#define ERR_FAIL_COND_V(m_cond, m_retval)                                                                                                  \
	if (unlikely(m_cond)) {                                                                                                                \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Condition \"" _STR(m_cond) "\" is true. Returning: " _STR(m_retval)); \
		return m_retval;                                                                                                                   \
	} else                                                                                                                                 \
		((void)0)

/**
 * Ensures `m_cond` is false.
 * If `m_cond` is true, prints `m_msg` and the current function returns `m_retval`.
 *
 * If checking for null use ERR_FAIL_NULL_V_MSG instead.
 * If checking index bounds use ERR_FAIL_INDEX_V_MSG instead.
 */
#define ERR_FAIL_COND_V_MSG(m_cond, m_retval, m_msg)                                                                                              \
	if (unlikely(m_cond)) {                                                                                                                       \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Condition \"" _STR(m_cond) "\" is true. Returning: " _STR(m_retval), m_msg); \
		return m_retval;                                                                                                                          \
	} else                                                                                                                                        \
		((void)0)

/**
 * Same as `ERR_FAIL_COND_V_MSG` but also notifies the editor.
 */
#define ERR_FAIL_COND_V_EDMSG(m_cond, m_retval, m_msg)                                                                                                  \
	if (unlikely(m_cond)) {                                                                                                                             \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Condition \"" _STR(m_cond) "\" is true. Returning: " _STR(m_retval), m_msg, true); \
		return m_retval;                                                                                                                                \
	} else                                                                                                                                              \
		((void)0)

/**
 * Try using `ERR_CONTINUE_MSG`.
 * Only use this macro if there is no sensible error message.
 *
 * Ensures `m_cond` is false.
 * If `m_cond` is true, the current loop continues.
 */
#define ERR_CONTINUE(m_cond)                                                                                                \
	if (unlikely(m_cond)) {                                                                                                 \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Condition \"" _STR(m_cond) "\" is true. Continuing."); \
		continue;                                                                                                           \
	} else                                                                                                                  \
		((void)0)

/**
 * Ensures `m_cond` is false.
 * If `m_cond` is true, prints `m_msg` and the current loop continues.
 */
#define ERR_CONTINUE_MSG(m_cond, m_msg)                                                                                            \
	if (unlikely(m_cond)) {                                                                                                        \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Condition \"" _STR(m_cond) "\" is true. Continuing.", m_msg); \
		continue;                                                                                                                  \
	} else                                                                                                                         \
		((void)0)

/**
 * Same as `ERR_CONTINUE_MSG` but also notifies the editor.
 */
#define ERR_CONTINUE_EDMSG(m_cond, m_msg)                                                                                                \
	if (unlikely(m_cond)) {                                                                                                              \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Condition \"" _STR(m_cond) "\" is true. Continuing.", m_msg, true); \
		continue;                                                                                                                        \
	} else                                                                                                                               \
		((void)0)

/**
 * Try using `ERR_BREAK_MSG`.
 * Only use this macro if there is no sensible error message.
 *
 * Ensures `m_cond` is false.
 * If `m_cond` is true, the current loop breaks.
 */
#define ERR_BREAK(m_cond)                                                                                                 \
	if (unlikely(m_cond)) {                                                                                               \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Condition \"" _STR(m_cond) "\" is true. Breaking."); \
		break;                                                                                                            \
	} else                                                                                                                \
		((void)0)

/**
 * Ensures `m_cond` is false.
 * If `m_cond` is true, prints `m_msg` and the current loop breaks.
 */
#define ERR_BREAK_MSG(m_cond, m_msg)                                                                                             \
	if (unlikely(m_cond)) {                                                                                                      \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Condition \"" _STR(m_cond) "\" is true. Breaking.", m_msg); \
		break;                                                                                                                   \
	} else                                                                                                                       \
		((void)0)

/**
 * Same as `ERR_BREAK_MSG` but also notifies the editor.
 */
#define ERR_BREAK_EDMSG(m_cond, m_msg)                                                                                                 \
	if (unlikely(m_cond)) {                                                                                                            \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Condition \"" _STR(m_cond) "\" is true. Breaking.", m_msg, true); \
		break;                                                                                                                         \
	} else                                                                                                                             \
		((void)0)

/**
 * Try using `ERR_FAIL_COND_MSG` or `ERR_FAIL_COND_V_MSG`.
 * Only use this macro if there is no sensible fallback i.e. the error is unrecoverable, and
 * there is no sensible error message.
 *
 * Ensures `m_cond` is false.
 * If `m_cond` is true, the application crashes.
 */
#define CRASH_COND(m_cond)                                                                                             \
	if (unlikely(m_cond)) {                                                                                            \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "FATAL: Condition \"" _STR(m_cond) "\" is true."); \
		::godot::_err_flush_stdout();                                                                                  \
		GENERATE_TRAP();                                                                                               \
	} else                                                                                                             \
		((void)0)

/**
 * Try using `ERR_FAIL_COND_MSG` or `ERR_FAIL_COND_V_MSG`.
 * Only use this macro if there is no sensible fallback i.e. the error is unrecoverable.
 *
 * Ensures `m_cond` is false.
 * If `m_cond` is true, prints `m_msg` and the application crashes.
 */
#define CRASH_COND_MSG(m_cond, m_msg)                                                                                         \
	if (unlikely(m_cond)) {                                                                                                   \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "FATAL: Condition \"" _STR(m_cond) "\" is true.", m_msg); \
		::godot::_err_flush_stdout();                                                                                         \
		GENERATE_TRAP();                                                                                                      \
	} else                                                                                                                    \
		((void)0)

// Generic error macros.

/**
 * Try using `ERR_FAIL_COND_MSG` or `ERR_FAIL_MSG`.
 * Only use this macro if more complex error detection or recovery is required, and
 * there is no sensible error message.
 *
 * The current function returns.
 */
#define ERR_FAIL()                                                                              \
	if (true) {                                                                                 \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Method/function failed."); \
		return;                                                                                 \
	} else                                                                                      \
		((void)0)

/**
 * Try using `ERR_FAIL_COND_MSG`.
 * Only use this macro if more complex error detection or recovery is required.
 *
 * Prints `m_msg`, and the current function returns.
 */
#define ERR_FAIL_MSG(m_msg)                                                                            \
	if (true) {                                                                                        \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Method/function failed.", m_msg); \
		return;                                                                                        \
	} else                                                                                             \
		((void)0)

/**
 * Same as `ERR_FAIL_MSG` but also notifies the editor.
 */
#define ERR_FAIL_EDMSG(m_msg)                                                                                \
	if (true) {                                                                                              \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Method/function failed.", m_msg, true); \
		return;                                                                                              \
	} else                                                                                                   \
		((void)0)

/**
 * Try using `ERR_FAIL_COND_V_MSG` or `ERR_FAIL_V_MSG`.
 * Only use this macro if more complex error detection or recovery is required, and
 * there is no sensible error message.
 *
 * The current function returns `m_retval`.
 */
#define ERR_FAIL_V(m_retval)                                                                                               \
	if (true) {                                                                                                            \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Method/function failed. Returning: " _STR(m_retval)); \
		return m_retval;                                                                                                   \
	} else                                                                                                                 \
		((void)0)

/**
 * Try using `ERR_FAIL_COND_V_MSG`.
 * Only use this macro if more complex error detection or recovery is required.
 *
 * Prints `m_msg`, and the current function returns `m_retval`.
 */
#define ERR_FAIL_V_MSG(m_retval, m_msg)                                                                                           \
	if (true) {                                                                                                                   \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Method/function failed. Returning: " _STR(m_retval), m_msg); \
		return m_retval;                                                                                                          \
	} else                                                                                                                        \
		((void)0)

/**
 * Same as `ERR_FAIL_V_MSG` but also notifies the editor.
 */
#define ERR_FAIL_V_EDMSG(m_retval, m_msg)                                                                                               \
	if (true) {                                                                                                                         \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Method/function failed. Returning: " _STR(m_retval), m_msg, true); \
		return m_retval;                                                                                                                \
	} else                                                                                                                              \
		((void)0)

/**
 * Try using `ERR_FAIL_COND_MSG`, `ERR_FAIL_COND_V_MSG`, `ERR_CONTINUE_MSG` or `ERR_BREAK_MSG`.
 * Only use this macro at the start of a function that has not been implemented yet, or
 * if more complex error detection or recovery is required.
 *
 * Prints `m_msg`.
 */
#define ERR_PRINT(m_msg) \
	::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, m_msg)

/**
 * Same as `ERR_PRINT` but also notifies the editor.
 */
#define ERR_PRINT_ED(m_msg) \
	::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, m_msg, true)

/**
 * Prints `m_msg` once during the application lifetime.
 */
#define ERR_PRINT_ONCE(m_msg)                                                   \
	if (true) {                                                                 \
		static bool first_print = true;                                         \
		if (first_print) {                                                      \
			::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, m_msg); \
			first_print = false;                                                \
		}                                                                       \
	} else                                                                      \
		((void)0)

/**
 * Same as `ERR_PRINT_ONCE` but also notifies the editor.
 */
#define ERR_PRINT_ONCE_ED(m_msg)                                                      \
	if (true) {                                                                       \
		static bool first_print = true;                                               \
		if (first_print) {                                                            \
			::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, m_msg, true); \
			first_print = false;                                                      \
		}                                                                             \
	} else                                                                            \
		((void)0)

// Print warning message macros.

/**
 * Prints `m_msg`.
 *
 * If warning about deprecated usage, use `WARN_DEPRECATED` or `WARN_DEPRECATED_MSG` instead.
 */
#define WARN_PRINT(m_msg) \
	::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, m_msg, false, true)

/**
 * Same as `WARN_PRINT` but also notifies the editor.
 */
#define WARN_PRINT_ED(m_msg) \
	::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, m_msg, true, true)

/**
 * Prints `m_msg` once during the application lifetime.
 *
 * If warning about deprecated usage, use `WARN_DEPRECATED` or `WARN_DEPRECATED_MSG` instead.
 */
#define WARN_PRINT_ONCE(m_msg)                                                               \
	if (true) {                                                                              \
		static bool first_print = true;                                                      \
		if (first_print) {                                                                   \
			::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, m_msg, false, true); \
			first_print = false;                                                             \
		}                                                                                    \
	} else                                                                                   \
		((void)0)

/**
 * Same as `WARN_PRINT_ONCE` but also notifies the editor.
 */
#define WARN_PRINT_ONCE_ED(m_msg)                                                           \
	if (true) {                                                                             \
		static bool first_print = true;                                                     \
		if (first_print) {                                                                  \
			::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, m_msg, true, true); \
			first_print = false;                                                            \
		}                                                                                   \
	} else                                                                                  \
		((void)0)

// Print deprecated warning message macros.

/**
 * Warns that the current function is deprecated.
 */
#define WARN_DEPRECATED                                                                                                                                     \
	if (true) {                                                                                                                                             \
		static std::atomic<bool> warning_shown;                                                                                                             \
		if (!warning_shown.load()) {                                                                                                                        \
			::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "This method has been deprecated and will be removed in the future.", false, true); \
			warning_shown.store(true);                                                                                                                      \
		}                                                                                                                                                   \
	} else                                                                                                                                                  \
		((void)0)

/**
 * Warns that the current function is deprecated and prints `m_msg`.
 */
#define WARN_DEPRECATED_MSG(m_msg)                                                                                                                                 \
	if (true) {                                                                                                                                                    \
		static std::atomic<bool> warning_shown;                                                                                                                    \
		if (!warning_shown.load()) {                                                                                                                               \
			::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "This method has been deprecated and will be removed in the future.", m_msg, false, true); \
			warning_shown.store(true);                                                                                                                             \
		}                                                                                                                                                          \
	} else                                                                                                                                                         \
		((void)0)

/**
 * Do not use.
 * If the application should never reach this point use CRASH_NOW_MSG(m_msg) to explain why.
 *
 * The application crashes.
 */
#define CRASH_NOW()                                                                                    \
	if (true) {                                                                                        \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "FATAL: Method/function failed."); \
		::godot::_err_flush_stdout();                                                                  \
		GENERATE_TRAP();                                                                               \
	} else                                                                                             \
		((void)0)

/**
 * Only use if the application should never reach this point.
 *
 * Prints `m_msg`, and then the application crashes.
 */
#define CRASH_NOW_MSG(m_msg)                                                                                  \
	if (true) {                                                                                               \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "FATAL: Method/function failed.", m_msg); \
		::godot::_err_flush_stdout();                                                                         \
		GENERATE_TRAP();                                                                                      \
	} else                                                                                                    \
		((void)0)

/**
 * This should be a 'free' assert for program flow and should not be needed in any releases,
 *  only used in dev builds.
 */
#ifdef DEBUG_ENABLED
#define DEV_ASSERT(m_cond)                                                                                                       \
	if (unlikely(!(m_cond))) {                                                                                                   \
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "FATAL: DEV_ASSERT failed  \"" _STR(m_cond) "\" is false."); \
		::godot::_err_flush_stdout();                                                                                            \
		GENERATE_TRAP();                                                                                                         \
	} else                                                                                                                       \
		((void)0)
#else
#define DEV_ASSERT(m_cond)
#endif

/**
 * Gives an error message when a method bind is invalid (likely the hash changed).
 * Avoids crashing the application in this case. It's not free, so it's debug only.
 */
#ifdef DEBUG_ENABLED
#define CHECK_METHOD_BIND_RET(m_mb, m_ret)                                                                         \
	if (unlikely(!m_mb)) {                                                                                         \
		ERR_PRINT_ONCE("Method bind was not found. Likely the engine method changed to an incompatible version."); \
		return m_ret;                                                                                              \
	} else                                                                                                         \
		((void)0)

#define CHECK_METHOD_BIND(m_mb)                                                                                    \
	if (unlikely(!m_mb)) {                                                                                         \
		ERR_PRINT_ONCE("Method bind was not found. Likely the engine method changed to an incompatible version."); \
		return;                                                                                                    \
	} else                                                                                                         \
		((void)0)
#else
#define CHECK_METHOD_BIND_RET(m_mb, m_ret)
#define CHECK_METHOD_BIND(m_mb)
#endif

#endif
#endif // GODOT_ERROR_MACROS_HPP
