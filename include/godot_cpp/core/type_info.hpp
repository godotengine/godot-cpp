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

#ifndef GODOT_TYPE_INFO_HPP
#define GODOT_TYPE_INFO_HPP

#include <godot_cpp/core/object.hpp>
#include <godot_cpp/variant/typed_array.hpp>
#include <godot_cpp/variant/typed_dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>

#include <gdextension_interface.h>

namespace godot {

template <bool C, typename T = void>
struct EnableIf {
	typedef T type;
};

template <typename T>
struct EnableIf<false, T> {
};

template <typename, typename>
struct TypesAreSame {
	static bool const value = false;
};

template <typename A>
struct TypesAreSame<A, A> {
	static bool const value = true;
};

template <typename B, typename D>
struct TypeInherits {
	static D *get_d();

	static char (&test(B *))[1];
	static char (&test(...))[2];

	static bool const value = sizeof(test(get_d())) == sizeof(char) &&
			!TypesAreSame<B volatile const, void volatile const>::value;
};

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

template <class T, typename = void>
struct GetTypeInfo;

#define MAKE_TYPE_INFO(m_type, m_var_type)                                                                            \
	template <>                                                                                                       \
	struct GetTypeInfo<m_type> {                                                                                      \
		static constexpr GDExtensionVariantType VARIANT_TYPE = m_var_type;                                            \
		static constexpr GDExtensionClassMethodArgumentMetadata METADATA = GDEXTENSION_METHOD_ARGUMENT_METADATA_NONE; \
		static inline PropertyInfo get_class_info() {                                                                 \
			return make_property_info((Variant::Type)VARIANT_TYPE, "");                                               \
		}                                                                                                             \
	};                                                                                                                \
	template <>                                                                                                       \
	struct GetTypeInfo<const m_type &> {                                                                              \
		static constexpr GDExtensionVariantType VARIANT_TYPE = m_var_type;                                            \
		static constexpr GDExtensionClassMethodArgumentMetadata METADATA = GDEXTENSION_METHOD_ARGUMENT_METADATA_NONE; \
		static inline PropertyInfo get_class_info() {                                                                 \
			return make_property_info((Variant::Type)VARIANT_TYPE, "");                                               \
		}                                                                                                             \
	};

#define MAKE_TYPE_INFO_WITH_META(m_type, m_var_type, m_metadata)                       \
	template <>                                                                        \
	struct GetTypeInfo<m_type> {                                                       \
		static constexpr GDExtensionVariantType VARIANT_TYPE = m_var_type;             \
		static constexpr GDExtensionClassMethodArgumentMetadata METADATA = m_metadata; \
		static inline PropertyInfo get_class_info() {                                  \
			return make_property_info((Variant::Type)VARIANT_TYPE, "");                \
		}                                                                              \
	};                                                                                 \
	template <>                                                                        \
	struct GetTypeInfo<const m_type &> {                                               \
		static constexpr GDExtensionVariantType VARIANT_TYPE = m_var_type;             \
		static constexpr GDExtensionClassMethodArgumentMetadata METADATA = m_metadata; \
		static inline PropertyInfo get_class_info() {                                  \
			return make_property_info((Variant::Type)VARIANT_TYPE, "");                \
		}                                                                              \
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
MAKE_TYPE_INFO(char16_t, GDEXTENSION_VARIANT_TYPE_INT)
MAKE_TYPE_INFO(char32_t, GDEXTENSION_VARIANT_TYPE_INT)
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
MAKE_TYPE_INFO(PackedColorArray, GDEXTENSION_VARIANT_TYPE_PACKED_COLOR_ARRAY)

// For variant.
template <>
struct GetTypeInfo<Variant> {
	static constexpr GDExtensionVariantType VARIANT_TYPE = GDEXTENSION_VARIANT_TYPE_NIL;
	static constexpr GDExtensionClassMethodArgumentMetadata METADATA = GDEXTENSION_METHOD_ARGUMENT_METADATA_NONE;
	static inline PropertyInfo get_class_info() {
		return make_property_info(Variant::Type::NIL, "", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_DEFAULT | PROPERTY_USAGE_NIL_IS_VARIANT);
	}
};

template <>
struct GetTypeInfo<const Variant &> {
	static constexpr GDExtensionVariantType VARIANT_TYPE = GDEXTENSION_VARIANT_TYPE_NIL;
	static constexpr GDExtensionClassMethodArgumentMetadata METADATA = GDEXTENSION_METHOD_ARGUMENT_METADATA_NONE;
	static inline PropertyInfo get_class_info() {
		return make_property_info(Variant::Type::NIL, "", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_DEFAULT | PROPERTY_USAGE_NIL_IS_VARIANT);
	}
};

template <typename T>
struct GetTypeInfo<T *, typename EnableIf<TypeInherits<Object, T>::value>::type> {
	static const GDExtensionVariantType VARIANT_TYPE = GDEXTENSION_VARIANT_TYPE_OBJECT;
	static const GDExtensionClassMethodArgumentMetadata METADATA = GDEXTENSION_METHOD_ARGUMENT_METADATA_NONE;
	static inline PropertyInfo get_class_info() {
		return make_property_info(Variant::Type::OBJECT, "", PROPERTY_HINT_RESOURCE_TYPE, T::get_class_static());
	}
};

template <typename T>
struct GetTypeInfo<const T *, typename EnableIf<TypeInherits<Object, T>::value>::type> {
	static const GDExtensionVariantType VARIANT_TYPE = GDEXTENSION_VARIANT_TYPE_OBJECT;
	static const GDExtensionClassMethodArgumentMetadata METADATA = GDEXTENSION_METHOD_ARGUMENT_METADATA_NONE;
	static inline PropertyInfo get_class_info() {
		return make_property_info(Variant::Type::OBJECT, "", PROPERTY_HINT_RESOURCE_TYPE, T::get_class_static());
	}
};

inline String enum_qualified_name_to_class_info_name(const String &p_qualified_name) {
	PackedStringArray parts = p_qualified_name.split("::", false);
	if (parts.size() <= 2) {
		return String(".").join(parts);
	}
	// Contains namespace. We only want the class and enum names.
	return parts[parts.size() - 2] + "." + parts[parts.size() - 1];
}

#define TEMPL_MAKE_ENUM_TYPE_INFO(m_enum, m_impl)                                                                                            \
	template <>                                                                                                                              \
	struct GetTypeInfo<m_impl> {                                                                                                             \
		static const Variant::Type VARIANT_TYPE = Variant::INT;                                                                              \
		static const GDExtensionClassMethodArgumentMetadata METADATA = GDEXTENSION_METHOD_ARGUMENT_METADATA_NONE;                            \
		static inline PropertyInfo get_class_info() {                                                                                        \
			return make_property_info(Variant::Type::INT, "", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_DEFAULT | PROPERTY_USAGE_CLASS_IS_ENUM, \
					enum_qualified_name_to_class_info_name(#m_enum));                                                                        \
		}                                                                                                                                    \
	};

#define MAKE_ENUM_TYPE_INFO(m_enum)                 \
	TEMPL_MAKE_ENUM_TYPE_INFO(m_enum, m_enum)       \
	TEMPL_MAKE_ENUM_TYPE_INFO(m_enum, m_enum const) \
	TEMPL_MAKE_ENUM_TYPE_INFO(m_enum, m_enum &)     \
	TEMPL_MAKE_ENUM_TYPE_INFO(m_enum, const m_enum &)

template <typename T>
inline StringName _gde_constant_get_enum_name(T param, StringName p_constant) {
	if (GetTypeInfo<T>::VARIANT_TYPE == Variant::NIL) {
		ERR_PRINT(("Missing VARIANT_ENUM_CAST for constant's enum: " + String(p_constant)).utf8().get_data());
	}
	return GetTypeInfo<T>::get_class_info().class_name;
}

template <class T>
class BitField {
	int64_t value = 0;

public:
	_FORCE_INLINE_ void set_flag(T p_flag) { value |= p_flag; }
	_FORCE_INLINE_ bool has_flag(T p_flag) const { return value & p_flag; }
	_FORCE_INLINE_ void clear_flag(T p_flag) { return value &= ~p_flag; }
	_FORCE_INLINE_ BitField(int64_t p_value) { value = p_value; }
	_FORCE_INLINE_ operator int64_t() const { return value; }
	_FORCE_INLINE_ operator Variant() const { return value; }
};

#define TEMPL_MAKE_BITFIELD_TYPE_INFO(m_enum, m_impl)                                                                                            \
	template <>                                                                                                                                  \
	struct GetTypeInfo<m_impl> {                                                                                                                 \
		static const Variant::Type VARIANT_TYPE = Variant::INT;                                                                                  \
		static const GDExtensionClassMethodArgumentMetadata METADATA = GDEXTENSION_METHOD_ARGUMENT_METADATA_NONE;                                \
		static inline PropertyInfo get_class_info() {                                                                                            \
			return make_property_info(Variant::Type::INT, "", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_DEFAULT | PROPERTY_USAGE_CLASS_IS_BITFIELD, \
					enum_qualified_name_to_class_info_name(#m_enum));                                                                            \
		}                                                                                                                                        \
	};                                                                                                                                           \
	template <>                                                                                                                                  \
	struct GetTypeInfo<BitField<m_impl>> {                                                                                                       \
		static const Variant::Type VARIANT_TYPE = Variant::INT;                                                                                  \
		static const GDExtensionClassMethodArgumentMetadata METADATA = GDEXTENSION_METHOD_ARGUMENT_METADATA_NONE;                                \
		static inline PropertyInfo get_class_info() {                                                                                            \
			return make_property_info(Variant::Type::INT, "", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_DEFAULT | PROPERTY_USAGE_CLASS_IS_BITFIELD, \
					enum_qualified_name_to_class_info_name(#m_enum));                                                                            \
		}                                                                                                                                        \
	};

#define MAKE_BITFIELD_TYPE_INFO(m_enum)                 \
	TEMPL_MAKE_BITFIELD_TYPE_INFO(m_enum, m_enum)       \
	TEMPL_MAKE_BITFIELD_TYPE_INFO(m_enum, m_enum const) \
	TEMPL_MAKE_BITFIELD_TYPE_INFO(m_enum, m_enum &)     \
	TEMPL_MAKE_BITFIELD_TYPE_INFO(m_enum, const m_enum &)

template <typename T>
inline StringName _gde_constant_get_bitfield_name(T param, StringName p_constant) {
	if (GetTypeInfo<T>::VARIANT_TYPE == Variant::NIL) {
		ERR_PRINT(("Missing VARIANT_ENUM_CAST for constant's bitfield: " + String(p_constant)).utf8().get_data());
	}
	return GetTypeInfo<BitField<T>>::get_class_info().class_name;
}

template <class T>
struct PtrToArg<TypedArray<T>> {
	_FORCE_INLINE_ static TypedArray<T> convert(const void *p_ptr) {
		return TypedArray<T>(*reinterpret_cast<const Array *>(p_ptr));
	}
	typedef Array EncodeT;
	_FORCE_INLINE_ static void encode(TypedArray<T> p_val, void *p_ptr) {
		*reinterpret_cast<Array *>(p_ptr) = p_val;
	}
};

template <class T>
struct PtrToArg<const TypedArray<T> &> {
	typedef Array EncodeT;
	_FORCE_INLINE_ static TypedArray<T>
	convert(const void *p_ptr) {
		return TypedArray<T>(*reinterpret_cast<const Array *>(p_ptr));
	}
};

template <typename T>
struct GetTypeInfo<TypedArray<T>> {
	static constexpr GDExtensionVariantType VARIANT_TYPE = GDEXTENSION_VARIANT_TYPE_ARRAY;
	static constexpr GDExtensionClassMethodArgumentMetadata METADATA = GDEXTENSION_METHOD_ARGUMENT_METADATA_NONE;
	static inline PropertyInfo get_class_info() {
		return make_property_info(Variant::Type::ARRAY, "", PROPERTY_HINT_ARRAY_TYPE, T::get_class_static());
	}
};

template <typename T>
struct GetTypeInfo<const TypedArray<T> &> {
	static constexpr GDExtensionVariantType VARIANT_TYPE = GDEXTENSION_VARIANT_TYPE_ARRAY;
	static constexpr GDExtensionClassMethodArgumentMetadata METADATA = GDEXTENSION_METHOD_ARGUMENT_METADATA_NONE;
	static inline PropertyInfo get_class_info() {
		return make_property_info(Variant::Type::ARRAY, "", PROPERTY_HINT_ARRAY_TYPE, T::get_class_static());
	}
};

#define MAKE_TYPED_ARRAY_INFO(m_type, m_variant_type)                                                                                                \
	template <>                                                                                                                                      \
	struct GetTypeInfo<TypedArray<m_type>> {                                                                                                         \
		static constexpr GDExtensionVariantType VARIANT_TYPE = GDEXTENSION_VARIANT_TYPE_ARRAY;                                                       \
		static constexpr GDExtensionClassMethodArgumentMetadata METADATA = GDEXTENSION_METHOD_ARGUMENT_METADATA_NONE;                                \
		static inline PropertyInfo get_class_info() {                                                                                                \
			return make_property_info(Variant::Type::ARRAY, "", PROPERTY_HINT_ARRAY_TYPE, Variant::get_type_name(m_variant_type).utf8().get_data()); \
		}                                                                                                                                            \
	};                                                                                                                                               \
	template <>                                                                                                                                      \
	struct GetTypeInfo<const TypedArray<m_type> &> {                                                                                                 \
		static constexpr GDExtensionVariantType VARIANT_TYPE = GDEXTENSION_VARIANT_TYPE_ARRAY;                                                       \
		static constexpr GDExtensionClassMethodArgumentMetadata METADATA = GDEXTENSION_METHOD_ARGUMENT_METADATA_NONE;                                \
		static inline PropertyInfo get_class_info() {                                                                                                \
			return make_property_info(Variant::Type::ARRAY, "", PROPERTY_HINT_ARRAY_TYPE, Variant::get_type_name(m_variant_type).utf8().get_data()); \
		}                                                                                                                                            \
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
MAKE_TYPED_ARRAY_INFO(Plane, Variant::PLANE)
MAKE_TYPED_ARRAY_INFO(Quaternion, Variant::QUATERNION)
MAKE_TYPED_ARRAY_INFO(AABB, Variant::AABB)
MAKE_TYPED_ARRAY_INFO(Basis, Variant::BASIS)
MAKE_TYPED_ARRAY_INFO(Transform3D, Variant::TRANSFORM3D)
MAKE_TYPED_ARRAY_INFO(Color, Variant::COLOR)
MAKE_TYPED_ARRAY_INFO(StringName, Variant::STRING_NAME)
MAKE_TYPED_ARRAY_INFO(NodePath, Variant::NODE_PATH)
MAKE_TYPED_ARRAY_INFO(RID, Variant::RID)
MAKE_TYPED_ARRAY_INFO(Callable, Variant::CALLABLE)
MAKE_TYPED_ARRAY_INFO(Signal, Variant::SIGNAL)
MAKE_TYPED_ARRAY_INFO(Dictionary, Variant::DICTIONARY)
MAKE_TYPED_ARRAY_INFO(Array, Variant::ARRAY)
/*
MAKE_TYPED_ARRAY_INFO(Vector<uint8_t>, Variant::PACKED_BYTE_ARRAY)
MAKE_TYPED_ARRAY_INFO(Vector<int32_t>, Variant::PACKED_INT32_ARRAY)
MAKE_TYPED_ARRAY_INFO(Vector<int64_t>, Variant::PACKED_INT64_ARRAY)
MAKE_TYPED_ARRAY_INFO(Vector<float>, Variant::PACKED_FLOAT32_ARRAY)
MAKE_TYPED_ARRAY_INFO(Vector<double>, Variant::PACKED_FLOAT64_ARRAY)
MAKE_TYPED_ARRAY_INFO(Vector<String>, Variant::PACKED_STRING_ARRAY)
MAKE_TYPED_ARRAY_INFO(Vector<Vector2>, Variant::PACKED_VECTOR2_ARRAY)
MAKE_TYPED_ARRAY_INFO(Vector<Vector3>, Variant::PACKED_VECTOR3_ARRAY)
MAKE_TYPED_ARRAY_INFO(Vector<Color>, Variant::PACKED_COLOR_ARRAY)
*/

template <class TKey, class TValue>
struct PtrToArg<TypedDictionary<TKey, TValue>> {
	_FORCE_INLINE_ static TypedDictionary<TKey, TValue> convert(const void *p_ptr) {
		return TypedDictionary<TKey, TValue>(*reinterpret_cast<const Dictionary *>(p_ptr));
	}
	typedef Dictionary EncodeT;
	_FORCE_INLINE_ static void encode(TypedDictionary<TKey, TValue> p_val, void *p_ptr) {
		*reinterpret_cast<Dictionary *>(p_ptr) = p_val;
	}
};

template <class TKey, class TValue>
struct PtrToArg<const TypedDictionary<TKey, TValue> &> {
	typedef Dictionary EncodeT;
	_FORCE_INLINE_ static TypedDictionary<TKey, TValue>
	convert(const void *p_ptr) {
		return TypedDictionary<TKey, TValue>(*reinterpret_cast<const Dictionary *>(p_ptr));
	}
};

template <class TKey, class TValue>
struct GetTypeInfo<TypedDictionary<TKey, TValue>> {
	static constexpr GDExtensionVariantType VARIANT_TYPE = GDEXTENSION_VARIANT_TYPE_DICTIONARY;
	static constexpr GDExtensionClassMethodArgumentMetadata METADATA = GDEXTENSION_METHOD_ARGUMENT_METADATA_NONE;
	static inline PropertyInfo get_class_info() {
		return make_property_info(Variant::Type::DICTIONARY, "", PROPERTY_HINT_DICTIONARY_TYPE, vformat("%s,%s", TKey::get_class_static(), TValue::get_class_static()));
	}
};

template <class TKey, class TValue>
struct GetTypeInfo<const TypedDictionary<TKey, TValue> &> {
	static constexpr GDExtensionVariantType VARIANT_TYPE = GDEXTENSION_VARIANT_TYPE_DICTIONARY;
	static constexpr GDExtensionClassMethodArgumentMetadata METADATA = GDEXTENSION_METHOD_ARGUMENT_METADATA_NONE;
	static inline PropertyInfo get_class_info() {
		return make_property_info(Variant::Type::DICTIONARY, "", PROPERTY_HINT_DICTIONARY_TYPE, vformat("%s,%s", TKey::get_class_static(), TValue::get_class_static()));
	}
};

#define MAKE_TYPED_DICTIONARY_INFO(m_type, m_variant_type)                                                                                                                                                                                 \
	template <>                                                                                                                                                                                                                            \
	struct GetTypeInfo<TypedDictionary<m_type, m_type>> {                                                                                                                                                                                  \
		static constexpr GDExtensionVariantType VARIANT_TYPE = GDEXTENSION_VARIANT_TYPE_DICTIONARY;                                                                                                                                        \
		static constexpr GDExtensionClassMethodArgumentMetadata METADATA = GDEXTENSION_METHOD_ARGUMENT_METADATA_NONE;                                                                                                                      \
		static inline PropertyInfo get_class_info() {                                                                                                                                                                                      \
			return make_property_info(Variant::Type::DICTIONARY, "", PROPERTY_HINT_DICTIONARY_TYPE, vformat("%s,%s", Variant::get_type_name(m_variant_type).utf8().get_data(), Variant::get_type_name(m_variant_type).utf8().get_data())); \
		}                                                                                                                                                                                                                                  \
	};                                                                                                                                                                                                                                     \
	template <>                                                                                                                                                                                                                            \
	struct GetTypeInfo<const TypedDictionary<m_type, m_type> &> {                                                                                                                                                                          \
		static constexpr GDExtensionVariantType VARIANT_TYPE = GDEXTENSION_VARIANT_TYPE_DICTIONARY;                                                                                                                                        \
		static constexpr GDExtensionClassMethodArgumentMetadata METADATA = GDEXTENSION_METHOD_ARGUMENT_METADATA_NONE;                                                                                                                      \
		static inline PropertyInfo get_class_info() {                                                                                                                                                                                      \
			return make_property_info(Variant::Type::DICTIONARY, "", PROPERTY_HINT_DICTIONARY_TYPE, vformat("%s,%s", Variant::get_type_name(m_variant_type).utf8().get_data(), Variant::get_type_name(m_variant_type).utf8().get_data())); \
		}                                                                                                                                                                                                                                  \
	};

#define MAKE_TYPED_DICTIONARY_WITH_OBJECT_INFO(m_type, m_variant_type)                                                                                                                                  \
	template <class T>                                                                                                                                                                                  \
	struct GetTypeInfo<TypedDictionary<T, m_type>> {                                                                                                                                                    \
		static constexpr GDExtensionVariantType VARIANT_TYPE = GDEXTENSION_VARIANT_TYPE_DICTIONARY;                                                                                                     \
		static constexpr GDExtensionClassMethodArgumentMetadata METADATA = GDEXTENSION_METHOD_ARGUMENT_METADATA_NONE;                                                                                   \
		static inline PropertyInfo get_class_info() {                                                                                                                                                   \
			return make_property_info(Variant::Type::DICTIONARY, "", PROPERTY_HINT_DICTIONARY_TYPE, vformat("%s,%s", T::get_class_static(), Variant::get_type_name(m_variant_type).utf8().get_data())); \
		}                                                                                                                                                                                               \
	};                                                                                                                                                                                                  \
	template <class T>                                                                                                                                                                                  \
	struct GetTypeInfo<const TypedDictionary<T, m_type> &> {                                                                                                                                            \
		static constexpr GDExtensionVariantType VARIANT_TYPE = GDEXTENSION_VARIANT_TYPE_DICTIONARY;                                                                                                     \
		static constexpr GDExtensionClassMethodArgumentMetadata METADATA = GDEXTENSION_METHOD_ARGUMENT_METADATA_NONE;                                                                                   \
		static inline PropertyInfo get_class_info() {                                                                                                                                                   \
			return make_property_info(Variant::Type::DICTIONARY, "", PROPERTY_HINT_DICTIONARY_TYPE, vformat("%s,%s", T::get_class_static(), Variant::get_type_name(m_variant_type).utf8().get_data())); \
		}                                                                                                                                                                                               \
	};                                                                                                                                                                                                  \
	template <class T>                                                                                                                                                                                  \
	struct GetTypeInfo<TypedDictionary<m_type, T>> {                                                                                                                                                    \
		static constexpr GDExtensionVariantType VARIANT_TYPE = GDEXTENSION_VARIANT_TYPE_DICTIONARY;                                                                                                     \
		static constexpr GDExtensionClassMethodArgumentMetadata METADATA = GDEXTENSION_METHOD_ARGUMENT_METADATA_NONE;                                                                                   \
		static inline PropertyInfo get_class_info() {                                                                                                                                                   \
			return make_property_info(Variant::Type::DICTIONARY, "", PROPERTY_HINT_DICTIONARY_TYPE, vformat("%s,%s", Variant::get_type_name(m_variant_type).utf8().get_data(), T::get_class_static())); \
		}                                                                                                                                                                                               \
	};                                                                                                                                                                                                  \
	template <class T>                                                                                                                                                                                  \
	struct GetTypeInfo<const TypedDictionary<m_type, T> &> {                                                                                                                                            \
		static constexpr GDExtensionVariantType VARIANT_TYPE = GDEXTENSION_VARIANT_TYPE_DICTIONARY;                                                                                                     \
		static constexpr GDExtensionClassMethodArgumentMetadata METADATA = GDEXTENSION_METHOD_ARGUMENT_METADATA_NONE;                                                                                   \
		static inline PropertyInfo get_class_info() {                                                                                                                                                   \
			return make_property_info(Variant::Type::DICTIONARY, "", PROPERTY_HINT_DICTIONARY_TYPE, vformat("%s,%s", Variant::get_type_name(m_variant_type).utf8().get_data(), T::get_class_static())); \
		}                                                                                                                                                                                               \
	};

#define MAKE_TYPED_DICTIONARY_EXPANDED_INFO(m_type_a, m_variant_type_a, m_type_b, m_variant_type_b)                                                                                                                                            \
	template <>                                                                                                                                                                                                                                \
	struct GetTypeInfo<TypedDictionary<m_type_a, m_type_b>> {                                                                                                                                                                                  \
		static constexpr GDExtensionVariantType VARIANT_TYPE = GDEXTENSION_VARIANT_TYPE_DICTIONARY;                                                                                                                                            \
		static constexpr GDExtensionClassMethodArgumentMetadata METADATA = GDEXTENSION_METHOD_ARGUMENT_METADATA_NONE;                                                                                                                          \
		static inline PropertyInfo get_class_info() {                                                                                                                                                                                          \
			return make_property_info(Variant::Type::DICTIONARY, "", PROPERTY_HINT_DICTIONARY_TYPE, vformat("%s,%s", Variant::get_type_name(m_variant_type_a).utf8().get_data(), Variant::get_type_name(m_variant_type_b).utf8().get_data())); \
		}                                                                                                                                                                                                                                      \
	};                                                                                                                                                                                                                                         \
	template <>                                                                                                                                                                                                                                \
	struct GetTypeInfo<const TypedDictionary<m_type_a, m_type_b> &> {                                                                                                                                                                          \
		static constexpr GDExtensionVariantType VARIANT_TYPE = GDEXTENSION_VARIANT_TYPE_DICTIONARY;                                                                                                                                            \
		static constexpr GDExtensionClassMethodArgumentMetadata METADATA = GDEXTENSION_METHOD_ARGUMENT_METADATA_NONE;                                                                                                                          \
		static inline PropertyInfo get_class_info() {                                                                                                                                                                                          \
			return make_property_info(Variant::Type::DICTIONARY, "", PROPERTY_HINT_DICTIONARY_TYPE, vformat("%s,%s", Variant::get_type_name(m_variant_type_a).utf8().get_data(), Variant::get_type_name(m_variant_type_b).utf8().get_data())); \
		}                                                                                                                                                                                                                                      \
	};                                                                                                                                                                                                                                         \
	template <>                                                                                                                                                                                                                                \
	struct GetTypeInfo<TypedDictionary<m_type_b, m_type_a>> {                                                                                                                                                                                  \
		static constexpr GDExtensionVariantType VARIANT_TYPE = GDEXTENSION_VARIANT_TYPE_DICTIONARY;                                                                                                                                            \
		static constexpr GDExtensionClassMethodArgumentMetadata METADATA = GDEXTENSION_METHOD_ARGUMENT_METADATA_NONE;                                                                                                                          \
		static inline PropertyInfo get_class_info() {                                                                                                                                                                                          \
			return make_property_info(Variant::Type::DICTIONARY, "", PROPERTY_HINT_DICTIONARY_TYPE, vformat("%s,%s", Variant::get_type_name(m_variant_type_b).utf8().get_data(), Variant::get_type_name(m_variant_type_a).utf8().get_data())); \
		}                                                                                                                                                                                                                                      \
	};                                                                                                                                                                                                                                         \
	template <>                                                                                                                                                                                                                                \
	struct GetTypeInfo<const TypedDictionary<m_type_b, m_type_a> &> {                                                                                                                                                                          \
		static constexpr GDExtensionVariantType VARIANT_TYPE = GDEXTENSION_VARIANT_TYPE_DICTIONARY;                                                                                                                                            \
		static constexpr GDExtensionClassMethodArgumentMetadata METADATA = GDEXTENSION_METHOD_ARGUMENT_METADATA_NONE;                                                                                                                          \
		static inline PropertyInfo get_class_info() {                                                                                                                                                                                          \
			return make_property_info(Variant::Type::DICTIONARY, "", PROPERTY_HINT_DICTIONARY_TYPE, vformat("%s,%s", Variant::get_type_name(m_variant_type_b).utf8().get_data(), Variant::get_type_name(m_variant_type_a).utf8().get_data())); \
		}                                                                                                                                                                                                                                      \
	};

MAKE_TYPED_DICTIONARY_INFO(bool, Variant::BOOL)
MAKE_TYPED_DICTIONARY_INFO(uint8_t, Variant::INT)
MAKE_TYPED_DICTIONARY_INFO(int8_t, Variant::INT)
MAKE_TYPED_DICTIONARY_INFO(uint16_t, Variant::INT)
MAKE_TYPED_DICTIONARY_INFO(int16_t, Variant::INT)
MAKE_TYPED_DICTIONARY_INFO(uint32_t, Variant::INT)
MAKE_TYPED_DICTIONARY_INFO(int32_t, Variant::INT)
MAKE_TYPED_DICTIONARY_INFO(uint64_t, Variant::INT)
MAKE_TYPED_DICTIONARY_INFO(int64_t, Variant::INT)
MAKE_TYPED_DICTIONARY_INFO(float, Variant::FLOAT)
MAKE_TYPED_DICTIONARY_INFO(double, Variant::FLOAT)
MAKE_TYPED_DICTIONARY_INFO(String, Variant::STRING)
MAKE_TYPED_DICTIONARY_INFO(Vector2, Variant::VECTOR2)
MAKE_TYPED_DICTIONARY_INFO(Vector2i, Variant::VECTOR2I)
MAKE_TYPED_DICTIONARY_INFO(Rect2, Variant::RECT2)
MAKE_TYPED_DICTIONARY_INFO(Rect2i, Variant::RECT2I)
MAKE_TYPED_DICTIONARY_INFO(Vector3, Variant::VECTOR3)
MAKE_TYPED_DICTIONARY_INFO(Vector3i, Variant::VECTOR3I)
MAKE_TYPED_DICTIONARY_INFO(Transform2D, Variant::TRANSFORM2D)
MAKE_TYPED_DICTIONARY_INFO(Plane, Variant::PLANE)
MAKE_TYPED_DICTIONARY_INFO(Quaternion, Variant::QUATERNION)
MAKE_TYPED_DICTIONARY_INFO(AABB, Variant::AABB)
MAKE_TYPED_DICTIONARY_INFO(Basis, Variant::BASIS)
MAKE_TYPED_DICTIONARY_INFO(Transform3D, Variant::TRANSFORM3D)
MAKE_TYPED_DICTIONARY_INFO(Color, Variant::COLOR)
MAKE_TYPED_DICTIONARY_INFO(StringName, Variant::STRING_NAME)
MAKE_TYPED_DICTIONARY_INFO(NodePath, Variant::NODE_PATH)
MAKE_TYPED_DICTIONARY_INFO(RID, Variant::RID)
MAKE_TYPED_DICTIONARY_INFO(Callable, Variant::CALLABLE)
MAKE_TYPED_DICTIONARY_INFO(Signal, Variant::SIGNAL)
MAKE_TYPED_DICTIONARY_INFO(Dictionary, Variant::DICTIONARY)
MAKE_TYPED_DICTIONARY_INFO(Array, Variant::ARRAY)

MAKE_TYPED_DICTIONARY_WITH_OBJECT_INFO(Variant, Variant::NIL)
MAKE_TYPED_DICTIONARY_WITH_OBJECT_INFO(bool, Variant::BOOL)
MAKE_TYPED_DICTIONARY_WITH_OBJECT_INFO(uint8_t, Variant::INT)
MAKE_TYPED_DICTIONARY_WITH_OBJECT_INFO(int8_t, Variant::INT)
MAKE_TYPED_DICTIONARY_WITH_OBJECT_INFO(uint16_t, Variant::INT)
MAKE_TYPED_DICTIONARY_WITH_OBJECT_INFO(int16_t, Variant::INT)
MAKE_TYPED_DICTIONARY_WITH_OBJECT_INFO(uint32_t, Variant::INT)
MAKE_TYPED_DICTIONARY_WITH_OBJECT_INFO(int32_t, Variant::INT)
MAKE_TYPED_DICTIONARY_WITH_OBJECT_INFO(uint64_t, Variant::INT)
MAKE_TYPED_DICTIONARY_WITH_OBJECT_INFO(int64_t, Variant::INT)
MAKE_TYPED_DICTIONARY_WITH_OBJECT_INFO(float, Variant::FLOAT)
MAKE_TYPED_DICTIONARY_WITH_OBJECT_INFO(double, Variant::FLOAT)
MAKE_TYPED_DICTIONARY_WITH_OBJECT_INFO(String, Variant::STRING)
MAKE_TYPED_DICTIONARY_WITH_OBJECT_INFO(Vector2, Variant::VECTOR2)
MAKE_TYPED_DICTIONARY_WITH_OBJECT_INFO(Vector2i, Variant::VECTOR2I)
MAKE_TYPED_DICTIONARY_WITH_OBJECT_INFO(Rect2, Variant::RECT2)
MAKE_TYPED_DICTIONARY_WITH_OBJECT_INFO(Rect2i, Variant::RECT2I)
MAKE_TYPED_DICTIONARY_WITH_OBJECT_INFO(Vector3, Variant::VECTOR3)
MAKE_TYPED_DICTIONARY_WITH_OBJECT_INFO(Vector3i, Variant::VECTOR3I)
MAKE_TYPED_DICTIONARY_WITH_OBJECT_INFO(Transform2D, Variant::TRANSFORM2D)
MAKE_TYPED_DICTIONARY_WITH_OBJECT_INFO(Plane, Variant::PLANE)
MAKE_TYPED_DICTIONARY_WITH_OBJECT_INFO(Quaternion, Variant::QUATERNION)
MAKE_TYPED_DICTIONARY_WITH_OBJECT_INFO(AABB, Variant::AABB)
MAKE_TYPED_DICTIONARY_WITH_OBJECT_INFO(Basis, Variant::BASIS)
MAKE_TYPED_DICTIONARY_WITH_OBJECT_INFO(Transform3D, Variant::TRANSFORM3D)
MAKE_TYPED_DICTIONARY_WITH_OBJECT_INFO(Color, Variant::COLOR)
MAKE_TYPED_DICTIONARY_WITH_OBJECT_INFO(StringName, Variant::STRING_NAME)
MAKE_TYPED_DICTIONARY_WITH_OBJECT_INFO(NodePath, Variant::NODE_PATH)
MAKE_TYPED_DICTIONARY_WITH_OBJECT_INFO(RID, Variant::RID)
MAKE_TYPED_DICTIONARY_WITH_OBJECT_INFO(Callable, Variant::CALLABLE)
MAKE_TYPED_DICTIONARY_WITH_OBJECT_INFO(Signal, Variant::SIGNAL)
MAKE_TYPED_DICTIONARY_WITH_OBJECT_INFO(Dictionary, Variant::DICTIONARY)
MAKE_TYPED_DICTIONARY_WITH_OBJECT_INFO(Array, Variant::ARRAY)

MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Variant, Variant::NIL, bool, Variant::BOOL)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Variant, Variant::NIL, uint8_t, Variant::INT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Variant, Variant::NIL, int8_t, Variant::INT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Variant, Variant::NIL, uint16_t, Variant::INT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Variant, Variant::NIL, int16_t, Variant::INT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Variant, Variant::NIL, uint32_t, Variant::INT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Variant, Variant::NIL, int32_t, Variant::INT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Variant, Variant::NIL, uint64_t, Variant::INT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Variant, Variant::NIL, int64_t, Variant::INT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Variant, Variant::NIL, float, Variant::FLOAT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Variant, Variant::NIL, double, Variant::FLOAT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Variant, Variant::NIL, String, Variant::STRING)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Variant, Variant::NIL, Vector2, Variant::VECTOR2)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Variant, Variant::NIL, Vector2i, Variant::VECTOR2I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Variant, Variant::NIL, Rect2, Variant::RECT2)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Variant, Variant::NIL, Rect2i, Variant::RECT2I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Variant, Variant::NIL, Vector3, Variant::VECTOR3)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Variant, Variant::NIL, Vector3i, Variant::VECTOR3I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Variant, Variant::NIL, Transform2D, Variant::TRANSFORM2D)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Variant, Variant::NIL, Plane, Variant::PLANE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Variant, Variant::NIL, Quaternion, Variant::QUATERNION)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Variant, Variant::NIL, AABB, Variant::AABB)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Variant, Variant::NIL, Basis, Variant::BASIS)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Variant, Variant::NIL, Transform3D, Variant::TRANSFORM3D)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Variant, Variant::NIL, Color, Variant::COLOR)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Variant, Variant::NIL, StringName, Variant::STRING_NAME)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Variant, Variant::NIL, NodePath, Variant::NODE_PATH)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Variant, Variant::NIL, RID, Variant::RID)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Variant, Variant::NIL, Callable, Variant::CALLABLE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Variant, Variant::NIL, Signal, Variant::SIGNAL)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Variant, Variant::NIL, Dictionary, Variant::DICTIONARY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Variant, Variant::NIL, Array, Variant::ARRAY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(bool, Variant::BOOL, uint8_t, Variant::INT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(bool, Variant::BOOL, int8_t, Variant::INT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(bool, Variant::BOOL, uint16_t, Variant::INT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(bool, Variant::BOOL, int16_t, Variant::INT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(bool, Variant::BOOL, uint32_t, Variant::INT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(bool, Variant::BOOL, int32_t, Variant::INT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(bool, Variant::BOOL, uint64_t, Variant::INT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(bool, Variant::BOOL, int64_t, Variant::INT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(bool, Variant::BOOL, float, Variant::FLOAT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(bool, Variant::BOOL, double, Variant::FLOAT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(bool, Variant::BOOL, String, Variant::STRING)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(bool, Variant::BOOL, Vector2, Variant::VECTOR2)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(bool, Variant::BOOL, Vector2i, Variant::VECTOR2I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(bool, Variant::BOOL, Rect2, Variant::RECT2)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(bool, Variant::BOOL, Rect2i, Variant::RECT2I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(bool, Variant::BOOL, Vector3, Variant::VECTOR3)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(bool, Variant::BOOL, Vector3i, Variant::VECTOR3I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(bool, Variant::BOOL, Transform2D, Variant::TRANSFORM2D)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(bool, Variant::BOOL, Plane, Variant::PLANE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(bool, Variant::BOOL, Quaternion, Variant::QUATERNION)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(bool, Variant::BOOL, AABB, Variant::AABB)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(bool, Variant::BOOL, Basis, Variant::BASIS)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(bool, Variant::BOOL, Transform3D, Variant::TRANSFORM3D)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(bool, Variant::BOOL, Color, Variant::COLOR)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(bool, Variant::BOOL, StringName, Variant::STRING_NAME)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(bool, Variant::BOOL, NodePath, Variant::NODE_PATH)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(bool, Variant::BOOL, RID, Variant::RID)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(bool, Variant::BOOL, Callable, Variant::CALLABLE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(bool, Variant::BOOL, Signal, Variant::SIGNAL)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(bool, Variant::BOOL, Dictionary, Variant::DICTIONARY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(bool, Variant::BOOL, Array, Variant::ARRAY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint8_t, Variant::INT, int8_t, Variant::INT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint8_t, Variant::INT, uint16_t, Variant::INT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint8_t, Variant::INT, int16_t, Variant::INT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint8_t, Variant::INT, uint32_t, Variant::INT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint8_t, Variant::INT, int32_t, Variant::INT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint8_t, Variant::INT, uint64_t, Variant::INT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint8_t, Variant::INT, int64_t, Variant::INT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint8_t, Variant::INT, float, Variant::FLOAT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint8_t, Variant::INT, double, Variant::FLOAT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint8_t, Variant::INT, String, Variant::STRING)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint8_t, Variant::INT, Vector2, Variant::VECTOR2)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint8_t, Variant::INT, Vector2i, Variant::VECTOR2I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint8_t, Variant::INT, Rect2, Variant::RECT2)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint8_t, Variant::INT, Rect2i, Variant::RECT2I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint8_t, Variant::INT, Vector3, Variant::VECTOR3)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint8_t, Variant::INT, Vector3i, Variant::VECTOR3I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint8_t, Variant::INT, Transform2D, Variant::TRANSFORM2D)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint8_t, Variant::INT, Plane, Variant::PLANE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint8_t, Variant::INT, Quaternion, Variant::QUATERNION)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint8_t, Variant::INT, AABB, Variant::AABB)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint8_t, Variant::INT, Basis, Variant::BASIS)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint8_t, Variant::INT, Transform3D, Variant::TRANSFORM3D)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint8_t, Variant::INT, Color, Variant::COLOR)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint8_t, Variant::INT, StringName, Variant::STRING_NAME)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint8_t, Variant::INT, NodePath, Variant::NODE_PATH)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint8_t, Variant::INT, RID, Variant::RID)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint8_t, Variant::INT, Callable, Variant::CALLABLE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint8_t, Variant::INT, Signal, Variant::SIGNAL)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint8_t, Variant::INT, Dictionary, Variant::DICTIONARY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint8_t, Variant::INT, Array, Variant::ARRAY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int8_t, Variant::INT, uint16_t, Variant::INT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int8_t, Variant::INT, int16_t, Variant::INT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int8_t, Variant::INT, uint32_t, Variant::INT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int8_t, Variant::INT, int32_t, Variant::INT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int8_t, Variant::INT, uint64_t, Variant::INT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int8_t, Variant::INT, int64_t, Variant::INT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int8_t, Variant::INT, float, Variant::FLOAT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int8_t, Variant::INT, double, Variant::FLOAT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int8_t, Variant::INT, String, Variant::STRING)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int8_t, Variant::INT, Vector2, Variant::VECTOR2)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int8_t, Variant::INT, Vector2i, Variant::VECTOR2I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int8_t, Variant::INT, Rect2, Variant::RECT2)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int8_t, Variant::INT, Rect2i, Variant::RECT2I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int8_t, Variant::INT, Vector3, Variant::VECTOR3)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int8_t, Variant::INT, Vector3i, Variant::VECTOR3I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int8_t, Variant::INT, Transform2D, Variant::TRANSFORM2D)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int8_t, Variant::INT, Plane, Variant::PLANE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int8_t, Variant::INT, Quaternion, Variant::QUATERNION)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int8_t, Variant::INT, AABB, Variant::AABB)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int8_t, Variant::INT, Basis, Variant::BASIS)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int8_t, Variant::INT, Transform3D, Variant::TRANSFORM3D)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int8_t, Variant::INT, Color, Variant::COLOR)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int8_t, Variant::INT, StringName, Variant::STRING_NAME)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int8_t, Variant::INT, NodePath, Variant::NODE_PATH)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int8_t, Variant::INT, RID, Variant::RID)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int8_t, Variant::INT, Callable, Variant::CALLABLE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int8_t, Variant::INT, Signal, Variant::SIGNAL)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int8_t, Variant::INT, Dictionary, Variant::DICTIONARY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int8_t, Variant::INT, Array, Variant::ARRAY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint16_t, Variant::INT, int16_t, Variant::INT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint16_t, Variant::INT, uint32_t, Variant::INT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint16_t, Variant::INT, int32_t, Variant::INT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint16_t, Variant::INT, uint64_t, Variant::INT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint16_t, Variant::INT, int64_t, Variant::INT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint16_t, Variant::INT, float, Variant::FLOAT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint16_t, Variant::INT, double, Variant::FLOAT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint16_t, Variant::INT, String, Variant::STRING)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint16_t, Variant::INT, Vector2, Variant::VECTOR2)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint16_t, Variant::INT, Vector2i, Variant::VECTOR2I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint16_t, Variant::INT, Rect2, Variant::RECT2)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint16_t, Variant::INT, Rect2i, Variant::RECT2I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint16_t, Variant::INT, Vector3, Variant::VECTOR3)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint16_t, Variant::INT, Vector3i, Variant::VECTOR3I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint16_t, Variant::INT, Transform2D, Variant::TRANSFORM2D)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint16_t, Variant::INT, Plane, Variant::PLANE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint16_t, Variant::INT, Quaternion, Variant::QUATERNION)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint16_t, Variant::INT, AABB, Variant::AABB)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint16_t, Variant::INT, Basis, Variant::BASIS)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint16_t, Variant::INT, Transform3D, Variant::TRANSFORM3D)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint16_t, Variant::INT, Color, Variant::COLOR)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint16_t, Variant::INT, StringName, Variant::STRING_NAME)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint16_t, Variant::INT, NodePath, Variant::NODE_PATH)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint16_t, Variant::INT, RID, Variant::RID)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint16_t, Variant::INT, Callable, Variant::CALLABLE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint16_t, Variant::INT, Signal, Variant::SIGNAL)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint16_t, Variant::INT, Dictionary, Variant::DICTIONARY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint16_t, Variant::INT, Array, Variant::ARRAY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int16_t, Variant::INT, uint32_t, Variant::INT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int16_t, Variant::INT, int32_t, Variant::INT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int16_t, Variant::INT, uint64_t, Variant::INT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int16_t, Variant::INT, int64_t, Variant::INT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int16_t, Variant::INT, float, Variant::FLOAT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int16_t, Variant::INT, double, Variant::FLOAT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int16_t, Variant::INT, String, Variant::STRING)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int16_t, Variant::INT, Vector2, Variant::VECTOR2)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int16_t, Variant::INT, Vector2i, Variant::VECTOR2I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int16_t, Variant::INT, Rect2, Variant::RECT2)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int16_t, Variant::INT, Rect2i, Variant::RECT2I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int16_t, Variant::INT, Vector3, Variant::VECTOR3)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int16_t, Variant::INT, Vector3i, Variant::VECTOR3I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int16_t, Variant::INT, Transform2D, Variant::TRANSFORM2D)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int16_t, Variant::INT, Plane, Variant::PLANE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int16_t, Variant::INT, Quaternion, Variant::QUATERNION)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int16_t, Variant::INT, AABB, Variant::AABB)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int16_t, Variant::INT, Basis, Variant::BASIS)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int16_t, Variant::INT, Transform3D, Variant::TRANSFORM3D)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int16_t, Variant::INT, Color, Variant::COLOR)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int16_t, Variant::INT, StringName, Variant::STRING_NAME)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int16_t, Variant::INT, NodePath, Variant::NODE_PATH)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int16_t, Variant::INT, RID, Variant::RID)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int16_t, Variant::INT, Callable, Variant::CALLABLE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int16_t, Variant::INT, Signal, Variant::SIGNAL)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int16_t, Variant::INT, Dictionary, Variant::DICTIONARY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int16_t, Variant::INT, Array, Variant::ARRAY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint32_t, Variant::INT, int32_t, Variant::INT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint32_t, Variant::INT, uint64_t, Variant::INT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint32_t, Variant::INT, int64_t, Variant::INT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint32_t, Variant::INT, float, Variant::FLOAT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint32_t, Variant::INT, double, Variant::FLOAT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint32_t, Variant::INT, String, Variant::STRING)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint32_t, Variant::INT, Vector2, Variant::VECTOR2)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint32_t, Variant::INT, Vector2i, Variant::VECTOR2I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint32_t, Variant::INT, Rect2, Variant::RECT2)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint32_t, Variant::INT, Rect2i, Variant::RECT2I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint32_t, Variant::INT, Vector3, Variant::VECTOR3)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint32_t, Variant::INT, Vector3i, Variant::VECTOR3I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint32_t, Variant::INT, Transform2D, Variant::TRANSFORM2D)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint32_t, Variant::INT, Plane, Variant::PLANE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint32_t, Variant::INT, Quaternion, Variant::QUATERNION)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint32_t, Variant::INT, AABB, Variant::AABB)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint32_t, Variant::INT, Basis, Variant::BASIS)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint32_t, Variant::INT, Transform3D, Variant::TRANSFORM3D)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint32_t, Variant::INT, Color, Variant::COLOR)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint32_t, Variant::INT, StringName, Variant::STRING_NAME)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint32_t, Variant::INT, NodePath, Variant::NODE_PATH)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint32_t, Variant::INT, RID, Variant::RID)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint32_t, Variant::INT, Callable, Variant::CALLABLE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint32_t, Variant::INT, Signal, Variant::SIGNAL)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint32_t, Variant::INT, Dictionary, Variant::DICTIONARY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint32_t, Variant::INT, Array, Variant::ARRAY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int32_t, Variant::INT, uint64_t, Variant::INT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int32_t, Variant::INT, int64_t, Variant::INT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int32_t, Variant::INT, float, Variant::FLOAT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int32_t, Variant::INT, double, Variant::FLOAT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int32_t, Variant::INT, String, Variant::STRING)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int32_t, Variant::INT, Vector2, Variant::VECTOR2)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int32_t, Variant::INT, Vector2i, Variant::VECTOR2I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int32_t, Variant::INT, Rect2, Variant::RECT2)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int32_t, Variant::INT, Rect2i, Variant::RECT2I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int32_t, Variant::INT, Vector3, Variant::VECTOR3)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int32_t, Variant::INT, Vector3i, Variant::VECTOR3I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int32_t, Variant::INT, Transform2D, Variant::TRANSFORM2D)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int32_t, Variant::INT, Plane, Variant::PLANE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int32_t, Variant::INT, Quaternion, Variant::QUATERNION)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int32_t, Variant::INT, AABB, Variant::AABB)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int32_t, Variant::INT, Basis, Variant::BASIS)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int32_t, Variant::INT, Transform3D, Variant::TRANSFORM3D)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int32_t, Variant::INT, Color, Variant::COLOR)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int32_t, Variant::INT, StringName, Variant::STRING_NAME)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int32_t, Variant::INT, NodePath, Variant::NODE_PATH)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int32_t, Variant::INT, RID, Variant::RID)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int32_t, Variant::INT, Callable, Variant::CALLABLE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int32_t, Variant::INT, Signal, Variant::SIGNAL)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int32_t, Variant::INT, Dictionary, Variant::DICTIONARY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int32_t, Variant::INT, Array, Variant::ARRAY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint64_t, Variant::INT, int64_t, Variant::INT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint64_t, Variant::INT, float, Variant::FLOAT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint64_t, Variant::INT, double, Variant::FLOAT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint64_t, Variant::INT, String, Variant::STRING)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint64_t, Variant::INT, Vector2, Variant::VECTOR2)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint64_t, Variant::INT, Vector2i, Variant::VECTOR2I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint64_t, Variant::INT, Rect2, Variant::RECT2)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint64_t, Variant::INT, Rect2i, Variant::RECT2I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint64_t, Variant::INT, Vector3, Variant::VECTOR3)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint64_t, Variant::INT, Vector3i, Variant::VECTOR3I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint64_t, Variant::INT, Transform2D, Variant::TRANSFORM2D)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint64_t, Variant::INT, Plane, Variant::PLANE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint64_t, Variant::INT, Quaternion, Variant::QUATERNION)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint64_t, Variant::INT, AABB, Variant::AABB)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint64_t, Variant::INT, Basis, Variant::BASIS)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint64_t, Variant::INT, Transform3D, Variant::TRANSFORM3D)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint64_t, Variant::INT, Color, Variant::COLOR)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint64_t, Variant::INT, StringName, Variant::STRING_NAME)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint64_t, Variant::INT, NodePath, Variant::NODE_PATH)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint64_t, Variant::INT, RID, Variant::RID)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint64_t, Variant::INT, Callable, Variant::CALLABLE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint64_t, Variant::INT, Signal, Variant::SIGNAL)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint64_t, Variant::INT, Dictionary, Variant::DICTIONARY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(uint64_t, Variant::INT, Array, Variant::ARRAY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int64_t, Variant::INT, float, Variant::FLOAT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int64_t, Variant::INT, double, Variant::FLOAT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int64_t, Variant::INT, String, Variant::STRING)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int64_t, Variant::INT, Vector2, Variant::VECTOR2)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int64_t, Variant::INT, Vector2i, Variant::VECTOR2I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int64_t, Variant::INT, Rect2, Variant::RECT2)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int64_t, Variant::INT, Rect2i, Variant::RECT2I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int64_t, Variant::INT, Vector3, Variant::VECTOR3)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int64_t, Variant::INT, Vector3i, Variant::VECTOR3I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int64_t, Variant::INT, Transform2D, Variant::TRANSFORM2D)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int64_t, Variant::INT, Plane, Variant::PLANE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int64_t, Variant::INT, Quaternion, Variant::QUATERNION)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int64_t, Variant::INT, AABB, Variant::AABB)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int64_t, Variant::INT, Basis, Variant::BASIS)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int64_t, Variant::INT, Transform3D, Variant::TRANSFORM3D)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int64_t, Variant::INT, Color, Variant::COLOR)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int64_t, Variant::INT, StringName, Variant::STRING_NAME)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int64_t, Variant::INT, NodePath, Variant::NODE_PATH)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int64_t, Variant::INT, RID, Variant::RID)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int64_t, Variant::INT, Callable, Variant::CALLABLE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int64_t, Variant::INT, Signal, Variant::SIGNAL)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int64_t, Variant::INT, Dictionary, Variant::DICTIONARY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(int64_t, Variant::INT, Array, Variant::ARRAY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(float, Variant::FLOAT, double, Variant::FLOAT)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(float, Variant::FLOAT, String, Variant::STRING)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(float, Variant::FLOAT, Vector2, Variant::VECTOR2)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(float, Variant::FLOAT, Vector2i, Variant::VECTOR2I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(float, Variant::FLOAT, Rect2, Variant::RECT2)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(float, Variant::FLOAT, Rect2i, Variant::RECT2I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(float, Variant::FLOAT, Vector3, Variant::VECTOR3)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(float, Variant::FLOAT, Vector3i, Variant::VECTOR3I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(float, Variant::FLOAT, Transform2D, Variant::TRANSFORM2D)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(float, Variant::FLOAT, Plane, Variant::PLANE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(float, Variant::FLOAT, Quaternion, Variant::QUATERNION)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(float, Variant::FLOAT, AABB, Variant::AABB)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(float, Variant::FLOAT, Basis, Variant::BASIS)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(float, Variant::FLOAT, Transform3D, Variant::TRANSFORM3D)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(float, Variant::FLOAT, Color, Variant::COLOR)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(float, Variant::FLOAT, StringName, Variant::STRING_NAME)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(float, Variant::FLOAT, NodePath, Variant::NODE_PATH)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(float, Variant::FLOAT, RID, Variant::RID)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(float, Variant::FLOAT, Callable, Variant::CALLABLE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(float, Variant::FLOAT, Signal, Variant::SIGNAL)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(float, Variant::FLOAT, Dictionary, Variant::DICTIONARY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(float, Variant::FLOAT, Array, Variant::ARRAY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(double, Variant::FLOAT, String, Variant::STRING)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(double, Variant::FLOAT, Vector2, Variant::VECTOR2)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(double, Variant::FLOAT, Vector2i, Variant::VECTOR2I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(double, Variant::FLOAT, Rect2, Variant::RECT2)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(double, Variant::FLOAT, Rect2i, Variant::RECT2I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(double, Variant::FLOAT, Vector3, Variant::VECTOR3)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(double, Variant::FLOAT, Vector3i, Variant::VECTOR3I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(double, Variant::FLOAT, Transform2D, Variant::TRANSFORM2D)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(double, Variant::FLOAT, Plane, Variant::PLANE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(double, Variant::FLOAT, Quaternion, Variant::QUATERNION)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(double, Variant::FLOAT, AABB, Variant::AABB)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(double, Variant::FLOAT, Basis, Variant::BASIS)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(double, Variant::FLOAT, Transform3D, Variant::TRANSFORM3D)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(double, Variant::FLOAT, Color, Variant::COLOR)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(double, Variant::FLOAT, StringName, Variant::STRING_NAME)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(double, Variant::FLOAT, NodePath, Variant::NODE_PATH)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(double, Variant::FLOAT, RID, Variant::RID)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(double, Variant::FLOAT, Callable, Variant::CALLABLE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(double, Variant::FLOAT, Signal, Variant::SIGNAL)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(double, Variant::FLOAT, Dictionary, Variant::DICTIONARY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(double, Variant::FLOAT, Array, Variant::ARRAY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(String, Variant::STRING, Vector2, Variant::VECTOR2)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(String, Variant::STRING, Vector2i, Variant::VECTOR2I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(String, Variant::STRING, Rect2, Variant::RECT2)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(String, Variant::STRING, Rect2i, Variant::RECT2I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(String, Variant::STRING, Vector3, Variant::VECTOR3)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(String, Variant::STRING, Vector3i, Variant::VECTOR3I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(String, Variant::STRING, Transform2D, Variant::TRANSFORM2D)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(String, Variant::STRING, Plane, Variant::PLANE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(String, Variant::STRING, Quaternion, Variant::QUATERNION)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(String, Variant::STRING, AABB, Variant::AABB)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(String, Variant::STRING, Basis, Variant::BASIS)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(String, Variant::STRING, Transform3D, Variant::TRANSFORM3D)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(String, Variant::STRING, Color, Variant::COLOR)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(String, Variant::STRING, StringName, Variant::STRING_NAME)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(String, Variant::STRING, NodePath, Variant::NODE_PATH)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(String, Variant::STRING, RID, Variant::RID)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(String, Variant::STRING, Callable, Variant::CALLABLE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(String, Variant::STRING, Signal, Variant::SIGNAL)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(String, Variant::STRING, Dictionary, Variant::DICTIONARY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(String, Variant::STRING, Array, Variant::ARRAY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector2, Variant::VECTOR2, Vector2i, Variant::VECTOR2I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector2, Variant::VECTOR2, Rect2, Variant::RECT2)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector2, Variant::VECTOR2, Rect2i, Variant::RECT2I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector2, Variant::VECTOR2, Vector3, Variant::VECTOR3)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector2, Variant::VECTOR2, Vector3i, Variant::VECTOR3I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector2, Variant::VECTOR2, Transform2D, Variant::TRANSFORM2D)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector2, Variant::VECTOR2, Plane, Variant::PLANE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector2, Variant::VECTOR2, Quaternion, Variant::QUATERNION)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector2, Variant::VECTOR2, AABB, Variant::AABB)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector2, Variant::VECTOR2, Basis, Variant::BASIS)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector2, Variant::VECTOR2, Transform3D, Variant::TRANSFORM3D)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector2, Variant::VECTOR2, Color, Variant::COLOR)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector2, Variant::VECTOR2, StringName, Variant::STRING_NAME)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector2, Variant::VECTOR2, NodePath, Variant::NODE_PATH)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector2, Variant::VECTOR2, RID, Variant::RID)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector2, Variant::VECTOR2, Callable, Variant::CALLABLE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector2, Variant::VECTOR2, Signal, Variant::SIGNAL)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector2, Variant::VECTOR2, Dictionary, Variant::DICTIONARY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector2, Variant::VECTOR2, Array, Variant::ARRAY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector2i, Variant::VECTOR2I, Rect2, Variant::RECT2)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector2i, Variant::VECTOR2I, Rect2i, Variant::RECT2I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector2i, Variant::VECTOR2I, Vector3, Variant::VECTOR3)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector2i, Variant::VECTOR2I, Vector3i, Variant::VECTOR3I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector2i, Variant::VECTOR2I, Transform2D, Variant::TRANSFORM2D)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector2i, Variant::VECTOR2I, Plane, Variant::PLANE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector2i, Variant::VECTOR2I, Quaternion, Variant::QUATERNION)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector2i, Variant::VECTOR2I, AABB, Variant::AABB)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector2i, Variant::VECTOR2I, Basis, Variant::BASIS)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector2i, Variant::VECTOR2I, Transform3D, Variant::TRANSFORM3D)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector2i, Variant::VECTOR2I, Color, Variant::COLOR)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector2i, Variant::VECTOR2I, StringName, Variant::STRING_NAME)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector2i, Variant::VECTOR2I, NodePath, Variant::NODE_PATH)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector2i, Variant::VECTOR2I, RID, Variant::RID)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector2i, Variant::VECTOR2I, Callable, Variant::CALLABLE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector2i, Variant::VECTOR2I, Signal, Variant::SIGNAL)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector2i, Variant::VECTOR2I, Dictionary, Variant::DICTIONARY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector2i, Variant::VECTOR2I, Array, Variant::ARRAY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Rect2, Variant::RECT2, Rect2i, Variant::RECT2I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Rect2, Variant::RECT2, Vector3, Variant::VECTOR3)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Rect2, Variant::RECT2, Vector3i, Variant::VECTOR3I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Rect2, Variant::RECT2, Transform2D, Variant::TRANSFORM2D)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Rect2, Variant::RECT2, Plane, Variant::PLANE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Rect2, Variant::RECT2, Quaternion, Variant::QUATERNION)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Rect2, Variant::RECT2, AABB, Variant::AABB)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Rect2, Variant::RECT2, Basis, Variant::BASIS)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Rect2, Variant::RECT2, Transform3D, Variant::TRANSFORM3D)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Rect2, Variant::RECT2, Color, Variant::COLOR)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Rect2, Variant::RECT2, StringName, Variant::STRING_NAME)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Rect2, Variant::RECT2, NodePath, Variant::NODE_PATH)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Rect2, Variant::RECT2, RID, Variant::RID)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Rect2, Variant::RECT2, Callable, Variant::CALLABLE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Rect2, Variant::RECT2, Signal, Variant::SIGNAL)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Rect2, Variant::RECT2, Dictionary, Variant::DICTIONARY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Rect2, Variant::RECT2, Array, Variant::ARRAY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Rect2i, Variant::RECT2I, Vector3, Variant::VECTOR3)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Rect2i, Variant::RECT2I, Vector3i, Variant::VECTOR3I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Rect2i, Variant::RECT2I, Transform2D, Variant::TRANSFORM2D)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Rect2i, Variant::RECT2I, Plane, Variant::PLANE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Rect2i, Variant::RECT2I, Quaternion, Variant::QUATERNION)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Rect2i, Variant::RECT2I, AABB, Variant::AABB)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Rect2i, Variant::RECT2I, Basis, Variant::BASIS)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Rect2i, Variant::RECT2I, Transform3D, Variant::TRANSFORM3D)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Rect2i, Variant::RECT2I, Color, Variant::COLOR)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Rect2i, Variant::RECT2I, StringName, Variant::STRING_NAME)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Rect2i, Variant::RECT2I, NodePath, Variant::NODE_PATH)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Rect2i, Variant::RECT2I, RID, Variant::RID)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Rect2i, Variant::RECT2I, Callable, Variant::CALLABLE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Rect2i, Variant::RECT2I, Signal, Variant::SIGNAL)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Rect2i, Variant::RECT2I, Dictionary, Variant::DICTIONARY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Rect2i, Variant::RECT2I, Array, Variant::ARRAY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector3, Variant::VECTOR3, Vector3i, Variant::VECTOR3I)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector3, Variant::VECTOR3, Transform2D, Variant::TRANSFORM2D)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector3, Variant::VECTOR3, Plane, Variant::PLANE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector3, Variant::VECTOR3, Quaternion, Variant::QUATERNION)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector3, Variant::VECTOR3, AABB, Variant::AABB)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector3, Variant::VECTOR3, Basis, Variant::BASIS)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector3, Variant::VECTOR3, Transform3D, Variant::TRANSFORM3D)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector3, Variant::VECTOR3, Color, Variant::COLOR)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector3, Variant::VECTOR3, StringName, Variant::STRING_NAME)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector3, Variant::VECTOR3, NodePath, Variant::NODE_PATH)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector3, Variant::VECTOR3, RID, Variant::RID)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector3, Variant::VECTOR3, Callable, Variant::CALLABLE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector3, Variant::VECTOR3, Signal, Variant::SIGNAL)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector3, Variant::VECTOR3, Dictionary, Variant::DICTIONARY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector3, Variant::VECTOR3, Array, Variant::ARRAY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector3i, Variant::VECTOR3I, Transform2D, Variant::TRANSFORM2D)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector3i, Variant::VECTOR3I, Plane, Variant::PLANE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector3i, Variant::VECTOR3I, Quaternion, Variant::QUATERNION)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector3i, Variant::VECTOR3I, AABB, Variant::AABB)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector3i, Variant::VECTOR3I, Basis, Variant::BASIS)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector3i, Variant::VECTOR3I, Transform3D, Variant::TRANSFORM3D)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector3i, Variant::VECTOR3I, Color, Variant::COLOR)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector3i, Variant::VECTOR3I, StringName, Variant::STRING_NAME)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector3i, Variant::VECTOR3I, NodePath, Variant::NODE_PATH)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector3i, Variant::VECTOR3I, RID, Variant::RID)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector3i, Variant::VECTOR3I, Callable, Variant::CALLABLE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector3i, Variant::VECTOR3I, Signal, Variant::SIGNAL)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector3i, Variant::VECTOR3I, Dictionary, Variant::DICTIONARY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Vector3i, Variant::VECTOR3I, Array, Variant::ARRAY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Transform2D, Variant::TRANSFORM2D, Plane, Variant::PLANE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Transform2D, Variant::TRANSFORM2D, Quaternion, Variant::QUATERNION)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Transform2D, Variant::TRANSFORM2D, AABB, Variant::AABB)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Transform2D, Variant::TRANSFORM2D, Basis, Variant::BASIS)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Transform2D, Variant::TRANSFORM2D, Transform3D, Variant::TRANSFORM3D)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Transform2D, Variant::TRANSFORM2D, Color, Variant::COLOR)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Transform2D, Variant::TRANSFORM2D, StringName, Variant::STRING_NAME)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Transform2D, Variant::TRANSFORM2D, NodePath, Variant::NODE_PATH)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Transform2D, Variant::TRANSFORM2D, RID, Variant::RID)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Transform2D, Variant::TRANSFORM2D, Callable, Variant::CALLABLE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Transform2D, Variant::TRANSFORM2D, Signal, Variant::SIGNAL)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Transform2D, Variant::TRANSFORM2D, Dictionary, Variant::DICTIONARY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Transform2D, Variant::TRANSFORM2D, Array, Variant::ARRAY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Plane, Variant::PLANE, Quaternion, Variant::QUATERNION)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Plane, Variant::PLANE, AABB, Variant::AABB)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Plane, Variant::PLANE, Basis, Variant::BASIS)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Plane, Variant::PLANE, Transform3D, Variant::TRANSFORM3D)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Plane, Variant::PLANE, Color, Variant::COLOR)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Plane, Variant::PLANE, StringName, Variant::STRING_NAME)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Plane, Variant::PLANE, NodePath, Variant::NODE_PATH)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Plane, Variant::PLANE, RID, Variant::RID)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Plane, Variant::PLANE, Callable, Variant::CALLABLE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Plane, Variant::PLANE, Signal, Variant::SIGNAL)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Plane, Variant::PLANE, Dictionary, Variant::DICTIONARY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Plane, Variant::PLANE, Array, Variant::ARRAY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Quaternion, Variant::QUATERNION, AABB, Variant::AABB)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Quaternion, Variant::QUATERNION, Basis, Variant::BASIS)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Quaternion, Variant::QUATERNION, Transform3D, Variant::TRANSFORM3D)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Quaternion, Variant::QUATERNION, Color, Variant::COLOR)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Quaternion, Variant::QUATERNION, StringName, Variant::STRING_NAME)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Quaternion, Variant::QUATERNION, NodePath, Variant::NODE_PATH)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Quaternion, Variant::QUATERNION, RID, Variant::RID)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Quaternion, Variant::QUATERNION, Callable, Variant::CALLABLE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Quaternion, Variant::QUATERNION, Signal, Variant::SIGNAL)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Quaternion, Variant::QUATERNION, Dictionary, Variant::DICTIONARY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Quaternion, Variant::QUATERNION, Array, Variant::ARRAY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(AABB, Variant::AABB, Basis, Variant::BASIS)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(AABB, Variant::AABB, Transform3D, Variant::TRANSFORM3D)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(AABB, Variant::AABB, Color, Variant::COLOR)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(AABB, Variant::AABB, StringName, Variant::STRING_NAME)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(AABB, Variant::AABB, NodePath, Variant::NODE_PATH)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(AABB, Variant::AABB, RID, Variant::RID)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(AABB, Variant::AABB, Callable, Variant::CALLABLE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(AABB, Variant::AABB, Signal, Variant::SIGNAL)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(AABB, Variant::AABB, Dictionary, Variant::DICTIONARY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(AABB, Variant::AABB, Array, Variant::ARRAY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Basis, Variant::BASIS, Transform3D, Variant::TRANSFORM3D)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Basis, Variant::BASIS, Color, Variant::COLOR)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Basis, Variant::BASIS, StringName, Variant::STRING_NAME)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Basis, Variant::BASIS, NodePath, Variant::NODE_PATH)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Basis, Variant::BASIS, RID, Variant::RID)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Basis, Variant::BASIS, Callable, Variant::CALLABLE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Basis, Variant::BASIS, Signal, Variant::SIGNAL)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Basis, Variant::BASIS, Dictionary, Variant::DICTIONARY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Basis, Variant::BASIS, Array, Variant::ARRAY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Transform3D, Variant::TRANSFORM3D, Color, Variant::COLOR)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Transform3D, Variant::TRANSFORM3D, StringName, Variant::STRING_NAME)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Transform3D, Variant::TRANSFORM3D, NodePath, Variant::NODE_PATH)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Transform3D, Variant::TRANSFORM3D, RID, Variant::RID)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Transform3D, Variant::TRANSFORM3D, Callable, Variant::CALLABLE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Transform3D, Variant::TRANSFORM3D, Signal, Variant::SIGNAL)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Transform3D, Variant::TRANSFORM3D, Dictionary, Variant::DICTIONARY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Transform3D, Variant::TRANSFORM3D, Array, Variant::ARRAY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Color, Variant::COLOR, StringName, Variant::STRING_NAME)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Color, Variant::COLOR, NodePath, Variant::NODE_PATH)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Color, Variant::COLOR, RID, Variant::RID)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Color, Variant::COLOR, Callable, Variant::CALLABLE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Color, Variant::COLOR, Signal, Variant::SIGNAL)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Color, Variant::COLOR, Dictionary, Variant::DICTIONARY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Color, Variant::COLOR, Array, Variant::ARRAY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(StringName, Variant::STRING_NAME, NodePath, Variant::NODE_PATH)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(StringName, Variant::STRING_NAME, RID, Variant::RID)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(StringName, Variant::STRING_NAME, Callable, Variant::CALLABLE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(StringName, Variant::STRING_NAME, Signal, Variant::SIGNAL)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(StringName, Variant::STRING_NAME, Dictionary, Variant::DICTIONARY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(StringName, Variant::STRING_NAME, Array, Variant::ARRAY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(NodePath, Variant::NODE_PATH, RID, Variant::RID)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(NodePath, Variant::NODE_PATH, Callable, Variant::CALLABLE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(NodePath, Variant::NODE_PATH, Signal, Variant::SIGNAL)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(NodePath, Variant::NODE_PATH, Dictionary, Variant::DICTIONARY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(NodePath, Variant::NODE_PATH, Array, Variant::ARRAY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(RID, Variant::RID, Callable, Variant::CALLABLE)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(RID, Variant::RID, Signal, Variant::SIGNAL)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(RID, Variant::RID, Dictionary, Variant::DICTIONARY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(RID, Variant::RID, Array, Variant::ARRAY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Callable, Variant::CALLABLE, Signal, Variant::SIGNAL)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Callable, Variant::CALLABLE, Dictionary, Variant::DICTIONARY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Callable, Variant::CALLABLE, Array, Variant::ARRAY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Signal, Variant::SIGNAL, Dictionary, Variant::DICTIONARY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Signal, Variant::SIGNAL, Array, Variant::ARRAY)
MAKE_TYPED_DICTIONARY_EXPANDED_INFO(Dictionary, Variant::DICTIONARY, Array, Variant::ARRAY)

#define CLASS_INFO(m_type) (GetTypeInfo<m_type *>::get_class_info())

} // namespace godot

#endif // GODOT_TYPE_INFO_HPP
