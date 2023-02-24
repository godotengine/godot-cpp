import sys

import my_spawn

from SCons.Tool import msvc, mingw
from SCons.Variables import *


def options(opts):
    opts.Add(BoolVariable("use_mingw", "Use the MinGW compiler instead of MSVC - only effective on Windows", False))
    opts.Add(BoolVariable("use_llvm", "Use the LLVM compiler", False))
    opts.Add(BoolVariable("use_clang_cl", "Use the clang driver instead of MSVC - only effective on Windows", False))
    opts.Add(("mingw_prefix", "MinGW prefix", os.getenv("MINGW_PREFIX", "")))


def exists(env):
    return True


def get_mingw_bin_prefix(prefix, arch):
    if not prefix:
        mingw_bin_prefix = ""
    elif prefix[-1] != "/":
        mingw_bin_prefix = prefix + "/bin/"
    else:
        mingw_bin_prefix = prefix + "bin/"

    if arch == "x86_64":
        mingw_bin_prefix += "x86_64-w64-mingw32-"
    elif arch == "x86_32":
        mingw_bin_prefix += "i686-w64-mingw32-"
    elif arch == "arm32":
        mingw_bin_prefix += "armv7-w64-mingw32-"
    elif arch == "arm64":
        mingw_bin_prefix += "aarch64-w64-mingw32-"

    return mingw_bin_prefix


def try_cmd(test, prefix, arch):
    if arch:
        try:
            out = subprocess.Popen(
                get_mingw_bin_prefix(prefix, arch) + test,
                shell=True,
                stderr=subprocess.PIPE,
                stdout=subprocess.PIPE,
            )
            out.communicate()
            if out.returncode == 0:
                return True
        except Exception:
            pass
    else:
        for a in ["x86_64", "x86_32", "arm64", "arm32"]:
            try:
                out = subprocess.Popen(
                    get_mingw_bin_prefix(prefix, a) + test,
                    shell=True,
                    stderr=subprocess.PIPE,
                    stdout=subprocess.PIPE,
                )
                out.communicate()
                if out.returncode == 0:
                    return True
            except Exception:
                pass

    return False


def generate(env):
    base = None
    if not env["use_mingw"] and msvc.exists(env):
        msvc_arch_aliases = {"x86_32": "x86", "arm32": "arm"}
        if env["arch"] in msvc_arch_aliases.keys():
            env["TARGET_ARCH"] = msvc_arch_aliases[env["arch"]]
        else:
            env["TARGET_ARCH"] = env["arch"]

        env["is_msvc"] = True

        # MSVC, linker, and archiver.
        msvc.generate(env)
        env.Tool("mslib")
        env.Tool("mslink")

        env.Append(CPPDEFINES=["TYPED_METHOD_BIND", "NOMINMAX"])
        env.Append(CCFLAGS=["/EHsc"])
        env.Append(LINKFLAGS=["/WX"])

        if env["use_clang_cl"]:
            env["CC"] = "clang-cl"
            env["CXX"] = "clang-cl"

    elif sys.platform == "win32" or sys.platform == "msys":
        env["use_mingw"] = True
        mingw.generate(env)
        # Don't want lib prefixes
        env["IMPLIBPREFIX"] = ""
        env["SHLIBPREFIX"] = ""
        # Want dll suffix
        env["SHLIBSUFFIX"] = ".dll"
        # Long line hack. Use custom spawn, quick AR append (to avoid files with the same names to override each other).
        my_spawn.configure(env)

    else:
        env["use_mingw"] = True

        prefix = get_mingw_bin_prefix(env["mingw_prefix"], env["arch"])

        # Cross-compilation using MinGW
        if env["use_llvm"]:
            env["CC"] = prefix + "clang"
            env["CXX"] = prefix + "clang++"
            if try_cmd("ar --version", env["mingw_prefix"], env["arch"]):
                env["AR"] = prefix + "ar"
            if try_cmd("ranlib --version", env["mingw_prefix"], env["arch"]):
                env["RANLIB"] = prefix + "ranlib"
            env["LINK"] = prefix + "clang++"
        else:
            env["CC"] = prefix + "gcc"
            env["CXX"] = prefix + "g++"
            if try_cmd("gcc-ar --version", env["mingw_prefix"], env["arch"]):
                env["AR"] = prefix + "gcc-ar"
            if try_cmd("gcc-ranlib --version", env["mingw_prefix"], env["arch"]):
                env["RANLIB"] = prefix + "gcc-ranlib"
            env["LINK"] = prefix + "g++"

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
