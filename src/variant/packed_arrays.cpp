/*************************************************************************/
/*  packed_arrays.cpp                                                    */
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

// extra functions for packed arrays

#include <godot_cpp/godot.hpp>

#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/packed_byte_array.hpp>
#include <godot_cpp/variant/packed_color_array.hpp>
#include <godot_cpp/variant/packed_float32_array.hpp>
#include <godot_cpp/variant/packed_float64_array.hpp>
#include <godot_cpp/variant/packed_int32_array.hpp>
#include <godot_cpp/variant/packed_int64_array.hpp>
#include <godot_cpp/variant/packed_string_array.hpp>
#include <godot_cpp/variant/packed_vector2_array.hpp>
#include <godot_cpp/variant/packed_vector3_array.hpp>

namespace godot {

const uint8_t &PackedByteArray::operator[](int p_index) const {
	return *internal::gdn_interface->packed_byte_array_operator_index_const((GDNativeTypePtr *)this, p_index);
}

uint8_t &PackedByteArray::operator[](int p_index) {
	return *internal::gdn_interface->packed_byte_array_operator_index((GDNativeTypePtr *)this, p_index);
}

const uint8_t *PackedByteArray::ptr() const {
	return internal::gdn_interface->packed_byte_array_operator_index_const((GDNativeTypePtr *)this, 0);
}

uint8_t *PackedByteArray::ptrw() {
	return internal::gdn_interface->packed_byte_array_operator_index((GDNativeTypePtr *)this, 0);
}

const Color &PackedColorArray::operator[](int p_index) const {
	const Color *color = (const Color *)internal::gdn_interface->packed_color_array_operator_index_const((GDNativeTypePtr *)this, p_index);
	return *color;
}

Color &PackedColorArray::operator[](int p_index) {
	Color *color = (Color *)internal::gdn_interface->packed_color_array_operator_index((GDNativeTypePtr *)this, p_index);
	return *color;
}

const Color *PackedColorArray::ptr() const {
	return (const Color *)internal::gdn_interface->packed_color_array_operator_index_const((GDNativeTypePtr *)this, 0);
}

Color *PackedColorArray::ptrw() {
	return (Color *)internal::gdn_interface->packed_color_array_operator_index((GDNativeTypePtr *)this, 0);
}

const float &PackedFloat32Array::operator[](int p_index) const {
	return *internal::gdn_interface->packed_float32_array_operator_index_const((GDNativeTypePtr *)this, p_index);
}

float &PackedFloat32Array::operator[](int p_index) {
	return *internal::gdn_interface->packed_float32_array_operator_index((GDNativeTypePtr *)this, p_index);
}

const float *PackedFloat32Array::ptr() const {
	return internal::gdn_interface->packed_float32_array_operator_index_const((GDNativeTypePtr *)this, 0);
}

float *PackedFloat32Array::ptrw() {
	return internal::gdn_interface->packed_float32_array_operator_index((GDNativeTypePtr *)this, 0);
}

const double &PackedFloat64Array::operator[](int p_index) const {
	return *internal::gdn_interface->packed_float64_array_operator_index_const((GDNativeTypePtr *)this, p_index);
}

double &PackedFloat64Array::operator[](int p_index) {
	return *internal::gdn_interface->packed_float64_array_operator_index((GDNativeTypePtr *)this, p_index);
}

const double *PackedFloat64Array::ptr() const {
	return internal::gdn_interface->packed_float64_array_operator_index_const((GDNativeTypePtr *)this, 0);
}

double *PackedFloat64Array::ptrw() {
	return internal::gdn_interface->packed_float64_array_operator_index((GDNativeTypePtr *)this, 0);
}

const int32_t &PackedInt32Array::operator[](int p_index) const {
	return *internal::gdn_interface->packed_int32_array_operator_index_const((GDNativeTypePtr *)this, p_index);
}

int32_t &PackedInt32Array::operator[](int p_index) {
	return *internal::gdn_interface->packed_int32_array_operator_index((GDNativeTypePtr *)this, p_index);
}

const int32_t *PackedInt32Array::ptr() const {
	return internal::gdn_interface->packed_int32_array_operator_index_const((GDNativeTypePtr *)this, 0);
}

int32_t *PackedInt32Array::ptrw() {
	return internal::gdn_interface->packed_int32_array_operator_index((GDNativeTypePtr *)this, 0);
}

const int64_t &PackedInt64Array::operator[](int p_index) const {
	return *internal::gdn_interface->packed_int64_array_operator_index_const((GDNativeTypePtr *)this, p_index);
}

int64_t &PackedInt64Array::operator[](int p_index) {
	return *internal::gdn_interface->packed_int64_array_operator_index((GDNativeTypePtr *)this, p_index);
}

const int64_t *PackedInt64Array::ptr() const {
	return internal::gdn_interface->packed_int64_array_operator_index_const((GDNativeTypePtr *)this, 0);
}

int64_t *PackedInt64Array::ptrw() {
	return internal::gdn_interface->packed_int64_array_operator_index((GDNativeTypePtr *)this, 0);
}

const String &PackedStringArray::operator[](int p_index) const {
	const String *string = (const String *)internal::gdn_interface->packed_string_array_operator_index_const((GDNativeTypePtr *)this, p_index);
	return *string;
}

String &PackedStringArray::operator[](int p_index) {
	String *string = (String *)internal::gdn_interface->packed_string_array_operator_index((GDNativeTypePtr *)this, p_index);
	return *string;
}

const String *PackedStringArray::ptr() const {
	return (const String *)internal::gdn_interface->packed_string_array_operator_index_const((GDNativeTypePtr *)this, 0);
}

String *PackedStringArray::ptrw() {
	return (String *)internal::gdn_interface->packed_string_array_operator_index((GDNativeTypePtr *)this, 0);
}

const Vector2 &PackedVector2Array::operator[](int p_index) const {
	const Vector2 *vec = (const Vector2 *)internal::gdn_interface->packed_vector2_array_operator_index_const((GDNativeTypePtr *)this, p_index);
	return *vec;
}

Vector2 &PackedVector2Array::operator[](int p_index) {
	Vector2 *vec = (Vector2 *)internal::gdn_interface->packed_vector2_array_operator_index((GDNativeTypePtr *)this, p_index);
	return *vec;
}

const Vector2 *PackedVector2Array::ptr() const {
	return (const Vector2 *)internal::gdn_interface->packed_vector2_array_operator_index_const((GDNativeTypePtr *)this, 0);
}

Vector2 *PackedVector2Array::ptrw() {
	return (Vector2 *)internal::gdn_interface->packed_vector2_array_operator_index((GDNativeTypePtr *)this, 0);
}

const Vector3 &PackedVector3Array::operator[](int p_index) const {
	const Vector3 *vec = (const Vector3 *)internal::gdn_interface->packed_vector3_array_operator_index_const((GDNativeTypePtr *)this, p_index);
	return *vec;
}

Vector3 &PackedVector3Array::operator[](int p_index) {
	Vector3 *vec = (Vector3 *)internal::gdn_interface->packed_vector3_array_operator_index((GDNativeTypePtr *)this, p_index);
	return *vec;
}

const Vector3 *PackedVector3Array::ptr() const {
	return (const Vector3 *)internal::gdn_interface->packed_vector3_array_operator_index_const((GDNativeTypePtr *)this, 0);
}

Vector3 *PackedVector3Array::ptrw() {
	return (Vector3 *)internal::gdn_interface->packed_vector3_array_operator_index((GDNativeTypePtr *)this, 0);
}

const Variant &Array::operator[](int p_index) const {
	const Variant *var = (const Variant *)internal::gdn_interface->array_operator_index_const((GDNativeTypePtr *)this, p_index);
	return *var;
}

Variant &Array::operator[](int p_index) {
	Variant *var = (Variant *)internal::gdn_interface->array_operator_index((GDNativeTypePtr *)this, p_index);
	return *var;
}

const Variant &Dictionary::operator[](const Variant &p_key) const {
	const Variant *var = (const Variant *)internal::gdn_interface->dictionary_operator_index_const((GDNativeTypePtr *)this, (GDNativeVariantPtr)&p_key);
	return *var;
}

Variant &Dictionary::operator[](const Variant &p_key) {
	Variant *var = (Variant *)internal::gdn_interface->dictionary_operator_index((GDNativeTypePtr *)this, (GDNativeVariantPtr)&p_key);
	return *var;
}

} // namespace godot
