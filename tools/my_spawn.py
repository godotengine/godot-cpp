import os


def exists(env):
    return os.name == "nt"


# Workaround for MinGW. See:
# http://www.scons.org/wiki/LongCmdLinesOnWin32
def configure(env):
    import subprocess

    def mySubProcess(cmdline, env):
        # print(cmdline)
        rv = subprocess.run(args=cmdline, shell=True, env=env).returncode
        if rv:
            print("=====")
            print("subprocess.run().returncode=", rv, "(", hex(rv), ")")
            print("len(cmdline)=", len(cmdline))
            print("=====")
        return rv

    def mySpawn(sh, escape, cmd, args, env):
        newargs = " ".join(args[1:])
        cmdline = cmd + " " + newargs

        rv = 0
        if len(args) > 4 and cmd.endswith("ar"):
            # print("Long ar command is split.\nargc=", len(args))
            lead = len(" ".join(args[0:3]))
            begin = 3
            length = lead + 1 + len(args[begin])
            for i in range(4, len(args)):
                length += 1 + len(args[i])
                if length > 8158:
                    cmdline = " ".join(args[0:3] + args[begin:i])
                    # print("objs=", i - begin, ", length=", len(cmdline))
                    rv = mySubProcess(cmdline, env)
                    if rv:
                        break
                    begin = i
                    length = lead + 1 + len(args[begin])
            if not rv:
                cmdline = " ".join(args[0:3] + args[begin:])
                # print("objs=", len(args) - begin, ", length=", len(cmdline))
                rv = mySubProcess(cmdline, env)
        else:
            rv = mySubProcess(" ".join(args), env)
        return rv

    env["SPAWN"] = mySpawn
    env.Replace(ARFLAGS=["q"])
