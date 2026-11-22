/**************************************************************************/
/*  type_info.hpp                                                         */
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

#include <godot_cpp/core/method_ptrcall.hpp>
#include <godot_cpp/core/object.hpp>
#include <godot_cpp/variant/typed_array.hpp>
#include <godot_cpp/variant/variant.hpp>

#include <gdextension_interface.h>

namespace godot {

/**
 * Exposes a nested type when the compile-time condition is true.
 */
template <bool C, typename T = void>
struct EnableIf {
	/**
	 * Type available to substitution when the condition is true.
	 */
	typedef T type;
};

/**
 * Removes the nested type for a false condition, allowing substitution to discard a candidate.
 */
template <typename T>
struct EnableIf<false, T> {
};

/**
 * Reports that two different C++ types do not match.
 */
template <typename, typename>
struct TypesAreSame {
	/**
	 * Indicates that the template arguments are different types.
	 */
	static bool const value = false;
};

/**
 * Matches two occurrences of the same C++ type.
 */
template <typename A>
struct TypesAreSame<A, A> {
	/**
	 * Indicates that the template arguments name the same type.
	 */
	static bool const value = true;
};

/**
 * Tests whether two non-type arguments identify the same function.
 */
template <auto A, auto B>
struct FunctionsAreSame {
	/**
	 * Indicates that the function template arguments differ.
	 */
	static bool const value = false;
};

/**
 * Matches two uses of the same function as template arguments.
 */
template <auto A>
struct FunctionsAreSame<A, A> {
	/**
	 * Indicates that both template arguments identify the same function.
	 */
	static bool const value = true;
};

/**
 * Checks whether a derived pointer can match the base pointer overload, excluding a void base type.
 */
template <typename B, typename D>
struct TypeInherits {
	/**
	 * Supplies a derived pointer type for the unevaluated overload test.
	 */
	static D *get_d();

	/**
	 * Selects a one-byte result when the argument converts to the base pointer.
	 */
	static char (&test(B *))[1];
	/**
	 * Selects a two-byte result when the base pointer overload does not match.
	 */
	static char (&test(...))[2];

	/**
	 * Reports whether the base pointer overload was selected and the base type is non-void.
	 */
	static bool const value = sizeof(test(get_d())) == sizeof(char) &&
			!TypesAreSame<B volatile const, void volatile const>::value;
};

/**
 * Builds registration metadata for a property. A resource-type hint also supplies the property class name.
 */
static PropertyInfo make_property_info(Variant::Type p_type, const StringName &p_name, uint32_t p_hint = PROPERTY_HINT_NONE, const String &p_hint_string = "", uint32_t p_usage = PROPERTY_USAGE_DEFAULT, const StringName &p_class_name = "") {
	PropertyInfo info;
	info.type = p_type;
	info.name = p_name;
	info.hint = p_hint;
	info.hint_string = p_hint_string;
	info.usage = p_usage;
	if (p_hint == PROPERTY_HINT_RESOURCE_TYPE) {
		info.class_name = p_hint_string;
	} else {
		info.class_name = p_class_name;
	}
	return info;
}

// If the compiler fails because it's trying to instantiate the primary 'GetTypeInfo' template
// instead of one of the specializations, it's most likely because the type 'T' is not supported.
// If 'T' is a class that inherits 'Object', make sure it can see the actual class declaration
// instead of a forward declaration. You can always forward declare 'T' in a header file, and then
// include the actual declaration of 'T' in the source file where 'GetTypeInfo<T>' is instantiated.

/**
 * Declares the specialization point that maps supported C++ types to variant and method registration metadata.
 */
template <typename T, typename = void>
struct GetTypeInfo;

/**
 * Defines variant and property metadata for a C++ type and its const reference, with no additional argument metadata.
 */
#define MAKE_TYPE_INFO(m_type, m_var_type) \
	template <> \
	struct GetTypeInfo<m_type> { \
		static constexpr GDExtensionVariantType VARIANT_TYPE = m_var_type; \
		static constexpr GDExtensionClassMethodArgumentMetadata METADATA = GDEXTENSION_METHOD_ARGUMENT_METADATA_NONE; \
		static inline PropertyInfo get_class_info() { \
			return make_property_info((Variant::Type)VARIANT_TYPE, ""); \
		} \
	}; \
	template <> \
	struct GetTypeInfo<const m_type &> { \
		static constexpr GDExtensionVariantType VARIANT_TYPE = m_var_type; \
		static constexpr GDExtensionClassMethodArgumentMetadata METADATA = GDEXTENSION_METHOD_ARGUMENT_METADATA_NONE; \
		static inline PropertyInfo get_class_info() { \
			return make_property_info((Variant::Type)VARIANT_TYPE, ""); \
		} \
	};

/**
 * Defines variant and property metadata for a C++ type and its const reference, with an explicit ABI argument metadata value.
 */
#define MAKE_TYPE_INFO_WITH_META(m_type, m_var_type, m_metadata) \
	template <> \
	struct GetTypeInfo<m_type> { \
		static constexpr GDExtensionVariantType VARIANT_TYPE = m_var_type; \
		static constexpr GDExtensionClassMethodArgumentMetadata METADATA = m_metadata; \
		static inline PropertyInfo get_class_info() { \
			return make_property_info((Variant::Type)VARIANT_TYPE, ""); \
		} \
	}; \
	template <> \
	struct GetTypeInfo<const m_type &> { \
		static constexpr GDExtensionVariantType VARIANT_TYPE = m_var_type; \
		static constexpr GDExtensionClassMethodArgumentMetadata METADATA = m_metadata; \
		static inline PropertyInfo get_class_info() { \
			return make_property_info((Variant::Type)VARIANT_TYPE, ""); \
		} \
	};

MAKE_TYPE_INFO(bool, GDEXTENSION_VARIANT_TYPE_BOOL)
MAKE_TYPE_INFO_WITH_META(uint8_t, GDEXTENSION_VARIANT_TYPE_INT, GDEXTENSION_METHOD_ARGUMENT_METADATA_INT_IS_UINT8)
MAKE_TYPE_INFO_WITH_META(int8_t, GDEXTENSION_VARIANT_TYPE_INT, GDEXTENSION_METHOD_ARGUMENT_METADATA_INT_IS_INT8)
MAKE_TYPE_INFO_WITH_META(uint16_t, GDEXTENSION_VARIANT_TYPE_INT, GDEXTENSION_METHOD_ARGUMENT_METADATA_INT_IS_UINT16)
MAKE_TYPE_INFO_WITH_META(int16_t, GDEXTENSION_VARIANT_TYPE_INT, GDEXTENSION_METHOD_ARGUMENT_METADATA_INT_IS_INT16)
MAKE_TYPE_INFO_WITH_META(uint32_t, GDEXTENSION_VARIANT_TYPE_INT, GDEXTENSION_METHOD_ARGUMENT_METADATA_INT_IS_UINT32)
MAKE_TYPE_INFO_WITH_META(int32_t, GDEXTENSION_VARIANT_TYPE_INT, GDEXTENSION_METHOD_ARGUMENT_METADATA_INT_IS_INT32)
MAKE_TYPE_INFO_WITH_META(uint64_t, GDEXTENSION_VARIANT_TYPE_INT, GDEXTENSION_METHOD_ARGUMENT_METADATA_INT_IS_UINT64)
MAKE_TYPE_INFO_WITH_META(int64_t, GDEXTENSION_VARIANT_TYPE_INT, GDEXTENSION_METHOD_ARGUMENT_METADATA_INT_IS_INT64)
MAKE_TYPE_INFO_WITH_META(char16_t, GDEXTENSION_VARIANT_TYPE_INT, GDEXTENSION_METHOD_ARGUMENT_METADATA_INT_IS_CHAR16)
MAKE_TYPE_INFO_WITH_META(char32_t, GDEXTENSION_VARIANT_TYPE_INT, GDEXTENSION_METHOD_ARGUMENT_METADATA_INT_IS_CHAR32)
MAKE_TYPE_INFO_WITH_META(float, GDEXTENSION_VARIANT_TYPE_FLOAT, GDEXTENSION_METHOD_ARGUMENT_METADATA_REAL_IS_FLOAT)
MAKE_TYPE_INFO_WITH_META(double, GDEXTENSION_VARIANT_TYPE_FLOAT, GDEXTENSION_METHOD_ARGUMENT_METADATA_REAL_IS_DOUBLE)

MAKE_TYPE_INFO(String, GDEXTENSION_VARIANT_TYPE_STRING)
MAKE_TYPE_INFO(Vector2, GDEXTENSION_VARIANT_TYPE_VECTOR2)
MAKE_TYPE_INFO(Vector2i, GDEXTENSION_VARIANT_TYPE_VECTOR2I)
MAKE_TYPE_INFO(Rect2, GDEXTENSION_VARIANT_TYPE_RECT2)
MAKE_TYPE_INFO(Rect2i, GDEXTENSION_VARIANT_TYPE_RECT2I)
MAKE_TYPE_INFO(Vector3, GDEXTENSION_VARIANT_TYPE_VECTOR3)
MAKE_TYPE_INFO(Vector3i, GDEXTENSION_VARIANT_TYPE_VECTOR3I)
MAKE_TYPE_INFO(Transform2D, GDEXTENSION_VARIANT_TYPE_TRANSFORM2D)
MAKE_TYPE_INFO(Vector4, GDEXTENSION_VARIANT_TYPE_VECTOR4)
MAKE_TYPE_INFO(Vector4i, GDEXTENSION_VARIANT_TYPE_VECTOR4I)
MAKE_TYPE_INFO(Plane, GDEXTENSION_VARIANT_TYPE_PLANE)
MAKE_TYPE_INFO(Quaternion, GDEXTENSION_VARIANT_TYPE_QUATERNION)
MAKE_TYPE_INFO(AABB, GDEXTENSION_VARIANT_TYPE_AABB)
MAKE_TYPE_INFO(Basis, GDEXTENSION_VARIANT_TYPE_BASIS)
MAKE_TYPE_INFO(Transform3D, GDEXTENSION_VARIANT_TYPE_TRANSFORM3D)
MAKE_TYPE_INFO(Projection, GDEXTENSION_VARIANT_TYPE_PROJECTION)
MAKE_TYPE_INFO(Color, GDEXTENSION_VARIANT_TYPE_COLOR)
MAKE_TYPE_INFO(StringName, GDEXTENSION_VARIANT_TYPE_STRING_NAME)
MAKE_TYPE_INFO(NodePath, GDEXTENSION_VARIANT_TYPE_NODE_PATH)
MAKE_TYPE_INFO(RID, GDEXTENSION_VARIANT_TYPE_RID)
MAKE_TYPE_INFO(Callable, GDEXTENSION_VARIANT_TYPE_CALLABLE)
MAKE_TYPE_INFO(Signal, GDEXTENSION_VARIANT_TYPE_SIGNAL)
MAKE_TYPE_INFO(Dictionary, GDEXTENSION_VARIANT_TYPE_DICTIONARY)
MAKE_TYPE_INFO(Array, GDEXTENSION_VARIANT_TYPE_ARRAY)
MAKE_TYPE_INFO(PackedByteArray, GDEXTENSION_VARIANT_TYPE_PACKED_BYTE_ARRAY)
MAKE_TYPE_INFO(PackedInt32Array, GDEXTENSION_VARIANT_TYPE_PACKED_INT32_ARRAY)
MAKE_TYPE_INFO(PackedInt64Array, GDEXTENSION_VARIANT_TYPE_PACKED_INT64_ARRAY)
MAKE_TYPE_INFO(PackedFloat32Array, GDEXTENSION_VARIANT_TYPE_PACKED_FLOAT32_ARRAY)
MAKE_TYPE_INFO(PackedFloat64Array, GDEXTENSION_VARIANT_TYPE_PACKED_FLOAT64_ARRAY)
MAKE_TYPE_INFO(PackedStringArray, GDEXTENSION_VARIANT_TYPE_PACKED_STRING_ARRAY)
MAKE_TYPE_INFO(PackedVector2Array, GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY)
MAKE_TYPE_INFO(PackedVector3Array, GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR3_ARRAY)
MAKE_TYPE_INFO(PackedVector4Array, GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR4_ARRAY)
MAKE_TYPE_INFO(PackedColorArray, GDEXTENSION_VARIANT_TYPE_PACKED_COLOR_ARRAY)

// For variant.
/**
 * Provides binding metadata for parameters and results that accept a variant of any type.
 */
template <>
struct GetTypeInfo<Variant> {
	/**
	 * Uses the nil marker for a generic variant in registration metadata.
	 */
	static constexpr GDExtensionVariantType VARIANT_TYPE = GDEXTENSION_VARIANT_TYPE_NIL;
	/**
	 * Indicates that the generic variant has no extra argument metadata.
	 */
	static constexpr GDExtensionClassMethodArgumentMetadata METADATA = GDEXTENSION_METHOD_ARGUMENT_METADATA_NONE;
	/**
	 * Marks a nil-typed property descriptor as accepting a variant of any type.
	 */
	static inline PropertyInfo get_class_info() {
		return make_property_info(Variant::Type::NIL, "", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_DEFAULT | PROPERTY_USAGE_NIL_IS_VARIANT);
	}
};

/**
 * Provides binding metadata for a generic variant passed by const reference.
 */
template <>
struct GetTypeInfo<const Variant &> {
	/**
	 * Uses the nil marker for a generic variant const reference in registration metadata.
	 */
	static constexpr GDExtensionVariantType VARIANT_TYPE = GDEXTENSION_VARIANT_TYPE_NIL;
	/**
	 * Indicates that the const variant reference has no extra argument metadata.
	 */
	static constexpr GDExtensionClassMethodArgumentMetadata METADATA = GDEXTENSION_METHOD_ARGUMENT_METADATA_NONE;
	/**
	 * Marks the const-reference descriptor as accepting a variant of any type.
	 */
	static inline PropertyInfo get_class_info() {
		return make_property_info(Variant::Type::NIL, "", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_DEFAULT | PROPERTY_USAGE_NIL_IS_VARIANT);
	}
};

/**
 * Provides object registration metadata for a pointer to a Godot class.
 */
template <typename T>
struct GetTypeInfo<T *, typename EnableIf<TypeInherits<Object, T>::value>::type> {
	/**
	 * Registers the pointer as an object variant.
	 */
	static constexpr GDExtensionVariantType VARIANT_TYPE = GDEXTENSION_VARIANT_TYPE_OBJECT;
	/**
	 * Indicates that the pointer has no additional ABI argument metadata.
	 */
	static constexpr GDExtensionClassMethodArgumentMetadata METADATA = GDEXTENSION_METHOD_ARGUMENT_METADATA_NONE;
	/**
	 * Builds property metadata with a resource-type hint identifying the object class.
	 */
	static inline PropertyInfo get_class_info() {
		return make_property_info(Variant::Type::OBJECT, "", PROPERTY_HINT_RESOURCE_TYPE, T::get_class_static());
	}
};

/**
 * Provides object registration metadata for a pointer to a const Godot class.
 */
template <typename T>
struct GetTypeInfo<const T *, typename EnableIf<TypeInherits<Object, T>::value>::type> {
	/**
	 * Registers the pointer to const as an object variant.
	 */
	static constexpr GDExtensionVariantType VARIANT_TYPE = GDEXTENSION_VARIANT_TYPE_OBJECT;
	/**
	 * Indicates that the const pointer has no additional ABI argument metadata.
	 */
	static constexpr GDExtensionClassMethodArgumentMetadata METADATA = GDEXTENSION_METHOD_ARGUMENT_METADATA_NONE;
	/**
	 * Builds property metadata with a resource-type hint identifying the object class.
	 */
	static inline PropertyInfo get_class_info() {
		return make_property_info(Variant::Type::OBJECT, "", PROPERTY_HINT_RESOURCE_TYPE, T::get_class_static());
	}
};

/**
 * Converts the C++ enum name to Godot's dotted name. With more than two components, keeps only the final two.
 */
inline String enum_qualified_name_to_class_info_name(const String &p_qualified_name) {
	PackedStringArray parts = p_qualified_name.split("::", false);
	if (parts.size() <= 2) {
		return String(".").join(parts);
	}
	// Contains namespace. We only want the class and enum names.
	return parts[parts.size() - 2] + "." + parts[parts.size() - 1];
}

/**
 * Defines integer variant metadata for one enum spelling and marks its property descriptor as a class enum.
 */
#define TEMPL_MAKE_ENUM_TYPE_INFO(m_enum, m_impl) \
	template <> \
	struct GetTypeInfo<m_impl> { \
		static constexpr Variant::Type VARIANT_TYPE = Variant::INT; \
		static constexpr GDExtensionClassMethodArgumentMetadata METADATA = GDEXTENSION_METHOD_ARGUMENT_METADATA_NONE; \
		static inline PropertyInfo get_class_info() { \
			return make_property_info(Variant::Type::INT, "", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_DEFAULT | PROPERTY_USAGE_CLASS_IS_ENUM, \
					enum_qualified_name_to_class_info_name(#m_enum)); \
		} \
	};

/**
 * Registers the enum type and its const and reference forms.
 */
#define MAKE_ENUM_TYPE_INFO(m_enum) \
	TEMPL_MAKE_ENUM_TYPE_INFO(m_enum, m_enum) \
	TEMPL_MAKE_ENUM_TYPE_INFO(m_enum, m_enum const) \
	TEMPL_MAKE_ENUM_TYPE_INFO(m_enum, m_enum &) \
	TEMPL_MAKE_ENUM_TYPE_INFO(m_enum, const m_enum &)

/**
 * Gets the registered enum name for an integer constant's type. Reports missing enum metadata when the variant type resolves to nil.
 */
template <typename T>
inline StringName _gde_constant_get_enum_name(T param, StringName p_constant) {
	if (GetTypeInfo<T>::VARIANT_TYPE == Variant::NIL) {
		ERR_PRINT(("Missing VARIANT_ENUM_CAST for constant's enum: " + String(p_constant)).utf8().get_data());
	}
	return GetTypeInfo<T>::get_class_info().class_name;
}

/**
 * Holds the flags for an enum in a 64-bit integer mask.
 */
template <typename T>
class BitField {
	/**
	 * Stores the bits representing the currently selected flags.
	 */
	int64_t value = 0;

public:
	/**
	 * Sets every bit included in the supplied flag mask.
	 */
	_FORCE_INLINE_ void set_flag(T p_flag) { value |= p_flag; }
	/**
	 * Returns whether any bit in the supplied mask is set.
	 */
	_FORCE_INLINE_ bool has_flag(T p_flag) const { return value & p_flag; }
	/**
	 * Clears every bit included in the supplied flag mask.
	 */
	_FORCE_INLINE_ void clear_flag(T p_flag) { value &= ~p_flag; }
	/**
	 * Initializes the flags from a raw integer mask.
	 */
	_FORCE_INLINE_ BitField(int64_t p_value) { value = p_value; }
	/**
	 * Returns the stored flags as a signed 64-bit integer.
	 */
	_FORCE_INLINE_ operator int64_t() const { return value; }
	/**
	 * Converts the flags to an integer variant.
	 */
	_FORCE_INLINE_ operator Variant() const { return value; }
};

/**
 * Defines integer variant metadata for a flag enum and its `godot::BitField` wrapper and marks the property as a class bitfield.
 */
#define TEMPL_MAKE_BITFIELD_TYPE_INFO(m_enum, m_impl) \
	template <> \
	struct GetTypeInfo<m_impl> { \
		static constexpr Variant::Type VARIANT_TYPE = Variant::INT; \
		static constexpr GDExtensionClassMethodArgumentMetadata METADATA = GDEXTENSION_METHOD_ARGUMENT_METADATA_NONE; \
		static inline PropertyInfo get_class_info() { \
			return make_property_info(Variant::Type::INT, "", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_DEFAULT | PROPERTY_USAGE_CLASS_IS_BITFIELD, \
					enum_qualified_name_to_class_info_name(#m_enum)); \
		} \
	}; \
	template <> \
	struct GetTypeInfo<BitField<m_impl>> { \
		static constexpr Variant::Type VARIANT_TYPE = Variant::INT; \
		static constexpr GDExtensionClassMethodArgumentMetadata METADATA = GDEXTENSION_METHOD_ARGUMENT_METADATA_NONE; \
		static inline PropertyInfo get_class_info() { \
			return make_property_info(Variant::Type::INT, "", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_DEFAULT | PROPERTY_USAGE_CLASS_IS_BITFIELD, \
					enum_qualified_name_to_class_info_name(#m_enum)); \
		} \
	};

/**
 * Registers bitfield metadata for the enum's value, const, and reference forms.
 */
#define MAKE_BITFIELD_TYPE_INFO(m_enum) \
	TEMPL_MAKE_BITFIELD_TYPE_INFO(m_enum, m_enum) \
	TEMPL_MAKE_BITFIELD_TYPE_INFO(m_enum, m_enum const) \
	TEMPL_MAKE_BITFIELD_TYPE_INFO(m_enum, m_enum &) \
	TEMPL_MAKE_BITFIELD_TYPE_INFO(m_enum, const m_enum &)

/**
 * Gets the registered bitfield name for a constant's enum type. Reports missing metadata when the variant type resolves to nil.
 */
template <typename T>
inline StringName _gde_constant_get_bitfield_name(T param, StringName p_constant) {
	if (GetTypeInfo<T>::VARIANT_TYPE == Variant::NIL) {
		ERR_PRINT(("Missing VARIANT_ENUM_CAST for constant's bitfield: " + String(p_constant)).utf8().get_data());
	}
	return GetTypeInfo<BitField<T>>::get_class_info().class_name;
}

/**
 * Adapts typed arrays passed by value to the engine's array pointer-call storage.
 */
template <typename T>
struct PtrToArg<TypedArray<T>> {
	/**
	 * Wraps an incoming array using the requested element type.
	 */
	_FORCE_INLINE_ static TypedArray<T> convert(const void *p_ptr) {
		return TypedArray<T>(*reinterpret_cast<const Array *>(p_ptr));
	}
	/**
	 * Declares the base array type used as the engine return slot.
	 */
	typedef Array EncodeT;
	/**
	 * Assigns a typed array to the engine array return slot.
	 */
	_FORCE_INLINE_ static void encode(TypedArray<T> p_val, void *p_ptr) {
		*reinterpret_cast<Array *>(p_ptr) = p_val;
	}
};

/**
 * Adapts a const typed-array reference to the engine's array pointer-call storage.
 */
template <typename T>
struct PtrToArg<const TypedArray<T> &> {
	/**
	 * Declares the base array used for pointer-call storage.
	 */
	typedef Array EncodeT;
	/**
	 * Wraps the incoming array with the requested element type for a const reference parameter.
	 */
	_FORCE_INLINE_ static TypedArray<T>
	convert(const void *p_ptr) {
		return TypedArray<T>(*reinterpret_cast<const Array *>(p_ptr));
	}
};

/**
 * Registers an object-typed array for a parameter or result passed by value.
 */
template <typename T>
struct GetTypeInfo<TypedArray<T>> {
	/**
	 * Registers the typed array as an array variant.
	 */
	static constexpr GDExtensionVariantType VARIANT_TYPE = GDEXTENSION_VARIANT_TYPE_ARRAY;
	/**
	 * Indicates that the array has no additional ABI argument metadata.
	 */
	static constexpr GDExtensionClassMethodArgumentMetadata METADATA = GDEXTENSION_METHOD_ARGUMENT_METADATA_NONE;
	/**
	 * Builds the array property hint from the element class's registered name.
	 */
	static inline PropertyInfo get_class_info() {
		return make_property_info(Variant::Type::ARRAY, "", PROPERTY_HINT_ARRAY_TYPE, T::get_class_static());
	}
};

/**
 * Registers an object-typed array passed by const reference.
 */
template <typename T>
struct GetTypeInfo<const TypedArray<T> &> {
	/**
	 * Registers the const array reference as an array variant.
	 */
	static constexpr GDExtensionVariantType VARIANT_TYPE = GDEXTENSION_VARIANT_TYPE_ARRAY;
	/**
	 * Indicates that the const reference has no additional ABI argument metadata.
	 */
	static constexpr GDExtensionClassMethodArgumentMetadata METADATA = GDEXTENSION_METHOD_ARGUMENT_METADATA_NONE;
	/**
	 * Builds the array property hint from the element class's registered name.
	 */
	static inline PropertyInfo get_class_info() {
		return make_property_info(Variant::Type::ARRAY, "", PROPERTY_HINT_ARRAY_TYPE, T::get_class_static());
	}
};

/**
 * Defines method registration metadata for typed arrays with a built-in element type, including const references.
 */
#define MAKE_TYPED_ARRAY_INFO(m_type, m_variant_type) \
	template <> \
	struct GetTypeInfo<TypedArray<m_type>> { \
		static constexpr GDExtensionVariantType VARIANT_TYPE = GDEXTENSION_VARIANT_TYPE_ARRAY; \
		static constexpr GDExtensionClassMethodArgumentMetadata METADATA = GDEXTENSION_METHOD_ARGUMENT_METADATA_NONE; \
		static inline PropertyInfo get_class_info() { \
			return make_property_info(Variant::Type::ARRAY, "", PROPERTY_HINT_ARRAY_TYPE, Variant::get_type_name(m_variant_type).utf8().get_data()); \
		} \
	}; \
	template <> \
	struct GetTypeInfo<const TypedArray<m_type> &> { \
		static constexpr GDExtensionVariantType VARIANT_TYPE = GDEXTENSION_VARIANT_TYPE_ARRAY; \
		static constexpr GDExtensionClassMethodArgumentMetadata METADATA = GDEXTENSION_METHOD_ARGUMENT_METADATA_NONE; \
		static inline PropertyInfo get_class_info() { \
			return make_property_info(Variant::Type::ARRAY, "", PROPERTY_HINT_ARRAY_TYPE, Variant::get_type_name(m_variant_type).utf8().get_data()); \
		} \
	};

MAKE_TYPED_ARRAY_INFO(bool, Variant::BOOL)
MAKE_TYPED_ARRAY_INFO(uint8_t, Variant::INT)
MAKE_TYPED_ARRAY_INFO(int8_t, Variant::INT)
MAKE_TYPED_ARRAY_INFO(uint16_t, Variant::INT)
MAKE_TYPED_ARRAY_INFO(int16_t, Variant::INT)
MAKE_TYPED_ARRAY_INFO(uint32_t, Variant::INT)
MAKE_TYPED_ARRAY_INFO(int32_t, Variant::INT)
MAKE_TYPED_ARRAY_INFO(uint64_t, Variant::INT)
MAKE_TYPED_ARRAY_INFO(int64_t, Variant::INT)
MAKE_TYPED_ARRAY_INFO(float, Variant::FLOAT)
MAKE_TYPED_ARRAY_INFO(double, Variant::FLOAT)
MAKE_TYPED_ARRAY_INFO(String, Variant::STRING)
MAKE_TYPED_ARRAY_INFO(Vector2, Variant::VECTOR2)
MAKE_TYPED_ARRAY_INFO(Vector2i, Variant::VECTOR2I)
MAKE_TYPED_ARRAY_INFO(Rect2, Variant::RECT2)
MAKE_TYPED_ARRAY_INFO(Rect2i, Variant::RECT2I)
MAKE_TYPED_ARRAY_INFO(Vector3, Variant::VECTOR3)
MAKE_TYPED_ARRAY_INFO(Vector3i, Variant::VECTOR3I)
MAKE_TYPED_ARRAY_INFO(Transform2D, Variant::TRANSFORM2D)
MAKE_TYPED_ARRAY_INFO(Vector4, Variant::VECTOR4)
MAKE_TYPED_ARRAY_INFO(Vector4i, Variant::VECTOR4I)
MAKE_TYPED_ARRAY_INFO(Plane, Variant::PLANE)
MAKE_TYPED_ARRAY_INFO(Quaternion, Variant::QUATERNION)
MAKE_TYPED_ARRAY_INFO(AABB, Variant::AABB)
MAKE_TYPED_ARRAY_INFO(Basis, Variant::BASIS)
MAKE_TYPED_ARRAY_INFO(Transform3D, Variant::TRANSFORM3D)
MAKE_TYPED_ARRAY_INFO(Projection, Variant::PROJECTION)
MAKE_TYPED_ARRAY_INFO(Color, Variant::COLOR)
MAKE_TYPED_ARRAY_INFO(StringName, Variant::STRING_NAME)
MAKE_TYPED_ARRAY_INFO(NodePath, Variant::NODE_PATH)
MAKE_TYPED_ARRAY_INFO(RID, Variant::RID)
MAKE_TYPED_ARRAY_INFO(Callable, Variant::CALLABLE)
MAKE_TYPED_ARRAY_INFO(Signal, Variant::SIGNAL)
MAKE_TYPED_ARRAY_INFO(Dictionary, Variant::DICTIONARY)
MAKE_TYPED_ARRAY_INFO(Array, Variant::ARRAY)
MAKE_TYPED_ARRAY_INFO(PackedByteArray, Variant::PACKED_BYTE_ARRAY)
MAKE_TYPED_ARRAY_INFO(PackedInt32Array, Variant::PACKED_INT32_ARRAY)
MAKE_TYPED_ARRAY_INFO(PackedInt64Array, Variant::PACKED_INT64_ARRAY)
MAKE_TYPED_ARRAY_INFO(PackedFloat32Array, Variant::PACKED_FLOAT32_ARRAY)
MAKE_TYPED_ARRAY_INFO(PackedFloat64Array, Variant::PACKED_FLOAT64_ARRAY)
MAKE_TYPED_ARRAY_INFO(PackedStringArray, Variant::PACKED_STRING_ARRAY)
MAKE_TYPED_ARRAY_INFO(PackedVector2Array, Variant::PACKED_VECTOR2_ARRAY)
MAKE_TYPED_ARRAY_INFO(PackedVector3Array, Variant::PACKED_VECTOR3_ARRAY)
MAKE_TYPED_ARRAY_INFO(PackedVector4Array, Variant::PACKED_VECTOR4_ARRAY)
MAKE_TYPED_ARRAY_INFO(PackedColorArray, Variant::PACKED_COLOR_ARRAY)
/*
MAKE_TYPED_ARRAY_INFO(IPAddress, Variant::STRING)
*/

#undef MAKE_TYPED_ARRAY_INFO

/**
 * Builds the object property descriptor for a registered C++ class.
 */
#define CLASS_INFO(m_type) (GetTypeInfo<m_type *>::get_class_info())

} // namespace godot
