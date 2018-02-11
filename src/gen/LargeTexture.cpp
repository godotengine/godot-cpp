#include <LargeTexture.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Texture.hpp>


namespace godot {


void *LargeTexture::___get_type_tag()
{
	return (void *) &LargeTexture::___get_type_tag;
}

void *LargeTexture::___get_base_type_tag()
{
	return (void *) &Texture::___get_type_tag;
}

LargeTexture *LargeTexture::_new()
{
	return (LargeTexture *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"LargeTexture")());
}
int64_t LargeTexture::add_piece(const Vector2 ofs, const Ref<Texture> texture) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LargeTexture", "add_piece");
	}
	return ___godot_icall_int_Vector2_Object(mb, (const Object *) this, ofs, texture.ptr());
}

void LargeTexture::set_piece_offset(const int64_t idx, const Vector2 ofs) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LargeTexture", "set_piece_offset");
	}
	___godot_icall_void_int_Vector2(mb, (const Object *) this, idx, ofs);
}

void LargeTexture::set_piece_texture(const int64_t idx, const Ref<Texture> texture) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LargeTexture", "set_piece_texture");
	}
	___godot_icall_void_int_Object(mb, (const Object *) this, idx, texture.ptr());
}

void LargeTexture::set_size(const Vector2 size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LargeTexture", "set_size");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, size);
}

void LargeTexture::clear() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LargeTexture", "clear");
	}
	___godot_icall_void(mb, (const Object *) this);
}

int64_t LargeTexture::get_piece_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LargeTexture", "get_piece_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

Vector2 LargeTexture::get_piece_offset(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LargeTexture", "get_piece_offset");
	}
	return ___godot_icall_Vector2_int(mb, (const Object *) this, idx);
}

Ref<Texture> LargeTexture::get_piece_texture(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LargeTexture", "get_piece_texture");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object_int(mb, (const Object *) this, idx));
}

void LargeTexture::_set_data(const Array data) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LargeTexture", "_set_data");
	}
	___godot_icall_void_Array(mb, (const Object *) this, data);
}

Array LargeTexture::_get_data() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LargeTexture", "_get_data");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

}