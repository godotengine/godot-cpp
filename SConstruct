#!python
import os, subprocess


# Local dependency paths, adapt them to your setup
godot_headers_path = ARGUMENTS.get("headers", os.getenv("GODOT_HEADERS", "../godot_headers/"))
godot_bin_path = ARGUMENTS.get("godotbinpath", os.getenv("GODOT_BIN_PATH", "../godot_fork/bin/godot.x11.tools.64.llvm"))

target = ARGUMENTS.get("target", "debug")
platform = ARGUMENTS.get("p", ARGUMENTS.get("platform", "linux"))

# This makes sure to keep the session environment variables on windows, 
# that way you can run scons in a vs 2017 prompt and it will find all the required tools
env = Environment()
if platform == "windows":
    env = Environment(ENV = os.environ)

if ARGUMENTS.get("use_llvm", "no") == "yes":
    env["CXX"] = "clang++"

def add_sources(sources, directory):
    for file in os.listdir(directory):
        if file.endswith('.cpp'):
            sources.append(directory + '/' + file)


if platform == "osx":
    env.Append(CCFLAGS = ['-g','-O3', '-std=c++14', '-arch', 'x86_64'])
    env.Append(LINKFLAGS = ['-arch', 'x86_64', '-framework', 'Cocoa', '-Wl,-undefined,dynamic_lookup'])

if platform == "linux":
    env.Append(CCFLAGS = ['-fPIC', '-g','-O3', '-std=c++14'])

env.Append(CPPPATH=['.', godot_headers_path, 'include', 'include/core'])

if platform == "windows":
    if target == "debug":
        env.Append(CCFLAGS = ['-EHsc', '-D_DEBUG', '/MDd'])
    else:
        env.Append(CCFLAGS = ['-O2', '-EHsc', '-DNDEBUG', '/MD'])

sources = []
add_sources(sources, "src/core")

if ARGUMENTS.get("generate_bindings", "no") == "yes":
    # TODO Generating the API should be done only if the Godot build is more recent than the JSON file
    json_api_file = os.path.join(os.getcwd(), 'godot_api.json')

    subprocess.call([os.path.expanduser(godot_bin_path), '--gdnative-generate-json-api', json_api_file])

    # actually create the bindings here
    
    import binding_generator

    
    binding_generator.generate_bindings(json_api_file)

add_sources(sources, "src")

library = env.StaticLibrary(target='bin/godot_cpp_bindings', source=sources)
Default(library)

