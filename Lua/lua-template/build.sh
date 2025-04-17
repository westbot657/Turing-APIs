#!/bin/sh

set -e  # Exit on error

if ! command -v zig >/dev/null 2>&1; then
  echo "Please install zig."
  exit 1
fi

mkdir build
nelua main.nelua --cflags="-m32" -o build/script.c


zig cc build/script.c -target wasm32-unknown-unknown -O2 -o build/script.wasm

