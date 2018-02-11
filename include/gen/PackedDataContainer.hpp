#ifndef GODOT_CPP_PACKEDDATACONTAINER_HPP
#define GODOT_CPP_PACKEDDATACONTAINER_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Resource.hpp>
namespace godot {


class PackedDataContainer : public Resource {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "PackedDataContainer"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static PackedDataContainer *_new();

	// methods
	void _set_data(const PoolByteArray arg0);
	PoolByteArray _get_data() const;
	Variant _iter_init(const Array arg0);
	Variant _iter_get(const Variant arg0);
	Variant _iter_next(const Array arg0);
	Error pack(const Variant value);
	int64_t size() const;

};

}

#endif