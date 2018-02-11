#include <ImmediateGeometry.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Texture.hpp>


namespace godot {


void *ImmediateGeometry::___get_type_tag()
{
	return (void *) &ImmediateGeometry::___get_type_tag;
}

void *ImmediateGeometry::___get_base_type_tag()
{
	return (void *) &GeometryInstance::___get_type_tag;
}

ImmediateGeometry *ImmediateGeometry::_new()
{
	return (ImmediateGeometry *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"ImmediateGeometry")());
}
void ImmediateGeometry::begin(const int64_t primitive, const Ref<Texture> texture) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ImmediateGeometry", "begin");
	}
	___godot_icall_void_int_Object(mb, (const Object *) this, primitive, texture.ptr());
}

void ImmediateGeometry::set_normal(const Vector3 normal) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ImmediateGeometry", "set_normal");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, normal);
}

void ImmediateGeometry::set_tangent(const Plane tangent) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ImmediateGeometry", "set_tangent");
	}
	___godot_icall_void_Plane(mb, (const Object *) this, tangent);
}

void ImmediateGeometry::set_color(const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ImmediateGeometry", "set_color");
	}
	___godot_icall_void_Color(mb, (const Object *) this, color);
}

void ImmediateGeometry::set_uv(const Vector2 uv) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ImmediateGeometry", "set_uv");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, uv);
}

void ImmediateGeometry::set_uv2(const Vector2 uv) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ImmediateGeometry", "set_uv2");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, uv);
}

void ImmediateGeometry::add_vertex(const Vector3 position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ImmediateGeometry", "add_vertex");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, position);
}

void ImmediateGeometry::add_sphere(const int64_t lats, const int64_t lons, const double radius, const bool add_uv) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ImmediateGeometry", "add_sphere");
	}
	___godot_icall_void_int_int_float_bool(mb, (const Object *) this, lats, lons, radius, add_uv);
}

void ImmediateGeometry::end() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ImmediateGeometry", "end");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void ImmediateGeometry::clear() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ImmediateGeometry", "clear");
	}
	___godot_icall_void(mb, (const Object *) this);
}

}