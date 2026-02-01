# How to set up project and compile

Required dependencies:
- One of:
  - zig (recommended, easiest when you're on windows)
  - gcc
  - clang

Recommended tools:
- One of:
  - CLion (JetBrains IDE)
  - vscode
  - Visual Studio probably works too idk

Setup instructions:
1. copy the template and turing-api directories for either C or C++
2. also copy `shared/include/wasm.h`
3. good luck, idk.

Compile project:
1. you can figure it out, target wasm32-wasi
2. Copy the output .wasm file into your beatmap directory