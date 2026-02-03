#!/bin/sh
# Release build script — always use the Zig-based wasi cross-file so Meson
# uses Zig as the compiler targeting wasm32-wasi.
DIR="$(cd "$(dirname "$0")" && pwd)"
meson setup build-release --buildtype=release --cross-file "$DIR/zig-cross.txt"
meson compile -C build-release
mkdir -p ./build
cp ./build-release/compile_commands.json ./build/compile_commands.json