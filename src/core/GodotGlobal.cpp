#include "GodotGlobal.hpp"

#include "String.hpp"

#include <godot_nativescript.h>

namespace godot {

void Godot::print(const String& message)
{
	godot_print((godot_string *) &message);
}

void Godot::print_warning(const String& description, const String& function, const String& file, int line)
{
	godot_print_warning(description.c_string(), function.c_string(), file.c_string(), line);
}

void Godot::print_error(const String& description, const String& function, const String& file, int line)
{
	godot_print_error(description.c_string(), function.c_string(), file.c_string(), line);
}

};
