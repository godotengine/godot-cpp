#!/usr/bin/env python

import json
import os
import re
import sys


def parse_header_file(file_path):
    types = {"classes": [], "structs": [], "defines": [], "enums": []}

    with open(file_path, "r", encoding="utf-8") as file:
        content = file.read()

        # Regular expressions to match different types
        struct_pattern = r"struct.*\s(\S+)\s*\{"
        type_pattern = r"typedef.*\s(\S+)\s*\;"
        enum_pattern = r"enum.*\s(\S+)\s*\{"
        class_pattern = r"class\s+[\w\s]*?([a-zA-Z_]\w*)\s*[:{]"
        define_pattern = r"#define\s+([a-zA-Z_]\w*)"

        # Extract classes
        types["classes"] += re.findall(class_pattern, content)

        # Extract structs
        struct_names = re.findall(struct_pattern, content)
        types["structs"].extend(struct_names)
        type_names = re.findall(type_pattern, content)
        types["structs"].extend(type_names)
        enum_names = re.findall(enum_pattern, content)
        types["enums"].extend(enum_names)

        # Extract defines
        define_matches = re.findall(define_pattern, content)
        types["defines"] += define_matches

    # Debug the case where no classes or structs are found
    # if len(types["classes"]) == 0 and len(types["structs"]) == 0 and len(types["defines"]) == 0:
    #    print(f"{file_path} missing things")
    return types


def map_header_files(directory):
    file_types_mapping = {}
    for root, dirs, files in os.walk(directory):
        if "thirdparty" in dirs:
            dirs.remove("thirdparty")
        if "tests" in dirs:
            dirs.remove("tests")
        if "test" in dirs:
            dirs.remove("test")
        if "misc" in dirs:
            dirs.remove("misc")
        if "gdextension" in dirs:
            dirs.remove("gdextension")
        for file in files:
            if file.endswith(".h") or file.endswith(".hpp"):
                relative_path = os.path.relpath(root, directory)
                file_path = os.path.join(root, file)
                file_types_mapping[f"{relative_path}/{file}"] = parse_header_file(file_path)

    return file_types_mapping


if __name__ == "__main__":
    # Get current directory for godot-cpp
    current_directory = os.path.join(os.getcwd(), "")
    mapping_name = ""
    if len(sys.argv) > 1:
        mapping_name = "_godot"
        current_directory = os.path.join(os.getcwd(), sys.argv[1])

    file_types_mapping = map_header_files(current_directory)
    with open(f"output_header_mapping{mapping_name}.json", "w") as json_file:
        json.dump(file_types_mapping, json_file, indent=4)
