#ifndef GODOT_CPP_PARALLAXBACKGROUND_HPP
#define GODOT_CPP_PARALLAXBACKGROUND_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "CanvasLayer.hpp"
namespace godot {


class ParallaxBackground : public CanvasLayer {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "ParallaxBackground"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static ParallaxBackground *_new();

	// methods
	void _camera_moved(const Transform2D arg0, const Vector2 arg1);
	void set_scroll_offset(const Vector2 ofs);
	Vector2 get_scroll_offset() const;
	void set_scroll_base_offset(const Vector2 ofs);
	Vector2 get_scroll_base_offset() const;
	void set_scroll_base_scale(const Vector2 scale);
	Vector2 get_scroll_base_scale() const;
	void set_limit_begin(const Vector2 ofs);
	Vector2 get_limit_begin() const;
	void set_limit_end(const Vector2 ofs);
	Vector2 get_limit_end() const;
	void set_ignore_camera_zoom(const bool ignore);
	bool is_ignore_camera_zoom();

};

}

#endif