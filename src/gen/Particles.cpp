#include <Particles.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Material.hpp>
#include <Mesh.hpp>


namespace godot {


void *Particles::___get_type_tag()
{
	return (void *) &Particles::___get_type_tag;
}

void *Particles::___get_base_type_tag()
{
	return (void *) &GeometryInstance::___get_type_tag;
}

Particles *Particles::_new()
{
	return (Particles *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Particles")());
}
void Particles::set_emitting(const bool emitting) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles", "set_emitting");
	}
	___godot_icall_void_bool(mb, (const Object *) this, emitting);
}

void Particles::set_amount(const int64_t amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles", "set_amount");
	}
	___godot_icall_void_int(mb, (const Object *) this, amount);
}

void Particles::set_lifetime(const double secs) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles", "set_lifetime");
	}
	___godot_icall_void_float(mb, (const Object *) this, secs);
}

void Particles::set_one_shot(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles", "set_one_shot");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

void Particles::set_pre_process_time(const double secs) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles", "set_pre_process_time");
	}
	___godot_icall_void_float(mb, (const Object *) this, secs);
}

void Particles::set_explosiveness_ratio(const double ratio) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles", "set_explosiveness_ratio");
	}
	___godot_icall_void_float(mb, (const Object *) this, ratio);
}

void Particles::set_randomness_ratio(const double ratio) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles", "set_randomness_ratio");
	}
	___godot_icall_void_float(mb, (const Object *) this, ratio);
}

void Particles::set_visibility_aabb(const AABB aabb) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles", "set_visibility_aabb");
	}
	___godot_icall_void_AABB(mb, (const Object *) this, aabb);
}

void Particles::set_use_local_coordinates(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles", "set_use_local_coordinates");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

void Particles::set_fixed_fps(const int64_t fps) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles", "set_fixed_fps");
	}
	___godot_icall_void_int(mb, (const Object *) this, fps);
}

void Particles::set_fractional_delta(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles", "set_fractional_delta");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

void Particles::set_process_material(const Ref<Material> material) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles", "set_process_material");
	}
	___godot_icall_void_Object(mb, (const Object *) this, material.ptr());
}

void Particles::set_speed_scale(const double scale) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles", "set_speed_scale");
	}
	___godot_icall_void_float(mb, (const Object *) this, scale);
}

bool Particles::is_emitting() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles", "is_emitting");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

int64_t Particles::get_amount() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles", "get_amount");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

double Particles::get_lifetime() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles", "get_lifetime");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

bool Particles::get_one_shot() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles", "get_one_shot");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

double Particles::get_pre_process_time() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles", "get_pre_process_time");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

double Particles::get_explosiveness_ratio() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles", "get_explosiveness_ratio");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

double Particles::get_randomness_ratio() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles", "get_randomness_ratio");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

AABB Particles::get_visibility_aabb() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles", "get_visibility_aabb");
	}
	return ___godot_icall_AABB(mb, (const Object *) this);
}

bool Particles::get_use_local_coordinates() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles", "get_use_local_coordinates");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

int64_t Particles::get_fixed_fps() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles", "get_fixed_fps");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

bool Particles::get_fractional_delta() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles", "get_fractional_delta");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

Ref<Material> Particles::get_process_material() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles", "get_process_material");
	}
	return Ref<Material>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

double Particles::get_speed_scale() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles", "get_speed_scale");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Particles::set_draw_order(const int64_t order) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles", "set_draw_order");
	}
	___godot_icall_void_int(mb, (const Object *) this, order);
}

Particles::DrawOrder Particles::get_draw_order() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles", "get_draw_order");
	}
	return (Particles::DrawOrder) ___godot_icall_int(mb, (const Object *) this);
}

void Particles::set_draw_passes(const int64_t passes) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles", "set_draw_passes");
	}
	___godot_icall_void_int(mb, (const Object *) this, passes);
}

void Particles::set_draw_pass_mesh(const int64_t pass, const Ref<Mesh> mesh) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles", "set_draw_pass_mesh");
	}
	___godot_icall_void_int_Object(mb, (const Object *) this, pass, mesh.ptr());
}

int64_t Particles::get_draw_passes() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles", "get_draw_passes");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

Ref<Mesh> Particles::get_draw_pass_mesh(const int64_t pass) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles", "get_draw_pass_mesh");
	}
	return Ref<Mesh>::__internal_constructor(___godot_icall_Object_int(mb, (const Object *) this, pass));
}

void Particles::restart() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles", "restart");
	}
	___godot_icall_void(mb, (const Object *) this);
}

AABB Particles::capture_aabb() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Particles", "capture_aabb");
	}
	return ___godot_icall_AABB(mb, (const Object *) this);
}

}