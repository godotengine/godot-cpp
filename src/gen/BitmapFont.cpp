#include <BitmapFont.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Texture.hpp>
#include <BitmapFont.hpp>


namespace godot {


void *BitmapFont::___get_type_tag()
{
	return (void *) &BitmapFont::___get_type_tag;
}

void *BitmapFont::___get_base_type_tag()
{
	return (void *) &Font::___get_type_tag;
}

BitmapFont *BitmapFont::_new()
{
	return (BitmapFont *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"BitmapFont")());
}
Error BitmapFont::create_from_fnt(const String path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BitmapFont", "create_from_fnt");
	}
	return (Error) ___godot_icall_int_String(mb, (const Object *) this, path);
}

void BitmapFont::set_height(const double px) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BitmapFont", "set_height");
	}
	___godot_icall_void_float(mb, (const Object *) this, px);
}

void BitmapFont::set_ascent(const double px) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BitmapFont", "set_ascent");
	}
	___godot_icall_void_float(mb, (const Object *) this, px);
}

void BitmapFont::add_kerning_pair(const int64_t char_a, const int64_t char_b, const int64_t kerning) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BitmapFont", "add_kerning_pair");
	}
	___godot_icall_void_int_int_int(mb, (const Object *) this, char_a, char_b, kerning);
}

int64_t BitmapFont::get_kerning_pair(const int64_t char_a, const int64_t char_b) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BitmapFont", "get_kerning_pair");
	}
	return ___godot_icall_int_int_int(mb, (const Object *) this, char_a, char_b);
}

void BitmapFont::add_texture(const Ref<Texture> texture) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BitmapFont", "add_texture");
	}
	___godot_icall_void_Object(mb, (const Object *) this, texture.ptr());
}

void BitmapFont::add_char(const int64_t character, const int64_t texture, const Rect2 rect, const Vector2 align, const double advance) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BitmapFont", "add_char");
	}
	___godot_icall_void_int_int_Rect2_Vector2_float(mb, (const Object *) this, character, texture, rect, align, advance);
}

int64_t BitmapFont::get_texture_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BitmapFont", "get_texture_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

Ref<Texture> BitmapFont::get_texture(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BitmapFont", "get_texture");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object_int(mb, (const Object *) this, idx));
}

Vector2 BitmapFont::get_char_size(const int64_t _char, const int64_t next) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BitmapFont", "get_char_size");
	}
	return ___godot_icall_Vector2_int_int(mb, (const Object *) this, _char, next);
}

void BitmapFont::set_distance_field_hint(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BitmapFont", "set_distance_field_hint");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

void BitmapFont::clear() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BitmapFont", "clear");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void BitmapFont::_set_chars(const PoolIntArray arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BitmapFont", "_set_chars");
	}
	___godot_icall_void_PoolIntArray(mb, (const Object *) this, arg0);
}

PoolIntArray BitmapFont::_get_chars() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BitmapFont", "_get_chars");
	}
	return ___godot_icall_PoolIntArray(mb, (const Object *) this);
}

void BitmapFont::_set_kernings(const PoolIntArray arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BitmapFont", "_set_kernings");
	}
	___godot_icall_void_PoolIntArray(mb, (const Object *) this, arg0);
}

PoolIntArray BitmapFont::_get_kernings() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BitmapFont", "_get_kernings");
	}
	return ___godot_icall_PoolIntArray(mb, (const Object *) this);
}

void BitmapFont::_set_textures(const Array arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BitmapFont", "_set_textures");
	}
	___godot_icall_void_Array(mb, (const Object *) this, arg0);
}

Array BitmapFont::_get_textures() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BitmapFont", "_get_textures");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

void BitmapFont::set_fallback(const Ref<BitmapFont> fallback) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BitmapFont", "set_fallback");
	}
	___godot_icall_void_Object(mb, (const Object *) this, fallback.ptr());
}

Ref<BitmapFont> BitmapFont::get_fallback() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BitmapFont", "get_fallback");
	}
	return Ref<BitmapFont>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

}