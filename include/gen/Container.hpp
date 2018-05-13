#ifndef GODOT_CPP_CONTAINER_HPP
#define GODOT_CPP_CONTAINER_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Control.hpp"
namespace godot {

class Object;

class Container : public Control {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Container"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants
	const static int NOTIFICATION_SORT_CHILDREN = 50;


	static Container *_new();

	// methods
	void _sort_children();
	void _child_minsize_changed();
	void queue_sort();
	void fit_child_in_rect(const Object *child, const Rect2 rect);

};

}

#endif