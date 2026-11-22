/**************************************************************************/
/*  load_proc_address.inc                                                 */
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

/**
 * Reports an initialization error using the early engine error function, with the source function, file, and line.
 *
 * - `m_msg` — Message passed to the engine's early error printer.
 */
#define ERR_PRINT_EARLY(m_msg) \
	::godot::gdextension_interface::print_error(m_msg, FUNCTION_STR, __FILE__, __LINE__, false)

/**
 * Resolves the named engine entry point and stores it in the GDExtension interface. Logs an error and returns false from the enclosing initializer if the resolver returns null.
 *
 * - `m_name` — Engine interface entry point name, used as both member and lookup string.
 * - `m_type` — Function pointer type used to store the lookup result.
 */
#define LOAD_PROC_ADDRESS(m_name, m_type)                                               \
	::godot::gdextension_interface::m_name = (m_type)p_get_proc_address(#m_name);                   \
	if (!::godot::gdextension_interface::m_name) {                                                  \
		ERR_PRINT_EARLY("Unable to load GDExtension interface function " #m_name "()"); \
		return false;                                                                   \
	}
