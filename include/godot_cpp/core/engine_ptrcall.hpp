/*************************************************************************/
/*  engine_ptrcall.hpp                                                   */
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

#ifndef GODOT_CPP_ENGINE_PTRCALL_HPP
#define GODOT_CPP_ENGINE_PTRCALL_HPP

#include <godot/gdnative_interface.h>

#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/core/object.hpp>
#include <godot_cpp/godot.hpp>

#include <array>

namespace godot {

namespace internal {

template <class O, class... Args>
O *_call_native_mb_ret_obj(const GDNativeMethodBindPtr mb, void *instance, const Args &...args) {
	GodotObject *ret = nullptr;
	std::array<const GDNativeTypePtr, sizeof...(Args)> mb_args = { { (const GDNativeTypePtr)args... } };
	internal::gdn_interface->object_method_bind_ptrcall(mb, instance, mb_args.data(), &ret);
	return reinterpret_cast<O *>(internal::gdn_interface->object_get_instance_binding(ret, internal::token, &O::___binding_callbacks));
}

template <class R, class... Args>
R _call_native_mb_ret(const GDNativeMethodBindPtr mb, void *instance, const Args &...args) {
	R ret;
	std::array<const GDNativeTypePtr, sizeof...(Args)> mb_args = { { (const GDNativeTypePtr)args... } };
	internal::gdn_interface->object_method_bind_ptrcall(mb, instance, mb_args.data(), &ret);
	return ret;
}

template <class... Args>
void _call_native_mb_no_ret(const GDNativeMethodBindPtr mb, void *instance, const Args &...args) {
	std::array<const GDNativeTypePtr, sizeof...(Args)> mb_args = { { (const GDNativeTypePtr)args... } };
	internal::gdn_interface->object_method_bind_ptrcall(mb, instance, mb_args.data(), nullptr);
}

template <class R, class... Args>
R _call_utility_ret(GDNativePtrUtilityFunction func, const Args &...args) {
	R ret;
	std::array<const GDNativeTypePtr, sizeof...(Args)> mb_args = { { (const GDNativeTypePtr)args... } };
	func(&ret, mb_args.data(), mb_args.size());
	return ret;
}

template <class... Args>
Object *_call_utility_ret_obj(const GDNativePtrUtilityFunction func, void *instance, const Args &...args) {
	GodotObject *ret = nullptr;
	std::array<const GDNativeTypePtr, sizeof...(Args)> mb_args = { { (const GDNativeTypePtr)args... } };
	func(&ret, mb_args.data(), mb_args.size());
	return (Object *)internal::gdn_interface->object_get_instance_binding(ret, internal::token, &Object::___binding_callbacks);
}

template <class... Args>
void _call_utility_no_ret(const GDNativePtrUtilityFunction func, const Args &...args) {
	std::array<const GDNativeTypePtr, sizeof...(Args)> mb_args = { { (const GDNativeTypePtr)args... } };
	func(nullptr, mb_args.data(), mb_args.size());
}

} // namespace internal

} // namespace godot

#endif // ! GODOT_CPP_ENGINE_PTRCALL_HPP
