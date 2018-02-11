#include <VisibilityEnabler.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Object.hpp>


namespace godot {


void *VisibilityEnabler::___get_type_tag()
{
	return (void *) &VisibilityEnabler::___get_type_tag;
}

void *VisibilityEnabler::___get_base_type_tag()
{
	return (void *) &VisibilityNotifier::___get_type_tag;
}

VisibilityEnabler *VisibilityEnabler::_new()
{
	return (VisibilityEnabler *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"VisibilityEnabler")());
}
void VisibilityEnabler::set_enabler(const int64_t enabler, const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisibilityEnabler", "set_enabler");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, enabler, enabled);
}

bool VisibilityEnabler::is_enabler_enabled(const int64_t enabler) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisibilityEnabler", "is_enabler_enabled");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, enabler);
}

void VisibilityEnabler::_node_removed(const Object *arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisibilityEnabler", "_node_removed");
	}
	___godot_icall_void_Object(mb, (const Object *) this, arg0);
}

}