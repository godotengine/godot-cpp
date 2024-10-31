import json
import os

from compat_generator import map_header_files


def match_headers(mapping1, mapping2):
    matches = {}
    for header_file, data1 in mapping1.items():
        for header_file2, data2 in mapping2.items():
            # Check if classes/defines/structs in header_file1 are present in header_file2
            if header_file not in matches:
                matches[header_file] = []
            if (
                any(class_name in data2["classes"] for class_name in data1["classes"])
                or any(define_name in data2["defines"] for define_name in data1["defines"])
                or any(define_name in data2["structs"] for define_name in data1["structs"])
            ):  # or
                # any(define_name in data2["enums"] for define_name in data1["enums"])):
                matches[header_file].append(header_file2)
    return matches


if __name__ == "__main__":
    # Load the two header mappings
    with open("output_header_mapping_godot.json", "r") as file:
        mapping_godot = json.load(file)
    file_types_mapping_godot_cpp_gen = map_header_files(os.path.join(os.getcwd(), "gen", "include"))
    matches = match_headers(file_types_mapping_godot_cpp_gen, mapping_godot)

    # Optionally, you can save the matches to a file
    with open("header_matches.json", "w") as outfile:
        json.dump(matches, outfile, indent=4)
