#include "__icalls.hpp"

#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <Object.hpp>


namespace godot {

void ___godot_icall_void_RID_RID_RID_RID_int_int(godot_method_bind *mb, const Object *inst, const RID& arg0, const RID& arg1, const RID& arg2, const RID& arg3, const int arg4, const int arg5) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
		(void *) &arg5,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_int_int_Object(godot_method_bind *mb, const Object *inst, const int arg0, const int arg1, const Object *arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) arg2->_owner,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_RID(godot_method_bind *mb, const Object *inst, const RID& arg0) {
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_RID_RID_int(godot_method_bind *mb, const Object *inst, const RID& arg0, const RID& arg1, const int arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_int_int_Transform2D(godot_method_bind *mb, const Object *inst, const int arg0, const int arg1, const Transform2D& arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
bool ___godot_icall_bool_Transform2D_Object_Transform2D(godot_method_bind *mb, const Object *inst, const Transform2D& arg0, const Object *arg1, const Transform2D& arg2) {
	bool ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) arg1->_owner,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_RID_Vector3_Vector3(godot_method_bind *mb, const Object *inst, const RID& arg0, const Vector3& arg1, const Vector3& arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_int_int_int_bool_bool_bool_Vector2(godot_method_bind *mb, const Object *inst, const int arg0, const int arg1, const int arg2, const bool arg3, const bool arg4, const bool arg5, const Vector2& arg6) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
		(void *) &arg5,
		(void *) &arg6,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Object *___godot_icall_Object_float(godot_method_bind *mb, const Object *inst, const double arg0) {
	godot_object *ret;
	ret = nullptr;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, ret);
}
int64_t ___godot_icall_int_Vector2(godot_method_bind *mb, const Object *inst, const Vector2& arg0) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
bool ___godot_icall_bool_RID_Transform2D_Vector2_bool_float_Object(godot_method_bind *mb, const Object *inst, const RID& arg0, const Transform2D& arg1, const Vector2& arg2, const bool arg3, const double arg4, const Object *arg5) {
	bool ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
		(void *) arg5->_owner,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
PoolRealArray ___godot_icall_PoolRealArray(godot_method_bind *mb, const Object *inst) {
	PoolRealArray ret;
	const void *args[1] = {
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_float_Color(godot_method_bind *mb, const Object *inst, const double arg0, const Color& arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Dictionary ___godot_icall_Dictionary_String(godot_method_bind *mb, const Object *inst, const String& arg0) {
	Dictionary ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_Object_String_Variant(godot_method_bind *mb, const Object *inst, const Object *arg0, const String& arg1, const Variant& arg2) {
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_String_String_Object_Object(godot_method_bind *mb, const Object *inst, const String& arg0, const String& arg1, const Object *arg2, const Object *arg3) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) arg2->_owner,
		(void *) arg3->_owner,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
NodePath ___godot_icall_NodePath(godot_method_bind *mb, const Object *inst) {
	NodePath ret;
	const void *args[1] = {
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_Object_Vector2_Color_Object(godot_method_bind *mb, const Object *inst, const Object *arg0, const Vector2& arg1, const Color& arg2, const Object *arg3) {
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
		(void *) &arg2,
		(void *) arg3->_owner,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Array ___godot_icall_Array_int_int(godot_method_bind *mb, const Object *inst, const int arg0, const int arg1) {
	Array ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Object *___godot_icall_Object_String_bool_String(godot_method_bind *mb, const Object *inst, const String& arg0, const bool arg1, const String& arg2) {
	godot_object *ret;
	ret = nullptr;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, ret);
}
void ___godot_icall_void_RID_Vector2_Vector2(godot_method_bind *mb, const Object *inst, const RID& arg0, const Vector2& arg1, const Vector2& arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_RID_bool_float_float_float_RID(godot_method_bind *mb, const Object *inst, const RID& arg0, const bool arg1, const double arg2, const double arg3, const double arg4, const RID& arg5) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
		(void *) &arg5,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_Object_int_bool(godot_method_bind *mb, const Object *inst, const Object *arg0, const int arg1, const bool arg2) {
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
PoolVector2Array ___godot_icall_PoolVector2Array_PoolVector2Array(godot_method_bind *mb, const Object *inst, const PoolVector2Array& arg0) {
	PoolVector2Array ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Array ___godot_icall_Array_AABB_RID(godot_method_bind *mb, const Object *inst, const AABB& arg0, const RID& arg1) {
	Array ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Array ___godot_icall_Array_Array_int(godot_method_bind *mb, const Object *inst, const Array& arg0, const int arg1) {
	Array ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_int_int_float(godot_method_bind *mb, const Object *inst, const int arg0, const int arg1, const double arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
int64_t ___godot_icall_int_Dictionary(godot_method_bind *mb, const Object *inst, const Dictionary& arg0) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_Dictionary(godot_method_bind *mb, const Object *inst, const Dictionary& arg0) {
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Array ___godot_icall_Array_RID_int(godot_method_bind *mb, const Object *inst, const RID& arg0, const int arg1) {
	Array ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
bool ___godot_icall_bool_String_String_bool(godot_method_bind *mb, const Object *inst, const String& arg0, const String& arg1, const bool arg2) {
	bool ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_int_RID_int_int_int(godot_method_bind *mb, const Object *inst, const int arg0, const RID& arg1, const int arg2, const int arg3, const int arg4) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
RID ___godot_icall_RID_Vector2_RID_RID(godot_method_bind *mb, const Object *inst, const Vector2& arg0, const RID& arg1, const RID& arg2) {
	RID ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_String_Color(godot_method_bind *mb, const Object *inst, const String& arg0, const Color& arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
double ___godot_icall_float_RID_Vector2_int_int_Color(godot_method_bind *mb, const Object *inst, const RID& arg0, const Vector2& arg1, const int arg2, const int arg3, const Color& arg4) {
	double ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
RID ___godot_icall_RID_int(godot_method_bind *mb, const Object *inst, const int arg0) {
	RID ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Vector2 ___godot_icall_Vector2_float_bool(godot_method_bind *mb, const Object *inst, const double arg0, const bool arg1) {
	Vector2 ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_String_Object_String_Variant(godot_method_bind *mb, const Object *inst, const String& arg0, const Object *arg1, const String& arg2, const Variant& arg3) {
	const void *args[] = {
		(void *) &arg0,
		(void *) arg1->_owner,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
double ___godot_icall_float_String(godot_method_bind *mb, const Object *inst, const String& arg0) {
	double ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_RID_Transform2D(godot_method_bind *mb, const Object *inst, const RID& arg0, const Transform2D& arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_int_float_Variant_float(godot_method_bind *mb, const Object *inst, const int arg0, const double arg1, const Variant& arg2, const double arg3) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_RID_int(godot_method_bind *mb, const Object *inst, const RID& arg0, const int arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
RID ___godot_icall_RID_Vector2_Vector2_Vector2_RID_RID(godot_method_bind *mb, const Object *inst, const Vector2& arg0, const Vector2& arg1, const Vector2& arg2, const RID& arg3, const RID& arg4) {
	RID ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_bool_Vector2_Vector2(godot_method_bind *mb, const Object *inst, const bool arg0, const Vector2& arg1, const Vector2& arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_RID_int_float_float_bool_float_float_float_float(godot_method_bind *mb, const Object *inst, const RID& arg0, const int arg1, const double arg2, const double arg3, const bool arg4, const double arg5, const double arg6, const double arg7, const double arg8) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
		(void *) &arg5,
		(void *) &arg6,
		(void *) &arg7,
		(void *) &arg8,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Object *___godot_icall_Object_Vector3_bool(godot_method_bind *mb, const Object *inst, const Vector3& arg0, const bool arg1) {
	godot_object *ret;
	ret = nullptr;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, ret);
}
void ___godot_icall_void_RID_Vector2(godot_method_bind *mb, const Object *inst, const RID& arg0, const Vector2& arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
bool ___godot_icall_bool_String_int_String_int(godot_method_bind *mb, const Object *inst, const String& arg0, const int arg1, const String& arg2, const int arg3) {
	bool ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_int_Object_bool(godot_method_bind *mb, const Object *inst, const int arg0, const Object *arg1, const bool arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) arg1->_owner,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_int_String_String_Variant(godot_method_bind *mb, const Object *inst, const int arg0, const String& arg1, const String& arg2, const Variant& arg3) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_Vector3_Vector3(godot_method_bind *mb, const Object *inst, const Vector3& arg0, const Vector3& arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
RID ___godot_icall_RID_RID_Transform_RID_Transform(godot_method_bind *mb, const Object *inst, const RID& arg0, const Transform& arg1, const RID& arg2, const Transform& arg3) {
	RID ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_PoolStringArray_bool_String_int(godot_method_bind *mb, const Object *inst, const PoolStringArray& arg0, const bool arg1, const String& arg2, const int arg3) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_RID_String_RID(godot_method_bind *mb, const Object *inst, const RID& arg0, const String& arg1, const RID& arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
int64_t ___godot_icall_int_Vector3(godot_method_bind *mb, const Object *inst, const Vector3& arg0) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_Object_int_Vector2(godot_method_bind *mb, const Object *inst, const Object *arg0, const int arg1, const Vector2& arg2) {
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
PoolVector3Array ___godot_icall_PoolVector3Array_PoolVector3Array_Plane(godot_method_bind *mb, const Object *inst, const PoolVector3Array& arg0, const Plane& arg1) {
	PoolVector3Array ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_RID_Transform(godot_method_bind *mb, const Object *inst, const RID& arg0, const Transform& arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_RID_Vector2_float_Color(godot_method_bind *mb, const Object *inst, const RID& arg0, const Vector2& arg1, const double arg2, const Color& arg3) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Variant ___godot_icall_Variant_Variant(godot_method_bind *mb, const Object *inst, const Variant& arg0) {
	Variant ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_Object_int_Transform(godot_method_bind *mb, const Object *inst, const Object *arg0, const int arg1, const Transform& arg2) {
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Vector2 ___godot_icall_Vector2_float(godot_method_bind *mb, const Object *inst, const double arg0) {
	Vector2 ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_RID_int_int_int(godot_method_bind *mb, const Object *inst, const RID& arg0, const int arg1, const int arg2, const int arg3) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_String_Dictionary(godot_method_bind *mb, const Object *inst, const String& arg0, const Dictionary& arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_String_float(godot_method_bind *mb, const Object *inst, const String& arg0, const double arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_float_float_float_float(godot_method_bind *mb, const Object *inst, const double arg0, const double arg1, const double arg2, const double arg3) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
PoolVector3Array ___godot_icall_PoolVector3Array_int_float(godot_method_bind *mb, const Object *inst, const int arg0, const double arg1) {
	PoolVector3Array ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_int_Array(godot_method_bind *mb, const Object *inst, const int arg0, const Array& arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_RID_Vector2_Vector2_Color_float_bool(godot_method_bind *mb, const Object *inst, const RID& arg0, const Vector2& arg1, const Vector2& arg2, const Color& arg3, const double arg4, const bool arg5) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
		(void *) &arg5,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
int64_t ___godot_icall_int_Vector2_float_float_int_int(godot_method_bind *mb, const Object *inst, const Vector2& arg0, const double arg1, const double arg2, const int arg3, const int arg4) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_Vector2_int_bool_bool_bool(godot_method_bind *mb, const Object *inst, const Vector2& arg0, const int arg1, const bool arg2, const bool arg3, const bool arg4) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_RID_bool_float_float_float(godot_method_bind *mb, const Object *inst, const RID& arg0, const bool arg1, const double arg2, const double arg3, const double arg4) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
RID ___godot_icall_RID_Object_int(godot_method_bind *mb, const Object *inst, const Object *arg0, const int arg1) {
	RID ret;
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_Object_Vector2_String_Color_int(godot_method_bind *mb, const Object *inst, const Object *arg0, const Vector2& arg1, const String& arg2, const Color& arg3, const int arg4) {
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_int_int_int(godot_method_bind *mb, const Object *inst, const int arg0, const int arg1, const int arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_RID_int_Array_Array_int(godot_method_bind *mb, const Object *inst, const RID& arg0, const int arg1, const Array& arg2, const Array& arg3, const int arg4) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_int_float_float_float_bool(godot_method_bind *mb, const Object *inst, const int arg0, const double arg1, const double arg2, const double arg3, const bool arg4) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Vector3 ___godot_icall_Vector3_Vector3_Vector3_Vector3(godot_method_bind *mb, const Object *inst, const Vector3& arg0, const Vector3& arg1, const Vector3& arg2) {
	Vector3 ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_Object_String_bool(godot_method_bind *mb, const Object *inst, const Object *arg0, const String& arg1, const bool arg2) {
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
AABB ___godot_icall_AABB_RID_int(godot_method_bind *mb, const Object *inst, const RID& arg0, const int arg1) {
	AABB ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
int64_t ___godot_icall_int_Transform_float(godot_method_bind *mb, const Object *inst, const Transform& arg0, const double arg1) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_RID_String(godot_method_bind *mb, const Object *inst, const RID& arg0, const String& arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_PoolVector2Array_PoolColorArray_float_bool(godot_method_bind *mb, const Object *inst, const PoolVector2Array& arg0, const PoolColorArray& arg1, const double arg2, const bool arg3) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Object *___godot_icall_Object_float_bool(godot_method_bind *mb, const Object *inst, const double arg0, const bool arg1) {
	godot_object *ret;
	ret = nullptr;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, ret);
}
Color ___godot_icall_Color_String(godot_method_bind *mb, const Object *inst, const String& arg0) {
	Color ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
bool ___godot_icall_bool_Object_NodePath_Object_NodePath_Variant_float_int_int_float(godot_method_bind *mb, const Object *inst, const Object *arg0, const NodePath& arg1, const Object *arg2, const NodePath& arg3, const Variant& arg4, const double arg5, const int arg6, const int arg7, const double arg8) {
	bool ret;
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
		(void *) arg2->_owner,
		(void *) &arg3,
		(void *) &arg4,
		(void *) &arg5,
		(void *) &arg6,
		(void *) &arg7,
		(void *) &arg8,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
String ___godot_icall_String_String_String_bool_int_int(godot_method_bind *mb, const Object *inst, const String& arg0, const String& arg1, const bool arg2, const int arg3, const int arg4) {
	String ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
String ___godot_icall_String_Variant(godot_method_bind *mb, const Object *inst, const Variant& arg0) {
	String ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_int_PoolIntArray(godot_method_bind *mb, const Object *inst, const int arg0, const PoolIntArray& arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
double ___godot_icall_float_RID_int(godot_method_bind *mb, const Object *inst, const RID& arg0, const int arg1) {
	double ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_String_Array_bool(godot_method_bind *mb, const Object *inst, const String& arg0, const Array& arg1, const bool arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
String ___godot_icall_String_Vector2(godot_method_bind *mb, const Object *inst, const Vector2& arg0) {
	String ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
bool ___godot_icall_bool_Transform2D_Vector2_bool(godot_method_bind *mb, const Object *inst, const Transform2D& arg0, const Vector2& arg1, const bool arg2) {
	bool ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Dictionary ___godot_icall_Dictionary_PoolVector2Array(godot_method_bind *mb, const Object *inst, const PoolVector2Array& arg0) {
	Dictionary ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_float(godot_method_bind *mb, const Object *inst, const double arg0) {
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
int64_t ___godot_icall_int_int_String(godot_method_bind *mb, const Object *inst, const int arg0, const String& arg1) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_int_int_bool(godot_method_bind *mb, const Object *inst, const int arg0, const int arg1, const bool arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_Variant_Object(godot_method_bind *mb, const Object *inst, const Variant& arg0, const Object *arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) arg1->_owner,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Transform2D ___godot_icall_Transform2D(godot_method_bind *mb, const Object *inst) {
	Transform2D ret;
	const void *args[1] = {
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_int_Color(godot_method_bind *mb, const Object *inst, const int arg0, const Color& arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_Object_Object_bool(godot_method_bind *mb, const Object *inst, const Object *arg0, const Object *arg1, const bool arg2) {
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) arg1->_owner,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
int64_t ___godot_icall_int_Object(godot_method_bind *mb, const Object *inst, const Object *arg0) {
	int64_t ret;
	const void *args[] = {
		(void *) arg0->_owner,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Transform ___godot_icall_Transform_RID_int(godot_method_bind *mb, const Object *inst, const RID& arg0, const int arg1) {
	Transform ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
PoolByteArray ___godot_icall_PoolByteArray_RID_int(godot_method_bind *mb, const Object *inst, const RID& arg0, const int arg1) {
	PoolByteArray ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
int64_t ___godot_icall_int_String_Object(godot_method_bind *mb, const Object *inst, const String& arg0, const Object *arg1) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) arg1->_owner,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
int64_t ___godot_icall_int_String_String_int(godot_method_bind *mb, const Object *inst, const String& arg0, const String& arg1, const int arg2) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Array ___godot_icall_Array_NodePath(godot_method_bind *mb, const Object *inst, const NodePath& arg0) {
	Array ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_PoolVector2Array_PoolIntArray(godot_method_bind *mb, const Object *inst, const PoolVector2Array& arg0, const PoolIntArray& arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_Object_int(godot_method_bind *mb, const Object *inst, const Object *arg0, const int arg1) {
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Vector3 ___godot_icall_Vector3_int_float(godot_method_bind *mb, const Object *inst, const int arg0, const double arg1) {
	Vector3 ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
bool ___godot_icall_bool_Object_NodePath_Variant_Variant_float_int_int_float(godot_method_bind *mb, const Object *inst, const Object *arg0, const NodePath& arg1, const Variant& arg2, const Variant& arg3, const double arg4, const int arg5, const int arg6, const double arg7) {
	bool ret;
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
		(void *) &arg5,
		(void *) &arg6,
		(void *) &arg7,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_String_int_String_int(godot_method_bind *mb, const Object *inst, const String& arg0, const int arg1, const String& arg2, const int arg3) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Variant ___godot_icall_Variant_NodePath(godot_method_bind *mb, const Object *inst, const NodePath& arg0) {
	Variant ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
PoolIntArray ___godot_icall_PoolIntArray_PoolVector2Array(godot_method_bind *mb, const Object *inst, const PoolVector2Array& arg0) {
	PoolIntArray ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_RID_int_int_float(godot_method_bind *mb, const Object *inst, const RID& arg0, const int arg1, const int arg2, const double arg3) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Vector3 ___godot_icall_Vector3_float(godot_method_bind *mb, const Object *inst, const double arg0) {
	Vector3 ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
RID ___godot_icall_RID(godot_method_bind *mb, const Object *inst) {
	RID ret;
	const void *args[1] = {
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_String_int(godot_method_bind *mb, const Object *inst, const String& arg0, const int arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_int(godot_method_bind *mb, const Object *inst, const int arg0) {
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_int_Transform(godot_method_bind *mb, const Object *inst, const int arg0, const Transform& arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Object *___godot_icall_Object_Object_int(godot_method_bind *mb, const Object *inst, const Object *arg0, const int arg1) {
	godot_object *ret;
	ret = nullptr;
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, ret);
}
bool ___godot_icall_bool_Object_String_Variant_Object_String_float_int_int_float(godot_method_bind *mb, const Object *inst, const Object *arg0, const String& arg1, const Variant& arg2, const Object *arg3, const String& arg4, const double arg5, const int arg6, const int arg7, const double arg8) {
	bool ret;
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
		(void *) &arg2,
		(void *) arg3->_owner,
		(void *) &arg4,
		(void *) &arg5,
		(void *) &arg6,
		(void *) &arg7,
		(void *) &arg8,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_RID_PoolVector2Array_bool(godot_method_bind *mb, const Object *inst, const RID& arg0, const PoolVector2Array& arg1, const bool arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
String ___godot_icall_String(godot_method_bind *mb, const Object *inst) {
	String ret;
	const void *args[1] = {
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Array ___godot_icall_Array_Object_int(godot_method_bind *mb, const Object *inst, const Object *arg0, const int arg1) {
	Array ret;
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_int_int_Color(godot_method_bind *mb, const Object *inst, const int arg0, const int arg1, const Color& arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_RID_PoolIntArray_PoolVector2Array_PoolColorArray_PoolVector2Array_RID_int_RID(godot_method_bind *mb, const Object *inst, const RID& arg0, const PoolIntArray& arg1, const PoolVector2Array& arg2, const PoolColorArray& arg3, const PoolVector2Array& arg4, const RID& arg5, const int arg6, const RID& arg7) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
		(void *) &arg5,
		(void *) &arg6,
		(void *) &arg7,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_RID_Object_String_Variant(godot_method_bind *mb, const Object *inst, const RID& arg0, const Object *arg1, const String& arg2, const Variant& arg3) {
	const void *args[] = {
		(void *) &arg0,
		(void *) arg1->_owner,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_RID_RID_RID_RID(godot_method_bind *mb, const Object *inst, const RID& arg0, const RID& arg1, const RID& arg2, const RID& arg3) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_RID_Vector2_String_Color_int(godot_method_bind *mb, const Object *inst, const RID& arg0, const Vector2& arg1, const String& arg2, const Color& arg3, const int arg4) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_int_bool_int(godot_method_bind *mb, const Object *inst, const int arg0, const bool arg1, const int arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_RID_Rect2_int(godot_method_bind *mb, const Object *inst, const RID& arg0, const Rect2& arg1, const int arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_int_Object_int_bool_String(godot_method_bind *mb, const Object *inst, const int arg0, const Object *arg1, const int arg2, const bool arg3, const String& arg4) {
	const void *args[] = {
		(void *) &arg0,
		(void *) arg1->_owner,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
String ___godot_icall_String_int_int(godot_method_bind *mb, const Object *inst, const int arg0, const int arg1) {
	String ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_bool_bool_int_int(godot_method_bind *mb, const Object *inst, const bool arg0, const bool arg1, const int arg2, const int arg3) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Variant ___godot_icall_Variant_RID_String(godot_method_bind *mb, const Object *inst, const RID& arg0, const String& arg1) {
	Variant ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
AABB ___godot_icall_AABB_RID(godot_method_bind *mb, const Object *inst, const RID& arg0) {
	AABB ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_RID_bool_Rect2(godot_method_bind *mb, const Object *inst, const RID& arg0, const bool arg1, const Rect2& arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_PoolVector3Array_PoolVector2Array_PoolColorArray_PoolVector2Array_PoolVector3Array_Array(godot_method_bind *mb, const Object *inst, const PoolVector3Array& arg0, const PoolVector2Array& arg1, const PoolColorArray& arg2, const PoolVector2Array& arg3, const PoolVector3Array& arg4, const Array& arg5) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
		(void *) &arg5,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
PoolRealArray ___godot_icall_PoolRealArray_int(godot_method_bind *mb, const Object *inst, const int arg0) {
	PoolRealArray ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Object *___godot_icall_Object_int(godot_method_bind *mb, const Object *inst, const int arg0) {
	godot_object *ret;
	ret = nullptr;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, ret);
}
void ___godot_icall_void_Object_String_int(godot_method_bind *mb, const Object *inst, const Object *arg0, const String& arg1, const int arg2) {
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
bool ___godot_icall_bool_Vector2_Vector2_Vector2_Vector2(godot_method_bind *mb, const Object *inst, const Vector2& arg0, const Vector2& arg1, const Vector2& arg2, const Vector2& arg3) {
	bool ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Vector2 ___godot_icall_Vector2_String(godot_method_bind *mb, const Object *inst, const String& arg0) {
	Vector2 ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Vector3 ___godot_icall_Vector3_Vector3(godot_method_bind *mb, const Object *inst, const Vector3& arg0) {
	Vector3 ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_RID_Color(godot_method_bind *mb, const Object *inst, const RID& arg0, const Color& arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Dictionary ___godot_icall_Dictionary_Vector3_Vector3_Array_int(godot_method_bind *mb, const Object *inst, const Vector3& arg0, const Vector3& arg1, const Array& arg2, const int arg3) {
	Dictionary ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
double ___godot_icall_float(godot_method_bind *mb, const Object *inst) {
	double ret;
	const void *args[1] = {
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
int64_t ___godot_icall_int_int_int_int_int(godot_method_bind *mb, const Object *inst, const int arg0, const int arg1, const int arg2, const int arg3) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
bool ___godot_icall_bool_float(godot_method_bind *mb, const Object *inst, const double arg0) {
	bool ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_String_Variant(godot_method_bind *mb, const Object *inst, const String& arg0, const Variant& arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Object *___godot_icall_Object_bool(godot_method_bind *mb, const Object *inst, const bool arg0) {
	godot_object *ret;
	ret = nullptr;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, ret);
}
void ___godot_icall_void_PoolVector2Array(godot_method_bind *mb, const Object *inst, const PoolVector2Array& arg0) {
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
PoolVector3Array ___godot_icall_PoolVector3Array_Vector3_Vector3_Array(godot_method_bind *mb, const Object *inst, const Vector3& arg0, const Vector3& arg1, const Array& arg2) {
	PoolVector3Array ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Color ___godot_icall_Color_int_int(godot_method_bind *mb, const Object *inst, const int arg0, const int arg1) {
	Color ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Variant ___godot_icall_Variant_Transform2D_Vector2_Object_Transform2D_Vector2(godot_method_bind *mb, const Object *inst, const Transform2D& arg0, const Vector2& arg1, const Object *arg2, const Transform2D& arg3, const Vector2& arg4) {
	Variant ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) arg2->_owner,
		(void *) &arg3,
		(void *) &arg4,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Transform2D ___godot_icall_Transform2D_RID_int(godot_method_bind *mb, const Object *inst, const RID& arg0, const int arg1) {
	Transform2D ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
PoolColorArray ___godot_icall_PoolColorArray(godot_method_bind *mb, const Object *inst) {
	PoolColorArray ret;
	const void *args[1] = {
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_Object_String_Array(godot_method_bind *mb, const Object *inst, const Object *arg0, const String& arg1, const Array& arg2) {
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
RID ___godot_icall_RID_RID_String(godot_method_bind *mb, const Object *inst, const RID& arg0, const String& arg1) {
	RID ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Transform ___godot_icall_Transform_RID(godot_method_bind *mb, const Object *inst, const RID& arg0) {
	Transform ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
int64_t ___godot_icall_int_Object_String_Variant_int(godot_method_bind *mb, const Object *inst, const Object *arg0, const String& arg1, const Variant& arg2, const int arg3) {
	int64_t ret;
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_RID_Rect2_Rect2_Color_bool_Object_bool(godot_method_bind *mb, const Object *inst, const RID& arg0, const Rect2& arg1, const Rect2& arg2, const Color& arg3, const bool arg4, const Object *arg5, const bool arg6) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
		(void *) arg5->_owner,
		(void *) &arg6,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Vector2 ___godot_icall_Vector2_int_int(godot_method_bind *mb, const Object *inst, const int arg0, const int arg1) {
	Vector2 ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
bool ___godot_icall_bool_String_Object(godot_method_bind *mb, const Object *inst, const String& arg0, const Object *arg1) {
	bool ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) arg1->_owner,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
int64_t ___godot_icall_int_int_String_int(godot_method_bind *mb, const Object *inst, const int arg0, const String& arg1, const int arg2) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
String ___godot_icall_String_String_Object(godot_method_bind *mb, const Object *inst, const String& arg0, const Object *arg1) {
	String ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) arg1->_owner,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Plane ___godot_icall_Plane(godot_method_bind *mb, const Object *inst) {
	Plane ret;
	const void *args[1] = {
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_PoolRealArray(godot_method_bind *mb, const Object *inst, const PoolRealArray& arg0) {
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
String ___godot_icall_String_String(godot_method_bind *mb, const Object *inst, const String& arg0) {
	String ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_PoolByteArray(godot_method_bind *mb, const Object *inst, const PoolByteArray& arg0) {
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
bool ___godot_icall_bool_int(godot_method_bind *mb, const Object *inst, const int arg0) {
	bool ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_Vector2_bool(godot_method_bind *mb, const Object *inst, const Vector2& arg0, const bool arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_String_int_Vector2(godot_method_bind *mb, const Object *inst, const String& arg0, const int arg1, const Vector2& arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
bool ___godot_icall_bool_String_int_int_int_int(godot_method_bind *mb, const Object *inst, const String& arg0, const int arg1, const int arg2, const int arg3, const int arg4) {
	bool ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Variant ___godot_icall_Variant_RID(godot_method_bind *mb, const Object *inst, const RID& arg0) {
	Variant ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
PoolVector3Array ___godot_icall_PoolVector3Array_Vector3_Vector3_Vector3_float(godot_method_bind *mb, const Object *inst, const Vector3& arg0, const Vector3& arg1, const Vector3& arg2, const double arg3) {
	PoolVector3Array ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Color ___godot_icall_Color_int(godot_method_bind *mb, const Object *inst, const int arg0) {
	Color ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_String_int_int(godot_method_bind *mb, const Object *inst, const String& arg0, const int arg1, const int arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Variant ___godot_icall_Variant_Vector2_Object(godot_method_bind *mb, const Object *inst, const Vector2& arg0, const Object *arg1) {
	Variant ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) arg1->_owner,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
bool ___godot_icall_bool_String_Dictionary(godot_method_bind *mb, const Object *inst, const String& arg0, const Dictionary& arg1) {
	bool ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_Vector2_Variant_Object(godot_method_bind *mb, const Object *inst, const Vector2& arg0, const Variant& arg1, const Object *arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) arg2->_owner,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Array ___godot_icall_Array_PoolByteArray(godot_method_bind *mb, const Object *inst, const PoolByteArray& arg0) {
	Array ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Array ___godot_icall_Array_float_float_int_int_int(godot_method_bind *mb, const Object *inst, const double arg0, const double arg1, const int arg2, const int arg3, const int arg4) {
	Array ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_RID_int_float(godot_method_bind *mb, const Object *inst, const RID& arg0, const int arg1, const double arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Vector2 ___godot_icall_Vector2_Vector2_Vector2_Vector2(godot_method_bind *mb, const Object *inst, const Vector2& arg0, const Vector2& arg1, const Vector2& arg2) {
	Vector2 ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
NodePath ___godot_icall_NodePath_int_bool(godot_method_bind *mb, const Object *inst, const int arg0, const bool arg1) {
	NodePath ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_int_Color_bool(godot_method_bind *mb, const Object *inst, const int arg0, const Color& arg1, const bool arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Vector2 ___godot_icall_Vector2_Vector2_bool(godot_method_bind *mb, const Object *inst, const Vector2& arg0, const bool arg1) {
	Vector2 ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Object *___godot_icall_Object_Vector3(godot_method_bind *mb, const Object *inst, const Vector3& arg0) {
	godot_object *ret;
	ret = nullptr;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, ret);
}
void ___godot_icall_void_RID_PoolVector2Array(godot_method_bind *mb, const Object *inst, const RID& arg0, const PoolVector2Array& arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_int_float_float_float(godot_method_bind *mb, const Object *inst, const int arg0, const double arg1, const double arg2, const double arg3) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_RID_bool_int_float_float_float_bool(godot_method_bind *mb, const Object *inst, const RID& arg0, const bool arg1, const int arg2, const double arg3, const double arg4, const double arg5, const bool arg6) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
		(void *) &arg5,
		(void *) &arg6,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Object *___godot_icall_Object_String_int(godot_method_bind *mb, const Object *inst, const String& arg0, const int arg1) {
	godot_object *ret;
	ret = nullptr;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, ret);
}
void ___godot_icall_void_Object_Object_int(godot_method_bind *mb, const Object *inst, const Object *arg0, const Object *arg1, const int arg2) {
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) arg1->_owner,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
PoolIntArray ___godot_icall_PoolIntArray_String_int_int_int(godot_method_bind *mb, const Object *inst, const String& arg0, const int arg1, const int arg2, const int arg3) {
	PoolIntArray ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Vector2 ___godot_icall_Vector2(godot_method_bind *mb, const Object *inst) {
	Vector2 ret;
	const void *args[1] = {
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
bool ___godot_icall_bool_Object_String_Object_String_Variant_float_int_int_float(godot_method_bind *mb, const Object *inst, const Object *arg0, const String& arg1, const Object *arg2, const String& arg3, const Variant& arg4, const double arg5, const int arg6, const int arg7, const double arg8) {
	bool ret;
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
		(void *) arg2->_owner,
		(void *) &arg3,
		(void *) &arg4,
		(void *) &arg5,
		(void *) &arg6,
		(void *) &arg7,
		(void *) &arg8,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
String ___godot_icall_String_Object(godot_method_bind *mb, const Object *inst, const Object *arg0) {
	String ret;
	const void *args[] = {
		(void *) arg0->_owner,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_bool_float(godot_method_bind *mb, const Object *inst, const bool arg0, const double arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_String_NodePath_bool(godot_method_bind *mb, const Object *inst, const String& arg0, const NodePath& arg1, const bool arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
int64_t ___godot_icall_int_int_int_float(godot_method_bind *mb, const Object *inst, const int arg0, const int arg1, const double arg2) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
PoolIntArray ___godot_icall_PoolIntArray_int(godot_method_bind *mb, const Object *inst, const int arg0) {
	PoolIntArray ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_Transform2D_Vector2(godot_method_bind *mb, const Object *inst, const Transform2D& arg0, const Vector2& arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_int_NodePath(godot_method_bind *mb, const Object *inst, const int arg0, const NodePath& arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
double ___godot_icall_float_int(godot_method_bind *mb, const Object *inst, const int arg0) {
	double ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Vector2 ___godot_icall_Vector2_int_int_Object_Vector2(godot_method_bind *mb, const Object *inst, const int arg0, const int arg1, const Object *arg2, const Vector2& arg3) {
	Vector2 ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) arg2->_owner,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Object *___godot_icall_Object_String_bool_bool(godot_method_bind *mb, const Object *inst, const String& arg0, const bool arg1, const bool arg2) {
	godot_object *ret;
	ret = nullptr;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, ret);
}
int64_t ___godot_icall_int_Object_Transform_Object(godot_method_bind *mb, const Object *inst, const Object *arg0, const Transform& arg1, const Object *arg2) {
	int64_t ret;
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
		(void *) arg2->_owner,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Variant ___godot_icall_Variant_Transform2D_Object_Transform2D(godot_method_bind *mb, const Object *inst, const Transform2D& arg0, const Object *arg1, const Transform2D& arg2) {
	Variant ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) arg1->_owner,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_Object_Color_bool(godot_method_bind *mb, const Object *inst, const Object *arg0, const Color& arg1, const bool arg2) {
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_Color(godot_method_bind *mb, const Object *inst, const Color& arg0) {
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_String_Object(godot_method_bind *mb, const Object *inst, const String& arg0, const Object *arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) arg1->_owner,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_RID_Rect2(godot_method_bind *mb, const Object *inst, const RID& arg0, const Rect2& arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_RID_bool_float_float_bool_float(godot_method_bind *mb, const Object *inst, const RID& arg0, const bool arg1, const double arg2, const double arg3, const bool arg4, const double arg5) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
		(void *) &arg5,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Array ___godot_icall_Array_Object_Vector3(godot_method_bind *mb, const Object *inst, const Object *arg0, const Vector3& arg1) {
	Array ret;
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_Object_Rect2(godot_method_bind *mb, const Object *inst, const Object *arg0, const Rect2& arg1) {
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
bool ___godot_icall_bool_String_int_int_int(godot_method_bind *mb, const Object *inst, const String& arg0, const int arg1, const int arg2, const int arg3) {
	bool ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Variant ___godot_icall_Variant_String_String_Variant(godot_method_bind *mb, const Object *inst, const String& arg0, const String& arg1, const Variant& arg2) {
	Variant ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Variant ___godot_icall_Variant_Vector2_Vector2_Vector2_Vector2(godot_method_bind *mb, const Object *inst, const Vector2& arg0, const Vector2& arg1, const Vector2& arg2, const Vector2& arg3) {
	Variant ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
bool ___godot_icall_bool_Object_float_String_Variant_Variant_Variant_Variant_Variant(godot_method_bind *mb, const Object *inst, const Object *arg0, const double arg1, const String& arg2, const Variant& arg3, const Variant& arg4, const Variant& arg5, const Variant& arg6, const Variant& arg7) {
	bool ret;
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
		(void *) &arg5,
		(void *) &arg6,
		(void *) &arg7,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_int_bool_int_Color_bool_int_Color_Object_Object(godot_method_bind *mb, const Object *inst, const int arg0, const bool arg1, const int arg2, const Color& arg3, const bool arg4, const int arg5, const Color& arg6, const Object *arg7, const Object *arg8) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
		(void *) &arg5,
		(void *) &arg6,
		(void *) arg7->_owner,
		(void *) arg8->_owner,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_String_String_float(godot_method_bind *mb, const Object *inst, const String& arg0, const String& arg1, const double arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
bool ___godot_icall_bool_Object_String(godot_method_bind *mb, const Object *inst, const Object *arg0, const String& arg1) {
	bool ret;
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_RID_Rect2_RID_bool_Color_bool_RID(godot_method_bind *mb, const Object *inst, const RID& arg0, const Rect2& arg1, const RID& arg2, const bool arg3, const Color& arg4, const bool arg5, const RID& arg6) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
		(void *) &arg5,
		(void *) &arg6,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
RID ___godot_icall_RID_RID_int(godot_method_bind *mb, const Object *inst, const RID& arg0, const int arg1) {
	RID ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
bool ___godot_icall_bool_Vector2_Rect2(godot_method_bind *mb, const Object *inst, const Vector2& arg0, const Rect2& arg1) {
	bool ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_Transform2D(godot_method_bind *mb, const Object *inst, const Transform2D& arg0) {
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_Vector3_float(godot_method_bind *mb, const Object *inst, const Vector3& arg0, const double arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_Object_Rect2_bool_Color_bool_Object(godot_method_bind *mb, const Object *inst, const Object *arg0, const Rect2& arg1, const bool arg2, const Color& arg3, const bool arg4, const Object *arg5) {
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
		(void *) arg5->_owner,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Vector2 ___godot_icall_Vector2_int_float(godot_method_bind *mb, const Object *inst, const int arg0, const double arg1) {
	Vector2 ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_RID_RID_Vector2(godot_method_bind *mb, const Object *inst, const RID& arg0, const RID& arg1, const Vector2& arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_int_int_Vector2_float(godot_method_bind *mb, const Object *inst, const int arg0, const int arg1, const Vector2& arg2, const double arg3) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_Basis(godot_method_bind *mb, const Object *inst, const Basis& arg0) {
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
int64_t ___godot_icall_int_String(godot_method_bind *mb, const Object *inst, const String& arg0) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Variant ___godot_icall_Variant_int(godot_method_bind *mb, const Object *inst, const int arg0) {
	Variant ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_int_int_PoolStringArray_PoolByteArray(godot_method_bind *mb, const Object *inst, const int arg0, const int arg1, const PoolStringArray& arg2, const PoolByteArray& arg3) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
bool ___godot_icall_bool_Object_String_Variant_Variant_float_int_int_float(godot_method_bind *mb, const Object *inst, const Object *arg0, const String& arg1, const Variant& arg2, const Variant& arg3, const double arg4, const int arg5, const int arg6, const double arg7) {
	bool ret;
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
		(void *) &arg5,
		(void *) &arg6,
		(void *) &arg7,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
int64_t ___godot_icall_int_String_float_String_String(godot_method_bind *mb, const Object *inst, const String& arg0, const double arg1, const String& arg2, const String& arg3) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_String_Object_String(godot_method_bind *mb, const Object *inst, const String& arg0, const Object *arg1, const String& arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) arg1->_owner,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_PoolVector3Array_bool_bool(godot_method_bind *mb, const Object *inst, const PoolVector3Array& arg0, const bool arg1, const bool arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_Object_float(godot_method_bind *mb, const Object *inst, const Object *arg0, const double arg1) {
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Variant ___godot_icall_Variant_String_Array(godot_method_bind *mb, const Object *inst, const String& arg0, const Array& arg1) {
	Variant ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Vector2 ___godot_icall_Vector2_int(godot_method_bind *mb, const Object *inst, const int arg0) {
	Vector2 ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_String_Variant_bool(godot_method_bind *mb, const Object *inst, const String& arg0, const Variant& arg1, const bool arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
int64_t ___godot_icall_int_String_Object_String_Array_int(godot_method_bind *mb, const Object *inst, const String& arg0, const Object *arg1, const String& arg2, const Array& arg3, const int arg4) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) arg1->_owner,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Transform2D ___godot_icall_Transform2D_RID(godot_method_bind *mb, const Object *inst, const RID& arg0) {
	Transform2D ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_int_Transform2D(godot_method_bind *mb, const Object *inst, const int arg0, const Transform2D& arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
PoolVector3Array ___godot_icall_PoolVector3Array_Vector3_Vector3_bool(godot_method_bind *mb, const Object *inst, const Vector3& arg0, const Vector3& arg1, const bool arg2) {
	PoolVector3Array ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Object *___godot_icall_Object_Transform2D_Vector2(godot_method_bind *mb, const Object *inst, const Transform2D& arg0, const Vector2& arg1) {
	godot_object *ret;
	ret = nullptr;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, ret);
}
void ___godot_icall_void_Vector2_Vector2_Color_float_bool(godot_method_bind *mb, const Object *inst, const Vector2& arg0, const Vector2& arg1, const Color& arg2, const double arg3, const bool arg4) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Object *___godot_icall_Object_int_int(godot_method_bind *mb, const Object *inst, const int arg0, const int arg1) {
	godot_object *ret;
	ret = nullptr;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, ret);
}
void ___godot_icall_void_String_int_String(godot_method_bind *mb, const Object *inst, const String& arg0, const int arg1, const String& arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_String_int_bool(godot_method_bind *mb, const Object *inst, const String& arg0, const int arg1, const bool arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_String_String_Color_bool(godot_method_bind *mb, const Object *inst, const String& arg0, const String& arg1, const Color& arg2, const bool arg3) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_int_Variant_bool(godot_method_bind *mb, const Object *inst, const int arg0, const Variant& arg1, const bool arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Object *___godot_icall_Object_String_String(godot_method_bind *mb, const Object *inst, const String& arg0, const String& arg1) {
	godot_object *ret;
	ret = nullptr;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, ret);
}
int64_t ___godot_icall_int_int_int(godot_method_bind *mb, const Object *inst, const int arg0, const int arg1) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
int64_t ___godot_icall_int_String_PoolStringArray_bool_int_String(godot_method_bind *mb, const Object *inst, const String& arg0, const PoolStringArray& arg1, const bool arg2, const int arg3, const String& arg4) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
int64_t ___godot_icall_int_int_PoolStringArray_bool(godot_method_bind *mb, const Object *inst, const int arg0, const PoolStringArray& arg1, const bool arg2) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
int64_t ___godot_icall_int_String_String(godot_method_bind *mb, const Object *inst, const String& arg0, const String& arg1) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_Vector2_float_Vector2(godot_method_bind *mb, const Object *inst, const Vector2& arg0, const double arg1, const Vector2& arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Transform ___godot_icall_Transform_int(godot_method_bind *mb, const Object *inst, const int arg0) {
	Transform ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_RID_PoolVector2Array_PoolColorArray_float_bool(godot_method_bind *mb, const Object *inst, const RID& arg0, const PoolVector2Array& arg1, const PoolColorArray& arg2, const double arg3, const bool arg4) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_int_Object(godot_method_bind *mb, const Object *inst, const int arg0, const Object *arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) arg1->_owner,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
bool ___godot_icall_bool_String_String_int(godot_method_bind *mb, const Object *inst, const String& arg0, const String& arg1, const int arg2) {
	bool ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_String_bool(godot_method_bind *mb, const Object *inst, const String& arg0, const bool arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
bool ___godot_icall_bool_String_Variant(godot_method_bind *mb, const Object *inst, const String& arg0, const Variant& arg1) {
	bool ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_String_int_Object(godot_method_bind *mb, const Object *inst, const String& arg0, const int arg1, const Object *arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) arg2->_owner,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Variant ___godot_icall_Variant_RID_int(godot_method_bind *mb, const Object *inst, const RID& arg0, const int arg1) {
	Variant ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Array ___godot_icall_Array_int_float(godot_method_bind *mb, const Object *inst, const int arg0, const double arg1) {
	Array ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_RID_Variant(godot_method_bind *mb, const Object *inst, const RID& arg0, const Variant& arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_RID_Rect2_Color(godot_method_bind *mb, const Object *inst, const RID& arg0, const Rect2& arg1, const Color& arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Variant ___godot_icall_Variant_Array(godot_method_bind *mb, const Object *inst, const Array& arg0) {
	Variant ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_RID_Color_float_float(godot_method_bind *mb, const Object *inst, const RID& arg0, const Color& arg1, const double arg2, const double arg3) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Dictionary ___godot_icall_Dictionary_int(godot_method_bind *mb, const Object *inst, const int arg0) {
	Dictionary ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
bool ___godot_icall_bool_String_Object_String(godot_method_bind *mb, const Object *inst, const String& arg0, const Object *arg1, const String& arg2) {
	bool ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) arg1->_owner,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Variant ___godot_icall_Variant_String(godot_method_bind *mb, const Object *inst, const String& arg0) {
	Variant ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_String_Object_int_String_Variant(godot_method_bind *mb, const Object *inst, const String& arg0, const Object *arg1, const int arg2, const String& arg3, const Variant& arg4) {
	const void *args[] = {
		(void *) &arg0,
		(void *) arg1->_owner,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_bool(godot_method_bind *mb, const Object *inst, const bool arg0) {
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Vector2 ___godot_icall_Vector2_String_int(godot_method_bind *mb, const Object *inst, const String& arg0, const int arg1) {
	Vector2 ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
int64_t ___godot_icall_int_PoolByteArray(godot_method_bind *mb, const Object *inst, const PoolByteArray& arg0) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_Vector2_Vector2(godot_method_bind *mb, const Object *inst, const Vector2& arg0, const Vector2& arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_RID_Vector2_Color_bool_Object(godot_method_bind *mb, const Object *inst, const RID& arg0, const Vector2& arg1, const Color& arg2, const bool arg3, const Object *arg4) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) arg4->_owner,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_PoolVector3Array(godot_method_bind *mb, const Object *inst, const PoolVector3Array& arg0) {
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
bool ___godot_icall_bool_Object_Object(godot_method_bind *mb, const Object *inst, const Object *arg0, const Object *arg1) {
	bool ret;
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) arg1->_owner,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_RID_float_float_float_float(godot_method_bind *mb, const Object *inst, const RID& arg0, const double arg1, const double arg2, const double arg3, const double arg4) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_Transform(godot_method_bind *mb, const Object *inst, const Transform& arg0) {
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
RID ___godot_icall_RID_RID_RID(godot_method_bind *mb, const Object *inst, const RID& arg0, const RID& arg1) {
	RID ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
String ___godot_icall_String_String_int(godot_method_bind *mb, const Object *inst, const String& arg0, const int arg1) {
	String ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_Object_Object_Rect2_Vector2(godot_method_bind *mb, const Object *inst, const Object *arg0, const Object *arg1, const Rect2& arg2, const Vector2& arg3) {
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) arg1->_owner,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_PoolVector2Array_PoolColorArray_PoolVector2Array_Object_float_Object(godot_method_bind *mb, const Object *inst, const PoolVector2Array& arg0, const PoolColorArray& arg1, const PoolVector2Array& arg2, const Object *arg3, const double arg4, const Object *arg5) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) arg3->_owner,
		(void *) &arg4,
		(void *) arg5->_owner,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_float_float_float(godot_method_bind *mb, const Object *inst, const double arg0, const double arg1, const double arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Object *___godot_icall_Object_Object(godot_method_bind *mb, const Object *inst, const Object *arg0) {
	godot_object *ret;
	ret = nullptr;
	const void *args[] = {
		(void *) arg0->_owner,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, ret);
}
void ___godot_icall_void_Rect2_Color_bool(godot_method_bind *mb, const Object *inst, const Rect2& arg0, const Color& arg1, const bool arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_RID_Vector3(godot_method_bind *mb, const Object *inst, const RID& arg0, const Vector3& arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Rect2 ___godot_icall_Rect2_int(godot_method_bind *mb, const Object *inst, const int arg0) {
	Rect2 ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
int64_t ___godot_icall_int_String_int_PoolByteArray(godot_method_bind *mb, const Object *inst, const String& arg0, const int arg1, const PoolByteArray& arg2) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_int_int_bool_int(godot_method_bind *mb, const Object *inst, const int arg0, const int arg1, const bool arg2, const int arg3) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_Object_Object_String_Variant(godot_method_bind *mb, const Object *inst, const Object *arg0, const Object *arg1, const String& arg2, const Variant& arg3) {
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) arg1->_owner,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_Object_String_int_int(godot_method_bind *mb, const Object *inst, const Object *arg0, const String& arg1, const int arg2, const int arg3) {
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_RID_float_float_float(godot_method_bind *mb, const Object *inst, const RID& arg0, const double arg1, const double arg2, const double arg3) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_PoolIntArray(godot_method_bind *mb, const Object *inst, const PoolIntArray& arg0) {
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Variant ___godot_icall_Variant_int_int(godot_method_bind *mb, const Object *inst, const int arg0, const int arg1) {
	Variant ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_Array(godot_method_bind *mb, const Object *inst, const Array& arg0) {
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_String_int_Object_Vector2(godot_method_bind *mb, const Object *inst, const String& arg0, const int arg1, const Object *arg2, const Vector2& arg3) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) arg2->_owner,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Color ___godot_icall_Color_String_String(godot_method_bind *mb, const Object *inst, const String& arg0, const String& arg1) {
	Color ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
int64_t ___godot_icall_int_Vector2_Object(godot_method_bind *mb, const Object *inst, const Vector2& arg0, const Object *arg1) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) arg1->_owner,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_RID_PoolVector2Array_PoolColorArray_PoolVector2Array_RID_float_RID(godot_method_bind *mb, const Object *inst, const RID& arg0, const PoolVector2Array& arg1, const PoolColorArray& arg2, const PoolVector2Array& arg3, const RID& arg4, const double arg5, const RID& arg6) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
		(void *) &arg5,
		(void *) &arg6,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
int64_t ___godot_icall_int_Object_bool_String(godot_method_bind *mb, const Object *inst, const Object *arg0, const bool arg1, const String& arg2) {
	int64_t ret;
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_int_Vector2(godot_method_bind *mb, const Object *inst, const int arg0, const Vector2& arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_RID_bool_float_float_float_int(godot_method_bind *mb, const Object *inst, const RID& arg0, const bool arg1, const double arg2, const double arg3, const double arg4, const int arg5) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
		(void *) &arg5,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_String(godot_method_bind *mb, const Object *inst, const String& arg0) {
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_Object_Object_Vector3_Vector3_int(godot_method_bind *mb, const Object *inst, const Object *arg0, const Object *arg1, const Vector3& arg2, const Vector3& arg3, const int arg4) {
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) arg1->_owner,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
PoolVector2Array ___godot_icall_PoolVector2Array_Vector2_Vector2_bool(godot_method_bind *mb, const Object *inst, const Vector2& arg0, const Vector2& arg1, const bool arg2) {
	PoolVector2Array ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
RID ___godot_icall_RID_RID(godot_method_bind *mb, const Object *inst, const RID& arg0) {
	RID ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
double ___godot_icall_float_RID_int_int(godot_method_bind *mb, const Object *inst, const RID& arg0, const int arg1, const int arg2) {
	double ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_NodePath_Variant(godot_method_bind *mb, const Object *inst, const NodePath& arg0, const Variant& arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_Object_Object_int_bool(godot_method_bind *mb, const Object *inst, const Object *arg0, const Object *arg1, const int arg2, const bool arg3) {
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) arg1->_owner,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
int64_t ___godot_icall_int_String_int_String(godot_method_bind *mb, const Object *inst, const String& arg0, const int arg1, const String& arg2) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Variant ___godot_icall_Variant_String_bool(godot_method_bind *mb, const Object *inst, const String& arg0, const bool arg1) {
	Variant ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_Vector2_Vector2_Vector2_int(godot_method_bind *mb, const Object *inst, const Vector2& arg0, const Vector2& arg1, const Vector2& arg2, const int arg3) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_PoolStringArray(godot_method_bind *mb, const Object *inst, const PoolStringArray& arg0) {
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_RID_AABB(godot_method_bind *mb, const Object *inst, const RID& arg0, const AABB& arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
int64_t ___godot_icall_int_Object_bool(godot_method_bind *mb, const Object *inst, const Object *arg0, const bool arg1) {
	int64_t ret;
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
int64_t ___godot_icall_int_String_int_bool_bool(godot_method_bind *mb, const Object *inst, const String& arg0, const int arg1, const bool arg2, const bool arg3) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_Object_Rect2_Vector2(godot_method_bind *mb, const Object *inst, const Object *arg0, const Rect2& arg1, const Vector2& arg2) {
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
int64_t ___godot_icall_int_Variant(godot_method_bind *mb, const Object *inst, const Variant& arg0) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Vector3 ___godot_icall_Vector3_Vector3_Vector3_bool(godot_method_bind *mb, const Object *inst, const Vector3& arg0, const Vector3& arg1, const bool arg2) {
	Vector3 ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_int_float(godot_method_bind *mb, const Object *inst, const int arg0, const double arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_int_int(godot_method_bind *mb, const Object *inst, const int arg0, const int arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Object *___godot_icall_Object_RID(godot_method_bind *mb, const Object *inst, const RID& arg0) {
	godot_object *ret;
	ret = nullptr;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, ret);
}
String ___godot_icall_String_Dictionary(godot_method_bind *mb, const Object *inst, const Dictionary& arg0) {
	String ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
int64_t ___godot_icall_int_String_int_String_int(godot_method_bind *mb, const Object *inst, const String& arg0, const int arg1, const String& arg2, const int arg3) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_PoolVector2Array_Color_float_bool(godot_method_bind *mb, const Object *inst, const PoolVector2Array& arg0, const Color& arg1, const double arg2, const bool arg3) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
bool ___godot_icall_bool_RID_int(godot_method_bind *mb, const Object *inst, const RID& arg0, const int arg1) {
	bool ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_int_float_bool_bool(godot_method_bind *mb, const Object *inst, const int arg0, const double arg1, const bool arg2, const bool arg3) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Array ___godot_icall_Array_Vector3(godot_method_bind *mb, const Object *inst, const Vector3& arg0) {
	Array ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
int64_t ___godot_icall_int_int(godot_method_bind *mb, const Object *inst, const int arg0) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
PoolIntArray ___godot_icall_PoolIntArray(godot_method_bind *mb, const Object *inst) {
	PoolIntArray ret;
	const void *args[1] = {
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_Object_Rect2_Rect2_Color_bool_Object_bool(godot_method_bind *mb, const Object *inst, const Object *arg0, const Rect2& arg1, const Rect2& arg2, const Color& arg3, const bool arg4, const Object *arg5, const bool arg6) {
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
		(void *) arg5->_owner,
		(void *) &arg6,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
PoolVector3Array ___godot_icall_PoolVector3Array(godot_method_bind *mb, const Object *inst) {
	PoolVector3Array ret;
	const void *args[1] = {
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_int_Object_String(godot_method_bind *mb, const Object *inst, const int arg0, const Object *arg1, const String& arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) arg1->_owner,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_Object_bool(godot_method_bind *mb, const Object *inst, const Object *arg0, const bool arg1) {
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
bool ___godot_icall_bool_String(godot_method_bind *mb, const Object *inst, const String& arg0) {
	bool ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
PoolStringArray ___godot_icall_PoolStringArray_String(godot_method_bind *mb, const Object *inst, const String& arg0) {
	PoolStringArray ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
int64_t ___godot_icall_int_int_String_PoolStringArray_PoolByteArray(godot_method_bind *mb, const Object *inst, const int arg0, const String& arg1, const PoolStringArray& arg2, const PoolByteArray& arg3) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Object *___godot_icall_Object_Rect2(godot_method_bind *mb, const Object *inst, const Rect2& arg0) {
	godot_object *ret;
	ret = nullptr;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, ret);
}
int64_t ___godot_icall_int_bool(godot_method_bind *mb, const Object *inst, const bool arg0) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_String_String_Object(godot_method_bind *mb, const Object *inst, const String& arg0, const String& arg1, const Object *arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) arg2->_owner,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_Vector2_float_Color(godot_method_bind *mb, const Object *inst, const Vector2& arg0, const double arg1, const Color& arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
RID ___godot_icall_RID_RID_Vector3_RID_Vector3(godot_method_bind *mb, const Object *inst, const RID& arg0, const Vector3& arg1, const RID& arg2, const Vector3& arg3) {
	RID ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_Vector3(godot_method_bind *mb, const Object *inst, const Vector3& arg0) {
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_Rect2_bool(godot_method_bind *mb, const Object *inst, const Rect2& arg0, const bool arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_int_bool_bool(godot_method_bind *mb, const Object *inst, const int arg0, const bool arg1, const bool arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_RID_Plane(godot_method_bind *mb, const Object *inst, const RID& arg0, const Plane& arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_AABB(godot_method_bind *mb, const Object *inst, const AABB& arg0) {
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_Vector2_Variant(godot_method_bind *mb, const Object *inst, const Vector2& arg0, const Variant& arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
int64_t ___godot_icall_int_Object_int(godot_method_bind *mb, const Object *inst, const Object *arg0, const int arg1) {
	int64_t ret;
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
PoolVector2Array ___godot_icall_PoolVector2Array_Vector2_Vector2_Vector2_Vector2(godot_method_bind *mb, const Object *inst, const Vector2& arg0, const Vector2& arg1, const Vector2& arg2, const Vector2& arg3) {
	PoolVector2Array ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_RID_float(godot_method_bind *mb, const Object *inst, const RID& arg0, const double arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_int_Object_int(godot_method_bind *mb, const Object *inst, const int arg0, const Object *arg1, const int arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) arg1->_owner,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
PoolVector2Array ___godot_icall_PoolVector2Array_int_float(godot_method_bind *mb, const Object *inst, const int arg0, const double arg1) {
	PoolVector2Array ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_RID_int_Color(godot_method_bind *mb, const Object *inst, const RID& arg0, const int arg1, const Color& arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
PoolVector3Array ___godot_icall_PoolVector3Array_Vector3_Vector3_float_float(godot_method_bind *mb, const Object *inst, const Vector3& arg0, const Vector3& arg1, const double arg2, const double arg3) {
	PoolVector3Array ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
int64_t ___godot_icall_int_String_int(godot_method_bind *mb, const Object *inst, const String& arg0, const int arg1) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
int64_t ___godot_icall_int_String_Object_int(godot_method_bind *mb, const Object *inst, const String& arg0, const Object *arg1, const int arg2) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) arg1->_owner,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_int_bool_String_String(godot_method_bind *mb, const Object *inst, const int arg0, const bool arg1, const String& arg2, const String& arg3) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
int64_t ___godot_icall_int_String_String_Dictionary_Array_Array(godot_method_bind *mb, const Object *inst, const String& arg0, const String& arg1, const Dictionary& arg2, const Array& arg3, const Array& arg4) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_Object_String(godot_method_bind *mb, const Object *inst, const Object *arg0, const String& arg1) {
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_RID_PoolByteArray(godot_method_bind *mb, const Object *inst, const RID& arg0, const PoolByteArray& arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_RID_bool_float_float_float_float_float_float_Color_int_int_float(godot_method_bind *mb, const Object *inst, const RID& arg0, const bool arg1, const double arg2, const double arg3, const double arg4, const double arg5, const double arg6, const double arg7, const Color& arg8, const int arg9, const int arg10, const double arg11) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
		(void *) &arg5,
		(void *) &arg6,
		(void *) &arg7,
		(void *) &arg8,
		(void *) &arg9,
		(void *) &arg10,
		(void *) &arg11,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
PoolIntArray ___godot_icall_PoolIntArray_RID(godot_method_bind *mb, const Object *inst, const RID& arg0) {
	PoolIntArray ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
int64_t ___godot_icall_int_NodePath(godot_method_bind *mb, const Object *inst, const NodePath& arg0) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_Plane(godot_method_bind *mb, const Object *inst, const Plane& arg0) {
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
bool ___godot_icall_bool_Vector2_Variant(godot_method_bind *mb, const Object *inst, const Vector2& arg0, const Variant& arg1) {
	bool ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
int64_t ___godot_icall_int_String_int_int_int(godot_method_bind *mb, const Object *inst, const String& arg0, const int arg1, const int arg2, const int arg3) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Array ___godot_icall_Array_Object(godot_method_bind *mb, const Object *inst, const Object *arg0) {
	Array ret;
	const void *args[] = {
		(void *) arg0->_owner,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_RID_Rect2_RID_Rect2_Color_bool_RID_bool(godot_method_bind *mb, const Object *inst, const RID& arg0, const Rect2& arg1, const RID& arg2, const Rect2& arg3, const Color& arg4, const bool arg5, const RID& arg6, const bool arg7) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
		(void *) &arg5,
		(void *) &arg6,
		(void *) &arg7,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Vector3 ___godot_icall_Vector3_Vector3_Vector3_bool_float_int_float(godot_method_bind *mb, const Object *inst, const Vector3& arg0, const Vector3& arg1, const bool arg2, const double arg3, const int arg4, const double arg5) {
	Vector3 ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
		(void *) &arg5,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_NodePath(godot_method_bind *mb, const Object *inst, const NodePath& arg0) {
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Variant ___godot_icall_Variant(godot_method_bind *mb, const Object *inst) {
	Variant ret;
	const void *args[1] = {
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
bool ___godot_icall_bool_Vector2_bool_float_Object(godot_method_bind *mb, const Object *inst, const Vector2& arg0, const bool arg1, const double arg2, const Object *arg3) {
	bool ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) arg3->_owner,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_PoolVector2Array_Color_PoolVector2Array_Object_Object_bool(godot_method_bind *mb, const Object *inst, const PoolVector2Array& arg0, const Color& arg1, const PoolVector2Array& arg2, const Object *arg3, const Object *arg4, const bool arg5) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) arg3->_owner,
		(void *) arg4->_owner,
		(void *) &arg5,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_int_String(godot_method_bind *mb, const Object *inst, const int arg0, const String& arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
PoolIntArray ___godot_icall_PoolIntArray_int_int(godot_method_bind *mb, const Object *inst, const int arg0, const int arg1) {
	PoolIntArray ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Object *___godot_icall_Object_RID_int(godot_method_bind *mb, const Object *inst, const RID& arg0, const int arg1) {
	godot_object *ret;
	ret = nullptr;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, ret);
}
void ___godot_icall_void_bool_bool(godot_method_bind *mb, const Object *inst, const bool arg0, const bool arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_String_String_int(godot_method_bind *mb, const Object *inst, const String& arg0, const String& arg1, const int arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_PoolVector2Array_PoolColorArray_PoolVector2Array_Object_Object_bool(godot_method_bind *mb, const Object *inst, const PoolVector2Array& arg0, const PoolColorArray& arg1, const PoolVector2Array& arg2, const Object *arg3, const Object *arg4, const bool arg5) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) arg3->_owner,
		(void *) arg4->_owner,
		(void *) &arg5,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
PoolByteArray ___godot_icall_PoolByteArray_int(godot_method_bind *mb, const Object *inst, const int arg0) {
	PoolByteArray ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_Object(godot_method_bind *mb, const Object *inst, const Object *arg0) {
	const void *args[] = {
		(void *) arg0->_owner,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_RID_PoolIntArray(godot_method_bind *mb, const Object *inst, const RID& arg0, const PoolIntArray& arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_int_Plane(godot_method_bind *mb, const Object *inst, const int arg0, const Plane& arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_RID_int_RID(godot_method_bind *mb, const Object *inst, const RID& arg0, const int arg1, const RID& arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_int_int_int_int_int(godot_method_bind *mb, const Object *inst, const int arg0, const int arg1, const int arg2, const int arg3, const int arg4) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_int_Variant(godot_method_bind *mb, const Object *inst, const int arg0, const Variant& arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_Rect2(godot_method_bind *mb, const Object *inst, const Rect2& arg0) {
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Object *___godot_icall_Object_NodePath(godot_method_bind *mb, const Object *inst, const NodePath& arg0) {
	godot_object *ret;
	ret = nullptr;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, ret);
}
Vector3 ___godot_icall_Vector3(godot_method_bind *mb, const Object *inst) {
	Vector3 ret;
	const void *args[1] = {
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
RID ___godot_icall_RID_int_bool(godot_method_bind *mb, const Object *inst, const int arg0, const bool arg1) {
	RID ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_RID_bool(godot_method_bind *mb, const Object *inst, const RID& arg0, const bool arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Array ___godot_icall_Array_RID(godot_method_bind *mb, const Object *inst, const RID& arg0) {
	Array ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Array ___godot_icall_Array_String_int_int(godot_method_bind *mb, const Object *inst, const String& arg0, const int arg1, const int arg2) {
	Array ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Color ___godot_icall_Color_float(godot_method_bind *mb, const Object *inst, const double arg0) {
	Color ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
PoolIntArray ___godot_icall_PoolIntArray_int_float_float(godot_method_bind *mb, const Object *inst, const int arg0, const double arg1, const double arg2) {
	PoolIntArray ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
bool ___godot_icall_bool_int_int(godot_method_bind *mb, const Object *inst, const int arg0, const int arg1) {
	bool ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Rect2 ___godot_icall_Rect2_Object_int(godot_method_bind *mb, const Object *inst, const Object *arg0, const int arg1) {
	Rect2 ret;
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Object *___godot_icall_Object_String(godot_method_bind *mb, const Object *inst, const String& arg0) {
	godot_object *ret;
	ret = nullptr;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, ret);
}
Array ___godot_icall_Array_Vector2_int_Array_int(godot_method_bind *mb, const Object *inst, const Vector2& arg0, const int arg1, const Array& arg2, const int arg3) {
	Array ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
int64_t ___godot_icall_int_int_String_PoolStringArray_String(godot_method_bind *mb, const Object *inst, const int arg0, const String& arg1, const PoolStringArray& arg2, const String& arg3) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Array ___godot_icall_Array_int(godot_method_bind *mb, const Object *inst, const int arg0) {
	Array ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Vector3 ___godot_icall_Vector3_int_int_int(godot_method_bind *mb, const Object *inst, const int arg0, const int arg1, const int arg2) {
	Vector3 ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
PoolStringArray ___godot_icall_PoolStringArray_Object(godot_method_bind *mb, const Object *inst, const Object *arg0) {
	PoolStringArray ret;
	const void *args[] = {
		(void *) arg0->_owner,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
RID ___godot_icall_RID_int_int_float(godot_method_bind *mb, const Object *inst, const int arg0, const int arg1, const double arg2) {
	RID ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_Object_AABB(godot_method_bind *mb, const Object *inst, const Object *arg0, const AABB& arg1) {
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_RID_String_Variant(godot_method_bind *mb, const Object *inst, const RID& arg0, const String& arg1, const Variant& arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_RID_int_int_bool(godot_method_bind *mb, const Object *inst, const RID& arg0, const int arg1, const int arg2, const bool arg3) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_String_int_int_int(godot_method_bind *mb, const Object *inst, const String& arg0, const int arg1, const int arg2, const int arg3) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Variant ___godot_icall_Variant_Object_String(godot_method_bind *mb, const Object *inst, const Object *arg0, const String& arg1) {
	Variant ret;
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
PoolStringArray ___godot_icall_PoolStringArray(godot_method_bind *mb, const Object *inst) {
	PoolStringArray ret;
	const void *args[1] = {
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Object *___godot_icall_Object_Object_String(godot_method_bind *mb, const Object *inst, const Object *arg0, const String& arg1) {
	godot_object *ret;
	ret = nullptr;
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, ret);
}
int64_t ___godot_icall_int_Object_Transform2D_Object(godot_method_bind *mb, const Object *inst, const Object *arg0, const Transform2D& arg1, const Object *arg2) {
	int64_t ret;
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
		(void *) arg2->_owner,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_int_String_Variant(godot_method_bind *mb, const Object *inst, const int arg0, const String& arg1, const Variant& arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_String_PoolStringArray(godot_method_bind *mb, const Object *inst, const String& arg0, const PoolStringArray& arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
PoolVector3Array ___godot_icall_PoolVector3Array_Vector3_Vector3_Vector3_Vector3(godot_method_bind *mb, const Object *inst, const Vector3& arg0, const Vector3& arg1, const Vector3& arg2, const Vector3& arg3) {
	PoolVector3Array ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_PoolVector2Array_int(godot_method_bind *mb, const Object *inst, const PoolVector2Array& arg0, const int arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
double ___godot_icall_float_RID(godot_method_bind *mb, const Object *inst, const RID& arg0) {
	double ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
double ___godot_icall_float_String_String(godot_method_bind *mb, const Object *inst, const String& arg0, const String& arg1) {
	double ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Color ___godot_icall_Color_RID_int(godot_method_bind *mb, const Object *inst, const RID& arg0, const int arg1) {
	Color ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Dictionary ___godot_icall_Dictionary_Vector2_Vector2_Array_int(godot_method_bind *mb, const Object *inst, const Vector2& arg0, const Vector2& arg1, const Array& arg2, const int arg3) {
	Dictionary ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_String_String(godot_method_bind *mb, const Object *inst, const String& arg0, const String& arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Array ___godot_icall_Array_Array_RID(godot_method_bind *mb, const Object *inst, const Array& arg0, const RID& arg1) {
	Array ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
PoolVector3Array ___godot_icall_PoolVector3Array_int_int(godot_method_bind *mb, const Object *inst, const int arg0, const int arg1) {
	PoolVector3Array ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
bool ___godot_icall_bool(godot_method_bind *mb, const Object *inst) {
	bool ret;
	const void *args[1] = {
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
int64_t ___godot_icall_int_RID_int(godot_method_bind *mb, const Object *inst, const RID& arg0, const int arg1) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Vector2 ___godot_icall_Vector2_Vector2_Vector2_bool_float_int_float(godot_method_bind *mb, const Object *inst, const Vector2& arg0, const Vector2& arg1, const bool arg2, const double arg3, const int arg4, const double arg5) {
	Vector2 ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
		(void *) &arg5,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
PoolByteArray ___godot_icall_PoolByteArray_RID(godot_method_bind *mb, const Object *inst, const RID& arg0) {
	PoolByteArray ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Object *___godot_icall_Object_String_String_bool(godot_method_bind *mb, const Object *inst, const String& arg0, const String& arg1, const bool arg2) {
	godot_object *ret;
	ret = nullptr;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, ret);
}
bool ___godot_icall_bool_bool(godot_method_bind *mb, const Object *inst, const bool arg0) {
	bool ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Dictionary ___godot_icall_Dictionary_Object(godot_method_bind *mb, const Object *inst, const Object *arg0) {
	Dictionary ret;
	const void *args[] = {
		(void *) arg0->_owner,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_float_bool(godot_method_bind *mb, const Object *inst, const double arg0, const bool arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_RID_RID_Transform(godot_method_bind *mb, const Object *inst, const RID& arg0, const RID& arg1, const Transform& arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
NodePath ___godot_icall_NodePath_Object(godot_method_bind *mb, const Object *inst, const Object *arg0) {
	NodePath ret;
	const void *args[] = {
		(void *) arg0->_owner,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_int_int_Variant(godot_method_bind *mb, const Object *inst, const int arg0, const int arg1, const Variant& arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Vector2 ___godot_icall_Vector2_Vector2(godot_method_bind *mb, const Object *inst, const Vector2& arg0) {
	Vector2 ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
int64_t ___godot_icall_int_Vector2_bool(godot_method_bind *mb, const Object *inst, const Vector2& arg0, const bool arg1) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
double ___godot_icall_float_Object_Vector2_String_String_Color(godot_method_bind *mb, const Object *inst, const Object *arg0, const Vector2& arg1, const String& arg2, const String& arg3, const Color& arg4) {
	double ret;
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
bool ___godot_icall_bool_RID_int_int(godot_method_bind *mb, const Object *inst, const RID& arg0, const int arg1, const int arg2) {
	bool ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_Vector3_Vector3_Vector3_int(godot_method_bind *mb, const Object *inst, const Vector3& arg0, const Vector3& arg1, const Vector3& arg2, const int arg3) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Array ___godot_icall_Array_Vector3_Vector3_RID(godot_method_bind *mb, const Object *inst, const Vector3& arg0, const Vector3& arg1, const RID& arg2) {
	Array ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_PoolStringArray_int(godot_method_bind *mb, const Object *inst, const PoolStringArray& arg0, const int arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_RID_RID_Transform2D(godot_method_bind *mb, const Object *inst, const RID& arg0, const RID& arg1, const Transform2D& arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_RID_RID(godot_method_bind *mb, const Object *inst, const RID& arg0, const RID& arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_RID_Rect2_Rect2_RID_Vector2_Vector2_int_int_bool_Color_RID(godot_method_bind *mb, const Object *inst, const RID& arg0, const Rect2& arg1, const Rect2& arg2, const RID& arg3, const Vector2& arg4, const Vector2& arg5, const int arg6, const int arg7, const bool arg8, const Color& arg9, const RID& arg10) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
		(void *) &arg5,
		(void *) &arg6,
		(void *) &arg7,
		(void *) &arg8,
		(void *) &arg9,
		(void *) &arg10,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_PoolVector3Array_Object_bool(godot_method_bind *mb, const Object *inst, const PoolVector3Array& arg0, const Object *arg1, const bool arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) arg1->_owner,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Variant ___godot_icall_Variant_Array_Array_int_Array(godot_method_bind *mb, const Object *inst, const Array& arg0, const Array& arg1, const int arg2, const Array& arg3) {
	Variant ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_int_PoolRealArray(godot_method_bind *mb, const Object *inst, const int arg0, const PoolRealArray& arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Array ___godot_icall_Array_float_float_int_int(godot_method_bind *mb, const Object *inst, const double arg0, const double arg1, const int arg2, const int arg3) {
	Array ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_int_int_float_bool(godot_method_bind *mb, const Object *inst, const int arg0, const int arg1, const double arg2, const bool arg3) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_Variant(godot_method_bind *mb, const Object *inst, const Variant& arg0) {
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
bool ___godot_icall_bool_Vector2(godot_method_bind *mb, const Object *inst, const Vector2& arg0) {
	bool ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Plane ___godot_icall_Plane_int(godot_method_bind *mb, const Object *inst, const int arg0) {
	Plane ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
int64_t ___godot_icall_int_String_PoolStringArray_bool_Array(godot_method_bind *mb, const Object *inst, const String& arg0, const PoolStringArray& arg1, const bool arg2, const Array& arg3) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_int_int_bool_int_PoolByteArray(godot_method_bind *mb, const Object *inst, const int arg0, const int arg1, const bool arg2, const int arg3, const PoolByteArray& arg4) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_String_Object_int(godot_method_bind *mb, const Object *inst, const String& arg0, const Object *arg1, const int arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) arg1->_owner,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
bool ___godot_icall_bool_Object(godot_method_bind *mb, const Object *inst, const Object *arg0) {
	bool ret;
	const void *args[] = {
		(void *) arg0->_owner,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_int_bool(godot_method_bind *mb, const Object *inst, const int arg0, const bool arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_int_int_Rect2_Vector2_float(godot_method_bind *mb, const Object *inst, const int arg0, const int arg1, const Rect2& arg2, const Vector2& arg3, const double arg4) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_int_float_float_bool(godot_method_bind *mb, const Object *inst, const int arg0, const double arg1, const double arg2, const bool arg3) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_String_int_int_int_int(godot_method_bind *mb, const Object *inst, const String& arg0, const int arg1, const int arg2, const int arg3, const int arg4) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_String_String_Color(godot_method_bind *mb, const Object *inst, const String& arg0, const String& arg1, const Color& arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
bool ___godot_icall_bool_NodePath(godot_method_bind *mb, const Object *inst, const NodePath& arg0) {
	bool ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
int64_t ___godot_icall_int_String_int_int(godot_method_bind *mb, const Object *inst, const String& arg0, const int arg1, const int arg2) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
RID ___godot_icall_RID_Vector2_Vector2_RID_RID(godot_method_bind *mb, const Object *inst, const Vector2& arg0, const Vector2& arg1, const RID& arg2, const RID& arg3) {
	RID ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_int_Rect2(godot_method_bind *mb, const Object *inst, const int arg0, const Rect2& arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
PoolStringArray ___godot_icall_PoolStringArray_String_bool(godot_method_bind *mb, const Object *inst, const String& arg0, const bool arg1) {
	PoolStringArray ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Transform ___godot_icall_Transform_bool(godot_method_bind *mb, const Object *inst, const bool arg0) {
	Transform ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Array ___godot_icall_Array(godot_method_bind *mb, const Object *inst) {
	Array ret;
	const void *args[1] = {
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Transform2D ___godot_icall_Transform2D_int_int(godot_method_bind *mb, const Object *inst, const int arg0, const int arg1) {
	Transform2D ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_RID_int_int(godot_method_bind *mb, const Object *inst, const RID& arg0, const int arg1, const int arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
int64_t ___godot_icall_int_bool_bool(godot_method_bind *mb, const Object *inst, const bool arg0, const bool arg1) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_int_String_int(godot_method_bind *mb, const Object *inst, const int arg0, const String& arg1, const int arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_int_Object_Vector2(godot_method_bind *mb, const Object *inst, const int arg0, const Object *arg1, const Vector2& arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) arg1->_owner,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_Object_Object_Object(godot_method_bind *mb, const Object *inst, const Object *arg0, const Object *arg1, const Object *arg2) {
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) arg1->_owner,
		(void *) arg2->_owner,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_RID_Object_int(godot_method_bind *mb, const Object *inst, const RID& arg0, const Object *arg1, const int arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) arg1->_owner,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Object *___godot_icall_Object(godot_method_bind *mb, const Object *inst) {
	godot_object *ret;
	ret = nullptr;
	const void *args[1] = {
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, ret);
}
Dictionary ___godot_icall_Dictionary_String_String(godot_method_bind *mb, const Object *inst, const String& arg0, const String& arg1) {
	Dictionary ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
int64_t ___godot_icall_int_Object_String_Variant(godot_method_bind *mb, const Object *inst, const Object *arg0, const String& arg1, const Variant& arg2) {
	int64_t ret;
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_String_Object_bool(godot_method_bind *mb, const Object *inst, const String& arg0, const Object *arg1, const bool arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) arg1->_owner,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
PoolStringArray ___godot_icall_PoolStringArray_int(godot_method_bind *mb, const Object *inst, const int arg0) {
	PoolStringArray ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_int_Vector3(godot_method_bind *mb, const Object *inst, const int arg0, const Vector3& arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
int64_t ___godot_icall_int_RID(godot_method_bind *mb, const Object *inst, const RID& arg0) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void(godot_method_bind *mb, const Object *inst) {
	const void *args[1] = {
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
int64_t ___godot_icall_int(godot_method_bind *mb, const Object *inst) {
	int64_t ret;
	const void *args[1] = {
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
PoolVector2Array ___godot_icall_PoolVector2Array(godot_method_bind *mb, const Object *inst) {
	PoolVector2Array ret;
	const void *args[1] = {
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Vector2 ___godot_icall_Vector2_Vector3(godot_method_bind *mb, const Object *inst, const Vector3& arg0) {
	Vector2 ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_RID_int_int_int_int(godot_method_bind *mb, const Object *inst, const RID& arg0, const int arg1, const int arg2, const int arg3, const int arg4) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Object *___godot_icall_Object_Vector2_bool(godot_method_bind *mb, const Object *inst, const Vector2& arg0, const bool arg1) {
	godot_object *ret;
	ret = nullptr;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, ret);
}
PoolVector2Array ___godot_icall_PoolVector2Array_int(godot_method_bind *mb, const Object *inst, const int arg0) {
	PoolVector2Array ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Variant ___godot_icall_Variant_String_String_Array(godot_method_bind *mb, const Object *inst, const String& arg0, const String& arg1, const Array& arg2) {
	Variant ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_String_Vector2(godot_method_bind *mb, const Object *inst, const String& arg0, const Vector2& arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_int_Array_Array_int(godot_method_bind *mb, const Object *inst, const int arg0, const Array& arg1, const Array& arg2, const int arg3) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
bool ___godot_icall_bool_String_String(godot_method_bind *mb, const Object *inst, const String& arg0, const String& arg1) {
	bool ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_RID_PoolVector2Array_PoolColorArray_PoolVector2Array_RID_RID_bool(godot_method_bind *mb, const Object *inst, const RID& arg0, const PoolVector2Array& arg1, const PoolColorArray& arg2, const PoolVector2Array& arg3, const RID& arg4, const RID& arg5, const bool arg6) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
		(void *) &arg5,
		(void *) &arg6,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
double ___godot_icall_float_Vector2(godot_method_bind *mb, const Object *inst, const Vector2& arg0) {
	double ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_Vector2(godot_method_bind *mb, const Object *inst, const Vector2& arg0) {
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
String ___godot_icall_String_int(godot_method_bind *mb, const Object *inst, const int arg0) {
	String ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
bool ___godot_icall_bool_Vector3(godot_method_bind *mb, const Object *inst, const Vector3& arg0) {
	bool ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
bool ___godot_icall_bool_String_int(godot_method_bind *mb, const Object *inst, const String& arg0, const int arg1) {
	bool ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_int_Vector3_float(godot_method_bind *mb, const Object *inst, const int arg0, const Vector3& arg1, const double arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_String_Object_Variant(godot_method_bind *mb, const Object *inst, const String& arg0, const Object *arg1, const Variant& arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) arg1->_owner,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_RID_RID_RID(godot_method_bind *mb, const Object *inst, const RID& arg0, const RID& arg1, const RID& arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_RID_int_Transform(godot_method_bind *mb, const Object *inst, const RID& arg0, const int arg1, const Transform& arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_int_int_PoolByteArray(godot_method_bind *mb, const Object *inst, const int arg0, const int arg1, const PoolByteArray& arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Object *___godot_icall_Object_Vector2(godot_method_bind *mb, const Object *inst, const Vector2& arg0) {
	godot_object *ret;
	ret = nullptr;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, ret);
}
Vector3 ___godot_icall_Vector3_int(godot_method_bind *mb, const Object *inst, const int arg0) {
	Vector3 ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_RID_int_bool(godot_method_bind *mb, const Object *inst, const RID& arg0, const int arg1, const bool arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_PoolColorArray(godot_method_bind *mb, const Object *inst, const PoolColorArray& arg0) {
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
bool ___godot_icall_bool_Transform2D_Vector2_Object_Transform2D_Vector2(godot_method_bind *mb, const Object *inst, const Transform2D& arg0, const Vector2& arg1, const Object *arg2, const Transform2D& arg3, const Vector2& arg4) {
	bool ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) arg2->_owner,
		(void *) &arg3,
		(void *) &arg4,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_NodePath_Object_int(godot_method_bind *mb, const Object *inst, const NodePath& arg0, const Object *arg1, const int arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) arg1->_owner,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Array ___godot_icall_Array_String_bool(godot_method_bind *mb, const Object *inst, const String& arg0, const bool arg1) {
	Array ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Transform2D ___godot_icall_Transform2D_Object(godot_method_bind *mb, const Object *inst, const Object *arg0) {
	Transform2D ret;
	const void *args[] = {
		(void *) arg0->_owner,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
double ___godot_icall_float_Vector2_Vector2_Vector2_float(godot_method_bind *mb, const Object *inst, const Vector2& arg0, const Vector2& arg1, const Vector2& arg2, const double arg3) {
	double ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_RID_int_Transform2D(godot_method_bind *mb, const Object *inst, const RID& arg0, const int arg1, const Transform2D& arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
int64_t ___godot_icall_int_String_PoolStringArray_bool(godot_method_bind *mb, const Object *inst, const String& arg0, const PoolStringArray& arg1, const bool arg2) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
AABB ___godot_icall_AABB(godot_method_bind *mb, const Object *inst) {
	AABB ret;
	const void *args[1] = {
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
int64_t ___godot_icall_int_int_float(godot_method_bind *mb, const Object *inst, const int arg0, const double arg1) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_Vector3_Vector3_Vector3(godot_method_bind *mb, const Object *inst, const Vector3& arg0, const Vector3& arg1, const Vector3& arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_int_PoolVector2Array(godot_method_bind *mb, const Object *inst, const int arg0, const PoolVector2Array& arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Vector3 ___godot_icall_Vector3_RID(godot_method_bind *mb, const Object *inst, const RID& arg0) {
	Vector3 ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Transform2D ___godot_icall_Transform2D_int(godot_method_bind *mb, const Object *inst, const int arg0) {
	Transform2D ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
int64_t ___godot_icall_int_int_int_int(godot_method_bind *mb, const Object *inst, const int arg0, const int arg1, const int arg2) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_int_int_int_int(godot_method_bind *mb, const Object *inst, const int arg0, const int arg1, const int arg2, const int arg3) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
double ___godot_icall_float_int_int(godot_method_bind *mb, const Object *inst, const int arg0, const int arg1) {
	double ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_int_Object_Transform2D_bool_Vector2(godot_method_bind *mb, const Object *inst, const int arg0, const Object *arg1, const Transform2D& arg2, const bool arg3, const Vector2& arg4) {
	const void *args[] = {
		(void *) &arg0,
		(void *) arg1->_owner,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Object *___godot_icall_Object_String_int_int(godot_method_bind *mb, const Object *inst, const String& arg0, const int arg1, const int arg2) {
	godot_object *ret;
	ret = nullptr;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, ret);
}
Color ___godot_icall_Color(godot_method_bind *mb, const Object *inst) {
	Color ret;
	const void *args[1] = {
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
String ___godot_icall_String_Variant_String_bool(godot_method_bind *mb, const Object *inst, const Variant& arg0, const String& arg1, const bool arg2) {
	String ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
NodePath ___godot_icall_NodePath_int(godot_method_bind *mb, const Object *inst, const int arg0) {
	NodePath ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
int64_t ___godot_icall_int_int_float_Vector3_Quat_Vector3(godot_method_bind *mb, const Object *inst, const int arg0, const double arg1, const Vector3& arg2, const Quat& arg3, const Vector3& arg4) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
int64_t ___godot_icall_int_int_float_bool(godot_method_bind *mb, const Object *inst, const int arg0, const double arg1, const bool arg2) {
	int64_t ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Vector3 ___godot_icall_Vector3_float_bool(godot_method_bind *mb, const Object *inst, const double arg0, const bool arg1) {
	Vector3 ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_Object_String_PoolStringArray(godot_method_bind *mb, const Object *inst, const Object *arg0, const String& arg1, const PoolStringArray& arg2) {
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_String_PoolByteArray_bool(godot_method_bind *mb, const Object *inst, const String& arg0, const PoolByteArray& arg1, const bool arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
bool ___godot_icall_bool_RID(godot_method_bind *mb, const Object *inst, const RID& arg0) {
	bool ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_String_String_PoolStringArray(godot_method_bind *mb, const Object *inst, const String& arg0, const String& arg1, const PoolStringArray& arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_String_Array(godot_method_bind *mb, const Object *inst, const String& arg0, const Array& arg1) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Transform ___godot_icall_Transform(godot_method_bind *mb, const Object *inst) {
	Transform ret;
	const void *args[1] = {
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
PoolByteArray ___godot_icall_PoolByteArray(godot_method_bind *mb, const Object *inst) {
	PoolByteArray ret;
	const void *args[1] = {
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
bool ___godot_icall_bool_Object_NodePath_Variant_Object_NodePath_float_int_int_float(godot_method_bind *mb, const Object *inst, const Object *arg0, const NodePath& arg1, const Variant& arg2, const Object *arg3, const NodePath& arg4, const double arg5, const int arg6, const int arg7, const double arg8) {
	bool ret;
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
		(void *) &arg2,
		(void *) arg3->_owner,
		(void *) &arg4,
		(void *) &arg5,
		(void *) &arg6,
		(void *) &arg7,
		(void *) &arg8,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_RID_Rect2_bool_Color_bool_Object(godot_method_bind *mb, const Object *inst, const RID& arg0, const Rect2& arg1, const bool arg2, const Color& arg3, const bool arg4, const Object *arg5) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
		(void *) arg5->_owner,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_String_float_float_bool(godot_method_bind *mb, const Object *inst, const String& arg0, const double arg1, const double arg2, const bool arg3) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_RID_bool_int_float_float_float_int_float_float_bool(godot_method_bind *mb, const Object *inst, const RID& arg0, const bool arg1, const int arg2, const double arg3, const double arg4, const double arg5, const int arg6, const double arg7, const double arg8, const bool arg9) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
		(void *) &arg5,
		(void *) &arg6,
		(void *) &arg7,
		(void *) &arg8,
		(void *) &arg9,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_String_String_Variant(godot_method_bind *mb, const Object *inst, const String& arg0, const String& arg1, const Variant& arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Rect2 ___godot_icall_Rect2(godot_method_bind *mb, const Object *inst) {
	Rect2 ret;
	const void *args[1] = {
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Dictionary ___godot_icall_Dictionary_bool(godot_method_bind *mb, const Object *inst, const bool arg0) {
	Dictionary ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
PoolVector2Array ___godot_icall_PoolVector2Array_Vector2_Vector2(godot_method_bind *mb, const Object *inst, const Vector2& arg0, const Vector2& arg1) {
	PoolVector2Array ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Basis ___godot_icall_Basis(godot_method_bind *mb, const Object *inst) {
	Basis ret;
	const void *args[1] = {
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Vector3 ___godot_icall_Vector3_Vector2(godot_method_bind *mb, const Object *inst, const Vector2& arg0) {
	Vector3 ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
bool ___godot_icall_bool_Vector2_Variant_Object(godot_method_bind *mb, const Object *inst, const Vector2& arg0, const Variant& arg1, const Object *arg2) {
	bool ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) arg2->_owner,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_Object_bool_RID(godot_method_bind *mb, const Object *inst, const Object *arg0, const bool arg1, const RID& arg2) {
	const void *args[] = {
		(void *) arg0->_owner,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_RID_int_Variant(godot_method_bind *mb, const Object *inst, const RID& arg0, const int arg1, const Variant& arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
Dictionary ___godot_icall_Dictionary(godot_method_bind *mb, const Object *inst) {
	Dictionary ret;
	const void *args[1] = {
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
void ___godot_icall_void_RID_bool_Color_Color_float(godot_method_bind *mb, const Object *inst, const RID& arg0, const bool arg1, const Color& arg2, const Color& arg3, const double arg4) {
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
void ___godot_icall_void_RID_Object_String(godot_method_bind *mb, const Object *inst, const RID& arg0, const Object *arg1, const String& arg2) {
	const void *args[] = {
		(void *) &arg0,
		(void *) arg1->_owner,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, nullptr);
}
String ___godot_icall_String_PoolByteArray(godot_method_bind *mb, const Object *inst, const PoolByteArray& arg0) {
	String ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
double ___godot_icall_float_float(godot_method_bind *mb, const Object *inst, const double arg0) {
	double ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Variant ___godot_icall_Variant_Vector3_Vector3_Vector3_Vector3_Vector3(godot_method_bind *mb, const Object *inst, const Vector3& arg0, const Vector3& arg1, const Vector3& arg2, const Vector3& arg3, const Vector3& arg4) {
	Variant ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
		(void *) &arg3,
		(void *) &arg4,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
bool ___godot_icall_bool_Transform_Vector3_bool(godot_method_bind *mb, const Object *inst, const Transform& arg0, const Vector3& arg1, const bool arg2) {
	bool ret;
	const void *args[] = {
		(void *) &arg0,
		(void *) &arg1,
		(void *) &arg2,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
String ___godot_icall_String_RID(godot_method_bind *mb, const Object *inst, const RID& arg0) {
	String ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
PoolByteArray ___godot_icall_PoolByteArray_String(godot_method_bind *mb, const Object *inst, const String& arg0) {
	PoolByteArray ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
Array ___godot_icall_Array_String(godot_method_bind *mb, const Object *inst, const String& arg0) {
	Array ret;
	const void *args[] = {
		(void *) &arg0,
	};

	godot::api->godot_method_bind_ptrcall(mb, inst->_owner, args, &ret);
	return ret;
}
}
