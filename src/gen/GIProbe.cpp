#include <GIProbe.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <GIProbeData.hpp>
#include <Object.hpp>


namespace godot {


void *GIProbe::___get_type_tag()
{
	return (void *) &GIProbe::___get_type_tag;
}

void *GIProbe::___get_base_type_tag()
{
	return (void *) &VisualInstance::___get_type_tag;
}

GIProbe *GIProbe::_new()
{
	return (GIProbe *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"GIProbe")());
}
void GIProbe::set_probe_data(const Ref<GIProbeData> data) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GIProbe", "set_probe_data");
	}
	___godot_icall_void_Object(mb, (const Object *) this, data.ptr());
}

Ref<GIProbeData> GIProbe::get_probe_data() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GIProbe", "get_probe_data");
	}
	return Ref<GIProbeData>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void GIProbe::set_subdiv(const int64_t subdiv) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GIProbe", "set_subdiv");
	}
	___godot_icall_void_int(mb, (const Object *) this, subdiv);
}

GIProbe::Subdiv GIProbe::get_subdiv() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GIProbe", "get_subdiv");
	}
	return (GIProbe::Subdiv) ___godot_icall_int(mb, (const Object *) this);
}

void GIProbe::set_extents(const Vector3 extents) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GIProbe", "set_extents");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, extents);
}

Vector3 GIProbe::get_extents() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GIProbe", "get_extents");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

void GIProbe::set_dynamic_range(const int64_t max) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GIProbe", "set_dynamic_range");
	}
	___godot_icall_void_int(mb, (const Object *) this, max);
}

int64_t GIProbe::get_dynamic_range() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GIProbe", "get_dynamic_range");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void GIProbe::set_energy(const double max) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GIProbe", "set_energy");
	}
	___godot_icall_void_float(mb, (const Object *) this, max);
}

double GIProbe::get_energy() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GIProbe", "get_energy");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void GIProbe::set_bias(const double max) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GIProbe", "set_bias");
	}
	___godot_icall_void_float(mb, (const Object *) this, max);
}

double GIProbe::get_bias() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GIProbe", "get_bias");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void GIProbe::set_normal_bias(const double max) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GIProbe", "set_normal_bias");
	}
	___godot_icall_void_float(mb, (const Object *) this, max);
}

double GIProbe::get_normal_bias() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GIProbe", "get_normal_bias");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void GIProbe::set_propagation(const double max) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GIProbe", "set_propagation");
	}
	___godot_icall_void_float(mb, (const Object *) this, max);
}

double GIProbe::get_propagation() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GIProbe", "get_propagation");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void GIProbe::set_interior(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GIProbe", "set_interior");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool GIProbe::is_interior() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GIProbe", "is_interior");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void GIProbe::set_compress(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GIProbe", "set_compress");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool GIProbe::is_compressed() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GIProbe", "is_compressed");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void GIProbe::bake(const Object *from_node, const bool create_visual_debug) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GIProbe", "bake");
	}
	___godot_icall_void_Object_bool(mb, (const Object *) this, from_node, create_visual_debug);
}

void GIProbe::debug_bake() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GIProbe", "debug_bake");
	}
	___godot_icall_void(mb, (const Object *) this);
}

}