#ifndef GODOT_CPP_BITMAP_HPP
#define GODOT_CPP_BITMAP_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Resource.hpp>
namespace godot {

class Image;

class BitMap : public Resource {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "BitMap"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static BitMap *_new();

	// methods
	void create(const Vector2 size);
	void create_from_image_alpha(const Ref<Image> image, const double threshold = 0.1);
	void set_bit(const Vector2 position, const bool bit);
	bool get_bit(const Vector2 position) const;
	void set_bit_rect(const Rect2 p_rect, const bool bit);
	int64_t get_true_bit_count() const;
	Vector2 get_size() const;
	void _set_data(const Dictionary arg0);
	Dictionary _get_data() const;

};

}

#endif