#ifndef GODOT_CPP_VISUALSCRIPTFUNCTIONCALL_HPP
#define GODOT_CPP_VISUALSCRIPTFUNCTIONCALL_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <Variant.hpp>
#include <VisualScriptFunctionCall.hpp>

#include <VisualScriptNode.hpp>
namespace godot {


class VisualScriptFunctionCall : public VisualScriptNode {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "VisualScriptFunctionCall"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum RPCCallMode {
		RPC_DISABLED = 0,
		RPC_UNRELIABLE = 2,
		RPC_RELIABLE = 1,
		RPC_RELIABLE_TO_ID = 3,
		RPC_UNRELIABLE_TO_ID = 4,
	};
	enum CallMode {
		CALL_MODE_INSTANCE = 2,
		CALL_MODE_BASIC_TYPE = 3,
		CALL_MODE_SELF = 0,
		CALL_MODE_NODE_PATH = 1,
		CALL_MODE_SINGLETON = 4,
	};

	// constants


	static VisualScriptFunctionCall *_new();

	// methods
	void set_base_type(const String base_type);
	String get_base_type() const;
	void set_base_script(const String base_script);
	String get_base_script() const;
	void set_basic_type(const int64_t basic_type);
	Variant::Type get_basic_type() const;
	void set_singleton(const String singleton);
	String get_singleton() const;
	void set_function(const String function);
	String get_function() const;
	void set_call_mode(const int64_t mode);
	VisualScriptFunctionCall::CallMode get_call_mode() const;
	void set_base_path(const NodePath base_path);
	NodePath get_base_path() const;
	void set_use_default_args(const int64_t amount);
	int64_t get_use_default_args() const;
	void _set_argument_cache(const Dictionary argument_cache);
	Dictionary _get_argument_cache() const;
	void set_rpc_call_mode(const int64_t mode);
	VisualScriptFunctionCall::RPCCallMode get_rpc_call_mode() const;
	void set_validate(const bool enable);
	bool get_validate() const;

};

}

#endif