#include <PhysicsShapeQueryParameters.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Resource.hpp>


namespace godot {


void *PhysicsShapeQueryParameters::___get_type_tag()
{
	return (void *) &PhysicsShapeQueryParameters::___get_type_tag;
}

void *PhysicsShapeQueryParameters::___get_base_type_tag()
{
	return (void *) &Reference::___get_type_tag;
}

PhysicsShapeQueryParameters *PhysicsShapeQueryParameters::_new()
{
	return (PhysicsShapeQueryParameters *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"PhysicsShapeQueryParameters")());
}
void PhysicsShapeQueryParameters::set_shape(const Ref<Resource> shape) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsShapeQueryParameters", "set_shape");
	}
	___godot_icall_void_Object(mb, (const Object *) this, shape.ptr());
}

void PhysicsShapeQueryParameters::set_shape_rid(const RID shape) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsShapeQueryParameters", "set_shape_rid");
	}
	___godot_icall_void_RID(mb, (const Object *) this, shape);
}

RID PhysicsShapeQueryParameters::get_shape_rid() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsShapeQueryParameters", "get_shape_rid");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

void PhysicsShapeQueryParameters::set_transform(const Transform transform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsShapeQueryParameters", "set_transform");
	}
	___godot_icall_void_Transform(mb, (const Object *) this, transform);
}

Transform PhysicsShapeQueryParameters::get_transform() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsShapeQueryParameters", "get_transform");
	}
	return ___godot_icall_Transform(mb, (const Object *) this);
}

void PhysicsShapeQueryParameters::set_margin(const double margin) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsShapeQueryParameters", "set_margin");
	}
	___godot_icall_void_float(mb, (const Object *) this, margin);
}

double PhysicsShapeQueryParameters::get_margin() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsShapeQueryParameters", "get_margin");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void PhysicsShapeQueryParameters::set_collision_mask(const int64_t collision_mask) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsShapeQueryParameters", "set_collision_mask");
	}
	___godot_icall_void_int(mb, (const Object *) this, collision_mask);
}

int64_t PhysicsShapeQueryParameters::get_collision_mask() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsShapeQueryParameters", "get_collision_mask");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void PhysicsShapeQueryParameters::set_exclude(const Array exclude) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsShapeQueryParameters", "set_exclude");
	}
	___godot_icall_void_Array(mb, (const Object *) this, exclude);
}

Array PhysicsShapeQueryParameters::get_exclude() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsShapeQueryParameters", "get_exclude");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

}