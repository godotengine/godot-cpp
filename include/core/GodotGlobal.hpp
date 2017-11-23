#ifndef GODOT_GLOBAL_HPP
#define GODOT_GLOBAL_HPP

#include <gdnative_api_struct.gen.h>
#include "String.hpp"


namespace godot {

extern "C" const godot_gdnative_core_api_struct *api;
extern "C" const godot_gdnative_ext_nativescript_api_struct *nativescript_api;

class Godot {

public:
	static void print(const String& message);
	static void print_warning(const String& description, const String& function, const String& file, int line);
	static void print_error(const String& description, const String& function, const String& file, int line);

};



struct _RegisterState {
	static void *nativescript_handle;
};

}

#endif
