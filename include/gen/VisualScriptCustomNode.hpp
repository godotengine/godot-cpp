#ifndef GODOT_CPP_VISUALSCRIPTCUSTOMNODE_HPP
#define GODOT_CPP_VISUALSCRIPTCUSTOMNODE_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <VisualScriptNode.hpp>
namespace godot {


class VisualScriptCustomNode : public VisualScriptNode {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "VisualScriptCustomNode"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum StartMode {
		START_MODE_BEGIN_SEQUENCE = 0,
		START_MODE_CONTINUE_SEQUENCE = 1,
		START_MODE_RESUME_YIELD = 2,
	};

	// constants
	const static int STEP_EXIT_FUNCTION_BIT = 134217728;
	const static int STEP_GO_BACK_BIT = 33554432;
	const static int STEP_YIELD_BIT = 268435456;
	const static int STEP_NO_ADVANCE_BIT = 67108864;
	const static int STEP_PUSH_STACK_BIT = 16777216;


	static VisualScriptCustomNode *_new();

	// methods
	int64_t _get_output_sequence_port_count();
	bool _has_input_sequence_port();
	String _get_output_sequence_port_text(const int64_t idx);
	int64_t _get_input_value_port_count();
	int64_t _get_output_value_port_count();
	int64_t _get_input_value_port_type(const int64_t idx);
	String _get_input_value_port_name(const int64_t idx);
	int64_t _get_output_value_port_type(const int64_t idx);
	String _get_output_value_port_name(const int64_t idx);
	String _get_caption();
	String _get_text();
	String _get_category();
	int64_t _get_working_memory_size();
	Variant _step(const Array inputs, const Array outputs, const int64_t start_mode, const Array working_mem);
	void _script_changed();

};

}

#endif