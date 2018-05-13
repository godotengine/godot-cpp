#ifndef GODOT_CPP_PHYSICS2DSHAPEQUERYPARAMETERS_HPP
#define GODOT_CPP_PHYSICS2DSHAPEQUERYPARAMETERS_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Reference.hpp"
namespace godot {

class Resource;

class Physics2DShapeQueryParameters : public Reference {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Physics2DShapeQueryParameters"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static Physics2DShapeQueryParameters *_new();

	// methods
	void set_shape(const Ref<Resource> shape);
	void set_shape_rid(const RID shape);
	RID get_shape_rid() const;
	void set_transform(const Transform2D transform);
	Transform2D get_transform() const;
	void set_motion(const Vector2 motion);
	Vector2 get_motion() const;
	void set_margin(const double margin);
	double get_margin() const;
	void set_collision_layer(const int64_t collision_layer);
	int64_t get_collision_layer() const;
	void set_exclude(const Array exclude);
	Array get_exclude() const;

};

}

#endif