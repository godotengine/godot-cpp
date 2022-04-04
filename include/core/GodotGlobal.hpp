/*************************************************************************/
/*  GodotGlobal.hpp                                                      */
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

#ifndef GODOT_GLOBAL_HPP
#define GODOT_GLOBAL_HPP

#include "Array.hpp"
#include "String.hpp"
#include <gdnative_api_struct.gen.h>

namespace godot {

extern "C" const godot_gdnative_core_api_struct *api;
extern "C" const godot_gdnative_core_1_1_api_struct *core_1_1_api;
extern "C" const godot_gdnative_core_1_2_api_struct *core_1_2_api;

extern "C" const godot_gdnative_ext_nativescript_api_struct *nativescript_api;
extern "C" const godot_gdnative_ext_nativescript_1_1_api_struct *nativescript_1_1_api;
extern "C" const godot_gdnative_ext_pluginscript_api_struct *pluginscript_api;
extern "C" const godot_gdnative_ext_android_api_struct *android_api;
extern "C" const godot_gdnative_ext_arvr_api_struct *arvr_api;
extern "C" const godot_gdnative_ext_videodecoder_api_struct *videodecoder_api;
extern "C" const godot_gdnative_ext_net_api_struct *net_api;
extern "C" const godot_gdnative_ext_net_3_2_api_struct *net_3_2_api;

extern "C" const void *gdnlib;

class Godot {
public:
	static void print(const String &message);
	static void print_warning(const String &description, const String &function, const String &file, int line);
	static void print_error(const String &description, const String &function, const String &file, int line);

	static void gdnative_init(godot_gdnative_init_options *o);
	static void gdnative_terminate(godot_gdnative_terminate_options *o);
	static void nativescript_init(void *handle);
	static void nativescript_terminate(void *handle);

	static void gdnative_profiling_add_data(const char *p_signature, uint64_t p_time);

	template <class... Args>
	static void print(const String &fmt, Args... values) {
		print(fmt.format(Array::make(values...)));
	}
};

struct _RegisterState {
	static void *nativescript_handle;
	static int language_index;
};

} // namespace godot

#endif
