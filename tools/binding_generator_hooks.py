class BindingGeneratorHooks:
    # Alter all class header files generated in `include/godot_cpp/classes`, such as `node_3d.hpp`, `object.hpp`, and `resource.hpp`.
    def alter_engine_class_header(self, class_api, lines):
        return lines

    # Alter all class source files generated in `src/classes`, the `.cpp` counterparts to the headers modified by `alter_engine_class_header`.
    def alter_engine_class_source(self, class_api, lines):
        return lines

    # Alter the `include/godot_cpp/classes/global_constants.hpp` file, which defines many enums.
    def alter_global_constants(self, api, lines):
        return lines

    # Alter the `include/godot_cpp/variant/utility_functions.hpp` file, which contains utility functions such as math or print functions.
    def alter_utility_functions_header(self, api, lines):
        return lines

    # Alter the `src/variant/utility_functions.cpp` file, which provides implementations of the declarations in the header file.
    def alter_utility_functions_source(self, api, lines):
        return lines

    # Alter built-in class headers generated in `include/godot_cpp/variant/`. Built-in classes include `Dictionary`, `PackedInt32Array`, and `StringName`.
    def alter_builtin_class_header(self, builtin_api, lines):
        return lines

    # Alter built-in class sources generated in `src/variant/`, the implementations of the built-in classes.
    def alter_builtin_class_source(self, builtin_api, lines):
        return lines
