extends "res://test_base.gd"

var custom_signal_emitted = null

class TestClass:
	func test(p_msg: String) -> String:
		return p_msg + " world"

func _ready():
	var example: Example = $Example

	# Signal.
	example.emit_custom_signal("Button", 42)
	assert_equal(custom_signal_emitted, ["Button", 42])

	# To string.
	assert_equal(example.to_string(),'Example:[ GDExtension::Example <--> Instance ID:%s ]' % example.get_instance_id())
	# It appears there's a bug with instance ids :-(
	#assert_equal($Example/ExampleMin.to_string(), 'ExampleMin:[Wrapped:%s]' % $Example/ExampleMin.get_instance_id())

	# Call static methods.
	assert_equal(Example.test_static(9, 100), 109);
	# It's void and static, so all we know is that it didn't crash.
	Example.test_static2()

	# Property list.
	example.property_from_list = Vector3(100, 200, 300)
	assert_equal(example.property_from_list, Vector3(100, 200, 300))
	var prop_list = example.get_property_list()
	for prop_info in prop_list:
		if prop_info['name'] == 'mouse_filter':
			assert_equal(prop_info['usage'], PROPERTY_USAGE_NO_EDITOR)

	# Call simple methods.
	example.simple_func()
	assert_equal(custom_signal_emitted, ['simple_func', 3])
	example.simple_const_func()
	assert_equal(custom_signal_emitted, ['simple_const_func', 4])

	# Pass custom reference.
	assert_equal(example.custom_ref_func(null), -1)
	var ref1 = ExampleRef.new()
	ref1.id = 27
	assert_equal(example.custom_ref_func(ref1), 27)
	ref1.id += 1;
	assert_equal(example.custom_const_ref_func(ref1), 28)

	# Pass core reference.
	assert_equal(example.image_ref_func(null), "invalid")
	assert_equal(example.image_const_ref_func(null), "invalid")
	var image = Image.new()
	assert_equal(example.image_ref_func(image), "valid")
	assert_equal(example.image_const_ref_func(image), "valid")

	# Return values.
	assert_equal(example.return_something("some string"), "some string42")
	assert_equal(example.return_something_const(), get_viewport())
	var null_ref = example.return_empty_ref()
	assert_equal(null_ref, null)
	var ret_ref = example.return_extended_ref()
	assert_not_equal(ret_ref.get_instance_id(), 0)
	assert_equal(ret_ref.get_id(), 0)
	assert_equal(example.get_v4(), Vector4(1.2, 3.4, 5.6, 7.8))
	assert_equal(example.test_node_argument(example), example)

	# VarArg method calls.
	var var_ref = ExampleRef.new()
	assert_not_equal(example.extended_ref_checks(var_ref).get_instance_id(), var_ref.get_instance_id())
	assert_equal(example.varargs_func("some", "arguments", "to", "test"), 4)
	assert_equal(example.varargs_func_nv("some", "arguments", "to", "test"), 46)
	example.varargs_func_void("some", "arguments", "to", "test")
	assert_equal(custom_signal_emitted, ["varargs_func_void", 5])

	# Method calls with default values.
	assert_equal(example.def_args(), 300)
	assert_equal(example.def_args(50), 250)
	assert_equal(example.def_args(50, 100), 150)

	# Array and Dictionary
	assert_equal(example.test_array(), [1, 2])
	assert_equal(example.test_tarray(), [ Vector2(1, 2), Vector2(2, 3) ])
	assert_equal(example.test_dictionary(), {"hello": "world", "foo": "bar"})
	var array: Array[int] = [1, 2, 3]
	assert_equal(example.test_tarray_arg(array), 6)

	example.callable_bind()
	assert_equal(custom_signal_emitted, ["bound", 11])

	# String += operator
	assert_equal(example.test_string_ops(), "ABCĎE")

	# UtilityFunctions::str()
	assert_equal(example.test_str_utility(), "Hello, World! The answer is 42")

	# Test converting string to char* and doing comparison.
	assert_equal(example.test_string_is_forty_two("blah"), false)
	assert_equal(example.test_string_is_forty_two("forty two"), true)

	# String::resize().
	assert_equal(example.test_string_resize("What"), "What!?")

	# mp_callable() with void method.
	var mp_callable: Callable = example.test_callable_mp()
	assert_equal(mp_callable.is_valid(), true)
	mp_callable.call(example, "void", 36)
	assert_equal(custom_signal_emitted, ["unbound_method1: Example - void", 36])

	# Check that it works with is_connected().
	assert_equal(example.renamed.is_connected(mp_callable), false)
	example.renamed.connect(mp_callable)
	assert_equal(example.renamed.is_connected(mp_callable), true)
	# Make sure a new object is still treated as equivalent.
	assert_equal(example.renamed.is_connected(example.test_callable_mp()), true)
	assert_equal(mp_callable.hash(), example.test_callable_mp().hash())
	example.renamed.disconnect(mp_callable)
	assert_equal(example.renamed.is_connected(mp_callable), false)

	# mp_callable() with return value.
	var mp_callable_ret: Callable = example.test_callable_mp_ret()
	assert_equal(mp_callable_ret.call(example, "test", 77), "unbound_method2: Example - test - 77")

	# mp_callable() with const method and return value.
	var mp_callable_retc: Callable = example.test_callable_mp_retc()
	assert_equal(mp_callable_retc.call(example, "const", 101), "unbound_method3: Example - const - 101")

	# mp_callable_static() with void method.
	var mp_callable_static: Callable = example.test_callable_mp_static()
	mp_callable_static.call(example, "static", 83)
	assert_equal(custom_signal_emitted, ["unbound_static_method1: Example - static", 83])

	# Check that it works with is_connected().
	assert_equal(example.renamed.is_connected(mp_callable_static), false)
	example.renamed.connect(mp_callable_static)
	assert_equal(example.renamed.is_connected(mp_callable_static), true)
	# Make sure a new object is still treated as equivalent.
	assert_equal(example.renamed.is_connected(example.test_callable_mp_static()), true)
	assert_equal(mp_callable_static.hash(), example.test_callable_mp_static().hash())
	example.renamed.disconnect(mp_callable_static)
	assert_equal(example.renamed.is_connected(mp_callable_static), false)

	# mp_callable_static() with return value.
	var mp_callable_static_ret: Callable = example.test_callable_mp_static_ret()
	assert_equal(mp_callable_static_ret.call(example, "static-ret", 84), "unbound_static_method2: Example - static-ret - 84")

	# CallableCustom.
	var custom_callable: Callable = example.test_custom_callable();
	assert_equal(custom_callable.is_custom(), true);
	assert_equal(custom_callable.is_valid(), true);
	assert_equal(custom_callable.call(), "Hi")
	assert_equal(custom_callable.hash(), 27);
	assert_equal(custom_callable.get_object(), null);
	assert_equal(custom_callable.get_method(), "");
	assert_equal(str(custom_callable), "<MyCallableCustom>");

	# PackedArray iterators
	assert_equal(example.test_vector_ops(), 105)
	assert_equal(example.test_vector_init_list(), 105)

	# Properties.
	assert_equal(example.group_subgroup_custom_position, Vector2(0, 0))
	example.group_subgroup_custom_position = Vector2(50, 50)
	assert_equal(example.group_subgroup_custom_position, Vector2(50, 50))

	# Test Object::cast_to<>() and that correct wrappers are being used.
	var control = Control.new()
	var sprite = Sprite2D.new()
	var example_ref = ExampleRef.new()

	assert_equal(example.test_object_cast_to_node(control), true)
	assert_equal(example.test_object_cast_to_control(control), true)
	assert_equal(example.test_object_cast_to_example(control), false)

	assert_equal(example.test_object_cast_to_node(example), true)
	assert_equal(example.test_object_cast_to_control(example), true)
	assert_equal(example.test_object_cast_to_example(example), true)

	assert_equal(example.test_object_cast_to_node(sprite), true)
	assert_equal(example.test_object_cast_to_control(sprite), false)
	assert_equal(example.test_object_cast_to_example(sprite), false)

	assert_equal(example.test_object_cast_to_node(example_ref), false)
	assert_equal(example.test_object_cast_to_control(example_ref), false)
	assert_equal(example.test_object_cast_to_example(example_ref), false)

	control.queue_free()
	sprite.queue_free()

	# Test that passing null for objects works as expected too.
	var example_null : Example = null
	assert_equal(example.test_object_cast_to_node(example_null), false)

	# Test conversions to and from Variant.
	assert_equal(example.test_variant_vector2i_conversion(Vector2i(1, 1)), Vector2i(1, 1))
	assert_equal(example.test_variant_vector2i_conversion(Vector2(1.0, 1.0)), Vector2i(1, 1))
	assert_equal(example.test_variant_int_conversion(10), 10)
	assert_equal(example.test_variant_int_conversion(10.0), 10)
	assert_equal(example.test_variant_float_conversion(10.0), 10.0)
	assert_equal(example.test_variant_float_conversion(10), 10.0)

	# Test that ptrcalls from GDExtension to the engine are correctly encoding Object and RefCounted.
	var new_node = Node.new()
	example.test_add_child(new_node)
	assert_equal(new_node.get_parent(), example)

	var new_tileset = TileSet.new()
	var new_tilemap = TileMap.new()
	example.test_set_tileset(new_tilemap, new_tileset)
	assert_equal(new_tilemap.tile_set, new_tileset)
	new_tilemap.queue_free()

	# Test variant call.
	var test_obj = TestClass.new()
	assert_equal(example.test_variant_call(test_obj), "hello world")

	# Constants.
	assert_equal(Example.FIRST, 0)
	assert_equal(Example.ANSWER_TO_EVERYTHING, 42)
	assert_equal(Example.CONSTANT_WITHOUT_ENUM, 314)

	# BitFields.
	assert_equal(Example.FLAG_ONE, 1)
	assert_equal(Example.FLAG_TWO, 2)
	assert_equal(example.test_bitfield(0), 0)
	assert_equal(example.test_bitfield(Example.FLAG_ONE | Example.FLAG_TWO), 3)

	# Test variant iterator.
	assert_equal(example.test_variant_iterator([10, 20, 30]), [15, 25, 35])
	assert_equal(example.test_variant_iterator(null), "iter_init: not valid")

	# RPCs.
	assert_equal(example.return_last_rpc_arg(), 0)
	example.test_rpc(42)
	assert_equal(example.return_last_rpc_arg(), 42)
	example.test_send_rpc(100)
	assert_equal(example.return_last_rpc_arg(), 100)

	# Virtual method.
	var event = InputEventKey.new()
	event.key_label = KEY_H
	event.unicode = 72
	get_viewport().push_input(event)
	assert_equal(custom_signal_emitted, ["_input: H", 72])

	# Check NOTIFICATION_POST_INITIALIZED, both when created from GDScript and godot-cpp.
	var new_example_ref = ExampleRef.new()
	assert_equal(new_example_ref.was_post_initialized(), true)
	assert_equal(example.test_post_initialize(), true)

	# Test that we can access an engine singleton.
	assert_equal(example.test_use_engine_singleton(), OS.get_name())

	# Test that notifications happen on both parent and child classes.
	var example_child = $ExampleChild
	assert_equal(example_child.get_value1(), 11)
	assert_equal(example_child.get_value2(), 33)
	example_child.notification(NOTIFICATION_ENTER_TREE, true)
	assert_equal(example_child.get_value1(), 11)
	assert_equal(example_child.get_value2(), 22)

	exit_with_status()

func _on_Example_custom_signal(signal_name, value):
	custom_signal_emitted = [signal_name, value]
