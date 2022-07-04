#!/usr/bin/env python

import os
import platform
import sys
import subprocess
from binding_generator import scons_generate_bindings, scons_emit_files

EnsureSConsVersion(4, 3)


def add_sources(sources, dir, extension):
    for f in os.listdir(dir):
        if f.endswith("." + extension):
            sources.append(dir + "/" + f)


# Try to detect the host platform automatically.
# This is used if no `platform` argument is passed
if sys.platform.startswith("linux"):
    default_platform = "linux"
elif sys.platform == "darwin":
    default_platform = "osx"
elif sys.platform == "win32" or sys.platform == "msys":
    default_platform = "windows"
elif ARGUMENTS.get("platform", ""):
    default_platform = ARGUMENTS.get("platform")
else:
    raise ValueError("Could not detect platform automatically, please specify with platform=<platform>")

env = Environment(tools=["default"])

platforms = ("linux", "osx", "windows", "android", "ios", "javascript")
opts = Variables([], ARGUMENTS)
opts.Add(
    EnumVariable(
        "platform",
        "Target platform",
        default_platform,
        allowed_values=platforms,
        ignorecase=2,
    )
)

# Must be the same setting as used for cpp_bindings
opts.Add(EnumVariable("target", "Compilation target", "debug", allowed_values=("debug", "release"), ignorecase=2))
opts.Add(
    PathVariable(
        "headers_dir", "Path to the directory containing Godot headers", "godot-headers", PathVariable.PathIsDir
    )
)
opts.Add(PathVariable("custom_api_file", "Path to a custom JSON API file", None, PathVariable.PathIsFile))
opts.Add(
    BoolVariable("generate_bindings", "Force GDExtension API bindings generation. Auto-detected by default.", False)
)
opts.Add(BoolVariable("generate_template_get_node", "Generate a template version of the Node class's get_node.", True))

opts.Add(BoolVariable("build_library", "Build the godot-cpp library.", True))
opts.Add(EnumVariable("float", "Floating-point precision", "32", ("32", "64")))

# Add platform options
tools = {}
for pl in platforms:
    tool = Tool(pl, toolpath=["tools"])
    if hasattr(tool, "options"):
        tool.options(opts)
    tools[pl] = tool

# CPU architecture options.
architecture_array = ["", "universal", "x86_32", "x86_64", "arm32", "arm64", "rv64", "ppc32", "ppc64", "wasm32"]
architecture_aliases = {
    "x64": "x86_64",
    "amd64": "x86_64",
    "armv7": "arm32",
    "armv8": "arm64",
    "arm64v8": "arm64",
    "aarch64": "arm64",
    "rv": "rv64",
    "riscv": "rv64",
    "riscv64": "rv64",
    "ppcle": "ppc32",
    "ppc": "ppc32",
    "ppc64le": "ppc64",
}
opts.Add(EnumVariable("arch", "CPU architecture", "", architecture_array, architecture_aliases))

opts.Update(env)
Help(opts.GenerateHelpText(env))

# Process CPU architecture argument.
if env["arch"] == "":
    # No architecture specified. Default to arm64 if building for Android,
    # universal if building for macOS or iOS, wasm32 if building for web,
    # otherwise default to the host architecture.
    if env["platform"] in ["osx", "ios"]:
        env["arch"] = "universal"
    elif env["platform"] == "android":
        env["arch"] = "arm64"
    elif env["platform"] == "javascript":
        env["arch"] = "wasm32"
    else:
        host_machine = platform.machine().lower()
        if host_machine in architecture_array:
            env["arch"] = host_machine
        elif host_machine in architecture_aliases.keys():
            env["arch"] = architecture_aliases[host_machine]
        elif "86" in host_machine:
            # Catches x86, i386, i486, i586, i686, etc.
            env["arch"] = "x86_32"
        else:
            print("Unsupported CPU architecture: " + host_machine)
            Exit()

tool = Tool(env["platform"], toolpath=["tools"])

if tool is None or not tool.exists(env):
    raise ValueError("Required toolchain not found for platform " + env["platform"])

tool.generate(env)

# Detect and print a warning listing unknown SCons variables to ease troubleshooting.
unknown = opts.UnknownVariables()
if unknown:
    print("WARNING: Unknown SCons variables were passed and will be ignored:")
    for item in unknown.items():
        print("    " + item[0] + "=" + item[1])

print("Building for architecture " + env["arch"] + " on platform " + env["platform"])

# Require C++17
if env.get("is_msvc", False):
    env.Append(CXXFLAGS=["/std:c++17"])
else:
    env.Append(CXXFLAGS=["-std=c++17"])

if env["target"] == "debug":
    env.Append(CPPDEFINES=["DEBUG_ENABLED", "DEBUG_METHODS_ENABLED"])

if env["float"] == "64":
    env.Append(CPPDEFINES=["REAL_T_IS_DOUBLE"])


# Generate bindings
env.Append(BUILDERS={"GenerateBindings": Builder(action=scons_generate_bindings, emitter=scons_emit_files)})
json_api_file = ""

if "custom_api_file" in env:
    json_api_file = env["custom_api_file"]
else:
    json_api_file = os.path.join(os.getcwd(), env["headers_dir"], "extension_api.json")

bindings = env.GenerateBindings(
    env.Dir("."), [json_api_file, os.path.join(env["headers_dir"], "godot", "gdnative_interface.h")]
)

# Forces bindings regeneration.
if env["generate_bindings"]:
    AlwaysBuild(bindings)

# Includes
env.Append(CPPPATH=[[env.Dir(d) for d in [env["headers_dir"], "include", os.path.join("gen", "include")]]])

# Sources to compile
sources = []
add_sources(sources, "src", "cpp")
add_sources(sources, "src/classes", "cpp")
add_sources(sources, "src/core", "cpp")
add_sources(sources, "src/variant", "cpp")
sources.extend([f for f in bindings if str(f).endswith(".cpp")])

env["arch_suffix"] = env["arch"]
if env["ios_simulator"]:
    env["arch_suffix"] += ".simulator"

library = None
env["OBJSUFFIX"] = ".{}.{}.{}{}".format(env["platform"], env["target"], env["arch_suffix"], env["OBJSUFFIX"])
library_name = "libgodot-cpp.{}.{}.{}{}".format(env["platform"], env["target"], env["arch_suffix"], env["LIBSUFFIX"])

if env["build_library"]:
    library = env.StaticLibrary(target=env.File("bin/%s" % library_name), source=sources)
    Default(library)

env.Append(LIBPATH=[env.Dir("bin")])
env.Append(LIBS=library_name)
Return("env")
