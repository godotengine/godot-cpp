#include "GodotGlobal.hpp"

#include "String.hpp"

namespace godot {

void *_RegisterState::nativescript_handle;
const godot_gdnative_core_api_struct *api = nullptr;
const godot_gdnative_ext_nativescript_api_struct *nativescript_api = nullptr;

void Godot::print(const String& message)
{
	godot::api->godot_print((godot_string *) &message);
}

void Godot::print_warning(const String& description, const String& function, const String& file, int line)
{
	int len;

	char * c_desc = description.alloc_c_string();
	char * c_func = function.alloc_c_string();
	char * c_file = file.alloc_c_string();

	if (c_desc != nullptr && c_func !=nullptr && c_file != nullptr) {
		godot::api->godot_print_warning(c_desc, c_func, c_file, line);
	};

	if (c_desc != nullptr) godot::api->godot_free(c_desc);
	if (c_func != nullptr) godot::api->godot_free(c_func);
	if (c_file != nullptr) godot::api->godot_free(c_file);
}

void Godot::print_error(const String& description, const String& function, const String& file, int line)
{
	int len;

	char * c_desc = description.alloc_c_string();
	char * c_func = function.alloc_c_string();
	char * c_file = file.alloc_c_string();

	if (c_desc != nullptr && c_func !=nullptr && c_file != nullptr) {
		godot::api->godot_print_error(c_desc, c_func, c_file, line);
	};

	if (c_desc != nullptr) godot::api->godot_free(c_desc);
	if (c_func != nullptr) godot::api->godot_free(c_func);
	if (c_file != nullptr) godot::api->godot_free(c_file);
}

void Godot::gdnative_init(godot_gdnative_init_options *options)
{
	godot::api = options->api_struct;

	// now find our extensions
	for (int i = 0; i < godot::api->num_extensions; i++) {
		switch (godot::api->extensions[i]->type) {
			case GDNATIVE_EXT_NATIVESCRIPT: {
				godot::nativescript_api = (godot_gdnative_ext_nativescript_api_struct *)godot::api->extensions[i];
			}; break;
			default: break;
		};
	};
}

void Godot::gdnative_terminate(godot_gdnative_terminate_options *options)
{
	// reserved for future use.
}

void Godot::nativescript_init(void *handle)
{
	godot::_RegisterState::nativescript_handle = handle;
}

};
