#include <StaticBody.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *StaticBody::___get_type_tag()
{
	return (void *) &StaticBody::___get_type_tag;
}

void *StaticBody::___get_base_type_tag()
{
	return (void *) &PhysicsBody::___get_type_tag;
}

StaticBody *StaticBody::_new()
{
	return (StaticBody *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"StaticBody")());
}
void StaticBody::set_constant_linear_velocity(const Vector3 vel) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StaticBody", "set_constant_linear_velocity");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, vel);
}

void StaticBody::set_constant_angular_velocity(const Vector3 vel) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StaticBody", "set_constant_angular_velocity");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, vel);
}

Vector3 StaticBody::get_constant_linear_velocity() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StaticBody", "get_constant_linear_velocity");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

Vector3 StaticBody::get_constant_angular_velocity() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StaticBody", "get_constant_angular_velocity");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

void StaticBody::set_friction(const double friction) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StaticBody", "set_friction");
	}
	___godot_icall_void_float(mb, (const Object *) this, friction);
}

double StaticBody::get_friction() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StaticBody", "get_friction");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void StaticBody::set_bounce(const double bounce) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StaticBody", "set_bounce");
	}
	___godot_icall_void_float(mb, (const Object *) this, bounce);
}

double StaticBody::get_bounce() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StaticBody", "get_bounce");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

}