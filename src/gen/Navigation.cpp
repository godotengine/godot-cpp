#include <Navigation.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <NavigationMesh.hpp>
#include <Object.hpp>


namespace godot {


void *Navigation::___get_type_tag()
{
	return (void *) &Navigation::___get_type_tag;
}

void *Navigation::___get_base_type_tag()
{
	return (void *) &Spatial::___get_type_tag;
}

Navigation *Navigation::_new()
{
	return (Navigation *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Navigation")());
}
int64_t Navigation::navmesh_add(const Ref<NavigationMesh> mesh, const Transform xform, const Object *owner) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Navigation", "navmesh_add");
	}
	return ___godot_icall_int_Object_Transform_Object(mb, (const Object *) this, mesh.ptr(), xform, owner);
}

void Navigation::navmesh_set_transform(const int64_t id, const Transform xform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Navigation", "navmesh_set_transform");
	}
	___godot_icall_void_int_Transform(mb, (const Object *) this, id, xform);
}

void Navigation::navmesh_remove(const int64_t id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Navigation", "navmesh_remove");
	}
	___godot_icall_void_int(mb, (const Object *) this, id);
}

PoolVector3Array Navigation::get_simple_path(const Vector3 start, const Vector3 end, const bool optimize) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Navigation", "get_simple_path");
	}
	return ___godot_icall_PoolVector3Array_Vector3_Vector3_bool(mb, (const Object *) this, start, end, optimize);
}

Vector3 Navigation::get_closest_point_to_segment(const Vector3 start, const Vector3 end, const bool use_collision) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Navigation", "get_closest_point_to_segment");
	}
	return ___godot_icall_Vector3_Vector3_Vector3_bool(mb, (const Object *) this, start, end, use_collision);
}

Vector3 Navigation::get_closest_point(const Vector3 to_point) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Navigation", "get_closest_point");
	}
	return ___godot_icall_Vector3_Vector3(mb, (const Object *) this, to_point);
}

Vector3 Navigation::get_closest_point_normal(const Vector3 to_point) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Navigation", "get_closest_point_normal");
	}
	return ___godot_icall_Vector3_Vector3(mb, (const Object *) this, to_point);
}

Object *Navigation::get_closest_point_owner(const Vector3 to_point) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Navigation", "get_closest_point_owner");
	}
	return (Object *) ___godot_icall_Object_Vector3(mb, (const Object *) this, to_point);
}

void Navigation::set_up_vector(const Vector3 up) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Navigation", "set_up_vector");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, up);
}

Vector3 Navigation::get_up_vector() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Navigation", "get_up_vector");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

}