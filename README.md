# Turing API

The API is a work in progress, and I will try to get as many languages to be supported as I can.  

Currently supported languages:  
- C
- C++
- Rust
- Zig
- Lua (via Nelua)                 [website](https://nelua.io/)
- TypeScript (via AssmeblyScript) [website](https://www.assemblyscript.org/)
- Go (via TinyGo)                 [website](https://tinygo.org/)

Currently supportable, but not a priority (reach out if you want one of these languages to be given proper support):
- Grain [website](https://grain-lang.org/) targets wasm32-unknown-unknown directly
- Nim   [website](https://nim-lang.org/)   targets standalone C
- V     [website](https://vlang.io/)       targets wasm32-unknown-unknown directly. Experimental, may be buggy.
- Odin  [website](https://odin-lang.org/)  targets wasm32-freestanding
- D     [website](https://dlang.org/)      targets wasm32-unknown-unknown directly

Languages that I've checked and are not currently supportable, but may be possible in the future:
- Kotlin
- Python (including Cython)
- C#
- Java
- Ruby
- Perl
- PHP


If you don't see your preferred language here, chances are it doesn't meet the requirements to work with turing.  

## Prerequisits to supporting a language
If you would like to try and add support for a language yourself, it must meet these requirement:  
1. The language must be able to compile without the standard library, as system calls will not work in the wasm environment.  
2. Must be able to either:
    1. Compile to `wasm32-unknown-unknown` (sometimes called `wasm32-standalone` or `wasm32-freestanding`)
    2. Transpile to C (again, cannot use the standard library), C can then be compiled to `wasm32-unknown-unknown`

The distinction of `wasm32-unknown-unknown`/`wasm32-standalone` is very important.  
`emscripten`, `wasi`, `wasip`, etc are NOT compatible, as they all assume the runtime
environment to define a large number of functions that turing does not provide.  



