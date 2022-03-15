/*************************************************************************/
/*  builtin_ptrcall.hpp                                                  */
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

#ifndef GODOT_CPP_BUILTIN_PTRCALL_HPP
#define GODOT_CPP_BUILTIN_PTRCALL_HPP

#include <godot/gdnative_interface.h>

#include <array>

namespace godot {

namespace internal {

template <class... Args>
void _call_builtin_constructor(const GDNativePtrConstructor constructor, GDNativeTypePtr base, Args... args) {
	std::array<const GDNativeTypePtr, sizeof...(Args)> call_args = { { (const GDNativeTypePtr)args... } };
	constructor(base, call_args.data());
}

template <class T, class... Args>
T _call_builtin_method_ptr_ret(const GDNativePtrBuiltInMethod method, GDNativeTypePtr base, Args... args) {
	T ret;
	std::array<const GDNativeTypePtr, sizeof...(Args)> call_args = { { (const GDNativeTypePtr)args... } };
	method(base, call_args.data(), &ret, sizeof...(Args));
	return ret;
}

template <class... Args>
void _call_builtin_method_ptr_no_ret(const GDNativePtrBuiltInMethod method, GDNativeTypePtr base, Args... args) {
	std::array<const GDNativeTypePtr, sizeof...(Args)> call_args = { { (const GDNativeTypePtr)args... } };
	method(base, call_args.data(), nullptr, sizeof...(Args));
}

template <class T>
T _call_builtin_operator_ptr(const GDNativePtrOperatorEvaluator op, const GDNativeTypePtr left, const GDNativeTypePtr right) {
	T ret;
	op(left, right, &ret);
	return ret;
}

template <class T>
T _call_builtin_ptr_getter(const GDNativePtrGetter getter, const GDNativeTypePtr base) {
	T ret;
	getter(base, &ret);
	return ret;
}

} // namespace internal

} // namespace godot

#endif // ! GODOT_CPP_BUILTIN_PTRCALL_HPP
