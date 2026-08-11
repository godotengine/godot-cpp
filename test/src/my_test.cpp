/* godot-cpp integration testing project.
 *
 * This is free and unencumbered software released into the public domain.
 */

#include "my_test.h"

#include <godot_cpp/core/class_db.hpp>

#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/classes/multiplayer_api.hpp>
#include <godot_cpp/classes/multiplayer_peer.hpp>
#include <godot_cpp/classes/os.hpp>
#include <godot_cpp/classes/scene_tree.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

class MyCallableCustom : public CallableCustom {
public:
	virtual uint32_t hash() const {
		return 27;
	}

	virtual String get_as_text() const {
		return "<MyCallableCustom>";
	}

	static bool compare_equal_func(const CallableCustom *p_a, const CallableCustom *p_b) {
		return p_a == p_b;
	}

	virtual CompareEqualFunc get_compare_equal_func() const {
		return &MyCallableCustom::compare_equal_func;
	}

	static bool compare_less_func(const CallableCustom *p_a, const CallableCustom *p_b) {
		return (void *)p_a < (void *)p_b;
	}

	virtual CompareLessFunc get_compare_less_func() const {
		return &MyCallableCustom::compare_less_func;
	}

	bool is_valid() const {
		return true;
	}

	virtual ObjectID get_object() const {
		return ObjectID();
	}

	virtual int get_argument_count(bool &r_is_valid) const {
		r_is_valid = true;
		return 2;
	}

	virtual void call(const Variant **p_arguments, int p_argcount, Variant &r_return_value, GDExtensionCallError &r_call_error) const {
		r_return_value = "Hi";
		r_call_error.error = GDEXTENSION_CALL_OK;
	}
};

void MyTestRef::set_id(int p_id) {
	id = p_id;
}

int MyTestRef::get_id() const {
	return id;
}

void MyTestRef::_notification(int p_what) {
	if (p_what == NOTIFICATION_POSTINITIALIZE) {
		post_initialized = true;
	}
}

void MyTestRef::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_id", "id"), &MyTestRef::set_id);
	ClassDB::bind_method(D_METHOD("get_id"), &MyTestRef::get_id);

	ClassDB::bind_method(D_METHOD("was_post_initialized"), &MyTestRef::was_post_initialized);

	ADD_PROPERTY(PropertyInfo(Variant::INT, "id"), "set_id", "get_id");
}

MyTestRef::MyTestRef() {
	id = 0;
}

MyTestRef::~MyTestRef() {
}

Dictionary MyTestMain::get_godot_target_version() const {
	Dictionary ret;
	ret["major"] = GODOT_VERSION_MAJOR;
	ret["minor"] = GODOT_VERSION_MINOR;
	ret["patch"] = GODOT_VERSION_PATCH;
	return ret;
}

int MyTestMain::test_static(int p_a, int p_b) {
	return p_a + p_b;
}

void MyTestMain::test_static2() {
	//UtilityFunctions::print("  void static");
}

int MyTestMain::def_args(int p_a, int p_b) {
	return p_a + p_b;
}

void MyTestMain::_notification(int p_what) {
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

bool MyTestMain::_set(const StringName &p_name, const Variant &p_value) {
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

bool MyTestMain::_get(const StringName &p_name, Variant &r_ret) const {
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

String MyTestMain::_to_string() const {
	return "[ GDExtension::MyTestMain <--> Instance ID:" + uitos(get_instance_id()) + " ]";
}

void MyTestMain::_get_property_list(List<PropertyInfo> *p_list) const {
	p_list->push_back(PropertyInfo(Variant::VECTOR3, "property_from_list"));
	for (int i = 0; i < 3; i++) {
		p_list->push_back(PropertyInfo(Variant::VECTOR2, "dproperty_" + itos(i)));
	}
}

bool MyTestMain::_property_can_revert(const StringName &p_name) const {
	if (p_name == StringName("property_from_list") && property_from_list != Vector3(42, 42, 42)) {
		return true;
	} else {
		return false;
	}
}

bool MyTestMain::_property_get_revert(const StringName &p_name, Variant &r_property) const {
	if (p_name == StringName("property_from_list")) {
		r_property = Vector3(42, 42, 42);
		return true;
	} else {
		return false;
	}
}

void MyTestMain::_validate_property(PropertyInfo &p_property) const {
	String name = p_property.name;
	// Test hiding the "mouse_filter" property from the editor.
	if (name == "mouse_filter") {
		p_property.usage = PROPERTY_USAGE_NO_EDITOR;
	}
}

void MyTestMain::_bind_methods() {
	// Methods.
	ClassDB::bind_method(D_METHOD("get_godot_target_version"), &MyTestMain::get_godot_target_version);
	ClassDB::bind_method(D_METHOD("simple_func"), &MyTestMain::simple_func);
	ClassDB::bind_method(D_METHOD("simple_const_func"), &MyTestMain::simple_const_func);
	ClassDB::bind_method(D_METHOD("custom_ref_func", "ref"), &MyTestMain::custom_ref_func);
	ClassDB::bind_method(D_METHOD("custom_const_ref_func", "ref"), &MyTestMain::custom_const_ref_func);
	ClassDB::bind_method(D_METHOD("image_ref_func", "image"), &MyTestMain::image_ref_func);
	ClassDB::bind_method(D_METHOD("image_const_ref_func", "image"), &MyTestMain::image_const_ref_func);
	ClassDB::bind_method(D_METHOD("return_something"), &MyTestMain::return_something);
	ClassDB::bind_method(D_METHOD("return_something_const"), &MyTestMain::return_something_const);
	ClassDB::bind_method(D_METHOD("return_empty_ref"), &MyTestMain::return_empty_ref);
	ClassDB::bind_method(D_METHOD("return_extended_ref"), &MyTestMain::return_extended_ref);
	ClassDB::bind_method(D_METHOD("extended_ref_checks", "ref"), &MyTestMain::extended_ref_checks);

	ClassDB::bind_method(D_METHOD("is_object_binding_set_by_parent_constructor"), &MyTestMain::is_object_binding_set_by_parent_constructor);

	ClassDB::bind_method(D_METHOD("test_array"), &MyTestMain::test_array);
	ClassDB::bind_method(D_METHOD("test_tarray_arg", "array"), &MyTestMain::test_tarray_arg);
	ClassDB::bind_method(D_METHOD("test_tarray"), &MyTestMain::test_tarray);
	ClassDB::bind_method(D_METHOD("test_dictionary"), &MyTestMain::test_dictionary);

#if GODOT_VERSION_MINOR >= 4
	ClassDB::bind_method(D_METHOD("test_tdictionary_arg", "dictionary"), &MyTestMain::test_tdictionary_arg);
	ClassDB::bind_method(D_METHOD("test_tdictionary"), &MyTestMain::test_tdictionary);
#endif // GODOT_VERSION_MINOR >= 4

	ClassDB::bind_method(D_METHOD("test_node_argument"), &MyTestMain::test_node_argument);
	ClassDB::bind_method(D_METHOD("test_string_ops"), &MyTestMain::test_string_ops);
	ClassDB::bind_method(D_METHOD("test_str_utility"), &MyTestMain::test_str_utility);
	ClassDB::bind_method(D_METHOD("test_string_is_forty_two"), &MyTestMain::test_string_is_forty_two);
	ClassDB::bind_method(D_METHOD("test_string_resize"), &MyTestMain::test_string_resize);
	ClassDB::bind_method(D_METHOD("test_typed_array_of_packed"), &MyTestMain::test_typed_array_of_packed);
	ClassDB::bind_method(D_METHOD("test_vector_ops"), &MyTestMain::test_vector_ops);
	ClassDB::bind_method(D_METHOD("test_vector_init_list"), &MyTestMain::test_vector_init_list);

	ClassDB::bind_method(D_METHOD("test_object_cast_to_node", "object"), &MyTestMain::test_object_cast_to_node);
	ClassDB::bind_method(D_METHOD("test_object_cast_to_control", "object"), &MyTestMain::test_object_cast_to_control);
	ClassDB::bind_method(D_METHOD("test_object_cast_to_my_test_main", "object"), &MyTestMain::test_object_cast_to_my_test_main);

	ClassDB::bind_method(D_METHOD("test_variant_vector2i_conversion", "variant"), &MyTestMain::test_variant_vector2i_conversion);
	ClassDB::bind_method(D_METHOD("test_variant_int_conversion", "variant"), &MyTestMain::test_variant_int_conversion);
	ClassDB::bind_method(D_METHOD("test_variant_float_conversion", "variant"), &MyTestMain::test_variant_float_conversion);
	ClassDB::bind_method(D_METHOD("test_object_is_valid", "variant"), &MyTestMain::test_object_is_valid);

	ClassDB::bind_method(D_METHOD("test_add_child", "node"), &MyTestMain::test_add_child);
	ClassDB::bind_method(D_METHOD("test_set_tileset", "tilemap", "tileset"), &MyTestMain::test_set_tileset);
	ClassDB::bind_method(D_METHOD("test_tween_smoke_test"), &MyTestMain::test_tween_smoke_test);

	ClassDB::bind_method(D_METHOD("test_variant_call", "variant"), &MyTestMain::test_variant_call);

	ClassDB::bind_method(D_METHOD("test_callable_mp"), &MyTestMain::test_callable_mp);
	ClassDB::bind_method(D_METHOD("test_callable_mp_ret"), &MyTestMain::test_callable_mp_ret);
	ClassDB::bind_method(D_METHOD("test_callable_mp_retc"), &MyTestMain::test_callable_mp_retc);
	ClassDB::bind_method(D_METHOD("test_callable_mp_static"), &MyTestMain::test_callable_mp_static);
	ClassDB::bind_method(D_METHOD("test_callable_mp_static_ret"), &MyTestMain::test_callable_mp_static_ret);
	ClassDB::bind_method(D_METHOD("test_custom_callable"), &MyTestMain::test_custom_callable);

	ClassDB::bind_method(D_METHOD("test_bitfield", "flags"), &MyTestMain::test_bitfield);

	ClassDB::bind_method(D_METHOD("test_variant_iterator", "input"), &MyTestMain::test_variant_iterator);

	ClassDB::bind_method(D_METHOD("test_rpc", "value"), &MyTestMain::test_rpc);
	ClassDB::bind_method(D_METHOD("test_send_rpc", "value"), &MyTestMain::test_send_rpc);
	ClassDB::bind_method(D_METHOD("return_last_rpc_arg"), &MyTestMain::return_last_rpc_arg);

	ClassDB::bind_method(D_METHOD("def_args", "a", "b"), &MyTestMain::def_args, DEFVAL(100), DEFVAL(200));
	ClassDB::bind_method(D_METHOD("callable_bind"), &MyTestMain::callable_bind);
	ClassDB::bind_method(D_METHOD("test_post_initialize"), &MyTestMain::test_post_initialize);

#if GODOT_VERSION_MINOR >= 4
	ClassDB::bind_method(D_METHOD("test_get_internal", "a"), &MyTestMain::test_get_internal);
#endif // GODOT_VERSION_MINOR >= 4

	GDVIRTUAL_BIND(_do_something_virtual, "name", "value");
	ClassDB::bind_method(D_METHOD("test_virtual_implemented_in_script"), &MyTestMain::test_virtual_implemented_in_script);
	GDVIRTUAL_BIND(_do_something_virtual_with_control, "control");

	ClassDB::bind_method(D_METHOD("test_use_engine_singleton"), &MyTestMain::test_use_engine_singleton);
	ClassDB::bind_method(D_METHOD("test_use_scene_tree_singleton"), &MyTestMain::test_use_scene_tree_singleton);

	ClassDB::bind_method(D_METHOD("test_get_internal_class"), &MyTestMain::test_get_internal_class);

	ClassDB::bind_static_method("MyTestMain", D_METHOD("test_static", "a", "b"), &MyTestMain::test_static);
	ClassDB::bind_static_method("MyTestMain", D_METHOD("test_static2"), &MyTestMain::test_static2);

	ClassDB::bind_static_method("MyTestMain", D_METHOD("test_library_path"), &MyTestMain::test_library_path);

	{
		MethodInfo mi;
		mi.arguments.push_back(PropertyInfo(Variant::STRING, "some_argument"));
		mi.name = "varargs_func";
		ClassDB::bind_vararg_method(METHOD_FLAGS_DEFAULT, "varargs_func", &MyTestMain::varargs_func, mi);
	}

	{
		MethodInfo mi;
		mi.arguments.push_back(PropertyInfo(Variant::STRING, "some_argument"));
		mi.name = "varargs_func_nv";
		ClassDB::bind_vararg_method(METHOD_FLAGS_DEFAULT, "varargs_func_nv", &MyTestMain::varargs_func_nv, mi);
	}

	{
		MethodInfo mi;
		mi.arguments.push_back(PropertyInfo(Variant::STRING, "some_argument"));
		mi.name = "varargs_func_void";
		ClassDB::bind_vararg_method(METHOD_FLAGS_DEFAULT, "varargs_func_void", &MyTestMain::varargs_func_void, mi);
	}

	// Properties.
	ADD_GROUP("Test group", "group_");
	ADD_SUBGROUP("Test subgroup", "group_subgroup_");

	ClassDB::bind_method(D_METHOD("get_custom_position"), &MyTestMain::get_custom_position);
	ClassDB::bind_method(D_METHOD("get_v4"), &MyTestMain::get_v4);
	ClassDB::bind_method(D_METHOD("set_custom_position", "position"), &MyTestMain::set_custom_position);
	ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "group_subgroup_custom_position"), "set_custom_position", "get_custom_position");

	// Signals.
	ADD_SIGNAL(MethodInfo("custom_signal", PropertyInfo(Variant::STRING, "name"), PropertyInfo(Variant::INT, "value")));
	ClassDB::bind_method(D_METHOD("emit_custom_signal", "name", "value"), &MyTestMain::emit_custom_signal);

	// Constants.
	BIND_ENUM_CONSTANT(FIRST);
	BIND_ENUM_CONSTANT(ANSWER_TO_EVERYTHING);

	BIND_BITFIELD_FLAG(FLAG_ONE);
	BIND_BITFIELD_FLAG(FLAG_TWO);

	BIND_CONSTANT(CONSTANT_WITHOUT_ENUM);
	BIND_ENUM_CONSTANT(OUTSIDE_OF_CLASS);
}

bool MyTestMain::has_object_instance_binding() const {
	return ::godot::gdextension_interface::object_get_instance_binding(_owner, ::godot::gdextension_interface::token, nullptr);
}

MyTestMain::MyTestMain() :
		object_instance_binding_set_by_parent_constructor(has_object_instance_binding()) {
	// Test conversion, to ensure users can use all parent class functions at this time.
	// It would crash if instance binding still not be initialized.
	Variant v = Variant(this);
	Object *o = (Object *)v;

	//UtilityFunctions::print("Constructor.");
}

MyTestMain::~MyTestMain() {
	//UtilityFunctions::print("Destructor.");
}

// Methods.
void MyTestMain::simple_func() {
	emit_custom_signal("simple_func", 3);
}

void MyTestMain::simple_const_func() const {
	((MyTestMain *)this)->emit_custom_signal("simple_const_func", 4);
}

int MyTestMain::custom_ref_func(Ref<MyTestRef> p_ref) {
	return p_ref.is_valid() ? p_ref->get_id() : -1;
}

int MyTestMain::custom_const_ref_func(const Ref<MyTestRef> &p_ref) {
	return p_ref.is_valid() ? p_ref->get_id() : -1;
}

String MyTestMain::image_ref_func(Ref<Image> p_image) {
	return p_image.is_valid() ? String("valid") : String("invalid");
}

String MyTestMain::image_const_ref_func(const Ref<Image> &p_image) {
	return p_image.is_valid() ? String("valid") : String("invalid");
}

String MyTestMain::return_something(const String &base) {
	return base + String("42");
}

Viewport *MyTestMain::return_something_const() const {
	if (is_inside_tree()) {
		Viewport *result = get_viewport();
		return result;
	}
	return nullptr;
}

Ref<MyTestRef> MyTestMain::return_empty_ref() const {
	Ref<MyTestRef> ref;
	return ref;
}

Ref<MyTestRef> MyTestMain::return_extended_ref() const {
	return memnew(MyTestRef());
}

Ref<MyTestRef> MyTestMain::extended_ref_checks(Ref<MyTestRef> p_ref) const {
	// This is therefore the preferred way of instancing and returning a refcounted object:
	Ref<MyTestRef> ref;
	ref.instantiate();
	return ref;
}

Variant MyTestMain::varargs_func(const Variant **args, GDExtensionInt arg_count, GDExtensionCallError &error) {
	return arg_count;
}

int MyTestMain::varargs_func_nv(const Variant **args, GDExtensionInt arg_count, GDExtensionCallError &error) {
	return 42 + arg_count;
}

void MyTestMain::varargs_func_void(const Variant **args, GDExtensionInt arg_count, GDExtensionCallError &error) {
	emit_custom_signal("varargs_func_void", arg_count + 1);
}

void MyTestMain::emit_custom_signal(const String &name, int value) {
	emit_signal("custom_signal", name, value);
}

bool MyTestMain::is_object_binding_set_by_parent_constructor() const {
	return object_instance_binding_set_by_parent_constructor;
}

Array MyTestMain::test_array() const {
	Array arr;

	arr.resize(2);
	arr[0] = Variant(1);
	arr[1] = Variant(2);

	return arr;
}

String MyTestMain::test_string_ops() const {
	String s = String("A");
	s += "B";
	s += "C";
	s += char32_t(0x010E);
	s = s + "E";
	return s;
}

String MyTestMain::test_str_utility() const {
	return UtilityFunctions::str("Hello, ", "World", "! The answer is ", 42);
}

bool MyTestMain::test_string_is_forty_two(const String &p_string) const {
	return strcmp(p_string.utf8().ptr(), "forty two") == 0;
}

String MyTestMain::test_string_resize(String p_string) const {
	int orig_len = p_string.length();
	p_string.resize(orig_len + 3);
	char32_t *data = p_string.ptrw();
	data[orig_len + 0] = '!';
	data[orig_len + 1] = '?';
	data[orig_len + 2] = '\0';
	return p_string;
}

TypedArray<PackedInt32Array> MyTestMain::test_typed_array_of_packed() const {
	TypedArray<PackedInt32Array> arr;
	PackedInt32Array packed_arr1;
	packed_arr1.push_back(1);
	packed_arr1.push_back(2);
	arr.push_back(packed_arr1);
	PackedInt32Array packed_arr2;
	packed_arr2.push_back(3);
	packed_arr2.push_back(4);
	arr.push_back(packed_arr2);
	return arr;
}

int MyTestMain::test_vector_ops() const {
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

int MyTestMain::test_vector_init_list() const {
	PackedInt32Array arr = { 10, 20, 30, 45 };
	int ret = 0;
	for (const int32_t &E : arr) {
		ret += E;
	}
	return ret;
}

Callable MyTestMain::test_callable_mp() {
	return callable_mp(this, &MyTestMain::unbound_method1);
}

Callable MyTestMain::test_callable_mp_ret() {
	return callable_mp(this, &MyTestMain::unbound_method2);
}

Callable MyTestMain::test_callable_mp_retc() const {
	return callable_mp(this, &MyTestMain::unbound_method3);
}

Callable MyTestMain::test_callable_mp_static() const {
	return callable_mp_static(&MyTestMain::unbound_static_method1);
}

Callable MyTestMain::test_callable_mp_static_ret() const {
	return callable_mp_static(&MyTestMain::unbound_static_method2);
}

Callable MyTestMain::test_custom_callable() const {
	return Callable(memnew(MyCallableCustom));
}

void MyTestMain::unbound_method1(Object *p_object, String p_string, int p_int) {
	String test = "unbound_method1: ";
	test += p_object->get_class();
	test += " - " + p_string;
	emit_custom_signal(test, p_int);
}

String MyTestMain::unbound_method2(Object *p_object, String p_string, int p_int) {
	String test = "unbound_method2: ";
	test += p_object->get_class();
	test += " - " + p_string;
	test += " - " + itos(p_int);
	return test;
}

String MyTestMain::unbound_method3(Object *p_object, String p_string, int p_int) const {
	String test = "unbound_method3: ";
	test += p_object->get_class();
	test += " - " + p_string;
	test += " - " + itos(p_int);
	return test;
}

void MyTestMain::unbound_static_method1(MyTestMain *p_object, String p_string, int p_int) {
	String test = "unbound_static_method1: ";
	test += p_object->get_class();
	test += " - " + p_string;
	p_object->emit_custom_signal(test, p_int);
}

String MyTestMain::unbound_static_method2(Object *p_object, String p_string, int p_int) {
	String test = "unbound_static_method2: ";
	test += p_object->get_class();
	test += " - " + p_string;
	test += " - " + itos(p_int);
	return test;
}

int MyTestMain::test_tarray_arg(const TypedArray<int64_t> &p_array) {
	int sum = 0;
	for (int i = 0; i < p_array.size(); i++) {
		sum += (int)p_array[i];
	}
	return sum;
}

TypedArray<Vector2> MyTestMain::test_tarray() const {
	TypedArray<Vector2> arr;

	arr.resize(2);
	arr[0] = Vector2(1, 2);
	arr[1] = Vector2(2, 3);

	return arr;
}

Dictionary MyTestMain::test_dictionary() const {
	Dictionary dict;

	dict["hello"] = "world";
	dict["foo"] = "bar";

	return dict;
}

#if GODOT_VERSION_MINOR >= 4
int MyTestMain::test_tdictionary_arg(const TypedDictionary<String, int64_t> &p_dictionary) {
	int sum = 0;
	TypedArray<int64_t> values = p_dictionary.values();
	for (int i = 0; i < p_dictionary.size(); i++) {
		sum += (int)values[i];
	}
	return sum;
}

TypedDictionary<Vector2, Vector2i> MyTestMain::test_tdictionary() const {
	TypedDictionary<Vector2, Vector2i> dict;

	dict[Vector2(1, 2)] = Vector2i(2, 3);

	return dict;
}
#endif // GODOT_VERSION_MINOR >= 4

MyTestMain *MyTestMain::test_node_argument(MyTestMain *p_node) const {
	return p_node;
}

bool MyTestMain::test_object_cast_to_node(Object *p_object) const {
	return Object::cast_to<Node>(p_object) != nullptr;
}

bool MyTestMain::test_object_cast_to_control(Object *p_object) const {
	return Object::cast_to<Control>(p_object) != nullptr;
}

bool MyTestMain::test_object_cast_to_my_test_main(Object *p_object) const {
	return Object::cast_to<MyTestMain>(p_object) != nullptr;
}

Vector2i MyTestMain::test_variant_vector2i_conversion(const Variant &p_variant) const {
	return p_variant;
}

int MyTestMain::test_variant_int_conversion(const Variant &p_variant) const {
	return p_variant;
}

float MyTestMain::test_variant_float_conversion(const Variant &p_variant) const {
	return p_variant;
}

bool MyTestMain::test_object_is_valid(const Variant &p_variant) const {
	return static_cast<bool>(p_variant.get_validated_object());
}

void MyTestMain::test_add_child(Node *p_node) {
	add_child(p_node);
}

void MyTestMain::test_set_tileset(TileMap *p_tilemap, const Ref<TileSet> &p_tileset) const {
	p_tilemap->set_tileset(p_tileset);
}

bool MyTestMain::test_tween_smoke_test() {
	Ref<Tween> tween = create_tween();
	return tween.is_valid() && tween->is_class("Tween") && tween->get_reference_count() > 1;
}

Variant MyTestMain::test_variant_call(Variant p_variant) {
	return p_variant.call("test", "hello");
}

BitField<MyTestMain::Flags> MyTestMain::test_bitfield(BitField<Flags> flags) {
	return flags;
}

Variant MyTestMain::test_variant_iterator(const Variant &p_input) {
	Array output;

	Variant iter;

	bool is_init_valid = true;
	if (!p_input.iter_init(iter, is_init_valid)) {
		if (!is_init_valid) {
			return "iter_init: not valid";
		}
		return output;
	}

	bool is_iter_next_valid = true;
	bool is_iter_get_valid = true;
	do {
		if (!is_iter_next_valid) {
			return "iter_next: not valid";
		}

		Variant value = p_input.iter_get(iter, is_iter_get_valid);
		if (!is_iter_get_valid) {
			return "iter_get: not valid";
		}
		output.push_back(((int)value) + 5);

	} while (p_input.iter_next(iter, is_iter_next_valid));

	if (!is_iter_next_valid) {
		return "iter_next: not valid";
	}

	return output;
}

void MyTestMain::test_rpc(int p_value) {
	last_rpc_arg = p_value;
}

void MyTestMain::test_send_rpc(int p_value) {
	rpc("test_rpc", p_value);
}

int MyTestMain::return_last_rpc_arg() {
	return last_rpc_arg;
}

void MyTestMain::callable_bind() {
	Callable c = Callable(this, "emit_custom_signal").bind("bound", 11);
	c.call();
}

// Properties.
void MyTestMain::set_custom_position(const Vector2 &pos) {
	custom_position = pos;
}

Vector2 MyTestMain::get_custom_position() const {
	return custom_position;
}

Vector4 MyTestMain::get_v4() const {
	return Vector4(1.2, 3.4, 5.6, 7.8);
}

bool MyTestMain::test_post_initialize() const {
	Ref<MyTestRef> new_my_test_ref;
	new_my_test_ref.instantiate();
	return new_my_test_ref->was_post_initialized();
}

// Virtual function override.
bool MyTestMain::_has_point(const Vector2 &point) const {
	Label *label = get_node<Label>("Label");
	label->set_text("Got point: " + Variant(point).stringify());

	return false;
}

void MyTestMain::_input(const Ref<InputEvent> &event) {
	const InputEventKey *key_event = Object::cast_to<const InputEventKey>(*event);
	if (key_event) {
		emit_custom_signal(String("_input: ") + key_event->get_key_label(), key_event->get_unicode());
	}
}

void MyTestBase::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_value1"), &MyTestBase::get_value1);
	ClassDB::bind_method(D_METHOD("get_value2"), &MyTestBase::get_value2);
}

void MyTestBase::_notification(int p_what) {
	if (p_what == NOTIFICATION_ENTER_TREE) {
		value1 = 11;
		value2 = 22;
	}
}

void MyTestChild::_notification(int p_what) {
	if (p_what == NOTIFICATION_ENTER_TREE) {
		value2 = 33;
	}
}

String MyTestMain::test_virtual_implemented_in_script(const String &p_name, int p_value) {
	String ret;
	if (GDVIRTUAL_CALL(_do_something_virtual, p_name, p_value, ret)) {
		return ret;
	}
	return "Unimplemented";
}

String MyTestMain::test_use_engine_singleton() const {
	return OS::get_singleton()->get_name();
}

bool MyTestMain::test_use_scene_tree_singleton() const {
	SceneTree *scene_tree = SceneTree::get_singleton();
	return scene_tree != nullptr && scene_tree == get_tree();
}

String MyTestMain::test_library_path() {
	String library_path;
	::godot::gdextension_interface::get_library_path(::godot::gdextension_interface::library, library_path._native_ptr());
	return library_path;
}

Ref<RefCounted> MyTestMain::test_get_internal_class() const {
	Ref<MyTestInternal> it;
	it.instantiate();
	return it;
}

#if GODOT_VERSION_MINOR >= 4
int64_t MyTestMain::test_get_internal(const Variant &p_input) const {
	if (p_input.get_type() != Variant::INT) {
		return -1;
	}

	return *VariantInternal::get_int(&p_input);
}
#endif // GODOT_VERSION_MINOR >= 4

void MyTestRuntime::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_prop_value", "value"), &MyTestRuntime::set_prop_value);
	ClassDB::bind_method(D_METHOD("get_prop_value"), &MyTestRuntime::get_prop_value);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "prop_value"), "set_prop_value", "get_prop_value");
}

void MyTestRuntime::set_prop_value(int p_prop_value) {
	prop_value = p_prop_value;
}

int MyTestRuntime::get_prop_value() const {
	return prop_value;
}

MyTestRuntime::MyTestRuntime() {
}

MyTestRuntime::~MyTestRuntime() {
}

void MyTestPrzykład::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_the_word"), &MyTestPrzykład::get_the_word);
}

String MyTestPrzykład::get_the_word() const {
	return U"słowo to przykład";
}

void MyTestInternal::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_the_answer"), &MyTestInternal::get_the_answer);
}

int MyTestInternal::get_the_answer() const {
	return 42;
}

void MyTestThreadSafeClass::_bind_methods() {
	ClassDB::bind_method(D_METHOD("test"), &MyTestThreadSafeClass::test);
	ClassDB::bind_method(D_METHOD("test_const"), &MyTestThreadSafeClass::test_const);
	ClassDB::bind_method(D_METHOD("test_manual"), &MyTestThreadSafeClass::test_manual);
}

int MyTestThreadSafeClass::test() {
	_THREAD_SAFE_METHOD_
	return 123;
}

int MyTestThreadSafeClass::test_const() const {
	_THREAD_SAFE_METHOD_
	return 456;
}

int MyTestThreadSafeClass::test_manual() {
	_THREAD_SAFE_LOCK_
	_THREAD_SAFE_UNLOCK_
	return 789;
}
