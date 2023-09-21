/**************************************************************************/
/*  callable_method_pointer.hpp                                           */
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

#ifndef GODOT_CALLABLE_METHOD_POINTER_HPP
#define GODOT_CALLABLE_METHOD_POINTER_HPP

#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/variant/variant.hpp>

namespace godot {

class CallableCustomMethodPointerBase {
public:
	virtual Object *get_object() const = 0;
	virtual void call(const Variant **p_arguments, int p_argcount, Variant &r_return_value, GDExtensionCallError &r_call_error) const = 0;
};

namespace internal {

Callable create_custom_callable(CallableCustomMethodPointerBase *p_callable_method_pointer);

} // namespace internal

//
// No return value.
//

template <class T, class... P>
class CallableCustomMethodPointer : public CallableCustomMethodPointerBase {
	T *instance;
	void (T::*method)(P...);

public:
	virtual Object *get_object() const override {
		return instance;
	}

	virtual void call(const Variant **p_arguments, int p_argcount, Variant &r_return_value, GDExtensionCallError &r_call_error) const override {
		call_with_variant_args(instance, method, p_arguments, p_argcount, r_call_error);
	}

	CallableCustomMethodPointer(T *p_instance, void (T::*p_method)(P...)) {
		instance = p_instance;
		method = p_method;
	}
};

template <class T, class... P>
Callable create_custom_callable_function_pointer(T *p_instance, void (T::*p_method)(P...)) {
	typedef CallableCustomMethodPointer<T, P...> CCMP;
	CCMP *ccmp = memnew(CCMP(p_instance, p_method));
	return ::godot::internal::create_custom_callable(ccmp);
}

//
// With return value.
//

template <class T, class R, class... P>
class CallableCustomMethodPointerRet : public CallableCustomMethodPointerBase {
	T *instance;
	R(T::*method)
	(P...);

public:
	virtual Object *get_object() const override {
		return instance;
	}

	virtual void call(const Variant **p_arguments, int p_argcount, Variant &r_return_value, GDExtensionCallError &r_call_error) const override {
		call_with_variant_args_ret(instance, method, p_arguments, p_argcount, r_return_value, r_call_error);
	}

	CallableCustomMethodPointerRet(T *p_instance, R (T::*p_method)(P...)) {
		instance = p_instance;
		method = p_method;
	}
};

template <class T, class R, class... P>
Callable create_custom_callable_function_pointer(T *p_instance, R (T::*p_method)(P...)) {
	typedef CallableCustomMethodPointerRet<T, R, P...> CCMP; // Messes with memnew otherwise.
	CCMP *ccmp = memnew(CCMP(p_instance, p_method));
	return ::godot::internal::create_custom_callable(ccmp);
}

//
// Const with return value.
//

template <class T, class R, class... P>
class CallableCustomMethodPointerRetC : public CallableCustomMethodPointerBase {
	T *instance;
	R(T::*method)
	(P...) const;

public:
	virtual Object *get_object() const override {
		return instance;
	}

	virtual void call(const Variant **p_arguments, int p_argcount, Variant &r_return_value, GDExtensionCallError &r_call_error) const override {
		call_with_variant_args_retc(instance, method, p_arguments, p_argcount, r_return_value, r_call_error);
	}

	CallableCustomMethodPointerRetC(const T *p_instance, R (T::*p_method)(P...) const) {
		instance = const_cast<T *>(p_instance);
		method = p_method;
	}
};

template <class T, class R, class... P>
Callable create_custom_callable_function_pointer(const T *p_instance, R (T::*p_method)(P...) const) {
	typedef CallableCustomMethodPointerRetC<T, R, P...> CCMP; // Messes with memnew otherwise.
	CCMP *ccmp = memnew(CCMP(p_instance, p_method));
	return ::godot::internal::create_custom_callable(ccmp);
}

//
// Static method with no return value.
//

template <class... P>
class CallableCustomStaticMethodPointer : public CallableCustomMethodPointerBase {
	void (*method)(P...);

public:
	virtual Object *get_object() const override {
		return nullptr;
	}

	virtual void call(const Variant **p_arguments, int p_argcount, Variant &r_return_value, GDExtensionCallError &r_call_error) const override {
		call_with_variant_args_static_ret(method, p_arguments, p_argcount, r_return_value, r_call_error);
		r_return_value = Variant();
	}

	CallableCustomStaticMethodPointer(void (*p_method)(P...)) {
		method = p_method;
	}
};

template <class... P>
Callable create_custom_callable_static_function_pointer(void (*p_method)(P...)) {
	typedef CallableCustomStaticMethodPointer<P...> CCMP;
	CCMP *ccmp = memnew(CCMP(p_method));
	return ::godot::internal::create_custom_callable(ccmp);
}

//
// Static method with return value.
//

template <class R, class... P>
class CallableCustomStaticMethodPointerRet : public CallableCustomMethodPointerBase {
	R(*method)
	(P...);

public:
	virtual Object *get_object() const override {
		return nullptr;
	}

	virtual void call(const Variant **p_arguments, int p_argcount, Variant &r_return_value, GDExtensionCallError &r_call_error) const override {
		call_with_variant_args_static_ret(method, p_arguments, p_argcount, r_return_value, r_call_error);
	}

	CallableCustomStaticMethodPointerRet(R (*p_method)(P...)) {
		method = p_method;
	}
};

template <class R, class... P>
Callable create_custom_callable_static_function_pointer(R (*p_method)(P...)) {
	typedef CallableCustomStaticMethodPointerRet<R, P...> CCMP;
	CCMP *ccmp = memnew(CCMP(p_method));
	return ::godot::internal::create_custom_callable(ccmp);
}

//
// The API:
//

#define callable_mp(I, M) ::godot::create_custom_callable_function_pointer(I, M)
#define callable_mp_static(M) ::godot::create_custom_callable_static_function_pointer(M)

} // namespace godot

#endif // GODOT_CALLABLE_METHOD_POINTER_HPP
