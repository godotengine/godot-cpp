#include "PoolArrays.hpp"

#include "Defs.hpp"

#include "String.hpp"
#include "Color.hpp"
#include "Vector2.hpp"
#include "Vector3.hpp"

#include <godot/godot_pool_arrays.h>

namespace godot {

PoolByteArray::PoolByteArray()
{
	godot_pool_byte_array_new(&_godot_array);
}

PoolByteArray::PoolByteArray(const Array& array)
{
	godot_pool_byte_array_new_with_array(&_godot_array, (godot_array *) &array);
}

void PoolByteArray::append(const uint8_t data)
{
	godot_pool_byte_array_append(&_godot_array, data);
}

void PoolByteArray::append_array(const PoolByteArray& array)
{
	godot_pool_byte_array_append_array(&_godot_array, &array._godot_array);
}

int PoolByteArray::insert(const int idx, const uint8_t data)
{
	return godot_pool_byte_array_insert(&_godot_array, idx, data);
}

void PoolByteArray::invert()
{
	godot_pool_byte_array_invert(&_godot_array);
}

void PoolByteArray::push_back(const uint8_t data)
{
	godot_pool_byte_array_push_back(&_godot_array, data);
}

void PoolByteArray::remove(const int idx)
{
	godot_pool_byte_array_remove(&_godot_array, idx);
}

void PoolByteArray::resize(const int size)
{
	godot_pool_byte_array_resize(&_godot_array, size);
}

void PoolByteArray::set(const int idx, const uint8_t data)
{
	godot_pool_byte_array_set(&_godot_array, idx, data);
}

uint8_t PoolByteArray::operator [](const int idx)
{
	return godot_pool_byte_array_get(&_godot_array, idx);
}

int PoolByteArray::size()
{
	return godot_pool_byte_array_size(&_godot_array);
}


PoolByteArray::~PoolByteArray()
{
	godot_pool_byte_array_destroy(&_godot_array);
}



PoolIntArray::PoolIntArray()
{
	godot_pool_int_array_new(&_godot_array);
}

PoolIntArray::PoolIntArray(const Array& array)
{
	godot_pool_int_array_new_with_array(&_godot_array, (godot_array *) &array);
}

void PoolIntArray::append(const int data)
{
	godot_pool_int_array_append(&_godot_array, data);
}

void PoolIntArray::append_array(const PoolIntArray& array)
{
	godot_pool_int_array_append_array(&_godot_array, &array._godot_array);
}

int PoolIntArray::insert(const int idx, const int data)
{
	return godot_pool_int_array_insert(&_godot_array, idx, data);
}

void PoolIntArray::invert()
{
	godot_pool_int_array_invert(&_godot_array);
}

void PoolIntArray::push_back(const int data)
{
	godot_pool_int_array_push_back(&_godot_array, data);
}

void PoolIntArray::remove(const int idx)
{
	godot_pool_int_array_remove(&_godot_array, idx);
}

void PoolIntArray::resize(const int size)
{
	godot_pool_int_array_resize(&_godot_array, size);
}

void PoolIntArray::set(const int idx, const int data)
{
	godot_pool_int_array_set(&_godot_array, idx, data);
}

int PoolIntArray::operator [](const int idx)
{
	return godot_pool_int_array_get(&_godot_array, idx);
}

int PoolIntArray::size()
{
	return godot_pool_int_array_size(&_godot_array);
}


PoolIntArray::~PoolIntArray()
{
	godot_pool_int_array_destroy(&_godot_array);
}


PoolRealArray::PoolRealArray()
{
	godot_pool_real_array_new(&_godot_array);
}

PoolRealArray::PoolRealArray(const Array& array)
{
	godot_pool_real_array_new_with_array(&_godot_array, (godot_array *) &array);
}

void PoolRealArray::append(const real_t data)
{
	godot_pool_real_array_append(&_godot_array, data);
}

void PoolRealArray::append_array(const PoolRealArray& array)
{
	godot_pool_real_array_append_array(&_godot_array, &array._godot_array);
}

int PoolRealArray::insert(const int idx, const real_t data)
{
	return godot_pool_real_array_insert(&_godot_array, idx, data);
}

void PoolRealArray::invert()
{
	godot_pool_real_array_invert(&_godot_array);
}

void PoolRealArray::push_back(const real_t data)
{
	godot_pool_real_array_push_back(&_godot_array, data);
}

void PoolRealArray::remove(const int idx)
{
	godot_pool_real_array_remove(&_godot_array, idx);
}

void PoolRealArray::resize(const int size)
{
	godot_pool_real_array_resize(&_godot_array, size);
}

void PoolRealArray::set(const int idx, const real_t data)
{
	godot_pool_real_array_set(&_godot_array, idx, data);
}

real_t PoolRealArray::operator [](const int idx)
{
	return godot_pool_real_array_get(&_godot_array, idx);
}

int PoolRealArray::size()
{
	return godot_pool_real_array_size(&_godot_array);
}


PoolRealArray::~PoolRealArray()
{
	godot_pool_real_array_destroy(&_godot_array);
}



PoolStringArray::PoolStringArray()
{
	godot_pool_string_array_new(&_godot_array);
}

PoolStringArray::PoolStringArray(const Array& array)
{
	godot_pool_string_array_new_with_array(&_godot_array, (godot_array *) &array);
}

void PoolStringArray::append(const String& data)
{
	godot_pool_string_array_append(&_godot_array, (godot_string *) &data);
}

void PoolStringArray::append_array(const PoolStringArray& array)
{
	godot_pool_string_array_append_array(&_godot_array, &array._godot_array);
}

int PoolStringArray::insert(const int idx, const String& data)
{
	return godot_pool_string_array_insert(&_godot_array, idx, (godot_string *) &data);
}

void PoolStringArray::invert()
{
	godot_pool_string_array_invert(&_godot_array);
}

void PoolStringArray::push_back(const String& data)
{
	godot_pool_string_array_push_back(&_godot_array, (godot_string *) &data);
}

void PoolStringArray::remove(const int idx)
{
	godot_pool_string_array_remove(&_godot_array, idx);
}

void PoolStringArray::resize(const int size)
{
	godot_pool_string_array_resize(&_godot_array, size);
}

void PoolStringArray::set(const int idx, const String& data)
{
	godot_pool_string_array_set(&_godot_array, idx, (godot_string *) &data);
}

String PoolStringArray::operator [](const int idx)
{
	String s;
	godot_string str = godot_pool_string_array_get(&_godot_array, idx);
	godot_string_new_copy((godot_string *) &s, &str);
	godot_string_destroy(&str);
	return s;
}

int PoolStringArray::size()
{
	return godot_pool_string_array_size(&_godot_array);
}


PoolStringArray::~PoolStringArray()
{
	godot_pool_string_array_destroy(&_godot_array);
}



PoolVector2Array::PoolVector2Array()
{
	godot_pool_vector2_array_new(&_godot_array);
}

PoolVector2Array::PoolVector2Array(const Array& array)
{
	godot_pool_vector2_array_new_with_array(&_godot_array, (godot_array *) &array);
}

void PoolVector2Array::append(const Vector2& data)
{
	godot_pool_vector2_array_append(&_godot_array, (godot_vector2 *) &data);
}

void PoolVector2Array::append_array(const PoolVector2Array& array)
{
	godot_pool_vector2_array_append_array(&_godot_array, &array._godot_array);
}

int PoolVector2Array::insert(const int idx, const Vector2& data)
{
	return godot_pool_vector2_array_insert(&_godot_array, idx, (godot_vector2 *) &data);
}

void PoolVector2Array::invert()
{
	godot_pool_vector2_array_invert(&_godot_array);
}

void PoolVector2Array::push_back(const Vector2& data)
{
	godot_pool_vector2_array_push_back(&_godot_array, (godot_vector2 *) &data);
}

void PoolVector2Array::remove(const int idx)
{
	godot_pool_vector2_array_remove(&_godot_array, idx);
}

void PoolVector2Array::resize(const int size)
{
	godot_pool_vector2_array_resize(&_godot_array, size);
}

void PoolVector2Array::set(const int idx, const Vector2& data)
{
	godot_pool_vector2_array_set(&_godot_array, idx, (godot_vector2 *) &data);
}

Vector2 PoolVector2Array::operator [](const int idx)
{
	Vector2 v;
	*(godot_vector2 *) &v = godot_pool_vector2_array_get(&_godot_array, idx);
	return v;
}

int PoolVector2Array::size()
{
	return godot_pool_vector2_array_size(&_godot_array);
}


PoolVector2Array::~PoolVector2Array()
{
	godot_pool_vector2_array_destroy(&_godot_array);
}



PoolVector3Array::PoolVector3Array()
{
	godot_pool_vector3_array_new(&_godot_array);
}

PoolVector3Array::PoolVector3Array(const Array& array)
{
	godot_pool_vector3_array_new_with_array(&_godot_array, (godot_array *) &array);
}

void PoolVector3Array::append(const Vector3& data)
{
	godot_pool_vector3_array_append(&_godot_array, (godot_vector3 *) &data);
}

void PoolVector3Array::append_array(const PoolVector3Array& array)
{
	godot_pool_vector3_array_append_array(&_godot_array, &array._godot_array);
}

int PoolVector3Array::insert(const int idx, const Vector3& data)
{
	return godot_pool_vector3_array_insert(&_godot_array, idx, (godot_vector3 *) &data);
}

void PoolVector3Array::invert()
{
	godot_pool_vector3_array_invert(&_godot_array);
}

void PoolVector3Array::push_back(const Vector3& data)
{
	godot_pool_vector3_array_push_back(&_godot_array, (godot_vector3 *) &data);
}

void PoolVector3Array::remove(const int idx)
{
	godot_pool_vector3_array_remove(&_godot_array, idx);
}

void PoolVector3Array::resize(const int size)
{
	godot_pool_vector3_array_resize(&_godot_array, size);
}

void PoolVector3Array::set(const int idx, const Vector3& data)
{
	godot_pool_vector3_array_set(&_godot_array, idx, (godot_vector3 *) &data);
}

Vector3 PoolVector3Array::operator [](const int idx)
{
	Vector3 v;
	*(godot_vector3 *) &v = godot_pool_vector3_array_get(&_godot_array, idx);
	return v;
}

int PoolVector3Array::size()
{
	return godot_pool_vector3_array_size(&_godot_array);
}


PoolVector3Array::~PoolVector3Array()
{
	godot_pool_vector3_array_destroy(&_godot_array);
}


PoolColorArray::PoolColorArray()
{
	godot_pool_color_array_new(&_godot_array);
}

PoolColorArray::PoolColorArray(const Array& array)
{
	godot_pool_color_array_new_with_array(&_godot_array, (godot_array *) &array);
}

void PoolColorArray::append(const Color& data)
{
	godot_pool_color_array_append(&_godot_array, (godot_color *) &data);
}

void PoolColorArray::append_array(const PoolColorArray& array)
{
	godot_pool_color_array_append_array(&_godot_array, &array._godot_array);
}

int PoolColorArray::insert(const int idx, const Color& data)
{
	return godot_pool_color_array_insert(&_godot_array, idx, (godot_color *) &data);
}

void PoolColorArray::invert()
{
	godot_pool_color_array_invert(&_godot_array);
}

void PoolColorArray::push_back(const Color& data)
{
	godot_pool_color_array_push_back(&_godot_array, (godot_color *) &data);
}

void PoolColorArray::remove(const int idx)
{
	godot_pool_color_array_remove(&_godot_array, idx);
}

void PoolColorArray::resize(const int size)
{
	godot_pool_color_array_resize(&_godot_array, size);
}

void PoolColorArray::set(const int idx, const Color& data)
{
	godot_pool_color_array_set(&_godot_array, idx, (godot_color *) &data);
}

Color PoolColorArray::operator [](const int idx)
{
	Color v;
	*(godot_color *) &v = godot_pool_color_array_get(&_godot_array, idx);
	return v;
}

int PoolColorArray::size()
{
	return godot_pool_color_array_size(&_godot_array);
}


PoolColorArray::~PoolColorArray()
{
	godot_pool_color_array_destroy(&_godot_array);
}



}
