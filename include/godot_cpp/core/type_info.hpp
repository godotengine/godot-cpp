/*************************************************************************/
/*  type_info.hpp                                                        */
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

#ifndef GODOT_TYPE_INFO_HPP
#define GODOT_TYPE_INFO_HPP

#include <godot_cpp/core/object.hpp>
#include <godot_cpp/variant/variant.hpp>

#include <godot/gdnative_interface.h>

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

// If the compiler fails because it's trying to instantiate the primary 'GetTypeInfo' template
// instead of one of the specializations, it's most likely because the type 'T' is not supported.
// If 'T' is a class that inherits 'Object', make sure it can see the actual class declaration
// instead of a forward declaration. You can always forward declare 'T' in a header file, and then
// include the actual declaration of 'T' in the source file where 'GetTypeInfo<T>' is instantiated.

template <class T, typename = void>
struct GetTypeInfo;

#define MAKE_TYPE_INFO(m_type, m_var_type)                                                                                         \
	template <>                                                                                                                    \
	struct GetTypeInfo<m_type> {                                                                                                   \
		static constexpr GDNativeVariantType VARIANT_TYPE = m_var_type;                                                            \
		static constexpr GDNativeExtensionClassMethodArgumentMetadata METADATA = GDNATIVE_EXTENSION_METHOD_ARGUMENT_METADATA_NONE; \
		static inline GDNativePropertyInfo get_class_info() {                                                                      \
			return PropertyInfo(VARIANT_TYPE, "");                                                                                 \
		}                                                                                                                          \
	};                                                                                                                             \
	template <>                                                                                                                    \
	struct GetTypeInfo<const m_type &> {                                                                                           \
		static constexpr GDNativeVariantType VARIANT_TYPE = m_var_type;                                                            \
		static constexpr GDNativeExtensionClassMethodArgumentMetadata METADATA = GDNATIVE_EXTENSION_METHOD_ARGUMENT_METADATA_NONE; \
		static inline GDNativePropertyInfo get_class_info() {                                                                      \
			return PropertyInfo(VARIANT_TYPE, "");                                                                                 \
		}                                                                                                                          \
	};

#define MAKE_TYPE_INFO_WITH_META(m_type, m_var_type, m_metadata)                             \
	template <>                                                                              \
	struct GetTypeInfo<m_type> {                                                             \
		static constexpr GDNativeVariantType VARIANT_TYPE = m_var_type;                      \
		static constexpr GDNativeExtensionClassMethodArgumentMetadata METADATA = m_metadata; \
		static inline GDNativePropertyInfo get_class_info() {                                \
			return PropertyInfo(VARIANT_TYPE, "");                                           \
		}                                                                                    \
	};                                                                                       \
	template <>                                                                              \
	struct GetTypeInfo<const m_type &> {                                                     \
		static constexpr GDNativeVariantType VARIANT_TYPE = m_var_type;                      \
		static constexpr GDNativeExtensionClassMethodArgumentMetadata METADATA = m_metadata; \
		static inline GDNativePropertyInfo get_class_info() {                                \
			return PropertyInfo(VARIANT_TYPE, "");                                           \
		}                                                                                    \
	};

MAKE_TYPE_INFO(bool, GDNATIVE_VARIANT_TYPE_BOOL)
MAKE_TYPE_INFO_WITH_META(uint8_t, GDNATIVE_VARIANT_TYPE_INT, GDNATIVE_EXTENSION_METHOD_ARGUMENT_METADATA_INT_IS_UINT8)
MAKE_TYPE_INFO_WITH_META(int8_t, GDNATIVE_VARIANT_TYPE_INT, GDNATIVE_EXTENSION_METHOD_ARGUMENT_METADATA_INT_IS_INT8)
MAKE_TYPE_INFO_WITH_META(uint16_t, GDNATIVE_VARIANT_TYPE_INT, GDNATIVE_EXTENSION_METHOD_ARGUMENT_METADATA_INT_IS_UINT16)
MAKE_TYPE_INFO_WITH_META(int16_t, GDNATIVE_VARIANT_TYPE_INT, GDNATIVE_EXTENSION_METHOD_ARGUMENT_METADATA_INT_IS_INT16)
MAKE_TYPE_INFO_WITH_META(uint32_t, GDNATIVE_VARIANT_TYPE_INT, GDNATIVE_EXTENSION_METHOD_ARGUMENT_METADATA_INT_IS_UINT32)
MAKE_TYPE_INFO_WITH_META(int32_t, GDNATIVE_VARIANT_TYPE_INT, GDNATIVE_EXTENSION_METHOD_ARGUMENT_METADATA_INT_IS_INT32)
MAKE_TYPE_INFO_WITH_META(uint64_t, GDNATIVE_VARIANT_TYPE_INT, GDNATIVE_EXTENSION_METHOD_ARGUMENT_METADATA_INT_IS_UINT64)
MAKE_TYPE_INFO_WITH_META(int64_t, GDNATIVE_VARIANT_TYPE_INT, GDNATIVE_EXTENSION_METHOD_ARGUMENT_METADATA_INT_IS_INT64)
MAKE_TYPE_INFO(char16_t, GDNATIVE_VARIANT_TYPE_INT)
MAKE_TYPE_INFO(char32_t, GDNATIVE_VARIANT_TYPE_INT)
MAKE_TYPE_INFO_WITH_META(float, GDNATIVE_VARIANT_TYPE_FLOAT, GDNATIVE_EXTENSION_METHOD_ARGUMENT_METADATA_REAL_IS_FLOAT)
MAKE_TYPE_INFO_WITH_META(double, GDNATIVE_VARIANT_TYPE_FLOAT, GDNATIVE_EXTENSION_METHOD_ARGUMENT_METADATA_REAL_IS_DOUBLE)

MAKE_TYPE_INFO(String, GDNATIVE_VARIANT_TYPE_STRING)
MAKE_TYPE_INFO(Vector2, GDNATIVE_VARIANT_TYPE_VECTOR2)
MAKE_TYPE_INFO(Vector2i, GDNATIVE_VARIANT_TYPE_VECTOR2I)
MAKE_TYPE_INFO(Rect2, GDNATIVE_VARIANT_TYPE_RECT2)
MAKE_TYPE_INFO(Rect2i, GDNATIVE_VARIANT_TYPE_RECT2I)
MAKE_TYPE_INFO(Vector3, GDNATIVE_VARIANT_TYPE_VECTOR3)
MAKE_TYPE_INFO(Vector3i, GDNATIVE_VARIANT_TYPE_VECTOR3I)
MAKE_TYPE_INFO(Transform2D, GDNATIVE_VARIANT_TYPE_TRANSFORM2D)
MAKE_TYPE_INFO(Plane, GDNATIVE_VARIANT_TYPE_PLANE)
MAKE_TYPE_INFO(Quaternion, GDNATIVE_VARIANT_TYPE_QUATERNION)
MAKE_TYPE_INFO(AABB, GDNATIVE_VARIANT_TYPE_AABB)
MAKE_TYPE_INFO(Basis, GDNATIVE_VARIANT_TYPE_BASIS)
MAKE_TYPE_INFO(Transform3D, GDNATIVE_VARIANT_TYPE_TRANSFORM3D)
MAKE_TYPE_INFO(Color, GDNATIVE_VARIANT_TYPE_COLOR)
MAKE_TYPE_INFO(StringName, GDNATIVE_VARIANT_TYPE_STRING_NAME)
MAKE_TYPE_INFO(NodePath, GDNATIVE_VARIANT_TYPE_NODE_PATH)
MAKE_TYPE_INFO(RID, GDNATIVE_VARIANT_TYPE_RID)
MAKE_TYPE_INFO(Callable, GDNATIVE_VARIANT_TYPE_CALLABLE)
MAKE_TYPE_INFO(Signal, GDNATIVE_VARIANT_TYPE_SIGNAL)
MAKE_TYPE_INFO(Dictionary, GDNATIVE_VARIANT_TYPE_DICTIONARY)
MAKE_TYPE_INFO(Array, GDNATIVE_VARIANT_TYPE_ARRAY)
MAKE_TYPE_INFO(PackedByteArray, GDNATIVE_VARIANT_TYPE_PACKED_BYTE_ARRAY)
MAKE_TYPE_INFO(PackedInt32Array, GDNATIVE_VARIANT_TYPE_PACKED_INT32_ARRAY)
MAKE_TYPE_INFO(PackedInt64Array, GDNATIVE_VARIANT_TYPE_PACKED_INT64_ARRAY)
MAKE_TYPE_INFO(PackedFloat32Array, GDNATIVE_VARIANT_TYPE_PACKED_FLOAT32_ARRAY)
MAKE_TYPE_INFO(PackedFloat64Array, GDNATIVE_VARIANT_TYPE_PACKED_FLOAT64_ARRAY)
MAKE_TYPE_INFO(PackedStringArray, GDNATIVE_VARIANT_TYPE_PACKED_STRING_ARRAY)
MAKE_TYPE_INFO(PackedVector2Array, GDNATIVE_VARIANT_TYPE_PACKED_VECTOR2_ARRAY)
MAKE_TYPE_INFO(PackedVector3Array, GDNATIVE_VARIANT_TYPE_PACKED_VECTOR3_ARRAY)
MAKE_TYPE_INFO(PackedColorArray, GDNATIVE_VARIANT_TYPE_PACKED_COLOR_ARRAY)

// For variant.
template <>
struct GetTypeInfo<Variant> {
	static constexpr GDNativeVariantType VARIANT_TYPE = GDNATIVE_VARIANT_TYPE_NIL;
	static constexpr GDNativeExtensionClassMethodArgumentMetadata METADATA = GDNATIVE_EXTENSION_METHOD_ARGUMENT_METADATA_NONE;
	static inline GDNativePropertyInfo get_class_info() {
		return PropertyInfo(GDNATIVE_VARIANT_TYPE_NIL, "", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_DEFAULT | PROPERTY_USAGE_NIL_IS_VARIANT);
	}
};

template <>
struct GetTypeInfo<const Variant &> {
	static constexpr GDNativeVariantType VARIANT_TYPE = GDNATIVE_VARIANT_TYPE_NIL;
	static constexpr GDNativeExtensionClassMethodArgumentMetadata METADATA = GDNATIVE_EXTENSION_METHOD_ARGUMENT_METADATA_NONE;
	static inline GDNativePropertyInfo get_class_info() {
		return PropertyInfo(GDNATIVE_VARIANT_TYPE_NIL, "", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_DEFAULT | PROPERTY_USAGE_NIL_IS_VARIANT);
	}
};

template <typename T>
struct GetTypeInfo<T *, typename EnableIf<TypeInherits<Object, T>::value>::type> {
	static const GDNativeVariantType VARIANT_TYPE = GDNATIVE_VARIANT_TYPE_OBJECT;
	static const GDNativeExtensionClassMethodArgumentMetadata METADATA = GDNATIVE_EXTENSION_METHOD_ARGUMENT_METADATA_NONE;
	static inline PropertyInfo get_class_info() {
		return PropertyInfo(GDNATIVE_VARIANT_TYPE_OBJECT, T::get_class_static());
	}
};

template <typename T>
struct GetTypeInfo<const T *, typename EnableIf<TypeInherits<Object, T>::value>::type> {
	static const GDNativeVariantType VARIANT_TYPE = GDNATIVE_VARIANT_TYPE_OBJECT;
	static const GDNativeExtensionClassMethodArgumentMetadata METADATA = GDNATIVE_EXTENSION_METHOD_ARGUMENT_METADATA_NONE;
	static inline PropertyInfo get_class_info() {
		return PropertyInfo(GDNATIVE_VARIANT_TYPE_OBJECT, T::get_class_static());
	}
};

#define TEMPL_MAKE_ENUM_TYPE_INFO(m_class, m_enum, m_impl)                                                                                                           \
	template <>                                                                                                                                                      \
	struct GetTypeInfo<m_impl> {                                                                                                                                     \
		static const Variant::Type VARIANT_TYPE = Variant::INT;                                                                                                      \
		static const GDNativeExtensionClassMethodArgumentMetadata METADATA = GDNATIVE_EXTENSION_METHOD_ARGUMENT_METADATA_NONE;                                       \
		static inline GDNativePropertyInfo get_class_info() {                                                                                                        \
			return PropertyInfo(GDNATIVE_VARIANT_TYPE_INT, "", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_DEFAULT | PROPERTY_USAGE_CLASS_IS_ENUM, #m_class "." #m_enum); \
		}                                                                                                                                                            \
	};

#define MAKE_ENUM_TYPE_INFO(m_class, m_enum)                          \
	TEMPL_MAKE_ENUM_TYPE_INFO(m_class, m_enum, m_class::m_enum)       \
	TEMPL_MAKE_ENUM_TYPE_INFO(m_class, m_enum, m_class::m_enum const) \
	TEMPL_MAKE_ENUM_TYPE_INFO(m_class, m_enum, m_class::m_enum &)     \
	TEMPL_MAKE_ENUM_TYPE_INFO(m_class, m_enum, const m_class::m_enum &)

template <typename T>
inline const char *__constant_get_enum_name(T param, const char *p_constant) {
	if (GetTypeInfo<T>::VARIANT_TYPE == Variant::NIL) {
		ERR_PRINT(("Missing VARIANT_ENUM_CAST for constant's enum: " + String(p_constant)).utf8().get_data());
	}
	return GetTypeInfo<T>::get_class_info().class_name;
}

#define CLASS_INFO(m_type) (GetTypeInfo<m_type *>::get_class_info())

} // namespace godot

#endif // ! GODOT_TYPE_INFO_HPP
