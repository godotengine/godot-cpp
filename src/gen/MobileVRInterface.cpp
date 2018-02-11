#include <MobileVRInterface.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


MobileVRInterface *MobileVRInterface::_new()
{
	return (MobileVRInterface *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"MobileVRInterface")());
}
void MobileVRInterface::set_iod(const double iod) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MobileVRInterface", "set_iod");
	}
	___godot_icall_void_float(mb, (const Object *) this, iod);
}

double MobileVRInterface::get_iod() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MobileVRInterface", "get_iod");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void MobileVRInterface::set_display_width(const double display_width) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MobileVRInterface", "set_display_width");
	}
	___godot_icall_void_float(mb, (const Object *) this, display_width);
}

double MobileVRInterface::get_display_width() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MobileVRInterface", "get_display_width");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void MobileVRInterface::set_display_to_lens(const double display_to_lens) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MobileVRInterface", "set_display_to_lens");
	}
	___godot_icall_void_float(mb, (const Object *) this, display_to_lens);
}

double MobileVRInterface::get_display_to_lens() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MobileVRInterface", "get_display_to_lens");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void MobileVRInterface::set_oversample(const double oversample) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MobileVRInterface", "set_oversample");
	}
	___godot_icall_void_float(mb, (const Object *) this, oversample);
}

double MobileVRInterface::get_oversample() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MobileVRInterface", "get_oversample");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void MobileVRInterface::set_k1(const double k) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MobileVRInterface", "set_k1");
	}
	___godot_icall_void_float(mb, (const Object *) this, k);
}

double MobileVRInterface::get_k1() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MobileVRInterface", "get_k1");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void MobileVRInterface::set_k2(const double k) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MobileVRInterface", "set_k2");
	}
	___godot_icall_void_float(mb, (const Object *) this, k);
}

double MobileVRInterface::get_k2() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MobileVRInterface", "get_k2");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

}