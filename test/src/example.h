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

// We don't need windows.h in this example plugin but many others do, and it can
// lead to annoying situations due to the ton of macros it defines.
// So we include it and make sure CI warns us if we use something that conflicts
// with a Windows define.
#ifdef WIN32
#include <windows.h>
#endif

#include <godot_cpp/core/binder_common.hpp>

class Example : public godot::Object {
	GDCLASS(Example, godot::Object);

protected:
	static void _bind_methods();

private:
	godot::Vector2i my_prop;

public:
	// Constants.
	enum Constants {
		FOO,
		BAR,
	};

	Example();
	~Example();

	// Functions.
	godot::String my_method(const godot::String &base, const Constants arg);
	godot::Variant my_varargs_method(const godot::Variant **args, GDNativeInt arg_count, GDNativeCallError &error);
	void emit_my_signal(const godot::String &name, int value);

	// Property.
	void set_my_prop(const godot::Vector2 &pos);
	godot::Vector2 get_my_prop() const;

	// Static method.
	static int my_static_method(int p_a, int p_b);
};

VARIANT_ENUM_CAST(Example, Constants);

#endif // EXAMPLE_CLASS_H
