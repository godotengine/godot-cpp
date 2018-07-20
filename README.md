# godot-cpp
C++ bindings for the Godot script API

# Creating a GDNative library (Linux)
Create a directory named `SimpleLibrary` with subdirectories `lib, src`

Getting latest `godot-cpp` and `godot_headers`
```
$ git clone https://github.com/GodotNativeTools/godot-cpp
$ git clone https://github.com/GodotNativeTools/godot_headers
```
right now our directory structure should look like this:
```
godot-cpp
godot_headers
SimpleLibrary
├── lib/
└── src/
```

Now to generate cpp bindings
```
$ cd godot-cpp
$ scons godotbinpath="../godot_fork/bin/godot_binary" p=linux
$ cd ..
```
resulting libraries will be placed under `bin/` and the generated headers will be placed under `include/*`

**Note:**
> `generate_bindings=yes` is used to force regenerating C++ bindings (`godot_api.json` - Godot API)

> Include `use_llvm=yes` for using clang++

> You may need to specify `headers=../godot_headers` if you have compilation issues related to missing include files

And our directory structure will be
```
godot-cpp
└── bin/libgodot-cpp.a
godot_headers
SimpleLibrary
├── lib/
└── src/
```

# Creating simple class

Create `init.cpp` under `SimpleLibrary/src/` and add the following code
```cpp
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
           // register_signal<SimpleClass>("signal_name", "string_argument", GODOT_VARIANT_TYPE_STRING)
        }
	
	String _name;
};

/** GDNative Initialize **/
extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options *o)
{
    godot::Godot::gdnative_init(o);
}

/** GDNative Terminate **/
extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options *o)
{
    godot::Godot::gdnative_terminate(o);
}

/** NativeScript Initialize **/
extern "C" void GDN_EXPORT godot_nativescript_init(void *handle)
{
    godot::Godot::nativescript_init(handle);

    godot::register_class<SimpleClass>();
}
```

# Compiling
```
$ cd SimpleLibrary
$ clang -fPIC -o src/init.os -c src/init.cpp -g -O3 -std=c++14 -I../godot-cpp/include -Igodot_headers
$ clang -o lib/libtest.so -shared src/init.os -L../godot-cpp/lib -lgodot-cpp
```
This creates the file `libtest.so` in your `SimpleLibrary/lib` directory. For windows you need to find out what compiler flags need to be used.

# Creating `.gdns` file
follow [godot_header/README.md](https://github.com/GodotNativeTools/godot_headers/blob/master/README.md#how-do-i-use-native-scripts-from-the-editor) to create the `.gdns` 

# Implementing with gdscript
```gdscript
var simpleclass = load("res://simpleclass.gdns").new();
simpleclass.method("Test argument");
```

