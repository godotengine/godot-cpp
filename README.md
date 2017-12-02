# cpp_bindings
C++ bindings for the Godot script API

# Creating a GDNative library (Linux)
Create a directory named `SimpleLibrary` with subdirectories `lib, src`

Getting latest `cpp_bindings` and `godot_headers`
```
$ cd SimpleLibrary
$ git clone https://github.com/GodotNativeTools/cpp_bindings
$ git clone https://github.com/GodotNativeTools/godot_headers
```
right now our directory structure should look like this
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

Building cpp_bindings
```
$ scons godotbinpath="<GODOT-FORK>/bin/" headers="<GODOT-FORK>/modules/gdnative/include/" p=linux generate_bindings=yes
```
resulting libraries will be placed under `bin/` and the generated headers will be placed under `include/*`

**Note:**
> `generate_bindings=yes` is used to generate C++ bindings (`godot_api.json` - Godot API)
> Include `use_llvm=yes` for using clang++

Copy binding libraries into the `SimpleLibrary/lib` folder
```
$ cd ..
$ cp cpp_bindings/bin/libgodot_cpp_bindings.a lib/
```
And our directory structure will be
```
[SimpleLibrary]
  ├── cpp_bindings/
  ├── godot_headers/
  ├── lib/
  │	  └──libgodot_cpp_bindings.a
  └── src/
```

# Creating simple class

Create `init.cpp` under `SimpleLibrary/src/` and add the following code
```
#include <core/Godot.hpp>
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
	   
	   /**
	    * How to register exports like gdscript
	    * export var _name = "SimpleClass"
	    **/
	   register_property((char *)"base/name", &SimpleClass::_name, String("SimpleClass"));

           /** For registering signal **/
           // register_signal<SimpleClass>("signal_name");
        }
	
	String _name;
};

/** GDNative Initialize **/
GDNATIVE_INIT(godot_gdnative_init_options *options) {

}

/** GDNative Terminate **/
GDNATIVE_TERMINATE(godot_gdnative_terminate_options *options) {

}

/** NativeScript Initialize **/
NATIVESCRIPT_INIT() {
        register_class<SimpleClass>();
}
```

# Compiling
```
$ cd ..
$ clang -fPIC -o src/init.os -c src/init.cpp -g -O3 -std=c++14 -Icpp_bindings/include -Igodot_headers
$ clang -o lib/libtest.so -shared src/init.os -Llib -lgodot_cpp_bindings
```
This creates the file `libtest.so` in your `SimpleLibrary/lib` directory. For windows you need to find out what compiler flags need to be used.

# Creating `.gdns` file
follow [godot_header/README.md](https://github.com/GodotNativeTools/godot_headers/blob/master/README.md#how-do-i-use-native-scripts-from-the-editor) to create the `.gdns` 

# Implementing with gdscript
```gdscript
var simpleclass = load("res://simpleclass.gdns").new();
simpleclass.method("Test argument");
```

