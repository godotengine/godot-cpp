#ifndef POOLARRAYS_H
#define POOLARRAYS_H

#if defined(_WIN32)
#  ifdef _GD_CPP_CORE_API_IMPL
#    define GD_CPP_CORE_API __declspec(dllexport)
#  else
#    define GD_CPP_CORE_API __declspec(dllimport)
#  endif
#else
#  define GD_CPP_CORE_API
#endif

#include "Defs.hpp"

#include "String.hpp"
#include "Color.hpp"
#include "Vector2.hpp"
#include "Vector3.hpp"

#include <godot/godot_pool_arrays.h>

namespace godot {

class Array;

class GD_CPP_CORE_API PoolByteArray {
	godot_pool_byte_array _godot_array;
public:
	PoolByteArray();

	PoolByteArray(const Array& array);

	void append(const uint8_t data);

	void append_array(const PoolByteArray& array);

	int insert(const int idx, const uint8_t data);

	void invert();

	void push_back(const uint8_t data);

	void remove(const int idx);

	void resize(const int size);

	void set(const int idx, const uint8_t data);

	uint8_t operator [](const int idx);

	int size();

	~PoolByteArray();
};


class GD_CPP_CORE_API PoolIntArray {
	godot_pool_int_array _godot_array;
public:
	PoolIntArray();

	PoolIntArray(const Array& array);

	void append(const int data);

	void append_array(const PoolIntArray& array);

	int insert(const int idx, const int data);

	void invert();

	void push_back(const int data);

	void remove(const int idx);

	void resize(const int size);

	void set(const int idx, const int data);

	int operator [](const int idx);

	int size();

	~PoolIntArray();
};


class GD_CPP_CORE_API PoolRealArray {
	godot_pool_real_array _godot_array;
public:
	PoolRealArray();

	PoolRealArray(const Array& array);

	void append(const real_t data);

	void append_array(const PoolRealArray& array);

	int insert(const int idx, const real_t data);

	void invert();

	void push_back(const real_t data);

	void remove(const int idx);

	void resize(const int size);

	void set(const int idx, const real_t data);

	real_t operator [](const int idx);

	int size();

	~PoolRealArray();
};


class GD_CPP_CORE_API PoolStringArray {
	godot_pool_string_array _godot_array;
public:
	PoolStringArray();

	PoolStringArray(const Array& array);

	void append(const String& data);

	void append_array(const PoolStringArray& array);

	int insert(const int idx, const String& data);

	void invert();

	void push_back(const String& data);

	void remove(const int idx);

	void resize(const int size);

	void set(const int idx, const String& data);

	String operator [](const int idx);

	int size();

	~PoolStringArray();
};



class GD_CPP_CORE_API PoolVector2Array {
	godot_pool_vector2_array _godot_array;
public:
	PoolVector2Array();

	PoolVector2Array(const Array& array);

	void append(const Vector2& data);

	void append_array(const PoolVector2Array& array);

	int insert(const int idx, const Vector2& data);

	void invert();

	void push_back(const Vector2& data);

	void remove(const int idx);

	void resize(const int size);

	void set(const int idx, const Vector2& data);

	Vector2 operator [](const int idx);

	int size();

	~PoolVector2Array();
};


class GD_CPP_CORE_API PoolVector3Array {
	godot_pool_vector3_array _godot_array;
public:
	PoolVector3Array();

	PoolVector3Array(const Array& array);

	void append(const Vector3& data);

	void append_array(const PoolVector3Array& array);

	int insert(const int idx, const Vector3& data);

	void invert();

	void push_back(const Vector3& data);

	void remove(const int idx);

	void resize(const int size);

	void set(const int idx, const Vector3& data);

	Vector3 operator [](const int idx);

	int size();

	~PoolVector3Array();
};


class GD_CPP_CORE_API PoolColorArray {
	godot_pool_color_array _godot_array;
public:
	PoolColorArray();

	PoolColorArray(const Array& array);

	void append(const Color& data);

	void append_array(const PoolColorArray& array);

	int insert(const int idx, const Color& data);

	void invert();

	void push_back(const Color& data);

	void remove(const int idx);

	void resize(const int size);

	void set(const int idx, const Color& data);

	Color operator [](const int idx);

	int size();

	~PoolColorArray();
};




}

#endif // POOLARRAYS_H
