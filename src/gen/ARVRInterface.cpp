#include <ARVRInterface.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *ARVRInterface::___get_type_tag()
{
	return (void *) &ARVRInterface::___get_type_tag;
}

void *ARVRInterface::___get_base_type_tag()
{
	return (void *) &Reference::___get_type_tag;
}

String ARVRInterface::get_name() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRInterface", "get_name");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

int64_t ARVRInterface::get_capabilities() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRInterface", "get_capabilities");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

bool ARVRInterface::is_primary() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRInterface", "is_primary");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void ARVRInterface::set_is_primary(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRInterface", "set_is_primary");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool ARVRInterface::is_initialized() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRInterface", "is_initialized");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void ARVRInterface::set_is_initialized(const bool initialized) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRInterface", "set_is_initialized");
	}
	___godot_icall_void_bool(mb, (const Object *) this, initialized);
}

bool ARVRInterface::initialize() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRInterface", "initialize");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void ARVRInterface::uninitialize() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRInterface", "uninitialize");
	}
	___godot_icall_void(mb, (const Object *) this);
}

ARVRInterface::Tracking_status ARVRInterface::get_tracking_status() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRInterface", "get_tracking_status");
	}
	return (ARVRInterface::Tracking_status) ___godot_icall_int(mb, (const Object *) this);
}

Vector2 ARVRInterface::get_render_targetsize() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRInterface", "get_render_targetsize");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

bool ARVRInterface::is_stereo() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRInterface", "is_stereo");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

bool ARVRInterface::get_anchor_detection_is_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRInterface", "get_anchor_detection_is_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void ARVRInterface::set_anchor_detection_is_enabled(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRInterface", "set_anchor_detection_is_enabled");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

}