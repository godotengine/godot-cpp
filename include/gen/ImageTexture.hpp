#ifndef GODOT_CPP_IMAGETEXTURE_HPP
#define GODOT_CPP_IMAGETEXTURE_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <Image.hpp>
#include <ImageTexture.hpp>

#include <Texture.hpp>
namespace godot {

class Image;

class ImageTexture : public Texture {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "ImageTexture"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum Storage {
		STORAGE_COMPRESS_LOSSLESS = 2,
		STORAGE_COMPRESS_LOSSY = 1,
		STORAGE_RAW = 0,
	};

	// constants


	static ImageTexture *_new();

	// methods
	void create(const int64_t width, const int64_t height, const int64_t format, const int64_t flags = 7);
	void create_from_image(const Ref<Image> image, const int64_t flags = 7);
	Image::Format get_format() const;
	void load(const String path);
	void set_data(const Ref<Image> image);
	void set_storage(const int64_t mode);
	ImageTexture::Storage get_storage() const;
	void set_lossy_storage_quality(const double quality);
	double get_lossy_storage_quality() const;
	void set_size_override(const Vector2 size);
	void _reload_hook(const RID rid);

};

}

#endif