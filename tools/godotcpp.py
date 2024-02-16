import os, sys, platform

from SCons.Variables import EnumVariable, PathVariable, BoolVariable
from SCons.Tool import Tool
from SCons.Builder import Builder
from SCons.Errors import UserError

from binding_generator import scons_generate_bindings, scons_emit_files


def add_sources(sources, dir, extension):
    for f in os.listdir(dir):
        if f.endswith("." + extension):
            sources.append(dir + "/" + f)


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


platforms = ("linux", "macos", "windows", "android", "ios", "web")

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
        EnumVariable(
            key="platform",
            help="Target platform",
            default=env.get("platform", default_platform),
            allowed_values=platforms,
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

    # Add platform options
    for pl in platforms:
        tool = Tool(pl, toolpath=["tools"])
        if hasattr(tool, "options"):
            tool.options(opts)

    # Targets flags tool (optimizations, debug symbols)
    target_tool = Tool("targets", toolpath=["tools"])
    target_tool.options(opts)


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

    if env.get("use_hot_reload") is None:
        env["use_hot_reload"] = env["target"] != "template_release"
    if env["use_hot_reload"]:
        env.Append(CPPDEFINES=["HOT_RELOAD_ENABLED"])

    tool = Tool(env["platform"], toolpath=["tools"])

    if tool is None or not tool.exists(env):
        raise ValueError("Required toolchain not found for platform " + env["platform"])

    tool.generate(env)
    target_tool = Tool("targets", toolpath=["tools"])
    target_tool.generate(env)

    # Disable exception handling. Godot doesn't use exceptions anywhere, and this
    # saves around 20% of binary size and very significant build time.
    if env["disable_exceptions"]:
        if env.get("is_msvc", False):
            env.Append(CPPDEFINES=[("_HAS_EXCEPTIONS", 0)])
        else:
            env.Append(CXXFLAGS=["-fno-exceptions"])
    elif env.get("is_msvc", False):
        env.Append(CXXFLAGS=["/EHsc"])

    if not env.get("is_msvc", False):
        if env["symbols_visibility"] == "visible":
            env.Append(CCFLAGS=["-fvisibility=default"])
            env.Append(LINKFLAGS=["-fvisibility=default"])
        elif env["symbols_visibility"] == "hidden":
            env.Append(CCFLAGS=["-fvisibility=hidden"])
            env.Append(LINKFLAGS=["-fvisibility=hidden"])

    # Require C++17
    if env.get("is_msvc", False):
        env.Append(CXXFLAGS=["/std:c++17"])
    else:
        env.Append(CXXFLAGS=["-std=c++17"])

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

    # Builders
    env.Append(BUILDERS={"GodotCPPBindings": Builder(action=scons_generate_bindings, emitter=scons_emit_files)})
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
