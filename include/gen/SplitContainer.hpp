#ifndef GODOT_CPP_SPLITCONTAINER_HPP
#define GODOT_CPP_SPLITCONTAINER_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <SplitContainer.hpp>

#include <Container.hpp>
namespace godot {

class InputEvent;

class SplitContainer : public Container {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "SplitContainer"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum DraggerVisibility {
		DRAGGER_VISIBLE = 0,
		DRAGGER_HIDDEN = 1,
		DRAGGER_HIDDEN_COLLAPSED = 2,
	};

	// constants

	// methods
	void _gui_input(const Ref<InputEvent> arg0);
	void set_split_offset(const int64_t offset);
	int64_t get_split_offset() const;
	void set_collapsed(const bool collapsed);
	bool is_collapsed() const;
	void set_dragger_visibility(const int64_t mode);
	SplitContainer::DraggerVisibility get_dragger_visibility() const;

};

}

#endif