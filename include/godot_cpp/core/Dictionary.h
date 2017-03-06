#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "Variant.h"

#include "Array.h"

#include <godot/godot_dictionary.h>

namespace godot {

class Dictionary {
	godot_dictionary _godot_dictionary;
public:
	Dictionary();

	void clear();

	bool empty() const;

	void erase(const Variant& key);

	bool has(const Variant& key) const;

	bool has_all(const Array& keys) const;

	uint32_t hash() const;

	Array keys() const;

	int parse_json(const String& json);

	Variant &operator [](const Variant& key);

	const Variant &operator [](const Variant& key) const;

	int size() const;

	String to_json() const;

	Array values() const;

	~Dictionary();

};

}

#endif // DICTIONARY_H
