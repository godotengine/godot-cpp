# Using output_header_mapping.json convert all imports in specified source folder location from godot imports to godot-compat imports


import json
import os
import sys

from compat_generator import map_header_files
from header_matcher import match_headers

if __name__ == "__main__":
    if len(sys.argv) > 3:
        src_directory = os.path.join(os.getcwd(), sys.argv[1])
        godot_directory = os.path.join(os.getcwd(), sys.argv[2])
        godot_cpp_directory = os.path.join(os.getcwd(), sys.argv[3])
    else:
        raise Exception("Usage: python module_converter.py <source directory> <godot directory> <godot-cpp directory>")
    # Load the godot mappings
    with open(f"{godot_directory}/output_header_mapping_godot.json", "r") as file:
        godot_mappings = json.load(file)
    
    # Generate mappings for godot-cpp
    godot_cpp_mappings = map_header_files(godot_cpp_directory)
    matches = match_headers(godot_mappings, godot_cpp_mappings)
    # Save matches to a file
    with open("header_matches.json", "w") as outfile:
        json.dump(matches, outfile, indent=4)
    src_directory = os.getcwd()
    # Go through folder specified through all files with .cpp, .h or .hpp
    for root, dirs, files in os.walk(src_directory):
        for file in files:
            if file.endswith(".cpp") or file.endswith(".h") or file.endswith(".hpp"):
                with open(os.path.join(root, file), "r") as f:
                    content = f.read()

                # Replace imports to godot imports with godot_compat imports
                for match in matches:
                    generate_imports = matches[match]
                    godot_compat_imports = ""
                    for generate_import in generate_imports:
                        godot_compat_import = generate_import.replace("gen/include/godot_cpp/", "godot_compat/")
                        godot_compat_import = godot_compat_import.replace("include/godot_cpp/", "godot_compat/")
                        godot_compat_imports += f"#include <{godot_compat_import}>\n"
                    # Remove last 'n from imports
                    godot_compat_imports = godot_compat_imports[:-1]
                    content = content.replace(f"#include \"{match}\"", godot_compat_imports)
                # Write the modified content back to the file
                with open(os.path.join(root, file), "w") as f:
                    f.write(content)
