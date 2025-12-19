# How to set up project and compile

Required dependencies:
- Node.js
- npm

Recommended tools:
- vscode

Setup instructions:
1. copy the entire `asmscript-template` and `turing-api-asmscript` directories into your project directory.
2. rename the `asmscript-template` directory if desired.
3. cd into `asmscript-template`.
4. run `npm install --save-dev @assemblyscript/wasi-shim` to download the wasm compiler.
5. edit `asmscript-template/assembly/index.asc`

Compile project:
1. cd into `asmscript-template`.
2. run `npx asc assembly/index.asc --target release`.
3. Compiled wasm file is found at `asmscript-template/build/release.wasm`.
4. Copy it into your beatmap directory.
