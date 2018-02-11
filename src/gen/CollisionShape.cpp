#include <CollisionShape.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Resource.hpp>
#include <Shape.hpp>


namespace godot {


void *CollisionShape::___get_type_tag()
{
	return (void *) &CollisionShape::___get_type_tag;
}

void *CollisionShape::___get_base_type_tag()
{
	return (void *) &Spatial::___get_type_tag;
}

CollisionShape *CollisionShape::_new()
{
	return (CollisionShape *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"CollisionShape")());
}
void CollisionShape::resource_changed(const Ref<Resource> resource) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionShape", "resource_changed");
	}
	___godot_icall_void_Object(mb, (const Object *) this, resource.ptr());
}

void CollisionShape::set_shape(const Ref<Shape> shape) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionShape", "set_shape");
	}
	___godot_icall_void_Object(mb, (const Object *) this, shape.ptr());
}

Ref<Shape> CollisionShape::get_shape() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionShape", "get_shape");
	}
	return Ref<Shape>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void CollisionShape::set_disabled(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionShape", "set_disabled");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool CollisionShape::is_disabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionShape", "is_disabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void CollisionShape::make_convex_from_brothers() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionShape", "make_convex_from_brothers");
	}
	___godot_icall_void(mb, (const Object *) this);
}

}