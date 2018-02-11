#include <VisibilityEnabler2D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Object.hpp>


namespace godot {


void *VisibilityEnabler2D::___get_type_tag()
{
	return (void *) &VisibilityEnabler2D::___get_type_tag;
}

void *VisibilityEnabler2D::___get_base_type_tag()
{
	return (void *) &VisibilityNotifier2D::___get_type_tag;
}

VisibilityEnabler2D *VisibilityEnabler2D::_new()
{
	return (VisibilityEnabler2D *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"VisibilityEnabler2D")());
}
void VisibilityEnabler2D::set_enabler(const int64_t enabler, const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisibilityEnabler2D", "set_enabler");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, enabler, enabled);
}

bool VisibilityEnabler2D::is_enabler_enabled(const int64_t enabler) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisibilityEnabler2D", "is_enabler_enabled");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, enabler);
}

void VisibilityEnabler2D::_node_removed(const Object *arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisibilityEnabler2D", "_node_removed");
	}
	___godot_icall_void_Object(mb, (const Object *) this, arg0);
}

}