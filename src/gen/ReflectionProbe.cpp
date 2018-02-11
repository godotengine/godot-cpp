#include <ReflectionProbe.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *ReflectionProbe::___get_type_tag()
{
	return (void *) &ReflectionProbe::___get_type_tag;
}

void *ReflectionProbe::___get_base_type_tag()
{
	return (void *) &VisualInstance::___get_type_tag;
}

ReflectionProbe *ReflectionProbe::_new()
{
	return (ReflectionProbe *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"ReflectionProbe")());
}
void ReflectionProbe::set_intensity(const double intensity) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ReflectionProbe", "set_intensity");
	}
	___godot_icall_void_float(mb, (const Object *) this, intensity);
}

double ReflectionProbe::get_intensity() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ReflectionProbe", "get_intensity");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void ReflectionProbe::set_interior_ambient(const Color ambient) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ReflectionProbe", "set_interior_ambient");
	}
	___godot_icall_void_Color(mb, (const Object *) this, ambient);
}

Color ReflectionProbe::get_interior_ambient() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ReflectionProbe", "get_interior_ambient");
	}
	return ___godot_icall_Color(mb, (const Object *) this);
}

void ReflectionProbe::set_interior_ambient_energy(const double ambient_energy) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ReflectionProbe", "set_interior_ambient_energy");
	}
	___godot_icall_void_float(mb, (const Object *) this, ambient_energy);
}

double ReflectionProbe::get_interior_ambient_energy() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ReflectionProbe", "get_interior_ambient_energy");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void ReflectionProbe::set_interior_ambient_probe_contribution(const double ambient_probe_contribution) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ReflectionProbe", "set_interior_ambient_probe_contribution");
	}
	___godot_icall_void_float(mb, (const Object *) this, ambient_probe_contribution);
}

double ReflectionProbe::get_interior_ambient_probe_contribution() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ReflectionProbe", "get_interior_ambient_probe_contribution");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void ReflectionProbe::set_max_distance(const double max_distance) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ReflectionProbe", "set_max_distance");
	}
	___godot_icall_void_float(mb, (const Object *) this, max_distance);
}

double ReflectionProbe::get_max_distance() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ReflectionProbe", "get_max_distance");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void ReflectionProbe::set_extents(const Vector3 extents) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ReflectionProbe", "set_extents");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, extents);
}

Vector3 ReflectionProbe::get_extents() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ReflectionProbe", "get_extents");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

void ReflectionProbe::set_origin_offset(const Vector3 origin_offset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ReflectionProbe", "set_origin_offset");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, origin_offset);
}

Vector3 ReflectionProbe::get_origin_offset() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ReflectionProbe", "get_origin_offset");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

void ReflectionProbe::set_as_interior(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ReflectionProbe", "set_as_interior");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool ReflectionProbe::is_set_as_interior() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ReflectionProbe", "is_set_as_interior");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void ReflectionProbe::set_enable_box_projection(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ReflectionProbe", "set_enable_box_projection");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool ReflectionProbe::is_box_projection_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ReflectionProbe", "is_box_projection_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void ReflectionProbe::set_enable_shadows(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ReflectionProbe", "set_enable_shadows");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool ReflectionProbe::are_shadows_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ReflectionProbe", "are_shadows_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void ReflectionProbe::set_cull_mask(const int64_t layers) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ReflectionProbe", "set_cull_mask");
	}
	___godot_icall_void_int(mb, (const Object *) this, layers);
}

int64_t ReflectionProbe::get_cull_mask() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ReflectionProbe", "get_cull_mask");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void ReflectionProbe::set_update_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ReflectionProbe", "set_update_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

ReflectionProbe::UpdateMode ReflectionProbe::get_update_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ReflectionProbe", "get_update_mode");
	}
	return (ReflectionProbe::UpdateMode) ___godot_icall_int(mb, (const Object *) this);
}

}