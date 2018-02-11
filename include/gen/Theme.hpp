#ifndef GODOT_CPP_THEME_HPP
#define GODOT_CPP_THEME_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Resource.hpp>
namespace godot {

class Texture;
class StyleBox;
class Font;

class Theme : public Resource {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Theme"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static Theme *_new();

	// methods
	void set_icon(const String name, const String type, const Ref<Texture> texture);
	Ref<Texture> get_icon(const String name, const String type) const;
	bool has_icon(const String name, const String type) const;
	void clear_icon(const String name, const String type);
	PoolStringArray get_icon_list(const String type) const;
	void set_stylebox(const String name, const String type, const Ref<StyleBox> texture);
	Ref<StyleBox> get_stylebox(const String name, const String type) const;
	bool has_stylebox(const String name, const String type) const;
	void clear_stylebox(const String name, const String type);
	PoolStringArray get_stylebox_list(const String type) const;
	PoolStringArray get_stylebox_types() const;
	void set_font(const String name, const String type, const Ref<Font> font);
	Ref<Font> get_font(const String name, const String type) const;
	bool has_font(const String name, const String type) const;
	void clear_font(const String name, const String type);
	PoolStringArray get_font_list(const String type) const;
	void set_color(const String name, const String type, const Color color);
	Color get_color(const String name, const String type) const;
	bool has_color(const String name, const String type) const;
	void clear_color(const String name, const String type);
	PoolStringArray get_color_list(const String type) const;
	void set_constant(const String name, const String type, const int64_t constant);
	int64_t get_constant(const String name, const String type) const;
	bool has_constant(const String name, const String type) const;
	void clear_constant(const String name, const String type);
	PoolStringArray get_constant_list(const String type) const;
	void set_default_font(const Ref<Font> font);
	Ref<Font> get_default_font() const;
	PoolStringArray get_type_list(const String type) const;
	void _emit_theme_changed();
	void copy_default_theme();

};

}

#endif