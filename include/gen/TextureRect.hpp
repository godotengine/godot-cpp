#ifndef GODOT_CPP_TEXTURERECT_HPP
#define GODOT_CPP_TEXTURERECT_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <TextureRect.hpp>

#include <Control.hpp>
namespace godot {

class Texture;

class TextureRect : public Control {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "TextureRect"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum StretchMode {
		STRETCH_SCALE = 1,
		STRETCH_KEEP = 3,
		STRETCH_KEEP_ASPECT = 5,
		STRETCH_SCALE_ON_EXPAND = 0,
		STRETCH_TILE = 2,
		STRETCH_KEEP_ASPECT_CENTERED = 6,
		STRETCH_KEEP_CENTERED = 4,
		STRETCH_KEEP_ASPECT_COVERED = 7,
	};

	// constants


	static TextureRect *_new();

	// methods
	void set_texture(const Ref<Texture> texture);
	Ref<Texture> get_texture() const;
	void set_expand(const bool enable);
	bool has_expand() const;
	void set_stretch_mode(const int64_t stretch_mode);
	TextureRect::StretchMode get_stretch_mode() const;

};

}

#endif