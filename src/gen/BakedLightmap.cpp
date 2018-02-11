#include <BakedLightmap.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <BakedLightmapData.hpp>
#include <Object.hpp>


namespace godot {


void *BakedLightmap::___get_type_tag()
{
	return (void *) &BakedLightmap::___get_type_tag;
}

void *BakedLightmap::___get_base_type_tag()
{
	return (void *) &VisualInstance::___get_type_tag;
}

BakedLightmap *BakedLightmap::_new()
{
	return (BakedLightmap *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"BakedLightmap")());
}
void BakedLightmap::set_light_data(const Ref<BakedLightmapData> data) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BakedLightmap", "set_light_data");
	}
	___godot_icall_void_Object(mb, (const Object *) this, data.ptr());
}

Ref<BakedLightmapData> BakedLightmap::get_light_data() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BakedLightmap", "get_light_data");
	}
	return Ref<BakedLightmapData>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void BakedLightmap::set_bake_cell_size(const double bake_cell_size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BakedLightmap", "set_bake_cell_size");
	}
	___godot_icall_void_float(mb, (const Object *) this, bake_cell_size);
}

double BakedLightmap::get_bake_cell_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BakedLightmap", "get_bake_cell_size");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void BakedLightmap::set_capture_cell_size(const double capture_cell_size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BakedLightmap", "set_capture_cell_size");
	}
	___godot_icall_void_float(mb, (const Object *) this, capture_cell_size);
}

double BakedLightmap::get_capture_cell_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BakedLightmap", "get_capture_cell_size");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void BakedLightmap::set_bake_quality(const int64_t bake_quality) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BakedLightmap", "set_bake_quality");
	}
	___godot_icall_void_int(mb, (const Object *) this, bake_quality);
}

BakedLightmap::BakeQuality BakedLightmap::get_bake_quality() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BakedLightmap", "get_bake_quality");
	}
	return (BakedLightmap::BakeQuality) ___godot_icall_int(mb, (const Object *) this);
}

void BakedLightmap::set_bake_mode(const int64_t bake_mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BakedLightmap", "set_bake_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, bake_mode);
}

BakedLightmap::BakeMode BakedLightmap::get_bake_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BakedLightmap", "get_bake_mode");
	}
	return (BakedLightmap::BakeMode) ___godot_icall_int(mb, (const Object *) this);
}

void BakedLightmap::set_extents(const Vector3 extents) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BakedLightmap", "set_extents");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, extents);
}

Vector3 BakedLightmap::get_extents() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BakedLightmap", "get_extents");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

void BakedLightmap::set_propagation(const double propagation) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BakedLightmap", "set_propagation");
	}
	___godot_icall_void_float(mb, (const Object *) this, propagation);
}

double BakedLightmap::get_propagation() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BakedLightmap", "get_propagation");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void BakedLightmap::set_energy(const double energy) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BakedLightmap", "set_energy");
	}
	___godot_icall_void_float(mb, (const Object *) this, energy);
}

double BakedLightmap::get_energy() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BakedLightmap", "get_energy");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void BakedLightmap::set_hdr(const bool hdr) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BakedLightmap", "set_hdr");
	}
	___godot_icall_void_bool(mb, (const Object *) this, hdr);
}

bool BakedLightmap::is_hdr() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BakedLightmap", "is_hdr");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void BakedLightmap::set_image_path(const String image_path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BakedLightmap", "set_image_path");
	}
	___godot_icall_void_String(mb, (const Object *) this, image_path);
}

String BakedLightmap::get_image_path() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BakedLightmap", "get_image_path");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

BakedLightmap::BakeError BakedLightmap::bake(const Object *from_node, const bool create_visual_debug) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BakedLightmap", "bake");
	}
	return (BakedLightmap::BakeError) ___godot_icall_int_Object_bool(mb, (const Object *) this, from_node, create_visual_debug);
}

void BakedLightmap::debug_bake() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BakedLightmap", "debug_bake");
	}
	___godot_icall_void(mb, (const Object *) this);
}

}