#ifndef GODOT_CPP_VISUALSCRIPTBASICTYPECONSTANT_HPP
#define GODOT_CPP_VISUALSCRIPTBASICTYPECONSTANT_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <Variant.hpp>

#include <VisualScriptNode.hpp>
namespace godot {


class VisualScriptBasicTypeConstant : public VisualScriptNode {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "VisualScriptBasicTypeConstant"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static VisualScriptBasicTypeConstant *_new();

	// methods
	void set_basic_type(const int64_t name);
	Variant::Type get_basic_type() const;
	void set_basic_type_constant(const String name);
	String get_basic_type_constant() const;

};

}

#endif