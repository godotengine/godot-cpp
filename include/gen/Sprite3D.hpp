#ifndef GODOT_CPP_SPRITE3D_HPP
#define GODOT_CPP_SPRITE3D_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "SpriteBase3D.hpp"
namespace godot {

class Texture;

class Sprite3D : public SpriteBase3D {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Sprite3D"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static Sprite3D *_new();

	// methods
	void set_texture(const Ref<Texture> texture);
	Ref<Texture> get_texture() const;
	void set_region(const bool enabled);
	bool is_region() const;
	void set_region_rect(const Rect2 rect);
	Rect2 get_region_rect() const;
	void set_frame(const int64_t frame);
	int64_t get_frame() const;
	void set_vframes(const int64_t vframes);
	int64_t get_vframes() const;
	void set_hframes(const int64_t hframes);
	int64_t get_hframes() const;

};

}

#endif