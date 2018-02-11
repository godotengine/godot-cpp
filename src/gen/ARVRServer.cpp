#include <ARVRServer.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <ARVRInterface.hpp>
#include <ARVRPositionalTracker.hpp>


namespace godot {


void *ARVRServer::___get_type_tag()
{
	return (void *) &ARVRServer::___get_type_tag;
}

void *ARVRServer::___get_base_type_tag()
{
	return (void *) &Object::___get_type_tag;
}

ARVRServer *ARVRServer::_singleton = NULL;


ARVRServer::ARVRServer() {
	_owner = godot::api->godot_global_get_singleton((char *) "ARVRServer");
}


double ARVRServer::get_world_scale() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRServer", "get_world_scale");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void ARVRServer::set_world_scale(const double arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRServer", "set_world_scale");
	}
	___godot_icall_void_float(mb, (const Object *) this, arg0);
}

Transform ARVRServer::get_reference_frame() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRServer", "get_reference_frame");
	}
	return ___godot_icall_Transform(mb, (const Object *) this);
}

void ARVRServer::center_on_hmd(const int64_t rotation_mode, const bool keep_height) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRServer", "center_on_hmd");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, rotation_mode, keep_height);
}

Transform ARVRServer::get_hmd_transform() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRServer", "get_hmd_transform");
	}
	return ___godot_icall_Transform(mb, (const Object *) this);
}

int64_t ARVRServer::get_interface_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRServer", "get_interface_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

Ref<ARVRInterface> ARVRServer::get_interface(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRServer", "get_interface");
	}
	return Ref<ARVRInterface>::__internal_constructor(___godot_icall_Object_int(mb, (const Object *) this, idx));
}

Array ARVRServer::get_interfaces() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRServer", "get_interfaces");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

Ref<ARVRInterface> ARVRServer::find_interface(const String name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRServer", "find_interface");
	}
	return Ref<ARVRInterface>::__internal_constructor(___godot_icall_Object_String(mb, (const Object *) this, name));
}

int64_t ARVRServer::get_tracker_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRServer", "get_tracker_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

ARVRPositionalTracker *ARVRServer::get_tracker(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRServer", "get_tracker");
	}
	return (ARVRPositionalTracker *) ___godot_icall_Object_int(mb, (const Object *) this, idx);
}

Ref<ARVRInterface> ARVRServer::get_primary_interface() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRServer", "get_primary_interface");
	}
	return Ref<ARVRInterface>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void ARVRServer::set_primary_interface(const Ref<ARVRInterface> interface) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRServer", "set_primary_interface");
	}
	___godot_icall_void_Object(mb, (const Object *) this, interface.ptr());
}

int64_t ARVRServer::get_last_process_usec() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRServer", "get_last_process_usec");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t ARVRServer::get_last_commit_usec() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRServer", "get_last_commit_usec");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t ARVRServer::get_last_frame_usec() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRServer", "get_last_frame_usec");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

}