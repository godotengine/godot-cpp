#include <Physics2DShapeQueryResult.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Object.hpp>


namespace godot {


void *Physics2DShapeQueryResult::___get_type_tag()
{
	return (void *) &Physics2DShapeQueryResult::___get_type_tag;
}

void *Physics2DShapeQueryResult::___get_base_type_tag()
{
	return (void *) &Reference::___get_type_tag;
}

int64_t Physics2DShapeQueryResult::get_result_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DShapeQueryResult", "get_result_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

RID Physics2DShapeQueryResult::get_result_rid(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DShapeQueryResult", "get_result_rid");
	}
	return ___godot_icall_RID_int(mb, (const Object *) this, idx);
}

int64_t Physics2DShapeQueryResult::get_result_object_id(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DShapeQueryResult", "get_result_object_id");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, idx);
}

Object *Physics2DShapeQueryResult::get_result_object(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DShapeQueryResult", "get_result_object");
	}
	return (Object *) ___godot_icall_Object_int(mb, (const Object *) this, idx);
}

int64_t Physics2DShapeQueryResult::get_result_object_shape(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DShapeQueryResult", "get_result_object_shape");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, idx);
}

}