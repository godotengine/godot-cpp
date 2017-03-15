#ifndef IMAGE_H
#define IMAGE_H

#if defined(_WIN32)
#  ifdef _GD_CPP_CORE_API_IMPL
#    define GD_CPP_CORE_API __declspec(dllexport)
#  else
#    define GD_CPP_CORE_API __declspec(dllimport)
#  endif
#else
#  define GD_CPP_CORE_API
#endif

#include "Defs.hpp"

#include "Vector2.hpp"
#include "Rect2.hpp"
#include "Color.hpp"
#include "String.hpp"

#include <godot/godot_image.h>

namespace godot {

class PoolByteArray;

class GD_CPP_CORE_API Image {
	godot_image _godot_image;
public:

	enum Format {

		FORMAT_L8, //luminance
		FORMAT_LA8, //luminance-alpha
		FORMAT_R8,
		FORMAT_RG8,
		FORMAT_RGB8,
		FORMAT_RGBA8,
		FORMAT_RGB565, //16 bit
		FORMAT_RGBA4444,
		FORMAT_RGBA5551,
		FORMAT_RF, //float
		FORMAT_RGF,
		FORMAT_RGBF,
		FORMAT_RGBAF,
		FORMAT_RH, //half float
		FORMAT_RGH,
		FORMAT_RGBH,
		FORMAT_RGBAH,
		FORMAT_DXT1, //s3tc bc1
		FORMAT_DXT3, //bc2
		FORMAT_DXT5, //bc3
		FORMAT_ATI1, //bc4
		FORMAT_ATI2, //bc5
		FORMAT_BPTC_RGBA, //btpc bc6h
		FORMAT_BPTC_RGBF, //float /
		FORMAT_BPTC_RGBFU, //unsigned float
		FORMAT_PVRTC2, //pvrtc
		FORMAT_PVRTC2A,
		FORMAT_PVRTC4,
		FORMAT_PVRTC4A,
		FORMAT_ETC, //etc1
		FORMAT_ETC2_R11, //etc2
		FORMAT_ETC2_R11S, //signed, NOT srgb.
		FORMAT_ETC2_RG11,
		FORMAT_ETC2_RG11S,
		FORMAT_ETC2_RGB8,
		FORMAT_ETC2_RGBA8,
		FORMAT_ETC2_RGB8A1,
		FORMAT_MAX
	};

	enum Interpolation {

		INTERPOLATE_NEAREST,
		INTERPOLATE_BILINEAR,
		INTERPOLATE_CUBIC,
		/* INTERPOLATE GAUSS */
	};

	enum CompressMode {
		COMPRESS_16BIT,
		COMPRESS_S3TC,
		COMPRESS_PVRTC2,
		COMPRESS_PVRTC4,
		COMPRESS_ETC,
		COMPRESS_ETC2
	};


	Image();

	Image(const int width, const int height, const bool mipmaps, const Format format);

	void blit_rect(const Image& src, const Rect2& src_rect, const Vector2& dest = Vector2(0, 0));

	void brush_transfer(const Image& src, const Image& brush, const Vector2& pos = Vector2(0, 0));

	Image brushed(const Image& src, const Image& brush, const Vector2& pos = Vector2(0, 0));

	Image compressed(const Format format);

	Image converted(const Format format);

	Image decompressed();

	bool empty() const;

	void fix_alpha_edges();

	PoolByteArray get_data();


	Format get_format() const;

	int get_height() const;

	Color get_pixel(const int x, const int y, const int mipmap_level = 0);

	Image get_rect(const Rect2& area = Rect2());

	Rect2 get_used_rect() const;

	int get_width() const;

	Error load(const String& path);

	void put_pixel(const int x, const int y, const Color& color, int mipmap_level = 0);

	Image resized(const int x, const int y, const Interpolation interpolation = INTERPOLATE_NEAREST);

	Error save_png(const String& path);

	~Image();
};

}

#endif // IMAGE_H
