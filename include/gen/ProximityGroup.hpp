#ifndef GODOT_CPP_PROXIMITYGROUP_HPP
#define GODOT_CPP_PROXIMITYGROUP_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include "ProximityGroup.hpp"

#include "Spatial.hpp"
namespace godot {


class ProximityGroup : public Spatial {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "ProximityGroup"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum DispatchMode {
		MODE_SIGNAL = 1,
		MODE_PROXY = 0,
	};

	// constants


	static ProximityGroup *_new();

	// methods
	void set_group_name(const String name);
	String get_group_name() const;
	void set_dispatch_mode(const int64_t mode);
	ProximityGroup::DispatchMode get_dispatch_mode() const;
	void set_grid_radius(const Vector3 radius);
	Vector3 get_grid_radius() const;
	void broadcast(const String name, const Variant parameters);
	void _proximity_group_broadcast(const String name, const Variant params);

};

}

#endif