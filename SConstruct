#!/usr/bin/env python

import os
import sys
import subprocess


def add_sources(sources, dir, extension):
    for f in os.listdir(dir):
        if f.endswith('.' + extension):
            sources.append(dir + '/' + f)

def sys_exec(args):
    proc = subprocess.Popen(args, stdout=subprocess.PIPE)
    (out, err) = proc.communicate()
    return out.rstrip("\r\n").lstrip()

march_android_switcher = {
    "arm": "armv7-a",
    "arm64": "armv8-a",
    "x86": "i686",
    "x86_64": "x86-64"
}


# Try to detect the host platform automatically.
# This is used if no `platform` argument is passed
if sys.platform.startswith('linux'):
    host_platform = 'linux'
elif sys.platform == 'darwin':
    host_platform = 'osx'
elif sys.platform == 'win32':
    host_platform = 'windows'
else:
    raise ValueError(
        'Could not detect platform automatically, please specify with '
        'platform=<platform>'
    )

opts = Variables([], ARGUMENTS)
opts.Add(EnumVariable(
    'platform',
    'Target platform',
    host_platform,
    allowed_values=('linux', 'osx', 'windows', 'android', 'ios'),
    ignorecase=2
))
opts.Add(EnumVariable(
    'bits',
    'Target platform bits',
    'default',
    ('default', '32', '64')
))
opts.Add(BoolVariable(
    'use_llvm',
    'Use the LLVM compiler - only effective when targeting Linux',
    False
))
opts.Add(BoolVariable(
    'use_mingw',
    'Use the MinGW compiler instead of MSVC - only effective on Windows',
    False
))
# Must be the same setting as used for cpp_bindings
opts.Add(EnumVariable(
    'target',
    'Compilation target',
    'debug',
    allowed_values=('debug', 'release'),
    ignorecase=2
))
opts.Add(PathVariable(
    'headers_dir',
    'Path to the directory containing Godot headers',
    'godot_headers',
    PathVariable.PathIsDir
))
opts.Add(PathVariable(
    'custom_api_file',
    'Path to a custom JSON API file',
    None,
    PathVariable.PathIsFile
))
opts.Add(BoolVariable(
    'generate_bindings',
    'Generate GDNative API bindings',
    False
))
opts.Add(EnumVariable(
    'ios_sdk',
    'iOS SDK version',
    '12.2',
    ('12.1', '12.2')
))
opts.Add((
    'ndk_path',
    'Path to Android NDK',
    os.getenv('ANDROID_NDK_ROOT', '../NDK')
))
opts.Add(EnumVariable(
    'android_api',
    'Target Android API',
    '21',
    ('21', '22', '23', '24', '25', '26', '27', '28')
))
opts.Add(EnumVariable(
    'arch',
    'Target Android ABI',
    'default',
    ('default', 'arm', 'x86')
))

env = Environment()
opts.Update(env)

Help(opts.GenerateHelpText(env))

is64 = sys.maxsize > 2**32
if (
    env['TARGET_ARCH'] == 'amd64' or
    env['TARGET_ARCH'] == 'emt64' or
    env['TARGET_ARCH'] == 'x86_64'
):
    is64 = True

if env['bits'] == 'default':
    env['bits'] = '64' if is64 else '32'

if env['arch'] == 'default':
    if env['platform'] == 'windows' or env['platform'] == 'linux' or env['platform'] == 'osx':
        env['arch'] = 'x86'
if env['platform'] == 'android' or env['platform'] == 'ios':
    env['arch'] = 'arm'

if env['platform'] == 'android':
    android_abi = env['arch']
    if env['arch'] == 'arm':
        if env['bits'] == '64':
            android_abi += "64"
    elif env['arch'] == 'x86':
        if env['bits'] == '64':
            android_abi += "_64"
    opts.Add(('ndk_toolchain', 'Path where the ndk toolchain will be created', "/tmp/android-" + env['android_api'] + "-" + android_abi + "-toolchain"))
    opts.Update(env)
    print("Android abi is " + android_abi)

# This makes sure to keep the session environment variables on Windows.
# This way, you can run SCons in a Visual Studio 2017 prompt and it will find
# all the required tools
if host_platform == 'windows':
    if env['bits'] == '64':
        env = Environment(TARGET_ARCH='amd64')
    elif env['bits'] == '32':
        env = Environment(TARGET_ARCH='x86')

    opts.Update(env)

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

elif env['platform'] == "ios":
    SDK_MIN_VERSION = "8.0"
    # we could do better to automatically find the right sdk version
    SDK_VERSION = env['ios_sdk']
    IOS_PLATFORM_SDK = sys_exec(["xcode-select", "-p"]) + "/Platforms"
    env["CXX"] = sys_exec(["xcrun", "-sdk", "iphoneos", "-find", "clang++"])
    env.Append(CCFLAGS = ['-g','-O3', '-std=c++11', '-arch', 'arm64', '-arch', 'armv7', '-arch', 'armv7s', '-isysroot', '%s/iPhoneOS.platform/Developer/SDKs/iPhoneOS%s.sdk' % (IOS_PLATFORM_SDK, SDK_VERSION) , '-miphoneos-version-min=%s' % SDK_MIN_VERSION])
    env.Append(LINKFLAGS = ['-arch', 'arm64', '-arch', 'armv7', '-arch', 'armv7s', '-isysroot', '%s/iPhoneOS.platform/Developer/SDKs/iPhoneOS%s.sdk' % (IOS_PLATFORM_SDK, SDK_VERSION) , '-miphoneos-version-min=%s' % SDK_MIN_VERSION, '-Wl,-undefined,dynamic_lookup'])

elif env['platform'] == "android":
    sys_exec(["python", env['ndk_path'] + "/build/tools/make_standalone_toolchain.py", "--arch", android_abi, "--api", env['android_api'], "--install-dir", env['ndk_toolchain']])
    suffix = "/bin/"
    if android_abi == "arm":
        suffix += "arm-linux-androideabi"
        ranlib = env['ndk_toolchain'] + "/arm-linux-androideabi/bin/ranlib"
    elif android_abi == "arm64":
        suffix += "aarch64-linux-android"
        ranlib = env['ndk_toolchain'] + "/aarch64-linux-android/bin/ranlib"
    elif android_abi == "x86":
        suffix += "i686-linux-android"
        ranlib = env['ndk_toolchain'] + "/i686-linux-android/bin/ranlib"
    elif android_abi == "x86_64":
        suffix += "x86_64-linux-android"
        ranlib = env['ndk_toolchain'] + "/x86_64-linux-android/bin/ranlib"
    env["AR"] = env['ndk_toolchain'] + suffix + "-ar"
    env["AS"] = env['ndk_toolchain'] + suffix + "-as"
    env["CC"] = env['ndk_toolchain'] + suffix + "-clang"
    env["CXX"] = env['ndk_toolchain'] + suffix + "-clang++"
    env["LD"] = env['ndk_toolchain'] + suffix + "-ld"
    env["STRIP"] = env['ndk_toolchain'] + suffix + "-strip"
    env["RANLIB"] = ranlib
    march = march_android_switcher.get(android_abi, "Invalid android architecture")
    env.Append(CCFLAGS = ['-fPIE', '-fPIC', '-mfpu=neon', '-march=' + march])
    env.Append(LDFLAGS = ['-pie', '-Wl'])

elif env['platform'] == 'osx':
    # Use Clang on macOS by default
    env['CXX'] = 'clang++'

    if env['bits'] == '32':
        raise ValueError(
            'Only 64-bit builds are supported for the macOS target.'
        )

    env.Append(CCFLAGS=['-g', '-std=c++14', '-arch', 'x86_64'])
    env.Append(LINKFLAGS=[
        '-arch',
        'x86_64',
        '-framework',
        'Cocoa',
        '-Wl,-undefined,dynamic_lookup',
    ])

    if env['target'] == 'debug':
        env.Append(CCFLAGS=['-Og'])
    elif env['target'] == 'release':
        env.Append(CCFLAGS=['-O3'])

elif env['platform'] == 'windows':
    if host_platform == 'windows' and not env['use_mingw']:
        # MSVC
        env.Append(LINKFLAGS=['/WX'])
        if env['target'] == 'debug':
            env.Append(CCFLAGS=['/Z7', '/Od', '/EHsc', '/D_DEBUG', '/MDd'])
        elif env['target'] == 'release':
            env.Append(CCFLAGS=['/O2', '/EHsc', '/DNDEBUG', '/MD'])

    elif host_platform == 'linux':
        # Cross-compilation using MinGW
        if env['bits'] == '64':
            env['CXX'] = 'x86_64-w64-mingw32-g++'
        elif env['bits'] == '32':
            env['CXX'] = 'i686-w64-mingw32-g++'

    # Native or cross-compilation using MinGW
    if host_platform == 'linux' or env['use_mingw']:
        env.Append(CCFLAGS=['-g', '-O3', '-std=c++14', '-Wwrite-strings'])
        env.Append(LINKFLAGS=[
            '--static',
            '-Wl,--no-undefined',
            '-static-libgcc',
            '-static-libstdc++',
        ])

env.Append(CPPPATH=[
    '.',
    env['headers_dir'],
    'include',
    'include/gen',
    'include/core',
])

# Generate bindings?
json_api_file = ''

if 'custom_api_file' in env:
    json_api_file = env['custom_api_file']
else:
    json_api_file = os.path.join(os.getcwd(), 'godot_headers', 'api.json')

if env['generate_bindings']:
    # Actually create the bindings here
    import binding_generator

    binding_generator.generate_bindings(json_api_file)

# Sources to compile
sources = []
add_sources(sources, 'src/core', 'cpp')
add_sources(sources, 'src/gen', 'cpp')

if env['platform'] == 'ios':
    target = 'bin/' + 'libgodot-cpp.{}.{}.a'.format(
        env['platform'],
        env['target'],
    )
else:
    target = 'bin/' + 'libgodot-cpp.{}.{}.{}'.format(
        env['platform'],
        env['target'],
        (env['arch'] + '.' + env['bits']) if env['platform'] != 'android' else march_android_switcher.get(android_abi, "Invalid android architecture") + '.a',
    )

library = env.StaticLibrary(
    target=target, source=sources
)
Default(library)
