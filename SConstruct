#!python

import os, subprocess, platform, sys


def add_sources(sources, dir, extension):
  for f in os.listdir(dir):
      if f.endswith('.' + extension):
          sources.append(dir + '/' + f)

# Try to detect the host platform automatically
# This is used if no `platform` argument is passed
if sys.platform.startswith('linux'):
    host_platform = 'linux'
elif sys.platform == 'darwin':
    host_platform = 'osx'
elif sys.platform == 'win32':
    host_platform = 'windows'
else:
    raise ValueError('Could not detect platform automatically, please specify with platform=<platform>')

opts = Variables([], ARGUMENTS)

opts.Add(EnumVariable('platform', 'Target platform', host_platform, ('linux', 'osx', 'windows')))
opts.Add(EnumVariable('bits', 'Target platform bits', 'default', ('default', '32', '64')))
opts.Add(BoolVariable('use_llvm', 'Use the LLVM compiler - only effective when targeting Linux', False))
opts.Add(BoolVariable('use_mingw', 'Use the MinGW compiler - only effective on Windows', False))
# Must be the same setting as used for cpp_bindings
opts.Add(EnumVariable('target', 'Compilation target', 'debug', ('debug', 'release')))
opts.Add(PathVariable('headers_dir', 'Path to the directory containing Godot headers', 'godot_headers'))

env = Environment()
opts.Update(env)
Help(opts.GenerateHelpText(env))

is64 = sys.maxsize > 2**32
if env['bits'] == 'default':
    env['bits'] = '64' if is64 else '32'

if env['platform'] == 'linux':
    if env['use_llvm']:
        env['CXX'] = 'clang++'

    env.Append(CCFLAGS=['-fPIC', '-g', '-std=c++14', '-Wwrite-strings'])
    env.Append(LINKFLAGS=["-Wl,-R,'$$ORIGIN'"])

    if env['target'] == 'debug':
        env.Append(CCFLAGS=['-Og'])
    elif env['target'] == 'release':
        env.Append(CCFLAGS=['-O3'])

    if env['bits'] == '64':
        env.Append(CCFLAGS=['-m64'])
        env.Append(LINKFLAGS=['-m64'])
    elif env['bits'] == '32':
        env.Append(CCFLAGS=['-m32'])
        env.Append(LINKFLAGS=['-m32'])

elif env['platform'] == 'osx':
    if env['bits'] == '32':
        raise ValueError('Only 64-bit builds are supported for the macOS target.')

    env.Append(CCFLAGS=['-g', '-std=c++14', '-arch', 'x86_64'])
    env.Append(LINKFLAGS=['-arch', 'x86_64', '-framework', 'Cocoa', '-Wl,-undefined,dynamic_lookup'])

    if env['target'] == 'debug':
        env.Append(CCFLAGS=['-Og'])
    elif env['target'] == 'release':
        env.Append(CCFLAGS=['-O3'])

elif env['platform'] == 'windows':
    # This makes sure to keep the session environment variables on Windows
    # This way, you can run SCons in a Visual Studio 2017 prompt and it will find all the required tools
    if env['bits'] == '64':
        env.Override(os.environ)
        env.Append(TARGET_ARCH='amd64')
    elif env['bits'] == '32':
        env.Override(os.environ)
        env.Append(TARGET_ARCH='x86')

    if host_platform == 'windows' and not env['use_mingw']:
        # MSVC
        env.Append(LINKFLAGS=['/WX'])
        if env['target'] == 'debug':
            env.Append(CCFLAGS=['/EHsc', '/D_DEBUG', '/MDd'])
        elif env['target'] == 'release':
            env.Append(CCFLAGS=['/O2', '/EHsc', '/DNDEBUG', '/MD'])
    else:
        # MinGW
        if env['bits'] == '64':
            env['CXX'] = 'x86_64-w64-mingw32-g++'
        elif env['bits'] == '32':
            env['CXX'] = 'i686-w64-mingw32-g++'

        env.Append(CCFLAGS=['-g', '-O3', '-std=c++14', '-Wwrite-strings'])
        env.Append(LINKFLAGS=['--static', '-Wl,--no-undefined', '-static-libgcc', '-static-libstdc++'])


env.Append(CPPPATH=['.', env['headers_dir'], 'include', 'include/core'])

# Generate bindings?
json_api_file = ''

if ARGUMENTS.get('use_custom_api_file', 'no') == 'yes':
    json_api_file = ARGUMENTS.get('custom_api_file', '')
else:
    json_api_file = os.path.join(os.getcwd(), 'godot_api.json')

if ARGUMENTS.get('generate_bindings', 'no') == 'yes':
    # Actually create the bindings here

    import binding_generator

    binding_generator.generate_bindings(json_api_file)

sources = []
add_sources(sources, 'src/core', 'cpp')
add_sources(sources, 'src', 'cpp')

library = env.StaticLibrary(
    target='bin/' + 'libgodot-cpp.{}.{}.{}'.format(env['platform'], env['target'], env['bits']), source=sources
)
Default(library)
