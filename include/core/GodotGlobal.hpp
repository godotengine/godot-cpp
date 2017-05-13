#ifndef GODOT_GLOBAL_HPP
#define GODOT_GLOBAL_HPP

#if defined(_WIN32)
#  ifdef _GD_CPP_CORE_API_IMPL
#    define GD_CPP_CORE_API __declspec(dllexport)
#  else
#    define GD_CPP_CORE_API __declspec(dllimport)
#  endif
#else
#  define GD_CPP_CORE_API
#endif

#include "String.hpp"


namespace godot {

class GD_CPP_CORE_API Godot {

public:
	static void print(const String& message);
	static void print_warning(const String& description, const String& function, const String& file, int line);
	static void print_error(const String& description, const String& function, const String& file, int line);

};

}

#endif
