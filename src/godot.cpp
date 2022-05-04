/*************************************************************************/
/*  godot.cpp                                                            */
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

#include <godot_cpp/godot.hpp>

#include <godot_cpp/classes/wrapped.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/memory.hpp>
#include <godot_cpp/variant/variant.hpp>

#include <godot_cpp/core/error_macros.hpp>

namespace godot {

namespace internal {

const GDNativeInterface *gdn_interface = nullptr;
GDNativeExtensionClassLibraryPtr library = nullptr;
void *token = nullptr;

} // namespace internal

GDExtensionBinding::Callback GDExtensionBinding::init_callback = nullptr;
GDExtensionBinding::Callback GDExtensionBinding::terminate_callback = nullptr;
GDNativeInitializationLevel GDExtensionBinding::minimum_initialization_level = GDNATIVE_INITIALIZATION_CORE;

GDNativeBool GDExtensionBinding::init(const GDNativeInterface *p_interface, const GDNativeExtensionClassLibraryPtr p_library, GDNativeInitialization *r_initialization) {
	internal::gdn_interface = p_interface;
	internal::library = p_library;
	internal::token = p_library;

	r_initialization->initialize = initialize_level;
	r_initialization->deinitialize = deinitialize_level;
	r_initialization->minimum_initialization_level = minimum_initialization_level;

	ERR_FAIL_COND_V_MSG(init_callback == nullptr, false, "Initialization callback must be defined.");

	Variant::init_bindings();

	return true;
}

void GDExtensionBinding::initialize_level(void *userdata, GDNativeInitializationLevel p_level) {
	ClassDB::current_level = p_level;

	if (init_callback) {
		init_callback(static_cast<ModuleInitializationLevel>(p_level));
	}

	ClassDB::initialize(p_level);
}

void GDExtensionBinding::deinitialize_level(void *userdata, GDNativeInitializationLevel p_level) {
	ClassDB::current_level = p_level;
	ClassDB::deinitialize(p_level);

	if (terminate_callback) {
		terminate_callback(static_cast<ModuleInitializationLevel>(p_level));
	}
}

void GDExtensionBinding::InitObject::register_initializer(Callback p_init) const {
	GDExtensionBinding::init_callback = p_init;
}

void GDExtensionBinding::InitObject::register_terminator(Callback p_terminate) const {
	GDExtensionBinding::terminate_callback = p_terminate;
}

void GDExtensionBinding::InitObject::set_minimum_library_initialization_level(ModuleInitializationLevel p_level) const {
	GDExtensionBinding::minimum_initialization_level = static_cast<GDNativeInitializationLevel>(p_level);
}

GDNativeBool GDExtensionBinding::InitObject::init() const {
	return GDExtensionBinding::init(gdn_interface, library, initialization);
}

} // namespace godot

extern "C" {

void GDN_EXPORT initialize_level(void *userdata, GDNativeInitializationLevel p_level) {
	godot::GDExtensionBinding::initialize_level(userdata, p_level);
}

void GDN_EXPORT deinitialize_level(void *userdata, GDNativeInitializationLevel p_level) {
	godot::GDExtensionBinding::deinitialize_level(userdata, p_level);
}
}
