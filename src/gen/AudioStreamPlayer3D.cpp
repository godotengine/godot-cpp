#include <AudioStreamPlayer3D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <AudioStream.hpp>


namespace godot {


void *AudioStreamPlayer3D::___get_type_tag()
{
	return (void *) &AudioStreamPlayer3D::___get_type_tag;
}

void *AudioStreamPlayer3D::___get_base_type_tag()
{
	return (void *) &Spatial::___get_type_tag;
}

AudioStreamPlayer3D *AudioStreamPlayer3D::_new()
{
	return (AudioStreamPlayer3D *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"AudioStreamPlayer3D")());
}
void AudioStreamPlayer3D::set_stream(const Ref<AudioStream> stream) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer3D", "set_stream");
	}
	___godot_icall_void_Object(mb, (const Object *) this, stream.ptr());
}

Ref<AudioStream> AudioStreamPlayer3D::get_stream() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer3D", "get_stream");
	}
	return Ref<AudioStream>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void AudioStreamPlayer3D::set_unit_db(const double unit_db) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer3D", "set_unit_db");
	}
	___godot_icall_void_float(mb, (const Object *) this, unit_db);
}

double AudioStreamPlayer3D::get_unit_db() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer3D", "get_unit_db");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioStreamPlayer3D::set_unit_size(const double unit_size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer3D", "set_unit_size");
	}
	___godot_icall_void_float(mb, (const Object *) this, unit_size);
}

double AudioStreamPlayer3D::get_unit_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer3D", "get_unit_size");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioStreamPlayer3D::set_max_db(const double max_db) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer3D", "set_max_db");
	}
	___godot_icall_void_float(mb, (const Object *) this, max_db);
}

double AudioStreamPlayer3D::get_max_db() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer3D", "get_max_db");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioStreamPlayer3D::set_pitch_scale(const double pitch_scale) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer3D", "set_pitch_scale");
	}
	___godot_icall_void_float(mb, (const Object *) this, pitch_scale);
}

double AudioStreamPlayer3D::get_pitch_scale() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer3D", "get_pitch_scale");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioStreamPlayer3D::play(const double from_position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer3D", "play");
	}
	___godot_icall_void_float(mb, (const Object *) this, from_position);
}

void AudioStreamPlayer3D::seek(const double to_position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer3D", "seek");
	}
	___godot_icall_void_float(mb, (const Object *) this, to_position);
}

void AudioStreamPlayer3D::stop() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer3D", "stop");
	}
	___godot_icall_void(mb, (const Object *) this);
}

bool AudioStreamPlayer3D::is_playing() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer3D", "is_playing");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

double AudioStreamPlayer3D::get_playback_position() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer3D", "get_playback_position");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioStreamPlayer3D::set_bus(const String bus) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer3D", "set_bus");
	}
	___godot_icall_void_String(mb, (const Object *) this, bus);
}

String AudioStreamPlayer3D::get_bus() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer3D", "get_bus");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void AudioStreamPlayer3D::set_autoplay(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer3D", "set_autoplay");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool AudioStreamPlayer3D::is_autoplay_enabled() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer3D", "is_autoplay_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void AudioStreamPlayer3D::_set_playing(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer3D", "_set_playing");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool AudioStreamPlayer3D::_is_active() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer3D", "_is_active");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void AudioStreamPlayer3D::set_max_distance(const double metres) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer3D", "set_max_distance");
	}
	___godot_icall_void_float(mb, (const Object *) this, metres);
}

double AudioStreamPlayer3D::get_max_distance() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer3D", "get_max_distance");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioStreamPlayer3D::set_area_mask(const int64_t mask) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer3D", "set_area_mask");
	}
	___godot_icall_void_int(mb, (const Object *) this, mask);
}

int64_t AudioStreamPlayer3D::get_area_mask() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer3D", "get_area_mask");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void AudioStreamPlayer3D::set_emission_angle(const double degrees) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer3D", "set_emission_angle");
	}
	___godot_icall_void_float(mb, (const Object *) this, degrees);
}

double AudioStreamPlayer3D::get_emission_angle() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer3D", "get_emission_angle");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioStreamPlayer3D::set_emission_angle_enabled(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer3D", "set_emission_angle_enabled");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool AudioStreamPlayer3D::is_emission_angle_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer3D", "is_emission_angle_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void AudioStreamPlayer3D::set_emission_angle_filter_attenuation_db(const double db) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer3D", "set_emission_angle_filter_attenuation_db");
	}
	___godot_icall_void_float(mb, (const Object *) this, db);
}

double AudioStreamPlayer3D::get_emission_angle_filter_attenuation_db() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer3D", "get_emission_angle_filter_attenuation_db");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioStreamPlayer3D::set_attenuation_filter_cutoff_hz(const double degrees) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer3D", "set_attenuation_filter_cutoff_hz");
	}
	___godot_icall_void_float(mb, (const Object *) this, degrees);
}

double AudioStreamPlayer3D::get_attenuation_filter_cutoff_hz() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer3D", "get_attenuation_filter_cutoff_hz");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioStreamPlayer3D::set_attenuation_filter_db(const double db) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer3D", "set_attenuation_filter_db");
	}
	___godot_icall_void_float(mb, (const Object *) this, db);
}

double AudioStreamPlayer3D::get_attenuation_filter_db() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer3D", "get_attenuation_filter_db");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioStreamPlayer3D::set_attenuation_model(const int64_t model) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer3D", "set_attenuation_model");
	}
	___godot_icall_void_int(mb, (const Object *) this, model);
}

AudioStreamPlayer3D::AttenuationModel AudioStreamPlayer3D::get_attenuation_model() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer3D", "get_attenuation_model");
	}
	return (AudioStreamPlayer3D::AttenuationModel) ___godot_icall_int(mb, (const Object *) this);
}

void AudioStreamPlayer3D::set_out_of_range_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer3D", "set_out_of_range_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

AudioStreamPlayer3D::OutOfRangeMode AudioStreamPlayer3D::get_out_of_range_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer3D", "get_out_of_range_mode");
	}
	return (AudioStreamPlayer3D::OutOfRangeMode) ___godot_icall_int(mb, (const Object *) this);
}

void AudioStreamPlayer3D::set_doppler_tracking(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer3D", "set_doppler_tracking");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

AudioStreamPlayer3D::DopplerTracking AudioStreamPlayer3D::get_doppler_tracking() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer3D", "get_doppler_tracking");
	}
	return (AudioStreamPlayer3D::DopplerTracking) ___godot_icall_int(mb, (const Object *) this);
}

void AudioStreamPlayer3D::_bus_layout_changed() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer3D", "_bus_layout_changed");
	}
	___godot_icall_void(mb, (const Object *) this);
}

}