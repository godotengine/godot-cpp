#ifndef GODOT_CPP_BACKBUFFERCOPY_HPP
#define GODOT_CPP_BACKBUFFERCOPY_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <BackBufferCopy.hpp>

#include <Node2D.hpp>
namespace godot {


class BackBufferCopy : public Node2D {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "BackBufferCopy"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum CopyMode {
		COPY_MODE_DISABLED = 0,
		COPY_MODE_RECT = 1,
		COPY_MODE_VIEWPORT = 2,
	};

	// constants


	static BackBufferCopy *_new();

	// methods
	void set_rect(const Rect2 rect);
	Rect2 get_rect() const;
	void set_copy_mode(const int64_t copy_mode);
	BackBufferCopy::CopyMode get_copy_mode() const;

};

}

#endif