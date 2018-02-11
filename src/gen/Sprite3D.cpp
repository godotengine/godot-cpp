#include <Sprite3D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Texture.hpp>


namespace godot {


void *Sprite3D::___get_type_tag()
{
	return (void *) &Sprite3D::___get_type_tag;
}

void *Sprite3D::___get_base_type_tag()
{
	return (void *) &SpriteBase3D::___get_type_tag;
}

Sprite3D *Sprite3D::_new()
{
	return (Sprite3D *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Sprite3D")());
}
void Sprite3D::set_texture(const Ref<Texture> texture) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Sprite3D", "set_texture");
	}
	___godot_icall_void_Object(mb, (const Object *) this, texture.ptr());
}

Ref<Texture> Sprite3D::get_texture() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Sprite3D", "get_texture");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void Sprite3D::set_region(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Sprite3D", "set_region");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool Sprite3D::is_region() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Sprite3D", "is_region");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Sprite3D::set_region_rect(const Rect2 rect) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Sprite3D", "set_region_rect");
	}
	___godot_icall_void_Rect2(mb, (const Object *) this, rect);
}

Rect2 Sprite3D::get_region_rect() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Sprite3D", "get_region_rect");
	}
	return ___godot_icall_Rect2(mb, (const Object *) this);
}

void Sprite3D::set_frame(const int64_t frame) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Sprite3D", "set_frame");
	}
	___godot_icall_void_int(mb, (const Object *) this, frame);
}

int64_t Sprite3D::get_frame() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Sprite3D", "get_frame");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void Sprite3D::set_vframes(const int64_t vframes) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Sprite3D", "set_vframes");
	}
	___godot_icall_void_int(mb, (const Object *) this, vframes);
}

int64_t Sprite3D::get_vframes() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Sprite3D", "get_vframes");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void Sprite3D::set_hframes(const int64_t hframes) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Sprite3D", "set_hframes");
	}
	___godot_icall_void_int(mb, (const Object *) this, hframes);
}

int64_t Sprite3D::get_hframes() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Sprite3D", "get_hframes");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

}