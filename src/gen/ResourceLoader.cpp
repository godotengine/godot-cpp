#include <ResourceLoader.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <ResourceInteractiveLoader.hpp>
#include <Resource.hpp>


namespace godot {


void *ResourceLoader::___get_type_tag()
{
	return (void *) &ResourceLoader::___get_type_tag;
}

void *ResourceLoader::___get_base_type_tag()
{
	return (void *) &Object::___get_type_tag;
}

ResourceLoader *ResourceLoader::_singleton = NULL;


ResourceLoader::ResourceLoader() {
	_owner = godot::api->godot_global_get_singleton((char *) "ResourceLoader");
}


Ref<ResourceInteractiveLoader> ResourceLoader::load_interactive(const String path, const String type_hint) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_ResourceLoader", "load_interactive");
	}
	return Ref<ResourceInteractiveLoader>::__internal_constructor(___godot_icall_Object_String_String(mb, (const Object *) this, path, type_hint));
}

Ref<Resource> ResourceLoader::load(const String path, const String type_hint, const bool p_no_cache) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_ResourceLoader", "load");
	}
	return Ref<Resource>::__internal_constructor(___godot_icall_Object_String_String_bool(mb, (const Object *) this, path, type_hint, p_no_cache));
}

PoolStringArray ResourceLoader::get_recognized_extensions_for_type(const String type) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_ResourceLoader", "get_recognized_extensions_for_type");
	}
	return ___godot_icall_PoolStringArray_String(mb, (const Object *) this, type);
}

void ResourceLoader::set_abort_on_missing_resources(const bool abort) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_ResourceLoader", "set_abort_on_missing_resources");
	}
	___godot_icall_void_bool(mb, (const Object *) this, abort);
}

PoolStringArray ResourceLoader::get_dependencies(const String path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_ResourceLoader", "get_dependencies");
	}
	return ___godot_icall_PoolStringArray_String(mb, (const Object *) this, path);
}

bool ResourceLoader::has(const String path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_ResourceLoader", "has");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, path);
}

}