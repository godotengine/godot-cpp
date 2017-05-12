#!python
import os, subprocess


# Local dependency paths, adapt them to your setup
godot_headers_path = "../godot_headers/"
godot_bin_path = "../godot_fork/bin/"

# for windows
godot_lib_path = "../godot_fork/bin/"


env = Environment()

if ARGUMENTS.get("use_llvm", "no") == "yes":
    env["CXX"] = "clang++"

target = ARGUMENTS.get("target", "core")
platform = ARGUMENTS.get("p", "linux")


godot_name = "godot." + ("x11" if platform == "linux" else platform) + ".tools.64"


def add_sources(sources, directory):
    for file in os.listdir(directory):
        if file.endswith('.cpp'):
            sources.append(directory + '/' + file)


if target == "core":
    if platform == "linux":
        env.Append(CCFLAGS = ['-g','-O3', '-std=c++14'])
    
    env.Append(CPPPATH=['include/core', godot_headers_path])

    if platform == "windows":
        env.Append(LIBS=[godot_name + '.lib'])
        env.Append(LIBPATH=[godot_lib_path])

    env.Append(CPPFLAGS=['-D_GD_CPP_CORE_API_IMPL'])

    sources = []
    add_sources(sources, "src/core")

    library = env.SharedLibrary(target='bin/godot_cpp_core', source=sources)
    Default(library)


elif target == "bindings":

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
       

    if platform == "linux":
        if env["CXX"] == "clang++":
            env.Append(CCFLAGS = ['-Wno-writable-strings'])
        else:
            env.Append(CCFLAGS = ['-Wno-write-strings', '-Wno-return-local-addr'])
        
        env.Append(CCFLAGS = ['-g','-O3', '-std=c++14'])
        env.Append(LINKFLAGS = ['-Wl,-R,\'$$ORIGIN\''])
    env.Append(CPPPATH=['.', godot_headers_path, 'include', 'include/core'])

    if platform == "windows":
        env.Append(LIBS=[godot_name])
        env.Append(LIBPATH=[godot_lib_path])

    env.Append(LIBS=['godot_cpp_core'])
    env.Append(LIBPATH=['bin'])

    env.Append(CPPFLAGS=['-D_GD_CPP_BINDING_IMPL'])

    sources = []
    add_sources(sources, "src")

    library = env.SharedLibrary(target='bin/godot_cpp_bindings', source=sources)
    Default(library)

