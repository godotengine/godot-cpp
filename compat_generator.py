import re
import os
import json
import sys


def parse_header_file(file_path):
    types = {"classes": [], "structs": [], "defines": []}

    with open(file_path, "r", encoding="utf-8") as file:
        content = file.read()

        # Regular expressions to match different types
        struct_pattern = r"struct\s+[\w\s]*?([a-zA-Z_]\w*)\s*[:{]"
        class_pattern = r"class\s+[\w\s]*?([a-zA-Z_]\w*)\s*[:{]"
        define_pattern = r"#define\s+([a-zA-Z_]\w*)"

        # Extract classes
        types["classes"] += re.findall(class_pattern, content)

        # Extract structs
        types["structs"] += re.findall(struct_pattern, content)

        # Extract defines
        define_matches = re.findall(define_pattern, content)
        types["defines"] += define_matches

    if len(types["classes"]) == 0 and len(types["structs"]) == 0 and len(types["defines"]) == 0:
        print(f"{file_path} missing things")
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
        for file in files:
            if file.endswith(".h") or file.endswith(".hpp"):
                relative_path = os.path.relpath(root, directory)
                file_path = os.path.join(root, file)
                file_types_mapping[f"{relative_path}/{file}"] = parse_header_file(file_path)

    return file_types_mapping


if __name__ == "__main__":
    # Get current directory
    current_directory = os.getcwd()

    if len(sys.argv) > 1:
        current_directory = os.path.join(os.getcwd(), sys.argv[1])

    file_types_mapping = map_header_files(current_directory)
    with open("output_header_mapping.json", "w") as json_file:
        json.dump(file_types_mapping, json_file, indent=4)
