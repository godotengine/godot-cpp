#ifndef GODOT_CPP_LARGETEXTURE_HPP
#define GODOT_CPP_LARGETEXTURE_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Texture.hpp>
namespace godot {

class Texture;

class LargeTexture : public Texture {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "LargeTexture"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static LargeTexture *_new();

	// methods
	int64_t add_piece(const Vector2 ofs, const Ref<Texture> texture);
	void set_piece_offset(const int64_t idx, const Vector2 ofs);
	void set_piece_texture(const int64_t idx, const Ref<Texture> texture);
	void set_size(const Vector2 size);
	void clear();
	int64_t get_piece_count() const;
	Vector2 get_piece_offset(const int64_t idx) const;
	Ref<Texture> get_piece_texture(const int64_t idx) const;
	void _set_data(const Array data);
	Array _get_data() const;

};

}

#endif