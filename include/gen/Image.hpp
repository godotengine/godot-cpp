#ifndef GODOT_CPP_IMAGE_HPP
#define GODOT_CPP_IMAGE_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include "Image.hpp"

#include "Resource.hpp"
namespace godot {

class Image;

class Image : public Resource {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Image"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum AlphaMode {
		ALPHA_BLEND = 2,
		ALPHA_BIT = 1,
		ALPHA_NONE = 0,
	};
	enum CompressSource {
		COMPRESS_SOURCE_NORMAL = 2,
		COMPRESS_SOURCE_GENERIC = 0,
		COMPRESS_SOURCE_SRGB = 1,
	};
	enum Interpolation {
		INTERPOLATE_CUBIC = 2,
		INTERPOLATE_BILINEAR = 1,
		INTERPOLATE_NEAREST = 0,
	};
	enum CompressMode {
		COMPRESS_ETC2 = 4,
		COMPRESS_PVRTC2 = 1,
		COMPRESS_PVRTC4 = 2,
		COMPRESS_ETC = 3,
		COMPRESS_S3TC = 0,
	};
	enum Format {
		FORMAT_RGTC_RG = 21,
		FORMAT_RGB8 = 4,
		FORMAT_ETC2_RGBA8 = 35,
		FORMAT_BPTC_RGBFU = 24,
		FORMAT_MAX = 37,
		FORMAT_RG8 = 3,
		FORMAT_BPTC_RGBA = 22,
		FORMAT_RGBE9995 = 16,
		FORMAT_ETC2_RGB8A1 = 36,
		FORMAT_ETC2_R11S = 31,
		FORMAT_R8 = 2,
		FORMAT_RGBAH = 15,
		FORMAT_RGBAF = 11,
		FORMAT_ETC = 29,
		FORMAT_RF = 8,
		FORMAT_ETC2_R11 = 30,
		FORMAT_ETC2_RGB8 = 34,
		FORMAT_RGBA5551 = 7,
		FORMAT_RH = 12,
		FORMAT_RGTC_R = 20,
		FORMAT_RGBA8 = 5,
		FORMAT_L8 = 0,
		FORMAT_ETC2_RG11 = 32,
		FORMAT_RGBF = 10,
		FORMAT_ETC2_RG11S = 33,
		FORMAT_LA8 = 1,
		FORMAT_PVRTC4 = 27,
		FORMAT_RGF = 9,
		FORMAT_RGBH = 14,
		FORMAT_PVRTC2A = 26,
		FORMAT_PVRTC2 = 25,
		FORMAT_PVRTC4A = 28,
		FORMAT_RGBA4444 = 6,
		FORMAT_DXT5 = 19,
		FORMAT_DXT3 = 18,
		FORMAT_RGH = 13,
		FORMAT_DXT1 = 17,
		FORMAT_BPTC_RGBF = 23,
	};

	// constants


	static Image *_new();

	// methods
	int64_t get_width() const;
	int64_t get_height() const;
	Vector2 get_size() const;
	bool has_mipmaps() const;
	Image::Format get_format() const;
	PoolByteArray get_data() const;
	void convert(const int64_t format);
	int64_t get_mipmap_offset(const int64_t mipmap) const;
	void resize_to_po2(const bool square = false);
	void resize(const int64_t width, const int64_t height, const int64_t interpolation = 1);
	void shrink_x2();
	void expand_x2_hq2x();
	void crop(const int64_t width, const int64_t height);
	void flip_x();
	void flip_y();
	Error generate_mipmaps(const bool renormalize = false);
	void clear_mipmaps();
	void create(const int64_t width, const int64_t height, const bool use_mipmaps, const int64_t format);
	void create_from_data(const int64_t width, const int64_t height, const bool use_mipmaps, const int64_t format, const PoolByteArray data);
	bool is_empty() const;
	Error load(const String path);
	Error save_png(const String path) const;
	Image::AlphaMode detect_alpha() const;
	bool is_invisible() const;
	Error compress(const int64_t mode, const int64_t source, const double lossy_quality);
	Error decompress();
	bool is_compressed() const;
	void fix_alpha_edges();
	void premultiply_alpha();
	void srgb_to_linear();
	void normalmap_to_xy();
	void bumpmap_to_normalmap(const double bump_scale = 1);
	void blit_rect(const Ref<Image> src, const Rect2 src_rect, const Vector2 dst);
	void blit_rect_mask(const Ref<Image> src, const Ref<Image> mask, const Rect2 src_rect, const Vector2 dst);
	void blend_rect(const Ref<Image> src, const Rect2 src_rect, const Vector2 dst);
	void blend_rect_mask(const Ref<Image> src, const Ref<Image> mask, const Rect2 src_rect, const Vector2 dst);
	void fill(const Color color);
	Rect2 get_used_rect() const;
	Ref<Image> get_rect(const Rect2 rect) const;
	void copy_from(const Ref<Image> src);
	void _set_data(const Dictionary data);
	Dictionary _get_data() const;
	void lock();
	void unlock();
	Color get_pixelv(const Vector2 src) const;
	Color get_pixel(const int64_t x, const int64_t y) const;
	void set_pixelv(const Vector2 dst, const Color color);
	void set_pixel(const int64_t x, const int64_t y, const Color color);
	Error load_png_from_buffer(const PoolByteArray buffer);
	Error load_jpg_from_buffer(const PoolByteArray buffer);

};

}

#endif