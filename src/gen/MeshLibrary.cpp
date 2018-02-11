#include <MeshLibrary.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Mesh.hpp>
#include <NavigationMesh.hpp>
#include <Texture.hpp>


namespace godot {


void *MeshLibrary::___get_type_tag()
{
	return (void *) &MeshLibrary::___get_type_tag;
}

void *MeshLibrary::___get_base_type_tag()
{
	return (void *) &Resource::___get_type_tag;
}

MeshLibrary *MeshLibrary::_new()
{
	return (MeshLibrary *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"MeshLibrary")());
}
void MeshLibrary::create_item(const int64_t id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshLibrary", "create_item");
	}
	___godot_icall_void_int(mb, (const Object *) this, id);
}

void MeshLibrary::set_item_name(const int64_t id, const String name) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshLibrary", "set_item_name");
	}
	___godot_icall_void_int_String(mb, (const Object *) this, id, name);
}

void MeshLibrary::set_item_mesh(const int64_t id, const Ref<Mesh> mesh) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshLibrary", "set_item_mesh");
	}
	___godot_icall_void_int_Object(mb, (const Object *) this, id, mesh.ptr());
}

void MeshLibrary::set_item_navmesh(const int64_t id, const Ref<NavigationMesh> navmesh) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshLibrary", "set_item_navmesh");
	}
	___godot_icall_void_int_Object(mb, (const Object *) this, id, navmesh.ptr());
}

void MeshLibrary::set_item_shapes(const int64_t id, const Array shapes) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshLibrary", "set_item_shapes");
	}
	___godot_icall_void_int_Array(mb, (const Object *) this, id, shapes);
}

void MeshLibrary::set_item_preview(const int64_t id, const Ref<Texture> texture) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshLibrary", "set_item_preview");
	}
	___godot_icall_void_int_Object(mb, (const Object *) this, id, texture.ptr());
}

String MeshLibrary::get_item_name(const int64_t id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshLibrary", "get_item_name");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, id);
}

Ref<Mesh> MeshLibrary::get_item_mesh(const int64_t id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshLibrary", "get_item_mesh");
	}
	return Ref<Mesh>::__internal_constructor(___godot_icall_Object_int(mb, (const Object *) this, id));
}

Ref<NavigationMesh> MeshLibrary::get_item_navmesh(const int64_t id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshLibrary", "get_item_navmesh");
	}
	return Ref<NavigationMesh>::__internal_constructor(___godot_icall_Object_int(mb, (const Object *) this, id));
}

Array MeshLibrary::get_item_shapes(const int64_t id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshLibrary", "get_item_shapes");
	}
	return ___godot_icall_Array_int(mb, (const Object *) this, id);
}

Ref<Texture> MeshLibrary::get_item_preview(const int64_t id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshLibrary", "get_item_preview");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object_int(mb, (const Object *) this, id));
}

void MeshLibrary::remove_item(const int64_t id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshLibrary", "remove_item");
	}
	___godot_icall_void_int(mb, (const Object *) this, id);
}

int64_t MeshLibrary::find_item_by_name(const String name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshLibrary", "find_item_by_name");
	}
	return ___godot_icall_int_String(mb, (const Object *) this, name);
}

void MeshLibrary::clear() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshLibrary", "clear");
	}
	___godot_icall_void(mb, (const Object *) this);
}

PoolIntArray MeshLibrary::get_item_list() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshLibrary", "get_item_list");
	}
	return ___godot_icall_PoolIntArray(mb, (const Object *) this);
}

int64_t MeshLibrary::get_last_unused_item_id() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MeshLibrary", "get_last_unused_item_id");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

}