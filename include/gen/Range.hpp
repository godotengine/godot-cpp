#ifndef GODOT_CPP_RANGE_HPP
#define GODOT_CPP_RANGE_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Control.hpp"
namespace godot {

class Object;

class Range : public Control {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Range"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants

	// methods
	double get_value() const;
	double get_min() const;
	double get_max() const;
	double get_step() const;
	double get_page() const;
	double get_as_ratio() const;
	void set_value(const double value);
	void set_min(const double minimum);
	void set_max(const double maximum);
	void set_step(const double step);
	void set_page(const double pagesize);
	void set_as_ratio(const double value);
	void set_use_rounded_values(const bool enabled);
	bool is_using_rounded_values() const;
	void set_exp_ratio(const bool enabled);
	bool is_ratio_exp() const;
	void share(const Object *with);
	void unshare();

};

}

#endif