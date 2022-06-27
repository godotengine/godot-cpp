import sys

import my_spawn
from SCons.Tool.MSCommon import msvc_exists
from SCons.Variables import *


def options(opts):
    opts.Add(BoolVariable("use_mingw", "Use the MinGW compiler instead of MSVC - only effective on Windows", False))


def exists(env):
    return True


def generate(env):
    base = None
    if not env["use_mingw"] and msvc_exists(env):
        base = env.Tool("msvc")
        env["is_msvc"] = True
        if env["arch"] == "x86_64":
            env["TARGET_ARCH"] = "amd64"
        elif env["arch"] == "x86_32":
            env["TARGET_ARCH"] = "x86"
        base.generate(env)
        env.Append(CPPDEFINES=["TYPED_METHOD_BIND"])
        env.Append(LINKFLAGS=["/WX"])
        if env["target"] == "debug":
            env.Append(CCFLAGS=["/Z7", "/Od", "/EHsc", "/D_DEBUG", "/MDd"])
        elif env["target"] == "release":
            env.Append(CCFLAGS=["/O2", "/EHsc", "/DNDEBUG", "/MD"])

    elif sys.platform == "win32" or sys.platform == "msys":
        env["use_mingw"] = True
        base = env.Tool("mingw")
        base.generate(env)
        # Still need to use C++17.
        env.Append(CCFLAGS=["-std=c++17"])
        # Don't want lib prefixes
        env["IMPLIBPREFIX"] = ""
        env["SHLIBPREFIX"] = ""
        # Want dll suffix
        env["SHLIBSUFFIX"] = ".dll"
        # Long line hack. Use custom spawn, quick AR append (to avoid files with the same names to override each other).
        my_spawn.configure(env)

    else:
        env["use_mingw"] = True
        # Cross-compilation using MinGW
        prefix = "i686" if env["arch"] == "x86_32" else env["arch"]
        env["CXX"] = prefix + "-w64-mingw32-g++"
        env["CC"] = prefix + "-w64-mingw32-gcc"
        env["AR"] = prefix + "-w64-mingw32-ar"
        env["RANLIB"] = prefix + "-w64-mingw32-ranlib"
        env["LINK"] = prefix + "-w64-mingw32-g++"
        # Want dll suffix
        env["SHLIBSUFFIX"] = ".dll"

        # These options are for a release build even using target=debug
        env.Append(CCFLAGS=["-O3", "-Wwrite-strings"])
        env.Append(
            LINKFLAGS=[
                "--static",
                "-Wl,--no-undefined",
                "-static-libgcc",
                "-static-libstdc++",
            ]
        )
