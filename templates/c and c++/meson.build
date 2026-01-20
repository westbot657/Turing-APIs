project('turing_script', 'c', 'cpp', default_options: ['c_std=c11', 'cpp_std=c++20'])


# on release builds, disable debug symbols and enable optimizations
buildtype = get_option('buildtype')
if buildtype == 'release'    
    add_project_arguments('-O3', language: 'c')
    add_project_arguments('-O3', language: 'cpp')
    # add_project_arguments('-g0', language: 'c')
    # add_project_arguments('-g0', language: 'cpp')

# enable LTO on release builds
    add_project_arguments('-flto', language: 'c')
    add_project_arguments('-flto', language: 'cpp')

# hide all symbols by default (only exported functions will be visible)
    add_project_arguments('-fvisibility=hidden', language: 'c')
    add_project_arguments('-fvisibility=hidden', language: 'cpp')
    
# enable function/data sections for dead code elimination
    add_project_arguments('-ffunction-sections', language: 'c')
    add_project_arguments('-ffunction-sections', language: 'cpp')
    add_project_arguments('-fdata-sections', language: 'c')
    add_project_arguments('-fdata-sections', language: 'cpp')

# enable stripping on release builds
    add_project_link_arguments('-s', language: 'c')
    add_project_link_arguments('-s', language: 'cpp')
    
# strip unused functions and keep only exported ones (Emscripten)
    # add_project_link_arguments('-sEXPORTED_RUNTIME_METHODS=[]', language: 'c')
    # add_project_link_arguments('-sEXPORTED_RUNTIME_METHODS=[]', language: 'cpp')
    add_project_link_arguments('-Wl,--gc-sections', language: 'c')
    add_project_link_arguments('-Wl,--gc-sections', language: 'cpp')
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