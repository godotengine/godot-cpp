#ifndef ARRAY_H
#define ARRAY_H

#include <godot/godot_array.h>

#include "Variant.h"

namespace godot {

class Array {
	godot_array _godot_array;
public:
	Array()
	{
		godot_array_new(&_godot_array);
	}

	Array(const PoolByteArray& a)
	{
		godot_array_new_pool_byte_array(&_godot_array, (godot_pool_byte_array *) &a);
	}

	Array(const PoolIntArray& a)
	{
		godot_array_new_pool_int_array(&_godot_array, (godot_pool_int_array *) &a);
	}

	Array(const PoolRealArray& a)
	{
		godot_array_new_pool_real_array(&_godot_array, (godot_pool_real_array *) &a);
	}

	Array(const PoolStringArray& a)
	{
		godot_array_new_pool_string_array(&_godot_array, (godot_pool_string_array *) &a);
	}

	Array(const PoolVector2Array& a)
	{
		godot_array_new_pool_vector2_array(&_godot_array, (godot_pool_vector2_array *) &a);
	}

	Array(const PoolVector3Array& a)
	{
		godot_array_new_pool_vector3_array(&_godot_array, (godot_pool_vector3_array *) &a);
	}

	Array(const PoolColorArray& a)
	{
		godot_array_new_pool_color_array(&_godot_array, (godot_pool_color_array *) &a);
	}

	Variant& operator [](const int idx)
	{
		godot_variant *v = godot_array_get(&_godot_array, idx);
		return *(Variant *) v;
	}

	Variant operator [](const int idx) const
	{
		// Yes, I'm casting away the const... you can hate me now.
		// since the result is
		godot_variant *v = godot_array_get((godot_array *) &_godot_array, idx);
		return *(Variant *) v;
	}

	void append(const Variant& v)
	{
		godot_array_append(&_godot_array, (godot_variant *) &v);
	}

	void clear()
	{
		godot_array_clear(&_godot_array);
	}

	int count(const Variant& v)
	{
		return godot_array_count(&_godot_array, (godot_variant *) &v);
	}

	bool empty() const
	{
		return godot_array_empty(&_godot_array);
	}

	void erase(const Variant& v)
	{
		godot_array_erase(&_godot_array, (godot_variant *) &v);
	}

	Variant front() const
	{
		godot_variant v = godot_array_front(&_godot_array);
		return *(Variant *) &v;
	}

	Variant back() const
	{
		godot_variant v = godot_array_back(&_godot_array);
		return *(Variant *) &v;
	}

	int find(const Variant& what, const int from = 0)
	{
		return godot_array_find(&_godot_array, (godot_variant *) &what, from);
	}

	int find_last(const Variant& what)
	{
		return godot_array_find_last(&_godot_array, (godot_variant *) &what);
	}

	bool has(const Variant& what) const
	{
		return godot_array_has(&_godot_array, (godot_variant *) &what);
	}

	uint32_t hash() const
	{
		return godot_array_hash(&_godot_array);
	}

	void insert(const int pos, const Variant& value)
	{
		godot_array_insert(&_godot_array, pos, (godot_variant *) &value);
	}

	void invert()
	{
		godot_array_invert(&_godot_array);
	}

	bool is_shared() const
	{
		return godot_array_is_shared(&_godot_array);
	}

	Variant pop_back()
	{
		godot_variant v = godot_array_pop_back(&_godot_array);
		return *(Variant *) &v;
	}

	Variant pop_front()
	{
		godot_variant v = godot_array_pop_front(&_godot_array);
		return *(Variant *) &v;
	}

	void push_back(const Variant& v)
	{
		godot_array_push_back(&_godot_array, (godot_variant *) &v);
	}

	void push_front(const Variant& v)
	{
		godot_array_push_front(&_godot_array, (godot_variant *) &v);
	}

	void remove(const int idx)
	{
		godot_array_remove(&_godot_array, idx);
	}

	int size() const
	{
		return godot_array_size(&_godot_array);
	}

	void resize(const int size)
	{
		godot_array_resize(&_godot_array, size);
	}

	int rfind(const Variant& what, const int from = -1)
	{
		return godot_array_rfind(&_godot_array, (godot_variant *) &what, from);
	}

	void sort()
	{
		godot_array_sort(&_godot_array);
	}

	void sort_custom(Object *obj, const String& func)
	{
		godot_array_sort_custom(&_godot_array, (godot_object *) obj, (godot_string *) &func);
	}

	~Array()
	{
		godot_array_destroy(&_godot_array);
	}


};

}

#endif // ARRAY_H
