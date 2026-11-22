/**************************************************************************/
/*  method_bind.hpp                                                       */
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

#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/core/type_info.hpp>

#include <godot_cpp/core/memory.hpp>

#include <gdextension_interface.h>

#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/templates/local_vector.hpp>

namespace godot {

/**
 * Holds an extension method's registration data and provides the two call paths Godot uses to invoke it.
 */
class MethodBind {
	/**
	 * Stores the registered method flags before const, static, and variadic flags are added.
	 */
	uint32_t hint_flags = METHOD_FLAGS_DEFAULT;
	/**
	 * Stores the interned name by which Godot calls the method.
	 */
	StringName name;
	/**
	 * Stores the name of the extension class that exposes the method.
	 */
	StringName instance_class;
	/**
	 * Counts declared arguments, apart from the return slot and additional variadic arguments.
	 */
	int argument_count = 0;

	/**
	 * Controls whether Godot registers the method as callable without an instance.
	 */
	bool _static = false;
	/**
	 * Controls whether Godot registers the method with the const flag.
	 */
	bool _const = false;
	/**
	 * Indicates whether registration must describe a return value.
	 */
	bool _returns = false;
	/**
	 * Indicates whether the binding accepts extra variant arguments.
	 */
	bool _vararg = false;

	/**
	 * Stores parameter names in argument order. The vector may contain fewer names than the method's parameter count.
	 */
	LocalVector<StringName> argument_names;
	/**
	 * Owns the table of variant types. The return type is at index zero, followed by the argument types.
	 */
	GDExtensionVariantType *argument_types = nullptr;
	/**
	 * Stores the default variants for the trailing parameters in call order.
	 */
	LocalVector<Variant> default_arguments;

protected:
	/**
	 * Sets the flag that marks the bound method as const.
	 *
	 * - `p_const` — Whether to include the const method flag.
	 */
	void _set_const(bool p_const);
	/**
	 * Sets the flag for methods callable without an instance.
	 *
	 * - `p_static` — Whether to include the static method flag.
	 */
	void _set_static(bool p_static);
	/**
	 * Records whether the signature has a return value.
	 *
	 * - `p_returns` — Whether the return slot has a value to register.
	 */
	void _set_returns(bool p_returns);
	/**
	 * Sets the flag for methods that take a variable number of arguments.
	 *
	 * - `p_vararg` — Whether the binding accepts extra arguments.
	 */
	void _set_vararg(bool p_vararg);
	/**
	 * Gets the variant type used to build the registration table.
	 *
	 * - `p_arg` — Zero-based argument index. Use minus one for the return slot.
	 */
	virtual GDExtensionVariantType gen_argument_type(int p_arg) const = 0;
	/**
	 * Builds the property information registered for an argument or result.
	 *
	 * - `p_arg` — Zero-based argument index. Use minus one for the return slot.
	 */
	virtual PropertyInfo gen_argument_type_info(int p_arg) const = 0;
	/**
	 * Replaces the cached variant type table and updates the argument count.
	 *
	 * - `p_count` — Number of declared arguments. The table also includes the return slot.
	 */
	void _generate_argument_types(int p_count);

	/**
	 * Records the number of declared arguments.
	 *
	 * - `p_count` — Number of arguments excluding the return slot.
	 */
	void set_argument_count(int p_count) { argument_count = p_count; }

public:
	/**
	 * Returns the saved defaults in trailing parameter order.
	 */
	_FORCE_INLINE_ const LocalVector<Variant> &get_default_arguments() const { return default_arguments; }
	/**
	 * Returns the number of trailing arguments with saved defaults.
	 */
	_FORCE_INLINE_ int get_default_argument_count() const { return (int)default_arguments.size(); }

	/**
	 * Returns a boolean variant indicating whether the argument is among those with saved defaults.
	 *
	 * - `p_arg` — Zero-based argument index in the complete signature.
	 */
	_FORCE_INLINE_ Variant has_default_argument(int p_arg) const {
		const int num_default_args = (int)(default_arguments.size());
		const int idx = p_arg - (argument_count - num_default_args);

		if (idx < 0 || idx >= num_default_args) {
			return false;
		} else {
			return true;
		}
	}
	/**
	 * Returns the saved default for an argument, or a nil variant if that argument has no default.
	 *
	 * - `p_arg` — Zero-based argument index in the complete signature.
	 */
	_FORCE_INLINE_ Variant get_default_argument(int p_arg) const {
		const int num_default_args = (int)(default_arguments.size());
		const int idx = p_arg - (argument_count - num_default_args);

		if (idx < 0 || idx >= num_default_args) {
			return Variant();
		} else {
			return default_arguments[idx];
		}
	}

	/**
	 * Reads the cached variant type for an argument or result.
	 *
	 * - `p_argument` — Zero-based argument index. Use minus one for the return slot.
	 */
	_FORCE_INLINE_ GDExtensionVariantType get_argument_type(int p_argument) const {
		ERR_FAIL_COND_V(p_argument < -1 || p_argument > argument_count, GDEXTENSION_VARIANT_TYPE_NIL);
		return argument_types[p_argument + 1];
	}

	/**
	 * Builds property information and supplies the saved name for an argument if present.
	 *
	 * - `p_argument` — Zero-based argument index. Use minus one for the return slot.
	 */
	PropertyInfo get_argument_info(int p_argument) const;

	/**
	 * Returns the property information in ABI order, with the return slot first.
	 */
	LocalVector<PropertyInfo> get_arguments_info_list() const {
		LocalVector<PropertyInfo> vec;
		// First element is return value
		vec.reserve(argument_count + 1);
		for (int i = 0; i < argument_count + 1; i++) {
			vec.push_back(get_argument_info(i - 1));
		}
		return vec;
	}

	/**
	 * Replaces the argument names used during method registration.
	 *
	 * - `p_names` — Names in argument order, starting at the first parameter.
	 */
	void set_argument_names(const LocalVector<StringName> &p_names);
	/**
	 * Returns the saved argument names in registration order.
	 */
	const LocalVector<StringName> &get_argument_names() const;

	/**
	 * Gets extra ABI metadata for the argument or result, such as numeric width.
	 *
	 * - `p_argument` — Zero-based argument index. Use minus one for the return slot.
	 */
	virtual GDExtensionClassMethodArgumentMetadata get_argument_metadata(int p_argument) const = 0;

	/**
	 * Replaces the base flags used for method registration.
	 *
	 * - `p_hint_flags` — Bit mask to combine with flags derived from the method signature.
	 */
	_FORCE_INLINE_ void set_hint_flags(uint32_t p_hint_flags) { hint_flags = p_hint_flags; }
	/**
	 * Combines the stored flags with the binding's const, static, and variadic flags.
	 */
	_FORCE_INLINE_ uint32_t get_hint_flags() const { return hint_flags | (is_const() ? GDEXTENSION_METHOD_FLAG_CONST : 0) | (is_vararg() ? GDEXTENSION_METHOD_FLAG_VARARG : 0) | (is_static() ? GDEXTENSION_METHOD_FLAG_STATIC : 0); }
	/**
	 * Returns the registered class name stored for the binding.
	 */
	_FORCE_INLINE_ StringName get_instance_class() const { return instance_class; }
	/**
	 * Records which extension class exposes the method.
	 *
	 * - `p_class` — Registered name of the class used for method registration.
	 */
	_FORCE_INLINE_ void set_instance_class(StringName p_class) { instance_class = p_class; }

	/**
	 * Returns the number of declared arguments. Variadic arguments have no fixed count here.
	 */
	_FORCE_INLINE_ int get_argument_count() const { return argument_count; }

	/**
	 * Invokes the bound method through the variant call path and returns its result as a variant.
	 *
	 * - `p_instance` — C++ instance on which to invoke the method.
	 * - `p_args` — Borrowed array of variant pointers in call order.
	 * - `p_argument_count` — Number of supplied argument pointers.
	 * - `r_error` — Writable call status. The dispatch code reports argument errors here.
	 */
	virtual Variant call(GDExtensionClassInstancePtr p_instance, const GDExtensionConstVariantPtr *p_args, GDExtensionInt p_argument_count, GDExtensionCallError &r_error) const = 0;
	/**
	 * Invokes the method through the typed pointer call path.
	 *
	 * - `p_instance` — C++ instance on which to invoke the method.
	 * - `p_args` — Borrowed array of addresses of typed arguments in call order.
	 * - `r_return` — Engine storage for the encoded return value, when the method returns one.
	 */
	virtual void ptrcall(GDExtensionClassInstancePtr p_instance, const GDExtensionConstTypePtr *p_args, GDExtensionTypePtr r_return) const = 0;

	/**
	 * Returns the interned name exposed to Godot.
	 */
	StringName get_name() const;
	/**
	 * Sets the name used to register and find this binding.
	 *
	 * - `p_name` — Interned method name exposed to Godot.
	 */
	void set_name(const StringName &p_name);
	/**
	 * Returns whether the binding adds the const method flag.
	 */
	_FORCE_INLINE_ bool is_const() const { return _const; }
	/**
	 * Returns whether the binding adds the static method flag.
	 */
	_FORCE_INLINE_ bool is_static() const { return _static; }
	/**
	 * Returns whether the binding adds the variadic method flag.
	 */
	_FORCE_INLINE_ bool is_vararg() const { return _vararg; }
	/**
	 * Returns whether registration includes a return value.
	 */
	_FORCE_INLINE_ bool has_return() const { return _returns; }

	/**
	 * Replaces the saved default variants.
	 *
	 * - `p_default_arguments` — Defaults for the trailing parameters, in parameter order.
	 */
	void set_default_arguments(const LocalVector<Variant> &p_default_arguments) { default_arguments = p_default_arguments; }

	/**
	 * Returns the extra ABI metadata in registration order, with the return slot first.
	 */
	LocalVector<GDExtensionClassMethodArgumentMetadata> get_arguments_metadata_list() const {
		LocalVector<GDExtensionClassMethodArgumentMetadata> vec;
		// First element is return value
		vec.reserve(argument_count + 1);
		for (int i = 0; i < argument_count + 1; i++) {
			vec.push_back(get_argument_metadata(i - 1));
		}
		return vec;
	}

	/**
	 * Dispatches an engine variant call through its registered binding and constructs the ABI return variant.
	 *
	 * - `p_method_userdata` — Pointer to the binding registered as method userdata.
	 * - `p_instance` — C++ instance on which to invoke the method.
	 * - `p_args` — Borrowed array of variant pointers in call order.
	 * - `p_argument_count` — Number of supplied argument pointers.
	 * - `r_error` — Writable call status. The dispatch code reports argument errors here.
	 * - `r_return` — Uninitialized ABI storage in which this function constructs the returned variant.
	 */
	static void bind_call(void *p_method_userdata, GDExtensionClassInstancePtr p_instance, const GDExtensionConstVariantPtr *p_args, GDExtensionInt p_argument_count, GDExtensionVariantPtr r_return, GDExtensionCallError *r_error);
	/**
	 * Dispatches an engine pointer call through its registered binding.
	 *
	 * - `p_method_userdata` — Pointer to the binding registered as method userdata.
	 * - `p_instance` — C++ instance on which to invoke the method.
	 * - `p_args` — Borrowed array of addresses of typed arguments in call order.
	 * - `r_return` — Engine storage for the encoded return value, when the method returns one.
	 */
	static void bind_ptrcall(void *p_method_userdata, GDExtensionClassInstancePtr p_instance, const GDExtensionConstTypePtr *p_args, GDExtensionTypePtr r_return);

	/**
	 * Frees the table of registered variant types and destroys the method binding.
	 */
	virtual ~MethodBind();
};

/**
 * Shares registration and type information for member functions that receive the variant argument array directly.
 *
 * - `Derived` — Specialization that provides the return property information.
 * - `T` — Class that declares the member function.
 * - `R` — C++ result type of the member function.
 * - `should_returns` — Whether registration describes a return value.
 */
template <typename Derived, typename T, typename R, bool should_returns>
class MethodBindVarArgBase : public MethodBind {
protected:
	/**
	 * Stores the member function called with the engine's variant arguments and error output.
	 */
	R (T::*method)(const Variant **, GDExtensionInt, GDExtensionCallError &);
	/**
	 * Stores the property information for the declared prefix of the argument list.
	 */
	LocalVector<PropertyInfo> arguments;

public:
	/**
	 * Builds property information for the result, a declared argument, or an additional variant.
	 *
	 * - `p_arg` — Argument index. Negative indices select the result. Indices past the declared prefix describe generic variants.
	 */
	virtual PropertyInfo gen_argument_type_info(int p_arg) const {
		if (p_arg < 0) {
			return _gen_return_type_info();
		} else if ((size_t)(p_arg) < arguments.size()) {
			return arguments[p_arg];
		} else {
			return make_property_info(Variant::Type::NIL, "vararg", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_DEFAULT | PROPERTY_USAGE_NIL_IS_VARIANT);
		}
	}

	/**
	 * Returns the variant type from the variadic binding's argument or result information.
	 *
	 * - `p_arg` — Argument index. A negative index selects the result.
	 */
	virtual GDExtensionVariantType gen_argument_type(int p_arg) const {
		return static_cast<GDExtensionVariantType>(gen_argument_type_info(p_arg).type);
	}

	/**
	 * Reports that this binding uses no extra argument metadata.
	 *
	 * - `first int parameter` — Position of the argument or result. All positions use the same metadata value.
	 */
	virtual GDExtensionClassMethodArgumentMetadata get_argument_metadata(int) const {
		return GDEXTENSION_METHOD_ARGUMENT_METADATA_NONE;
	}

	/**
	 * Reports an error because the variadic method is called through the variant call path.
	 *
	 * - `p_instance` — Instance pointer supplied for the attempted call. The binding does not read it.
	 * - `p_args` — Typed argument pointers supplied for the attempted call. The binding does not read them.
	 * - `r_return` — Return storage supplied for the attempted call. The binding leaves it untouched.
	 */
	virtual void ptrcall(GDExtensionClassInstancePtr p_instance, const GDExtensionConstTypePtr *p_args, GDExtensionTypePtr r_return) const {
		ERR_FAIL(); // Can't call.
	}

	/**
	 * Stores the callable and initializes registration metadata for the variadic signature.
	 *
	 * - `p_method` — Member function that receives the variant pointers, count, and call status.
	 * - `p_method_info` — Registration metadata for the declared argument prefix.
	 * - `p_return_nil_is_variant` — Retained by the interface. This binding derives the return metadata from the specialization.
	 */
	MethodBindVarArgBase(
			R (T::*p_method)(const Variant **, GDExtensionInt, GDExtensionCallError &),
			const MethodInfo &p_method_info,
			bool p_return_nil_is_variant) :
			method(p_method) {
		_set_vararg(true);
		_set_const(true);
		set_argument_count(p_method_info.arguments.size());
		if (p_method_info.arguments.size()) {
			arguments = p_method_info.arguments;

			LocalVector<StringName> names;
			names.reserve(p_method_info.arguments.size());
			for (size_t i = 0; i < p_method_info.arguments.size(); i++) {
				names.push_back(p_method_info.arguments[i].name);
			}
			set_argument_names(names);
		}

		_generate_argument_types((int)p_method_info.arguments.size());
		_set_returns(should_returns);
	}

	/**
	 * Destroys the variadic binding and its saved argument information.
	 */
	~MethodBindVarArgBase() {}

private:
	/**
	 * Uses the specialization to build the return property information.
	 */
	PropertyInfo _gen_return_type_info() const {
		return reinterpret_cast<const Derived *>(this)->_gen_return_type_info_impl();
	}
};

/**
 * Binds a member function that receives the variant argument array directly and returns void.
 *
 * - `T` — Class that declares the bound member function.
 */
template <typename T>
class MethodBindVarArgT : public MethodBindVarArgBase<MethodBindVarArgT<T>, T, void, false> {
	/**
	 * Lets the shared variadic binding read the specialization's return property information.
	 */
	friend class MethodBindVarArgBase<MethodBindVarArgT<T>, T, void, false>;

public:
	/**
	 * Forwards the incoming variant array directly to the member function and returns a nil variant.
	 *
	 * - `p_instance` — C++ instance on which to invoke the method.
	 * - `p_args` — Borrowed array of variant pointers in call order.
	 * - `p_argument_count` — Number of supplied argument pointers.
	 * - `r_error` — Call status forwarded by reference to the target method.
	 */
	virtual Variant call(GDExtensionClassInstancePtr p_instance, const GDExtensionConstVariantPtr *p_args, GDExtensionInt p_argument_count, GDExtensionCallError &r_error) const {
		(static_cast<T *>(p_instance)->*MethodBindVarArgBase<MethodBindVarArgT<T>, T, void, false>::method)((const Variant **)p_args, p_argument_count, r_error);
		return {};
	}

	/**
	 * Initializes the registration signature from the supplied method information.
	 *
	 * - `p_method` — Member function to invoke.
	 * - `p_method_info` — Registration metadata for the declared arguments.
	 * - `p_return_nil_is_variant` — Retained by the interface. This binding derives the return metadata from the specialization.
	 */
	MethodBindVarArgT(
			void (T::*p_method)(const Variant **, GDExtensionInt, GDExtensionCallError &),
			const MethodInfo &p_method_info,
			bool p_return_nil_is_variant) :
			MethodBindVarArgBase<MethodBindVarArgT<T>, T, void, false>(p_method, p_method_info, p_return_nil_is_variant) {
	}

private:
	/**
	 * Provides empty return property information for a void method.
	 */
	PropertyInfo _gen_return_type_info_impl() const {
		return {};
	}
};

/**
 * Creates the variadic binding and records its declaring class for registration.
 *
 * - `T` — Class that declares the bound member function.
 * - `p_method` — Member function to bind.
 * - `p_info` — Registration metadata for the declared arguments.
 * - `p_return_nil_is_variant` — Retained by the interface. This binding derives the return metadata from the specialization.
 */
template <typename T>
MethodBind *create_vararg_method_bind(void (T::*p_method)(const Variant **, GDExtensionInt, GDExtensionCallError &), const MethodInfo &p_info, bool p_return_nil_is_variant) {
	MethodBind *a = memnew((MethodBindVarArgT<T>)(p_method, p_info, p_return_nil_is_variant));
	a->set_instance_class(T::get_class_static());
	return a;
}

/**
 * Binds a member function that receives the variant argument array directly and returns a value.
 *
 * - `T` — Class that declares the bound member function.
 * - `R` — C++ result type converted into the Godot call result.
 */
template <typename T, typename R>
class MethodBindVarArgTR : public MethodBindVarArgBase<MethodBindVarArgTR<T, R>, T, R, true> {
	/**
	 * Lets the shared variadic binding read the specialization's return property information.
	 */
	friend class MethodBindVarArgBase<MethodBindVarArgTR<T, R>, T, R, true>;

public:
	/**
	 * Forwards the incoming variant array directly to the member function and converts its return value to a variant.
	 *
	 * - `p_instance` — C++ instance on which to invoke the method.
	 * - `p_args` — Borrowed array of variant pointers in call order.
	 * - `p_argument_count` — Number of supplied argument pointers.
	 * - `r_error` — Call status forwarded by reference to the target method.
	 */
	virtual Variant call(GDExtensionClassInstancePtr p_instance, const GDExtensionConstVariantPtr *p_args, GDExtensionInt p_argument_count, GDExtensionCallError &r_error) const {
		return (static_cast<T *>(p_instance)->*MethodBindVarArgBase<MethodBindVarArgTR<T, R>, T, R, true>::method)((const Variant **)p_args, p_argument_count, r_error);
	}

	/**
	 * Initializes the registration signature from the supplied method information.
	 *
	 * - `p_method` — Member function to invoke.
	 * - `p_info` — Registration metadata for the declared arguments.
	 * - `p_return_nil_is_variant` — Retained by the interface. This binding derives the return metadata from the specialization.
	 */
	MethodBindVarArgTR(
			R (T::*p_method)(const Variant **, GDExtensionInt, GDExtensionCallError &),
			const MethodInfo &p_info,
			bool p_return_nil_is_variant) :
			MethodBindVarArgBase<MethodBindVarArgTR<T, R>, T, R, true>(p_method, p_info, p_return_nil_is_variant) {
	}

private:
	/**
	 * Builds the return slot property information from the declared result type.
	 */
	PropertyInfo _gen_return_type_info_impl() const {
		return GetTypeInfo<R>::get_class_info();
	}
};

/**
 * Creates the variadic binding and records its declaring class for registration.
 *
 * - `T` — Class that declares the bound member function.
 * - `R` — C++ result type converted into the Godot call result.
 * - `p_method` — Member function to bind.
 * - `p_info` — Registration metadata for the declared arguments.
 * - `p_return_nil_is_variant` — Retained by the interface. This binding derives the return metadata from the specialization.
 */
template <typename T, typename R>
MethodBind *create_vararg_method_bind(R (T::*p_method)(const Variant **, GDExtensionInt, GDExtensionCallError &), const MethodInfo &p_info, bool p_return_nil_is_variant) {
	MethodBind *a = memnew((MethodBindVarArgTR<T, R>)(p_method, p_info, p_return_nil_is_variant));
	a->set_instance_class(T::get_class_static());
	return a;
}

#ifndef TYPED_METHOD_BIND
/**
 * Placeholder class used to store member pointers when typed bindings are disabled.
 */
class _gde_UnexistingClass;
/**
 * Selects the placeholder class used for member pointers in untyped bindings.
 */
#define MB_T _gde_UnexistingClass
#else
/**
 * Uses the actual declaring class for the member pointer in typed bindings.
 */
#define MB_T T
#endif

// No return, not const.

#ifdef TYPED_METHOD_BIND
/**
 * Binds a fixed-argument member function returning void to Godot's method call interface.
 *
 * - `T` — Class that declares the bound member function.
 * - `P` — C++ parameter types in declaration order, used to decode calls and register argument types.
 */
template <typename T, typename... P>
#else
/**
 * Binds a fixed-argument member function returning void using the placeholder class for member storage.
 *
 * - `P` — C++ parameter types in declaration order, used to decode calls and register argument types.
 */
template <typename... P>
#endif // TYPED_METHOD_BIND
class MethodBindT : public MethodBind {
	/**
	 * Stores the member function pointer used for variant and pointer calls.
	 */
	void (MB_T::*method)(P...);

protected:
// GCC raises warnings in the case P = {} as the comparison is always false...
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wlogical-op"
#endif
	/**
	 * Returns the variant type for a declared argument, or nil outside that range.
	 *
	 * - `p_arg` — Zero-based argument index. Use minus one for the return slot.
	 */
	virtual GDExtensionVariantType gen_argument_type(int p_arg) const {
		if (p_arg >= 0 && p_arg < (int)sizeof...(P)) {
			return call_get_argument_type<P...>(p_arg);
		} else {
			return GDEXTENSION_VARIANT_TYPE_NIL;
		}
	}

	/**
	 * Builds property information for a declared argument. Outside that range the descriptor is empty.
	 *
	 * - `p_arg` — Zero-based argument index. Use minus one for the return slot.
	 */
	virtual PropertyInfo gen_argument_type_info(int p_arg) const {
		PropertyInfo pi;
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
	/**
	 * Returns ABI metadata for a declared argument.
	 *
	 * - `p_argument` — Zero-based argument index. Use minus one for the return slot.
	 */
	virtual GDExtensionClassMethodArgumentMetadata get_argument_metadata(int p_argument) const {
		return call_get_argument_metadata<P...>(p_argument);
	}

	/**
	 * Decodes the variant arguments, fills in missing trailing defaults, and invokes the member function. Returns a nil variant.
	 *
	 * - `p_instance` — C++ instance on which to invoke the method.
	 * - `p_args` — Borrowed array of variant pointers in call order.
	 * - `p_argument_count` — Number of supplied argument pointers.
	 * - `r_error` — Writable call status. The dispatch code reports argument errors here.
	 */
	virtual Variant call(GDExtensionClassInstancePtr p_instance, const GDExtensionConstVariantPtr *p_args, GDExtensionInt p_argument_count, GDExtensionCallError &r_error) const {
#ifdef TYPED_METHOD_BIND
		call_with_variant_args_dv(static_cast<T *>(p_instance), method, p_args, (int)p_argument_count, r_error, get_default_arguments());
#else
		call_with_variant_args_dv(reinterpret_cast<MB_T *>(p_instance), method, p_args, p_argument_count, r_error, get_default_arguments());
#endif
		return Variant();
	}
	/**
	 * Decodes arguments from typed pointers and invokes the member function.
	 *
	 * - `p_instance` — C++ instance on which to invoke the method.
	 * - `p_args` — Borrowed array of addresses of typed arguments in call order.
	 * - `r_ret` — Return storage supplied by the caller. A void call leaves it untouched.
	 */
	virtual void ptrcall(GDExtensionClassInstancePtr p_instance, const GDExtensionConstTypePtr *p_args, GDExtensionTypePtr r_ret) const {
#ifdef TYPED_METHOD_BIND
		call_with_ptr_args<T, P...>(static_cast<T *>(p_instance), method, p_args, nullptr);
#else
		call_with_ptr_args<MB_T, P...>(reinterpret_cast<MB_T *>(p_instance), method, p_args, nullptr);
#endif // TYPED_METHOD_BIND
	}

	/**
	 * Stores the pointer and builds the metadata for the fixed signature.
	 *
	 * - `p_method` — Pointer to the member function returning void invoked by the binding.
	 */
	MethodBindT(void (MB_T::*p_method)(P...)) {
		method = p_method;
		_generate_argument_types(sizeof...(P));
		set_argument_count(sizeof...(P));
	}
};

/**
 * Creates a method binding and records the declaring class for registration.
 *
 * - `T` — Class that declares the bound member function.
 * - `P` — C++ parameter types in declaration order, used to decode calls and register argument types.
 * - `p_method` — Pointer to the member function returning void to bind.
 */
template <typename T, typename... P>
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
/**
 * Binds a fixed-argument const member function returning void to Godot's method call interface.
 *
 * - `T` — Class that declares the bound member function.
 * - `P` — C++ parameter types in declaration order, used to decode calls and register argument types.
 */
template <typename T, typename... P>
#else
/**
 * Binds a fixed-argument const member function returning void using the placeholder class for member storage.
 *
 * - `P` — C++ parameter types in declaration order, used to decode calls and register argument types.
 */
template <typename... P>
#endif // TYPED_METHOD_BIND
class MethodBindTC : public MethodBind {
	/**
	 * Stores the member function pointer used for variant and pointer calls.
	 */
	void (MB_T::*method)(P...) const;

protected:
// GCC raises warnings in the case P = {} as the comparison is always false...
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wlogical-op"
#endif
	/**
	 * Returns the variant type for a declared argument, or nil outside that range.
	 *
	 * - `p_arg` — Zero-based argument index. Use minus one for the return slot.
	 */
	virtual GDExtensionVariantType gen_argument_type(int p_arg) const {
		if (p_arg >= 0 && p_arg < (int)sizeof...(P)) {
			return call_get_argument_type<P...>(p_arg);
		} else {
			return GDEXTENSION_VARIANT_TYPE_NIL;
		}
	}

	/**
	 * Builds property information for a declared argument. Outside that range the descriptor is empty.
	 *
	 * - `p_arg` — Zero-based argument index. Use minus one for the return slot.
	 */
	virtual PropertyInfo gen_argument_type_info(int p_arg) const {
		PropertyInfo pi;
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
	/**
	 * Returns ABI metadata for a declared argument.
	 *
	 * - `p_argument` — Zero-based argument index. Use minus one for the return slot.
	 */
	virtual GDExtensionClassMethodArgumentMetadata get_argument_metadata(int p_argument) const {
		return call_get_argument_metadata<P...>(p_argument);
	}

	/**
	 * Decodes the variant arguments, fills in missing trailing defaults, and invokes the member function. Returns a nil variant.
	 *
	 * - `p_instance` — C++ instance on which to invoke the method.
	 * - `p_args` — Borrowed array of variant pointers in call order.
	 * - `p_argument_count` — Number of supplied argument pointers.
	 * - `r_error` — Writable call status. The dispatch code reports argument errors here.
	 */
	virtual Variant call(GDExtensionClassInstancePtr p_instance, const GDExtensionConstVariantPtr *p_args, GDExtensionInt p_argument_count, GDExtensionCallError &r_error) const {
#ifdef TYPED_METHOD_BIND
		call_with_variant_argsc_dv(static_cast<T *>(p_instance), method, p_args, (int)p_argument_count, r_error, get_default_arguments());
#else
		call_with_variant_argsc_dv(reinterpret_cast<MB_T *>(p_instance), method, p_args, p_argument_count, r_error, get_default_arguments());
#endif
		return Variant();
	}
	/**
	 * Decodes arguments from typed pointers and invokes the member function.
	 *
	 * - `p_instance` — C++ instance on which to invoke the method.
	 * - `p_args` — Borrowed array of addresses of typed arguments in call order.
	 * - `r_ret` — Return storage supplied by the caller. A void call leaves it untouched.
	 */
	virtual void ptrcall(GDExtensionClassInstancePtr p_instance, const GDExtensionConstTypePtr *p_args, GDExtensionTypePtr r_ret) const {
#ifdef TYPED_METHOD_BIND
		call_with_ptr_args<T, P...>(static_cast<T *>(p_instance), method, p_args, nullptr);
#else
		call_with_ptr_args<MB_T, P...>(reinterpret_cast<MB_T *>(p_instance), method, p_args, nullptr);
#endif // TYPED_METHOD_BIND
	}

	/**
	 * Stores the pointer and builds the metadata for the fixed signature.
	 *
	 * - `p_method` — Pointer to the const member function returning void invoked by the binding.
	 */
	MethodBindTC(void (MB_T::*p_method)(P...) const) {
		method = p_method;
		_generate_argument_types(sizeof...(P));
		set_argument_count(sizeof...(P));
		_set_const(true);
	}
};

/**
 * Creates a method binding and records the declaring class for registration.
 *
 * - `T` — Class that declares the bound member function.
 * - `P` — C++ parameter types in declaration order, used to decode calls and register argument types.
 * - `p_method` — Pointer to the const member function returning void to bind.
 */
template <typename T, typename... P>
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
/**
 * Binds a fixed-argument member function with a return value to Godot's method call interface.
 *
 * - `T` — Class that declares the bound member function.
 * - `R` — C++ result type converted into the Godot call result.
 * - `P` — C++ parameter types in declaration order, used to decode calls and register argument types.
 */
template <typename T, typename R, typename... P>
#else
/**
 * Binds a fixed-argument member function with a return value using the placeholder class for member storage.
 *
 * - `R` — C++ result type converted into the Godot call result.
 * - `P` — C++ parameter types in declaration order, used to decode calls and register argument types.
 */
template <typename R, typename... P>
#endif // TYPED_METHOD_BIND
class MethodBindTR : public MethodBind {
	/**
	 * Stores the member function pointer used for variant and pointer calls.
	 */
	R (MB_T::*method)(P...);

protected:
// GCC raises warnings in the case P = {} as the comparison is always false...
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wlogical-op"
#endif
	/**
	 * Returns the variant type for a declared argument. Other indices use the return type.
	 *
	 * - `p_arg` — Zero-based argument index. Use minus one for the return slot.
	 */
	virtual GDExtensionVariantType gen_argument_type(int p_arg) const {
		if (p_arg >= 0 && p_arg < (int)sizeof...(P)) {
			return call_get_argument_type<P...>(p_arg);
		} else {
			return GDExtensionVariantType(GetTypeInfo<R>::VARIANT_TYPE);
		}
	}

	/**
	 * Builds property information for a declared argument or the return slot.
	 *
	 * - `p_arg` — Zero-based argument index. Use minus one for the return slot.
	 */
	virtual PropertyInfo gen_argument_type_info(int p_arg) const {
		if (p_arg >= 0 && p_arg < (int)sizeof...(P)) {
			PropertyInfo pi;
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
	/**
	 * Returns ABI metadata for the argument or the return value.
	 *
	 * - `p_argument` — Zero-based argument index. Use minus one for the return slot.
	 */
	virtual GDExtensionClassMethodArgumentMetadata get_argument_metadata(int p_argument) const {
		if (p_argument >= 0) {
			return call_get_argument_metadata<P...>(p_argument);
		} else {
			return GetTypeInfo<R>::METADATA;
		}
	}

	/**
	 * Decodes the variant arguments, fills in missing trailing defaults, and invokes the member function. Returns its result as a variant.
	 *
	 * - `p_instance` — C++ instance on which to invoke the method.
	 * - `p_args` — Borrowed array of variant pointers in call order.
	 * - `p_argument_count` — Number of supplied argument pointers.
	 * - `r_error` — Writable call status. The dispatch code reports argument errors here.
	 */
	virtual Variant call(GDExtensionClassInstancePtr p_instance, const GDExtensionConstVariantPtr *p_args, GDExtensionInt p_argument_count, GDExtensionCallError &r_error) const {
		Variant ret;
#ifdef TYPED_METHOD_BIND
		call_with_variant_args_ret_dv(static_cast<T *>(p_instance), method, p_args, (int)p_argument_count, ret, r_error, get_default_arguments());
#else
		call_with_variant_args_ret_dv((MB_T *)p_instance, method, p_args, p_argument_count, ret, r_error, get_default_arguments());
#endif
		return ret;
	}
	/**
	 * Decodes arguments from typed pointers and invokes the member function, then encodes its result in the return slot.
	 *
	 * - `p_instance` — C++ instance on which to invoke the method.
	 * - `p_args` — Borrowed array of addresses of typed arguments in call order.
	 * - `r_ret` — Writable engine storage for the encoded result.
	 */
	virtual void ptrcall(GDExtensionClassInstancePtr p_instance, const GDExtensionConstTypePtr *p_args, GDExtensionTypePtr r_ret) const {
#ifdef TYPED_METHOD_BIND
		call_with_ptr_args<T, R, P...>(static_cast<T *>(p_instance), method, p_args, r_ret);
#else
		call_with_ptr_args<MB_T, R, P...>(reinterpret_cast<MB_T *>(p_instance), method, p_args, r_ret);
#endif // TYPED_METHOD_BIND
	}

	/**
	 * Stores the pointer and builds the metadata for the fixed signature.
	 *
	 * - `p_method` — Pointer to the member function with a return value invoked by the binding.
	 */
	MethodBindTR(R (MB_T::*p_method)(P...)) {
		method = p_method;
		_generate_argument_types(sizeof...(P));
		set_argument_count(sizeof...(P));
		_set_returns(true);
	}
};

/**
 * Creates a method binding and records the declaring class for registration.
 *
 * - `T` — Class that declares the bound member function.
 * - `R` — C++ result type converted into the Godot call result.
 * - `P` — C++ parameter types in declaration order, used to decode calls and register argument types.
 * - `p_method` — Pointer to the member function with a return value to bind.
 */
template <typename T, typename R, typename... P>
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
/**
 * Binds a fixed-argument const member function with a return value to Godot's method call interface.
 *
 * - `T` — Class that declares the bound member function.
 * - `R` — C++ result type converted into the Godot call result.
 * - `P` — C++ parameter types in declaration order, used to decode calls and register argument types.
 */
template <typename T, typename R, typename... P>
#else
/**
 * Binds a fixed-argument const member function with a return value using the placeholder class for member storage.
 *
 * - `R` — C++ result type converted into the Godot call result.
 * - `P` — C++ parameter types in declaration order, used to decode calls and register argument types.
 */
template <typename R, typename... P>
#endif // TYPED_METHOD_BIND
class MethodBindTRC : public MethodBind {
	/**
	 * Stores the member function pointer used for variant and pointer calls.
	 */
	R (MB_T::*method)(P...) const;

protected:
// GCC raises warnings in the case P = {} as the comparison is always false...
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wlogical-op"
#endif
	/**
	 * Returns the variant type for a declared argument. Other indices use the return type.
	 *
	 * - `p_arg` — Zero-based argument index. Use minus one for the return slot.
	 */
	virtual GDExtensionVariantType gen_argument_type(int p_arg) const {
		if (p_arg >= 0 && p_arg < (int)sizeof...(P)) {
			return call_get_argument_type<P...>(p_arg);
		} else {
			return GDExtensionVariantType(GetTypeInfo<R>::VARIANT_TYPE);
		}
	}

	/**
	 * Builds property information for a declared argument or the return slot.
	 *
	 * - `p_arg` — Zero-based argument index. Use minus one for the return slot.
	 */
	virtual PropertyInfo gen_argument_type_info(int p_arg) const {
		if (p_arg >= 0 && p_arg < (int)sizeof...(P)) {
			PropertyInfo pi;
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
	/**
	 * Returns ABI metadata for the argument or the return value.
	 *
	 * - `p_argument` — Zero-based argument index. Use minus one for the return slot.
	 */
	virtual GDExtensionClassMethodArgumentMetadata get_argument_metadata(int p_argument) const {
		if (p_argument >= 0) {
			return call_get_argument_metadata<P...>(p_argument);
		} else {
			return GetTypeInfo<R>::METADATA;
		}
	}

	/**
	 * Decodes the variant arguments, fills in missing trailing defaults, and invokes the member function. Returns its result as a variant.
	 *
	 * - `p_instance` — C++ instance on which to invoke the method.
	 * - `p_args` — Borrowed array of variant pointers in call order.
	 * - `p_argument_count` — Number of supplied argument pointers.
	 * - `r_error` — Writable call status. The dispatch code reports argument errors here.
	 */
	virtual Variant call(GDExtensionClassInstancePtr p_instance, const GDExtensionConstVariantPtr *p_args, GDExtensionInt p_argument_count, GDExtensionCallError &r_error) const {
		Variant ret;
#ifdef TYPED_METHOD_BIND
		call_with_variant_args_retc_dv(static_cast<T *>(p_instance), method, p_args, (int)p_argument_count, ret, r_error, get_default_arguments());
#else
		call_with_variant_args_retc_dv((MB_T *)p_instance, method, p_args, p_argument_count, ret, r_error, get_default_arguments());
#endif
		return ret;
	}
	/**
	 * Decodes arguments from typed pointers and invokes the member function, then encodes its result in the return slot.
	 *
	 * - `p_instance` — C++ instance on which to invoke the method.
	 * - `p_args` — Borrowed array of addresses of typed arguments in call order.
	 * - `r_ret` — Writable engine storage for the encoded result.
	 */
	virtual void ptrcall(GDExtensionClassInstancePtr p_instance, const GDExtensionConstTypePtr *p_args, GDExtensionTypePtr r_ret) const {
#ifdef TYPED_METHOD_BIND
		call_with_ptr_args<T, R, P...>(static_cast<T *>(p_instance), method, p_args, r_ret);
#else
		call_with_ptr_args<MB_T, R, P...>(reinterpret_cast<MB_T *>(p_instance), method, p_args, r_ret);
#endif // TYPED_METHOD_BIND
	}

	/**
	 * Stores the pointer and builds the metadata for the fixed signature.
	 *
	 * - `p_method` — Pointer to the const member function with a return value invoked by the binding.
	 */
	MethodBindTRC(R (MB_T::*p_method)(P...) const) {
		method = p_method;
		_generate_argument_types(sizeof...(P));
		set_argument_count(sizeof...(P));
		_set_returns(true);
		_set_const(true);
	}
};

/**
 * Creates a method binding and records the declaring class for registration.
 *
 * - `T` — Class that declares the bound member function.
 * - `R` — C++ result type converted into the Godot call result.
 * - `P` — C++ parameter types in declaration order, used to decode calls and register argument types.
 * - `p_method` — Pointer to the const member function with a return value to bind.
 */
template <typename T, typename R, typename... P>
MethodBind *create_method_bind(R (T::*p_method)(P...) const) {
#ifdef TYPED_METHOD_BIND
	MethodBind *a = memnew((MethodBindTRC<T, R, P...>)(p_method));
#else
	MethodBind *a = memnew((MethodBindTRC<R, P...>)(reinterpret_cast<R (MB_T::*)(P...) const>(p_method)));
#endif // TYPED_METHOD_BIND
	a->set_instance_class(T::get_class_static());
	return a;
}

// STATIC BINDS

// no return

/**
 * Binds a fixed-argument static function returning void to Godot's method call interface.
 *
 * - `P` — C++ parameter types in declaration order, used to decode calls and register argument types.
 */
template <typename... P>
class MethodBindTS : public MethodBind {
	/**
	 * Stores the function pointer used for variant and pointer calls.
	 */
	void (*function)(P...);

protected:
// GCC raises warnings in the case P = {} as the comparison is always false...
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wlogical-op"
#endif
	/**
	 * Returns the variant type for a declared argument, or nil outside that range.
	 *
	 * - `p_arg` — Zero-based argument index. Use minus one for the return slot.
	 */
	virtual GDExtensionVariantType gen_argument_type(int p_arg) const {
		if (p_arg >= 0 && p_arg < (int)sizeof...(P)) {
			return call_get_argument_type<P...>(p_arg);
		} else {
			return GDEXTENSION_VARIANT_TYPE_NIL;
		}
	}

	/**
	 * Builds property information for a declared argument. Outside that range the descriptor is empty.
	 *
	 * - `p_arg` — Zero-based argument index. Use minus one for the return slot.
	 */
	virtual PropertyInfo gen_argument_type_info(int p_arg) const {
		PropertyInfo pi;
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
	/**
	 * Returns ABI metadata for a declared argument.
	 *
	 * - `p_arg` — Zero-based argument index. Use minus one for the return slot.
	 */
	virtual GDExtensionClassMethodArgumentMetadata get_argument_metadata(int p_arg) const {
		return call_get_argument_metadata<P...>(p_arg);
	}

	/**
	 * Decodes the variant arguments, fills in missing trailing defaults, and invokes the function. Returns a nil variant.
	 *
	 * - `p_object` — Instance pointer supplied by Godot. The static call does not use it.
	 * - `p_args` — Borrowed array of variant pointers in call order.
	 * - `p_arg_count` — Number of supplied argument pointers.
	 * - `r_error` — Writable call status. The dispatch code reports argument errors here.
	 */
	virtual Variant call(GDExtensionClassInstancePtr p_object, const GDExtensionConstVariantPtr *p_args, GDExtensionInt p_arg_count, GDExtensionCallError &r_error) const {
		(void)p_object; // unused
		call_with_variant_args_static_dv(function, p_args, p_arg_count, r_error, get_default_arguments());
		return Variant();
	}

	/**
	 * Decodes arguments from typed pointers and invokes the function.
	 *
	 * - `p_object` — Instance pointer supplied by Godot. The static call does not use it.
	 * - `p_args` — Borrowed array of addresses of typed arguments in call order.
	 * - `r_ret` — Return storage supplied by the caller. A void call leaves it untouched.
	 */
	virtual void ptrcall(GDExtensionClassInstancePtr p_object, const GDExtensionConstTypePtr *p_args, GDExtensionTypePtr r_ret) const {
		(void)p_object;
		(void)r_ret;
		call_with_ptr_args_static_method(function, p_args);
	}

	/**
	 * Stores the pointer and builds the metadata for the fixed signature.
	 *
	 * - `p_function` — Pointer to the static function returning void invoked by the binding.
	 */
	MethodBindTS(void (*p_function)(P...)) {
		function = p_function;
		_generate_argument_types(sizeof...(P));
		set_argument_count(sizeof...(P));
		_set_static(true);
	}
};

/**
 * Creates a binding for the function. The registry assigns the exposing class separately.
 *
 * - `P` — C++ parameter types in declaration order, used to decode calls and register argument types.
 * - `p_method` — Pointer to the static function returning void to bind.
 */
template <typename... P>
MethodBind *create_static_method_bind(void (*p_method)(P...)) {
	MethodBind *a = memnew((MethodBindTS<P...>)(p_method));
	return a;
}

// return

/**
 * Binds a fixed-argument static function with a return value to Godot's method call interface.
 *
 * - `R` — C++ result type converted into the Godot call result.
 * - `P` — C++ parameter types in declaration order, used to decode calls and register argument types.
 */
template <typename R, typename... P>
class MethodBindTRS : public MethodBind {
	/**
	 * Stores the function pointer used for variant and pointer calls.
	 */
	R (*function)(P...);

protected:
// GCC raises warnings in the case P = {} as the comparison is always false...
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wlogical-op"
#endif
	/**
	 * Returns the variant type for a declared argument. Other indices use the return type.
	 *
	 * - `p_arg` — Zero-based argument index. Use minus one for the return slot.
	 */
	virtual GDExtensionVariantType gen_argument_type(int p_arg) const {
		if (p_arg >= 0 && p_arg < (int)sizeof...(P)) {
			return call_get_argument_type<P...>(p_arg);
		} else {
			return GDExtensionVariantType(GetTypeInfo<R>::VARIANT_TYPE);
		}
	}

	/**
	 * Builds property information for a declared argument or the return slot.
	 *
	 * - `p_arg` — Zero-based argument index. Use minus one for the return slot.
	 */
	virtual PropertyInfo gen_argument_type_info(int p_arg) const {
		if (p_arg >= 0 && p_arg < (int)sizeof...(P)) {
			PropertyInfo pi;
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
	/**
	 * Returns ABI metadata for the argument or the return value.
	 *
	 * - `p_arg` — Zero-based argument index. Use minus one for the return slot.
	 */
	virtual GDExtensionClassMethodArgumentMetadata get_argument_metadata(int p_arg) const {
		if (p_arg >= 0) {
			return call_get_argument_metadata<P...>(p_arg);
		} else {
			return GetTypeInfo<R>::METADATA;
		}
	}

	/**
	 * Decodes the variant arguments, fills in missing trailing defaults, and invokes the function. Returns its result as a variant.
	 *
	 * - `p_object` — Instance pointer supplied by Godot. The static call does not use it.
	 * - `p_args` — Borrowed array of variant pointers in call order.
	 * - `p_arg_count` — Number of supplied argument pointers.
	 * - `r_error` — Writable call status. The dispatch code reports argument errors here.
	 */
	virtual Variant call(GDExtensionClassInstancePtr p_object, const GDExtensionConstVariantPtr *p_args, GDExtensionInt p_arg_count, GDExtensionCallError &r_error) const {
		Variant ret;
		call_with_variant_args_static_ret_dv(function, p_args, p_arg_count, ret, r_error, get_default_arguments());
		return ret;
	}

	/**
	 * Decodes arguments from typed pointers and invokes the function, then encodes its result in the return slot.
	 *
	 * - `p_object` — Instance pointer supplied by Godot. The static call does not use it.
	 * - `p_args` — Borrowed array of addresses of typed arguments in call order.
	 * - `r_ret` — Writable engine storage for the encoded result.
	 */
	virtual void ptrcall(GDExtensionClassInstancePtr p_object, const GDExtensionConstTypePtr *p_args, GDExtensionTypePtr r_ret) const {
		(void)p_object;
		call_with_ptr_args_static_method_ret(function, p_args, r_ret);
	}

	/**
	 * Stores the pointer and builds the metadata for the fixed signature.
	 *
	 * - `p_function` — Pointer to the static function with a return value invoked by the binding.
	 */
	MethodBindTRS(R (*p_function)(P...)) {
		function = p_function;
		_generate_argument_types(sizeof...(P));
		set_argument_count(sizeof...(P));
		_set_static(true);
		_set_returns(true);
	}
};

/**
 * Creates a binding for the function. The registry assigns the exposing class separately.
 *
 * - `R` — C++ result type converted into the Godot call result.
 * - `P` — C++ parameter types in declaration order, used to decode calls and register argument types.
 * - `p_method` — Pointer to the static function with a return value to bind.
 */
template <typename R, typename... P>
MethodBind *create_static_method_bind(R (*p_method)(P...)) {
	MethodBind *a = memnew((MethodBindTRS<R, P...>)(p_method));
	return a;
}

} // namespace godot
