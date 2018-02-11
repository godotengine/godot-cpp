#include <TriangleMesh.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *TriangleMesh::___get_type_tag()
{
	return (void *) &TriangleMesh::___get_type_tag;
}

void *TriangleMesh::___get_base_type_tag()
{
	return (void *) &Reference::___get_type_tag;
}

TriangleMesh *TriangleMesh::_new()
{
	return (TriangleMesh *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"TriangleMesh")());
}
}