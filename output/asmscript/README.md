# How to set up project and compile

required dependencies:
- Node.js
- npm

Setup instructions:
1. copy the entire `asmscript-template` and `turing-api-asmscript` folders into your project directory
2. rename the asmscript-template folder if desired.
3. cd into `asmscript-template`
4. run `npm install --save-dev @assemblyscript/wasi-shim` to download the wasm compiler.

Compile project:
1. cd into `asmscript-template`
2. run `npx asc assembly/index.ts --target release`
3. Compiled wasm file is found at `asmscript-template/build/release.wasm`

