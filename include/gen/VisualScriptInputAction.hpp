#ifndef GODOT_CPP_VISUALSCRIPTINPUTACTION_HPP
#define GODOT_CPP_VISUALSCRIPTINPUTACTION_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <VisualScriptInputAction.hpp>

#include <VisualScriptNode.hpp>
namespace godot {


class VisualScriptInputAction : public VisualScriptNode {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "VisualScriptInputAction"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum Mode {
		MODE_RELEASED = 1,
		MODE_PRESSED = 0,
		MODE_JUST_PRESSED = 2,
		MODE_JUST_RELEASED = 3,
	};

	// constants


	static VisualScriptInputAction *_new();

	// methods
	void set_action_name(const String name);
	String get_action_name() const;
	void set_action_mode(const int64_t mode);
	VisualScriptInputAction::Mode get_action_mode() const;

};

}

#endif