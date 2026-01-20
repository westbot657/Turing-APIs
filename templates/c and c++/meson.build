project('turing_script', 'c', 'cpp', default_options: ['c_std=c11', 'cpp_std=c++20'])


# on release builds, disable debug symbols and enable optimizations
buildtype = get_option('buildtype')
if buildtype == 'release'    
    add_project_arguments('-O3', language: 'c')
    add_project_arguments('-O3', language: 'cpp')
    add_project_arguments('-g0', language: 'c')
    add_project_arguments('-g0', language: 'cpp')

# enable LTO on release builds
    add_project_arguments('-flto', language: 'c')
    add_project_arguments('-flto', language: 'cpp')

# enable stripping on release builds
    add_project_link_arguments('-s', language: 'c')
    add_project_link_arguments('-s', language: 'cpp')
endif

# target wasm32-unknown-unknown requires special handling

# additional per-subdir logic
subdir('api')



api_inc = include_directories('api')
executable(
    'turing_script',
    'src/main.cpp',
    include_directories: api_inc,
    link_with: libapi,
)