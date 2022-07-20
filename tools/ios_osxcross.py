import os


def options(opts):
    opts.Add("ios_triple", "Triple for ios toolchain", "")


def exists(env):
    return "OSXCROSS_IOS" in os.environ


def generate(env):
    compiler_path = "$IOS_TOOLCHAIN_PATH/usr/bin/${ios_triple}"
    env["CC"] = compiler_path + "clang"
    env["CXX"] = compiler_path + "clang++"
    env["AR"] = compiler_path + "ar"
    env["RANLIB"] = compiler_path + "ranlib"
    env["SHLIBSUFFIX"] = ".dylib"

    env.Prepend(
        CPPPATH=[
            "$IOS_SDK_PATH/usr/include",
            "$IOS_SDK_PATH/System/Library/Frameworks/AudioUnit.framework/Headers",
        ]
    )
    env.Append(CCFLAGS=["-stdlib=libc++"])
