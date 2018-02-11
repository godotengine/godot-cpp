#include <HingeJoint.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *HingeJoint::___get_type_tag()
{
	return (void *) &HingeJoint::___get_type_tag;
}

void *HingeJoint::___get_base_type_tag()
{
	return (void *) &Joint::___get_type_tag;
}

HingeJoint *HingeJoint::_new()
{
	return (HingeJoint *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"HingeJoint")());
}
void HingeJoint::set_param(const int64_t param, const double value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("HingeJoint", "set_param");
	}
	___godot_icall_void_int_float(mb, (const Object *) this, param, value);
}

double HingeJoint::get_param(const int64_t param) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("HingeJoint", "get_param");
	}
	return ___godot_icall_float_int(mb, (const Object *) this, param);
}

void HingeJoint::set_flag(const int64_t flag, const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("HingeJoint", "set_flag");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, flag, enabled);
}

bool HingeJoint::get_flag(const int64_t flag) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("HingeJoint", "get_flag");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, flag);
}

void HingeJoint::_set_upper_limit(const double upper_limit) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("HingeJoint", "_set_upper_limit");
	}
	___godot_icall_void_float(mb, (const Object *) this, upper_limit);
}

double HingeJoint::_get_upper_limit() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("HingeJoint", "_get_upper_limit");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void HingeJoint::_set_lower_limit(const double lower_limit) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("HingeJoint", "_set_lower_limit");
	}
	___godot_icall_void_float(mb, (const Object *) this, lower_limit);
}

double HingeJoint::_get_lower_limit() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("HingeJoint", "_get_lower_limit");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

}