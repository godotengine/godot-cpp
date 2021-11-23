/*************************************************************************/
/*  example.cpp                                                          */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2021 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2021 Godot Engine contributors (cf. AUTHORS.md).   */
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

#include "example.h"

#include <godot_cpp/core/class_db.hpp>

#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

uint64_t ExampleRef::instance_count = 0;

void ExampleRef::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_value"), &ExampleRef::get_value);
	ClassDB::bind_method(D_METHOD("set_value", "value"), &ExampleRef::set_value);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "value"), "set_value", "get_value");
}

ExampleRef::ExampleRef() {
	instance_count++;
	UtilityFunctions::print("ExampleRef created. Our total instance count is now: ", instance_count);

	// default this
	value = 1;
}

ExampleRef::~ExampleRef() {
	instance_count--;
	UtilityFunctions::print("ExampleRef destroyed. Our total instance count is now: ", instance_count);
}

void ExampleRef::set_value(int64_t p_value) {
	value = p_value;
}

int64_t ExampleRef::get_value() const {
	return value;
}

void Example::_bind_methods() {
	// Methods.
	ClassDB::bind_method(D_METHOD("simple_func"), &Example::simple_func);
	ClassDB::bind_method(D_METHOD("simple_const_func"), &Example::simple_const_func);
	ClassDB::bind_method(D_METHOD("return_something", "base"), &Example::return_something);
	ClassDB::bind_method(D_METHOD("return_something_const"), &Example::return_something_const);
	ClassDB::bind_method(D_METHOD("return_extended_ref"), &Example::return_extended_ref);
	ClassDB::bind_method(D_METHOD("extended_ref_checks", "ref"), &Example::extended_ref_checks);

	ClassDB::bind_method(D_METHOD("test_array"), &Example::test_array);
	ClassDB::bind_method(D_METHOD("test_dictionary"), &Example::test_dictionary);

	{
		MethodInfo mi;
		mi.arguments.push_back(PropertyInfo(Variant::STRING, "some_argument"));
		mi.name = "varargs_func";
		ClassDB::bind_vararg_method(METHOD_FLAGS_DEFAULT, "varargs_func", &Example::varargs_func, mi);
	}

	// Properties.
	ADD_GROUP("Test group", "group_");
	ADD_SUBGROUP("Test subgroup", "group_subgroup_");

	ClassDB::bind_method(D_METHOD("get_custom_position"), &Example::get_custom_position);
	ClassDB::bind_method(D_METHOD("set_custom_position", "position"), &Example::set_custom_position);
	ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "group_subgroup_custom_position"), "set_custom_position", "get_custom_position");

	ClassDB::bind_method(D_METHOD("get_ref_obj"), &Example::get_ref_obj);
	ClassDB::bind_method(D_METHOD("set_ref_obj", "ref_obj"), &Example::set_ref_obj);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "ref_obj", PROPERTY_HINT_RESOURCE_TYPE, "ExampleRef"), "set_ref_obj", "get_ref_obj");

	// Signals.
	ADD_SIGNAL(MethodInfo("custom_signal", PropertyInfo(Variant::STRING, "name"), PropertyInfo(Variant::INT, "value")));
	ClassDB::bind_method(D_METHOD("emit_custom_signal", "name", "value"), &Example::emit_custom_signal);

	// Constants.
	BIND_ENUM_CONSTANT(FIRST);
	BIND_ENUM_CONSTANT(ANSWER_TO_EVERYTHING);

	BIND_CONSTANT(CONSTANT_WITHOUT_ENUM);
}

Example::Example() {
	UtilityFunctions::print("Example Constructor.");
}

Example::~Example() {
	UtilityFunctions::print("Example Destructor.");
}

// Methods.
void Example::simple_func() {
	UtilityFunctions::print("Simple func called.");
}

void Example::simple_const_func() const {
	UtilityFunctions::print("Simple const func called.");
}

String Example::return_something(const String &base) {
	UtilityFunctions::print("Return something called.");
	return base;
}

Viewport *Example::return_something_const() const {
	UtilityFunctions::print("Return something const called.");
	if (is_inside_tree()) {
		Viewport *result = get_viewport();
		return result;
	}
	return nullptr;
}

Ref<ExampleRef> Example::return_extended_ref() const {
	// When subclassing RefCounted we should ALWAYS use Ref<..> or Godot will start doing confusing things as it will start using reference counting to manage the object.
	// We should never instantiate the object directly such as this:
	// return memnew(ExampleRef());

	Ref<ExampleRef> ref;
	ref.instantiate();
	return ref;
}

Ref<ExampleRef> Example::extended_ref_checks(Ref<ExampleRef> p_ref) const {
	Ref<ExampleRef> ref;
	ref.instantiate();
	UtilityFunctions::print("Example ref checks called with value: ", p_ref->get_instance_id(), ", returning value: ", ref->get_instance_id());
	return ref;
}

Variant Example::varargs_func(const Variant **args, GDNativeInt arg_count, GDNativeCallError &error) {
	UtilityFunctions::print("Varargs called with ", String::num((double)arg_count), " arguments");
	return arg_count;
}

void Example::emit_custom_signal(const String &name, int value) {
	emit_signal("custom_signal", name, value);
}

Array Example::test_array() const {
	Array arr;

	arr.resize(2);
	arr[0] = Variant(1);
	arr[1] = Variant(2);

	return arr;
}

Dictionary Example::test_dictionary() const {
	Dictionary dict;

	dict["hello"] = "world";
	dict["foo"] = "bar";

	return dict;
}

// Properties.
void Example::set_custom_position(const Vector2 &pos) {
	custom_position = pos;
}

Vector2 Example::get_custom_position() const {
	return custom_position;
}

void Example::set_ref_obj(const Ref<ExampleRef> p_ref) {
	ref_obj = p_ref;
}

Ref<ExampleRef> Example::get_ref_obj() const {
	return ref_obj;
}

// Virtual function override.
bool Example::_has_point(const Vector2 &point) const {
	Label *label = get_node<Label>("Label");
	label->set_text("Got point: " + Variant(point).stringify());

	return false;
}
