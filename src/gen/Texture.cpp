#include <Texture.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Texture.hpp>
#include <Image.hpp>


namespace godot {


void *Texture::___get_type_tag()
{
	return (void *) &Texture::___get_type_tag;
}

void *Texture::___get_base_type_tag()
{
	return (void *) &Resource::___get_type_tag;
}

int64_t Texture::get_width() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Texture", "get_width");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t Texture::get_height() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Texture", "get_height");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

Vector2 Texture::get_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Texture", "get_size");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

bool Texture::has_alpha() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Texture", "has_alpha");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Texture::set_flags(const int64_t flags) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Texture", "set_flags");
	}
	___godot_icall_void_int(mb, (const Object *) this, flags);
}

int64_t Texture::get_flags() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Texture", "get_flags");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void Texture::draw(const RID canvas_item, const Vector2 position, const Color modulate, const bool transpose, const Ref<Texture> normal_map) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Texture", "draw");
	}
	___godot_icall_void_RID_Vector2_Color_bool_Object(mb, (const Object *) this, canvas_item, position, modulate, transpose, normal_map.ptr());
}

void Texture::draw_rect(const RID canvas_item, const Rect2 rect, const bool tile, const Color modulate, const bool transpose, const Ref<Texture> normal_map) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Texture", "draw_rect");
	}
	___godot_icall_void_RID_Rect2_bool_Color_bool_Object(mb, (const Object *) this, canvas_item, rect, tile, modulate, transpose, normal_map.ptr());
}

void Texture::draw_rect_region(const RID canvas_item, const Rect2 rect, const Rect2 src_rect, const Color modulate, const bool transpose, const Ref<Texture> normal_map, const bool clip_uv) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Texture", "draw_rect_region");
	}
	___godot_icall_void_RID_Rect2_Rect2_Color_bool_Object_bool(mb, (const Object *) this, canvas_item, rect, src_rect, modulate, transpose, normal_map.ptr(), clip_uv);
}

Ref<Image> Texture::get_data() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Texture", "get_data");
	}
	return Ref<Image>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

}