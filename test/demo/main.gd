extends Node

var signal_emitted = false

func _ready():
	var ret = $Example.my_method("Arg", FOO)
	assert(ret == "ArgFoo")
	var ret = $Example.my_method("Arg", BAR)
	assert(ret == "ArgBar")

	var ret = $Example.my_varargs_method(Null, 1, 2, "3")
	assert(ret == 4)

	var ret = $Example.my_static_method(1, 2)
	assert(ret == 3)

	$Example.my_prop = Vector2(1, 2)
	assert($Example.my_prop == Vector2(1, 2))

	$Example.emit_signal("my_signal", 42)
	assert(signal_emitted == true)

	# All good, exiting ;-)
	get_tree().quit(0)

func _on_Example_my_signal(signal_name, value):
	signal_emitted = value == 42
