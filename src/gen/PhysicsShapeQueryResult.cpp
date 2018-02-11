#include <PhysicsShapeQueryResult.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Object.hpp>


namespace godot {


void *PhysicsShapeQueryResult::___get_type_tag()
{
	return (void *) &PhysicsShapeQueryResult::___get_type_tag;
}

void *PhysicsShapeQueryResult::___get_base_type_tag()
{
	return (void *) &Reference::___get_type_tag;
}

int64_t PhysicsShapeQueryResult::get_result_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsShapeQueryResult", "get_result_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

RID PhysicsShapeQueryResult::get_result_rid(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsShapeQueryResult", "get_result_rid");
	}
	return ___godot_icall_RID_int(mb, (const Object *) this, idx);
}

int64_t PhysicsShapeQueryResult::get_result_object_id(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsShapeQueryResult", "get_result_object_id");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, idx);
}

Object *PhysicsShapeQueryResult::get_result_object(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsShapeQueryResult", "get_result_object");
	}
	return (Object *) ___godot_icall_Object_int(mb, (const Object *) this, idx);
}

int64_t PhysicsShapeQueryResult::get_result_object_shape(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsShapeQueryResult", "get_result_object_shape");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, idx);
}

}