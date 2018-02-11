#include <MultiMesh.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Mesh.hpp>


namespace godot {


void *MultiMesh::___get_type_tag()
{
	return (void *) &MultiMesh::___get_type_tag;
}

void *MultiMesh::___get_base_type_tag()
{
	return (void *) &Resource::___get_type_tag;
}

MultiMesh *MultiMesh::_new()
{
	return (MultiMesh *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"MultiMesh")());
}
void MultiMesh::set_mesh(const Ref<Mesh> mesh) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MultiMesh", "set_mesh");
	}
	___godot_icall_void_Object(mb, (const Object *) this, mesh.ptr());
}

Ref<Mesh> MultiMesh::get_mesh() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MultiMesh", "get_mesh");
	}
	return Ref<Mesh>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void MultiMesh::set_color_format(const int64_t format) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MultiMesh", "set_color_format");
	}
	___godot_icall_void_int(mb, (const Object *) this, format);
}

MultiMesh::ColorFormat MultiMesh::get_color_format() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MultiMesh", "get_color_format");
	}
	return (MultiMesh::ColorFormat) ___godot_icall_int(mb, (const Object *) this);
}

void MultiMesh::set_transform_format(const int64_t format) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MultiMesh", "set_transform_format");
	}
	___godot_icall_void_int(mb, (const Object *) this, format);
}

MultiMesh::TransformFormat MultiMesh::get_transform_format() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MultiMesh", "get_transform_format");
	}
	return (MultiMesh::TransformFormat) ___godot_icall_int(mb, (const Object *) this);
}

void MultiMesh::set_instance_count(const int64_t count) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MultiMesh", "set_instance_count");
	}
	___godot_icall_void_int(mb, (const Object *) this, count);
}

int64_t MultiMesh::get_instance_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MultiMesh", "get_instance_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void MultiMesh::set_instance_transform(const int64_t instance, const Transform transform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MultiMesh", "set_instance_transform");
	}
	___godot_icall_void_int_Transform(mb, (const Object *) this, instance, transform);
}

Transform MultiMesh::get_instance_transform(const int64_t instance) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MultiMesh", "get_instance_transform");
	}
	return ___godot_icall_Transform_int(mb, (const Object *) this, instance);
}

void MultiMesh::set_instance_color(const int64_t instance, const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MultiMesh", "set_instance_color");
	}
	___godot_icall_void_int_Color(mb, (const Object *) this, instance, color);
}

Color MultiMesh::get_instance_color(const int64_t instance) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MultiMesh", "get_instance_color");
	}
	return ___godot_icall_Color_int(mb, (const Object *) this, instance);
}

AABB MultiMesh::get_aabb() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MultiMesh", "get_aabb");
	}
	return ___godot_icall_AABB(mb, (const Object *) this);
}

void MultiMesh::_set_transform_array(const PoolVector3Array arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MultiMesh", "_set_transform_array");
	}
	___godot_icall_void_PoolVector3Array(mb, (const Object *) this, arg0);
}

PoolVector3Array MultiMesh::_get_transform_array() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MultiMesh", "_get_transform_array");
	}
	return ___godot_icall_PoolVector3Array(mb, (const Object *) this);
}

void MultiMesh::_set_color_array(const PoolColorArray arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MultiMesh", "_set_color_array");
	}
	___godot_icall_void_PoolColorArray(mb, (const Object *) this, arg0);
}

PoolColorArray MultiMesh::_get_color_array() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MultiMesh", "_get_color_array");
	}
	return ___godot_icall_PoolColorArray(mb, (const Object *) this);
}

}