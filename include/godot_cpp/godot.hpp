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

/**
 * The procedure lookup function supplied by the running Godot instance to resolve GDExtension entry points.
 *
 * ```cpp
 * // After the bindings are initialized, test for an optional engine procedure.
 * bool has_new_allocator = gdextension_interface::get_proc_address("mem_alloc2") != nullptr;
 * ```
 */
extern "C" GDExtensionInterfaceGetProcAddress get_proc_address;
/**
 * Godot's handle for the loaded extension library. Registration calls use it to associate declarations with that library.
 *
 * ```cpp
 * // In GDExtensionBinding::initialize_level(), for the core level.
 * gdextension_interface::register_main_loop_callbacks(gdextension_interface::library, &init_data->main_loop_callbacks);
 * ```
 */
extern "C" GDExtensionClassLibraryPtr library;
/**
 * Identifies this extension's instance bindings and custom callable userdata. Initialization uses the library handle as the token.
 *
 * ```cpp
 * // In Callable::Callable(CallableCustom *), while building the native record.
 * info.token = gdextension_interface::token;
 * ```
 */
extern "C" void *token;

#if GODOT_VERSION_MINOR >= 5
/**
 * Version record for the running engine when targeting Godot 4.5 or later. The binding fills it while checking compatibility.
 *
 * ```cpp
 * unsigned engine_minor = gdextension_interface::godot_version.minor;
 * ```
 */
extern "C" GDExtensionGodotVersion2 godot_version;
#else
/**
 * Version record for the running engine when targeting a Godot API before 4.5.
 *
 * ```cpp
 * unsigned engine_minor = gdextension_interface::godot_version.minor;
 * ```
 */
extern "C" GDExtensionGodotVersion godot_version;
#endif

} // namespace gdextension_interface

namespace internal {

/**
 * Registers a generated compressed class reference for Godot's editor help panel.
 *
 * ```cpp
 * // In the generated documentation source alongside the static compressed bytes.
 * static internal::DocDataRegistration docs(_doc_data_hash, _doc_data_uncompressed_size, _doc_data_compressed_size, _doc_data_compressed);
 * ```
 */
class DocDataRegistration {
public:
	/**
	 * Stores the generated data pointers and sizes for loading at the editor level. A second registration is rejected when valid documentation is already present.
	 *
	 * - `p_hash` — A hash string stored for the lifetime of the module.
	 * - `p_uncompressed_size` — The byte length of the XML after decompression.
	 * - `p_compressed_size` — The byte length of the compressed buffer.
	 * - `p_data` — The compressed bytes, stored for the lifetime of the module.
	 *
	 * ```cpp
	 * // In the generated documentation source.
	 * static internal::DocDataRegistration docs(_doc_data_hash, _doc_data_uncompressed_size, _doc_data_compressed_size, _doc_data_compressed);
	 * ```
	 */
	DocDataRegistration(const char *p_hash, int p_uncompressed_size, int p_compressed_size, const unsigned char *p_data);
};

} // namespace internal

/**
 * Identifies the engine subsystem phase passed to extension initialization and termination callbacks.
 *
 * ```cpp
 * // In an extension's initializer, register the Node subclass at the scene level.
 * if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE) { GDREGISTER_CLASS(AtlasPreview); }
 * ```
 */
enum ModuleInitializationLevel {
	/**
	 * The phase for core engine initialization. The binding registers main loop hooks at this level.
	 *
	 * ```cpp
	 * // In the initializer, reset a module-owned counter before subsystem setup.
	 * if (p_level == MODULE_INITIALIZATION_LEVEL_CORE) { processed_frames = 0; }
	 * ```
	 */
	MODULE_INITIALIZATION_LEVEL_CORE = GDEXTENSION_INITIALIZATION_CORE,
	/**
	 * The phase for engine server initialization.
	 *
	 * ```cpp
	 * // In the initializer for a module that installs a rendering server hook.
	 * if (p_level == MODULE_INITIALIZATION_LEVEL_SERVERS) { register_render_hook(); }
	 * ```
	 */
	MODULE_INITIALIZATION_LEVEL_SERVERS = GDEXTENSION_INITIALIZATION_SERVERS,
	/**
	 * The phase for scene types, including extension Node classes.
	 *
	 * ```cpp
	 * // In the entry point after constructing init.
	 * init.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);
	 * ```
	 */
	MODULE_INITIALIZATION_LEVEL_SCENE = GDEXTENSION_INITIALIZATION_SCENE,
	/**
	 * The editor-only phase for extension editor types and plugin setup.
	 *
	 * ```cpp
	 * // In an editor initializer, restrict plugin registration to the editor phase.
	 * if (p_level == MODULE_INITIALIZATION_LEVEL_EDITOR) { GDREGISTER_CLASS(AtlasInspectorPlugin); }
	 * ```
	 */
	MODULE_INITIALIZATION_LEVEL_EDITOR = GDEXTENSION_INITIALIZATION_EDITOR,
	/**
	 * The exclusive upper bound of initialization levels. The binding uses it to size and validate its level counters.
	 *
	 * ```cpp
	 * int level_counts[MODULE_INITIALIZATION_LEVEL_MAX] = {};
	 * ```
	 */
	MODULE_INITIALIZATION_LEVEL_MAX
};

/**
 * Connects Godot's C initialization interface to the C++ binding and to callbacks registered by an extension.
 *
 * ```cpp
 * // In the entry point, publish the initializer that registers the extension's Node classes.
 * GDExtensionBinding::InitObject init(p_get_proc_address, p_library, r_initialization);
 * init.register_initializer(initialize_atlas_module);
 * init.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);
 * return init.init();
 * ```
 */
class GDExtensionBinding {
public:
	/**
	 * A callback invoked with the subsystem phase being initialized or terminated.
	 *
	 * ```cpp
	 * // An extension initializer with the required signature.
	 * GDExtensionBinding::Callback initialize = +[](ModuleInitializationLevel level) {
	 *     if (level == MODULE_INITIALIZATION_LEVEL_SCENE) { GDREGISTER_CLASS(AtlasPreview); }
	 * };
	 * ```
	 */
	using Callback = void (*)(ModuleInitializationLevel p_level);

	/**
	 * Stores per-entry-point callback settings. The binding passes an instance back through Godot's initialization userdata.
	 *
	 * ```cpp
	 * // In GDExtensionBinding::initialize_level().
	 * InitData *init_data = static_cast<InitData *>(p_userdata);
	 * ```
	 */
	struct InitData {
		/**
		 * Holds the lowest level requested for the library, in the C interface format.
		 *
		 * ```cpp
		 * // In GDExtensionBinding::init(), when filling the engine's record.
		 * r_initialization->minimum_initialization_level = p_init_data->minimum_initialization_level;
		 * ```
		 */
		GDExtensionInitializationLevel minimum_initialization_level = GDEXTENSION_INITIALIZATION_CORE;
		/**
		 * The extension's callback for entering a level. Binding setup requires it.
		 *
		 * ```cpp
		 * // In GDExtensionBinding::InitObject::register_initializer().
		 * init_data->init_callback = p_init;
		 * ```
		 */
		Callback init_callback = nullptr;
		/**
		 * The optional extension callback for leaving a level.
		 *
		 * ```cpp
		 * // In GDExtensionBinding::InitObject::register_terminator().
		 * init_data->terminate_callback = p_terminate;
		 * ```
		 */
		Callback terminate_callback = nullptr;
#if GODOT_VERSION_MINOR >= 5
		/**
		 * Stores optional startup, process-frame, and shutdown callbacks for registration at the core level.
		 *
		 * ```cpp
		 * // In GDExtensionBinding::InitObject::register_frame_callback().
		 * init_data->main_loop_callbacks.frame_func = p_callback;
		 * ```
		 */
		GDExtensionMainLoopCallbacks main_loop_callbacks = {};

		/**
		 * Tests whether any main loop callback has been set.
		 *
		 * ```cpp
		 * // In GDExtensionBinding::initialize_level().
		 * if (init_data && init_data->has_main_loop_callbacks()) {
		 *     gdextension_interface::register_main_loop_callbacks(gdextension_interface::library, &init_data->main_loop_callbacks);
		 * }
		 * ```
		 */
		inline bool has_main_loop_callbacks() const {
			return main_loop_callbacks.frame_func || main_loop_callbacks.startup_func || main_loop_callbacks.shutdown_func;
		}
#endif
	};

	/**
	 * Owns the initialization callback records so they outlive the `InitObject` used to prepare them.
	 *
	 * ```cpp
	 * // In GDExtensionBinding::InitObject's constructor.
	 * GDExtensionBinding::initdata.add(init_data);
	 * ```
	 */
	class InitDataList {
		/**
		 * Counts the callback records currently owned by this list.
		 *
		 * ```cpp
		 * // In InitDataList::add(), after ensuring capacity.
		 * data[data_count++] = p_data;
		 * ```
		 */
		int data_count = 0;
		/**
		 * Counts the available pointer slots in the backing allocation.
		 *
		 * ```cpp
		 * // In InitDataList::add(), after successfully increasing capacity.
		 * data_capacity += 32;
		 * ```
		 */
		int data_capacity = 0;
		/**
		 * Points to the allocation holding all the owned callback record pointers.
		 *
		 * ```cpp
		 * // In InitDataList's destructor.
		 * for (int i = 0; i < data_count; ++i) { delete data[i]; }
		 * ```
		 */
		InitData **data = nullptr;

	public:
		/**
		 * Transfers a callback record to the list when it can store the pointer. The allocation grows in groups of 32 slots.
		 *
		 * ```cpp
		 * // In GDExtensionBinding::InitObject's constructor.
		 * GDExtensionBinding::initdata.add(init_data);
		 * ```
		 */
		void add(InitData *p_cb);
		/**
		 * Deletes the stored callback records and frees the backing pointer allocation.
		 *
		 * ```cpp
		 * // In an internal scope that owns its own callback records.
		 * InitDataList records;
		 * records.add(new InitData()); // Leaving the scope destroys the records.
		 * ```
		 */
		~InitDataList();
	};

	/**
	 * Indicates that the shared API pointers and binding types have been initialized.
	 *
	 * ```cpp
	 * // In GDExtensionBinding::init(), after registering the engine classes.
	 * api_initialized = true;
	 * ```
	 */
	static bool api_initialized;
	/**
	 * Tracks active initializations at each level. Shared class database teardown runs when that level's count reaches zero.
	 *
	 * ```cpp
	 * // In GDExtensionBinding::deinitialize_level().
	 * level_initialized[p_level]--;
	 * ```
	 */
	static int level_initialized[MODULE_INITIALIZATION_LEVEL_MAX];
	/**
	 * Owns the persistent callback records supplied to Godot as initialization userdata.
	 *
	 * ```cpp
	 * // In GDExtensionBinding::InitObject's constructor.
	 * GDExtensionBinding::initdata.add(init_data);
	 * ```
	 */
	static InitDataList initdata;
	/**
	 * Fills the initialization record for Godot. The first successful call loads the API and initializes the binding tables. Returns false if setup fails or the initializer is missing.
	 *
	 * ```cpp
	 * // In GDExtensionBinding::InitObject::init().
	 * return GDExtensionBinding::init(get_proc_address, library, init_data, initialization);
	 * ```
	 */
	static GDExtensionBool init(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, InitData *p_init_data, GDExtensionInitialization *r_initialization);

public:
	/**
	 * Invokes the extension initializer for the given phase and initializes shared class data on the first entry at that level.
	 *
	 * - `p_userdata` — The `InitData` stored in the native initialization record.
	 *
	 * ```cpp
	 * // In GDExtensionBinding::init().
	 * r_initialization->initialize = initialize_level;
	 * ```
	 */
	static void initialize_level(void *p_userdata, GDExtensionInitializationLevel p_level);
	/**
	 * Invokes the extension terminator for the phase. The last exit at that level releases its shared class data and triggers editor plugin cleanup for the editor level.
	 *
	 * ```cpp
	 * // In GDExtensionBinding::init().
	 * r_initialization->deinitialize = deinitialize_level;
	 * ```
	 */
	static void deinitialize_level(void *p_userdata, GDExtensionInitializationLevel p_level);

	/**
	 * Collects an extension's callbacks and minimum initialization level before registering them with Godot.
	 *
	 * ```cpp
	 * // In the entry point of an extension that adds scene nodes.
	 * GDExtensionBinding::InitObject init(p_get_proc_address, p_library, r_initialization);
	 * init.register_initializer(initialize_atlas_module);
	 * init.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);
	 * return init.init();
	 * ```
	 */
	class InitObject {
		/**
		 * Stores the engine function used to resolve GDExtension procedures.
		 *
		 * ```cpp
		 * // In InitObject's constructor.
		 * get_proc_address = p_get_proc_address;
		 * ```
		 */
		GDExtensionInterfaceGetProcAddress get_proc_address;
		/**
		 * Stores the library handle passed by Godot for this entry point.
		 *
		 * ```cpp
		 * // In InitObject's constructor.
		 * library = p_library;
		 * ```
		 */
		GDExtensionClassLibraryPtr library;
		/**
		 * Points to the output record Godot supplies for this entry point.
		 *
		 * ```cpp
		 * // In InitObject's constructor.
		 * initialization = r_initialization;
		 * ```
		 */
		GDExtensionInitialization *initialization;
		/**
		 * Points to the callback settings owned by `GDExtensionBinding::initdata`.
		 *
		 * ```cpp
		 * // In InitObject::register_initializer().
		 * init_data->init_callback = p_init;
		 * ```
		 */
		mutable InitData *init_data = nullptr;

	public:
		/**
		 * Captures the entry point arguments and allocates the callback record that the binding will keep alive.
		 *
		 * ```cpp
		 * // In the entry point, capture its arguments before registering callbacks.
		 * GDExtensionBinding::InitObject init(p_get_proc_address, p_library, r_initialization);
		 * init.register_initializer(initialize_atlas_module);
		 * ```
		 */
		InitObject(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization);

		/**
		 * Sets the callback invoked as Godot enters an initialization level. A callback must be supplied before calling `init()`.
		 *
		 * ```cpp
		 * // In the entry point for a module that registers a custom Node subclass.
		 * init.register_initializer(+[](ModuleInitializationLevel level) {
		 *     if (level == MODULE_INITIALIZATION_LEVEL_SCENE) { GDREGISTER_CLASS(AtlasPreview); }
		 * });
		 * ```
		 */
		void register_initializer(Callback p_init) const;
		/**
		 * Sets the optional callback invoked as Godot leaves an initialization level.
		 *
		 * ```cpp
		 * // In the entry point, install cleanup for the scene-level preview cache.
		 * init.register_terminator(+[](ModuleInitializationLevel level) {
		 *     if (level == MODULE_INITIALIZATION_LEVEL_SCENE) { preview_cache.clear(); }
		 * });
		 * ```
		 */
		void register_terminator(Callback p_init) const;
		/**
		 * Sets the earliest initialization level the library requires.
		 *
		 * ```cpp
		 * // After constructing init in the entry point.
		 * init.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);
		 * ```
		 */
		void set_minimum_library_initialization_level(ModuleInitializationLevel p_level) const;

#if GODOT_VERSION_MINOR >= 5
		/**
		 * Sets a callback for main loop startup, after Godot has finished its initialization phases.
		 *
		 * ```cpp
		 * // In the entry point, with print_string.hpp included.
		 * init.register_startup_callback(+[] { print_line("Extension started"); });
		 * ```
		 */
		void register_startup_callback(GDExtensionMainLoopStartupCallback p_callback) const;
		/**
		 * Sets a callback for each process frame after the nodes' `_process()` callbacks and before the script server's frame hook.
		 *
		 * ```cpp
		 * // In the entry point. processed_frames is a persistent application counter.
		 * init.register_frame_callback(+[] { ++processed_frames; });
		 * ```
		 */
		void register_frame_callback(GDExtensionMainLoopFrameCallback p_callback) const;
		/**
		 * Sets a main loop shutdown callback that runs while the engine is still initialized.
		 *
		 * ```cpp
		 * // In the entry point, with print_string.hpp included.
		 * init.register_shutdown_callback(+[] { print_line("Extension shutting down"); });
		 * ```
		 */
		void register_shutdown_callback(GDExtensionMainLoopShutdownCallback p_callback) const;
#endif

		/**
		 * Finalizes binding setup and writes the callback information into the engine's initialization record. The entry point returns this success flag.
		 *
		 * ```cpp
		 * // At the end of the entry point after registering an initializer.
		 * return init.init();
		 * ```
		 */
		GDExtensionBool init() const;
	};
};

} // namespace godot
