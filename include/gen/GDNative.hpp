#ifndef GODOT_CPP_GDNATIVE_HPP
#define GODOT_CPP_GDNATIVE_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Reference.hpp"
namespace godot {

class GDNativeLibrary;

class GDNative : public Reference {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "GDNative"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static GDNative *_new();

	// methods
	void set_library(const Ref<GDNativeLibrary> library);
	Ref<GDNativeLibrary> get_library();
	bool initialize();
	bool terminate();
	Variant call_native(const String calling_type, const String procedure_name, const Array arguments);

};

}

#endif