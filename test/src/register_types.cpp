/* godot-cpp integration testing project.
 *
 * This is free and unencumbered software released into the public domain.
 */

#include "register_types.h"

#include <gdextension_interface.h>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

#include "my_test.h"
#include "tests.h"

using namespace godot;

void initialize_my_test_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	GDREGISTER_CLASS(MyTestRef);
	GDREGISTER_CLASS(MyTestMin);
	GDREGISTER_CLASS(MyTestMain);
	GDREGISTER_VIRTUAL_CLASS(MyTestVirtual);
	GDREGISTER_ABSTRACT_CLASS(MyTestAbstractBase);
	GDREGISTER_CLASS(MyTestConcrete);
	GDREGISTER_CLASS(MyTestBase);
	GDREGISTER_CLASS(MyTestChild);
	GDREGISTER_RUNTIME_CLASS(MyTestRuntime);
	GDREGISTER_CLASS(MyTestPrzykład);
	GDREGISTER_INTERNAL_CLASS(MyTestInternal);
	GDREGISTER_CLASS(MyTestThreadSafeClass);
}

void uninitialize_my_test_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}

extern "C" {
// Initialization.
GDExtensionBool GDE_EXPORT my_test_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
	::godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

	init_obj.register_initializer(initialize_my_test_module);
	init_obj.register_terminator(uninitialize_my_test_module);
	init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

	return init_obj.init();
}
}
