#ifndef GODOT_CPP_VISUALSCRIPTPROPERTYGET_HPP
#define GODOT_CPP_VISUALSCRIPTPROPERTYGET_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <Variant.hpp>
#include <VisualScriptPropertyGet.hpp>

#include <VisualScriptNode.hpp>
namespace godot {


class VisualScriptPropertyGet : public VisualScriptNode {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "VisualScriptPropertyGet"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum CallMode {
		CALL_MODE_INSTANCE = 2,
		CALL_MODE_SELF = 0,
		CALL_MODE_NODE_PATH = 1,
	};

	// constants


	static VisualScriptPropertyGet *_new();

	// methods
	void set_base_type(const String base_type);
	String get_base_type() const;
	void set_base_script(const String base_script);
	String get_base_script() const;
	void set_basic_type(const int64_t basic_type);
	Variant::Type get_basic_type() const;
	void _set_type_cache(const int64_t type_cache);
	Variant::Type _get_type_cache() const;
	void set_property(const String property);
	String get_property() const;
	void set_call_mode(const int64_t mode);
	VisualScriptPropertyGet::CallMode get_call_mode() const;
	void set_base_path(const NodePath base_path);
	NodePath get_base_path() const;
	void set_index(const String index);
	String get_index() const;

};

}

#endif