import os
import sys
from SCons.Script import ARGUMENTS
from SCons.Variables import *
from SCons.Variables.BoolVariable import _text2bool


def get_cmdline_bool(option, default):
    """We use `ARGUMENTS.get()` to check if options were manually overridden on the command line,
    and SCons' _text2bool helper to convert them to booleans, otherwise they're handled as strings.
    """
    cmdline_val = ARGUMENTS.get(option)
    if cmdline_val is not None:
        return _text2bool(cmdline_val)
    else:
        return default


def options(opts):
    opts.Add(
        EnumVariable(
            "optimize",
            "The desired optimization flags",
            "speed_trace",
            ("none", "custom", "debug", "speed", "speed_trace", "size"),
        )
    )
    opts.Add(BoolVariable("debug_symbols", "Build with debugging symbols", True))
    opts.Add(BoolVariable("dev_build", "Developer build with dev-only debugging code (DEV_ENABLED)", False))


def exists(env):
    return True


def generate(env):
    env.dev_build = env["dev_build"]
    env.debug_features = env["target"] in ["editor", "template_debug"]
    env.editor_build = env["target"] == "editor"

    if env.editor_build:
        env.AppendUnique(CPPDEFINES=["TOOLS_ENABLED"])

    if env.debug_features:
        env.AppendUnique(CPPDEFINES=["DEBUG_ENABLED", "DEBUG_METHODS_ENABLED"])

    if env.dev_build:
        opt_level = "none"
        env.AppendUnique(CPPDEFINES=["DEV_ENABLED"])
    elif env.debug_features:
        opt_level = "speed_trace"
    else:  # Release
        opt_level = "speed"

    env["optimize"] = ARGUMENTS.get("optimize", opt_level)
    env["debug_symbols"] = get_cmdline_bool("debug_symbols", env.dev_build)

    if env.get("is_msvc", False):
        if env["debug_symbols"]:
            env.Append(CCFLAGS=["/Zi", "/FS"])
            env.Append(LINKFLAGS=["/DEBUG:FULL"])

        if env["optimize"] == "speed" or env["optimize"] == "speed_trace":
            env.Append(CCFLAGS=["/O2"])
            env.Append(LINKFLAGS=["/OPT:REF"])
        elif env["optimize"] == "size":
            env.Append(CCFLAGS=["/O1"])
            env.Append(LINKFLAGS=["/OPT:REF"])

        if env["optimize"] == "debug" or env["optimize"] == "none":
            env.Append(CCFLAGS=["/MDd", "/Od"])
        else:
            env.Append(CCFLAGS=["/MD"])

    else:
        if env["debug_symbols"]:
            if env.dev_build:
                env.Append(CCFLAGS=["-g3"])
            else:
                env.Append(CCFLAGS=["-g2"])

        if env["optimize"] == "speed":
            env.Append(CCFLAGS=["-O3"])
        # `-O2` is friendlier to debuggers than `-O3`, leading to better crash backtraces.
        elif env["optimize"] == "speed_trace":
            env.Append(CCFLAGS=["-O2"])
        elif env["optimize"] == "size":
            env.Append(CCFLAGS=["-Os"])
        elif env["optimize"] == "debug":
            env.Append(CCFLAGS=["-Og"])
        elif env["optimize"] == "none":
            env.Append(CCFLAGS=["-O0"])
