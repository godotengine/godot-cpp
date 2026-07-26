import os


def exists(env):
    return os.name == "nt"


# Workaround for MinGW. See:
# http://www.scons.org/wiki/LongCmdLinesOnWin32
def configure(env):
    import subprocess
    import sys

    def mySubProcess(cmdline, env):
        # print "SPAWNED : " + cmdline
        startupinfo = subprocess.STARTUPINFO()
        startupinfo.dwFlags |= subprocess.STARTF_USESHOWWINDOW
        proc = subprocess.Popen(
            cmdline,
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            startupinfo=startupinfo,
            shell=False,
            env=env,
        )
        data, err = proc.communicate()
        rv = proc.wait()
        if rv:
            print("=====")
            print(err.decode(sys.stdout.encoding, errors="replace"))
            print("=====")
        return rv

    def mySpawn(sh, escape, cmd, args, env):
        # Used by TEMPFILE, which spawns a "del" command to clean up the response file.
        # See the equivalent code in the engine in `methods.py`.
        if cmd == "del":
            os.remove(args[1])
            return 0

        newargs = " ".join(args[1:])
        cmdline = cmd + " " + newargs

        return mySubProcess(cmdline, env)

    env["SPAWN"] = mySpawn
