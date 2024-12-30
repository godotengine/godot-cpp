#!/usr/bin/env python

import os
import sys
from pathlib import Path

sys.path.insert(1, os.path.join(os.path.dirname(__file__), "..", ".."))

from binding_generator import generate_bindings, get_file_list

api_filepath = "gdextension/extension_api.json"
bits = "64"
precision = "single"
output_dir = "self_test"


def test(profile_filepath=""):
    generate_bindings(
        api_filepath,
        use_template_get_node=False,
        bits=bits,
        precision=precision,
        output_dir=output_dir,
        profile_filepath=profile_filepath,
    )
    flist = get_file_list(api_filepath, output_dir, headers=True, sources=True, profile_filepath=profile_filepath)

    p = Path(output_dir) / "gen"
    allfiles = [str(f.as_posix()) for f in p.glob("**/*.*")]
    missing = list(filter((lambda f: f not in flist), allfiles))
    extras = list(filter((lambda f: f not in allfiles), flist))
    if len(missing) > 0 or len(extras) > 0:
        print("Error!")
        for f in missing:
            print("MISSING: " + str(f))
        for f in extras:
            print("EXTRA: " + str(f))
        sys.exit(1)
    else:
        print("OK!")


test("test/build_profile.json")
test()
