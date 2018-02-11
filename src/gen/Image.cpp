#include <Image.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Image.hpp>


namespace godot {


void *Image::___get_type_tag()
{
	return (void *) &Image::___get_type_tag;
}

void *Image::___get_base_type_tag()
{
	return (void *) &Resource::___get_type_tag;
}

Image *Image::_new()
{
	return (Image *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Image")());
}
int64_t Image::get_width() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "get_width");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t Image::get_height() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "get_height");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

Vector2 Image::get_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "get_size");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

bool Image::has_mipmaps() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "has_mipmaps");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

Image::Format Image::get_format() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "get_format");
	}
	return (Image::Format) ___godot_icall_int(mb, (const Object *) this);
}

PoolByteArray Image::get_data() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "get_data");
	}
	return ___godot_icall_PoolByteArray(mb, (const Object *) this);
}

void Image::convert(const int64_t format) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "convert");
	}
	___godot_icall_void_int(mb, (const Object *) this, format);
}

int64_t Image::get_mipmap_offset(const int64_t mipmap) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "get_mipmap_offset");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, mipmap);
}

void Image::resize_to_po2(const bool square) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "resize_to_po2");
	}
	___godot_icall_void_bool(mb, (const Object *) this, square);
}

void Image::resize(const int64_t width, const int64_t height, const int64_t interpolation) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "resize");
	}
	___godot_icall_void_int_int_int(mb, (const Object *) this, width, height, interpolation);
}

void Image::shrink_x2() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "shrink_x2");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Image::expand_x2_hq2x() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "expand_x2_hq2x");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Image::crop(const int64_t width, const int64_t height) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "crop");
	}
	___godot_icall_void_int_int(mb, (const Object *) this, width, height);
}

void Image::flip_x() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "flip_x");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Image::flip_y() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "flip_y");
	}
	___godot_icall_void(mb, (const Object *) this);
}

Error Image::generate_mipmaps() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "generate_mipmaps");
	}
	return (Error) ___godot_icall_int(mb, (const Object *) this);
}

void Image::clear_mipmaps() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "clear_mipmaps");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Image::create(const int64_t width, const int64_t height, const bool use_mipmaps, const int64_t format) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "create");
	}
	___godot_icall_void_int_int_bool_int(mb, (const Object *) this, width, height, use_mipmaps, format);
}

void Image::create_from_data(const int64_t width, const int64_t height, const bool use_mipmaps, const int64_t format, const PoolByteArray data) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "create_from_data");
	}
	___godot_icall_void_int_int_bool_int_PoolByteArray(mb, (const Object *) this, width, height, use_mipmaps, format, data);
}

bool Image::is_empty() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "is_empty");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

Error Image::load(const String path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "load");
	}
	return (Error) ___godot_icall_int_String(mb, (const Object *) this, path);
}

Error Image::save_png(const String path) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "save_png");
	}
	return (Error) ___godot_icall_int_String(mb, (const Object *) this, path);
}

Image::AlphaMode Image::detect_alpha() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "detect_alpha");
	}
	return (Image::AlphaMode) ___godot_icall_int(mb, (const Object *) this);
}

bool Image::is_invisible() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "is_invisible");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

Error Image::compress(const int64_t mode, const int64_t source, const double lossy_quality) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "compress");
	}
	return (Error) ___godot_icall_int_int_int_float(mb, (const Object *) this, mode, source, lossy_quality);
}

Error Image::decompress() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "decompress");
	}
	return (Error) ___godot_icall_int(mb, (const Object *) this);
}

bool Image::is_compressed() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "is_compressed");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Image::fix_alpha_edges() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "fix_alpha_edges");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Image::premultiply_alpha() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "premultiply_alpha");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Image::srgb_to_linear() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "srgb_to_linear");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Image::normalmap_to_xy() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "normalmap_to_xy");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Image::blit_rect(const Ref<Image> src, const Rect2 src_rect, const Vector2 dst) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "blit_rect");
	}
	___godot_icall_void_Object_Rect2_Vector2(mb, (const Object *) this, src.ptr(), src_rect, dst);
}

void Image::blit_rect_mask(const Ref<Image> src, const Ref<Image> mask, const Rect2 src_rect, const Vector2 dst) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "blit_rect_mask");
	}
	___godot_icall_void_Object_Object_Rect2_Vector2(mb, (const Object *) this, src.ptr(), mask.ptr(), src_rect, dst);
}

void Image::blend_rect(const Ref<Image> src, const Rect2 src_rect, const Vector2 dst) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "blend_rect");
	}
	___godot_icall_void_Object_Rect2_Vector2(mb, (const Object *) this, src.ptr(), src_rect, dst);
}

void Image::blend_rect_mask(const Ref<Image> src, const Ref<Image> mask, const Rect2 src_rect, const Vector2 dst) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "blend_rect_mask");
	}
	___godot_icall_void_Object_Object_Rect2_Vector2(mb, (const Object *) this, src.ptr(), mask.ptr(), src_rect, dst);
}

void Image::fill(const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "fill");
	}
	___godot_icall_void_Color(mb, (const Object *) this, color);
}

Rect2 Image::get_used_rect() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "get_used_rect");
	}
	return ___godot_icall_Rect2(mb, (const Object *) this);
}

Ref<Image> Image::get_rect(const Rect2 rect) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "get_rect");
	}
	return Ref<Image>::__internal_constructor(___godot_icall_Object_Rect2(mb, (const Object *) this, rect));
}

void Image::copy_from(const Ref<Image> src) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "copy_from");
	}
	___godot_icall_void_Object(mb, (const Object *) this, src.ptr());
}

void Image::_set_data(const Dictionary data) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "_set_data");
	}
	___godot_icall_void_Dictionary(mb, (const Object *) this, data);
}

Dictionary Image::_get_data() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "_get_data");
	}
	return ___godot_icall_Dictionary(mb, (const Object *) this);
}

void Image::lock() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "lock");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Image::unlock() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "unlock");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Image::set_pixel(const int64_t x, const int64_t y, const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "set_pixel");
	}
	___godot_icall_void_int_int_Color(mb, (const Object *) this, x, y, color);
}

Color Image::get_pixel(const int64_t x, const int64_t y) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "get_pixel");
	}
	return ___godot_icall_Color_int_int(mb, (const Object *) this, x, y);
}

Error Image::load_png_from_buffer(const PoolByteArray buffer) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "load_png_from_buffer");
	}
	return (Error) ___godot_icall_int_PoolByteArray(mb, (const Object *) this, buffer);
}

Error Image::load_jpg_from_buffer(const PoolByteArray buffer) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Image", "load_jpg_from_buffer");
	}
	return (Error) ___godot_icall_int_PoolByteArray(mb, (const Object *) this, buffer);
}

}