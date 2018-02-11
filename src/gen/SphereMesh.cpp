#include <SphereMesh.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *SphereMesh::___get_type_tag()
{
	return (void *) &SphereMesh::___get_type_tag;
}

void *SphereMesh::___get_base_type_tag()
{
	return (void *) &PrimitiveMesh::___get_type_tag;
}

SphereMesh *SphereMesh::_new()
{
	return (SphereMesh *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"SphereMesh")());
}
void SphereMesh::set_radius(const double radius) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SphereMesh", "set_radius");
	}
	___godot_icall_void_float(mb, (const Object *) this, radius);
}

double SphereMesh::get_radius() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SphereMesh", "get_radius");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void SphereMesh::set_height(const double height) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SphereMesh", "set_height");
	}
	___godot_icall_void_float(mb, (const Object *) this, height);
}

double SphereMesh::get_height() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SphereMesh", "get_height");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void SphereMesh::set_radial_segments(const int64_t radial_segments) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SphereMesh", "set_radial_segments");
	}
	___godot_icall_void_int(mb, (const Object *) this, radial_segments);
}

int64_t SphereMesh::get_radial_segments() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SphereMesh", "get_radial_segments");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void SphereMesh::set_rings(const int64_t rings) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SphereMesh", "set_rings");
	}
	___godot_icall_void_int(mb, (const Object *) this, rings);
}

int64_t SphereMesh::get_rings() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SphereMesh", "get_rings");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void SphereMesh::set_is_hemisphere(const bool is_hemisphere) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SphereMesh", "set_is_hemisphere");
	}
	___godot_icall_void_bool(mb, (const Object *) this, is_hemisphere);
}

bool SphereMesh::get_is_hemisphere() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SphereMesh", "get_is_hemisphere");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

}