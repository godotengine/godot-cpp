#include <Shape2D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Shape2D.hpp>


namespace godot {


void *Shape2D::___get_type_tag()
{
	return (void *) &Shape2D::___get_type_tag;
}

void *Shape2D::___get_base_type_tag()
{
	return (void *) &Resource::___get_type_tag;
}

void Shape2D::set_custom_solver_bias(const double bias) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Shape2D", "set_custom_solver_bias");
	}
	___godot_icall_void_float(mb, (const Object *) this, bias);
}

double Shape2D::get_custom_solver_bias() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Shape2D", "get_custom_solver_bias");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

bool Shape2D::collide(const Transform2D local_xform, const Ref<Shape2D> with_shape, const Transform2D shape_xform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Shape2D", "collide");
	}
	return ___godot_icall_bool_Transform2D_Object_Transform2D(mb, (const Object *) this, local_xform, with_shape.ptr(), shape_xform);
}

bool Shape2D::collide_with_motion(const Transform2D local_xform, const Vector2 local_motion, const Ref<Shape2D> with_shape, const Transform2D shape_xform, const Vector2 shape_motion) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Shape2D", "collide_with_motion");
	}
	return ___godot_icall_bool_Transform2D_Vector2_Object_Transform2D_Vector2(mb, (const Object *) this, local_xform, local_motion, with_shape.ptr(), shape_xform, shape_motion);
}

Variant Shape2D::collide_and_get_contacts(const Transform2D local_xform, const Ref<Shape2D> with_shape, const Transform2D shape_xform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Shape2D", "collide_and_get_contacts");
	}
	return ___godot_icall_Variant_Transform2D_Object_Transform2D(mb, (const Object *) this, local_xform, with_shape.ptr(), shape_xform);
}

Variant Shape2D::collide_with_motion_and_get_contacts(const Transform2D local_xform, const Vector2 local_motion, const Ref<Shape2D> with_shape, const Transform2D shape_xform, const Vector2 shape_motion) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Shape2D", "collide_with_motion_and_get_contacts");
	}
	return ___godot_icall_Variant_Transform2D_Vector2_Object_Transform2D_Vector2(mb, (const Object *) this, local_xform, local_motion, with_shape.ptr(), shape_xform, shape_motion);
}

}