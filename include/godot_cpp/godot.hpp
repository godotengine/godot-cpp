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

#pragma once

#include <godot_cpp/core/gdextension_interface_loader.hpp>

namespace godot {

namespace gdextension_interface {

extern "C" GDExtensionInterfaceGetProcAddress get_proc_address;
extern "C" GDExtensionClassLibraryPtr library;
extern "C" void *token;

#if GODOT_VERSION_MINOR >= 5
extern "C" GDExtensionGodotVersion2 godot_version;
#else
extern "C" GDExtensionGodotVersion godot_version;
#endif

} // namespace gdextension_interface

namespace internal {

class DocDataRegistration {
public:
	DocDataRegistration(const char *p_hash, int p_uncompressed_size, int p_compressed_size, const unsigned char *p_data);
};

} // namespace internal

enum ModuleInitializationLevel {
	MODULE_INITIALIZATION_LEVEL_CORE = GDEXTENSION_INITIALIZATION_CORE,
	MODULE_INITIALIZATION_LEVEL_SERVERS = GDEXTENSION_INITIALIZATION_SERVERS,
	MODULE_INITIALIZATION_LEVEL_SCENE = GDEXTENSION_INITIALIZATION_SCENE,
	MODULE_INITIALIZATION_LEVEL_EDITOR = GDEXTENSION_INITIALIZATION_EDITOR,
	MODULE_INITIALIZATION_LEVEL_MAX
};

class GDExtensionBinding {
public:
	using Callback = void (*)(ModuleInitializationLevel p_level);

	struct InitData {
		GDExtensionInitializationLevel minimum_initialization_level = GDEXTENSION_INITIALIZATION_CORE;
		Callback init_callback = nullptr;
		Callback terminate_callback = nullptr;
#if GODOT_VERSION_MINOR >= 5
		GDExtensionMainLoopCallbacks main_loop_callbacks = {};

		inline bool has_main_loop_callbacks() const {
			return main_loop_callbacks.frame_func || main_loop_callbacks.startup_func || main_loop_callbacks.shutdown_func;
		}
#endif
	};

	class InitDataList {
		int data_count = 0;
		int data_capacity = 0;
		InitData **data = nullptr;

	public:
		void add(InitData *p_cb);
		~InitDataList();
	};

	static bool api_initialized;
	static int level_initialized[MODULE_INITIALIZATION_LEVEL_MAX];
	static InitDataList initdata;
	static GDExtensionBool init(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, InitData *p_init_data, GDExtensionInitialization *r_initialization);

public:
	static void initialize_level(void *p_userdata, GDExtensionInitializationLevel p_level);
	static void deinitialize_level(void *p_userdata, GDExtensionInitializationLevel p_level);

	class InitObject {
		GDExtensionInterfaceGetProcAddress get_proc_address;
		GDExtensionClassLibraryPtr library;
		GDExtensionInitialization *initialization;
		mutable InitData *init_data = nullptr;

	public:
		InitObject(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization);

		void register_initializer(Callback p_init) const;
		void register_terminator(Callback p_init) const;
		void set_minimum_library_initialization_level(ModuleInitializationLevel p_level) const;

#if GODOT_VERSION_MINOR >= 5
		// Register a callback that is called after all initialization levels when Godot is fully initialized.
		void register_startup_callback(GDExtensionMainLoopStartupCallback p_callback) const;
		// Register a callback that is called for every process frame. This will run after all `_process()` methods on Node, and before `ScriptServer::frame()`.
		void register_frame_callback(GDExtensionMainLoopFrameCallback p_callback) const;
		// Register a callback that is called before Godot is shutdown when it is still fully initialized.
		void register_shutdown_callback(GDExtensionMainLoopShutdownCallback p_callback) const;
#endif

		GDExtensionBool init() const;
	};
};

} // namespace godot
