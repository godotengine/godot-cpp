#include <TextureRect.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Texture.hpp>


namespace godot {


void *TextureRect::___get_type_tag()
{
	return (void *) &TextureRect::___get_type_tag;
}

void *TextureRect::___get_base_type_tag()
{
	return (void *) &Control::___get_type_tag;
}

TextureRect *TextureRect::_new()
{
	return (TextureRect *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"TextureRect")());
}
void TextureRect::set_texture(const Ref<Texture> texture) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextureRect", "set_texture");
	}
	___godot_icall_void_Object(mb, (const Object *) this, texture.ptr());
}

Ref<Texture> TextureRect::get_texture() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextureRect", "get_texture");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void TextureRect::set_expand(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextureRect", "set_expand");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool TextureRect::has_expand() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextureRect", "has_expand");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void TextureRect::set_stretch_mode(const int64_t stretch_mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextureRect", "set_stretch_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, stretch_mode);
}

TextureRect::StretchMode TextureRect::get_stretch_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TextureRect", "get_stretch_mode");
	}
	return (TextureRect::StretchMode) ___godot_icall_int(mb, (const Object *) this);
}

}