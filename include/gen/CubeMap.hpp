#ifndef GODOT_CPP_CUBEMAP_HPP
#define GODOT_CPP_CUBEMAP_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <CubeMap.hpp>

#include <Resource.hpp>
namespace godot {

class Image;

class CubeMap : public Resource {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "CubeMap"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum Flags {
		FLAG_MIPMAPS = 1,
		FLAG_FILTER = 4,
		FLAG_REPEAT = 2,
		FLAGS_DEFAULT = 7,
	};
	enum Side {
		SIDE_FRONT = 4,
		SIDE_LEFT = 0,
		SIDE_BACK = 5,
		SIDE_BOTTOM = 2,
		SIDE_RIGHT = 1,
		SIDE_TOP = 3,
	};
	enum Storage {
		STORAGE_COMPRESS_LOSSLESS = 2,
		STORAGE_COMPRESS_LOSSY = 1,
		STORAGE_RAW = 0,
	};

	// constants


	static CubeMap *_new();

	// methods
	int64_t get_width() const;
	int64_t get_height() const;
	void set_flags(const int64_t flags);
	int64_t get_flags() const;
	void set_side(const int64_t side, const Ref<Image> image);
	Ref<Image> get_side(const int64_t side) const;
	void set_storage(const int64_t mode);
	CubeMap::Storage get_storage() const;
	void set_lossy_storage_quality(const double quality);
	double get_lossy_storage_quality() const;

};

}

#endif