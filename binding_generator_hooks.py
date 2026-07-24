class BindingGeneratorHooks:
    def alter_engine_class_header(self, class_api, lines):
        return lines

    def alter_engine_class_source(self, class_api, lines):
        return lines

    def alter_global_constants(self, api, lines):
        return lines

    def alter_utility_functions_header(self, api, lines):
        return lines

    def alter_utility_functions_source(self, api, lines):
        return lines

    def alter_builtin_class_header(self, builtin_api, lines):
        return lines

    def alter_builtin_class_source(self, builtin_api, lines):
        return lines

    # and more...
