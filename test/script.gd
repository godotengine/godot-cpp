
extends MainLoop

func _initialize():
    OS.exit_code = 1
    var native_script = load("res://gdexample.gdns")
    print("NativeScript ", native_script)
    if native_script == null || !is_instance_valid(native_script):
        print("NativeScript invalid")
        return
    print("Library ", native_script.library)
    if native_script.library == null || !is_instance_valid(native_script.library):
        print("Library invalid")
        return
    var ref = native_script.new()
    print("RefCounted ", ref)
    if ref == null || !is_instance_valid(ref):
        print("RefCounted invalid")
        return
    print("RefCounted value ", ref.value)
    if ref.value != 50:
        print("RefCounted value mismatch")
        return
    print("RefCounted vec ", ref.vec)
    if ref.vec != Vector2(10, 20):
        print("RefCounted vec mismatch")
        return
    print("RefCounted name ", ref.name)
    if ref.name != "SimpleClass":
        print("RefCounted name mismatch")
        return
    print("Call method ", ref.method(1))
    if ref.method(1) != 1:
        print("Call method mismatch")
        return
    print("All tests passed")
    OS.exit_code = 0

func _process(_delta):
    return true
