#ifndef DICTIONARY_H
#define DICTIONARY_H

#if defined(_WIN32)
#  ifdef _GD_CPP_CORE_API_IMPL
#    define GD_CPP_CORE_API __declspec(dllexport)
#  else
#    define GD_CPP_CORE_API __declspec(dllimport)
#  endif
#else
#  define GD_CPP_CORE_API
#endif

#include "Variant.hpp"

#include "Array.hpp"

#include <godot/godot_dictionary.h>

namespace godot {

class GD_CPP_CORE_API Dictionary {
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
