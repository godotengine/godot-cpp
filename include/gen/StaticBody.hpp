#ifndef GODOT_CPP_STATICBODY_HPP
#define GODOT_CPP_STATICBODY_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <PhysicsBody.hpp>
namespace godot {


class StaticBody : public PhysicsBody {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "StaticBody"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static StaticBody *_new();

	// methods
	void set_constant_linear_velocity(const Vector3 vel);
	void set_constant_angular_velocity(const Vector3 vel);
	Vector3 get_constant_linear_velocity() const;
	Vector3 get_constant_angular_velocity() const;
	void set_friction(const double friction);
	double get_friction() const;
	void set_bounce(const double bounce);
	double get_bounce() const;

};

}

#endif