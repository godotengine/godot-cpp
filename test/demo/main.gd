extends Node

func _ready():
	# Connect signals.
	$Button.button_up.connect($Example.emit_custom_signal, ["Button", 42])
	$Example.custom_signal.connect(on_signal)

	# Call methods.
	$Example.simple_func()
	($Example as Example).simple_const_func() # Force use of ptrcall
	prints("returned", $Example.return_something("some string"))
	prints("returned const", $Example.return_something_const())
	prints("vararg args", $Example.varargs_func("some", "arguments", "to", "test"))

	# Use properties.
	prints("custom position is", $Example.group_subgroup_custom_position)
	$Example.group_subgroup_custom_position = Vector2(50, 50)
	prints("custom position now is", $Example.group_subgroup_custom_position)

	# Get constants
	prints("FIRST", $Example.FIRST)
	prints("ANSWER_TO_EVERYTHING", $Example.ANSWER_TO_EVERYTHING)
	prints("CONSTANT_WITHOUT_ENUM", $Example.CONSTANT_WITHOUT_ENUM)

func on_signal(name, value):
	prints("Example emitted:", name, value)
