import codecs
import os
import subprocess
import sys

import common_compiler_flags
from SCons.Variables import BoolVariable


def has_visionos_osxcross():
    return "OSXCROSS_VISIONOS" in os.environ


def options(opts):
    opts.Add(BoolVariable("visionos_simulator", "Target visionOS Simulator", False))
    opts.Add("visionos_min_version", "Target minimum xros/xrsimulator version", "26.0")
    opts.Add(
        "VISIONOS_TOOLCHAIN_PATH",
        "Path to visionOS toolchain",
        "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain",
    )
    opts.Add("VISIONOS_SDK_PATH", "Path to the visionOS SDK", "")

    if has_visionos_osxcross():
        opts.Add("visionos_triple", "Triple for visionOS toolchain", "")


def exists(env):
    return sys.platform == "darwin" or has_visionos_osxcross()


def generate(env):
    if env["arch"] not in ("arm64", "x86_64"):
        raise ValueError("Only arm64 and x86_64 are supported on visionOS. Exiting.")

    if env["visionos_simulator"]:
        sdk_name = "xrsimulator"
        target_os_flag = "-mtargetos=xros" + env["visionos_min_version"] + "-simulator"
        env.Append(CPPDEFINES=["VISIONOS_SIMULATOR"])
    else:
        sdk_name = "xros"
        target_os_flag = "-mtargetos=xros" + env["visionos_min_version"]

    env.Append(CCFLAGS=[target_os_flag])
    env.Append(LINKFLAGS=[target_os_flag])

    if sys.platform == "darwin":
        if env["VISIONOS_SDK_PATH"] == "":
            try:
                env["VISIONOS_SDK_PATH"] = codecs.utf_8_decode(
                    subprocess.check_output(["xcrun", "--sdk", sdk_name, "--show-sdk-path"]).strip()
                )[0]
            except (subprocess.CalledProcessError, OSError):
                raise ValueError(
                    "Failed to find SDK path while running xcrun --sdk {} --show-sdk-path.".format(sdk_name)
                )

        compiler_path = env["VISIONOS_TOOLCHAIN_PATH"] + "/usr/bin/"
        env["CC"] = compiler_path + "clang"
        env["CXX"] = compiler_path + "clang++"
        env["AR"] = compiler_path + "ar"
        env["RANLIB"] = compiler_path + "ranlib"
        env["SHLIBSUFFIX"] = ".dylib"
        env["ENV"]["PATH"] = env["VISIONOS_TOOLCHAIN_PATH"] + "/Developer/usr/bin/:" + env["ENV"]["PATH"]

    else:
        compiler_path = "$VISIONOS_TOOLCHAIN_PATH/usr/bin/${visionos_triple}"
        env["CC"] = compiler_path + "clang"
        env["CXX"] = compiler_path + "clang++"
        env["AR"] = compiler_path + "ar"
        env["RANLIB"] = compiler_path + "ranlib"
        env["SHLIBSUFFIX"] = ".dylib"

        env.Prepend(
            CPPPATH=[
                "$VISIONOS_SDK_PATH/usr/include",
                "$VISIONOS_SDK_PATH/System/Library/Frameworks/AudioUnit.framework/Headers",
            ]
        )

        env.Append(CCFLAGS=["-stdlib=libc++"])

        binpath = os.path.join(env["VISIONOS_TOOLCHAIN_PATH"], "usr", "bin")
        if binpath not in env["ENV"]["PATH"]:
            env.PrependENVPath("PATH", binpath)

    env.Append(LINKFLAGS=["-arch", env["arch"]])
    env.Append(CCFLAGS=["-arch", env["arch"]])

    env.Append(CCFLAGS=["-isysroot", env["VISIONOS_SDK_PATH"]])
    env.Append(LINKFLAGS=["-isysroot", env["VISIONOS_SDK_PATH"], "-F" + env["VISIONOS_SDK_PATH"]])

    env.Append(CCFLAGS=["-Wno-ambiguous-macro"])

    env.Append(LINKFLAGS=["-Wl,-dead_strip"])

    env.Append(CPPDEFINES=["VISIONOS_ENABLED", "APPLE_EMBEDDED_ENABLED", "UNIX_ENABLED"])

    if env["lto"] == "auto":
        env["lto"] = "none"

    common_compiler_flags.generate(env)
