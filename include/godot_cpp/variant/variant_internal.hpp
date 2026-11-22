/**************************************************************************/
/*  variant_internal.hpp                                                  */
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

#include <godot_cpp/core/version.hpp>

#if GODOT_VERSION_MINOR >= 4

#include <gdextension_interface.h>
#include <godot_cpp/variant/variant.hpp>

namespace godot {
// For use when you want to access the internal pointer of a Variant directly.
// Use with caution. You need to be sure that the type is correct.

namespace internal {
/**
 * Defines the mapping from supported C++ storage types to the corresponding variant type tags.
 */
template <typename T>
struct VariantInternalType {};

/**
 * Maps native \`bool\` storage to its engine variant type tag.
 */
template <>
struct VariantInternalType<bool> {
	static constexpr Variant::Type type = Variant::BOOL;
};
/**
 * Maps native \`int64_t\` storage to its engine variant type tag.
 */
template <>
struct VariantInternalType<int64_t> {
	static constexpr Variant::Type type = Variant::INT;
};
/**
 * Maps native \`double\` storage to its engine variant type tag.
 */
template <>
struct VariantInternalType<double> {
	static constexpr Variant::Type type = Variant::FLOAT;
};
/**
 * Maps native \`godot::String\` storage to its engine variant type tag.
 */
template <>
struct VariantInternalType<String> {
	static constexpr Variant::Type type = Variant::STRING;
};
/**
 * Maps native \`godot::Vector2\` storage to its engine variant type tag.
 */
template <>
struct VariantInternalType<Vector2> {
	static constexpr Variant::Type type = Variant::VECTOR2;
};
/**
 * Maps native \`godot::Vector2i\` storage to its engine variant type tag.
 */
template <>
struct VariantInternalType<Vector2i> {
	static constexpr Variant::Type type = Variant::VECTOR2I;
};
/**
 * Maps native \`godot::Rect2\` storage to its engine variant type tag.
 */
template <>
struct VariantInternalType<Rect2> {
	static constexpr Variant::Type type = Variant::RECT2;
};
/**
 * Maps native \`godot::Rect2i\` storage to its engine variant type tag.
 */
template <>
struct VariantInternalType<Rect2i> {
	static constexpr Variant::Type type = Variant::RECT2I;
};
/**
 * Maps native \`godot::Vector3\` storage to its engine variant type tag.
 */
template <>
struct VariantInternalType<Vector3> {
	static constexpr Variant::Type type = Variant::VECTOR3;
};
/**
 * Maps native \`godot::Vector3i\` storage to its engine variant type tag.
 */
template <>
struct VariantInternalType<Vector3i> {
	static constexpr Variant::Type type = Variant::VECTOR3I;
};
/**
 * Maps native \`godot::Transform2D\` storage to its engine variant type tag.
 */
template <>
struct VariantInternalType<Transform2D> {
	static constexpr Variant::Type type = Variant::TRANSFORM2D;
};
/**
 * Maps native \`godot::Vector4\` storage to its engine variant type tag.
 */
template <>
struct VariantInternalType<Vector4> {
	static constexpr Variant::Type type = Variant::VECTOR4;
};
/**
 * Maps native \`godot::Vector4i\` storage to its engine variant type tag.
 */
template <>
struct VariantInternalType<Vector4i> {
	static constexpr Variant::Type type = Variant::VECTOR4I;
};
/**
 * Maps native \`godot::Plane\` storage to its engine variant type tag.
 */
template <>
struct VariantInternalType<Plane> {
	static constexpr Variant::Type type = Variant::PLANE;
};
/**
 * Maps native \`godot::Quaternion\` storage to its engine variant type tag.
 */
template <>
struct VariantInternalType<Quaternion> {
	static constexpr Variant::Type type = Variant::QUATERNION;
};
/**
 * Maps native \`godot::AABB\` storage to its engine variant type tag.
 */
template <>
struct VariantInternalType<AABB> {
	static constexpr Variant::Type type = Variant::AABB;
};
/**
 * Maps native \`godot::Basis\` storage to its engine variant type tag.
 */
template <>
struct VariantInternalType<Basis> {
	static constexpr Variant::Type type = Variant::BASIS;
};
/**
 * Maps native \`godot::Transform3D\` storage to its engine variant type tag.
 */
template <>
struct VariantInternalType<Transform3D> {
	static constexpr Variant::Type type = Variant::TRANSFORM3D;
};
/**
 * Maps native \`godot::Projection\` storage to its engine variant type tag.
 */
template <>
struct VariantInternalType<Projection> {
	static constexpr Variant::Type type = Variant::PROJECTION;
};
/**
 * Maps native \`godot::Color\` storage to its engine variant type tag.
 */
template <>
struct VariantInternalType<Color> {
	static constexpr Variant::Type type = Variant::COLOR;
};
/**
 * Maps native \`godot::StringName\` storage to its engine variant type tag.
 */
template <>
struct VariantInternalType<StringName> {
	static constexpr Variant::Type type = Variant::STRING_NAME;
};
/**
 * Maps native \`godot::NodePath\` storage to its engine variant type tag.
 */
template <>
struct VariantInternalType<NodePath> {
	static constexpr Variant::Type type = Variant::NODE_PATH;
};
/**
 * Maps native \`godot::RID\` storage to its engine variant type tag.
 */
template <>
struct VariantInternalType<RID> {
	static constexpr Variant::Type type = Variant::RID;
};
/**
 * Maps native \`godot::Object *\` storage to its engine variant type tag.
 */
template <>
struct VariantInternalType<Object *> {
	static constexpr Variant::Type type = Variant::OBJECT;
};
/**
 * Maps native \`godot::Callable\` storage to its engine variant type tag.
 */
template <>
struct VariantInternalType<Callable> {
	static constexpr Variant::Type type = Variant::CALLABLE;
};
/**
 * Maps native \`godot::Signal\` storage to its engine variant type tag.
 */
template <>
struct VariantInternalType<Signal> {
	static constexpr Variant::Type type = Variant::SIGNAL;
};
/**
 * Maps native \`godot::Dictionary\` storage to its engine variant type tag.
 */
template <>
struct VariantInternalType<Dictionary> {
	static constexpr Variant::Type type = Variant::DICTIONARY;
};
/**
 * Maps native \`godot::Array\` storage to its engine variant type tag.
 */
template <>
struct VariantInternalType<Array> {
	static constexpr Variant::Type type = Variant::ARRAY;
};
/**
 * Maps native \`godot::PackedByteArray\` storage to its engine variant type tag.
 */
template <>
struct VariantInternalType<PackedByteArray> {
	static constexpr Variant::Type type = Variant::PACKED_BYTE_ARRAY;
};
/**
 * Maps native \`godot::PackedInt32Array\` storage to its engine variant type tag.
 */
template <>
struct VariantInternalType<PackedInt32Array> {
	static constexpr Variant::Type type = Variant::PACKED_INT32_ARRAY;
};
/**
 * Maps native \`godot::PackedInt64Array\` storage to its engine variant type tag.
 */
template <>
struct VariantInternalType<PackedInt64Array> {
	static constexpr Variant::Type type = Variant::PACKED_INT64_ARRAY;
};
/**
 * Maps native \`godot::PackedFloat32Array\` storage to its engine variant type tag.
 */
template <>
struct VariantInternalType<PackedFloat32Array> {
	static constexpr Variant::Type type = Variant::PACKED_FLOAT32_ARRAY;
};
/**
 * Maps native \`godot::PackedFloat64Array\` storage to its engine variant type tag.
 */
template <>
struct VariantInternalType<PackedFloat64Array> {
	static constexpr Variant::Type type = Variant::PACKED_FLOAT64_ARRAY;
};
/**
 * Maps native \`godot::PackedStringArray\` storage to its engine variant type tag.
 */
template <>
struct VariantInternalType<PackedStringArray> {
	static constexpr Variant::Type type = Variant::PACKED_STRING_ARRAY;
};
/**
 * Maps native \`godot::PackedVector2Array\` storage to its engine variant type tag.
 */
template <>
struct VariantInternalType<PackedVector2Array> {
	static constexpr Variant::Type type = Variant::PACKED_VECTOR2_ARRAY;
};
/**
 * Maps native \`godot::PackedVector3Array\` storage to its engine variant type tag.
 */
template <>
struct VariantInternalType<PackedVector3Array> {
	static constexpr Variant::Type type = Variant::PACKED_VECTOR3_ARRAY;
};
/**
 * Maps native \`godot::PackedColorArray\` storage to its engine variant type tag.
 */
template <>
struct VariantInternalType<PackedColorArray> {
	static constexpr Variant::Type type = Variant::PACKED_COLOR_ARRAY;
};
/**
 * Maps native \`godot::PackedVector4Array\` storage to its engine variant type tag.
 */
template <>
struct VariantInternalType<PackedVector4Array> {
	static constexpr Variant::Type type = Variant::PACKED_VECTOR4_ARRAY;
};
} //namespace internal

class VariantInternal {
	friend class Variant;

	/**
	 * Engine functions that locate the native contents of a variant, indexed by its type tag.
	 */
	static GDExtensionVariantGetInternalPtrFunc get_internal_func[Variant::VARIANT_MAX];

	/**
	 * Caches the engine's internal-value pointer function for each supported variant type.
	 */
	static void init_bindings();

public:
	/**
	 * Gets a pointer to the stored value of type `T`. The pointer refers to engine-owned storage. There is
	 * no type conversion.
	 */
	template <typename T>
	_FORCE_INLINE_ static T *get_internal_value(Variant *v) {
		return static_cast<T *>(get_internal_func[::godot::internal::VariantInternalType<T>::type](v));
	}

	/**
	 * Gets a pointer to the stored value of type `T`. The pointer refers to engine-owned storage. There is
	 * no type conversion.
	 */
	template <typename T>
	_FORCE_INLINE_ static const T *get_internal_value(const Variant *v) {
		return static_cast<const T *>(get_internal_func[::godot::internal::VariantInternalType<T>::type](const_cast<Variant *>(v)));
	}

	// Atomic types.
	/**
	 * Returns a writable pointer to the stored \`bool\`. The variant must already hold that type.
	 */
	_FORCE_INLINE_ static bool *get_bool(Variant *v) { return get_internal_value<bool>(v); }
	/**
	 * Returns a read-only pointer to the stored \`bool\`. The variant must already hold that type.
	 */
	_FORCE_INLINE_ static const bool *get_bool(const Variant *v) { return get_internal_value<bool>(v); }
	/**
	 * Returns a writable pointer to the stored \`int64_t\`. The variant must already hold that type.
	 */
	_FORCE_INLINE_ static int64_t *get_int(Variant *v) { return get_internal_value<int64_t>(v); }
	/**
	 * Returns a read-only pointer to the stored \`int64_t\`. The variant must already hold that type.
	 */
	_FORCE_INLINE_ static const int64_t *get_int(const Variant *v) { return get_internal_value<int64_t>(v); }
	/**
	 * Returns a writable pointer to the stored \`double\`. The variant must already hold that type.
	 */
	_FORCE_INLINE_ static double *get_float(Variant *v) { return get_internal_value<double>(v); }
	/**
	 * Returns a read-only pointer to the stored \`double\`. The variant must already hold that type.
	 */
	_FORCE_INLINE_ static const double *get_float(const Variant *v) { return get_internal_value<double>(v); }
	/**
	 * Returns a writable pointer to the stored \`godot::String\`. The variant must already hold that type.
	 */
	_FORCE_INLINE_ static String *get_string(Variant *v) { return get_internal_value<String>(v); }
	/**
	 * Returns a read-only pointer to the stored \`godot::String\`. The variant must already hold that type.
	 */
	_FORCE_INLINE_ static const String *get_string(const Variant *v) { return get_internal_value<String>(v); }

	// Math types.
	/**
	 * Returns a writable pointer to the stored \`godot::Vector2\`. The variant must already hold that type.
	 */
	_FORCE_INLINE_ static Vector2 *get_vector2(Variant *v) { return get_internal_value<Vector2>(v); }
	/**
	 * Returns a read-only pointer to the stored \`godot::Vector2\`. The variant must already hold that
	 * type.
	 */
	_FORCE_INLINE_ static const Vector2 *get_vector2(const Variant *v) { return get_internal_value<Vector2>(v); }
	/**
	 * Returns a writable pointer to the stored \`godot::Vector2i\`. The variant must already hold that
	 * type.
	 */
	_FORCE_INLINE_ static Vector2i *get_vector2i(Variant *v) { return get_internal_value<Vector2i>(v); }
	/**
	 * Returns a read-only pointer to the stored \`godot::Vector2i\`. The variant must already hold that
	 * type.
	 */
	_FORCE_INLINE_ static const Vector2i *get_vector2i(const Variant *v) { return get_internal_value<Vector2i>(v); }
	/**
	 * Returns a writable pointer to the stored \`godot::Rect2\`. The variant must already hold that type.
	 */
	_FORCE_INLINE_ static Rect2 *get_rect2(Variant *v) { return get_internal_value<Rect2>(v); }
	/**
	 * Returns a read-only pointer to the stored \`godot::Rect2\`. The variant must already hold that type.
	 */
	_FORCE_INLINE_ static const Rect2 *get_rect2(const Variant *v) { return get_internal_value<Rect2>(v); }
	/**
	 * Returns a writable pointer to the stored \`godot::Rect2i\`. The variant must already hold that type.
	 */
	_FORCE_INLINE_ static Rect2i *get_rect2i(Variant *v) { return get_internal_value<Rect2i>(v); }
	/**
	 * Returns a read-only pointer to the stored \`godot::Rect2i\`. The variant must already hold that type.
	 */
	_FORCE_INLINE_ static const Rect2i *get_rect2i(const Variant *v) { return get_internal_value<Rect2i>(v); }
	/**
	 * Returns a writable pointer to the stored \`godot::Vector3\`. The variant must already hold that type.
	 */
	_FORCE_INLINE_ static Vector3 *get_vector3(Variant *v) { return get_internal_value<Vector3>(v); }
	/**
	 * Returns a read-only pointer to the stored \`godot::Vector3\`. The variant must already hold that
	 * type.
	 */
	_FORCE_INLINE_ static const Vector3 *get_vector3(const Variant *v) { return get_internal_value<Vector3>(v); }
	/**
	 * Returns a writable pointer to the stored \`godot::Vector3i\`. The variant must already hold that
	 * type.
	 */
	_FORCE_INLINE_ static Vector3i *get_vector3i(Variant *v) { return get_internal_value<Vector3i>(v); }
	/**
	 * Returns a read-only pointer to the stored \`godot::Vector3i\`. The variant must already hold that
	 * type.
	 */
	_FORCE_INLINE_ static const Vector3i *get_vector3i(const Variant *v) { return get_internal_value<Vector3i>(v); }
	/**
	 * Returns a writable pointer to the stored \`godot::Vector4\`. The variant must already hold that type.
	 */
	_FORCE_INLINE_ static Vector4 *get_vector4(Variant *v) { return get_internal_value<Vector4>(v); }
	/**
	 * Returns a read-only pointer to the stored \`godot::Vector4\`. The variant must already hold that
	 * type.
	 */
	_FORCE_INLINE_ static const Vector4 *get_vector4(const Variant *v) { return get_internal_value<Vector4>(v); }
	/**
	 * Returns a writable pointer to the stored \`godot::Vector4i\`. The variant must already hold that
	 * type.
	 */
	_FORCE_INLINE_ static Vector4i *get_vector4i(Variant *v) { return get_internal_value<Vector4i>(v); }
	/**
	 * Returns a read-only pointer to the stored \`godot::Vector4i\`. The variant must already hold that
	 * type.
	 */
	_FORCE_INLINE_ static const Vector4i *get_vector4i(const Variant *v) { return get_internal_value<Vector4i>(v); }
	/**
	 * Returns a writable pointer to the stored \`godot::Transform2D\`. The variant must already hold that
	 * type.
	 */
	_FORCE_INLINE_ static Transform2D *get_transform2d(Variant *v) { return get_internal_value<Transform2D>(v); }
	/**
	 * Returns a read-only pointer to the stored \`godot::Transform2D\`. The variant must already hold that
	 * type.
	 */
	_FORCE_INLINE_ static const Transform2D *get_transform2d(const Variant *v) { return get_internal_value<Transform2D>(v); }
	/**
	 * Returns a writable pointer to the stored \`godot::Plane\`. The variant must already hold that type.
	 */
	_FORCE_INLINE_ static Plane *get_plane(Variant *v) { return get_internal_value<Plane>(v); }
	/**
	 * Returns a read-only pointer to the stored \`godot::Plane\`. The variant must already hold that type.
	 */
	_FORCE_INLINE_ static const Plane *get_plane(const Variant *v) { return get_internal_value<Plane>(v); }
	/**
	 * Returns a writable pointer to the stored \`godot::Quaternion\`. The variant must already hold that
	 * type.
	 */
	_FORCE_INLINE_ static Quaternion *get_quaternion(Variant *v) { return get_internal_value<Quaternion>(v); }
	/**
	 * Returns a read-only pointer to the stored \`godot::Quaternion\`. The variant must already hold that
	 * type.
	 */
	_FORCE_INLINE_ static const Quaternion *get_quaternion(const Variant *v) { return get_internal_value<Quaternion>(v); }
	/**
	 * Returns a writable pointer to the stored \`godot::AABB\`. The variant must already hold that type.
	 */
	_FORCE_INLINE_ static AABB *get_aabb(Variant *v) { return get_internal_value<AABB>(v); }
	/**
	 * Returns a read-only pointer to the stored \`godot::AABB\`. The variant must already hold that type.
	 */
	_FORCE_INLINE_ static const AABB *get_aabb(const Variant *v) { return get_internal_value<AABB>(v); }
	/**
	 * Returns a writable pointer to the stored \`godot::Basis\`. The variant must already hold that type.
	 */
	_FORCE_INLINE_ static Basis *get_basis(Variant *v) { return get_internal_value<Basis>(v); }
	/**
	 * Returns a read-only pointer to the stored \`godot::Basis\`. The variant must already hold that type.
	 */
	_FORCE_INLINE_ static const Basis *get_basis(const Variant *v) { return get_internal_value<Basis>(v); }
	/**
	 * Returns a writable pointer to the stored \`godot::Transform3D\`. The variant must already hold that
	 * type.
	 */
	_FORCE_INLINE_ static Transform3D *get_transform(Variant *v) { return get_internal_value<Transform3D>(v); }
	/**
	 * Returns a read-only pointer to the stored \`godot::Transform3D\`. The variant must already hold that
	 * type.
	 */
	_FORCE_INLINE_ static const Transform3D *get_transform(const Variant *v) { return get_internal_value<Transform3D>(v); }
	/**
	 * Returns a writable pointer to the stored \`godot::Projection\`. The variant must already hold that
	 * type.
	 */
	_FORCE_INLINE_ static Projection *get_projection(Variant *v) { return get_internal_value<Projection>(v); }
	/**
	 * Returns a read-only pointer to the stored \`godot::Projection\`. The variant must already hold that
	 * type.
	 */
	_FORCE_INLINE_ static const Projection *get_projection(const Variant *v) { return get_internal_value<Projection>(v); }

	// Misc types.
	/**
	 * Returns a writable pointer to the stored \`godot::Color\`. The variant must already hold that type.
	 */
	_FORCE_INLINE_ static Color *get_color(Variant *v) { return get_internal_value<Color>(v); }
	/**
	 * Returns a read-only pointer to the stored \`godot::Color\`. The variant must already hold that type.
	 */
	_FORCE_INLINE_ static const Color *get_color(const Variant *v) { return get_internal_value<Color>(v); }
	/**
	 * Returns a writable pointer to the stored \`godot::StringName\`. The variant must already hold that
	 * type.
	 */
	_FORCE_INLINE_ static StringName *get_string_name(Variant *v) { return get_internal_value<StringName>(v); }
	/**
	 * Returns a read-only pointer to the stored \`godot::StringName\`. The variant must already hold that
	 * type.
	 */
	_FORCE_INLINE_ static const StringName *get_string_name(const Variant *v) { return get_internal_value<StringName>(v); }
	/**
	 * Returns a writable pointer to the stored \`godot::NodePath\`. The variant must already hold that
	 * type.
	 */
	_FORCE_INLINE_ static NodePath *get_node_path(Variant *v) { return get_internal_value<NodePath>(v); }
	/**
	 * Returns a read-only pointer to the stored \`godot::NodePath\`. The variant must already hold that
	 * type.
	 */
	_FORCE_INLINE_ static const NodePath *get_node_path(const Variant *v) { return get_internal_value<NodePath>(v); }
	/**
	 * Returns a writable pointer to the stored \`godot::RID\`. The variant must already hold that type.
	 */
	_FORCE_INLINE_ static RID *get_rid(Variant *v) { return get_internal_value<RID>(v); }
	/**
	 * Returns a read-only pointer to the stored \`godot::RID\`. The variant must already hold that type.
	 */
	_FORCE_INLINE_ static const RID *get_rid(const Variant *v) { return get_internal_value<RID>(v); }
	/**
	 * Returns a writable pointer to the stored \`godot::Callable\`. The variant must already hold that
	 * type.
	 */
	_FORCE_INLINE_ static Callable *get_callable(Variant *v) { return get_internal_value<Callable>(v); }
	/**
	 * Returns a read-only pointer to the stored \`godot::Callable\`. The variant must already hold that
	 * type.
	 */
	_FORCE_INLINE_ static const Callable *get_callable(const Variant *v) { return get_internal_value<Callable>(v); }
	/**
	 * Returns a writable pointer to the stored \`godot::Signal\`. The variant must already hold that type.
	 */
	_FORCE_INLINE_ static Signal *get_signal(Variant *v) { return get_internal_value<Signal>(v); }
	/**
	 * Returns a read-only pointer to the stored \`godot::Signal\`. The variant must already hold that type.
	 */
	_FORCE_INLINE_ static const Signal *get_signal(const Variant *v) { return get_internal_value<Signal>(v); }
	/**
	 * Returns a writable pointer to the stored \`godot::Dictionary\`. The variant must already hold that
	 * type.
	 */
	_FORCE_INLINE_ static Dictionary *get_dictionary(Variant *v) { return get_internal_value<Dictionary>(v); }
	/**
	 * Returns a read-only pointer to the stored \`godot::Dictionary\`. The variant must already hold that
	 * type.
	 */
	_FORCE_INLINE_ static const Dictionary *get_dictionary(const Variant *v) { return get_internal_value<Dictionary>(v); }
	/**
	 * Returns a writable pointer to the stored \`godot::Array\`. The variant must already hold that type.
	 */
	_FORCE_INLINE_ static Array *get_array(Variant *v) { return get_internal_value<Array>(v); }
	/**
	 * Returns a read-only pointer to the stored \`godot::Array\`. The variant must already hold that type.
	 */
	_FORCE_INLINE_ static const Array *get_array(const Variant *v) { return get_internal_value<Array>(v); }

	// Typed arrays.
	/**
	 * Returns a writable pointer to the stored \`godot::PackedByteArray\`. The variant must already hold
	 * that type.
	 */
	_FORCE_INLINE_ static PackedByteArray *get_byte_array(Variant *v) { return get_internal_value<PackedByteArray>(v); }
	/**
	 * Returns a read-only pointer to the stored \`godot::PackedByteArray\`. The variant must already hold
	 * that type.
	 */
	_FORCE_INLINE_ static const PackedByteArray *get_byte_array(const Variant *v) { return get_internal_value<PackedByteArray>(v); }
	/**
	 * Returns a writable pointer to the stored \`godot::PackedInt32Array\`. The variant must already hold
	 * that type.
	 */
	_FORCE_INLINE_ static PackedInt32Array *get_int32_array(Variant *v) { return get_internal_value<PackedInt32Array>(v); }
	/**
	 * Returns a read-only pointer to the stored \`godot::PackedInt32Array\`. The variant must already hold
	 * that type.
	 */
	_FORCE_INLINE_ static const PackedInt32Array *get_int32_array(const Variant *v) { return get_internal_value<PackedInt32Array>(v); }
	/**
	 * Returns a writable pointer to the stored \`godot::PackedInt64Array\`. The variant must already hold
	 * that type.
	 */
	_FORCE_INLINE_ static PackedInt64Array *get_int64_array(Variant *v) { return get_internal_value<PackedInt64Array>(v); }
	/**
	 * Returns a read-only pointer to the stored \`godot::PackedInt64Array\`. The variant must already hold
	 * that type.
	 */
	_FORCE_INLINE_ static const PackedInt64Array *get_int64_array(const Variant *v) { return get_internal_value<PackedInt64Array>(v); }
	/**
	 * Returns a writable pointer to the stored \`godot::PackedFloat32Array\`. The variant must already hold
	 * that type.
	 */
	_FORCE_INLINE_ static PackedFloat32Array *get_float32_array(Variant *v) { return get_internal_value<PackedFloat32Array>(v); }
	/**
	 * Returns a read-only pointer to the stored \`godot::PackedFloat32Array\`. The variant must already
	 * hold that type.
	 */
	_FORCE_INLINE_ static const PackedFloat32Array *get_float32_array(const Variant *v) { return get_internal_value<PackedFloat32Array>(v); }
	/**
	 * Returns a writable pointer to the stored \`godot::PackedFloat64Array\`. The variant must already hold
	 * that type.
	 */
	_FORCE_INLINE_ static PackedFloat64Array *get_float64_array(Variant *v) { return get_internal_value<PackedFloat64Array>(v); }
	/**
	 * Returns a read-only pointer to the stored \`godot::PackedFloat64Array\`. The variant must already
	 * hold that type.
	 */
	_FORCE_INLINE_ static const PackedFloat64Array *get_float64_array(const Variant *v) { return get_internal_value<PackedFloat64Array>(v); }
	/**
	 * Returns a writable pointer to the stored \`godot::PackedStringArray\`. The variant must already hold
	 * that type.
	 */
	_FORCE_INLINE_ static PackedStringArray *get_string_array(Variant *v) { return get_internal_value<PackedStringArray>(v); }
	/**
	 * Returns a read-only pointer to the stored \`godot::PackedStringArray\`. The variant must already hold
	 * that type.
	 */
	_FORCE_INLINE_ static const PackedStringArray *get_string_array(const Variant *v) { return get_internal_value<PackedStringArray>(v); }
	/**
	 * Returns a writable pointer to the stored \`godot::PackedVector2Array\`. The variant must already hold
	 * that type.
	 */
	_FORCE_INLINE_ static PackedVector2Array *get_vector2_array(Variant *v) { return get_internal_value<PackedVector2Array>(v); }
	/**
	 * Returns a read-only pointer to the stored \`godot::PackedVector2Array\`. The variant must already
	 * hold that type.
	 */
	_FORCE_INLINE_ static const PackedVector2Array *get_vector2_array(const Variant *v) { return get_internal_value<PackedVector2Array>(v); }
	/**
	 * Returns a writable pointer to the stored \`godot::PackedVector3Array\`. The variant must already hold
	 * that type.
	 */
	_FORCE_INLINE_ static PackedVector3Array *get_vector3_array(Variant *v) { return get_internal_value<PackedVector3Array>(v); }
	/**
	 * Returns a read-only pointer to the stored \`godot::PackedVector3Array\`. The variant must already
	 * hold that type.
	 */
	_FORCE_INLINE_ static const PackedVector3Array *get_vector3_array(const Variant *v) { return get_internal_value<PackedVector3Array>(v); }
	/**
	 * Returns a writable pointer to the stored \`godot::PackedColorArray\`. The variant must already hold
	 * that type.
	 */
	_FORCE_INLINE_ static PackedColorArray *get_color_array(Variant *v) { return get_internal_value<PackedColorArray>(v); }
	/**
	 * Returns a read-only pointer to the stored \`godot::PackedColorArray\`. The variant must already hold
	 * that type.
	 */
	_FORCE_INLINE_ static const PackedColorArray *get_color_array(const Variant *v) { return get_internal_value<PackedColorArray>(v); }
	/**
	 * Returns a writable pointer to the stored \`godot::PackedVector4Array\`. The variant must already hold
	 * that type.
	 */
	_FORCE_INLINE_ static PackedVector4Array *get_vector4_array(Variant *v) { return get_internal_value<PackedVector4Array>(v); }
	/**
	 * Returns a read-only pointer to the stored \`godot::PackedVector4Array\`. The variant must already
	 * hold that type.
	 */
	_FORCE_INLINE_ static const PackedVector4Array *get_vector4_array(const Variant *v) { return get_internal_value<PackedVector4Array>(v); }

	/**
	 * Returns a pointer to the native object-pointer slot. The variant must already store an object.
	 */
	_FORCE_INLINE_ static Object **get_object(Variant *v) { return get_internal_value<Object *>(v); }
	/**
	 * Returns a pointer to the native object-pointer slot. The variant must already store an object.
	 */
	_FORCE_INLINE_ static const Object **get_object(const Variant *v) { return (const Object **)get_internal_value<Object *>(v); }

	/**
	 * Selects the native storage pointer based on the variant's current type. Returns null for nil.
	 */
	_FORCE_INLINE_ static void *get_opaque_pointer(Variant *v) {
		switch (v->get_type()) {
			case Variant::NIL:
				return nullptr;
			case Variant::BOOL:
				return get_bool(v);
			case Variant::INT:
				return get_int(v);
			case Variant::FLOAT:
				return get_float(v);
			case Variant::STRING:
				return get_string(v);
			case Variant::VECTOR2:
				return get_vector2(v);
			case Variant::VECTOR2I:
				return get_vector2i(v);
			case Variant::VECTOR3:
				return get_vector3(v);
			case Variant::VECTOR3I:
				return get_vector3i(v);
			case Variant::VECTOR4:
				return get_vector4(v);
			case Variant::VECTOR4I:
				return get_vector4i(v);
			case Variant::RECT2:
				return get_rect2(v);
			case Variant::RECT2I:
				return get_rect2i(v);
			case Variant::TRANSFORM3D:
				return get_transform(v);
			case Variant::PROJECTION:
				return get_projection(v);
			case Variant::TRANSFORM2D:
				return get_transform2d(v);
			case Variant::QUATERNION:
				return get_quaternion(v);
			case Variant::PLANE:
				return get_plane(v);
			case Variant::BASIS:
				return get_basis(v);
			case Variant::AABB:
				return get_aabb(v);
			case Variant::COLOR:
				return get_color(v);
			case Variant::STRING_NAME:
				return get_string_name(v);
			case Variant::NODE_PATH:
				return get_node_path(v);
			case Variant::RID:
				return get_rid(v);
			case Variant::CALLABLE:
				return get_callable(v);
			case Variant::SIGNAL:
				return get_signal(v);
			case Variant::DICTIONARY:
				return get_dictionary(v);
			case Variant::ARRAY:
				return get_array(v);
			case Variant::PACKED_BYTE_ARRAY:
				return get_byte_array(v);
			case Variant::PACKED_INT32_ARRAY:
				return get_int32_array(v);
			case Variant::PACKED_INT64_ARRAY:
				return get_int64_array(v);
			case Variant::PACKED_FLOAT32_ARRAY:
				return get_float32_array(v);
			case Variant::PACKED_FLOAT64_ARRAY:
				return get_float64_array(v);
			case Variant::PACKED_STRING_ARRAY:
				return get_string_array(v);
			case Variant::PACKED_VECTOR2_ARRAY:
				return get_vector2_array(v);
			case Variant::PACKED_VECTOR3_ARRAY:
				return get_vector3_array(v);
			case Variant::PACKED_COLOR_ARRAY:
				return get_color_array(v);
			case Variant::PACKED_VECTOR4_ARRAY:
				return get_vector4_array(v);
			case Variant::OBJECT:
				return get_object(v);
			case Variant::VARIANT_MAX:
				ERR_FAIL_V(nullptr);
		}
		ERR_FAIL_V(nullptr);
	}

	/**
	 * Selects the native storage pointer based on the variant's current type. Returns null for nil.
	 */
	_FORCE_INLINE_ static const void *get_opaque_pointer(const Variant *v) {
		switch (v->get_type()) {
			case Variant::NIL:
				return nullptr;
			case Variant::BOOL:
				return get_bool(v);
			case Variant::INT:
				return get_int(v);
			case Variant::FLOAT:
				return get_float(v);
			case Variant::STRING:
				return get_string(v);
			case Variant::VECTOR2:
				return get_vector2(v);
			case Variant::VECTOR2I:
				return get_vector2i(v);
			case Variant::VECTOR3:
				return get_vector3(v);
			case Variant::VECTOR3I:
				return get_vector3i(v);
			case Variant::VECTOR4:
				return get_vector4(v);
			case Variant::VECTOR4I:
				return get_vector4i(v);
			case Variant::RECT2:
				return get_rect2(v);
			case Variant::RECT2I:
				return get_rect2i(v);
			case Variant::TRANSFORM3D:
				return get_transform(v);
			case Variant::PROJECTION:
				return get_projection(v);
			case Variant::TRANSFORM2D:
				return get_transform2d(v);
			case Variant::QUATERNION:
				return get_quaternion(v);
			case Variant::PLANE:
				return get_plane(v);
			case Variant::BASIS:
				return get_basis(v);
			case Variant::AABB:
				return get_aabb(v);
			case Variant::COLOR:
				return get_color(v);
			case Variant::STRING_NAME:
				return get_string_name(v);
			case Variant::NODE_PATH:
				return get_node_path(v);
			case Variant::RID:
				return get_rid(v);
			case Variant::CALLABLE:
				return get_callable(v);
			case Variant::SIGNAL:
				return get_signal(v);
			case Variant::DICTIONARY:
				return get_dictionary(v);
			case Variant::ARRAY:
				return get_array(v);
			case Variant::PACKED_BYTE_ARRAY:
				return get_byte_array(v);
			case Variant::PACKED_INT32_ARRAY:
				return get_int32_array(v);
			case Variant::PACKED_INT64_ARRAY:
				return get_int64_array(v);
			case Variant::PACKED_FLOAT32_ARRAY:
				return get_float32_array(v);
			case Variant::PACKED_FLOAT64_ARRAY:
				return get_float64_array(v);
			case Variant::PACKED_STRING_ARRAY:
				return get_string_array(v);
			case Variant::PACKED_VECTOR2_ARRAY:
				return get_vector2_array(v);
			case Variant::PACKED_VECTOR3_ARRAY:
				return get_vector3_array(v);
			case Variant::PACKED_COLOR_ARRAY:
				return get_color_array(v);
			case Variant::PACKED_VECTOR4_ARRAY:
				return get_vector4_array(v);
			case Variant::OBJECT:
				return get_object(v);
			case Variant::VARIANT_MAX:
				ERR_FAIL_V(nullptr);
		}
		ERR_FAIL_V(nullptr);
	}
};

/**
 * Forwards a typed variant-storage pointer request to `godot::VariantInternal::get_internal_value()`.
 */
template <typename T>
struct VariantGetInternalPtr {
	/**
	 * Forwards the request for a pointer to the variant's existing native value of type `T`.
	 */
	static ::godot::internal::VariantInternalType<T> *get_ptr(Variant *v) { return VariantInternal::get_internal_value<T>(v); }
	/**
	 * Forwards the request for a pointer to the variant's existing native value of type `T`.
	 */
	static const ::godot::internal::VariantInternalType<T> *get_ptr(const Variant *v) { return VariantInternal::get_internal_value<T>(v); }
};

/**
 * Controls whether direct assignment to the stored value is enabled. Object pointer storage has a
 * disabled specialization.
 */
template <typename T>
struct can_set_variant_internal_value {
	static const bool value = true;
};

/**
 * Controls whether direct assignment to the stored value is enabled. Object pointer storage has a
 * disabled specialization.
 */
template <>
struct can_set_variant_internal_value<Object *> {
	static const bool value = false;
};

/**
 * Reads or assigns an existing native variant value of type `T` through its storage pointer.
 */
template <typename T>
struct VariantInternalAccessor {
	static _FORCE_INLINE_ const T &get(const Variant *v) { return *VariantInternal::get_internal_value<T>(v); }

	// Enable set() only for those types where we can set (all but Object *).
	/**
	 * Assigns the supplied value to the variant's existing storage when storage assignment for the type is
	 * enabled.
	 */
	template <typename U = T, typename = std::enable_if_t<can_set_variant_internal_value<U>::value>>
	static _FORCE_INLINE_ void set(Variant *v, const ::godot::internal::VariantInternalType<U> &p_value) {
		*VariantInternal::get_internal_value<U>(v) = p_value;
	}
};

/**
 * Assigns the default-constructed value to a variant's existing storage of type `T`. Uses the
 * storage-assignment trait to exclude object pointers.
 */
template <typename T, std::enable_if_t<can_set_variant_internal_value<T>::value>>
struct VariantDefaultInitializer {
	/**
	 * Assigns a default-constructed `T` to the variant's existing storage of that type.
	 */
	static _FORCE_INLINE_ void init(Variant *v) { *VariantInternal::get_internal_value<T>(v) = T(); }
};

} // namespace godot

#endif // GODOT_VERSION_MINOR >= 4
