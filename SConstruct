#!python

import os, subprocess, platform


def add_source(sources, name):
  sources.append(name)

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
godot_headers = ARGUMENTS.get('headers', '../godot_headers')
godot_bin_path = ARGUMENTS.get('godotbinpath', os.getenv('GODOT_BIN_PATH', '../godot_fork/bin/godot.x11.tools.64.llvm'))
result_path = 'bin/'
result_name = ARGUMENTS.get('n', ARGUMENTS.get('name', os.path.relpath('.', '..')))


# This makes sure to keep the session environment variables on windows, 
# that way you can run scons in a vs 2017 prompt and it will find all the required tools
env = Environment()
if target_platform == 'windows':
    env = Environment(ENV = os.environ)

if ARGUMENTS.get('use_llvm', 'no') == 'yes':
    env['CXX'] = 'clang++'


if target_platform == 'linux':
    result_name += '.linux.' + target_arch

    env['CXX']='gcc-5'
    env.Append(CCFLAGS = [ '-fPIC', '-g', '-O3', '-std=c++14', '-Wwrite-strings' ])
    env.Append(LINKFLAGS = [ '-Wl,-R,\'$$ORIGIN\'' ])

    if target_arch == '32':
        env.Append(CCFLAGS = [ '-m32' ])
        env.Append(LINKFLAGS = [ '-m32' ])
    elif target_arch == '64':
        env.Append(CCFLAGS = [ '-m64' ])
        env.Append(LINKFLAGS = [ '-m64' ])

elif target_platform == 'windows':
    result_name += '.windows.' + target_arch

    if host_platform == 'Windows':
        result_name += '.dll'

        env.Append(LINKFLAGS = [ '/WX' ])
        if target == 'debug':
            env.Append(CCFLAGS = ['-EHsc', '-D_DEBUG', '/MDd' ])
        else:
            env.Append(CCFLAGS = ['-O2', '-EHsc', '-DNDEBUG', '/MD' ])
    else:
        if target_arch == '32':
            env['CXX']='i686-w64-mingw32-g++'
        elif target_arch == '64':
            env['CXX']='x86_64-w64-mingw32-g++'

        env.Append(CCFLAGS = [ '-g', '-O3', '-std=c++14', '-Wwrite-strings' ])
        env.Append(LINKFLAGS = [ '--static', '-Wl,--no-undefined', '-static-libgcc', '-static-libstdc++' ])

elif platform == 'osx':
    env.Append(CCFLAGS = [ '-g','-O3', '-std=c++14', '-arch', 'x86_64' ])
    env.Append(LINKFLAGS = [ '-arch', 'x86_64', '-framework', 'Cocoa', '-Wl,-undefined,dynamic_lookup' ])


env.Append(CPPPATH=['.', godot_headers, 'include', 'include/core'])


if ARGUMENTS.get('generate_bindings', 'no') == 'yes':
    # TODO Generating the API should be done only if the Godot build is more recent than the JSON file
    json_api_file = os.path.join(os.getcwd(), 'godot_api.json')

    subprocess.call([os.path.expanduser(godot_bin_path), '--gdnative-generate-json-api', json_api_file])

    # actually create the bindings here
    
    import binding_generator

    binding_generator.generate_bindings(json_api_file)


sources = []
add_sources(sources, 'src/core', 'cpp')
add_sources(sources, 'src', 'cpp')


library = env.StaticLibrary(target=result_path + '/' + result_name, source=sources)
Default(library)
