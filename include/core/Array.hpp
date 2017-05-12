#ifndef ARRAY_H
#define ARRAY_H

#if defined(_WIN32)
#  ifdef _GD_CPP_CORE_API_IMPL
#    define GD_CPP_CORE_API __declspec(dllexport)
#  else
#    define GD_CPP_CORE_API __declspec(dllimport)
#  endif
#else
#  define GD_CPP_CORE_API
#endif

#include <godot/godot_array.h>

#include "String.hpp"

namespace godot {

class Variant;
class PoolByteArray;
class PoolIntArray;
class PoolRealArray;
class PoolStringArray;
class PoolVector2Array;
class PoolVector3Array;
class PoolColorArray;

class Object;

class GD_CPP_CORE_API Array {
	godot_array _godot_array;
public:
	Array();

	Array(const PoolByteArray& a);

	Array(const PoolIntArray& a);

	Array(const PoolRealArray& a);

	Array(const PoolStringArray& a);

	Array(const PoolVector2Array& a);

	Array(const PoolVector3Array& a);

	Array(const PoolColorArray& a);

	Variant& operator [](const int idx);

	Variant operator [](const int idx) const;

	void append(const Variant& v);

	void clear();

	int count(const Variant& v);

	bool empty() const;

	void erase(const Variant& v);

	Variant front() const;

	Variant back() const;

	int find(const Variant& what, const int from = 0);

	int find_last(const Variant& what);

	bool has(const Variant& what) const;

	uint32_t hash() const;

	void insert(const int pos, const Variant& value);

	void invert();

	bool is_shared() const;

	Variant pop_back();

	Variant pop_front();

	void push_back(const Variant& v);

	void push_front(const Variant& v);

	void remove(const int idx);

	int size() const;

	void resize(const int size);

	int rfind(const Variant& what, const int from = -1);

	void sort();

	void sort_custom(Object *obj, const String& func);

	~Array();

};

}

#endif // ARRAY_H
