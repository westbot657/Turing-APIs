#!/bin/sh
if ! command -v zig >/dev/null 2>&1; then
  echo "Please install zig."
  exit 1
fi
mkdir build

zig cc src/turing_api_c.c -target wasm32-unknown-unknown -O2 -o build/script.wasm
