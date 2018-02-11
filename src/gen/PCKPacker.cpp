#include <PCKPacker.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *PCKPacker::___get_type_tag()
{
	return (void *) &PCKPacker::___get_type_tag;
}

void *PCKPacker::___get_base_type_tag()
{
	return (void *) &Reference::___get_type_tag;
}

PCKPacker *PCKPacker::_new()
{
	return (PCKPacker *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"PCKPacker")());
}
Error PCKPacker::pck_start(const String pck_name, const int64_t alignment) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PCKPacker", "pck_start");
	}
	return (Error) ___godot_icall_int_String_int(mb, (const Object *) this, pck_name, alignment);
}

Error PCKPacker::add_file(const String pck_path, const String source_path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PCKPacker", "add_file");
	}
	return (Error) ___godot_icall_int_String_String(mb, (const Object *) this, pck_path, source_path);
}

Error PCKPacker::flush(const bool verbose) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PCKPacker", "flush");
	}
	return (Error) ___godot_icall_int_bool(mb, (const Object *) this, verbose);
}

}