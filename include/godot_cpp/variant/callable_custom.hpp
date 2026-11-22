/**************************************************************************/
/*  callable_custom.hpp                                                   */
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

#include <godot_cpp/core/object_id.hpp>
#include <godot_cpp/variant/string_name.hpp>

namespace godot {

class Object;

/**
 * The call interface shared by native custom callables. Implementations provide a call target, invoke it, and report call errors.
 *
 * ```cpp
 * // In a binding trampoline that holds a CallableCustomBase pointer.
 * target->call(args, arg_count, result, call_error);
 * ```
 */
class CallableCustomBase {
public:
	/**
	 * Returns the instance identifier associated with the callable. A callable without an object can return a default `ObjectID`.
	 *
	 * ```cpp
	 * // In a custom callable override storing the ID of its target node.
	 * ObjectID get_object() const override { return target_id; }
	 * ```
	 */
	virtual ObjectID get_object() const = 0;
	/**
	 * Reports the argument count when known. The default implementation sets `r_is_valid` to false and returns zero.
	 *
	 * ```cpp
	 * // In a custom callable that accepts one tile ID.
	 * int get_argument_count(bool &r_is_valid) const override {
	 *     r_is_valid = true;
	 *     return 1;
	 * }
	 * ```
	 */
	virtual int get_argument_count(bool &r_is_valid) const;
	/**
	 * Invokes the custom target and writes the result and call status into the supplied outputs.
	 *
	 * - `p_arguments` — The incoming argument pointers in call order.
	 * - `p_argcount` — The number of argument pointers available.
	 *
	 * ```cpp
	 * // In the binding's call trampoline, with result and error outputs supplied by Godot.
	 * callable_custom->call(args, arg_count, result, call_error);
	 * ```
	 */
	virtual void call(const Variant **p_arguments, int p_argcount, Variant &r_return_value, GDExtensionCallError &r_call_error) const = 0;
	/**
	 * Allows destruction of a derived callable through the base interface.
	 *
	 * ```cpp
	 * // In the binding's cleanup callback for a heap-allocated custom callable.
	 * memdelete(callable_custom);
	 * ```
	 */
	virtual ~CallableCustomBase() {}
};

/**
 * Defines an extension-owned callable that Godot can invoke, compare, hash, and display through a `Callable`.
 *
 * ```cpp
 * // In a preview node using a custom callable derived from CallableCustom.
 * Callable rebuild(memnew(RebuildTileCallable(tile_id)));
 * button->connect("pressed", rebuild);
 * ```
 */
class CallableCustom : public CallableCustomBase {
public:
	/**
	 * A function pointer that tests whether two custom callables of a compatible kind represent the same operation.
	 *
	 * ```cpp
	 * // In the comparison trampoline, after confirming that both callables supplied the same equality callback.
	 * CallableCustom::CompareEqualFunc equal = a->get_compare_equal_func();
	 * return equal(a, b);
	 * ```
	 */
	typedef bool (*CompareEqualFunc)(const CallableCustom *p_a, const CallableCustom *p_b);
	/**
	 * A function pointer that tests whether the first custom callable precedes the second in its ordering.
	 *
	 * ```cpp
	 * // In the comparison trampoline, after confirming that the two ordering callbacks match.
	 * CallableCustom::CompareLessFunc less = a->get_compare_less_func();
	 * return less(a, b);
	 * ```
	 */
	typedef bool (*CompareLessFunc)(const CallableCustom *p_a, const CallableCustom *p_b);

	/**
	 * Produces the hash returned by the enclosing `Callable`. Callables judged equal must produce the same hash.
	 *
	 * ```cpp
	 * // In a callable whose comparison treats identical tile IDs as equal.
	 * uint32_t hash() const override { return HashMapHasherDefault::hash(tile_id); }
	 * ```
	 */
	virtual uint32_t hash() const = 0;
	/**
	 * Provides the text Godot uses when formatting or displaying the custom callable.
	 *
	 * ```cpp
	 * // In a custom tile rebuild callable, for diagnostics.
	 * String get_as_text() const override { return "RebuildTile(" + itos(tile_id) + ")"; }
	 * ```
	 */
	virtual String get_as_text() const = 0;
	/**
	 * Supplies the equality callback. The binding calls it only when both custom callables supply the same callback address.
	 *
	 * ```cpp
	 * // In a custom callable subclass with a static compare_equal function.
	 * CompareEqualFunc get_compare_equal_func() const override { return &compare_equal; }
	 * ```
	 */
	virtual CompareEqualFunc get_compare_equal_func() const = 0;
	/**
	 * Supplies the ordering callback. The binding compares userdata addresses when the two callback addresses differ.
	 *
	 * ```cpp
	 * // In a custom callable subclass with a static compare_less function.
	 * CompareLessFunc get_compare_less_func() const override { return &compare_less; }
	 * ```
	 */
	virtual CompareLessFunc get_compare_less_func() const = 0;
	/**
	 * Checks whether the custom callable can run. By default it checks that its associated object ID resolves to a live Godot object.
	 *
	 * ```cpp
	 * // In the binding's validity trampoline.
	 * return callable_custom->is_valid();
	 * ```
	 */
	virtual bool is_valid() const;
	/**
	 * Supplies the object ID recorded for this custom callable. The default validity check also uses this ID.
	 *
	 * ```cpp
	 * // In the constructor that wraps this object in a Callable.
	 * info.object_id = p_callable_custom->get_object();
	 * ```
	 */
	virtual ObjectID get_object() const = 0;
	/**
	 * Implements invocation through the `Callable` wrapper. On failure, set the call error to describe why invocation failed.
	 *
	 * ```cpp
	 * // In a custom callable that requires one argument, inside its call() override.
	 * if (p_argcount == 0) {
	 *     r_call_error.error = GDEXTENSION_CALL_ERROR_TOO_FEW_ARGUMENTS;
	 *     r_call_error.expected = 1;
	 *     return;
	 * }
	 * ```
	 */
	virtual void call(const Variant **p_arguments, int p_argcount, Variant &r_return_value, GDExtensionCallError &r_call_error) const = 0;
};

} // namespace godot
