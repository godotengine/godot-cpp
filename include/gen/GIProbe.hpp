#ifndef GODOT_CPP_GIPROBE_HPP
#define GODOT_CPP_GIPROBE_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <GIProbe.hpp>

#include <VisualInstance.hpp>
namespace godot {

class GIProbeData;
class Object;

class GIProbe : public VisualInstance {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "GIProbe"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum Subdiv {
		SUBDIV_512 = 3,
		SUBDIV_MAX = 4,
		SUBDIV_256 = 2,
		SUBDIV_64 = 0,
		SUBDIV_128 = 1,
	};

	// constants


	static GIProbe *_new();

	// methods
	void set_probe_data(const Ref<GIProbeData> data);
	Ref<GIProbeData> get_probe_data() const;
	void set_subdiv(const int64_t subdiv);
	GIProbe::Subdiv get_subdiv() const;
	void set_extents(const Vector3 extents);
	Vector3 get_extents() const;
	void set_dynamic_range(const int64_t max);
	int64_t get_dynamic_range() const;
	void set_energy(const double max);
	double get_energy() const;
	void set_bias(const double max);
	double get_bias() const;
	void set_normal_bias(const double max);
	double get_normal_bias() const;
	void set_propagation(const double max);
	double get_propagation() const;
	void set_interior(const bool enable);
	bool is_interior() const;
	void set_compress(const bool enable);
	bool is_compressed() const;
	void bake(const Object *from_node = nullptr, const bool create_visual_debug = false);
	void debug_bake();

};

}

#endif