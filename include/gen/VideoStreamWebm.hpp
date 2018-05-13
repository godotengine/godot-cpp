#ifndef GODOT_CPP_VIDEOSTREAMWEBM_HPP
#define GODOT_CPP_VIDEOSTREAMWEBM_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "VideoStream.hpp"
namespace godot {


class VideoStreamWebm : public VideoStream {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "VideoStreamWebm"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static VideoStreamWebm *_new();

	// methods
	void set_file(const String file);
	String get_file();

};

}

#endif