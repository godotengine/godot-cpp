#!/usr/bin/env python

import argparse
import re
import subprocess
from dataclasses import dataclass


@dataclass()
class Opts:
    use_llvm: str = "yes"
    optimize: str = "none"
    debug_symbols: str = "yes"
    compiledb: str = "yes"
    use_pch: str = "yes"


def get_command() -> str:
    cmd = "scons"
    for key, value in opts.__dict__.items():
        cmd += f" {key}={value}"
    return cmd


def run(cmd: str = get_command()):
    return subprocess.run(cmd, shell=True)


def get_pch_build_command(file_path: str, json_file_path: str = "compile_commands.json") -> str:
    """
    Extracts the "command" associated with a given "file" from compile_commands.json.

    Scons and godot have no pre compiled header support for clang so have to use stupid hacks to make it work
    Hacky steps to compile pch:
    1. Run `bd.py build_pch` this will then:
    2. find the pch.cpp (file_path) entry in the generated compile_commands.json file
    3. Copy the "command" parameter string to get the full compile command.
    4. Change "-o /path/to/pch.cpp" to -o /path/to/src/pch.hpp.pch at the front of the command
    5. Change the command target the the end of the command to "/path/to/src/pch.hpp"
    6. Run the compile command with the replaced output and input arguments to compile the pch file

    Note: If using with ccache make a file "~/.config/ccache/ccache.conf" with "sloppiness = pch_defines,time_macros" in it or ccache will not work with PCH.
    """
    import json

    try:
        with open(json_file_path, "r") as file:
            data = json.load(file)

        if isinstance(data, list):
            for entry in data:
                if not isinstance(entry, dict):
                    continue

                command = entry.get("command")
                cpp_file = entry.get("file")
                if command and cpp_file and file_path in cpp_file:
                    return str(command)

        print(f"No pch command found for file: {file_path}")
        return ""

    except FileNotFoundError:
        print(f"Error: The file '{json_file_path}' was not found.")
    except json.JSONDecodeError:
        print("Error: Failed to decode JSON. Please check the file format.")
    except Exception as e:
        print(f"An unexpected error occurred: {e}")

    return ""


def build_pch(pch_path: str):
    command = get_pch_build_command(pch_path + ".cpp")
    if not command:
        return

    command = command.replace(pch_path + ".os", pch_path + ".hpp.pch")
    command = command.replace(pch_path + ".cpp", pch_path + ".hpp")
    command = command.replace(
        "-fno-exceptions", "-fno-exceptions -fpch-codegen -fpch-preprocess -fpch-instantiate-templates"
    )
    command = re.sub(r"-include-pch\s.*(hpp\.pch)", "", command)
    command = command.replace("register_types", "pch")

    print("Precompiling header: ", pch_path.replace("register_types", "pch") + ".hpp")
    run(command)


parser = argparse.ArgumentParser()
parser.add_argument(
    "command",
    choices=[
        "build_pch",
        "time_trace",
    ],
    nargs="?",
    help="Build command to execute.",
)

args = parser.parse_args()

opts = Opts()

if args.command == "build_pch":
    opts.use_pch = "no"
    build_pch("src/register_types")
    exit(0)

run()
