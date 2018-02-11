#ifndef GODOT_CPP_MOBILEVRINTERFACE_HPP
#define GODOT_CPP_MOBILEVRINTERFACE_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <ARVRInterface.hpp>
namespace godot {


class MobileVRInterface : public ARVRInterface {
public:

	static inline const char *___get_class_name() { return (const char *) "MobileVRInterface"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static MobileVRInterface *_new();

	// methods
	void set_iod(const double iod);
	double get_iod() const;
	void set_display_width(const double display_width);
	double get_display_width() const;
	void set_display_to_lens(const double display_to_lens);
	double get_display_to_lens() const;
	void set_oversample(const double oversample);
	double get_oversample() const;
	void set_k1(const double k);
	double get_k1() const;
	void set_k2(const double k);
	double get_k2() const;

};

}

#endif