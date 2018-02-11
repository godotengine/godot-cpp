#ifndef GODOT_CPP_DYNAMICFONT_HPP
#define GODOT_CPP_DYNAMICFONT_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Font.hpp>
namespace godot {

class DynamicFontData;

class DynamicFont : public Font {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "DynamicFont"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum SpacingType {
		SPACING_SPACE = 3,
		SPACING_TOP = 0,
		SPACING_BOTTOM = 1,
		SPACING_CHAR = 2,
	};

	// constants


	static DynamicFont *_new();

	// methods
	void set_font_data(const Ref<DynamicFontData> data);
	Ref<DynamicFontData> get_font_data() const;
	void set_size(const int64_t data);
	int64_t get_size() const;
	void set_use_mipmaps(const bool enable);
	bool get_use_mipmaps() const;
	void set_use_filter(const bool enable);
	bool get_use_filter() const;
	void set_spacing(const int64_t type, const int64_t value);
	int64_t get_spacing(const int64_t type) const;
	void add_fallback(const Ref<DynamicFontData> data);
	void set_fallback(const int64_t idx, const Ref<DynamicFontData> data);
	Ref<DynamicFontData> get_fallback(const int64_t idx) const;
	void remove_fallback(const int64_t idx);
	int64_t get_fallback_count() const;

};

}

#endif