#ifndef GODOT_CPP_VISUALSCRIPTPROPERTYSET_HPP
#define GODOT_CPP_VISUALSCRIPTPROPERTYSET_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include "Variant.hpp"
#include "VisualScriptPropertySet.hpp"

#include "VisualScriptNode.hpp"
namespace godot {


class VisualScriptPropertySet : public VisualScriptNode {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "VisualScriptPropertySet"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum AssignOp {
		ASSIGN_OP_MOD = 5,
		ASSIGN_OP_BIT_XOR = 10,
		ASSIGN_OP_NONE = 0,
		ASSIGN_OP_BIT_OR = 9,
		ASSIGN_OP_SHIFT_RIGHT = 7,
		ASSIGN_OP_SUB = 2,
		ASSIGN_OP_SHIFT_LEFT = 6,
		ASSIGN_OP_DIV = 4,
		ASSIGN_OP_BIT_AND = 8,
		ASSIGN_OP_ADD = 1,
		ASSIGN_OP_MUL = 3,
	};
	enum CallMode {
		CALL_MODE_INSTANCE = 2,
		CALL_MODE_BASIC_TYPE = 3,
		CALL_MODE_SELF = 0,
		CALL_MODE_NODE_PATH = 1,
	};

	// constants


	static VisualScriptPropertySet *_new();

	// methods
	void set_base_type(const String base_type);
	String get_base_type() const;
	void set_base_script(const String base_script);
	String get_base_script() const;
	void set_basic_type(const int64_t basic_type);
	Variant::Type get_basic_type() const;
	void _set_type_cache(const Dictionary type_cache);
	Dictionary _get_type_cache() const;
	void set_property(const String property);
	String get_property() const;
	void set_call_mode(const int64_t mode);
	VisualScriptPropertySet::CallMode get_call_mode() const;
	void set_base_path(const NodePath base_path);
	NodePath get_base_path() const;
	void set_index(const String index);
	String get_index() const;
	void set_assign_op(const int64_t assign_op);
	VisualScriptPropertySet::AssignOp get_assign_op() const;

};

}

#endif