/*************************************************************************/
/*  GodotProfiling.hpp                                                   */
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

#ifndef GODOT_PROFILING_HPP
#define GODOT_PROFILING_HPP

#include "OS.hpp"

namespace godot {

class FunctionProfiling {
	char signature[1024];
	uint64_t ticks;

public:
	FunctionProfiling(const char *p_function, const int p_line) {
		snprintf(signature, 1024, "::%d::%s", p_line, p_function);
		ticks = OS::get_singleton()->get_ticks_usec();
	}
	~FunctionProfiling() {
		uint64_t t = OS::get_singleton()->get_ticks_usec() - ticks;
		if (t > 0) {
			Godot::gdnative_profiling_add_data(signature, t);
		}
	}
};

} // namespace godot

#ifdef DEBUG_ENABLED
#define GODOT_PROFILING_FUNCTION FunctionProfiling __function_profiling(__FUNCTION__, __LINE__);
#else
#define GODOT_PROFILING_FUNCTION
#endif

#endif
