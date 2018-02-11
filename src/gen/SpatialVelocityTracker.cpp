#include <SpatialVelocityTracker.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *SpatialVelocityTracker::___get_type_tag()
{
	return (void *) &SpatialVelocityTracker::___get_type_tag;
}

void *SpatialVelocityTracker::___get_base_type_tag()
{
	return (void *) &Reference::___get_type_tag;
}

SpatialVelocityTracker *SpatialVelocityTracker::_new()
{
	return (SpatialVelocityTracker *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"SpatialVelocityTracker")());
}
void SpatialVelocityTracker::set_track_physics_step(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialVelocityTracker", "set_track_physics_step");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool SpatialVelocityTracker::is_tracking_physics_step() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialVelocityTracker", "is_tracking_physics_step");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void SpatialVelocityTracker::update_position(const Vector3 position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialVelocityTracker", "update_position");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, position);
}

Vector3 SpatialVelocityTracker::get_tracked_linear_velocity() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialVelocityTracker", "get_tracked_linear_velocity");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

void SpatialVelocityTracker::reset(const Vector3 position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpatialVelocityTracker", "reset");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, position);
}

}