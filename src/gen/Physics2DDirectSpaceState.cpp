#include <Physics2DDirectSpaceState.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Physics2DShapeQueryParameters.hpp>


namespace godot {


void *Physics2DDirectSpaceState::___get_type_tag()
{
	return (void *) &Physics2DDirectSpaceState::___get_type_tag;
}

void *Physics2DDirectSpaceState::___get_base_type_tag()
{
	return (void *) &Object::___get_type_tag;
}

Array Physics2DDirectSpaceState::intersect_point(const Vector2 point, const int64_t max_results, const Array exclude, const int64_t collision_layer) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DDirectSpaceState", "intersect_point");
	}
	return ___godot_icall_Array_Vector2_int_Array_int(mb, (const Object *) this, point, max_results, exclude, collision_layer);
}

Dictionary Physics2DDirectSpaceState::intersect_ray(const Vector2 from, const Vector2 to, const Array exclude, const int64_t collision_layer) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DDirectSpaceState", "intersect_ray");
	}
	return ___godot_icall_Dictionary_Vector2_Vector2_Array_int(mb, (const Object *) this, from, to, exclude, collision_layer);
}

Array Physics2DDirectSpaceState::intersect_shape(const Ref<Physics2DShapeQueryParameters> shape, const int64_t max_results) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DDirectSpaceState", "intersect_shape");
	}
	return ___godot_icall_Array_Object_int(mb, (const Object *) this, shape.ptr(), max_results);
}

Array Physics2DDirectSpaceState::cast_motion(const Ref<Physics2DShapeQueryParameters> shape) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DDirectSpaceState", "cast_motion");
	}
	return ___godot_icall_Array_Object(mb, (const Object *) this, shape.ptr());
}

Array Physics2DDirectSpaceState::collide_shape(const Ref<Physics2DShapeQueryParameters> shape, const int64_t max_results) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DDirectSpaceState", "collide_shape");
	}
	return ___godot_icall_Array_Object_int(mb, (const Object *) this, shape.ptr(), max_results);
}

Dictionary Physics2DDirectSpaceState::get_rest_info(const Ref<Physics2DShapeQueryParameters> shape) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DDirectSpaceState", "get_rest_info");
	}
	return ___godot_icall_Dictionary_Object(mb, (const Object *) this, shape.ptr());
}

}