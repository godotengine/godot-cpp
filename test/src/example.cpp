/*************************************************************************/
/*  example.cpp                                                          */
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

#include <godot_cpp/core/class_db.hpp>

#include "example.h"

int Example::my_static_method(int p_a, int p_b) {
	return p_a + p_b;
}

void Example::_bind_methods() {
	// Methods.
	godot::ClassDB::bind_method(godot::D_METHOD("my_method"), &Example::my_method);

	{
		godot::MethodInfo mi;
		mi.arguments.push_back(godot::PropertyInfo(godot::Variant::STRING, "some_argument"));
		mi.name = "my_varargs_method";
		godot::ClassDB::bind_vararg_method(godot::METHOD_FLAGS_DEFAULT, "my_varargs_method", &Example::my_varargs_method, mi);
	}

	godot::ClassDB::bind_static_method("Example", godot::D_METHOD("my_static_method", "a", "b"), &Example::my_static_method);

	// Properties.
	ADD_GROUP("Test group", "group_");
	ADD_SUBGROUP("Test subgroup", "group_subgroup_");

	godot::ClassDB::bind_method(godot::D_METHOD("get_my_prop"), &Example::get_my_prop);
	godot::ClassDB::bind_method(godot::D_METHOD("set_my_prop", "position"), &Example::set_my_prop);
	ADD_PROPERTY(godot::PropertyInfo(godot::Variant::VECTOR2I, "group_subgroup_my_prop"), "set_my_prop", "get_my_prop");

	// Signals.
	ADD_SIGNAL(godot::MethodInfo("my_signal", godot::PropertyInfo(godot::Variant::STRING, "name"), godot::PropertyInfo(godot::Variant::INT, "value")));
	godot::ClassDB::bind_method(godot::D_METHOD("emit_my_signal", "name", "value"), &Example::emit_my_signal);

	// Constants.
	BIND_ENUM_CONSTANT(FOO);
	BIND_ENUM_CONSTANT(BAR);
}

Example::Example() {
}

Example::~Example() {
}

// Methods.
godot::String Example::my_method(const godot::String &base, const Constants arg) {
	if (arg == Constants::FOO) {
		return base + "Foo";
	} else {
		return base + "Bar";
	}
}

godot::Variant Example::my_varargs_method(const godot::Variant **args, GDNativeInt arg_count, GDNativeCallError &error) {
	return arg_count;
}

void Example::emit_my_signal(const godot::String &name, int value) {
	emit_signal("my_signal", name, value);
}

// Properties.
void Example::set_my_prop(const godot::Vector2 &pos) {
	my_prop = pos;
}

godot::Vector2 Example::get_my_prop() const {
	return my_prop;
}
