#include <ResourcePreloader.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Resource.hpp>


namespace godot {


void *ResourcePreloader::___get_type_tag()
{
	return (void *) &ResourcePreloader::___get_type_tag;
}

void *ResourcePreloader::___get_base_type_tag()
{
	return (void *) &Node::___get_type_tag;
}

ResourcePreloader *ResourcePreloader::_new()
{
	return (ResourcePreloader *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"ResourcePreloader")());
}
void ResourcePreloader::_set_resources(const Array arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ResourcePreloader", "_set_resources");
	}
	___godot_icall_void_Array(mb, (const Object *) this, arg0);
}

Array ResourcePreloader::_get_resources() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ResourcePreloader", "_get_resources");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

void ResourcePreloader::add_resource(const String name, const Ref<Resource> resource) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ResourcePreloader", "add_resource");
	}
	___godot_icall_void_String_Object(mb, (const Object *) this, name, resource.ptr());
}

void ResourcePreloader::remove_resource(const String name) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ResourcePreloader", "remove_resource");
	}
	___godot_icall_void_String(mb, (const Object *) this, name);
}

void ResourcePreloader::rename_resource(const String name, const String newname) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ResourcePreloader", "rename_resource");
	}
	___godot_icall_void_String_String(mb, (const Object *) this, name, newname);
}

bool ResourcePreloader::has_resource(const String name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ResourcePreloader", "has_resource");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, name);
}

Ref<Resource> ResourcePreloader::get_resource(const String name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ResourcePreloader", "get_resource");
	}
	return Ref<Resource>::__internal_constructor(___godot_icall_Object_String(mb, (const Object *) this, name));
}

PoolStringArray ResourcePreloader::get_resource_list() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ResourcePreloader", "get_resource_list");
	}
	return ___godot_icall_PoolStringArray(mb, (const Object *) this);
}

}