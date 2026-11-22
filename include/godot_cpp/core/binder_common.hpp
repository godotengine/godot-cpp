/**************************************************************************/
/*  binder_common.hpp                                                     */
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

#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/core/method_ptrcall.hpp>
#include <godot_cpp/core/type_info.hpp>

#include <array>

namespace godot {

/**
 * Registers an enum for Godot method binding. Converts between the C++ enum and the engine's signed 64-bit representation.
 *
 * - `m_enum` — Enum type to register, qualified with its C++ scope.
 */
#define VARIANT_ENUM_CAST(m_enum) \
	namespace godot { \
	MAKE_ENUM_TYPE_INFO(m_enum) \
	template <> \
	struct VariantCaster<m_enum> { \
		static _FORCE_INLINE_ m_enum cast(const Variant &p_variant) { \
			return (m_enum)p_variant.operator int64_t(); \
		} \
	}; \
	template <> \
	struct PtrToArg<m_enum> { \
		_FORCE_INLINE_ static m_enum convert(const void *p_ptr) { \
			return m_enum(*reinterpret_cast<const int64_t *>(p_ptr)); \
		} \
		typedef int64_t EncodeT; \
		_FORCE_INLINE_ static void encode(m_enum p_val, void *p_ptr) { \
			*reinterpret_cast<int64_t *>(p_ptr) = static_cast<int64_t>(p_val); \
		} \
	}; \
	}

/**
 * Registers a flag enum and its `godot::BitField` wrapper for method binding. Encodes the flags as a signed 64-bit integer.
 *
 * - `m_enum` — Enum type whose values represent flags, qualified with its C++ scope.
 */
#define VARIANT_BITFIELD_CAST(m_enum) \
	namespace godot { \
	MAKE_BITFIELD_TYPE_INFO(m_enum) \
	template <> \
	struct VariantCaster<BitField<m_enum>> { \
		static _FORCE_INLINE_ BitField<m_enum> cast(const Variant &p_variant) { \
			return BitField<m_enum>(p_variant.operator int64_t()); \
		} \
	}; \
	template <> \
	struct PtrToArg<BitField<m_enum>> { \
		_FORCE_INLINE_ static BitField<m_enum> convert(const void *p_ptr) { \
			return BitField<m_enum>(*reinterpret_cast<const int64_t *>(p_ptr)); \
		} \
		typedef int64_t EncodeT; \
		_FORCE_INLINE_ static void encode(BitField<m_enum> p_val, void *p_ptr) { \
			*reinterpret_cast<int64_t *>(p_ptr) = static_cast<int64_t>(p_val); \
		} \
	}; \
	}

/**
 * Selects the conversion used for a method argument passed by value.
 *
 * - `T` — C++ type requested by the method signature.
 */
template <typename T>
struct VariantCaster {
	/**
	 * Converts the variant to a C++ value. A Godot object pointer uses a class cast before it is returned.
	 *
	 * - `p_variant` — Source variant from the engine's argument array.
	 */
	static _FORCE_INLINE_ T cast(const Variant &p_variant) {
		using TStripped = std::remove_pointer_t<T>;
		if constexpr (std::is_base_of<Object, TStripped>::value) {
			return Object::cast_to<TStripped>(p_variant);
		} else {
			return p_variant;
		}
	}
};

/**
 * Selects the conversion used for a method argument passed by non-const reference.
 *
 * - `T` — C++ type requested by the method signature.
 */
template <typename T>
struct VariantCaster<T &> {
	/**
	 * Converts the variant to a C++ value. A Godot object pointer uses a class cast before it is returned.
	 *
	 * - `p_variant` — Source variant from the engine's argument array.
	 */
	static _FORCE_INLINE_ T cast(const Variant &p_variant) {
		using TStripped = std::remove_pointer_t<T>;
		if constexpr (std::is_base_of<Object, TStripped>::value) {
			return Object::cast_to<TStripped>(p_variant);
		} else {
			return p_variant;
		}
	}
};

/**
 * Selects the conversion used for a method argument passed by const reference.
 *
 * - `T` — C++ type requested by the method signature.
 */
template <typename T>
struct VariantCaster<const T &> {
	/**
	 * Converts the variant to a C++ value. A Godot object pointer uses a class cast before it is returned.
	 *
	 * - `p_variant` — Source variant from the engine's argument array.
	 */
	static _FORCE_INLINE_ T cast(const Variant &p_variant) {
		using TStripped = std::remove_pointer_t<T>;
		if constexpr (std::is_base_of<Object, TStripped>::value) {
			return Object::cast_to<TStripped>(p_variant);
		} else {
			return p_variant;
		}
	}
};

/**
 * Adds a class check to variant argument validation for pointers to Godot objects.
 *
 * - `T` — C++ argument type whose object class may need validation.
 */
template <typename T>
struct VariantObjectClassChecker {
	/**
	 * Checks whether a non-null Godot object can be cast to the required class. Other argument types pass this check.
	 *
	 * - `p_variant` — Source variant from the engine's argument array.
	 */
	static _FORCE_INLINE_ bool check(const Variant &p_variant) {
		using TStripped = std::remove_pointer_t<T>;
		if constexpr (std::is_base_of<Object, TStripped>::value) {
			Object *obj = p_variant;
			return Object::cast_to<TStripped>(p_variant) || !obj;
		} else {
			return true;
		}
	}
};

/**
 * Declares the reference wrapper used for object-class checks on reference-counted arguments.
 *
 * - `T` — Reference-counted Godot object type.
 */
template <typename T>
class Ref;

/**
 * Adds a class check for a reference-counted argument passed by const reference.
 *
 * - `T` — Type that the object reference must hold.
 */
template <typename T>
struct VariantObjectClassChecker<const Ref<T> &> {
	/**
	 * Checks whether the source object can be held as the requested reference type. An empty object also passes this class check.
	 *
	 * - `p_variant` — Source variant from the engine's argument array.
	 */
	static _FORCE_INLINE_ bool check(const Variant &p_variant) {
		Object *obj = p_variant;
		const Ref<T> node = p_variant;
		return node.ptr() || !obj;
	}
};

/**
 * Validates and converts a variant argument passed by value.
 *
 * - `T` — C++ type used to determine the required variant type and object class.
 */
template <typename T>
struct VariantCasterAndValidate {
	/**
	 * Checks whether the argument can be converted strictly and reports a mismatch. It still attempts the C++ conversion.
	 *
	 * - `p_args` — Array of pointers to the incoming variants.
	 * - `p_arg_idx` — Zero-based index of the argument to check. The array must contain a readable variant pointer at this index.
	 * - `r_error` — Call status set to invalid argument on a mismatch, with the index and expected variant type. Left unchanged when the check passes.
	 */
	static _FORCE_INLINE_ T cast(const Variant **p_args, uint32_t p_arg_idx, GDExtensionCallError &r_error) {
		GDExtensionVariantType argtype = GDExtensionVariantType(GetTypeInfo<T>::VARIANT_TYPE);
		if (!::godot::gdextension_interface::variant_can_convert_strict(static_cast<GDExtensionVariantType>(p_args[p_arg_idx]->get_type()), argtype) ||
				!VariantObjectClassChecker<T>::check(p_args[p_arg_idx])) {
			r_error.error = GDEXTENSION_CALL_ERROR_INVALID_ARGUMENT;
			r_error.argument = p_arg_idx;
			r_error.expected = argtype;
		}

		return VariantCaster<T>::cast(*p_args[p_arg_idx]);
	}
};

/**
 * Validates and converts a variant argument passed by non-const reference.
 *
 * - `T` — C++ type used to determine the required variant type and object class.
 */
template <typename T>
struct VariantCasterAndValidate<T &> {
	/**
	 * Checks whether the argument can be converted strictly and reports a mismatch. It still attempts the C++ conversion.
	 *
	 * - `p_args` — Array of pointers to the incoming variants.
	 * - `p_arg_idx` — Zero-based index of the argument to check. The array must contain a readable variant pointer at this index.
	 * - `r_error` — Call status set to invalid argument on a mismatch, with the index and expected variant type. Left unchanged when the check passes.
	 */
	static _FORCE_INLINE_ T cast(const Variant **p_args, uint32_t p_arg_idx, GDExtensionCallError &r_error) {
		GDExtensionVariantType argtype = GDExtensionVariantType(GetTypeInfo<T>::VARIANT_TYPE);
		if (!::godot::gdextension_interface::variant_can_convert_strict(static_cast<GDExtensionVariantType>(p_args[p_arg_idx]->get_type()), argtype) ||
				!VariantObjectClassChecker<T>::check(p_args[p_arg_idx])) {
			r_error.error = GDEXTENSION_CALL_ERROR_INVALID_ARGUMENT;
			r_error.argument = p_arg_idx;
			r_error.expected = argtype;
		}

		return VariantCaster<T>::cast(*p_args[p_arg_idx]);
	}
};

/**
 * Validates and converts a variant argument passed by const reference.
 *
 * - `T` — C++ type used to determine the required variant type and object class.
 */
template <typename T>
struct VariantCasterAndValidate<const T &> {
	/**
	 * Checks whether the argument can be converted strictly and reports a mismatch. It still attempts the C++ conversion.
	 *
	 * - `p_args` — Array of pointers to the incoming variants.
	 * - `p_arg_idx` — Zero-based index of the argument to check. The array must contain a readable variant pointer at this index.
	 * - `r_error` — Call status set to invalid argument on a mismatch, with the index and expected variant type. Left unchanged when the check passes.
	 */
	static _FORCE_INLINE_ T cast(const Variant **p_args, uint32_t p_arg_idx, GDExtensionCallError &r_error) {
		GDExtensionVariantType argtype = GDExtensionVariantType(GetTypeInfo<T>::VARIANT_TYPE);
		if (!::godot::gdextension_interface::variant_can_convert_strict(static_cast<GDExtensionVariantType>(p_args[p_arg_idx]->get_type()), argtype) ||
				!VariantObjectClassChecker<T>::check(p_args[p_arg_idx])) {
			r_error.error = GDEXTENSION_CALL_ERROR_INVALID_ARGUMENT;
			r_error.argument = p_arg_idx;
			r_error.expected = argtype;
		}

		return VariantCaster<T>::cast(*p_args[p_arg_idx]);
	}
};

/**
 * Reads the typed argument slots and invokes the member function.
 *
 * - `T` — Class that declares the member function.
 * - `P` — C++ parameter types in argument order.
 * - `Is` — Zero-based indices used to pair each argument pointer with its C++ type.
 * - `p_instance` — C++ object on which to invoke the member function.
 * - `p_method` — Pointer to the member function invoked by the binding.
 * - `p_args` — Borrowed argument addresses in the types expected by the pointer-call ABI.
 * - `final IndexSequence parameter` — Selects the compile-time argument indices for expansion.
 */
template <typename T, typename... P, size_t... Is>
void call_with_ptr_args_helper(T *p_instance, void (T::*p_method)(P...), const GDExtensionConstTypePtr *p_args, IndexSequence<Is...>) {
	(p_instance->*p_method)(PtrToArg<P>::convert(p_args[Is])...);
}

/**
 * Reads the typed argument slots and invokes the const member function.
 *
 * - `T` — Class that declares the member function.
 * - `P` — C++ parameter types in argument order.
 * - `Is` — Zero-based indices used to pair each argument pointer with its C++ type.
 * - `p_instance` — C++ object on which to invoke the member function.
 * - `p_method` — Pointer to the const member function invoked by the binding.
 * - `p_args` — Borrowed argument addresses in the types expected by the pointer-call ABI.
 * - `final IndexSequence parameter` — Selects the compile-time argument indices for expansion.
 */
template <typename T, typename... P, size_t... Is>
void call_with_ptr_argsc_helper(T *p_instance, void (T::*p_method)(P...) const, const GDExtensionConstTypePtr *p_args, IndexSequence<Is...>) {
	(p_instance->*p_method)(PtrToArg<P>::convert(p_args[Is])...);
}

/**
 * Reads the typed argument slots and invokes the member function. Encodes the result into the engine return slot.
 *
 * - `T` — Class that declares the member function.
 * - `R` — C++ result type used to encode the return value.
 * - `P` — C++ parameter types in argument order.
 * - `Is` — Zero-based indices used to pair each argument pointer with its C++ type.
 * - `p_instance` — C++ object on which to invoke the member function.
 * - `p_method` — Pointer to the member function invoked by the binding.
 * - `p_args` — Borrowed argument addresses in the types expected by the pointer-call ABI.
 * - `r_ret` — Writable engine storage for the encoded result.
 * - `final IndexSequence parameter` — Selects the compile-time argument indices for expansion.
 */
template <typename T, typename R, typename... P, size_t... Is>
void call_with_ptr_args_ret_helper(T *p_instance, R (T::*p_method)(P...), const GDExtensionConstTypePtr *p_args, void *r_ret, IndexSequence<Is...>) {
	PtrToArg<R>::encode((p_instance->*p_method)(PtrToArg<P>::convert(p_args[Is])...), r_ret);
}

/**
 * Reads the typed argument slots and invokes the const member function. Encodes the result into the engine return slot.
 *
 * - `T` — Class that declares the member function.
 * - `R` — C++ result type used to encode the return value.
 * - `P` — C++ parameter types in argument order.
 * - `Is` — Zero-based indices used to pair each argument pointer with its C++ type.
 * - `p_instance` — C++ object on which to invoke the member function.
 * - `p_method` — Pointer to the const member function invoked by the binding.
 * - `p_args` — Borrowed argument addresses in the types expected by the pointer-call ABI.
 * - `r_ret` — Writable engine storage for the encoded result.
 * - `final IndexSequence parameter` — Selects the compile-time argument indices for expansion.
 */
template <typename T, typename R, typename... P, size_t... Is>
void call_with_ptr_args_retc_helper(T *p_instance, R (T::*p_method)(P...) const, const GDExtensionConstTypePtr *p_args, void *r_ret, IndexSequence<Is...>) {
	PtrToArg<R>::encode((p_instance->*p_method)(PtrToArg<P>::convert(p_args[Is])...), r_ret);
}

/**
 * Reads the typed argument slots and invokes the member function.
 *
 * - `T` — Class that declares the member function.
 * - `P` — C++ parameter types in argument order.
 * - `p_instance` — C++ object on which to invoke the member function.
 * - `p_method` — Pointer to the member function invoked by the binding.
 * - `p_args` — Borrowed argument addresses in the types expected by the pointer-call ABI.
 * - `fourth void pointer parameter` — Return storage for the pointer call. The void overload does not use it.
 */
template <typename T, typename... P>
void call_with_ptr_args(T *p_instance, void (T::*p_method)(P...), const GDExtensionConstTypePtr *p_args, void * /*ret*/) {
	call_with_ptr_args_helper<T, P...>(p_instance, p_method, p_args, BuildIndexSequence<sizeof...(P)>{});
}

/**
 * Reads the typed argument slots and invokes the const member function.
 *
 * - `T` — Class that declares the member function.
 * - `P` — C++ parameter types in argument order.
 * - `p_instance` — C++ object on which to invoke the member function.
 * - `p_method` — Pointer to the const member function invoked by the binding.
 * - `p_args` — Borrowed argument addresses in the types expected by the pointer-call ABI.
 * - `fourth void pointer parameter` — Return storage for the pointer call. The void overload does not use it.
 */
template <typename T, typename... P>
void call_with_ptr_args(T *p_instance, void (T::*p_method)(P...) const, const GDExtensionConstTypePtr *p_args, void * /*ret*/) {
	call_with_ptr_argsc_helper<T, P...>(p_instance, p_method, p_args, BuildIndexSequence<sizeof...(P)>{});
}

/**
 * Reads the typed argument slots and invokes the member function. Encodes the result into the engine return slot.
 *
 * - `T` — Class that declares the member function.
 * - `R` — C++ result type used to encode the return value.
 * - `P` — C++ parameter types in argument order.
 * - `p_instance` — C++ object on which to invoke the member function.
 * - `p_method` — Pointer to the member function invoked by the binding.
 * - `p_args` — Borrowed argument addresses in the types expected by the pointer-call ABI.
 * - `r_ret` — Writable engine storage for the encoded result.
 */
template <typename T, typename R, typename... P>
void call_with_ptr_args(T *p_instance, R (T::*p_method)(P...), const GDExtensionConstTypePtr *p_args, void *r_ret) {
	call_with_ptr_args_ret_helper<T, R, P...>(p_instance, p_method, p_args, r_ret, BuildIndexSequence<sizeof...(P)>{});
}

/**
 * Reads the typed argument slots and invokes the const member function. Encodes the result into the engine return slot.
 *
 * - `T` — Class that declares the member function.
 * - `R` — C++ result type used to encode the return value.
 * - `P` — C++ parameter types in argument order.
 * - `p_instance` — C++ object on which to invoke the member function.
 * - `p_method` — Pointer to the const member function invoked by the binding.
 * - `p_args` — Borrowed argument addresses in the types expected by the pointer-call ABI.
 * - `r_ret` — Writable engine storage for the encoded result.
 */
template <typename T, typename R, typename... P>
void call_with_ptr_args(T *p_instance, R (T::*p_method)(P...) const, const GDExtensionConstTypePtr *p_args, void *r_ret) {
	call_with_ptr_args_retc_helper<T, R, P...>(p_instance, p_method, p_args, r_ret, BuildIndexSequence<sizeof...(P)>{});
}

/**
 * Expands the argument array and invokes the member function with converted variants.
 *
 * - `T` — Class that declares the member function.
 * - `P` — C++ parameter types in argument order.
 * - `Is` — Zero-based indices used to pair each argument pointer with its C++ type.
 * - `p_instance` — C++ object on which to invoke the member function.
 * - `p_method` — Pointer to the member function invoked by the binding.
 * - `p_args` — Borrowed array of variant pointers in call order.
 * - `r_error` — Call status set to success before conversion. Debug builds report type errors during conversion.
 * - `final IndexSequence parameter` — Selects the compile-time argument indices for expansion.
 */
template <typename T, typename... P, size_t... Is>
void call_with_variant_args_helper(T *p_instance, void (T::*p_method)(P...), const Variant **p_args, GDExtensionCallError &r_error, IndexSequence<Is...>) {
	r_error.error = GDEXTENSION_CALL_OK;

#ifdef DEBUG_ENABLED
	(p_instance->*p_method)(VariantCasterAndValidate<P>::cast(p_args, Is, r_error)...);
#else
	(p_instance->*p_method)(VariantCaster<P>::cast(*p_args[Is])...);
#endif
	(void)(p_args); // Avoid warning.
}

/**
 * Expands the argument array and invokes the const member function with converted variants.
 *
 * - `T` — Class that declares the member function.
 * - `P` — C++ parameter types in argument order.
 * - `Is` — Zero-based indices used to pair each argument pointer with its C++ type.
 * - `p_instance` — C++ object on which to invoke the member function.
 * - `p_method` — Pointer to the const member function invoked by the binding.
 * - `p_args` — Borrowed array of variant pointers in call order.
 * - `r_error` — Call status set to success before conversion. Debug builds report type errors during conversion.
 * - `final IndexSequence parameter` — Selects the compile-time argument indices for expansion.
 */
template <typename T, typename... P, size_t... Is>
void call_with_variant_argsc_helper(T *p_instance, void (T::*p_method)(P...) const, const Variant **p_args, GDExtensionCallError &r_error, IndexSequence<Is...>) {
	r_error.error = GDEXTENSION_CALL_OK;

#ifdef DEBUG_ENABLED
	(p_instance->*p_method)(VariantCasterAndValidate<P>::cast(p_args, Is, r_error)...);
#else
	(p_instance->*p_method)(VariantCaster<P>::cast(*p_args[Is])...);
#endif
	(void)(p_args); // Avoid warning.
}

/**
 * Expands the argument array and invokes the member function with converted variants. Stores the return value as a variant.
 *
 * - `T` — Class that declares the member function.
 * - `R` — C++ result type used to encode the return value.
 * - `P` — C++ parameter types in argument order.
 * - `Is` — Zero-based indices used to pair each argument pointer with its C++ type.
 * - `p_instance` — C++ object on which to invoke the member function.
 * - `p_method` — Pointer to the member function invoked by the binding.
 * - `p_args` — Borrowed array of variant pointers in call order.
 * - `r_ret` — Variant written with the result if the function is invoked.
 * - `r_error` — Call status set to success before conversion. Debug builds report type errors during conversion.
 * - `final IndexSequence parameter` — Selects the compile-time argument indices for expansion.
 */
template <typename T, typename R, typename... P, size_t... Is>
void call_with_variant_args_ret_helper(T *p_instance, R (T::*p_method)(P...), const Variant **p_args, Variant &r_ret, GDExtensionCallError &r_error, IndexSequence<Is...>) {
	r_error.error = GDEXTENSION_CALL_OK;

#ifdef DEBUG_ENABLED
	r_ret = (p_instance->*p_method)(VariantCasterAndValidate<P>::cast(p_args, Is, r_error)...);
#else
	r_ret = (p_instance->*p_method)(VariantCaster<P>::cast(*p_args[Is])...);
#endif
	(void)p_args; // Avoid warning.
}

/**
 * Expands the argument array and invokes the const member function with converted variants. Stores the return value as a variant.
 *
 * - `T` — Class that declares the member function.
 * - `R` — C++ result type used to encode the return value.
 * - `P` — C++ parameter types in argument order.
 * - `Is` — Zero-based indices used to pair each argument pointer with its C++ type.
 * - `p_instance` — C++ object on which to invoke the member function.
 * - `p_method` — Pointer to the const member function invoked by the binding.
 * - `p_args` — Borrowed array of variant pointers in call order.
 * - `r_ret` — Variant written with the result if the function is invoked.
 * - `r_error` — Call status set to success before conversion. Debug builds report type errors during conversion.
 * - `final IndexSequence parameter` — Selects the compile-time argument indices for expansion.
 */
template <typename T, typename R, typename... P, size_t... Is>
void call_with_variant_args_retc_helper(T *p_instance, R (T::*p_method)(P...) const, const Variant **p_args, Variant &r_ret, GDExtensionCallError &r_error, IndexSequence<Is...>) {
	r_error.error = GDEXTENSION_CALL_OK;

#ifdef DEBUG_ENABLED
	r_ret = (p_instance->*p_method)(VariantCasterAndValidate<P>::cast(p_args, Is, r_error)...);
#else
	r_ret = (p_instance->*p_method)(VariantCaster<P>::cast(*p_args[Is])...);
#endif
	(void)p_args; // Avoid warning.
}

/**
 * Invokes the member function with variant arguments after the debug argument count check.
 *
 * - `T` — Class that declares the member function.
 * - `P` — C++ parameter types in argument order.
 * - `p_instance` — C++ object on which to invoke the member function.
 * - `p_method` — Pointer to the member function invoked by the binding.
 * - `p_args` — Borrowed array of variant pointers in call order.
 * - `p_argcount` — Number of supplied arguments. Debug builds check it against the number of C++ parameters.
 * - `r_error` — Call status updated by dispatch. Debug builds also report argument count or type mismatches.
 */
template <typename T, typename... P>
void call_with_variant_args(T *p_instance, void (T::*p_method)(P...), const Variant **p_args, int p_argcount, GDExtensionCallError &r_error) {
#ifdef DEBUG_ENABLED
	if ((size_t)p_argcount > sizeof...(P)) {
		r_error.error = GDEXTENSION_CALL_ERROR_TOO_MANY_ARGUMENTS;
		r_error.expected = (int32_t)sizeof...(P);
		return;
	}

	if ((size_t)p_argcount < sizeof...(P)) {
		r_error.error = GDEXTENSION_CALL_ERROR_TOO_FEW_ARGUMENTS;
		r_error.expected = (int32_t)sizeof...(P);
		return;
	}
#endif
	call_with_variant_args_helper<T, P...>(p_instance, p_method, p_args, r_error, BuildIndexSequence<sizeof...(P)>{});
}

/**
 * Invokes the member function with variant arguments after the debug argument count check. Stores the return value as a variant.
 *
 * - `T` — Class that declares the member function.
 * - `R` — C++ result type used to encode the return value.
 * - `P` — C++ parameter types in argument order.
 * - `p_instance` — C++ object on which to invoke the member function.
 * - `p_method` — Pointer to the member function invoked by the binding.
 * - `p_args` — Borrowed array of variant pointers in call order.
 * - `p_argcount` — Number of supplied arguments. Debug builds check it against the number of C++ parameters.
 * - `r_ret` — Variant written with the result if the function is invoked.
 * - `r_error` — Call status updated by dispatch. Debug builds also report argument count or type mismatches.
 */
template <typename T, typename R, typename... P>
void call_with_variant_args_ret(T *p_instance, R (T::*p_method)(P...), const Variant **p_args, int p_argcount, Variant &r_ret, GDExtensionCallError &r_error) {
#ifdef DEBUG_ENABLED
	if ((size_t)p_argcount > sizeof...(P)) {
		r_error.error = GDEXTENSION_CALL_ERROR_TOO_MANY_ARGUMENTS;
		r_error.expected = (int32_t)sizeof...(P);
		return;
	}

	if ((size_t)p_argcount < sizeof...(P)) {
		r_error.error = GDEXTENSION_CALL_ERROR_TOO_FEW_ARGUMENTS;
		r_error.expected = (int32_t)sizeof...(P);
		return;
	}
#endif
	call_with_variant_args_ret_helper<T, R, P...>(p_instance, p_method, p_args, r_ret, r_error, BuildIndexSequence<sizeof...(P)>{});
}

/**
 * Invokes the const member function with variant arguments after the debug argument count check. Stores the return value as a variant.
 *
 * - `T` — Class that declares the member function.
 * - `R` — C++ result type used to encode the return value.
 * - `P` — C++ parameter types in argument order.
 * - `p_instance` — C++ object on which to invoke the member function.
 * - `p_method` — Pointer to the const member function invoked by the binding.
 * - `p_args` — Borrowed array of variant pointers in call order.
 * - `p_argcount` — Number of supplied arguments. Debug builds check it against the number of C++ parameters.
 * - `r_ret` — Variant written with the result if the function is invoked.
 * - `r_error` — Call status updated by dispatch. Debug builds also report argument count or type mismatches.
 */
template <typename T, typename R, typename... P>
void call_with_variant_args_retc(T *p_instance, R (T::*p_method)(P...) const, const Variant **p_args, int p_argcount, Variant &r_ret, GDExtensionCallError &r_error) {
#ifdef DEBUG_ENABLED
	if ((size_t)p_argcount > sizeof...(P)) {
		r_error.error = GDEXTENSION_CALL_ERROR_TOO_MANY_ARGUMENTS;
		r_error.expected = (int32_t)sizeof...(P);
		return;
	}

	if ((size_t)p_argcount < sizeof...(P)) {
		r_error.error = GDEXTENSION_CALL_ERROR_TOO_FEW_ARGUMENTS;
		r_error.expected = (int32_t)sizeof...(P);
		return;
	}
#endif
	call_with_variant_args_retc_helper<T, R, P...>(p_instance, p_method, p_args, r_ret, r_error, BuildIndexSequence<sizeof...(P)>{});
}

/**
 * Fills omitted trailing arguments with defaults and invokes the member function with converted variants.
 *
 * - `T` — Class that declares the member function.
 * - `P` — C++ parameter types in argument order.
 * - `p_instance` — C++ object on which to invoke the member function.
 * - `p_method` — Pointer to the member function invoked by the binding.
 * - `p_args` — Borrowed ABI variant pointers in call order.
 * - `p_argcount` — Number of supplied arguments before adding defaults. Debug builds check that it fits the signature and saved defaults.
 * - `r_error` — Call status updated by dispatch. Debug builds also report argument count or type mismatches.
 * - `default_values` — Defaults for the final parameters in declaration order, used to fill the missing arguments.
 */
template <typename T, typename... P>
void call_with_variant_args_dv(T *p_instance, void (T::*p_method)(P...), const GDExtensionConstVariantPtr *p_args, int p_argcount, GDExtensionCallError &r_error, const LocalVector<Variant> &default_values) {
#ifdef DEBUG_ENABLED
	if ((size_t)p_argcount > sizeof...(P)) {
		r_error.error = GDEXTENSION_CALL_ERROR_TOO_MANY_ARGUMENTS;
		r_error.expected = (int32_t)sizeof...(P);
		return;
	}
#endif

	int32_t missing = (int32_t)sizeof...(P) - (int32_t)p_argcount;

	int32_t dvs = (int32_t)default_values.size();
#ifdef DEBUG_ENABLED
	if (missing > dvs) {
		r_error.error = GDEXTENSION_CALL_ERROR_TOO_FEW_ARGUMENTS;
		r_error.expected = (int32_t)sizeof...(P);
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

/**
 * Fills omitted trailing arguments with defaults and invokes the const member function with converted variants.
 *
 * - `T` — Class that declares the member function.
 * - `P` — C++ parameter types in argument order.
 * - `p_instance` — C++ object on which to invoke the member function.
 * - `p_method` — Pointer to the const member function invoked by the binding.
 * - `p_args` — Borrowed ABI variant pointers in call order.
 * - `p_argcount` — Number of supplied arguments before adding defaults. Debug builds check that it fits the signature and saved defaults.
 * - `r_error` — Call status updated by dispatch. Debug builds also report argument count or type mismatches.
 * - `default_values` — Defaults for the final parameters in declaration order, used to fill the missing arguments.
 */
template <typename T, typename... P>
void call_with_variant_argsc_dv(T *p_instance, void (T::*p_method)(P...) const, const GDExtensionConstVariantPtr *p_args, int p_argcount, GDExtensionCallError &r_error, const LocalVector<Variant> &default_values) {
#ifdef DEBUG_ENABLED
	if ((size_t)p_argcount > sizeof...(P)) {
		r_error.error = GDEXTENSION_CALL_ERROR_TOO_MANY_ARGUMENTS;
		r_error.expected = (int32_t)sizeof...(P);
		return;
	}
#endif

	int32_t missing = (int32_t)sizeof...(P) - (int32_t)p_argcount;

	int32_t dvs = (int32_t)default_values.size();
#ifdef DEBUG_ENABLED
	if (missing > dvs) {
		r_error.error = GDEXTENSION_CALL_ERROR_TOO_FEW_ARGUMENTS;
		r_error.expected = (int32_t)sizeof...(P);
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

/**
 * Fills omitted trailing arguments with defaults and invokes the member function with converted variants. Stores the return value as a variant.
 *
 * - `T` — Class that declares the member function.
 * - `R` — C++ result type used to encode the return value.
 * - `P` — C++ parameter types in argument order.
 * - `p_instance` — C++ object on which to invoke the member function.
 * - `p_method` — Pointer to the member function invoked by the binding.
 * - `p_args` — Borrowed ABI variant pointers in call order.
 * - `p_argcount` — Number of supplied arguments before adding defaults. Debug builds check that it fits the signature and saved defaults.
 * - `r_ret` — Variant written with the result if the function is invoked.
 * - `r_error` — Call status updated by dispatch. Debug builds also report argument count or type mismatches.
 * - `default_values` — Defaults for the final parameters in declaration order, used to fill the missing arguments.
 */
template <typename T, typename R, typename... P>
void call_with_variant_args_ret_dv(T *p_instance, R (T::*p_method)(P...), const GDExtensionConstVariantPtr *p_args, int p_argcount, Variant &r_ret, GDExtensionCallError &r_error, const LocalVector<Variant> &default_values) {
#ifdef DEBUG_ENABLED
	if ((size_t)p_argcount > sizeof...(P)) {
		r_error.error = GDEXTENSION_CALL_ERROR_TOO_MANY_ARGUMENTS;
		r_error.expected = (int32_t)sizeof...(P);
		return;
	}
#endif

	int32_t missing = (int32_t)sizeof...(P) - (int32_t)p_argcount;

	int32_t dvs = (int32_t)default_values.size();
#ifdef DEBUG_ENABLED
	if (missing > dvs) {
		r_error.error = GDEXTENSION_CALL_ERROR_TOO_FEW_ARGUMENTS;
		r_error.expected = (int32_t)sizeof...(P);
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

/**
 * Fills omitted trailing arguments with defaults and invokes the const member function with converted variants. Stores the return value as a variant.
 *
 * - `T` — Class that declares the member function.
 * - `R` — C++ result type used to encode the return value.
 * - `P` — C++ parameter types in argument order.
 * - `p_instance` — C++ object on which to invoke the member function.
 * - `p_method` — Pointer to the const member function invoked by the binding.
 * - `p_args` — Borrowed ABI variant pointers in call order.
 * - `p_argcount` — Number of supplied arguments before adding defaults. Debug builds check that it fits the signature and saved defaults.
 * - `r_ret` — Variant written with the result if the function is invoked.
 * - `r_error` — Call status updated by dispatch. Debug builds also report argument count or type mismatches.
 * - `default_values` — Defaults for the final parameters in declaration order, used to fill the missing arguments.
 */
template <typename T, typename R, typename... P>
void call_with_variant_args_retc_dv(T *p_instance, R (T::*p_method)(P...) const, const GDExtensionConstVariantPtr *p_args, int p_argcount, Variant &r_ret, GDExtensionCallError &r_error, const LocalVector<Variant> &default_values) {
#ifdef DEBUG_ENABLED
	if ((size_t)p_argcount > sizeof...(P)) {
		r_error.error = GDEXTENSION_CALL_ERROR_TOO_MANY_ARGUMENTS;
		r_error.expected = (int32_t)sizeof...(P);
		return;
	}
#endif

	int32_t missing = (int32_t)sizeof...(P) - (int32_t)p_argcount;

	int32_t dvs = (int32_t)default_values.size();
#ifdef DEBUG_ENABLED
	if (missing > dvs) {
		r_error.error = GDEXTENSION_CALL_ERROR_TOO_FEW_ARGUMENTS;
		r_error.expected = (int32_t)sizeof...(P);
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
#if defined(DEBUG_ENABLED) && defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-but-set-parameter"
#endif

/**
 * Writes the variant type when the current position matches the requested index, then advances the position.
 *
 * - `Q` — C++ type of the current parameter.
 * - `p_arg` — Zero-based index requested by the caller.
 * - `index` — Current position in the type pack. Incremented on every call.
 * - `type` — Output for the variant type. Left unchanged at other indices.
 */
template <typename Q>
void call_get_argument_type_helper(int p_arg, int &index, GDExtensionVariantType &type) {
	if (p_arg == index) {
		type = GDExtensionVariantType(GetTypeInfo<Q>::VARIANT_TYPE);
	}
	index++;
}

/**
 * Returns the variant type for the requested argument. Returns nil if the index is outside the pack.
 *
 * - `P` — C++ parameter types in signature order.
 * - `p_arg` — Zero-based index of the requested parameter.
 */
template <typename... P>
GDExtensionVariantType call_get_argument_type(int p_arg) {
	GDExtensionVariantType type = GDEXTENSION_VARIANT_TYPE_NIL;
	int index = 0;
	// I think rocket science is simpler than modern C++.
	using expand_type = int[];
	expand_type a{ 0, (call_get_argument_type_helper<P>(p_arg, index, type), 0)... };
	(void)a; // Suppress (valid, but unavoidable) -Wunused-variable warning.
	(void)index; // Suppress GCC warning.
	return type;
}

/**
 * Writes the property information when the current position matches the requested index, then advances the position.
 *
 * - `Q` — C++ type of the current parameter.
 * - `p_arg` — Zero-based index requested by the caller.
 * - `index` — Current position in the type pack. Incremented on every call.
 * - `info` — Output for the property information. Left unchanged at other indices.
 */
template <typename Q>
void call_get_argument_type_info_helper(int p_arg, int &index, PropertyInfo &info) {
	if (p_arg == index) {
		info = GetTypeInfo<Q>::get_class_info();
	}
	index++;
}

/**
 * Writes the property information for the requested argument. Leaves the supplied descriptor unchanged if the index is outside the pack.
 *
 * - `P` — C++ parameter types in signature order.
 * - `p_arg` — Zero-based index of the requested parameter.
 * - `info` — Descriptor written when the argument is found.
 */
template <typename... P>
void call_get_argument_type_info(int p_arg, PropertyInfo &info) {
	int index = 0;
	// I think rocket science is simpler than modern C++.
	using expand_type = int[];
	expand_type a{ 0, (call_get_argument_type_info_helper<P>(p_arg, index, info), 0)... };
	(void)a; // Suppress (valid, but unavoidable) -Wunused-variable warning.
	(void)index; // Suppress GCC warning.
}

/**
 * Writes the ABI argument metadata when the current position matches the requested index, then advances the position.
 *
 * - `Q` — C++ type of the current parameter.
 * - `p_arg` — Zero-based index requested by the caller.
 * - `index` — Current position in the type pack. Incremented on every call.
 * - `md` — Output for the ABI argument metadata. Left unchanged at other indices.
 */
template <typename Q>
void call_get_argument_metadata_helper(int p_arg, int &index, GDExtensionClassMethodArgumentMetadata &md) {
	if (p_arg == index) {
		md = GetTypeInfo<Q>::METADATA;
	}
	index++;
}

/**
 * Returns the ABI argument metadata for the requested argument. Returns the empty metadata value if the index is outside the pack.
 *
 * - `P` — C++ parameter types in signature order.
 * - `p_arg` — Zero-based index of the requested parameter.
 */
template <typename... P>
GDExtensionClassMethodArgumentMetadata call_get_argument_metadata(int p_arg) {
	GDExtensionClassMethodArgumentMetadata md = GDEXTENSION_METHOD_ARGUMENT_METADATA_NONE;

	int index = 0;
	// I think rocket science is simpler than modern C++.
	using expand_type = int[];
	expand_type a{ 0, (call_get_argument_metadata_helper<P>(p_arg, index, md), 0)... };
	(void)a; // Suppress (valid, but unavoidable) -Wunused-variable warning.
	(void)index;
	return md;
}

/**
 * Expands the argument array and invokes the function with converted variants.
 *
 * - `P` — C++ parameter types in argument order.
 * - `Is` — Zero-based indices used to pair each argument pointer with its C++ type.
 * - `p_method` — Pointer to the function invoked by the binding.
 * - `p_args` — Borrowed array of variant pointers in call order.
 * - `r_error` — Call status set to success before conversion. Debug builds report type errors during conversion.
 * - `final IndexSequence parameter` — Selects the compile-time argument indices for expansion.
 */
template <typename... P, size_t... Is>
void call_with_variant_args_static(void (*p_method)(P...), const Variant **p_args, GDExtensionCallError &r_error, IndexSequence<Is...>) {
	r_error.error = GDEXTENSION_CALL_OK;

#ifdef DEBUG_ENABLED
	(p_method)(VariantCasterAndValidate<P>::cast(p_args, Is, r_error)...);
#else
	(p_method)(VariantCaster<P>::cast(*p_args[Is])...);
#endif
}

/**
 * Fills omitted trailing arguments with defaults and invokes the function with converted variants.
 *
 * - `P` — C++ parameter types in argument order.
 * - `p_method` — Pointer to the function invoked by the binding.
 * - `p_args` — Borrowed ABI variant pointers in call order.
 * - `p_argcount` — Number of supplied arguments before adding defaults. Debug builds check that it fits the signature and saved defaults.
 * - `r_error` — Call status updated by dispatch. Debug builds also report argument count or type mismatches.
 * - `default_values` — Defaults for the final parameters in declaration order, used to fill the missing arguments.
 */
template <typename... P>
void call_with_variant_args_static_dv(void (*p_method)(P...), const GDExtensionConstVariantPtr *p_args, int p_argcount, GDExtensionCallError &r_error, const LocalVector<Variant> &default_values) {
#ifdef DEBUG_ENABLED
	if ((size_t)p_argcount > sizeof...(P)) {
		r_error.error = GDEXTENSION_CALL_ERROR_TOO_MANY_ARGUMENTS;
		r_error.expected = sizeof...(P);
		return;
	}
#endif

	int32_t missing = (int32_t)sizeof...(P) - (int32_t)p_argcount;

	int32_t dvs = default_values.size();
#ifdef DEBUG_ENABLED
	if (missing > dvs) {
		r_error.error = GDEXTENSION_CALL_ERROR_TOO_FEW_ARGUMENTS;
		r_error.expected = sizeof...(P);
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

	call_with_variant_args_static(p_method, argsp.data(), r_error, BuildIndexSequence<sizeof...(P)>{});
}

/**
 * Reads the typed argument slots and invokes the function.
 *
 * - `P` — C++ parameter types in argument order.
 * - `Is` — Zero-based indices used to pair each argument pointer with its C++ type.
 * - `p_method` — Pointer to the function invoked by the binding.
 * - `p_args` — Borrowed argument addresses in the types expected by the pointer-call ABI.
 * - `final IndexSequence parameter` — Selects the compile-time argument indices for expansion.
 */
template <typename... P, size_t... Is>
void call_with_ptr_args_static_method_helper(void (*p_method)(P...), const GDExtensionConstTypePtr *p_args, IndexSequence<Is...>) {
	p_method(PtrToArg<P>::convert(p_args[Is])...);
}

/**
 * Reads the typed argument slots and invokes the function.
 *
 * - `P` — C++ parameter types in argument order.
 * - `p_method` — Pointer to the function invoked by the binding.
 * - `p_args` — Borrowed argument addresses in the types expected by the pointer-call ABI.
 */
template <typename... P>
void call_with_ptr_args_static_method(void (*p_method)(P...), const GDExtensionConstTypePtr *p_args) {
	call_with_ptr_args_static_method_helper<P...>(p_method, p_args, BuildIndexSequence<sizeof...(P)>{});
}

/**
 * Invokes the function with variant arguments after the debug argument count check. Stores the return value as a variant.
 *
 * - `R` — C++ result type used to encode the return value.
 * - `P` — C++ parameter types in argument order.
 * - `p_method` — Pointer to the function invoked by the binding.
 * - `p_args` — Borrowed array of variant pointers in call order.
 * - `p_argcount` — Number of supplied arguments. Debug builds check it against the number of C++ parameters.
 * - `r_ret` — Variant written with the result if the function is invoked.
 * - `r_error` — Call status updated by dispatch. Debug builds also report argument count or type mismatches.
 */
template <typename R, typename... P>
void call_with_variant_args_static_ret(R (*p_method)(P...), const Variant **p_args, int p_argcount, Variant &r_ret, GDExtensionCallError &r_error) {
#ifdef DEBUG_ENABLED
	if ((size_t)p_argcount > sizeof...(P)) {
		r_error.error = GDEXTENSION_CALL_ERROR_TOO_MANY_ARGUMENTS;
		r_error.expected = (int32_t)sizeof...(P);
		return;
	}

	if ((size_t)p_argcount < sizeof...(P)) {
		r_error.error = GDEXTENSION_CALL_ERROR_TOO_FEW_ARGUMENTS;
		r_error.expected = (int32_t)sizeof...(P);
		return;
	}
#endif
	call_with_variant_args_static_ret<R, P...>(p_method, p_args, r_ret, r_error, BuildIndexSequence<sizeof...(P)>{});
}

/**
 * Invokes the function with variant arguments after the debug argument count check.
 *
 * - `P` — C++ parameter types in argument order.
 * - `p_method` — Pointer to the function invoked by the binding.
 * - `p_args` — Borrowed array of variant pointers in call order.
 * - `p_argcount` — Number of supplied arguments. Debug builds check it against the number of C++ parameters.
 * - `r_ret` — Return variant supplied by the caller. The void overload leaves it unchanged.
 * - `r_error` — Call status updated by dispatch. Debug builds also report argument count or type mismatches.
 */
template <typename... P>
void call_with_variant_args_static_ret(void (*p_method)(P...), const Variant **p_args, int p_argcount, Variant &r_ret, GDExtensionCallError &r_error) {
#ifdef DEBUG_ENABLED
	if ((size_t)p_argcount > sizeof...(P)) {
		r_error.error = GDEXTENSION_CALL_ERROR_TOO_MANY_ARGUMENTS;
		r_error.expected = (int32_t)sizeof...(P);
		return;
	}

	if ((size_t)p_argcount < sizeof...(P)) {
		r_error.error = GDEXTENSION_CALL_ERROR_TOO_FEW_ARGUMENTS;
		r_error.expected = (int32_t)sizeof...(P);
		return;
	}
#endif
	call_with_variant_args_static<P...>(p_method, p_args, r_error, BuildIndexSequence<sizeof...(P)>{});
}

/**
 * Expands the argument array and invokes the function with converted variants. Stores the return value as a variant.
 *
 * - `R` — C++ result type used to encode the return value.
 * - `P` — C++ parameter types in argument order.
 * - `Is` — Zero-based indices used to pair each argument pointer with its C++ type.
 * - `p_method` — Pointer to the function invoked by the binding.
 * - `p_args` — Borrowed array of variant pointers in call order.
 * - `r_ret` — Variant written with the result if the function is invoked.
 * - `r_error` — Call status set to success before conversion. Debug builds report type errors during conversion.
 * - `final IndexSequence parameter` — Selects the compile-time argument indices for expansion.
 */
template <typename R, typename... P, size_t... Is>
void call_with_variant_args_static_ret(R (*p_method)(P...), const Variant **p_args, Variant &r_ret, GDExtensionCallError &r_error, IndexSequence<Is...>) {
	r_error.error = GDEXTENSION_CALL_OK;

#ifdef DEBUG_ENABLED
	r_ret = (p_method)(VariantCasterAndValidate<P>::cast(p_args, Is, r_error)...);
#else
	r_ret = (p_method)(VariantCaster<P>::cast(*p_args[Is])...);
#endif
}

/**
 * Fills omitted trailing arguments with defaults and invokes the function with converted variants. Stores the return value as a variant.
 *
 * - `R` — C++ result type used to encode the return value.
 * - `P` — C++ parameter types in argument order.
 * - `p_method` — Pointer to the function invoked by the binding.
 * - `p_args` — Borrowed ABI variant pointers in call order.
 * - `p_argcount` — Number of supplied arguments before adding defaults. Debug builds check that it fits the signature and saved defaults.
 * - `r_ret` — Variant written with the result if the function is invoked.
 * - `r_error` — Call status updated by dispatch. Debug builds also report argument count or type mismatches.
 * - `default_values` — Defaults for the final parameters in declaration order, used to fill the missing arguments.
 */
template <typename R, typename... P>
void call_with_variant_args_static_ret_dv(R (*p_method)(P...), const GDExtensionConstVariantPtr *p_args, int p_argcount, Variant &r_ret, GDExtensionCallError &r_error, const LocalVector<Variant> &default_values) {
#ifdef DEBUG_ENABLED
	if ((size_t)p_argcount > sizeof...(P)) {
		r_error.error = GDEXTENSION_CALL_ERROR_TOO_MANY_ARGUMENTS;
		r_error.expected = sizeof...(P);
		return;
	}
#endif

	int32_t missing = (int32_t)sizeof...(P) - (int32_t)p_argcount;

	int32_t dvs = default_values.size();
#ifdef DEBUG_ENABLED
	if (missing > dvs) {
		r_error.error = GDEXTENSION_CALL_ERROR_TOO_FEW_ARGUMENTS;
		r_error.expected = sizeof...(P);
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

	call_with_variant_args_static_ret(p_method, argsp.data(), r_ret, r_error, BuildIndexSequence<sizeof...(P)>{});
}

/**
 * Reads the typed argument slots and invokes the function. Encodes the result into the engine return slot.
 *
 * - `R` — C++ result type used to encode the return value.
 * - `P` — C++ parameter types in argument order.
 * - `Is` — Zero-based indices used to pair each argument pointer with its C++ type.
 * - `p_method` — Pointer to the function invoked by the binding.
 * - `p_args` — Borrowed argument addresses in the types expected by the pointer-call ABI.
 * - `r_ret` — Writable engine storage for the encoded result.
 * - `final IndexSequence parameter` — Selects the compile-time argument indices for expansion.
 */
template <typename R, typename... P, size_t... Is>
void call_with_ptr_args_static_method_ret_helper(R (*p_method)(P...), const GDExtensionConstTypePtr *p_args, void *r_ret, IndexSequence<Is...>) {
	PtrToArg<R>::encode(p_method(PtrToArg<P>::convert(p_args[Is])...), r_ret);
}

/**
 * Reads the typed argument slots and invokes the function. Encodes the result into the engine return slot.
 *
 * - `R` — C++ result type used to encode the return value.
 * - `P` — C++ parameter types in argument order.
 * - `p_method` — Pointer to the function invoked by the binding.
 * - `p_args` — Borrowed argument addresses in the types expected by the pointer-call ABI.
 * - `r_ret` — Writable engine storage for the encoded result.
 */
template <typename R, typename... P>
void call_with_ptr_args_static_method_ret(R (*p_method)(P...), const GDExtensionConstTypePtr *p_args, void *r_ret) {
	call_with_ptr_args_static_method_ret_helper<R, P...>(p_method, p_args, r_ret, BuildIndexSequence<sizeof...(P)>{});
}

#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif

} // namespace godot

#include <godot_cpp/classes/global_constants_binds.hpp>
#include <godot_cpp/variant/builtin_binds.hpp>
