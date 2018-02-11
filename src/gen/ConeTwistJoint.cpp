#include <ConeTwistJoint.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *ConeTwistJoint::___get_type_tag()
{
	return (void *) &ConeTwistJoint::___get_type_tag;
}

void *ConeTwistJoint::___get_base_type_tag()
{
	return (void *) &Joint::___get_type_tag;
}

ConeTwistJoint *ConeTwistJoint::_new()
{
	return (ConeTwistJoint *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"ConeTwistJoint")());
}
void ConeTwistJoint::set_param(const int64_t param, const double value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ConeTwistJoint", "set_param");
	}
	___godot_icall_void_int_float(mb, (const Object *) this, param, value);
}

double ConeTwistJoint::get_param(const int64_t param) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ConeTwistJoint", "get_param");
	}
	return ___godot_icall_float_int(mb, (const Object *) this, param);
}

void ConeTwistJoint::_set_swing_span(const double swing_span) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ConeTwistJoint", "_set_swing_span");
	}
	___godot_icall_void_float(mb, (const Object *) this, swing_span);
}

double ConeTwistJoint::_get_swing_span() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ConeTwistJoint", "_get_swing_span");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void ConeTwistJoint::_set_twist_span(const double twist_span) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ConeTwistJoint", "_set_twist_span");
	}
	___godot_icall_void_float(mb, (const Object *) this, twist_span);
}

double ConeTwistJoint::_get_twist_span() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ConeTwistJoint", "_get_twist_span");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

}