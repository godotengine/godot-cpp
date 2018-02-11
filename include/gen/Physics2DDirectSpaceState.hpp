#ifndef GODOT_CPP_PHYSICS2DDIRECTSPACESTATE_HPP
#define GODOT_CPP_PHYSICS2DDIRECTSPACESTATE_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Object.hpp>
namespace godot {

class Physics2DShapeQueryParameters;

class Physics2DDirectSpaceState : public Object {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Physics2DDirectSpaceState"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants

	// methods
	Array intersect_point(const Vector2 point, const int64_t max_results = 32, const Array exclude = Array(), const int64_t collision_layer = 2147483647);
	Dictionary intersect_ray(const Vector2 from, const Vector2 to, const Array exclude = Array(), const int64_t collision_layer = 2147483647);
	Array intersect_shape(const Ref<Physics2DShapeQueryParameters> shape, const int64_t max_results = 32);
	Array cast_motion(const Ref<Physics2DShapeQueryParameters> shape);
	Array collide_shape(const Ref<Physics2DShapeQueryParameters> shape, const int64_t max_results = 32);
	Dictionary get_rest_info(const Ref<Physics2DShapeQueryParameters> shape);

};

}

#endif