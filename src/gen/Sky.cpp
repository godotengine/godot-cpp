#include <Sky.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *Sky::___get_type_tag()
{
	return (void *) &Sky::___get_type_tag;
}

void *Sky::___get_base_type_tag()
{
	return (void *) &Resource::___get_type_tag;
}

void Sky::set_radiance_size(const int64_t size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Sky", "set_radiance_size");
	}
	___godot_icall_void_int(mb, (const Object *) this, size);
}

Sky::RadianceSize Sky::get_radiance_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Sky", "get_radiance_size");
	}
	return (Sky::RadianceSize) ___godot_icall_int(mb, (const Object *) this);
}

}