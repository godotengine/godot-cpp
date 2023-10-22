import sys

import my_spawn

from SCons.Tool import msvc, mingw
from SCons.Variables import *


def options(opts):
    opts.Add(BoolVariable("use_mingw", "Use the MinGW compiler instead of MSVC - only effective on Windows", False))
    opts.Add(BoolVariable("use_clang_cl", "Use the clang driver instead of MSVC - only effective on Windows", False))
    opts.Add(BoolVariable("use_static_cpp", "Link MinGW/MSVC C++ runtime libraries statically", True))


def exists(env):
    return True


def generate(env):
    base = None
    if not env["use_mingw"] and msvc.exists(env):
        if env["arch"] == "x86_64":
            env["TARGET_ARCH"] = "amd64"
        elif env["arch"] == "x86_32":
            env["TARGET_ARCH"] = "x86"
        env["is_msvc"] = True

        # MSVC, linker, and archiver.
        msvc.generate(env)
        env.Tool("mslib")
        env.Tool("mslink")

        env.Append(CPPDEFINES=["TYPED_METHOD_BIND", "NOMINMAX"])
        env.Append(CCFLAGS=["/utf-8"])
        env.Append(LINKFLAGS=["/WX"])

        if env["use_clang_cl"]:
            env["CC"] = "clang-cl"
            env["CXX"] = "clang-cl"

        if env["use_static_cpp"]:
            env.Append(CCFLAGS=["/MT"])
        else:
            env.Append(CCFLAGS=["/MD"])

    elif sys.platform == "win32" or sys.platform == "msys":
        env["use_mingw"] = True
        mingw.generate(env)
        # Don't want lib prefixes
        env["IMPLIBPREFIX"] = ""
        env["SHLIBPREFIX"] = ""
        # Want dll suffix
        env["SHLIBSUFFIX"] = ".dll"

        env.Append(CCFLAGS=["-Wwrite-strings"])
        env.Append(LINKFLAGS=["-Wl,--no-undefined"])
        if env["use_static_cpp"]:
            env.Append(
                LINKFLAGS=[
                    "-static",
                    "-static-libgcc",
                    "-static-libstdc++",
                ]
            )

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

        env.Append(CCFLAGS=["-Wwrite-strings"])
        env.Append(LINKFLAGS=["-Wl,--no-undefined"])
        if env["use_static_cpp"]:
            env.Append(
                LINKFLAGS=[
                    "-static",
                    "-static-libgcc",
                    "-static-libstdc++",
                ]
            )

    env.Append(CPPDEFINES=["WINDOWS_ENABLED"])
