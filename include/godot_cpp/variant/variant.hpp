/**************************************************************************/
/*  variant.hpp                                                           */
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

#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/variant/variant_size.hpp>

#include <gdextension_interface.h>

#include <array>

namespace godot {

class ObjectID;

/**
 * Holds a Godot value whose type is determined at runtime. The wrapper manages the engine value and
 * exposes its conversions, dynamic calls, and container access.
 */
class Variant {
	/**
	 * Aligned storage for the engine's native variant value. The size comes from the selected GDExtension
	 * API configuration.
	 */
	alignas(8) uint8_t opaque[GODOT_CPP_VARIANT_SIZE]{ 0 };

	friend class GDExtensionBinding;
	friend class MethodBind;
	friend class VariantInternal;

	/**
	 * Loads the engine's variant conversion functions and initializes access to native variant values.
	 */
	static void init_bindings();

public:
	/**
	 * Identifies the value stored in a variant. The numeric values match the GDExtension variant type tags.
	 */
	enum Type {
		/**
		 * No value.
		 */
		NIL,

		// atomic types
		/**
		 * A Boolean value.
		 */
		BOOL,
		/**
		 * A signed 64-bit integer.
		 */
		INT,
		/**
		 * A double-precision floating-point value.
		 */
		FLOAT,
		/**
		 * A value of type `godot::String`.
		 */
		STRING,

		// math types
		/**
		 * A value of type `godot::Vector2`.
		 */
		VECTOR2,
		/**
		 * A value of type `godot::Vector2i`.
		 */
		VECTOR2I,
		/**
		 * A value of type `godot::Rect2`.
		 */
		RECT2,
		/**
		 * A value of type `godot::Rect2i`.
		 */
		RECT2I,
		/**
		 * A value of type `godot::Vector3`.
		 */
		VECTOR3,
		/**
		 * A value of type `godot::Vector3i`.
		 */
		VECTOR3I,
		/**
		 * A value of type `godot::Transform2D`.
		 */
		TRANSFORM2D,
		/**
		 * A value of type `godot::Vector4`.
		 */
		VECTOR4,
		/**
		 * A value of type `godot::Vector4i`.
		 */
		VECTOR4I,
		/**
		 * A value of type `godot::Plane`.
		 */
		PLANE,
		/**
		 * A value of type `godot::Quaternion`.
		 */
		QUATERNION,
		/**
		 * A value of type `godot::AABB`.
		 */
		AABB,
		/**
		 * A value of type `godot::Basis`.
		 */
		BASIS,
		/**
		 * A value of type `godot::Transform3D`.
		 */
		TRANSFORM3D,
		/**
		 * A value of type `godot::Projection`.
		 */
		PROJECTION,

		// misc types
		/**
		 * A value of type `godot::Color`.
		 */
		COLOR,
		/**
		 * A value of type `godot::StringName`.
		 */
		STRING_NAME,
		/**
		 * A value of type `godot::NodePath`.
		 */
		NODE_PATH,
		/**
		 * A value of type `godot::RID`.
		 */
		RID,
		/**
		 * A reference to a Godot object, which may be null.
		 */
		OBJECT,
		/**
		 * A value of type `godot::Callable`.
		 */
		CALLABLE,
		/**
		 * A value of type `godot::Signal`.
		 */
		SIGNAL,
		/**
		 * A value of type `godot::Dictionary`.
		 */
		DICTIONARY,
		/**
		 * A value of type `godot::Array`.
		 */
		ARRAY,

		// typed arrays
		/**
		 * A value of type `godot::PackedByteArray`.
		 */
		PACKED_BYTE_ARRAY,
		/**
		 * A value of type `godot::PackedInt32Array`.
		 */
		PACKED_INT32_ARRAY,
		/**
		 * A value of type `godot::PackedInt64Array`.
		 */
		PACKED_INT64_ARRAY,
		/**
		 * A value of type `godot::PackedFloat32Array`.
		 */
		PACKED_FLOAT32_ARRAY,
		/**
		 * A value of type `godot::PackedFloat64Array`.
		 */
		PACKED_FLOAT64_ARRAY,
		/**
		 * A value of type `godot::PackedStringArray`.
		 */
		PACKED_STRING_ARRAY,
		/**
		 * A value of type `godot::PackedVector2Array`.
		 */
		PACKED_VECTOR2_ARRAY,
		/**
		 * A value of type `godot::PackedVector3Array`.
		 */
		PACKED_VECTOR3_ARRAY,
		/**
		 * A value of type `godot::PackedColorArray`.
		 */
		PACKED_COLOR_ARRAY,
		/**
		 * A value of type `godot::PackedVector4Array`.
		 */
		PACKED_VECTOR4_ARRAY,

		/**
		 * The number of variant type tags..
		 */
		VARIANT_MAX
	};

	/**
	 * Selects an operation for `godot::Variant::evaluate()`. Operand types determine whether the operation
	 * is supported.
	 */
	enum Operator {
		// comparison
		/**
		 * Evaluates equality for supported operands.
		 */
		OP_EQUAL,
		/**
		 * Evaluates inequality for supported operands.
		 */
		OP_NOT_EQUAL,
		/**
		 * Evaluates less-than comparison for supported operands.
		 */
		OP_LESS,
		/**
		 * Evaluates less-than-or-equal comparison for supported operands.
		 */
		OP_LESS_EQUAL,
		/**
		 * Evaluates greater-than comparison for supported operands.
		 */
		OP_GREATER,
		/**
		 * Evaluates greater-than-or-equal comparison for supported operands.
		 */
		OP_GREATER_EQUAL,
		// mathematic
		/**
		 * Evaluates addition for supported operands.
		 */
		OP_ADD,
		/**
		 * Evaluates subtraction for supported operands.
		 */
		OP_SUBTRACT,
		/**
		 * Evaluates multiplication for supported operands.
		 */
		OP_MULTIPLY,
		/**
		 * Evaluates division for supported operands.
		 */
		OP_DIVIDE,
		/**
		 * Evaluates unary negation for supported operands.
		 */
		OP_NEGATE,
		/**
		 * Evaluates unary plus for supported operands.
		 */
		OP_POSITIVE,
		/**
		 * Evaluates remainder for supported operands.
		 */
		OP_MODULE,
		/**
		 * Evaluates exponentiation for supported operands.
		 */
		OP_POWER,
		// bitwise
		/**
		 * Evaluates left bit shift for supported operands.
		 */
		OP_SHIFT_LEFT,
		/**
		 * Evaluates right bit shift for supported operands.
		 */
		OP_SHIFT_RIGHT,
		/**
		 * Evaluates bitwise AND for supported operands.
		 */
		OP_BIT_AND,
		/**
		 * Evaluates bitwise OR for supported operands.
		 */
		OP_BIT_OR,
		/**
		 * Evaluates bitwise XOR for supported operands.
		 */
		OP_BIT_XOR,
		/**
		 * Evaluates bitwise complement for supported operands.
		 */
		OP_BIT_NEGATE,
		// logic
		/**
		 * Evaluates logical AND for supported operands.
		 */
		OP_AND,
		/**
		 * Evaluates logical OR for supported operands.
		 */
		OP_OR,
		/**
		 * Evaluates logical XOR for supported operands.
		 */
		OP_XOR,
		/**
		 * Evaluates logical negation for supported operands.
		 */
		OP_NOT,
		// containment
		/**
		 * Evaluates membership of the left operand in the right operand for supported operands.
		 */
		OP_IN,
		/**
		 * The number of operator tags. Used as an upper bound when indexing operator tables.
		 */
		OP_MAX
	};

private:
	/**
	 * Table of engine functions that construct a native variant from a specific value type. Indexed by the
	 * variant type tag.
	 */
	static GDExtensionVariantFromTypeConstructorFunc from_type_constructor[VARIANT_MAX];
	/**
	 * Table of engine functions that extract a value of a requested type from a native variant. Indexed by
	 * the destination type tag.
	 */
	static GDExtensionTypeFromVariantConstructorFunc to_type_constructor[VARIANT_MAX];

public:
	/**
	 * Returns the address of the native variant value for calls through the GDExtension interface. The
	 * address belongs to this wrapper.
	 */
	_FORCE_INLINE_ GDExtensionVariantPtr _native_ptr() const { return const_cast<uint8_t (*)[GODOT_CPP_VARIANT_SIZE]>(&opaque); }
	/**
	 * Creates a nil variant.
	 */
	Variant();
	/**
	 * Creates a nil variant.
	 */
	Variant(std::nullptr_t n) :
			Variant() {}
	/**
	 * Copies the initialized native variant at the supplied GDExtension pointer.
	 */
	explicit Variant(GDExtensionConstVariantPtr native_ptr);
	/**
	 * Copies the engine value from the other variant. Reference-backed values retain their shared backing.
	 */
	Variant(const Variant &other);
	/**
	 * Transfers the native value from the other variant and leaves the source nil.
	 */
	Variant(Variant &&other);
	/**
	 * Stores a Boolean as a variant.
	 */
	Variant(bool v);
	/**
	 * Stores the input as a signed 64-bit variant integer.
	 */
	Variant(int64_t v);
	/**
	 * Stores the input as a signed 64-bit variant integer.
	 */
	Variant(int32_t v) :
			Variant(static_cast<int64_t>(v)) {}
	/**
	 * Stores the input as a signed 64-bit variant integer.
	 */
	Variant(int16_t v) :
			Variant(static_cast<int64_t>(v)) {}
	/**
	 * Stores the input as a signed 64-bit variant integer.
	 */
	Variant(int8_t v) :
			Variant(static_cast<int64_t>(v)) {}
	/**
	 * Stores the input as a signed 64-bit variant integer.
	 */
	Variant(uint64_t v) :
			Variant(static_cast<int64_t>(v)) {}
	/**
	 * Stores the input as a signed 64-bit variant integer.
	 */
	Variant(uint32_t v) :
			Variant(static_cast<int64_t>(v)) {}
	/**
	 * Stores the input as a signed 64-bit variant integer.
	 */
	Variant(uint16_t v) :
			Variant(static_cast<int64_t>(v)) {}
	/**
	 * Stores the input as a signed 64-bit variant integer.
	 */
	Variant(uint8_t v) :
			Variant(static_cast<int64_t>(v)) {}
	/**
	 * Stores the input as a double-precision variant float.
	 */
	Variant(double v);
	/**
	 * Stores the input as a double-precision variant float.
	 */
	Variant(float v) :
			Variant((double)v) {}
	/**
	 * Wraps the supplied value as a \`godot::String\` variant.
	 */
	Variant(const String &v);
	/**
	 * Constructs and stores a Godot string from the supplied null-terminated character sequence.
	 */
	Variant(const char *v) :
			Variant(String(v)) {}
	/**
	 * Constructs and stores a Godot string from the supplied null-terminated character sequence.
	 */
	Variant(const char16_t *v) :
			Variant(String(v)) {}
	/**
	 * Constructs and stores a Godot string from the supplied null-terminated character sequence.
	 */
	Variant(const char32_t *v) :
			Variant(String(v)) {}
	/**
	 * Constructs and stores a Godot string from the supplied null-terminated character sequence.
	 */
	Variant(const wchar_t *v) :
			Variant(String(v)) {}
	/**
	 * Wraps the supplied value as a \`godot::Vector2\` variant.
	 */
	Variant(const Vector2 &v);
	/**
	 * Wraps the supplied value as a \`godot::Vector2i\` variant.
	 */
	Variant(const Vector2i &v);
	/**
	 * Wraps the supplied value as a \`godot::Rect2\` variant.
	 */
	Variant(const Rect2 &v);
	/**
	 * Wraps the supplied value as a \`godot::Rect2i\` variant.
	 */
	Variant(const Rect2i &v);
	/**
	 * Wraps the supplied value as a \`godot::Vector3\` variant.
	 */
	Variant(const Vector3 &v);
	/**
	 * Wraps the supplied value as a \`godot::Vector3i\` variant.
	 */
	Variant(const Vector3i &v);
	/**
	 * Wraps the supplied value as a \`godot::Transform2D\` variant.
	 */
	Variant(const Transform2D &v);
	/**
	 * Wraps the supplied value as a \`godot::Vector4\` variant.
	 */
	Variant(const Vector4 &v);
	/**
	 * Wraps the supplied value as a \`godot::Vector4i\` variant.
	 */
	Variant(const Vector4i &v);
	/**
	 * Wraps the supplied value as a \`godot::Plane\` variant.
	 */
	Variant(const Plane &v);
	/**
	 * Wraps the supplied value as a \`godot::Quaternion\` variant.
	 */
	Variant(const Quaternion &v);
	/**
	 * Wraps the supplied value as a \`godot::AABB\` variant.
	 */
	Variant(const ::godot::AABB &v);
	/**
	 * Wraps the supplied value as a \`godot::Basis\` variant.
	 */
	Variant(const Basis &v);
	/**
	 * Wraps the supplied value as a \`godot::Transform3D\` variant.
	 */
	Variant(const Transform3D &v);
	/**
	 * Wraps the supplied value as a \`godot::Projection\` variant.
	 */
	Variant(const Projection &v);
	/**
	 * Wraps the supplied value as a \`godot::Color\` variant.
	 */
	Variant(const Color &v);
	/**
	 * Wraps the supplied value as a \`godot::StringName\` variant.
	 */
	Variant(const StringName &v);
	/**
	 * Wraps the supplied value as a \`godot::NodePath\` variant.
	 */
	Variant(const NodePath &v);
	/**
	 * Wraps the supplied value as a \`godot::RID\` variant.
	 */
	Variant(const ::godot::RID &v);
	/**
	 * Stores the numeric object instance ID as a variant integer.
	 */
	Variant(const ObjectID &v);
	/**
	 * Stores the engine object behind the wrapper. A null pointer produces an object variant with no
	 * object.
	 */
	Variant(const Object *v);
	/**
	 * Wraps the supplied value as a \`godot::Callable\` variant.
	 */
	Variant(const Callable &v);
	/**
	 * Wraps the supplied value as a \`godot::Signal\` variant.
	 */
	Variant(const Signal &v);
	/**
	 * Wraps the supplied value as a \`godot::Dictionary\` variant.
	 */
	Variant(const Dictionary &v);
	/**
	 * Wraps the supplied value as a \`godot::Array\` variant.
	 */
	Variant(const Array &v);
	/**
	 * Wraps the supplied value as a \`godot::PackedByteArray\` variant.
	 */
	Variant(const PackedByteArray &v);
	/**
	 * Wraps the supplied value as a \`godot::PackedInt32Array\` variant.
	 */
	Variant(const PackedInt32Array &v);
	/**
	 * Wraps the supplied value as a \`godot::PackedInt64Array\` variant.
	 */
	Variant(const PackedInt64Array &v);
	/**
	 * Wraps the supplied value as a \`godot::PackedFloat32Array\` variant.
	 */
	Variant(const PackedFloat32Array &v);
	/**
	 * Wraps the supplied value as a \`godot::PackedFloat64Array\` variant.
	 */
	Variant(const PackedFloat64Array &v);
	/**
	 * Wraps the supplied value as a \`godot::PackedStringArray\` variant.
	 */
	Variant(const PackedStringArray &v);
	/**
	 * Wraps the supplied value as a \`godot::PackedVector2Array\` variant.
	 */
	Variant(const PackedVector2Array &v);
	/**
	 * Wraps the supplied value as a \`godot::PackedVector3Array\` variant.
	 */
	Variant(const PackedVector3Array &v);
	/**
	 * Wraps the supplied value as a \`godot::PackedColorArray\` variant.
	 */
	Variant(const PackedColorArray &v);
	/**
	 * Wraps the supplied value as a \`godot::PackedVector4Array\` variant.
	 */
	Variant(const PackedVector4Array &v);
	/**
	 * Destroys the native variant value and releases any resources it holds.
	 */
	~Variant();

	/**
	 * Converts the stored value to \`bool\` using the engine conversion.
	 */
	operator bool() const;
	/**
	 * Converts the stored value to \`int64_t\` using the engine conversion.
	 */
	operator int64_t() const;
	/**
	 * Converts through the engine integer type, then casts the result to \`int32_t\`.
	 */
	operator int32_t() const;
	/**
	 * Converts through the engine integer type, then casts the result to \`int16_t\`.
	 */
	operator int16_t() const;
	/**
	 * Converts through the engine integer type, then casts the result to \`int8_t\`.
	 */
	operator int8_t() const;
	/**
	 * Converts through the engine integer type, then casts the result to \`uint64_t\`.
	 */
	operator uint64_t() const;
	/**
	 * Converts through the engine integer type, then casts the result to \`uint32_t\`.
	 */
	operator uint32_t() const;
	/**
	 * Converts through the engine integer type, then casts the result to \`uint16_t\`.
	 */
	operator uint16_t() const;
	/**
	 * Converts through the engine integer type, then casts the result to \`uint8_t\`.
	 */
	operator uint8_t() const;
	/**
	 * Converts the stored value to \`double\` using the engine conversion.
	 */
	operator double() const;
	/**
	 * Converts through the engine double-precision float, then casts the result to \`float\`.
	 */
	operator float() const;
	/**
	 * Converts the stored value to \`godot::String\` using the engine conversion.
	 */
	operator String() const;
	/**
	 * Converts the stored value to \`godot::Vector2\` using the engine conversion.
	 */
	operator Vector2() const;
	/**
	 * Converts the stored value to \`godot::Vector2i\` using the engine conversion.
	 */
	operator Vector2i() const;
	/**
	 * Converts the stored value to \`godot::Rect2\` using the engine conversion.
	 */
	operator Rect2() const;
	/**
	 * Converts the stored value to \`godot::Rect2i\` using the engine conversion.
	 */
	operator Rect2i() const;
	/**
	 * Converts the stored value to \`godot::Vector3\` using the engine conversion.
	 */
	operator Vector3() const;
	/**
	 * Converts the stored value to \`godot::Vector3i\` using the engine conversion.
	 */
	operator Vector3i() const;
	/**
	 * Converts the stored value to \`godot::Transform2D\` using the engine conversion.
	 */
	operator Transform2D() const;
	/**
	 * Converts the stored value to \`godot::Vector4\` using the engine conversion.
	 */
	operator Vector4() const;
	/**
	 * Converts the stored value to \`godot::Vector4i\` using the engine conversion.
	 */
	operator Vector4i() const;
	/**
	 * Converts the stored value to \`godot::Plane\` using the engine conversion.
	 */
	operator Plane() const;
	/**
	 * Converts the stored value to \`godot::Quaternion\` using the engine conversion.
	 */
	operator Quaternion() const;
	/**
	 * Converts the stored value to \`godot::AABB\` using the engine conversion.
	 */
	operator ::godot::AABB() const;
	/**
	 * Converts the stored value to \`godot::Basis\` using the engine conversion.
	 */
	operator Basis() const;
	/**
	 * Converts the stored value to \`godot::Transform3D\` using the engine conversion.
	 */
	operator Transform3D() const;
	/**
	 * Converts the stored value to \`godot::Projection\` using the engine conversion.
	 */
	operator Projection() const;
	/**
	 * Converts the stored value to \`godot::Color\` using the engine conversion.
	 */
	operator Color() const;
	/**
	 * Converts the stored value to \`godot::StringName\` using the engine conversion.
	 */
	operator StringName() const;
	/**
	 * Converts the stored value to \`godot::NodePath\` using the engine conversion.
	 */
	operator NodePath() const;
	/**
	 * Converts the stored value to \`godot::RID\` using the engine conversion.
	 */
	operator ::godot::RID() const;
	/**
	 * Returns the stored object instance ID or the numeric value converted to an instance ID.
	 */
	operator ObjectID() const;
	/**
	 * Converts the native object handle to the C++ object binding. Returns null if there is no object
	 * handle.
	 */
	operator Object *() const;
	/**
	 * Converts the stored value to \`godot::Callable\` using the engine conversion.
	 */
	operator Callable() const;
	/**
	 * Converts the stored value to \`godot::Signal\` using the engine conversion.
	 */
	operator Signal() const;
	/**
	 * Converts the stored value to \`godot::Dictionary\` using the engine conversion.
	 */
	operator Dictionary() const;
	/**
	 * Converts the stored value to \`godot::Array\` using the engine conversion.
	 */
	operator Array() const;
	/**
	 * Converts the stored value to \`godot::PackedByteArray\` using the engine conversion.
	 */
	operator PackedByteArray() const;
	/**
	 * Converts the stored value to \`godot::PackedInt32Array\` using the engine conversion.
	 */
	operator PackedInt32Array() const;
	/**
	 * Converts the stored value to \`godot::PackedInt64Array\` using the engine conversion.
	 */
	operator PackedInt64Array() const;
	/**
	 * Converts the stored value to \`godot::PackedFloat32Array\` using the engine conversion.
	 */
	operator PackedFloat32Array() const;
	/**
	 * Converts the stored value to \`godot::PackedFloat64Array\` using the engine conversion.
	 */
	operator PackedFloat64Array() const;
	/**
	 * Converts the stored value to \`godot::PackedStringArray\` using the engine conversion.
	 */
	operator PackedStringArray() const;
	/**
	 * Converts the stored value to \`godot::PackedVector2Array\` using the engine conversion.
	 */
	operator PackedVector2Array() const;
	/**
	 * Converts the stored value to \`godot::PackedVector3Array\` using the engine conversion.
	 */
	operator PackedVector3Array() const;
	/**
	 * Converts the stored value to \`godot::PackedColorArray\` using the engine conversion.
	 */
	operator PackedColorArray() const;
	/**
	 * Converts the stored value to \`godot::PackedVector4Array\` using the engine conversion.
	 */
	operator PackedVector4Array() const;

	/**
	 * Returns the binding for the contained object if the engine still recognizes it as valid. Returns null
	 * for non-object values or invalid objects.
	 */
	Object *get_validated_object() const;

	/**
	 * Replaces the native value with an engine copy of the other variant.
	 */
	Variant &operator=(const Variant &other);
	/**
	 * Swaps native values with the source variant.
	 */
	Variant &operator=(Variant &&other);
	/**
	 * Tests equality using the engine equality operator after requiring matching type tags.
	 */
	bool operator==(const Variant &other) const;
	/**
	 * Returns true for differing type tags. For matching tags, uses the engine inequality operator.
	 */
	bool operator!=(const Variant &other) const;
	/**
	 * Orders differing types by their type tags. For matching types, uses the engine less-than operator.
	 */
	bool operator<(const Variant &other) const;

	/**
	 * Invokes the named method on the variant's value. Writes the return value and call status to the two
	 * output arguments.
	 */
	void callp(const StringName &method, const Variant **args, int argcount, Variant &r_ret, GDExtensionCallError &r_error);

	/**
	 * Converts the supplied arguments to variants and invokes the named instance method. Returns the method
	 * result and discards the separate engine call status.
	 */
	template <typename... Args>
	Variant call(const StringName &method, Args... args) {
		std::array<Variant, sizeof...(args)> vargs = { args... };
		std::array<const Variant *, sizeof...(args)> argptrs;
		for (size_t i = 0; i < vargs.size(); i++) {
			argptrs[i] = &vargs[i];
		}
		Variant result;
		GDExtensionCallError error;
		callp(method, argptrs.data(), argptrs.size(), result, error);
		return result;
	}

	/**
	 * Invokes a static method on the given variant type. Writes the return value and call status to the two
	 * output arguments.
	 */
	static void callp_static(Variant::Type type, const StringName &method, const Variant **args, int argcount, Variant &r_ret, GDExtensionCallError &r_error);

	/**
	 * Converts the supplied arguments to variants and invokes a static method on the given variant type.
	 * Returns the method result and discards the separate engine call status.
	 */
	template <typename... Args>
	static Variant call_static(Variant::Type type, const StringName &method, Args... args) {
		std::array<Variant, sizeof...(args)> vargs = { args... };
		std::array<const Variant *, sizeof...(args)> argptrs;
		for (size_t i = 0; i < vargs.size(); i++) {
			argptrs[i] = &vargs[i];
		}
		Variant result;
		GDExtensionCallError error;
		callp_static(type, method, argptrs.data(), argptrs.size(), result, error);
		return result;
	}

	/**
	 * Evaluates an operation with engine variant semantics. Writes the result and reports whether the
	 * operand types support the operation.
	 */
	static void evaluate(const Operator &op, const Variant &a, const Variant &b, Variant &r_ret, bool &r_valid);

	/**
	 * Assigns a value at the given key, using the access rules of the stored type. If supplied, the
	 * validity output reports whether the assignment succeeded.
	 */
	void set(const Variant &key, const Variant &value, bool *r_valid = nullptr);
	/**
	 * Sets a named member of the stored value and reports whether the assignment succeeded.
	 */
	void set_named(const StringName &name, const Variant &value, bool &r_valid);
	/**
	 * Sets the value at the integer index. Reports access validity and whether the index is out of bounds
	 * separately.
	 */
	void set_indexed(int64_t index, const Variant &value, bool &r_valid, bool &r_oob);
	/**
	 * Assigns an entry through the stored type's keyed interface and reports whether the assignment
	 * succeeded.
	 */
	void set_keyed(const Variant &key, const Variant &value, bool &r_valid);
	/**
	 * Reads a value at the given key, using the access rules of the stored type. If supplied, the validity
	 * output reports whether access succeeded.
	 */
	Variant get(const Variant &key, bool *r_valid = nullptr) const;
	/**
	 * Reads a named member of the stored value and reports whether access succeeded.
	 */
	Variant get_named(const StringName &name, bool &r_valid) const;
	/**
	 * Reads the value at the integer index. Reports access validity and whether the index is out of bounds
	 * separately.
	 */
	Variant get_indexed(int64_t index, bool &r_valid, bool &r_oob) const;
	/**
	 * Reads an entry through the stored type's keyed interface and reports whether access succeeded.
	 */
	Variant get_keyed(const Variant &key, bool &r_valid) const;
	/**
	 * Tests membership of the supplied value in the stored value using the engine's containment operator.
	 * The optional flag reports whether the operation is supported.
	 */
	bool in(const Variant &index, bool *r_valid = nullptr) const;

	/**
	 * Initializes the engine's iteration state for this value. Returns whether iteration has a first item
	 * and separately reports whether iteration is supported.
	 */
	bool iter_init(Variant &r_iter, bool &r_valid) const;
	/**
	 * Advances an initialized iteration state. Returns whether an item is available and separately reports
	 * whether the state is valid.
	 */
	bool iter_next(Variant &r_iter, bool &r_valid) const;
	/**
	 * Reads the current item for an initialized iteration state and reports whether the state is valid.
	 */
	Variant iter_get(const Variant &r_iter, bool &r_valid) const;

	/**
	 * Returns the runtime type tag of the stored value.
	 */
	Variant::Type get_type() const;
	/**
	 * Tests whether the stored value has a method with the given name.
	 */
	bool has_method(const StringName &method) const;
	/**
	 * Tests whether a value accessible by key contains the given key. The optional output reports whether
	 * the stored value supports this query.
	 */
	bool has_key(const Variant &key, bool *r_valid = nullptr) const;
	/**
	 * Tests whether the built-in type defines the named member.
	 */
	static bool has_member(Variant::Type type, const StringName &member);

	/**
	 * Returns the engine's hash for the stored value.
	 */
	uint32_t hash() const;
	/**
	 * Returns the engine's hash for the value using the supplied starting recursion depth for nested
	 * containers.
	 */
	uint32_t recursive_hash(int recursion_count) const;
	/**
	 * Tests equality using the engine's hash-key comparison rules.
	 */
	bool hash_compare(const Variant &variant) const;
	/**
	 * Evaluates the value as a Boolean using the engine's truth-value rules.
	 */
	bool booleanize() const;
	/**
	 * Returns the engine's text representation of the stored value.
	 */
	String stringify() const;
	/**
	 * Duplicates an array or dictionary. A deep copy duplicates nested arrays and dictionaries. Other
	 * variant types are copied as values.
	 */
	Variant duplicate(bool deep = false) const;

	/**
	 * Returns the engine's name for the given variant type tag.
	 */
	static String get_type_name(Variant::Type type);
#if GODOT_VERSION_MINOR >= 7
	/**
	 * Returns the type tag for the given engine type name, or `godot::Variant::NIL` if no type matches.
	 */
	static Variant::Type get_type_by_name(const String &p_name);
#endif
	/**
	 * Tests whether the engine supports conversion between the supplied type tags.
	 */
	static bool can_convert(Variant::Type from, Variant::Type to);
	/**
	 * Tests whether the engine permits a strict conversion between the supplied type tags.
	 */
	static bool can_convert_strict(Variant::Type from, Variant::Type to);

	/**
	 * Destroys the current native value and initializes the variant to nil.
	 */
	void clear();
};

struct VariantHasher {
	/**
	 * Returns the supplied variant's engine hash.
	 */
	static _FORCE_INLINE_ uint32_t hash(const Variant &p_variant) { return p_variant.hash(); }
};

struct VariantComparator {
	/**
	 * Tests whether both variants compare equal under the engine's hash-key rules.
	 */
	static _FORCE_INLINE_ bool compare(const Variant &p_lhs, const Variant &p_rhs) { return p_lhs.hash_compare(p_rhs); }
};

template <typename... VarArgs>
String vformat(const String &p_text, const VarArgs... p_args) {
	Variant args[sizeof...(p_args) + 1] = { p_args..., Variant() }; // +1 makes sure zero sized arrays are also supported.
	Array args_array;
	args_array.resize(sizeof...(p_args));
	for (uint32_t i = 0; i < sizeof...(p_args); i++) {
		args_array[i] = args[i];
	}

	return p_text % args_array;
}

Variant &Array::Iterator::operator*() const {
	return *elem_ptr;
}

Variant *Array::Iterator::operator->() const {
	return elem_ptr;
}

Array::Iterator &Array::Iterator::operator++() {
	elem_ptr++;
	return *this;
}

Array::Iterator &Array::Iterator::operator--() {
	elem_ptr--;
	return *this;
}

const Variant &Array::ConstIterator::operator*() const {
	return *elem_ptr;
}

const Variant *Array::ConstIterator::operator->() const {
	return elem_ptr;
}

Array::ConstIterator &Array::ConstIterator::operator++() {
	elem_ptr++;
	return *this;
}

Array::ConstIterator &Array::ConstIterator::operator--() {
	elem_ptr--;
	return *this;
}

Array::Iterator Array::begin() {
	return Array::Iterator(ptrw());
}
Array::Iterator Array::end() {
	return Array::Iterator(ptrw() + size());
}

Array::ConstIterator Array::begin() const {
	return Array::ConstIterator(ptr());
}
Array::ConstIterator Array::end() const {
	return Array::ConstIterator(ptr() + size());
}

Array::Array(std::initializer_list<Variant> p_init) :
		Array() {
	ERR_FAIL_COND(resize(p_init.size()) != 0);
	Variant *variant_ptr = ptrw();

	size_t i = 0;
	for (const Variant &element : p_init) {
		variant_ptr[i++] = element;
	}
}

#include <godot_cpp/variant/builtin_vararg_methods.hpp>

#ifdef REAL_T_IS_DOUBLE
using PackedRealArray = PackedFloat64Array;
#else
using PackedRealArray = PackedFloat32Array;
#endif // REAL_T_IS_DOUBLE

} // namespace godot
