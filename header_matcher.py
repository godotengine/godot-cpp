import json


def match_headers(mapping1, mapping2):
    matches = {}
    for header_file, data1 in mapping1.items():
        for header_file2, data2 in mapping2.items():
            # Check if classes in header_file1 are present in header_file2
            if any(class_name in data2["classes"] for class_name in data1["classes"]):
                if header_file not in matches:
                    matches[header_file] = []
                matches[header_file].append(header_file2)
    return matches


if __name__ == "__main__":
    # Load the two header mappings
    with open("output_header_mapping.json", "r") as file:
        mapping1 = json.load(file)

    with open("output_header_mapping_godot.json", "r") as file:
        mapping2 = json.load(file)

    # Match the headers
    matches = match_headers(mapping1, mapping2)

    # Output the matches
    for header_file, matching_files in matches.items():
        print(f"{header_file} matches with:")
        for matching_file in matching_files:
            print(f"- {matching_file}")
        print()

    # Optionally, you can save the matches to a file
    with open("header_matches.json", "w") as outfile:
        json.dump(matches, outfile, indent=4)
