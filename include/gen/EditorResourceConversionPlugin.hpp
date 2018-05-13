#ifndef GODOT_CPP_EDITORRESOURCECONVERSIONPLUGIN_HPP
#define GODOT_CPP_EDITORRESOURCECONVERSIONPLUGIN_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Reference.hpp"
namespace godot {

class Resource;

class EditorResourceConversionPlugin : public Reference {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "EditorResourceConversionPlugin"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static EditorResourceConversionPlugin *_new();

	// methods
	Ref<Resource> _convert(const Ref<Resource> resource);
	String _converts_to();

};

}

#endif