import os
import re

# Backslashes that aren't escaping a quote or another backslash.
WINPATHSEP_RE = re.compile(r"\\([^\"'\\]|$)")


def tempfile_arg_esc_func(arg):
    from SCons.Subst import quote_spaces

    arg = quote_spaces(arg)
    # GCC requires double Windows slashes, let's use UNIX separator
    return WINPATHSEP_RE.sub(r"/\1", arg)


# The generated bindings can produce enough object files to exceed the command
# line length limit when creating the static library. This works around that by
# writing the command to a response file. Refer to the engine equivalent in
# https://github.com/godotengine/godot/blob/master/platform/windows/detect.py
def configure(env):
    # This is SCons lazy evaluation syntax, only switching to a file when the command is actually too long.
    # The flags must stay in the command (not in the file) to work with GCC 13 or older.
    env["ARCOM"] = "$AR $ARFLAGS ${TEMPFILE('$TARGET $SOURCES', '$ARCOMSTR')}"
    env["TEMPFILESUFFIX"] = ".rsp"
    if os.name == "nt":
        env["TEMPFILEARGESCFUNC"] = tempfile_arg_esc_func
