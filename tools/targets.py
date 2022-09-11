import os
import sys
from SCons.Variables import *


def options(opts):
    opts.Add(
        EnumVariable(
            "optimize",
            "The desired optimization flags",
            "auto",
            ("auto", "none", "debug", "speed", "size", "0", "1", "2", "3"),
        )
    )
    opts.Add(BoolVariable("debug_symbols", "Add debugging symbols to release builds", False))


def exists(env):
    return True


def generate(env):
    if env["optimize"] == "auto":
        env["optimize"] = "speed" if env["target"] == "release" else "debug"
    env["debug_symbols"] = env["debug_symbols"] or env["target"] == "debug"

    if "is_msvc" in env and env["is_msvc"]:
        if env["debug_symbols"]:
            env.Append(CCFLAGS=["/Z7", "/D_DEBUG"])
            env.Append(LINKFLAGS=["/DEBUG:FULL"])
        else:
            env.Append(CCFLAGS=["/Z7", "/DNDEBUG"])

        if env["optimize"] == "speed":
            env.Append(CCFLAGS=["/O2"])
        elif env["optimize"] == "size":
            env.Append(CCFLAGS=["/Os"])
        elif env["optimize"] == "debug":
            env.Append(CCFLAGS=["/Od"])
        elif env["optimize"] == "none":
            env.Append(CCFLAGS=["/Od"])
        else:
            env.Append(CCFLAGS=["/O%s" % env["optimize"]])
    else:
        if env["debug_symbols"]:
            env.Append(CCFLAGS=["-g"])

        if env["optimize"] == "speed":
            env.Append(CCFLAGS=["-O3"])
        elif env["optimize"] == "size":
            env.Append(CCFLAGS=["-Os"])
        elif env["optimize"] == "debug":
            env.Append(CCFLAGS=["-Og"])
        elif env["optimize"] == "none":
            env.Append(CCFLAGS=["-O0"])
        else:
            env.Append(CCFLAGS=["-O%s" % env["optimize"]])
