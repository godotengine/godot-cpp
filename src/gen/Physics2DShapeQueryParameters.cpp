#include <Physics2DShapeQueryParameters.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Resource.hpp>


namespace godot {


void *Physics2DShapeQueryParameters::___get_type_tag()
{
	return (void *) &Physics2DShapeQueryParameters::___get_type_tag;
}

void *Physics2DShapeQueryParameters::___get_base_type_tag()
{
	return (void *) &Reference::___get_type_tag;
}

Physics2DShapeQueryParameters *Physics2DShapeQueryParameters::_new()
{
	return (Physics2DShapeQueryParameters *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Physics2DShapeQueryParameters")());
}
void Physics2DShapeQueryParameters::set_shape(const Ref<Resource> shape) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DShapeQueryParameters", "set_shape");
	}
	___godot_icall_void_Object(mb, (const Object *) this, shape.ptr());
}

void Physics2DShapeQueryParameters::set_shape_rid(const RID shape) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DShapeQueryParameters", "set_shape_rid");
	}
	___godot_icall_void_RID(mb, (const Object *) this, shape);
}

RID Physics2DShapeQueryParameters::get_shape_rid() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DShapeQueryParameters", "get_shape_rid");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

void Physics2DShapeQueryParameters::set_transform(const Transform2D transform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DShapeQueryParameters", "set_transform");
	}
	___godot_icall_void_Transform2D(mb, (const Object *) this, transform);
}

Transform2D Physics2DShapeQueryParameters::get_transform() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DShapeQueryParameters", "get_transform");
	}
	return ___godot_icall_Transform2D(mb, (const Object *) this);
}

void Physics2DShapeQueryParameters::set_motion(const Vector2 motion) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DShapeQueryParameters", "set_motion");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, motion);
}

Vector2 Physics2DShapeQueryParameters::get_motion() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DShapeQueryParameters", "get_motion");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void Physics2DShapeQueryParameters::set_margin(const double margin) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DShapeQueryParameters", "set_margin");
	}
	___godot_icall_void_float(mb, (const Object *) this, margin);
}

double Physics2DShapeQueryParameters::get_margin() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DShapeQueryParameters", "get_margin");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Physics2DShapeQueryParameters::set_collision_layer(const int64_t collision_layer) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DShapeQueryParameters", "set_collision_layer");
	}
	___godot_icall_void_int(mb, (const Object *) this, collision_layer);
}

int64_t Physics2DShapeQueryParameters::get_collision_layer() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DShapeQueryParameters", "get_collision_layer");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void Physics2DShapeQueryParameters::set_exclude(const Array exclude) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DShapeQueryParameters", "set_exclude");
	}
	___godot_icall_void_Array(mb, (const Object *) this, exclude);
}

Array Physics2DShapeQueryParameters::get_exclude() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DShapeQueryParameters", "get_exclude");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

}