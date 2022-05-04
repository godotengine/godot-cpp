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

enum ModuleInitializationLevel {
	MODULE_INITIALIZATION_LEVEL_CORE = GDNATIVE_INITIALIZATION_CORE,
	MODULE_INITIALIZATION_LEVEL_SERVERS = GDNATIVE_INITIALIZATION_SERVERS,
	MODULE_INITIALIZATION_LEVEL_SCENE = GDNATIVE_INITIALIZATION_SCENE,
	MODULE_INITIALIZATION_LEVEL_EDITOR = GDNATIVE_INITIALIZATION_EDITOR
};

class GDExtensionBinding {
public:
	using Callback = void (*)(ModuleInitializationLevel p_level);

	static Callback init_callback;
	static Callback terminate_callback;
	static GDNativeInitializationLevel minimum_initialization_level;
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

		void register_initializer(Callback p_init) const;
		void register_terminator(Callback p_init) const;
		void set_minimum_library_initialization_level(ModuleInitializationLevel p_level) const;

		GDNativeBool init() const;
	};
};

} // namespace godot

#endif // ! GODOT_HPP
