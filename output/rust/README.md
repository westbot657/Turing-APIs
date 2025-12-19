# How to set up project and compile

Required dependencies:
- rust
- rustup
- cargo

Recommended tools:
- RustRover (JetBrains IDE, free to use)

Setup instructions:
1. copy the entire `rust-template` directory
2. rename the `rust-template` directory if desired
3. open the project in an IDE
4. run `rustup add wasm32-wasip1`

Compile project:
1. run `cargo build --target wasm32-wasip1 --release`
2. Compiled wasm file is found at target/wasm32-wasip1/release/[crate-name].wasm
3. copy the wasm file into your beatmap directory

