#include "example.h"

#include <godot_cpp/core/class_db.hpp>

#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void Example::_bind_methods() {
	// Methods.
	ClassDB::bind_method(D_METHOD("simple_func"), &Example::simple_func);
	ClassDB::bind_method(D_METHOD("simple_const_func"), &Example::simple_const_func);
	ClassDB::bind_method(D_METHOD("return_something"), &Example::return_something);
	ClassDB::bind_method(D_METHOD("return_something_const"), &Example::return_something_const);

	{
		MethodInfo mi;
		mi.arguments.push_back(PropertyInfo(Variant::STRING, "some_argument"));
		mi.name = "varargs_func";
		ClassDB::bind_vararg_method(METHOD_FLAGS_DEFAULT, "varargs_func", &Example::varargs_func, mi);
	}

	// Properties.
	ClassDB::bind_method(D_METHOD("get_custom_position"), &Example::get_custom_position);
	ClassDB::bind_method(D_METHOD("set_custom_position", "position"), &Example::set_custom_position);
	ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "custom_position"), "set_custom_position", "get_custom_position");

	// Signals.
	ADD_SIGNAL(MethodInfo("custom_signal", PropertyInfo(Variant::STRING, "name"), PropertyInfo(Variant::INT, "value")));
	ClassDB::bind_method(D_METHOD("emit_custom_signal", "name", "value"), &Example::emit_custom_signal);

	// Constants.
	BIND_ENUM_CONSTANT(FIRST);
	BIND_ENUM_CONSTANT(ANSWER_TO_EVERYTHING);

	BIND_CONSTANT(CONSTANT_WITHOUT_ENUM);

	// Virtual function override.
	BIND_VIRTUAL_METHOD(_has_point);
}

// Methods.
void Example::simple_func() {
	UtilityFunctions::print("Simple func called.");
}

void Example::simple_const_func() const {
	UtilityFunctions::print("Simple const func called.");
}

String Example::return_something(const String &base) {
	UtilityFunctions::print("Return something called.");
	return base;
}

Viewport *Example::return_something_const() const {
	UtilityFunctions::print("Return something const called.");
	if (is_inside_tree()) {
		Viewport *result = get_viewport();
		return result;
	}
	return nullptr;
}

Variant Example::varargs_func(const Variant **args, GDNativeInt arg_count, GDNativeCallError &error) {
	UtilityFunctions::print("Varargs called with ", String::num(arg_count), " arguments");
	return arg_count;
}

void Example::emit_custom_signal(const String &name, int value) {
	emit_signal("custom_signal", name, value);
}

// Properties.
void Example::set_custom_position(const Vector2 &pos) {
	custom_position = pos;
}

Vector2 Example::get_custom_position() const {
	return custom_position;
}

// Virtual function override.
bool Example::_has_point(const Vector2 &point) {
	Label *label = get_node<Label>("Label");
	label->set_text("Got point: " + Variant(point).stringify());

	return false;
}
