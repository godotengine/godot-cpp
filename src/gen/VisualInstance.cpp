#include <VisualInstance.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *VisualInstance::___get_type_tag()
{
	return (void *) &VisualInstance::___get_type_tag;
}

void *VisualInstance::___get_base_type_tag()
{
	return (void *) &Spatial::___get_type_tag;
}

RID VisualInstance::_get_visual_instance_rid() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualInstance", "_get_visual_instance_rid");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

void VisualInstance::set_base(const RID base) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualInstance", "set_base");
	}
	___godot_icall_void_RID(mb, (const Object *) this, base);
}

void VisualInstance::set_layer_mask(const int64_t mask) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualInstance", "set_layer_mask");
	}
	___godot_icall_void_int(mb, (const Object *) this, mask);
}

int64_t VisualInstance::get_layer_mask() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualInstance", "get_layer_mask");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

AABB VisualInstance::get_transformed_aabb() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualInstance", "get_transformed_aabb");
	}
	return ___godot_icall_AABB(mb, (const Object *) this);
}

AABB VisualInstance::get_aabb() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualInstance", "get_aabb");
	}
	return ___godot_icall_AABB(mb, (const Object *) this);
}

}