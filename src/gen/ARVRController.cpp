#include <ARVRController.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *ARVRController::___get_type_tag()
{
	return (void *) &ARVRController::___get_type_tag;
}

void *ARVRController::___get_base_type_tag()
{
	return (void *) &Spatial::___get_type_tag;
}

ARVRController *ARVRController::_new()
{
	return (ARVRController *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"ARVRController")());
}
void ARVRController::set_controller_id(const int64_t controller_id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRController", "set_controller_id");
	}
	___godot_icall_void_int(mb, (const Object *) this, controller_id);
}

int64_t ARVRController::get_controller_id() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRController", "get_controller_id");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

String ARVRController::get_controller_name() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRController", "get_controller_name");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

int64_t ARVRController::get_joystick_id() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRController", "get_joystick_id");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t ARVRController::is_button_pressed(const int64_t button) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRController", "is_button_pressed");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, button);
}

double ARVRController::get_joystick_axis(const int64_t axis) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRController", "get_joystick_axis");
	}
	return ___godot_icall_float_int(mb, (const Object *) this, axis);
}

bool ARVRController::get_is_active() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRController", "get_is_active");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

ARVRPositionalTracker::TrackerHand ARVRController::get_hand() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRController", "get_hand");
	}
	return (ARVRPositionalTracker::TrackerHand) ___godot_icall_int(mb, (const Object *) this);
}

double ARVRController::get_rumble() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRController", "get_rumble");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void ARVRController::set_rumble(const double rumble) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRController", "set_rumble");
	}
	___godot_icall_void_float(mb, (const Object *) this, rumble);
}

}