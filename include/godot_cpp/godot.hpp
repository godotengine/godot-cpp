/**************************************************************************/
/*  godot.hpp                                                             */
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

#ifndef GODOT_GODOT_HPP
#define GODOT_GODOT_HPP

#include <gdextension_interface.h>

namespace godot {

namespace internal {

extern "C" const GDExtensionInterface *gde_interface;
extern "C" GDExtensionClassLibraryPtr library;
extern "C" void *token;

} // namespace internal

enum ModuleInitializationLevel {
	MODULE_INITIALIZATION_LEVEL_CORE = GDEXTENSION_INITIALIZATION_CORE,
	MODULE_INITIALIZATION_LEVEL_SERVERS = GDEXTENSION_INITIALIZATION_SERVERS,
	MODULE_INITIALIZATION_LEVEL_SCENE = GDEXTENSION_INITIALIZATION_SCENE,
	MODULE_INITIALIZATION_LEVEL_EDITOR = GDEXTENSION_INITIALIZATION_EDITOR
};

class GDExtensionBinding {
public:
	using Callback = void (*)(ModuleInitializationLevel p_level);

	static Callback init_callback;
	static Callback terminate_callback;
	static GDExtensionInitializationLevel minimum_initialization_level;
	static GDExtensionBool init(const GDExtensionInterface *p_interface, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization);

public:
	static void initialize_level(void *userdata, GDExtensionInitializationLevel p_level);
	static void deinitialize_level(void *userdata, GDExtensionInitializationLevel p_level);

	class InitObject {
		const GDExtensionInterface *gde_interface;
		GDExtensionClassLibraryPtr library;
		GDExtensionInitialization *initialization;

	public:
		InitObject(const GDExtensionInterface *p_interface, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) :
				gde_interface(p_interface),
				library(p_library),
				initialization(r_initialization) {}

		void register_initializer(Callback p_init) const;
		void register_terminator(Callback p_init) const;
		void set_minimum_library_initialization_level(ModuleInitializationLevel p_level) const;

		GDExtensionBool init() const;
	};
};

} // namespace godot

#endif // GODOT_GODOT_HPP
