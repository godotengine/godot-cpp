#include "register_types.h"

#include <godot/gdnative_interface.h>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

#include "example.h"

using namespace godot;

void register_example_types() {
	ClassDB::register_class<Example>();
}

void unregister_example_types() {}

extern "C" {

// Initialization.

GDNativeBool GDN_EXPORT example_library_init(const GDNativeInterface *p_interface, const GDNativeExtensionClassLibraryPtr p_library, GDNativeInitialization *r_initialization) {
	GDNativeBool result = godot::GDExtensionBinding::init(p_interface, p_library, r_initialization);

	if (result) {
		register_example_types();
	}

	return result;
}

void GDN_EXPORT initialize_level(void *userdata, GDNativeInitializationLevel p_level) {
	godot::GDExtensionBinding::initialize_level(userdata, p_level);
}

void GDN_EXPORT deinitialize_level(void *userdata, GDNativeInitializationLevel p_level) {
	godot::GDExtensionBinding::deinitialize_level(userdata, p_level);
}
}
