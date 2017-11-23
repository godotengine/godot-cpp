#include "GodotGlobal.hpp"

#include "String.hpp"

namespace godot {

void *_RegisterState::nativescript_handle;
const godot_gdnative_core_api_struct *api = NULL;
const godot_gdnative_ext_nativescript_api_struct *nativescript_api = NULL;

void Godot::print(const String& message)
{
	godot::api->godot_print((godot_string *) &message);
}

void Godot::print_warning(const String& description, const String& function, const String& file, int line)
{
	int len;

	description.get_c_string(NULL, &len);
	char * c_desc = (char *)godot::api->godot_alloc(len + 1);
	description.get_c_string(c_desc, &len);
	c_desc[len] = '\0';

	function.get_c_string(NULL, &len);
	char * c_func = (char *)godot::api->godot_alloc(len + 1);
	function.get_c_string(c_func, &len);
	c_func[len] = '\0';

	file.get_c_string(NULL, &len);
	char * c_file = (char *)godot::api->godot_alloc(len + 1);
	file.get_c_string(c_file, &len);
	c_file[len] = '\0';

	godot::api->godot_print_warning(c_desc, c_func, c_file, line);

	godot::api->godot_free(c_desc);
	godot::api->godot_free(c_func);
	godot::api->godot_free(c_file);
}

void Godot::print_error(const String& description, const String& function, const String& file, int line)
{
	int len;

	description.get_c_string(NULL, &len);
	char * c_desc = (char *)godot::api->godot_alloc(len + 1);
	description.get_c_string(c_desc, &len);
	c_desc[len] = '\0';

	function.get_c_string(NULL, &len);
	char * c_func = (char *)godot::api->godot_alloc(len + 1);
	function.get_c_string(c_func, &len);
	c_func[len] = '\0';

	file.get_c_string(NULL, &len);
	char * c_file = (char *)godot::api->godot_alloc(len + 1);
	file.get_c_string(c_file, &len);
	c_file[len] = '\0';

	godot::api->godot_print_error(c_desc, c_func, c_file, line);

	godot::api->godot_free(c_desc);
	godot::api->godot_free(c_func);
	godot::api->godot_free(c_file);
}

};

void gdnative_init(godot_gdnative_init_options *options);
extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options *options)
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

	gdnative_init(options);
}

void gdnative_terminate(godot_gdnative_terminate_options *options);
extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options *options)
{
	gdnative_terminate(options);
}

void nativescript_init();
extern "C" void GDN_EXPORT godot_nativescript_init(void *handle)
{
	godot::_RegisterState::nativescript_handle = handle;
	nativescript_init();
}
