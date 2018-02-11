#include <Particles2D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Material.hpp>
#include <Texture.hpp>


namespace godot {


void *Particles2D::___get_type_tag()
{
	return (void *) &Particles2D::___get_type_tag;
}

void *Particles2D::___get_base_type_tag()
{
	return (void *) &Node2D::___get_type_tag;
}

Particles2D *Particles2D::_new()
{
	return (Particles2D *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Particles2D")());
}
void Particles2D::set_emitting(const bool emitting) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles2D", "set_emitting");
	}
	___godot_icall_void_bool(mb, (const Object *) this, emitting);
}

void Particles2D::set_amount(const int64_t amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles2D", "set_amount");
	}
	___godot_icall_void_int(mb, (const Object *) this, amount);
}

void Particles2D::set_lifetime(const double secs) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles2D", "set_lifetime");
	}
	___godot_icall_void_float(mb, (const Object *) this, secs);
}

void Particles2D::set_one_shot(const bool secs) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles2D", "set_one_shot");
	}
	___godot_icall_void_bool(mb, (const Object *) this, secs);
}

void Particles2D::set_pre_process_time(const double secs) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles2D", "set_pre_process_time");
	}
	___godot_icall_void_float(mb, (const Object *) this, secs);
}

void Particles2D::set_explosiveness_ratio(const double ratio) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles2D", "set_explosiveness_ratio");
	}
	___godot_icall_void_float(mb, (const Object *) this, ratio);
}

void Particles2D::set_randomness_ratio(const double ratio) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles2D", "set_randomness_ratio");
	}
	___godot_icall_void_float(mb, (const Object *) this, ratio);
}

void Particles2D::set_visibility_rect(const Rect2 aabb) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles2D", "set_visibility_rect");
	}
	___godot_icall_void_Rect2(mb, (const Object *) this, aabb);
}

void Particles2D::set_use_local_coordinates(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles2D", "set_use_local_coordinates");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

void Particles2D::set_fixed_fps(const int64_t fps) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles2D", "set_fixed_fps");
	}
	___godot_icall_void_int(mb, (const Object *) this, fps);
}

void Particles2D::set_fractional_delta(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles2D", "set_fractional_delta");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

void Particles2D::set_process_material(const Ref<Material> material) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles2D", "set_process_material");
	}
	___godot_icall_void_Object(mb, (const Object *) this, material.ptr());
}

void Particles2D::set_speed_scale(const double scale) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles2D", "set_speed_scale");
	}
	___godot_icall_void_float(mb, (const Object *) this, scale);
}

bool Particles2D::is_emitting() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles2D", "is_emitting");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

int64_t Particles2D::get_amount() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles2D", "get_amount");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

double Particles2D::get_lifetime() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles2D", "get_lifetime");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

bool Particles2D::get_one_shot() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles2D", "get_one_shot");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

double Particles2D::get_pre_process_time() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles2D", "get_pre_process_time");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

double Particles2D::get_explosiveness_ratio() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles2D", "get_explosiveness_ratio");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

double Particles2D::get_randomness_ratio() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles2D", "get_randomness_ratio");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

Rect2 Particles2D::get_visibility_rect() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles2D", "get_visibility_rect");
	}
	return ___godot_icall_Rect2(mb, (const Object *) this);
}

bool Particles2D::get_use_local_coordinates() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles2D", "get_use_local_coordinates");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

int64_t Particles2D::get_fixed_fps() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles2D", "get_fixed_fps");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

bool Particles2D::get_fractional_delta() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles2D", "get_fractional_delta");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

Ref<Material> Particles2D::get_process_material() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles2D", "get_process_material");
	}
	return Ref<Material>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

double Particles2D::get_speed_scale() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles2D", "get_speed_scale");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Particles2D::set_draw_order(const int64_t order) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles2D", "set_draw_order");
	}
	___godot_icall_void_int(mb, (const Object *) this, order);
}

Particles2D::DrawOrder Particles2D::get_draw_order() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles2D", "get_draw_order");
	}
	return (Particles2D::DrawOrder) ___godot_icall_int(mb, (const Object *) this);
}

void Particles2D::set_texture(const Ref<Texture> texture) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles2D", "set_texture");
	}
	___godot_icall_void_Object(mb, (const Object *) this, texture.ptr());
}

Ref<Texture> Particles2D::get_texture() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles2D", "get_texture");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void Particles2D::set_normal_map(const Ref<Texture> texture) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles2D", "set_normal_map");
	}
	___godot_icall_void_Object(mb, (const Object *) this, texture.ptr());
}

Ref<Texture> Particles2D::get_normal_map() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles2D", "get_normal_map");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

Rect2 Particles2D::capture_rect() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles2D", "capture_rect");
	}
	return ___godot_icall_Rect2(mb, (const Object *) this);
}

void Particles2D::set_v_frames(const int64_t frames) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles2D", "set_v_frames");
	}
	___godot_icall_void_int(mb, (const Object *) this, frames);
}

int64_t Particles2D::get_v_frames() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles2D", "get_v_frames");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void Particles2D::set_h_frames(const int64_t frames) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles2D", "set_h_frames");
	}
	___godot_icall_void_int(mb, (const Object *) this, frames);
}

int64_t Particles2D::get_h_frames() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles2D", "get_h_frames");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void Particles2D::restart() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles2D", "restart");
	}
	___godot_icall_void(mb, (const Object *) this);
}

}