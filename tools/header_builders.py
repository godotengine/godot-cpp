import os.path


## See https://github.com/godotengine/godot/blob/master/glsl_builders.py
def build_raw_header(source_filename: str, constant_name: str) -> None:
    # Read the source file content.
    with open(source_filename, "r") as source_file:
        source_content = source_file.read()
        constant_name = constant_name.replace(".", "_")
        # Build header content using a C raw string literal.
        header_content = (
            "/* THIS FILE IS GENERATED. EDITS WILL BE LOST. */\n\n"
            "#pragma once\n\n"
            f"inline constexpr const char *{constant_name}"
            " = "
            f'R"<!>({source_content})<!>"'
            ";\n"
        )
        # Write the header to the provided file name with a ".gen.h" suffix.
        header_filename = f"{source_filename}.gen.h"
        with open(header_filename, "w") as header_file:
            header_file.write(header_content)


def build_raw_headers_action(target, source, env):
    env.NoCache(target)
    for src in source:
        source_filename = str(src)
        # To match Godot, replace ".glsl" with "_shader_glsl". Does nothing for non-GLSL files.
        constant_name = os.path.basename(source_filename).replace(".glsl", "_shader_glsl")
        build_raw_header(source_filename, constant_name)


def escape_svg(filename: str) -> str:
    with open(filename, encoding="utf-8", newline="\n") as svg_file:
        svg_content = svg_file.read()
        return f'R"<!>({svg_content})<!>"'


## See https://github.com/godotengine/godot/blob/master/editor/icons/editor_icons_builders.py
## See https://github.com/godotengine/godot/blob/master/scene/theme/icons/default_theme_icons_builders.py
def make_svg_icons_action(target, source, env):
    destination = str(target[0])
    constant_prefix = os.path.basename(destination).replace(".gen.h", "")
    svg_icons = [str(x) for x in source]
    # Convert the SVG icons to escaped strings and convert their names to C strings.
    icon_names = [f'"{os.path.basename(fname)[:-4]}"' for fname in svg_icons]
    icon_sources = [escape_svg(fname) for fname in svg_icons]
    # Join them as indented comma-separated items for use in an array initializer.
    icon_names_str = ",\n\t".join(icon_names)
    icon_sources_str = ",\n\t".join(icon_sources)
    # Write the file to disk.
    with open(destination, "w", encoding="utf-8", newline="\n") as destination_file:
        destination_file.write(
            f"""\
/* THIS FILE IS GENERATED. EDITS WILL BE LOST. */

#pragma once

inline constexpr int {constant_prefix}_count = {len(icon_names)};
inline constexpr const char *{constant_prefix}_sources[] = {{
	{icon_sources_str}
}};

inline constexpr const char *{constant_prefix}_names[] = {{
	{icon_names_str}
}};
"""
        )
