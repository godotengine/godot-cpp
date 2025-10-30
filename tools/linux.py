import os
import re
import subprocess
import sys

import common_compiler_flags
from SCons.Tool import clang, clangxx
from SCons.Variables import BoolVariable, EnumVariable

compiler_version_cache = None


def get_compiler_version(env):
    """
    Returns a dictionary with various version information:

    - major, minor, patch: Version following semantic versioning system
    - metadata1, metadata2: Extra information
    - date: Date of the build
    """

    global compiler_version_cache
    if compiler_version_cache is not None:
        return compiler_version_cache

    import shlex

    ret = {
        "major": -1,
        "minor": -1,
        "patch": -1,
        "metadata1": "",
        "metadata2": "",
        "date": "",
        "apple_major": -1,
        "apple_minor": -1,
        "apple_patch1": -1,
        "apple_patch2": -1,
        "apple_patch3": -1,
    }

    if env.msvc and not env["use_llvm"]:
        try:
            # FIXME: `-latest` works for most cases, but there are edge-cases where this would
            # benefit from a more nuanced search.
            # https://github.com/godotengine/godot/pull/91069#issuecomment-2358956731
            # https://github.com/godotengine/godot/pull/91069#issuecomment-2380836341
            args = [
                env["VSWHERE"],
                "-latest",
                "-prerelease",
                "-products",
                "*",
                "-requires",
                "Microsoft.Component.MSBuild",
                "-utf8",
            ]
            version = subprocess.check_output(args, encoding="utf-8").strip()
            for line in version.splitlines():
                split = line.split(":", 1)
                if split[0] == "catalog_productDisplayVersion":
                    sem_ver = split[1].split(".")
                    ret["major"] = int(sem_ver[0])
                    ret["minor"] = int(sem_ver[1])
                    ret["patch"] = int(sem_ver[2].split()[0])
                # Could potentially add section for determining preview version, but
                # that can wait until metadata is actually used for something.
                if split[0] == "catalog_buildVersion":
                    ret["metadata1"] = split[1]
        except (subprocess.CalledProcessError, OSError):
            print("Couldn't find vswhere to determine compiler version.")
        return update_compiler_version_cache(ret)

    # Not using -dumpversion as some GCC distros only return major, and
    # Clang used to return hardcoded 4.2.1: # https://reviews.llvm.org/D56803
    try:
        version = subprocess.check_output(
            shlex.split(env.subst(env["CXX"]), posix=False) + ["--version"], shell=(os.name == "nt"), encoding="utf-8"
        ).strip()
    except (subprocess.CalledProcessError, OSError):
        print("Couldn't parse CXX environment variable to infer compiler version.")
        return update_compiler_version_cache(ret)

    match = re.search(
        r"(?:(?<=version )|(?<=\) )|(?<=^))"
        r"(?P<major>\d+)"
        r"(?:\.(?P<minor>\d*))?"
        r"(?:\.(?P<patch>\d*))?"
        r"(?:-(?P<metadata1>[0-9a-zA-Z-]*))?"
        r"(?:\+(?P<metadata2>[0-9a-zA-Z-]*))?"
        r"(?: (?P<date>[0-9]{8}|[0-9]{6})(?![0-9a-zA-Z]))?",
        version,
    )
    if match is not None:
        for key, value in match.groupdict().items():
            if value is not None:
                ret[key] = value

    match_apple = re.search(
        r"(?:(?<=clang-)|(?<=\) )|(?<=^))"
        r"(?P<apple_major>\d+)"
        r"(?:\.(?P<apple_minor>\d*))?"
        r"(?:\.(?P<apple_patch1>\d*))?"
        r"(?:\.(?P<apple_patch2>\d*))?"
        r"(?:\.(?P<apple_patch3>\d*))?",
        version,
    )
    if match_apple is not None:
        for key, value in match_apple.groupdict().items():
            if value is not None:
                ret[key] = value

    # Transform semantic versioning to integers
    for key in [
        "major",
        "minor",
        "patch",
        "apple_major",
        "apple_minor",
        "apple_patch1",
        "apple_patch2",
        "apple_patch3",
    ]:
        ret[key] = int(ret[key] or -1)
    return update_compiler_version_cache(ret)


def update_compiler_version_cache(value):
    global compiler_version_cache
    compiler_version_cache = value
    return value


def options(opts):
    opts.Add(BoolVariable("use_llvm", "Use the LLVM compiler - only effective when targeting Linux", False))
    opts.Add(BoolVariable("use_static_cpp", "Link libgcc and libstdc++ statically for better portability", True))
    opts.Add(
        EnumVariable("linker", "Linker program", "default", ["default", "bfd", "gold", "lld", "mold"], ignorecase=2),
    )


def exists(env):
    return True


def using_gcc(env) -> bool:
    return not env["use_llvm"]


def generate(env):
    if env["use_llvm"]:
        clang.generate(env)
        clangxx.generate(env)
    elif env.use_hot_reload:
        # Required for extensions to truly unload.
        env.Append(CXXFLAGS=["-fno-gnu-unique"])

    if env["linker"] != "default":
        print("Using linker program: " + env["linker"])
        if env["linker"] == "mold" and using_gcc(env):  # GCC < 12.1 doesn't support -fuse-ld=mold.
            cc_version = get_compiler_version(env)
            cc_semver = (cc_version["major"], cc_version["minor"])
            if cc_semver < (12, 1):
                found_wrapper = False
                for path in ["/usr/libexec", "/usr/local/libexec", "/usr/lib", "/usr/local/lib"]:
                    if os.path.isfile(path + "/mold/ld"):
                        env.Append(LINKFLAGS=["-B" + path + "/mold"])
                        found_wrapper = True
                        break
                if not found_wrapper:
                    for path in os.environ["PATH"].split(os.pathsep):
                        if os.path.isfile(path + "/ld.mold"):
                            env.Append(LINKFLAGS=["-B" + path])
                            found_wrapper = True
                            break
                    if not found_wrapper:
                        print(
                            "Couldn't locate mold installation path. Make sure it's installed in /usr, /usr/local or in PATH environment variable."
                        )
                        sys.exit(255)
            else:
                env.Append(LINKFLAGS=["-fuse-ld=mold"])
        else:
            env.Append(LINKFLAGS=["-fuse-ld=%s" % env["linker"]])

    env.Append(CCFLAGS=["-fPIC", "-Wwrite-strings"])
    env.Append(LINKFLAGS=["-Wl,-R,'$$ORIGIN'"])

    if env["arch"] == "x86_64":
        # -m64 and -m32 are x86-specific already, but it doesn't hurt to
        # be clear and also specify -march=x86-64. Similar with 32-bit.
        env.Append(CCFLAGS=["-m64", "-march=x86-64"])
        env.Append(LINKFLAGS=["-m64", "-march=x86-64"])
    elif env["arch"] == "x86_32":
        env.Append(CCFLAGS=["-m32", "-march=i686"])
        env.Append(LINKFLAGS=["-m32", "-march=i686"])
    elif env["arch"] == "arm64":
        env.Append(CCFLAGS=["-march=armv8-a"])
        env.Append(LINKFLAGS=["-march=armv8-a"])
    elif env["arch"] == "rv64":
        env.Append(CCFLAGS=["-march=rv64gc"])
        env.Append(LINKFLAGS=["-march=rv64gc"])

    # Link statically for portability
    if env["use_static_cpp"]:
        env.Append(LINKFLAGS=["-static-libgcc", "-static-libstdc++"])

    env.Append(CPPDEFINES=["LINUX_ENABLED", "UNIX_ENABLED"])

    # Refer to https://github.com/godotengine/godot/blob/master/platform/linuxbsd/detect.py
    if env["lto"] == "auto":
        env["lto"] = "full"

    common_compiler_flags.generate(env)
