#include <SpatialMaterial.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Texture.hpp>


namespace godot {


void *SpatialMaterial::___get_type_tag()
{
	return (void *) &SpatialMaterial::___get_type_tag;
}

void *SpatialMaterial::___get_base_type_tag()
{
	return (void *) &Material::___get_type_tag;
}

SpatialMaterial *SpatialMaterial::_new()
{
	return (SpatialMaterial *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"SpatialMaterial")());
}
void SpatialMaterial::set_albedo(const Color albedo) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_albedo");
	}
	___godot_icall_void_Color(mb, (const Object *) this, albedo);
}

Color SpatialMaterial::get_albedo() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_albedo");
	}
	return ___godot_icall_Color(mb, (const Object *) this);
}

void SpatialMaterial::set_specular(const double specular) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_specular");
	}
	___godot_icall_void_float(mb, (const Object *) this, specular);
}

double SpatialMaterial::get_specular() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_specular");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void SpatialMaterial::set_metallic(const double metallic) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_metallic");
	}
	___godot_icall_void_float(mb, (const Object *) this, metallic);
}

double SpatialMaterial::get_metallic() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_metallic");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void SpatialMaterial::set_roughness(const double roughness) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_roughness");
	}
	___godot_icall_void_float(mb, (const Object *) this, roughness);
}

double SpatialMaterial::get_roughness() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_roughness");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void SpatialMaterial::set_emission(const Color emission) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_emission");
	}
	___godot_icall_void_Color(mb, (const Object *) this, emission);
}

Color SpatialMaterial::get_emission() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_emission");
	}
	return ___godot_icall_Color(mb, (const Object *) this);
}

void SpatialMaterial::set_emission_energy(const double emission_energy) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_emission_energy");
	}
	___godot_icall_void_float(mb, (const Object *) this, emission_energy);
}

double SpatialMaterial::get_emission_energy() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_emission_energy");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void SpatialMaterial::set_normal_scale(const double normal_scale) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_normal_scale");
	}
	___godot_icall_void_float(mb, (const Object *) this, normal_scale);
}

double SpatialMaterial::get_normal_scale() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_normal_scale");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void SpatialMaterial::set_rim(const double rim) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_rim");
	}
	___godot_icall_void_float(mb, (const Object *) this, rim);
}

double SpatialMaterial::get_rim() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_rim");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void SpatialMaterial::set_rim_tint(const double rim_tint) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_rim_tint");
	}
	___godot_icall_void_float(mb, (const Object *) this, rim_tint);
}

double SpatialMaterial::get_rim_tint() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_rim_tint");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void SpatialMaterial::set_clearcoat(const double clearcoat) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_clearcoat");
	}
	___godot_icall_void_float(mb, (const Object *) this, clearcoat);
}

double SpatialMaterial::get_clearcoat() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_clearcoat");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void SpatialMaterial::set_clearcoat_gloss(const double clearcoat_gloss) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_clearcoat_gloss");
	}
	___godot_icall_void_float(mb, (const Object *) this, clearcoat_gloss);
}

double SpatialMaterial::get_clearcoat_gloss() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_clearcoat_gloss");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void SpatialMaterial::set_anisotropy(const double anisotropy) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_anisotropy");
	}
	___godot_icall_void_float(mb, (const Object *) this, anisotropy);
}

double SpatialMaterial::get_anisotropy() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_anisotropy");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void SpatialMaterial::set_depth_scale(const double depth_scale) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_depth_scale");
	}
	___godot_icall_void_float(mb, (const Object *) this, depth_scale);
}

double SpatialMaterial::get_depth_scale() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_depth_scale");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void SpatialMaterial::set_subsurface_scattering_strength(const double strength) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_subsurface_scattering_strength");
	}
	___godot_icall_void_float(mb, (const Object *) this, strength);
}

double SpatialMaterial::get_subsurface_scattering_strength() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_subsurface_scattering_strength");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void SpatialMaterial::set_transmission(const Color transmission) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_transmission");
	}
	___godot_icall_void_Color(mb, (const Object *) this, transmission);
}

Color SpatialMaterial::get_transmission() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_transmission");
	}
	return ___godot_icall_Color(mb, (const Object *) this);
}

void SpatialMaterial::set_refraction(const double refraction) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_refraction");
	}
	___godot_icall_void_float(mb, (const Object *) this, refraction);
}

double SpatialMaterial::get_refraction() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_refraction");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void SpatialMaterial::set_line_width(const double line_width) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_line_width");
	}
	___godot_icall_void_float(mb, (const Object *) this, line_width);
}

double SpatialMaterial::get_line_width() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_line_width");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void SpatialMaterial::set_point_size(const double point_size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_point_size");
	}
	___godot_icall_void_float(mb, (const Object *) this, point_size);
}

double SpatialMaterial::get_point_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_point_size");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void SpatialMaterial::set_detail_uv(const int64_t detail_uv) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_detail_uv");
	}
	___godot_icall_void_int(mb, (const Object *) this, detail_uv);
}

SpatialMaterial::DetailUV SpatialMaterial::get_detail_uv() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_detail_uv");
	}
	return (SpatialMaterial::DetailUV) ___godot_icall_int(mb, (const Object *) this);
}

void SpatialMaterial::set_blend_mode(const int64_t blend_mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_blend_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, blend_mode);
}

SpatialMaterial::BlendMode SpatialMaterial::get_blend_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_blend_mode");
	}
	return (SpatialMaterial::BlendMode) ___godot_icall_int(mb, (const Object *) this);
}

void SpatialMaterial::set_depth_draw_mode(const int64_t depth_draw_mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_depth_draw_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, depth_draw_mode);
}

SpatialMaterial::DepthDrawMode SpatialMaterial::get_depth_draw_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_depth_draw_mode");
	}
	return (SpatialMaterial::DepthDrawMode) ___godot_icall_int(mb, (const Object *) this);
}

void SpatialMaterial::set_cull_mode(const int64_t cull_mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_cull_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, cull_mode);
}

SpatialMaterial::CullMode SpatialMaterial::get_cull_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_cull_mode");
	}
	return (SpatialMaterial::CullMode) ___godot_icall_int(mb, (const Object *) this);
}

void SpatialMaterial::set_diffuse_mode(const int64_t diffuse_mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_diffuse_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, diffuse_mode);
}

SpatialMaterial::DiffuseMode SpatialMaterial::get_diffuse_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_diffuse_mode");
	}
	return (SpatialMaterial::DiffuseMode) ___godot_icall_int(mb, (const Object *) this);
}

void SpatialMaterial::set_specular_mode(const int64_t specular_mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_specular_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, specular_mode);
}

SpatialMaterial::SpecularMode SpatialMaterial::get_specular_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_specular_mode");
	}
	return (SpatialMaterial::SpecularMode) ___godot_icall_int(mb, (const Object *) this);
}

void SpatialMaterial::set_flag(const int64_t flag, const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_flag");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, flag, enable);
}

bool SpatialMaterial::get_flag(const int64_t flag) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_flag");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, flag);
}

void SpatialMaterial::set_feature(const int64_t feature, const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_feature");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, feature, enable);
}

bool SpatialMaterial::get_feature(const int64_t feature) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_feature");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, feature);
}

void SpatialMaterial::set_texture(const int64_t param, const Ref<Texture> texture) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_texture");
	}
	___godot_icall_void_int_Object(mb, (const Object *) this, param, texture.ptr());
}

Ref<Texture> SpatialMaterial::get_texture(const int64_t param) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_texture");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object_int(mb, (const Object *) this, param));
}

void SpatialMaterial::set_detail_blend_mode(const int64_t detail_blend_mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_detail_blend_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, detail_blend_mode);
}

SpatialMaterial::BlendMode SpatialMaterial::get_detail_blend_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_detail_blend_mode");
	}
	return (SpatialMaterial::BlendMode) ___godot_icall_int(mb, (const Object *) this);
}

void SpatialMaterial::set_uv1_scale(const Vector3 scale) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_uv1_scale");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, scale);
}

Vector3 SpatialMaterial::get_uv1_scale() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_uv1_scale");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

void SpatialMaterial::set_uv1_offset(const Vector3 offset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_uv1_offset");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, offset);
}

Vector3 SpatialMaterial::get_uv1_offset() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_uv1_offset");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

void SpatialMaterial::set_uv1_triplanar_blend_sharpness(const double sharpness) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_uv1_triplanar_blend_sharpness");
	}
	___godot_icall_void_float(mb, (const Object *) this, sharpness);
}

double SpatialMaterial::get_uv1_triplanar_blend_sharpness() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_uv1_triplanar_blend_sharpness");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void SpatialMaterial::set_uv2_scale(const Vector3 scale) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_uv2_scale");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, scale);
}

Vector3 SpatialMaterial::get_uv2_scale() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_uv2_scale");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

void SpatialMaterial::set_uv2_offset(const Vector3 offset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_uv2_offset");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, offset);
}

Vector3 SpatialMaterial::get_uv2_offset() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_uv2_offset");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

void SpatialMaterial::set_uv2_triplanar_blend_sharpness(const double sharpness) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_uv2_triplanar_blend_sharpness");
	}
	___godot_icall_void_float(mb, (const Object *) this, sharpness);
}

double SpatialMaterial::get_uv2_triplanar_blend_sharpness() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_uv2_triplanar_blend_sharpness");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void SpatialMaterial::set_billboard_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_billboard_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

SpatialMaterial::BillboardMode SpatialMaterial::get_billboard_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_billboard_mode");
	}
	return (SpatialMaterial::BillboardMode) ___godot_icall_int(mb, (const Object *) this);
}

void SpatialMaterial::set_particles_anim_h_frames(const int64_t frames) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_particles_anim_h_frames");
	}
	___godot_icall_void_int(mb, (const Object *) this, frames);
}

int64_t SpatialMaterial::get_particles_anim_h_frames() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_particles_anim_h_frames");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void SpatialMaterial::set_particles_anim_v_frames(const int64_t frames) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_particles_anim_v_frames");
	}
	___godot_icall_void_int(mb, (const Object *) this, frames);
}

int64_t SpatialMaterial::get_particles_anim_v_frames() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_particles_anim_v_frames");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void SpatialMaterial::set_particles_anim_loop(const int64_t frames) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_particles_anim_loop");
	}
	___godot_icall_void_int(mb, (const Object *) this, frames);
}

int64_t SpatialMaterial::get_particles_anim_loop() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_particles_anim_loop");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void SpatialMaterial::set_depth_deep_parallax(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_depth_deep_parallax");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool SpatialMaterial::is_depth_deep_parallax_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "is_depth_deep_parallax_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void SpatialMaterial::set_depth_deep_parallax_min_layers(const int64_t layer) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_depth_deep_parallax_min_layers");
	}
	___godot_icall_void_int(mb, (const Object *) this, layer);
}

int64_t SpatialMaterial::get_depth_deep_parallax_min_layers() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_depth_deep_parallax_min_layers");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void SpatialMaterial::set_depth_deep_parallax_max_layers(const int64_t layer) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_depth_deep_parallax_max_layers");
	}
	___godot_icall_void_int(mb, (const Object *) this, layer);
}

int64_t SpatialMaterial::get_depth_deep_parallax_max_layers() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_depth_deep_parallax_max_layers");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void SpatialMaterial::set_grow(const double amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_grow");
	}
	___godot_icall_void_float(mb, (const Object *) this, amount);
}

double SpatialMaterial::get_grow() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_grow");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void SpatialMaterial::set_emission_operator(const int64_t _operator) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_emission_operator");
	}
	___godot_icall_void_int(mb, (const Object *) this, _operator);
}

SpatialMaterial::EmissionOperator SpatialMaterial::get_emission_operator() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_emission_operator");
	}
	return (SpatialMaterial::EmissionOperator) ___godot_icall_int(mb, (const Object *) this);
}

void SpatialMaterial::set_ao_light_affect(const double amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_ao_light_affect");
	}
	___godot_icall_void_float(mb, (const Object *) this, amount);
}

double SpatialMaterial::get_ao_light_affect() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_ao_light_affect");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void SpatialMaterial::set_alpha_scissor_threshold(const double threshold) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_alpha_scissor_threshold");
	}
	___godot_icall_void_float(mb, (const Object *) this, threshold);
}

double SpatialMaterial::get_alpha_scissor_threshold() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_alpha_scissor_threshold");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void SpatialMaterial::set_grow_enabled(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_grow_enabled");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool SpatialMaterial::is_grow_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "is_grow_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void SpatialMaterial::set_metallic_texture_channel(const int64_t channel) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_metallic_texture_channel");
	}
	___godot_icall_void_int(mb, (const Object *) this, channel);
}

SpatialMaterial::TextureChannel SpatialMaterial::get_metallic_texture_channel() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_metallic_texture_channel");
	}
	return (SpatialMaterial::TextureChannel) ___godot_icall_int(mb, (const Object *) this);
}

void SpatialMaterial::set_roughness_texture_channel(const int64_t channel) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_roughness_texture_channel");
	}
	___godot_icall_void_int(mb, (const Object *) this, channel);
}

SpatialMaterial::TextureChannel SpatialMaterial::get_roughness_texture_channel() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_roughness_texture_channel");
	}
	return (SpatialMaterial::TextureChannel) ___godot_icall_int(mb, (const Object *) this);
}

void SpatialMaterial::set_ao_texture_channel(const int64_t channel) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_ao_texture_channel");
	}
	___godot_icall_void_int(mb, (const Object *) this, channel);
}

SpatialMaterial::TextureChannel SpatialMaterial::get_ao_texture_channel() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_ao_texture_channel");
	}
	return (SpatialMaterial::TextureChannel) ___godot_icall_int(mb, (const Object *) this);
}

void SpatialMaterial::set_refraction_texture_channel(const int64_t channel) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_refraction_texture_channel");
	}
	___godot_icall_void_int(mb, (const Object *) this, channel);
}

SpatialMaterial::TextureChannel SpatialMaterial::get_refraction_texture_channel() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_refraction_texture_channel");
	}
	return (SpatialMaterial::TextureChannel) ___godot_icall_int(mb, (const Object *) this);
}

void SpatialMaterial::set_proximity_fade(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_proximity_fade");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool SpatialMaterial::is_proximity_fade_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "is_proximity_fade_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void SpatialMaterial::set_proximity_fade_distance(const double distance) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_proximity_fade_distance");
	}
	___godot_icall_void_float(mb, (const Object *) this, distance);
}

double SpatialMaterial::get_proximity_fade_distance() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_proximity_fade_distance");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void SpatialMaterial::set_distance_fade(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_distance_fade");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool SpatialMaterial::is_distance_fade_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "is_distance_fade_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void SpatialMaterial::set_distance_fade_max_distance(const double distance) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_distance_fade_max_distance");
	}
	___godot_icall_void_float(mb, (const Object *) this, distance);
}

double SpatialMaterial::get_distance_fade_max_distance() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_distance_fade_max_distance");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void SpatialMaterial::set_distance_fade_min_distance(const double distance) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "set_distance_fade_min_distance");
	}
	___godot_icall_void_float(mb, (const Object *) this, distance);
}

double SpatialMaterial::get_distance_fade_min_distance() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialMaterial", "get_distance_fade_min_distance");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

}