@tool
extends Example

func _on_custom_signal( _msg, _value ) -> void:
	print_rich("[color=green] ******** PASSED ******** [/color]")
	get_tree().quit(0)


func _on_timeout():
	print_rich("[color=red] ******** FAILED ********[/color]")
	get_tree().quit(1)


func _ready() -> void:
	# Dont quit if the reload test isn't specified on the command line.
	if not 'test_reload' in OS.get_cmdline_args(): return

	print("gdscript:Reload Test is Enabled")
	# Connect to the custom signal of Example
	custom_signal.connect(_on_custom_signal)

	# Start 5s watchdog timer
	var timer = get_tree().create_timer(10.0)
	timer.timeout.connect(_on_timeout)

	print("Awaiting Custom Signal (with 10s timeout)")
