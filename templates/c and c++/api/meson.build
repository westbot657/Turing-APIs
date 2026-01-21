# build a static library from sources in the `api` directory

# glm_dep defined by parent meson.build

api_sources = files('turing_api_cpp.cpp')
libapi = static_library('api', api_sources, dependencies: [glm_dep])
