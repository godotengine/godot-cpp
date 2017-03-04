#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "Variant.h"

#include "Array.h"

#include <godot/godot_dictionary.h>

namespace godot {

class Dictionary {
	godot_dictionary _godot_dictionary;
public:
	Dictionary()
	{
		godot_dictionary_new(&_godot_dictionary);
	}

	void clear()
	{
		godot_dictionary_clear(&_godot_dictionary);
	}

	bool empty() const
	{
		return godot_dictionary_empty(&_godot_dictionary);
	}

	void erase(const Variant& key)
	{
		godot_dictionary_erase(&_godot_dictionary, (godot_variant *) &key);
	}

	bool has(const Variant& key) const
	{
		return godot_dictionary_has(&_godot_dictionary, (godot_variant *) &key);
	}

	bool has_all(const Array& keys) const
	{
		return godot_dictionary_has_all(&_godot_dictionary, (godot_array *) &keys);
	}

	uint32_t hash() const
	{
		return godot_dictionary_hash(&_godot_dictionary);
	}

	Array keys() const
	{
		godot_array a = godot_dictionary_keys(&_godot_dictionary);
		return *(Array *) &a;
	}

	int parse_json(const String& json)
	{
		return godot_dictionary_parse_json(&_godot_dictionary, (godot_string *) &json);
	}

	Variant &operator [](const Variant& key)
	{
		return *(Variant *) godot_dictionary_operator_index(&_godot_dictionary, (godot_variant *) &key);
	}

	const Variant &operator [](const Variant& key) const
	{
		// oops I did it again
		return *(Variant *) godot_dictionary_operator_index((godot_dictionary *) &_godot_dictionary, (godot_variant *) &key);
	}

	int size() const
	{
		return godot_dictionary_size(&_godot_dictionary);
	}

	String to_json() const
	{
		godot_string s = godot_dictionary_to_json(&_godot_dictionary);
		return *(String *) &s;
	}

	Array values() const
	{
		godot_array a = godot_dictionary_values(&_godot_dictionary);
		return *(Array *) &a;
	}

	~Dictionary()
	{
		godot_dictionary_destroy(&_godot_dictionary);
	}

};

}

#endif // DICTIONARY_H
