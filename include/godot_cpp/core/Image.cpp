#include "Image.h"

#include "Defs.h"

#include "Vector2.h"
#include "Rect2.h"
#include "Color.h"
#include "String.h"

#include "PoolArrays.h"

#include <godot/godot_image.h>

namespace godot {

Image::Image()
{
	godot_image_new(&_godot_image);
}

Image::Image(const int width, const int height, const bool mipmaps, const Format format)
{
	godot_image_new_with_size_format(&_godot_image, width, height, mipmaps, (godot_image_format) format);
}

void Image::blit_rect(const Image& src, const Rect2& src_rect, const Vector2& dest)
{
	// @DLScript @Todo
}

void Image::brush_transfer(const Image& src, const Image& brush, const Vector2& pos)
{
	// @DLScript @Todo
}

Image Image::brushed(const Image& src, const Image& brush, const Vector2& pos)
{
	return *this; // @DLScript @Todo
}

Image Image::compressed(const Format format)
{
	return *this; // @DLScript @Todo
}

Image Image::converted(const Format format)
{
	return *this; // @DLScript @Todo
}

Image Image::decompressed()
{
	return *this; // @DLScript @Todo
}

bool Image::empty() const
{
	return true; // @DLScript @Todo
}

void Image::fix_alpha_edges()
{
	// @DLScript @Todo
}


PoolByteArray Image::get_data()
{
	// @Todo
	return PoolByteArray();
}


Image::Format Image::get_format() const
{
	return Format::FORMAT_RGBAH; // @DLScript @Todo
}

int Image::get_height() const
{
	return godot_image_get_height(&_godot_image);
}

Color Image::get_pixel(const int x, const int y, const int mipmap_level)
{
	return Color(); // @DLScript @Todo
}

Image Image::get_rect(const Rect2& area)
{
	return *this; // @DLScript @Todo
}

Rect2 Image::get_used_rect() const
{
	return Rect2(); // @DLScript @Todo
}

int Image::get_width() const
{
	return godot_image_get_width(&_godot_image);
}

Error Image::load(const String& path)
{
	return (Error) godot_image_load(&_godot_image, (godot_string *) &path);
}

void Image::put_pixel(const int x, const int y, const Color& color, int mipmap_level)
{
	// @DLScript @Todo
}

Image Image::resized(const int x, const int y, const Interpolation interpolation)
{
	return *this; // @DLScript @Todo
}

Error Image::save_png(const String& path)
{
	return (Error) godot_image_save_png(&_godot_image, (godot_string *) &path); // @Todo Error enum
}

Image::~Image()
{
	godot_image_destroy(&_godot_image);
}


}
