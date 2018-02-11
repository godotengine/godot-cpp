#include <VisualScriptMathConstant.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *VisualScriptMathConstant::___get_type_tag()
{
	return (void *) &VisualScriptMathConstant::___get_type_tag;
}

void *VisualScriptMathConstant::___get_base_type_tag()
{
	return (void *) &VisualScriptNode::___get_type_tag;
}

VisualScriptMathConstant *VisualScriptMathConstant::_new()
{
	return (VisualScriptMathConstant *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"VisualScriptMathConstant")());
}
void VisualScriptMathConstant::set_math_constant(const int64_t which) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptMathConstant", "set_math_constant");
	}
	___godot_icall_void_int(mb, (const Object *) this, which);
}

VisualScriptMathConstant::MathConstant VisualScriptMathConstant::get_math_constant() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptMathConstant", "get_math_constant");
	}
	return (VisualScriptMathConstant::MathConstant) ___godot_icall_int(mb, (const Object *) this);
}

}