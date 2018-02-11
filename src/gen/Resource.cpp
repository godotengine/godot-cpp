#include <Resource.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Node.hpp>
#include <Resource.hpp>


namespace godot {


void *Resource::___get_type_tag()
{
	return (void *) &Resource::___get_type_tag;
}

void *Resource::___get_base_type_tag()
{
	return (void *) &Reference::___get_type_tag;
}

Resource *Resource::_new()
{
	return (Resource *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Resource")());
}
void Resource::_setup_local_to_scene() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Resource", "_setup_local_to_scene");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Resource::set_path(const String path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Resource", "set_path");
	}
	___godot_icall_void_String(mb, (const Object *) this, path);
}

void Resource::take_over_path(const String path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Resource", "take_over_path");
	}
	___godot_icall_void_String(mb, (const Object *) this, path);
}

String Resource::get_path() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Resource", "get_path");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void Resource::set_name(const String name) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Resource", "set_name");
	}
	___godot_icall_void_String(mb, (const Object *) this, name);
}

String Resource::get_name() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Resource", "get_name");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

RID Resource::get_rid() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Resource", "get_rid");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

void Resource::set_local_to_scene(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Resource", "set_local_to_scene");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool Resource::is_local_to_scene() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Resource", "is_local_to_scene");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

Node *Resource::get_local_scene() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Resource", "get_local_scene");
	}
	return (Node *) ___godot_icall_Object(mb, (const Object *) this);
}

void Resource::setup_local_to_scene() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Resource", "setup_local_to_scene");
	}
	___godot_icall_void(mb, (const Object *) this);
}

Ref<Resource> Resource::duplicate(const bool subresources) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Resource", "duplicate");
	}
	return Ref<Resource>::__internal_constructor(___godot_icall_Object_bool(mb, (const Object *) this, subresources));
}

}