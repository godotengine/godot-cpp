import os


def options(opts):
    opts.Add("osxcross_sdk", "OSXCross SDK version", "darwin16")


def exists(env):
    return "OSXCROSS_ROOT" in os.environ


def generate(env):
    root = os.environ.get("OSXCROSS_ROOT", "")
    if env["arch"] == "arm64":
        basecmd = root + "/target/bin/arm64-apple-" + env["osxcross_sdk"] + "-"
    else:
        basecmd = root + "/target/bin/x86_64-apple-" + env["osxcross_sdk"] + "-"

    env["CC"] = basecmd + "clang"
    env["CXX"] = basecmd + "clang++"
    env["AR"] = basecmd + "ar"
    env["RANLIB"] = basecmd + "ranlib"
    env["AS"] = basecmd + "as"

    binpath = os.path.join(root, "target", "bin")
    if binpath not in env["ENV"]["PATH"]:
        # Add OSXCROSS bin folder to PATH (required for linking).
        env["ENV"]["PATH"] = "%s:%s" % (binpath, env["ENV"]["PATH"])
