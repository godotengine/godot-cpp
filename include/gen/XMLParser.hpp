#ifndef GODOT_CPP_XMLPARSER_HPP
#define GODOT_CPP_XMLPARSER_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include "XMLParser.hpp"

#include "Reference.hpp"
namespace godot {


class XMLParser : public Reference {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "XMLParser"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum NodeType {
		NODE_COMMENT = 4,
		NODE_UNKNOWN = 6,
		NODE_ELEMENT = 1,
		NODE_TEXT = 3,
		NODE_ELEMENT_END = 2,
		NODE_CDATA = 5,
		NODE_NONE = 0,
	};

	// constants


	static XMLParser *_new();

	// methods
	Error read();
	XMLParser::NodeType get_node_type();
	String get_node_name() const;
	String get_node_data() const;
	int64_t get_node_offset() const;
	int64_t get_attribute_count() const;
	String get_attribute_name(const int64_t idx) const;
	String get_attribute_value(const int64_t idx) const;
	bool has_attribute(const String name) const;
	String get_named_attribute_value(const String name) const;
	String get_named_attribute_value_safe(const String name) const;
	bool is_empty() const;
	int64_t get_current_line() const;
	void skip_section();
	Error seek(const int64_t position);
	Error open(const String file);
	Error open_buffer(const PoolByteArray buffer);

};

}

#endif