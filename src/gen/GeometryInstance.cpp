#include <GeometryInstance.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Material.hpp>


namespace godot {


void *GeometryInstance::___get_type_tag()
{
	return (void *) &GeometryInstance::___get_type_tag;
}

void *GeometryInstance::___get_base_type_tag()
{
	return (void *) &VisualInstance::___get_type_tag;
}

void GeometryInstance::set_material_override(const Ref<Material> material) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GeometryInstance", "set_material_override");
	}
	___godot_icall_void_Object(mb, (const Object *) this, material.ptr());
}

Ref<Material> GeometryInstance::get_material_override() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GeometryInstance", "get_material_override");
	}
	return Ref<Material>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void GeometryInstance::set_flag(const int64_t flag, const bool value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GeometryInstance", "set_flag");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, flag, value);
}

bool GeometryInstance::get_flag(const int64_t flag) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GeometryInstance", "get_flag");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, flag);
}

void GeometryInstance::set_cast_shadows_setting(const int64_t shadow_casting_setting) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GeometryInstance", "set_cast_shadows_setting");
	}
	___godot_icall_void_int(mb, (const Object *) this, shadow_casting_setting);
}

GeometryInstance::ShadowCastingSetting GeometryInstance::get_cast_shadows_setting() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GeometryInstance", "get_cast_shadows_setting");
	}
	return (GeometryInstance::ShadowCastingSetting) ___godot_icall_int(mb, (const Object *) this);
}

void GeometryInstance::set_lod_max_hysteresis(const double mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GeometryInstance", "set_lod_max_hysteresis");
	}
	___godot_icall_void_float(mb, (const Object *) this, mode);
}

double GeometryInstance::get_lod_max_hysteresis() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GeometryInstance", "get_lod_max_hysteresis");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void GeometryInstance::set_lod_max_distance(const double mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GeometryInstance", "set_lod_max_distance");
	}
	___godot_icall_void_float(mb, (const Object *) this, mode);
}

double GeometryInstance::get_lod_max_distance() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GeometryInstance", "get_lod_max_distance");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void GeometryInstance::set_lod_min_hysteresis(const double mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GeometryInstance", "set_lod_min_hysteresis");
	}
	___godot_icall_void_float(mb, (const Object *) this, mode);
}

double GeometryInstance::get_lod_min_hysteresis() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GeometryInstance", "get_lod_min_hysteresis");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void GeometryInstance::set_lod_min_distance(const double mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GeometryInstance", "set_lod_min_distance");
	}
	___godot_icall_void_float(mb, (const Object *) this, mode);
}

double GeometryInstance::get_lod_min_distance() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GeometryInstance", "get_lod_min_distance");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void GeometryInstance::set_extra_cull_margin(const double margin) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GeometryInstance", "set_extra_cull_margin");
	}
	___godot_icall_void_float(mb, (const Object *) this, margin);
}

double GeometryInstance::get_extra_cull_margin() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GeometryInstance", "get_extra_cull_margin");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

}