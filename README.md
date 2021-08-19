# godot-cpp

C++ bindings for the Godot extension API.

**Note: this is a work in progress for the extension system included in Godot 4.0**

## Stub

Both this whole bindings system and this document are still work in progress and
thus it is still incomplete. It will be improved once the extension API is settled.

## How to use

It's a bit similar to what it was for 3.x but also a bit different.

Compiling this repository generates a static library to be linked with your shared lib,
just like before.

To use the shared lib in your Godot project you'll need a `.gdextension` file, which replaces what was the `.gdnlib`before. Follow the example:

```ini
[configuration]

entry_symbol = "example_library_init"

[libraries]

Linux.64 = "bin/x11/libgdexample.so"
```

The `entry_symbol` is the name of the function that initializes your library. It should be similar to following layout:

```cpp
extern "C" {
GDNativeBool GDN_EXPORT example_library_init(const GDNativeInterface *p_interface, const GDNativeExtensionClassLibraryPtr p_library, GDNativeInitialization *r_initialization) {
	GDNativeBool result = godot::GDExtensionBinding::init(p_interface, p_library, r_initialization);

	if (result) {
		register_example_types();
	}

	return result;
}
}
```

The `register_example_types()` should register the classes in ClassDB, very like a Godot module would do.

```cpp
using namespace godot;
void register_example_types() {
	ClassDB::register_class<Example>();
}
```

Extension registering has not yet been added to the Godot editor, so to make it recognize your extension you need to add the following section to your `project.godot`:

```ini
[native_extensions]

paths=["res://example.gdextension"]
```

Any node and resource you register will be available in the corresponding `Create...` dialog. Any class will be available to scripting as well.

## Example

Check the project in the `test` folder for an example on how to use and register different things.

This project isn't yet made to run in CI.

## Issues

This really needs to be tested and very likely has things missing that weren't noticed yet. Use at your own risk (and contribute back with reports and fixes if you can).
