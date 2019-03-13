# godot-cpp
C++ bindings for the Godot script API

The instructions below feature the new NativeScript 1.1 class structure and will only work for modules created for Godot 3.1 and later. Use the following branches for older implementations:

Version | Branch
--- | ---
**Godot 3.0 Nativescript 1.0** | [3.0](https://github.com/GodotNativeTools/godot-cpp/tree/3.0)
**Godot 3.1 Nativescript 1.0** | [nativescript-1.0](https://github.com/GodotNativeTools/godot-cpp/tree/nativescript-1.0)

Index:
-   [**Contributing**](#contributing)
-   [**Getting Started**](#getting-started)
-   [**Creating a simple class**](#creating-a-simple-class)

## Contributing
We greatly appreciate help in maintaining and extending this project. 
If you wish to help out ensure you have an account on Github and create a "fork" of the this repo.
Rémi "Akien" Verschelde wrote an excellent bit of documentation for the main Godot project on this: 
https://docs.godotengine.org/en/3.0/community/contributing/pr_workflow.html

It is advisible to also install clang-format and copy the files in `misc/hooks` into `.git/hooks` so format checking is done before your changes are submitted.

## Getting Started

| **Build latest version of Godot** | [**GitHub**](https://github.com/godotengine/godot) | [**Docs**](https://godot.readthedocs.io/en/latest/development/compiling/index.html) |
| --- | --- | --- |

### Setting up a new project

We recommend using git for managing your project and the instructions below assume so. Alternatively you can download the source code directly from GitHub in which case you need to download both [godot-cpp](https://github.com/GodotNativeTools/godot-cpp) and [godot_headers](https://github.com/GodotNativeTools/godot_headers).

```
$ mkdir SimpleLibrary
$ cd SimpleLibrary
$ mkdir bin
$ mkdir src
$ git clone --recursive https://github.com/GodotNativeTools/godot-cpp
```

Note that if you wish to use a specific branch, add the -b option to the clone command:
```
$ git clone --recursive https://github.com/GodotNativeTools/godot-cpp -b 3.0
```

If your project is an existing repository, use git submodule instead:
```
$ git submodule add https://github.com/GodotNativeTools/godot-cpp
$ git submodule update --init --recursive
```

Right now our directory structure should look like this:
```
SimpleLibrary/
├─godot-cpp/
| └─godot_headers/
├─bin/
└─src/
```

### Updating the api.json
Our api.json file contains meta data of all the classes that are part of the Godot core and are needed to generate the C++ binding classes for use in GDNative modules. 

This file is supplied with our godot_headers repository for your convinience but if you are running a custom build of Godot and need access to classes that have recent changes a new api.json file must be generated. You do this by starting your Godot executable with the following parameters:

```
$ godot --gdnative-generate-json-api api.json
```

Now copy the api.json file into your folder structure so its easy to access. **Note** the remark below for the extra ```custom_api_file``` command line parameter needed to tell scons where to find your file.

### Compiling the cpp bindings library
The final step is to compile our cpp bindings library:
```
$ cd godot-cpp
$ scons platform=<your platform> generate_bindings=yes
$ cd ..
```

> Replace `<your platform>` with either `windows`, `linux` or `osx`.

> Include `use_llvm=yes` for using clang++

> Include `target=runtime` to build a runtime build (windows only at the moment)

> The resulting library will be created in `godot-cpp/bin/`, take note of its name as it will be different depending on platform.

> If you want to use an alternative api.json file add `use_custom_api_file=yes custom_api_file=../api.json`, be sure to specify the correct location of where you placed your file.

## Creating a simple class

Create `init.cpp` under `SimpleLibrary/src/` and add the following code
```cpp
#include <Godot.hpp>
#include <Reference.hpp>

using namespace godot;

class SimpleClass : public Reference {
    GODOT_CLASS(SimpleClass, Reference);
public:
    SimpleClass() { }

    /* _init must exist as it is called by Godot */
    void _init() { }

    void test_void_method() {
        Godot::print("This is test");
    }

    Variant method(Variant arg) {
        Variant ret;
        ret = arg;

        return ret;
    }

    static void _register_methods() {
        register_method("method", &SimpleClass::method);
        
        /**
         * How to register exports like gdscript
         * export var _name = "SimpleClass"
         **/
        register_property<SimpleClass, String>("base/name", &SimpleClass::_name, String("SimpleClass"));

        /* or alternatively with getter and setter methods */
        register_property<SimpleClass, int>("base/value", &SimpleClass::set_value, &SimpleClass::get_value, 0);

        /** For registering signal **/
        // register_signal<SimpleClass>("signal_name");
        // register_signal<SimpleClass>("signal_name", "string_argument", GODOT_VARIANT_TYPE_STRING)
    }
    
    String _name;
    int _value;

    void set_value(int p_value) {
        _value = p_value;
    }

    int get_value() const {
        return _value;
    }
};

/** GDNative Initialize **/
extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options *o) {
    godot::Godot::gdnative_init(o);
}

/** GDNative Terminate **/
extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options *o) {
    godot::Godot::gdnative_terminate(o);
}

/** NativeScript Initialize **/
extern "C" void GDN_EXPORT godot_nativescript_init(void *handle) {
    godot::Godot::nativescript_init(handle);

    godot::register_class<SimpleClass>();
}
```

### Compiling

*Linux*
```
$ cd SimpleLibrary
$ clang -fPIC -o src/init.os -c src/init.cpp -g -O3 -std=c++14 -Igodot-cpp/include -Igodot-cpp/include/core -Igodot-cpp/include/gen -Igodot-cpp/godot_headers
$ clang -o bin/libtest.so -shared src/init.os -Lgodot-cpp/bin -l<name of the godot-cpp>
```
> This creates the file `libtest.so` in your `SimpleLibrary/bin` directory.

> You will need to replace `<name of the godot-cpp>` with the file that was created in [**Compiling the cpp bindings library**](#compiling-the-cpp-bindings-library)

*Windows*
```
$ cd SimpleLibrary
$ cl /Fosrc/init.obj /c src/init.cpp /nologo -EHsc -DNDEBUG /MDd /Igodot-cpp\include /Igodot-cpp\include\core /Igodot-cpp\include\gen /Igodot-cpp\godot_headers
$ link /nologo /dll /out:bin\libtest.dll /implib:bin\libsimple.lib src\init.obj godot-cpp\bin\<name of the godot-cpp>
```
> This creates the file `libtest.dll` in your `SimpleLibrary/bin` directory.

> You will need to replace `<name of the godot-cpp>` with the file that was created in [**Compiling the cpp bindings library**](#compiling-the-cpp-bindings-library)

> Finally replace `/MDd` with `/MD` if you're generated a runtime build.

*macOS*
For OSX you need to find out what compiler flags need to be used.

### Creating `.gdnlib` and `.gdns` files
follow [godot_header/README.md](https://github.com/GodotNativeTools/godot_headers/blob/master/README.md#how-do-i-use-native-scripts-from-the-editor) to create the `.gdns` 

### Implementing with gdscript
```gdscript
var simpleclass = load("res://simpleclass.gdns").new();
simpleclass.method("Test argument");
```

