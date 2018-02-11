#include <SliderJoint.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *SliderJoint::___get_type_tag()
{
	return (void *) &SliderJoint::___get_type_tag;
}

void *SliderJoint::___get_base_type_tag()
{
	return (void *) &Joint::___get_type_tag;
}

SliderJoint *SliderJoint::_new()
{
	return (SliderJoint *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"SliderJoint")());
}
void SliderJoint::set_param(const int64_t param, const double value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SliderJoint", "set_param");
	}
	___godot_icall_void_int_float(mb, (const Object *) this, param, value);
}

double SliderJoint::get_param(const int64_t param) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SliderJoint", "get_param");
	}
	return ___godot_icall_float_int(mb, (const Object *) this, param);
}

void SliderJoint::_set_upper_limit_angular(const double upper_limit_angular) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SliderJoint", "_set_upper_limit_angular");
	}
	___godot_icall_void_float(mb, (const Object *) this, upper_limit_angular);
}

double SliderJoint::_get_upper_limit_angular() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SliderJoint", "_get_upper_limit_angular");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void SliderJoint::_set_lower_limit_angular(const double lower_limit_angular) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SliderJoint", "_set_lower_limit_angular");
	}
	___godot_icall_void_float(mb, (const Object *) this, lower_limit_angular);
}

double SliderJoint::_get_lower_limit_angular() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SliderJoint", "_get_lower_limit_angular");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

}