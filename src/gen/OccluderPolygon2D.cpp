#include <OccluderPolygon2D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *OccluderPolygon2D::___get_type_tag()
{
	return (void *) &OccluderPolygon2D::___get_type_tag;
}

void *OccluderPolygon2D::___get_base_type_tag()
{
	return (void *) &Resource::___get_type_tag;
}

OccluderPolygon2D *OccluderPolygon2D::_new()
{
	return (OccluderPolygon2D *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"OccluderPolygon2D")());
}
void OccluderPolygon2D::set_closed(const bool closed) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("OccluderPolygon2D", "set_closed");
	}
	___godot_icall_void_bool(mb, (const Object *) this, closed);
}

bool OccluderPolygon2D::is_closed() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("OccluderPolygon2D", "is_closed");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void OccluderPolygon2D::set_cull_mode(const int64_t cull_mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("OccluderPolygon2D", "set_cull_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, cull_mode);
}

OccluderPolygon2D::CullMode OccluderPolygon2D::get_cull_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("OccluderPolygon2D", "get_cull_mode");
	}
	return (OccluderPolygon2D::CullMode) ___godot_icall_int(mb, (const Object *) this);
}

void OccluderPolygon2D::set_polygon(const PoolVector2Array polygon) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("OccluderPolygon2D", "set_polygon");
	}
	___godot_icall_void_PoolVector2Array(mb, (const Object *) this, polygon);
}

PoolVector2Array OccluderPolygon2D::get_polygon() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("OccluderPolygon2D", "get_polygon");
	}
	return ___godot_icall_PoolVector2Array(mb, (const Object *) this);
}

}