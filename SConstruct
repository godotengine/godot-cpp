#!python

import os, subprocess, platform


def add_sources(sources, dir, extension):
  for f in os.listdir(dir):
      if f.endswith('.' + extension):
          sources.append(dir + '/' + f)


env = Environment()
host_platform = platform.system()
target_platform = ARGUMENTS.get('p', ARGUMENTS.get('platform', 'linux'))
target_arch = ARGUMENTS.get('a', ARGUMENTS.get('arch', '64'))
# default to debug build, must be same setting as used for cpp_bindings
target = ARGUMENTS.get('target', 'debug')
# Local dependency paths, adapt them to your setup
godot_headers = ARGUMENTS.get('headers', 'godot_headers')
result_path = 'bin'
result_name = ARGUMENTS.get('n', ARGUMENTS.get('name', os.path.relpath('.', '..')))


if target_platform == 'linux':
    result_name += '.linux.' + target_arch

    if ARGUMENTS.get('use_llvm', 'no') == 'yes':
        env['CXX'] = 'clang++'

    env.Append(CCFLAGS = [ '-fPIC', '-g', '-std=c++14', '-Wwrite-strings' ])
    env.Append(LINKFLAGS = [ '-Wl,-R,\'$$ORIGIN\'' ])

    if target == 'debug':
        env.Append(CCFLAGS = ['-Og'])
    else:
        env.Append(CCFLAGS = ['-O3'])

    if target_arch == '32':
        env.Append(CCFLAGS = [ '-m32' ])
        env.Append(LINKFLAGS = [ '-m32' ])
    elif target_arch == '64':
        env.Append(CCFLAGS = [ '-m64' ])
        env.Append(LINKFLAGS = [ '-m64' ])

elif target_platform == 'windows':
    # This makes sure to keep the session environment variables on windows,
    # that way you can run scons in a vs 2017 prompt and it will find all the required tools
    if (target_arch == '64'):
        env = Environment(ENV = os.environ, TARGET_ARCH='amd64')
    else:
        env = Environment(ENV = os.environ, TARGET_ARCH='x86')

    result_name += '.windows.' + target_arch

    if host_platform == 'Windows':
        result_name += '.lib'

        env.Append(LINKFLAGS = [ '/WX' ])
        if target == 'debug':
            env.Append(CCFLAGS = ['/EHsc', '/D_DEBUG', '/MDd' ])
        else:
            env.Append(CCFLAGS = ['/O2', '/EHsc', '/DNDEBUG', '/MD' ])
    else:
        if target_arch == '32':
            env['CXX']='i686-w64-mingw32-g++'
        elif target_arch == '64':
            env['CXX']='x86_64-w64-mingw32-g++'

        env.Append(CCFLAGS = [ '-g', '-O3', '-std=c++14', '-Wwrite-strings' ])
        env.Append(LINKFLAGS = [ '--static', '-Wl,--no-undefined', '-static-libgcc', '-static-libstdc++' ])

elif target_platform == 'osx':
    if ARGUMENTS.get('use_llvm', 'no') == 'yes':
        env['CXX'] = 'clang++'

    # Only 64-bits is supported for OS X
    target_arch = '64'
    result_name += '.osx.' + target_arch

    env.Append(CCFLAGS = [ '-g','-O3', '-std=c++14', '-arch', 'x86_64' ])
    env.Append(LINKFLAGS = [ '-arch', 'x86_64', '-framework', 'Cocoa', '-Wl,-undefined,dynamic_lookup' ])

elif target_platform == 'uwp':
    # blatently stolen from godot uwp platform, I have no idea what half of this does...
    vc_base_path = os.environ['VCTOOLSINSTALLDIR'] if "VCTOOLSINSTALLDIR" in os.environ else os.environ['VCINSTALLDIR']

    if target == "debug":
        env.Append(CCFLAGS=['/Zi', '/DDEBUG_ENABLED', '/DDEBUG_MEMORY_ENABLED'])
        env.Append(CPPFLAGS=['/MDd'])
        env.Append(LINKFLAGS=['/DEBUG'])
    else:
        env.Append(CPPFLAGS=['/O2', '/GL'])
        env.Append(CPPFLAGS=['/MD'])
        env.Append(LINKFLAGS=['/LTCG'])

    if (target_arch == '32'):
        env.Append(LINKFLAGS=['/MACHINE:X86'])
    else:
        env.Append(LINKFLAGS=['/MACHINE:X64'])

    env.Append(CPPPATH=['#platform/uwp', '#drivers/windows'])
    env.Append(CCFLAGS=['/DUWP_ENABLED', '/DWINDOWS_ENABLED', '/DTYPED_METHOD_BIND'])
    env.Append(CCFLAGS=['/DGLES_ENABLED', '/DGL_GLEXT_PROTOTYPES', '/DEGL_EGLEXT_PROTOTYPES', '/DANGLE_ENABLED'])
    winver = "0x0602" # Windows 8 is the minimum target for UWP build
    env.Append(CCFLAGS=['/DWINVER=%s' % winver, '/D_WIN32_WINNT=%s' % winver])

    env.Append(CPPFLAGS=['/AI', vc_base_path + 'lib/store/references'])
    env.Append(CPPFLAGS=['/AI', vc_base_path + 'lib/x86/store/references'])

    env.Append(CCFLAGS='/FS /MP /GS /wd"4453" /wd"28204" /wd"4291" /Zc:wchar_t /Gm- /fp:precise /D "_UNICODE" /D "UNICODE" /D "WINAPI_FAMILY=WINAPI_FAMILY_APP" /errorReport:prompt /WX- /Zc:forScope /Gd /EHsc /nologo'.split())
    env.Append(CXXFLAGS='/ZW /FS'.split())
    env.Append(CCFLAGS=['/AI', vc_base_path + '\\vcpackages', '/AI', os.environ['WINDOWSSDKDIR'] + '\\References\\CommonConfiguration\\Neutral'])

    env.Append(LINKFLAGS=['/MANIFEST:NO', '/NXCOMPAT', '/DYNAMICBASE', '/WINMD', '/APPCONTAINER', '/ERRORREPORT:PROMPT', '/NOLOGO', '/TLBID:1', '/NODEFAULTLIB:"kernel32.lib"', '/NODEFAULTLIB:"ole32.lib"'])

    LIBS = [
        'WindowsApp',
        'mincore',
    ]
    env.Append(LINKFLAGS=[p + ".lib" for p in LIBS])

    result_name += '.uwp.' + target_arch


env.Append(CPPPATH=['.', godot_headers, 'include', 'include/core'])

# Generate bindings?
json_api_file = ''

if ARGUMENTS.get('use_custom_api_file', 'no') == 'yes':
    json_api_file = ARGUMENTS.get('custom_api_file', '')
else:
    json_api_file = os.path.join(os.getcwd(), 'godot_api.json')

if ARGUMENTS.get('generate_bindings', 'no') == 'yes':
    # actually create the bindings here
    
    import binding_generator

    binding_generator.generate_bindings(json_api_file)

sources = []
add_sources(sources, 'src/core', 'cpp')
add_sources(sources, 'src', 'cpp')


library = env.StaticLibrary(target=result_path + '/' + result_name, source=sources)
Default(library)
