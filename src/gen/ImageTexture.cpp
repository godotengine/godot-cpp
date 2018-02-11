#include <ImageTexture.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Image.hpp>


namespace godot {


void *ImageTexture::___get_type_tag()
{
	return (void *) &ImageTexture::___get_type_tag;
}

void *ImageTexture::___get_base_type_tag()
{
	return (void *) &Texture::___get_type_tag;
}

ImageTexture *ImageTexture::_new()
{
	return (ImageTexture *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"ImageTexture")());
}
void ImageTexture::create(const int64_t width, const int64_t height, const int64_t format, const int64_t flags) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ImageTexture", "create");
	}
	___godot_icall_void_int_int_int_int(mb, (const Object *) this, width, height, format, flags);
}

void ImageTexture::create_from_image(const Ref<Image> image, const int64_t flags) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ImageTexture", "create_from_image");
	}
	___godot_icall_void_Object_int(mb, (const Object *) this, image.ptr(), flags);
}

Image::Format ImageTexture::get_format() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ImageTexture", "get_format");
	}
	return (Image::Format) ___godot_icall_int(mb, (const Object *) this);
}

void ImageTexture::load(const String path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ImageTexture", "load");
	}
	___godot_icall_void_String(mb, (const Object *) this, path);
}

void ImageTexture::set_data(const Ref<Image> image) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ImageTexture", "set_data");
	}
	___godot_icall_void_Object(mb, (const Object *) this, image.ptr());
}

void ImageTexture::set_storage(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ImageTexture", "set_storage");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

ImageTexture::Storage ImageTexture::get_storage() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ImageTexture", "get_storage");
	}
	return (ImageTexture::Storage) ___godot_icall_int(mb, (const Object *) this);
}

void ImageTexture::set_lossy_storage_quality(const double quality) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ImageTexture", "set_lossy_storage_quality");
	}
	___godot_icall_void_float(mb, (const Object *) this, quality);
}

double ImageTexture::get_lossy_storage_quality() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ImageTexture", "get_lossy_storage_quality");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void ImageTexture::set_size_override(const Vector2 size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ImageTexture", "set_size_override");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, size);
}

void ImageTexture::_reload_hook(const RID rid) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ImageTexture", "_reload_hook");
	}
	___godot_icall_void_RID(mb, (const Object *) this, rid);
}

}