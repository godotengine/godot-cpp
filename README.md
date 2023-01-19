# godot-cpp

> **Warning**
>
> This repository's `master` branch is only usable with Godot 4.0 ([GDExtension](https://godotengine.org/article/introducing-gd-extensions)).
>
> Switch to the [`3.5` branch](https://github.com/godotengine/godot-cpp/tree/3.5)
> if using Godot 3.5.x with GDNative,
> or the [`3.x` branch](https://github.com/godotengine/godot-cpp/tree/3.x)
> if using the Godot 3.x development branch with GDNative.

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

> As the `master` branch of Godot is constantly getting updated, if you are
> using `godot-cpp` against a more current version of Godot, see the instructions
> in the `gdextension` folder to update the relevant files.

## Contributing

We greatly appreciate help in maintaining and extending this project. If you
wish to help out, ensure you have an account on GitHub and create a "fork" of
this repository. Rémi "Akien" Verschelde wrote an excellent bit of documentation
for the main Godot project on this:
[Pull request workflow](https://docs.godotengine.org/en/stable/community/contributing/pr_workflow.html)

Please install clang-format and copy the files in `misc/hooks` into `.git/hooks`
so formatting is done before your changes are submitted.

## Getting Started

It's a bit similar to what it was for 3.x but also a bit different.
This new approach is much more akin to how core Godot modules are structured.

Compiling this repository generates a static library to be linked with your shared lib,
just like before.

To use the shared lib in your Godot project you'll need a `.gdextension`
file, which replaces what was the `.gdnlib` before.
Follow [the example](test/demo/example.gdextension):

```ini
[configuration]

entry_symbol = "example_library_init"

[libraries]

macos.debug = "bin/libgdexample.macos.debug.framework"
macos.release = "bin/libgdexample.macos.release.framework"
windows.debug.x86_64 = "bin/libgdexample.windows.debug.x86_64.dll"
windows.release.x86_64 = "bin/libgdexample.windows.release.x86_64.dll"
linux.debug.x86_64 = "bin/libgdexample.linux.debug.x86_64.so"
linux.release.x86_64 = "bin/libgdexample.linux.release.x86_64.so"
# Repeat for other architectures to support arm64, rv64, etc.
```

The `entry_symbol` is the name of the function that initializes
your library. It should be similar to following layout:

```cpp
extern "C" {

// Initialization.

GDExtensionBool GDE_EXPORT example_library_init(const GDExtensionInterface *p_interface, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
	godot::GDExtensionBinding::InitObject init_obj(p_interface, p_library, r_initialization);

	init_obj.register_initializer(initialize_example_module);
	init_obj.register_terminator(uninitialize_example_module);
	init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

	return init_obj.init();
}
}
```

The `initialize_example_module()` should register the classes in ClassDB, very like a Godot module would do.

```cpp
using namespace godot;
void initialize_example_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
	ClassDB::register_class<Example>();
}
```

Any node and resource you register will be available in the corresponding `Create...` dialog. Any class will be available to scripting as well.

## Included Example

Check the project in the `test` folder for an example on how to use and register different things.
