#ifndef GODOT_CPP_OCCLUDERPOLYGON2D_HPP
#define GODOT_CPP_OCCLUDERPOLYGON2D_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <OccluderPolygon2D.hpp>

#include <Resource.hpp>
namespace godot {


class OccluderPolygon2D : public Resource {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "OccluderPolygon2D"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum CullMode {
		CULL_COUNTER_CLOCKWISE = 2,
		CULL_CLOCKWISE = 1,
		CULL_DISABLED = 0,
	};

	// constants


	static OccluderPolygon2D *_new();

	// methods
	void set_closed(const bool closed);
	bool is_closed() const;
	void set_cull_mode(const int64_t cull_mode);
	OccluderPolygon2D::CullMode get_cull_mode() const;
	void set_polygon(const PoolVector2Array polygon);
	PoolVector2Array get_polygon() const;

};

}

#endif