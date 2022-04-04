/*************************************************************************/
/*  Dictionary.cpp                                                       */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2022 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2022 Godot Engine contributors (cf. AUTHORS.md).   */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#include "Dictionary.hpp"
#include "Array.hpp"
#include "GodotGlobal.hpp"
#include "Variant.hpp"

namespace godot {

Dictionary::Dictionary() {
	godot::api->godot_dictionary_new(&_godot_dictionary);
}

Dictionary::Dictionary(const Dictionary &other) {
	godot::api->godot_dictionary_new_copy(&_godot_dictionary, &other._godot_dictionary);
}

Dictionary &Dictionary::operator=(const Dictionary &other) {
	godot::api->godot_dictionary_destroy(&_godot_dictionary);
	godot::api->godot_dictionary_new_copy(&_godot_dictionary, &other._godot_dictionary);
	return *this;
}

void Dictionary::clear() {
	godot::api->godot_dictionary_clear(&_godot_dictionary);
}

bool Dictionary::empty() const {
	return godot::api->godot_dictionary_empty(&_godot_dictionary);
}

void Dictionary::erase(const Variant &key) {
	godot::api->godot_dictionary_erase(&_godot_dictionary, (godot_variant *)&key);
}

bool Dictionary::has(const Variant &key) const {
	return godot::api->godot_dictionary_has(&_godot_dictionary, (godot_variant *)&key);
}

bool Dictionary::has_all(const Array &keys) const {
	return godot::api->godot_dictionary_has_all(&_godot_dictionary, (godot_array *)&keys);
}

uint32_t Dictionary::hash() const {
	return godot::api->godot_dictionary_hash(&_godot_dictionary);
}

Array Dictionary::keys() const {
	godot_array a = godot::api->godot_dictionary_keys(&_godot_dictionary);
	return Array(a);
}

Variant &Dictionary::operator[](const Variant &key) {
	godot_variant *v = godot::api->godot_dictionary_operator_index(&_godot_dictionary, (godot_variant *)&key);
	return *reinterpret_cast<Variant *>(v);
}

const Variant &Dictionary::operator[](const Variant &key) const {
	// oops I did it again
	godot_variant *v = godot::api->godot_dictionary_operator_index((godot_dictionary *)&_godot_dictionary, (godot_variant *)&key);
	return *reinterpret_cast<Variant *>(v);
}

int Dictionary::size() const {
	return godot::api->godot_dictionary_size(&_godot_dictionary);
}

String Dictionary::to_json() const {
	godot_string s = godot::api->godot_dictionary_to_json(&_godot_dictionary);
	return String(s);
}

Array Dictionary::values() const {
	godot_array a = godot::api->godot_dictionary_values(&_godot_dictionary);
	return Array(a);
}

Dictionary::~Dictionary() {
	godot::api->godot_dictionary_destroy(&_godot_dictionary);
}

} // namespace godot
