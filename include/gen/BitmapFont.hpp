#ifndef GODOT_CPP_BITMAPFONT_HPP
#define GODOT_CPP_BITMAPFONT_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Font.hpp>
namespace godot {

class Texture;
class BitmapFont;

class BitmapFont : public Font {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "BitmapFont"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static BitmapFont *_new();

	// methods
	Error create_from_fnt(const String path);
	void set_height(const double px);
	void set_ascent(const double px);
	void add_kerning_pair(const int64_t char_a, const int64_t char_b, const int64_t kerning);
	int64_t get_kerning_pair(const int64_t char_a, const int64_t char_b) const;
	void add_texture(const Ref<Texture> texture);
	void add_char(const int64_t character, const int64_t texture, const Rect2 rect, const Vector2 align = Vector2(0, 0), const double advance = -1);
	int64_t get_texture_count() const;
	Ref<Texture> get_texture(const int64_t idx) const;
	Vector2 get_char_size(const int64_t _char, const int64_t next = 0) const;
	void set_distance_field_hint(const bool enable);
	void clear();
	void _set_chars(const PoolIntArray arg0);
	PoolIntArray _get_chars() const;
	void _set_kernings(const PoolIntArray arg0);
	PoolIntArray _get_kernings() const;
	void _set_textures(const Array arg0);
	Array _get_textures() const;
	void set_fallback(const Ref<BitmapFont> fallback);
	Ref<BitmapFont> get_fallback() const;

};

}

#endif