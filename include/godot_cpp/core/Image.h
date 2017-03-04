#ifndef IMAGE_H
#define IMAGE_H

#include "Defs.h"

#include "Vector2.h"
#include "Rect2.h"
#include "Color.h"
#include "String.h"

#include <godot/godot_image.h>

namespace godot {

class Image {
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


	Image()
	{
		godot_image_new(&_godot_image);
	}

	Image(const int width, const int height, const bool mipmaps, const Format format)
	{
		godot_image_new_with_size_format(&_godot_image, width, height, mipmaps, (godot_image_format) format);
	}

	void blit_rect(const Image& src, const Rect2& src_rect, const Vector2& dest = Vector2(0, 0))
	{
		// @DLScript @Todo
	}

	void brush_transfer(const Image& src, const Image& brush, const Vector2& pos = Vector2(0, 0))
	{
		// @DLScript @Todo
	}

	Image brushed(const Image& src, const Image& brush, const Vector2& pos = Vector2(0, 0))
	{
		return *this; // @DLScript @Todo
	}

	Image compressed(const Format format)
	{
		return *this; // @DLScript @Todo
	}

	Image converted(const Format format)
	{
		return *this; // @DLScript @Todo
	}

	Image decompressed()
	{
		return *this; // @DLScript @Todo
	}

	bool empty() const
	{
		return true; // @DLScript @Todo
	}

	void fix_alpha_edges()
	{
		// @DLScript @Todo
	}

	/*
	PoolByteArray get_data()
	{
		// @Todo
	}
	*/

	Format get_format() const
	{
		return Format::FORMAT_RGBAH; // @DLScript @Todo
	}

	int get_height() const
	{
		return godot_image_get_height(&_godot_image);
	}

	Color get_pixel(const int x, const int y, const int mipmap_level = 0)
	{
		return Color(); // @DLScript @Todo
	}

	Image get_rect(const Rect2& area = Rect2())
	{
		return *this; // @DLScript @Todo
	}

	Rect2 get_used_rect() const
	{
		return Rect2(); // @DLScript @Todo
	}

	int get_width() const
	{
		return godot_image_get_width(&_godot_image);
	}

	Error load(const String& path)
	{
		return (Error) godot_image_load(&_godot_image, (godot_string *) &path);
	}

	void put_pixel(const int x, const int y, const Color& color, int mipmap_level = 0)
	{
		// @DLScript @Todo
	}

	Image resized(const int x, const int y, const Interpolation interpolation = INTERPOLATE_NEAREST)
	{
		return *this; // @DLScript @Todo
	}

	Error save_png(const String& path)
	{
		return (Error) godot_image_save_png(&_godot_image, (godot_string *) &path); // @Todo Error enum
	}

	~Image()
	{
		godot_image_destroy(&_godot_image);
	}
};

}

#endif // IMAGE_H
