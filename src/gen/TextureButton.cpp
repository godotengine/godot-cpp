#include <TextureButton.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Texture.hpp>
#include <BitMap.hpp>


namespace godot {


void *TextureButton::___get_type_tag()
{
	return (void *) &TextureButton::___get_type_tag;
}

void *TextureButton::___get_base_type_tag()
{
	return (void *) &BaseButton::___get_type_tag;
}

TextureButton *TextureButton::_new()
{
	return (TextureButton *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"TextureButton")());
}
void TextureButton::set_normal_texture(const Ref<Texture> texture) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextureButton", "set_normal_texture");
	}
	___godot_icall_void_Object(mb, (const Object *) this, texture.ptr());
}

void TextureButton::set_pressed_texture(const Ref<Texture> texture) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextureButton", "set_pressed_texture");
	}
	___godot_icall_void_Object(mb, (const Object *) this, texture.ptr());
}

void TextureButton::set_hover_texture(const Ref<Texture> texture) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextureButton", "set_hover_texture");
	}
	___godot_icall_void_Object(mb, (const Object *) this, texture.ptr());
}

void TextureButton::set_disabled_texture(const Ref<Texture> texture) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextureButton", "set_disabled_texture");
	}
	___godot_icall_void_Object(mb, (const Object *) this, texture.ptr());
}

void TextureButton::set_focused_texture(const Ref<Texture> texture) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextureButton", "set_focused_texture");
	}
	___godot_icall_void_Object(mb, (const Object *) this, texture.ptr());
}

void TextureButton::set_click_mask(const Ref<BitMap> mask) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextureButton", "set_click_mask");
	}
	___godot_icall_void_Object(mb, (const Object *) this, mask.ptr());
}

void TextureButton::set_expand(const bool p_expand) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextureButton", "set_expand");
	}
	___godot_icall_void_bool(mb, (const Object *) this, p_expand);
}

void TextureButton::set_stretch_mode(const int64_t p_mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextureButton", "set_stretch_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, p_mode);
}

Ref<Texture> TextureButton::get_normal_texture() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextureButton", "get_normal_texture");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

Ref<Texture> TextureButton::get_pressed_texture() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextureButton", "get_pressed_texture");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

Ref<Texture> TextureButton::get_hover_texture() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextureButton", "get_hover_texture");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

Ref<Texture> TextureButton::get_disabled_texture() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextureButton", "get_disabled_texture");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

Ref<Texture> TextureButton::get_focused_texture() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextureButton", "get_focused_texture");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

Ref<BitMap> TextureButton::get_click_mask() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextureButton", "get_click_mask");
	}
	return Ref<BitMap>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

bool TextureButton::get_expand() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextureButton", "get_expand");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

TextureButton::StretchMode TextureButton::get_stretch_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextureButton", "get_stretch_mode");
	}
	return (TextureButton::StretchMode) ___godot_icall_int(mb, (const Object *) this);
}

}