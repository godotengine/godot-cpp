#include <ConfirmationDialog.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Button.hpp>


namespace godot {


void *ConfirmationDialog::___get_type_tag()
{
	return (void *) &ConfirmationDialog::___get_type_tag;
}

void *ConfirmationDialog::___get_base_type_tag()
{
	return (void *) &AcceptDialog::___get_type_tag;
}

ConfirmationDialog *ConfirmationDialog::_new()
{
	return (ConfirmationDialog *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"ConfirmationDialog")());
}
Button *ConfirmationDialog::get_cancel() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ConfirmationDialog", "get_cancel");
	}
	return (Button *) ___godot_icall_Object(mb, (const Object *) this);
}

}