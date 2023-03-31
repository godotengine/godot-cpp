import os


def exists(env):
    return os.name == "nt"


# Workaround for MinGW. See:
# http://www.scons.org/wiki/LongCmdLinesOnWin32
def configure(env):
    import subprocess

    def mySubProcess(cmdline, env):
        # print("SPAWNED: " + cmdline)
        proc = subprocess.run(
            args=cmdline,
            shell=True,
            env=env,
        )
        rv = proc.returncode
        if rv:
            print("=====")
            print(rv, "(", hex(rv), ")")
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
