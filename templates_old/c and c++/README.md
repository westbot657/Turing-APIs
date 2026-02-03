# How to set up project and compile

Required dependencies:
- C++ compiler:
  - emscripten (use choco to install on Windows)
- meson
- ninja

Recommended tools:
- One of:
  - CLion (JetBrains IDE)
  - vscode (clangd extension. NOT Microsoft C++ Tools)
  - Visual Studio probably works too idk

Setup instructions:
Run `./dev.sh` to compile project and setup Intellisense. Rerun when modifying `meson.build` e.g more dependencies or source files. Restart clangd too (VS Code).

Use `./release.sh` for optimized builds with stripping enabled.