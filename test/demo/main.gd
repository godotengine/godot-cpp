extends Node

func _ready():
	# Bind signals
	prints("Signal bind")
	$Button.button_up.connect($Example.emit_custom_signal.bind("Button", 42))

	prints("")

	# To string.
	prints("To string")
	prints("  Example --> ", $Example.to_string())
	prints("  ExampleMin --> ", $Example/ExampleMin.to_string())

	# Call static methods.
	prints("Static method calls")
	prints("  static (109)", Example.test_static(9, 100));
	Example.test_static2();

	# Property list.
	prints("Property list")
	$Example.property_from_list = Vector3(100, 200, 300)
	prints("  property value ", $Example.property_from_list)

	# Call methods.
	prints("Instance method calls")
	$Example.simple_func()
	($Example as Example).simple_const_func() # Force use of ptrcall
	prints("  returned", $Example.return_something("some string"))
	prints("  returned const", $Example.return_something_const())
	var null_ref = $Example.return_empty_ref()
	prints("  returned empty ref", null_ref)
	var ret_ref = $Example.return_extended_ref()
	prints("  returned ref", ret_ref.get_instance_id(), ", id:", ret_ref.get_id())
	prints("  returned ", $Example.get_v4())
	prints("  test node argument", $Example.test_node_argument($Example))

	prints("VarArg method calls")
	var ref = ExampleRef.new()
	prints("  sending ref: ", ref.get_instance_id(), "returned ref: ", $Example.extended_ref_checks(ref).get_instance_id())
	prints("  vararg args", $Example.varargs_func("some", "arguments", "to", "test"))
	prints("  vararg_nv ret", $Example.varargs_func_nv("some", "arguments", "to", "test"))
	$Example.varargs_func_void("some", "arguments", "to", "test")

	prints("Method calls with default values")
	prints("  defval (300)", $Example.def_args())
	prints("  defval (250)", $Example.def_args(50))
	prints("  defval (150)", $Example.def_args(50, 100))

	prints("Array and Dictionary")
	prints("  test array", $Example.test_array())
	prints("  test tarray", $Example.test_tarray())
	prints("  test dictionary", $Example.test_dictionary())
	var array: Array[int] = [1, 2, 3]
	$Example.test_tarray_arg(array)

	prints("String += operator")
	prints("  test string +=", $Example.test_string_ops())

	prints("PackedArray iterators")
	prints("  test packed array iterators", $Example.test_vector_ops())

	prints("Properties")
	prints("  custom position is", $Example.group_subgroup_custom_position)
	$Example.group_subgroup_custom_position = Vector2(50, 50)
	prints("  custom position now is", $Example.group_subgroup_custom_position)

	prints("Constants")
	prints("  FIRST", $Example.FIRST)
	prints("  ANSWER_TO_EVERYTHING", $Example.ANSWER_TO_EVERYTHING)
	prints("  CONSTANT_WITHOUT_ENUM", $Example.CONSTANT_WITHOUT_ENUM)

	prints("BitFields")
	prints("  FLAG_ONE", Example.FLAG_ONE)
	prints("  FLAG_TWO", Example.FLAG_TWO)
	prints("  returned BitField", $Example.test_bitfield(0))
	prints("  returned BitField", $Example.test_bitfield(Example.FLAG_ONE | Example.FLAG_TWO))

func _on_Example_custom_signal(signal_name, value):
	prints("Example emitted:", signal_name, value)
