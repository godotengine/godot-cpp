/*************************************************************************/
/*  godot.hpp                                                            */
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

#ifndef GODOT_HPP
#define GODOT_HPP

#include <godot/gdnative_interface.h>

namespace godot {

namespace internal {

extern "C" const GDNativeInterface *gdn_interface;
extern "C" GDNativeExtensionClassLibraryPtr library;
extern "C" void *token;

} // namespace internal

class GDExtensionBinding {
public:
	using Callback = void (*)();

	static Callback init_callbacks[GDNATIVE_MAX_INITIALIZATION_LEVEL];
	static Callback terminate_callbacks[GDNATIVE_MAX_INITIALIZATION_LEVEL];
	static GDNativeBool init(const GDNativeInterface *p_interface, const GDNativeExtensionClassLibraryPtr p_library, GDNativeInitialization *r_initialization);

public:
	static void initialize_level(void *userdata, GDNativeInitializationLevel p_level);
	static void deinitialize_level(void *userdata, GDNativeInitializationLevel p_level);

	class InitObject {
		const GDNativeInterface *gdn_interface;
		const GDNativeExtensionClassLibraryPtr library;
		GDNativeInitialization *initialization;

	public:
		InitObject(const GDNativeInterface *p_interface, const GDNativeExtensionClassLibraryPtr p_library, GDNativeInitialization *r_initialization) :
				gdn_interface(p_interface),
				library(p_library),
				initialization(r_initialization){};

		void register_core_initializer(Callback p_core_init) const;
		void register_server_initializer(Callback p_server_init) const;
		void register_driver_initializer(Callback p_driver_init) const;
		void register_scene_initializer(Callback p_scene_init) const;
		void register_editor_initializer(Callback p_editor_init) const;
		void register_core_terminator(Callback p_core_terminate) const;
		void register_server_terminator(Callback p_server_terminate) const;
		void register_scene_terminator(Callback p_scene_terminate) const;
		void register_driver_terminator(Callback p_driver_terminate) const;
		void register_editor_terminator(Callback p_editor_terminate) const;

		GDNativeBool init() const;
	};
};

} // namespace godot

#endif // ! GODOT_HPP
