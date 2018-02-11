#include <ARVRPositionalTracker.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *ARVRPositionalTracker::___get_type_tag()
{
	return (void *) &ARVRPositionalTracker::___get_type_tag;
}

void *ARVRPositionalTracker::___get_base_type_tag()
{
	return (void *) &Object::___get_type_tag;
}

ARVRPositionalTracker *ARVRPositionalTracker::_new()
{
	return (ARVRPositionalTracker *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"ARVRPositionalTracker")());
}
ARVRServer::TrackerType ARVRPositionalTracker::get_type() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRPositionalTracker", "get_type");
	}
	return (ARVRServer::TrackerType) ___godot_icall_int(mb, (const Object *) this);
}

String ARVRPositionalTracker::get_name() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRPositionalTracker", "get_name");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

int64_t ARVRPositionalTracker::get_joy_id() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRPositionalTracker", "get_joy_id");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

bool ARVRPositionalTracker::get_tracks_orientation() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRPositionalTracker", "get_tracks_orientation");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

Basis ARVRPositionalTracker::get_orientation() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRPositionalTracker", "get_orientation");
	}
	return ___godot_icall_Basis(mb, (const Object *) this);
}

bool ARVRPositionalTracker::get_tracks_position() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRPositionalTracker", "get_tracks_position");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

Vector3 ARVRPositionalTracker::get_position() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRPositionalTracker", "get_position");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

ARVRPositionalTracker::TrackerHand ARVRPositionalTracker::get_hand() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRPositionalTracker", "get_hand");
	}
	return (ARVRPositionalTracker::TrackerHand) ___godot_icall_int(mb, (const Object *) this);
}

Transform ARVRPositionalTracker::get_transform(const bool adjust_by_reference_frame) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRPositionalTracker", "get_transform");
	}
	return ___godot_icall_Transform_bool(mb, (const Object *) this, adjust_by_reference_frame);
}

void ARVRPositionalTracker::_set_type(const int64_t type) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRPositionalTracker", "_set_type");
	}
	___godot_icall_void_int(mb, (const Object *) this, type);
}

void ARVRPositionalTracker::_set_name(const String name) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRPositionalTracker", "_set_name");
	}
	___godot_icall_void_String(mb, (const Object *) this, name);
}

void ARVRPositionalTracker::_set_joy_id(const int64_t joy_id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRPositionalTracker", "_set_joy_id");
	}
	___godot_icall_void_int(mb, (const Object *) this, joy_id);
}

void ARVRPositionalTracker::_set_orientation(const Basis orientation) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRPositionalTracker", "_set_orientation");
	}
	___godot_icall_void_Basis(mb, (const Object *) this, orientation);
}

void ARVRPositionalTracker::_set_rw_position(const Vector3 rw_position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRPositionalTracker", "_set_rw_position");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, rw_position);
}

double ARVRPositionalTracker::get_rumble() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRPositionalTracker", "get_rumble");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void ARVRPositionalTracker::set_rumble(const double rumble) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRPositionalTracker", "set_rumble");
	}
	___godot_icall_void_float(mb, (const Object *) this, rumble);
}

}