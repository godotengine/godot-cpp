#include <KinematicCollision.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Object.hpp>


namespace godot {


void *KinematicCollision::___get_type_tag()
{
	return (void *) &KinematicCollision::___get_type_tag;
}

void *KinematicCollision::___get_base_type_tag()
{
	return (void *) &Reference::___get_type_tag;
}

KinematicCollision *KinematicCollision::_new()
{
	return (KinematicCollision *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"KinematicCollision")());
}
Vector3 KinematicCollision::get_position() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("KinematicCollision", "get_position");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

Vector3 KinematicCollision::get_normal() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("KinematicCollision", "get_normal");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

Vector3 KinematicCollision::get_travel() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("KinematicCollision", "get_travel");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

Vector3 KinematicCollision::get_remainder() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("KinematicCollision", "get_remainder");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

Object *KinematicCollision::get_local_shape() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("KinematicCollision", "get_local_shape");
	}
	return (Object *) ___godot_icall_Object(mb, (const Object *) this);
}

Object *KinematicCollision::get_collider() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("KinematicCollision", "get_collider");
	}
	return (Object *) ___godot_icall_Object(mb, (const Object *) this);
}

int64_t KinematicCollision::get_collider_id() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("KinematicCollision", "get_collider_id");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

Object *KinematicCollision::get_collider_shape() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("KinematicCollision", "get_collider_shape");
	}
	return (Object *) ___godot_icall_Object(mb, (const Object *) this);
}

int64_t KinematicCollision::get_collider_shape_index() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("KinematicCollision", "get_collider_shape_index");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

Vector3 KinematicCollision::get_collider_velocity() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("KinematicCollision", "get_collider_velocity");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

Variant KinematicCollision::get_collider_metadata() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("KinematicCollision", "get_collider_metadata");
	}
	return ___godot_icall_Variant(mb, (const Object *) this);
}

}