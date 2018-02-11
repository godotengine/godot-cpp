#include <ResourceInteractiveLoader.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Resource.hpp>


namespace godot {


void *ResourceInteractiveLoader::___get_type_tag()
{
	return (void *) &ResourceInteractiveLoader::___get_type_tag;
}

void *ResourceInteractiveLoader::___get_base_type_tag()
{
	return (void *) &Reference::___get_type_tag;
}

Ref<Resource> ResourceInteractiveLoader::get_resource() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ResourceInteractiveLoader", "get_resource");
	}
	return Ref<Resource>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

Error ResourceInteractiveLoader::poll() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ResourceInteractiveLoader", "poll");
	}
	return (Error) ___godot_icall_int(mb, (const Object *) this);
}

Error ResourceInteractiveLoader::wait() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ResourceInteractiveLoader", "wait");
	}
	return (Error) ___godot_icall_int(mb, (const Object *) this);
}

int64_t ResourceInteractiveLoader::get_stage() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ResourceInteractiveLoader", "get_stage");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t ResourceInteractiveLoader::get_stage_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ResourceInteractiveLoader", "get_stage_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

}