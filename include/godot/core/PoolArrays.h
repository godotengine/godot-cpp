#ifndef POOLARRAYS_H
#define POOLARRAYS_H

#include "Defs.h"

#include "String.h"
#include "Color.h"
#include "Vector2.h"
#include "Vector3.h"

#include <godot/godot_pool_arrays.h>

namespace godot {

class Array;

class PoolByteArray {
	godot_pool_byte_array _godot_array;
public:
	PoolByteArray()
	{
		godot_pool_byte_array_new(&_godot_array);
	}

	PoolByteArray(const Array& array)
	{
		godot_pool_byte_array_new_with_array(&_godot_array, (godot_array *) &array);
	}

	void append(const uint8_t data)
	{
		godot_pool_byte_array_append(&_godot_array, data);
	}

	void append_array(const PoolByteArray& array)
	{
		godot_pool_byte_array_append_array(&_godot_array, &array._godot_array);
	}

	int insert(const int idx, const uint8_t data)
	{
		return godot_pool_byte_array_insert(&_godot_array, idx, data);
	}

	void invert()
	{
		godot_pool_byte_array_invert(&_godot_array);
	}

	void push_back(const uint8_t data)
	{
		godot_pool_byte_array_push_back(&_godot_array, data);
	}

	void remove(const int idx)
	{
		godot_pool_byte_array_remove(&_godot_array, idx);
	}

	void resize(const int size)
	{
		godot_pool_byte_array_resize(&_godot_array, size);
	}

	void set(const int idx, const uint8_t data)
	{
		godot_pool_byte_array_set(&_godot_array, idx, data);
	}

	uint8_t operator [](const int idx)
	{
		return godot_pool_byte_array_get(&_godot_array, idx);
	}

	int size()
	{
		return godot_pool_byte_array_size(&_godot_array);
	}


	~PoolByteArray()
	{
		godot_pool_byte_array_destroy(&_godot_array);
	}
};


class PoolIntArray {
	godot_pool_int_array _godot_array;
public:
	PoolIntArray()
	{
		godot_pool_int_array_new(&_godot_array);
	}

	PoolIntArray(const Array& array)
	{
		godot_pool_int_array_new_with_array(&_godot_array, (godot_array *) &array);
	}

	void append(const int data)
	{
		godot_pool_int_array_append(&_godot_array, data);
	}

	void append_array(const PoolIntArray& array)
	{
		godot_pool_int_array_append_array(&_godot_array, &array._godot_array);
	}

	int insert(const int idx, const int data)
	{
		return godot_pool_int_array_insert(&_godot_array, idx, data);
	}

	void invert()
	{
		godot_pool_int_array_invert(&_godot_array);
	}

	void push_back(const int data)
	{
		godot_pool_int_array_push_back(&_godot_array, data);
	}

	void remove(const int idx)
	{
		godot_pool_int_array_remove(&_godot_array, idx);
	}

	void resize(const int size)
	{
		godot_pool_int_array_resize(&_godot_array, size);
	}

	void set(const int idx, const int data)
	{
		godot_pool_int_array_set(&_godot_array, idx, data);
	}

	int operator [](const int idx)
	{
		return godot_pool_int_array_get(&_godot_array, idx);
	}

	int size()
	{
		return godot_pool_int_array_size(&_godot_array);
	}


	~PoolIntArray()
	{
		godot_pool_int_array_destroy(&_godot_array);
	}
};


class PoolRealArray {
	godot_pool_real_array _godot_array;
public:
	PoolRealArray()
	{
		godot_pool_real_array_new(&_godot_array);
	}

	PoolRealArray(const Array& array)
	{
		godot_pool_real_array_new_with_array(&_godot_array, (godot_array *) &array);
	}

	void append(const real_t data)
	{
		godot_pool_real_array_append(&_godot_array, data);
	}

	void append_array(const PoolRealArray& array)
	{
		godot_pool_real_array_append_array(&_godot_array, &array._godot_array);
	}

	int insert(const int idx, const real_t data)
	{
		return godot_pool_real_array_insert(&_godot_array, idx, data);
	}

	void invert()
	{
		godot_pool_real_array_invert(&_godot_array);
	}

	void push_back(const real_t data)
	{
		godot_pool_real_array_push_back(&_godot_array, data);
	}

	void remove(const int idx)
	{
		godot_pool_real_array_remove(&_godot_array, idx);
	}

	void resize(const int size)
	{
		godot_pool_real_array_resize(&_godot_array, size);
	}

	void set(const int idx, const real_t data)
	{
		godot_pool_real_array_set(&_godot_array, idx, data);
	}

	real_t operator [](const int idx)
	{
		return godot_pool_real_array_get(&_godot_array, idx);
	}

	int size()
	{
		return godot_pool_real_array_size(&_godot_array);
	}


	~PoolRealArray()
	{
		godot_pool_real_array_destroy(&_godot_array);
	}
};


class PoolStringArray {
	godot_pool_string_array _godot_array;
public:
	PoolStringArray()
	{
		godot_pool_string_array_new(&_godot_array);
	}

	PoolStringArray(const Array& array)
	{
		godot_pool_string_array_new_with_array(&_godot_array, (godot_array *) &array);
	}

	void append(const String& data)
	{
		godot_pool_string_array_append(&_godot_array, (godot_string *) &data);
	}

	void append_array(const PoolStringArray& array)
	{
		godot_pool_string_array_append_array(&_godot_array, &array._godot_array);
	}

	int insert(const int idx, const String& data)
	{
		return godot_pool_string_array_insert(&_godot_array, idx, (godot_string *) &data);
	}

	void invert()
	{
		godot_pool_string_array_invert(&_godot_array);
	}

	void push_back(const String& data)
	{
		godot_pool_string_array_push_back(&_godot_array, (godot_string *) &data);
	}

	void remove(const int idx)
	{
		godot_pool_string_array_remove(&_godot_array, idx);
	}

	void resize(const int size)
	{
		godot_pool_string_array_resize(&_godot_array, size);
	}

	void set(const int idx, const String& data)
	{
		godot_pool_string_array_set(&_godot_array, idx, (godot_string *) &data);
	}

	String operator [](const int idx)
	{
		String s;
		godot_string str = godot_pool_string_array_get(&_godot_array, idx);
		godot_string_copy_string((godot_string *) &s, &str);
		godot_string_destroy(&str);
		return s;
	}

	int size()
	{
		return godot_pool_string_array_size(&_godot_array);
	}


	~PoolStringArray()
	{
		godot_pool_string_array_destroy(&_godot_array);
	}
};



class PoolVector2Array {
	godot_pool_vector2_array _godot_array;
public:
	PoolVector2Array()
	{
		godot_pool_vector2_array_new(&_godot_array);
	}

	PoolVector2Array(const Array& array)
	{
		godot_pool_vector2_array_new_with_array(&_godot_array, (godot_array *) &array);
	}

	void append(const Vector2& data)
	{
		godot_pool_vector2_array_append(&_godot_array, (godot_vector2 *) &data);
	}

	void append_array(const PoolVector2Array& array)
	{
		godot_pool_vector2_array_append_array(&_godot_array, &array._godot_array);
	}

	int insert(const int idx, const Vector2& data)
	{
		return godot_pool_vector2_array_insert(&_godot_array, idx, (godot_vector2 *) &data);
	}

	void invert()
	{
		godot_pool_vector2_array_invert(&_godot_array);
	}

	void push_back(const Vector2& data)
	{
		godot_pool_vector2_array_push_back(&_godot_array, (godot_vector2 *) &data);
	}

	void remove(const int idx)
	{
		godot_pool_vector2_array_remove(&_godot_array, idx);
	}

	void resize(const int size)
	{
		godot_pool_vector2_array_resize(&_godot_array, size);
	}

	void set(const int idx, const Vector2& data)
	{
		godot_pool_vector2_array_set(&_godot_array, idx, (godot_vector2 *) &data);
	}

	Vector2 operator [](const int idx)
	{
		Vector2 v;
		*(godot_vector2 *) &v = godot_pool_vector2_array_get(&_godot_array, idx);
		return v;
	}

	int size()
	{
		return godot_pool_vector2_array_size(&_godot_array);
	}


	~PoolVector2Array()
	{
		godot_pool_vector2_array_destroy(&_godot_array);
	}
};


class PoolVector3Array {
	godot_pool_vector3_array _godot_array;
public:
	PoolVector3Array()
	{
		godot_pool_vector3_array_new(&_godot_array);
	}

	PoolVector3Array(const Array& array)
	{
		godot_pool_vector3_array_new_with_array(&_godot_array, (godot_array *) &array);
	}

	void append(const Vector3& data)
	{
		godot_pool_vector3_array_append(&_godot_array, (godot_vector3 *) &data);
	}

	void append_array(const PoolVector3Array& array)
	{
		godot_pool_vector3_array_append_array(&_godot_array, &array._godot_array);
	}

	int insert(const int idx, const Vector3& data)
	{
		return godot_pool_vector3_array_insert(&_godot_array, idx, (godot_vector3 *) &data);
	}

	void invert()
	{
		godot_pool_vector3_array_invert(&_godot_array);
	}

	void push_back(const Vector3& data)
	{
		godot_pool_vector3_array_push_back(&_godot_array, (godot_vector3 *) &data);
	}

	void remove(const int idx)
	{
		godot_pool_vector3_array_remove(&_godot_array, idx);
	}

	void resize(const int size)
	{
		godot_pool_vector3_array_resize(&_godot_array, size);
	}

	void set(const int idx, const Vector3& data)
	{
		godot_pool_vector3_array_set(&_godot_array, idx, (godot_vector3 *) &data);
	}

	Vector3 operator [](const int idx)
	{
		Vector3 v;
		*(godot_vector3 *) &v = godot_pool_vector3_array_get(&_godot_array, idx);
		return v;
	}

	int size()
	{
		return godot_pool_vector3_array_size(&_godot_array);
	}


	~PoolVector3Array()
	{
		godot_pool_vector3_array_destroy(&_godot_array);
	}
};


class PoolColorArray {
	godot_pool_color_array _godot_array;
public:
	PoolColorArray()
	{
		godot_pool_color_array_new(&_godot_array);
	}

	PoolColorArray(const Array& array)
	{
		godot_pool_color_array_new_with_array(&_godot_array, (godot_array *) &array);
	}

	void append(const Color& data)
	{
		godot_pool_color_array_append(&_godot_array, (godot_color *) &data);
	}

	void append_array(const PoolColorArray& array)
	{
		godot_pool_color_array_append_array(&_godot_array, &array._godot_array);
	}

	int insert(const int idx, const Color& data)
	{
		return godot_pool_color_array_insert(&_godot_array, idx, (godot_color *) &data);
	}

	void invert()
	{
		godot_pool_color_array_invert(&_godot_array);
	}

	void push_back(const Color& data)
	{
		godot_pool_color_array_push_back(&_godot_array, (godot_color *) &data);
	}

	void remove(const int idx)
	{
		godot_pool_color_array_remove(&_godot_array, idx);
	}

	void resize(const int size)
	{
		godot_pool_color_array_resize(&_godot_array, size);
	}

	void set(const int idx, const Color& data)
	{
		godot_pool_color_array_set(&_godot_array, idx, (godot_color *) &data);
	}

	Color operator [](const int idx)
	{
		Color v;
		*(godot_color *) &v = godot_pool_color_array_get(&_godot_array, idx);
		return v;
	}

	int size()
	{
		return godot_pool_color_array_size(&_godot_array);
	}


	~PoolColorArray()
	{
		godot_pool_color_array_destroy(&_godot_array);
	}
};




}

#endif // POOLARRAYS_H
