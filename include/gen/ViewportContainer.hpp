#ifndef GODOT_CPP_VIEWPORTCONTAINER_HPP
#define GODOT_CPP_VIEWPORTCONTAINER_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Container.hpp"
namespace godot {

class InputEvent;

class ViewportContainer : public Container {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "ViewportContainer"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static ViewportContainer *_new();

	// methods
	void _input(const Ref<InputEvent> event);
	void set_stretch(const bool enable);
	bool is_stretch_enabled() const;
	void set_stretch_shrink(const int64_t amount);
	int64_t get_stretch_shrink() const;

};

}

#endif