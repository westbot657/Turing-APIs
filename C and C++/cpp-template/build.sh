#!/bin/sh
if ! command -v zig >/dev/null 2>&1; then
  echo "Please install zig."
  exit 1
fi
mkdir build

zig c++ main.cpp -target wasm32-unknown-unknown -I../turing-api-cpp/include -I../internal/src --no-entry -O2 -o build/script.wasm
