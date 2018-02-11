#include <BoneAttachment.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *BoneAttachment::___get_type_tag()
{
	return (void *) &BoneAttachment::___get_type_tag;
}

void *BoneAttachment::___get_base_type_tag()
{
	return (void *) &Spatial::___get_type_tag;
}

BoneAttachment *BoneAttachment::_new()
{
	return (BoneAttachment *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"BoneAttachment")());
}
void BoneAttachment::set_bone_name(const String bone_name) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BoneAttachment", "set_bone_name");
	}
	___godot_icall_void_String(mb, (const Object *) this, bone_name);
}

String BoneAttachment::get_bone_name() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BoneAttachment", "get_bone_name");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

}