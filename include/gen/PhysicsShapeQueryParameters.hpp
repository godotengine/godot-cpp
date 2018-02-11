#ifndef GODOT_CPP_PHYSICSSHAPEQUERYPARAMETERS_HPP
#define GODOT_CPP_PHYSICSSHAPEQUERYPARAMETERS_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Reference.hpp>
namespace godot {

class Resource;

class PhysicsShapeQueryParameters : public Reference {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "PhysicsShapeQueryParameters"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static PhysicsShapeQueryParameters *_new();

	// methods
	void set_shape(const Ref<Resource> shape);
	void set_shape_rid(const RID shape);
	RID get_shape_rid() const;
	void set_transform(const Transform transform);
	Transform get_transform() const;
	void set_margin(const double margin);
	double get_margin() const;
	void set_collision_mask(const int64_t collision_mask);
	int64_t get_collision_mask() const;
	void set_exclude(const Array exclude);
	Array get_exclude() const;

};

}

#endif