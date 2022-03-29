/*************************************************************************/
/*  method_bind.hpp                                                      */
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

#ifndef GODOT_CPP_METHOD_BIND_HPP
#define GODOT_CPP_METHOD_BIND_HPP

#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/core/type_info.hpp>

#include <godot_cpp/core/memory.hpp>

#include <godot/gdnative_interface.h>

#include <godot_cpp/classes/global_constants.hpp>

#include <string>
#include <vector>

#include <iostream>

namespace godot {

class MethodBind {
	const char *name = nullptr;
	const char *instance_class = nullptr;
	int argument_count = 0;
	uint32_t hint_flags = METHOD_FLAGS_DEFAULT;

	bool _is_const = false;
	bool _has_return = false;

	std::vector<std::string> argument_names;
	GDNativeVariantType *argument_types = nullptr;
	std::vector<Variant> default_arguments;

protected:
	virtual GDNativeVariantType gen_argument_type(int p_arg) const = 0;
	virtual GDNativePropertyInfo gen_argument_type_info(int p_arg) const = 0;
	void generate_argument_types(int p_count);
	void set_const(bool p_const);
	void set_return(bool p_return);
	void set_argument_count(int p_count);

public:
	const char *get_name() const;
	void set_name(const char *p_name);
	_FORCE_INLINE_ int get_default_argument_count() const { return (int)default_arguments.size(); }
	_FORCE_INLINE_ const std::vector<Variant> &get_default_arguments() const { return default_arguments; }
	_FORCE_INLINE_ Variant has_default_argument(int p_arg) const {
		int idx = p_arg - (argument_count - (int)default_arguments.size());

		if (idx < 0 || idx >= default_arguments.size()) {
			return false;
		} else {
			return true;
		}
	}
	_FORCE_INLINE_ Variant get_default_argument(int p_arg) const {
		int idx = p_arg - (argument_count - (int)default_arguments.size());

		if (idx < 0 || idx >= default_arguments.size()) {
			return Variant();
		} else {
			return default_arguments[idx];
		}
	}
	_FORCE_INLINE_ const char *get_instance_class() const { return instance_class; }
	_FORCE_INLINE_ void set_instance_class(const char *p_class) { instance_class = p_class; }

	_FORCE_INLINE_ int get_argument_count() const { return argument_count; };
	_FORCE_INLINE_ bool is_const() const { return _is_const; }
	_FORCE_INLINE_ bool has_return() const { return _has_return; }
	_FORCE_INLINE_ uint32_t get_hint_flags() const { return hint_flags; }
	_FORCE_INLINE_ void set_hint_flags(uint32_t p_hint_flags) { hint_flags = p_hint_flags; }
	void set_argument_names(const std::vector<std::string> &p_names);
	std::vector<std::string> get_argument_names() const;
	void set_default_arguments(const std::vector<Variant> &p_default_arguments) { default_arguments = p_default_arguments; }

	_FORCE_INLINE_ GDNativeVariantType get_argument_type(int p_argument) const {
		ERR_FAIL_COND_V(p_argument < -1 || p_argument > argument_count, GDNATIVE_VARIANT_TYPE_NIL);
		return argument_types[p_argument + 1];
	}

	GDNativePropertyInfo get_argument_info(int p_argument) const;
	virtual GDNativeExtensionClassMethodArgumentMetadata get_argument_metadata(int p_argument) const = 0;

	virtual Variant call(GDExtensionClassInstancePtr p_instance, const GDNativeVariantPtr *p_args, const GDNativeInt p_argument_count, GDNativeCallError &r_error) const = 0;
	virtual void ptrcall(GDExtensionClassInstancePtr p_instance, const GDNativeTypePtr *p_args, GDNativeTypePtr r_return) const = 0;

	// Extension info.
	static GDNativeVariantType bind_get_argument_type(void *p_method_userdata, int32_t p_argument);
	static void bind_get_argument_info(void *p_method_userdata, int32_t p_argument, GDNativePropertyInfo *r_info);
	static GDNativeExtensionClassMethodArgumentMetadata bind_get_argument_metadata(void *p_method_userdata, int32_t p_argument);

	static void bind_call(void *p_method_userdata, GDExtensionClassInstancePtr p_instance, const GDNativeVariantPtr *p_args, const GDNativeInt p_argument_count, GDNativeVariantPtr r_return, GDNativeCallError *r_error);
	static void bind_ptrcall(void *p_method_userdata, GDExtensionClassInstancePtr p_instance, const GDNativeTypePtr *p_args, GDNativeTypePtr r_return);

	virtual ~MethodBind();
};

template <class Derived, class T, class R, bool should_returns>
class MethodBindVarArgBase : public MethodBind {
protected:
	R(T::*method)
	(const Variant **, GDNativeInt, GDNativeCallError &);
	MethodInfo method_info;

public:
	virtual GDNativePropertyInfo gen_argument_type_info(int p_arg) const {
		if (p_arg < 0) {
			return _gen_return_type_info();
		} else if (p_arg < method_info.arguments.size()) {
			return method_info.arguments[p_arg];
		} else {
			return PropertyInfo(Variant::NIL, "vararg", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_DEFAULT | PROPERTY_USAGE_NIL_IS_VARIANT);
		}
	}

	virtual GDNativeVariantType gen_argument_type(int p_arg) const {
		return static_cast<GDNativeVariantType>(gen_argument_type_info(p_arg).type);
	}

	virtual GDNativeExtensionClassMethodArgumentMetadata get_argument_metadata(int) const {
		return GDNATIVE_EXTENSION_METHOD_ARGUMENT_METADATA_NONE;
	}

	virtual void ptrcall(GDExtensionClassInstancePtr p_instance, const GDNativeTypePtr *p_args, GDNativeTypePtr r_return) const {
		ERR_FAIL(); // Can't call.
	}

	virtual bool is_const() const { return false; }

	virtual bool is_vararg() const { return true; }

	MethodBindVarArgBase(
			R (T::*p_method)(const Variant **, GDNativeInt, GDNativeCallError &),
			const MethodInfo &p_method_info,
			bool p_return_nil_is_variant) :
			method(p_method), method_info(p_method_info) {
		set_argument_count(method_info.arguments.size());
		if (method_info.arguments.size()) {
			std::vector<std::string> names;
			names.reserve(method_info.arguments.size());
			for (int i = 0; i < method_info.arguments.size(); i++) {
				names.push_back(method_info.arguments[i].name);
			}

			set_argument_names(names);
		}

		if (p_return_nil_is_variant) {
			method_info.return_val.usage |= PROPERTY_USAGE_NIL_IS_VARIANT;
		}
		generate_argument_types((int)method_info.arguments.size());
		set_return(should_returns);
	}

private:
	GDNativePropertyInfo _gen_return_type_info() const {
		return reinterpret_cast<const Derived *>(this)->_gen_return_type_info_impl();
	}
};

template <class T>
class MethodBindVarArgT : public MethodBindVarArgBase<MethodBindVarArgT<T>, T, void, false> {
	friend class MethodBindVarArgBase<MethodBindVarArgT<T>, T, void, false>;

public:
	virtual Variant call(GDExtensionClassInstancePtr p_instance, const GDNativeVariantPtr *p_args, const GDNativeInt p_argument_count, GDNativeCallError &r_error) const {
		(static_cast<T *>(p_instance)->*MethodBindVarArgBase<MethodBindVarArgT<T>, T, void, false>::method)((const Variant **)p_args, p_argument_count, r_error);
		return {};
	}

	MethodBindVarArgT(
			void (T::*p_method)(const Variant **, GDNativeInt, GDNativeCallError &),
			const MethodInfo &p_method_info,
			bool p_return_nil_is_variant) :
			MethodBindVarArgBase<MethodBindVarArgT<T>, T, void, false>(p_method, p_method_info, p_return_nil_is_variant) {
	}

private:
	GDNativePropertyInfo _gen_return_type_info_impl() const {
		return {};
	}
};

template <class T>
MethodBind *create_vararg_method_bind(void (T::*p_method)(const Variant **, GDNativeInt, GDNativeCallError &), const MethodInfo &p_info, bool p_return_nil_is_variant) {
	MethodBind *a = memnew((MethodBindVarArgT<T>)(p_method, p_info, p_return_nil_is_variant));
	a->set_instance_class(T::get_class_static());
	return a;
}

template <class T, class R>
class MethodBindVarArgTR : public MethodBindVarArgBase<MethodBindVarArgTR<T, R>, T, R, true> {
	friend class MethodBindVarArgBase<MethodBindVarArgTR<T, R>, T, R, true>;

public:
	virtual Variant call(GDExtensionClassInstancePtr p_instance, const GDNativeVariantPtr *p_args, const GDNativeInt p_argument_count, GDNativeCallError &r_error) const {
		return (static_cast<T *>(p_instance)->*MethodBindVarArgBase<MethodBindVarArgTR<T, R>, T, R, true>::method)((const Variant **)p_args, p_argument_count, r_error);
	}

	MethodBindVarArgTR(
			R (T::*p_method)(const Variant **, GDNativeInt, GDNativeCallError &),
			const MethodInfo &p_info,
			bool p_return_nil_is_variant) :
			MethodBindVarArgBase<MethodBindVarArgTR<T, R>, T, R, true>(p_method, p_info, p_return_nil_is_variant) {
	}

private:
	GDNativePropertyInfo _gen_return_type_info_impl() const {
		return GetTypeInfo<R>::get_class_info();
	}
};

template <class T, class R>
MethodBind *create_vararg_method_bind(R (T::*p_method)(const Variant **, GDNativeInt, GDNativeCallError &), const MethodInfo &p_info, bool p_return_nil_is_variant) {
	MethodBind *a = memnew((MethodBindVarArgTR<T, R>)(p_method, p_info, p_return_nil_is_variant));
	a->set_instance_class(T::get_class_static());
	return a;
}

#ifndef TYPED_METHOD_BIND
class ___UnexistingClass;
#define MB_T ___UnexistingClass
#else
#define MB_T T
#endif

// No return, not const.

#ifdef TYPED_METHOD_BIND
template <class T, class... P>
#else
template <class... P>
#endif // TYPED_METHOD_BIND
class MethodBindT : public MethodBind {
	void (MB_T::*method)(P...);

protected:
// GCC raises warnings in the case P = {} as the comparison is always false...
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wlogical-op"
#endif
	virtual GDNativeVariantType gen_argument_type(int p_arg) const {
		if (p_arg >= 0 && p_arg < (int)sizeof...(P)) {
			return call_get_argument_type<P...>(p_arg);
		} else {
			return GDNATIVE_VARIANT_TYPE_NIL;
		}
	}

	virtual GDNativePropertyInfo gen_argument_type_info(int p_arg) const {
		GDNativePropertyInfo pi;
		if (p_arg >= 0 && p_arg < (int)sizeof...(P)) {
			call_get_argument_type_info<P...>(p_arg, pi);
		} else {
			pi = PropertyInfo();
		}
		return pi;
	}
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif

public:
	virtual GDNativeExtensionClassMethodArgumentMetadata get_argument_metadata(int p_argument) const {
		return call_get_argument_metadata<P...>(p_argument);
	}

	virtual Variant call(GDExtensionClassInstancePtr p_instance, const GDNativeVariantPtr *p_args, const GDNativeInt p_argument_count, GDNativeCallError &r_error) const {
#ifdef TYPED_METHOD_BIND
		call_with_variant_args_dv(static_cast<T *>(p_instance), method, p_args, (int)p_argument_count, r_error, get_default_arguments());
#else
		call_with_variant_args_dv(reinterpret_cast<MB_T *>(p_instance), method, p_args, p_argument_count, r_error, get_default_arguments());
#endif
		return Variant();
	}
	virtual void ptrcall(GDExtensionClassInstancePtr p_instance, const GDNativeTypePtr *p_args, GDNativeTypePtr r_ret) const {
#ifdef TYPED_METHOD_BIND
		call_with_ptr_args<T, P...>(static_cast<T *>(p_instance), method, p_args, nullptr);
#else
		call_with_ptr_args<MB_T, P...>(reinterpret_cast<MB_T *>(p_instance), method, p_args, nullptr);
#endif // TYPED_METHOD_BIND
	}

	MethodBindT(void (MB_T::*p_method)(P...)) {
		method = p_method;
		generate_argument_types(sizeof...(P));
		set_argument_count(sizeof...(P));
	}
};

template <class T, class... P>
MethodBind *create_method_bind(void (T::*p_method)(P...)) {
#ifdef TYPED_METHOD_BIND
	MethodBind *a = memnew((MethodBindT<T, P...>)(p_method));
#else
	MethodBind *a = memnew((MethodBindT<P...>)(reinterpret_cast<void (MB_T::*)(P...)>(p_method)));
#endif // TYPED_METHOD_BIND
	a->set_instance_class(T::get_class_static());
	return a;
}

// No return, const.

#ifdef TYPED_METHOD_BIND
template <class T, class... P>
#else
template <class... P>
#endif // TYPED_METHOD_BIND
class MethodBindTC : public MethodBind {
	void (MB_T::*method)(P...) const;

protected:
// GCC raises warnings in the case P = {} as the comparison is always false...
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wlogical-op"
#endif
	virtual GDNativeVariantType gen_argument_type(int p_arg) const {
		if (p_arg >= 0 && p_arg < (int)sizeof...(P)) {
			return call_get_argument_type<P...>(p_arg);
		} else {
			return GDNATIVE_VARIANT_TYPE_NIL;
		}
	}

	virtual GDNativePropertyInfo gen_argument_type_info(int p_arg) const {
		GDNativePropertyInfo pi;
		if (p_arg >= 0 && p_arg < (int)sizeof...(P)) {
			call_get_argument_type_info<P...>(p_arg, pi);
		} else {
			pi = PropertyInfo();
		}
		return pi;
	}
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif

public:
	virtual GDNativeExtensionClassMethodArgumentMetadata get_argument_metadata(int p_argument) const {
		return call_get_argument_metadata<P...>(p_argument);
	}

	virtual Variant call(GDExtensionClassInstancePtr p_instance, const GDNativeVariantPtr *p_args, const GDNativeInt p_argument_count, GDNativeCallError &r_error) const {
#ifdef TYPED_METHOD_BIND
		call_with_variant_argsc_dv(static_cast<T *>(p_instance), method, p_args, (int)p_argument_count, r_error, get_default_arguments());
#else
		call_with_variant_argsc_dv(reinterpret_cast<MB_T *>(p_instance), method, p_args, p_argument_count, r_error, get_default_arguments());
#endif
		return Variant();
	}
	virtual void ptrcall(GDExtensionClassInstancePtr p_instance, const GDNativeTypePtr *p_args, GDNativeTypePtr r_ret) const {
#ifdef TYPED_METHOD_BIND
		call_with_ptr_args<T, P...>(static_cast<T *>(p_instance), method, p_args, nullptr);
#else
		call_with_ptr_args<MB_T, P...>(reinterpret_cast<MB_T *>(p_instance), method, p_args, nullptr);
#endif // TYPED_METHOD_BIND
	}

	MethodBindTC(void (MB_T::*p_method)(P...) const) {
		method = p_method;
		generate_argument_types(sizeof...(P));
		set_argument_count(sizeof...(P));
	}
};

template <class T, class... P>
MethodBind *create_method_bind(void (T::*p_method)(P...) const) {
#ifdef TYPED_METHOD_BIND
	MethodBind *a = memnew((MethodBindTC<T, P...>)(p_method));
#else
	MethodBind *a = memnew((MethodBindTC<P...>)(reinterpret_cast<void (MB_T::*)(P...) const>(p_method)));
#endif // TYPED_METHOD_BIND
	a->set_instance_class(T::get_class_static());
	return a;
}

// Return, not const.

#ifdef TYPED_METHOD_BIND
template <class T, class R, class... P>
#else
template <class R, class... P>
#endif // TYPED_METHOD_BIND
class MethodBindTR : public MethodBind {
	R(MB_T::*method)
	(P...);

protected:
// GCC raises warnings in the case P = {} as the comparison is always false...
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wlogical-op"
#endif
	virtual GDNativeVariantType gen_argument_type(int p_arg) const {
		if (p_arg >= 0 && p_arg < (int)sizeof...(P)) {
			return call_get_argument_type<P...>(p_arg);
		} else {
			return GetTypeInfo<R>::VARIANT_TYPE;
		}
	}

	virtual GDNativePropertyInfo gen_argument_type_info(int p_arg) const {
		if (p_arg >= 0 && p_arg < (int)sizeof...(P)) {
			GDNativePropertyInfo pi;
			call_get_argument_type_info<P...>(p_arg, pi);
			return pi;
		} else {
			return GetTypeInfo<R>::get_class_info();
		}
	}
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif

public:
	virtual GDNativeExtensionClassMethodArgumentMetadata get_argument_metadata(int p_argument) const {
		if (p_argument >= 0) {
			return call_get_argument_metadata<P...>(p_argument);
		} else {
			return GetTypeInfo<R>::METADATA;
		}
	}

	virtual Variant call(GDExtensionClassInstancePtr p_instance, const GDNativeVariantPtr *p_args, const GDNativeInt p_argument_count, GDNativeCallError &r_error) const {
		Variant ret;
#ifdef TYPED_METHOD_BIND
		call_with_variant_args_ret_dv(static_cast<T *>(p_instance), method, p_args, (int)p_argument_count, ret, r_error, get_default_arguments());
#else
		call_with_variant_args_ret_dv((MB_T *)p_instance, method, p_args, p_argument_count, ret, r_error, get_default_arguments());
#endif
		return ret;
	}
	virtual void ptrcall(GDExtensionClassInstancePtr p_instance, const GDNativeTypePtr *p_args, GDNativeTypePtr r_ret) const {
#ifdef TYPED_METHOD_BIND
		call_with_ptr_args<T, R, P...>(static_cast<T *>(p_instance), method, p_args, r_ret);
#else
		call_with_ptr_args<MB_T, R, P...>(reinterpret_cast<MB_T *>(p_instance), method, p_args, r_ret);
#endif // TYPED_METHOD_BIND
	}

	MethodBindTR(R (MB_T::*p_method)(P...)) {
		method = p_method;
		generate_argument_types(sizeof...(P));
		set_argument_count(sizeof...(P));
		set_return(true);
	}
};

template <class T, class R, class... P>
MethodBind *create_method_bind(R (T::*p_method)(P...)) {
#ifdef TYPED_METHOD_BIND
	MethodBind *a = memnew((MethodBindTR<T, R, P...>)(p_method));
#else
	MethodBind *a = memnew((MethodBindTR<R, P...>)(reinterpret_cast<R (MB_T::*)(P...)>(p_method)));
#endif // TYPED_METHOD_BIND
	a->set_instance_class(T::get_class_static());
	return a;
}

// Return, const.

#ifdef TYPED_METHOD_BIND
template <class T, class R, class... P>
#else
template <class R, class... P>
#endif // TYPED_METHOD_BIND
class MethodBindTRC : public MethodBind {
	R(MB_T::*method)
	(P...) const;

protected:
// GCC raises warnings in the case P = {} as the comparison is always false...
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wlogical-op"
#endif
	virtual GDNativeVariantType gen_argument_type(int p_arg) const {
		if (p_arg >= 0 && p_arg < (int)sizeof...(P)) {
			return call_get_argument_type<P...>(p_arg);
		} else {
			return GetTypeInfo<R>::VARIANT_TYPE;
		}
	}

	virtual GDNativePropertyInfo gen_argument_type_info(int p_arg) const {
		if (p_arg >= 0 && p_arg < (int)sizeof...(P)) {
			GDNativePropertyInfo pi;
			call_get_argument_type_info<P...>(p_arg, pi);
			return pi;
		} else {
			return GetTypeInfo<R>::get_class_info();
		}
	}
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif

public:
	virtual GDNativeExtensionClassMethodArgumentMetadata get_argument_metadata(int p_argument) const {
		if (p_argument >= 0) {
			return call_get_argument_metadata<P...>(p_argument);
		} else {
			return GetTypeInfo<R>::METADATA;
		}
	}

	virtual Variant call(GDExtensionClassInstancePtr p_instance, const GDNativeVariantPtr *p_args, const GDNativeInt p_argument_count, GDNativeCallError &r_error) const {
		Variant ret;
#ifdef TYPED_METHOD_BIND
		call_with_variant_args_retc_dv(static_cast<T *>(p_instance), method, p_args, (int)p_argument_count, ret, r_error, get_default_arguments());
#else
		call_with_variant_args_retc_dv((MB_T *)p_instance, method, p_args, p_argument_count, ret, r_error, get_default_arguments());
#endif
		return ret;
	}
	virtual void ptrcall(GDExtensionClassInstancePtr p_instance, const GDNativeTypePtr *p_args, GDNativeTypePtr r_ret) const {
#ifdef TYPED_METHOD_BIND
		call_with_ptr_args<T, R, P...>(static_cast<T *>(p_instance), method, p_args, r_ret);
#else
		call_with_ptr_args<MB_T, R, P...>(reinterpret_cast<MB_T *>(p_instance), method, p_args, r_ret);
#endif // TYPED_METHOD_BIND
	}

	MethodBindTRC(R (MB_T::*p_method)(P...) const) {
		method = p_method;
		generate_argument_types(sizeof...(P));
		set_argument_count(sizeof...(P));
		set_return(true);
	}
};

template <class T, class R, class... P>
MethodBind *create_method_bind(R (T::*p_method)(P...) const) {
#ifdef TYPED_METHOD_BIND
	MethodBind *a = memnew((MethodBindTRC<T, R, P...>)(p_method));
#else
	MethodBind *a = memnew((MethodBindTRC<R, P...>)(reinterpret_cast<R (MB_T::*)(P...) const>(p_method)));
#endif // TYPED_METHOD_BIND
	a->set_instance_class(T::get_class_static());
	return a;
}

} // namespace godot

#endif // ! GODOT_CPP_METHOD_BIND_HPP
