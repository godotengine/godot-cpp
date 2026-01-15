/**************************************************************************/
/*  godot.cpp                                                             */
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

#include <godot_cpp/godot.hpp>

#include <godot_cpp/classes/editor_plugin_registration.hpp>
#include <godot_cpp/classes/wrapped.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/load_proc_address.inc>
#include <godot_cpp/core/memory.hpp>
#include <godot_cpp/core/version.hpp>
#include <godot_cpp/variant/variant.hpp>

#include <godot_cpp/core/error_macros.hpp>

#include <stdio.h>

namespace godot {

namespace gdextension_interface {

GDExtensionInterfaceGetProcAddress get_proc_address = nullptr;
GDExtensionClassLibraryPtr library = nullptr;
void *token = nullptr;

#if GODOT_VERSION_MINOR >= 5
GDExtensionGodotVersion2 godot_version = {};
#else
GDExtensionGodotVersion godot_version = {};
#endif

} // namespace gdextension_interface

namespace internal {

struct DocData {
	const char *hash = nullptr;
	int uncompressed_size = 0;
	int compressed_size = 0;
	const unsigned char *data = nullptr;

	inline bool is_valid() const {
		return hash != nullptr && uncompressed_size > 0 && compressed_size > 0 && data != nullptr;
	}

	void load_data() const;
};

static DocData &get_doc_data() {
	static DocData doc_data;
	return doc_data;
}

DocDataRegistration::DocDataRegistration(const char *p_hash, int p_uncompressed_size, int p_compressed_size, const unsigned char *p_data) {
	DocData &doc_data = get_doc_data();
	if (doc_data.is_valid()) {
		printf("ERROR: Attempting to register documentation data when we already have some - discarding.\n");
		return;
	}
	doc_data.hash = p_hash;
	doc_data.uncompressed_size = p_uncompressed_size;
	doc_data.compressed_size = p_compressed_size;
	doc_data.data = p_data;
}

} // namespace internal

bool GDExtensionBinding::api_initialized = false;
int GDExtensionBinding::level_initialized[MODULE_INITIALIZATION_LEVEL_MAX] = { 0 };
GDExtensionBinding::InitDataList GDExtensionBinding::initdata;

// Partial definition of the legacy interface so we can detect it and show an error.
typedef struct {
	uint32_t version_major;
	uint32_t version_minor;
	uint32_t version_patch;
	const char *version_string;

	GDExtensionInterfaceFunctionPtr unused1;
	GDExtensionInterfaceFunctionPtr unused2;
	GDExtensionInterfaceFunctionPtr unused3;

	GDExtensionInterfacePrintError print_error;
	GDExtensionInterfacePrintErrorWithMessage print_error_with_message;
} LegacyGDExtensionInterface;

GDExtensionBool GDExtensionBinding::init(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, InitData *p_init_data, GDExtensionInitialization *r_initialization) {
	if (!p_init_data || !p_init_data->init_callback) {
		ERR_FAIL_V_MSG(false, "Initialization callback must be defined.");
	}

	if (api_initialized) {
		r_initialization->initialize = initialize_level;
		r_initialization->deinitialize = deinitialize_level;
		r_initialization->userdata = p_init_data;
		r_initialization->minimum_initialization_level = p_init_data->minimum_initialization_level;

		return true;
	}

	// Make sure we weren't passed the legacy struct.
	uint32_t *raw_interface = (uint32_t *)(void *)p_get_proc_address;
	if (uintptr_t(p_get_proc_address) % alignof(LegacyGDExtensionInterface) == 0 && raw_interface[0] == 4 && raw_interface[1] == 0) {
		// Use the legacy interface only to give a nice error.
		LegacyGDExtensionInterface *legacy_interface = (LegacyGDExtensionInterface *)p_get_proc_address;
		::godot::gdextension_interface::print_error = (GDExtensionInterfacePrintError)legacy_interface->print_error;
		ERR_PRINT_EARLY("Cannot load a GDExtension built for Godot 4.1+ in Godot 4.0.");
		return false;
	}

	// Load the "print_error" function first (needed by the ERR_PRINT_EARLY() macro).
	::godot::gdextension_interface::print_error = (GDExtensionInterfacePrintError)p_get_proc_address("print_error");
	if (!::godot::gdextension_interface::print_error) {
		printf("ERROR: Unable to load GDExtension interface function print_error().\n");
		return false;
	}

	::godot::gdextension_interface::get_proc_address = p_get_proc_address;
	::godot::gdextension_interface::library = p_library;
	::godot::gdextension_interface::token = p_library;

#if GODOT_VERSION_MINOR >= 5
	LOAD_PROC_ADDRESS(get_godot_version2, GDExtensionInterfaceGetGodotVersion2);
	::godot::gdextension_interface::get_godot_version2(&::godot::gdextension_interface::godot_version);
#else
	LOAD_PROC_ADDRESS(get_godot_version, GDExtensionInterfaceGetGodotVersion);
	::godot::gdextension_interface::get_godot_version(&::godot::gdextension_interface::godot_version);
#endif

	// Check that godot-cpp was compiled using an extension_api.json older or at the
	// same version as the Godot that is loading it.
	bool compatible;
	if (::godot::gdextension_interface::godot_version.major != GODOT_VERSION_MAJOR) {
		compatible = ::godot::gdextension_interface::godot_version.major > GODOT_VERSION_MAJOR;
	} else if (::godot::gdextension_interface::godot_version.minor != GODOT_VERSION_MINOR) {
		compatible = ::godot::gdextension_interface::godot_version.minor > GODOT_VERSION_MINOR;
	} else {
#if GODOT_VERSION_PATCH > 0
		compatible = ::godot::gdextension_interface::godot_version.patch >= GODOT_VERSION_PATCH;
#else
		// Prevent -Wtype-limits warning due to unsigned comparison.
		compatible = true;
#endif
	}
	if (!compatible) {
		// We need to use snprintf() here because vformat() uses Variant, and we haven't loaded
		// the GDExtension interface far enough to use Variants yet.
		char msg[128];
		snprintf(msg, 128, "Cannot load a GDExtension built for Godot %d.%d.%d using an older version of Godot (%d.%d.%d).",
				GODOT_VERSION_MAJOR, GODOT_VERSION_MINOR, GODOT_VERSION_PATCH,
				::godot::gdextension_interface::godot_version.major, ::godot::gdextension_interface::godot_version.minor, ::godot::gdextension_interface::godot_version.patch);
		ERR_PRINT_EARLY(msg);
		return false;
	}

	if (!::godot::internal::load_gdextension_interface(p_get_proc_address)) {
		return false;
	}

	r_initialization->initialize = initialize_level;
	r_initialization->deinitialize = deinitialize_level;
	r_initialization->userdata = p_init_data;
	r_initialization->minimum_initialization_level = p_init_data->minimum_initialization_level;

	Variant::init_bindings();
	::godot::internal::register_engine_classes();

	api_initialized = true;
	return true;
}

#undef LOAD_PROC_ADDRESS
#undef ERR_PRINT_EARLY

void GDExtensionBinding::initialize_level(void *p_userdata, GDExtensionInitializationLevel p_level) {
	ERR_FAIL_COND(static_cast<ModuleInitializationLevel>(p_level) >= MODULE_INITIALIZATION_LEVEL_MAX);
	ClassDB::current_level = p_level;

	InitData *init_data = static_cast<InitData *>(p_userdata);
	if (init_data && init_data->init_callback) {
		init_data->init_callback(static_cast<ModuleInitializationLevel>(p_level));
	}

	if (level_initialized[p_level] == 0) {
		ClassDB::initialize(p_level);
	}
	level_initialized[p_level]++;

#if GODOT_VERSION_MINOR >= 5
	if ((ModuleInitializationLevel)p_level == MODULE_INITIALIZATION_LEVEL_CORE && init_data && init_data->has_main_loop_callbacks()) {
		::godot::gdextension_interface::register_main_loop_callbacks(::godot::gdextension_interface::library, &init_data->main_loop_callbacks);
	}
#endif

	if ((ModuleInitializationLevel)p_level == MODULE_INITIALIZATION_LEVEL_EDITOR) {
#if GODOT_VERSION_MINOR >= 5
		::godot::gdextension_interface::editor_register_get_classes_used_callback(::godot::gdextension_interface::library, &ClassDB::_editor_get_classes_used_callback);
#endif

		const ::godot::internal::DocData &doc_data = ::godot::internal::get_doc_data();
		if (doc_data.is_valid()) {
			doc_data.load_data();
		}
	}
}

void GDExtensionBinding::deinitialize_level(void *p_userdata, GDExtensionInitializationLevel p_level) {
	ERR_FAIL_COND(static_cast<ModuleInitializationLevel>(p_level) >= MODULE_INITIALIZATION_LEVEL_MAX);
	ClassDB::current_level = p_level;

	InitData *init_data = static_cast<InitData *>(p_userdata);
	if (init_data && init_data->terminate_callback) {
		init_data->terminate_callback(static_cast<ModuleInitializationLevel>(p_level));
	}

	level_initialized[p_level]--;
	if (level_initialized[p_level] == 0) {
		EditorPlugins::deinitialize(p_level);
		ClassDB::deinitialize(p_level);
	}
}

void GDExtensionBinding::InitDataList::add(InitData *p_data) {
	if (data_count == data_capacity) {
		void *new_ptr = realloc(data, sizeof(InitData *) * (data_capacity + 32));
		if (new_ptr) {
			data = (InitData **)(new_ptr);
			data_capacity += 32;
		} else {
			ERR_FAIL_MSG("Unable to allocate memory for extension callbacks.");
		}
	}
	data[data_count++] = p_data;
}

GDExtensionBinding::InitDataList::~InitDataList() {
	for (int i = 0; i < data_count; i++) {
		if (data[i]) {
			delete data[i];
		}
	}
	if (data) {
		free(data);
	}
}

GDExtensionBinding::InitObject::InitObject(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
	get_proc_address = p_get_proc_address;
	library = p_library;
	initialization = r_initialization;
	init_data = new InitData();
	GDExtensionBinding::initdata.add(init_data);
}

void GDExtensionBinding::InitObject::register_initializer(Callback p_init) const {
	init_data->init_callback = p_init;
}

void GDExtensionBinding::InitObject::register_terminator(Callback p_terminate) const {
	init_data->terminate_callback = p_terminate;
}

void GDExtensionBinding::InitObject::set_minimum_library_initialization_level(ModuleInitializationLevel p_level) const {
	init_data->minimum_initialization_level = static_cast<GDExtensionInitializationLevel>(p_level);
}

#if GODOT_VERSION_MINOR >= 5
void GDExtensionBinding::InitObject::register_startup_callback(GDExtensionMainLoopStartupCallback p_callback) const {
	init_data->main_loop_callbacks.startup_func = p_callback;
}

void GDExtensionBinding::InitObject::register_frame_callback(GDExtensionMainLoopFrameCallback p_callback) const {
	init_data->main_loop_callbacks.frame_func = p_callback;
}

void GDExtensionBinding::InitObject::register_shutdown_callback(GDExtensionMainLoopShutdownCallback p_callback) const {
	init_data->main_loop_callbacks.shutdown_func = p_callback;
}
#endif

GDExtensionBool GDExtensionBinding::InitObject::init() const {
	return GDExtensionBinding::init(get_proc_address, library, init_data, initialization);
}

void ::godot::internal::DocData::load_data() const {
	PackedByteArray compressed;
	compressed.resize(compressed_size);
	memcpy(compressed.ptrw(), data, compressed_size);

	// FileAccess::COMPRESSION_DEFLATE = 1
	PackedByteArray decompressed = compressed.decompress(uncompressed_size, 1);

	::godot::gdextension_interface::editor_help_load_xml_from_utf8_chars_and_len(reinterpret_cast<const char *>(decompressed.ptr()), uncompressed_size);
}

} // namespace godot
