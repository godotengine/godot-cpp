#include <SpriteBase3D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *SpriteBase3D::___get_type_tag()
{
	return (void *) &SpriteBase3D::___get_type_tag;
}

void *SpriteBase3D::___get_base_type_tag()
{
	return (void *) &GeometryInstance::___get_type_tag;
}

void SpriteBase3D::set_centered(const bool centered) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpriteBase3D", "set_centered");
	}
	___godot_icall_void_bool(mb, (const Object *) this, centered);
}

bool SpriteBase3D::is_centered() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpriteBase3D", "is_centered");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void SpriteBase3D::set_offset(const Vector2 offset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpriteBase3D", "set_offset");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, offset);
}

Vector2 SpriteBase3D::get_offset() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpriteBase3D", "get_offset");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void SpriteBase3D::set_flip_h(const bool flip_h) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpriteBase3D", "set_flip_h");
	}
	___godot_icall_void_bool(mb, (const Object *) this, flip_h);
}

bool SpriteBase3D::is_flipped_h() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpriteBase3D", "is_flipped_h");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void SpriteBase3D::set_flip_v(const bool flip_v) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpriteBase3D", "set_flip_v");
	}
	___godot_icall_void_bool(mb, (const Object *) this, flip_v);
}

bool SpriteBase3D::is_flipped_v() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpriteBase3D", "is_flipped_v");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void SpriteBase3D::set_modulate(const Color modulate) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpriteBase3D", "set_modulate");
	}
	___godot_icall_void_Color(mb, (const Object *) this, modulate);
}

Color SpriteBase3D::get_modulate() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpriteBase3D", "get_modulate");
	}
	return ___godot_icall_Color(mb, (const Object *) this);
}

void SpriteBase3D::set_opacity(const double opacity) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpriteBase3D", "set_opacity");
	}
	___godot_icall_void_float(mb, (const Object *) this, opacity);
}

double SpriteBase3D::get_opacity() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpriteBase3D", "get_opacity");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void SpriteBase3D::set_pixel_size(const double pixel_size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpriteBase3D", "set_pixel_size");
	}
	___godot_icall_void_float(mb, (const Object *) this, pixel_size);
}

double SpriteBase3D::get_pixel_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpriteBase3D", "get_pixel_size");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void SpriteBase3D::set_axis(const int64_t axis) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpriteBase3D", "set_axis");
	}
	___godot_icall_void_int(mb, (const Object *) this, axis);
}

Vector3::Axis SpriteBase3D::get_axis() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpriteBase3D", "get_axis");
	}
	return (Vector3::Axis) ___godot_icall_int(mb, (const Object *) this);
}

void SpriteBase3D::set_draw_flag(const int64_t flag, const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpriteBase3D", "set_draw_flag");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, flag, enabled);
}

bool SpriteBase3D::get_draw_flag(const int64_t flag) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpriteBase3D", "get_draw_flag");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, flag);
}

void SpriteBase3D::set_alpha_cut_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpriteBase3D", "set_alpha_cut_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

SpriteBase3D::AlphaCutMode SpriteBase3D::get_alpha_cut_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpriteBase3D", "get_alpha_cut_mode");
	}
	return (SpriteBase3D::AlphaCutMode) ___godot_icall_int(mb, (const Object *) this);
}

Rect2 SpriteBase3D::get_item_rect() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpriteBase3D", "get_item_rect");
	}
	return ___godot_icall_Rect2(mb, (const Object *) this);
}

void SpriteBase3D::_queue_update() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpriteBase3D", "_queue_update");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void SpriteBase3D::_im_update() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpriteBase3D", "_im_update");
	}
	___godot_icall_void(mb, (const Object *) this);
}

}