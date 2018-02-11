#include <Material.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Material.hpp>


namespace godot {


void *Material::___get_type_tag()
{
	return (void *) &Material::___get_type_tag;
}

void *Material::___get_base_type_tag()
{
	return (void *) &Resource::___get_type_tag;
}

void Material::set_next_pass(const Ref<Material> next_pass) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Material", "set_next_pass");
	}
	___godot_icall_void_Object(mb, (const Object *) this, next_pass.ptr());
}

Ref<Material> Material::get_next_pass() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Material", "get_next_pass");
	}
	return Ref<Material>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void Material::set_render_priority(const int64_t priority) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Material", "set_render_priority");
	}
	___godot_icall_void_int(mb, (const Object *) this, priority);
}

int64_t Material::get_render_priority() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Material", "get_render_priority");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

}