/**************************************************************************/
/*  wrapped.cpp                                                           */
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

#include <godot_cpp/classes/wrapped.hpp>

#include <godot_cpp/variant/builtin_types.hpp>

#include <godot_cpp/classes/object.hpp>

namespace godot {

const StringName *Wrapped::_get_extension_class_name() const {
	return nullptr;
}

void Wrapped::_postinitialize() {
	const StringName *extension_class = _get_extension_class_name();
	if (extension_class) {
		godot::internal::gdextension_interface_object_set_instance(_owner, reinterpret_cast<GDExtensionConstStringNamePtr>(extension_class), this);
	}
	godot::internal::gdextension_interface_object_set_instance_binding(_owner, godot::internal::token, this, _get_bindings_callbacks());
}

Wrapped::Wrapped(const StringName p_godot_class) {
	_owner = godot::internal::gdextension_interface_classdb_construct_object(reinterpret_cast<GDExtensionConstStringNamePtr>(p_godot_class._native_ptr()));
}

Wrapped::Wrapped(GodotObject *p_godot_object) {
	_owner = p_godot_object;
}

void postinitialize_handler(Wrapped *p_wrapped) {
	p_wrapped->_postinitialize();
}

} // namespace godot
