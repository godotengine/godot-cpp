#include <Generic6DOFJoint.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *Generic6DOFJoint::___get_type_tag()
{
	return (void *) &Generic6DOFJoint::___get_type_tag;
}

void *Generic6DOFJoint::___get_base_type_tag()
{
	return (void *) &Joint::___get_type_tag;
}

Generic6DOFJoint *Generic6DOFJoint::_new()
{
	return (Generic6DOFJoint *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Generic6DOFJoint")());
}
void Generic6DOFJoint::_set_angular_hi_limit_x(const double angle) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Generic6DOFJoint", "_set_angular_hi_limit_x");
	}
	___godot_icall_void_float(mb, (const Object *) this, angle);
}

double Generic6DOFJoint::_get_angular_hi_limit_x() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Generic6DOFJoint", "_get_angular_hi_limit_x");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Generic6DOFJoint::_set_angular_lo_limit_x(const double angle) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Generic6DOFJoint", "_set_angular_lo_limit_x");
	}
	___godot_icall_void_float(mb, (const Object *) this, angle);
}

double Generic6DOFJoint::_get_angular_lo_limit_x() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Generic6DOFJoint", "_get_angular_lo_limit_x");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Generic6DOFJoint::_set_angular_hi_limit_y(const double angle) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Generic6DOFJoint", "_set_angular_hi_limit_y");
	}
	___godot_icall_void_float(mb, (const Object *) this, angle);
}

double Generic6DOFJoint::_get_angular_hi_limit_y() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Generic6DOFJoint", "_get_angular_hi_limit_y");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Generic6DOFJoint::_set_angular_lo_limit_y(const double angle) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Generic6DOFJoint", "_set_angular_lo_limit_y");
	}
	___godot_icall_void_float(mb, (const Object *) this, angle);
}

double Generic6DOFJoint::_get_angular_lo_limit_y() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Generic6DOFJoint", "_get_angular_lo_limit_y");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Generic6DOFJoint::_set_angular_hi_limit_z(const double angle) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Generic6DOFJoint", "_set_angular_hi_limit_z");
	}
	___godot_icall_void_float(mb, (const Object *) this, angle);
}

double Generic6DOFJoint::_get_angular_hi_limit_z() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Generic6DOFJoint", "_get_angular_hi_limit_z");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Generic6DOFJoint::_set_angular_lo_limit_z(const double angle) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Generic6DOFJoint", "_set_angular_lo_limit_z");
	}
	___godot_icall_void_float(mb, (const Object *) this, angle);
}

double Generic6DOFJoint::_get_angular_lo_limit_z() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Generic6DOFJoint", "_get_angular_lo_limit_z");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Generic6DOFJoint::set_param_x(const int64_t param, const double value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Generic6DOFJoint", "set_param_x");
	}
	___godot_icall_void_int_float(mb, (const Object *) this, param, value);
}

double Generic6DOFJoint::get_param_x(const int64_t param) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Generic6DOFJoint", "get_param_x");
	}
	return ___godot_icall_float_int(mb, (const Object *) this, param);
}

void Generic6DOFJoint::set_param_y(const int64_t param, const double value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Generic6DOFJoint", "set_param_y");
	}
	___godot_icall_void_int_float(mb, (const Object *) this, param, value);
}

double Generic6DOFJoint::get_param_y(const int64_t param) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Generic6DOFJoint", "get_param_y");
	}
	return ___godot_icall_float_int(mb, (const Object *) this, param);
}

void Generic6DOFJoint::set_param_z(const int64_t param, const double value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Generic6DOFJoint", "set_param_z");
	}
	___godot_icall_void_int_float(mb, (const Object *) this, param, value);
}

double Generic6DOFJoint::get_param_z(const int64_t param) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Generic6DOFJoint", "get_param_z");
	}
	return ___godot_icall_float_int(mb, (const Object *) this, param);
}

void Generic6DOFJoint::set_flag_x(const int64_t flag, const bool value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Generic6DOFJoint", "set_flag_x");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, flag, value);
}

bool Generic6DOFJoint::get_flag_x(const int64_t flag) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Generic6DOFJoint", "get_flag_x");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, flag);
}

void Generic6DOFJoint::set_flag_y(const int64_t flag, const bool value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Generic6DOFJoint", "set_flag_y");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, flag, value);
}

bool Generic6DOFJoint::get_flag_y(const int64_t flag) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Generic6DOFJoint", "get_flag_y");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, flag);
}

void Generic6DOFJoint::set_flag_z(const int64_t flag, const bool value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Generic6DOFJoint", "set_flag_z");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, flag, value);
}

bool Generic6DOFJoint::get_flag_z(const int64_t flag) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Generic6DOFJoint", "get_flag_z");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, flag);
}

}