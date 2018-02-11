#include <TextureProgress.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Texture.hpp>


namespace godot {


void *TextureProgress::___get_type_tag()
{
	return (void *) &TextureProgress::___get_type_tag;
}

void *TextureProgress::___get_base_type_tag()
{
	return (void *) &Range::___get_type_tag;
}

TextureProgress *TextureProgress::_new()
{
	return (TextureProgress *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"TextureProgress")());
}
void TextureProgress::set_under_texture(const Ref<Texture> tex) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextureProgress", "set_under_texture");
	}
	___godot_icall_void_Object(mb, (const Object *) this, tex.ptr());
}

Ref<Texture> TextureProgress::get_under_texture() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextureProgress", "get_under_texture");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void TextureProgress::set_progress_texture(const Ref<Texture> tex) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextureProgress", "set_progress_texture");
	}
	___godot_icall_void_Object(mb, (const Object *) this, tex.ptr());
}

Ref<Texture> TextureProgress::get_progress_texture() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextureProgress", "get_progress_texture");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void TextureProgress::set_over_texture(const Ref<Texture> tex) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextureProgress", "set_over_texture");
	}
	___godot_icall_void_Object(mb, (const Object *) this, tex.ptr());
}

Ref<Texture> TextureProgress::get_over_texture() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextureProgress", "get_over_texture");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void TextureProgress::set_fill_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextureProgress", "set_fill_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

int64_t TextureProgress::get_fill_mode() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextureProgress", "get_fill_mode");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void TextureProgress::set_radial_initial_angle(const double mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextureProgress", "set_radial_initial_angle");
	}
	___godot_icall_void_float(mb, (const Object *) this, mode);
}

double TextureProgress::get_radial_initial_angle() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextureProgress", "get_radial_initial_angle");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void TextureProgress::set_radial_center_offset(const Vector2 mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextureProgress", "set_radial_center_offset");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, mode);
}

Vector2 TextureProgress::get_radial_center_offset() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextureProgress", "get_radial_center_offset");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void TextureProgress::set_fill_degrees(const double mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextureProgress", "set_fill_degrees");
	}
	___godot_icall_void_float(mb, (const Object *) this, mode);
}

double TextureProgress::get_fill_degrees() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextureProgress", "get_fill_degrees");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void TextureProgress::set_stretch_margin(const int64_t margin, const int64_t value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextureProgress", "set_stretch_margin");
	}
	___godot_icall_void_int_int(mb, (const Object *) this, margin, value);
}

int64_t TextureProgress::get_stretch_margin(const int64_t margin) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextureProgress", "get_stretch_margin");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, margin);
}

void TextureProgress::set_nine_patch_stretch(const bool stretch) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextureProgress", "set_nine_patch_stretch");
	}
	___godot_icall_void_bool(mb, (const Object *) this, stretch);
}

bool TextureProgress::get_nine_patch_stretch() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextureProgress", "get_nine_patch_stretch");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

}