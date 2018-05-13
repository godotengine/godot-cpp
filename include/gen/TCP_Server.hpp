#ifndef GODOT_CPP_TCP_SERVER_HPP
#define GODOT_CPP_TCP_SERVER_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Reference.hpp"
namespace godot {

class StreamPeerTCP;

class TCP_Server : public Reference {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "TCP_Server"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static TCP_Server *_new();

	// methods
	Error listen(const int64_t port, const String bind_address = "*");
	bool is_connection_available() const;
	Ref<StreamPeerTCP> take_connection();
	void stop();

};

}

#endif