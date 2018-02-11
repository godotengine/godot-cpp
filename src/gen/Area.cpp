#include <Area.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Object.hpp>


namespace godot {


void *Area::___get_type_tag()
{
	return (void *) &Area::___get_type_tag;
}

void *Area::___get_base_type_tag()
{
	return (void *) &CollisionObject::___get_type_tag;
}

Area *Area::_new()
{
	return (Area *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Area")());
}
void Area::_body_enter_tree(const int64_t id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "_body_enter_tree");
	}
	___godot_icall_void_int(mb, (const Object *) this, id);
}

void Area::_body_exit_tree(const int64_t id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "_body_exit_tree");
	}
	___godot_icall_void_int(mb, (const Object *) this, id);
}

void Area::_area_enter_tree(const int64_t id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "_area_enter_tree");
	}
	___godot_icall_void_int(mb, (const Object *) this, id);
}

void Area::_area_exit_tree(const int64_t id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "_area_exit_tree");
	}
	___godot_icall_void_int(mb, (const Object *) this, id);
}

void Area::set_space_override_mode(const int64_t enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "set_space_override_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, enable);
}

Area::SpaceOverride Area::get_space_override_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "get_space_override_mode");
	}
	return (Area::SpaceOverride) ___godot_icall_int(mb, (const Object *) this);
}

void Area::set_gravity_is_point(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "set_gravity_is_point");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool Area::is_gravity_a_point() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "is_gravity_a_point");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Area::set_gravity_distance_scale(const double distance_scale) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "set_gravity_distance_scale");
	}
	___godot_icall_void_float(mb, (const Object *) this, distance_scale);
}

double Area::get_gravity_distance_scale() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "get_gravity_distance_scale");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Area::set_gravity_vector(const Vector3 vector) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "set_gravity_vector");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, vector);
}

Vector3 Area::get_gravity_vector() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "get_gravity_vector");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

void Area::set_gravity(const double gravity) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "set_gravity");
	}
	___godot_icall_void_float(mb, (const Object *) this, gravity);
}

double Area::get_gravity() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "get_gravity");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Area::set_angular_damp(const double angular_damp) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "set_angular_damp");
	}
	___godot_icall_void_float(mb, (const Object *) this, angular_damp);
}

double Area::get_angular_damp() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "get_angular_damp");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Area::set_linear_damp(const double linear_damp) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "set_linear_damp");
	}
	___godot_icall_void_float(mb, (const Object *) this, linear_damp);
}

double Area::get_linear_damp() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "get_linear_damp");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Area::set_priority(const double priority) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "set_priority");
	}
	___godot_icall_void_float(mb, (const Object *) this, priority);
}

double Area::get_priority() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "get_priority");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Area::set_collision_mask(const int64_t collision_mask) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "set_collision_mask");
	}
	___godot_icall_void_int(mb, (const Object *) this, collision_mask);
}

int64_t Area::get_collision_mask() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "get_collision_mask");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void Area::set_collision_layer(const int64_t collision_layer) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "set_collision_layer");
	}
	___godot_icall_void_int(mb, (const Object *) this, collision_layer);
}

int64_t Area::get_collision_layer() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "get_collision_layer");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void Area::set_collision_mask_bit(const int64_t bit, const bool value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "set_collision_mask_bit");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, bit, value);
}

bool Area::get_collision_mask_bit(const int64_t bit) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "get_collision_mask_bit");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, bit);
}

void Area::set_collision_layer_bit(const int64_t bit, const bool value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "set_collision_layer_bit");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, bit, value);
}

bool Area::get_collision_layer_bit(const int64_t bit) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "get_collision_layer_bit");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, bit);
}

void Area::set_monitorable(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "set_monitorable");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool Area::is_monitorable() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "is_monitorable");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Area::set_monitoring(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "set_monitoring");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool Area::is_monitoring() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "is_monitoring");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

Array Area::get_overlapping_bodies() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "get_overlapping_bodies");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

Array Area::get_overlapping_areas() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "get_overlapping_areas");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

bool Area::overlaps_body(const Object *body) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "overlaps_body");
	}
	return ___godot_icall_bool_Object(mb, (const Object *) this, body);
}

bool Area::overlaps_area(const Object *area) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "overlaps_area");
	}
	return ___godot_icall_bool_Object(mb, (const Object *) this, area);
}

void Area::_body_inout(const int64_t arg0, const RID arg1, const int64_t arg2, const int64_t arg3, const int64_t arg4) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "_body_inout");
	}
	___godot_icall_void_int_RID_int_int_int(mb, (const Object *) this, arg0, arg1, arg2, arg3, arg4);
}

void Area::_area_inout(const int64_t arg0, const RID arg1, const int64_t arg2, const int64_t arg3, const int64_t arg4) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "_area_inout");
	}
	___godot_icall_void_int_RID_int_int_int(mb, (const Object *) this, arg0, arg1, arg2, arg3, arg4);
}

void Area::set_audio_bus_override(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "set_audio_bus_override");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool Area::is_overriding_audio_bus() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "is_overriding_audio_bus");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Area::set_audio_bus(const String name) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "set_audio_bus");
	}
	___godot_icall_void_String(mb, (const Object *) this, name);
}

String Area::get_audio_bus() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "get_audio_bus");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void Area::set_use_reverb_bus(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "set_use_reverb_bus");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool Area::is_using_reverb_bus() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "is_using_reverb_bus");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Area::set_reverb_bus(const String name) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "set_reverb_bus");
	}
	___godot_icall_void_String(mb, (const Object *) this, name);
}

String Area::get_reverb_bus() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "get_reverb_bus");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void Area::set_reverb_amount(const double amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "set_reverb_amount");
	}
	___godot_icall_void_float(mb, (const Object *) this, amount);
}

double Area::get_reverb_amount() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "get_reverb_amount");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Area::set_reverb_uniformity(const double amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "set_reverb_uniformity");
	}
	___godot_icall_void_float(mb, (const Object *) this, amount);
}

double Area::get_reverb_uniformity() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Area", "get_reverb_uniformity");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

}