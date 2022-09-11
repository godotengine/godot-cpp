import os
import sys
import macos_osxcross


def options(opts):
    opts.Add("macos_deployment_target", "macOS deployment target", "default")
    opts.Add("macos_sdk_path", "macOS SDK path", "")
    macos_osxcross.options(opts)


def exists(env):
    return sys.platform == "darwin" or macos_osxcross.exists(env)


def generate(env):
    if env["arch"] not in ("universal", "arm64", "x86_64"):
        print("Only universal, arm64, and x86_64 are supported on macOS. Exiting.")
        Exit()

    if sys.platform == "darwin":
        # Use clang on macOS by default
        env["CXX"] = "clang++"
        env["CC"] = "clang"
    else:
        # Use osxcross
        macos_osxcross.generate(env)

    if env["arch"] == "universal":
        env.Append(LINKFLAGS=["-arch", "x86_64", "-arch", "arm64"])
        env.Append(CCFLAGS=["-arch", "x86_64", "-arch", "arm64"])
    else:
        env.Append(LINKFLAGS=["-arch", env["arch"]])
        env.Append(CCFLAGS=["-arch", env["arch"]])

    if env["macos_deployment_target"] != "default":
        env.Append(CCFLAGS=["-mmacosx-version-min=" + env["macos_deployment_target"]])
        env.Append(LINKFLAGS=["-mmacosx-version-min=" + env["macos_deployment_target"]])

    if env["macos_sdk_path"]:
        env.Append(CCFLAGS=["-isysroot", env["macos_sdk_path"]])
        env.Append(LINKFLAGS=["-isysroot", env["macos_sdk_path"]])

    env.Append(
        LINKFLAGS=[
            "-framework",
            "Cocoa",
            "-Wl,-undefined,dynamic_lookup",
        ]
    )
