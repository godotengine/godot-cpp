import os
from SCons.Util import WhereIs


def exists(env):
    return WhereIs("emcc") is not None


def generate(env):
    if env["arch"] not in ("wasm32"):
        print("Only wasm32 supported on web. Exiting.")
        env.Exit(1)

    env["CC"] = "emcc"
    env["CXX"] = "em++"
    env["AR"] = "emar"
    env["RANLIB"] = "emranlib"
    env.Append(CPPFLAGS=["-s", "SIDE_MODULE=1"])
    env.Append(LINKFLAGS=["-s", "SIDE_MODULE=1"])
    env["SHOBJSUFFIX"] = ".bc"
    env["SHLIBSUFFIX"] = ".wasm"
    # Use TempFileMunge since some AR invocations are too long for cmd.exe.
    # Use POSIX-style paths, required with TempFileMunge.
    env["ARCOM_POSIX"] = env["ARCOM"].replace("$TARGET", "$TARGET.posix").replace("$SOURCES", "$SOURCES.posix")
    env["ARCOM"] = "${TEMPFILE(ARCOM_POSIX)}"

    # Thread support (via SharedArrayBuffer).
    env.Append(CCFLAGS=["-s", "USE_PTHREADS=1"])
    env.Append(LINKFLAGS=["-s", "USE_PTHREADS=1"])

    # All intermediate files are just LLVM bitcode.
    env["OBJPREFIX"] = ""
    env["OBJSUFFIX"] = ".bc"
    env["PROGPREFIX"] = ""
    # Program() output consists of multiple files, so specify suffixes manually at builder.
    env["PROGSUFFIX"] = ""
    env["LIBPREFIX"] = "lib"
    env["LIBSUFFIX"] = ".a"
    env["LIBPREFIXES"] = ["$LIBPREFIX"]
    env["LIBSUFFIXES"] = ["$LIBSUFFIX"]
    env.Replace(SHLINKFLAGS="$LINKFLAGS")
    env.Replace(SHLINKFLAGS="$LINKFLAGS")

    env.Append(CPPDEFINES=["WEB_ENABLED", "UNIX_ENABLED"])
