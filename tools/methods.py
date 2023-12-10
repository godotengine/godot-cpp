import os

# Useful methods for custom scripts


# A utility function for getting the name of an unblocked file
def _get_unblocked_file_name(original_file_path, new_file_ext, max_files=256, keep_newest_one=True):
    lib_dir = os.path.normpath(os.path.dirname(original_file_path))
    lib_name = os.path.splitext(os.path.basename(original_file_path))[0]

    # Collect all matching files
    found_files = [
        f
        for f in os.listdir(lib_dir)
        if os.path.isfile(os.path.join(lib_dir, f)) and f.startswith(lib_name) and f.endswith("." + new_file_ext)
    ]
    found_files = sorted(found_files, key=lambda x: os.path.getmtime(os.path.join(lib_dir, x)))

    # Clean up the old files if possible, except for the newest one
    if found_files:
        if keep_newest_one:
            found_files.pop()
        for f in found_files:
            try:
                os.remove(os.path.join(lib_dir, f))
            except:
                pass

    # Search for a unblocked file name
    file_name = ""
    for s in range(max_files):
        file_name = "{}_{}.{}".format(os.path.join(lib_dir, lib_name), s, new_file_ext)
        if not os.path.exists(file_name):
            break
        try:
            with open(file_name, "a") as f:
                pass
        except IOError:
            continue
        break

    return file_name


# This is necessary to support debugging and Hot-Reload at the same time when building using MSVC
def msvc_try_rename_pdb(env, full_lib_path):
    if not env.get("is_msvc", False):
        print("Renaming the PDB file will be ignored because of a compiler mismatch.")
        return
    if not env["debug_symbols"]:
        print("Renaming the PDB file will be ignored because debug symbols generation is disabled.")
        return
    if not env["use_hot_reload"]:
        print("Renaming the PDB file will be ignored because Hot-Reload is disabled.")
        return

    pdb_name = _get_unblocked_file_name(full_lib_path, "pdb")
    print("New path to the PDB: " + pdb_name)

    # Explicit assignment of the PDB path
    env.Append(LINKFLAGS=["/PDB:" + pdb_name])
