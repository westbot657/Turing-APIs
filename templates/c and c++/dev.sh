#!/bin/sh
# Dev build script — always use the Zig-based wasi cross-file so Meson
# uses Emscripten as the compiler targeting wasm32-wasi.
DIR="$(cd "$(dirname "$0")" && pwd)"
meson setup build-debug --buildtype=debug --cross-file "$DIR/wasi-cross.txt"
meson compile -C build-debug