#include <ParticlesMaterial.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Texture.hpp>
#include <CurveTexture.hpp>
#include <GradientTexture.hpp>


namespace godot {


void *ParticlesMaterial::___get_type_tag()
{
	return (void *) &ParticlesMaterial::___get_type_tag;
}

void *ParticlesMaterial::___get_base_type_tag()
{
	return (void *) &Material::___get_type_tag;
}

ParticlesMaterial *ParticlesMaterial::_new()
{
	return (ParticlesMaterial *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"ParticlesMaterial")());
}
void ParticlesMaterial::set_spread(const double degrees) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParticlesMaterial", "set_spread");
	}
	___godot_icall_void_float(mb, (const Object *) this, degrees);
}

double ParticlesMaterial::get_spread() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParticlesMaterial", "get_spread");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void ParticlesMaterial::set_flatness(const double amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParticlesMaterial", "set_flatness");
	}
	___godot_icall_void_float(mb, (const Object *) this, amount);
}

double ParticlesMaterial::get_flatness() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParticlesMaterial", "get_flatness");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void ParticlesMaterial::set_param(const int64_t param, const double value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParticlesMaterial", "set_param");
	}
	___godot_icall_void_int_float(mb, (const Object *) this, param, value);
}

double ParticlesMaterial::get_param(const int64_t param) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParticlesMaterial", "get_param");
	}
	return ___godot_icall_float_int(mb, (const Object *) this, param);
}

void ParticlesMaterial::set_param_randomness(const int64_t param, const double randomness) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParticlesMaterial", "set_param_randomness");
	}
	___godot_icall_void_int_float(mb, (const Object *) this, param, randomness);
}

double ParticlesMaterial::get_param_randomness(const int64_t param) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParticlesMaterial", "get_param_randomness");
	}
	return ___godot_icall_float_int(mb, (const Object *) this, param);
}

void ParticlesMaterial::set_param_texture(const int64_t param, const Ref<Texture> texture) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParticlesMaterial", "set_param_texture");
	}
	___godot_icall_void_int_Object(mb, (const Object *) this, param, texture.ptr());
}

Ref<Texture> ParticlesMaterial::get_param_texture(const int64_t param) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParticlesMaterial", "get_param_texture");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object_int(mb, (const Object *) this, param));
}

void ParticlesMaterial::set_color(const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParticlesMaterial", "set_color");
	}
	___godot_icall_void_Color(mb, (const Object *) this, color);
}

Color ParticlesMaterial::get_color() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParticlesMaterial", "get_color");
	}
	return ___godot_icall_Color(mb, (const Object *) this);
}

void ParticlesMaterial::set_color_ramp(const Ref<Texture> ramp) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParticlesMaterial", "set_color_ramp");
	}
	___godot_icall_void_Object(mb, (const Object *) this, ramp.ptr());
}

Ref<Texture> ParticlesMaterial::get_color_ramp() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParticlesMaterial", "get_color_ramp");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void ParticlesMaterial::set_flag(const int64_t flag, const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParticlesMaterial", "set_flag");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, flag, enable);
}

bool ParticlesMaterial::get_flag(const int64_t flag) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParticlesMaterial", "get_flag");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, flag);
}

void ParticlesMaterial::set_emission_shape(const int64_t shape) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParticlesMaterial", "set_emission_shape");
	}
	___godot_icall_void_int(mb, (const Object *) this, shape);
}

ParticlesMaterial::EmissionShape ParticlesMaterial::get_emission_shape() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParticlesMaterial", "get_emission_shape");
	}
	return (ParticlesMaterial::EmissionShape) ___godot_icall_int(mb, (const Object *) this);
}

void ParticlesMaterial::set_emission_sphere_radius(const double radius) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParticlesMaterial", "set_emission_sphere_radius");
	}
	___godot_icall_void_float(mb, (const Object *) this, radius);
}

double ParticlesMaterial::get_emission_sphere_radius() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParticlesMaterial", "get_emission_sphere_radius");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void ParticlesMaterial::set_emission_box_extents(const Vector3 extents) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParticlesMaterial", "set_emission_box_extents");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, extents);
}

Vector3 ParticlesMaterial::get_emission_box_extents() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParticlesMaterial", "get_emission_box_extents");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

void ParticlesMaterial::set_emission_point_texture(const Ref<Texture> texture) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParticlesMaterial", "set_emission_point_texture");
	}
	___godot_icall_void_Object(mb, (const Object *) this, texture.ptr());
}

Ref<Texture> ParticlesMaterial::get_emission_point_texture() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParticlesMaterial", "get_emission_point_texture");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void ParticlesMaterial::set_emission_normal_texture(const Ref<Texture> texture) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParticlesMaterial", "set_emission_normal_texture");
	}
	___godot_icall_void_Object(mb, (const Object *) this, texture.ptr());
}

Ref<Texture> ParticlesMaterial::get_emission_normal_texture() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParticlesMaterial", "get_emission_normal_texture");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void ParticlesMaterial::set_emission_color_texture(const Ref<Texture> texture) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParticlesMaterial", "set_emission_color_texture");
	}
	___godot_icall_void_Object(mb, (const Object *) this, texture.ptr());
}

Ref<Texture> ParticlesMaterial::get_emission_color_texture() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParticlesMaterial", "get_emission_color_texture");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void ParticlesMaterial::set_emission_point_count(const int64_t point_count) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParticlesMaterial", "set_emission_point_count");
	}
	___godot_icall_void_int(mb, (const Object *) this, point_count);
}

int64_t ParticlesMaterial::get_emission_point_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParticlesMaterial", "get_emission_point_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void ParticlesMaterial::set_trail_divisor(const int64_t divisor) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParticlesMaterial", "set_trail_divisor");
	}
	___godot_icall_void_int(mb, (const Object *) this, divisor);
}

int64_t ParticlesMaterial::get_trail_divisor() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParticlesMaterial", "get_trail_divisor");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void ParticlesMaterial::set_trail_size_modifier(const Ref<CurveTexture> texture) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParticlesMaterial", "set_trail_size_modifier");
	}
	___godot_icall_void_Object(mb, (const Object *) this, texture.ptr());
}

Ref<CurveTexture> ParticlesMaterial::get_trail_size_modifier() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParticlesMaterial", "get_trail_size_modifier");
	}
	return Ref<CurveTexture>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void ParticlesMaterial::set_trail_color_modifier(const Ref<GradientTexture> texture) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParticlesMaterial", "set_trail_color_modifier");
	}
	___godot_icall_void_Object(mb, (const Object *) this, texture.ptr());
}

Ref<GradientTexture> ParticlesMaterial::get_trail_color_modifier() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParticlesMaterial", "get_trail_color_modifier");
	}
	return Ref<GradientTexture>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

Vector3 ParticlesMaterial::get_gravity() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParticlesMaterial", "get_gravity");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

void ParticlesMaterial::set_gravity(const Vector3 accel_vec) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParticlesMaterial", "set_gravity");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, accel_vec);
}

}