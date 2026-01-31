C/C++ Turing API Template

This template provides the minimal C++ API surface used by generated projects.

Contents
- `turing_api_cpp.hpp` — header with `turing::Log`, `Vec2/Vec3/Vec4` typedefs (glm), and lifecycle hooks.
- `turing_api_cpp.cpp` — basic implementations and C wrappers for `on_load`, `on_update`, `on_exit`.

Version

- API semver: 0.1.0
- APIVersion: 0.1.0

Notes
- Logging currently prints to stdout/stderr; adapt to host logging when targeting wasm.
- Uses `glm` for vector types; ensure `glm` is added as a dependency in your build.
