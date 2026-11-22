/**************************************************************************/
/*  engine_ptrcall.hpp                                                    */
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

#include <gdextension_interface.h>

#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/core/object.hpp>
#include <godot_cpp/godot.hpp>

#include <array>

namespace godot {

namespace internal {

/**
 * Calls an engine class method that returns an object and retrieves the C++ wrapper for the returned engine pointer. Returns null when the engine returns no object.
 *
 * **Used for** returning the child node pointer from `godot::Node::get_node()`.
 *
 * - `O` — The wrapper type declared for the method's return value.
 * - `instance` — The underlying engine object pointer used by the method.
 *
 * - `mb` — Resolved Godot method binding to call.
 * - `Args` — Types of the ABI argument pointers in call order.
 * - `args` — Addresses of argument values already encoded for the ABI.
 *
 * ```cpp
 * // In the generated Node::get_node() wrapper, after resolving the method bind.
 * return internal::_call_native_mb_ret_obj<Node>(_gde_method_bind, _owner, &p_path);
 * ```
 */
template <typename O, typename... Args>
O *_call_native_mb_ret_obj(const GDExtensionMethodBindPtr mb, void *instance, const Args &...args) {
	GodotObject *ret = nullptr;
	std::array<GDExtensionConstTypePtr, sizeof...(Args)> mb_args = { { (GDExtensionConstTypePtr)args... } };
	::godot::gdextension_interface::object_method_bind_ptrcall(mb, instance, mb_args.data(), &ret);
	if (ret == nullptr) {
		return nullptr;
	}
	return reinterpret_cast<O *>(::godot::internal::get_object_instance_binding(ret));
}

/**
 * Calls an engine class method through its method bind. Receives the result using `godot::PtrToArg<R>::EncodeT` and converts it to the declared C++ return type.
 *
 * **Used for** returning values such as the `godot::StringName` produced by `godot::Node::get_name()`.
 *
 * - `R` — Declared C++ return type. Its pointer-call adapter selects the ABI storage type.
 * - `mb` — Resolved Godot method binding to call.
 * - `instance` — Engine object that receives the call, or null for a static call.
 * - `Args` — Types of the ABI argument pointers in call order.
 * - `args` — Addresses of argument values already encoded for the ABI.
 *
 * ```cpp
 * // In the generated Node::get_name() wrapper.
 * return internal::_call_native_mb_ret<StringName>(_gde_method_bind, _owner);
 * ```
 */
template <typename R, typename... Args>
R _call_native_mb_ret(const GDExtensionMethodBindPtr mb, void *instance, const Args &...args) {
	typename PtrToArg<R>::EncodeT ret;
	std::array<GDExtensionConstTypePtr, sizeof...(Args)> mb_args = { { (GDExtensionConstTypePtr)args... } };
	::godot::gdextension_interface::object_method_bind_ptrcall(mb, instance, mb_args.data(), &ret);
	return static_cast<R>(ret);
}

/**
 * Calls an engine class method with ABI argument pointers and a null return slot.
 *
 * **Used for** calling setters such as `godot::Node::set_name()` on their engine instances.
 *
 * - `mb` — Resolved Godot method binding to call.
 * - `instance` — Engine object that receives the call, or null for a static call.
 * - `Args` — Types of the ABI argument pointers in call order.
 * - `args` — Addresses of argument values already encoded for the ABI.
 *
 * ```cpp
 * // In the generated Node::set_name() wrapper.
 * internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_name);
 * ```
 */
template <typename... Args>
void _call_native_mb_no_ret(const GDExtensionMethodBindPtr mb, void *instance, const Args &...args) {
	std::array<GDExtensionConstTypePtr, sizeof...(Args)> mb_args = { { (GDExtensionConstTypePtr)args... } };
	::godot::gdextension_interface::object_method_bind_ptrcall(mb, instance, mb_args.data(), nullptr);
}

/**
 * Calls a Godot global utility function. Receives the value in `godot::PtrToArg<R>::EncodeT` storage and converts it to the declared C++ type.
 *
 * **Used for** returning results from generated utility wrappers such as `godot::UtilityFunctions::sin()`.
 *
 * - `R` — Declared C++ return type. Its pointer-call adapter selects the ABI storage type.
 * - `func` — Resolved engine utility function pointer.
 * - `Args` — Types of the ABI argument pointers in call order.
 * - `args` — Addresses of argument values already encoded for the ABI.
 *
 * ```cpp
 * // In the generated UtilityFunctions::sin() wrapper, after encoding the input angle.
 * return internal::_call_utility_ret<double>(_gde_function, &p_angle_rad_encoded);
 * ```
 */
template <typename R, typename... Args>
R _call_utility_ret(GDExtensionPtrUtilityFunction func, const Args &...args) {
	typename PtrToArg<R>::EncodeT ret;
	std::array<GDExtensionConstTypePtr, sizeof...(Args)> mb_args = { { (GDExtensionConstTypePtr)args... } };
	func(&ret, mb_args.data(), mb_args.size());
	return static_cast<R>(ret);
}

/**
 * Calls a Godot global utility function that returns an engine object. Returns the corresponding C++ binding or null when the engine returns no object.
 *
 * **Used for** resolving an object ID to its wrapper in `godot::UtilityFunctions::instance_from_id()`.
 *
 * - `func` — Resolved engine utility function pointer.
 * - `Args` — Types of the ABI argument pointers in call order.
 * - `args` — Addresses of argument values already encoded for the ABI.
 *
 * ```cpp
 * // In the generated UtilityFunctions::instance_from_id() wrapper.
 * return internal::_call_utility_ret_obj(_gde_function, &p_instance_id_encoded);
 * ```
 */
template <typename... Args>
Object *_call_utility_ret_obj(const GDExtensionPtrUtilityFunction func, const Args &...args) {
	GodotObject *ret = nullptr;
	std::array<GDExtensionConstTypePtr, sizeof...(Args)> mb_args = { { (GDExtensionConstTypePtr)args... } };
	func(&ret, mb_args.data(), mb_args.size());
	return (Object *)::godot::internal::get_object_instance_binding(ret);
}

/**
 * Calls a Godot global utility function with ABI argument pointers and a null return slot.
 *
 * **Used for** calling procedures such as `godot::UtilityFunctions::seed()` that take arguments without returning a value.
 *
 * - `func` — Resolved engine utility function pointer.
 * - `Args` — Types of the ABI argument pointers in call order.
 * - `args` — Addresses of argument values already encoded for the ABI.
 *
 * ```cpp
 * // In the generated UtilityFunctions::seed() wrapper, after encoding the seed.
 * internal::_call_utility_no_ret(_gde_function, &p_base_encoded);
 * ```
 */
template <typename... Args>
void _call_utility_no_ret(const GDExtensionPtrUtilityFunction func, const Args &...args) {
	std::array<GDExtensionConstTypePtr, sizeof...(Args)> mb_args = { { (GDExtensionConstTypePtr)args... } };
	func(nullptr, mb_args.data(), mb_args.size());
}

} // namespace internal

} // namespace godot
