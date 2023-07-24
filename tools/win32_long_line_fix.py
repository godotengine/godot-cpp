import os, sys, subprocess


def exists(env):
    return os.name == "nt" or sys.platform == "cygwin"


def generate(env):
    if env.get("is_msvc", False):
        # Applied by MSVC tool.
        return

    # Workaround for long command lines on Windows. See:
    # http://www.scons.org/wiki/LongCmdLinesOnWin32
    def mySubProcess(cmdline, env):
        # print "SPAWNED : " + cmdline
        if os.name == "nt":
            shell = False
            startupinfo = subprocess.STARTUPINFO()
            startupinfo.dwFlags |= subprocess.STARTF_USESHOWWINDOW
        else:
            shell = True  # Needed when os is posix (windows + cygwin/msys2).
            startupinfo = None

        proc = subprocess.Popen(
            cmdline,
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            startupinfo=startupinfo,
            shell=shell,
            env=env,
        )
        data, err = proc.communicate()
        rv = proc.wait()
        if rv:
            print("=====")
            print(err.decode("utf-8"))
            print("=====")
        return rv

    def mySpawn(sh, escape, cmd, args, env):

        newargs = " ".join(args[1:])
        cmdline = cmd + " " + newargs

        rv = 0
        if len(cmdline) > 32000 and cmd.endswith("ar"):
            cmdline = cmd + " " + args[1] + " " + args[2] + " "
            for i in range(3, len(args)):
                rv = mySubProcess(cmdline + args[i], env)
                if rv:
                    break
        else:
            rv = mySubProcess(cmdline, env)

        return rv

    env["SPAWN"] = mySpawn
    env.Replace(ARFLAGS=["q"])
