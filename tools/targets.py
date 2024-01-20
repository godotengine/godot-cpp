import os
import re
import subprocess
import sys
from SCons.Script import ARGUMENTS
from SCons.Variables import *
from SCons.Variables.BoolVariable import _text2bool


# Helper methods


def get_compiler_version(env):
    """
    Returns an array of version numbers as ints: [major, minor, patch].
    The return array should have at least two values (major, minor).
    """
    if not env.get("is_msvc", False):
        # Not using -dumpversion as some GCC distros only return major, and
        # Clang used to return hardcoded 4.2.1: # https://reviews.llvm.org/D56803
        try:
            version = subprocess.check_output([env.subst(env["CXX"]), "--version"]).strip().decode("utf-8")
        except (subprocess.CalledProcessError, OSError):
            print("Couldn't parse CXX environment variable to infer compiler version.")
            return None
    else:  # TODO: Implement for MSVC
        return None
    match = re.search(
        "(?:(?<=version )|(?<=\) )|(?<=^))"
        "(?P<major>\d+)"
        "(?:\.(?P<minor>\d*))?"
        "(?:\.(?P<patch>\d*))?"
        "(?:-(?P<metadata1>[0-9a-zA-Z-]*))?"
        "(?:\+(?P<metadata2>[0-9a-zA-Z-]*))?"
        "(?: (?P<date>[0-9]{8}|[0-9]{6})(?![0-9a-zA-Z]))?",
        version,
    )
    if match is not None:
        return match.groupdict()
    else:
        return None


def get_cmdline_bool(option, default):
    """We use `ARGUMENTS.get()` to check if options were manually overridden on the command line,
    and SCons' _text2bool helper to convert them to booleans, otherwise they're handled as strings.
    """
    cmdline_val = ARGUMENTS.get(option)
    if cmdline_val is not None:
        return _text2bool(cmdline_val)
    else:
        return default


def using_gcc(env):
    return "gcc" in os.path.basename(env["CC"])


def using_emcc(env):
    return "emcc" in os.path.basename(env["CC"])


def using_clang(env):
    return "clang" in os.path.basename(env["CC"])


def is_vanilla_clang(env):
    if not using_clang(env):
        return False
    try:
        version = subprocess.check_output([env.subst(env["CXX"]), "--version"]).strip().decode("utf-8")
    except (subprocess.CalledProcessError, OSError):
        print("Couldn't parse CXX environment variable to infer compiler version.")
        return False
    return not version.startswith("Apple")


# Main tool definition


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
    opts.Add(EnumVariable("warnings", "Level of compilation warnings", "all", ("extra", "all", "moderate", "no")))
    opts.Add(BoolVariable("werror", "Treat compiler warnings as errors", False))


def exists(env):
    return True


def generate(env):
    # Configuration of build targets:
    # - Editor or template
    # - Debug features (DEBUG_ENABLED code)
    # - Dev only code (DEV_ENABLED code)
    # - Optimization level
    # - Debug symbols for crash traces / debuggers

    # Keep this configuration in sync with SConstruct in upstream Godot.

    env.editor_build = env["target"] == "editor"
    env.dev_build = env["dev_build"]
    env.debug_features = env["target"] in ["editor", "template_debug"]

    if env.dev_build:
        opt_level = "none"
    elif env.debug_features:
        opt_level = "speed_trace"
    else:  # Release
        opt_level = "speed"

    env["optimize"] = ARGUMENTS.get("optimize", opt_level)
    env["debug_symbols"] = get_cmdline_bool("debug_symbols", env.dev_build)

    if env.editor_build:
        env.Append(CPPDEFINES=["TOOLS_ENABLED"])

    if env.debug_features:
        # DEBUG_ENABLED enables debugging *features* and debug-only code, which is intended
        # to give *users* extra debugging information for their game development.
        env.Append(CPPDEFINES=["DEBUG_ENABLED"])
        # In upstream Godot this is added in typedefs.h when DEBUG_ENABLED is set.
        env.Append(CPPDEFINES=["DEBUG_METHODS_ENABLED"])

    if env.dev_build:
        # DEV_ENABLED enables *engine developer* code which should only be compiled for those
        # working on the engine itself.
        env.Append(CPPDEFINES=["DEV_ENABLED"])
    else:
        # Disable assert() for production targets (only used in thirdparty code).
        env.Append(CPPDEFINES=["NDEBUG"])

    # Set optimize and debug_symbols flags.
    # "custom" means do nothing and let users set their own optimization flags.
    if env.get("is_msvc", False):
        if env["debug_symbols"]:
            env.Append(CCFLAGS=["/Zi", "/FS"])
            env.Append(LINKFLAGS=["/DEBUG:FULL"])

        if env["optimize"] == "speed":
            env.Append(CCFLAGS=["/O2"])
            env.Append(LINKFLAGS=["/OPT:REF"])
        elif env["optimize"] == "speed_trace":
            env.Append(CCFLAGS=["/O2"])
            env.Append(LINKFLAGS=["/OPT:REF", "/OPT:NOICF"])
        elif env["optimize"] == "size":
            env.Append(CCFLAGS=["/O1"])
            env.Append(LINKFLAGS=["/OPT:REF"])
        elif env["optimize"] == "debug" or env["optimize"] == "none":
            env.Append(CCFLAGS=["/Od"])

        # Warnings
        if env["warnings"] == "no":
            env.Append(CCFLAGS=["/w"])
        else:
            if env["warnings"] == "extra":
                env.Append(CCFLAGS=["/W4"])
            elif env["warnings"] == "all":
                env.Append(CCFLAGS=["/W3"])
            elif env["warnings"] == "moderate":
                env.Append(CCFLAGS=["/W2"])
            # Disable warnings which we don't plan to fix.

            env.Append(
                CCFLAGS=[
                    "/wd4100",  # C4100 (unreferenced formal parameter): Doesn't play nice with polymorphism.
                    "/wd4127",  # C4127 (conditional expression is constant)
                    "/wd4201",  # C4201 (non-standard nameless struct/union): Only relevant for C89.
                    "/wd4244",  # C4244 C4245 C4267 (narrowing conversions): Unavoidable at this scale.
                    "/wd4245",
                    "/wd4267",
                    "/wd4305",  # C4305 (truncation): double to float or real_t, too hard to avoid.
                    "/wd4514",  # C4514 (unreferenced inline function has been removed)
                    "/wd4714",  # C4714 (function marked as __forceinline not inlined)
                    "/wd4820",  # C4820 (padding added after construct)
                ]
            )

        if env["werror"]:
            env.Append(CCFLAGS=["/WX"])

    else:
        if env["debug_symbols"]:
            # Adding dwarf-4 explicitly makes stacktraces work with clang builds,
            # otherwise addr2line doesn't understand them.
            env.Append(CCFLAGS=["-gdwarf-4"])
            if env.dev_build:
                env.Append(CCFLAGS=["-g3"])
            else:
                env.Append(CCFLAGS=["-g2"])
        else:
            if using_clang(env) and not is_vanilla_clang(env):
                # Apple Clang, its linker doesn't like -s.
                env.Append(LINKFLAGS=["-Wl,-S", "-Wl,-x", "-Wl,-dead_strip"])
            else:
                env.Append(LINKFLAGS=["-s"])

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

        # Warnings
        cc_version = get_compiler_version(env) or {
            "major": None,
            "minor": None,
            "patch": None,
            "metadata1": None,
            "metadata2": None,
            "date": None,
        }
        cc_version_major = int(cc_version["major"] or -1)
        cc_version_minor = int(cc_version["minor"] or -1)

        common_warnings = []

        if using_gcc(env):
            common_warnings += ["-Wshadow-local", "-Wno-misleading-indentation"]
            if cc_version_major == 7:  # Bogus warning fixed in 8+.
                common_warnings += ["-Wno-strict-overflow"]
            if cc_version_major < 11:
                # Regression in GCC 9/10, spams so much in our variadic templates
                # that we need to outright disable it.
                common_warnings += ["-Wno-type-limits"]
            if cc_version_major >= 12:  # False positives in our error macros, see GH-58747.
                common_warnings += ["-Wno-return-type"]
        elif using_clang(env) or using_emcc(env):
            # We often implement `operator<` for structs of pointers as a requirement
            # for putting them in `Set` or `Map`. We don't mind about unreliable ordering.
            common_warnings += ["-Wno-ordered-compare-function-pointers"]

        if env["warnings"] == "extra":
            env.Append(CCFLAGS=["-Wall", "-Wextra", "-Wwrite-strings", "-Wno-unused-parameter"] + common_warnings)
            env.Append(CXXFLAGS=["-Wctor-dtor-privacy", "-Wnon-virtual-dtor"])
            if using_gcc(env):
                env.Append(
                    CCFLAGS=[
                        "-Walloc-zero",
                        "-Wduplicated-branches",
                        "-Wduplicated-cond",
                        "-Wstringop-overflow=4",
                    ]
                )
                env.Append(CXXFLAGS=["-Wplacement-new=1"])
                # Need to fix a warning with AudioServer lambdas before enabling.
                # if cc_version_major != 9:  # GCC 9 had a regression (GH-36325).
                #    env.Append(CXXFLAGS=["-Wnoexcept"])
                if cc_version_major >= 9:
                    env.Append(CCFLAGS=["-Wattribute-alias=2"])
                if cc_version_major >= 11:  # Broke on MethodBind templates before GCC 11.
                    env.Append(CCFLAGS=["-Wlogical-op"])
            elif using_clang(env) or using_emcc(env):
                env.Append(CCFLAGS=["-Wimplicit-fallthrough"])
        elif env["warnings"] == "all":
            env.Append(CCFLAGS=["-Wall"] + common_warnings)
        elif env["warnings"] == "moderate":
            env.Append(CCFLAGS=["-Wall", "-Wno-unused"] + common_warnings)
        else:  # 'no'
            env.Append(CCFLAGS=["-w"])

        if env["werror"]:
            env.Append(CCFLAGS=["-Werror"])
