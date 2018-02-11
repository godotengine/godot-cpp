#include <GIProbeData.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *GIProbeData::___get_type_tag()
{
	return (void *) &GIProbeData::___get_type_tag;
}

void *GIProbeData::___get_base_type_tag()
{
	return (void *) &Resource::___get_type_tag;
}

GIProbeData *GIProbeData::_new()
{
	return (GIProbeData *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"GIProbeData")());
}
void GIProbeData::set_bounds(const AABB bounds) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GIProbeData", "set_bounds");
	}
	___godot_icall_void_AABB(mb, (const Object *) this, bounds);
}

AABB GIProbeData::get_bounds() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GIProbeData", "get_bounds");
	}
	return ___godot_icall_AABB(mb, (const Object *) this);
}

void GIProbeData::set_cell_size(const double cell_size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GIProbeData", "set_cell_size");
	}
	___godot_icall_void_float(mb, (const Object *) this, cell_size);
}

double GIProbeData::get_cell_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GIProbeData", "get_cell_size");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void GIProbeData::set_to_cell_xform(const Transform to_cell_xform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GIProbeData", "set_to_cell_xform");
	}
	___godot_icall_void_Transform(mb, (const Object *) this, to_cell_xform);
}

Transform GIProbeData::get_to_cell_xform() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GIProbeData", "get_to_cell_xform");
	}
	return ___godot_icall_Transform(mb, (const Object *) this);
}

void GIProbeData::set_dynamic_data(const PoolIntArray dynamic_data) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GIProbeData", "set_dynamic_data");
	}
	___godot_icall_void_PoolIntArray(mb, (const Object *) this, dynamic_data);
}

PoolIntArray GIProbeData::get_dynamic_data() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GIProbeData", "get_dynamic_data");
	}
	return ___godot_icall_PoolIntArray(mb, (const Object *) this);
}

void GIProbeData::set_dynamic_range(const int64_t dynamic_range) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GIProbeData", "set_dynamic_range");
	}
	___godot_icall_void_int(mb, (const Object *) this, dynamic_range);
}

int64_t GIProbeData::get_dynamic_range() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GIProbeData", "get_dynamic_range");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void GIProbeData::set_energy(const double energy) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GIProbeData", "set_energy");
	}
	___godot_icall_void_float(mb, (const Object *) this, energy);
}

double GIProbeData::get_energy() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GIProbeData", "get_energy");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void GIProbeData::set_bias(const double bias) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GIProbeData", "set_bias");
	}
	___godot_icall_void_float(mb, (const Object *) this, bias);
}

double GIProbeData::get_bias() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GIProbeData", "get_bias");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void GIProbeData::set_normal_bias(const double bias) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GIProbeData", "set_normal_bias");
	}
	___godot_icall_void_float(mb, (const Object *) this, bias);
}

double GIProbeData::get_normal_bias() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GIProbeData", "get_normal_bias");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void GIProbeData::set_propagation(const double propagation) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GIProbeData", "set_propagation");
	}
	___godot_icall_void_float(mb, (const Object *) this, propagation);
}

double GIProbeData::get_propagation() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GIProbeData", "get_propagation");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void GIProbeData::set_interior(const bool interior) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GIProbeData", "set_interior");
	}
	___godot_icall_void_bool(mb, (const Object *) this, interior);
}

bool GIProbeData::is_interior() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GIProbeData", "is_interior");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void GIProbeData::set_compress(const bool compress) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GIProbeData", "set_compress");
	}
	___godot_icall_void_bool(mb, (const Object *) this, compress);
}

bool GIProbeData::is_compressed() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GIProbeData", "is_compressed");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

}