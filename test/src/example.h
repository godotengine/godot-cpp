/*************************************************************************/
/*  example.h                                                            */
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

#ifndef EXAMPLE_CLASS_H
#define EXAMPLE_CLASS_H

// We don't need windows.h in this plugin but many others do and it throws up on itself all the time
// So best to include it and make sure CI warns us when we use something Microsoft took for their own goals....
#ifdef WIN32
#include <windows.h>
#endif

#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/viewport.hpp>

#include <godot_cpp/core/binder_common.hpp>

using namespace godot;

class ExampleRef : public RefCounted {
	GDCLASS(ExampleRef, RefCounted);

protected:
	static void _bind_methods() {}

public:
	ExampleRef();
	~ExampleRef();
};

class Example : public Control {
	GDCLASS(Example, Control);

protected:
	static void _bind_methods();

private:
	Vector2 custom_position;

public:
	// Constants.
	enum Constants {
		FIRST,
		ANSWER_TO_EVERYTHING = 42,
	};

	enum {
		CONSTANT_WITHOUT_ENUM = 314,
	};

	Example();
	~Example();

	// Functions.
	void simple_func();
	void simple_const_func() const;
	String return_something(const String &base);
	Viewport *return_something_const() const;
	ExampleRef *return_extended_ref() const;
	Ref<ExampleRef> extended_ref_checks(Ref<ExampleRef> p_ref) const;
	Variant varargs_func(const Variant **args, GDNativeInt arg_count, GDNativeCallError &error);
	int varargs_func_nv(const Variant **args, GDNativeInt arg_count, GDNativeCallError &error);
	void varargs_func_void(const Variant **args, GDNativeInt arg_count, GDNativeCallError &error);
	void emit_custom_signal(const String &name, int value);

	Array test_array() const;
	Dictionary test_dictionary() const;

	// Property.
	void set_custom_position(const Vector2 &pos);
	Vector2 get_custom_position() const;

	// Virtual function override (no need to bind manually).
	virtual bool _has_point(const Vector2 &point) const override;
};

VARIANT_ENUM_CAST(Example, Constants);

#endif // ! EXAMPLE_CLASS_H
