/**************************************************************************/
/*  editor_plugin_registration.hpp                                        */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#ifndef GODOT_EDITOR_PLUGIN_REGISTRATION_HPP
#define GODOT_EDITOR_PLUGIN_REGISTRATION_HPP

#ifdef GODOT_MODULE
#include "editor/plugins/editor_plugin.h"
#else

#include <godot_cpp/templates/vector.hpp>

namespace godot {

class EditorPlugin;
class StringName;

class EditorPlugins {
private:
	static Vector<StringName> plugin_classes;

public:
	static void add_plugin_class(const StringName &p_class_name);
	static void remove_plugin_class(const StringName &p_class_name);
	static void deinitialize(GDExtensionInitializationLevel p_level);

	template <typename T>
	static void add_by_type() {
		add_plugin_class(T::get_class_static());
	}
	template <typename T>
	static void remove_by_type() {
		remove_plugin_class(T::get_class_static());
	}
};

} // namespace godot

#endif
#endif // GODOT_EDITOR_PLUGIN_REGISTRATION_HPP
