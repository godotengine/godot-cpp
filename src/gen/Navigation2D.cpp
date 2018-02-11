#include <Navigation2D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <NavigationPolygon.hpp>
#include <Object.hpp>


namespace godot {


void *Navigation2D::___get_type_tag()
{
	return (void *) &Navigation2D::___get_type_tag;
}

void *Navigation2D::___get_base_type_tag()
{
	return (void *) &Node2D::___get_type_tag;
}

Navigation2D *Navigation2D::_new()
{
	return (Navigation2D *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Navigation2D")());
}
int64_t Navigation2D::navpoly_add(const Ref<NavigationPolygon> mesh, const Transform2D xform, const Object *owner) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Navigation2D", "navpoly_add");
	}
	return ___godot_icall_int_Object_Transform2D_Object(mb, (const Object *) this, mesh.ptr(), xform, owner);
}

void Navigation2D::navpoly_set_transform(const int64_t id, const Transform2D xform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Navigation2D", "navpoly_set_transform");
	}
	___godot_icall_void_int_Transform2D(mb, (const Object *) this, id, xform);
}

void Navigation2D::navpoly_remove(const int64_t id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Navigation2D", "navpoly_remove");
	}
	___godot_icall_void_int(mb, (const Object *) this, id);
}

PoolVector2Array Navigation2D::get_simple_path(const Vector2 start, const Vector2 end, const bool optimize) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Navigation2D", "get_simple_path");
	}
	return ___godot_icall_PoolVector2Array_Vector2_Vector2_bool(mb, (const Object *) this, start, end, optimize);
}

Vector2 Navigation2D::get_closest_point(const Vector2 to_point) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Navigation2D", "get_closest_point");
	}
	return ___godot_icall_Vector2_Vector2(mb, (const Object *) this, to_point);
}

Object *Navigation2D::get_closest_point_owner(const Vector2 to_point) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Navigation2D", "get_closest_point_owner");
	}
	return (Object *) ___godot_icall_Object_Vector2(mb, (const Object *) this, to_point);
}

}