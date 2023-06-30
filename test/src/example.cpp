/* godot-cpp integration testing project.
 *
 * This is free and unencumbered software released into the public domain.
 */

#include "example.h"

#include <godot_cpp/core/class_db.hpp>

#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/classes/multiplayer_api.hpp>
#include <godot_cpp/classes/multiplayer_peer.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void ExampleRef::set_id(int p_id) {
	id = p_id;
}

int ExampleRef::get_id() const {
	return id;
}

void ExampleRef::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_id", "id"), &ExampleRef::set_id);
	ClassDB::bind_method(D_METHOD("get_id"), &ExampleRef::get_id);

	ADD_PROPERTY(PropertyInfo(Variant::INT, "id"), "set_id", "get_id");
}

ExampleRef::ExampleRef() {
	id = 0;
}

ExampleRef::~ExampleRef() {
}

int Example::test_static(int p_a, int p_b) {
	return p_a + p_b;
}

void Example::test_static2() {
	//UtilityFunctions::print("  void static");
}

int Example::def_args(int p_a, int p_b) {
	return p_a + p_b;
}

void Example::_notification(int p_what) {
	if (p_what == NOTIFICATION_READY) {
		Dictionary opts;
		opts["rpc_mode"] = MultiplayerAPI::RPC_MODE_AUTHORITY;
		opts["transfer_mode"] = MultiplayerPeer::TRANSFER_MODE_RELIABLE;
		opts["call_local"] = true;
		opts["channel"] = 0;
		rpc_config("test_rpc", opts);
	}
	//UtilityFunctions::print("Notification: ", String::num(p_what));
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
	ClassDB::bind_method(D_METHOD("custom_ref_func", "ref"), &Example::custom_ref_func);
	ClassDB::bind_method(D_METHOD("custom_const_ref_func", "ref"), &Example::custom_const_ref_func);
	ClassDB::bind_method(D_METHOD("image_ref_func", "image"), &Example::image_ref_func);
	ClassDB::bind_method(D_METHOD("image_const_ref_func", "image"), &Example::image_const_ref_func);
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
	ClassDB::bind_method(D_METHOD("test_str_utility"), &Example::test_str_utility);
	ClassDB::bind_method(D_METHOD("test_vector_ops"), &Example::test_vector_ops);

	ClassDB::bind_method(D_METHOD("test_bitfield", "flags"), &Example::test_bitfield);

	ClassDB::bind_method(D_METHOD("test_rpc", "value"), &Example::test_rpc);
	ClassDB::bind_method(D_METHOD("test_send_rpc", "value"), &Example::test_send_rpc);
	ClassDB::bind_method(D_METHOD("return_last_rpc_arg"), &Example::return_last_rpc_arg);

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
	//UtilityFunctions::print("Constructor.");
}

Example::~Example() {
	//UtilityFunctions::print("Destructor.");
}

// Methods.
void Example::simple_func() {
	emit_custom_signal("simple_func", 3);
}

void Example::simple_const_func() const {
	((Example *)this)->emit_custom_signal("simple_const_func", 4);
}

int Example::custom_ref_func(Ref<ExampleRef> p_ref) {
	return p_ref.is_valid() ? p_ref->get_id() : -1;
}

int Example::custom_const_ref_func(const Ref<ExampleRef> &p_ref) {
	return p_ref.is_valid() ? p_ref->get_id() : -1;
}

String Example::image_ref_func(Ref<Image> p_image) {
	return p_image.is_valid() ? String("valid") : String("invalid");
}

String Example::image_const_ref_func(const Ref<Image> &p_image) {
	return p_image.is_valid() ? String("valid") : String("invalid");
}

String Example::return_something(const String &base) {
	return base + String("42");
}

Viewport *Example::return_something_const() const {
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

Ref<ExampleRef> Example::extended_ref_checks(Ref<ExampleRef> p_ref) const {
	// This is therefor the prefered way of instancing and returning a refcounted object:
	Ref<ExampleRef> ref;
	ref.instantiate();
	return ref;
}

Variant Example::varargs_func(const Variant **args, GDExtensionInt arg_count, GDExtensionCallError &error) {
	return arg_count;
}

int Example::varargs_func_nv(const Variant **args, GDExtensionInt arg_count, GDExtensionCallError &error) {
	return 42 + arg_count;
}

void Example::varargs_func_void(const Variant **args, GDExtensionInt arg_count, GDExtensionCallError &error) {
	emit_custom_signal("varargs_func_void", arg_count + 1);
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

String Example::test_str_utility() const {
	return UtilityFunctions::str("Hello, ", "World", "! The answer is ", 42);
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

int Example::test_tarray_arg(const TypedArray<int64_t> &p_array) {
	int sum = 0;
	for (int i = 0; i < p_array.size(); i++) {
		sum += (int)p_array[i];
	}
	return sum;
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

Example *Example::test_node_argument(Example *p_node) const {
	return p_node;
}

BitField<Example::Flags> Example::test_bitfield(BitField<Flags> flags) {
	return flags;
}

void Example::test_rpc(int p_value) {
	last_rpc_arg = p_value;
}

void Example::test_send_rpc(int p_value) {
	rpc("test_rpc", p_value);
}

int Example::return_last_rpc_arg() {
	return last_rpc_arg;
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

void Example::_input(const Ref<InputEvent> &event) {
	const InputEventKey *key_event = Object::cast_to<const InputEventKey>(*event);
	if (key_event) {
		emit_custom_signal(String("_input: ") + key_event->get_key_label(), key_event->get_unicode());
	}
}
