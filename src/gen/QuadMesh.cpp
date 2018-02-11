#include <QuadMesh.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *QuadMesh::___get_type_tag()
{
	return (void *) &QuadMesh::___get_type_tag;
}

void *QuadMesh::___get_base_type_tag()
{
	return (void *) &PrimitiveMesh::___get_type_tag;
}

QuadMesh *QuadMesh::_new()
{
	return (QuadMesh *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"QuadMesh")());
}
void QuadMesh::set_size(const Vector2 size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("QuadMesh", "set_size");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, size);
}

Vector2 QuadMesh::get_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("QuadMesh", "get_size");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

}