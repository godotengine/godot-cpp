#include <RemoteTransform2D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *RemoteTransform2D::___get_type_tag()
{
	return (void *) &RemoteTransform2D::___get_type_tag;
}

void *RemoteTransform2D::___get_base_type_tag()
{
	return (void *) &Node2D::___get_type_tag;
}

RemoteTransform2D *RemoteTransform2D::_new()
{
	return (RemoteTransform2D *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"RemoteTransform2D")());
}
void RemoteTransform2D::set_remote_node(const NodePath path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RemoteTransform2D", "set_remote_node");
	}
	___godot_icall_void_NodePath(mb, (const Object *) this, path);
}

NodePath RemoteTransform2D::get_remote_node() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RemoteTransform2D", "get_remote_node");
	}
	return ___godot_icall_NodePath(mb, (const Object *) this);
}

void RemoteTransform2D::set_use_global_coordinates(const bool use_global_coordinates) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RemoteTransform2D", "set_use_global_coordinates");
	}
	___godot_icall_void_bool(mb, (const Object *) this, use_global_coordinates);
}

bool RemoteTransform2D::get_use_global_coordinates() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RemoteTransform2D", "get_use_global_coordinates");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void RemoteTransform2D::set_update_position(const bool update_remote_position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RemoteTransform2D", "set_update_position");
	}
	___godot_icall_void_bool(mb, (const Object *) this, update_remote_position);
}

bool RemoteTransform2D::get_update_position() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RemoteTransform2D", "get_update_position");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void RemoteTransform2D::set_update_rotation(const bool update_remote_rotation) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RemoteTransform2D", "set_update_rotation");
	}
	___godot_icall_void_bool(mb, (const Object *) this, update_remote_rotation);
}

bool RemoteTransform2D::get_update_rotation() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RemoteTransform2D", "get_update_rotation");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void RemoteTransform2D::set_update_scale(const bool update_remote_scale) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RemoteTransform2D", "set_update_scale");
	}
	___godot_icall_void_bool(mb, (const Object *) this, update_remote_scale);
}

bool RemoteTransform2D::get_update_scale() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RemoteTransform2D", "get_update_scale");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

}