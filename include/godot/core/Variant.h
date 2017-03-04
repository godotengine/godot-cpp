#ifndef VARIANT_H
#define VARIANT_H

#include <godot/godot_variant.h>

#include "Defs.h"

#include "Basis.h"
#include "Color.h"
#include "Image.h"
#include "InputEvent.h"
#include "NodePath.h"
#include "Plane.h"
#include "PoolArrays.h"
#include "Quat.h"
#include "Rect2.h"
#include "Rect3.h"
#include "RID.h"
#include "String.h"
#include "Transform.h"
#include "Transform2D.h"
#include "Vector2.h"
#include "Vector3.h"

#include <iostream>

namespace godot {

class Dictionary;

class Array;

class Variant {
	godot_variant _godot_variant;
public:
	enum Type {

		NIL,

		// atomic types
		BOOL,
		INT,
		REAL,
		STRING,

		// math types

		VECTOR2,		// 5
		RECT2,
		VECTOR3,
		TRANSFORM2D,
		PLANE,
		QUAT,			// 10
		RECT3, //sorry naming convention fail :( not like it's used often
		BASIS,
		TRANSFORM,

		// misc types
		COLOR,
		IMAGE,			// 15
		NODE_PATH,
		_RID,
		OBJECT,
		INPUT_EVENT,
		DICTIONARY,		// 20
		ARRAY,

		// arrays
		POOL_BYTE_ARRAY,
		POOL_INT_ARRAY,
		POOL_REAL_ARRAY,
		POOL_STRING_ARRAY,	// 25
		POOL_VECTOR2_ARRAY,
		POOL_VECTOR3_ARRAY,
		POOL_COLOR_ARRAY,

		VARIANT_MAX

	};

	Variant()
	{
		godot_variant_new_nil(&_godot_variant);
	}

	Variant(const Variant& v)
	{
		godot_variant_copy(&_godot_variant, &v._godot_variant);
	}

	Variant(bool p_bool)
	{
		godot_variant_new_bool(&_godot_variant, p_bool);
	}

	Variant(signed int p_int) // real one
	{
		godot_variant_new_int(&_godot_variant, p_int);
	}

	Variant(unsigned int p_int)
	{
		godot_variant_new_int(&_godot_variant, p_int);
	}

	Variant(signed short p_short) // real one
	{
		godot_variant_new_int(&_godot_variant, (int) p_short);
	}

	Variant(unsigned short p_short) : Variant((unsigned int) p_short) {}

	Variant(signed char p_char) : Variant((signed int) p_char) {}// real one

	Variant(unsigned char p_char) : Variant((unsigned int) p_char) {}
	Variant(int64_t p_char) // real one
	{
		godot_variant_new_int(&_godot_variant, p_char);
	}

	Variant(uint64_t p_char)
	{
		godot_variant_new_int(&_godot_variant, p_char);
	}

	Variant(float p_float)
	{
		godot_variant_new_real(&_godot_variant, p_float);
	}

	Variant(double p_double)
	{
		godot_variant_new_real(&_godot_variant, p_double);
	}

	Variant(const String& p_string)
	{
		godot_variant_new_string(&_godot_variant, (godot_string *) &p_string);
	}

	Variant(const char * const p_cstring)
	{
		String s = String(p_cstring);
		godot_variant_new_string(&_godot_variant, (godot_string *) &s);
	}

	Variant(const wchar_t * p_wstring)
	{
		String s = p_wstring;
		godot_variant_new_string(&_godot_variant, (godot_string *) &s);
	}

	Variant(const Vector2& p_vector2)
	{
		godot_variant_new_vector2(&_godot_variant, (godot_vector2 *) &p_vector2);
	}

	Variant(const Rect2& p_rect2)
	{
		godot_variant_new_rect2(&_godot_variant, (godot_rect2 *) &p_rect2);
	}

	Variant(const Vector3& p_vector3)
	{
		godot_variant_new_vector3(&_godot_variant, (godot_vector3 *) &p_vector3);
	}

	Variant(const Plane& p_plane)
	{
		godot_variant_new_plane(&_godot_variant, (godot_plane *) &p_plane);
	}


	Variant(const Rect3& p_aabb)
	{
		godot_variant_new_rect3(&_godot_variant, (godot_rect3 *) &p_aabb);
	}

	Variant(const Quat& p_quat)
	{
		godot_variant_new_quat(&_godot_variant, (godot_quat *) &p_quat);
	}

	Variant(const Basis& p_transform)
	{
		godot_variant_new_basis(&_godot_variant, (godot_basis *) &p_transform);
	}

	Variant(const Transform2D& p_transform)
	{
		godot_variant_new_transform2d(&_godot_variant, (godot_transform2d *) &p_transform);
	}

	Variant(const Transform& p_transform)
	{
		godot_variant_new_transform(&_godot_variant, (godot_transform *) &p_transform);
	}

	Variant(const Color& p_color)
	{
		godot_variant_new_color(&_godot_variant, (godot_color *) &p_color);
	}

	Variant(const Image& p_image)
	{
		godot_variant_new_image(&_godot_variant, (godot_image *) &p_image);
	}

	Variant(const NodePath& p_path)
	{
		godot_variant_new_node_path(&_godot_variant, (godot_node_path *) &p_path);
	}

	Variant(const RID& p_rid)
	{
		godot_variant_new_rid(&_godot_variant, (godot_rid *) &p_rid);
	}

	Variant(const Object* p_object)
	{
		godot_variant_new_object(&_godot_variant, (godot_object *) p_object);
	}

	Variant(const InputEvent& p_input_event)
	{
		godot_variant_new_input_event(&_godot_variant, (godot_input_event *) &p_input_event);
	}

	Variant(const Dictionary& p_dictionary)
	{
		godot_variant_new_dictionary(&_godot_variant, (godot_dictionary *) &p_dictionary);
	}

	Variant(const Array& p_array)
	{
		godot_variant_new_array(&_godot_variant, (godot_array *) &p_array);
	}

	Variant(const PoolByteArray& p_raw_array)
	{
		godot_variant_new_pool_byte_array(&_godot_variant, (godot_pool_byte_array *) &p_raw_array);
	}

	Variant(const PoolIntArray& p_int_array)
	{
		godot_variant_new_pool_int_array(&_godot_variant, (godot_pool_int_array *) &p_int_array);
	}

	Variant(const PoolRealArray& p_real_array)
	{
		godot_variant_new_pool_real_array(&_godot_variant, (godot_pool_real_array *) &p_real_array);
	}

	Variant(const PoolStringArray& p_string_array)
	{
		godot_variant_new_pool_string_array(&_godot_variant, (godot_pool_string_array *) &p_string_array);
	}

	Variant(const PoolVector2Array& p_vector2_array)
	{
		godot_variant_new_pool_vector2_array(&_godot_variant, (godot_pool_vector2_array *) &p_vector2_array);
	}

	Variant(const PoolVector3Array& p_vector3_array)
	{
		godot_variant_new_pool_vector3_array(&_godot_variant, (godot_pool_vector3_array *) &p_vector3_array);
	}

	Variant(const PoolColorArray& p_color_array)
	{
		godot_variant_new_pool_color_array(&_godot_variant, (godot_pool_color_array *) &p_color_array);
	}


	Variant &operator =(const Variant& v)
	{
		godot_variant_copy(&_godot_variant, &v._godot_variant);
		return *this;
	}


	operator bool() const
	{
		bool valid = false;
		bool result = booleanize(valid);
		return valid && result;
	}
	operator signed int() const
	{
		return godot_variant_as_int(&_godot_variant);
	}
	operator unsigned int() const // this is the real one
	{
		return godot_variant_as_int(&_godot_variant);
	}
	operator signed short() const
	{
		return godot_variant_as_int(&_godot_variant);
	}
	operator unsigned short() const
	{
		return godot_variant_as_int(&_godot_variant);
	}
	operator signed char() const
	{
		return godot_variant_as_int(&_godot_variant);
	}
	operator unsigned char() const
	{
		return godot_variant_as_int(&_godot_variant);
	}
	operator int64_t() const
	{
		return godot_variant_as_int(&_godot_variant);
	}
	operator uint64_t() const
	{
		return godot_variant_as_int(&_godot_variant);
	}


	operator wchar_t() const
	{
		return godot_variant_as_int(&_godot_variant);
	}

	operator float() const
	{
		return godot_variant_as_real(&_godot_variant);
	}

	operator double() const
	{
		return godot_variant_as_real(&_godot_variant);
	}
	operator String() const
	{
		godot_string s = godot_variant_as_string(&_godot_variant);
		return *(String *) &s;
	}
	operator Vector2() const
	{
		godot_vector2 s = godot_variant_as_vector2(&_godot_variant);
		return *(Vector2 *) &s;
	}
	operator Rect2() const
	{
		godot_rect2 s = godot_variant_as_rect2(&_godot_variant);
		return *(Rect2 *) &s;
	}
	operator Vector3() const
	{
		godot_vector3 s = godot_variant_as_vector3(&_godot_variant);
		return *(Vector3 *) &s;
	}
	operator Plane() const
	{
		godot_plane s = godot_variant_as_plane(&_godot_variant);
		return *(Plane *) &s;
	}
	operator Rect3() const
	{
		godot_rect3 s = godot_variant_as_rect3(&_godot_variant);
		return *(Rect3 *) &s;
	}
	operator Quat() const
	{
		godot_quat s = godot_variant_as_quat(&_godot_variant);
		return *(Quat *) &s;
	}
	operator Basis() const
	{
		godot_basis s = godot_variant_as_basis(&_godot_variant);
		return *(Basis *) &s;
	}
	operator Transform() const
	{
		godot_transform s = godot_variant_as_transform(&_godot_variant);
		return *(Transform *) &s;
	}
	operator Transform2D() const
	{
		godot_transform2d s = godot_variant_as_transform2d(&_godot_variant);
		return *(Transform2D *) &s;
	}

	operator Color() const
	{
		godot_color s = godot_variant_as_color(&_godot_variant);
		return *(Color *) &s;
	}
	operator Image() const
	{
		godot_image s = godot_variant_as_image(&_godot_variant);
		return *(Image *) &s;
	}
	operator NodePath() const
	{
		godot_node_path s = godot_variant_as_node_path(&_godot_variant);
		return *(NodePath *) &s;
	}
	operator RID() const
	{
		godot_rid s = godot_variant_as_rid(&_godot_variant);
		return *(RID *) &s;
	}
	operator InputEvent() const
	{
		godot_input_event s = godot_variant_as_input_event(&_godot_variant);
		return *(InputEvent *) &s;
	}
	operator Object*() const
	{
		godot_object *s = godot_variant_as_object(&_godot_variant);
		return (Object *) s;
	}

	operator Dictionary() const;
	operator Array() const;

	operator PoolByteArray() const
	{
		godot_pool_byte_array s = godot_variant_as_pool_byte_array(&_godot_variant);
		return *(PoolByteArray *) &s;
	}
	operator PoolIntArray() const
	{
		godot_pool_int_array s = godot_variant_as_pool_int_array(&_godot_variant);
		return *(PoolIntArray *) &s;
	}
	operator PoolRealArray() const
	{
		godot_pool_real_array s = godot_variant_as_pool_real_array(&_godot_variant);
		return *(PoolRealArray *) &s;
	}
	operator PoolStringArray() const
	{
		godot_pool_string_array s = godot_variant_as_pool_string_array(&_godot_variant);
		return *(PoolStringArray *) &s;
	}
	operator PoolVector2Array() const
	{
		godot_pool_vector2_array s = godot_variant_as_pool_vector2_array(&_godot_variant);
		return *(PoolVector2Array *) &s;
	}
	operator PoolVector3Array() const
	{
		godot_pool_vector3_array s = godot_variant_as_pool_vector3_array(&_godot_variant);
		return *(PoolVector3Array *) &s;
	}
	operator PoolColorArray() const
	{
		godot_pool_color_array s = godot_variant_as_pool_color_array(&_godot_variant);
		return *(PoolColorArray *) &s;
	}

	Type get_type() const
	{
		return (Type) godot_variant_get_type(&_godot_variant);
	}


	Variant call(const String& method, const Variant **args, const int arg_count)
	{
		Variant v;
		*(godot_variant *) &v = godot_variant_call(&_godot_variant, (godot_string *) &method, (const godot_variant **)args, arg_count);
		return v;
	}

	bool has_method(const String& method)
	{
		return godot_variant_has_method(&_godot_variant, (godot_string *) &method);
	}

	bool operator ==(const Variant& b) const
	{
		return godot_variant_operator_equal(&_godot_variant, &b._godot_variant);
	}

	bool operator !=(const Variant& b) const
	{
		return !(*this == b);
	}

	bool operator <(const Variant& b) const
	{
		return godot_variant_operator_less(&_godot_variant, &b._godot_variant);
	}

	bool operator <=(const Variant& b) const
	{
		return (*this < b) || (*this == b);
	}

	bool operator >(const Variant& b) const
	{
		return !(*this <= b);
	}

	bool operator >=(const Variant& b) const
	{
		return !(*this < b);
	}

	bool hash_compare(const Variant& b) const
	{
		return godot_variant_hash_compare(&_godot_variant, &b._godot_variant);
	}

	bool booleanize(bool &valid) const
	{
		return godot_variant_booleanize(&_godot_variant, &valid);
	}

	~Variant()
	{
		godot_variant_destroy(&_godot_variant);
	}



};

}

#endif // VARIANT_H
