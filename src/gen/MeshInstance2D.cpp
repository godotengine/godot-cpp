#include <MeshInstance2D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Mesh.hpp>
#include <Texture.hpp>


namespace godot {


void *MeshInstance2D::___get_type_tag()
{
	return (void *) &MeshInstance2D::___get_type_tag;
}

void *MeshInstance2D::___get_base_type_tag()
{
	return (void *) &Node2D::___get_type_tag;
}

MeshInstance2D *MeshInstance2D::_new()
{
	return (MeshInstance2D *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"MeshInstance2D")());
}
void MeshInstance2D::set_mesh(const Ref<Mesh> mesh) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshInstance2D", "set_mesh");
	}
	___godot_icall_void_Object(mb, (const Object *) this, mesh.ptr());
}

Ref<Mesh> MeshInstance2D::get_mesh() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshInstance2D", "get_mesh");
	}
	return Ref<Mesh>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void MeshInstance2D::set_texture(const Ref<Texture> texture) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshInstance2D", "set_texture");
	}
	___godot_icall_void_Object(mb, (const Object *) this, texture.ptr());
}

Ref<Texture> MeshInstance2D::get_texture() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshInstance2D", "get_texture");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void MeshInstance2D::set_normal_map(const Ref<Texture> normal_map) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshInstance2D", "set_normal_map");
	}
	___godot_icall_void_Object(mb, (const Object *) this, normal_map.ptr());
}

Ref<Texture> MeshInstance2D::get_normal_map() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshInstance2D", "get_normal_map");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

}