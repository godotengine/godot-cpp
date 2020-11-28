
extends MainLoop

func _initialize():
    OS.exit_code = 1
    var native_script = load("res://gdexample.gdns")
    print("Native Script ", native_script)
    if native_script == null || !is_instance_valid(native_script):
        return
    print("Library ", native_script.library)
    if native_script.library == null || !is_instance_valid(native_script.library):
        return
    var ref = native_script.new()
    print("Reference ", ref)
    if ref == null || !is_instance_valid(ref):
        return
    print("Reference name ", ref.name)
    if ref.name != "SimpleClass":
        return
    print("Reference value ", ref.value)
    if ref.value != 0:
        return
    print("Call method ", ref.method(1))
    if ref.method(1) != 1:
        return
    OS.exit_code = 0

func _idle(_delta):
    return true

