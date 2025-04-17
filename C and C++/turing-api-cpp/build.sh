#!/bin/sh
if ! command -v zig >/dev/null 2>&1; then
  echo "Please install zig."
  exit 1
fi
mkdir build

zig c++ src/turing_api_cpp.cpp -target wasm32-unknown-unknown -O2 -o build/script.wasm
