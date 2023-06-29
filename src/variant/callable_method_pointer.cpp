/**************************************************************************/
/*  callable_method_pointer.cpp                                           */
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

#include <godot_cpp/variant/callable_method_pointer.hpp>

//#include <godot_cpp/godot.hpp>

namespace godot {

static void call_custom_callable(void *userdata, const GDExtensionConstVariantPtr *p_args, GDExtensionInt p_argument_count, GDExtensionVariantPtr r_return, GDExtensionCallError *r_error) {
	CallableCustomMethodPointerBase *callable_method_pointer = (CallableCustomMethodPointerBase *)userdata;
	callable_method_pointer->call((const Variant **)p_args, p_argument_count, *(Variant *)r_return, *r_error);
}

static void free_custom_callable(void *userdata) {
	CallableCustomMethodPointerBase *callable_method_pointer = (CallableCustomMethodPointerBase *)userdata;
	memdelete(callable_method_pointer);
}

namespace internal {

Callable create_custom_callable(CallableCustomMethodPointerBase *p_callable_method_pointer) {
	Object *object = p_callable_method_pointer->get_object();

	GDExtensionCallableCustomInfo info = {};
	info.callable_userdata = p_callable_method_pointer;
	info.token = internal::token;
	info.object = object != nullptr ? object->_owner : nullptr;
	info.call_func = &call_custom_callable;
	info.free_func = &free_custom_callable;

	Callable callable;
	::godot::internal::gdextension_interface_callable_custom_create(callable._native_ptr(), &info);
	return callable;
}

} // namespace internal

} // namespace godot
