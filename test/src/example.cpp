/* godot-cpp integration testing project.
 *
 * This is free and unencumbered software released into the public domain.
 */

#include "example.h"

#include <godot_cpp/core/class_db.hpp>

#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

int ExampleRef::instance_count = 0;
int ExampleRef::last_id = 0;

int ExampleRef::get_id() const {
	return id;
}

void ExampleRef::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_id"), &ExampleRef::get_id);
}

ExampleRef::ExampleRef() {
	id = ++last_id;
	instance_count++;

	UtilityFunctions::print("ExampleRef ", itos(id), " created, current instance count: ", itos(instance_count));
}

ExampleRef::~ExampleRef() {
	instance_count--;
	UtilityFunctions::print("ExampleRef ", itos(id), " destroyed, current instance count: ", itos(instance_count));
}

int Example::test_static(int p_a, int p_b) {
	return p_a + p_b;
}

void Example::test_static2() {
	UtilityFunctions::print("  void static");
}

int Example::def_args(int p_a, int p_b) {
	return p_a + p_b;
}

void Example::_notification(int p_what) {
	UtilityFunctions::print("Notification: ", String::num(p_what));
}

bool Example::_set(const StringName &p_name, const Variant &p_value) {
	String name = p_name;
	if (name.begins_with("dproperty")) {
		int64_t index = name.get_slicec('_', 1).to_int();
		dprop[index] = p_value;
		return true;
	}
	if (name == "property_from_list") {
		property_from_list = p_value;
		return true;
	}
	return false;
}

bool Example::_get(const StringName &p_name, Variant &r_ret) const {
	String name = p_name;
	if (name.begins_with("dproperty")) {
		int64_t index = name.get_slicec('_', 1).to_int();
		r_ret = dprop[index];
		return true;
	}
	if (name == "property_from_list") {
		r_ret = property_from_list;
		return true;
	}
	return false;
}

String Example::_to_string() const {
	return "[ GDExtension::Example <--> Instance ID:" + uitos(get_instance_id()) + " ]";
}

void Example::_get_property_list(List<PropertyInfo> *p_list) const {
	p_list->push_back(PropertyInfo(Variant::VECTOR3, "property_from_list"));
	for (int i = 0; i < 3; i++) {
		p_list->push_back(PropertyInfo(Variant::VECTOR2, "dproperty_" + itos(i)));
	}
}

bool Example::_property_can_revert(const StringName &p_name) const {
	if (p_name == StringName("property_from_list") && property_from_list != Vector3(42, 42, 42)) {
		return true;
	} else {
		return false;
	}
};

bool Example::_property_get_revert(const StringName &p_name, Variant &r_property) const {
	if (p_name == StringName("property_from_list")) {
		r_property = Vector3(42, 42, 42);
		return true;
	} else {
		return false;
	}
};

void Example::_bind_methods() {
	// Methods.
	ClassDB::bind_method(D_METHOD("simple_func"), &Example::simple_func);
	ClassDB::bind_method(D_METHOD("simple_const_func"), &Example::simple_const_func);
	ClassDB::bind_method(D_METHOD("return_something"), &Example::return_something);
	ClassDB::bind_method(D_METHOD("return_something_const"), &Example::return_something_const);
	ClassDB::bind_method(D_METHOD("return_empty_ref"), &Example::return_empty_ref);
	ClassDB::bind_method(D_METHOD("return_extended_ref"), &Example::return_extended_ref);
	ClassDB::bind_method(D_METHOD("extended_ref_checks", "ref"), &Example::extended_ref_checks);

	ClassDB::bind_method(D_METHOD("test_array"), &Example::test_array);
	ClassDB::bind_method(D_METHOD("test_tarray_arg", "array"), &Example::test_tarray_arg);
	ClassDB::bind_method(D_METHOD("test_tarray"), &Example::test_tarray);
	ClassDB::bind_method(D_METHOD("test_dictionary"), &Example::test_dictionary);
	ClassDB::bind_method(D_METHOD("test_node_argument"), &Example::test_node_argument);
	ClassDB::bind_method(D_METHOD("test_string_ops"), &Example::test_string_ops);
	ClassDB::bind_method(D_METHOD("test_vector_ops"), &Example::test_vector_ops);

	ClassDB::bind_method(D_METHOD("test_bitfield", "flags"), &Example::test_bitfield);

	ClassDB::bind_method(D_METHOD("def_args", "a", "b"), &Example::def_args, DEFVAL(100), DEFVAL(200));

	ClassDB::bind_static_method("Example", D_METHOD("test_static", "a", "b"), &Example::test_static);
	ClassDB::bind_static_method("Example", D_METHOD("test_static2"), &Example::test_static2);

	{
		MethodInfo mi;
		mi.arguments.push_back(PropertyInfo(Variant::STRING, "some_argument"));
		mi.name = "varargs_func";
		ClassDB::bind_vararg_method(METHOD_FLAGS_DEFAULT, "varargs_func", &Example::varargs_func, mi);
	}

	{
		MethodInfo mi;
		mi.arguments.push_back(PropertyInfo(Variant::STRING, "some_argument"));
		mi.name = "varargs_func_nv";
		ClassDB::bind_vararg_method(METHOD_FLAGS_DEFAULT, "varargs_func_nv", &Example::varargs_func_nv, mi);
	}

	{
		MethodInfo mi;
		mi.arguments.push_back(PropertyInfo(Variant::STRING, "some_argument"));
		mi.name = "varargs_func_void";
		ClassDB::bind_vararg_method(METHOD_FLAGS_DEFAULT, "varargs_func_void", &Example::varargs_func_void, mi);
	}

	// Properties.
	ADD_GROUP("Test group", "group_");
	ADD_SUBGROUP("Test subgroup", "group_subgroup_");

	ClassDB::bind_method(D_METHOD("get_custom_position"), &Example::get_custom_position);
	ClassDB::bind_method(D_METHOD("get_v4"), &Example::get_v4);
	ClassDB::bind_method(D_METHOD("set_custom_position", "position"), &Example::set_custom_position);
	ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "group_subgroup_custom_position"), "set_custom_position", "get_custom_position");

	// Signals.
	ADD_SIGNAL(MethodInfo("custom_signal", PropertyInfo(Variant::STRING, "name"), PropertyInfo(Variant::INT, "value")));
	ClassDB::bind_method(D_METHOD("emit_custom_signal", "name", "value"), &Example::emit_custom_signal);

	// Constants.
	BIND_ENUM_CONSTANT(FIRST);
	BIND_ENUM_CONSTANT(ANSWER_TO_EVERYTHING);

	BIND_BITFIELD_FLAG(FLAG_ONE);
	BIND_BITFIELD_FLAG(FLAG_TWO);

	BIND_CONSTANT(CONSTANT_WITHOUT_ENUM);
	BIND_ENUM_CONSTANT(OUTSIDE_OF_CLASS);
}

Example::Example() {
	UtilityFunctions::print("Constructor.");
}

Example::~Example() {
	UtilityFunctions::print("Destructor.");
}

// Methods.
void Example::simple_func() {
	UtilityFunctions::print("  Simple func called.");
}

void Example::simple_const_func() const {
	UtilityFunctions::print("  Simple const func called.");
}

String Example::return_something(const String &base) {
	UtilityFunctions::print("  Return something called.");
	return base;
}

Viewport *Example::return_something_const() const {
	UtilityFunctions::print("  Return something const called.");
	if (is_inside_tree()) {
		Viewport *result = get_viewport();
		return result;
	}
	return nullptr;
}

Ref<ExampleRef> Example::return_empty_ref() const {
	Ref<ExampleRef> ref;
	return ref;
}

ExampleRef *Example::return_extended_ref() const {
	// You can instance and return a refcounted object like this, but keep in mind that refcounting starts with the returned object
	// and it will be destroyed when all references are destroyed. If you store this pointer you run the risk of having a pointer
	// to a destroyed object.
	return memnew(ExampleRef());
}

Example *Example::test_node_argument(Example *p_node) const {
	UtilityFunctions::print("  Test node argument called with ", p_node ? String::num(p_node->get_instance_id()) : "null");
	return p_node;
}

Ref<ExampleRef> Example::extended_ref_checks(Ref<ExampleRef> p_ref) const {
	// This is therefor the prefered way of instancing and returning a refcounted object:
	Ref<ExampleRef> ref;
	ref.instantiate();

	UtilityFunctions::print("  Example ref checks called with value: ", p_ref->get_instance_id(), ", returning value: ", ref->get_instance_id());
	return ref;
}

Variant Example::varargs_func(const Variant **args, GDExtensionInt arg_count, GDExtensionCallError &error) {
	UtilityFunctions::print("  Varargs (Variant return) called with ", String::num((double)arg_count), " arguments");
	return arg_count;
}

int Example::varargs_func_nv(const Variant **args, GDExtensionInt arg_count, GDExtensionCallError &error) {
	UtilityFunctions::print("  Varargs (int return) called with ", String::num((double)arg_count), " arguments");
	return 42;
}

void Example::varargs_func_void(const Variant **args, GDExtensionInt arg_count, GDExtensionCallError &error) {
	UtilityFunctions::print("  Varargs (no return) called with ", String::num((double)arg_count), " arguments");
}

void Example::emit_custom_signal(const String &name, int value) {
	emit_signal("custom_signal", name, value);
}

Array Example::test_array() const {
	Array arr;

	arr.resize(2);
	arr[0] = Variant(1);
	arr[1] = Variant(2);

	return arr;
}

String Example::test_string_ops() const {
	String s = String("A");
	s += "B";
	s += "C";
	s += char32_t(0x010E);
	s = s + "E";
	return s;
}

int Example::test_vector_ops() const {
	PackedInt32Array arr;
	arr.push_back(10);
	arr.push_back(20);
	arr.push_back(30);
	arr.push_back(45);
	int ret = 0;
	for (const int32_t &E : arr) {
		ret += E;
	}
	return ret;
}

void Example::test_tarray_arg(const TypedArray<int64_t> &p_array) {
	for (int i = 0; i < p_array.size(); i++) {
		UtilityFunctions::print(p_array[i]);
	}
}

TypedArray<Vector2> Example::test_tarray() const {
	TypedArray<Vector2> arr;

	arr.resize(2);
	arr[0] = Vector2(1, 2);
	arr[1] = Vector2(2, 3);

	return arr;
}

Dictionary Example::test_dictionary() const {
	Dictionary dict;

	dict["hello"] = "world";
	dict["foo"] = "bar";

	return dict;
}

BitField<Example::Flags> Example::test_bitfield(BitField<Flags> flags) {
	UtilityFunctions::print("  Got BitField: ", String::num_int64(flags));
	return flags;
}

// Properties.
void Example::set_custom_position(const Vector2 &pos) {
	custom_position = pos;
}

Vector2 Example::get_custom_position() const {
	return custom_position;
}

Vector4 Example::get_v4() const {
	return Vector4(1.2, 3.4, 5.6, 7.8);
}

// Virtual function override.
bool Example::_has_point(const Vector2 &point) const {
	Label *label = get_node<Label>("Label");
	label->set_text("Got point: " + Variant(point).stringify());

	return false;
}
