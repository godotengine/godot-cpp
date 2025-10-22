/* godot-cpp integration testing project.
 *
 * This is free and unencumbered software released into the public domain.
 */

#include "register_types.h"

#include <gdextension_interface.h>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

#include "example.h"
#include "godot_cpp/classes/dir_access.hpp"
#include "godot_cpp/classes/editor_interface.hpp"
#include "godot_cpp/classes/file_access.hpp"
#include "godot_cpp/classes/gd_extension_manager.hpp"
#include "godot_cpp/classes/thread.hpp"
#include "tests.h"

#include <chrono>

using namespace godot;
using std::chrono_literals::operator""s;

// Global flag to control the timer thread
std::atomic keep_running(true);

// Minimal static worker, no class needed
static void timer_thread_function(int interval_ms);

// Global thread ref
static Ref<Thread> g_reload_thread;

// Function to simulate extension reload
void trigger_extension_reload() {
	// Loop if the scene is not yet loaded.
	if (const EditorInterface *ei = EditorInterface::get_singleton();
			!ei->get_edited_scene_root()) {
		return;
	}
	keep_running = false;

	// Trigger the Reload
	const auto gdextension_path = String{ "res://example.gdextension" };
	if (GDExtensionManager *ext_manager = GDExtensionManager::get_singleton()) {
		ext_manager->call_deferred("reload_extension", gdextension_path);
		UtilityFunctions::print("Simulating GDExtension reload...");
	}
}

void timer_thread_function(const int interval_ms) {
	while (keep_running) {
		OS::get_singleton()->delay_msec(interval_ms);
		trigger_extension_reload();
	}
}

void initialize_example_module(ModuleInitializationLevel p_level) {
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE) {
		UtilityFunctions::print("Initializing Integration Testing Extension");
		GDREGISTER_CLASS(ExampleRef);
		GDREGISTER_CLASS(ExampleMin);
		GDREGISTER_CLASS(Example);
		GDREGISTER_VIRTUAL_CLASS(ExampleVirtual);
		GDREGISTER_ABSTRACT_CLASS(ExampleAbstractBase);
		GDREGISTER_CLASS(ExampleConcrete);
		GDREGISTER_CLASS(ExampleBase);
		GDREGISTER_CLASS(ExampleChild);
		GDREGISTER_RUNTIME_CLASS(ExampleRuntime);
		GDREGISTER_CLASS(ExamplePrzykład);
		GDREGISTER_INTERNAL_CLASS(ExampleInternal);
	} else if (p_level == MODULE_INITIALIZATION_LEVEL_EDITOR) {
		if (OS::get_singleton()->get_cmdline_args().has("test_reload")) {
			UtilityFunctions::print("Test Reload is enabled");
			const String lock_path = "res://test_reload_lock";
			if (FileAccess::file_exists(lock_path)) {
				UtilityFunctions::print("Lock File Exists");
			} else {
				UtilityFunctions::print("Creating Timer Thread");
				// Start reload thread with a 3s loop timer.
				g_reload_thread.instantiate();
				g_reload_thread->start(callable_mp_static(&timer_thread_function).bind(3000));

				// Create the lock file to prevent future inits from starting duplicates.
				if (const Ref<FileAccess> lock_file = FileAccess::open(lock_path, FileAccess::WRITE); lock_file.is_valid()) {
					UtilityFunctions::print("Creating Lock File");
					lock_file->close();
				} else {
					UtilityFunctions::print("Warning: Failed to create lock file.");
				}
			}
		}
	}
}

void uninitialize_example_module(ModuleInitializationLevel p_level) {
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE) {
		UtilityFunctions::print("Uninitializing Integration Testing Extension");
	} else if (p_level == MODULE_INITIALIZATION_LEVEL_EDITOR) {
		// Stop the timer thread when deinitializing
		keep_running = false;

		// Join reload thread if ever started
		if (g_reload_thread.is_valid()) {
			UtilityFunctions::print("Waiting for reload thread to finish...");
			// Loop-check for race safety (up to ~3s max, your interval)
			for (int i = 0; i < 10; ++i) { // Arbitrary retries; adjust if needed
				if (g_reload_thread->is_alive()) {
					OS::get_singleton()->delay_msec(300); // Short poll delay
				} else {
					break;
				}
			}
			g_reload_thread->wait_to_finish(); // Blocks until done; safe even if not alive
			g_reload_thread.unref();
			UtilityFunctions::print("Reload thread joined.");
		}
	}
}

extern "C" {
// Initialization.
GDExtensionBool GDE_EXPORT example_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
	GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

	init_obj.register_initializer(initialize_example_module);
	init_obj.register_terminator(uninitialize_example_module);
	init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

	return init_obj.init();
}
}
