#include <ProjectSettings.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *ProjectSettings::___get_type_tag()
{
	return (void *) &ProjectSettings::___get_type_tag;
}

void *ProjectSettings::___get_base_type_tag()
{
	return (void *) &Object::___get_type_tag;
}

ProjectSettings *ProjectSettings::_singleton = NULL;


ProjectSettings::ProjectSettings() {
	_owner = godot::api->godot_global_get_singleton((char *) "ProjectSettings");
}


bool ProjectSettings::has_setting(const String name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProjectSettings", "has_setting");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, name);
}

void ProjectSettings::set_setting(const String name, const Variant value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProjectSettings", "set_setting");
	}
	___godot_icall_void_String_Variant(mb, (const Object *) this, name, value);
}

Variant ProjectSettings::get_setting(const String name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProjectSettings", "get_setting");
	}
	return ___godot_icall_Variant_String(mb, (const Object *) this, name);
}

void ProjectSettings::set_order(const String name, const int64_t position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProjectSettings", "set_order");
	}
	___godot_icall_void_String_int(mb, (const Object *) this, name, position);
}

int64_t ProjectSettings::get_order(const String name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProjectSettings", "get_order");
	}
	return ___godot_icall_int_String(mb, (const Object *) this, name);
}

void ProjectSettings::set_initial_value(const String name, const Variant value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProjectSettings", "set_initial_value");
	}
	___godot_icall_void_String_Variant(mb, (const Object *) this, name, value);
}

void ProjectSettings::add_property_info(const Dictionary hint) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProjectSettings", "add_property_info");
	}
	___godot_icall_void_Dictionary(mb, (const Object *) this, hint);
}

void ProjectSettings::clear(const String name) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProjectSettings", "clear");
	}
	___godot_icall_void_String(mb, (const Object *) this, name);
}

String ProjectSettings::localize_path(const String path) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProjectSettings", "localize_path");
	}
	return ___godot_icall_String_String(mb, (const Object *) this, path);
}

String ProjectSettings::globalize_path(const String path) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProjectSettings", "globalize_path");
	}
	return ___godot_icall_String_String(mb, (const Object *) this, path);
}

Error ProjectSettings::save() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProjectSettings", "save");
	}
	return (Error) ___godot_icall_int(mb, (const Object *) this);
}

bool ProjectSettings::load_resource_pack(const String pack) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProjectSettings", "load_resource_pack");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, pack);
}

bool ProjectSettings::property_can_revert(const String name) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProjectSettings", "property_can_revert");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, name);
}

Variant ProjectSettings::property_get_revert(const String name) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProjectSettings", "property_get_revert");
	}
	return ___godot_icall_Variant_String(mb, (const Object *) this, name);
}

Error ProjectSettings::save_custom(const String file) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProjectSettings", "save_custom");
	}
	return (Error) ___godot_icall_int_String(mb, (const Object *) this, file);
}

}