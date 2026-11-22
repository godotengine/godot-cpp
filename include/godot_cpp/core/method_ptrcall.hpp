/**************************************************************************/
/*  method_ptrcall.hpp                                                    */
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

#include <godot_cpp/core/defs.hpp>

#include <godot_cpp/core/object.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/variant/variant.hpp>

namespace godot {

/**
 * Provides the primary template for conversions between C++ values and pointer-call storage.
 *
 * **Used for** selecting the argument and result conversions in a C++ method binding.
 *
 * - `T` — C++ argument or result type whose storage conversion is defined by a specialization.
 */
template <typename T>
struct PtrToArg {};

/**
 * Provides by-value and const-reference adapters that copy the type directly between engine storage and C++.
 *
 * **Used for** binding types such as `godot::Vector2` whose C++ values share the engine's pointer-call representation.
 *
 * - `m_type` — C++ value type stored in the argument and result slots.
 */
#define MAKE_PTRARG(m_type) \
	template <> \
	struct PtrToArg<m_type> { \
		_FORCE_INLINE_ static m_type convert(const void *p_ptr) { \
			return *reinterpret_cast<const m_type *>(p_ptr); \
		} \
		typedef m_type EncodeT; \
		_FORCE_INLINE_ static void encode(m_type p_val, void *p_ptr) { \
			*reinterpret_cast<m_type *>(p_ptr) = p_val; \
		} \
	}; \
	template <> \
	struct PtrToArg<const m_type &> { \
		_FORCE_INLINE_ static m_type convert(const void *p_ptr) { \
			return *reinterpret_cast<const m_type *>(p_ptr); \
		} \
		typedef m_type EncodeT; \
		_FORCE_INLINE_ static void encode(m_type p_val, void *p_ptr) { \
			*reinterpret_cast<m_type *>(p_ptr) = p_val; \
		} \
	}

/**
 * Provides by-value and const-reference adapters that cast between the C++ value type and a different pointer-call storage type. Also exposes the encoded argument value for outgoing calls.
 *
 * **Used for** passing C++ types such as `float` through engine slots that use a different type, such as `double`.
 *
 * - `m_type` — Type in the C++ method signature.
 * - `m_conv` — Type used by the engine for the argument and result slots.
 */
#define MAKE_PTRARGCONV(m_type, m_conv) \
	template <> \
	struct PtrToArg<m_type> { \
		_FORCE_INLINE_ static m_type convert(const void *p_ptr) { \
			return static_cast<m_type>(*reinterpret_cast<const m_conv *>(p_ptr)); \
		} \
		typedef m_conv EncodeT; \
		_FORCE_INLINE_ static void encode(m_type p_val, void *p_ptr) { \
			*reinterpret_cast<m_conv *>(p_ptr) = static_cast<m_conv>(p_val); \
		} \
		_FORCE_INLINE_ static m_conv encode_arg(m_type p_val) { \
			return static_cast<m_conv>(p_val); \
		} \
	}; \
	template <> \
	struct PtrToArg<const m_type &> { \
		_FORCE_INLINE_ static m_type convert(const void *p_ptr) { \
			return static_cast<m_type>(*reinterpret_cast<const m_conv *>(p_ptr)); \
		} \
		typedef m_conv EncodeT; \
		_FORCE_INLINE_ static void encode(m_type p_val, void *p_ptr) { \
			*reinterpret_cast<m_conv *>(p_ptr) = static_cast<m_conv>(p_val); \
		} \
		_FORCE_INLINE_ static m_conv encode_arg(m_type p_val) { \
			return static_cast<m_conv>(p_val); \
		} \
	}

/**
 * Provides value and const-reference adapters that read a copy from engine storage and accept the encoded value by const reference.
 *
 * **Used for** writing results such as `godot::Transform3D` into a pointer-call slot from a C++ reference.
 *
 * - `m_type` — C++ value type copied between the C++ caller and the engine slot.
 */
#define MAKE_PTRARG_BY_REFERENCE(m_type) \
	template <> \
	struct PtrToArg<m_type> { \
		_FORCE_INLINE_ static m_type convert(const void *p_ptr) { \
			return *reinterpret_cast<const m_type *>(p_ptr); \
		} \
		typedef m_type EncodeT; \
		_FORCE_INLINE_ static void encode(const m_type &p_val, void *p_ptr) { \
			*reinterpret_cast<m_type *>(p_ptr) = p_val; \
		} \
	}; \
	template <> \
	struct PtrToArg<const m_type &> { \
		_FORCE_INLINE_ static m_type convert(const void *p_ptr) { \
			return *reinterpret_cast<const m_type *>(p_ptr); \
		} \
		typedef m_type EncodeT; \
		_FORCE_INLINE_ static void encode(const m_type &p_val, void *p_ptr) { \
			*reinterpret_cast<m_type *>(p_ptr) = p_val; \
		} \
	}

MAKE_PTRARGCONV(bool, uint8_t);
// Integer types.
MAKE_PTRARGCONV(uint8_t, int64_t);
MAKE_PTRARGCONV(int8_t, int64_t);
MAKE_PTRARGCONV(uint16_t, int64_t);
MAKE_PTRARGCONV(int16_t, int64_t);
MAKE_PTRARGCONV(uint32_t, int64_t);
MAKE_PTRARGCONV(int32_t, int64_t);
MAKE_PTRARGCONV(char16_t, int64_t);
MAKE_PTRARGCONV(char32_t, int64_t);
MAKE_PTRARGCONV(wchar_t, int64_t);
MAKE_PTRARG(int64_t);
MAKE_PTRARG(uint64_t);
// Float types
MAKE_PTRARGCONV(float, double);
MAKE_PTRARG(double);

MAKE_PTRARG(String);
MAKE_PTRARG(Vector2);
MAKE_PTRARG(Vector2i);
MAKE_PTRARG(Rect2);
MAKE_PTRARG(Rect2i);
MAKE_PTRARG_BY_REFERENCE(Vector3);
MAKE_PTRARG_BY_REFERENCE(Vector3i);
MAKE_PTRARG(Transform2D);
MAKE_PTRARG_BY_REFERENCE(Vector4);
MAKE_PTRARG_BY_REFERENCE(Vector4i);
MAKE_PTRARG_BY_REFERENCE(Plane);
MAKE_PTRARG(Quaternion);
MAKE_PTRARG_BY_REFERENCE(AABB);
MAKE_PTRARG_BY_REFERENCE(Basis);
MAKE_PTRARG_BY_REFERENCE(Transform3D);
MAKE_PTRARG_BY_REFERENCE(Projection);
MAKE_PTRARG_BY_REFERENCE(Color);
MAKE_PTRARG(StringName);
MAKE_PTRARG(NodePath);
MAKE_PTRARG(RID);
// Object doesn't need this.
MAKE_PTRARG(Callable);
MAKE_PTRARG(Signal);
MAKE_PTRARG(Dictionary);
MAKE_PTRARG(Array);
MAKE_PTRARG(PackedByteArray);
MAKE_PTRARG(PackedInt32Array);
MAKE_PTRARG(PackedInt64Array);
MAKE_PTRARG(PackedFloat32Array);
MAKE_PTRARG(PackedFloat64Array);
MAKE_PTRARG(PackedStringArray);
MAKE_PTRARG(PackedVector2Array);
MAKE_PTRARG(PackedVector3Array);
MAKE_PTRARG(PackedVector4Array);
MAKE_PTRARG(PackedColorArray);
MAKE_PTRARG_BY_REFERENCE(Variant);

// This is for Object.

/**
 * Adapts a non-const Godot object wrapper pointer to the engine object pointer passed through the ABI.
 *
 * **Used for** binding C++ methods that take or return mutable Godot object pointers.
 *
 * - `T` — Non-const class derived from `godot::Object`.
 */
template <typename T>
struct PtrToArg<T *> {
	static_assert(std::is_base_of<Object, T>::value, "Cannot encode non-Object value as an Object");
	/**
	 * Returns the C++ instance binding for the engine object in the argument slot. Returns null for a null slot
	 * or null object pointer.
	 *
	 * **Used for** passing an engine object argument to a C++ method that can modify the object.
	 *
	 * - `p_ptr` — Address of a slot containing a `GDExtensionObjectPtr`, or null for an absent argument.
	 */
	_FORCE_INLINE_ static T *convert(const void *p_ptr) {
		return likely(p_ptr) ? reinterpret_cast<T *>(::godot::internal::get_object_instance_binding(*reinterpret_cast<GDExtensionObjectPtr *>(const_cast<void *>(p_ptr)))) : nullptr;
	}
	/**
	 * Defines the common mutable object pointer type used by the return adapter.
	 *
	 * **Used for** exposing the result storage type through the same adapter interface as value results.
	 */
	typedef Object *EncodeT;
	/**
	 * Writes the wrapped engine object pointer, or null for a null C++ pointer.
	 *
	 * **Used for** returning an object from a C++ method through the engine's pointer-call result slot.
	 *
	 * - `p_var` — C++ wrapper whose engine object is returned, or null.
	 * - `p_ptr` — Writable address of the result slot. The engine object pointer is always written.
	 */
	_FORCE_INLINE_ static void encode(T *p_var, void *p_ptr) {
		*reinterpret_cast<const void **>(p_ptr) = likely(p_var) ? p_var->_owner : nullptr;
	}
};

/**
 * Adapts a const Godot object wrapper pointer to the engine object pointer passed through the ABI.
 *
 * **Used for** binding C++ methods with read-only Godot object pointer parameters or results.
 *
 * - `T` — Godot object class whose C++ wrapper is accessed through a const pointer.
 */
template <typename T>
struct PtrToArg<const T *> {
	static_assert(std::is_base_of<Object, T>::value, "Cannot encode non-Object value as an Object");
	/**
	 * Returns the C++ instance binding as a const pointer. Returns null for a null slot or null object pointer.
	 *
	 * **Used for** passing an engine object argument to a C++ method that takes a pointer to const.
	 *
	 * - `p_ptr` — Address of a slot containing a `GDExtensionObjectPtr`, or null for an absent argument.
	 */
	_FORCE_INLINE_ static const T *convert(const void *p_ptr) {
		return likely(p_ptr) ? reinterpret_cast<const T *>(::godot::internal::get_object_instance_binding(*reinterpret_cast<GDExtensionObjectPtr *>(const_cast<void *>(p_ptr)))) : nullptr;
	}
	/**
	 * Defines the common const object pointer type used by the return adapter.
	 *
	 * **Used for** selecting const pointer result storage from the declared C++ return type.
	 */
	typedef const Object *EncodeT;
	/**
	 * Writes the wrapped engine object pointer, or null for a null C++ pointer.
	 *
	 * **Used for** returning the engine object for a const wrapper without modifying the wrapper.
	 *
	 * - `p_var` — Const C++ wrapper whose engine object is returned, or null.
	 * - `p_ptr` — Writable address of the result slot. The engine object pointer is always written.
	 */
	_FORCE_INLINE_ static void encode(T *p_var, void *p_ptr) {
		*reinterpret_cast<const void **>(p_ptr) = likely(p_var) ? p_var->_owner : nullptr;
	}
};

// Pointers.
/**
 * Provides direct pointer-slot adapters for native pointers and pointers to const native data used by generated virtual calls.
 *
 * **Used for** passing data such as `godot::Glyph` buffers through a native pointer in a generated virtual binding.
 *
 * - `m_type` — Type addressed by the pointer in the C++ signature.
 */
#define GDVIRTUAL_NATIVE_PTR(m_type) \
	template <> \
	struct PtrToArg<m_type *> { \
		_FORCE_INLINE_ static m_type *convert(const void *p_ptr) { \
			return (m_type *)(*(void **)p_ptr); \
		} \
		typedef m_type *EncodeT; \
		_FORCE_INLINE_ static void encode(m_type *p_var, void *p_ptr) { \
			*reinterpret_cast<m_type **>(p_ptr) = p_var; \
		} \
	}; \
\
	template <> \
	struct PtrToArg<const m_type *> { \
		_FORCE_INLINE_ static const m_type *convert(const void *p_ptr) { \
			return (const m_type *)(*(const void **)p_ptr); \
		} \
		typedef const m_type *EncodeT; \
		_FORCE_INLINE_ static void encode(const m_type *p_var, void *p_ptr) { \
			*reinterpret_cast<const m_type **>(p_ptr) = p_var; \
		} \
	}

GDVIRTUAL_NATIVE_PTR(void);
GDVIRTUAL_NATIVE_PTR(bool);
GDVIRTUAL_NATIVE_PTR(char);
GDVIRTUAL_NATIVE_PTR(char16_t);
GDVIRTUAL_NATIVE_PTR(char32_t);
GDVIRTUAL_NATIVE_PTR(wchar_t);
GDVIRTUAL_NATIVE_PTR(uint8_t);
GDVIRTUAL_NATIVE_PTR(uint8_t *);
GDVIRTUAL_NATIVE_PTR(int8_t);
GDVIRTUAL_NATIVE_PTR(uint16_t);
GDVIRTUAL_NATIVE_PTR(int16_t);
GDVIRTUAL_NATIVE_PTR(uint32_t);
GDVIRTUAL_NATIVE_PTR(int32_t);
GDVIRTUAL_NATIVE_PTR(int64_t);
GDVIRTUAL_NATIVE_PTR(uint64_t);
GDVIRTUAL_NATIVE_PTR(float);
GDVIRTUAL_NATIVE_PTR(double);

} // namespace godot
