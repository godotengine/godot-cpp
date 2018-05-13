#ifndef GODOT_CPP_TEXTURE_HPP
#define GODOT_CPP_TEXTURE_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Resource.hpp"
namespace godot {

class Texture;
class Image;

class Texture : public Resource {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Texture"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum Flags {
		FLAG_FILTER = 4,
		FLAG_CONVERT_TO_LINEAR = 16,
		FLAG_VIDEO_SURFACE = 4096,
		FLAGS_DEFAULT = 7,
		FLAG_MIRRORED_REPEAT = 32,
		FLAG_MIPMAPS = 1,
		FLAG_ANISOTROPIC_FILTER = 8,
		FLAG_REPEAT = 2,
	};

	// constants

	// methods
	int64_t get_width() const;
	int64_t get_height() const;
	Vector2 get_size() const;
	bool has_alpha() const;
	void set_flags(const int64_t flags);
	int64_t get_flags() const;
	void draw(const RID canvas_item, const Vector2 position, const Color modulate = Color(1,1,1,1), const bool transpose = false, const Ref<Texture> normal_map = nullptr) const;
	void draw_rect(const RID canvas_item, const Rect2 rect, const bool tile, const Color modulate = Color(1,1,1,1), const bool transpose = false, const Ref<Texture> normal_map = nullptr) const;
	void draw_rect_region(const RID canvas_item, const Rect2 rect, const Rect2 src_rect, const Color modulate = Color(1,1,1,1), const bool transpose = false, const Ref<Texture> normal_map = nullptr, const bool clip_uv = true) const;
	Ref<Image> get_data() const;

};

}

#endif