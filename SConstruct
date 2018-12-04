#!python

import os, subprocess, platform, sys
from compat import iteritems, isbasestring

def use_windows_spawn_fix(self, platform=None):

    if (os.name != "nt"):
        return  # not needed, only for windows

    # On Windows, due to the limited command line length, when creating a static library
    # from a very high number of objects SCons will invoke "ar" once per object file;
    # that makes object files with same names to be overwritten so the last wins and
    # the library looses symbols defined by overwritten objects.
    # By enabling quick append instead of the default mode (replacing), libraries will
    # got built correctly regardless the invocation strategy.
    # Furthermore, since SCons will rebuild the library from scratch when an object file
    # changes, no multiple versions of the same object file will be present.
    self.Replace(ARFLAGS='q')

    def mySubProcess(cmdline, env):

        startupinfo = subprocess.STARTUPINFO()
        startupinfo.dwFlags |= subprocess.STARTF_USESHOWWINDOW
        proc = subprocess.Popen(cmdline, stdin=subprocess.PIPE, stdout=subprocess.PIPE,
                                stderr=subprocess.PIPE, startupinfo=startupinfo, shell=False, env=env)
        data, err = proc.communicate()
        rv = proc.wait()
        if rv:
            print("=====")
            print(err)
            print("=====")
        return rv

    def mySpawn(sh, escape, cmd, args, env):

        newargs = ' '.join(args[1:])
        cmdline = cmd + " " + newargs

        rv = 0
        env = {str(key): str(value) for key, value in iteritems(env)}
        if len(cmdline) > 32000 and cmd.endswith("ar"):
            cmdline = cmd + " " + args[1] + " " + args[2] + " "
            for i in range(3, len(args)):
                rv = mySubProcess(cmdline + args[i], env)
                if rv:
                    break
        else:
            rv = mySubProcess(cmdline, env)

        return rv

    self['SPAWN'] = mySpawn

def add_sources(sources, dir, extension):
  for f in os.listdir(dir):
      if f.endswith('.' + extension):
          sources.append(dir + '/' + f)

env = Environment()

opts = Variables([], ARGUMENTS)

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

opts.Add(EnumVariable('platform', 'Target platform', host_platform,
                    allowed_values=('linux', 'osx', 'windows'),
                    ignorecase=2))
opts.Add(PathVariable('osxcross_dir', 'Platform', '.'))
opts.Add(EnumVariable('bits', 'Target platform bits', 'default', ('default', '32', '64')))
opts.Add(BoolVariable('use_llvm', 'Use the LLVM compiler - only effective when targeting Linux', False))
opts.Add(BoolVariable('use_mingw', 'Use the MinGW compiler - only effective on Windows', False))
# Must be the same setting as used for cpp_bindings
opts.Add(EnumVariable('target', 'Compilation target', 'debug', ('debug', 'release')))
opts.Add(PathVariable('headers_dir', 'Path to the directory containing Godot headers', 'godot_headers'))
opts.Add(EnumVariable('target', 'Compilation target', 'debug',
                    allowed_values=('debug', 'release'),
                    ignorecase=2))
opts.Add(PathVariable('headers_dir', 'Path to the directory containing Godot headers', 'godot_headers', PathVariable.PathIsDir))
opts.Add(BoolVariable('use_custom_api_file', 'Use a custom JSON API file', False))
opts.Add(PathVariable('custom_api_file', 'Path to the custom JSON API file', None, PathVariable.PathIsFile))
opts.Add(BoolVariable('generate_bindings', 'Generate GDNative API bindings', False))

unknown = opts.UnknownVariables()
if unknown:
    print("Unknown variables:" + unknown.keys())
    Exit(1)
opts.Add(BoolVariable('use_osxcross', 'OSXCross to compile for macOS from Linux', False))
opts.Add(PathVariable('headers_dir', 'Path to the directory containing Godot headers', 'godot_headers'))

opts.Update(env)
Help(opts.GenerateHelpText(env))

is64 = False
if (env['TARGET_ARCH'] == 'amd64' or env['TARGET_ARCH'] == 'emt64' or env['TARGET_ARCH'] == 'x86_64'):
    is64 = True
if env['bits'] == 'default':
    env['bits'] = '64' if is64 else '32'

if env['platform'] == 'linux' and not env['use_osxcross']:
    if env['use_llvm']:
        env['CXX'] = 'clang++'

    if not env['use_mingw']:
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

    if env['use_mingw']:
        if env['bits'] == '64':
            env['CXX'] = 'x86_64-w64-mingw32-g++'
        elif env['bits'] == '32':
            env['CXX'] = 'i686-w64-mingw32-g++'
        mingw_prefix = '' 
        if env['bits'] == '64':
            mingw_prefix = 'x86_64-w64-mingw32-'
        elif env['bits'] == '32':
            mingw_prefix = 'i686-w64-mingw32-'
        env["CC"] = mingw_prefix + "gcc"
        env['AS'] = mingw_prefix + "as"
        env['CXX'] = mingw_prefix + "g++"
        env['AR'] = mingw_prefix + "gcc-ar"
        env['RANLIB'] = mingw_prefix + "gcc-ranlib"
        env['LINK'] = mingw_prefix + "g++"
        
        env.Append(CCFLAGS=['-g', '-O3', '-std=c++14', '-Wwrite-strings'])
        env.Append(LINKFLAGS=['--static', '-Wl,--no-undefined', '-Wl,--subsystem,windows'])
        env['platform'] = 'windows'

elif env['platform'] == 'osx' or env['use_osxcross']:
    if env['bits'] == '32':
        raise ValueError('Only 64-bit builds are supported for the macOS target.')

    env['platform'] = 'osx'

    if env['osxcross_dir']:
        env['CXX'] = env['osxcross_dir'] + '/target/bin/x86_64-apple-darwin15-clang++-libc++'
        env['LINK'] = env['osxcross_dir'] + '/target/bin/x86_64-apple-darwin15-clang++-libc++'
        env['AR'] = env['osxcross_dir'] + '/target/bin/x86_64-apple-darwin15-ar'
        env['AS'] = env['osxcross_dir'] + '/target/bin/x86_64-apple-darwin15-as'
        env['RANLIB'] = env['osxcross_dir'] + '/target/bin/x86_64-apple-darwin15-ranlib'

    env.Append(CCFLAGS=['-g', '-std=c++14', '-arch', 'x86_64'])
    env.Append(LINKFLAGS=['-arch', 'x86_64', '-framework', 'Cocoa', '-Wl,-undefined,dynamic_lookup'])

    if env['target'] == 'debug':
        env.Append(CCFLAGS=['-Og'])
    elif env['target'] == 'release':
        env.Append(CCFLAGS=['-O3'])

elif env['platform'] == 'windows':

    # This makes sure to keep the session environment variables on Windows
    # This way, you can run SCons in a Visual Studio 2017 prompt and it will find all the required tools
    if env['platform'] == 'windows':
        if env['bits'] == '64':
             env = Environment(TARGET_ARCH='amd64')
        elif env['bits'] == '32':
             env = Environment(TARGET_ARCH='x86')
        else:
             print("Warning: bits argument not specified, target arch is=" + env['TARGET_ARCH'])
        opts.Update(env)

    if host_platform == 'windows' and env['use_mingw'] == False:
        # MSVC
        env.Append(LINKFLAGS=['/WX'])
        if env['target'] == 'debug':
            env.Append(CCFLAGS=['/EHsc', '/D_DEBUG', '/MDd'])
        elif env['target'] == 'release':
            env.Append(CCFLAGS=['/O2', '/EHsc', '/DNDEBUG', '/MD'])
    elif host_platform == 'windows':
        env = env.Clone(tools = ['mingw'])
        env['ENV'] = {'PATH' : os.environ['PATH'], 'TMP' : os.environ['TMP']}
        # Workaround for MinGW. See:
        # http://www.scons.org/wiki/LongCmdLinesOnWin32
        use_windows_spawn_fix(env)
        
        if env['bits'] == '64':
                mingw_prefix = 'x86_64-w64-mingw32-g++'
        elif env['bits'] == '32':
                mingw_prefix = 'i686-w64-mingw32-g++'
        env["CC"] = mingw_prefix + "gcc"
        env['AS'] = mingw_prefix + "as"
        env['CXX'] = mingw_prefix + "g++"
        env['AR'] = mingw_prefix + "gcc-ar"
        env['RANLIB'] = mingw_prefix + "gcc-ranlib"
        env['LINK'] = mingw_prefix + "g++"

        env['CCFLAGS'] = ['-g', '-O3', '-std=c++14', '-Wwrite-strings']
        env['LINKFLAGS']= ['--static', '-Wl,--no-undefined', '-static-libgcc', '-static-libstdc++']

env.Append(CPPPATH=['.', env['headers_dir'], 'include', 'include/gen', 'include/core'])

# Generate bindings?
json_api_file = ''

if env['use_custom_api_file']:
    json_api_file = env['custom_api_file']
else:
    json_api_file = os.path.join(os.getcwd(), 'godot_headers', 'api.json')

if env['generate_bindings']:
    # Actually create the bindings here

    import binding_generator

    binding_generator.generate_bindings(json_api_file)

# source to compile
sources = []
add_sources(sources, 'src/core', 'cpp')
add_sources(sources, 'src/gen', 'cpp')

library = env.StaticLibrary(
    target='bin/' + 'libgodot-cpp.{}.{}.{}'.format(env['platform'], env['target'], env['bits']), source=sources
)
Default(library)

