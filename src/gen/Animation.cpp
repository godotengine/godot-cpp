#include <Animation.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Animation.hpp>


namespace godot {


void *Animation::___get_type_tag()
{
	return (void *) &Animation::___get_type_tag;
}

void *Animation::___get_base_type_tag()
{
	return (void *) &Resource::___get_type_tag;
}

Animation *Animation::_new()
{
	return (Animation *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Animation")());
}
int64_t Animation::add_track(const int64_t type, const int64_t at_position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Animation", "add_track");
	}
	return ___godot_icall_int_int_int(mb, (const Object *) this, type, at_position);
}

void Animation::remove_track(const int64_t idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Animation", "remove_track");
	}
	___godot_icall_void_int(mb, (const Object *) this, idx);
}

int64_t Animation::get_track_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Animation", "get_track_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

Animation::TrackType Animation::track_get_type(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Animation", "track_get_type");
	}
	return (Animation::TrackType) ___godot_icall_int_int(mb, (const Object *) this, idx);
}

NodePath Animation::track_get_path(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Animation", "track_get_path");
	}
	return ___godot_icall_NodePath_int(mb, (const Object *) this, idx);
}

void Animation::track_set_path(const int64_t idx, const NodePath path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Animation", "track_set_path");
	}
	___godot_icall_void_int_NodePath(mb, (const Object *) this, idx, path);
}

int64_t Animation::find_track(const NodePath path) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Animation", "find_track");
	}
	return ___godot_icall_int_NodePath(mb, (const Object *) this, path);
}

void Animation::track_move_up(const int64_t idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Animation", "track_move_up");
	}
	___godot_icall_void_int(mb, (const Object *) this, idx);
}

void Animation::track_move_down(const int64_t idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Animation", "track_move_down");
	}
	___godot_icall_void_int(mb, (const Object *) this, idx);
}

void Animation::track_set_imported(const int64_t idx, const bool imported) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Animation", "track_set_imported");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, idx, imported);
}

bool Animation::track_is_imported(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Animation", "track_is_imported");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, idx);
}

void Animation::track_set_enabled(const int64_t idx, const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Animation", "track_set_enabled");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, idx, enabled);
}

bool Animation::track_is_enabled(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Animation", "track_is_enabled");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, idx);
}

int64_t Animation::transform_track_insert_key(const int64_t idx, const double time, const Vector3 location, const Quat rotation, const Vector3 scale) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Animation", "transform_track_insert_key");
	}
	return ___godot_icall_int_int_float_Vector3_Quat_Vector3(mb, (const Object *) this, idx, time, location, rotation, scale);
}

void Animation::track_insert_key(const int64_t idx, const double time, const Variant key, const double transition) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Animation", "track_insert_key");
	}
	___godot_icall_void_int_float_Variant_float(mb, (const Object *) this, idx, time, key, transition);
}

void Animation::track_remove_key(const int64_t idx, const int64_t key_idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Animation", "track_remove_key");
	}
	___godot_icall_void_int_int(mb, (const Object *) this, idx, key_idx);
}

void Animation::track_remove_key_at_position(const int64_t idx, const double position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Animation", "track_remove_key_at_position");
	}
	___godot_icall_void_int_float(mb, (const Object *) this, idx, position);
}

void Animation::track_set_key_value(const int64_t idx, const int64_t key, const Variant value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Animation", "track_set_key_value");
	}
	___godot_icall_void_int_int_Variant(mb, (const Object *) this, idx, key, value);
}

void Animation::track_set_key_transition(const int64_t idx, const int64_t key_idx, const double transition) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Animation", "track_set_key_transition");
	}
	___godot_icall_void_int_int_float(mb, (const Object *) this, idx, key_idx, transition);
}

double Animation::track_get_key_transition(const int64_t idx, const int64_t key_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Animation", "track_get_key_transition");
	}
	return ___godot_icall_float_int_int(mb, (const Object *) this, idx, key_idx);
}

int64_t Animation::track_get_key_count(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Animation", "track_get_key_count");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, idx);
}

Variant Animation::track_get_key_value(const int64_t idx, const int64_t key_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Animation", "track_get_key_value");
	}
	return ___godot_icall_Variant_int_int(mb, (const Object *) this, idx, key_idx);
}

double Animation::track_get_key_time(const int64_t idx, const int64_t key_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Animation", "track_get_key_time");
	}
	return ___godot_icall_float_int_int(mb, (const Object *) this, idx, key_idx);
}

int64_t Animation::track_find_key(const int64_t idx, const double time, const bool exact) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Animation", "track_find_key");
	}
	return ___godot_icall_int_int_float_bool(mb, (const Object *) this, idx, time, exact);
}

void Animation::track_set_interpolation_type(const int64_t idx, const int64_t interpolation) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Animation", "track_set_interpolation_type");
	}
	___godot_icall_void_int_int(mb, (const Object *) this, idx, interpolation);
}

Animation::InterpolationType Animation::track_get_interpolation_type(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Animation", "track_get_interpolation_type");
	}
	return (Animation::InterpolationType) ___godot_icall_int_int(mb, (const Object *) this, idx);
}

void Animation::track_set_interpolation_loop_wrap(const int64_t idx, const bool interpolation) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Animation", "track_set_interpolation_loop_wrap");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, idx, interpolation);
}

bool Animation::track_get_interpolation_loop_wrap(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Animation", "track_get_interpolation_loop_wrap");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, idx);
}

Array Animation::transform_track_interpolate(const int64_t idx, const double time_sec) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Animation", "transform_track_interpolate");
	}
	return ___godot_icall_Array_int_float(mb, (const Object *) this, idx, time_sec);
}

void Animation::value_track_set_update_mode(const int64_t idx, const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Animation", "value_track_set_update_mode");
	}
	___godot_icall_void_int_int(mb, (const Object *) this, idx, mode);
}

Animation::UpdateMode Animation::value_track_get_update_mode(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Animation", "value_track_get_update_mode");
	}
	return (Animation::UpdateMode) ___godot_icall_int_int(mb, (const Object *) this, idx);
}

PoolIntArray Animation::value_track_get_key_indices(const int64_t idx, const double time_sec, const double delta) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Animation", "value_track_get_key_indices");
	}
	return ___godot_icall_PoolIntArray_int_float_float(mb, (const Object *) this, idx, time_sec, delta);
}

PoolIntArray Animation::method_track_get_key_indices(const int64_t idx, const double time_sec, const double delta) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Animation", "method_track_get_key_indices");
	}
	return ___godot_icall_PoolIntArray_int_float_float(mb, (const Object *) this, idx, time_sec, delta);
}

String Animation::method_track_get_name(const int64_t idx, const int64_t key_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Animation", "method_track_get_name");
	}
	return ___godot_icall_String_int_int(mb, (const Object *) this, idx, key_idx);
}

Array Animation::method_track_get_params(const int64_t idx, const int64_t key_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Animation", "method_track_get_params");
	}
	return ___godot_icall_Array_int_int(mb, (const Object *) this, idx, key_idx);
}

void Animation::set_length(const double time_sec) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Animation", "set_length");
	}
	___godot_icall_void_float(mb, (const Object *) this, time_sec);
}

double Animation::get_length() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Animation", "get_length");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Animation::set_loop(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Animation", "set_loop");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool Animation::has_loop() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Animation", "has_loop");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Animation::set_step(const double size_sec) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Animation", "set_step");
	}
	___godot_icall_void_float(mb, (const Object *) this, size_sec);
}

double Animation::get_step() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Animation", "get_step");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Animation::clear() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Animation", "clear");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Animation::copy_track(const int64_t track, const Ref<Animation> to_animation) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Animation", "copy_track");
	}
	___godot_icall_void_int_Object(mb, (const Object *) this, track, to_animation.ptr());
}

}