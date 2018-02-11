#include <Spatial.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Spatial.hpp>
#include <World.hpp>
#include <SpatialGizmo.hpp>


namespace godot {


void *Spatial::___get_type_tag()
{
	return (void *) &Spatial::___get_type_tag;
}

void *Spatial::___get_base_type_tag()
{
	return (void *) &Node::___get_type_tag;
}

Spatial *Spatial::_new()
{
	return (Spatial *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Spatial")());
}
void Spatial::set_transform(const Transform local) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "set_transform");
	}
	___godot_icall_void_Transform(mb, (const Object *) this, local);
}

Transform Spatial::get_transform() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "get_transform");
	}
	return ___godot_icall_Transform(mb, (const Object *) this);
}

void Spatial::set_translation(const Vector3 translation) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "set_translation");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, translation);
}

Vector3 Spatial::get_translation() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "get_translation");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

void Spatial::set_rotation(const Vector3 euler) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "set_rotation");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, euler);
}

Vector3 Spatial::get_rotation() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "get_rotation");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

void Spatial::set_rotation_degrees(const Vector3 euler_degrees) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "set_rotation_degrees");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, euler_degrees);
}

Vector3 Spatial::get_rotation_degrees() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "get_rotation_degrees");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

void Spatial::set_scale(const Vector3 scale) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "set_scale");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, scale);
}

Vector3 Spatial::get_scale() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "get_scale");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

void Spatial::set_global_transform(const Transform global) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "set_global_transform");
	}
	___godot_icall_void_Transform(mb, (const Object *) this, global);
}

Transform Spatial::get_global_transform() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "get_global_transform");
	}
	return ___godot_icall_Transform(mb, (const Object *) this);
}

Spatial *Spatial::get_parent_spatial() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "get_parent_spatial");
	}
	return (Spatial *) ___godot_icall_Object(mb, (const Object *) this);
}

void Spatial::set_ignore_transform_notification(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "set_ignore_transform_notification");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

void Spatial::set_as_toplevel(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "set_as_toplevel");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool Spatial::is_set_as_toplevel() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "is_set_as_toplevel");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

Ref<World> Spatial::get_world() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "get_world");
	}
	return Ref<World>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void Spatial::_update_gizmo() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "_update_gizmo");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Spatial::update_gizmo() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "update_gizmo");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Spatial::set_gizmo(const Ref<SpatialGizmo> gizmo) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "set_gizmo");
	}
	___godot_icall_void_Object(mb, (const Object *) this, gizmo.ptr());
}

Ref<SpatialGizmo> Spatial::get_gizmo() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "get_gizmo");
	}
	return Ref<SpatialGizmo>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void Spatial::set_visible(const bool visible) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "set_visible");
	}
	___godot_icall_void_bool(mb, (const Object *) this, visible);
}

bool Spatial::is_visible() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "is_visible");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

bool Spatial::is_visible_in_tree() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "is_visible_in_tree");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Spatial::show() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "show");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Spatial::hide() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "hide");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Spatial::set_notify_local_transform(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "set_notify_local_transform");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool Spatial::is_local_transform_notification_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "is_local_transform_notification_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Spatial::set_notify_transform(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "set_notify_transform");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool Spatial::is_transform_notification_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "is_transform_notification_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Spatial::rotate(const Vector3 axis, const double angle) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "rotate");
	}
	___godot_icall_void_Vector3_float(mb, (const Object *) this, axis, angle);
}

void Spatial::global_rotate(const Vector3 axis, const double angle) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "global_rotate");
	}
	___godot_icall_void_Vector3_float(mb, (const Object *) this, axis, angle);
}

void Spatial::global_scale(const Vector3 scale) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "global_scale");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, scale);
}

void Spatial::global_translate(const Vector3 offset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "global_translate");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, offset);
}

void Spatial::rotate_object_local(const Vector3 axis, const double angle) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "rotate_object_local");
	}
	___godot_icall_void_Vector3_float(mb, (const Object *) this, axis, angle);
}

void Spatial::scale_object_local(const Vector3 scale) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "scale_object_local");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, scale);
}

void Spatial::translate_object_local(const Vector3 offset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "translate_object_local");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, offset);
}

void Spatial::rotate_x(const double angle) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "rotate_x");
	}
	___godot_icall_void_float(mb, (const Object *) this, angle);
}

void Spatial::rotate_y(const double angle) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "rotate_y");
	}
	___godot_icall_void_float(mb, (const Object *) this, angle);
}

void Spatial::rotate_z(const double angle) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "rotate_z");
	}
	___godot_icall_void_float(mb, (const Object *) this, angle);
}

void Spatial::translate(const Vector3 offset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "translate");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, offset);
}

void Spatial::orthonormalize() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "orthonormalize");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Spatial::set_identity() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "set_identity");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Spatial::look_at(const Vector3 target, const Vector3 up) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "look_at");
	}
	___godot_icall_void_Vector3_Vector3(mb, (const Object *) this, target, up);
}

void Spatial::look_at_from_position(const Vector3 position, const Vector3 target, const Vector3 up) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "look_at_from_position");
	}
	___godot_icall_void_Vector3_Vector3_Vector3(mb, (const Object *) this, position, target, up);
}

Vector3 Spatial::to_local(const Vector3 global_point) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "to_local");
	}
	return ___godot_icall_Vector3_Vector3(mb, (const Object *) this, global_point);
}

Vector3 Spatial::to_global(const Vector3 local_point) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Spatial", "to_global");
	}
	return ___godot_icall_Vector3_Vector3(mb, (const Object *) this, local_point);
}

}