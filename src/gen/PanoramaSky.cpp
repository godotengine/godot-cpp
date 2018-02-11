#include <PanoramaSky.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Texture.hpp>


namespace godot {


void *PanoramaSky::___get_type_tag()
{
	return (void *) &PanoramaSky::___get_type_tag;
}

void *PanoramaSky::___get_base_type_tag()
{
	return (void *) &Sky::___get_type_tag;
}

PanoramaSky *PanoramaSky::_new()
{
	return (PanoramaSky *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"PanoramaSky")());
}
void PanoramaSky::set_panorama(const Ref<Texture> texture) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PanoramaSky", "set_panorama");
	}
	___godot_icall_void_Object(mb, (const Object *) this, texture.ptr());
}

Ref<Texture> PanoramaSky::get_panorama() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PanoramaSky", "get_panorama");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

}