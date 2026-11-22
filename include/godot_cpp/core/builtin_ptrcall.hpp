/**************************************************************************/
/*  builtin_ptrcall.hpp                                                   */
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
#include <godot_cpp/core/object.hpp>

#include <array>

namespace godot {

namespace internal {

/**
 * Calls a built-in Variant method that returns a Godot object. Returns its C++ binding when present, or null if the engine returns no object.
 *
 * **Used for** letting generated wrappers such as `godot::Callable::get_object()` return a C++ object pointer.
 *
 * - `O` — The expected C++ wrapper type, as declared by the method binding.
 *
 * - `method` — Resolved engine entry point for the built-in method.
 * - `base` — Address of the built-in value, or null for a static method.
 * - `Args` — Types of the ABI argument pointers in call order.
 * - `args` — Addresses of argument values already encoded for the ABI.
 *
 * ```cpp
 * // In the generated Callable::get_object() wrapper.
 * return internal::_call_builtin_method_ptr_ret_obj<Object>(_method_bindings.method_get_object, (GDExtensionTypePtr)&opaque);
 * ```
 */
template <typename O, typename... Args>
O *_call_builtin_method_ptr_ret_obj(const GDExtensionPtrBuiltInMethod method, GDExtensionTypePtr base, const Args &...args) {
	GodotObject *ret = nullptr;
	std::array<GDExtensionConstTypePtr, sizeof...(Args)> call_args = { { (GDExtensionConstTypePtr)args... } };
	method(base, call_args.data(), &ret, sizeof...(Args));
	if (ret == nullptr) {
		return nullptr;
	}
	return reinterpret_cast<O *>(::godot::internal::get_object_instance_binding(ret));
}

/**
 * Constructs a built-in Godot value in the supplied storage with ABI argument pointers.
 *
 * **Used for** starting the lifetime of a value in the storage owned by a generated wrapper, such as `godot::Array`.
 *
 * - `base` — Storage for the new value. A previous value must already have been destroyed.
 *
 * - `constructor` — Resolved engine constructor for this argument signature.
 * - `Args` — Types of the ABI argument pointers in call order.
 * - `args` — Addresses of argument values already encoded for the ABI.
 *
 * ```cpp
 * // In the generated default Array constructor.
 * internal::_call_builtin_constructor(_method_bindings.constructor_0, &opaque);
 * ```
 */
template <typename... Args>
void _call_builtin_constructor(const GDExtensionPtrConstructor constructor, GDExtensionTypePtr base, Args... args) {
	std::array<GDExtensionConstTypePtr, sizeof...(Args)> call_args = { { (GDExtensionConstTypePtr)args... } };
	constructor(base, call_args.data());
}

/**
 * Calls a built-in method and returns the value written by the engine into its return slot.
 *
 * **Used for** returning a value from generated wrappers such as `godot::Array::size()`.
 *
 * - `T` — The C++ type used for the result at the GDExtension ABI.
 *
 * - `method` — Resolved engine entry point for the built-in method.
 * - `base` — Address of the built-in value, or null for a static method.
 * - `Args` — Types of the ABI argument pointers in call order.
 * - `args` — Addresses of argument values already encoded for the ABI.
 *
 * ```cpp
 * // In the generated Array::size() wrapper.
 * return internal::_call_builtin_method_ptr_ret<int64_t>(_method_bindings.method_size, (GDExtensionTypePtr)&opaque);
 * ```
 */
template <typename T, typename... Args>
T _call_builtin_method_ptr_ret(const GDExtensionPtrBuiltInMethod method, GDExtensionTypePtr base, Args... args) {
	T ret;
	std::array<GDExtensionConstTypePtr, sizeof...(Args)> call_args = { { (GDExtensionConstTypePtr)args... } };
	method(base, call_args.data(), &ret, sizeof...(Args));
	return ret;
}

/**
 * Calls a built-in Variant method with ABI arguments and a null return slot.
 *
 * **Used for** dispatching generated methods such as `godot::Array::clear()` that have no result.
 *
 * - `method` — Resolved engine entry point for the built-in method.
 * - `base` — Address of the built-in value, or null for a static method.
 * - `Args` — Types of the ABI argument pointers in call order.
 * - `args` — Addresses of argument values already encoded for the ABI.
 *
 * ```cpp
 * // In the generated Array::clear() wrapper.
 * internal::_call_builtin_method_ptr_no_ret(_method_bindings.method_clear, &opaque);
 * ```
 */
template <typename... Args>
void _call_builtin_method_ptr_no_ret(const GDExtensionPtrBuiltInMethod method, GDExtensionTypePtr base, Args... args) {
	std::array<GDExtensionConstTypePtr, sizeof...(Args)> call_args = { { (GDExtensionConstTypePtr)args... } };
	method(base, call_args.data(), nullptr, sizeof...(Args));
}

/**
 * Evaluates a built-in operator through its ABI function pointer. Unary operators receive a null right operand.
 *
 * **Used for** applying Godot's operator rules in generated wrappers, such as equality between `godot::NodePath` and `godot::Variant`.
 *
 * - `T` — ABI storage type used for the returned value.
 * - `op` — Resolved engine operator for the given operand types.
 * - `left` — Address of the left operand in ABI storage.
 * - `right` — Address of the right operand, or null for a unary operator.
 *
 * ```cpp
 * // In the generated NodePath equality operator for a Variant operand.
 * return internal::_call_builtin_operator_ptr<int8_t>(_method_bindings.operator_equal_Variant, &opaque, &p_other);
 * ```
 */
template <typename T>
T _call_builtin_operator_ptr(const GDExtensionPtrOperatorEvaluator op, GDExtensionConstTypePtr left, GDExtensionConstTypePtr right) {
	T ret;
	op(left, right, &ret);
	return ret;
}

/**
 * Reads a member of a built-in Variant type through the ABI getter and returns the value written into the result slot.
 *
 * **Used for** implementing a generated member getter when the value is stored in the engine's built-in representation.
 *
 * - `T` — ABI storage type used for the returned value.
 * - `getter` — Resolved engine getter for the requested member.
 * - `base` — Address of the built-in value containing the member.
 *
 * ```cpp
 * // In a built-in member getter, with getter resolved for the encoded base and member.
 * return internal::_call_builtin_ptr_getter<T>(getter, base);
 * ```
 */
template <typename T>
T _call_builtin_ptr_getter(const GDExtensionPtrGetter getter, GDExtensionConstTypePtr base) {
	T ret;
	getter(base, &ret);
	return ret;
}

} // namespace internal

} // namespace godot
