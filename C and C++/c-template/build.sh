#!/bin/sh
if ! command -v zig >/dev/null 2>&1; then
  echo "Please install zig."
  exit 1
fi
mkdir build
zig cc main.c -target wasm32-freestanding \
    -I../turing-api-c/include -I../internal/src \
    --no-entry -O2 -o build/script.wasm
