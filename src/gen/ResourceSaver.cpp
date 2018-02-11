#include <ResourceSaver.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Resource.hpp>


namespace godot {


void *ResourceSaver::___get_type_tag()
{
	return (void *) &ResourceSaver::___get_type_tag;
}

void *ResourceSaver::___get_base_type_tag()
{
	return (void *) &Object::___get_type_tag;
}

ResourceSaver *ResourceSaver::_singleton = NULL;


ResourceSaver::ResourceSaver() {
	_owner = godot::api->godot_global_get_singleton((char *) "ResourceSaver");
}


Error ResourceSaver::save(const String path, const Ref<Resource> resource, const int64_t flags) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_ResourceSaver", "save");
	}
	return (Error) ___godot_icall_int_String_Object_int(mb, (const Object *) this, path, resource.ptr(), flags);
}

PoolStringArray ResourceSaver::get_recognized_extensions(const Ref<Resource> type) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_ResourceSaver", "get_recognized_extensions");
	}
	return ___godot_icall_PoolStringArray_Object(mb, (const Object *) this, type.ptr());
}

}