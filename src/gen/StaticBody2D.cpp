#include <StaticBody2D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *StaticBody2D::___get_type_tag()
{
	return (void *) &StaticBody2D::___get_type_tag;
}

void *StaticBody2D::___get_base_type_tag()
{
	return (void *) &PhysicsBody2D::___get_type_tag;
}

StaticBody2D *StaticBody2D::_new()
{
	return (StaticBody2D *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"StaticBody2D")());
}
void StaticBody2D::set_constant_linear_velocity(const Vector2 vel) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StaticBody2D", "set_constant_linear_velocity");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, vel);
}

void StaticBody2D::set_constant_angular_velocity(const double vel) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StaticBody2D", "set_constant_angular_velocity");
	}
	___godot_icall_void_float(mb, (const Object *) this, vel);
}

Vector2 StaticBody2D::get_constant_linear_velocity() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StaticBody2D", "get_constant_linear_velocity");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

double StaticBody2D::get_constant_angular_velocity() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StaticBody2D", "get_constant_angular_velocity");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void StaticBody2D::set_friction(const double friction) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StaticBody2D", "set_friction");
	}
	___godot_icall_void_float(mb, (const Object *) this, friction);
}

double StaticBody2D::get_friction() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StaticBody2D", "get_friction");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void StaticBody2D::set_bounce(const double bounce) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StaticBody2D", "set_bounce");
	}
	___godot_icall_void_float(mb, (const Object *) this, bounce);
}

double StaticBody2D::get_bounce() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StaticBody2D", "get_bounce");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

}