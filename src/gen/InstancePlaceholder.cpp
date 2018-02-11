#include <InstancePlaceholder.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <PackedScene.hpp>


namespace godot {


void *InstancePlaceholder::___get_type_tag()
{
	return (void *) &InstancePlaceholder::___get_type_tag;
}

void *InstancePlaceholder::___get_base_type_tag()
{
	return (void *) &Node::___get_type_tag;
}

Dictionary InstancePlaceholder::get_stored_values(const bool with_order) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InstancePlaceholder", "get_stored_values");
	}
	return ___godot_icall_Dictionary_bool(mb, (const Object *) this, with_order);
}

void InstancePlaceholder::replace_by_instance(const Ref<PackedScene> custom_scene) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InstancePlaceholder", "replace_by_instance");
	}
	___godot_icall_void_Object(mb, (const Object *) this, custom_scene.ptr());
}

String InstancePlaceholder::get_instance_path() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InstancePlaceholder", "get_instance_path");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

}