# godot-cpp

This repository contains the  *C++ bindings* for the [**Godot Engine**](https://github.com/godotengine/godot)'s GDExtensions API.

- [**Versioning**](#versioning)
- [**Contributing**](#contributing)
- [**Getting Started**](#getting-started)
- [**Included Example**](#included-example)

## Versioning

This repositories follows the same branch versioning as the main [Godot Engine
repository](https://github.com/godotengine/godot):

- `master` tracks the current development branch.
- `3.x` tracks the development of the next 3.x minor release.
- Other versioned branches (e.g. `3.3`, `3.2`) track the latest stable release
  in the corresponding branch.

Stable releases are also tagged on this repository:
[**Tags**](https://github.com/godotengine/godot-cpp/tags).

**For any project built against a stable release of Godot, we recommend using
this repository as a Git submodule, checking out the specific tag matching your
Godot version.**

> As the `master` and `3.x` branches are constantly getting updates, if you are
> using `godot-cpp` against a more current version of Godot, see the instructions
> in [**godot-headers**](https://github.com/godotengine/godot-headers) for
> updating the relevant files.

## Contributing

We greatly appreciate help in maintaining and extending this project. If you
wish to help out, ensure you have an account on GitHub and create a "fork" of
this repository. Rémi "Akien" Verschelde wrote an excellent bit of documentation
for the main Godot project on this:
[Pull request workflow](https://docs.godotengine.org/en/stable/community/contributing/pr_workflow.html)

Please install clang-format and copy the files in `misc/hooks` into `.git/hooks`
so formatting is done before your changes are submitted.

## Getting Started

It's a bit similar to what it was for 3.x but also a bit different. This new approach is much more akin to how core Godot modules are structured.

Compiling this repository generates a static library to be linked with your shared lib,
just like before.

To use the shared lib in your Godot project you'll need a `.gdextension` file, which replaces what was the `.gdnlib` before. Follow the example:

```ini
[configuration]

entry_symbol = "example_library_init"

[libraries]

linux.64.debug = "bin/libgdexample.linux.debug.64.so"
linux.64.release = "bin/libgdexample.linux.release.64.so"
windows.64.debug = "bin/libgdexample.windows.debug.64.dll"
windows.64.release = "bin/libgdexample.windows.release.64.dll"
macos.debug = "bin/libgdexample.debug.framework"
macos.release = "bin/libgdexample.release.framework"
```

The `entry_symbol` is the name of the function that initializes your library. It should be similar to following layout:

```cpp
extern "C" {

// Initialization.

GDNativeBool GDN_EXPORT example_library_init(const GDNativeInterface *p_interface, const GDNativeExtensionClassLibraryPtr p_library, GDNativeInitialization *r_initialization) {
	godot::GDExtensionBinding::InitObject init_obj(p_interface, p_library, r_initialization);

	init_obj.register_scene_initializer(register_example_types);
	init_obj.register_scene_terminator(unregister_example_types);

	return init_obj.init();
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

Any node and resource you register will be available in the corresponding `Create...` dialog. Any class will be available to scripting as well.

## Included Example

Check the project in the `test` folder for an example on how to use and register different things.
