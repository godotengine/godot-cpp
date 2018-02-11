#include <MultiMeshInstance.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <MultiMesh.hpp>


namespace godot {


void *MultiMeshInstance::___get_type_tag()
{
	return (void *) &MultiMeshInstance::___get_type_tag;
}

void *MultiMeshInstance::___get_base_type_tag()
{
	return (void *) &GeometryInstance::___get_type_tag;
}

MultiMeshInstance *MultiMeshInstance::_new()
{
	return (MultiMeshInstance *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"MultiMeshInstance")());
}
void MultiMeshInstance::set_multimesh(const Ref<MultiMesh> multimesh) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MultiMeshInstance", "set_multimesh");
	}
	___godot_icall_void_Object(mb, (const Object *) this, multimesh.ptr());
}

Ref<MultiMesh> MultiMeshInstance::get_multimesh() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MultiMeshInstance", "get_multimesh");
	}
	return Ref<MultiMesh>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

}