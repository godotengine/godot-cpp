# cpp_bindings
C++ bindings for the Godot script API

# Creating a GDNative library (Linux)
Create a director named `SimpleLibrary` with subdirector `lib, src`

Getting latest `cpp_bindings` and `godot_headers`
```
$ cd SimpleLibrary
$ git clone https://github.com/GodotNativeTools/cpp_bindings
$ git clone https://github.com/GodotNativeTools/godot_headers
```
right now our file structure should look like this
```
[SimpleLibrary]
	├── cpp_bindings/
	├── godot_headers/
	├── lib/
	└── src/
```

Now to generate cpp bindings
```
$ cd cpp_bindings
```

Edit `SConstruct` file and assign your godot executable path at line:7 `godot_bin_path = "../godot_fork/bin/"`,

Building core/bindings, (`libgodot_cpp_core.so` , `libgodot_cpp_bindings.so`)
```
$ scons p=linux
$ scons p=linux target=bindings generate_bindings=yes
```
resulting libraries will be placed under `bin/` and generated bindings will be found under `includes/*`

Note: Use `use_llvm=yes` to use clang.

copy Core && Bindings librarys into `SimpleLibrary/lib` folder
```
$ cd ..
$ cp cpp_bindings/bin/libgodot_cpp_core.so lib/
$ cp cpp_bindings/bin/libgodot_cpp_bindings.so lib/
```
And our file structure will be
```
[SimpleLibrary]
  ├── cpp_bindings/
  ├── godot_headers/
  ├── lib/
  │       ├── libgodot_cpp_core.so
  │       ├── libgodot_cpp_bindings.so
  └── src/
```

# Creating simple class

Create `init.cpp` under `SimpleLibrary/src/` and add the following code
```
#include <godot.h>

#include <core/Godot.hpp>
#include <core/GodotGlobal.hpp>
#include <Reference.hpp>

using namespace godot;

class SimpleClass : public GodotScript<Reference> {
        GODOT_CLASS(SimpleClass);
public:
        SimpleClass() { }

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
        }
};

GODOT_NATIVE_INIT(godot_native_init_options *options) {
        register_class<SimpleClass>();
}
```

# Compiling
```
$ cd ..
$ clang -fPIC -o src/init.os -c src/init.cpp -g -O3 -std=c++14 -Icpp_bindings/include -Igodot_headers -Icpp_bindings/include/core
$ clang -o lib/libtest.so -shared src/init.os -Llib -lgodot_cpp_core -lgodot_cpp_bindings
```
This creates the file `libtest.so` in your `SimpleLibrary/lib` directory. For windows you need to find out what compiler flags need to be used.

# Creating `.gdn` file
follow [godot_header/README.md](https://github.com/GodotNativeTools/godot_headers/blob/master/README.md) file to create the `.gdn`

# Implementing with gdscript
```
var simpleclass = load("res://simpleclass.gdn").new();
simpleclass.method("Test argument");
```
