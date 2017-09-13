#!python
import os, subprocess


# Local dependency paths, adapt them to your setup
godot_headers_path = ARGUMENTS.get("headers", "../godot_headers/")
godot_bin_path = ARGUMENTS.get("godotbinpath", "../godot_fork/bin/")

# for windows
godot_lib_path = ARGUMENTS.get("godotlibpath", godot_bin_path)

target = ARGUMENTS.get("target", "debug")
platform = ARGUMENTS.get("p", "linux")

# This makes sure to keep the session environment variables on windows, 
# that way you can run scons in a vs 2017 prompt and it will find all the required tools
env = Environment()
if platform == "windows":
    env = Environment(ENV = os.environ)

if ARGUMENTS.get("use_llvm", "no") == "yes":
    env["CXX"] = "clang++"

godot_name = "godot." + ("x11" if platform == "linux" else platform) + ".tools.64"


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
    env.Append(LIBS=[godot_name])
    env.Append(LIBPATH=[godot_lib_path])

sources = []
add_sources(sources, "src/core")


if ARGUMENTS.get("generate_bindings", "no") == "yes":
    godot_executable = godot_bin_path + godot_name

    if env["CXX"] == "clang++":
        godot_executable += ".llvm"

    if platform == "windows":
        godot_executable += ".exe"
    
    # TODO Generating the API should be done only if the Godot build is more recent than the JSON file
    json_api_file = 'godot_api.json'

    subprocess.call([godot_executable, '--gdnative-generate-json-api', json_api_file])

    # actually create the bindings here
    
    import binding_generator

    
    binding_generator.generate_bindings(json_api_file)


add_sources(sources, "src")

library = env.StaticLibrary(target='bin/godot_cpp_bindings', source=sources)
Default(library)

