#ifndef GODOT_CPP_GRIDCONTAINER_HPP
#define GODOT_CPP_GRIDCONTAINER_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Container.hpp"
namespace godot {

class Control;

class GridContainer : public Container {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "GridContainer"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static GridContainer *_new();

	// methods
	void set_columns(const int64_t columns);
	int64_t get_columns() const;
	Control *get_child_control_at_cell(const int64_t row, const int64_t column);

};

}

#endif