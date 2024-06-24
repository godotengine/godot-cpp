import os
import platform
import sys

from SCons.Action import Action
from SCons.Builder import Builder
from SCons.Errors import UserError
from SCons.Script import ARGUMENTS
from SCons.Tool import Tool
from SCons.Variables import BoolVariable, EnumVariable, PathVariable
from SCons.Variables.BoolVariable import _text2bool

from binding_generator import scons_emit_files, scons_generate_bindings


def add_sources(sources, dir, extension):
    for f in os.listdir(dir):
        if f.endswith("." + extension):
            sources.append(dir + "/" + f)


def get_cmdline_bool(option, default):
    """We use `ARGUMENTS.get()` to check if options were manually overridden on the command line,
    and SCons' _text2bool helper to convert them to booleans, otherwise they're handled as strings.
    """
    cmdline_val = ARGUMENTS.get(option)
    if cmdline_val is not None:
        return _text2bool(cmdline_val)
    else:
        return default


def normalize_path(val, env):
    return val if os.path.isabs(val) else os.path.join(env.Dir("#").abspath, val)


def validate_file(key, val, env):
    if not os.path.isfile(normalize_path(val, env)):
        raise UserError("'%s' is not a file: %s" % (key, val))


def validate_dir(key, val, env):
    if not os.path.isdir(normalize_path(val, env)):
        raise UserError("'%s' is not a directory: %s" % (key, val))


def validate_parent_dir(key, val, env):
    if not os.path.isdir(normalize_path(os.path.dirname(val), env)):
        raise UserError("'%s' is not a directory: %s" % (key, os.path.dirname(val)))


def get_platform_tools_paths(env):
    path = env.get("custom_tools", None)
    if path is None:
        return ["tools"]
    return [normalize_path(path, env), "tools"]


def get_custom_platforms(env):
    path = env.get("custom_tools", None)
    if path is None:
        return []
    platforms = []
    for x in os.listdir(normalize_path(path, env)):
        if not x.endswith(".py"):
            continue
        platforms.append(x.removesuffix(".py"))
    return platforms


def no_verbose(env):
    colors = {}

    # Colors are disabled in non-TTY environments such as pipes. This means
    # that if output is redirected to a file, it will not contain color codes
    if sys.stdout.isatty():
        colors["blue"] = "\033[0;94m"
        colors["bold_blue"] = "\033[1;94m"
        colors["reset"] = "\033[0m"
    else:
        colors["blue"] = ""
        colors["bold_blue"] = ""
        colors["reset"] = ""

    # There is a space before "..." to ensure that source file names can be
    # Ctrl + clicked in the VS Code terminal.
    compile_source_message = "{}Compiling {}$SOURCE{} ...{}".format(
        colors["blue"], colors["bold_blue"], colors["blue"], colors["reset"]
    )
    java_compile_source_message = "{}Compiling {}$SOURCE{} ...{}".format(
        colors["blue"], colors["bold_blue"], colors["blue"], colors["reset"]
    )
    compile_shared_source_message = "{}Compiling shared {}$SOURCE{} ...{}".format(
        colors["blue"], colors["bold_blue"], colors["blue"], colors["reset"]
    )
    link_program_message = "{}Linking Program {}$TARGET{} ...{}".format(
        colors["blue"], colors["bold_blue"], colors["blue"], colors["reset"]
    )
    link_library_message = "{}Linking Static Library {}$TARGET{} ...{}".format(
        colors["blue"], colors["bold_blue"], colors["blue"], colors["reset"]
    )
    ranlib_library_message = "{}Ranlib Library {}$TARGET{} ...{}".format(
        colors["blue"], colors["bold_blue"], colors["blue"], colors["reset"]
    )
    link_shared_library_message = "{}Linking Shared Library {}$TARGET{} ...{}".format(
        colors["blue"], colors["bold_blue"], colors["blue"], colors["reset"]
    )
    java_library_message = "{}Creating Java Archive {}$TARGET{} ...{}".format(
        colors["blue"], colors["bold_blue"], colors["blue"], colors["reset"]
    )
    compiled_resource_message = "{}Creating Compiled Resource {}$TARGET{} ...{}".format(
        colors["blue"], colors["bold_blue"], colors["blue"], colors["reset"]
    )
    generated_file_message = "{}Generating {}$TARGET{} ...{}".format(
        colors["blue"], colors["bold_blue"], colors["blue"], colors["reset"]
    )

    env.Append(CXXCOMSTR=[compile_source_message])
    env.Append(CCCOMSTR=[compile_source_message])
    env.Append(SHCCCOMSTR=[compile_shared_source_message])
    env.Append(SHCXXCOMSTR=[compile_shared_source_message])
    env.Append(ARCOMSTR=[link_library_message])
    env.Append(RANLIBCOMSTR=[ranlib_library_message])
    env.Append(SHLINKCOMSTR=[link_shared_library_message])
    env.Append(LINKCOMSTR=[link_program_message])
    env.Append(JARCOMSTR=[java_library_message])
    env.Append(JAVACCOMSTR=[java_compile_source_message])
    env.Append(RCCOMSTR=[compiled_resource_message])
    env.Append(GENCOMSTR=[generated_file_message])


platforms = ["linux", "macos", "windows", "android", "ios", "web"]

# CPU architecture options.
architecture_array = [
    "",
    "universal",
    "x86_32",
    "x86_64",
    "arm32",
    "arm64",
    "rv64",
    "ppc32",
    "ppc64",
    "wasm32",
]
architecture_aliases = {
    "x64": "x86_64",
    "amd64": "x86_64",
    "armv7": "arm32",
    "armv8": "arm64",
    "arm64v8": "arm64",
    "aarch64": "arm64",
    "rv": "rv64",
    "riscv": "rv64",
    "riscv64": "rv64",
    "ppcle": "ppc32",
    "ppc": "ppc32",
    "ppc64le": "ppc64",
}


def exists(env):
    return True


def options(opts, env):
    # Try to detect the host platform automatically.
    # This is used if no `platform` argument is passed
    if sys.platform.startswith("linux"):
        default_platform = "linux"
    elif sys.platform == "darwin":
        default_platform = "macos"
    elif sys.platform == "win32" or sys.platform == "msys":
        default_platform = "windows"
    elif ARGUMENTS.get("platform", ""):
        default_platform = ARGUMENTS.get("platform")
    else:
        raise ValueError("Could not detect platform automatically, please specify with platform=<platform>")

    opts.Add(
        PathVariable(
            key="custom_tools",
            help="Path to directory containing custom tools",
            default=env.get("custom_tools", None),
            validator=validate_dir,
        )
    )

    opts.Update(env)

    custom_platforms = get_custom_platforms(env)

    opts.Add(
        EnumVariable(
            key="platform",
            help="Target platform",
            default=env.get("platform", default_platform),
            allowed_values=platforms + custom_platforms,
            ignorecase=2,
        )
    )

    # Editor and template_debug are compatible (i.e. you can use the same binary for Godot editor builds and Godot debug templates).
    # Godot release templates are only compatible with "template_release" builds.
    # For this reason, we default to template_debug builds, unlike Godot which defaults to editor builds.
    opts.Add(
        EnumVariable(
            key="target",
            help="Compilation target",
            default=env.get("target", "template_debug"),
            allowed_values=("editor", "template_release", "template_debug"),
        )
    )
    opts.Add(
        PathVariable(
            key="gdextension_dir",
            help="Path to a custom directory containing GDExtension interface header and API JSON file",
            default=env.get("gdextension_dir", None),
            validator=validate_dir,
        )
    )
    opts.Add(
        PathVariable(
            key="custom_api_file",
            help="Path to a custom GDExtension API JSON file (takes precedence over `gdextension_dir`)",
            default=env.get("custom_api_file", None),
            validator=validate_file,
        )
    )
    opts.Add(
        BoolVariable(
            key="generate_bindings",
            help="Force GDExtension API bindings generation. Auto-detected by default.",
            default=env.get("generate_bindings", False),
        )
    )
    opts.Add(
        BoolVariable(
            key="generate_template_get_node",
            help="Generate a template version of the Node class's get_node.",
            default=env.get("generate_template_get_node", True),
        )
    )
    opts.Add(
        BoolVariable(
            key="build_library",
            help="Build the godot-cpp library.",
            default=env.get("build_library", True),
        )
    )
    opts.Add(
        EnumVariable(
            key="precision",
            help="Set the floating-point precision level",
            default=env.get("precision", "single"),
            allowed_values=("single", "double"),
        )
    )
    opts.Add(
        EnumVariable(
            key="arch",
            help="CPU architecture",
            default=env.get("arch", ""),
            allowed_values=architecture_array,
            map=architecture_aliases,
        )
    )

    # compiledb
    opts.Add(
        BoolVariable(
            key="compiledb",
            help="Generate compilation DB (`compile_commands.json`) for external tools",
            default=env.get("compiledb", False),
        )
    )
    opts.Add(
        PathVariable(
            key="compiledb_file",
            help="Path to a custom `compile_commands.json` file",
            default=env.get("compiledb_file", "compile_commands.json"),
            validator=validate_parent_dir,
        )
    )

    opts.Add(
        PathVariable(
            "build_profile",
            "Path to a file containing a feature build profile",
            default=env.get("build_profile", None),
            validator=validate_file,
        )
    )

    opts.Add(
        BoolVariable(
            key="use_hot_reload",
            help="Enable the extra accounting required to support hot reload.",
            default=env.get("use_hot_reload", None),
        )
    )

    opts.Add(
        BoolVariable(
            "disable_exceptions", "Force disabling exception handling code", default=env.get("disable_exceptions", True)
        )
    )

    opts.Add(
        EnumVariable(
            key="symbols_visibility",
            help="Symbols visibility on GNU platforms. Use 'auto' to apply the default value.",
            default=env.get("symbols_visibility", "hidden"),
            allowed_values=["auto", "visible", "hidden"],
        )
    )

    opts.Add(
        EnumVariable(
            "optimize",
            "The desired optimization flags",
            "speed_trace",
            ("none", "custom", "debug", "speed", "speed_trace", "size"),
        )
    )
    opts.Add(BoolVariable("debug_symbols", "Build with debugging symbols", True))
    opts.Add(BoolVariable("dev_build", "Developer build with dev-only debugging code (DEV_ENABLED)", False))
    opts.Add(BoolVariable("verbose", "Enable verbose output for the compilation", False))

    # Add platform options (custom tools can override platforms)
    for pl in sorted(set(platforms + custom_platforms)):
        tool = Tool(pl, toolpath=get_platform_tools_paths(env))
        if hasattr(tool, "options"):
            tool.options(opts)


def generate(env):
    # Default num_jobs to local cpu count if not user specified.
    # SCons has a peculiarity where user-specified options won't be overridden
    # by SetOption, so we can rely on this to know if we should use our default.
    initial_num_jobs = env.GetOption("num_jobs")
    altered_num_jobs = initial_num_jobs + 1
    env.SetOption("num_jobs", altered_num_jobs)
    if env.GetOption("num_jobs") == altered_num_jobs:
        cpu_count = os.cpu_count()
        if cpu_count is None:
            print("Couldn't auto-detect CPU count to configure build parallelism. Specify it with the -j argument.")
        else:
            safer_cpu_count = cpu_count if cpu_count <= 4 else cpu_count - 1
            print(
                "Auto-detected %d CPU cores available for build parallelism. Using %d cores by default. You can override it with the -j argument."
                % (cpu_count, safer_cpu_count)
            )
            env.SetOption("num_jobs", safer_cpu_count)

    # Process CPU architecture argument.
    if env["arch"] == "":
        # No architecture specified. Default to arm64 if building for Android,
        # universal if building for macOS or iOS, wasm32 if building for web,
        # otherwise default to the host architecture.
        if env["platform"] in ["macos", "ios"]:
            env["arch"] = "universal"
        elif env["platform"] == "android":
            env["arch"] = "arm64"
        elif env["platform"] == "web":
            env["arch"] = "wasm32"
        else:
            host_machine = platform.machine().lower()
            if host_machine in architecture_array:
                env["arch"] = host_machine
            elif host_machine in architecture_aliases.keys():
                env["arch"] = architecture_aliases[host_machine]
            elif "86" in host_machine:
                # Catches x86, i386, i486, i586, i686, etc.
                env["arch"] = "x86_32"
            else:
                print("Unsupported CPU architecture: " + host_machine)
                env.Exit(1)

    print("Building for architecture " + env["arch"] + " on platform " + env["platform"])

    # These defaults may be needed by platform tools
    env.use_hot_reload = env.get("use_hot_reload", env["target"] != "template_release")
    env.editor_build = env["target"] == "editor"
    env.dev_build = env["dev_build"]
    env.debug_features = env["target"] in ["editor", "template_debug"]

    if env.dev_build:
        opt_level = "none"
    elif env.debug_features:
        opt_level = "speed_trace"
    else:  # Release
        opt_level = "speed"

    env["optimize"] = ARGUMENTS.get("optimize", opt_level)
    env["debug_symbols"] = get_cmdline_bool("debug_symbols", env.dev_build)

    tool = Tool(env["platform"], toolpath=get_platform_tools_paths(env))

    if tool is None or not tool.exists(env):
        raise ValueError("Required toolchain not found for platform " + env["platform"])

    tool.generate(env)

    if env.use_hot_reload:
        env.Append(CPPDEFINES=["HOT_RELOAD_ENABLED"])

    if env.editor_build:
        env.Append(CPPDEFINES=["TOOLS_ENABLED"])

    # Configuration of build targets:
    # - Editor or template
    # - Debug features (DEBUG_ENABLED code)
    # - Dev only code (DEV_ENABLED code)
    # - Optimization level
    # - Debug symbols for crash traces / debuggers
    # Keep this configuration in sync with SConstruct in upstream Godot.
    if env.debug_features:
        # DEBUG_ENABLED enables debugging *features* and debug-only code, which is intended
        # to give *users* extra debugging information for their game development.
        env.Append(CPPDEFINES=["DEBUG_ENABLED"])
        # In upstream Godot this is added in typedefs.h when DEBUG_ENABLED is set.
        env.Append(CPPDEFINES=["DEBUG_METHODS_ENABLED"])

    if env.dev_build:
        # DEV_ENABLED enables *engine developer* code which should only be compiled for those
        # working on the engine itself.
        env.Append(CPPDEFINES=["DEV_ENABLED"])
    else:
        # Disable assert() for production targets (only used in thirdparty code).
        env.Append(CPPDEFINES=["NDEBUG"])

    if env["precision"] == "double":
        env.Append(CPPDEFINES=["REAL_T_IS_DOUBLE"])

    # Allow detecting when building as a GDExtension.
    env.Append(CPPDEFINES=["GDEXTENSION"])

    # Suffix
    suffix = ".{}.{}".format(env["platform"], env["target"])
    if env.dev_build:
        suffix += ".dev"
    if env["precision"] == "double":
        suffix += ".double"
    suffix += "." + env["arch"]
    if env["ios_simulator"]:
        suffix += ".simulator"

    env["suffix"] = suffix  # Exposed when included from another project
    env["OBJSUFFIX"] = suffix + env["OBJSUFFIX"]

    # compile_commands.json
    env.Tool("compilation_db")
    env.Alias("compiledb", env.CompilationDatabase(normalize_path(env["compiledb_file"], env)))

    # Formatting
    if not env["verbose"]:
        no_verbose(env)

    # Builders
    env.Append(
        BUILDERS={
            "GodotCPPBindings": Builder(action=Action(scons_generate_bindings, "$GENCOMSTR"), emitter=scons_emit_files)
        }
    )
    env.AddMethod(_godot_cpp, "GodotCPP")


def _godot_cpp(env):
    extension_dir = normalize_path(env.get("gdextension_dir", env.Dir("gdextension").abspath), env)
    api_file = normalize_path(env.get("custom_api_file", env.File(extension_dir + "/extension_api.json").abspath), env)
    bindings = env.GodotCPPBindings(
        env.Dir("."),
        [
            api_file,
            os.path.join(extension_dir, "gdextension_interface.h"),
            "binding_generator.py",
        ],
    )
    # Forces bindings regeneration.
    if env["generate_bindings"]:
        env.AlwaysBuild(bindings)
        env.NoCache(bindings)

    # Sources to compile
    sources = []
    add_sources(sources, "src", "cpp")
    add_sources(sources, "src/classes", "cpp")
    add_sources(sources, "src/core", "cpp")
    add_sources(sources, "src/variant", "cpp")
    sources.extend([f for f in bindings if str(f).endswith(".cpp")])

    # Includes
    env.AppendUnique(CPPPATH=[env.Dir(d) for d in [extension_dir, "include", "gen/include"]])

    library = None
    library_name = "libgodot-cpp" + env["suffix"] + env["LIBSUFFIX"]

    if env["build_library"]:
        library = env.StaticLibrary(target=env.File("bin/%s" % library_name), source=sources)
        default_args = [library]

        # Add compiledb if the option is set
        if env.get("compiledb", False):
            default_args += ["compiledb"]

        env.Default(*default_args)

    env.AppendUnique(LIBS=[env.File("bin/%s" % library_name)])
    return library
