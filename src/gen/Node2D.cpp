#include <Node2D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Object.hpp>


namespace godot {


void *Node2D::___get_type_tag()
{
	return (void *) &Node2D::___get_type_tag;
}

void *Node2D::___get_base_type_tag()
{
	return (void *) &CanvasItem::___get_type_tag;
}

Node2D *Node2D::_new()
{
	return (Node2D *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Node2D")());
}
void Node2D::set_position(const Vector2 position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node2D", "set_position");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, position);
}

void Node2D::set_rotation(const double radians) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node2D", "set_rotation");
	}
	___godot_icall_void_float(mb, (const Object *) this, radians);
}

void Node2D::set_rotation_degrees(const double degrees) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node2D", "set_rotation_degrees");
	}
	___godot_icall_void_float(mb, (const Object *) this, degrees);
}

void Node2D::set_scale(const Vector2 scale) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node2D", "set_scale");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, scale);
}

Vector2 Node2D::get_position() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node2D", "get_position");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

double Node2D::get_rotation() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node2D", "get_rotation");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

double Node2D::get_rotation_degrees() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node2D", "get_rotation_degrees");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

Vector2 Node2D::get_scale() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node2D", "get_scale");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void Node2D::rotate(const double radians) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node2D", "rotate");
	}
	___godot_icall_void_float(mb, (const Object *) this, radians);
}

void Node2D::move_local_x(const double delta, const bool scaled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node2D", "move_local_x");
	}
	___godot_icall_void_float_bool(mb, (const Object *) this, delta, scaled);
}

void Node2D::move_local_y(const double delta, const bool scaled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node2D", "move_local_y");
	}
	___godot_icall_void_float_bool(mb, (const Object *) this, delta, scaled);
}

void Node2D::translate(const Vector2 offset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node2D", "translate");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, offset);
}

void Node2D::global_translate(const Vector2 offset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node2D", "global_translate");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, offset);
}

void Node2D::apply_scale(const Vector2 ratio) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node2D", "apply_scale");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, ratio);
}

void Node2D::set_global_position(const Vector2 position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node2D", "set_global_position");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, position);
}

Vector2 Node2D::get_global_position() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node2D", "get_global_position");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void Node2D::set_global_rotation(const double radians) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node2D", "set_global_rotation");
	}
	___godot_icall_void_float(mb, (const Object *) this, radians);
}

double Node2D::get_global_rotation() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node2D", "get_global_rotation");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Node2D::set_global_rotation_degrees(const double degrees) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node2D", "set_global_rotation_degrees");
	}
	___godot_icall_void_float(mb, (const Object *) this, degrees);
}

double Node2D::get_global_rotation_degrees() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node2D", "get_global_rotation_degrees");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Node2D::set_global_scale(const Vector2 scale) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node2D", "set_global_scale");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, scale);
}

Vector2 Node2D::get_global_scale() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node2D", "get_global_scale");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void Node2D::set_transform(const Transform2D xform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node2D", "set_transform");
	}
	___godot_icall_void_Transform2D(mb, (const Object *) this, xform);
}

void Node2D::set_global_transform(const Transform2D xform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node2D", "set_global_transform");
	}
	___godot_icall_void_Transform2D(mb, (const Object *) this, xform);
}

void Node2D::look_at(const Vector2 point) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node2D", "look_at");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, point);
}

double Node2D::get_angle_to(const Vector2 point) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node2D", "get_angle_to");
	}
	return ___godot_icall_float_Vector2(mb, (const Object *) this, point);
}

Vector2 Node2D::to_local(const Vector2 global_point) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node2D", "to_local");
	}
	return ___godot_icall_Vector2_Vector2(mb, (const Object *) this, global_point);
}

Vector2 Node2D::to_global(const Vector2 local_point) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node2D", "to_global");
	}
	return ___godot_icall_Vector2_Vector2(mb, (const Object *) this, local_point);
}

void Node2D::set_z_index(const int64_t z_index) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node2D", "set_z_index");
	}
	___godot_icall_void_int(mb, (const Object *) this, z_index);
}

int64_t Node2D::get_z_index() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node2D", "get_z_index");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void Node2D::set_z_as_relative(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node2D", "set_z_as_relative");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool Node2D::is_z_relative() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node2D", "is_z_relative");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

Transform2D Node2D::get_relative_transform_to_parent(const Object *parent) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Node2D", "get_relative_transform_to_parent");
	}
	return ___godot_icall_Transform2D_Object(mb, (const Object *) this, parent);
}

}