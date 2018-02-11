#ifndef GODOT_CPP_VISUALSCRIPTYIELDSIGNAL_HPP
#define GODOT_CPP_VISUALSCRIPTYIELDSIGNAL_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <VisualScriptYieldSignal.hpp>

#include <VisualScriptNode.hpp>
namespace godot {


class VisualScriptYieldSignal : public VisualScriptNode {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "VisualScriptYieldSignal"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum CallMode {
		CALL_MODE_INSTANCE = 2,
		CALL_MODE_SELF = 0,
		CALL_MODE_NODE_PATH = 1,
	};

	// constants


	static VisualScriptYieldSignal *_new();

	// methods
	void set_base_type(const String base_type);
	String get_base_type() const;
	void set_signal(const String signal);
	String get_signal() const;
	void set_call_mode(const int64_t mode);
	VisualScriptYieldSignal::CallMode get_call_mode() const;
	void set_base_path(const NodePath base_path);
	NodePath get_base_path() const;

};

}

#endif