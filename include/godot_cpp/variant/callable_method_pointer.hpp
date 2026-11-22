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

#pragma once

#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/variant/variant.hpp>

namespace godot {

/**
 * Base for extension callables backed by C++ function pointers. Keeps comparison data and a hash for engine callable operations.
 */
class CallableCustomMethodPointerBase : public CallableCustomBase {
	/**
	 * Points to the derived callable's comparison words.
	 */
	uint32_t *comp_ptr = nullptr;
	/**
	 * Counts the 32-bit comparison words in the derived callable's payload.
	 */
	uint32_t comp_size;
	/**
	 * Stores the hash computed from the comparison payload.
	 */
	uint32_t h;

protected:
	/**
	 * Records a payload that stays valid for the callable's lifetime and computes its hash. The size is measured in bytes.
	 *
	 * - `p_base_ptr` — First word of the comparison payload. The buffer must remain valid for the lifetime of the callable.
	 * - `p_ptr_size` — Payload size in bytes. It must be a positive multiple of the size of a 32-bit word.
	 */
	void _setup(uint32_t *p_base_ptr, uint32_t p_ptr_size);

public:
	/**
	 * Returns the comparison word array used by equality and ordering callbacks.
	 */
	_FORCE_INLINE_ const uint32_t *get_comp_ptr() const { return comp_ptr; }
	/**
	 * Returns the number of 32-bit comparison words.
	 */
	_FORCE_INLINE_ uint32_t get_comp_size() const { return comp_size; }
	/**
	 * Returns the cached payload hash.
	 */
	_FORCE_INLINE_ uint32_t get_hash() const { return h; }
};

namespace internal {

/**
 * Creates an engine callable around the supplied implementation. The engine's free callback deletes the implementation.
 *
 * - `p_callable_method_pointer` — Implementation to attach as engine userdata. The callable takes ownership and releases it through its free callback.
 */
Callable create_callable_from_ccmp(CallableCustomMethodPointerBase *p_callable_method_pointer);

} // namespace internal

//
// No return value.
//

/**
 * Adapts a non-const member function returning void to an engine callable.
 *
 * - `T` — Godot object wrapper class that declares the member function.
 * - `P` — C++ parameter types in the order used to convert the incoming variants.
 */
template <typename T, typename... P>
class CallableCustomMethodPointer : public CallableCustomMethodPointerBase {
	/**
	 * Stores the target instance and function pointer used for dispatch and bytewise comparison.
	 */
	struct Data {
		/**
		 * Points to the instance on which to invoke the method.
		 */
		T *instance;
		/**
		 * Stores the C++ function pointer invoked by the callable.
		 */
		void (T::*method)(P...);
	} data;
	static_assert(sizeof(Data) % 4 == 0);

public:
	/**
	 * Returns the receiver's object ID for callable registration. The validity callback uses this ID to check whether the receiver still exists in the object database.
	 */
	virtual ObjectID get_object() const override {
		return ObjectID(data.instance->get_instance_id());
	}

	/**
	 * Reports the parameter pack size as a known argument count.
	 *
	 * - `r_is_valid` — Set to true to tell the caller that the returned count is known.
	 */
	virtual int get_argument_count(bool &r_is_valid) const override {
		r_is_valid = true;
		return sizeof...(P);
	}

	/**
	 * Invokes the member function with converted variant arguments and reports argument errors. There is no C++ result to write.
	 *
	 * - `p_arguments` — Array of pointers to the incoming variants in C++ parameter order. The dispatcher borrows the array and its values for the call.
	 * - `p_argcount` — Number of supplied argument pointers. Debug builds check it against the number of C++ parameters.
	 * - `r_return_value` — Return slot supplied by the engine. This void member-function adapter leaves it untouched.
	 * - `r_call_error` — Output call status. Debug builds can report invalid argument counts or types.
	 */
	virtual void call(const Variant **p_arguments, int p_argcount, Variant &r_return_value, GDExtensionCallError &r_call_error) const override {
		call_with_variant_args(data.instance, data.method, p_arguments, p_argcount, r_call_error);
	}

	/**
	 * Stores the instance and function pointer in a zero-initialized comparison payload and records its hash.
	 *
	 * - `p_instance` — Live Godot object wrapper on which the callable invokes the method.
	 * - `p_method` — Pointer to the non-const member function invoked on the target instance.
	 */
	CallableCustomMethodPointer(T *p_instance, void (T::*p_method)(P...)) {
		memset(&data, 0, sizeof(Data));
		data.instance = p_instance;
		data.method = p_method;
		_setup((uint32_t *)&data, sizeof(Data));
	}
};

/**
 * Returns an engine callable for the supplied non-const member function returning void. The target instance supplies the callable's object identifier.
 *
 * - `T` — Godot object wrapper class that declares the member function.
 * - `P` — C++ parameter types in the order used to convert the incoming variants.
 * - `p_instance` — Live Godot object wrapper on which the callable invokes the method.
 * - `p_method` — Pointer to the non-const member function invoked on the target instance.
 */
template <typename T, typename... P>
Callable create_custom_callable_function_pointer(T *p_instance, void (T::*p_method)(P...)) {
	/**
	 * Names the concrete callable implementation for allocation through `memnew`.
	 */
	typedef CallableCustomMethodPointer<T, P...> CCMP;
	CCMP *ccmp = memnew(CCMP(p_instance, p_method));
	return ::godot::internal::create_callable_from_ccmp(ccmp);
}

//
// With return value.
//

/**
 * Adapts a non-const member function with a return value to an engine callable.
 *
 * - `T` — Godot object wrapper class that declares the member function.
 * - `R` — C++ return type converted to a Godot variant.
 * - `P` — C++ parameter types in the order used to convert the incoming variants.
 */
template <typename T, typename R, typename... P>
class CallableCustomMethodPointerRet : public CallableCustomMethodPointerBase {
	/**
	 * Stores the target instance and function pointer used for dispatch and bytewise comparison.
	 */
	struct Data {
		/**
		 * Points to the instance on which to invoke the method.
		 */
		T *instance;
		/**
		 * Stores the C++ function pointer invoked by the callable.
		 */
		R (T::*method)(P...);
	} data;
	static_assert(sizeof(Data) % 4 == 0);

public:
	/**
	 * Returns the receiver's object ID for callable registration. The validity callback uses this ID to check whether the receiver still exists in the object database.
	 */
	virtual ObjectID get_object() const override {
		return ObjectID(data.instance->get_instance_id());
	}

	/**
	 * Reports the parameter pack size as a known argument count.
	 *
	 * - `r_is_valid` — Set to true to tell the caller that the returned count is known.
	 */
	virtual int get_argument_count(bool &r_is_valid) const override {
		r_is_valid = true;
		return sizeof...(P);
	}

	/**
	 * Invokes the member function with converted variant arguments and converts its result to a variant.
	 *
	 * - `p_arguments` — Array of pointers to the incoming variants in C++ parameter order. The dispatcher borrows the array and its values for the call.
	 * - `p_argcount` — Number of supplied argument pointers. Debug builds check it against the number of C++ parameters.
	 * - `r_return_value` — Output slot for the C++ return value converted to a variant when the target is called.
	 * - `r_call_error` — Output call status. Debug builds can report invalid argument counts or types.
	 */
	virtual void call(const Variant **p_arguments, int p_argcount, Variant &r_return_value, GDExtensionCallError &r_call_error) const override {
		call_with_variant_args_ret(data.instance, data.method, p_arguments, p_argcount, r_return_value, r_call_error);
	}

	/**
	 * Stores the instance and function pointer in a zero-initialized comparison payload and records its hash.
	 *
	 * - `p_instance` — Live Godot object wrapper on which the callable invokes the method.
	 * - `p_method` — Pointer to the non-const member function invoked on the target instance.
	 */
	CallableCustomMethodPointerRet(T *p_instance, R (T::*p_method)(P...)) {
		memset(&data, 0, sizeof(Data));
		data.instance = p_instance;
		data.method = p_method;
		_setup((uint32_t *)&data, sizeof(Data));
	}
};

/**
 * Returns an engine callable for the supplied non-const member function with a return value. The target instance supplies the callable's object identifier.
 *
 * - `T` — Godot object wrapper class that declares the member function.
 * - `R` — C++ return type converted to a Godot variant.
 * - `P` — C++ parameter types in the order used to convert the incoming variants.
 * - `p_instance` — Live Godot object wrapper on which the callable invokes the method.
 * - `p_method` — Pointer to the non-const member function invoked on the target instance.
 */
template <typename T, typename R, typename... P>
Callable create_custom_callable_function_pointer(T *p_instance, R (T::*p_method)(P...)) {
	/**
	 * Names the concrete callable implementation for allocation through `memnew`.
	 */
	typedef CallableCustomMethodPointerRet<T, R, P...> CCMP; // Messes with memnew otherwise.
	CCMP *ccmp = memnew(CCMP(p_instance, p_method));
	return ::godot::internal::create_callable_from_ccmp(ccmp);
}

//
// Const with return value.
//

/**
 * Adapts a const member function with a return value to an engine callable.
 *
 * - `T` — Godot object wrapper class that declares the member function.
 * - `R` — C++ return type converted to a Godot variant.
 * - `P` — C++ parameter types in the order used to convert the incoming variants.
 */
template <typename T, typename R, typename... P>
class CallableCustomMethodPointerRetC : public CallableCustomMethodPointerBase {
	/**
	 * Stores the target instance and function pointer used for dispatch and bytewise comparison.
	 */
	struct Data {
		/**
		 * Points to the instance on which to invoke the method.
		 */
		T *instance;
		/**
		 * Stores the C++ function pointer invoked by the callable.
		 */
		R (T::*method)(P...) const;
	} data;
	static_assert(sizeof(Data) % 4 == 0);

public:
	/**
	 * Returns the receiver's object ID for callable registration. The validity callback uses this ID to check whether the receiver still exists in the object database.
	 */
	virtual ObjectID get_object() const override {
		return ObjectID(data.instance->get_instance_id());
	}

	/**
	 * Reports the parameter pack size as a known argument count.
	 *
	 * - `r_is_valid` — Set to true to tell the caller that the returned count is known.
	 */
	virtual int get_argument_count(bool &r_is_valid) const override {
		r_is_valid = true;
		return sizeof...(P);
	}

	/**
	 * Invokes the const member function with converted variant arguments and converts its result to a variant.
	 *
	 * - `p_arguments` — Array of pointers to the incoming variants in C++ parameter order. The dispatcher borrows the array and its values for the call.
	 * - `p_argcount` — Number of supplied argument pointers. Debug builds check it against the number of C++ parameters.
	 * - `r_return_value` — Output slot for the C++ return value converted to a variant when the target is called.
	 * - `r_call_error` — Output call status. Debug builds can report invalid argument counts or types.
	 */
	virtual void call(const Variant **p_arguments, int p_argcount, Variant &r_return_value, GDExtensionCallError &r_call_error) const override {
		call_with_variant_args_retc(data.instance, data.method, p_arguments, p_argcount, r_return_value, r_call_error);
	}

	/**
	 * Stores the instance and function pointer in a zero-initialized comparison payload and records its hash.
	 *
	 * - `p_instance` — Live Godot object wrapper on which the callable invokes the method.
	 * - `p_method` — Pointer to the const member function invoked on the target instance.
	 */
	CallableCustomMethodPointerRetC(const T *p_instance, R (T::*p_method)(P...) const) {
		memset(&data, 0, sizeof(Data));
		data.instance = const_cast<T *>(p_instance);
		data.method = p_method;
		_setup((uint32_t *)&data, sizeof(Data));
	}
};

/**
 * Returns an engine callable for the supplied const member function with a return value. The target instance supplies the callable's object identifier.
 *
 * - `T` — Godot object wrapper class that declares the member function.
 * - `R` — C++ return type converted to a Godot variant.
 * - `P` — C++ parameter types in the order used to convert the incoming variants.
 * - `p_instance` — Live Godot object wrapper on which the callable invokes the method.
 * - `p_method` — Pointer to the const member function invoked on the target instance.
 */
template <typename T, typename R, typename... P>
Callable create_custom_callable_function_pointer(const T *p_instance, R (T::*p_method)(P...) const) {
	/**
	 * Names the concrete callable implementation for allocation through `memnew`.
	 */
	typedef CallableCustomMethodPointerRetC<T, R, P...> CCMP; // Messes with memnew otherwise.
	CCMP *ccmp = memnew(CCMP(p_instance, p_method));
	return ::godot::internal::create_callable_from_ccmp(ccmp);
}

//
// Static method with no return value.
//

/**
 * Adapts a free or static function returning void to an engine callable.
 *
 * - `P` — C++ parameter types in the order used to convert the incoming variants.
 */
template <typename... P>
class CallableCustomStaticMethodPointer : public CallableCustomMethodPointerBase {
	/**
	 * Stores the function pointer used for dispatch and bytewise comparison.
	 */
	struct Data {
		/**
		 * Stores the C++ function pointer invoked by the callable.
		 */
		void (*method)(P...);
	} data;
	static_assert(sizeof(Data) % 4 == 0);

public:
	/**
	 * Returns the zero object ID that marks this callable as having no receiver. Its validity callback accepts this ID without consulting the object database.
	 */
	virtual ObjectID get_object() const override {
		return ObjectID();
	}

	/**
	 * Reports the parameter pack size as a known argument count.
	 *
	 * - `r_is_valid` — Set to true to tell the caller that the returned count is known.
	 */
	virtual int get_argument_count(bool &r_is_valid) const override {
		r_is_valid = true;
		return sizeof...(P);
	}

	/**
	 * Invokes the function with converted variant arguments and sets the return variant to nil.
	 *
	 * - `p_arguments` — Array of pointers to the incoming variants in C++ parameter order. The dispatcher borrows the array and its values for the call.
	 * - `p_argcount` — Number of supplied argument pointers. Debug builds check it against the number of C++ parameters.
	 * - `r_return_value` — Output slot set to a nil variant, including when argument validation rejects the call.
	 * - `r_call_error` — Output call status. Debug builds can report invalid argument counts or types.
	 */
	virtual void call(const Variant **p_arguments, int p_argcount, Variant &r_return_value, GDExtensionCallError &r_call_error) const override {
		call_with_variant_args_static_ret(data.method, p_arguments, p_argcount, r_return_value, r_call_error);
		r_return_value = Variant();
	}

	/**
	 * Stores the function pointer in a zero-initialized comparison payload and records its hash.
	 *
	 * - `p_method` — Pointer to the free or static C++ function invoked by the callable.
	 */
	CallableCustomStaticMethodPointer(void (*p_method)(P...)) {
		memset(&data, 0, sizeof(Data));
		data.method = p_method;
		_setup((uint32_t *)&data, sizeof(Data));
	}
};

/**
 * Returns an engine callable for the supplied free or static function returning void.
 *
 * - `P` — C++ parameter types in the order used to convert the incoming variants.
 * - `p_method` — Pointer to the free or static C++ function invoked by the callable.
 */
template <typename... P>
Callable create_custom_callable_static_function_pointer(void (*p_method)(P...)) {
	/**
	 * Names the concrete callable implementation for allocation through `memnew`.
	 */
	typedef CallableCustomStaticMethodPointer<P...> CCMP;
	CCMP *ccmp = memnew(CCMP(p_method));
	return ::godot::internal::create_callable_from_ccmp(ccmp);
}

//
// Static method with return value.
//

/**
 * Adapts a free or static function with a return value to an engine callable.
 *
 * - `R` — C++ return type converted to a Godot variant.
 * - `P` — C++ parameter types in the order used to convert the incoming variants.
 */
template <typename R, typename... P>
class CallableCustomStaticMethodPointerRet : public CallableCustomMethodPointerBase {
	/**
	 * Stores the function pointer used for dispatch and bytewise comparison.
	 */
	struct Data {
		/**
		 * Stores the C++ function pointer invoked by the callable.
		 */
		R (*method)(P...);
	} data;
	static_assert(sizeof(Data) % 4 == 0);

public:
	/**
	 * Returns the zero object ID that marks this callable as having no receiver. Its validity callback accepts this ID without consulting the object database.
	 */
	virtual ObjectID get_object() const override {
		return ObjectID();
	}

	/**
	 * Reports the parameter pack size as a known argument count.
	 *
	 * - `r_is_valid` — Set to true to tell the caller that the returned count is known.
	 */
	virtual int get_argument_count(bool &r_is_valid) const override {
		r_is_valid = true;
		return sizeof...(P);
	}

	/**
	 * Invokes the function with converted variant arguments and converts its result to a variant.
	 *
	 * - `p_arguments` — Array of pointers to the incoming variants in C++ parameter order. The dispatcher borrows the array and its values for the call.
	 * - `p_argcount` — Number of supplied argument pointers. Debug builds check it against the number of C++ parameters.
	 * - `r_return_value` — Output slot for the C++ return value converted to a variant when the target is called.
	 * - `r_call_error` — Output call status. Debug builds can report invalid argument counts or types.
	 */
	virtual void call(const Variant **p_arguments, int p_argcount, Variant &r_return_value, GDExtensionCallError &r_call_error) const override {
		call_with_variant_args_static_ret(data.method, p_arguments, p_argcount, r_return_value, r_call_error);
	}

	/**
	 * Stores the function pointer in a zero-initialized comparison payload and records its hash.
	 *
	 * - `p_method` — Pointer to the free or static C++ function invoked by the callable.
	 */
	CallableCustomStaticMethodPointerRet(R (*p_method)(P...)) {
		memset(&data, 0, sizeof(Data));
		data.method = p_method;
		_setup((uint32_t *)&data, sizeof(Data));
	}
};

/**
 * Returns an engine callable for the supplied free or static function with a return value.
 *
 * - `R` — C++ return type converted to a Godot variant.
 * - `P` — C++ parameter types in the order used to convert the incoming variants.
 * - `p_method` — Pointer to the free or static C++ function invoked by the callable.
 */
template <typename R, typename... P>
Callable create_custom_callable_static_function_pointer(R (*p_method)(P...)) {
	/**
	 * Names the concrete callable implementation for allocation through `memnew`.
	 */
	typedef CallableCustomStaticMethodPointerRet<R, P...> CCMP;
	CCMP *ccmp = memnew(CCMP(p_method));
	return ::godot::internal::create_callable_from_ccmp(ccmp);
}

//
// The API:
//

/**
 * Creates a callable for a C++ member function on the supplied instance.
 *
 * - `I` — Object instance on which the method is invoked.
 * - `M` — Pointer to a C++ member function compatible with the instance.
 */
#define callable_mp(I, M) ::godot::create_custom_callable_function_pointer(I, M)
/**
 * Creates a callable for a free or static C++ function.
 *
 * - `M` — Pointer to a free or static C++ function.
 */
#define callable_mp_static(M) ::godot::create_custom_callable_static_function_pointer(M)

} // namespace godot
