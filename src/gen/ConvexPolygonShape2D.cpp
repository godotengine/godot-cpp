#include <ConvexPolygonShape2D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *ConvexPolygonShape2D::___get_type_tag()
{
	return (void *) &ConvexPolygonShape2D::___get_type_tag;
}

void *ConvexPolygonShape2D::___get_base_type_tag()
{
	return (void *) &Shape2D::___get_type_tag;
}

ConvexPolygonShape2D *ConvexPolygonShape2D::_new()
{
	return (ConvexPolygonShape2D *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"ConvexPolygonShape2D")());
}
void ConvexPolygonShape2D::set_point_cloud(const PoolVector2Array point_cloud) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ConvexPolygonShape2D", "set_point_cloud");
	}
	___godot_icall_void_PoolVector2Array(mb, (const Object *) this, point_cloud);
}

void ConvexPolygonShape2D::set_points(const PoolVector2Array points) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ConvexPolygonShape2D", "set_points");
	}
	___godot_icall_void_PoolVector2Array(mb, (const Object *) this, points);
}

PoolVector2Array ConvexPolygonShape2D::get_points() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ConvexPolygonShape2D", "get_points");
	}
	return ___godot_icall_PoolVector2Array(mb, (const Object *) this);
}

}