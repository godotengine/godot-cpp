#include <ConvexPolygonShape.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *ConvexPolygonShape::___get_type_tag()
{
	return (void *) &ConvexPolygonShape::___get_type_tag;
}

void *ConvexPolygonShape::___get_base_type_tag()
{
	return (void *) &Shape::___get_type_tag;
}

ConvexPolygonShape *ConvexPolygonShape::_new()
{
	return (ConvexPolygonShape *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"ConvexPolygonShape")());
}
void ConvexPolygonShape::set_points(const PoolVector3Array points) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ConvexPolygonShape", "set_points");
	}
	___godot_icall_void_PoolVector3Array(mb, (const Object *) this, points);
}

PoolVector3Array ConvexPolygonShape::get_points() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ConvexPolygonShape", "get_points");
	}
	return ___godot_icall_PoolVector3Array(mb, (const Object *) this);
}

}