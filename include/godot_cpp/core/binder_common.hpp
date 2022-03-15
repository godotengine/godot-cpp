/*************************************************************************/
/*  binder_common.hpp                                                    */
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

#ifndef GODOT_CPP_BINDER_COMMON_HPP
#define GODOT_CPP_BINDER_COMMON_HPP

#include <godot/gdnative_interface.h>

#include <godot_cpp/core/method_ptrcall.hpp>
#include <godot_cpp/core/type_info.hpp>

#include <array>
#include <vector>

namespace godot {

#define VARIANT_ENUM_CAST(m_class, m_enum)                                            \
	namespace godot {                                                                 \
	MAKE_ENUM_TYPE_INFO(m_class, m_enum)                                              \
	template <>                                                                       \
	struct VariantCaster<m_class::m_enum> {                                           \
		static _FORCE_INLINE_ m_class::m_enum cast(const Variant &p_variant) {        \
			return (m_class::m_enum)p_variant.operator int64_t();                     \
		}                                                                             \
	};                                                                                \
	template <>                                                                       \
	struct PtrToArg<m_class::m_enum> {                                                \
		_FORCE_INLINE_ static m_class::m_enum convert(const void *p_ptr) {            \
			return m_class::m_enum(*reinterpret_cast<const int64_t *>(p_ptr));        \
		}                                                                             \
		typedef int64_t EncodeT;                                                      \
		_FORCE_INLINE_ static void encode(m_class::m_enum p_val, const void *p_ptr) { \
			*(int64_t *)p_ptr = p_val;                                                \
		}                                                                             \
	};                                                                                \
	}

template <class T>
struct VariantCaster {
	static _FORCE_INLINE_ T cast(const Variant &p_variant) {
		return p_variant;
	}
};

template <class T>
struct VariantCaster<T &> {
	static _FORCE_INLINE_ T cast(const Variant &p_variant) {
		return p_variant;
	}
};

template <class T>
struct VariantCaster<const T &> {
	static _FORCE_INLINE_ T cast(const Variant &p_variant) {
		return p_variant;
	}
};

template <typename T>
struct VariantObjectClassChecker {
	static _FORCE_INLINE_ bool check(const Variant &p_variant) {
		return true;
	}
};

template <typename T>
class Ref;

template <typename T>
struct VariantObjectClassChecker<const Ref<T> &> {
	static _FORCE_INLINE_ bool check(const Variant &p_variant) {
		Object *obj = p_variant;
		const Ref<T> node = p_variant;
		return node.ptr() || !obj;
	}
};

template <class T>
struct VariantCasterAndValidate {
	static _FORCE_INLINE_ T cast(const Variant **p_args, uint32_t p_arg_idx, GDNativeCallError &r_error) {
		GDNativeVariantType argtype = GetTypeInfo<T>::VARIANT_TYPE;
		if (!internal::gdn_interface->variant_can_convert_strict(static_cast<GDNativeVariantType>(p_args[p_arg_idx]->get_type()), argtype) ||
				!VariantObjectClassChecker<T>::check(p_args[p_arg_idx])) {
			r_error.error = GDNATIVE_CALL_ERROR_INVALID_ARGUMENT;
			r_error.argument = p_arg_idx;
			r_error.expected = argtype;
		}

		return VariantCaster<T>::cast(*p_args[p_arg_idx]);
	}
};

template <class T>
struct VariantCasterAndValidate<T &> {
	static _FORCE_INLINE_ T cast(const Variant **p_args, uint32_t p_arg_idx, GDNativeCallError &r_error) {
		GDNativeVariantType argtype = GetTypeInfo<T>::VARIANT_TYPE;
		if (!internal::gdn_interface->variant_can_convert_strict(static_cast<GDNativeVariantType>(p_args[p_arg_idx]->get_type()), argtype) ||
				!VariantObjectClassChecker<T>::check(p_args[p_arg_idx])) {
			r_error.error = GDNATIVE_CALL_ERROR_INVALID_ARGUMENT;
			r_error.argument = p_arg_idx;
			r_error.expected = argtype;
		}

		return VariantCaster<T>::cast(*p_args[p_arg_idx]);
	}
};

template <class T>
struct VariantCasterAndValidate<const T &> {
	static _FORCE_INLINE_ T cast(const Variant **p_args, uint32_t p_arg_idx, GDNativeCallError &r_error) {
		GDNativeVariantType argtype = GetTypeInfo<T>::VARIANT_TYPE;
		if (!internal::gdn_interface->variant_can_convert_strict(static_cast<GDNativeVariantType>(p_args[p_arg_idx]->get_type()), argtype) ||
				!VariantObjectClassChecker<T>::check(p_args[p_arg_idx])) {
			r_error.error = GDNATIVE_CALL_ERROR_INVALID_ARGUMENT;
			r_error.argument = p_arg_idx;
			r_error.expected = argtype;
		}

		return VariantCaster<T>::cast(*p_args[p_arg_idx]);
	}
};

template <class T, class... P, size_t... Is>
void call_with_ptr_args_helper(T *p_instance, void (T::*p_method)(P...), const GDNativeTypePtr *p_args, IndexSequence<Is...>) {
	(p_instance->*p_method)(PtrToArg<P>::convert(p_args[Is])...);
}

template <class T, class... P, size_t... Is>
void call_with_ptr_argsc_helper(T *p_instance, void (T::*p_method)(P...) const, const GDNativeTypePtr *p_args, IndexSequence<Is...>) {
	(p_instance->*p_method)(PtrToArg<P>::convert(p_args[Is])...);
}

template <class T, class R, class... P, size_t... Is>
void call_with_ptr_args_ret_helper(T *p_instance, R (T::*p_method)(P...), const GDNativeTypePtr *p_args, void *r_ret, IndexSequence<Is...>) {
	PtrToArg<R>::encode((p_instance->*p_method)(PtrToArg<P>::convert(p_args[Is])...), r_ret);
}

template <class T, class R, class... P, size_t... Is>
void call_with_ptr_args_retc_helper(T *p_instance, R (T::*p_method)(P...) const, const GDNativeTypePtr *p_args, void *r_ret, IndexSequence<Is...>) {
	PtrToArg<R>::encode((p_instance->*p_method)(PtrToArg<P>::convert(p_args[Is])...), r_ret);
}

template <class T, class... P>
void call_with_ptr_args(T *p_instance, void (T::*p_method)(P...), const GDNativeTypePtr *p_args, void * /*ret*/) {
	call_with_ptr_args_helper<T, P...>(p_instance, p_method, p_args, BuildIndexSequence<sizeof...(P)>{});
}

template <class T, class... P>
void call_with_ptr_args(T *p_instance, void (T::*p_method)(P...) const, const GDNativeTypePtr *p_args, void * /*ret*/) {
	call_with_ptr_argsc_helper<T, P...>(p_instance, p_method, p_args, BuildIndexSequence<sizeof...(P)>{});
}

template <class T, class R, class... P>
void call_with_ptr_args(T *p_instance, R (T::*p_method)(P...), const GDNativeTypePtr *p_args, void *r_ret) {
	call_with_ptr_args_ret_helper<T, R, P...>(p_instance, p_method, p_args, r_ret, BuildIndexSequence<sizeof...(P)>{});
}

template <class T, class R, class... P>
void call_with_ptr_args(T *p_instance, R (T::*p_method)(P...) const, const GDNativeTypePtr *p_args, void *r_ret) {
	call_with_ptr_args_retc_helper<T, R, P...>(p_instance, p_method, p_args, r_ret, BuildIndexSequence<sizeof...(P)>{});
}

template <class T, class... P, size_t... Is>
void call_with_variant_args_helper(T *p_instance, void (T::*p_method)(P...), const Variant **p_args, GDNativeCallError &r_error, IndexSequence<Is...>) {
	r_error.error = GDNATIVE_CALL_OK;

#ifdef DEBUG_METHODS_ENABLED
	(p_instance->*p_method)(VariantCasterAndValidate<P>::cast(p_args, Is, r_error)...);
#else
	(p_instance->*p_method)(VariantCaster<P>::cast(*p_args[Is])...);
#endif
	(void)(p_args); // Avoid warning.
}

template <class T, class... P, size_t... Is>
void call_with_variant_argsc_helper(T *p_instance, void (T::*p_method)(P...) const, const Variant **p_args, GDNativeCallError &r_error, IndexSequence<Is...>) {
	r_error.error = GDNATIVE_CALL_OK;

#ifdef DEBUG_METHODS_ENABLED
	(p_instance->*p_method)(VariantCasterAndValidate<P>::cast(p_args, Is, r_error)...);
#else
	(p_instance->*p_method)(VariantCaster<P>::cast(*p_args[Is])...);
#endif
	(void)(p_args); // Avoid warning.
}

template <class T, class R, class... P, size_t... Is>
void call_with_variant_args_ret_helper(T *p_instance, R (T::*p_method)(P...), const Variant **p_args, Variant &r_ret, GDNativeCallError &r_error, IndexSequence<Is...>) {
	r_error.error = GDNATIVE_CALL_OK;

#ifdef DEBUG_METHODS_ENABLED
	r_ret = (p_instance->*p_method)(VariantCasterAndValidate<P>::cast(p_args, Is, r_error)...);
#else
	r_ret = (p_instance->*p_method)(VariantCaster<P>::cast(*p_args[Is])...);
#endif
}

template <class T, class R, class... P, size_t... Is>
void call_with_variant_args_retc_helper(T *p_instance, R (T::*p_method)(P...) const, const Variant **p_args, Variant &r_ret, GDNativeCallError &r_error, IndexSequence<Is...>) {
	r_error.error = GDNATIVE_CALL_OK;

#ifdef DEBUG_METHODS_ENABLED
	r_ret = (p_instance->*p_method)(VariantCasterAndValidate<P>::cast(p_args, Is, r_error)...);
#else
	r_ret = (p_instance->*p_method)(VariantCaster<P>::cast(*p_args[Is])...);
#endif
	(void)p_args;
}

template <class T, class... P>
void call_with_variant_args_dv(T *p_instance, void (T::*p_method)(P...), const GDNativeVariantPtr *p_args, int p_argcount, GDNativeCallError &r_error, const std::vector<Variant> &default_values) {
#ifdef DEBUG_ENABLED
	if ((size_t)p_argcount > sizeof...(P)) {
		r_error.error = GDNATIVE_CALL_ERROR_TOO_MANY_ARGUMENTS;
		r_error.argument = (int32_t)sizeof...(P);
		return;
	}
#endif

	int32_t missing = (int32_t)sizeof...(P) - (int32_t)p_argcount;

	int32_t dvs = (int32_t)default_values.size();
#ifdef DEBUG_ENABLED
	if (missing > dvs) {
		r_error.error = GDNATIVE_CALL_ERROR_TOO_FEW_ARGUMENTS;
		r_error.argument = (int32_t)sizeof...(P);
		return;
	}
#endif

	Variant args[sizeof...(P) == 0 ? 1 : sizeof...(P)]; // Avoid zero sized array.
	std::array<const Variant *, sizeof...(P)> argsp;
	for (int32_t i = 0; i < (int32_t)sizeof...(P); i++) {
		if (i < p_argcount) {
			args[i] = Variant(p_args[i]);
		} else {
			args[i] = default_values[i - p_argcount + (dvs - missing)];
		}
		argsp[i] = &args[i];
	}

	call_with_variant_args_helper(p_instance, p_method, argsp.data(), r_error, BuildIndexSequence<sizeof...(P)>{});
}

template <class T, class... P>
void call_with_variant_argsc_dv(T *p_instance, void (T::*p_method)(P...) const, const GDNativeVariantPtr *p_args, int p_argcount, GDNativeCallError &r_error, const std::vector<Variant> &default_values) {
#ifdef DEBUG_ENABLED
	if ((size_t)p_argcount > sizeof...(P)) {
		r_error.error = GDNATIVE_CALL_ERROR_TOO_MANY_ARGUMENTS;
		r_error.argument = (int32_t)sizeof...(P);
		return;
	}
#endif

	int32_t missing = (int32_t)sizeof...(P) - (int32_t)p_argcount;

	int32_t dvs = (int32_t)default_values.size();
#ifdef DEBUG_ENABLED
	if (missing > dvs) {
		r_error.error = GDNATIVE_CALL_ERROR_TOO_FEW_ARGUMENTS;
		r_error.argument = (int32_t)sizeof...(P);
		return;
	}
#endif

	Variant args[sizeof...(P) == 0 ? 1 : sizeof...(P)]; // Avoid zero sized array.
	std::array<const Variant *, sizeof...(P)> argsp;
	for (int32_t i = 0; i < (int32_t)sizeof...(P); i++) {
		if (i < p_argcount) {
			args[i] = Variant(p_args[i]);
		} else {
			args[i] = default_values[i - p_argcount + (dvs - missing)];
		}
		argsp[i] = &args[i];
	}

	call_with_variant_argsc_helper(p_instance, p_method, argsp.data(), r_error, BuildIndexSequence<sizeof...(P)>{});
}

template <class T, class R, class... P>
void call_with_variant_args_ret_dv(T *p_instance, R (T::*p_method)(P...), const GDNativeVariantPtr *p_args, int p_argcount, Variant &r_ret, GDNativeCallError &r_error, const std::vector<Variant> &default_values) {
#ifdef DEBUG_ENABLED
	if ((size_t)p_argcount > sizeof...(P)) {
		r_error.error = GDNATIVE_CALL_ERROR_TOO_MANY_ARGUMENTS;
		r_error.argument = (int32_t)sizeof...(P);
		return;
	}
#endif

	int32_t missing = (int32_t)sizeof...(P) - (int32_t)p_argcount;

	int32_t dvs = (int32_t)default_values.size();
#ifdef DEBUG_ENABLED
	if (missing > dvs) {
		r_error.error = GDNATIVE_CALL_ERROR_TOO_FEW_ARGUMENTS;
		r_error.argument = (int32_t)sizeof...(P);
		return;
	}
#endif

	Variant args[sizeof...(P) == 0 ? 1 : sizeof...(P)]; // Avoid zero sized array.
	std::array<const Variant *, sizeof...(P)> argsp;
	for (int32_t i = 0; i < (int32_t)sizeof...(P); i++) {
		if (i < p_argcount) {
			args[i] = Variant(p_args[i]);
		} else {
			args[i] = default_values[i - p_argcount + (dvs - missing)];
		}
		argsp[i] = &args[i];
	}

	call_with_variant_args_ret_helper(p_instance, p_method, argsp.data(), r_ret, r_error, BuildIndexSequence<sizeof...(P)>{});
}

template <class T, class R, class... P>
void call_with_variant_args_retc_dv(T *p_instance, R (T::*p_method)(P...) const, const GDNativeVariantPtr *p_args, int p_argcount, Variant &r_ret, GDNativeCallError &r_error, const std::vector<Variant> &default_values) {
#ifdef DEBUG_ENABLED
	if ((size_t)p_argcount > sizeof...(P)) {
		r_error.error = GDNATIVE_CALL_ERROR_TOO_MANY_ARGUMENTS;
		r_error.argument = (int32_t)sizeof...(P);
		return;
	}
#endif

	int32_t missing = (int32_t)sizeof...(P) - (int32_t)p_argcount;

	int32_t dvs = (int32_t)default_values.size();
#ifdef DEBUG_ENABLED
	if (missing > dvs) {
		r_error.error = GDNATIVE_CALL_ERROR_TOO_FEW_ARGUMENTS;
		r_error.argument = (int32_t)sizeof...(P);
		return;
	}
#endif

	Variant args[sizeof...(P) == 0 ? 1 : sizeof...(P)]; // Avoid zero sized array.
	std::array<const Variant *, sizeof...(P)> argsp;
	for (int32_t i = 0; i < (int32_t)sizeof...(P); i++) {
		if (i < p_argcount) {
			args[i] = Variant(p_args[i]);
		} else {
			args[i] = default_values[i - p_argcount + (dvs - missing)];
		}
		argsp[i] = &args[i];
	}

	call_with_variant_args_retc_helper(p_instance, p_method, argsp.data(), r_ret, r_error, BuildIndexSequence<sizeof...(P)>{});
}

// GCC raises "parameter 'p_args' set but not used" when P = {},
// it's not clever enough to treat other P values as making this branch valid.
#if defined(DEBUG_METHODS_ENABLED) && defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-but-set-parameter"
#endif

template <class Q>
void call_get_argument_type_helper(int p_arg, int &index, GDNativeVariantType &type) {
	if (p_arg == index) {
		type = GetTypeInfo<Q>::VARIANT_TYPE;
	}
	index++;
}

template <class... P>
GDNativeVariantType call_get_argument_type(int p_arg) {
	GDNativeVariantType type = GDNATIVE_VARIANT_TYPE_NIL;
	int index = 0;
	// I think rocket science is simpler than modern C++.
	using expand_type = int[];
	expand_type a{ 0, (call_get_argument_type_helper<P>(p_arg, index, type), 0)... };
	(void)a; // Suppress (valid, but unavoidable) -Wunused-variable warning.
	(void)index; // Suppress GCC warning.
	return type;
}

template <class Q>
void call_get_argument_type_info_helper(int p_arg, int &index, GDNativePropertyInfo &info) {
	if (p_arg == index) {
		info = GetTypeInfo<Q>::get_class_info();
	}
	index++;
}

template <class... P>
void call_get_argument_type_info(int p_arg, GDNativePropertyInfo &info) {
	int index = 0;
	// I think rocket science is simpler than modern C++.
	using expand_type = int[];
	expand_type a{ 0, (call_get_argument_type_info_helper<P>(p_arg, index, info), 0)... };
	(void)a; // Suppress (valid, but unavoidable) -Wunused-variable warning.
	(void)index; // Suppress GCC warning.
}

template <class Q>
void call_get_argument_metadata_helper(int p_arg, int &index, GDNativeExtensionClassMethodArgumentMetadata &md) {
	if (p_arg == index) {
		md = GetTypeInfo<Q>::METADATA;
	}
	index++;
}

template <class... P>
GDNativeExtensionClassMethodArgumentMetadata call_get_argument_metadata(int p_arg) {
	GDNativeExtensionClassMethodArgumentMetadata md = GDNATIVE_EXTENSION_METHOD_ARGUMENT_METADATA_NONE;

	int index = 0;
	// I think rocket science is simpler than modern C++.
	using expand_type = int[];
	expand_type a{ 0, (call_get_argument_metadata_helper<P>(p_arg, index, md), 0)... };
	(void)a; // Suppress (valid, but unavoidable) -Wunused-variable warning.
	(void)index;
	return md;
}

#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif

} // namespace godot

#endif // ! GODOT_CPP_BINDER_COMMON_HPP
