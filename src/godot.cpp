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

GDExtensionBinding::Callback GDExtensionBinding::init_callbacks[GDNATIVE_MAX_INITIALIZATION_LEVEL] = {};
GDExtensionBinding::Callback GDExtensionBinding::terminate_callbacks[GDNATIVE_MAX_INITIALIZATION_LEVEL] = {};

GDNativeBool GDExtensionBinding::init(const GDNativeInterface *p_interface, const GDNativeExtensionClassLibraryPtr p_library, GDNativeInitialization *r_initialization) {
	internal::gdn_interface = p_interface;
	internal::library = p_library;
	internal::token = p_library;

	r_initialization->initialize = initialize_level;
	r_initialization->deinitialize = deinitialize_level;

	bool has_init = false;
	for (int i = 0; i < GDNATIVE_MAX_INITIALIZATION_LEVEL; i++) {
		if (init_callbacks[i]) {
			r_initialization->minimum_initialization_level = GDNativeInitializationLevel(i);
			has_init = true;
		}
	}
	ERR_FAIL_COND_V_MSG(!has_init, false, "At least one initialization callback must be defined.");

	Variant::init_bindings();

	return true;
}

void GDExtensionBinding::initialize_level(void *userdata, GDNativeInitializationLevel p_level) {
	ClassDB::current_level = p_level;

	if (init_callbacks[p_level]) {
		init_callbacks[p_level]();
	}

	ClassDB::initialize(p_level);
}

void GDExtensionBinding::deinitialize_level(void *userdata, GDNativeInitializationLevel p_level) {
	ClassDB::current_level = p_level;
	ClassDB::deinitialize(p_level);

	if (terminate_callbacks[p_level]) {
		terminate_callbacks[p_level]();
	}
}

void GDExtensionBinding::InitObject::register_core_initializer(Callback p_core_init) const {
	GDExtensionBinding::init_callbacks[GDNATIVE_INITIALIZATION_CORE] = p_core_init;
}

void GDExtensionBinding::InitObject::register_server_initializer(Callback p_server_init) const {
	GDExtensionBinding::init_callbacks[GDNATIVE_INITIALIZATION_SERVERS] = p_server_init;
}

void GDExtensionBinding::InitObject::register_scene_initializer(Callback p_scene_init) const {
	GDExtensionBinding::init_callbacks[GDNATIVE_INITIALIZATION_SCENE] = p_scene_init;
}

void GDExtensionBinding::InitObject::register_driver_initializer(Callback p_driver_init) const {
	GDExtensionBinding::init_callbacks[GDNATIVE_INITIALIZATION_DRIVER] = p_driver_init;
}

void GDExtensionBinding::InitObject::register_editor_initializer(Callback p_editor_init) const {
	GDExtensionBinding::init_callbacks[GDNATIVE_INITIALIZATION_EDITOR] = p_editor_init;
}

void GDExtensionBinding::InitObject::register_core_terminator(Callback p_core_terminate) const {
	GDExtensionBinding::terminate_callbacks[GDNATIVE_INITIALIZATION_CORE] = p_core_terminate;
}

void GDExtensionBinding::InitObject::register_server_terminator(Callback p_server_terminate) const {
	GDExtensionBinding::terminate_callbacks[GDNATIVE_INITIALIZATION_SERVERS] = p_server_terminate;
}

void GDExtensionBinding::InitObject::register_scene_terminator(Callback p_scene_terminate) const {
	GDExtensionBinding::terminate_callbacks[GDNATIVE_INITIALIZATION_SCENE] = p_scene_terminate;
}

void GDExtensionBinding::InitObject::register_driver_terminator(Callback p_driver_terminate) const {
	GDExtensionBinding::terminate_callbacks[GDNATIVE_INITIALIZATION_DRIVER] = p_driver_terminate;
}

void GDExtensionBinding::InitObject::register_editor_terminator(Callback p_editor_terminate) const {
	GDExtensionBinding::terminate_callbacks[GDNATIVE_INITIALIZATION_EDITOR] = p_editor_terminate;
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
