import os, sys, subprocess

import win32_long_line_fix

from SCons.Tool import msvc
from SCons.Variables import BoolVariable


is_windows = sys.platform in ["win32", "msys", "cygwin"]


def try_cmd(test):
    try:
        out = subprocess.Popen(
            test,
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


def get_compiler_target(cmd):
    try:
        return subprocess.check_output(cmd + " -dumpmachine", text=True, shell=True).strip()
    except subprocess.CalledProcessError as e:
        pass
    return ""


def find_mingw_tool(cmd, prefixes=[], required=True):
    for prefix in prefixes:
        if not try_cmd(prefix + cmd + " --version"):
            continue
        return prefix + cmd
    print("Unable to find required mingw tool '%s'. Tried: %s" % (cmd, [p + cmd for p in prefixes]))
    return cmd


def options(opts):
    opts.Add(BoolVariable("use_mingw", "Use the MinGW gcc compiler instead of MSVC - only effective on Windows", False))
    opts.Add(
        BoolVariable("use_mingw_llvm", "Use the MinGW llvm compiler instead of MSVC - only effective on Windows", False)
    )
    opts.Add(BoolVariable("use_clang_cl", "Use the clang driver instead of MSVC - only effective on Windows", False))


def exists(env):
    return True


def generate(env):
    if env["use_mingw_llvm"]:
        env["use_mingw"] = True

    if is_windows and not env["use_mingw"] and msvc.exists(env):
        env["is_msvc"] = True

        msvc_arch_names = {
            "x86_64": "amd64",
            "x86_32": "x86",
            "arm32": "arm",
            "arm64": "arm64",
        }

        msvc_arch = msvc_arch_names.get(env["arch"], "")
        if msvc_arch == "":
            print("WARNING: Unsupported MSVC platform '%s', the resulting binary might be invalid." % env["arch"])
            msvc_arch = os.environ.get("Platform", "")

        env["TARGET_ARCH"] = msvc_arch

        # MSVC, linker, and archiver.
        msvc.generate(env)
        env.Tool("mslib")
        env.Tool("mslink")

        env.Append(CPPDEFINES=["TYPED_METHOD_BIND", "NOMINMAX"])
        env.Append(CCFLAGS=["/EHsc", "/utf-8"])
        env.Append(LINKFLAGS=["/WX"])

        if env["use_clang_cl"]:
            env["CC"] = "clang-cl"
            env["CXX"] = "clang-cl"

    else:
        # Cross-compilation using MinGW
        env["use_mingw"] = True

        mingw_archs = {
            "x86_64": "x86_64",
            "x86_32": "i686",
            "arm32": "armv7",
            "arm64": "aarch64",
        }

        mingw_arch = mingw_archs.get(env["arch"], env["arch"])
        triple = mingw_arch + "-w64-mingw32-"
        compiler_prefixes = [triple, ""]
        if env["use_mingw_llvm"]:
            tool_prefixes = [triple + "llvm-"] + compiler_prefixes
            env["CC"] = find_mingw_tool("clang", compiler_prefixes)
            env["CXX"] = find_mingw_tool("clang++", compiler_prefixes)
        else:
            tool_prefixes = [triple + "gcc-"] + compiler_prefixes
            env["CC"] = find_mingw_tool("gcc", compiler_prefixes)
            env["CXX"] = find_mingw_tool("g++", compiler_prefixes)

        env["LINK"] = env["CXX"]
        env["AR"] = find_mingw_tool("ar", tool_prefixes)
        env["RANLIB"] = find_mingw_tool("ranlib", tool_prefixes)
        env["AS"] = find_mingw_tool("as", tool_prefixes)
        # We could also add the RC action but it's rarely needed by libraries, so let's keep this simple.
        env["RC"] = find_mingw_tool("windres", tool_prefixes)

        # Check compiler target.
        known_targets = [mingw_arch + "-w64-mingw32", mingw_arch + "-w64-windows-gnu"]
        compiler_target = get_compiler_target(env["CXX"])
        if compiler_target not in known_targets:
            print(
                "WARNING: Unknown compiler target: %s.\nExpected any of: %s.\nThe resulting binary may be invalid."
                % (compiler_target, known_targets)
            )

        env["SHLIBSUFFIX"] = ".dll"
        env.Append(CCFLAGS=["-Wwrite-strings"])
        env.Append(
            LINKFLAGS=[
                "--static",
                "-Wl,--no-undefined",
                "-static-libgcc",
                "-static-libstdc++",
            ]
        )

        # Needed by at least MSYS2-MinGW.
        if is_windows and "TEMP" in os.environ:
            env["ENV"]["TEMP"] = os.environ["TEMP"]

        # Long line hack on Windows.
        # Use custom spawn, quick AR append (to avoid files with the same names to override each other).
        if win32_long_line_fix.exists(env):
            win32_long_line_fix.generate(env)
