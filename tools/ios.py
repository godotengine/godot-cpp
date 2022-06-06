import os
import sys
import subprocess
from SCons.Variables import *

if sys.version_info < (3,):

    def decode_utf8(x):
        return x

else:
    import codecs

    def decode_utf8(x):
        return codecs.utf_8_decode(x)[0]


def options(opts):
    opts.Add(BoolVariable("ios_simulator", "Target iOS Simulator", False))
    opts.Add(
        "IPHONEPATH",
        "Path to iPhone toolchain",
        "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain",
    )


def exists(env):
    return sys.platform == "darwin"


def generate(env):
    if env["arch"] not in ("universal", "arm64", "x86_64"):
        print("Only universal, arm64, and x86_64 are supported on iOS. Exiting.")
        Exit()

    if env["ios_simulator"]:
        sdk_name = "iphonesimulator"
        env.Append(CCFLAGS=["-mios-simulator-version-min=10.0"])
    else:
        sdk_name = "iphoneos"
        env.Append(CCFLAGS=["-miphoneos-version-min=10.0"])

    try:
        sdk_path = decode_utf8(subprocess.check_output(["xcrun", "--sdk", sdk_name, "--show-sdk-path"]).strip())
    except (subprocess.CalledProcessError, OSError):
        raise ValueError("Failed to find SDK path while running xcrun --sdk {} --show-sdk-path.".format(sdk_name))

    compiler_path = env["IPHONEPATH"] + "/usr/bin/"
    env["ENV"]["PATH"] = env["IPHONEPATH"] + "/Developer/usr/bin/:" + env["ENV"]["PATH"]

    env["CC"] = compiler_path + "clang"
    env["CXX"] = compiler_path + "clang++"
    env["AR"] = compiler_path + "ar"
    env["RANLIB"] = compiler_path + "ranlib"
    env["SHLIBSUFFIX"] = ".dylib"

    if env["arch"] == "universal":
        if env["ios_simulator"]:
            env.Append(LINKFLAGS=["-arch", "x86_64", "-arch", "arm64"])
            env.Append(CCFLAGS=["-arch", "x86_64", "-arch", "arm64"])
        else:
            env.Append(LINKFLAGS=["-arch", "arm64"])
            env.Append(CCFLAGS=["-arch", "arm64"])
    else:
        env.Append(LINKFLAGS=["-arch", env["arch"]])
        env.Append(CCFLAGS=["-arch", env["arch"]])

    env.Append(CCFLAGS=["-isysroot", sdk_path])
    env.Append(LINKFLAGS=["-isysroot", sdk_path, "-F" + sdk_path])

    if env["target"] == "debug":
        env.Append(CCFLAGS=["-Og", "-g"])
    elif env["target"] == "release":
        env.Append(CCFLAGS=["-O3"])
